#ifndef DistanceControl_h
#define DistanceControl_h

#include "Arduino.h"
#include "MIDIControl.h"


#define VL6180X_ADDRESS 0x29
VL6180x _sensor(VL6180X_ADDRESS);
class DistanceControl : public MIDIControl {
   public:
     DistanceControl( int midiControlValue);
     void update();
   private:
     int _midiControlValue;
     int _lastValue;
     
};

DistanceControl::DistanceControl(int midiControlValue) {
  _midiControlValue = midiControlValue;
  _lastValue = 0; 
    Wire.begin(); //Start I2C library
  delay(100); // delay .1s
  if(_sensor.VL6180xInit() != 0){
    Serial.println("FAILED TO INITALIZE"); //Initialize device and check for errors
  }; 

  _sensor.VL6180xDefautSettings(); //Load default settings to get started.
  
    delay(1000); // delay 1s
}

void DistanceControl::update() {
  int rawInput = _sensor.getDistance();
  int newValue = map(rawInput, 0, 1023, 0, 127);
//  if (newValue != _lastValue) MIDI.sendControlChange(_midiControlValue, newValue, 1);
  _lastValue = newValue;
  Serial.println(newValue);
}

#endif
