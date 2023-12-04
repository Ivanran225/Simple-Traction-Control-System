
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

//tcs
/*
int sensor_pin = 2;
const int enablePin = 9;   // PWM pin connected to ENA on the L298N
const int in1Pin = 8;      // Input 1 pin connected to IN1 on the L298N
const int in2Pin = 7;      // Input 2 pin connected to IN2 on the L298N
*/
int mappedvalue = 0;

//sv
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
  //tcs:
  pinMode(9, OUTPUT);
  /*
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
*/
  //sv:
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
  
  // Start server
  server.begin();
}

/*void speed_sensor() {
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
    //start_time_average = 0;
    //stop_time_average = 0;
    NumReadings = 0;
    Readings = 0;
  }

  delay(100);
}

void motors() {
  //int throtle = 200;// = Serial.parseInt(); //Parseint tarda mucho
  //int pwmValue = map(throtle, 0, 100, 0, 255);
  // Set the motor speed
  int sliderValueint = sliderValue.toInt();
  mappedvalue = map(sliderValueint, -100, 0, 1, 255);
  if(mappedvalue > 0){
    analogWrite(enablePin, mappedvalue);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
  }
  if(mappedvalue == 1){
    analogWrite(enablePin, mappedvalue);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }

  //Serial.println(throtle);  
}
*/
void loop() {
  Serial.println(sliderValue);
  //speed_sensor();
  //motors();
}