#include "BlinkTask.h"

bool BlinkTask::run() {
  if (isAwake) {
    Log.traceln("Blink");
    builtInLed.on();
    msleep(onPeriod);
    builtInLed.off();
    msleep(offPeriod);
  } else {
    builtInLed.off();
    Log.traceln("Go to sleep");
    wakeup_semaphore.wait(); // When the awake toggle is off, go to sleep
  }
  yield();
  return true;
}
