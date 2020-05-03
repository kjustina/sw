/*
 * Copyright (c) 2018, Pensando Systems Inc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdint.h>

#include "platform/pal/include/pal.h"
#include "ev.h"
#include "evutils.h"

typedef struct evutil_fd_ctx_s {
    ev_io evio;                 /* must be first item in this struct */
    evutil_cb_t *rdcb;          /* read callback, if interested in reads */
    evutil_cb_t *wrcb;          /* write callback, if interested in writes */
    void *cbarg;                /* callback arg */
    struct pal_int *pal_int;    /* pal_int handle */
} evutil_fd_ctx_t;

#define EVUTIL_NFDS     256

static evutil_fd_ctx_t evutil_fd_ctx[EVUTIL_NFDS];

static void
evutil_fd_cb(EV_P_ ev_io *w, int revents)
{
    evutil_fd_ctx_t *fdctx = (evutil_fd_ctx_t *)w;
    evutil_cb_t *rdcb = fdctx->rdcb;
    evutil_cb_t *wrcb = fdctx->wrcb;

    if (fdctx->pal_int) {
        pal_int_start(fdctx->pal_int);
    }

    if ((revents & EV_READ) && rdcb) {
        rdcb(fdctx->cbarg);
    }
    if ((revents & EV_WRITE) && wrcb) {
        wrcb(fdctx->cbarg);
    }

    if (fdctx->pal_int) {
        pal_int_end(fdctx->pal_int);
    }
}

static void
evutil_add_fd_cmn(EV_P_ int fd, evutil_cb_t *rdcb, evutil_cb_t *wrcb, void *cbarg,
                  struct pal_int *pal_int)
{
    evutil_fd_ctx_t *fdctx;
    int events;

    assert(fd >= 0 && fd < EVUTIL_NFDS);
    fdctx = &evutil_fd_ctx[fd];
    fdctx->rdcb = rdcb;
    fdctx->wrcb = wrcb;
    fdctx->cbarg = cbarg;
    fdctx->pal_int = pal_int;

    events = 0;
    if (fdctx->rdcb) events |= EV_READ;
    if (fdctx->wrcb) events |= EV_WRITE;
#ifdef LIBEV
    ev_io_init(&fdctx->evio, evutil_fd_cb, fd, events);
    ev_io_start(EV_A_ &fdctx->evio);
#else
    if (0) evutil_fd_cb(EV_A_ &fdctx->evio, 0);
#endif
}

void
evutil_add_fd(EV_P_ int fd, evutil_cb_t *rdcb, evutil_cb_t *wrcb, void *cbarg)
{
    evutil_add_fd_cmn(EV_A_ fd, rdcb, wrcb, cbarg, NULL);
}

void
evutil_remove_fd(EV_P_ const int fd)
{
    evutil_fd_ctx_t *fdctx;

    assert(fd >= 0 && fd < EVUTIL_NFDS);
    fdctx = &evutil_fd_ctx[fd];
#ifdef LIBEV
    ev_io_stop(EV_A_ &fdctx->evio);
#endif
    fdctx->rdcb = fdctx->wrcb = NULL;
}

void
evutil_add_pal_int(EV_P_ struct pal_int *pal_int, evutil_cb_t *isrcb, void *cbarg)
{
    printf("%s:%d\n", __FILE__, __LINE__);
    return;
    int fd = pal_int_fd(pal_int);

    evutil_add_fd_cmn(EV_A_ fd, isrcb, NULL, cbarg, pal_int);
}

void
evutil_remove_pal_int(EV_P_ struct pal_int *pal_int)
{
    int fd = pal_int_fd(pal_int);

    evutil_remove_fd(EV_A_ fd);
}
