#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Define the pins for rear and front wheel speed sensors
const int rearSensorPin = 2;  // Use the appropriate pin number
const int frontSensorPin = 3; // Use the appropriate pin number

// Define the pin for the rear motor
const int rearMotorPin1 = 4;  // Use the appropriate pin number

// Set the target speed and speed difference thresholds
int targetSpeed = 100; // Adjust to your specific needs
const int speedDifferenceThreshold = 10; // Adjust as needed
bool slipDetected = false;

// Set up Wi-Fi credentials
const char* ssid = "Galaxy";
const char* password = "esp32abc";

ESP8266WebServer server(80);

void setup() {
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Define the control page with a vertical slider and square for slip
  server.on("/", HTTP_GET, [](){
    
String page = "<html><head>";
page += "<style>";
page += ".slider { transform: rotate(270deg); }";
page += ".square { width: 50px; height: 50px; background-color: ";
page += slipDetected ? "red;" : "green;";
page += " animation: blink 1s infinite; }";
page += "@keyframes blink {";
page += "  0% { opacity: 0; }";
page += "  50% { opacity: 1; }";
page += "  100% { opacity: 0; }";
page += "}";
page += ".content {";
page += "  margin-top: 20px;"; // Adjust the margin as needed
page += "}";
page += "</style></head><body>";
page += "<h1>RC Car Control</h1>";
page += "<div class='content'>";
page += "<p>Target Speed: " + String(targetSpeed) + "</p>";
page += "<p>Current Speed: " + String(analogRead(rearSensorPin)) + "</p>";
page += "<p>Slip Detected: <div class='square'></div></p>";
page += "</div>";
page += "<input type='range' class='slider' id='speedSlider' min='0' max='255' oninput='updateSpeed(value)' onload='setSliderValue()'>";
page += "<script>";
page += "function updateSpeed(val) {";
page += "  document.getElementById('speedSlider').value = val;";
page += "}";
page += "function setSliderValue() {";
page += "  document.getElementById('speedSlider').value = " + String(targetSpeed) + ";";
page += "}";
page += "</script>";
page += "</body></html>";
server.send(200, "text/html", page);

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
  int speedDifference = frontSpeed - rearSpeed;

  // Determine the motor speed based on the speed difference
  int rearMotorSpeed = targetSpeed + speedDifference;

  // Ensure motor speed is within a valid range (0-255)
  rearMotorSpeed = constrain(rearMotorSpeed, 0, 255);

  // Control the rear motor
  analogWrite(rearMotorPin1, rearMotorSpeed);

  // Check for slip
  slipDetected = (abs(speedDifference) > speedDifferenceThreshold);
}
