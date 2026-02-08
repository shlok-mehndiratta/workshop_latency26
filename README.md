# EECS IoT Workshop – Complete Beginner Guide

## Smart Environment Monitoring and Alert System using ESP32

---

## 📌 About This Repository

This repository contains the complete documentation and resources for the **EECS IoT Workshop**. It is designed for **absolute beginners** and follows a step-by-step learning approach, starting from basic setup and ending with a fully integrated IoT project.

Participants will learn how to interface multiple sensors with ESP32/NodeMCU and display real-time data on an LCD.

---

## 📖 How to Use This Guide

* Follow the tasks in order (Task 1 → Final Project)
* Do not skip any task
* Each task has its own folder and code
* Copy the code from the respective folder
* Paste it into Arduino IDE
* Upload to your board

This guide can also be exported as a PDF for offline learning.

---

## 📑 Table of Contents

1. Workshop Overview
2. Software Setup (Arduino IDE)
3. Hardware Fundamentals
4. Repository Structure
5. Task 1: LCD Setup
6. Task 2: DHT11 Integration
7. Task 3: IR Sensor & Buzzer
8. Task 4: Soil Moisture Sensor
9. Final Project Integration
10. Testing & Debugging
11. Practice Exercises
12. References
13. Future Expansion
14. Contributors & License

---

## 1. Workshop Overview

### Objective

The goal of this workshop is to help beginners build a smart monitoring system using IoT concepts.

### What You Will Learn

* ESP32/NodeMCU basics
* Sensor interfacing
* LCD communication
* Arduino IDE usage
* Real-time monitoring
* Alert systems

### Final Output

A system that displays:

* Temperature (°C)
* Humidity (%)
* Soil Moisture (%)

And triggers alerts using IR sensor and buzzer.

---

## 2. Software Setup (Arduino IDE)

### Step 1.1: Download Arduino IDE

Download from: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)

### Step 1.2: Install USB-to-Serial Drivers [LINK](https://drive.google.com/drive/folders/1_5TbIT9GiW2gZshUFSvet_-q4AdfdNoO?usp=drive_link)
--------------------------------------------------

Install BOTH drivers (safe even if only one is used).

1) CH340 / CH340C Driver
   - Manufacturer: WCH
   - Install the driver for your operating system
   - Restart computer if prompted

2) CP2102 Driver
   - Manufacturer: Silicon Labs
   - Install the CP210x USB-to-UART driver
   - Restart computer if prompted

### Step 2: Install Arduino IDE

Follow the installation steps for your operating system.

### Step 3: Add ESP32 Board

1. Open Arduino IDE
2. Go to File → Preferences
3. Add this snippet in Additional Boards Manager:
    ```
   https://dl.espressif.com/dl/package_esp32_index.json,
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
5. Go to Tools → Board → Boards Manager
6. Search for ESP32 and install

### Step 4: Select Board and Port

* Board: ESP32 Dev Module / NodeMCU
* Port: Select correct COM port

### Step 5: Install Required Libraries

* LiquidCrystal_I2C (by Martin Kubovčík, Frank de..)
* DHT Sensor Library (by adafruit)
* Adafruit Unified Sensor (by adafruit)

Install from: Sketch → Include Library → Manage Libraries

---

## 3. Hardware Fundamentals

### Main Components

* ESP32 / NodeMCU(esp8266)
* I2C LCD (16x2)
* DHT11
* IR Sensor
* Soil Moisture Sensor
* Buzzer
* Breadboard
* Jumper Wires

### Power Pins

* 3.3V / 5V: Power supply
* GND: Ground

### GPIO Pins

GPIO pins are used for sensor connections and control signals.

### Breadboard Basics

* Center gap separates power rails
* Rows are internally connected

### Safety Rules

* Do not short circuit
* Check power before connecting
* Disconnect USB while wiring

---

## 4. Repository Structure

```
EECS-IOT-Workshop/
│
├── README.md
│
├── Task-1-LCD/
│   └── lcd_code.ino
│
├── Task-2-DHT/
│   └── dht_code.ino
│
├── Task-3-IR/
│   └── ir_buzzer_code.ino
│
├── Task-4-Soil/
│   └── soil_code.ino
│
└── Final-Project/
    └── final_code.ino
