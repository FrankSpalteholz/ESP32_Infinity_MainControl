// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SH110X.h>
// #include <NewPing.h>
// #include "Images/SqHouseLogo.h"
// #include <elapsedMillis.h>



// // OLED display settings
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET -1

// Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // Ultrasonic sensor settings
// #define MAX_DISTANCE 200  // Maximum distance (in cm) to ping
// #define TRIG_PIN_1 2
// #define ECHO_PIN_1 15
// #define TRIG_PIN_2 16
// #define ECHO_PIN_2 4
// #define TRIG_PIN_3 19
// #define ECHO_PIN_3 18
// #define TRIG_PIN_4 5
// #define ECHO_PIN_4 17

// NewPing sonar1(TRIG_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
// NewPing sonar2(TRIG_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
// NewPing sonar3(TRIG_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
// NewPing sonar4(TRIG_PIN_4, ECHO_PIN_4, MAX_DISTANCE);

// int cursor[2] = {0,0};
// elapsedMillis lcdUpdateTimer;
// const uint16_t lcdUpdateTimerDelay = 100;


// void drawOnDisplay(int cursorPos[], int offset, const char* label, const char* state);
// char *concatenateCharArrays(char array1[], char array2[], char *concateArray);
// void debugOutputDisplay(int dataOffset, const char* mode, int data[4]);

// void setup() {
//   Serial.begin(9600);

//   // Initialize the OLED display
//   if (!display.begin(0x3c, true)) {
//     Serial.println(F("SSD1306 allocation failed"));
//     for (;;);
//   }
//   else
//   {
//     Serial.println(F("SSD1306 allocation success"));

//   }

//   display.display();
//   delay(1000);
//   display.clearDisplay();
// }

// void loop() {

//    //Read distances from ultrasonic sensors
//     unsigned int distance1 = sonar1.ping_cm();
//     unsigned int distance2 = sonar2.ping_cm();
//     unsigned int distance3 = sonar3.ping_cm();
//     unsigned int distance4 = sonar4.ping_cm();


// if(lcdUpdateTimer > lcdUpdateTimerDelay)
// {
        
   
//     // Print distances to serial monitor
//   //   Serial.print(F("Sensor 1: ")); Serial.print(distance1); Serial.println(F("cm"));
//   //   Serial.print(F("Sensor 2: ")); Serial.print(distance2); Serial.println(F("cm"));
//   //   Serial.print(F("Sensor 3: ")); Serial.print(distance3); Serial.println(F("cm"));
//   //   Serial.print(F("Sensor 4: ")); Serial.print(distance4); Serial.println(F("cm"));

//     int sonarData[4] = {0,0,0,0}; 

//     sonarData[0] =  distance1;
//     sonarData[1] =  distance2;
//     sonarData[2] =  distance3;
//     sonarData[3] =  distance4;

//     debugOutputDisplay(40, "", sonarData);

//     lcdUpdateTimer = 0;

//     // Wait for a second before the next loop
//   }
// }

// void drawOnDisplay(int cursorPos[2], int offset, const char* label, const char* state) {

//   display.setTextSize(1);
//   display.setTextColor(SH110X_WHITE);
//   display.setCursor(cursorPos[0], cursorPos[1]);
//   display.write(label);

//   display.setCursor(cursorPos[0] + offset, cursorPos[1]);
//   display.write(state);
  
//   //display.display();
 
// }

// void debugOutputDisplay(int dataOffset, const char* mode, int data[4])
// {   
//     char cstr[10];
//     char cstr2[5];
//     char cstr_out[10];
//     // cursor[0] = 0;
//     // cursor[1] = 0;
//     // drawOnDisplay(cursor, dataOffset, "[Control]", mode);
    
//     itoa(data[0], cstr, 10);
//     cursor[0] = 0;
//     cursor[1] = 0;
//     drawOnDisplay(cursor, dataOffset, "[S1]", cstr);
    
//     itoa(data[1], cstr, 10);
//     cursor[0] = 0;
//     cursor[1] = 15;
//     drawOnDisplay(cursor, dataOffset, "[S2]", cstr);

//     itoa(data[2], cstr, 10);
//     cursor[0] = 0;
//     cursor[1] = 30;
//     drawOnDisplay(cursor, dataOffset, "[S3]", cstr);

//     itoa(data[3], cstr, 10);
//     cursor[0] = 0;
//     cursor[1] = 45;
//     drawOnDisplay(cursor, dataOffset, "[S4]", cstr);

//     display.display();
//     display.clearDisplay();

// }


// char *concatenateCharArrays(char array1[], char array2[], char *concateArray)
// {
 
//   strcpy(concateArray, array1);
//   strcat(concateArray, ":");
//   strcat(concateArray, array2);

//   return concateArray;
// }

