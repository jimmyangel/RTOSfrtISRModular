#include "ServoTask.h"

ServoTask::ServoTask() {
}

bool ServoTask::run() {
  int valueDegrees = 0;
  servo_semaphore.wait();
  isrs::disableSoundSensorISR(); // We don't want the servo to start sound interrupt
  if (isAwake) {
    Log.traceln("Move the servo");
    if (isInductionLedsOn) {
      servo.write(180);
    } else {
      servo.write(0);
    }
  }
  msleep(1000);
  isrs::enableSoundSensorISR();
  return true;
}
