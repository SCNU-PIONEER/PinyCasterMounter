#pragma once
#include "FSMState.hpp"
#include "Mounter.hpp"

namespace MOUNTER {

class UpState final : public FSMState<FSMState_e> {
public:
    UpState(Mounter *_mounter) : FSMState<FSMState_e>(FSMState_e::UP), mounter_(_mounter) {};

    void enter() override {};
    void run() override {};
    void exit() override {};
    FSMState_e checkChange() final { return FSMState_e::UP; };

private:
    Mounter *mounter_;
};

} // namespace MOUNTER
