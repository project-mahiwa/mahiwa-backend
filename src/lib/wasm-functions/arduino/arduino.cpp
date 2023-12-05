#include <lib/wasm-functions/arduino/arduino.hpp>
// m3ApiRawFunction はただのマクロなので注意

/**
 * Digital I/O
 */
// pinModeで型定義したいが，怒られるので本体のuint8_tにして，使うときにcastする
uint8_t convertPinMode(uint8_t mode)
{
    switch (mode)
    {
    case 0:
        return INPUT;
    case 1:
        return OUTPUT;
    case 2:
        return INPUT_PULLUP;
    default:
        // 正直これ以外がきたら，ちゃんと例外にして止めたい
        return INPUT;
    }
}

m3ApiRawFunction(m3_digitalRead)
{
    m3ApiGetArg(uint32_t, pin);
    // returnはHIGHかLOWなので，HIGH:1 LOW:0にして返す
    m3ApiReturnType(uint8_t);

    m3ApiReturn(digitalRead(pin) == HIGH ? 1 : 0);

    m3ApiSuccess();
}
m3ApiRawFunction(m3_digitalWrite)
{
    m3ApiGetArg(uint32_t, pin);
    m3ApiGetArg(uint32_t, value);

    digitalWrite(pin, value);

    m3ApiSuccess();
}

m3ApiRawFunction(m3_pinMode)
{
    m3ApiGetArg(uint32_t, pin);
    m3ApiGetArg(uint32_t, mode);

    typedef uint8_t PinMode;
    pinMode(pin, (PinMode)convertPinMode(mode));

    m3ApiSuccess();
}

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
     * Digital I/O
     */
    m3_LinkRawFunction(module, arduino, "digitalRead", "v(i)", &m3_digitalRead);
    m3_LinkRawFunction(module, arduino, "digitalWrite", "v(ii)", &m3_digitalWrite);
    m3_LinkRawFunction(module, arduino, "pinMode", "v(ii)", &m3_pinMode);

    /**
     * Time
     */
    m3_LinkRawFunction(module, arduino, "delay", "v(i)", &m3_delay);
    m3_LinkRawFunction(module, arduino, "delayMicroseconds", "v(i)", &m3_delayMicroseconds);
    m3_LinkRawFunction(module, arduino, "millis", "v(i)", &m3_millis);
    m3_LinkRawFunction(module, arduino, "micros", "v(i)", &m3_micros);

    return m3Err_none;
}
