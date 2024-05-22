#include <Arduino.h>
#include <FastLED.h>

#include "Globals.h"

class CLed
{
        
    public:

        CLed();
        ~CLed();

        CRGB leds[NUM_STRIPS][NUM_STRIP_LEDS]; // strip num 1 = inside 2 = outside
        
        struct ledStripData
        {
            uint8_t hsvVals[3] = {0,0,80}; // hue sat val -> low-white
            int8_t dotDir = 0;
            uint8_t dotSpeed = 80; // in ms 
            int8_t dotPos = 0;
            int8_t dotStartPos = 0;

            // TODO check if those members are actually global rather than locally accessible
            CRGBPalette16 currentPalette;
            TBlendType    currentBlending;
        };

        ledStripData ledStrip[NUM_STRIPS];

        //extern CRGBPalette16 myRedWhiteBluePalette;
        //extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

        void initLEDStrips();
        void showStripsColors();

        //void SetupPurpleAndGreenPalette();
        //void SetupBlackAndWhiteStripedPalette();
        //void FillLEDsFromPaletteColors(uint8_t colorIndex, uint8_t brightness, int8_t direction);
        //void SetupTotallyRandomPalette();
        //void ChangePalettePeriodically();

    private:
        
        void writeLedStripsColors(uint8_t stripNum);

};

