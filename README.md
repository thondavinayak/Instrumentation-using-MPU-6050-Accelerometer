📌 Overview

This project demonstrates how to interface an MPU6050 accelerometer and gyroscope module with an Arduino to read motion data in real-time. The application captures acceleration and rotation values along all three axes (X, Y, Z), processes the data, and outputs it for further analysis or integration into embedded systems projects.

The example can be extended to applications such as:

Motion tracking

Orientation detection

Step counting

Gesture recognition

⚙️ Features

Reads accelerometer and gyroscope data from the MPU6050 using the I2C protocol.

Displays real-time X, Y, Z values via the Arduino Serial Monitor.

Easily adaptable for motion-based applications.

Minimal hardware setup and simple wiring.

🛠️ Hardware Requirements

Arduino Uno / Nano / Mega (or compatible board)

MPU6050 module

Jumper wires

Breadboard (optional)

🔌 Wiring Diagram
MPU6050 Pin	Arduino Pin
VCC	5V
GND	GND
SDA	A4
SCL	A5

(For Arduino Mega, use SDA → Pin 20 and SCL → Pin 21)


Open sketch_raw_data.ino in Arduino IDE.

▶️ Usage

Connect your MPU6050 to Arduino as per the wiring diagram.

Upload the code to your Arduino.

Open the Serial Monitor (Ctrl + Shift + M) and set baud rate to 115200.

Move the sensor and observe the changes in acceleration and rotation values.

📊 Example Output
Accel X:  0.12   Y: -0.05   Z:  9.81  m/s²
Gyro  X:  0.50   Y: -0.20   Z:  0.00  °/s
