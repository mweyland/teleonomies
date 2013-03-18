#ifndef SERVO_WRAPPER_H
#define SERVO_WRAPPER_H

#include <Servo.h>

class Servo_Test;

class Servo_Wrapper
{
  public:
    void begin();
    void apply_inverse_kinematics(double Xdes,double Ydes);
    enum servo_number { SERVO_1, SERVO_2, SERVO_3 };
    friend class Servo_test;

  private:
    void set_position(unsigned char servo_id, char pos);
    Servo servo[3];
};

#endif
