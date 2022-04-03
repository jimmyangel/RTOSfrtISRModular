#include "ClapTask.h"

bool ClapTask::run() {
  clap_semaphore.wait();
  Log.traceln("Sound detected");
  msleep(400); // Debounce
  clap_semaphore.wait(0); // Clear possible outstanding semaphore posts

  if (isInductionLedsOn) {
    isInductionLedsOn = false;
    inductionLeds.off();
  } else {
    isInductionLedsOn = true;
    inductionLeds.on();
  }

  servo_semaphore.post();
  return true;
}
