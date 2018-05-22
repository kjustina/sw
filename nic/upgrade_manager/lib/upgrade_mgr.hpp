// {C} Copyright 2018 Pensando Systems Inc. All rights reserved.

#ifndef __UPGRADE_MGR_H__
#define __UPGRADE_MGR_H__

#include "nic/delphi/sdk/delphi_sdk.hpp"
#include "nic/upgrade_manager/proto/upgrade.delphi.hpp"

namespace upgrade {

using namespace std;

// UpgradeMgr is the reactor for the UpgReq object
class UpgradeMgr : public delphi::objects::UpgReqReactor {
    delphi::SdkPtr sdk_;
public:
    UpgradeMgr(delphi::SdkPtr sk) {
        this->sdk_ = sk;
    }

    // OnUpgReqCreate gets called when UpgReq object is created
    virtual delphi::error OnUpgReqCreate(delphi::objects::UpgReqPtr upgreq);

    // OnUpgReqDelete gets called when UpgReq object is deleted
    virtual delphi::error OnUpgReqDelete(delphi::objects::UpgReqPtr upgreq);

    // OnUpgReqCmd gets called when UpgReqCmd attribute changes
    virtual delphi::error OnUpgReqCmd(delphi::objects::UpgReqPtr upgreq);

    // createUpgStateReq creates an upgrade request status object
    delphi::error createUpgStateReq(uint32_t id, upgrade::UpgReqStateType status);

    // findUpgStateReq finds the upgrade request status object
    delphi::objects::UpgStateReqPtr findUpgStateReq(uint32_t id);

    UpgReqStateType GetNextState(void);

    string UpgReqStateTypeToStr(UpgReqStateType type);

    bool CanMoveStateMachine(void);

    delphi::error MoveStateMachine(UpgReqStateType type);

    UpgRespStateType GetFailRespType(UpgReqStateType);
    UpgRespStateType GetPassRespType(UpgReqStateType);
};
typedef std::shared_ptr<UpgradeMgr> UpgradeMgrPtr;

} // namespace example

#endif // __UPGRADE_MGR_H__
