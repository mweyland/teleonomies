#include <Servo.h> // Has to remain here because of the crappy way the arduino IDE works.
#include "Servo_Wrapper.h"
#include "config.h"

void Servo_Wrapper::begin()
{
   servo[SERVO_1].attach(SERVO_1_PIN);
   servo[SERVO_2].attach(SERVO_2_PIN);
   servo[SERVO_3].attach(SERVO_3_PIN);

   servo[SERVO_1].write(SERVO_1_MIN);
   servo[SERVO_2].write(SERVO_2_MIN);
   servo[SERVO_3].write(SERVO_3_MIN);
}

void Servo_Wrapper::apply_inverse_kinematics(double Xdes, double Ydes)
{
  // FIXME: Document these coefficients
  double theta0 =  3.3333e-01  * Xdes - 5.7735e-01 * Ydes;
  double theta1 =  3.3333e-01  * Xdes + 5.7735e-01 * Ydes;
  double theta2 = -6.6667e-01  * Xdes + 0 * Ydes;

   //assuming the motor for theta2 is pointing towards 'east' of the beacon = 90°
   //and theta1 is between north and west that ist between 270° and 0°

   servo[SERVO_1].write(SERVO_1_MIN + ((theta0 + 0.57)/1.15)*(SERVO_1_MAX-SERVO_1_MIN));
   servo[SERVO_2].write(SERVO_2_MIN + ((theta1 + 0.57)/1.15)*(SERVO_2_MAX-SERVO_2_MIN));
   servo[SERVO_3].write(SERVO_3_MIN + ((theta2 + 0.66)/1.33)*(SERVO_3_MAX-SERVO_3_MIN));
}


// For debugging only
void Servo_Wrapper::set_position(unsigned char servo_id, char pos)
{
  if(servo_id < 3) servo[servo_id].write(pos);
}
