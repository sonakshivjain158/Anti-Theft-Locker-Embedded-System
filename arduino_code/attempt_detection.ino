String storedPassword = "1234";

int failedAttempts = 0;

void setup() {

  Serial.begin(9600);

  checkPassword("1111");
  checkPassword("2222");
  checkPassword("3333");
}

void loop() {
}

void checkPassword(String enteredPassword) {

  if (enteredPassword == storedPassword) {

    Serial.println("ACCESS GRANTED");

    failedAttempts = 0;
  }

  else {

    failedAttempts++;

    Serial.print("ACCESS DENIED - Attempt ");
    Serial.println(failedAttempts);

    if (failedAttempts >= 3) {

      Serial.println("ALARM ACTIVATED!");
    }
  }
}
