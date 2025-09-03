//----------------------------------------------------------
// #define DEBUG //DEBUG мод
//----------------------------------------------------------


//--MAX44009--<
#include <MAX44009.h> //MAX44009  https://github.com/dantudose/MAX44009
#include <Wire.h>

uint16_t SensorLux = 0;
uint16_t SensorLuxO;
bool errorSensorMAX44009 = 0;

MAX44009 light; 
//--MAX44009--||

//--Displays--<
#include <Arduino.h>
#include <SPI.h>             // Arduino SPI library

#include <TFT_eSPI.h>
#define display1_CS 14                                                                      // display 1             
#define display2_CS 13                                                                      // display 2
                                         
TFT_eSPI tft = TFT_eSPI();

#include "Free_Fonts.h"
#include "img_fon1.h"

//--Displays--||

//--WiFi--<
#include <WiFi.h> 
// #include <ESPmDNS.h>
// #include <NetworkUdp.h>
// #include <ArduinoOTA.h>

const char* WIFI_SSID = "8LLliKh814mH";
const char* WIFI_PASSWORD = "OkM3KI*eMy@B";

String clientId;
// String ipAddressS;
// String macAddressS;
// String SensorWiFi_RSSIS;

uint8_t SensorWiFi_RSSI = 0; //signal level
WiFiClient espClient;
uint32_t chipId; // Client ID
//--WiFi--||

//--LED--<
#include <FastLED.h>

#define DATA_PIN    19 
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    3
CRGB leds[NUM_LEDS];
// uint8_t ledBrightness = 150;
// uint8_t ledBrightnessO = 0;

bool blinkLed = false;

#define LED_CO2 0
#define LED_VOC 1
#define LED_PM 2

//--LED--||

//--BME280--<
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h> //BME280

bool errorSensorBME280 = 0;

uint16_t SensorPres = 0;
uint16_t SensorPresO;

uint16_t SensorAltitude = 0;

uint16_t SensorPresMbar = 0;

float TempKor = 0; //Temperature correction
float HumKor = 0; //Humidity correction

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C BME280
//--BME280--||

//--PMSA003--<
#include <PMserial.h> //PMSA003 https://github.com/avaldebe/PMserial

#define PMSA003_RX 33
#define PMSA003_TX 32

//PMSA003
uint16_t SensorPm25 = 0;
uint16_t SensorPm25O;
uint16_t SensorPm10 = 0;
uint16_t SensorPm10O;
uint16_t SensorPm01 = 0;
uint16_t SensorPm01O;

bool errorSensorPMSA003 = 0;

SerialPM pms(PMSA003, PMSA003_RX, PMSA003_TX); 
//--PMSA003--||

//--SCD30--<
#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30
SCD30 airSensor;

float SensorHum = 0;
float SensorHumO;

float SensorTemp = 0;
float SensorTempO;

uint16_t SensorCO2 = 0;
uint16_t SensorCO2O;

bool errorSensorSCD30 = 0;
//--SCD30--||

//--SGP41--<
#include <Arduino.h>
#include <NOxGasIndexAlgorithm.h>
#include <SensirionI2CSgp41.h>
#include <VOCGasIndexAlgorithm.h>

SensirionI2CSgp41 sgp41;

VOCGasIndexAlgorithm voc_algorithm;
NOxGasIndexAlgorithm nox_algorithm;

uint16_t SensorVoc = 0;
uint16_t SensorVocO;

uint16_t SensorNox = 0;
uint16_t SensorNoxO;

bool errorSensorSGP41 = 0;

#ifdef DEBUG
char errorMessage[64];
#endif
// time in seconds needed for NOx conditioning
uint8_t conditioning_s = 10;
//--SGP41--||

//--NTP--<
#include "time.h"
#define SNTP_GET_SERVERS_FROM_DHCP 1
#include <esp_sntp.h>

//The whole world pool.ntp.org
//Asia asia.pool.ntp.org
//Europe europe.pool.ntp.org <----
//North America north-america.pool.ntp.org
//Oceania oceania.pool.ntp.org
//South America south-america.pool.ntp.org

const char* ntpServer1 = "europe.pool.ntp.org";
const char* ntpServer2 = "time.google.com";
const long  gmtOffset_sec = 1 * 60 * 60; //+1 Beograd
const int   daylightOffset_sec = 3600;

// String timeCL = "00:00:00";

char daysOfTheWeek[7][5] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; // Two-dimensional array days of the week
String months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"}; // One-dimensional array months

uint8_t timS = 00;

uint8_t timM = 00;
uint8_t timMo = 99;
uint8_t timH = 00;
uint8_t timHo = 99;

uint8_t timDate = 00;
uint8_t timDateO = 00;

uint8_t timWeek = 00;
uint8_t timWeekO = 8;

uint8_t timMonth = 00;
uint8_t timMonthO = 13;

uint8_t timYear = 00;
uint8_t timYearO = 00;

//--NTP--||

//--Home Assistant--<
#include <ArduinoHA.h>  //https://github.com/dawidchyrzynski/arduino-home-assistant && https://github.com/knolleary/pubsubclient
/*
Icons https://pictogrammers.com/library/mdi/
Device Class https://www.home-assistant.io/integrations/sensor
Binary Sensor https://www.home-assistant.io/integrations/binary_sensor/#device-class
https://dawidchyrzynski.github.io/arduino-home-assistant/index.html
*/

