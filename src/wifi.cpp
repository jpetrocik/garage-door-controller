/**
 * 1. Attempts to connect to the provided SSID and turns on AP.
 * 2. If no SSID is provided turn on only the AP
 * 3. Once connected to the SSID, AP is turned off
 * 4. If connection is lost for more then 5 minutes, turns on AP
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "configuration.h"

DeviceConfig *wifi_deviceConfig;
WiFiEventHandler onStationModeGotIPEvent;

void onStationModeGotIP(const WiFiEventStationModeGotIP &evt)
{
  wifi_deviceConfig->stopTicker();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void enableApMode()
{
  WiFi.disconnect();

  wifi_deviceConfig->startTicker(0.25);
  WiFi.mode(WIFI_AP);

  char apName[15];
  uint32_t chipId = ESP.getChipId();
  sprintf(apName, "garage-%d", (chipId % 10000));
  Serial.print("Starting AP: ");
  Serial.println(apName);
  WiFi.softAP(apName);
}

void wifiSetup(DeviceConfig *deviceConfig)
{
  wifi_deviceConfig = deviceConfig;

  if (strlen(wifi_deviceConfig->wifiSsid) > 0)
  {
    wifi_deviceConfig->startTicker(0.5);

    Serial.print("Attempting to connect ");
    Serial.println(wifi_deviceConfig->wifiSsid);
    onStationModeGotIPEvent = WiFi.onStationModeGotIP(onStationModeGotIP);
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifi_deviceConfig->wifiSsid, wifi_deviceConfig->wifiPassword);
  }
  else
  {
    wifi_deviceConfig->startTicker(0.25);
    WiFi.mode(WIFI_AP);

    char apName[15];
    uint32_t chipId = ESP.getChipId();
    sprintf(apName, "garage-%d", (chipId % 10000));
    Serial.print("Starting AP: ");
    Serial.println(apName);
    WiFi.softAP(apName);
  }
}

void wifiLoop()
{
}
