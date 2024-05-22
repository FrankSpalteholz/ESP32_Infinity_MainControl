// #include <Arduino.h>
// #include <FastLED.h>

// #define LED_PIN     4
// #define LED_PIN2    19

// #define NUM_LEDS    64

// CRGB leds_inside[NUM_LEDS];
// CRGB leds_outside[NUM_LEDS];

// void setup() {

//   FastLED.addLeds<NEOPIXEL, LED_PIN>(leds_outside, NUM_LEDS);
//   FastLED.addLeds<NEOPIXEL, LED_PIN2>(leds_inside, NUM_LEDS);
  
// }

// void loop() {
  

// for(int i = 0; i < NUM_LEDS; i++) {

//     uint8_t colorHSV[3] = {0, 0, 160};
//     // set our current dot to red, green, and blue
//     //leds_inside[i] = CRGB::Red;
    
//     //leds_outside[i] = CHSV(colorHSV[0], colorHSV[1], colorHSV[2]);
    
//     leds_outside[i] = CRGB::OrangeRed;
//     FastLED.show();
//     // clear our current dot before we move on
//     //leds_inside[i] = CRGB::Black;
//     //leds_outside[i] = CRGB::Black;
//     delay(10);
//   }

  
// }