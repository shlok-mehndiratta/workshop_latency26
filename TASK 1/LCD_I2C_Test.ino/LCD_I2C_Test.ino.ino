/*
  PURPOSE:
  This code is only to test the 16x2 I2C LCD display.

  REQUIRED LIBRARY:
  - LiquidCrystal_I2C (by Frank de Brabander)
*/

#include <Wire.h>                    // Enables I2C communication
#include <LiquidCrystal_I2C.h>       // Library to control I2C LCD

#define SDA_PIN 21                   // ESP32 I2C SDA pin
#define SCL_PIN 22                   // ESP32 I2C SCL pin

// Create LCD object
// 0x27 = I2C address, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);      // Start I2C communication
  lcd.init();                        // Initialize LCD
  lcd.backlight();                   // Turn ON LCD backlight

  // -------- Serial Monitor --------
  Serial.begin(9600);
  Serial.println("LCD TEST | I2C Addr: 0x27 | Size: 16x2 | Status: OK");

  lcd.setCursor(0, 0);               // First row, first column
  lcd.print("LCD TEST");

  lcd.setCursor(0, 1);               // Second row
  lcd.print("Working Fine");
}

void loop() {
  // Nothing required here
}
