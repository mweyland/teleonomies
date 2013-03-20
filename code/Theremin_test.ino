#include "Theremin_test.h"

void Theremin_test::raw_test(Theremin theremin)
{
  uint32_t frequency = 0;
  while(!Serial.available())
  {
    while(!theremin.available());
    Serial.println(theremin.read());
  }
  while(Serial.available()) Serial.read();
}

void Theremin_test::sound_test(Theremin theremin)
{
  uint32_t frequency = 0;
  while(!Serial.available())
  {
    while(!theremin.available())
    {
      delayMicroseconds(frequency);
      digitalWrite(SPEAKER_PIN, HIGH);
      delayMicroseconds(frequency);
      digitalWrite(SPEAKER_PIN, LOW);
    }
    frequency = map(theremin.read(), 270000, 280000, 500, 1000);
  }
  while(Serial.available()) Serial.read();
}
