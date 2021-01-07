#ifndef LIGHT_FACE
#define LIGHT_FACE

#include "cube_animation.h"

class LightFaceMode : public ICubeAnimationMode {
  public:
    LightFaceMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // light each face
      byte planes[] = {
        (byte) (cube->getLevels() + 1),
        cube->getLevels(),
        (byte) (cube->getLevels() * 2),
        1
      };

      for (byte i = 5; i; i--)
      {
        for (byte p = 0; p < sizeof(planes); p++)
        {
          cube->lightPlane(planes[p], 5 * i);
        }
      }
    }
};

#endif
