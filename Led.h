#ifndef LED_H
#define LED_H
#include <Arduino.h>
class Led {
  
  private:
    byte pin;
    
  public:
    Led(byte pin);
    void init();
    void on();
    void off();
};
#endif