#include <Servo.h>

Servo lockServo;

void setup() {

  lockServo.attach(9);

  Serial.begin(9600);

  Serial.println("Servo Test");

  lockServo.write(0);
  Serial.println("LOCKED");

  delay(3000);

  lockServo.write(90);
  Serial.println("UNLOCKED");

  delay(3000);

  lockServo.write(0);
  Serial.println("LOCKED");
}

void loop() {
}
