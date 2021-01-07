#ifndef HELICOPTER
#define HELICOPTER

#include "cube_animation.h"

class HelicopterMode : public ICubeAnimationMode {
  private:
    byte topSeq[8] = {0,3,6,7,8,5,2,1};
    byte botSeq[8] = {8,5,2,1,0,3,6,7};
  public:
    HelicopterMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void animate() {
      // helicopter effect
      for (byte loops = 0, delay = 50; loops <= 8; loops++)
      {
        for (byte s = 0; s < 8; s++)
        {
            byte seq[] = {2 ,topSeq[s], 1, 4, 0, botSeq[s]};
            cube->lightSequence(seq, sizeof(seq), delay);
        }

        if (loops < 5) {
          delay -= 10;
        } else {
          delay += 10;
        }
      }
    }
};

#endif
