#ifndef DEVICE_CONTROLS
#define DEVICE_CONTROLS

#include "device_setup.h"

#define HANDLE_SWITCH()   \
if (shouldSwitchMode()) { \
  return;                 \
}

class IDeviceControls {
  public:
    virtual float getClockRatio() = 0;
    virtual bool shouldSwitchMode() = 0;
};

class IDeviceControlsDelegate {
  protected:
    IDeviceControls * controls;
  public:
    IDeviceControlsDelegate(IDeviceControls * deviceControls) {
      controls = deviceControls;
    }

    void delayMs(unsigned long ms) {
      float ratio = controls->getClockRatio();
      unsigned long msWithRatio = (unsigned long) ((float) ms * ratio);

      if (msWithRatio > 0) {
        delay(msWithRatio);
      }
    }

    virtual bool shouldSwitchMode() {
      return controls->shouldSwitchMode();
    }
};

#endif
