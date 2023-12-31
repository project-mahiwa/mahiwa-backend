#pragma once

#include <m3_env.h>
#include <Arduino.h>

#if defined(ESP32) || defined(PICOW)
#include <WiFi.h>
#include <WiFiClient.h>
#endif

#ifdef ESP32
// WebServer.hはarduino-esp32に内蔵されているが，arduino-rp2040には無い
#include <WebServer.h>
#endif

M3Result mahiwa_LinkNetwork(IM3Runtime runtime);
