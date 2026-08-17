const int buzzer = 10;
const int greenLED = 11;
const int redLED = 12;

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);

  Serial.println("LED and Buzzer Test");

  // Green LED
  digitalWrite(greenLED, HIGH);
  Serial.println("Green LED ON");
  delay(2000);

  digitalWrite(greenLED, LOW);

  // Red LED
  digitalWrite(redLED, HIGH);
  Serial.println("Red LED ON");
  delay(2000);

  digitalWrite(redLED, LOW);

  // Buzzer
  Serial.println("Buzzer ON");
  tone(buzzer, 1000);
  delay(2000);

  noTone(buzzer);

  Serial.println("Test Complete");
}

void loop() {
}
