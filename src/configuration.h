#ifndef Configuration_h
#define Configuration_h

#include <Arduino.h>
#include <Ticker.h>

#define CLIENT_ID "garage-door-%i"
#define RELAY_PIN 14
#define LED_PIN 2
#define BUTTON_PIN 0
#define DOOR_STATUS_PIN 12
// #define DOOR_CLOSE 0
// #define DOOR_OPEN 1

#define RELAY_CLOSE 1
#define RELAY_OPEN 0

#define LED_ON 1
#define LED_OFF 0

#define MQTT_ENABLED
#define WEBSERVER_ENABLED
#define OTA_ENABLED
#define MDNS_ENABLED

struct DeviceConfig
{
  char deviceName[20] = "door";
  char roomName[20] = "garage";
  char locationName[20] = "house";
  char hostname[41] = "garage-door";
  char mqttHost[50];
  char wifiSsid[25];
  char wifiPassword[50];
  boolean dirty = false;
  void (*startTicker)(float seconds);
  void (*stopTicker)();
};

#endif
