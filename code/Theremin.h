#ifndef _THEREMIN_H
#define _THEREMIN_H

class Theremin
{
  public:
    void begin();
    uint8_t available();
    uint32_t read();
};

#endif
