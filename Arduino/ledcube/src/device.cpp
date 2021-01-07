#include "device.h"

Device * Device::instance;

void Device::setup() {
  if (instance != nullptr) {
    return;
  }

  instance = new Device();
}

void Device::loop() {
  if (instance == nullptr) {
    return;
  }

  instance->onLoop();
}

int Device::getModeIndex(DeviceMode mode) {
  return static_cast<int>(mode);
}

Device::Device() :
  units(new DeviceUnits()),
  handlers({
    { .mode = DeviceMode::Demo, .handler = new DemoMode(units, this) }
  })
{
  IDeviceModeHandler * defaultModeHandler = nullptr;
  handlersForMode = new (IDeviceModeHandler *[DEVICE_MODES_COUNT]);

  for (auto h: handlers) {
    int modeIndex = Device::getModeIndex(h.mode);

    handlersForMode[modeIndex] = h.handler;

    if (defaultModeHandler == nullptr) {
      activeMode = h.mode;
      defaultModeHandler = h.handler;
    }
  }

  defaultModeHandler->onActivated();
}

DeviceMode Device::getActiveMode() {
  return activeMode;
}

void Device::setActiveMode(DeviceMode newMode) {
  if ((newMode == activeMode) || !isModeAllowed(newMode)) {
    return;
  }

  IDeviceModeHandler * currentHandler = getActiveModeHandler();

  currentHandler->onDeactivated();
  activeMode = newMode;

  getActiveModeHandler()->onActivated();
}

void Device::onLoop() {
  getActiveModeHandler()->onLoop();
}

IDeviceModeHandler * Device::getActiveModeHandler() {
  int modeIndex = Device::getModeIndex(activeMode);

  return handlersForMode[modeIndex];
}

bool Device::isModeAllowed(DeviceMode mode) {
  bool isValid = false;

  for (auto h: handlers) {
    if (h.mode == mode) {
      isValid = true;
      break;
    }
  }

  return isValid;
}