```

Each folder contains the code for that task.

---

## 5. Task 1: LCD Display Setup

### Objective

Connect and test the LCD with ESP32.

### Components

* ESP32
* I2C LCD
* Jumper Wires

### Typical Connections

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO 21   |
| SCL     | GPIO 22   |

### Steps

1. Connect LCD as per table
2. Open `Task-1-LCD/lcd_code.ino`
3. Copy code to Arduino IDE
4. Upload to board

### Expected Output

* LCD displays welcome message

### Troubleshooting

* Check I2C address
* Adjust contrast
* Verify connections

---

## 6. Task 2: DHT11 Temperature & Humidity

### Objective

Display temperature and humidity on LCD.

### Components

* DHT11
* LCD
* ESP32

### Typical Connections

| DHT11 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| DATA      | GPIO 5    |
| GND       | GND       |

### Steps

1. Connect DHT11
2. Open `Task-2-DHT/dht_code.ino`
3. Upload code

### Expected Output

* LCD shows temperature and humidity

### Notes

* Wait 2 seconds between readings

---

## 7. Task 3: IR Sensor & Buzzer

### Objective

Detect nearby objects and trigger alert.

### Components

* IR Sensor
* Buzzer
* ESP32

### Typical Connections

| Component | ESP32 Pin |
| --------- | --------- |
| IR OUT    | GPIO 4    |
| Buzzer    | GPIO 23   |

### Steps

1. Connect IR and buzzer
2. Open `Task-3-IR/ir_buzzer_code.ino`
3. Upload code

### Expected Output

* Message displayed on detection

---

## 8. Task 4: Soil Moisture Sensor

### Objective

Measure soil moisture percentage.

### Components

* Soil Sensor
* ESP32

### Typical Connections

| Sensor Pin | ESP32 Pin |
| ---------- | --------- |
| VCC        | 3.3V      |
| AO         | GPIO 13   |
| GND        | GND       |

### Steps

1. Connect soil sensor
2. Open `Task-4-Soil/soil_code.ino`
3. Upload code

### Expected Output

* Moisture percentage on LCD
* Buzzer activates (when hand is placed on IR sensor)

### Calibration

* Dry soil → Low value
* Wet soil → High value

---

## 9. Final Project Integration

### Objective

Combine all components into one system.

### Features

* Displays temperature
* Displays humidity
* Displays moisture
* Detects objects
* Triggers buzzer
* Shows alerts

### Alert Conditions

* IR Detection → Alert message + buzzer
* Moisture > 60% → Warning message

### Steps

1. Connect all components
2. Open `Final-Project/final_code.ino`
3. Upload code

### LCD Format

Line 1: Temp & Humidity
Line 2: Moisture & Status

---

## 10. Testing & Debugging

### Common Issues

#### Upload Failed

* Check COM port
* Press boot button

#### Blank LCD

* Check SDA/SCL
* Verify address

#### Sensor Not Working

* Check power
* Verify pin numbers

#### Library Error

* Reinstall libraries

---

## 11. Practice Exercises

1. Change moisture threshold
2. Modify alert messages
3. Add custom buzzer tones
4. Display date/time

---

## 12. References

* Arduino Documentation
* ESP32 Official Docs
* DHT11 Datasheet
* I2C LCD Guide
* Sensor Tutorials

---

## 13. Future Expansion

* Wi-Fi Connectivity
* Cloud Dashboard
* Mobile App
* Automatic Irrigation
* Smart Alerts

---

## 14. Contributors

EECS CLUB

### Workshop

EECS IoT Workshop



