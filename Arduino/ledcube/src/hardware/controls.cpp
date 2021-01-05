#include "controls.h"

Controls::Controls(int btnPin, int clkPin) {
  buttonPin = btnPin;
  wheelPin = clkPin;

  pinMode(buttonPin, INPUT);
  pinMode(wheelPin, INPUT);

  debouncer = new Debouncer(buttonPin, MODE_DEBOUNCE_DELAY);
}

float Controls::getClockRatio() {

}

bool Controls::shouldSwitchMode() {
  return debouncer->read() == LOW;
}
