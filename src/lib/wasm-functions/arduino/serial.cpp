#include <lib/wasm-functions/arduino/serial.hpp>
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
    m3ApiGetArg(int, int_num);
    Serial.print(int_num);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printDouble)
{
    m3ApiGetArg(double, double_num);
    Serial.print(double_num);
    m3ApiSuccess();
}
M3Result mahiwa_LinkSerial(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *serial = "serial";

    m3_LinkRawFunction(module, serial, "print", "v(*i)", &m3_print);
    m3_LinkRawFunction(module, serial, "printInt", "v(*i)", &m3_printInt);
    m3_LinkRawFunction(module, serial, "printDouble", "v(*F)", &m3_printDouble);

    return m3Err_none;
}
