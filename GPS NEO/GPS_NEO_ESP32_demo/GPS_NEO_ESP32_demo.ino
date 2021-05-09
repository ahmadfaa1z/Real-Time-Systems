#include <HardwareSerial.h>

int RXPin = 16;
int TXPin = 17;

//Default baud of NEO-6M is 9600
int GPSBaud = 9600;

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  Serial1.begin(GPSBaud,SERIAL_8N1,RXPin,TXPin);
}

void loop()
{
  // Displays information when new sentence is available.
  while (Serial1.available() > 0)
    Serial.write(Serial1.read());
}
