#ifndef CLAPTASK_H
#define CLAPTASK_H
#include <ArduinoLog.h>
#include <frt.h>
#include "Led.h"
#include "constants.h"

extern frt::Semaphore clap_semaphore;
extern frt::Semaphore servo_semaphore;
extern volatile bool isInductionLedsOn;

class ClapTask final : public frt::Task<ClapTask> {
  public:
    bool run();

  private:
    Led inductionLeds = Led(INDUCTION_LEDS_PIN);
};

#endif
