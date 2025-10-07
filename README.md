# 🌧️🔥 Rain and Fire Sensor Alarm System

### 🧠 *A Digital Logic Design Project using Arduino Nano*

---

## 📄 Overview
This project — **Rain and Fire Sensor Alarm System** — is designed to detect rain and fire using sensors connected to an Arduino Nano.  
It activates a buzzer and displays the status on an LCD screen whenever rain or fire is detected.

---

## 🎯 Objectives
- ⚙️ Design a digital logic circuit to process inputs from rain and fire sensors.  
- 🚨 Implement an alarm system that triggers upon hazard detection.  
- ✅ Ensure reliable and accurate readings from sensors.  
- 🧩 Integrate all components to form a working prototype.

---

## 💡 Benefits
### 🏠 Home Safety
- 🔥 Early fire detection prevents accidents.  
- 🌧️ Rain alerts help avoid water damage.

### 🌾 Agriculture
- 🌱 Protects crops from excessive rain.  
- 🌲 Early wildfire warning system.

### 🏭 Industrial Use
- 🧯 Monitors fire hazards in factories.  
- 💧 Prevents machinery damage from water.

### 🏢 Smart Buildings
- 🤖 Enables automated environmental response.  
- 📡 Enhances overall safety and disaster preparedness.

---

## 🧰 Components Used
|No.| 🧩 Component             | ⚙️ Description |
 
| 1 | Arduino Nano              | Microcontroller |
| 2 | Rain Sensor               | Detects moisture |
| 3 | Flame Sensor              | Detects infrared light from fire |
| 4 | LCD (16x2) with I2C       | Displays system status |
| 5 | Buzzer 5V                 | Sounds the alarm |
| 6 | LED                       | Visual indicator |
| 7 | Resistors (1kΩ, 150Ω)     | Current limiting |
| 8 | Breadboard & Jumper Wires | Circuit connections |
| 9 | 9V Battery                | Power source |

---

## ⚙️ Circuit Connections

- **Rain Sensor** → `VCC → 5V`, `GND → GND`, `OUT → A0`  
- **Flame Sensor** → `VCC → 5V`, `GND → GND`, `D0 → A1`  
- **LCD I2C** → `VCC → 5V`, `GND → GND`, `SDA → A4`, `SCL → A5`  
- **Buzzer** → `+ → D3`, `- → GND`  
- **LED** → `Anode → D4` via 150Ω, `Cathode → GND`  

---

## 💻 Arduino Code Snippet
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int rainSensorPin = A1;
const int flameSensorPin = A0;
const int buzzerPin = 9;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(rainSensorPin, INPUT);
  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("Rain:");
  lcd.setCursor(0,1);
  lcd.print("Fire:");
}

void loop() {
  bool isRaining = digitalRead(rainSensorPin) == LOW;
  bool isFire = digitalRead(flameSensorPin) == LOW;

  lcd.setCursor(6,0);
  lcd.print(isRaining ? "Yes" : "No ");
  
  lcd.setCursor(6,1);
  lcd.print(isFire ? "Yes" : "No ");

  digitalWrite(buzzerPin, (isRaining || isFire) ? HIGH : LOW);
  delay(100);
}
