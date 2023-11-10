#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
int x,y,z;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
#include <SoftwareSerial.h>
SoftwareSerial SoftSerial(2, 3);
void setup()
{
Serial.begin(9600);
SoftSerial.begin(9600);
pinMode(4,INPUT);
x=0;
y=0;
z=0;
if(!accel.begin())
{
Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
while(1);
}
}
void loop()
{
 sensors_event_t event;
 accel.getEvent(&event);
 Serial.print("X: "); Serial.print(x=event.acceleration.x); Serial.print(" ");
 Serial.print("Y: "); Serial.print(y=event.acceleration.y); Serial.print(" ");
 Serial.print("Z: "); Serial.print(z=event.acceleration.z); Serial.print("
");Serial.println("m/s^2 ");
 delay(500);
if(x>6)
{
SoftSerial.println("FALL DETECTED");
Serial.println("FALL DETECTED");
while(1);
}
if(digitalRead(4)==0)
{
SoftSerial.println("NEED HELP");
Serial.println("NEED HELP");
while(1);
}
} 