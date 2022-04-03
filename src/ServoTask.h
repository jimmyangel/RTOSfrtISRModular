#ifndef SERVOTASK_H
#define SERVOTASK_H
#include <ArduinoLog.h>
#include <frt.h>
#include <Adafruit_SoftServo.h>
#include "constants.h"
#include "isrs.h"

extern Adafruit_SoftServo servo;
extern frt::Semaphore servo_semaphore;
extern volatile bool isAwake;
extern volatile bool isInductionLedsOn;

class ServoTask final : public frt::Task<ServoTask> {
  public:
    ServoTask();
    bool run();
  private:
};

#endif
