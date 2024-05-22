#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <SPI.h>
#include <Wire.h>

#include "Globals.h"
#include "Images/SqHouseLogo.h"


class CLcd
{
    private:
        Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

        int cursor[2] = {0,0};

        char *concatenateCharArrays(char array1[], char array2[],  char *concateArray);
        void drawOnDisplay(int cursorPos[2], int offset, const char* label, const char* state);
        void initDataStruct();

    public:
        CLcd(/* args */);
        ~CLcd();

        void initDisplay();
        void debugOutputDisplay(int dataOffset, const char* mode, int data[4]);
};


CLcd::CLcd(/* args */) {}
CLcd::~CLcd() {}

void CLcd::initDisplay()
{
  

    display.begin(i2c_Address, true); // Address 0x3C default

    display.display();
    delay(1000);

    // Clear the buffer.
    display.clearDisplay();

    // // miniature bitmap display
    // display.drawBitmap(0, 0,  image_data_SqHouseLogo, 128, 64, 1);
    // display.display();
    // delay(1000);

    // display.display();
    display.clearDisplay();
}

char *CLcd::concatenateCharArrays(char array1[], char array2[], char *concateArray)
{
 
  strcpy(concateArray, array1);
  strcat(concateArray, ":");
  strcat(concateArray, array2);

  return concateArray;
}

void CLcd::debugOutputDisplay(int dataOffset, const char* mode, int data[4] )
{   
    char cstr[5];
    char cstr2[5];
    char cstr_out[10];
    // cursor[0] = 0;
    // cursor[1] = 0;
    // drawOnDisplay(cursor, dataOffset, "[Control]", mode);
    
    itoa(data[0], cstr, 10);
    itoa(data[1], cstr2, 10);
    concatenateCharArrays(cstr2, cstr, cstr_out);
    cursor[0] = 0;
    cursor[1] = 15;
    drawOnDisplay(cursor, dataOffset, "[S LR]", cstr_out);
    
    itoa(data[2], cstr, 10);
    cursor[0] = 0;
    cursor[1] = 15;
    drawOnDisplay(cursor, dataOffset + 45, "",cstr);

    itoa(data[3], cstr, 10);
    cursor[0] = 0;
    cursor[1] = 15;
    drawOnDisplay(cursor, dataOffset + 65, "", cstr);

    // itoa(data[3], cstr, 10);
    // cursor[0] = 0;
    // cursor[1] = 57;
    // drawOnDisplay(cursor, dataOffset, "[S2 Avr]", cstr);

    display.display();
    display.clearDisplay();

}

void CLcd::drawOnDisplay(int cursorPos[2], int offset, const char* label, const char* state) {

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(cursorPos[0], cursorPos[1]);
  display.write(label);

  display.setCursor(cursorPos[0] + offset, cursorPos[1]);
  display.write(state);
  
  //display.display();
 
}