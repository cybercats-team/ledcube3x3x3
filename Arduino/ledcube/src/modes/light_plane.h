#ifndef LIGHT_PLANE
#define LIGHT_PLANE

#include "cube_animation.h"

class LightPlaneMode : public ICubeAnimationMode {
  public:
    LightPlaneMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // light each plane
      for (byte i = 3; i; i--)
      {
        for (byte row = 1; row <= cube->getLevels() * 2; row++)
        {
          cube->lightPlane(row, 10 * i);

          HANDLE_INTERRUPTED()
        }
      }
    }
};

#endif
