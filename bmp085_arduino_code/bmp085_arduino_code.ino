#include <Wire.h>
#include <Adafruit_BMP085.h>  // Adafruit BMP085 library

Adafruit_BMP085 bmp;

void setup(){

 // init serial monitor
 Serial.begin(9600);

 // Sensor init
 if (!bmp.begin()) {
  Serial.println("No valid BMP085 sensor found!");
  while (true) {}
 }
}

void loop(){

 Serial.print("Temperature: ");
 Serial.print(bmp.readTemperature());
 Serial.print(" ");  // Here we have to cheat a little
 Serial.write(176);  // to show the "°" character
 Serial.println("C");

 Serial.print("Humidity: ");
 Serial.print(bmp.readPressure());
 Serial.println(" Pa");

 Serial.print("Height: ");
 Serial.print(bmp.readAltitude());
 Serial.println(" meter");

 Serial.println(); 
 delay(5000);      // wait 5 seconds
}
