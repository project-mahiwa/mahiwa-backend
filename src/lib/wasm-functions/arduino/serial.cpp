#include <lib/wasm-functions/arduino/serial.hpp>
// printlnはprintと改行をライブラリで組み合わせ作るようにする
m3ApiRawFunction(m3_print)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArgMem(const uint8_t *, out);
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(uint32_t, out_len);
    byte buff[out_len + 1];
    memcpy(buff, out, out_len);
    buff[out_len] = '\0';
    Serial.print((char *)buff);
    m3ApiSuccess();
}

// 本当はprintNumでintもfloatも実装したいが，Cには複合型やオーバーロードの仕組みがない
m3ApiRawFunction(m3_printInt)
{
    m3ApiGetArg(int, num);
    Serial.print(num);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printLong)
{
    m3ApiGetArg(long, num);
    Serial.print(num);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printFloat)
{
    m3ApiGetArg(float, num);
    m3ApiGetArg(uint8_t, format);
    Serial.print(num, format);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printDouble)
{
    m3ApiGetArg(double, num);
    m3ApiGetArg(uint8_t, format);
    Serial.print(num, format);
    m3ApiSuccess();
}
M3Result mahiwa_LinkSerial(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *serial = "serial";

    m3_LinkRawFunction(module, serial, "print", "v(*i)", &m3_print);
    m3_LinkRawFunction(module, serial, "printInt", "v(i)", &m3_printInt);
    m3_LinkRawFunction(module, serial, "printLong", "v(I)", &m3_printLong);
    m3_LinkRawFunction(module, serial, "printFloat", "v(fi)", &m3_printFloat);
    m3_LinkRawFunction(module, serial, "printDouble", "v(Fi)", &m3_printDouble);

    return m3Err_none;
}
