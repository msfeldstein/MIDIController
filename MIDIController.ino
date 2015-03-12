#include <MIDI.h>
#include <Wire.h>
#include <SFE_VL6180X.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#include "MIDIControl.h"
#include "ControlInput.h"
#include "NoteButton.h"
#include "DistanceControl.h"

const int NUM_CONTROLS = 5;
MIDIControl* controls[NUM_CONTROLS] = {
  new NoteButton(2, 36),
  new NoteButton(3, 40),
  new ControlInput(5, 10),
  new ControlInput(7, 11),
  new DistanceControl(12)
};

int LED = 13;
int lastSignal = 0;

void setup()
{
  MIDI.begin();
  // 115200 for hairless-midiserial
  Serial.begin(115200);
  Serial.println("HellO");
  pinMode(LED, OUTPUT);
}

void loop()
{
  Serial.println("Hi");
  delay(100);
  for (int i = 0; i < NUM_CONTROLS; i++) {
    controls[i]->update(); 
  }
 
}
