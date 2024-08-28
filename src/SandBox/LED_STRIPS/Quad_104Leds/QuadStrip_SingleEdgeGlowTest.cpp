// #include <FastLED.h>

// #define NUM_LEDS 104 // 26 LEDs pro Seite, 4 Seiten = 104 LEDs insgesamt
// #define DATA_PIN 0 // Pin für den LED-Strip

// CRGB leds[NUM_LEDS];

// // Parameter für die Helligkeit
// float cornerBrightness = 250;
// float edgeBrightness = 25;
// float middleBrightness = 0;

// // Parameter für die Animation
// float brightnessMin = 20;
// float brightnessMax = 250;
// float brightnessSpeed = 30;
// float brightnessDirection = 1;

// // Variable zur Bestimmung der aktiven Ecke
// uint8_t activeCorner = 3; // 0: Ecke 1, 1: Ecke 2, 2: Ecke 3, 3: Ecke 4

// // Funktion zur Berechnung der Helligkeit basierend auf der Position
// float getBrightnessForPosition(int pos) {
//     int side = pos / 26;
//     int localPos = pos % 26;

//     // Bestimme die benachbarten Seiten der aktiven Ecke
//     bool isActiveSide = (side == activeCorner || side == (activeCorner + 3) % 4);
//     if (!isActiveSide) {
//         return 0; // Diese Seite ist nicht aktiv
//     }

//     // Berechne die Helligkeit basierend auf der Entfernung von der Ecke
//     int distanceFromActiveCorner;
//     if (side == activeCorner) {
//         distanceFromActiveCorner = localPos; // Entfernung zur Ecke auf der aktiven Seite
//     } else {
//         distanceFromActiveCorner = 25 - localPos; // Entfernung zur Ecke auf der benachbarten Seite
//     }

//     // Berechne die Helligkeit und stelle sicher, dass sie im erlaubten Bereich liegt
//     float brightness = map(distanceFromActiveCorner, 0, 13, cornerBrightness, edgeBrightness);
//     brightness = constrain(brightness, middleBrightness, cornerBrightness);
    
//     return brightness;
// }

// // Aktualisiert die Helligkeit der Ecken
// void updateCornerBrightness() {
//     cornerBrightness += brightnessSpeed * brightnessDirection;
//     if (cornerBrightness >= brightnessMax) {
//         cornerBrightness = brightnessMax;
//         brightnessDirection = -1;
//     }
//     if (cornerBrightness <= brightnessMin) {
//         cornerBrightness = brightnessMin;
//         brightnessDirection = 1;
//     }
// }

// void setup() {
//     Serial.begin(9600);
//     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
//     FastLED.setBrightness(50);
// }

// void loop() {
//     updateCornerBrightness();

//     for (int i = 0; i < NUM_LEDS; i++) {
//         float brightness = getBrightnessForPosition(i);
//         leds[i] = CHSV(0, 0, brightness);
//     }

//     FastLED.show();
//     delay(30);
// }
