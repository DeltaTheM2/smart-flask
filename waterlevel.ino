// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_VL53L0X.h>
#define VL53L0X_LOG_ENABLED 0

uint32_t _trace_level = TRACE_LEVEL_ALL;

#if defined(PARTICLE) && (SYSTEM_VERSION >= 0X00060000)
SerialLogHandler logHandler(LOG_LEVEL_ALL);
#endif

Adafruit_VL53L0X lox = Adafruit_VL53L0X();


void setup() {
 Serial1.begin(115200);
 
 while(!Serial1)
 {
     delay(1);
 }
 
 Serial1.println("Testing the ToF sensor!!");
 if(!lox.begin())
 {
     Serial1.println("failed to initiate the Tof Sensor!");
     while(1);
 }
 
}

void loop() {

    VL53L0X_RangingMeasurementData_t measure;
    Serial1.print("Reading a measurement...");
    lox.rangingTest(&measure, true);
    
    if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial1.print("Distance (mm): "); Serial1.println(measure.RangeMilliMeter);
  } else {
    Serial1.println(" out of range ");
  }

  delay(1000);

}