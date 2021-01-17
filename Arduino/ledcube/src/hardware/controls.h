#ifndef CONTROLS
#define CONTROLS

#include <Arduino.h>
#include "../device_setup.h"
#include "../device_controls.h"
#include "../lib/debouncer.h"
#include "power_switch.h"

class Controls : 
  public IDeviceControls, 
  public IPowerHandler 
{
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
    Controls(int btnPin, int clkPin, float minRatio, float maxRatio, IPowerController * pwrSwitch);
    float getClockRatio();
    bool isInterrupted();
};

#endif