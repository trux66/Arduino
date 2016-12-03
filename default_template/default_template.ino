// Setup global variables
int onBoardLED = 13; // setup pin for onboard LED
int potPIN = A0;    // potentiometer is connected to pin A0


void setup() {
  // put your setup code here, to run once:
  pinMode(onBoardLED, OUTPUT);      // setup onBoardLED PIN for OUTPUT
  digitalWrite(onBoardLED, LOW);    // turn off the onboard LED
}

void loop() {
  // put your main code here, to run repeatedly:

}

