#include <Wire.h>

#define MPU6050_ADDR 0x68
#define PWR   0x6B
#define GYRO_X  0x43
#define GYRO_Y  0x45
#define GYRO_Z  0x47

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(PWR);
  Wire.write(0);  
  Wire.endTransmission(true);
}

void loop() {
  int gyroZ;
  float yaw;

  gyroZ = readMPU6050(GYRO_Z);
  yaw = gyroZ / 131.0;

  Serial.print("Yaw: ");
  Serial.println(yaw);
  delay(500);
}

//a function to read the data of gyro 

int readMPU6050(int reg) {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true);

  int data = Wire.read() << 8 | Wire.read();
  return data;
}
