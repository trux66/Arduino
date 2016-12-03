// Setup global variables
int onBoardLED = 13;    // setup pin for onboard LED
int potPIN = A0;        // potentiometer is connected to pin A0
int yellowLED=9;        // pin assignment for yellow LED
int blueLED=10;         // pin assignment for blue LED
int potRead;            // place to hold input values from potentiometer
int LEDWrite;           // value to write to the LED
float potVoltage;       // place to hold real world voltage value of the potentiometer setting

void setup() {
  pinMode(onBoardLED, OUTPUT);      // setup onBoardLED PIN for OUTPUT
  digitalWrite(onBoardLED, LOW);    // turn off the onboard LED

  pinMode(potPIN, INPUT);           // listen on potPIN
  pinMode(yellowLED, OUTPUT);       // setup yellow LED pin for OUTPUT
  pinMode(blueLED, OUTPUT);         // setup blue LED pin for OUTPUT
  Serial.begin(9600);               // start serial communications

}

void loop() {
  potRead = analogRead(potPIN);             // read from the potentiometer
  potVoltage = (5.0 / 1023.0) * potRead;    // calculate the voltage based on slope of line between potRead(1023) and 5.0v
  LEDWrite = (255.0/1023.0)* potRead;       // caluclate the write value to set proper voltage for LED output
  Serial.print("Potentiometer Voltage: ");  // format the serial output
  Serial.print(potVoltage);                 // print result as voltage
  Serial.print(";  LED value to write: ");  // format the serial output
  Serial.println(LEDWrite);                 // write to serial monitor pot value being set
  analogWrite(yellowLED, LEDWrite);         // write brigtness value based on pot setting
  analogWrite(blueLED, LEDWrite);           // write brigtness value based on pot setting
}

