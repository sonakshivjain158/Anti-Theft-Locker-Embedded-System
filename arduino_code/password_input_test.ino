#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

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

LiquidCrystal_I2C lcd(0x27, 16, 2);

String password = "";

void setup() {

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    // Clear password
    if (key == '*') {

      password = "";

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");

      Serial.println("Password Cleared");
    }

    // Submit password
    else if (key == '#') {

      Serial.print("Entered: ");

      for (int i = 0; i < password.length(); i++) {
        Serial.print("*");
      }

      Serial.println();

      password = "";

      lcd.clear();
      lcd.print("Password Sent");

      delay(1500);

      lcd.clear();
      lcd.print("Enter Password:");
    }

    // Add digit
    else {

      if (password.length() < 8) {

        password += key;

        lcd.setCursor(password.length() - 1, 1);
        lcd.print("*");
      }
    }
  }
}
