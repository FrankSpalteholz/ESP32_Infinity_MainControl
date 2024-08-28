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

        if(_distInRangeCounter[sonarNum] > SONAR_STATE_COUNTER_MAX)
            _distInRangeCounter[sonarNum]=1;
        else 
            _distInRangeCounter[sonarNum]++;

        _distOffRangeCounter[sonarNum] = 0;
        
    }
    else
    {
        _currDistances[sonarNum] = _lastDistances[sonarNum];

        if(_distOffRangeCounter[sonarNum] > SONAR_STATE_COUNTER_MAX)
            _distOffRangeCounter[sonarNum]=1;
        else 
            _distOffRangeCounter[sonarNum]++;

        _distInRangeCounter[sonarNum] = 0;
    }
    
    _sonarRawData[sonarNum] = _currDistances[sonarNum];

    if(isAverage)
        averageRawData(sonarNum);

}

void CSonars::setDistRangeState(uint8_t sonarNum)
{
    if(_distInRangeCounter[sonarNum] == 0 && _distOffRangeCounter[sonarNum] > SONAR_STATE_CHANGE_THRESH)
    {
        _isDistInRange[sonarNum] = 0;
    }
     if(_distInRangeCounter[sonarNum] > 0 && _distOffRangeCounter[sonarNum] < SONAR_STATE_CHANGE_THRESH)
    {
        _isDistInRange[sonarNum] = 1;
    }
};

void CSonars::averageRawData(uint8_t sonarNum)
{
    _sonarAvrData[sonarNum] = _sonarAvrs[sonarNum].reading(_sonarRawData[sonarNum]);
}
