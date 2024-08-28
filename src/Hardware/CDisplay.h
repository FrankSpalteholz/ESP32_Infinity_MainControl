#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <SPI.h>
#include <Wire.h>

#include "Globals.h"
#include "Images/SqHouseLogo.h"


class CDisplay
{
    private:

        Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

        uint8_t cursorPos[2] = {0,0};
        
        void drawOnDisplay(uint8_t offset, const char* label, const char* state);
        char *concatenateCharArrays(char array1[], char array2[],  char *concateArray);

    public:

        CDisplay();
        ~CDisplay();

        void initDisplay();
        void clearScreen(){display.clearDisplay();};
        void writeToScreen(){ display.display();};
        void setCursorPos(uint8_t xPos, uint8_t yPos){cursorPos[0] = xPos; cursorPos[1] = yPos;};
        void outputToDisplay(uint8_t labelEndCursor, uint8_t dataSeparation, const char* label, int data[], uint8_t dataCount);
};

CDisplay::CDisplay() {}
CDisplay::~CDisplay() {}

void CDisplay::initDisplay()
{
  
    display.begin(i2c_Address, true); // Address 0x3C default
    display.display();
    delay(2000);

    display.clearDisplay();
    display.display();

}

char *CDisplay::concatenateCharArrays(char array1[], char array2[], char *concateArray)
{
  strcpy(concateArray, array1);
  strcat(concateArray, ":");
  strcat(concateArray, array2);

  return concateArray;
}

void CDisplay::outputToDisplay(uint8_t labelEndCursor, uint8_t dataSeparation, const char* label, int data[], uint8_t dataCount)
{   
    drawOnDisplay(labelEndCursor, label, "");

    for (uint8_t i = 0; i < dataCount; i++)
    {
      char cstr[5];
      itoa(data[i], cstr, 10);
      drawOnDisplay(labelEndCursor + dataSeparation*i, "", cstr);
    }
    
}

void CDisplay::drawOnDisplay(uint8_t offset, const char* label, const char* state) {

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(cursorPos[0], cursorPos[1]);
  display.write(label);

  display.setCursor(cursorPos[0] + offset, cursorPos[1]);
  display.write(state);
  
}