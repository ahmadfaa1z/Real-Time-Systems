//Button Pins
const int Button_1 = 6;
const int Button_2 = 5;
const int Button_3 = 4;

//LED Pins
const int LED_1 = A1;
const int LED_2 = A2;
const int LED_3 = A3;
const int LED_4 = A4;
const int LED_5 = A5;


void setup() {
  Serial.begin(9600);
  
  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  pinMode(Button_3, INPUT);
  
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

void loop() {

//----------TROUBLESHOOT BUTTON----------//
//  Serial.println(digitalRead(Button_1));
//  Serial.println(digitalRead(Button_2));
//  Serial.println(digitalRead(Button_3));


  int Button_state1 = digitalRead(Button_1);
  int Button_state2 = digitalRead(Button_2);
  int Button_state3 = digitalRead(Button_3);

//----------FOR TESTING----------//
//  if(Button_state1 == 1){
//    digitalWrite(LED_1, HIGH);
//  } else {
//    digitalWrite(LED_1, LOW);
//  }

//----------(( Upward ))----------//
  if(Button_state1 == 1){
    digitalWrite(LED_1, HIGH);
    delay(200);
    digitalWrite(LED_2, HIGH);
    delay(200);
    digitalWrite(LED_3, HIGH);
    delay(200);
    digitalWrite(LED_4, HIGH);
    delay(200);
    digitalWrite(LED_5, HIGH);
    delay(200);
    
    digitalWrite(LED_1, LOW);
    delay(300);
    digitalWrite(LED_2, LOW);
    delay(300);
    digitalWrite(LED_3, LOW);
    delay(300);
    digitalWrite(LED_4, LOW);
    delay(300);
    digitalWrite(LED_5, LOW);
    delay(300);
  }
  
//----------(( Center to End ))----------//
  if(Button_state2 == 1){
    digitalWrite(LED_3, HIGH);
    delay(200);   
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_4, HIGH);
    delay(200);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_5, HIGH);
    delay(200);
    
    digitalWrite(LED_3, LOW);
    delay(300);   
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_4, LOW);
    delay(300);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_5, LOW);
    delay(300);
  }

//----------(( Downward ))----------//
  if(Button_state3 == 1){
    digitalWrite(LED_5, HIGH);
    delay(200);
    digitalWrite(LED_4, HIGH);
    delay(200);
    digitalWrite(LED_3, HIGH);
    delay(200);
    digitalWrite(LED_2, HIGH);
    delay(200);
    digitalWrite(LED_1, HIGH);
    delay(200);
    
    digitalWrite(LED_5, LOW);
    delay(300);
    digitalWrite(LED_4, LOW);
    delay(300);
    digitalWrite(LED_3, LOW);
    delay(300);
    digitalWrite(LED_2, LOW);
    delay(300);
    digitalWrite(LED_1, LOW);
    delay(300);
  }

//----------(( End to Center ))----------//
//  if(Button_state3 == 1){
//    digitalWrite(LED_1, HIGH);
//    digitalWrite(LED_5, HIGH);
//    delay(200);
//    digitalWrite(LED_2, HIGH);
//    digitalWrite(LED_4, HIGH);
//    delay(200);
//    digitalWrite(LED_3, HIGH);
//    delay(200);
//
//    digitalWrite(LED_1, LOW);
//    digitalWrite(LED_5, LOW);
//    delay(300);
//    digitalWrite(LED_2, LOW);
//    digitalWrite(LED_4, LOW);
//    delay(300);
//    digitalWrite(LED_3, LOW);
//    delay(300);
//  }
  
}
