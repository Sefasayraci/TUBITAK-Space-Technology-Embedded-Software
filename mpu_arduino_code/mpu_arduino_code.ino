#include "I2Cdev.h" //I2C kütüphanesi
#include "MPU6050.h" //Mpu6050 kütüphanesi
#include "Wire.h"
MPU6050 accelgyro; // Mpu6050 sensör tanımlama
int16_t ax, ay, az; //ivme tanımlama
int16_t gx, gy, gz; //gyro tanımlama
  
void setup() {
Wire.begin();
Serial.begin(9600);
//Serial.println("I2C cihazlar başlatılıyor...");
accelgyro.initialize();
//Serial.println("Test cihazı bağlantıları...");
//Serial.println(accelgyro.testConnection() ? "MPU6050 bağlantı başarılı" : "MPU6050 bağlantısı başarısız");
}
  
void loop() {
accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // ivme ve gyro değerlerini okuma
  
//açısal ivmeleri ve gyro değerlerini ekrana yazdırma
//Serial.print("a/g:\t");
Serial.print(ax); Serial.print("/");
Serial.print(ay); Serial.print("/");
Serial.print(az); Serial.print("/");
Serial.print(gx); Serial.print("/");
Serial.print(gy); Serial.print("/");
Serial.println(gz);

//delay(1000);
}
