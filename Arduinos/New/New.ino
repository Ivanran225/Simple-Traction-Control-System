float numReadingsRW = 0; // number of readings taken
float numReadingsFW = 0;
float totalFW = 0; // total of readings
float totalRW = 0;
float averageRPM_FW = 0; // average RPM
float averageRPM_RW = 0;
volatile unsigned long lastTriggerTime = 0; // last time the sensor was triggered
const int samplePeriod = 1000; // sample period in milliseconds
int periods = 0;
bool prevState = HIGH;

int throtleValue = 0;
int Sum_throtle = 0;
int avg_i_throtle = 0;

void setup() {
  attachInterrupt(digitalPinToInterrupt(3), RWsensorTriggered, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), FWsensorTriggered, FALLING);
  //attachInterrupt(digitalPinToInterrupt(3), sensorTriggered2, RISING);
  Serial.begin(9600);
  pinMode(3, INPUT);
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
    //Serial.print("Throtle: ");
    //Serial.println(throtleValue);
    Sum_throtle = 0;
    avg_i_throtle = 0;
    delay(10);
  }
}
void motors() {
  //int throtleValue = 100;// = Serial.parseInt(); //Parseint tarda mucho
  //int pwmValue = map(throtle, 0, 100, 0, 255);
  // Set the motor speed
  if(throtleValue > 0){
    analogWrite(9, throtleValue);
    digitalWrite(8, HIGH);
  }
  if(throtleValue == 1){
    analogWrite(9, throtleValue);
    digitalWrite(8, LOW);

  }

  //Serial.println(throtle);  
}
void loop() {
  float speeddiff;
  if (millis() - lastTriggerTime >= samplePeriod) {
    periods++;
    totalFW += numReadingsFW;
    totalRW += numReadingsRW;
    averageRPM_FW = totalFW / periods;
    averageRPM_RW = totalRW / periods;
    Serial.println("Front Wheel Speed: ");
    Serial.println(averageRPM_FW);
    Serial.println("Rear Wheel Speed: ");
    Serial.println(averageRPM_RW);
    speeddiff = averageRPM_RW - averageRPM_FW;
    numReadingsFW = 0;
    numReadingsRW = 0;
    lastTriggerTime = millis();
  }
  if(speeddiff > 0.1){
    throtleValue = 0;
    delay(1000);
    Serial.println("Slip!!!");
    speeddiff = 0;
    }
  //Serial.println(digitalRead(3));
  motors();
  throtle_imput();
}

volatile unsigned long lastTriggeredTime = 0;
const unsigned long delayTime = 300; // delay time in milliseconds

void FWsensorTriggered() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastTriggeredTime >= delayTime) {
    numReadingsFW++;  
    lastTriggeredTime = currentMillis;
  }
}
void RWsensorTriggered() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastTriggeredTime >= delayTime) {
    numReadingsRW++;  
    lastTriggeredTime = currentMillis;
  }
}
