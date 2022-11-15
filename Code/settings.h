//####################################################################################################################################################

// Adjust program settings here:
// #############################
#define BRIGHTNESS      128     // Brightness between 0 - 255 (128 was close to the limit for my USB port power outlet... Do not set this to high on your PC USB port...)
#define BRIGHTNESS_OFF  0       // Brightness between 0 - 255 when using night mode is used
#define NIGHTMODE_USED  1       // Turns Night Mode on (1) or off (0) after the set times below:
int NIGHTMODE_START = 22;       // Night Mode Start time: At the default 22 o'clock (value 22) the brigtness will be set to the value BRIGHTNESS_OFF = 0
int NIGHTMODE_END   = 7;        // Night Mode End time:   At the default  7 o'clock (value 7), the brigtness will be set to the value BRIGHTNESS = 128
#define RESETWIFI       0       // To DELETE the WiFi settings set to "1" and upload the sketch to the ESP. Set to "0" again and upload once more
#define SHOWSTARTTEXTS  1       // Show (1) or do not show (0) the "AWSW" "MAZE" "CLOCK" text at startup

// Color of the MAZE numbers:
#define COL_MAZE_NUMBER   COL_MAZE_CYAN   // Color value of the MAZE numbers (RGB = Red, Green, Blue)  --> 0, 255, 128 is CYAN = COL_MAZE_CYAN
#define COL_MAZE_RUNNER   COL_MAZE_RED  // Color value of the MAZE numbers (RGB = Red, Green, Blue)    --> 255, 0, 0 is RED    = COL_MAZE_RED
// Available colors as variable: 
// COL_MAZE_RED      = Color RED
// COL_MAZE_GREEN    = Color GREEN
// COL_MAZE_BLUE     = Color BLUE
// COL_MAZE_YELLOW   = Color YELLOW
// COL_MAZE_CYAN     = Color CYAN
// COL_MAZE_OFF      = Set LEDs OFF

// Some functions for testing:
// ###########################
#define USELEDTEST      0       // Show the RGB LED test on startup
#define USELETTERTEST   0       // Show the digits letter and runner test on startup
#define TIMEDATESERIAL  0       // Show current time and date in serial monitor

//####################################################################################################################################################

// LED matrix settings:
// ###################

#define PIN           D2      // D1 mini LED output pin
#define NUMPIXELS     256     // Number of pixels on the LED matrix
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//####################################################################################################################################################

// Adjust time settings here only:
// ###############################

// NTP Servers:
static const char ntpServerName[] = "us.pool.ntp.org";
//static const char ntpServerName[] = "time.nist.gov";
//static const char ntpServerName[] = "time-a.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-b.timefreq.bldrdoc.gov";
//static const char ntpServerName[] = "time-c.timefreq.bldrdoc.gov";

const int timeZone = +2;    // Central European Time
//const int timeZone = -5;  // Eastern Standard Time (USA)
//const int timeZone = -4;  // Eastern Daylight Time (USA)
//const int timeZone = -8;  // Pacific Standard Time (USA)
//const int timeZone = -7;  // Pacific Daylight Time (USA)

//####################################################################################################################################################
