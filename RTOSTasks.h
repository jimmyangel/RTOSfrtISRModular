#ifndef RTOSTASKS_H
#define RTOSTASKS_H
#include <frt.h>
//#include <Adafruit_SoftServo.h>
#include "BlinkTask.h"
#include "ButtonTask.h"
#include "MeasureTask.h"
#include "DisplayLCDTask.h"
#include "ServoTask.h"
#include "ClapTask.h"

// Intertask communication
frt::Semaphore button_semaphore;
frt::Semaphore wakeup_semaphore;
frt::Semaphore clap_semaphore;
frt::Semaphore servo_semaphore;
frt::Queue<LCDQueueData, 1> LCDQueue;

// Globals
volatile bool isAwake = false;
volatile bool isInductionLedsOn = false;
Adafruit_SoftServo servo;

// Tasks
BlinkTask blinkTask;
ButtonTask buttonTask;
MeasureTask measureTask;
DisplayLCDTask displayLCDTask;
ClapTask clapTask;
ServoTask servoTask;

#endif
