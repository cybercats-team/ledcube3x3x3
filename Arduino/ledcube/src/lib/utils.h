#ifndef UTILS
#define UTILS

#include <Arduino.h>

class Utils {
  public:
    static int logicalLevel(bool flag) {
      return flag ? HIGH : LOW;
    }
  private:
    Utils() {}
};

#endif
