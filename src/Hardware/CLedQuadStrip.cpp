#include "CLedQuadStrip.h"

CLedQuadStrip::CLedQuadStrip() {}

CLedQuadStrip::~CLedQuadStrip() {}

void CLedQuadStrip::initLEDStrips()
{

    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_C1, COLOR_ORDER>(ledQuadBottom, LED_STRIP_COUNT_C).setCorrection( TypicalLEDStrip );   

    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A1, COLOR_ORDER>(ledQuadsTopA[0], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A2, COLOR_ORDER>(ledQuadsTopA[1], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A3, COLOR_ORDER>(ledQuadsTopA[2], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A4, COLOR_ORDER>(ledQuadsTopA[3], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   

    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B1, COLOR_ORDER>(ledQuadsTopB[0], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B2, COLOR_ORDER>(ledQuadsTopB[1], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B3, COLOR_ORDER>(ledQuadsTopB[2], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B4, COLOR_ORDER>(ledQuadsTopB[3], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   

    // ledStripData[0][0].currentBlending = NOBLEND;
    // ledStripData[0][1].currentBlending = NOBLEND;
    // ledStripData[0][2].currentBlending = NOBLEND;
    // ledStripData[0][3].currentBlending = NOBLEND;

    // ledStripData[1][0].currentBlending = NOBLEND;
    // ledStripData[1][1].currentBlending = NOBLEND;
    // ledStripData[1][2].currentBlending = NOBLEND;
    // ledStripData[1][3].currentBlending = NOBLEND;

    FastLED.setBrightness(BRIGHTNESS);

}

uint8_t CLedQuadStrip::fadeHue(float colorShift, uint8_t startHue, uint8_t endHue) {
  // Verwende eine Sinuswelle für einen sanften Rücklauf des Farbtons
  return startHue + (endHue - startHue) * 0.5 * (1.0 + sin(3.14159 * colorShift)); // Die Sinuswelle variiert von -1 bis 1
}

void CLedQuadStrip::fadeBrightness(CRGB leds[], uint8_t numLeds, uint8_t startBrightness, uint8_t endBrightness)
{
    //for brightness going up
  if(endBrightness > startBrightness)
  {
    for(uint8_t j = startBrightness; j <= endBrightness; j++) 
    {
      for(uint8_t i = 0; i < numLeds; i++) 
      {
        leds[i].setHSV( 255, 0, j);
      }
      
      FastLED.show();
    }
  }
  
  //for brightness going down
  if(endBrightness < startBrightness)
  {
    for(uint8_t j=startBrightness; j >= endBrightness; j--) 
    {
      for(uint8_t i=0; i<numLeds; i++) 
      {
        leds[i].setHSV( 255, 0, j);
      }
      
      FastLED.show();
    }
  }
}
