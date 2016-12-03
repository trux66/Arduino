// Setup global variables
int onBoardLED = 13;    // setup pin for onboard LED
int potPIN = A0;        // potentiometer is connected to pin A0
int potRead;            // place to hold input values from potentiometer
float potVoltage;       // place to hold real world voltage value of the potentiometer setting

void setup() {
  pinMode(onBoardLED, OUTPUT);      // setup onBoardLED PIN for OUTPUT
  digitalWrite(onBoardLED, LOW);    // turn off the onboard LED

  pinMode(potPIN, INPUT);           // listen on potPIN
  Serial.begin(19200);              // start serial communications
}

void loop() {
  potRead = analogRead(potPIN);           // read from the potentiometer
  potVoltage = (5.0 / 1023.0) * potRead;  // calculate the voltage based on slope of line between potRead(1023) and 5.0v
  Serial.println(potVoltage);             // print result as voltage
  delay(250);                             // pause for 1/4 sec to allow slower scrolling
}

