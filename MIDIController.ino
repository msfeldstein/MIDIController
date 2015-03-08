#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>

#include "MIDISetup.h"
#include "MIDIControl.h"
#include "ControlInput.h"
#include "NoteButton.h"

MIDIControl* controls[4] = {
  new NoteButton(2, 36),
  new NoteButton(3, 40),
  new ControlInput(5, 10),
  new ControlInput(7, 11)
};

int LED = 13;
int lastSignal = 0;

void setup()
{
  MIDI.begin();
  // 115200 for hairless-midiserial
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 4; i++) {
    controls[i]->update(); 
  }
}
