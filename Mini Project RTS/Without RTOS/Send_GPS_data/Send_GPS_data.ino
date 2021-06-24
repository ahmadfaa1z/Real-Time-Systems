/*

GPS data sent does not updated properly

*/

#include <SPI.h>
#include <LoRa.h>
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// GPS
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

// LoRa Transmitter Pins
#define SS 5
#define RST 4
#define DIO0 2

// Variables

void setup() {
  Serial.begin(115200);
  Serial1.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);

  while (!Serial);
  Serial.println("Lora Transmitter");

  // setup LoRa
  LoRa.setPins(SS, RST, DIO0);

  // replace the LoRa.begin(---E-) argument with your location's frequency
  // 433E6 for Asia
  // 866E6 for Europe
  // 915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa connecting...");
    delay(500);
  }
  // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

}

void loop() {

  // GPS data
  if (Serial1.available() > 0) {
    gps.encode(Serial1.read());
    if (gps.time.isUpdated()) {

      LoRa.beginPacket();

      Serial.println("------------------------------------");
      Serial.println("Sending packet:");
      Serial.println("------------------------------------");
      
      // Raw date in DDMMYY format (u32)
      Serial.print("Raw date DDMMYY = ");
      Serial.println(gps.date.value());

      // Year (2000+) (u16)
      Serial.print("Year = ");
      Serial.println(gps.date.year());
      // Month (1-12) (u8)
      Serial.print("Month = ");
      Serial.println(gps.date.month());
      // Day (1-31) (u8)
      Serial.print("Day = ");
      Serial.println(gps.date.day());

      // Second (0-59) (u8)
      Serial.print("Second = ");
      Serial.println(gps.time.second());

      // Raw date in DDMMYY format (u32)
      LoRa.print("Raw date DDMMYY = ");
      LoRa.println(gps.date.value());

      // Year (2000+) (u16)
      LoRa.print("Year = ");
      LoRa.println(gps.date.year());
      // Month (1-12) (u8)
      LoRa.print("Month = ");
      LoRa.println(gps.date.month());
      // Day (1-31) (u8)
      LoRa.print("Day = ");
      LoRa.println(gps.date.day());

      // Second (0-59) (u8)
      LoRa.print("Second = ");
      LoRa.println(gps.time.second());

      LoRa.endPacket();

      Serial.println();
      delay(5000);
    }
  }


}
