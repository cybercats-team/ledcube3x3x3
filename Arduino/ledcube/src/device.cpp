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
    { .mode = DeviceMode::LightFrames, .handler = new LightFramesMode(units, this) },
    { .mode = DeviceMode::LightPulse, .handler = new LightPulseMode(units, this) },
    { .mode = DeviceMode::LightLevel, .handler = new LightLevelMode(units, this) },
    { .mode = DeviceMode::LightRow, .handler = new LightRowMode(units, this) },
    { .mode = DeviceMode::LightPlane, .handler = new LightPlaneMode(units, this) },
    { .mode = DeviceMode::LightRandom, .handler = new LightRandomMode(units, this) },
    { .mode = DeviceMode::LightDrop, .handler = new LightDropMode(units, this) },
    { .mode = DeviceMode::LightPerimeter, .handler = new LightPerimeterMode(units, this) },
    { .mode = DeviceMode::LightFace, .handler = new LightFaceMode(units, this) },
    { .mode = DeviceMode::ColumnRandom, .handler = new ColumnRandomMode(units, this) },
    { .mode = DeviceMode::ColumndDrop, .handler = new ColumnDropMode(units, this) },
    { .mode = DeviceMode::ColumnInOut, .handler = new ColumnInOutMode(units, this) },
    { .mode = DeviceMode::DiamondBox, .handler = new DiamondBoxMode(units, this) },
    { .mode = DeviceMode::Helicopter, .handler = new HelicopterMode(units, this) },
    { .mode = DeviceMode::LightOut, .handler = new LightOutMode(units, this) }
  })
{
  handlersForMode = new (IDeviceModeHandler *[DEVICE_MODES_COUNT]);

  for (auto h: handlers) {
    int modeIndex = Device::getModeIndex(h.mode);

    handlersForMode[modeIndex] = h.handler;
  }

  activateMode(selectRandomMode());
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
  activateMode(newMode);
}

void Device::setRandomMode() {
  DeviceMode newMode;

  do {
    newMode = selectRandomMode();
  } while (newMode == activeMode);

  setActiveMode(newMode);
}

void Device::onLoop() {
  getActiveModeHandler()->onLoop();
}

IDeviceModeHandler * Device::getActiveModeHandler() {
  int modeIndex = Device::getModeIndex(activeMode);

  return handlersForMode[modeIndex];
}

void Device::activateMode(DeviceMode newMode) {
  activeMode = newMode;
  getActiveModeHandler()->onActivated();
}

DeviceMode Device::selectRandomMode() {
  DeviceModeHandlerMap selectRandom = handlers[random(0, DEVICE_MODES_COUNT)];

  return selectRandom.mode;
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
