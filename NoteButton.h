#ifndef NoteButton_h
#define NoteButton_h

#include "Arduino.h"
#include "MIDIControl.h"

class NoteButton : public MIDIControl {
  public:
    NoteButton(int pin, int note);
    void update();
  private:
    int _pin;
    int _note;
    int _currentState;
};

NoteButton::NoteButton(int pin, int note) {
  pinMode(pin, INPUT);
  _pin = pin;
  _note = note;
  _currentState = LOW;
}

void NoteButton::update() {
  int newState = digitalRead(_pin);
  if (newState != _currentState) {
     _currentState = newState;
//     if (newState == HIGH)
//       MIDI.sendNoteOn(_note, 127, 1);
//     else
//       MIDI.sendNoteOff(_note,  0, 1);
  }
}

#endif
