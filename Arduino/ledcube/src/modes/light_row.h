#ifndef LIGHT_ROW
#define LIGHT_ROW

#include "cube_animation.h"

class LightRowMode : public ICubeAnimationMode {
  public:
    LightRowMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // light each row on each level
      for (byte level = 1; level <= cube->getLevels(); level++)
      {
        for (byte row=1; row <= cube->getLevels() * 2; row++)
        {
          cube->lightRow(row, level);

          HANDLE_SWITCH()
        }
      }
    }
};

#endif
