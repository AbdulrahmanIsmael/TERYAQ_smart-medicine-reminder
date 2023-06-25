#include <EEPROM.h>                 //SYSTEM PARAMETER  - EEPROM Library (By: Arduino)
#include <Wire.h>                   //SYSTEM PARAMETER  - WIRE Library (By: Arduino)
#include <SPI.h>                    //SYSTEM PARAMETER  - SPI Library (By: Arduino)
#include <WiFiManager.h>            //SYSTEM PARAMETER  - WiFi Library 
#include <SoftwareSerial.h>         //SYSTEM PARAMETER
#include <ESP32Time.h>              //SYSTEM PARAMETER
ESP32Time rtc;
#include <LiquidCrystal_I2C.h>      //SYSTEM PARAMETER  - ESP32 LCD Compatible Library (By: Robojax)
LiquidCrystal_I2C lcd(0x27,16,2);   //SYSTEM PARAMETER  - Configure LCD RowCol Size and I2C Address
SoftwareSerial gsmSerial(13, 12);   // RX, TX

// Define the fire base
#include <Firebase_ESP_Client.h>
#include <string>
#include "addons/TokenHelper.h"     //Provide the token generation process info.
#include "addons/RTDBHelper.h"      //Provide the RTDB payload printing info and other helper functions.
#define API_KEY "AIzaSyCJpWGYVnGrKoHyHP5eHmVk9uIBptHw3dg"   // Insert Firebase project API Key
#define DATABASE_URL "https://test-1313a-default-rtdb.firebaseio.com/"   // Insert RTDB URLefine the RTDB URL */
FirebaseData fbdo;                  // Define Firebase Data object.
FirebaseAuth auth;                  // Define firebase authentication.
FirebaseConfig config;              // Definee firebase configuration.

TaskHandle_t Core2;                 //SYSTEM PARAMETER  - Used for the ESP32 dual core operation


//====================================== USER PARAMETERS ===========================================//

#define stepPin         33          //SYSTEM PARAMETER - Stepper Driver Step Pin
#define dirPin          32          //SYSTEM PARAMETER - Stepper Driver Direction Pin
#define LED             2           //SYSTEM PARAMETER - LED Indicator GPIO Pin
#define Hall_sensor     35          //SYSTEM PARAMETER - Hall GPIO Pin
#define IR              34          //SYSTEM PARAMETER - IR GPIO Pin
#define buttonLeft      18          //SYSTEM PARAMETER - 
#define speaker         25          //SYSTEM PARAMETER - Speaker Enable Pin
#define buttonRight     19          //SYSTEM PARAMETER -
#define buttonBack      5           //SYSTEM PARAMETER - 
#define buttonSelect    23          //SYSTEM PARAMETER -
#define RXD2            16          //SYSTEM PARAMETER - voice recieve
#define TXD2            17          //SYSTEM PARAMETER - voice send


//========================================= WiFi SSID ==============================================//
char
ssid[] = "",                        //   USER PARAMETER - Enter Your WiFi SSID
pass[] = "";                        //   USER PARAMETER - Enter Your WiFi Password

const char* ntpServer = "europe.pool.ntp.org";
long  gmtOffset_sec = 7200;         //GMT+2:00 
const int   daylightOffset_sec = 0;
struct tm timeinfo;
struct tm timelcd;
WiFiManager wm;


//====================================== USER PARAMETERS ==========================================//
int
phone                   = 1201290445,
testInterval=1000,
millisLCDInterval       = 800,         //  USER PARAMETER - Time Interval Refresh Rate For LCD Display (ms)
millisWiFiInterval      = 1000,        //  USER PARAMETER - Time Interval Refresh Rate For WiFi Telemetry (ms)
millisStepperInterval   = 5000,        //  USER PARAMETER - Time Delay To Reset After Take Medicine
millisResetDelay        = 20000,       //  USER PARAMETER - Time Delay To Reset The Disk
hangUpInterval          = 59000,       //  USER PARAMETER - Time Delay To End Call
millisBlinkOnDelay      = 500,         //  USER PARAMETER - duration of led ON
millisBlinkOffDelay     = 1000,        //  USER PARAMETER - duraton of led OFF
backlightSleepMode      = 0,           //  USER PARAMETER - 0 = Never, 1 = 10secs, 2 = 5mins, 3 = 1hr, 4 = 6 hrs, 5 = 12hrs, 6 = 1 day, 7 = 3 days, 8 = 1wk, 9 = 1month
baudRate                = 500000;      //  USER PARAMETER - USB Serial Baud Rate (bps)

const long sendDataIntervalMillis = 300000; // gets/stores data from firebase database every 60 seconds.

