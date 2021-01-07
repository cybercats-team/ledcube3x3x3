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
    int lastLevel;
    float clockRatio = 0.0;
    float baseRatio;
    float minimalRatio;
    Debouncer * debouncer;
    void updateRatio();
    void updateRatio(bool initialize);
  public:
    Controls(int btnPin, int clkPin, float minRatio, float maxRatio);
    float getClockRatio();
    bool shouldSwitchMode();
};

#endif