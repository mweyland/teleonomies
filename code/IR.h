#ifndef _IR_H
#define _IR_H

#include "config.h"

enum orientation {IR_WEST, IR_SOUTH, IR_EAST, IR_NORTH, IR_UNKNOWN};

class IR
{
  public:
    void begin();
    double get_avg_angle();
    orientation get_orientation();

  private:
    unsigned short window[IR_WINDOW_SIZE];
    unsigned int window_index;
};

#endif
