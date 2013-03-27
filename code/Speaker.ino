#include "Speaker.h"
#include "config.h"

void Speaker::begin()
{
  pinMode(SPEAKER_PIN, OUTPUT);
  TCCR0A = _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(CS00);
  TIMSK0 = _BV(TOIE0);
}

uint8_t wav[] = {128, 153, 177, 199, 219, 234, 246, 254, 255, 254, 246, 234, 219, 199, 177, 153, 128, 103, 79, 57, 37, 22, 10, 2, 0, 2, 10, 22, 37, 57, 79, 103};


unsigned long i;
ISR(TIMER0_OVF_vect) {
  OCR0A = wav[i++ % 32];
}
