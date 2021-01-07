#ifndef LIGHT_PERIMETER
#define LIGHT_PERIMETER

#include "cube_animation.h"

class LightPerimeterMode : public ICubeAnimationMode {
  public:
    LightPerimeterMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // circle around cube at a random level
      for (byte x = 0; x <= 5; x++)
      {
        cube->lightPerimeter(random(0, cube->getLevels()), random(1,5), random(25,100));
      }
    }
};

#endif
