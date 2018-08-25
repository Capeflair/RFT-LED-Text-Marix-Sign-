#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <gamma.h>
#include <ArduinoJson.h>
#include <TimeLib.h>
#include <time.h>


#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define PIN 13

const char* def_ssid_1 = "RFT";
const char* def_password_1 = "freetankwa";

const char* def_ssid = "ICSASA LICENCING DEPARTMENT";
const char* def_password = "allwehearisradiogaga";

ESP8266WebServer server(80); //creating the server at port 80


Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(28, 7, PIN,//28 leds long by 7 high rft sign
                            NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB            + NEO_KHZ400);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(196, PIN, NEO_GRB + NEO_KHZ800);




const static int MAX_SCROLL_ITEMS = 20;
const static int WIFI_START_UP_TIME = 5000;

typedef struct {
	// delay values
	uint16_t delay;
	// value returned by the millis() function
	// in the previous run() call
	long unsigned int prev_millis;
  // Time at which the scroll item is added
  long unsigned int init_millis;
  // Time at which the scroll item should be stopped
  long unsigned int total_millis;
  // String to be shown
  String scroll_txt;
  // Colour of string to be shown
  // uint16_t colour;
  uint8_t red;
  uint8_t green;
  uint8_t blue;
	// which timers are enabled
  String animation;
  // number of cycles
  uint8_t cycles;
} Scroll_Item;

Scroll_Item scroll_items[MAX_SCROLL_ITEMS];
int show_scroll_item = -1;
int total_scroll_items = -1;
int cursor_position = matrix.width();


int animation_int_1 = 0;
int animation_int_2 = 0;
uint16_t animation_int16_1 = 0;
uint16_t animation_int16_2 = 0;

bool wifi_waiting_for_connection = false;
bool wifi_waiting_for_old_connection = false;

int wifi_lost_connection_count = 0;
bool wifi_default_connection_LIVE = true;

long unsigned int wifi_prev_millis;
long unsigned int wifi_operation_delay = 150;


bool timeIsSet = false;

const String fourletterwords[] = {
  "DICK","LOVE","HATE","HEAD","TOAD","DAYS","DAZE","TIME","RICE","FUCK","CUNT","MOOP","ARSE","KNOB"
  };

#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0])))

void setup() {
  Serial.begin(115200);  
  wifi_prev_millis = millis();
  Connect_to_last_wifi();
  Setup_Wifi();
  Setup_Matrix();
  Setup_Sign_Strings();
  show_scroll_item = 0; // this starts sign
  Change_Brightness(255);
}

void loop() {
  run_timer();
}
