#ifndef _THEREMIN_TEST_H
#define _THEREMIN_TEST_H

#include "Theremin.h"
#include "LED.h"

class Theremin_test
{
  public:
    static void raw_test(Theremin theremin);
    static void sound_test(Theremin theremin, LED led);
};

#endif
