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

// Task Handles for Task Scheduling
static TaskHandle_t printall;
static TaskHandle_t printpacket;
static TaskHandle_t promptdata;
static TaskHandle_t launch;

// Queue for passing data between tasks
static QueueHandle_t input_queue;
static const uint8_t msg_queue_len = 5;

// Timer
static TimerHandle_t one_shot_timer = NULL;
static TimerHandle_t auto_reload_timer = NULL;

// Mutex & Semaphore
static SemaphoreHandle_t mutex;
static SemaphoreHandle_t bin_sem;

// Globals
String day_val;
String month_val;
String year_val;
String hour_val;
String minute_val;
String second_val;
String alt_km;
String speed_kmph;
String lat_val;
String lng_val;
int packetnum = 0;

void myTimerCallback(TimerHandle_t xTimer) {

  // show # of packets received if timer id 1 expired
  if ((uint32_t)pvTimerGetTimerID(xTimer) == 1) {
    vTaskResume(printpacket);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    vTaskSuspend(printpacket);
  }
}

void loraReceive(void *parameter) {
  while (1) {
    packetnum++;
    int pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
      // received a packet
      String LoRaData = LoRa.readString();

      pos1 = LoRaData.indexOf('!');
      pos2 = LoRaData.indexOf('@');
      pos3 = LoRaData.indexOf('#');
      pos4 = LoRaData.indexOf('$');
      pos5 = LoRaData.indexOf('%');
      pos6 = LoRaData.indexOf('^');
      pos7 = LoRaData.indexOf('&');
      pos8 = LoRaData.indexOf('*');
      pos9 = LoRaData.indexOf('/');

      // Extracting part of the whole string into each data value
      day_val = LoRaData.substring(0, pos1);
      month_val = LoRaData.substring(pos1 + 1, pos2);
      year_val = LoRaData.substring(pos2 + 1, pos3);
      hour_val = LoRaData.substring(pos3 + 1, pos4);
      minute_val = LoRaData.substring(pos4 + 1, pos5);
      second_val = LoRaData.substring(pos5 + 1, pos6);
      alt_km = LoRaData.substring(pos6 + 1, pos7);
      speed_kmph = LoRaData.substring(pos7 + 1, pos8);
      lat_val = LoRaData.substring(pos8 + 1, pos9);
      lng_val = LoRaData.substring(pos9 + 1, LoRaData.length());
    }
  }
}

