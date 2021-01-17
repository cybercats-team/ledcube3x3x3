#ifndef POWER_SWITCH
#define POWER_SWITCH

#include <Arduino.h>
#include <avr/sleep.h>

#include "../device_controls.h"

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
  public:
    PowerSwitch(PowerSwitch &other) = delete;    
    void operator=(const PowerSwitch &) = delete;  
    static PowerSwitch * configure(int powerPin, IPowerControlDelegate * delegate);
    bool shuttingDown();
    bool poweredOff();
};

#endif