#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Define the pins for rear and front wheel speed sensors
const int rearSensorPin = 2;  // Use the appropriate pin number
const int frontSensorPin = 3; // Use the appropriate pin number

// Define the pin for the rear motor
const int rearMotorPin1 = 4;  // Use the appropriate pin number

// Set the target speed and speed difference thresholds
const int targetSpeed = 100; // Adjust to your specific needs
const int speedDifferenceThreshold = 10; // Adjust as needed

// Set up Wi-Fi credentials
const char* ssid = "galaxy";
const char* password = "esp32abc";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
 
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Define routes for your web pages
  server.on("/", HTTP_GET, [](void){
    server.send(200, "text/html", "<html><body><h1>RC Car Control</h1><p>Speed: " + String(targetSpeed) + "</p></body></html>");
  });

  // Add more routes for additional web pages and controls
  // For example, you can create a form to adjust the targetSpeed
  server.on("/control", HTTP_POST, [](){
    // Retrieve and update the targetSpeed from form data
    if (server.hasArg("targetSpeed")) {
      targetSpeed = server.arg("targetSpeed").toInt();
    }
    server.send(200, "text/html", "<html><body><h1>RC Car Control</h1><p>Speed updated!</p></body></html>");
  });

  // Start the server
  server.begin();

  pinMode(rearSensorPin, INPUT);
  pinMode(frontSensorPin, INPUT);
  pinMode(rearMotorPin1, OUTPUT);
}

void loop() {
  server.handleClient(); // Handle web server requests

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
}
