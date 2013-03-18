#include "Servo_test.h"

void Servo_test::servo_cycle_test(Servo_Wrapper servo)
{
  Serial.println("Servo 1");
  for(unsigned int i = SERVO_1_MIN; i <= SERVO_1_MAX; i++)
  {
    servo.set_position(0, i);
    delay(50);
  }
  Serial.println("Servo 2");
  for(unsigned int i = SERVO_2_MIN; i <= SERVO_2_MAX; i++)
  {
    servo.set_position(1, i);
    delay(50);
  }
  Serial.println("Servo 3");
  for(unsigned int i = SERVO_3_MIN; i <= SERVO_3_MAX; i++)
  {
    servo.set_position(2, i);
    delay(50);
  }
}

void Servo_test::servo_direction_test(Servo_Wrapper servo, IR ir)
{
  while(1){
    double theta  = ir.get_avg_angle();
    Serial.print("theta: ");
    Serial.println(theta);
    servo.apply_inverse_kinematics(cos(theta), sin(theta));
  }
}

