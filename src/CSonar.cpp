#include <CSonar.h>

CSonar::CSonar()
{
    for (uint8_t i = 0; i < SONAR_NUM; i++)
        _sonarAvrs[i].begin();
}

CSonar::~CSonar()
{}

void CSonar::readDistance(uint8_t sonarNum, bool isAverage)
{  
    long tmpDistance;

    _lastDistances[sonarNum] = _currDistances[sonarNum];

    if(_triggerSetHighTimer > _triggerSetHighTimerDelay)
    {   
        tmpDistance = _CSonar[sonarNum].ping_cm();

        if(tmpDistance > SONAR_DIST_MIN && tmpDistance < SONAR_DIST_MAX)
            _currDistances[sonarNum] = tmpDistance;
        else
            _currDistances[sonarNum] = _lastDistances[sonarNum] ;
    }

     _sonarRawData[sonarNum] = _currDistances[sonarNum];

     if(isAverage)
        averageRawData(sonarNum);
}

void CSonar::averageRawData(uint8_t sonarNum)
{
    _sonarAvrData[sonarNum] = _sonarAvrs[sonarNum].reading(_sonarRawData[sonarNum]);
}
