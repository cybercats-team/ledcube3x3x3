#include "power_switch.h"

PowerSwitch * PowerSwitch::instance = nullptr;

void PowerSwitch::onToggle() {
  instance->toggle();
}

void PowerSwitch::onWake() {
  instance->wake();
}

PowerSwitch::PowerSwitch(int powerPin, IPowerControlDelegate * delegate) {
  this->powerPin = powerPin;
  this->delegate = delegate;
  pwrInt = digitalPinToInterrupt(powerPin);

  pinMode(powerPin, INPUT);
  attachInterrupt(pwrInt, PowerSwitch::onToggle, HIGH);
  sleepOnNextLoop = digitalRead(powerPin) == HIGH;
}

void PowerSwitch::wake() {
  sleepOnNextLoop = false;
  delegate->powerOn();
}

void PowerSwitch::toggle() {
  detachInterrupt(pwrInt);
  sleepOnNextLoop = true;
}

void PowerSwitch::sleep() {
  delegate->powerOff();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  attachInterrupt(pwrInt, PowerSwitch::onWake, LOW);
  sleep_mode();
}

PowerSwitch * PowerSwitch::configure(int powerPin, IPowerControlDelegate * delegate) {
  if (instance == nullptr) {
    instance = new PowerSwitch(powerPin, delegate);
  }

  return instance;
}

bool PowerSwitch::shuttingDown() {
  return sleepOnNextLoop;
}

bool PowerSwitch::poweredOff() {
  if (sleepOnNextLoop) {
    sleep();
    return true;
  }

  attachInterrupt(pwrInt, PowerSwitch::onToggle, HIGH);
  return false;
}