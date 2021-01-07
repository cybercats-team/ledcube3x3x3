#ifndef LIGHT_PULSE
#define LIGHT_PULSE

#include "cube_animation.h"

class LightPulseMode : public ICubeAnimationMode {
  public:
    LightPulseMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // light each light one at a time
      for (byte level = 0; level < cube->getLevels(); level++)
      {
        for (byte col = 0; col < cube->getCols(); col++)
        {
          cube->lightPulse(level, col, 100);

          HANDLE_SWITCH()
        }
      }
    }
};

#endif
