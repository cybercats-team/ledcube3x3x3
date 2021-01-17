#include "power_switch.h"

PowerSwitch * PowerSwitch::instance = nullptr;

void PowerSwitch::onToggle() {
  instance->toggle();
}

void PowerSwitch::onWake() {
  instance->wake();
}

PowerSwitch::PowerSwitch(int powerPin, IPowerControlDelegate * delegate = nullptr) {
  this->powerPin = powerPin;
  this->delegate = delegate;
  pwrInt = digitalPinToInterrupt(powerPin);

  pinMode(powerPin, INPUT);       
  attachInterrupt(pwrInt, PowerSwitch::onToggle, HIGH);
  updateSleepState();
}

void PowerSwitch::prepareToSleep() {
  if (delegate == nullptr) {
    return;
  }

  delegate->powerOff();
}

void PowerSwitch::wake() {    
  sleepOnNextLoop = false;
}

void PowerSwitch::toggle() {
  detachInterrupt(pwrInt);
  updateSleepState();
}

void PowerSwitch::sleep() {
  prepareToSleep();
      
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  attachInterrupt(pwrInt, PowerSwitch::onWake, LOW); 
  sleep_mode();
}

void PowerSwitch::updateSleepState() {
  sleepOnNextLoop = digitalRead(powerPin) == HIGH; 
}

PowerSwitch * PowerSwitch::configure(int powerPin, IPowerControlDelegate * delegate = nullptr) {
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