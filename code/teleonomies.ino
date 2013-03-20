#include "Servo_Wrapper.h"
#include "LED.h"
#include "IR.h"
#include "Speaker.h"

#include "LED_test.h"
#include "IR_test.h"
#include "Servo_test.h"

LED led;
IR ir;
Speaker speaker;
Servo_Wrapper servo;

#define UP +1
#define DOWN -1

void setup()
{
  delay(1000);
  Serial.begin(9600);
  delay(1000);
  while(!Serial.dtr());
  delay(1000);
  
  led.begin();
  ir.begin();
  speaker.begin();
  servo.begin();
  
}

void reset()
{
  cli();
// disable watchdog, if enabled
// disable all peripherals
UDCON = 1;
USBCON = (1<<FRZCLK);  // disable USB
UCSR1B = 0;
delay(5);
EIMSK = 0; PCICR = 0; SPCR = 0; ACSR = 0; EECR = 0; ADCSRA = 0;
TIMSK0 = 0; TIMSK1 = 0; TIMSK2 = 0; TIMSK3 = 0; UCSR1B = 0; TWCR = 0;
DDRA = 0; DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
PORTA = 0; PORTB = 0; PORTC = 0; PORTD = 0; PORTE = 0; PORTF = 0;
asm volatile("jmp 0x7000");
}

void loop()
{
  
  Serial.println("Waiting for reset.");
  for(int i=5; i>=0; i--)
  {
    Serial.println(i);
    delay(500);
  }
  reset();
}

  /*
  Servo_test::servo_cycle_test(servo);
  Servo_test::servo_direction_test(servo, ir);
  */

/*
  LED_test::rgb_test(led);
  LED_test::brightness_test(led);
  LED_test::rainbow_test(led);
*/

/*
  IR_test::orientation_test(ir);
  IR_test::window_test(ir);
*/
