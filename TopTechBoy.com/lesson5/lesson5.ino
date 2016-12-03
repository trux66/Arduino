/*
 *  TopTechBoy.com Arduino Lesson 3 
 * 
 */

int onBoardLED=13; //Declare the onBoardLED as pin 13
int blueLEDPin=9; //Declare blueLEDPin an int, and set to pin 9 
int yellowLEDPin=10; //Declare yellowLEDPin an int, and set to pin 10 
int blueOnTime=250; //Declare blueOnTime an int, and set to 250 mseconds 
int blueOffTime=250; //Declare blueOffTime an int, and set to 250 
int yellowOnTime=250; //Declare yellowOnTime an int, and set to 250
int yellowOffTime=250; //Declare yellowOffTime an int, and set to 250
int numYellowBlinks=5; //Number of times to blink yellow LED
int numBlueBlinks=5;  //Number of times to blink Blue LED
String blueMessage="The Blue LED is Blinking";
String yellowMessage="The Yellow LED is Blinking";

void setup() {
  Serial.begin(19200);             // initialize the serial port
  pinMode(blueLEDPin, OUTPUT);    // Tell Arduino that blueLEDPin is an output pin
  pinMode(yellowLEDPin, OUTPUT);  // Tell Arduino that yellowLEDPin is an output pin
  pinMode(onBoardLED, OUTPUT);    // Tell Arduino that onBoarLED is an output pin
  digitalWrite(onBoardLED, LOW);  // turn off the onBoardLED
}

void loop() {
  Serial.println(blueMessage);
  for (int j=1; j<=numBlueBlinks; j=j+1) {     // Start our for loop
    Serial.print("   You are on blink #: ");
    Serial.println(j);             // current number of blinks in the loop
    digitalWrite(blueLEDPin,HIGH); // Turn blue LED on
    delay(blueOnTime);             // Leave on for blueOnTime
    digitalWrite(blueLEDPin,LOW);  // Turn blue LED off
    delay(blueOffTime);            // Leave off for blueOffTime
  }

  Serial.println("");
  Serial.println(yellowMessage);
  for (int j=1; j<=numYellowBlinks; j=j+1) {     // Start our for loop
    Serial.print("   You are on blink #: ");
    Serial.println(j);             // current number of blinks in the loop
    digitalWrite(yellowLEDPin,HIGH); //Turn yellow LED on
    delay(yellowOnTime);             //Leave on for yellowOnTime
    digitalWrite(yellowLEDPin,LOW);  //Turn yellow LED off
    delay(yellowOffTime);            //Leave off for yellowOffTime
  }
  Serial.println("");
}

