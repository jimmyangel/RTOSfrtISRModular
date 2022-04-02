#include "MeasureTask.h"

MeasureTask::MeasureTask() : dht_sensor( DHT_SENSOR_PIN ) {}

bool MeasureTask::run() {
  unsigned long timeStamp;
  int returnCode;
  msleep(4000); // Wait a bit
  if (isAwake) {
    Log.traceln("Measure %d", DHT_SENSOR_PIN);

    dht_sensor.setWaitForReading(true);
    timeStamp = millis();
    returnCode = dht_sensor.read();

    if (returnCode == DHTLIB_OK) {
      float t, h;
      t = dht_sensor.getTemperature()*9/5+32;
      h = dht_sensor.getHumidity();
      Log.traceln("Temperature %F deg. F, Humidity %F percent", t, h);
      Log.traceln("Latency %d ms", millis() - timeStamp);
      LCDQueue.push({t, h});
    } else {
      Log.traceln("DHT read error %d ", returnCode);
      dht_sensor.reset();
    }
  }

  return true;
}
