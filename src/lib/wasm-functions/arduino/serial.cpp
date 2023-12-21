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
m3ApiRawFunction(m3_printI32)
{
    m3ApiGetArg(int32_t, num);
    Serial.print(num);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printI64)
{
    m3ApiGetArg(int64_t, num);
    Serial.print(num);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printF32)
{
    m3ApiGetArg(float_t, num);
    m3ApiGetArg(int32_t, format);
    Serial.print(num, format);
    m3ApiSuccess();
}
m3ApiRawFunction(m3_printF64)
{
    m3ApiGetArg(double_t, num);
    m3ApiGetArg(int32_t, format);
    Serial.print(num, format);
    m3ApiSuccess();
}
M3Result mahiwa_LinkSerial(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *serial = "serial";

    m3_LinkRawFunction(module, serial, "print", "v(*i)", &m3_print);
    m3_LinkRawFunction(module, serial, "printI32", "v(i)", &m3_printI32);
    m3_LinkRawFunction(module, serial, "printI64", "v(I)", &m3_printI64);
    m3_LinkRawFunction(module, serial, "printF32", "v(fi)", &m3_printF32);
    m3_LinkRawFunction(module, serial, "printF64", "v(Fi)", &m3_printF64);

    return m3Err_none;
}
