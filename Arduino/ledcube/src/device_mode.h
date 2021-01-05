#ifndef DEVICE_MODE
#define DEVICE_MODE

#include "device_units.h"
#include "device_controls.h"

class IDeviceStateManager {
  public:
    virtual DeviceMode getActiveMode() = 0;
    virtual void setActiveMode(DeviceMode newMode) = 0;
    virtual ~IDeviceStateManager(){};
};

class IDeviceModeHandler: public IDeviceControlsDelegate {
  protected:
    IDeviceStateManager * stateManager;
    DeviceUnits * units;
  public:
    IDeviceModeHandler(DeviceUnits * deviceUnits, IDeviceStateManager * deviceStateManager)
      : IDeviceControlsDelegate(units->getControls())
    {
      units = deviceUnits;
      stateManager = deviceStateManager;
    }

    virtual void onLoop() = 0;
    virtual void onActivated(){};
    virtual void onDeactivated(){};
    virtual ~IDeviceModeHandler(){};
};

#endif
