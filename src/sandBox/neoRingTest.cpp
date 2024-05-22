// // Basic FastLED Aminations for a ring and for half a ring by Chemdoc77
// // This will work on a strip, too.

// #include <FastLED.h>

// #define DATA_PIN     23
// #define LED_TYPE     NEOPIXEL 
// #define NUM_LEDS     12
// CRGB leds[NUM_LEDS];
// int brightness = 30;
// uint16_t half = NUM_LEDS/2; 

// void cd77_colorwipe_dot(CRGB color, uint16_t wait) ;
// void cd77_colorwipe(CRGB color, uint16_t wait) ;
// void cd77_colorwipe_reverse(CRGB color, uint16_t wait);
// void cd77_colorwipe_half_dot(CRGB color, uint16_t wait) ;
// void cd77_colorwipe_half(CRGB color, uint16_t wait);

// void setup() { 

//   delay(1000);
//   FastLED.addLeds<LED_TYPE, DATA_PIN>(leds, NUM_LEDS);         
//   FastLED.setDither(false);
//   FastLED.setCorrection(TypicalLEDStrip);
//   FastLED.setBrightness(brightness);
//   FastLED.setMaxPowerInVoltsAndMilliamps(5, 1500);
//     set_max_power_indicator_LED(13);
//   fill_solid(leds, NUM_LEDS, CRGB::Black);
//   FastLED.show();
 
// }
// void loop() {

//   cd77_colorwipe(CRGB::Red , 200);
//   fill_solid(leds, NUM_LEDS, CRGB::Black);
//   FastLED.delay(50);
  
// //   cd77_colorwipe_reverse(CRGB::Blue, 200);
// //   fill_solid(leds, NUM_LEDS, CRGB::Black);
// //   FastLED.delay(50);
  
// //   cd77_colorwipe_dot(CRGB::Red, 100);  

// //   cd77_colorwipe_half(CRGB::Blue,200);
// //   fill_solid(leds, NUM_LEDS, CRGB::Black);
// //   FastLED.delay(50);
  
// //   cd77_colorwipe_half_dot(CRGB::Red, 100);
// }
// //==================== Functions ===============================

// void cd77_colorwipe_dot(CRGB color, uint16_t wait) {
//   for (uint16_t i = 0; i < NUM_LEDS; i++) {
//     leds[i] = color;
//     FastLED.delay(wait);
//     leds[i] = CRGB::Black;
//     FastLED.show();
//   }
// } 

// void cd77_colorwipe(CRGB color, uint16_t wait) {
//   for (uint16_t i = 0; i < NUM_LEDS; i++) 
//   {
//     leds[i] = color;
//     FastLED.delay(wait);
//   }
// }
// void cd77_colorwipe_reverse(CRGB color, uint16_t wait) {
//   for (uint16_t i = NUM_LEDS-1; i >= 0; i--) 
//   {
//     leds[i] = color;
//     FastLED.delay(wait);
//     leds[i] = CRGB::Black;
//     FastLED.show();
//   }
// }

// void cd77_colorwipe_half_dot(CRGB color, uint16_t wait) {
//   for (uint16_t i = 0; i < half; i++) {
//     leds[half-i] = color;
//     leds[i+half] = color;
//     FastLED.delay(wait);
//     leds[half-i] = CRGB::Black;
//     leds[i+half] = CRGB::Black;
//     FastLED.show();
//   }  
// }

// void cd77_colorwipe_half(CRGB color, uint16_t wait) {
//   for (uint16_t i = 0; i < half; i++) {
//     leds[half-i] = color;
//     leds[i+half] = color;
//     FastLED.delay(wait);
//   }
// }