#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Initialize the LCD, the address 0x27 is common for 16x2 I2C LCDs.
LiquidCrystal_I2C lcd(0x27, 16, 2);
// Pin definitions
const int rainSensorPin = A1;
const int flameSensorPin = A0;
const int rainLEDPin = 10; // Define rain LED pin
const int flameLEDPin = 10; // Define flame LED pin
const int buzzerPin = 9; // Define buzzer pin
void setup() {
// Initialize the LCD
Serial.begin(9600);
pinMode(12,OUTPUT);
lcd.init();
lcd.backlight();
// Set up the pins
pinMode(rainSensorPin, INPUT);
pinMode(flameSensorPin, INPUT);
pinMode(rainLEDPin, OUTPUT);
pinMode(flameLEDPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
// Start with LEDs and buzzer off
digitalWrite(rainLEDPin, LOW);
digitalWrite(flameLEDPin, LOW);
digitalWrite(buzzerPin, LOW);
// Print initial message
lcd.setCursor(0, 0);
lcd.print("Rain: ");
lcd.setCursor(0, 1);
lcd.print("Fire: ");
}
void loop() {
// Read sensor values
bool isRaining = digitalRead(rainSensorPin) == LOW;
bool isFireDetected = digitalRead(flameSensorPin) == LOW;
// Update the rain status on the LCD and LED

RAIN AND FIRE SENSOR ALARM DLD PROJECT REPORT

P a g e | 5

lcd.setCursor(6, 0);
if (isRaining) {
lcd.print("Yes");
digitalWrite(rainLEDPin, HIGH);
digitalWrite(buzzerPin, HIGH);
} else {
lcd.print("No ");
digitalWrite(rainLEDPin, LOW);
digitalWrite(buzzerPin, LOW);
}
// Update the fire status on the LCD, LED, and buzzer
lcd.setCursor(6, 1);
if (isFireDetected) {
lcd.print("Yes");
digitalWrite(flameLEDPin, HIGH);
digitalWrite(buzzerPin, HIGH);
} else {
lcd.print("No ");
digitalWrite(flameLEDPin, LOW);
digitalWrite(buzzerPin, LOW);
}
// Small delay to avoid excessive updating
delay(60);
}