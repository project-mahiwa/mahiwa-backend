#pragma once

#include <m3_env.h>
#include <Arduino.h>

#ifdef ESP32
// 無線アンテナのノイズで乱数生成するのでWiFi有効にする必要がある
#include <WiFi.h>
#ifndef DR_REG_RNG_BASE
#define DR_REG_RNG_BASE 0x3ff75144
#endif
#endif

M3Result mahiwa_LinkESP32(IM3Runtime runtime);
