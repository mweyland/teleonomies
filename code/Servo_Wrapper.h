#ifndef SERVO_WRAPPER_H
#define SERVO_WRAPPER_H

#include <Servo.h>

class Servo_Wrapper
{
  public:
    void begin();
    void apply_inverse_kinematics(double Xdes,double Ydes);
    enum servo_number { SERVO_1, SERVO_2, SERVO_3 };

  private:
    Servo servo[3];
};

#endif
