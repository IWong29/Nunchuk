#include "Nunchuk.h"
#define LED 13

Nunchuk chuk;

void setup() {
    pinMode(LED, OUTPUT);
    Serial.begin(115200);
    chuk.begin();
    Serial.println("Initialized.");
    delay(1000);
}

void loop() {
    if(chuk.getC()) Serial.println("C");
    if(chuk.getZ()) Serial.println("Z");
    Serial.print(chuk.getJoystick(0)); Serial.print(", "); Serial.println(chuk.getJoystick(1));
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);

}