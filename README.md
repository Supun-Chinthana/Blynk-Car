# Blynk-Controlled Robot - School Project

A Wi-Fi controlled robot built on the ESP8266 microcontroller, remotely operated via the Blynk mobile app. The robot features two independently controlled motors and an HC-SR04 ultrasonic sensor for distance measurement.

---

## Features

- Remote control over Wi-Fi using the Blynk app (virtual pins V1 and V7)
- Dual motor control via an L298N motor driver
- Ultrasonic distance sensing using an HC-SR04 sensor
- Runs fully over a home Wi-Fi network with no extra hardware remote needed

---

## Hardware Required

| Component | Quantity |
|-----------|----------|
| ESP8266 NodeMCU or Wemos D1 Mini | 1 |
| L298N Motor Driver Module | 1 |
| DC Gear Motors | 2 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Robot chassis and wheels | 1 set |
| Li-Po or 18650 battery pack | 1 |
| Jumper wires | as needed |

---

## Pin Configuration

| GPIO Pin | Function |
|----------|----------|
| GPIO 16 (D0) | Motor A - IN1 |
| GPIO 5 (D1) | Motor A - IN2 |
| GPIO 0 (D3) | Motor B - IN3 |
| GPIO 2 (D4) | Motor B - IN4 |
| GPIO 14 (D5) | Ultrasonic TRIG |
| GPIO 12 (D6) | Ultrasonic ECHO |
| GPIO 13 (D7) | Spare sensor pin |

---

## Wiring

```
ESP8266       -->   L298N Motor Driver
GPIO 16       -->   IN1
GPIO 5        -->   IN2
GPIO 0        -->   IN3
GPIO 2        -->   IN4

ESP8266       -->   HC-SR04
GPIO 14       -->   TRIG
GPIO 12       <--   ECHO
3.3V          -->   VCC
GND           -->   GND
```

---

## Software Setup

### 1. Install Arduino IDE and Libraries

In the Arduino IDE, install these libraries via Library Manager (Sketch > Include Library > Manage Libraries):

- Blynk by Volodymyr Shymanskyy
- ESP8266WiFi (bundled with the ESP8266 board package)

Add the ESP8266 board package via File > Preferences, then add this URL under Board Manager URLs:

```
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

### 2. Set Up Blynk

1. Download the Blynk IoT app on iOS or Android
2. Create a new template and copy your Template ID and Auth Token
3. Add two Button widgets to your dashboard:
   - Button on V7 controls Motor A (right side)
   - Button on V1 controls Motor B (left side)
4. Set both buttons to Switch mode

### 3. Configure the Sketch

Open `School_project_robot.ino` and fill in your details:

```cpp
#define BLYNK_TEMPLATE_ID   "your_template_id"
#define BLYNK_TEMPLATE_NAME "your_template_name"
#define auth                "your_auth_token"

const char* ssid = "your_wifi_name";
const char* pass = "your_wifi_password";
```

Note: Never commit real credentials to a public repo. Store them in a secrets.h file and add it to .gitignore.

### 4. Upload

- Select board: NodeMCU 1.0 (ESP-12E Module) or your ESP8266 variant
- Set baud rate to 9600
- Upload, then open Serial Monitor to confirm the Wi-Fi connection

---

## How to Control

Once the robot is powered on and connected:

1. Open the Blynk app and go to your dashboard
2. Press the V7 button to run Motor A
3. Press the V1 button to run Motor B
4. Press both together to go forward, or independently to turn

---

## Ultrasonic Sensor

The get_distance() function triggers the HC-SR04 and returns the distance in centimetres:

```cpp
int dist = get_distance(trigPin, echoPin);
Serial.println(dist);
```

This can be extended to stop the motors automatically when an obstacle is detected within a set distance.

---

## Possible Improvements

- Implement obstacle avoidance using the ultrasonic sensor
- Add PWM speed control with an analogWrite slider in Blynk
- Display live distance on the Blynk dashboard
- Replace the two buttons with a joystick widget for smoother directional control
- Move credentials into a secrets.h file excluded from version control

---

## License

This project was built as a school project and is open for learning and experimentation. Feel free to modify and build on it!
