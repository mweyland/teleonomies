#include "Theremin_test.h"


/* You can use this together with ArduinoPlot to find
 * suitable values, e.g. for the map() function below.
 * https://github.com/gregpinero/ArduinoPlot
 */
void Theremin_test::raw_test(Theremin theremin)
{
  while(!Serial.available())
  {
    while(!theremin.available());
    Serial.println(theremin.read());
  }
  while(Serial.available()) Serial.read();
}

void Theremin_test::sound_test(Theremin theremin, LED led)
{
  uint32_t set_frequency = 0;
  uint32_t current_frequency = 10;
  while(!Serial.available())
  {
    while(!theremin.available())
    {
      delayMicroseconds(current_frequency);
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(current_frequency);
      digitalWrite(SPEAKER_PIN, LOW);
      if(current_frequency < set_frequency) current_frequency += 1;
      if(current_frequency > set_frequency) current_frequency -= 1;
    }
    uint32_t measurment = theremin.read();
    Serial.print(measurment); Serial.print("\t");
    set_frequency = map(measurment, 265000, 275000, 500, 1000);
    Serial.print(set_frequency); Serial.print("\t");

    unsigned char colour = map(measurment, 265000, 275000, 0, 255);
    Serial.println(colour);
    led.set_colour(0, 0, colour);
  }
  while(Serial.available()) Serial.read();
}
