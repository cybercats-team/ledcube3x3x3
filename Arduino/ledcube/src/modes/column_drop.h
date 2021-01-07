#ifndef COLUMN_DROP
#define COLUMN_DROP

#include "cube_animation.h"

class ColumnDropMode : public ICubeAnimationMode {
  public:
    ColumnDropMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // turn off a single column randomly
      cube->enableBuffer();

      for (byte c = 0; c < 30; c++)
      {
        cube->fillBuffer();
        cube->invertBuffer();
        cube->randomColumn();
        cube->drawBuffer(7);
      }

      cube->enableBuffer(false);
    }
};

#endif
