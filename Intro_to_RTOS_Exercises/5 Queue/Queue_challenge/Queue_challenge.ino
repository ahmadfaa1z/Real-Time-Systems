#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const int LED_rate = 500; // ms
static const uint8_t buf_len = 255;
static const int led_pin = LED_BUILTIN;

// Settings
static const uint8_t msg_queue_len = 5;

// Globals
static QueueHandle_t msg_queue1;
static QueueHandle_t msg_queue2;

//*****************************************************************************
// Tasks

// Task: wait for item on queue and print it
void taskA(void *parameters)
{
  char c;
  char buf[buf_len];
  uint8_t idx = 0;
  char message[20];
  int rate_num;

  // Clear whole buffer
  memset(buf, 0, buf_len);

  // Loop forever
  while (1)
  {
    // See if there's a message in queue 2
    if (xQueueReceive(msg_queue2, (void *)&message, 0) == pdTRUE)
    {
      Serial.println(message);
    }
    // Wait before trying again
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    if (Serial.available() > 0)
    {
      c = Serial.read();

      if (c == '\n')
      {
        rate_num = atoi(buf);
        Serial.print("LED blink at rate: ");
        Serial.println(rate_num);
        idx = 0;
      }
      else
      {
        if (idx < buf_len - 1)
        {
          buf[idx] = c;
          idx++;
        }
      }
      // Send blink rate to queue 1
      if (xQueueSend(msg_queue1, (void *)&rate_num, 0) != pdTRUE)
      {
        Serial.println("Queue full");
      }
      // Wait before trying again
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  }
}

void taskB(void *parameter)
{
  char c;
  char message[20];
  static int num = 0;
  static int blink_num = 0;

  while (1)
  {
    if (xQueueReceive(msg_queue1, (void *)&blink_num, 0) == pdTRUE)
    {
      digitalWrite(led_pin, HIGH);
      vTaskDelay(LED_rate / portTICK_PERIOD_MS);
      digitalWrite(led_pin, LOW);
      vTaskDelay(LED_rate / portTICK_PERIOD_MS);
      blink_num++;
    }
    // Wait before trying again
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    if (xQueueSend(msg_queue2, (void *)&message, 0) != pdTRUE)
    {
      if (blink_num == 100) {
        // reset blink_num
        blink_num = 0;
        // send "Blinked" to Queue 2
        strcpy(message, "Blinked");
        Serial.println(++num);
      }
      Serial.println("Queue full");
    }
    // Wait before trying again
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

//*****************************************************************************
// Main (runs as its own task with priority 1 on core 1)

void setup()
{

  // Configure Serial
  Serial.begin(115200);

  // Wait a moment to start (so we don't miss Serial output)
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  Serial.println();
  Serial.println("---FreeRTOS Queue Challenge---");

  // Create queue
  msg_queue1 = xQueueCreate(msg_queue_len, sizeof(int));
  msg_queue2 = xQueueCreate(msg_queue_len, sizeof(int));

  // Start print task
  xTaskCreatePinnedToCore(taskA,
                          "Task A",
                          1024,
                          NULL,
                          1,
                          NULL,
                          app_cpu);

  xTaskCreatePinnedToCore(taskB,
                          "Task B",
                          1024,
                          NULL,
                          1,
                          NULL,
                          app_cpu);
}

void loop()
{

}
