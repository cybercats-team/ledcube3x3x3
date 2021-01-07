#ifndef DIAMOND_BOX
#define DIAMOND_BOX

#include "cube_animation.h"

class DiamondBoxMode : public ICubeAnimationMode {
  private:
    byte diamond[14] = {0,4, 1,1, 1,3, 1,4, 1,5, 1,7, 2,4};
    byte box[40] = {
      2,0, 2,1, 2,2, 2,3, 2,5, 2,6, 2,7, 2,8,
      1,0, 1,2, 1,6, 1,8,
      0,0, 0,1, 0,2, 0,3, 0,5, 0,6, 0,7, 0,8
    };
  public:
    DiamondBoxMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onLoop() {
      // diamond and box
      cube->lightSequence(box, sizeof(box), 200);
      cube->lightSequence(diamond, sizeof(diamond), 400);
    }
};

#endif
