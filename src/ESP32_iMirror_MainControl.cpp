// #include <Arduino.h>
// #include <elapsedMillis.h>

// #include "Globals.h"
// #include "CSonar.h"
// #include "CLcd.h"
// #include "CLed.h"

// CLcd lcd = CLcd();
// CLed ledStrips = CLed();
// CSonar sonars = CSonar();

// elapsedMillis lcdUpdateTimer;
// const uint16_t lcdUpdateTimerDelay = 100;

// void processSonars(bool isDoAverage);
// void updateLEDData(uint8_t stripNum);
// void writeLCDDebugData(uint8_t actor);


// bool isLCD = 1;
// bool isSonar = 1;
// bool isLED = 1;

// //int lcdProcessData[4] = {20,20,1,100};

// struct ledData
// {
//     int8_t handDistToSonar[2] = {0,0}; // 0 = right hand 1 = left hand
//     uint8_t distBtwHands = 0;

//     uint8_t brightness = 80; 
//     uint8_t colorHSV[3] = {0, 0, brightness};
//     uint8_t gradients = 8;

//     int8_t direction = 0;
//     uint8_t startPos = 0;
//     uint8_t currPos = 0;
//     uint8_t lastPos = 0;
//     uint8_t vel = 0;
// };

// ledData ledPlayer;
// ledData ledAvatar;

// int lcdDebugData[8] = {0,0,0,0,0,0,0,0};



// //##############################################################################################


// void setup() {

//     Serial.begin(9600);
    
//     if(isLCD)
//     {
//         lcd.initDisplay();
//     }
    
//     if(isLED)
//     {
//         delay(1000);
//         ledStrips.initLEDStrips();
//     }
// }


// //##############################################################################################


// void loop() {

//     if(isSonar)
//     {
//         processSonars(true);

//         // measure hand-distances to each sensor 
//         ledPlayer.handDistToSonar[0] = sonars.getAvrDistance(0); // right sensor
//         ledPlayer.handDistToSonar[1] = sonars.getAvrDistance(1)*-1; // left sensor
        
//         // calculate direction normalized  
//         ledPlayer.direction = (ledPlayer.handDistToSonar[0] + ledPlayer.handDistToSonar[1]) / abs(ledPlayer.handDistToSonar[0] + ledPlayer.handDistToSonar[1]);

//         // get distance between hands
//         ledPlayer.distBtwHands = ledPlayer.handDistToSonar[0] + abs(ledPlayer.handDistToSonar[1]);

//         // calculate dynamic brightness based on global distance between hands
//         if(ledPlayer.handDistToSonar[0] != 0 || ledPlayer.handDistToSonar[1] != 0)
//         {
//             ledPlayer.brightness = map(ledPlayer.distBtwHands,
//                                     SONAR_DIST_MIN * 2, 
//                                     SONAR_DIST_MAX * 2, 
//                                     LED_STRIP_MIN_BRIGHTNESS, 
//                                     LED_STRIP_MAX_BRIGHTNESS);
//         }
        
//     }

//     if(isLED)
//     {
//         updateLEDData(0);
//         updateLEDData(1);
//         ledStrips.showStripsColors();
//     }
    
//     if(isLCD && lcdUpdateTimer > lcdUpdateTimerDelay)
//     {
//         writeLCDDebugData(0);
//         lcd.debugOutputDisplay(40, "", lcdDebugData);
//         lcdUpdateTimer = 0;
//     }
  
// }

// //##############################################################################################

// void processSonars(bool isDoAverage)
// {
//     for (uint8_t i = 0; i < SONAR_NUM; i++)
//         sonars.readDistance(i, isDoAverage);
// }

// void updateLEDData(uint8_t stripNum)
// {

//     ledStrips.ledStrip[stripNum].dotDir = ledPlayer.direction;
//     ledStrips.ledStrip[stripNum].hsvVals[2] = ledPlayer.brightness;

// }

// void writeLCDDebugData(uint8_t actor)
// {   
//     switch (actor)
//     {
//         // 0 -> player 
//         case 0:
//             lcdDebugData[0] = ledPlayer.handDistToSonar[0]; // right hand
//             lcdDebugData[1] = ledPlayer.handDistToSonar[1]; // left hand
//             lcdDebugData[2] = ledPlayer.direction;
//             lcdDebugData[3] = ledPlayer.distBtwHands;          
//             break; 
//     }
    
// }

// // There are several different palettes of colors demonstrated here.
// //
// // FastLED provides several 'preset' palettes: RainbowColors_p, RainbowStripeColors_p,
// // OceanColors_p, CloudColors_p, LavaColors_p, ForestColors_p, and PartyColors_p.
// //
// // Additionally, you can manually define your own color palettes, or you can write
// // code that creates color palettes on the fly.  All are shown here.

