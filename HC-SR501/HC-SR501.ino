/*
Presence sensor HC-SR501


*/
//Define the pins
#define pirPin 2

// Variable to change detect and change the status
int val = 0;
int count = 0;
int delayMS = 10000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  
}

// the loop function runs over and over again forever
void loop() {
  // Read the sensor
  val = digitalRead(pirPin);
  // if detect motion don't move and wait
  if (val == HIGH) {

      Serial.println("Motion Detected");
      digitalWrite(LED_BUILTIN, LOW); 
      delay(delayMS);
    // If not detected move  and wait
    } else{

      Serial.println("No Motion detected");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(delayMS);
  }
  
}
