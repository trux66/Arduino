// Global variables
int redLED = 9;         // red LED connected to pin 9
int greenLED = 10;      // green LED connected to pin 10
int blueLED = 11;       // blue LED connected to pin 11
int onBoardLED = 13;    // onboard LED is connected to pin 13
int waitTime = 2000;     // setup a delay const

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

  analogWrite(redLED, redLevel);        // set level of red LED
  redLevel = redLevel + redFade;        // change level for next loop interation
  if (redLevel <= 0 || redLevel >= 255) {     // reverse the fade at top and bottom limits
    redFade = -redFade;
  }

  analogWrite(greenLED, greenLevel);
  greenLevel = greenLevel + greenFade;        // change level for next loop interation
  if (greenLevel <= 0 || greenLevel >= 255) {     // reverse the fade at top and bottom limits
    greenFade = -greenFade;
  }

  analogWrite(blueLED, blueLevel);
  blueLevel = blueLevel + blueFade;        // change level for next loop interation
  if (blueLevel <= 0 || blueLevel >= 255) {     // reverse the fade at top and bottom limits
    blueFade = -blueFade;
  }

  Serial.print("RGB level is: ");
  Serial.print(redLevel); Serial.print(",");
  Serial.print(greenLevel); Serial.print(",");
  Serial.print(blueLevel); Serial.print("; ");
  
  Serial.print("RGB fades are: ");
  Serial.print(redFade); Serial.print(",");
  Serial.print(greenFade); Serial.print(",");
  Serial.println(blueFade);
}
