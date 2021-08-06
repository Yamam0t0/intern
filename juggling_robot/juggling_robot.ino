#include "ArduinoRobotMotorPwm.h"

// モーター配置
enum MotorArrangement
{
    right_foot,
    left_foot,
    shot_mechanism,
    horizontal_projection,
    motor_count
};

// モーターピン接続
ArduinoRobotMotorPwm Motor[motor_count] = {
    ArduinoRobotMotorPwm{2, 4, 3},
    ArduinoRobotMotorPwm{5, 7, 6},
    ArduinoRobotMotorPwm{13, 8, 9},
    ArduinoRobotMotorPwm{A5, A2, 10},
};

void setup()
{
    Serial.begin(115200);
}

int solenoid_valve;

char data;
void loop()
{
    if (Serial.available() > 0)
    {
        data = Serial.read();
        switch (data)
        {
        // 非常事態用(全モーターOFF)
        case 'e':
            Reset();
            break;

        // 3個でジャグリング
        case 't':
            Motor[shot_mechanism].MotorVelocity(85);
            Motor[horizontal_projection].MotorVelocity(255);
            break;

        // 5個でジャグリング
        case 'f':
            Motor[shot_mechanism].MotorVelocity(170);
            Motor[horizontal_projection].MotorVelocity(255);
            break;

        // 7個でジャグリング
        case 's':
            Motor[shot_mechanism].MotorVelocity(255);
            Motor[horizontal_projection].MotorVelocity(255);
            break;

        // 全モーターストップ
        default:
            Reset();
            break;
        }
    }
}

// void ShotReload(char state)
// {
// }

// 足回り
void SuspensionSystem()
{
    for (int i = 0; i < 2; i++)
        Motor[i].MotorVelocity(0);
}

// 非常事態用
void Reset()
{
    for (int i = 0; i < motor_count; i++)
        Motor[i].MotorVelocity(0);
}