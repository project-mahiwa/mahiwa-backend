#pragma once

#include <m3_env.h>
#include <Arduino.h>

// ↓マイコンの判定は自動だが，必要なライブラリはちゃんとインクルードしないとコンパイルでコケる
#ifdef M5CORE2
#include <M5Core2.h>
#endif
#ifdef M5ATOMS3
#include <M5AtomS3.h>
#endif

#define LGFX_AUTODETECT
#include <LovyanGFX.hpp>

M3Result mahiwa_LinkDisplay(IM3Runtime runtime);
