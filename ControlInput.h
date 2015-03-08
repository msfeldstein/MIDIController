#ifndef ControlInput_h
#define ControlInput_h

#include "Arduino.h"
#include "MIDIControl.h"
#include "MIDISetup.h"

class ControlInput : public MIDIControl {
   public:
     ControlInput(int pin, int midiControlValue);
     void update();
   private:
     int _pin;
     int _midiControlValue;
     int _lastValue;
};

ControlInput::ControlInput(int pin, int midiControlValue) {
   _pin = pin;
  _midiControlValue = midiControlValue;
  _lastValue = 0; 
}

void ControlInput::update() {
  int rawInput = analogRead(_pin);
  int newValue = map(rawInput, 0, 1023, 0, 127);
  if (newValue != _lastValue) MIDI.sendControlChange(11, newValue, 1);
  _lastValue = newValue;
}

#endif
