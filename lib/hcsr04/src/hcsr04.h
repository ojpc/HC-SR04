#ifndef hc_sr04
#define hc_sr04

#include <Arduino.h>
#include <SPI.h>

class HCSR04
{
public:
  HCSR04(uint8_t, uint8_t);
  void sendPulse();
  int getEchoTime();
  float getDistance(String);
private:
  int echo_pin;
  int trigger_pin;
};

#endif
