#pragma once
#include <wasm3.h>
#include <Arduino.h>
#include <lib/wasm-function/arduino.hpp>

#define WASM_STACK_SLOTS 2048
#define NATIVE_STACK_SIZE (32 * 1024)

void wasm_task(void *);

#define FATAL_MSG(func, msg)              \
    {                                     \
        Serial.print("Fatal: " func " "); \
        Serial.println(msg);              \
        delay(1000);                      \
    }

#define FATAL(func, msg)     \
    {                        \
        FATAL_MSG(func, msg) \
        continue;            \
    }
