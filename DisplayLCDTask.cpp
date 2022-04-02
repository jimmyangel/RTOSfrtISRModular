#include "DisplayLCDTask.h"

DisplayLCDTask::DisplayLCDTask() : lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7) {
  lcd.begin(16, 2);
}

bool DisplayLCDTask::run() {

  LCDQueueData data;

  LCDQueue.pop(data); // Get message (or wait for it)
  Log.traceln("Display LCD");
  turnLCDOn();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Awake-measuring");
  lcd.setCursor(0,1);
  lcd.print(round(data.temperature));
  lcd.print(" F  ");
  lcd.print(round(data.humidity));
  lcd.print(" %  ");

  return true;
}

void DisplayLCDTask::turnLCDOff() {
  lcd.noDisplay();
  analogWrite(LCD_A, 0);
}

void DisplayLCDTask::turnLCDOn() {
  lcd.display();
  analogWrite(LCD_A, 200);
}
