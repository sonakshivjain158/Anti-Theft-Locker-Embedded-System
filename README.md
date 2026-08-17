# Anti-Theft-Locker-Embedded-System
An Industry-oriented embedded system implementing a secure electronic locker using Arduino UNO, keypad authentication, servo locking, LCD status display, failed-attempt detection, and buzzer-based security alerts with Wokwi simulation.

## Overview
The Anti-Theft Locker System is an embedded security system designed to protect valuables from unauthorized access.
The system uses a 4×4 keypad for password entry. The Arduino UNO processes the entered password and controls the locker mechanism based on authentication status.
If the password is correct, the locker unlocks and the green LED indicates successful access. If the password is incorrect, the attempt counter increases and the red LED indicates access denial. After three consecutive incorrect attempts, the buzzer alarm is activated and the locker remains locked.
The system also includes an automatic locking mechanism after successful access.

## Problem Statement
Traditional lockers generally depend on physical keys or basic mechanical locking mechanisms. Such systems can be vulnerable if keys are lost, duplicated, or accessed by unauthorized users.
This project demonstrates how an electronic access-control system can improve locker security using password authentication, automatic locking, failed-attempt detection, and alarm functionality.

## Objectives
* Implement keypad-based user authentication.
* Verify a user-entered password using a microcontroller.
* Control a servo motor as the locker locking mechanism.
* Display system status using a 16×2 I2C LCD.
* Indicate access status using red and green LEDs.
* Detect repeated incorrect password attempts.
* Activate a buzzer after three failed attempts.
* Automatically lock the locker after a successful access.
* Develop and test the complete system using virtual simulation.
* Document the project as an Embedded Systems proof of work on GitHub.

## Features
* 4×4 matrix keypad authentication
* Password masking using `*`
* Password verification
* Access granted and denied indication
* Servo-based lock and unlock mechanism
* 16×2 I2C LCD status display
* Green LED for successful authentication
* Red LED for denied access
* Failed-attempt counter
* Three-attempt security alarm
* Buzzer-based alert
* Automatic locker locking
* Wokwi virtual simulation
* Modular testing and debugging

## Components Used
| Component         | Purpose                        |
| ----------------- | ------------------------------ |
| Arduino UNO       | Main microcontroller           |
| 4×4 Matrix Keypad | Password input                 |
| Servo Motor       | Locker locking mechanism       |
| 16×2 I2C LCD      | System status display          |
| Buzzer            | Security alarm                 |
| Green LED         | Access granted indication      |
| Red LED           | Access denied/alarm indication |
| 220Ω Resistors    | LED current limiting           |
| Wokwi             | Virtual simulation platform    |

## Embedded Systems Concepts Used
* Microcontroller programming
* GPIO interfacing
* Matrix keypad interfacing
* Digital input and output
* Servo motor control
* PWM-based actuator control
* I2C communication
* LCD interfacing
* Password authentication
* String comparison
* Attempt counting
* Timer/delay-based control
* State-based control logic
* Embedded C/C++ programming
* Modular testing and debugging

## System Architecture
```text
                 ┌─────────────────┐
                 │   4×4 Keypad    │
                 └────────┬────────┘
                          │
                          ▼
                 ┌─────────────────┐
                 │   Arduino UNO   │
                 │                 │
                 │ Password Check  │
                 │ Attempt Counter │
                 │ Security Logic  │
                 └───────┬─────────┘
                         │
          ┌──────────────┼───────────────┐
          │              │               │
          ▼              ▼               ▼
       Servo            LCD            Buzzer
       Lock          16×2 I2C          Alarm
          │
          └──────────────┬───────────────┘
                         │
                 ┌───────┴───────┐
                 ▼               ▼
            Green LED        Red LED
            Granted          Denied
```

## Authentication Logic
```text
Start
  ↓
Locker Locked
  ↓
Enter Password
  ↓
Password Verification
  ↓
 ┌───────────────┐
 │ Correct?      │
 └───────┬───────┘
         │
    ┌────┴────┐
   YES        NO
    │          │
    ▼          ▼
 Unlock     Attempt + 1
    │          │
    ▼          ▼
 Green LED   Red LED
    │          │
    ▼          ▼
 Auto-lock   3 Attempts?
               │
               ▼
             Alarm
```

## Security Rules
### Correct Password
* Access is granted.
* Green LED turns ON.
* Servo unlocks the locker.
* Failed-attempt counter is reset.
* Locker automatically locks after the configured delay.
### Wrong Password
* Access is denied.
* Red LED indicates the failed attempt.
* Failed-attempt counter increases.
* Locker remains locked.
### Three Wrong Attempts
* Locker remains locked.
* Red LED indicates the security condition.
* Buzzer alarm is activated.
* Further access is restricted according to the implemented security logic.

