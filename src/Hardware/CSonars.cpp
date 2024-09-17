#include "Hardware/CSonars.h"

CSonars::CSonars()
{
    for (uint8_t i = 0; i < SONAR_NUM; i++)
    {
        _sonarAvrs[i].begin();
    }
}

CSonars::~CSonars()
{}

void CSonars::readDistance(uint8_t sonarNum, bool isAverage)
{  
    long tmpDistance;

    _lastDistances[sonarNum] = _currDistances[sonarNum];

    tmpDistance = _CSonar[sonarNum].ping_cm();

    if(tmpDistance > SONAR_DIST_MIN && tmpDistance < SONAR_DIST_MAX)
    {
        _currDistances[sonarNum] = tmpDistance;

        if(_distInRangeCounterTmp[sonarNum] > SONAR_RANGE_COUNTER_MAX)
            _distInRangeCounterTmp[sonarNum]=1;
        else 
            _distInRangeCounterTmp[sonarNum]++;

        _distOffRangeCounterTmp[sonarNum] = 0;
        
    }
    else
    {
        _currDistances[sonarNum] = _lastDistances[sonarNum];

        if(_distOffRangeCounterTmp[sonarNum] > SONAR_RANGE_COUNTER_MAX)
            _distOffRangeCounterTmp[sonarNum]=1;
        else 
            _distOffRangeCounterTmp[sonarNum]++;

        _distInRangeCounterTmp[sonarNum] = 0;
    }
    
    _distRawData[sonarNum] = _currDistances[sonarNum];

    if(isAverage)
        averageRawData(sonarNum);

}

void CSonars::setDistRangeState(uint8_t sonarNum)
{
    if(_distInRangeCounterTmp[sonarNum] == 0 && _distOffRangeCounterTmp[sonarNum] > SONAR_STATE_CHANGE_THRESH)
    {
        _isDistInRange[sonarNum] = 0;
    }

    if(_distInRangeCounterTmp[sonarNum] > 0 && _distOffRangeCounterTmp[sonarNum] < SONAR_STATE_CHANGE_THRESH)
    {
        _isDistInRange[sonarNum] = 1;
    }

    setDistRangeCounters(sonarNum);

};

void CSonars::averageRawData(uint8_t sonarNum)
{
    _currDistAvrgData[sonarNum] = _sonarAvrs[sonarNum].reading(_distRawData[sonarNum]);
    _lastDistAvrgData[sonarNum] = _currDistAvrgData[sonarNum];
}

void CSonars::setDistRangeCounters(uint8_t sonarNum)
{
    if(_isDistInRange[sonarNum] == 0 && _distOffRangeCounterTmp[sonarNum] < SONAR_RANGE_COUNTER_MAX)
        _distOffRangeCounter[sonarNum]++;
    
    if(_isDistInRange[sonarNum] == 0 && _distOffRangeCounterTmp[sonarNum] >= SONAR_RANGE_COUNTER_MAX)
        _distOffRangeCounter[sonarNum]=1;

    if(_isDistInRange[sonarNum] == 1 && _distInRangeCounterTmp[sonarNum] < SONAR_RANGE_COUNTER_MAX)
        _distInRangeCounter[sonarNum]++;
    
    if(_isDistInRange[sonarNum] == 1 && _distInRangeCounterTmp[sonarNum] >= SONAR_RANGE_COUNTER_MAX)
        _distInRangeCounter[sonarNum]=1;
    
}

void CSonars::calcDistVelocity(uint8_t sonarNum)
{
    _distVel[sonarNum] =  _currDistAvrgData[sonarNum] - _lastDistAvrgData[sonarNum];
}

void CSonars::setPairIDs(uint8_t pairId, uint8_t sonarIds[2])
{
    _pairIDs[pairId][0] = sonarIds[0];
    _pairIDs[pairId][1] = sonarIds[1];

}

void CSonars::setDistLengthBtwSonars(uint8_t lengthID, uint8_t sonarIDs[2])
{
    _distLengthBtwSonars[lengthID] = _currDistAvrgData[sonarIDs[0]] + _currDistAvrgData[sonarIDs[1]];
}

