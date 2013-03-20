#include "Speaker_test.h"
#include "Speaker.h"

void Speaker_test::simple_test()
{
  while(!Serial.available())
  {
    digitalWrite(SPEAKER_PIN, HIGH);
    delay(1);
    digitalWrite(SPEAKER_PIN, LOW);
    delay(1);
  }
  while(Serial.available()) Serial.read();
}
