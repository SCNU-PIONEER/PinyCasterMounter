#pragma once
#include "FSMState.hpp"
#include "Mounter.hpp"

namespace MOUNTER {

class StopState final : public FSMState<FSMState_e> {
public:
    StopState(Mounter *_mounter) : FSMState<FSMState_e>(FSMState_e::STOP), mounter_(_mounter) {};

    void enter() override {};
    void run() override {};
    void exit() override {};
    FSMState_e checkChange() final { return FSMState_e::STOP; };

private:
    Mounter *mounter_;
};

} // namespace MOUNTER
