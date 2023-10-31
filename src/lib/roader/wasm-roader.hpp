#pragma once
#include <Arduino.h>
#include <lib/wasm-functions/arduino.hpp>
#include <wasm3.h>

// wasm3のexampleの値に従う
// m3_NewRuntimeの第2引数
// https://github.com/wasm3/wasm3-arduino/blob/main/src/m3_env.c#L170
#define WASM_STACK_SLOTS 1024
#define NATIVE_STACK_SIZE (16 * 1024)

void wasm_task(void *);
