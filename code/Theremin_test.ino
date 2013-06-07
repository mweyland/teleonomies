#include "Theremin_test.h"


/* You can use this together with ArduinoPlot to find
 * suitable values, e.g. for the map() function below.
 * https://github.com/gregpinero/ArduinoPlot
 */
void Theremin_test::raw_test(Theremin theremin)
{
  while(!Serial.available())
  {
    while(!theremin.available());
    //theremin.read();
    Serial.print("theremin:");
    Serial.println(theremin.read());
  }
  while(Serial.available()) Serial.read();
}

void Theremin_test::sound_test(Theremin theremin, LED led)
{
  float set_frequency = 0;
  uint32_t current_frequency = 10;
  uint32_t measurement_average = 0; //222000;
  volatile uint32_t measurement_max = 0;
  uint32_t measurement_min = 225000;
  uint32_t measurement_window[] = {0,0,0,0,0};
  uint32_t n = 5; //window size
  short index = 0;
  uint32_t measurement_window_min[] = {225000,225000,225000,225000,225000};
  
  while(!Serial.available())
  {
    while(!theremin.available())
    {
        digitalWrite(SPEAKER_PIN, HIGH);
        delayMicroseconds(current_frequency);
        digitalWrite(SPEAKER_PIN, LOW);
        if(current_frequency < set_frequency) current_frequency += 1;
        if(current_frequency > set_frequency) current_frequency -= 1;      
    }
    
    uint32_t measurement = theremin.read();
    if (measurement > measurement_max)
    { 
      //ringbuffer with modulo - value after modulus defines window size
       
      measurement_window[index %n] = measurement;
      index++; 
      
      int i;
      uint32_t sum = 0;
      for (i = 0; i < n; i++)
      {
        sum  += measurement_window[i];
        //Serial.print("__measurement_window_max[");Serial.print(i);Serial.print("\t");Serial.println(measurement_window[i]);
      }
      measurement_max = (sum / n);
      //measurement_max = ((measurement_window[0] + measurement_window[1] + measurement_window[2] + measurement_window[3] + measurement_window[4])/5);
      
      Serial.print("__getting_new_max:");Serial.print(measurement_max); Serial.println();    
    }
    
    if (measurement < measurement_min)
    {     
      measurement_window_min[index %n] = measurement;
      index++;
      
      int i;
      measurement_min = 0;
      for (i = 0; i < n; i++)
      {
        measurement_min = measurement_min + measurement_window_min[i];
        //Serial.print("···measurement_window_min[");Serial.print(i);Serial.print("\t");Serial.println(measurement_window_min[i]);
      }
      measurement_min = (measurement_min / n);
      Serial.print("···getting_new_min:");Serial.print(measurement_min); Serial.println();  
    }
    
    measurement_average = (95 * measurement_average + 5 * measurement)/100;
    DELAY(400);
    
    set_frequency = (map(measurement_average, measurement_min, measurement_max, 0, 10000))/10000;
    Serial.print("set_frequency_mapped:");Serial.print(set_frequency); Serial.print("\t");
    float set_frequency_log = pow(set_frequency, exp(0.5)); //f(x) = pow(xy exp(p)); p = btw -1 & 1
    Serial.print("set_frequency_log:");Serial.print(set_frequency_log); Serial.println();
    //
    Serial.print("measurement:"); Serial.print(measurement); Serial.print("\t");
    //Serial.print("min_max_diff:"); Serial.print(measurement_max-measurement_min); Serial.print("\t");
    Serial.print("measurement_average:"); Serial.print(measurement_average); Serial.print("\t");
    Serial.print("measurement_min:"); Serial.print(measurement_min); Serial.print("\t");
    Serial.print("measurement_max:"); Serial.print(measurement_max); Serial.println("\t");
    //Serial.print("current_frequency:"); Serial.print(current_frequency); Serial.print("\t");
    
    //Serial.print("set_frequency:");Serial.print(set_frequency); Serial.println();
    /*
    for(current_frequency; current_frequency < set_frequency; current_frequency ++) {
      Serial.print("__up_current_frequency:"); Serial.print(current_frequency); Serial.println();
      } 
    for(current_frequency; current_frequency > 0; current_frequency --) {
      Serial.print("--down_current_frequency:"); Serial.print(current_frequency); Serial.println();
      }
    */
  
    //unsigned char colour = map(measurment, measurement_min, measurement_max, 0, 255);
    //Serial.println(colour);
    //led.set_colour(0, 0, colour);
  }
  while(Serial.available()) Serial.read();
}
