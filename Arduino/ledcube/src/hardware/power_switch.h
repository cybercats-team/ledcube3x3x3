#ifndef POWER_SWITCH
#define POWER_SWITCH

#include <Arduino.h>
#include <avr/sleep.h>

class IPowerControlDelegate {
  public:
    virtual void powerOff() = 0;
};

class IPowerController {
  public:
    virtual bool shuttingDown() = 0;
    virtual bool poweredOff() = 0;
};

class IPowerHandler: public IPowerController {
  protected:
    IPowerController * powerSwitch;
  public:
    IPowerHandler(IPowerController * pwrSw) {
      powerSwitch = pwrSw;
    }

    bool shuttingDown() {
      return powerSwitch->shuttingDown();
    }

    bool poweredOff() {
      return powerSwitch->poweredOff();
    }
};

class PowerSwitch: public IPowerController {
  private:
    static PowerSwitch * instance;
    static void onToggle();
    static void onWake();
    
    int powerPin;
    int pwrInt;
    bool sleepOnNextLoop;
    IPowerControlDelegate * delegate;
    
    PowerSwitch(int powerPin, IPowerControlDelegate * delegate);
    void prepareToSleep();
    void wake();    
    void toggle();    
    void sleep();
    void updateSleepState();
  public:
    PowerSwitch(PowerSwitch &other) = delete;    
    void operator=(const PowerSwitch &) = delete;  
    static PowerSwitch * configure(int powerPin, IPowerControlDelegate * delegate);
    bool shuttingDown();
    bool poweredOff();
};

#endif