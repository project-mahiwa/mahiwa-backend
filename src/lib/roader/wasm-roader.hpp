#pragma once
#include <Arduino.h>
#include <wasm3.h>
#include <lib/helper/wasm3-debugger.hpp>
#include <lib/roader/wasm-roader.hpp>
// #include <wasm/go-serial-print-and-arduino-delay.hpp>
#include <wasm/rust-serial-print-and-arduino-delay.hpp>

// 定義の追加
#include <lib/wasm-functions/arduino/arduino.hpp>
#include <lib/wasm-functions/arduino/serial.hpp>

// wasm3のexampleの値に従う
// m3_NewRuntimeの第2引数
// https://github.com/wasm3/wasm3-arduino/blob/main/src/m3_env.c#L170
#define WASM_STACK_SLOTS 1024
#define NATIVE_STACK_SIZE (16 * 1024)

void wasm_task(void *);
