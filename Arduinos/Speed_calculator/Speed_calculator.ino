int Sum_throtle = 0;
int Sum_FW = 0;
int avg_i_throtle = 0;
int avg_i_FW = 0;
int avg_i_RW = 0;
int throtleValue = 0;
int FW_sensor_pin = 2;
int RW_sensor_pin = 3;
const int enablePin = 9;   // PWM pin connected to ENA on the L298N
const int in1Pin = 8;      // Input 1 pin connected to IN1 on the L298N
const int in2Pin = 7;      // Input 2 pin connected to IN2 on the L298N
//smoth
const unsigned long interval = 1000;  // 1 second in milliseconds
unsigned long previousMillis = 0;
int* values = nullptr;
int valueCount = 0;

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging

  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(FW_sensor_pin, INPUT);
  pinMode(RW_sensor_pin, INPUT);

}

void FW_speed_sensor() {
  static unsigned long start_time_sensor = 0;
  unsigned long stop_time_sensor;
  unsigned long time_counted;
  unsigned long Readings;
  unsigned long Average;
  
  int sensor_state = digitalRead(FW_sensor_pin);

  if (sensor_state == LOW) {
    start_time_sensor = millis();
    delay(50);
  } 
  else if (sensor_state == HIGH) {
    stop_time_sensor = millis();
    time_counted = stop_time_sensor - start_time_sensor;
    //Serial.println(time_counted);
    delay(50);
  }
  if (time_counted > 0) {
    //Serial.println(time_counted);
    int iterations = 10;
    if (avg_i_FW < iterations) {
      Sum_FW = Sum_FW + time_counted;   // Sum for averaging
      avg_i_FW++;
      delay(10);
    }
    if (avg_i_FW == iterations) {
      int Average = Sum_FW / iterations;

      Serial.print("Front wheel speed: ");
      Serial.println(Average);

      Sum_FW = 0;
      avg_i_FW = 0;
    }
   }
  delay(10);
}

void RW_speed_sensor() {
  static unsigned long start_time_sensor = 0;
  unsigned long stop_time_sensor;
  unsigned long time_counted;
  unsigned long Readings;
  unsigned long Average;
  
  int sensor_state = digitalRead(RW_sensor_pin);

  if (sensor_state == LOW) {
    start_time_sensor = millis();
    delay(50);
  } 
  else if (sensor_state == HIGH) {
    stop_time_sensor = millis();
    time_counted = stop_time_sensor - start_time_sensor;
    //Serial.println(time_counted);
    delay(50);
  }
  if (time_counted > 0) {
    //Serial.println(time_counted);
    int iterations = 10;
    if (avg_i_FW < iterations) {
      Sum_FW = Sum_FW + time_counted;   // Sum for averaging
      avg_i_FW++;
      delay(10);
    }
    if (avg_i_FW == iterations) {
      int Average = Sum_FW / iterations;
      Serial.println("Rear wheel speed" + Average);
      Sum_FW = 0;
      avg_i_FW = 0;
      delay(10);
    }
   }
  delay(10);
}

void motors() {
  //int throtle = 200;// = Serial.parseInt(); //Parseint tarda mucho
  //int pwmValue = map(throtle, 0, 100, 0, 255);
  // Set the motor speed
  if(throtleValue > 0){
    analogWrite(enablePin, throtleValue);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
  }
  if(throtleValue == 1){
    analogWrite(enablePin, throtleValue);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }

  //Serial.println(throtle);  
}


int average(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum / size;
}

void throtle_imput() {
  int iterations = 40;
  if (avg_i_throtle < iterations) {
    int Analog = analogRead(A0);
    Sum_throtle = Sum_throtle + Analog;   // Sum for averaging
    avg_i_throtle++;
    delay(10);
  }
  if (avg_i_throtle == iterations) {
    int Average = Sum_throtle / iterations;
    //Serial.println(Average);
    throtleValue = map(Average, 7, 650, 0, 255);
    Serial.print("Throtle: ");
    Serial.println(throtleValue);
    Sum_throtle = 0;
    avg_i_throtle = 0;
    delay(10);
  }
}
void loop() {
  throtle_imput();
  motors();
  FW_speed_sensor();
  RW_speed_sensor();
}
/*
       if(Average > 0){
        Serial.println("Rear wheel speed" + Average);
       }*/