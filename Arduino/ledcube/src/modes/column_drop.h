#ifndef COLUMN_DROP
#define COLUMN_DROP

#include "cube_animation.h"

class ColumnDropMode : public ICubeAnimationMode {
  public:
    ColumnDropMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onActivated() {
      cube->enableBuffer();
    }

    void onDeactivated() {
      cube->enableBuffer(false);
    }

    void animate() {
      // turn off a single column randomly
      for (byte c = 0; c < 30; c++)
      {
        cube->fillBuffer();
        cube->invertBuffer();
        cube->randomColumn();
        cube->drawBuffer(7);

        HANDLE_SWITCH()
      }
    }
};

#endif
