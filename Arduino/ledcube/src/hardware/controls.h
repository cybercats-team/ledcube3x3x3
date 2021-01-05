#ifndef CONTROLS
#define CONTROLS

#include <Arduino.h>
#include "../device_setup.h"
#include "../device_controls.h"
#include "../lib/debouncer.h"

class Controls : public IDeviceControls {
  private:
    int buttonPin;
    int wheelPin;
    bool switchState = false;   // the current "switch mode" state
    Debouncer * debouncer;
  public:
    Controls(int btnPin, int clkPin);
    float getClockRatio();
    bool shouldSwitchMode();
};

#endif