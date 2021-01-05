#ifndef DEBOUNCER
#define DEBOUNCER

#include <Arduino.h>

class Debouncer {
  private:
    int inputPin;
    int buttonState;     // the current reading from the input pin
    int lastButtonState; // the previous reading from the input pin
    unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
    unsigned long debounceDelay;    // the debounce time; increase if the output flickers
  public:
    Debouncer(int inputPin, int delay);
    int read();
};

#endif
