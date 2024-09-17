/**
 * @brief Moves a dot around the four LED strips in a square pattern.
 *
 * This function is responsible for moving a white dot around the four LED strips
 * in a square pattern. The dot can move clockwise or counterclockwise, and the
 * speed of the movement is controlled by the `speed` parameter.
 *
 * @param ledQuads A 2D array of CRGB objects representing the LED strips.
 * @param speed The speed of the dot movement, in milliseconds between each step.
 * @param clockwise True to move the dot clockwise, false to move it counterclockwise.
 * @param pos A reference to the current position of the dot, which will be updated by the function.
 * @param numQuads The number of LED strips in the square pattern.
 */
void moveDotAroundSquare(CRGB ledQuads[4][LED_STRIP_COUNT_A_B], int speed, bool clockwise, int& pos, int numQuads)
#include <Arduino.h>
#include <FastLED.h>


#define LED_PIN_A1      23
#define LED_PIN_A2      27
#define LED_PIN_A3      33
#define LED_PIN_A4      14

#define LED_PIN_B1      25
#define LED_PIN_B2      26
#define LED_PIN_B3      32
#define LED_PIN_B4      12

#define STRIP_QUAD_COUNT        2
#define STRIPS_PER_LOOP_COUNT   4
#define LED_STRIP_COUNT_A_B     62
#define LED_STRIP_TYPE    WS2812B
#define COLOR_ORDER GRB

#define DOT_COLOR CRGB::White  // Color of the moving dot
#define DOT_DELAY 100          // Delay between dot movements (milliseconds)


CRGB ledQuadsTopA[STRIPS_PER_LOOP_COUNT][LED_STRIP_COUNT_A_B]; // Top A = inside B = outside
CRGB ledQuadsTopB[STRIPS_PER_LOOP_COUNT][LED_STRIP_COUNT_A_B]; // Top A = inside B = outside


// Global variables for position and timing
unsigned long previousMillis = 0;
const long interval = 10; // Interval in milliseconds

int outerSquarePos = 0;
int innerSquarePos = 0;


void  fillQuadsTestPattern();
void moveDotAroundSquare(CRGB ledQuads[4][LED_STRIP_COUNT_A_B], int speed, bool clockwise, int& pos, int numQuads);

void setup() {
    // Set up LED strips for FastLED as before
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A1, COLOR_ORDER>(ledQuadsTopA[0], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A2, COLOR_ORDER>(ledQuadsTopA[1], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A3, COLOR_ORDER>(ledQuadsTopA[2], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_A4, COLOR_ORDER>(ledQuadsTopA[3], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   

    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B1, COLOR_ORDER>(ledQuadsTopB[0], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B2, COLOR_ORDER>(ledQuadsTopB[1], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B3, COLOR_ORDER>(ledQuadsTopB[2], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
    FastLED.addLeds<LED_STRIP_TYPE, LED_PIN_B4, COLOR_ORDER>(ledQuadsTopB[3], LED_STRIP_COUNT_A_B).setCorrection( TypicalLEDStrip );   
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        // Save the last time you updated the LEDs
        previousMillis = currentMillis;

        FastLED.clear();
        // Move dots for both squares
        moveDotAroundSquare(ledQuadsTopB, 10, false, outerSquarePos, STRIPS_PER_LOOP_COUNT);
        moveDotAroundSquare(ledQuadsTopA, 10, true, innerSquarePos, STRIPS_PER_LOOP_COUNT);
        FastLED.show();
    }
}

void fillQuadsTestPattern() {
    // Clear all LEDs before setting a new pattern
    FastLED.clear();
    
    // Example: Set the inner and outer squares to different colors
    // Bottom side (index 0)
    fill_solid(ledQuadsTopA[0], LED_STRIP_COUNT_A_B, CRGB::Red);  // Inner bottom side in red
    fill_solid(ledQuadsTopB[0], LED_STRIP_COUNT_A_B, CRGB::Blue); // Outer bottom side in blue
    
    // Left side (index 1)
    fill_solid(ledQuadsTopA[1], LED_STRIP_COUNT_A_B, CRGB::Green);  // Inner left side in green
    fill_solid(ledQuadsTopB[1], LED_STRIP_COUNT_A_B, CRGB::Yellow); // Outer left side in yellow
    
    // Top side (index 2)
    fill_solid(ledQuadsTopA[2], LED_STRIP_COUNT_A_B, CRGB::Purple);  // Inner top side in purple
    fill_solid(ledQuadsTopB[2], LED_STRIP_COUNT_A_B, CRGB::Orange);  // Outer top side in orange
    
    // Right side (index 3)
    fill_solid(ledQuadsTopA[3], LED_STRIP_COUNT_A_B, CRGB::Cyan);  // Inner right side in cyan
    fill_solid(ledQuadsTopB[3], LED_STRIP_COUNT_A_B, CRGB::Magenta); // Outer right side in magenta
    
    FastLED.show();  // Update the LEDs
    delay(1000);  // Pause for a second before looping
}


void moveDotAroundSquare(CRGB ledQuads[4][LED_STRIP_COUNT_A_B], int speed, bool clockwise, int& pos, int numQuads) {
    const int numLedsPerSide = LED_STRIP_COUNT_A_B;
    const int totalLeds = numLedsPerSide * 4;

    // Clear all LEDs
    //FastLED.clear();

    // Calculate the LED index for the current position
    int side = pos / numLedsPerSide;
    int index = pos % numLedsPerSide;

    // Set the dot on the appropriate side
    if (side < numQuads) {
        ledQuads[side][index] = CRGB::White;
    }

   // FastLED.show();  // Update the LEDs

    // Update position based on direction
    if (clockwise) {
        pos = (pos + 1) % totalLeds;
    } else {
        pos = (pos - 1 + totalLeds) % totalLeds;
    }
}



