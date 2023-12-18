#pragma once
//
#include <Arduino.h>
#include <wasm3.h>

//
#include <lib/helper/wasm3-debugger.hpp>

// 定義読み込み
#include <lib/wasm-functions/arduino/arduino.hpp>
#include <lib/wasm-functions/arduino/serial.hpp>
#ifdef USE_COREMARK
#include <lib/wasm-functions/mahiwa/coremark/coremark.hpp>
#endif

// wasm3のexampleの値に従う
// m3_NewRuntimeの第2引数
// https://github.com/wasm3/wasm3-arduino/blob/main/src/m3_env.c#L170
// ここの値を大きくするとRAMの小さいマイコンでFatal: m3_LoadModule memory allocation failed になる
#define WASM_STACK_SLOTS 2048
#define NATIVE_STACK_SIZE (32 * 2048)

void wasm_task(void *);
