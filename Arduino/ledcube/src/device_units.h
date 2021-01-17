#ifndef DEVICE_UNITS
#define DEVICE_UNITS

#include <Arduino.h>
#include "device_setup.h"
#include "device_types.h"
#include "device_controls.h"
#include "hardware/controls.h"
#include "hardware/power_switch.h"
#include "lib/led_cube.h"

class DeviceUnits : public IPowerControlDelegate {
  private:
    LedCube * cube;
    IDeviceControls * controls;

    void initCube();
    void initControls();
    void initRandomSeed();
  public:
    DeviceUnits();
    void powerOff();

    LedCube * getCube() {
      return cube;
    }

    IDeviceControls * getControls() {
      return controls;
    }
};

#endif