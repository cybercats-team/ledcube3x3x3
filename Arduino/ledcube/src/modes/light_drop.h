#ifndef LIGHT_DROP
#define LIGHT_DROP

#include "cube_animation.h"

class LightDropMode : public ICubeAnimationMode {
  public:
    LightDropMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // random column drop
      for (byte x = 0; x <= 15; x++)
      {
        cube->lightDrop(random(0, cube->getCols()), random(50, 150));

        HANDLE_SWITCH()
      }
    }
};

#endif
