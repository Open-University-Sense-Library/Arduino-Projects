#include "pitches.h"


const int analogInPin = A0; //Speaker or buzzer pin
const int stepRange = 16; //Range of the synth, rough estimate
const float toneSnap = 1.059384363933533; //currently set to a semitone
const int startingNote = NOTE_E5; //lowest note playable, also determines the key


int chromaticarray[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
int majorarray[] = {0,2,4,5,7,9,11};
int minorarray[] = {0,2,3,5,7,8,11};
int arparray[] = {0,4,7};
int marparray[] = {0,3,7};
int minorbluearray[] = {0,3,5,6,7,10,12};


int sensorValue = 0; 
int noteValue = 0;    

float getScaleFreq(int notearray[], int scaleNo, int arraysize){
  int scaleSize = arraysize / sizeof(int);
  return startingNote * pow(2, floor(scaleNo/scaleSize)) * pow(toneSnap,notearray[scaleNo%scaleSize]);
}

void setup() {
}

void loop() {
  sensorValue = analogRead(analogInPin); 
  noteValue = map(sensorValue, 0, 1023, 0, stepRange);  
  tone(13, getScaleFreq(minorbluearray, noteValue, sizeof(minorbluearray)));
  delay(2);
}


