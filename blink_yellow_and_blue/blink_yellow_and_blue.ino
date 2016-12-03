// Global Variables
int yellowLED=11;
int blueLED=9;
int onBoardLED=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(onBoardLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int yellowOn=500;
  int yellowOff=500;
  int blueOn=500;
  int blueOff=500;

  digitalWrite(yellowLED,HIGH);
  delay(yellowOn);
  digitalWrite(yellowLED,LOW);
  delay(yellowOff);
  
  digitalWrite(blueLED,HIGH);
  delay(blueOn);
  digitalWrite(blueLED,LOW);
  delay(blueOff);  
}
