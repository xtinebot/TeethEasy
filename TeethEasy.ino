
#include <Servo.h>  // add servo library

Servo servo1; // controlled by accelerometer
Servo servo2; // the brush head

int xpin = A3;  // analog pin used to connect the Accelerometer
int pos;    // variable to read the value from the analog pin
int servo1Pin = 6;
int servo2Pin = 7;
int buttonPin = 3;
int buttonActivated;
int servoAngle;   // servo position in degrees


void setup() {
  servo1.attach(servo1Pin);  // attaches the servo on pin D11 to the servo
  servo2.attach(servo2Pin);
  servo1.write(270); //sets 0
  servo2.write(110);
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  
  pos = analogRead(xpin);           // reads the value of the accelerometer (value between 0 and 1023)
  Serial.println(pos);
  pos = map(pos, 430, 570, 180, 0); // scale it to use it with the servo (value between 0 and 180)
  //pos = map(pos, 380, 555, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  servo1.write(pos);               // sets the servo position according to the scaled value
  buttonActivated = digitalRead(buttonPin);                        // waits for the servo to get there
  if(buttonActivated == LOW)
  {
    brush();
    servo1.write(270); //sets 0
    servo2.write(110);
  }
  delay(200);
}

void brush()
{
//if you change the delay value (from example change 50 to 10), the speed of the servo changes
  for(int i = 0; i<100; i++)
  {
    for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
    {                                  
      servo2.write(servoAngle);              
      delay(1);
    } 
  }
  return;
}
