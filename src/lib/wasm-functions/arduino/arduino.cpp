#include <lib/wasm-functions/arduino/arduino.hpp>
// m3ApiRawFunction はただのマクロなので注意
/**
 * Random Numbers
 */
m3ApiRawFunction(m3_random)
{
    // https: // www.arduino.cc/reference/en/language/functions/random-numbers/random/
    // 公式リファレンスには
    // random(max)
    // random(min, max)
    // と引数の数に応じて内容が変わるが，コードを見る限り引数はvoidなので
    // random()として実装
    m3ApiReturnType(int32_t);

    m3ApiReturn(random());

    m3ApiSuccess();
}
m3ApiRawFunction(m3_randomSeed)
{
    m3ApiGetArg(int32_t, seed);

    randomSeed(seed);

    m3ApiSuccess();
}

/**
 * Characters
 */
// m3ApiRawFunction(m3_isAlpha)
// {
//     m3ApiGetArgMem(const uint8_t *, out);
//     m3ApiGetArg(uint32_t, out_len);
//     byte buff[out_len + 1];
//     memcpy(buff, out, out_len);
//     buff[out_len] = '\0';
//     m3ApiReturnType(boolean);
//     m3ApiReturn(isAlpha((int *)buff));
//     m3ApiSuccess();
// }
/**
 * Trigonometry
 */
m3ApiRawFunction(m3_cos)
{
    m3ApiGetArg(double_t, rad);
    m3ApiReturnType(double_t);

    m3ApiReturn(cos((double)rad));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_sin)
{
    m3ApiGetArg(double_t, rad);
    m3ApiReturnType(double_t);

    m3ApiReturn(sin((double)rad));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_tan)
{
    m3ApiGetArg(double_t, rad);
    m3ApiReturnType(double_t);

    m3ApiReturn(tan((double)rad));

    m3ApiSuccess();
}
/**
 * Math
 */
m3ApiRawFunction(m3_abs)
{
    m3ApiGetArg(int32_t, x);
    m3ApiReturnType(int32_t);

    m3ApiReturn(abs((int)x));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_constrain)
{
    m3ApiGetArg(int32_t, x);
    m3ApiGetArg(int32_t, a);
    m3ApiGetArg(int32_t, b);
    m3ApiReturnType(int32_t);

    m3ApiReturn(constrain((int)x, (int)a, (int)b));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_map)
{
    m3ApiGetArg(int32_t, value);
    m3ApiGetArg(int32_t, fromLow);
    m3ApiGetArg(int32_t, fromHight);
    m3ApiGetArg(int32_t, toLow);
    m3ApiGetArg(int32_t, toHigh);
    m3ApiReturnType(int32_t);

    m3ApiReturn(map((long)value, (long)fromLow, (long)fromHight, (long)toLow, (long)toHigh));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_max)
{
    m3ApiGetArg(int32_t, x);
    m3ApiGetArg(int32_t, y);
    m3ApiReturnType(int32_t);

    m3ApiReturn(max((long)x, (long)y));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_min)
{
    m3ApiGetArg(int32_t, x);
    m3ApiGetArg(int32_t, y);
    m3ApiReturnType(int32_t);

    m3ApiReturn(min((long)x, (long)y));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_pow)
{
    m3ApiGetArg(int32_t, base);
    m3ApiGetArg(int32_t, exponent);
    m3ApiReturnType(double_t);

    m3ApiReturn(pow((long)base, (long)exponent));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_sq)
{
    m3ApiGetArg(int32_t, x);
    m3ApiReturnType(int32_t);

    // これ型の指定なしだけどどうする？
    m3ApiReturn(sq(x));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_sqrt)
{
    m3ApiGetArg(int32_t, x);
    m3ApiReturnType(double_t);

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
    m3ApiGetArg(int32_t, pin);
    m3ApiReturnType(int32_t);

    // digitalReadがintでanalogReadがuint16_tなのは違和感だが、公式実装がそうなので合わせるしか無い
    m3ApiReturn(analogRead((uint8_t)pin));

    m3ApiSuccess();
}

m3ApiRawFunction(m3_analogWrite)
{
    m3ApiGetArg(int32_t, pin);
    m3ApiGetArg(int32_t, value);

    analogWrite((uint8_t)pin, (int)value);

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
    m3ApiGetArg(int32_t, pin);
    m3ApiReturnType(int32_t);

    m3ApiReturn(digitalRead((uint8_t)pin));

    m3ApiSuccess();
}
m3ApiRawFunction(m3_digitalWrite)
{
    m3ApiGetArg(int32_t, pin);
    m3ApiGetArg(int32_t, value);

    digitalWrite((uint8_t)pin, (uint8_t)value);

    m3ApiSuccess();
}

