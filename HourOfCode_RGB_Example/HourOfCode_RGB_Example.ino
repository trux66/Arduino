/*
  File: HourOfCode_RGB_Example
  Description:
  Reads an analog input on pin A0, scales it to 0-255 range for use in setting RGB LED to different colors; prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  Attach RGB to pins 9,10,11 using 220 ohm resitors and the common pin to ground.
*/

// Global variables
int redLED = 9;         // red LED connected to pin 9
int greenLED = 10;      // green LED connected to pin 10
int blueLED = 11;       // blue LED connected to pin 11
int onBoardLED = 13;    // onboard LED is connected to pin 13
int potPin = A0;        // potentiometer is connected to analog pin A0

int redLevel = 0;       // create variables to hold brightness levels
int greenLevel = 0;
int blueLevel = 0;

int potValue;           // create variable to hold potentiometer value read from potPin

void setup() {
  Serial.begin(9600);               // turn on the serial port for monitoring as needed
  pinMode(redLED, OUTPUT);          // set LED pins as OUTPUT
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(onBoardLED, OUTPUT);

  pinMode(potPin, INPUT);           // set potentiometer pin as input
  digitalWrite(onBoardLED, LOW);    // make sure the onboard LED is off
}

void loop() {

  potValue = analogRead(potPin);                  // read value from potentiometer
  // if potValue 0-341 - change redLevel
  // if potValue 342-682 - change greenLevel
  // if potValue 682-1023 - change blueLevel

  if (potValue >= 0 && potValue <= 341) {
    redLevel = map(potValue, 0, 1023, 0, 255);    // set new hue of redLED; adjust potentiometer (0-1023) to fit LED (0-255) scale
    greenLevel = 0;
    blueLevel = 0;
  }

  if (potValue >= 342 && potValue <= 682) {
    redLevel = 0;
    greenLevel = map(potValue, 0, 1023, 0, 255);  // set new hue of greenLED; adjust potentiometer (0-1023) to fit LED (0-255) scale
    blueLevel = 0;
  }

  if (potValue >= 683 && potValue <= 1023) {
    redLevel = 0;
    greenLevel = 0;
    blueLevel = map(potValue, 0, 1023, 0, 255);  // set new hue of blueLED; adjust potentiometer (0-1023) to fit LED (0-255) scale
  }

  analogWrite(redLED, redLevel);                // set value of redLED to scaled value of potentiometer
  analogWrite(greenLED, greenLevel);            // set value of greenLED to scaled value of potentiometer
  analogWrite(blueLED, blueLevel);              // set value of blueLED to scaled value of potentiometer

  Serial.print("RGB level is: ");               // print some data to the serial monitor for debuging if needed
  Serial.print(redLevel); Serial.print(",");    // sample output: "RGB level is: 0,245,0; POT Value is: 500"
  Serial.print(greenLevel); Serial.print(",");
  Serial.print(blueLevel); Serial.print("; ");
  Serial.print("POT Value is: "); Serial.println(potValue);
}

