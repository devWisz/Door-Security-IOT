# ESP8266 Door Security System using Blynk

This project is a simple IoT-based door security system built using an ESP8266 (NodeMCU) and Blynk Cloud.  
When the door is opened, the system immediately sends a notification alert to the user's smartphone.

The system can be enabled or disabled remotely using the Blynk mobile application to avoid false alerts.

---

## Project Overview

The ESP8266 continuously monitors a door sensor connected to a GPIO pin.  
When the system is armed and the door changes its state to open, a notification event is triggered through Blynk Cloud.

The system automatically disables itself after detecting a door open event to prevent repeated alerts.

---

## Features

- Real-time door open alert on mobile phone
- Enable or disable monitoring using Blynk app
- Uses Blynk Cloud for communication
- Prevents duplicate notifications
- Simple and beginner-friendly logic
- Easily extendable for future upgrades

---

## Hardware Requirements

- ESP8266 NodeMCU
- Magnetic reed switch or door sensor
- Jumper wires
- Stable WiFi connection

---

## Pin Configuration

| ESP8266 Pin | Function |
|------------|----------|
| D1         | Door sensor input |
| GND        | Sensor ground |
| 3.3V       | Sensor power (if required) |

The door sensor should output HIGH when the door is opened.

---

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Blynk IoT Platform
- Blynk Library for ESP8266

---

## Blynk App Setup

1. Create a new project in Blynk IoT Dashboard
2. Select device type as ESP8266
3. Create a Button widget
   - Virtual Pin: V0
   - Mode: Switch
4. Create an Event in Blynk
   - Event Name: door_opened
5. Copy the following credentials from Blynk:
   - BLYNK_TEMPLATE_ID
   - BLYNK_TEMPLATE_NAME
   - BLYNK_AUTH_TOKEN

Paste them into the source code.

---

## WiFi Configuration

Update the following lines in the code with your WiFi credentials:

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

---

## How the System Works

1. The system remains idle until enabled from the Blynk app.
2. When enabled, the ESP8266 checks the door sensor every second.
3. If the door opens while the system is enabled:
   - A notification is sent to the phone
   - The system disables itself automatically
   - The button state is reset in the Blynk app
4. The system must be manually re-enabled from the app for further monitoring.

---

## Code File

The main Arduino file should be named:

DoorSecurity_Blynk_ESP8266.ino

---

## Folder Structure

esp8266-blynk-door-security
|
|-- DoorSecurity_Blynk_ESP8266.ino
|-- README.md

---

## Timer Logic

The system uses BlynkTimer to check the door sensor every 1000 milliseconds.

This interval can be reduced for faster response if required.

---

## Limitations

- No local alarm or buzzer
- Requires continuous WiFi connection
- No battery backup
- Basic single-door monitoring

---

## Future Improvements

- Add buzzer or siren
- Add battery power with deep sleep
- Add support for multiple doors
- Store access logs in cloud database
- Improve security and tamper detection

---

## Developed by
Sarjak Khanal

---

## License

This project is open-source and free to use for learning and educational purposes.

