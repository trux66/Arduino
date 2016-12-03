/*
 Fade

 This example shows how to fade an LED using the analogWrite() function.

 The analogWrite() function uses PWM, so if you want to change the pin you're using, be
 sure to use another PWM capable pin. On most Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

*/

// Global Variables
int onBoardLED=13;  // set pin used for onboard LED control

int yellowLED=10;   // set PWM pin used for yellow LED control
int yellowBrightness=250;   // how bright the yellow LED is
int yellowFadeAmount=5;   // how many points to fade the LED by

int blueLED=9;      // set PWM pin used for blue LED control
int blueBrightness=0;   // how bright the blue LED is
int blueFadeAmount=5; // how many point to fade the LED by


// the setup routine runs once when you press reset:
void setup() {
  // declare used pins to be output
  pinMode(yellowLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(onBoardLED,OUTPUT);
  digitalWrite(onBoardLED,LOW); // turn off the onBoard LED

  // initialize serial communication at 9600 bits per second:
  // Serial.begin(19200);

}

// the loop routine runs over and over again
void loop() {
  // define some delays to be used later
  int yellowOn=500;
  int yellowOff=500;
  int blueOn=30;
  int blueOff=500;

  analogWrite(yellowLED, yellowBrightness); // set brightness of LED
  yellowBrightness = yellowBrightness + yellowFadeAmount; // change brightness for next time through loop
  if (yellowBrightness <= 0 || yellowBrightness >= 255) { // reverse fade at the top & bottom limits
    yellowFadeAmount = -yellowFadeAmount;
  }
  
  analogWrite(blueLED, blueBrightness); // set brightness of LED
  blueBrightness = blueBrightness + blueFadeAmount; // change brightness for next time through loop
  if (blueBrightness <= 0 || blueBrightness >= 255) { // reverse fade at the top & bottom limits
    blueFadeAmount = -blueFadeAmount;
  }
  delay(blueOn);  // wait for some time to see the fade effect

  // print out the value you read:
  // Serial.println(String(yellowBrightness) + " : " + String(blueBrightness));
}
