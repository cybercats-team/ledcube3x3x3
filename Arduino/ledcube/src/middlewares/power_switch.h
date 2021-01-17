#ifndef POWER_SWITCH
#define POWER_SWITCH

#include <Arduino.h>
#include <avr/sleep.h>

class IPowerControlDelegate {
  public:
    virtual void powerOff() = 0;
};

class PowerSwitch {
  private:
    static PowerSwitch * instance;

    static void onToggle() {
      instance->toggle();
    }

    static void onWake() {
      instance->wake();
    }
    
    int powerPin;
    int pwrInt;
    bool sleepOnNextLoop;
    IPowerControlDelegate * delegate;
    
    PowerSwitch(int powerPin, IPowerControlDelegate * delegate = nullptr) {
      this->powerPin = powerPin;
      this->delegate = delegate;
      pwrInt = digitalPinToInterrupt(powerPin);

      pinMode(powerPin, INPUT);       
      attachInterrupt(pwrInt, PowerSwitch::onToggle, HIGH);
      updateSleepState();
    }

    void prepareToSleep() {
      if (delegate == nullptr) {
        return;
      }

      delegate->powerOff();
    }
    
    void wake() {    
      sleepOnNextLoop = false;
    }
    
    void toggle() {
      detachInterrupt(pwrInt);
      updateSleepState();
    }
    
    void sleep() {
      prepareToSleep();
         
      set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
      attachInterrupt(pwrInt, PowerSwitch::onWake, LOW); 
      sleep_mode();
    }

    void updateSleepState() {
      sleepOnNextLoop = digitalRead(powerPin) == HIGH; 
    }
  public:
    PowerSwitch(PowerSwitch &other) = delete;    
    void operator=(const PowerSwitch &) = delete;
    
    static PowerSwitch * configure(int powerPin, IPowerControlDelegate * delegate = nullptr) {
      if (instance == nullptr) {
        instance = new PowerSwitch(powerPin, delegate);
      }

      return instance;
    }

    bool poweredOff() {
      if (sleepOnNextLoop) {
        sleep();
        return true;
      }
    
      attachInterrupt(pwrInt, PowerSwitch::onToggle, HIGH);
      return false;
    }
};

PowerSwitch * PowerSwitch::instance = nullptr;


#endif