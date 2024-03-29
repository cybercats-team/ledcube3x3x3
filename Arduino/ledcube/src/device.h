#ifndef DEVICE
#define DEVICE

#include <Arduino.h>
#include "device_setup.h"
#include "device_types.h"
#include "device_mode.h"
#include "device_units.h"
#include "device_controls.h"

#include "modes/light_frames.h"
#include "modes/light_pulse.h"
#include "modes/light_level.h"
#include "modes/light_row.h"
#include "modes/light_plane.h"
#include "modes/light_random.h"
#include "modes/light_drop.h"
#include "modes/light_perimeter.h"
#include "modes/light_face.h"
#include "modes/column_random.h"
#include "modes/column_drop.h"
#include "modes/column_inout.h"
#include "modes/diamond_box.h"
#include "modes/helicopter_effect.h"
#include "modes/light_out.h"

struct DeviceModeHandlerMap {
  DeviceMode mode;
  IDeviceModeHandler * handler;
};

class Device :
  public IDeviceStateManager,
  public IPowerControlDelegate,
  public IPowerHandler
{
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
    void deactivateCurrentMode();
    void activateMode(DeviceMode newMode);
    DeviceMode selectRandomMode();
    static int getModeIndex(DeviceMode mode);
  public:
    static void setup();
    static void loop();

    DeviceMode getActiveMode();
    void setActiveMode(DeviceMode newMode);
    void setRandomMode();
    void powerOn();
    void powerOff();
};

#endif
