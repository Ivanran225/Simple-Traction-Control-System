float revolutionsFW=0;
int rpmFW=0; // max value 32,767 16 bit
long  startTimeFW=0;
long  elapsedTimeFW;

//////

int Sum_throttle = 0;
int Sum_FW = 0;
int avg_i_throttle = 0;
int avg_i_FW = 0;
int avg_i_RW = 0;
int throttleValue = 0;
int FW_sensor_pin = 2;
int RW_sensor_pin = 3;
const int enablePin = 9;   // PWM pin connected to ENA on the L298N
const int in1Pin = 8;      // Input 1 pin connected to IN1 on the L298N
const int in2Pin = 7;      // Input 2 pin connected to IN2 on the L298N
//smoth
const unsigned long interval = 1000;  // 1 second in milliseconds
unsigned long previousMillis = 0;
int* values = nullptr;
int valueCount = 0;

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging

  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(FW_sensor_pin, INPUT);
  pinMode(RW_sensor_pin, INPUT);
  pinMode(3, INPUT_PULLUP);           // set pin to input
  pinMode(2, INPUT_PULLUP);           // set pin to input
}

void motors() {
  //int throttle = 200;// = Serial.parseInt(); //Parseint tarda mucho
  //int pwmValue = map(throttle, 0, 100, 0, 255);
  // Set the motor speed
  if(throttleValue > 0){
    analogWrite(enablePin, throttleValue);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, HIGH);
  }
  if(throttleValue == 1){
    analogWrite(enablePin, throttleValue);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  }

  //Serial.println(throttle);  
}

void interruptFunctionFW() //interrupt service routine
{  
  revolutionsFW++;
}
void FWSPEED() {
revolutionsFW=0; rpmFW=0;
startTimeFW=millis();         
attachInterrupt(digitalPinToInterrupt(2),interruptFunction,RISING);
delay(3000);
detachInterrupt(3);                

//now let's see how many counts we've had from the hall effect sensor and calc the RPM
elapsedTimeFW=millis()-startTimeFW;     //finds the time, should be very close to 1 sec

if(revolutionsFW>0)
{
  rpmFW=(max(1, revolutionsFW) * 60000) / elapsedTimeFW;        //calculates rpmFW
}
String outMsg = String("RPM :") + rpmFW;
Serial.println(outMsg);
}


int average(int arr[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum / size;
}

void throttle_imput() {
  int iterations = 20;
  if (avg_i_throttle < iterations) {
    int Analog = analogRead(A0);
    Sum_throttle = Sum_throttle + Analog;   // Sum for averaging
    avg_i_throttle++;
    delay(10);
  }
  if (avg_i_throttle == iterations) {
    int Average = Sum_throttle / iterations;
    //Serial.println(Average);
    throttleValue = map(Average, 20, 700, 0, 255);
    Serial.print("Throttle: ");
    Serial.println(throttleValue);
    Sum_throttle = 0;
    avg_i_throttle = 0;
    delay(10);
  }
}
void loop() {
  throttle_imput();
  motors();
}
/*
       if(Average > 0){
        Serial.println("Rear wheel speed" + Average);
       }*/