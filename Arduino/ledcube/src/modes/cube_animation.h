#ifndef CUBE_ANIMATION
#define CUBE_ANIMATION

#include "../device_mode.h"
#include "../device_controls.h"

class ICubeAnimationMode :
  public IDeviceModeHandler,
  public IDeviceControlsDelegate
{
  protected:
    LedCube * cube;
  public:
    virtual void animate() = 0;

    ICubeAnimationMode(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager) :
      IDeviceModeHandler(deviceUnits, deviceStateManager),
      IDeviceControlsDelegate(deviceUnits->getControls()),
      cube(deviceUnits->getCube()) {}

    void onLoop() {
      animate();
      stateManager->setRandomMode();
    }
};

#endif
