# 🔊 Sound Level Alarm System using ESP32 + OLED + Buzzer

This project implements an **infant cry detection and alert system** using an **ESP32**, a **microphone sensor**, an **OLED display**, and a **buzzer**. The system measures ambient noise and classifies it as either normal or loud. When a loud sound is detected, it activates an LED and buzzer, and displays a warning on the screen.

---

## 🛠️ Features

- 🧠 Converts analog sound input into decibels (dB)
- 📟 Displays sound status on an OLED screen
- 🚨 Triggers buzzer and LED when sound exceeds threshold
- 🔍 Real-time monitoring via Serial Monitor

---

## 🔌 Hardware Requirements

| Component              | Quantity |
|------------------------|----------|
| ESP32 Board            | 1        |
| Analog Sound Sensor    | 1        |
| OLED Display (SSD1306) | 1        |
| Buzzer                 | 1        |
| LED + Resistor         | 1        |
| Jumper Wires & Breadboard | —    |

---

## ⚙️ Pin Connections

| ESP32 Pin | Connected To        |
|-----------|---------------------|
| GPIO 34   | Microphone output   |
| GPIO 25   | Buzzer              |
| GPIO 2    | LED                 |
| SDA (21)  | OLED SDA            |
| SCL (22)  | OLED SCL            |

---

## 🧪 Threshold Settings

```cpp
#define LOW_SOUND_THRESHOLD 60
#define HIGH_SOUND_THRESHOLD 100