// // void FillLEDsFromPaletteColors(uint8_t colorIndex, uint8_t brightness, int8_t direction)
// // {   
// //     // for( int i = 0; i < NUM_LEDS; ++i) {
        
// //     //     if(direction > 0)
// //     //     {
// //     //         ledsOutside[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
// //     //         ledsInside[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
// //     //     }
// //     //     if(direction < 0)
// //     //     {
// //     //         ledsOutside[(NUM_LEDS-1)-i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
// //     //         ledsInside[(NUM_LEDS-1)-i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
// //     //     }
// //     //     //ledsInside[(NUM_LEDS-1)-i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        
// //     //     colorIndex += 1;
// //     // }
// // }


// // void ChangePalettePeriodically()
// // {
// //     uint8_t secondHand = (millis() / 1000) % 60;
// //     static uint8_t lastSecond = 99;
    
// //     if( lastSecond != secondHand) {
// //         lastSecond = secondHand;
// //         //if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
// //         //if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
// //         //if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
// //         //if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
// //         //if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
// //         //if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
// //         //if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
// //         //if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
// //         //if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
// //         //if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
// //         //if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
// //     }
// // }

// // // This function fills the palette with totally random colors.
// // void SetupTotallyRandomPalette()
// // {
// //     for( int i = 0; i < 16; ++i) {
// //         currentPalette[i] = CHSV( random8(), 255, random8());
// //     }
// // }

// // // This function sets up a palette of black and white stripes,
// // // using code.  Since the palette is effectively an array of
// // // sixteen CRGB colors, the various fill_* functions can be used
// // // to set them up.
// // void SetupBlackAndWhiteStripedPalette()
// // {
// //     // 'black out' all 16 palette entries...
// //     fill_solid( currentPalette, 16, CRGB::Black);
// //     // and set every fourth one to white.
// //     currentPalette[0] = CRGB::White;
// //     currentPalette[4] = CRGB::White;
// //     currentPalette[8] = CRGB::White;
// //     currentPalette[12] = CRGB::White;
    
// // }

// // // This function sets up a palette of purple and green stripes.
// // void SetupPurpleAndGreenPalette()
// // {
// //     CRGB purple = CHSV( HUE_PURPLE, 255, 255);
// //     CRGB green  = CHSV( HUE_GREEN, 255, 255);
// //     CRGB black  = CRGB::Black;
    
// //     currentPalette = CRGBPalette16(
// //                                    green,  green,  black,  black,
// //                                    purple, purple, black,  black,
// //                                    green,  green,  black,  black,
// //                                    purple, purple, black,  black );
// // }


// // // This example shows how to set up a static color palette
// // // which is stored in PROGMEM (flash), which is almost always more
// // // plentiful than RAM.  A static PROGMEM palette like this
// // // takes up 64 bytes of flash.
// // const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
// // {
// //     CRGB::Red,
// //     CRGB::Gray, // 'white' is too bright compared to red and blue
// //     CRGB::Blue,
// //     CRGB::Black,
    
// //     CRGB::Red,
// //     CRGB::Gray,
// //     CRGB::Blue,
// //     CRGB::Black,
    
// //     CRGB::Red,
// //     CRGB::Red,
// //     CRGB::Gray,
// //     CRGB::Gray,
// //     CRGB::Blue,
// //     CRGB::Blue,
// //     CRGB::Black,
// //     CRGB::Black
// // };



// // // Additional notes on FastLED compact palettes:
// // //
// // // Normally, in computer graphics, the palette (or "color lookup table")
// // // has 256 entries, each containing a specific 24-bit RGB color.  You can then
// // // index into the color palette using a simple 8-bit (one byte) value.
// // // A 256-entry color palette takes up 768 bytes of RAM, which on Arduino
// // // is quite possibly "too many" bytes.
// // //
// // // FastLED does offer traditional 256-element palettes, for setups that
// // // can afford the 768-byte cost in RAM.
// // //
// // // However, FastLED also offers a compact alternative.  FastLED offers
// // // palettes that store 16 distinct entries, but can be accessed AS IF
// // // they actually have 256 entries; this is accomplished by interpolating
// // // between the 16 explicit entries to create fifteen intermediate palette
// // // entries between each pair.
// // //
// // // So for example, if you set the first two explicit entries of a compact 
// // // palette to Green (0,255,0) and Blue (0,0,255), and then retrieved 
// // // the first sixteen entries from the virtual palette (of 256), you'd get
// // // Green, followed by a smooth gradient from green-to-blue, and then Blue.
