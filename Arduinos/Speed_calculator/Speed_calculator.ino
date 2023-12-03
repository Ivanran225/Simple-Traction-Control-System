int sensor_pin = 2;
const int enablePin = 9;   // PWM pin connected to ENA on the L298N
const int in1Pin = 8;      // Input 1 pin connected to IN1 on the L298N
const int in2Pin = 7;      // Input 2 pin connected to IN2 on the L298N

int index = 0;               // Index for the current reading
int total = 0;               // Running total of readings
int smoothedValue = 0;       // Smoothed sensor value

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging

  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(sensor_pin, INPUT);

}

void speed_sensor() {
  static unsigned long start_time_sensor = 0;
  static unsigned long start_time_average = 0;
  unsigned long stop_time_sensor;
  unsigned long stop_time_average;
  unsigned long time_counted;
  int NumReadings;
  unsigned long Readings;
  unsigned long Average;
  
  int sensor_state = digitalRead(sensor_pin);

  if (sensor_state == LOW) {
    start_time_sensor = millis();
    start_time_average = millis();
  } 
  else if (sensor_state == HIGH) {
    stop_time_sensor = millis();
    stop_time_average = millis();
    time_counted = stop_time_sensor - start_time_sensor;
  }

  if ((stop_time_average - start_time_average) < 3000) {
    NumReadings++;
    Readings = Readings + time_counted;
  } 
  else if ((stop_time_average - start_time_average) > 3000) {
    Average = Readings / NumReadings;
    //Serial.println(Average);
    Serial.println(start_time_average);
    Serial.println(stop_time_average);
    //start_time_average = 0;
    //stop_time_average = 0;
    NumReadings = 0;
    Readings = 0;
  }

  delay(100);
}


void motors() {
  int throtle = 200;// = Serial.parseInt(); //Parseint tarda mucho
  //int pwmValue = map(throtle, 0, 100, 0, 255);
  // Set the motor speed
  if(throtle > 0){
    analogWrite(enablePin, throtle);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
  }
  if(throtle == 1){
    analogWrite(enablePin, throtle);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }

  //Serial.println(throtle);  
}
void basora(){
  // Add any other code you need to run in the loop

  /*
  // Read the sensor value
  sensorValue = analogRead(sensorPin);

  // Check if the sensor is triggered (from 1023 to 0)
  if (sensorValue < 200 && previousSensorValue > 800) {
    // Record the start time when the sensor is triggered
    startTime = millis();
  }

    // Check if the sensor is untriggered (from more than 800 to less than 200)
  if (sensorValue > 800 && previousSensorValue < 200) {
    // Record the end time when the sensor is untriggered
    //endTime = millis();

    // Calculate the speed (change in distance / time)
    // Note: You may need to calibrate this formula based on your specific setup
    speed = endTime - startTime;
    smoothedValue = smoothValue(speed);
    // Print the smoothed value
    Serial.println(smoothedValue);

  // Update the previous sensor value
    previousSensorValue = sensorValue;

*/
}

void loop() {
  speed_sensor();
  motors();
}