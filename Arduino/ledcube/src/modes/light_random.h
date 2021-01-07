#ifndef LIGHT_RANDOM
#define LIGHT_RANDOM

#include "cube_animation.h"

class LightRandomMode : public ICubeAnimationMode {
  public:
    LightRandomMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // single random light at a time
      cube->randomLight(random(25,100), 100);
    }
};

#endif
