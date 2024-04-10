#include <Arduino.h>
#include <elapsedMillis.h>

#include "Globals.h"
#include "Sonars.h"
#include "Lcd_IO.h"

Lcd_IO lcd = Lcd_IO();
Sonars sonars = Sonars();

int data[4];

void processSonars(bool isAverage);


//##############################################################################################


void setup() {

    Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
    lcd.initDisplay();
}


//##############################################################################################


void loop() {

    processSonars(true);

    data[0] = sonars.getRawDistance(0);
    data[1] = sonars.getAvrDistance(0);
    data[2] = sonars.getRawDistance(1);
    data[3] = sonars.getAvrDistance(1);
    
    lcd.debugOutputDisplay(60, "SONAR", data);
  
}

//##############################################################################################

void processSonars(bool isAverage)
{
    for (uint8_t i = 0; i < SONAR_NUM; i++)
        sonars.readDistance(i, isAverage);
}