void printAll(void *parameter) {
  while (1) {
    xSemaphoreTake(mutex, portMAX_DELAY);
    Serial.println();
    Serial.println("************************************");
    Serial.println("RECEIVING packet:");
    Serial.println("************************************");

    char arr1[32];
    sprintf(arr1, "DATE: %02d-%02d-%d ", day_val.toInt(), month_val.toInt(), year_val.toInt());
    Serial.println(arr1);

    char arr2[32];
    sprintf(arr2, "TIME: %02d:%02d:%02d ", hour_val.toInt(), minute_val.toInt(), second_val.toInt());
    Serial.println(arr2);

    Serial.println("-------- ALTITUDE/HEIGHT --------");
    Serial.print("ALTITUDE: ");
    Serial.print(alt_km);
    Serial.println(" km");
    Serial.println("-------- SPEED --------");
    Serial.print("SPEED: ");
    Serial.print(speed_kmph);
    Serial.println(" kmph");
    Serial.println("-------- COORDINATE --------");
    Serial.print("LATITUDE: ");
    Serial.println(lat_val);
    Serial.print("LONGITUDE: ");
    Serial.println(lng_val);
    xSemaphoreGive(mutex);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void printPacketNum(void *parameters)
{
  while (1)
  {
    xSemaphoreTake(mutex, portMAX_DELAY);
    Serial.print("# of packets received: ");
    Serial.println(packetnum);
    xSemaphoreGive(mutex);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void promptData(void *parameter) {
  while (1) {
    char input;
    if (xQueueReceive(input_queue, (void *)&input, 0) == pdTRUE)
    {
      if (input == '5') {
        char arr1[32];
        sprintf(arr1, "DATE: %02d-%02d-%d ", day_val.toInt(), month_val.toInt(), year_val.toInt());
        xSemaphoreTake(mutex, portMAX_DELAY);
        Serial.println(arr1);
        xSemaphoreGive(mutex);
      }
      else if (input == '6') {
        char arr2[32];
        sprintf(arr2, "TIME: %02d:%02d:%02d ", hour_val.toInt(), minute_val.toInt(), second_val.toInt());
        xSemaphoreTake(mutex, portMAX_DELAY);
        Serial.println(arr2);
        xSemaphoreGive(mutex);
      }
      else if (input == '7') {
        xSemaphoreTake(mutex, portMAX_DELAY);
        Serial.println("-------- ALTITUDE/HEIGHT --------");
        Serial.print("ALTITUDE: ");
        Serial.print(alt_km);
        Serial.println(" km");
        xSemaphoreGive(mutex);
      }
      else if (input == '8') {
        xSemaphoreTake(mutex, portMAX_DELAY);
        Serial.println("-------- SPEED --------");
        Serial.print("SPEED: ");
        Serial.print(speed_kmph);
        Serial.println(" kmph");
        xSemaphoreGive(mutex);
      }
      else if (input == '9') {
        xSemaphoreTake(mutex, portMAX_DELAY);
        Serial.println("-------- COORDINATE --------");
        Serial.print("LATITUDE: ");
        Serial.println(lat_val);
        Serial.print("LONGITUDE: ");
        Serial.println(lng_val);
        xSemaphoreGive(mutex);
      }
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void launchRocket(void *parameter) {
  while (1) {
    // Copy the parameter into a local variable (from countdown)
    int cd_num = *(int *)parameter;

    // Release the binary semaphore so that the creating function can finish
    xSemaphoreGive(bin_sem);

    if (auto_reload_timer == NULL) {
      Serial.println("Could not create the timer");
    } else {
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      // Wait for the countdown and then starting the timers
      for (int i = cd_num; i > 0; i-- ) {
        printf("%d...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
      Serial.println("Launched!!");
      // Start timer (max block time if command queue is full)
      xTimerStart(auto_reload_timer, portMAX_DELAY);
    }
    // This task is to only setup the timer and will not run endlessly
    vTaskDelete(NULL);
  }
}

void setup() {
  long int countdown;

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

//  vTaskDelay(3000 / portTICK_PERIOD_MS);

  Serial.println("Set countdown time to launch rocket:");
  // Wait for input from Serial
  while (Serial.available() <= 0);
  // Read integer value
  countdown = Serial.parseInt();

  // Create Queue
  input_queue = xQueueCreate(msg_queue_len, sizeof(int));
  // Create binary semaphore before starting tasks
  bin_sem = xSemaphoreCreateBinary();
  // Create mutex
  mutex = xSemaphoreCreateMutex();
  // Create timer
  auto_reload_timer = xTimerCreate(
                        "Auto show # packet received",   // Name of timer
                        10000 / portTICK_PERIOD_MS,      // Period of timer (in ticks)
                        pdTRUE,                          // Auto-reload
                        (void *)1,                       // Timer ID
                        myTimerCallback);                // Callback function

  xTaskCreatePinnedToCore(
    loraReceive,
    "Receive from TX",
    5000,
    NULL,
    1,
    NULL,
    app_cpu
  );

  xTaskCreate(
    printPacketNum,
    "Print # of packets received",
    1024,
    NULL,
    1,
    &printpacket
  );
  vTaskSuspend(printpacket);

  xTaskCreate(
    launchRocket,
    "Start timer since launch",
    5000,
    (void *)&countdown,
    1,
    &launch
  );
  // Do nothing until binary semaphore has been returned
  xSemaphoreTake(bin_sem, portMAX_DELAY);
  vTaskSuspend(launch);

  xTaskCreate(
    printAll,
    "Print All Data from TX",
    5000,
    NULL,
    1,
    &printall
  );
  vTaskSuspend(printall);

  xTaskCreate(
    promptData,
    "Print Individual Data",
    1024,
    NULL,
    1,
    &promptdata
  );
  vTaskSuspend(promptdata);

  Serial.println(F("Type in your command: "));
  Serial.println("(1) to show all data in realtime");
  Serial.println("(2) for prompting choice of data");
  Serial.println("(3) to show # of packets received since");
  Serial.println("(4) to initiate launching rocket");
  Serial.println("(.) to EXIT");
}

void loop() {
  while (Serial.available()) {
    char input = Serial.read();
    xQueueSend(input_queue, (void *)&input, 10);
    if (input == '1') {
      vTaskResume(printall);
    }
    else if (input == '2') {
      vTaskResume(promptdata);
      Serial.println("(5) for DATE");
      Serial.println("(6) for TIME");
      Serial.println("(7) for ALTITUDE");
      Serial.println("(8) for SPEED");
      Serial.println("(9) for COORDINATE");
    }
    else if (input == '3') {
      vTaskResume(printpacket);
    }
    else if (input == '4') {
      vTaskResume(launch);
    }
    else if (input == '.') {
      Serial.println(F("Type in your command: "));
      Serial.println("(1) to show all data in realtime");
      Serial.println("(2) for prompting choice of data");
      Serial.println("(3) to show # of packets received since");
      Serial.println("(4) to initiate launching rocket");
      Serial.println("(.) to EXIT");
      vTaskSuspend(printall);
      vTaskSuspend(printpacket);
      vTaskSuspend(promptdata);
    }
  }
}
