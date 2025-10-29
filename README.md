# Ultrasonic-Radar-System-Using-Arduino
A real-time ultrasonic radar system using Arduino, HC-SR04, and SG90 servo motor for object detection and visualization with Python-based live radar display.

# Ultrasonic Radar (Servo + HC-SR04)

A simple rotating ultrasonic radar using an Arduino, SG90 servo, and HC-SR04 sensor.  
Outputs JSON to Serial for easy visualization with desktop tools (Python, Processing, etc.)

---

## Features
- Sweeps 0°–180° and back
- Measures distance (cm) at each angle
- Outputs JSON lines: {"angle":45,"dist":120} (dist=null if out-of-range)
- Python visualizer included (optional)

---

## Parts
- Arduino Uno / Nano
- SG90 servo
- HC-SR04 ultrasonic sensor
- Jumper wires & breadboard
- USB cable

---

## Wiring
- Servo signal -> D9 ; Vcc -> 5V ; GND -> GND  
- HC-SR04 TRIG -> D7 ; ECHO -> D6 ; VCC -> 5V ; GND -> GND

---

## Usage
1. Upload Radar_Arduino.ino to your Arduino.  
2. Open Serial Monitor at 115200 to see JSON output.  
3. (Optional) Run radar_visualizer.py on your PC (install pyserial, matplotlib, numpy) and set COM_PORT.

---

## Notes & Tips
- If servo causes Arduino resets, power servo from separate 5V supply and connect grounds.
- Increase/decrease stepDeg or servoDelayMs in sketch to change resolution and speed.
- For more robust distance readings use averaging or the NewPing library.
- Want 360°? add a simple 180° mirror or use a continuous rotation setup with multiple sensors.

---
