#ifndef DEMO_MODE
#define DEMO_MODE

#include <Arduino.h>
#include "../device_mode.h"
#include "../device_types.h"

class DemoMode : public IDeviceModeHandler {
  private:
    LedCube * cube;
    byte framesCount;
    byte frameLeds[CUBE_FRAMES][6];
  public:
    DemoMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager);
    void onLoop();
};

#endif
