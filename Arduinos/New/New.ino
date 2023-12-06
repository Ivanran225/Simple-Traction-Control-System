float numReadings = 0; // number of readings taken
float total = 0; // total of readings
float averageRPM = 0; // average RPM
volatile unsigned long lastTriggerTime = 0; // last time the sensor was triggered
const int samplePeriod = 1000; // sample period in milliseconds
int periods = 0;
bool prevState = HIGH;

void setup() {
  attachInterrupt(digitalPinToInterrupt(3), sensorTriggered, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), sensorTriggered2, RISING);
  Serial.begin(9600);
  pinMode(3, INPUT);
}
void motors() {
  int throtleValue = 50;// = Serial.parseInt(); //Parseint tarda mucho
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
    total += numReadings;
    averageRPM = total / periods;
    //Serial.println(averageRPM);
    numReadings = 0;
    lastTriggerTime = millis();
  }
  
  //Serial.println(digitalRead(3));
  motors();
}

void sensorTriggered() {
  if(prevState == HIGH){
    numReadings++;  
  }
  Serial.println("T1");
  prevState = LOW;
}

void sensorTriggered2() {
  prevState = HIGH;
  Serial.println("T2");
}