//===================================== SYSTEM PARAMETERS =========================================//
bool signupOK = false;               // Boolean variable for sign in status.
bool
dataSend              = 0,           // SYSTEM PARAMETER -
ledState              = 0,           // SYSTEM PARAMETER -
buttonRightCommand    = 0,           // SYSTEM PARAMETER - 
buttonLeftCommand     = 0,           // SYSTEM PARAMETER - 
buttonBackCommand     = 0,           // SYSTEM PARAMETER - 
buttonSelectCommand   = 0,           // SYSTEM PARAMETER -
settingMode           = 0,           // SYSTEM PARAMETER -
setMenuPage           = 0,           // SYSTEM PARAMETER -
boolTemp              = 0,           // SYSTEM PARAMETER -
call                  = 0,           // SYSTEM PARAMETER -  
makeCall              = 0,           // SYSTEM PARAMETER -  
idle                  = 0,           // SYSTEM PARAMETER -  
confirmationMenu      = 0;           // SYSTEM PARAMETER -      
char AI;            
int
menuPage              = 0,           // SYSTEM PARAMETER -
subMenuPage           = 0,           // SYSTEM PARAMETER -
takeTimes1            = 3,           // SYSTEM PARAMETER - 
takeTimes2            = 3,           // SYSTEM PARAMETER - 
takeTimes3            = 3,           // SYSTEM PARAMETER - 
takeTimes4            = 3,           // SYSTEM PARAMETER - 
actHour               = 0,           // SYSTEM PARAMETER - 
hour1                 = 2,           // SYSTEM PARAMETER - 
hour2                 = 5,           // SYSTEM PARAMETER - 
hour3                 = 8,           // SYSTEM PARAMETER - 
hour4                 = 9,           // SYSTEM PARAMETER - 
actMin                = 0,           // SYSTEM PARAMETER - 
min1                  = 20,          // SYSTEM PARAMETER - 
min2                  = 0,           // SYSTEM PARAMETER - 
min3                  = 0,           // SYSTEM PARAMETER - 
min4                  = 0,           // SYSTEM PARAMETER - 
angle                 = 0,           // SYSTEM PARAMETER - 
actSec                = 0,           // SYSTEM PARAMETER - 
hand                  = 0,           // SYSTEM PARAMETER - 
box                   = 0;           // SYSTEM PARAMETER - 
unsigned long 
sendDataPrevMillis    = 0,           //SYSTEM PARAMETER - 
currentLCDMillis      = 0,           //SYSTEM PARAMETER - 
currentLCDBackLMillis = 0,           //SYSTEM PARAMETER - 
currentWiFiMillis     = 0,           //SYSTEM PARAMETER - 
currentMenuSetMillis  = 0,           //SYSTEM PARAMETER - 
currentStepperMillis  = 0,           //SYSTEM PARAMETER - 
currentResetMillis    = 0,           //SYSTEM PARAMETER - 
currentGsmMillis      = 0,           //SYSTEM PARAMETER - 
prevWiFiMillis        = 0,           //SYSTEM PARAMETER -
prevLCDMillis         = 0,           //SYSTEM PARAMETER -
prevLCDBackLMillis    = 0,           //SYSTEM PARAMETER -
prevStepperMillis     = 0,           //SYSTEM PARAMETER - 
prevResetMillis       = 0,           //SYSTEM PARAMETER - 
prevGsmMillis         = 0,           //SYSTEM PARAMETER - 
prevBlinkMillis       = 0;           //SYSTEM PARAMETER - 

//======================================== MAIN PROGRAM ===============================================//
// The codes below contain all the system processes for the Reminder firmware. Most of them are called //
// from the 5 .ino tabs. The codes are too long, Arduino tabs helped me a lot in organizing them.      //
// The firmware runs on two cores of the Arduino ESP32 as seen on the two separate pairs of void       //
// setups and loops. The xTaskCreatePinnedToCore() freeRTOS function allows you to access the          //
// unused ESP32 core through Arduino. Yes it does multicore processes simultaneously!                  // 
//=====================================================================================================//

//================= CORE0: SETUP (DUAL CORE MODE) =====================//
void coreTwo(void * pvParameters){
 setupWiFi();                                              //TAB#3 - WiFi Initialization
//================= CORE0: LOOP (DUAL CORE MODE) ======================//
  while(1){
    Wireless_Telemetry();                                  //TAB#3 - Wireless telemetry  
  }
}

//================== CORE1: SETUP (DUAL CORE MODE) ====================//
void setup() {

  //SERIAL INITIALIZATION          
  Serial.begin(baudRate);                                   //Set serial baud rate
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);              //Set serial2 with AI Arduino
  Serial.println("> Serial Initialized");                   //Startup message
  gsmSerial.begin(9600);                                    //Set SoftWare serial baud rate for GSM
  
  //GPIO PIN INITIALIZATION
  pinMode(stepPin,OUTPUT);                          
  pinMode(dirPin,OUTPUT);
  pinMode(LED,OUTPUT); 
  pinMode(speaker,OUTPUT); 
  pinMode(Hall_sensor,INPUT);
  pinMode(IR,INPUT);
  pinMode(buttonLeft,INPUT); 
  pinMode(buttonRight,INPUT); 
  pinMode(buttonBack,INPUT); 
  pinMode(buttonSelect,INPUT); 
  
  //ENABLE DUAL CORE MULTITASKING
  xTaskCreatePinnedToCore(coreTwo,"coreTwo",10000,NULL,0,&Core2,0);
  
  //INITIALIZE AND LIOAD FLASH MEMORY DATA
  EEPROM.begin(512);
  Serial.println("> FLASH MEMORY: STORAGE INITIALIZED");  //Startup message 
  loadSettings();                                         //Load stored settings from flash memory       
  Serial.println("> FLASH MEMORY: SAVED DATA LOADED");    //Startup message 

  //LCD INITIALIZATION
  lcd.begin();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("  T E R Y A Q   ");
  lcd.setCursor(0,1);
  lcd.print("   Smile dude   ");
  delay(1500);
  lcd.clear();

  //Reset the position of box
  digitalWrite(dirPin,HIGH);          // Enables the motor to move in a particular direction
  while(digitalRead(Hall_sensor) != HIGH){
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(700);           // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(700);
  }

  Serial.println("> Box HAS INITIALIZED");                //Startup message

}

void loop() {
  Stepper_Process();
  Time_Table();
  LCD_Menu();
  gsmModule();
  AIDetect();
  delay(1);
}
