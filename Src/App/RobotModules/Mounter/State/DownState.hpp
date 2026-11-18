#pragma once
#include "FSMState.hpp"
#include "Mounter.hpp"

namespace MOUNTER {

class DownState final : public FSMState<FSMState_e> {
public:
    DownState(Mounter *_mounter) : FSMState<FSMState_e>(FSMState_e::DOWN), mounter_(_mounter) {};

    void enter() override {};
    void run() override {};
    void exit() override {};
    FSMState_e checkChange() final { return FSMState_e::DOWN; };

private:
    Mounter *mounter_;
};

} // namespace MOUNTER
