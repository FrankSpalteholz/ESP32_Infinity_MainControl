#include <Arduino.h>
#include <FastLED.h>

#include "Globals.h"

// TODO 1. define data structs for all strips (default/start values) in initLEDStrips
// TODO 2. 

class CLedQuadStrip
{
        
    public:

        CLedQuadStrip();
        ~CLedQuadStrip();

        CRGB ledQuadsTopA[STRIPS_PER_LOOP_COUNT][LED_STRIP_COUNT_A_B]; // Top A = inside B = outside
        CRGB ledQuadsTopB[STRIPS_PER_LOOP_COUNT][LED_STRIP_COUNT_A_B]; // Top A = inside B = outside
        CRGB ledQuadBottom[LED_STRIP_COUNT_C]; // C = bottom

        struct ledStrip
        {
            uint8_t hsvVals[3] = {0,0,80}; // hue sat val -> low-white
            
            float brightnessNoiseScale = 200;
            int noiseSpeed = 10;

            // Parameter für die Animation

            uint16_t z = 0;             // Z-Achsen-Parameter für Perlin Noise (wird für die Animation verwendet)
            uint8_t speed = 3;          // Startgeschwindigkeit der Animation
            uint16_t scale = 25;        // Skalierung des Noise für feinere Details

            uint8_t scaleMax = 50;
            uint8_t scaleMin = 10;

            uint8_t speedMax = 5;
            uint8_t speedMin = 2;

            unsigned long lastUpdate = 0;
            unsigned long speedChangeInterval = 5000;   // Intervall in Millisekunden, nach dem die Geschwindigkeit geändert wird
            unsigned long scaleChangeInterval = 5000;   // Intervall für Skalierungsänderung
            unsigned long colorChangeInterval = 500;    // Intervall für Farbänderung

            // Geschwindigkeit der Farbwechsel-Animation

            float colorChangeSpeed = 0.005;             // Kleinere Werte verlangsamen die Animation, größere Werte beschleunigen sie

            uint8_t startHue = 100;                     // Start-Farbton (Aqua)
            uint8_t endHue = 213;                       // End-Farbton (Purple: Aqua + 113)

        };

        ledStrip stripAData, stripBData, stripCData;

        void initLEDStrips();

        uint8_t fadeHue(float colorShift, uint8_t startHue, uint8_t endHue);
        void fadeBrightness(CRGB leds[], uint8_t numLeds, uint8_t brightness);

        void noiseAnim(CRGB leds[], ledStrip stripData, uint8_t numLeds); // strip A = 0, strip B = 1, strip C = 2

    private:

};

