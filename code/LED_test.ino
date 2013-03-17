void LED_test::rgb_test(LED led)
{
  for(unsigned int i=0; i<3; i++)
  {
    led.set_colour(0xff, 0x00, 0x00);
    delay(1000);
    led.set_colour(0x00, 0xff, 0x00);
    delay(1000);
    led.set_colour(0x00, 0x00, 0xff);
    delay(1000);
    led.off();
  }
}

void LED_test::brightness_test(LED led)
{
  led.set_colour(0xff, 0xff, 0xff);
  for(unsigned j=0; j<5; j++)
  {
    for(unsigned int i=0; i<=0xff; i++)
    {
      led.set_brightness(i);
      delay(10);
    }
  }
  led.off();
}

void LED_test::rainbow_test(LED led)
{
  unsigned char red = 0x00, green = 0x80, blue = 0xff;
  char red_dir = UP, green_dir = UP, blue_dir = DOWN;
  for(unsigned int i=0; i<10*0xff; i++)
  {
    led.set_colour(red, green, blue);
    delay(2);
    if(red   == 0xff) red_dir   = DOWN;
    if(green == 0xff) green_dir = DOWN;
    if(blue  == 0xff) blue_dir  = DOWN;

    if(!red)   red_dir   = UP; // !red is equal to (red == 0x00)
    if(!green) green_dir = UP;
    if(!blue)  blue_dir  = UP;
    
    red += red_dir;    
    green += green_dir;   
    blue += blue_dir;
  }
  led.off();
}
