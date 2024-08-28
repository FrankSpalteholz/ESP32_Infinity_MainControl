// #include <Arduino.h>
// #include <elapsedMillis.h>

// elapsedMillis timerRandom;
// const long timerRandomDelay = 1000;

// elapsedMillis timerFalse;
// const long timerFalseDelay = 100;

// elapsedMillis timerTrue;
// const long timerTrueDelay = 100;

// int counterFalse = 0;
// int counterTrue = 0;

// bool state = false;

// void setup()
// {
//     Serial.begin(9600);

// }

// void loop()
// {

//     if(timerRandom > timerRandomDelay)
//     {
//         state = random(2);
//         Serial.println(state);
//         timerRandom = 0;
//     }


//     if(timerFalse > timerFalseDelay && state == false)
//     {   
//         counterFalse++;
//         counterTrue=0;
//         Serial.print(state);
//         Serial.print(":");
//         Serial.print(counterFalse);
//         Serial.print(":");
//         Serial.println(counterTrue);
//         timerFalse = 0;
//     }

//     if(timerTrue > timerTrueDelay && state == true)
//     {   
//         counterTrue++;
//         counterFalse =0;
//         Serial.print(state);
//         Serial.print(":");
//         Serial.print(counterFalse);
//         Serial.print(":");
//         Serial.println(counterTrue);
//         timerTrue = 0;
//     }

    






// }