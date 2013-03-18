#ifndef _SERVO_TEST_H
#define _SERVO_TEST_H

#include "Servo_Wrapper.h"
#include "IR.h"

class Servo_test
{
  public:
    static void servo_cycle_test(Servo_Wrapper servo);
    static void servo_direction_test(Servo_Wrapper servo, IR ir);
};

#endif

