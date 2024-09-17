//#############################################################################
// SONAR 
//#############################################################################

#define SONAR_NUM 4

#define SONAR_1_TRIG_PIN  2
#define SONAR_1_ECHO_PIN  15

#define SONAR_2_TRIG_PIN  16
#define SONAR_2_ECHO_PIN  4

#define SONAR_3_TRIG_PIN  19
#define SONAR_3_ECHO_PIN  18

#define SONAR_4_TRIG_PIN  5
#define SONAR_4_ECHO_PIN  17

#define SONAR_READ_INTERVAL 30 

#define SONAR_DIST_MIN 5
#define SONAR_DIST_MAX 30

#define SONAR_STATE_CHANGE_THRESH 4
#define SONAR_RANGE_COUNTER_MAX 250

#define SONAR_DIST_AVERAGE_COUNT 4

//#############################################################################
// LED STRIPS
//#############################################################################

#define LED_PIN_A1      23
#define LED_PIN_A2      27
#define LED_PIN_A3      33
#define LED_PIN_A4      14

#define LED_PIN_B1      25
#define LED_PIN_B2      26
#define LED_PIN_B3      32
#define LED_PIN_B4      12

#define LED_PIN_C1      0

#define STRIP_QUAD_COUNT        2
#define STRIPS_PER_LOOP_COUNT   4
#define LED_STRIP_COUNT_A_B     62
#define LED_STRIP_COUNT_C       104

#define BRIGHTNESS  200
#define LED_STRIP_TYPE    WS2812B
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 100

#define LED_STRIP_MAX_BRIGHTNESS 180 //HSV Model
#define LED_STRIP_MIN_BRIGHTNESS 40

//#############################################################################
// OLED 
//#############################################################################


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's

#define I2C2_SDA 21
#define I2C2_SCL 22

#define SCREEN_UPDATE_INTERVAL 20;