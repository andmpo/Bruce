// Globals.h

//#define FGCOLOR TFT_PURPLE+0x3000
extern char16_t FGCOLOR;
#define ALCOLOR TFT_RED
#define BGCOLOR TFT_BLACK

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <functional>
#include <vector>
//#include <SPIFFS.h>
#include <LittleFS.h>
#include <NTPClient.h>
#include <Timezone.h>
#include <ESP32Time.h>
#include <EEPROM.h>
#include <ArduinoJson.h>

#if defined (STICK_C_PLUS) || defined (STICK_C)
  #include <AXP192.h>
  extern AXP192 axp192;
#endif

#if defined(CARDPUTER)
  #include <Keyboard.h>
  extern Keyboard_Class Keyboard;
#endif

#ifdef CYD
//#include <XPT2046_Touchscreen.h>
//#define XPT2046_IRQ 36
//#define XPT2046_MOSI 32
//#define XPT2046_MISO 39
//#define XPT2046_CLK 25
//#define XPT2046_CS 33
//extern SPIClass mySpi;
//extern XPT2046_Touchscreen ts;

extern uint16_t t_x ;
 
extern uint16_t t_y; 

#endif

#ifdef CYD
//#include <XPT2046_Touchscreen.h>
//#define XPT2046_IRQ 36
//#define XPT2046_MOSI 32
//#define XPT2046_MISO 39
//#define XPT2046_CLK 25
//#define XPT2046_CS 33
//extern SPIClass mySpi;
//extern XPT2046_Touchscreen ts;

extern uint16_t t_x ;
 
extern uint16_t t_y; 

#endif

// Declaração dos objetos TFT
extern TFT_eSPI tft;
extern TFT_eSprite sprite;
extern TFT_eSprite draw;

extern char timeStr[10];

extern bool clock_set;
extern time_t localTime;
extern struct tm* timeInfo;
extern ESP32Time rtc;
extern NTPClient timeClient;
extern Timezone myTZ;

extern int prog_handler;    // 0 - Flash, 1 - LittleFS, 2 - Download

extern bool sdcardMounted;  // informa se o cartão está montado ou não, sem precisar chamar a função setupSdCard

extern bool wifiConnected;  // informa se o wifi está ativo ou não

extern bool BLEConnected;  // informa se o BLE está ativo ou não

extern std::vector<std::pair<std::string, std::function<void()>>> options;

extern  String ssid;

extern  String pwd;

extern String fileToCopy;

extern int rotation;

extern uint8_t buff[4096];

extern const int bufSize;

extern bool returnToMenu; // variável para verificação e quebrar os loops

extern int IrTx;

extern int IrRx;

extern int RfTx;

extern int RfRx;

// Screen sleep control variables
extern unsigned long previousMillis;
extern bool isSleeping;
extern bool isScreenOff;
extern bool dimmer;
extern int dimmerSet;

void readFGCOLORFromEEPROM();

void backToMenu();

void updateTimeStr(struct tm timeInfo);

extern JsonDocument settings;
extern unsigned long dimmerTemp;
extern int dimmerSet;
extern int bright;
extern bool dimmer;
extern  String wui_usr;
extern  String wui_pwd;
extern int tmz;