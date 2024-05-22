#include "CLed.h"


CLed::CLed() {}

CLed::~CLed() {}

void CLed::initLEDStrips()
{

    FastLED.addLeds<LED_STRIP_TYPE, LED_STRIP_PIN, COLOR_ORDER>(leds[0], NUM_STRIP_LEDS).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_STRIP_PIN2, COLOR_ORDER>(leds[1], NUM_STRIP_LEDS).setCorrection( TypicalLEDStrip );   

    FastLED.setBrightness(BRIGHTNESS);
    //SetupBlackAndWhiteStripedPalette(); 
    //currentBlending = LINEARBLEND;
    ledStrip[0].currentBlending = NOBLEND;
    ledStrip[1].currentBlending = NOBLEND;

}

void CLed::writeLedStripsColors(uint8_t stripNum)
{
    
    int dotPos_prev = ledStrip[stripNum].dotPos;
    
    // TODO state 0 -> no move
    switch (ledStrip[stripNum].dotDir)
    {
        case -1:
        
            if(ledStrip[stripNum].dotPos >= LED_STRIP_LOWERBOUND)
            {
                ledStrip[stripNum].dotPos--;
                
                if(ledStrip[stripNum].dotPos < LED_STRIP_LOWERBOUND)
                {
                    ledStrip[stripNum].dotPos = LED_STRIP_UPPERBOUND-1;
                }

            }
            
           //Serial.println(val);


            leds[stripNum][ledStrip[stripNum].dotPos] = CHSV(   ledStrip[stripNum].hsvVals[0],
                                                                ledStrip[stripNum].hsvVals[1],
                                                                ledStrip[stripNum].hsvVals[2]);
            leds[stripNum][dotPos_prev] = CHSV( ledStrip[ stripNum].hsvVals[0],
                                                ledStrip[stripNum].hsvVals[1],
                                                0);
            
            break;
        
        case 1:

            if(ledStrip[stripNum].dotPos <= LED_STRIP_UPPERBOUND-1)
            {
                ledStrip[stripNum].dotPos++;
                
                if(ledStrip[stripNum].dotPos > LED_STRIP_UPPERBOUND-1)
                {
                    ledStrip[stripNum].dotPos = LED_STRIP_LOWERBOUND; 
                }
            }

            //Serial.println(val);

            leds[stripNum][ledStrip[stripNum].dotPos] = CHSV(   ledStrip[stripNum].hsvVals[0],
                                                                ledStrip[stripNum].hsvVals[1],
                                                                ledStrip[stripNum].hsvVals[2]);
            
            leds[stripNum][dotPos_prev] = CHSV( ledStrip[ stripNum].hsvVals[0],
                                                ledStrip[stripNum].hsvVals[1],
                                                0);

            break;   
    }
}

void CLed::showStripsColors()
{
    EVERY_N_MILLISECONDS(80)
    {   
        // for (int i = 0; i < NUM_LEDS; i++)
        // {
        //     leds[0][i] = CRGB::White;
        //     leds[1][i] = CRGB::White;
        // }
        
        
        writeLedStripsColors(0);
        writeLedStripsColors(1);
        
        FastLED.show();
    }
    
}



