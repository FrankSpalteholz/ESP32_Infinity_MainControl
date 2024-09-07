// #include <FastLED.h>

// #define NUM_LEDS 104 // 26 LEDs pro Seite, 4 Seiten = 104 LEDs insgesamt

// // Definiere den Pin für den LED-Strip
// #define DATA_PIN 0

// // Erstelle ein Array für die LEDs
// CRGB leds[NUM_LEDS];

// float brightnessNoiseScale = 200;

// int noiseSpeed = 10;

// // Parameter für die Animation
// uint16_t z = 0;          // Z-Achsen-Parameter für Perlin Noise (wird für die Animation verwendet)
// uint8_t speed = 3;       // Startgeschwindigkeit der Animation
// uint16_t scale = 30; // Skalierung des Noise für feinere Details

// uint8_t scaleMax = 50;
// uint8_t scaleMin = 10;

// uint8_t speedMax = 5;
// uint8_t speedMin = 2;

// unsigned long lastUpdate = 0;
// unsigned long speedChangeInterval = 5000; // Intervall in Millisekunden, nach dem die Geschwindigkeit geändert wird
// unsigned long scaleChangeInterval = 3000;  // Intervall für Skalierungsänderung
// unsigned long colorChangeInterval = 500; // Intervall für Farbänderung

// // Geschwindigkeit der Farbwechsel-Animation
// float colorChangeSpeed = 0.001; // Kleinere Werte verlangsamen die Animation, größere Werte beschleunigen sie


// uint8_t startHue = 100; // Start-Farbton (Aqua)
// uint8_t endHue = 213; // End-Farbton (Purple: Aqua + 128)

// bool display_messages = 1;
// bool display_dimming_index = 1;

// uint8_t calculateHue(float colorShift) {
//   // Verwende eine Sinuswelle für einen sanften Rücklauf des Farbtons
//   return startHue + (endHue - startHue) * 0.5 * (1.0 + sin(3.14159 * colorShift)); // Die Sinuswelle variiert von -1 bis 1
// }

// void setup() {

//     Serial.begin(9600);
//     // Initialisiere den LED-Strip
//     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
//     FastLED.setBrightness(50);
  
// }

// void loop() 
// {
//   // Generiere 1D Perlin-Noise-Werte und weise sie den LEDs zu
//   static uint16_t z = 0; // Z-Achsen-Parameter für Perlin Noise (wird für die Animation verwendet)

// //dimming_animation(0, 255, 10);


//   EVERY_N_MILLIS(10)
//   {
       
//     unsigned long currentTime = millis();

//     // Ändere die Geschwindigkeit nach Ablauf des Intervalls
//     if (currentTime - lastUpdate > speedChangeInterval) 
//     {
//         speed = random(speedMin, speedMax); // Geschwindigkeit zufällig zwischen 1 und 20 wählen
//         lastUpdate = currentTime;
//     }

//      // Ändere die Skalierung nach Ablauf des Intervalls
//     if (currentTime - lastUpdate > scaleChangeInterval) {
//         scale = random(scaleMin, scaleMax); // Skalierung zufällig zwischen 10 und 50 wählen
//         lastUpdate = currentTime;
//     }

//     static float colorShift = 0.0;
    
//     if (currentTime - lastUpdate > colorChangeInterval) {
//         colorShift += 1.0 / (colorChangeInterval / 10.0); // Inkrementiere den Farbton-Wert
//         if (colorShift >= 1.0) {
//         colorShift = 0.0; // Zurücksetzen, wenn der Wert 1.0 überschreitet
//         }
//         lastUpdate = currentTime;
//     }

   
//     colorShift += colorChangeSpeed; // Inkrementiere den Farbton-Wert

//     if (colorShift >= 1.0) {
//         colorShift = 0.0; // Zurücksetzen, wenn der Wert 1.0 überschreitet
//     }

//     // Berechne den aktuellen Farbton für die Animation
//     uint8_t currentHue = calculateHue(colorShift);

//     //Serial.println(currentHue);
//     // Generiere 1D Perlin-Noise-Werte und weise sie den LEDs zu
   
    
//     for (int i = 0; i < NUM_LEDS; i++) 
//     {
//         uint8_t noiseValue = inoise8(i * scale, z);
//         uint8_t brightness = map(noiseValue, 0, 255, 0, 255);
//         leds[i] = CHSV(currentHue, 150, brightness);
//         //leds[i] = CHSV(255, 0, brightness);

//     }

//     // Schließe den Kreis: Weise dem letzten und ersten LED denselben Noise-Wert zu
//     leds[0] = leds[NUM_LEDS - 1];

//     // Aktualisiere die LEDs
//     FastLED.show();

//     // Inkrementiere den Z-Wert basierend auf der aktuellen Geschwindigkeit
//     z += speed;

//     // Warte ein wenig, um die Animation zu verlangsamen
//     //delay(10);

//   }

// }
