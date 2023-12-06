float numReadings = 0; // number of readings taken
float total = 0; // total of readings
float averageRPM = 0; // average RPM
volatile unsigned long lastTriggerTime = 0; // last time the sensor was triggered
const int samplePeriod = 1000; // sample period in milliseconds
int periods = 0;
bool prevState = HIGH;

void setup() {
  attachInterrupt(digitalPinToInterrupt(3), sensorTriggered, FALLING);
  //attachInterrupt(digitalPinToInterrupt(3), sensorTriggered2, RISING);
  Serial.begin(9600);
  pinMode(3, INPUT);
}
void motors() {
  int throtleValue = 100;// = Serial.parseInt(); //Parseint tarda mucho
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
    numReadingsFW = 0;
    numReadingsRW = 0;
    lastTriggerTime = millis();
  }
  
  //Serial.println(digitalRead(3));
  motors();
}

volatile unsigned long lastTriggeredTime = 0;
const unsigned long delayTime = 300; // delay time in milliseconds

void sensorTriggered() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastTriggeredTime >= delayTime) {
    numReadingsFW++;
    numReadingsRW++;  
    lastTriggeredTime = currentMillis;
  }
}
