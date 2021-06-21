#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

#include <SPI.h>
#include <LoRa.h>
#include <HardwareSerial.h>
#include <TinyGPS++.h>

// Task Handles
//static TaskHandle_t task_1 = NULL;

// GPS
static const int RXPin = 16, TXPin = 17;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

// LoRa Transmitter Pins
#define SS 5
#define RST 4
#define DIO0 2

// Globals
int year_val;
int month_val;
int day_val;
int hour_val;
int minute_val;
int second_val;
float lat_val;
float lng_val;
double alt_cm;
double alt_m;
double alt_km;
double alt_f;
double speed_mps;
double speed_kmph;


// ----------- TASKS -----------

void gpsReader(void *parameter) {
  while (1) {
    while (Serial1.available() > 0) {
      gps.encode(Serial1.read());
      if (gps.date.isValid()) {
        year_val = gps.date.year();
        month_val = gps.date.month();
        day_val = gps.date.day();
      }
      if (gps.time.isValid()) {
        hour_val = 8 + gps.time.hour();
        minute_val = gps.time.minute();
        second_val = gps.time.second();
      }
      if (gps.location.isValid()) {
        lat_val = gps.location.lat();
      }
      if (gps.location.isValid()) {
        lng_val = gps.location.lng();
      }
      if (gps.altitude.isValid()) {
        alt_cm = gps.altitude.value();
        alt_m = gps.altitude.meters();
        alt_km = gps.altitude.kilometers();
        alt_f = gps.altitude.feet();
      }
      if (gps.speed.isValid()) {
        speed_mps = gps.speed.mps();
        speed_kmph = gps.speed.kmph();
      }

    }
    // try to detect if GPS is functioning
    if (millis() > 5000 && gps.charsProcessed() < 10)
      Serial.println(F("No GPS data received: check wiring"));

    // Wait for a while
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void loraSend(void *parameter) {
  while (1) {
    LoRa.beginPacket();

    Serial.println("------------------------------------");
    Serial.println("Sending packet:");
    Serial.println("------------------------------------");
    
    char arr1[32];
    sprintf(arr1, "DATE: %02d-%02d-%d ", month_val, day_val, year_val);
    Serial.println(arr1);
    
    char arr2[32];
    sprintf(arr2, "TIME: %02d:%02d:%02d ", hour_val, minute_val, second_val);
    Serial.println(arr2);

    Serial.print("ALTITUDE (in m): ");
    Serial.println(alt_m);

    Serial.print("LATITUDE: ");
    Serial.println(lat_val, 6);
    Serial.print("LONGITUDE: ");
    Serial.println(lng_val, 6);

    LoRa.println(arr1);
    LoRa.println(arr2);
    LoRa.print("ALTITUDE (in m): ");
    LoRa.println(alt_m);

    LoRa.print("LATITUDE: ");
    LoRa.println(lat_val, 6);
    LoRa.print("LONGITUDE: ");
    LoRa.println(lng_val, 6);
    
    LoRa.endPacket();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
  vTaskDelay(5000 / portTICK_PERIOD_MS);

  // setup LoRa
  LoRa.setPins(SS, RST, DIO0);
  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa connecting...");
    delay(500);
  }
  // Change sync word (0xF3) to match the receiver
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

  xTaskCreatePinnedToCore(
    gpsReader,
    "GPS Reader",
    4000,
    NULL,
    1,
    NULL,
    app_cpu
  );

  xTaskCreatePinnedToCore(
    loraSend,
    "Send to RX",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );
}

void loop() {

}
