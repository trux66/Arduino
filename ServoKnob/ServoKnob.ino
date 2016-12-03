/*
  Controlling a servo position using a potentiometer (variable resistor)
  by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

  modified on 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;      // create servo object to control a servo

int potpin = A0;     // analog pin used to connect the potentiometer
int servopin = 6;   // pin used for servo
int val;            // variable to read the value from the analog pin

void setup() {
  myservo.attach(servopin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);         // open the serial port
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("POT value: ");
  Serial.print(val);

  // using the map() funtion mimics the math to compute the slope line equation
  // map function = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  val = map(val, 0, 1023, 40, 160);     // scale it to use it with the servo (value between 40 and 160)
  Serial.print(", MAP value: ");
  Serial.println(val);

  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

