#include <ArduinoLog.h>
#include <avr/sleep.h>
#include "src/RTOSTasks.h"
#include "src/isrs.h"
#include "src/constants.h"

void setup() {

  Serial.begin(9600);

  while (!Serial);

  Log.begin(LOG_LEVEL_TRACE, &Serial);

  Log.noticeln( "Starting");
  Log.traceln("Start trace");

  Log.noticeln("Start Display LCD Task");
  displayLCDTask.start(2);

  Log.noticeln("Start Button Task");
  buttonTask.start(10); // Higher priority; mostly waiting for interrupt

  Log.noticeln("Start Blink Task");
  blinkTask.start(2);

  Log.noticeln("Start Clap Task");
  clapTask.start(2);

  isrs::enableButtonISR();

  isrs::enableSoundSensorISR();

  Log.noticeln("Start Measure Task");
  measureTask.start(2);

  displayLCDTask.turnLCDOff();

  // Set timer 0 compare interrupt
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0B);

  servo.attach(SERVO_PIN);

  Log.noticeln("Start Servo Task");
  servoTask.start(2);

}

void loop() {

  if (!isAwake) {
    displayLCDTask.turnLCDOff();
    Serial.flush(); // Wait for Serial output to finish before going power save mode

    set_sleep_mode( SLEEP_MODE_PWR_DOWN );

    portENTER_CRITICAL();
    sleep_enable();
    #if defined(BODS) && defined(BODSE)
    sleep_bod_disable();
    #endif
    portEXIT_CRITICAL();

    sleep_cpu();

    sleep_reset();
  }
}
