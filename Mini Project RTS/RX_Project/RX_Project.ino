#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

#include <SPI.h>
#include <LoRa.h>

// LoRa Receiver Pins
#define SS 18
#define RST 14
#define DIO0 26

void loraReceive(void *parameter) {
  while (1) {
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize > 0) {
      // received a packet
      Serial.println();
      Serial.println("************************************");
      Serial.println("Receiving packet:");
      Serial.println("************************************");

      // read packet
      while (LoRa.available()) {
        String LoRaData = LoRa.readString();
        Serial.print(LoRaData);
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");

  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
  // Change sync word (0xF3) to match the receiver
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

  xTaskCreatePinnedToCore(
    loraReceive,
    "Receive from TX",
    1024,
    NULL,
    1,
    NULL,
    app_cpu
  );
}

void loop() {

}
