#include <Arduino.h>
#include <elapsedMillis.h>

#include "Hardware/CDisplay.h"
#include "Hardware/CSonars.h"
#include "FastLED.h"
#include "Hardware/CLedQuadStrip.h"


CDisplay debugDisplay = CDisplay();
CSonars sonarSensors = CSonars();

CLedQuadStrip ledStrips = CLedQuadStrip();

elapsedMillis displayUpdateTimer;
const uint16_t displayUpdateTimerDelay = SCREEN_UPDATE_INTERVAL;

elapsedMillis sonarSensorUpdateTimer;
const uint16_t sonarSensorUpdateTimerDelay = SONAR_READ_INTERVAL;

elapsedMillis ledStripUpdateTimer;
const uint16_t ledStripUpdateTimerDelay = 10;

elapsedMillis brightnessUpdateTimer;
const uint16_t brightnessUpdateTimerDelay = 10;

bool isOLED = 1;
bool isSonars = 1;
bool isLEDStrips = 1;

int sonarDistData[SONAR_NUM];
int sonarDistStateData[SONAR_NUM];

int sonarInRangeCounterData[SONAR_NUM];
int sonarOffRangeCounterData[SONAR_NUM];

int sonarVelData[SONAR_NUM];
int sonarDistLengthData[2];

uint8_t sonarPairA[2] = {0,1};
uint8_t sonarPairB[2] = {2,3};

const char* labels[5] = {"[Dist]", "[State]", "[In]", "[Vel]", "[Len]"};


//#####################################################################################


void updateDebugDisplay();
void processSonars();


//#####################################################################################
//#####################################################################################



uint8_t brightness = 0;

void setup()
{
    Serial.begin(9600);

    if(isOLED) debugDisplay.initDisplay();
    if(isLEDStrips) ledStrips.initLEDStrips();

    sonarSensors.setPairIDs(0, sonarPairA);
    sonarSensors.setPairIDs(1, sonarPairB);

    //FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, 104);
    //FastLED.setBrightness(50);

}

//#####################################################################################




void loop()
{   
    
    if(isOLED)
    {
        updateDebugDisplay();
    }

    if(isSonars)
    {
        processSonars();
    }

    // if(isLEDStrips)
    // {
    //     if(ledStripUpdateTimer > ledStripUpdateTimerDelay)
    //     {
    //         ledStrips.fadeBrightness(LED_STRIP_COUNT_C, 255, 0);
    //         ledStripUpdateTimer = 0;
    //     }
    // } 

    // if(brightnessUpdateTimer > brightnessUpdateTimerDelay)
    // {   

    //     if(brightness >= 220)
    //         brightness=0;
    //     else
    //         brightness++;
    //     brightnessUpdateTimer = 0;
    // }

    if(ledStripUpdateTimer > ledStripUpdateTimerDelay)
    {
        
        uint8_t brightness = map(sonarDistData[1], 29, 6, 60, 255);
        
       // ledStrips.fadeBrightness(ledStrips.ledQuadBottom, LED_STRIP_COUNT_C, brightness);

        // ledStrips.fadeBrightness(ledStrips.ledQuadsTopA[0], LED_STRIP_COUNT_A_B, brightness);
        //  ledStrips.fadeBrightness(ledStrips.ledQuadsTopA[1], LED_STRIP_COUNT_A_B, brightness);
        //  ledStrips.fadeBrightness(ledStrips.ledQuadsTopA[2], LED_STRIP_COUNT_A_B, brightness);
        //  ledStrips.fadeBrightness(ledStrips.ledQuadsTopA[3], LED_STRIP_COUNT_A_B, brightness);

        // ledStrips.fadeBrightness(ledStrips.ledQuadsTopB[0], LED_STRIP_COUNT_A_B, brightness);
        // ledStrips.fadeBrightness(ledStrips.ledQuadsTopB[1], LED_STRIP_COUNT_A_B, brightness);
         ledStrips.fadeBrightness(ledStrips.ledQuadsTopB[2], LED_STRIP_COUNT_A_B, brightness);
        // ledStrips.fadeBrightness(ledStrips.ledQuadsTopB[3], LED_STRIP_COUNT_A_B, brightness);


        ledStrips.noiseAnim(ledStrips.ledQuadBottom, ledStrips.stripCData, LED_STRIP_COUNT_C);
        
        ledStripUpdateTimer = 0;
    }


}


//#####################################################################################
//#####################################################################################


void updateDebugDisplay()
{
    if(displayUpdateTimer > displayUpdateTimerDelay)
    {   
        debugDisplay.clearScreen();

        debugDisplay.setCursorPos(0, 2);   
        debugDisplay.outputToDisplay(50, 20, labels[0], sonarDistData, 4);
        debugDisplay.setCursorPos(0, 15);   
        debugDisplay.outputToDisplay(50, 20, labels[1], sonarDistStateData, 4);
        debugDisplay.setCursorPos(0, 28);   
        debugDisplay.outputToDisplay(50, 20, labels[2], sonarInRangeCounterData, 4);
        debugDisplay.setCursorPos(0, 41);   
        debugDisplay.outputToDisplay(50, 20, labels[3], sonarVelData, 4);
        debugDisplay.setCursorPos(0, 54);   
        debugDisplay.outputToDisplay(50, 40, labels[4], sonarDistLengthData, 2);
       
        debugDisplay.writeToScreen();

        displayUpdateTimer = 0;
    }

}

//#####################################################################################

void processSonars()
{
    if(sonarSensorUpdateTimer > sonarSensorUpdateTimerDelay)
    {

        for (uint8_t i = 0; i < SONAR_NUM; i++)
        {
            sonarSensors.readDistance(i, true);
            sonarDistData[i] = sonarSensors.getAvrDistance(i);
            
            sonarSensors.setDistRangeState(i);
            sonarDistStateData[i] = sonarSensors.getDistIsInRange(i);
            
            sonarInRangeCounterData[i] = sonarSensors.getDistInRangeCounter(i);

            sonarSensors.calcDistVelocity(i);
            sonarVelData[i] = sonarSensors.getDistVel(i);
 
            //Serial.println(sonarDistData[i]);
        }
        
        sonarSensors.setDistLengthBtwSonars(0, sonarPairA);
        sonarSensors.setDistLengthBtwSonars(1, sonarPairB);

        sonarDistLengthData[0] = sonarSensors.getDistLengthBtwSonars(0);
        sonarDistLengthData[1] = sonarSensors.getDistLengthBtwSonars(1);
    
        sonarSensorUpdateTimer = 0;
    }

};

//#####################################################################################
