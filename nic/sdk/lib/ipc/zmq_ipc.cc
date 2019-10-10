//------------------------------------------------------------------------------
// {C} Copyright 2019 Pensando Systems Inc. All rights reserved
//------------------------------------------------------------------------------

#include "ipc.hpp"
#include "zmq_ipc.hpp"

#include <memory>
#include <string>
#include <vector>

#include <assert.h>
#include <stdint.h>
#include <zmq.h>

#include "include/sdk/base.hpp"
#include "include/sdk/mem.hpp"

namespace sdk {
namespace lib {
namespace ipc {

static void *g_zmq_ctx = zmq_ctx_new();

static thread_local zmq_ipc_client *t_zmq_ipc_client_ = NULL;

void *
zmq_ipc_msg::data(void) {
    if (this->preamble_received_ && this->preamble_.is_pointer) {
        return *(void **)zmq_msg_data(&this->zmsg_);
    }
    return zmq_msg_data(&this->zmsg_);
}

size_t
zmq_ipc_msg::length(void) {
    if (this->preamble_received_ && this->preamble_.is_pointer) {
        return this->preamble_.real_length;
    }
    return zmq_msg_size(&this->zmsg_);
}

zmq_ipc_msg::zmq_ipc_msg() {
    int rc = zmq_msg_init(&this->zmsg_);
    assert(rc == 0);

    this->sender_ = 0;
    this->preamble_received_ = false;
}

zmq_ipc_msg::~zmq_ipc_msg() {
    zmq_msg_close(&this->zmsg_);
}

void
zmq_ipc_msg::set_sender(uint32_t sender) {
    this->sender_ = sender;
}

uint32_t
zmq_ipc_msg::sender(void) {
    return this->sender_;
}

zmq_msg_t *
zmq_ipc_msg::zmsg(void) {
    return &this->zmsg_;
}

void
zmq_ipc_msg::add_header(std::shared_ptr<zmq_ipc_msg> header) {
    this->headers_.push_back(header);
}

std::vector<zmq_ipc_msg_ptr> &
zmq_ipc_msg::headers(void) {
    return this->headers_;
}

zmq_ipc_msg_preamble_t *
zmq_ipc_msg::preamble(void) {
    return &this->preamble_;
}

void
zmq_ipc_msg::set_preamble_received(bool received) {
    this->preamble_received_ = received;
}

static std::string
ipc_path_external (uint32_t id)
{
    return "ipc:///tmp/pen_sdk_ipc_" + std::to_string(id);
}

static std::string
ipc_path_internal (uint32_t id)
{
    return "inproc://pen_sdk_ipc_" + std::to_string(id);
}

zmq_ipc_client::zmq_ipc_client() {
}

zmq_ipc_client::~zmq_ipc_client() {
    for (int i = 0; i < IPC_MAX_ID; i++) {
        if (this->zconnections_[i].zsocket) {
            zmq_close(this->zconnections_[i].zsocket);
            this->zconnections_[i].zsocket = NULL;
        }
    }

    zmq_close(this->zsocket_);
}

zmq_ipc_client *
zmq_ipc_client::factory(uint32_t id, bool bidirectional) {
    int            rv;
    void           *mem;
    zmq_ipc_client *new_client;

    mem = SDK_CALLOC(SDK_MEM_ALLOC_LIB_IPC_CLIENT, sizeof(*new_client));
    if (!mem) {
        return NULL;
    }
    new_client = new (mem) zmq_ipc_client();
    rv = new_client->init(id, bidirectional);
    if (rv < 0) {
        new_client->~zmq_ipc_client();
        SDK_FREE(SDK_MEM_ALLOC_LIB_IPC_CLIENT, new_client);
        return NULL;
    }

    return new_client;
}

void
zmq_ipc_client::destroy(zmq_ipc_client *client) {
    assert(client != NULL);
    client->~zmq_ipc_client();
    SDK_FREE(SDK_MEM_ALLOC_LIB_IPC_CLIENT, client);
}

int
zmq_ipc_client::init(uint32_t id, bool bidirectional) {
    int rc;

    assert(id <= IPC_MAX_ID);

    this->id_ = id;
    this->next_serial_ = 1;
        
    if (bidirectional) {
        this->zsocket_ = zmq_socket(g_zmq_ctx, ZMQ_ROUTER);
        rc = zmq_bind(this->zsocket_, ipc_path_external(id).c_str());
        assert(rc == 0);
        SDK_TRACE_DEBUG("Listening on %s", ipc_path_external(id).c_str());
        
        rc = zmq_bind(this->zsocket_, ipc_path_internal(id).c_str());
        assert(rc == 0);
        SDK_TRACE_DEBUG("Listening on %s", ipc_path_internal(id).c_str());
    }

    for (int i = 0; i < IPC_MAX_ID; i++) {
        this->zconnections_[i].zsocket = NULL;
    }

    return 0;
}

void *
zmq_ipc_client::connect_(uint32_t recipient, bool *is_internal) {
    if (this->zconnections_[recipient].zsocket == NULL) {
        void *zctx;
        void *zconn;
        int rc;

        zctx = g_zmq_ctx;
        zconn = zmq_socket(zctx, ZMQ_REQ);

        // stavros todo fixme, check externa/internal
        rc = zmq_connect(zconn, ipc_path_internal(recipient).c_str());
        assert(rc == 0);
        SDK_TRACE_DEBUG("Connecting to %s",
                        ipc_path_internal(recipient).c_str());
        this->zconnections_[recipient].is_internal = true;
        this->zconnections_[recipient].zsocket = zconn;
    }

    *is_internal = this->zconnections_[recipient].is_internal;
    return this->zconnections_[recipient].zsocket;
}

void
zmq_ipc_client::send_preamble_(void *socket, uint32_t recipient,
                               bool is_pointer, size_t real_length) {
    int rc;
    zmq_ipc_msg_preamble_t preamble;

    preamble.sender = this->id_;
    preamble.recipient = recipient;
    preamble.serial = this->next_serial_++;
    preamble.is_pointer = is_pointer;
    preamble.real_length = real_length;
    rc = zmq_send(socket, &preamble, sizeof(preamble), ZMQ_SNDMORE);
    assert(rc != -1);
    SDK_TRACE_DEBUG("Sent message: sender: %u, recipient: %u, serial: %u, "
                    "pointer: %d, real_length: %zu",
                    preamble.sender, preamble.recipient, preamble.serial,
                    preamble.is_pointer, real_length);
}

void
zmq_ipc_client::recv_preamble_(void *socket, zmq_ipc_msg_preamble_t *preamble) {
    int rc;

    rc = zmq_recv(socket, preamble, sizeof(*preamble), 0);
    assert(rc == sizeof(*preamble));

    SDK_TRACE_DEBUG("Received message: sender: %u, recipient: %u, serial: %u, "
                    "pointer: %d",
                    preamble->sender, preamble->recipient, preamble->serial,
                    preamble->is_pointer);
    assert(preamble->recipient == this->id_);
}

ipc_msg_ptr
zmq_ipc_client::send_recv_once(uint32_t recipient, const void *data,
                               size_t data_length)
{
    if (t_zmq_ipc_client_ == NULL) {
        t_zmq_ipc_client_ = zmq_ipc_client::factory(0, false);
    }
    return t_zmq_ipc_client_->send_recv(recipient, data, data_length);
}

ipc_msg_ptr
zmq_ipc_client::send_recv(uint32_t recipient, const void *data,
                          size_t data_length) {
    int rc;
    bool is_internal = false;
    void *zconn = this->connect_(recipient, &is_internal);
    zmq_ipc_msg_ptr msg = std::make_shared<zmq_ipc_msg>();

    this->send_preamble_(zconn, recipient, is_internal, data_length);
   
    if (is_internal)
    {
        // just send the pointer
        rc = zmq_send(zconn, &data, sizeof(data), 0);
        assert(rc >= 0);
    }
    else
    {
        rc = zmq_send(zconn, data, data_length, 0);
        assert(rc >= 0);
    }

    this->recv_preamble_(zconn, msg->preamble());
    msg->set_preamble_received(true);
    rc = zmq_recvmsg(zconn, msg->zmsg(), 0);
    assert(rc >= 0);

    return msg;
}

int
zmq_ipc_client::fd(void) {
    int    fd;
    size_t fd_len;

    fd_len = sizeof(fd);

    zmq_getsockopt(this->zsocket_, ZMQ_FD, &fd, &fd_len);

    return fd;
}

int
zmq_ipc_client::is_event_pending(void) {
    int zevents;
    size_t zevents_len;

    zevents_len = sizeof(zevents);

    zmq_getsockopt(this->zsocket_, ZMQ_EVENTS, &zevents, &zevents_len);

    return (zevents & ZMQ_POLLIN);
}

ipc_msg_ptr
zmq_ipc_client::recv(void) {
    int rc;

    if (!this->is_event_pending()) {
        return nullptr;
    }

    std::shared_ptr<zmq_ipc_msg> msg =
        std::make_shared<zmq_ipc_msg>();

    // See ZMQ Router to understand why we do this
    while(1) {
        std::shared_ptr<zmq_ipc_msg> header =
            std::make_shared<zmq_ipc_msg>();
        rc = zmq_recvmsg(this->zsocket_, header->zmsg(), 0);
        assert(rc != -1);
        msg->add_header(header);
        if (header->length() == 0) {
            break;
        }
    }

    this->recv_preamble_(this->zsocket_, msg->preamble());
    msg->set_preamble_received(true);
    msg->set_sender(msg->preamble()->sender);
    rc = zmq_recvmsg(this->zsocket_, msg->zmsg(), 0);
    assert(rc != -1);

    return msg;
}

void
zmq_ipc_client::reply(ipc_msg_ptr msg, const void *data,
                       size_t data_length) {
    int rc;
    zmq_ipc_msg_ptr zmsg =
        std::dynamic_pointer_cast<zmq_ipc_msg>(msg);

    // See ZMQ Router to understand why we do this
    for (auto header: zmsg->headers()) {
        rc = zmq_send(this->zsocket_, header->data(), header->length(),
                      ZMQ_SNDMORE);
        assert(rc != -1);
    }

    // stavros todo: send pointer
    this->send_preamble_(this->zsocket_, zmsg->sender(), false, data_length);
    rc = zmq_send(this->zsocket_, data, data_length, 0);
    assert(rc != -1);
}

} // namespace ipc
} // namespace lib
} // namespace sdk
