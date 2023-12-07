#include <lib/wasm-functions/arduino/arduino.hpp>
// m3ApiRawFunction はただのマクロなので注意

/**
 * Math
 */
m3ApiRawFunction(m3_abs)
{
    m3ApiGetArg(int, x);
    m3ApiReturnType(int);

    m3ApiReturn(abs(x));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_constrain)
{
    m3ApiGetArg(int, x);
    m3ApiGetArg(int, a);
    m3ApiGetArg(int, b);
    m3ApiReturnType(int);

    m3ApiReturn(constrain(x, a, b));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_map)
{
    m3ApiGetArg(long, value);
    m3ApiGetArg(long, fromLow);
    m3ApiGetArg(long, fromHight);
    m3ApiGetArg(long, toLow);
    m3ApiGetArg(long, toHigh);
    m3ApiReturnType(long);

    m3ApiReturn(map(value, fromLow, fromHight, toLow, toHigh));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_max)
{
    m3ApiGetArg(long, x);
    m3ApiGetArg(long, y);
    m3ApiReturnType(long);

    m3ApiReturn(max(x, y));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_min)
{
    m3ApiGetArg(long, x);
    m3ApiGetArg(long, y);
    m3ApiReturnType(long);

    m3ApiReturn(min(x, y));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_pow)
{
    m3ApiGetArg(long, base);
    m3ApiGetArg(long, exponent);
    m3ApiReturnType(double);

    m3ApiReturn(pow(base, exponent));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_sq)
{
    m3ApiGetArg(int, x);
    m3ApiReturnType(int);

    // これ型の指定なしだけどどうする？
    m3ApiReturn(sq(x));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_sqrt)
{
    m3ApiGetArg(int, x);
    m3ApiReturnType(double);

    // これ型の指定なしだけどどうする？
    m3ApiReturn(sqrt(x));

    m3ApiSuccess();
}
/**
 * Analog I/O
 */
// AnalogReferenceはマイコンによって種類が違う
// uint8_t convertAnalogReferenceType(uint8_t mode)
// {
//     switch (mode)
//     {
//     case 0:
//         return DEFAURT;
//     case 1:
//         return INTERNAL;
//     case 2:
//         return INTERNAL1V1;
//     case 3:
//         return INTERNAL2V56;
//     case 4:
//         return EXTERNAL;
//     default:
//         // 正直これ以外がきたら，ちゃんと例外にして止めたい
//         return DEFAULT;
//     }
// }

// m3ApiRawFunction(m3_analogReference)
// {
//     m3ApiGetArg(uint32_t, type);
//     // returnはHIGHかLOWなので，HIGH:1 LOW:0にして返す

//     analogReference(type);

//     m3ApiSuccess();
// }

m3ApiRawFunction(m3_analogRead)
{
    m3ApiGetArg(uint8_t, pin);
    m3ApiReturnType(uint16_t);

    m3ApiReturn(analogRead(pin));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_analogWrite)
{
    m3ApiGetArg(uint8_t, pin);
    m3ApiGetArg(int, value);

    analogWrite(pin, value);

    m3ApiSuccess();
}

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
    m3ApiGetArg(uint8_t, pin);
    m3ApiReturnType(int);

    m3ApiReturn(digitalRead(pin));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_digitalWrite)
{
    m3ApiGetArg(uint8_t, pin);
    m3ApiGetArg(uint8_t, value);

    digitalWrite(pin, value);

    m3ApiSuccess();
}

m3ApiRawFunction(m3_pinMode)
{
    m3ApiGetArg(uint8_t, pin);
    m3ApiGetArg(uint8_t, mode);

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
    m3ApiReturnType(unsigned long);

    m3ApiReturn(micros());

    m3ApiSuccess();
}
m3ApiRawFunction(m3_millis)
{
    m3ApiReturnType(unsigned long);

    m3ApiReturn(millis());

    m3ApiSuccess();
}

M3Result mahiwa_LinkArduino(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *arduino = "arduino";
    /**
     * analog I/O
     */
    m3_LinkRawFunction(module, arduino, "analogRead", "v(i)", &m3_analogRead);
    // m3_LinkRawFunction(module, arduino, "analogReference", "v(ii)", &m3_analogReference);
    m3_LinkRawFunction(module, arduino, "analogWrite", "v(ii)", &m3_analogWrite);
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
