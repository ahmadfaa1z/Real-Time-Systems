#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

// Pins
static const int Button_1 = 21;
static const int Button_2 = 22;
static const int Button_3 = 23;

static const int LED_1 = 13;
static const int LED_2 = 12;
static const int LED_3 = 14;
static const int LED_4 = 27;
static const int LED_5 = 26;

// TASK(1): Upward Sequence
void Sequence_1(void *parameter) {
  while (1) {
    int Button_state1 = (digitalRead(Button_1));    
    if (Button_state1 == 1) {
      digitalWrite(LED_1, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_3, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_4, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_5, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);

      digitalWrite(LED_1, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_3, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_4, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_5, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
  }
}

void Sequence_2(void *parameter) {
  while (1) {
    int Button_state2 = (digitalRead(Button_2));
    if (Button_state2 == 1) {
      digitalWrite(LED_3, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, HIGH);
      digitalWrite(LED_4, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_5, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);

      digitalWrite(LED_3, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, LOW);
      digitalWrite(LED_4, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_5, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
  }
}

void Sequence_3(void *parameter) {
  while (1) {
    int Button_state3 = (digitalRead(Button_3));
    if (Button_state3 == 1) {
      digitalWrite(LED_5, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_4, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_3, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);
      digitalWrite(LED_1, HIGH);
      vTaskDelay(200 / portTICK_PERIOD_MS);

      digitalWrite(LED_5, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_4, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_3, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_2, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
      digitalWrite(LED_1, LOW);
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  pinMode(Button_2, INPUT);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);

  xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
    Sequence_1,  // Function to be called
    "Sequence 1",   // Name of task
    1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL,         // Parameter to pass to function
    1,            // Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,         // Task handle
    app_cpu);     // Run on one core for demo purposes (ESP32 only)

xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
    Sequence_2,  // Function to be called
    "Sequence 2",   // Name of task
    1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL,         // Parameter to pass to function
    1,            // Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,         // Task handle
    app_cpu);     // Run on one core for demo purposes (ESP32 only)

xTaskCreatePinnedToCore(  // Use xTaskCreate() in vanilla FreeRTOS
    Sequence_3,  // Function to be called
    "Sequence 3",   // Name of task
    1024,         // Stack size (bytes in ESP32, words in FreeRTOS)
    NULL,         // Parameter to pass to function
    1,            // Task priority (0 to configMAX_PRIORITIES - 1)
    NULL,         // Task handle
    app_cpu);     // Run on one core for demo purposes (ESP32 only)


  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.
}

void loop() {
  // Do nothing
  // setup() and loop() run in their own task with priority 1 in core 1
  // on ESP32
}
