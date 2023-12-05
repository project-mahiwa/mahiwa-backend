#include <lib/wasm-functions/arduino/arduino.hpp>
// m3ApiRawFunction はただのマクロなので注意
m3ApiRawFunction(m3_arduino_delay)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(uint32_t, ms);
    delay(ms);
    m3ApiSuccess();
}

M3Result mahiwa_LinkArduino(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *arduino = "arduino";

    m3_LinkRawFunction(module, arduino, "delay", "v(i)", &m3_arduino_delay);

    return m3Err_none;
}
