#ifndef BLINKTASK_H
#define BLINKTASK_H
#include <ArduinoLog.h>
#include <frt.h>
#include "Led.h"

extern frt::Semaphore wakeup_semaphore;
extern volatile bool isAwake;

class BlinkTask final : public frt::Task<BlinkTask> {
  public:
    bool run();

  private:
    const int onPeriod = 200;
    const int offPeriod = 500;
    Led builtInLed = Led(LED_BUILTIN);
};

#endif
