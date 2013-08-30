const int analogInPin = A0; 
const int buttonInPin = 2; 
const int SpeakerPin = 13; 

void setup() {
  pinMode(buttonInPin, INPUT);   
  pinMode(SpeakerPin, OUTPUT);   
}

void loop() {
  int buttonState = digitalRead(buttonInPin);
  if(buttonState == HIGH){
    int sensorValue = analogRead(analogInPin);
    int frequency = map(sensorValue, 0, 1023, 50, 400);
    tone(SpeakerPin, frequency);
  }
}
