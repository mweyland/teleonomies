#include "IR.h"
#include "config.h"

void IR::begin()
{
  window_index = 0;
  for(unsigned int i = 0; i < IR_WINDOW_SIZE; i++) window[i]=random(5); // FIXME
//  pinMode(IR_ENABLE_PIN, OUTPUT);
//  digitalWrite(IR_ENABLE_PIN, HIGH);
}

double IR::get_avg_angle()
{
  // Must be called in regular intervals that are in line with the IR beacon frequency.
  orientation o = get_orientation();
  if(o != IR_UNKNOWN)
    window[++window_index % IR_WINDOW_SIZE] = o; 

  
  // FIXME: Maybe we should use the Mitsuta method
  // instead of direction cosine method.
  double sum_sin = 0, sum_cos = 0;
  
  for(unsigned int i=0; i < IR_WINDOW_SIZE; i++) 
  {
    sum_sin += sin(PI*window[i]/2.);
    sum_cos += cos(PI*window[i]/2.);
  }
  return atan2(sum_sin, sum_cos);
}

orientation IR::get_orientation()
{
  if(!digitalRead(IR_WEST_PIN)) return IR_WEST;
  if(!digitalRead(IR_SOUTH_PIN)) return IR_SOUTH;
  if(!digitalRead(IR_EAST_PIN)) return IR_EAST;
  if(!digitalRead(IR_NORTH_PIN)) return IR_NORTH;
  return IR_UNKNOWN;
}
