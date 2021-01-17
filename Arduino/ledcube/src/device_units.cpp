#include "device_units.h"

DeviceUnits::DeviceUnits() {
  initRandomSeed();
  initControls();
  initCube();
}

void DeviceUnits::initRandomSeed() {
  pinMode(RANDOM_SEED_PIN, INPUT);
  randomSeed(analogRead(RANDOM_SEED_PIN));
}

void DeviceUnits::initControls() {
  controls = new Controls(
    MODE_TOGGLE_PIN,
    CLOCK_INPUT_PIN,
    (float) CLOCK_RATIO_MIN,
    (float) CLOCK_RATIO_MAX,
    PowerSwitch::configure(POWER_TOGGLE_PIN, this)
  );
}

void DeviceUnits::initCube() {
  byte levelPins[CUBE_LEVEL_PINS_COUNT] = {
    LEVEL1_PIN, LEVEL2_PIN, LEVEL3_PIN
  };

  byte colPins[CUBE_COLUMN_PINS_COUNT] = {
    ROW1_COL1_PIN, ROW1_COL2_PIN, ROW1_COL3_PIN,
    ROW2_COL1_PIN, ROW2_COL2_PIN, ROW2_COL3_PIN,
    ROW3_COL1_PIN, ROW3_COL2_PIN, ROW3_COL3_PIN
  };

  cube = new LedCube(CUBE_SIZE, levelPins, colPins, controls);
}

void DeviceUnits::powerOff() {
  cube->turnOffAndReset();
}
