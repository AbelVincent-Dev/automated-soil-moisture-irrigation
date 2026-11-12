# Automated Soil Moisture Detection & Irrigation

An automated plant watering system built with an **Arduino Uno**, a **capacitive soil moisture sensor**, a **5V relay module**, and a **DC water pump**. 
The system continuously monitors soil moisture levels and triggers real-time irrigation cycles only when soil drops below a calibrated threshold, preventing both under- and over-watering.

## Hardware Components
* Arduino Uno Microcontroller
* Capacitive Soil Moisture Sensor (v1.2 / v2.0)
* 5V Single-Channel Relay Module[cite: 2]
* Mini Submersible DC Water Pump + Battery Power Supply
* Jumper Wires & Breadboard

## Pin Connections
| Component | Pin | Arduino Uno Pin |
| :--- | :--- | :--- |
| Soil Moisture Sensor | VCC / GND | 5V / GND |
| Soil Moisture Sensor | AOUT | A0 |
| 5V Relay Module | VCC / GND | 5V / GND |
| 5V Relay Module | IN | D7 |

## How It Works
1. **Sensing:** The analog pin `A0` reads voltage changes from the capacitive moisture probe.
2. **Threshold Logic:** If the reading exceeds `DRY_THRESHOLD`, the Arduino switches digital pin `D7` to trigger the 5V relay and power the pump.
3. **Auto Shut-Off:** Once moisture reaches `WET_THRESHOLD`, the relay cuts power to the pump to prevent over-watering.
