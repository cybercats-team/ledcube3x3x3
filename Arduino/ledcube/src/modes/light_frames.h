#ifndef LIGHT_FRAMES
#define LIGHT_FRAMES

#include "cube_animation.h"

class LightFramesMode : public ICubeAnimationMode {
  private:
    cubeFrame ** frames;
    byte framesCount = 8;
    byte frameLeds[8][6] = {
      {0,6, 1,6, 2,6},
      {0,7, 1,7, 2,7},
      {0,8, 1,8, 2,8},
      {0,5, 1,5, 2,5},
      {0,2, 1,2, 2,2},
      {0,1, 1,1, 2,1},
      {0,0, 1,0, 2,0},
      {0,3, 1,3, 2,3}
    };
  public:
    LightFramesMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      ICubeAnimationMode(deviceUnits, deviceStateManager) {}

    void onActivated() {
      frames = new cubeFrame *[framesCount];

      for (byte frame = 0; frame < framesCount; frame++) {
        frames[frame] = cube->createFrame(frameLeds[frame], 6, 10 * (framesCount - frame));
      }
    }

    void animate() {
      delayMs(10);
      HANDLE_INTERRUPTED()
      cube->lightFrames(frames, framesCount);
    }

    void onDeactivated() {
      cube->destroyFrames(frames, framesCount);
      delete frames;
    }
};

#endif
