#include <Arduino.h>
#include <movingAvg.h>
#include <NewPing.h>

#include "Globals.h"

class CSonars
{
    private:   

        u_int8_t _lastDistances[SONAR_NUM];
        u_int8_t _currDistances[SONAR_NUM];

        bool _isDistInRange[SONAR_NUM];

        u_int8_t _distInRangeCounter[SONAR_NUM];
        u_int8_t _distOffRangeCounter[SONAR_NUM];

        

        movingAvg _sonarAvrs[SONAR_NUM] = { movingAvg(SONAR_DIST_AVERAGE_COUNT), 
                                            movingAvg(SONAR_DIST_AVERAGE_COUNT),
                                            movingAvg(SONAR_DIST_AVERAGE_COUNT),
                                            movingAvg(SONAR_DIST_AVERAGE_COUNT)};

        u_int8_t _sonarRawData[SONAR_NUM];
        u_int8_t _sonarAvrData[SONAR_NUM];

        NewPing _CSonar[SONAR_NUM] = {
            NewPing(SONAR_1_TRIG_PIN, SONAR_1_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_2_TRIG_PIN, SONAR_2_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_3_TRIG_PIN, SONAR_3_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_4_TRIG_PIN, SONAR_4_ECHO_PIN, SONAR_DIST_MAX)
        };
  
        void averageRawData(uint8_t sonarNum);
        
    
    public:

        CSonars();
        ~CSonars();

        void readDistance(uint8_t sonarNum, bool isAverage);
        bool getDistIsInRange(uint8_t sonarNum){return _isDistInRange[sonarNum];};
        u_int8_t getDistOffRangeCounter(uint8_t sonarNum){return _distOffRangeCounter[sonarNum];};
        u_int8_t getDistInRangeCounter(uint8_t sonarNum){return _distInRangeCounter[sonarNum];};
        u_int8_t getRawDistance(u_int8_t sonarNum){return _sonarRawData[sonarNum];};
        u_int8_t getAvrDistance(u_int8_t sonarNum){return _sonarAvrData[sonarNum];};

        void setDistRangeState(uint8_t sonarNum);

};

