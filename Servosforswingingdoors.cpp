#include <Servo.h>  // Include the Servo library for controlling servo motors

Servo myservo;      // Create a Servo object to control the first servo
Servo myservo1;     // Create a Servo object to control the second servo
Servo myservo2;     // Create a Servo object to control the third servo

int pos = 0;        // Variable to store the servo position
int buttonPin = 6;  // Set digital pin 6 for the button input
int buttonVal;      // Variable to store the button state

void setup() {
  myservo.attach(12);      // Attach myservo to pin 12
  myservo1.attach(11);     // Attach myservo1 to pin 11
  myservo2.attach(9);      // Attach myservo2 to pin 9
  myservo.write(0);        // Initialize myservo at position 0
  myservo1.write(90);      // Initialize myservo1 at position 90
  myservo2.write(0);       // Initialize myservo2 at position 0
  pinMode(buttonPin, INPUT);// Set the button pin as an input
}

void loop() {
  buttonVal = digitalRead(buttonPin);  // Read the state of the button
  if (buttonVal == HIGH) {             // If the button is pressed (HIGH state)

    // First motion sequence: Move myservo from 0 to 90, myservo1 from 90 to 0, and myservo2 from 0 to 45
    for (pos = 0; pos <= 90; pos++) {
      myservo.write(pos);               // Move myservo to the position 'pos'
      myservo1.write(90 - pos);         // Move myservo1 to 90 - pos
      myservo2.write((double)(pos / 2));// Move myservo2 to half of 'pos'
      delay(20);                        // Wait 20 ms for smooth motion
    }

    // Second motion sequence: Move myservo from 90 to 0, myservo1 from 0 to 90, and myservo2 from 45 to 90
    for (pos = 90; pos >= 0; pos--) {
      myservo.write(90 - pos);          // Move myservo to 90 - pos
      myservo1.write(pos);              // Move myservo1 to 'pos'
      myservo2.write((double)(pos / 2) + 45);// Move myservo2 to half of 'pos' plus 45
      delay(20);                        // Wait 20 ms for smooth motion
    }

    // Third motion sequence: Move myservo from 0 to 90, myservo1 from 90 to 0, and myservo2 from 90 to 45
    for (pos = 0; pos <= 90; pos++) {
      myservo.write(pos);               // Move myservo to the position 'pos'
      myservo1.write(90 - pos);         // Move myservo1 to 90 - pos
      myservo2.write(90 - (double)(pos / 2));// Move myservo2 to 90 minus half of 'pos'
      delay(20);                        // Wait 20 ms for smooth motion
    }

    // Fourth motion sequence: Move myservo from 90 to 0, myservo1 from 0 to 90, and myservo2 from 45 to 0
    for (pos = 0; pos <= 90; pos++) {
      myservo.write(90 - pos);          // Move myservo to 90 - pos
      myservo1.write(pos);              // Move myservo1 to 'pos'
      myservo2.write(45 - (double)(pos / 2));// Move myservo2 to 45 minus half of 'pos'
      delay(20);                        // Wait 20 ms for smooth motion
    }
  }
}
