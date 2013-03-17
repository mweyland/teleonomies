#include "IR_test.h"

void IR_test::orientation_test(IR ir)
{
  while(!Serial.available())
  {
    orientation o = ir.get_orientation();
    switch(o)
    {
      case IR_NORTH:
        Serial.println("NORTH");
        break;
      case IR_EAST:
        Serial.println("EAST");
        break;
      case IR_SOUTH:
        Serial.println("SOUTH");
        break;
      case IR_WEST:
        Serial.println("WEST");
        break;
      case IR_UNKNOWN:
        Serial.println("UNKNOWN");
        break;
    }
    delay(100);
  }
  while(Serial.available()) Serial.read();
}

void IR_test::window_test(IR ir)
{
  while(!Serial.available())
  {
    double angle = ir.get_avg_angle();
    Serial.print("Angle: "); Serial.print(angle); Serial.print(", "); Serial.print(180*angle/PI); Serial.println(" deg.");
    delay(100);
  }
  while(Serial.available()) Serial.read();
}
