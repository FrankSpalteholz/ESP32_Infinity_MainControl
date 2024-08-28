// #include <Arduino.h>
// #include <FastLED.h>

// #include "Globals.h"

// class CLed_Quad
// {
        
//     public:

//         CLed_Quad();
//         ~CLed_Quad();

//         //CRGB leds_A[STRIPS_PER_LOOP_COUNT][LEDS_PER_STRIP_COUNT]; // A = inside
//         //CRGB leds_B[STRIPS_PER_LOOP_COUNT][LEDS_PER_STRIP_COUNT]; // B = outside
        
//         CRGB ledQuads[STRIP_QUAD_COUNT][STRIPS_PER_LOOP_COUNT][LEDS_PER_STRIP_COUNT]; // B = outside

//         //CRGB leds[2][104]; // strip num 1 = inside 2 = outside

//         struct ledStrip
//         {
//             uint8_t hsvVals[3] = {0,0,80}; // hue sat val -> low-white
//             int8_t dotDir = 0; // set to 1 for forward or -1 for backwards
//             uint8_t dotSpeed = 80; // in ms 
//             int8_t dotPos = 0;
//             int8_t dotStartPos = 0;

//             // TODO check if those members are actually global rather than locally accessible
//             CRGBPalette16 currentPalette;
//             TBlendType    currentBlending;
//         };

//         ledStrip ledStripData[STRIP_QUAD_COUNT][STRIPS_PER_LOOP_COUNT];

//         //extern CRGBPalette16 myRedWhiteBluePalette;
//         //extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

//         void initLEDStrips();
//         void showStripsColors();

//         //void SetupPurpleAndGreenPalette();
//         //void SetupBlackAndWhiteStripedPalette();
//         //void FillLEDsFromPaletteColors(uint8_t colorIndex, uint8_t brightness, int8_t direction);
//         //void SetupTotallyRandomPalette();
//         //void ChangePalettePeriodically();

//     private:
        
//         void writeLedStripsColors(uint8_t quadNum, uint8_t stripNum);
//         void writeLedStripQuadColors(uint8_t quadNum);

// };

