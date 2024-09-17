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

        u_int8_t _distInRangeCounterTmp[SONAR_NUM];
        u_int8_t _distOffRangeCounterTmp[SONAR_NUM];

        u_int8_t _distInRangeCounter[SONAR_NUM];
        u_int8_t _distOffRangeCounter[SONAR_NUM];

        u_int8_t _distRawData[SONAR_NUM];
        u_int8_t _currDistAvrgData[SONAR_NUM];
        u_int8_t _lastDistAvrgData[SONAR_NUM];

        int _distVel[SONAR_NUM];

        uint8_t _distLengthBtwSonars[2];
        uint8_t _pairIDs[2][2];

        movingAvg _sonarAvrs[SONAR_NUM] = { 
            movingAvg(SONAR_DIST_AVERAGE_COUNT), 
            movingAvg(SONAR_DIST_AVERAGE_COUNT),
            movingAvg(SONAR_DIST_AVERAGE_COUNT),
            movingAvg(SONAR_DIST_AVERAGE_COUNT)
        };

        NewPing _CSonar[SONAR_NUM] = {
            NewPing(SONAR_1_TRIG_PIN, SONAR_1_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_2_TRIG_PIN, SONAR_2_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_3_TRIG_PIN, SONAR_3_ECHO_PIN, SONAR_DIST_MAX),
            NewPing(SONAR_4_TRIG_PIN, SONAR_4_ECHO_PIN, SONAR_DIST_MAX)
        };

        void averageRawData(uint8_t sonarNum); 
        void setDistRangeCounters(uint8_t sonarNum);

        u_int8_t getDistOffRangeCounterTmp(uint8_t sonarNum){return _distOffRangeCounterTmp[sonarNum];};
        u_int8_t getDistInRangeCounterTmp(uint8_t sonarNum){return _distInRangeCounterTmp[sonarNum];};
        
    public:

        CSonars();
        ~CSonars();

        void readDistance(uint8_t sonarNum, bool isAverage);
        
        bool getDistIsInRange(uint8_t sonarNum){return _isDistInRange[sonarNum];};
        void setDistRangeState(uint8_t sonarNum);
        
        void calcDistVelocity(uint8_t sonarNum);

        u_int8_t getDistOffRangeCounter(uint8_t sonarNum){return _distOffRangeCounter[sonarNum];};
        u_int8_t getDistInRangeCounter(uint8_t sonarNum){return _distInRangeCounter[sonarNum];};
        
        int getDistVel(uint8_t sonarNum){return _distVel[sonarNum];};

        u_int8_t getRawDistance(u_int8_t sonarNum){return _distRawData[sonarNum];};
        u_int8_t getAvrDistance(u_int8_t sonarNum){return _currDistAvrgData[sonarNum];};

        void setPairIDs(uint8_t pairId, uint8_t sonarIds[2]);
        void setDistLengthBtwSonars(uint8_t lengthID, uint8_t sonarIDs[2]);
        uint8_t getDistLengthBtwSonars(uint8_t lengthID){return _distLengthBtwSonars[lengthID];};

};

