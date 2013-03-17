#include "Wire.h"
#include "LED.h"

#define I2C_ADDR 98

#define LED_REG_MODE1       0x00
#define LED_REG_MODE2       0x01
#define LED_REG_PWM0        0x02
#define LED_REG_PWM1        0x03
#define LED_REG_PWM2        0x04
#define LED_REG_PWM3        0x05
#define LED_REG_GRPPWM      0x06
#define LED_REG_GRPFREQ     0x07
#define LED_REG_LEDOUT      0x08
#define LED_REG_SUBADR1     0x09
#define LED_REG_SUBADR2     0x0A
#define LED_REG_SUBADR3     0x0B
#define LED_REG_ALLCALLADR  0x0C


void LED::begin()
{
  Wire.begin();
  // FIXME: Which ones of these are needed?
  i2c_write(LED_REG_MODE1, 0x0F);
  i2c_write(LED_REG_MODE2, 0x05);
  i2c_write(LED_REG_PWM0, 0x00);
  i2c_write(LED_REG_PWM1, 0x00);
  i2c_write(LED_REG_PWM2, 0x00);
  i2c_write(LED_REG_PWM3, 0x00);
  i2c_write(LED_REG_GRPPWM, 0x35);
  i2c_write(LED_REG_GRPFREQ, 0x00);
  i2c_write(LED_REG_LEDOUT, 0x3f);
  i2c_write(LED_REG_GRPFREQ, 0x00);
  i2c_write(LED_REG_ALLCALLADR, 0xE1); 
}

void LED::set_colour(char red, char green, char blue)
{
  i2c_write(LED_REG_PWM0, green);
  i2c_write(LED_REG_PWM1, blue);
  i2c_write(LED_REG_PWM2, red);
}

void LED::set_brightness(char val)
{
  i2c_write(LED_REG_GRPPWM, val);
}
 
void LED::off()
{
  set_colour(0x00, 0x00, 0x00);
}

void LED::i2c_write(char reg, char val)
{
  Wire.beginTransmission(I2C_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();

}

