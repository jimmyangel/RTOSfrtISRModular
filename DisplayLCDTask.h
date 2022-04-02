#ifndef DISPLAYLCDTASK_H
#define DISPLAYLCDTASK_H
#include <ArduinoLog.h>
#include <frt.h>
#include <LiquidCrystal.h>
#include "LCDQueue.h"
#include "constants.h"

extern frt::Queue<LCDQueueData, 1> LCDQueue;
extern volatile bool isAwake;

class DisplayLCDTask final : public frt::Task<DisplayLCDTask> {
  public:
    DisplayLCDTask();
    bool run();
    void turnLCDOff();
    void turnLCDOn();

  private:
    LiquidCrystal lcd;
};


#endif
