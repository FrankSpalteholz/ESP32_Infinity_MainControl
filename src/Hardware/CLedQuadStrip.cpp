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

void CLedQuadStrip::fadeBrightness(CRGB leds[], uint8_t numLeds, uint8_t brightness)
{
   for(uint8_t i = 0; i < numLeds; i++) 
    {
        leds[i].setHSV( 255, 0, brightness);
    }
    
    FastLED.show();
}

void CLedQuadStrip::noiseAnim(CRGB leds[], ledStrip stripData, uint8_t numLeds)
{
    // Generiere 1D Perlin-Noise-Werte und weise sie den LEDs zu
  static uint16_t z = 0; // Z-Achsen-Parameter für Perlin Noise (wird für die Animation verwendet)


  //EVERY_N_MILLIS(10)
  //{
       
    unsigned long currentTime = millis();

    // Ändere die Geschwindigkeit nach Ablauf des Intervalls
    if (currentTime - stripData.lastUpdate > stripData.speedChangeInterval) 
    {
        stripData.speed = random(stripData.speedMin, stripData.speedMax); // Geschwindigkeit zufällig zwischen 1 und 20 wählen
        stripData.lastUpdate = currentTime;
    }

     // Ändere die Skalierung nach Ablauf des Intervalls
    if (currentTime - stripData.lastUpdate > stripData.scaleChangeInterval) {
        stripData.scale = random(stripData.scaleMin, stripData.scaleMax); // Skalierung zufällig zwischen 10 und 50 wählen
        stripData.lastUpdate = currentTime;
    }

    static float colorShift = 0.0;
    
    if (currentTime - stripData.lastUpdate > stripData.colorChangeInterval) {
        colorShift += 1.0 / (stripData.colorChangeInterval / 10.0); // Inkrementiere den Farbton-Wert
        if (colorShift >= 1.0) {
        colorShift = 0.0; // Zurücksetzen, wenn der Wert 1.0 überschreitet
        }
        stripData.lastUpdate = currentTime;
    }

   
    colorShift += stripData.colorChangeSpeed; // Inkrementiere den Farbton-Wert

    if (colorShift >= 1.0) {
        colorShift = 0.0; // Zurücksetzen, wenn der Wert 1.0 überschreitet
    }

    // Berechne den aktuellen Farbton für die Animation
    uint8_t currentHue = fadeHue(colorShift, stripData.startHue, stripData.endHue);

    //Serial.println(currentHue);
    // Generiere 1D Perlin-Noise-Werte und weise sie den LEDs zu
   
    for (int i = 0; i < numLeds; i++) 
    {
        uint8_t noiseValue = inoise8(i * stripData.scale, z);
        uint8_t brightness = map(noiseValue, 0, 255, 0, 255);
        leds[i] = CHSV(currentHue, 255, brightness);

    }

    // Schließe den Kreis: Weise dem letzten und ersten LED denselben Noise-Wert zu
    leds[0] = leds[numLeds - 1];


    // Inkrementiere den Z-Wert basierend auf der aktuellen Geschwindigkeit
    z += stripData.speed;

    FastLED.show();

 // }

}
