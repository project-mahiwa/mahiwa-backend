#include <lib/wasm-functions/arduino/arduino.hpp>
// m3ApiRawFunction はただのマクロなので注意

/**
 * Time
 */
m3ApiRawFunction(m3_delay)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(uint32_t, ms);
    delay(ms);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_delayMicroseconds)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(uint32_t, us);
    delayMicroseconds(us);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_micros)
{
    m3ApiReturnType(uint32_t);
    m3ApiReturn(micros());
    m3ApiSuccess();
}
m3ApiRawFunction(m3_millis)
{
    m3ApiReturnType(uint32_t);
    m3ApiReturn(millis());
    m3ApiSuccess();
}

M3Result mahiwa_LinkArduino(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *arduino = "arduino";

    /**
     * Time
     */
    m3_LinkRawFunction(module, arduino, "delay", "v(i)", &m3_delay);
    m3_LinkRawFunction(module, arduino, "delayMicroseconds", "v(i)", &m3_delayMicroseconds);
    m3_LinkRawFunction(module, arduino, "millis", "v(i)", &m3_millis);
    m3_LinkRawFunction(module, arduino, "micros", "v(i)", &m3_micros);

    return m3Err_none;
}
