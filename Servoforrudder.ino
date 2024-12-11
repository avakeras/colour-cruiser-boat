
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo1;// twelve servo objects can be created on most boards
Servo myservo2;

int pos = 0; 
int buttonPin = 6;
int buttonVal;

void setup() {
  Serial.begin(9600);
  myservo.attach(12); 
  myservo1.attach(11);
  myservo2.attach(9);
  myservo.write(0);
  myservo1.write(90);
  myservo2.write(0);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  if (buttonVal == HIGH){
    // First two loops rudder moves to 90
    for(pos=0; pos<=90; pos++){
      myservo.write(pos);
      myservo1.write(90-pos);
      myservo2.write((double)(pos/2));
      delay(20);
    }
    for(pos=0; pos<=90; pos++){
      myservo.write(90-pos);
      myservo1.write(pos);
      myservo2.write((double)(pos/2)+45.0);
      delay(20);
    }
    // Last two loops rudder moves back to 0
    for(pos=0; pos<=90; pos++){
      myservo.write(pos);
      myservo1.write(90-pos);
      myservo2.write(90-(double)(pos/2));
      delay(20);
    }
    for(pos=0; pos<=90; pos++){
      myservo.write(90-pos);
      myservo1.write(pos);
      myservo2.write(45-(double)(pos/2));
      delay(20);
    }
  }
}