#ifndef LIGHT_LEVEL
#define LIGHT_LEVEL

#include "cube_animation.h"

class LightLevelMode : public ICubeAnimationMode {
  public:
    LightLevelMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // light one level at a time, increasing speed each time
      for (byte d = 25; d > 2; d-=2)
      {
        for (byte l = 1; l <= cube->getLevels(); l++)
        {
          cube->lightLevel(l, d);

          HANDLE_SWITCH()
        }
      }
    }
};

#endif
