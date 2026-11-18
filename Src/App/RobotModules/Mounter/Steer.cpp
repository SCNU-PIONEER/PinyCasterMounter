#include "Steer.hpp"
#include "dsp/fast_math_functions.h"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <numbers>
Steer::Steer()
{
    vtSteerPwm.start();
    scopeSteerPwm.start();
}

void Steer::setFrontSteerAng(uint8_t _steerAng)
{
    float realAng = static_cast<float>(_steerAng) * 2.87f / PI;
    float ccrValue = 500 + ((realAng / 90) * 1000);
    vtSteerPwm.setDutyCycle(static_cast<uint32_t>(ccrValue));
}

void Steer::setRearSteerAng(uint8_t _steerAng)
{
    float realAng = static_cast<float>(_steerAng) * 3.f / PI;
    float ccrValue = 500 + ((realAng / 180) * 2000);
    scopeSteerPwm.setDutyCycle(static_cast<uint32_t>(ccrValue));
}
