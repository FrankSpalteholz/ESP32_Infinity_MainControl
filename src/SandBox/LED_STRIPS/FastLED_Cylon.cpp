// #include <Arduino.h>
// #include <FastLED.h>
// #include "Globals.h"
// #include "Math/Matrix.h"

// // How many leds in your strip?
// //#define NUM_LEDS 62


// typedef Matrix4x4<double> Matrix4x4d; 

// // For led chips like Neopixels, which have a data line, ground, and power, you just
// // need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// // ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN

// // Define the array of leds
// CRGB leds_B1[LEDS_PER_STRIP_COUNT];
// CRGB leds_B2[LEDS_PER_STRIP_COUNT];
// CRGB leds_B3[LEDS_PER_STRIP_COUNT];
// CRGB leds_B4[LEDS_PER_STRIP_COUNT];

// CRGB leds_A1[LEDS_PER_STRIP_COUNT];
// CRGB leds_A2[LEDS_PER_STRIP_COUNT];
// CRGB leds_A3[LEDS_PER_STRIP_COUNT];
// CRGB leds_A4[LEDS_PER_STRIP_COUNT];

// CRGB ledDoubleQuad[STRIP_QUAD_COUNT][STRIPS_PER_LOOP_COUNT][LEDS_PER_STRIP_COUNT];
// //#define pins [] = { LED_PIN_A1,LED_PIN_A2,LED_PIN_A3,LED_PIN_A4, LED_PIN_B1,LED_PIN_B2,LED_PIN_B3, LED_PIN_B4 }
// #define pins2 { 0,2  }

// void setup(){ 

// 	Serial.begin(9600);
// 	Serial.println("resetting");

// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B1,RGB>(leds_B1,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B2,RGB>(leds_B2,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B3,RGB>(leds_B2,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B4,RGB>(leds_B3,LEDS_PER_STRIP_COUNT);

// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A1,RGB>(leds_A1,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A2,RGB>(leds_A2,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A3,RGB>(leds_A3,LEDS_PER_STRIP_COUNT);
// 	// FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A4,RGB>(leds_A4,LEDS_PER_STRIP_COUNT);

// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A1,RGB>(ledDoubleQuad[0][0],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A2,RGB>(ledDoubleQuad[0][1],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A3,RGB>(ledDoubleQuad[0][2],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_A4,RGB>(ledDoubleQuad[0][3],LEDS_PER_STRIP_COUNT);

// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B1,RGB>(ledDoubleQuad[1][0],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B2,RGB>(ledDoubleQuad[1][1],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B3,RGB>(ledDoubleQuad[1][2],LEDS_PER_STRIP_COUNT);
// 	FastLED.addLeds<LED_STRIP_TYPE,LED_PIN_B4,RGB>(ledDoubleQuad[1][3],LEDS_PER_STRIP_COUNT);

// 	FastLED.setBrightness(84);

// }

// void fadeAllStrips(int scale) 
// { 
// 	for (uint8_t j = 0; j < STRIP_QUAD_COUNT; j++)
// 		for (uint8_t k = 0; k < STRIPS_PER_LOOP_COUNT; k++)
// 			for(uint8_t i = 0; i < LEDS_PER_STRIP_COUNT; i++) 
// 				ledDoubleQuad[j][k][i].nscale8(scale); 
// }

// int reverseDirection(int count, int value, bool isRight)
// {
// 	if(isRight)
// 		return (count -1) - value;
// 	else
// 		return value += ((count)-1)*-1;
// }

// void loop() 
// { 

// 	static uint8_t hue = 0;
	
// 	// move fading dot on strip quad A & B towards right
// 	for (uint8_t k = 0; k < STRIPS_PER_LOOP_COUNT; k++)
// 		for(uint8_t i = 0; i < LEDS_PER_STRIP_COUNT; i++) 
// 		{
// 			ledDoubleQuad[1][k][i] = CHSV(hue++, 255, 255); // B Strip move right
// 			int ledIndex = reverseDirection(LEDS_PER_STRIP_COUNT, i, true);
// 			ledDoubleQuad[0][k][ledIndex] = CHSV(hue++, 255, 255); // A Strip move right

