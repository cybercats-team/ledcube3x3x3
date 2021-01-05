#include "controls.h"

Controls::Controls(int btnPin, int clkPin, float minRatio, float maxRatio) {
  buttonPin = btnPin;
  wheelPin = clkPin;

  pinMode(buttonPin, INPUT);
  pinMode(wheelPin, INPUT);
  lastLevel = analogRead(wheelPin);

  debouncer = new Debouncer(buttonPin, MODE_DEBOUNCE_DELAY);
  baseRatio = ((float) (1 << CLOCK_INPUT_RESOLUTION)) / (maxRatio - minRatio);
  minimalRatio = minRatio;
}

float Controls::getClockRatio() {
  int reading = analogRead(wheelPin);

  if ((clockRatio <= 0.0) || (reading != lastLevel)) {
    clockRatio = minimalRatio + ((float) reading) / baseRatio;
    lastLevel = reading;
  }

  return clockRatio;
}

bool Controls::shouldSwitchMode() {
  return debouncer->read() == LOW;
}
