#include "controls.h"

Controls::Controls(int btnPin, int clkPin, float minRatio, float maxRatio, IPowerController * pwrSwitch)
  : IPowerHandler(pwrSwitch) 
{
  buttonPin = btnPin;
  wheelPin = clkPin;

  pinMode(buttonPin, INPUT);
  pinMode(wheelPin, INPUT);

  baseRatio = ((float) (1 << CLOCK_INPUT_RESOLUTION)) / (maxRatio - minRatio);
  minimalRatio = minRatio;
  updateRatio(true);

  debouncer = new Debouncer(buttonPin, MODE_DEBOUNCE_DELAY);
}

float Controls::getClockRatio() {
  updateRatio();

  return clockRatio;
}

bool Controls::isInterrupted() {
  updateRatio();

  return powerSwitch->shuttingDown() || (debouncer->read() == LOW);
}

void Controls::updateRatio() {
  updateRatio(false);
}

void Controls::updateRatio(bool initialize) {
  int reading = analogRead(wheelPin);

  if (initialize || (reading != lastLevel)) {
    clockRatio = minimalRatio + ((float) reading) / baseRatio;
    lastLevel = reading;
  }
}