m3ApiRawFunction(m3_pinMode)
{
    m3ApiGetArg(int32_t, pin);
    m3ApiGetArg(int32_t, mode);

    pinMode((uint8_t)pin, convertPinMode((uint8_t)mode));

    m3ApiSuccess();
}

/**
 * Time
 */
m3ApiRawFunction(m3_delay)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(int64_t, ms);

    delay((uint32_t)ms);

    m3ApiSuccess();
}
m3ApiRawFunction(m3_delayMicroseconds)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(int64_t, us);

    delayMicroseconds((uint32_t)us);

    m3ApiSuccess();
}
m3ApiRawFunction(m3_micros)
{
    m3ApiReturnType(int64_t);

    m3ApiReturn(micros());

    m3ApiSuccess();
}
m3ApiRawFunction(m3_millis)
{
    m3ApiReturnType(int64_t);

    m3ApiReturn(millis());

    m3ApiSuccess();
}

M3Result mahiwa_LinkArduino(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *arduino = "arduino";
    // m3_LinkRawFunctionのi_signatureの書き方→https://github.com/wasm3/wasm3/issues/109
    // 厳密には正しくないが，WebAssemblyの型の制限もあるので，下記のように変換する
    // int,uint_8,uint_16,uint_32→i(i32)
    // uint64_t,long→I(i64)
    // float→f(f32)
    // double→F(f64)
    // void→v(void)

    /**
     * Random Numbers
     */
    // randomがWASIと競合するらしく，TinyGoではオーバーライドされて壊れるので，名前を変える
    m3_LinkRawFunction(module, arduino, "randomArduino", "i()", &m3_random);
    m3_LinkRawFunction(module, arduino, "randomSeed", "v(i)", &m3_randomSeed);
    /**
     * Trigonometry
     */
    m3_LinkRawFunction(module, arduino, "cos", "F(F)", &m3_cos);
    m3_LinkRawFunction(module, arduino, "sin", "F(F)", &m3_sin);
    m3_LinkRawFunction(module, arduino, "tan", "F(F)", &m3_tan);
    /**
     * Math
     */
    m3_LinkRawFunction(module, arduino, "abs", "i(i)", &m3_abs);
    m3_LinkRawFunction(module, arduino, "constrain", "i(iii)", &m3_constrain);
    m3_LinkRawFunction(module, arduino, "map", "i(iiiii)", &m3_map);
    m3_LinkRawFunction(module, arduino, "max", "i(ii)", &m3_max);
    m3_LinkRawFunction(module, arduino, "min", "i(ii)", &m3_min);
    // powがWASIと競合するらしく，TinyGoではオーバーライドされて壊れるので，名前を変える
    m3_LinkRawFunction(module, arduino, "powArduino", "F(ii)", &m3_pow);
    m3_LinkRawFunction(module, arduino, "sq", "i(i)", &m3_sq);
    // sqrtがWASIと競合するらしく，TinyGoではオーバーライドされて壊れるので，名前を変える
    m3_LinkRawFunction(module, arduino, "sqrtArduino", "F(i)", &m3_sqrt);
    /**
     * analog I/O
     */
    m3_LinkRawFunction(module, arduino, "analogRead", "i(i)", &m3_analogRead);
    // m3_LinkRawFunction(module, arduino, "analogReference", "v(ii)", &m3_analogReference);
    m3_LinkRawFunction(module, arduino, "analogWrite", "v(ii)", &m3_analogWrite);
    /**
     * Digital I/O
     */
    m3_LinkRawFunction(module, arduino, "digitalRead", "i(i)", &m3_digitalRead);
    m3_LinkRawFunction(module, arduino, "digitalWrite", "v(ii)", &m3_digitalWrite);
    m3_LinkRawFunction(module, arduino, "pinMode", "v(ii)", &m3_pinMode);

    /**
     * Time
     */
    m3_LinkRawFunction(module, arduino, "delay", "v(I)", &m3_delay);
    m3_LinkRawFunction(module, arduino, "delayMicroseconds", "v(I)", &m3_delayMicroseconds);
    m3_LinkRawFunction(module, arduino, "millis", "I()", &m3_millis);
    m3_LinkRawFunction(module, arduino, "micros", "I()", &m3_micros);

    return m3Err_none;
}
