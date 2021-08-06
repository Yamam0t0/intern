#ifndef ArduinoRobotMotorPwm_h
#define ArduinoRobotMotorPwm_h
#include "Arduino.h"

class ArduinoRobotMotorPwm
{
private:
    /* data */
    int CWpin;
    int CCWpin;
    int PWMpin;

public:
    ArduinoRobotMotorPwm(int CW, int CCW, int PWM);
    void MotorVelocity(int motor_velocity);
};

#endif