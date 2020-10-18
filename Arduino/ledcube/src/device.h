#ifndef DEVICE
#define DEVICE

#include "device_setup.h"
#include "device_types.h"
#include "device_mode.h"
#include "device_units.h"
#include "lib/utils.h"
#include "modes/demo.h"

struct DeviceModeHandlerMap {
  DeviceMode mode;
  IDeviceModeHandler * handler;
};

class Device: public IDeviceStateManager {
  private:
    static Device * instance;
    DeviceUnits * units;
    DeviceMode activeMode;
    IDeviceModeHandler ** handlersForMode;
    DeviceModeHandlerMap handlers[DEVICE_MODES_COUNT];

    Device();
    void onLoop();
    IDeviceModeHandler * getActiveModeHandler();
    bool isModeAllowed(DeviceMode mode);
    static int getModeIndex(DeviceMode mode);
  public:
    static void setup();
    static void loop();

    DeviceMode getActiveMode();
    void setActiveMode(DeviceMode newMode);
};

#endif
