#ifndef DEVICE_SETUP
#define DEVICE_SETUP

#define RANDOM_SEED_PIN A3
#define DEVICE_MODES_COUNT 15
#define MIDDLEWARES_ATTACHED 1

#define POWER_TOGGLE_PIN 2
#define MODE_TOGGLE_PIN A5
#define CLOCK_INPUT_PIN A4

#define MODE_DEBOUNCE_DELAY 20
#define CLOCK_INPUT_RESOLUTION 10

#define CLOCK_RATIO_MIN 0.5
#define CLOCK_RATIO_MAX 2

#define CUBE_SIZE 3
#define CUBE_LEVEL_PINS_COUNT CUBE_SIZE
#define CUBE_COLUMN_PINS_COUNT CUBE_SIZE * CUBE_SIZE

#define LEVEL1_PIN 8
#define LEVEL2_PIN 12
#define LEVEL3_PIN 13

#define ROW1_COL1_PIN A0
#define ROW1_COL2_PIN 9
#define ROW1_COL3_PIN 7
#define ROW2_COL1_PIN A2
#define ROW2_COL2_PIN 0
#define ROW2_COL3_PIN 6
#define ROW3_COL1_PIN A1
#define ROW3_COL2_PIN 11
#define ROW3_COL3_PIN 1

#endif