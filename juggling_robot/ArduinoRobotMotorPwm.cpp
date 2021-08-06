#include "ArduinoRobotMotorPwm.h"
#include "Arduino.h"

ArduinoRobotMotorPwm::ArduinoRobotMotorPwm(int CW, int CCW, int PWM)
{
    pinMode(CW, OUTPUT);
    pinMode(CCW, OUTPUT);
    pinMode(PWM, OUTPUT);
    CWpin = CW;
    CCWpin = CCW;
    PWMpin = PWM;
}

void ArduinoRobotMotorPwm::MotorVelocity(int motor_velocity)
{
    digitalWrite(CWpin, motor_velocity > 5);
    digitalWrite(CCWpin, motor_velocity < 5);
    analogWrite(PWMpin, abs(motor_velocity));
}