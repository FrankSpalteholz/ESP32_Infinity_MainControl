// #include <FastLED.h>

// #define NUM_LEDS 104 // 26 LEDs pro Seite, 4 Seiten = 104 LEDs insgesamt

// // Definiere den Pin für den LED-Strip
// #define DATA_PIN 0

// // Erstelle ein Array für die LEDs
// CRGB leds[NUM_LEDS];

// // Parameter für die Helligkeit
// float cornerBrightness = 200; // Maximaler Helligkeitswert an den Ecken
// float edgeBrightness = 10;   // Helligkeit an den Kanten, die zu den Ecken hin abnimmt
// float middleBrightness = 0;   // Minimaler Helligkeitswert in der Mitte der Seiten

// // Parameter für die Animation
// float brightnessMin = 20;    // Minimaler Helligkeitswert für die Ecken
// float brightnessMax = 250;    // Maximaler Helligkeitswert für die Ecken
// float brightnessSpeed = 30;  // Geschwindigkeit der Helligkeitsänderung
// float brightnessDirection = 1; // Richtung der Helligkeitsänderung: 1 für Erhöhung, -1 für Verringerung

// // Variable zur Bestimmung der aktiven Ecke
// uint8_t activeCorner = 0; // 0: Ecke 1, 1: Ecke 2, 2: Ecke 3, 3: Ecke 4


// float getBrightnessForPosition(int pos) {
//     // Berechne die Helligkeit für jede Position
//     int side = pos / 26; // Bestimme die Seite: 0, 1, 2, 3
//     int localPos = pos % 26; // Position innerhalb der Seite

//     // Berechne die Entfernung von den Ecken (0 bis 26)
//     float distanceToCorner = min(localPos, 25 - localPos);

//     // Berechne die Helligkeit basierend auf der Entfernung von den Ecken
//     float brightness = map(distanceToCorner, 0, 13, cornerBrightness, edgeBrightness);
//     brightness = constrain(brightness, middleBrightness, cornerBrightness);
    
//     return brightness;
// }


// void setup() {
//     Serial.begin(9600);
//     // Initialisiere den LED-Strip
//     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
//     FastLED.setBrightness(50);
// }

// void loop(){
// // Ändere die Helligkeit der Ecken kontinuierlich
//     cornerBrightness += brightnessSpeed * brightnessDirection;
    
//     // Wenn die Helligkeit den Minimalwert erreicht, ändern wir die Richtung
//     if (cornerBrightness >= brightnessMax) {
//         cornerBrightness = brightnessMax;
//         brightnessDirection = -1; // Wechsel zur Verringerung
//     }
    
//     // Wenn die Helligkeit den Maximalwert erreicht, ändern wir die Richtung
//     if (cornerBrightness <= brightnessMin) {
//         cornerBrightness = brightnessMin;
//         brightnessDirection = 1; // Wechsel zur Erhöhung
//     }

//     // Setze die Helligkeit für jede LED basierend auf ihrer Position
//     for (int i = 0; i < NUM_LEDS; i++) {
//         // Berechne die Helligkeit für jede Position
//         float brightness = getBrightnessForPosition(i);
        
//         // Setze die Farbe auf Weiß mit der berechneten Helligkeit
//         leds[i] = CHSV(0, 0, brightness); // Weiß = Hue 0, Saturation 0
//     }
    
//     // Aktualisiere die LEDs
//     FastLED.show();
    
//     // Warte ein wenig, um die Animation zu verlangsamen
//     delay(30);
// }
