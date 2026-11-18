#pragma once

#include "FSMState.hpp"
#include "IMotor.hpp"

#include "PidBasic.hpp"

namespace MOUNTER {

enum class FSMState_e : uint8_t { STOP, DOWN, UP };

struct MotorCtrl_s {
    PositionalPid *posPid;
    PositionalPid *velPid;
    float targetVel;
    float torq;
};

class Mounter {
public:
    Mounter();

    void stop();
    void enter();
    void update(void *_param);

private:
    PINYMOTOR::IMotor *motor_;
    MotorCtrl_s MounterCtrl;
    StateFactory<FSMState_e> stateFactory_;
};

} // namespace MOUNTER
