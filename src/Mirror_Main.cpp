// #include <Arduino.h>
// #include <elapsedMillis.h>

// #include "Hardware/CDisplay.h"
// #include "Hardware/CSonars.h"

// CDisplay debugDisplay = CDisplay();
// CSonars sonarSensors = CSonars();

// elapsedMillis displayUpdateTimer;
// const uint16_t displayUpdateTimerDelay = SCREEN_UPDATE_INTERVAL;

// elapsedMillis sonarSensorUpdateTimer;
// const uint16_t sonarSensorUpdateTimerDelay = SONAR_READ_INTERVAL;

// bool isOLED = 1;
// bool isSonars = 1;

// int sonarDistData[SONAR_NUM];
// int sonarDistStateData[SONAR_NUM];
// int sonarInRangeCounterData[SONAR_NUM];
// int sonarOffRangeCounterData[SONAR_NUM];

// const char* labels[4] = {"[Dist]", "[State]","[In]","[Out]"};

// void updateDebugDisplay();

// //#####################################################################################
// //#####################################################################################

// void setup()
// {
//     Serial.begin(9600);

//     if(isOLED) 
//         debugDisplay.initDisplay();
// }

// //#####################################################################################
// //#####################################################################################


// void loop()
// {   
//     if(sonarSensorUpdateTimer > sonarSensorUpdateTimerDelay)
//     {

//         for (uint8_t i = 0; i < SONAR_NUM; i++)
//         {
//             sonarSensors.readDistance(i, true);
//             sonarDistData[i] = sonarSensors.getAvrDistance(i);
//             sonarSensors.setDistRangeState(i);
//             sonarDistStateData[i] = sonarSensors.getDistIsInRange(i);
//             sonarInRangeCounterData[i] = sonarSensors.getDistInRangeCounter(i);

//         }

//         sonarSensorUpdateTimer = 0;
//     }

//     if(isOLED)
//         updateDebugDisplay();

    
// }

// //#####################################################################################
// //#####################################################################################


// void updateDebugDisplay()
// {
//     if(displayUpdateTimer > displayUpdateTimerDelay)
//     {
//         debugDisplay.clearScreen();

//         debugDisplay.setCursorPos(0, 2);   
//         debugDisplay.outputToDisplay(50, 20, labels[0], sonarDistData, 4);
//         debugDisplay.setCursorPos(0, 15);   
//         debugDisplay.outputToDisplay(50, 20, labels[1], sonarDistStateData, 4);
//         debugDisplay.setCursorPos(0, 28);   
//         debugDisplay.outputToDisplay(50, 20, labels[2], sonarInRangeCounterData, 4);
       
//         debugDisplay.writeToScreen();

//         displayUpdateTimer = 0;
//     }

// }