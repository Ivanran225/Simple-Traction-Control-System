// Import required libraries
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WiFiClientSecure.h>
WiFiClientSecure client;
// Define the pins for rear and front wheel speed sensors
const int rearSensorPin = 2;  // Use the appropriate pin number
const int frontSensorPin = 3; // Use the appropriate pin number

// Define the pin for the rear motor
const int rearMotorPin1 = 4;  // Use the appropriate pin number

// Set the target speed and speed difference thresholds
int targetSpeed = 100; // Adjust to your specific needs
const int speedDifferenceThreshold = 10; // Adjust as needed
bool slipDetected = false;

// Replace with your network credentials
const char* ssid = "Galaxy";
const char* password = "esp32abc";

const int output = 2;

String sliderValue = "0";

const char* PARAM_INPUT = "value";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>ESP Web Server</title>
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 2.3rem;}
    p {font-size: 1.9rem;}
    body {max-width: 400px; margin:0px auto; padding-bottom: 25px;}
    .slider { -webkit-appearance: none; margin: 14px; width: 360px; height: 25px; background: #FFD65C;
      outline: none; -webkit-transition: .2s; transition: opacity .2s;}
    .slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px; background: #003249; cursor: pointer;}
    .slider::-moz-range-thumb { width: 35px; height: 35px; background: #003249; cursor: pointer; } 
  </style>
</head>
<body>
  <h2>ESP Web Server</h2>
  <p><span id="textSliderValue">%SLIDERVALUE%</span></p>
  <p><input type="range" oninput="updateSliderPWM(this)" id="pwmSlider" min="0" max="1023" value="%SLIDERVALUE%" step="1" class="slider"></p>
<script>
function updateSliderPWM(element) {
  var sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("textSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?value="+sliderValue, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if (var == "SLIDERVALUE"){
    return sliderValue;
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  pinMode(rearSensorPin, INPUT);
  pinMode(frontSensorPin, INPUT);
  pinMode(rearMotorPin1, OUTPUT);
  
  analogWrite(output, sliderValue.toInt());

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/slider?value=<inputMessage>
  server.on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue = inputMessage;
      analogWrite(output, sliderValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });
  
  // Send a GET request
  String request = String("GET ") + "/slider?value="+sliderValue + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" +
                   "Connection: close\r\n\r\n";
  client.print(request);

  // Wait for the server's response
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  // Read the server's response
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
}
}
  
void loop() {
  Serial.println(sliderValue);
  
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