#include "Speaker_test.h"
#include "Speaker.h"

void Speaker_test::simple_test()
{
  while(!Serial.available())
  {
    digitalWrite(SPEAKER_PIN, HIGH);
    DELAY(1);
    digitalWrite(SPEAKER_PIN, LOW);
    DELAY(1);
  }
  while(Serial.available()) Serial.read();
}
