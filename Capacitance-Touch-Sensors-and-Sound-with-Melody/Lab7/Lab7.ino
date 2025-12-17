#include <FastTouch.h>
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

// Pin Vars
int sensor = 22;
int speaker = 14;

// Calibration Vars
volatile int minReading = 1023;
volatile int maxReading = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Calibration
  // calibrate();
  // Serial.println(minReading);
  // Serial.println(maxReading);
  // Serial.println();

  // read the sensor:
  int sensorReading = fastTouchRead(sensor);

  // print the sensor reading
  // Serial.println(sensorReading);

  // map reading
  int mapping = map(sensorReading, 12, 64, 0, 255);
  Serial.println(mapping);

  // play the pitch:
  if (mapping > 5) {
    // tone(speaker, mapping, 100);
    playSong();
  }

  delay(100);
}

void calibrate() {
  int reading = 0;
  for(int i = 0; i < 100; i++)
  {
    reading = fastTouchRead(sensor);
    if(reading < minReading)
      minReading = reading;
    if(reading > maxReading)
      maxReading = reading;
  }
} //end calibrate

void playSong() {

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 14; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(speaker, melody[thisNote], noteDuration*2);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30*2;

    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(speaker);
  }
}
