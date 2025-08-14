#include <Wire.h>

// MPU6050 registers
#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_ACCEL_YOUT_H 0x3D
#define MPU6050_ACCEL_ZOUT_H 0x3F
#define MPU6050_GYRO_XOUT_H 0x43
#define MPU6050_GYRO_YOUT_H 0x45
#define MPU6050_GYRO_ZOUT_H 0x47

// Accelerometer and gyroscope scaling factors
const float accel_scale = 16384.0; // for +/- 2g range
const float gyro_scale = 131.0;    // for +/- 250 deg/s range

// Raw data
float accel_x, accel_y, accel_z, gyro_x, gyro_y, gyro_z;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  initMPU6050();

}

void loop() {
  readMPU6050();
  printData();
  delay(1000);

}

void initMPU6050() {
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
}

void readMPU6050() {
  uint8_t data[14];
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14);
  while (Wire.available() < 14);
  for (uint8_t i = 0; i < 14; i++) {
    data[i] = Wire.read();
  }

  int16_t ax = (data[0] << 8 | data[1]);
  int16_t ay = (data[2] << 8 | data[3]);
  int16_t az = (data[4] << 8 | data[5]);
  int16_t gx = (data[8] << 8 | data[9]);
  int16_t gy = (data[10] << 8 | data[11]);
  int16_t gz = (data[12] << 8 | data[13]);

  accel_x = (float)ax / accel_scale;
  accel_y = (float)ay / accel_scale;
  accel_z = (float)az / accel_scale;
  gyro_x = (float)gx / gyro_scale;
  gyro_y = (float)gy / gyro_scale;
  gyro_z = (float)gz / gyro_scale;
}

void printData() {
  Serial.print("accel_x: ");
  Serial.print(accel_x);
  Serial.print(" accel_y: ");
  Serial.print(accel_y);
  Serial.print(" accel_z: ");
  Serial.println(accel_z);
  Serial.print("gyro_x: ");
  Serial.print(gyro_x);
  Serial.print(" gyro_y: ");
  Serial.print(gyro_y);
  Serial.print(" gyro_z: ");
  Serial.println(gyro_z);
}
