#ifndef DEVICE_CONTROLS
#define DEVICE_CONTROLS

#include "device_setup.h"

#define HANDLE_INTERRUPTED()   \
if (isInterrupted()) { \
  return;                 \
}

class IPowerControlDelegate {
  public:
    virtual void powerOff() = 0;
};

class IPowerController {
  public:
    virtual bool shuttingDown() = 0;
    virtual bool poweredOff() = 0;
};

class IPowerHandler: public IPowerController {
  protected:
    IPowerController * powerSwitch;
  public:
    IPowerHandler(IPowerController * pwrSw) {
      powerSwitch = pwrSw;
    }

    bool shuttingDown() {
      return powerSwitch->shuttingDown();
    }

    bool poweredOff() {
      return powerSwitch->poweredOff();
    }
};

class IDeviceControls: public IPowerHandler {
  public:
    IDeviceControls(IPowerController * pwrSwitch): IPowerHandler(pwrSwitch) {}
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
