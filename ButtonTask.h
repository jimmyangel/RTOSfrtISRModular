#ifndef BUTTONTASK_H
#define BUTTONTASK_H
#include <ArduinoLog.h>
#include <frt.h>
#include "constants.h"
#include "isrs.h"

extern frt::Semaphore button_semaphore;
extern frt::Semaphore wakeup_semaphore;
extern volatile bool isAwake;

class ButtonTask final : public frt::Task<ButtonTask> {
  public:
    bool run();

  private:
    const int buzzerOnTone = 400;
    const int buzzerOffTone = 800;
    const int buzzerDuration = 50;
};

#endif
