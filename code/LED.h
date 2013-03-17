#ifndef _LED_H
#define _LED_H

class LED
{
  public:
    void begin();
    void set_colour(char red, char green, char blue);
    void set_brightness(char val);
    void off();
    
  private:
    void i2c_write(char reg, char val);
};

#endif
