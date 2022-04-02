#ifndef MEASURE_H
#define MEASURE_H
#include <ArduinoLog.h>
#include <frt.h>
#include <dhtnew.h>
#include "LCDQueue.h"
#include "constants.h"

extern frt::Queue<LCDQueueData, 1> LCDQueue;
extern volatile bool isAwake;

class MeasureTask final : public frt::Task<MeasureTask> {
  public:
    MeasureTask();
    bool run();

  private:
    DHTNEW dht_sensor;
    float temperature = 0;
    float humidity = 0;
};

#endif
