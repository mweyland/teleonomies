#include "Speaker.h"
#include "config.h"

void Speaker::begin()
{
  pinMode(SPEAKER_PIN, OUTPUT);
}
