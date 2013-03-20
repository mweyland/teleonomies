#include "Theremin.h"
#include <FreqCount.h>

void Theremin::begin()
{
  FreqCount.begin(100);
}

uint8_t Theremin::available()
{
  return FreqCount.available();
}

uint32_t Theremin::read()
{
  return FreqCount.read();
}
  
