#include <Arduino.h>
#include <hcsr04.h>

int pinOUT = 3;
int pinIN = 4;
float distance;
String unit;
HCSR04 sr04 = HCSR04(pinOUT, pinIN);

void setup() {
    // put your setup code here, to run once:

    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    unit = "CM";
    distance = sr04.getDistance(unit);
    Serial.print(distance);
    Serial.print(" ");
    Serial.println(unit);
    delay(500);
}