//MQTT
#define BROKER_ADDR     IPAddress(192,168,1,13)
#define BROKER_USERNAME     "mqtt" // replace with your credentials
#define BROKER_PASSWORD     "mqtt"

HADevice device;
HAMqtt mqtt(espClient, device);

// bool butDefault = false;
bool AlarmBuzzer = true;
bool AlarmVibration = true;

//AdaptiveBright
bool AdaptiveBright = true;
uint8_t AdaptiveBrightMax = 150;
uint8_t AdaptiveBrightMin = 30;
uint8_t NotAdaptiveBright = 50;
//CO2
uint16_t CO2GreenZone = 1000;
uint16_t CO2OrangeZone = 2000;
uint16_t CO2DangerZone = 2500;
//NOx
uint16_t NOxGreenZone = 10;
uint16_t NOxOrangeZone = 100;
uint16_t NOxDangerZone = 200;
//VOC
uint16_t VOCGreenZone = 100;
uint16_t VOCOrangeZone = 200;
uint16_t VOCDangerZone = 300;
//PM2.5
uint16_t PM25GreenZone = 50;
uint16_t PM25OrangeZone = 100;
uint16_t PM25DangerZone = 150;

// bool startSendPar = true;

//---EEPROM---
#include <EEPROM.h>

bool defMemW = false; //Write default settings on startup

//--EEPROM--||

//---Sensors HA---
HASensorNumber signalSensor("signal_strength", HASensorNumber::PrecisionP0);//+
HASensorNumber luxSensor("illuminance", HASensorNumber::PrecisionP0);//+
HASensorNumber co2Sensor("carbon_dioxide", HASensorNumber::PrecisionP0);//+

HASensorNumber VOCindexSensor("VOC_index", HASensorNumber::PrecisionP0);//+
// HASensorNumber VOCSensor("VOC", HASensorNumber::PrecisionP0);//+

HASensorNumber NOxindexSensor("NOx_index", HASensorNumber::PrecisionP0);//+
// HASensorNumber NOxSensor("NOx", HASensorNumber::PrecisionP0);//+

HASensorNumber pm1Sensor("pm1", HASensorNumber::PrecisionP0);//+
HASensorNumber pm25Sensor("pm25", HASensorNumber::PrecisionP0);//+
HASensorNumber pm10Sensor("pm10", HASensorNumber::PrecisionP0);//+

HASensorNumber presSensor("atmospheric_pressure", HASensorNumber::PrecisionP0);//+
// HASensorNumber approxSensor("approx_altitude", HASensorNumber::PrecisionP0);//+
HASensorNumber humSensor("humidity", HASensorNumber::PrecisionP1);//+
HASensorNumber tempSensor("temperature", HASensorNumber::PrecisionP1);//+

HAButton buttonDefault("default");//++
HAButton buttonRestart("restart");//++
//AdaptiveBright

HANumber numberAdaptiveBrightMax("adaptive_bright_max");//+
HANumber numberAdaptiveBrightMin("adaptive_bright_min");//+
HANumber numberNotAdaptiveBright("not_adaptive_bright");//+

HANumber numberCO2GreenZone("co2_greenzone");
HANumber numberCO2OrangeZone("co2_orangezone");
HANumber numberCO2DangerZone("co2_dangerzone");

HANumber numberNOxGreenZone("nox_greenzone");
HANumber numberNOxOrangeZone("nox_orangezone");
HANumber numberNOxDangerZone("nox_dangerzone");

HANumber numberVOCGreenZone("voc_greenzone");
HANumber numberVOCOrangeZone("voc_orangezone");
HANumber numberVOCDangerZone("voc_dangerzone");

HANumber numberPM25GreenZone("pm25_greenzone");
HANumber numberPM25OrangeZone("pm25_orangezone");
HANumber numberPM25DangerZone("pm25_dangerzone");

// HASelect selectBuzzer("sound");//++
// HASelect selectVibration("vibration");//++
// HASelect selectAdaptiveBright("adaptive_bright");//+

HASwitch switchBuzzer("alarm_sound");
HASwitch switchVibration("alarm_vibration");
HASwitch switchAdaptiveBright("adaptive_bright");
//--Home Assistant--||

// #define LED_BUILTIN 1

void setup() {

  #ifdef DEBUG
  Serial.begin(115200);
  #endif
  
  Wire.begin();
//LED на плате 
  // pinMode(LED_BUILTIN, OUTPUT);
  // digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  // delay(1000);                      // wait for a second
  // digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

  memStart();

  startBME280();  //start BME280
  startMAX44009();  //start MAX44009
  startSGP41();

  startLED(); //start LED
  startDisplays();  //start Displays

  ntpStart();
  startWIFI(); //start WIFI
  // ArduinoOTA.begin();

  pms.init(); //start PMSA003
  startHA();
  delay(1000);
  dataBME280();
  dataSGP41();
  startSCD30(); //start SCD30

  timer1Start(); //start timer
  timer2Start(); //start timer
  timer3Start(); //start timer

  testLED();  //test led onli start
}

void loop() {
  // ArduinoOTA.handle();
  mqtt.loop();
  // startSendHA();

  timer1Data();
  timer2Data();
  timer3Data();
}