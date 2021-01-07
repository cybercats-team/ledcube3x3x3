#ifndef COLUMN_INOUT
#define COLUMN_INOUT

#include "cube_animation.h"

class ColumnInOutMode : public ICubeAnimationMode {
  public:
    ColumnInOutMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // cols in and out
      for (byte c = 1, d = 0; c <= 10; c++)
      {
        if (c % 2 == 0)
        {
          for (d=0; d < 20; d++)
          {
            cube->lightColumn(2,1);
            cube->lightColumn(4,1);
            cube->lightColumn(6,1);
            cube->lightColumn(8,1);
          }
        }
        else if (c % 4 == 1)
        {
          for (d = 0; d < 30; d++)
          {
            cube->lightColumn(1,1);
            cube->lightColumn(3,1);
            cube->lightColumn(7,1);
            cube->lightColumn(9,1);
          }
        }
        else
        {
          for (d = 0; d < 70; d++)
          {
            cube->lightColumn(5,1);
          }
        }
      }
    }
};

#endif
