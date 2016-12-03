#include <Servo.h>      // load servo control library

// Global variables
int redLED = 9;         // red LED connected to pin 9
int greenLED = 10;      // green LED connected to pin 10
int blueLED = 11;       // blue LED connected to pin 11
int onBoardLED = 13;    // onboard LED is connected to pin 13
int waitTime = 2000;     // setup a delay const
int servoPin = 6;       // Servo control pin
int potPin = 5;         // potentiometer pin

Servo myServo;          // create servo object

int redLevel = 250;     // setup variables to hold brightness levels
int greenLevel = 50;
int blueLevel = 150;

int redFade = 5;        // setup variables to control fade
int greenFade = 5;
int blueFade = 5;

void setup() {
  Serial.begin(9600);         // turn on the serial port for monitoring as needed
  pinMode(redLED, OUTPUT);    // setup pins as OUTPUT
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(onBoardLED, OUTPUT);

  digitalWrite(onBoardLED, LOW);    // make sure the onboard LED is off
}

void loop() {

}
