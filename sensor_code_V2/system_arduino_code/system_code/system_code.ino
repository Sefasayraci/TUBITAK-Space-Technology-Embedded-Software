/////////////////////////////////////////////
// Sadece eklenecek olan pusula sensörü kaldı. O da lehimlenecek.
////////////////////////////////////////////

#include <Wire.h>
#include <Adafruit_BMP085.h>  // Adafruit BMP085 library
#include "I2Cdev.h" //I2C kütüphanesi
#include "MPU6050.h" //Mpu6050 kütüphanesi
#include "Wire.h"

Adafruit_BMP085 bmp;
MPU6050 accelgyro; // Mpu6050 sensör tanımlama
int16_t ax, ay, az; //ivme tanımlama
int16_t gx, gy, gz; //gyro tanımlama

void setup(){

 Wire.begin();
 Serial.begin(9600);
 accelgyro.initialize();

 if (!bmp.begin()) {
  while (true) {}
 }
}

void loop(){
 accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 Serial.print(bmp.readTemperature());Serial.print("/");
 Serial.print(bmp.readPressure());Serial.print("/");
 Serial.print(bmp.readAltitude());Serial.print("/");
 Serial.print(ax); Serial.print("/");
 Serial.print(ay); Serial.print("/");
 Serial.print(az); Serial.print("/");
 Serial.print(gx); Serial.print("/");
 Serial.print(gy); Serial.print("/");
 Serial.println(gz);
 
 delay(1000);
}
