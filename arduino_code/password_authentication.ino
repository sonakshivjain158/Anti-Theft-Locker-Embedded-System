String storedPassword = "1234";
String enteredPassword = "1234";

void setup() {

  Serial.begin(9600);

  if (enteredPassword == storedPassword) {
    Serial.println("ACCESS GRANTED");
  }
  else {
    Serial.println("ACCESS DENIED");
  }
}

void loop() {
}

// Test 2
String storedPassword = "1234";
String enteredPassword = "1234";

void setup() {

  Serial.begin(9600);

  if (enteredPassword == storedPassword) {
    Serial.println("ACCESS GRANTED");
  }
  else {
    Serial.println("ACCESS DENIED");
  }
}

void loop() {
}
