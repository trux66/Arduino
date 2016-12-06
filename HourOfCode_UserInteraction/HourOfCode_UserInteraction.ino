/*
  File: HourOfCode_UserInteraction
  Description:
  Using a simple LED connected to the Arduino allow users to enter different blink rates to demonstrate interaction with the board.
  Attach LED to pin 8 and ground through a 220 ohm resistor.
*/

// Global variables
int LED = 8;          // LED is connected to pin 8
int onBoardLED = 13;  // onBoard LED is on pin 13
int blinkRate;        // create variable to hold blink rate entered

void setup() {
  Serial.begin(9600);                 // turn on the serial port

  pinMode(LED, OUTPUT);               // set our LED pins as OUTPUT
  pinMode(onBoardLED, OUTPUT);

  digitalWrite(onBoardLED, LOW);      // turn off the onBoard LED

  Serial.println("Please enter a blink rate (1=Fast, 2=Average, 3=Slow): ");  // Prompt for input
  while(Serial.available()==0){}      // wait for input
  blinkRate = Serial.parseInt();      // read the input
}

void loop() {
  if(Serial.available()>0){               // look for input on serial port
    blinkRate = Serial.parseInt();        // read the input
  }

  digitalWrite(LED, HIGH);                // turn on the LED
  if(blinkRate==1){delay(125);}           // leave LED on for 1/8 sec
  else if (blinkRate==2){delay(500);}     // leave LED on for 1/2 sec
  else {delay(1000);}                     // leave LED on for 1 sec

  digitalWrite(LED, LOW);                 // turn off the LED
  if(blinkRate==1){delay(125);}           // leave LED off for 1/8 sec
  else if (blinkRate==2){delay(500);}     // leave LED off for 1/2 sec
  else {delay(1000); }                    // leave LED off for 1 sec
}