// 			// Show the leds
// 			FastLED.show(); 
// 			// now that we've shown the leds, reset the i'th led to black
// 			// leds[i] = CRGB::Black;
// 			fadeAllStrips(175);
// 			// Wait a little bit before we loop around and do it again
// 			delay(10);

// 		}

// 	// move fading dot on strip quad A & B towards left
// 	for (uint8_t k = 0; k < STRIPS_PER_LOOP_COUNT; k++)
// 		for(uint8_t i = LEDS_PER_STRIP_COUNT-1; i >= 0; i--) 
// 		{
			 
// 			ledDoubleQuad[1][k][i] = CHSV(hue++, 255, 255);
// 			int ledIndex = reverseDirection(LEDS_PER_STRIP_COUNT, i, false);
// 			ledDoubleQuad[1][k][ledIndex] = CHSV(hue++, 255, 255);

// 			// Show the leds
// 			FastLED.show(); 
// 			// now that we've shown the leds, reset the i'th led to black
// 			// leds[i] = CRGB::Black;
// 			fadeAllStrips(175);
// 			// Wait a little bit before we loop around and do it again
// 			delay(10);

// 		}

// 	// for(int i = 0; i < LEDS_PER_STRIP_COUNT; i++) 
// 	// {
// 	// 	// Set the i'th led to red 
// 	// 	leds_B1[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B2[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B3[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B4[i] = CHSV(hue++, 255, 255);
		
		
// 	// 	//leds_A1[i] = CHSV(hue++, 255, 255);
// 	// 	int reverseDirection = i;
// 	// 	reverseDirection = (LEDS_PER_STRIP_COUNT -1) - reverseDirection;
// 	// 	leds_A1[reverseDirection] = CHSV(hue++, 255, 255);
// 	// 	// leds_A2[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_A3[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_A4[i] = CHSV(hue++, 255, 255);
		
// 	// 	// Serial.print("i: ");
// 	// 	// Serial.print(i);

// 	// 	// Serial.print(" -i: ");
// 	// 	// Serial.println(reverseDirection);


// 	// 	// Show the leds
// 	// 	FastLED.show(); 
// 	// 	// now that we've shown the leds, reset the i'th led to black
// 	// 	// leds[i] = CRGB::Black;
// 	// 	fadeAll();
// 	// 	// Wait a little bit before we loop around and do it again
// 	// 	delay(10);
// 	// }
	

// 	// // Now go in the other direction.  
// 	// for(int i = (LEDS_PER_STRIP_COUNT)-1; i >= 0; i--) {
// 	// 	// Set the i'th led to red 
// 	// 	leds_B1[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B2[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B3[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_B4[i] = CHSV(hue++, 255, 255);
		
// 	// 	int reverseDirection = abs(i);
// 	// 	reverseDirection = reverseDirection + ((LEDS_PER_STRIP_COUNT)-1)*-1;
// 	// 	leds_A1[abs(reverseDirection)] = CHSV(hue++, 255, 255);
// 	// 	// Serial.print("i: ");
// 	// 	// Serial.print(i);

// 	// 	// Serial.print(" -i: ");
// 	// 	// Serial.println(abs(reverseDirection));

// 	// 	//Serial.println(i);
// 	// 	//Serial.println(" -i: " + reverseDirection);

// 	// 	// leds_A2[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_A3[i] = CHSV(hue++, 255, 255);
// 	// 	// leds_A4[i] = CHSV(hue++, 255, 255);
// 	// 	// Show the leds
// 	// 	FastLED.show();
// 	// 	// now that we've shown the leds, reset the i'th led to black
// 	// 	// leds[i] = CRGB::Black;
// 	// 	fadeAll();
// 	// 	// Wait a little bit before we loop around and do it again
// 	// 	delay(10);
// 	// }

	
	
// }