#include "Mounter.hpp"

#include "Soc.hpp"
#include "DM4340.hpp"

#include "./State/StopState.hpp"
#include "./State/DownState.hpp"
#include "./State/UpState.hpp"

using namespace PINYMOTOR;
using namespace MOUNTER;

Mounter::Mounter()
{
    InitConfig_s mounter4340Config = {
        .pComHandle = reinterpret_cast<uint32_t *>(&HCAN1),
        .comType = ComType_e::CAN,
        .motorType = SupportMotor_e::DA_MIAO,
        .offsetId = 1,
        .txFreq = 1000.0f,
    };
    motor_ = new DMMOTOR::DM4340("Mounter", mounter4340Config, DMMOTOR::WorkMode_e::MIT_TT);

    MounterCtrl.posPid = new PositionalPid(0.1f, 0.0f, 0.0f, 0.0f, 10000.0f, 10000.0f);
    MounterCtrl.velPid = new PositionalPid(0.1f, 0.0f, 0.0f, 0.0f, 10000.0f, 10000.0f);

    stateFactory_.addState(FSMState_e::STOP, std::make_unique<StopState>(this));
    stateFactory_.addState(FSMState_e::DOWN, std::make_unique<DownState>(this));
    stateFactory_.addState(FSMState_e::UP, std::make_unique<UpState>(this));
    stateFactory_.init(stateFactory_.getNextState(FSMState_e::STOP));
}
