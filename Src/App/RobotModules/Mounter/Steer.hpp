#pragma once
#include "Bsp_pwm.hpp"
#include <cstdint>

extern TIM_HandleTypeDef htim1;
class Steer {
public:
    Steer();
    void setVtSteerAng(uint8_t _steerAng);
    void setScopeSteerAng(uint8_t _steerAng);
    void setFrontSteerAng(uint8_t _steerAng);
    void setRearSteerAng(uint8_t _steerAng);

    static constexpr float VT_MIN_ANG = 0.02f;
    static constexpr float VT_MAX_ANG = 0.40f;

private:
    Pwm vtSteerPwm{ &htim1, TIM_CHANNEL_3 };
    Pwm scopeSteerPwm{ &htim1, TIM_CHANNEL_1 };
};
