#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -----------------------------
// KEYPAD
// -----------------------------

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 13};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);

// -----------------------------
// LCD
// -----------------------------

LiquidCrystal_I2C lcd(0x27, 16, 2);

// -----------------------------
// SERVO
// -----------------------------

Servo lockServo;

const int SERVO_PIN = 9;

// -----------------------------
// OUTPUTS
// -----------------------------

const int BUZZER_PIN = 10;
const int GREEN_LED = 11;
const int RED_LED = 12;

// -----------------------------
// SECURITY
// -----------------------------

String storedPassword = "1234";
String enteredPassword = "";

int failedAttempts = 0;

const int MAX_ATTEMPTS = 3;

// -----------------------------
// SETUP
// -----------------------------

void setup() {

  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  lockServo.attach(SERVO_PIN);

  // Start locked
  lockServo.write(0);

  lcd.init();
  lcd.backlight();

  showLockedScreen();
}

// -----------------------------
// MAIN LOOP
// -----------------------------

void loop() {

  char key = keypad.getKey();

  if (key) {

    handleKey(key);
  }
}

// -----------------------------
// KEYPAD HANDLER
// -----------------------------

void handleKey(char key) {

  // CLEAR
  if (key == '*') {

    enteredPassword = "";

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter Password:");

    Serial.println("Input Cleared");

    return;
  }

  // ENTER
  if (key == '#') {

    verifyPassword();

    return;
  }

  // DIGIT
  if (enteredPassword.length() < 8) {

    enteredPassword += key;

    lcd.setCursor(0, 1);

    lcd.print("*");
  }
}

// -----------------------------
// PASSWORD VERIFICATION
// -----------------------------

void verifyPassword() {

  if (enteredPassword == storedPassword) {

    accessGranted();
  }

  else {

    accessDenied();
  }

  enteredPassword = "";
}

// -----------------------------
// ACCESS GRANTED
// -----------------------------

void accessGranted() {

  failedAttempts = 0;

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Access Granted");

  lcd.setCursor(0, 1);
  lcd.print("Locker Open");

  Serial.println("ACCESS GRANTED");

  // Unlock
  lockServo.write(90);

  delay(5000);

  // Lock again
  lockServo.write(0);

  digitalWrite(GREEN_LED, LOW);

  lcd.clear();

  lcd.print("Locker Locked");

  Serial.println("AUTO LOCK");

  delay(1500);

  showLockedScreen();
}

// -----------------------------
// ACCESS DENIED
// -----------------------------

void accessDenied() {

  failedAttempts++;

  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Access Denied");

  lcd.setCursor(0, 1);
  lcd.print("Attempt: ");
  lcd.print(failedAttempts);

  Serial.print("ACCESS DENIED - Attempt ");
  Serial.println(failedAttempts);

  delay(1500);

  digitalWrite(RED_LED, LOW);

  if (failedAttempts >= MAX_ATTEMPTS) {

    activateAlarm();

    failedAttempts = 0;
  }

  showLockedScreen();
}

// -----------------------------
// ALARM
// -----------------------------

void activateAlarm() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("TOO MANY");

  lcd.setCursor(0, 1);
  lcd.print("ATTEMPTS!");

  Serial.println("!!! SECURITY ALARM !!!");

  digitalWrite(RED_LED, HIGH);

  tone(BUZZER_PIN, 1000);

  delay(5000);

  noTone(BUZZER_PIN);

  digitalWrite(RED_LED, LOW);

  Serial.println("Alarm Deactivated");
}

// -----------------------------
// LOCKED SCREEN
// -----------------------------

void showLockedScreen() {

  lockServo.write(0);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Locker Locked");

  delay(1000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}
