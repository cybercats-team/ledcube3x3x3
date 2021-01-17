#ifndef DEVICE_CONTROLS
#define DEVICE_CONTROLS

#include "device_setup.h"
#include "hardware/power_switch.h"

#define HANDLE_SWITCH()   \
if (isInterrupted()) { \
  return;                 \
}

class IDeviceControls: public IPowerController {
  public:
    virtual float getClockRatio() = 0;
    virtual bool isInterrupted() = 0;
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

    virtual bool isInterrupted() {
      return controls->isInterrupted();
    }
};

#endif
