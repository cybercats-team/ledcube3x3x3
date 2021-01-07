#ifndef LIGHT_OUT
#define LIGHT_OUT

#include "cube_animation.h"

class LightOutMode : public ICubeAnimationMode {
  public:
    LightOutMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // turn off one light at a time
      cube->lightsOut();
    }
};

#endif
