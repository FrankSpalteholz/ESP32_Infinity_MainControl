// #include "CLed_Quad.h"

// CLed_Quad::CLed_Quad() {}

// CLed_Quad::~CLed_Quad() {}

// void CLed_Quad::initLEDStrips()
// {

//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A1, COLOR_ORDER>(leds_A[0], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A2, COLOR_ORDER>(leds_A[1], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A3, COLOR_ORDER>(leds_A[2], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A4, COLOR_ORDER>(leds_A[3], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   

//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B1, COLOR_ORDER>(leds_B[0], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B2, COLOR_ORDER>(leds_B[1], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B3, COLOR_ORDER>(leds_B[2], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     // FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B4, COLOR_ORDER>(leds_B[3], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   

//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A1, COLOR_ORDER>(ledQuads[0][0], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A2, COLOR_ORDER>(ledQuads[0][1], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A3, COLOR_ORDER>(ledQuads[0][2], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A4, COLOR_ORDER>(ledQuads[0][3], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   

//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B1, COLOR_ORDER>(ledQuads[1][0], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B2, COLOR_ORDER>(ledQuads[1][1], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B3, COLOR_ORDER>(ledQuads[1][2], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   
//     FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B4, COLOR_ORDER>(ledQuads[1][3], LEDS_PER_STRIP_COUNT).setCorrection( TypicalLEDStrip );   


//     ledStripData[0][0].currentBlending = NOBLEND;
//     ledStripData[0][1].currentBlending = NOBLEND;
//     ledStripData[0][2].currentBlending = NOBLEND;
//     ledStripData[0][3].currentBlending = NOBLEND;

//     ledStripData[1][0].currentBlending = NOBLEND;
//     ledStripData[1][1].currentBlending = NOBLEND;
//     ledStripData[1][2].currentBlending = NOBLEND;
//     ledStripData[1][3].currentBlending = NOBLEND;


//     FastLED.setBrightness(BRIGHTNESS);
//     //SetupBlackAndWhiteStripedPalette(); 
//     //currentBlending = LINEARBLEND;

// }

// void CLed_Quad::writeLedStripQuadColors(uint8_t quadNum)
// {}

// void CLed_Quad::writeLedStripsColors(uint8_t quadNum, uint8_t stripNum)
// {

//     int dotPos_prev = ledStripData[quadNum][stripNum].dotPos;
    
//     // TODO state 0 -> no move
//     switch (ledStripData[quadNum][stripNum].dotDir)
//     {
//         case -1:
        
//             if(ledStripData[quadNum][stripNum].dotPos >= LED_STRIP_LOWERBOUND)
//             {
//                 ledStripData[quadNum][stripNum].dotPos--;
                
//                 if(ledStripData[quadNum][stripNum].dotPos < LED_STRIP_LOWERBOUND)
//                 {
//                     ledStripData[quadNum][stripNum].dotPos = LED_STRIP_UPPERBOUND-1;
//                 }

//             }
            
//            //Serial.println(val);

//             ledQuads[quadNum][stripNum][ledStripData[quadNum][stripNum].dotPos] = CHSV(   ledStripData[quadNum][stripNum].hsvVals[0],
//                                                                 ledStripData[quadNum][stripNum].hsvVals[1],
//                                                                 ledStripData[quadNum][stripNum].hsvVals[2]);
//             ledQuads[quadNum][stripNum][dotPos_prev] = CHSV( ledStripData[quadNum][ stripNum].hsvVals[0],
//                                                 ledStripData[quadNum][stripNum].hsvVals[1],
//                                                 0);
            
//             break;
        
//         case 1:

//             if(ledStripData[quadNum][stripNum].dotPos <= LED_STRIP_UPPERBOUND-1)
//             {
//                 ledStripData[quadNum][stripNum].dotPos++;
                
//                 if(ledStripData[quadNum][stripNum].dotPos > LED_STRIP_UPPERBOUND-1)
//                 {
//                     ledStripData[quadNum][stripNum].dotPos = LED_STRIP_LOWERBOUND; 
//                 }
//             }

//             //Serial.println(val);

//             ledQuads[quadNum][stripNum][ledStripData[quadNum][stripNum].dotPos] = CHSV( ledStripData[quadNum][stripNum].hsvVals[0],
//                                                                                         ledStripData[quadNum][stripNum].hsvVals[1],
//                                                                                         ledStripData[quadNum][stripNum].hsvVals[2]);
            
//             ledQuads[quadNum][stripNum][dotPos_prev] = CHSV(ledStripData[quadNum][ stripNum].hsvVals[0],
//                                                             ledStripData[quadNum][stripNum].hsvVals[1],
//                                                             0);

//             break;   
//     }

//     // ledQuads[quadNum][stripNum][ledStripData[quadNum][stripNum].dotPos] = CHSV(   ledStripData[quadNum][stripNum].hsvVals[0],
//     //                                                             ledStripData[quadNum][stripNum].hsvVals[1],
//     //                                                             ledStripData[quadNum][stripNum].hsvVals[2]);
            
//     // ledQuads[quadNum][stripNum][dotPos_prev] = CHSV( ledStripData[quadNum][ stripNum].hsvVals[0],
//     //                                             ledStripData[quadNum][stripNum].hsvVals[1],
//     //                                             0);
// }

// void CLed_Quad::showStripsColors()
// {
//     // EVERY_N_MILLISECONDS(80)
//     // {   
//         // for (int i = 0; i < NUM_LEDS; i++)
//         // {
//         //     leds[0][i] = CRGB::White;
//         //     leds[1][i] = CRGB::White;
//         // }
        
        
//         writeLedStripsColors(0,0);
//         //writeLedStripsColors(0,1);
//         //writeLedStripsColors(0,2);
//         //writeLedStripsColors(0,3);

//         writeLedStripsColors(1,0);
//         //writeLedStripsColors(1,1);
//         //writeLedStripsColors(1,2);
//         //writeLedStripsColors(1,3);
        
//       //  FastLED.show();
//    // }
    
// }



