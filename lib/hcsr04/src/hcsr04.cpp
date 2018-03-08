
#include <hcsr04.h>

HCSR04::HCSR04(uint8_t trig_pin, uint8_t ech_pin)
{
  trigger_pin = trig_pin;
  pinMode(trig_pin, OUTPUT);
  echo_pin = ech_pin;
  pinMode(echo_pin, INPUT);
}

void HCSR04::sendPulse(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

int HCSR04::getEchoTime(){
  sendPulse();
  int timeout= 30000;
  int duration = pulseIn(echo_pin, HIGH, timeout);
  return duration;
}

float HCSR04::getDistance(String unit){
  float duration = getEchoTime();
  if (unit == "CM"){
    float distanceCM = duration/58.0;
    return distanceCM;
} else if (unit == "IN") {
    float distanceIN = duration/148.0;
    return distanceIN;
  }

  else {
    Serial.println("Wrong Units");}
}
