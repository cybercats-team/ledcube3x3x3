#ifndef COLUMN_RANDOM
#define COLUMN_RANDOM

#include "cube_animation.h"

class ColumnRandomMode : public ICubeAnimationMode {
  public:
    ColumnRandomMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // random columns
      cube->randomColumn(25);
    }
};

#endif