## Circuit Connections
### Keypad
| Keypad Pin | Arduino UNO |
| ---------- | ----------- |
| R1         | D2          |
| R2         | D3          |
| R3         | D4          |
| R4         | D5          |
| C1         | D6          |
| C2         | D7          |
| C3         | D8          |
| C4         | D13         |
### Servo
| Servo Pin | Arduino UNO |
| --------- | ----------- |
| Signal    | D9          |
| VCC       | 5V          |
| GND       | GND         |
### Buzzer
| Buzzer Pin | Arduino UNO |
| ---------- | ----------- |
| Positive   | D10         |
| Negative   | GND         |
### LEDs
| Component | Connection             |
| --------- | ---------------------- |
| Green LED | D11 → 220Ω → LED → GND |
| Red LED   | D12 → 220Ω → LED → GND |
### I2C LCD
| LCD Pin | Arduino UNO |
| ------- | ----------- |
| SDA     | A4          |
| SCL     | A5          |
| VCC     | 5V          |
| GND     | GND         |

## Project Structure
```text
Anti-Theft-Locker-Embedded-System/
│
├── arduino_code/
│   ├── keypad_test.ino
│   ├── lcd_test.ino
│   ├── servo_test.ino
│   ├── led_buzzer_test.ino
│   ├── password_input_test.ino
│   ├── password_authentication.ino
│   ├── attempt_detection.ino
│   └── anti_theft_locker.ino
│
├── simulation/
│
├── circuit_diagram/
│
├── screenshots/
│
└── README.md
```

## Simulation
The project is implemented and tested virtually using Wokwi.
The simulation contains:
* Arduino UNO
* 4×4 keypad
* Servo motor
* 16×2 I2C LCD
* Buzzer
* Red LED
* Green LED
### Simulation Workflow
1. Start the Wokwi simulation.
2. Verify that the locker starts in the locked state.
3. Enter the password using the keypad.
4. Press `#` to submit the password.
5. Enter the correct password to verify successful authentication.
6. Observe the green LED and servo unlock operation.
7. Wait for the automatic locking operation.
8. Enter an incorrect password.
9. Repeat incorrect passwords until the failed-attempt limit is reached.
10. Verify the red LED and buzzer alarm.

## Keypad Controls
```text
0–9  → Password digits
*    → Clear entered password
#    → Submit password
```

## Testing
The project was tested using individual component tests followed by complete system integration.
| Test                 | Condition                  | Expected Result                  |
| -------------------- | -------------------------- | -------------------------------- |
| Keypad Test          | Press keypad buttons       | Correct key detected             |
| LCD Test             | Start system               | LCD displays status              |
| Servo Lock Test      | Lock command               | Servo moves to locked position   |
| Servo Unlock Test    | Valid authentication       | Servo moves to unlocked position |
| Correct Password     | Valid password             | Access granted                   |
| Wrong Password       | Invalid password           | Access denied                    |
| Three Wrong Attempts | Three consecutive failures | Alarm activated                  |
| Auto-Lock            | Successful access          | Locker locks automatically       |
| Buzzer Test          | Security condition         | Buzzer activates                 |
| LED Test             | Access condition           | Correct LED activates            |

## Screenshots
Project screenshots are available in the `screenshots/` directory.
They demonstrate:
* Keypad testing
* LCD output
* Servo locked state
* Servo unlocked state
* Password entry
* Access granted
* Access denied
* Failed attempts
* Buzzer alarm
* LED status
* Serial Monitor output
* Complete simulation

## Test Results
The system successfully demonstrates the core security functions through virtual simulation, including password authentication, access control, servo locking/unlocking, status indication, failed-attempt detection, alarm activation, and automatic locking.
Detailed test evidence is available in the `screenshots/` directory.

## How to Run
### Virtual Simulation
1. Open the Wokwi simulation.
2. Verify the circuit connections.
3. Open the Arduino source code.
4. Start the simulation.
5. Enter the password using the keypad.
6. Observe the LCD, LEDs, servo, and buzzer.
7. Test both valid and invalid authentication cases.

## Future Improvements
The current implementation focuses on keypad-based authentication and virtual simulation.
Possible future improvements include:
* RFID authentication
* Fingerprint authentication
* Vibration/tamper detection
* EEPROM-based password storage
* ESP32-based Wi-Fi connectivity
* Mobile notifications
* GSM alerts
* Access-event logging
* Cloud database integration
* Multiple authorized users
* Administrative access control
* PCB implementation
* Physical locker enclosure

## Industry Relevance
Electronic access-control systems can be applied to:
* Bank lockers
* Office lockers
* Hotel safes
* School and college lockers
* Warehouse storage
* Industrial storage cabinets
* Home security systems
* Electronic access-control systems
The project demonstrates concepts relevant to embedded security, automation, access control, sensor/actuator interfacing, and microcontroller-based system design.

## Learning Outcomes
Through this project, the following concepts were practiced:
* Arduino programming
* Embedded C/C++
* GPIO interfacing
* Matrix keypad interfacing
* LCD and I2C communication
* Servo motor control
* Password authentication
* Security logic
* Alarm handling
* State-based control
* Virtual circuit simulation
* Embedded system testing
* Git and GitHub version control

## Author
**Sonakshi V Jain**
Embedded Systems Project
**Project:** Anti-Theft Locker System
