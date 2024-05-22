#include <Arduino.h>
#include <elapsedMillis.h>
#include "Globals.h"
#include "NewPing.h"
#include <movingAvg.h>

class CSonar
{
    private:   

        uint8_t _id;
        uint8_t _trigPin;
        uint8_t _echoPin;
        
        long _lastDistances[SONAR_NUM];
        long _currDistances[SONAR_NUM];

        movingAvg _sonarAvrs[2] = {movingAvg(DATA_AVERAGE_COUNT), movingAvg(DATA_AVERAGE_COUNT)};
        int _sonarRawData[SONAR_NUM];
        int _sonarAvrData[SONAR_NUM];

        NewPing _CSonar[SONAR_NUM] = {
            NewPing(SONAR_1_TRIG_PIN, SONAR_1_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_2_TRIG_PIN, SONAR_2_ECHO_PIN, SONAR_DIST_MAX)};
  
        elapsedMillis _triggerSetHighTimer;
        const uint16_t _triggerSetHighTimerDelay = SENSOR_READ_INTERVAL;

        void averageRawData(uint8_t sonarNum);
    
    public:

        CSonar();
        ~CSonar();

        void readDistance(uint8_t sonarNum, bool isAverage);
        int getRawDistance(u_int8_t sonarNum){return _sonarRawData[sonarNum];};
        int getAvrDistance(u_int8_t sonarNum){return _sonarAvrData[sonarNum];};

};

