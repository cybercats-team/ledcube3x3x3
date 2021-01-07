#ifndef DEMO_MODE
#define DEMO_MODE

#include "cube_animation.h"

class DemoMode : public ICubeAnimationMode {
  private:
    byte framesCount = 8;
  public:
    DemoMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}    
    void onLoop();
};

#endif
