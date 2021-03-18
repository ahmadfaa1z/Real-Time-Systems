// In progress

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static int LED_rate = 500; //ms

// Pins
static const int led_pin = LED_BUILTIN;


// TASK(1): Blink LED at given input from serial
void toggleLED(void *parameter) {
  while (1) {
    digitalWrite(led_pin, HIGH);
    vTaskDelay(LED_rate / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(LED_rate / portTICK_PERIOD_MS);
  }
}

// TASK(2): Ask input from serial for LED blink rate
void inputRate(void *parameter) {
  char input;

  while (1) {
    if (Serial.available() > 0) {
      input = Serial.read();
      LED_rate = input.toInt();
      Serial.print("LED blink at rate: ");
      Serial.println(LED_rate);
    }
  }
}

void setup() {

  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  Serial.println("Input blink rate (in ms): ");

  // Task to run forever
  xTaskCreatePinnedToCore(toggleLED,
                          "Blink LED",
                          1024,
                          NULL,
                          1,            // task priority
                          NULL,         // task handle
                          app_cpu);

  // Task to run once with higher priority
  xTaskCreatePinnedToCore(inputRate,
                          "Read input from Serial",
                          1024,
                          NULL,
                          1,            // task priority (must be same to prevent lockup)
                          NULL,         // task handle
                          app_cpu);

//  vTaskDelete(NULL);
}

void loop() {

}
