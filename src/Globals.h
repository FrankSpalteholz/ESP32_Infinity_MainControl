//#############################################################################
// SONAR 
//#############################################################################

#define SONAR_NUM 2

#define SONAR_1_TRIG_PIN  5
#define SONAR_1_ECHO_PIN  18

#define SONAR_2_TRIG_PIN  16
#define SONAR_2_ECHO_PIN  17

#define SENSOR_READ_INTERVAL 30 // in ms
#define SONAR_DIST_MIN 5
#define SONAR_DIST_MAX 40

#define DATA_AVERAGE_COUNT 7


//#############################################################################
// LED
//#############################################################################

#define LED_STRIP_PIN     4
#define LED_STRIP_PIN2    19
#define LED_RING    23

#define NUM_STRIPS      2
#define NUM_STRIP_LEDS  104
#define NUM_RING_LEDS   12

#define BRIGHTNESS  64
#define LED_STRIP_TYPE    WS2812B
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 100

#define LED_STRIP_MAX_BRIGHTNESS 180 //HSV Model
#define LED_STRIP_MIN_BRIGHTNESS 40

#define LED_STRIP_LOWERBOUND 0
#define LED_STRIP_UPPERBOUND 104



//#############################################################################
// LCD
//#############################################################################


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's

#define I2C2_SDA 25
#define I2C2_SCL 26