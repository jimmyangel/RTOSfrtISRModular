#ifndef RSRS_H
#define RSRS_H
#include <frt.h>
#include <Adafruit_SoftServo.h>
#include "constants.h"

extern volatile bool isAwake;
extern frt::Semaphore button_semaphore;
extern frt::Semaphore clap_semaphore;
extern Adafruit_SoftServo servo;

// Interrupts
namespace isrs {
  void buttonISR();
  void soundSensorISR();
  void enableButtonISR();
  void enableSoundSensorISR();
  void disableSoundSensorISR();
}

// Timer interrupt, used to refresh servo every 20ms

ISR(TIMER0_COMPA_vect);

#endif
