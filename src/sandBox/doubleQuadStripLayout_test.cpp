#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN     4
#define LED_PIN2    19



#define LED_PIN_A1     12
#define LED_PIN_A4     14
#define LED_PIN_A3     27
#define LED_PIN_A2     26
#define LED_PIN_B1     25
#define LED_PIN_B2     33
#define LED_PIN_B3     32
#define LED_PIN_B4     4


#define NUM_LEDS    64

CRGB leds_inside[NUM_LEDS];
CRGB leds_outside[NUM_LEDS];

CRGB leds_A1[NUM_LEDS];
CRGB leds_A2[NUM_LEDS];
CRGB leds_A3[NUM_LEDS];
CRGB leds_A4[NUM_LEDS];
CRGB leds_B1[NUM_LEDS];
CRGB leds_B2[NUM_LEDS];
CRGB leds_B3[NUM_LEDS];
CRGB leds_B4[NUM_LEDS];

void setup() {

  //FastLED.addLeds<NEOPIXEL, LED_PIN>(leds_outside, NUM_LEDS);
  //FastLED.addLeds<NEOPIXEL, LED_PIN2>(leds_inside, NUM_LEDS);

  FastLED.addLeds<NEOPIXEL, LED_PIN_A1>(leds_A1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_A2>(leds_A2, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_A3>(leds_A3, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_A4>(leds_A4, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_B1>(leds_B1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_B2>(leds_B2, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_B3>(leds_B3, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, LED_PIN_B4>(leds_B4, NUM_LEDS);
  
}

void loop() {
  

for(int i = 0; i < NUM_LEDS; i++) {

    uint8_t colorHSV[3] = {32, 255, 160};
    uint8_t colorHSV2[3] = {50, 255, 160};
    // set our current dot to red, green, and blue
    //leds_inside[i] = CRGB::Red;
    
    //leds_outside[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);
    
    leds_A1[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);
    leds_A2[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);
    leds_A3[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);
    leds_A4[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);

    leds_B1[i] = CHSV(colorHSV2[0], colorHSV2[1], colorHSV2[2]);
    leds_B2[i] = CHSV(colorHSV2[0], colorHSV2[1], colorHSV2[2]);
    leds_B3[i] = CHSV(colorHSV2[0], colorHSV2[1], colorHSV2[2]);
    leds_B4[i] = CHSV(colorHSV2[0], colorHSV2[1], colorHSV2[2]);

    FastLED.show();
    // clear our current dot before we move on
    //leds_inside[i] = CRGB::Black;
    //leds_outside[i] = CRGB::Black;

    leds_A1[i] = CRGB::Black;
    leds_A2[i] = CRGB::Black;
    leds_A3[i] = CRGB::Black;
    leds_A4[i] = CRGB::Black;

    leds_B1[i] = CRGB::Black;
    leds_B2[i] = CRGB::Black;
    leds_B3[i] = CRGB::Black;
    leds_B4[i] = CRGB::Black;

    delay(8);
  }

  
}