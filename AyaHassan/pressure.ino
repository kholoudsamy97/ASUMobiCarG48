#include <util/delay.h>
#include "Adafruit_BMP085.h"

#include <Wire.h>
Adafruit_BMP085 bmp;


void setup() {
 
bmp.begin();
 Serial.begin(9600);
}

void loop() {


//pressure

Serial.print("Temperature =");
Serial.print(bmp.readTemperature());
Serial.println(" *C ");
Serial.print(" Pressure = ");
Serial.print(bmp.readPressure ());
Serial.println(" Pa ");
Serial.print("Altitude = ");
Serial.print(bmp.readAltitude(101253));
Serial.println(" Meters ");
Serial.println();
delay (500);

}
