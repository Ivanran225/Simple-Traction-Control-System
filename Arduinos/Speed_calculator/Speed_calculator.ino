const int sensorPin = A0;
const int triggerThresholdLow = 200;
const int triggerThresholdHigh = 800;
const int enablePin = 9;   // PWM pin connected to ENA on the L298N
const int in1Pin = 8;      // Input 1 pin connected to IN1 on the L298N
const int in2Pin = 7;      // Input 2 pin connected to IN2 on the L298N
unsigned long lastTriggerTime = 0;  // Variable to store the last trigger time
unsigned long startTime;   // Variable to store the start time
unsigned long endTime;     // Variable to store the end time
unsigned long interval = 1000;  // Time interval in milliseconds (0.5 seconds)
int triggerCount = 0;      // Variable to store the number of sensor triggers

int sensorValue;          // Variable to store the sensor value
int previousSensorValue;  // Variable to store the previous sensor value
float speed;              // Variable to store the calculated speed
const int numReadings = 10;  // Number of readings to average
int readings[numReadings];   // Array to store sensor readings
int index = 0;               // Index for the current reading
int total = 0;               // Running total of readings
int smoothedValue = 0;       // Smoothed sensor value

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging

  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(13, OUTPUT);
  previousSensorValue = analogRead(sensorPin);  // Initialize previousSensorValue
}


int smoothValue(int rawValue) {
  // Subtract the oldest reading from the total
  total = total - readings[index];
  
  // Add the new reading to the total
  total = total + rawValue;

  // Store the new reading in the array
  readings[index] = rawValue;

  // Move to the next index
  index = (index + 1) % numReadings;

  // Calculate the average
  int average = total / numReadings;

  return average;
}
void speed_sensor() {
  int sensorValue = analogRead(sensorPin);
  
  // Update the previous sensor value
  previousSensorValue = sensorValue;

  // Check if the sensor is triggered (from less than 200 to more than 800)
  if ((sensorValue < triggerThresholdLow) && (previousSensorValue > triggerThresholdHigh || previousSensorValue == 0)) {
    // Record the start time when the sensor is triggered
    startTime = millis();

    // Increment the trigger count
    triggerCount++;
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
  }

  // Check if the time interval has passed
  if (millis() - lastTriggerTime >= interval) {
    // Display and reset the trigger count
    Serial.println(triggerCount);

    triggerCount = 0;  // Reset the trigger count
    lastTriggerTime = millis();   // Record the current time
  }

  // Update the previous sensor value
  previousSensorValue = sensorValue;
  //delay(50);
}


void motors() {
  if (Serial.available()) {
  }
  int throtle = Serial.parseInt();
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