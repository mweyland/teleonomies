#include "Servo_Wrapper.h"
#include "LED.h"
#include "IR.h"
#include "Speaker.h"

#include "LED_test.h"
#include "IR_test.h"

LED led;
IR ir;
Speaker speaker;
Servo_Wrapper servo;

#define UP +1
#define DOWN -1

void setup()
{
  Serial.begin(9600);
  while(!Serial.dtr());
  delay(1000);
  
  led.begin();
  ir.begin();
  speaker.begin();
  servo.begin();
  
}

void loop()
{
  Serial.println("DEBUG MODE");
  IR_test::orientation_test(ir);
  IR_test::window_test(ir);
}

/*
LED test:
LED_test::rgb_test(led);
LED_test::brightness_test(led);
LED_test::rainbow_test(led);
*/

