/*
Sensor will check the presence and move the servo drive.

*/
#include <Servo.h>
#define pirPin 2

// Variable to change detect and change the status
int val = 0;
int count = 0;
int delayMS = 60000;
int pos = 0;    // variable to store the servo position
Servo myservo;  // create Servo object to control a servo

void setup() {
  myservo.attach(9);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pirPin);

  if (val == HIGH) {
    Serial.println("Motion Detected");
    digitalWrite(LED_BUILTIN, LOW);
    count = 0;
  }

  if (count >= delayMS){
    Serial.println("Motion not detected prepare to move");
    digitalWrite(LED_BUILTIN, HIGH);
    count = 0;
  }

  count+= 1;
}
