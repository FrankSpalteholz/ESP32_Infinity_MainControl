#include <Arduino.h>
#include <FastLED.h>

#include "Globals.h"

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
            uint16_t scale = 30;        // Skalierung des Noise für feinere Details

            uint8_t scaleMax = 50;
            uint8_t scaleMin = 10;

            uint8_t speedMax = 5;
            uint8_t speedMin = 2;

            unsigned long lastUpdate = 0;
            unsigned long speedChangeInterval = 5000;   // Intervall in Millisekunden, nach dem die Geschwindigkeit geändert wird
            unsigned long scaleChangeInterval = 3000;   // Intervall für Skalierungsänderung
            unsigned long colorChangeInterval = 500;    // Intervall für Farbänderung

            // Geschwindigkeit der Farbwechsel-Animation

            float colorChangeSpeed = 0.001;             // Kleinere Werte verlangsamen die Animation, größere Werte beschleunigen sie

            uint8_t startHue = 100;                     // Start-Farbton (Aqua)
            uint8_t endHue = 213;                       // End-Farbton (Purple: Aqua + 128)

        };

        ledStrip stripAData, stripBData, stripCData;

        void initLEDStrips();

        uint8_t fadeHue(float colorShift, uint8_t startHue, uint8_t endHue);
        void fadeBrightness(CRGB leds[], uint8_t numLeds, uint8_t brightness);

        void stripC_startAnim();

    private:

};

