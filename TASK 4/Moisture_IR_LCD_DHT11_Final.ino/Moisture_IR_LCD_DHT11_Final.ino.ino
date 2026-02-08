/*
  ==========================================
  FINAL PROJECT:
  LCD + DHT11 + IR + MOISTURE + BUZZER
  ==========================================

  This is the FINAL combined file.

  Required Libraries:
  - LiquidCrystal_I2C
  - DHT sensor library (Adafruit)
  - Adafruit Unified Sensor
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// -------- Pin Definitions --------
#define DHTPIN 5
#define DHTTYPE DHT11
#define IR_PIN 4
#define MOISTURE_PIN 13
#define BUZZER 23

// -------- Object Creation --------
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  dht.begin();
  pinMode(IR_PIN, INPUT);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // -------- Serial Monitor --------
  Serial.begin(9600);
  Serial.println("System Initializing...");

  lcd.setCursor(0, 0);
  lcd.print("EECS CLUB");
  Serial.println("LCD: EECS CLUB");

  delay(1800);
  lcd.clear();
}

void loop() {
  int irState = digitalRead(IR_PIN);

  // ---- IR HAND DETECTION ----
  if (irState == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bhaag, Hatt");

    Serial.print("IR DETECTED → Bhaag, Hatt ; BUZZER ON ,");

    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);

    Serial.println("Buzzer OFF");
    Serial.println("------------------------------------------------");

    return;
  }

  // ---- SENSOR READINGS ----
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int moistureRaw = analogRead(MOISTURE_PIN);

  int moisturePercent = map(moistureRaw, 4095, 0, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // ---- SERIAL OUTPUT ----
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  // ---- LCD DISPLAY ----
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C H:");
  lcd.print(humidity);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(moisturePercent);
  lcd.print("%");

  // ---- MOISTURE ALERT ----
  if (moisturePercent > 60) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tsunami AA Gayi");

    Serial.println("ALERT: Soil moisture too high!");
    Serial.println("Tsunami AA Gayi");
    Serial.println("------------------------");

    delay(1000);
    return;
  }

  Serial.println("------------------------");
  delay(2000);
}
