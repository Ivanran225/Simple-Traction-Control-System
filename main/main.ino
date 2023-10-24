
// Define the pins for rear and front wheel speed sensors
const int rearSensorPin = 2;
const int frontSensorPin = 3;

// Define the pin for the rear motor
const int rearMotorPin1 = 4;
const int rearMotorPin2 = 5;

// Set the target speed and speed difference thresholds
const int targetSpeed = 100; // Adjust to your specific needs
const int speedDifferenceThreshold = 10; // Adjust as needed

void setup() {
  pinMode(rearSensorPin, INPUT);
  pinMode(frontSensorPin, INPUT);
  pinMode(rearMotorPin1, OUTPUT);
  pinMode(rearMotorPin2, OUTPUT);
}

void loop() {
  // Read rear and front wheel speed sensor values
  int rearSpeed = analogRead(rearSensorPin);
  int frontSpeed = analogRead(frontSensorPin);
  
  // Calculate the speed difference between the rear and front wheels
  int speedDifference = rearSpeed - frontSpeed;
  
  // Determine the motor speed based on the speed difference
  int rearMotorSpeed = targetSpeed - speedDifference;
  
  // Ensure motor speed is within a valid range (0-255)
  rearMotorSpeed = constrain(rearMotorSpeed, 0, 255);
  
  // Control the rear motor
  analogWrite(rearMotorPin1, rearMotorSpeed);
  analogWrite(rearMotorPin2, 0); // Adjust direction pins
}
