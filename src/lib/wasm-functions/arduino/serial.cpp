#include <lib/wasm-functions/arduino/serial.hpp>
m3ApiRawFunction(m3_serial_print)
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

M3Result mahiwa_LinkSerial(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *serial = "serial";

    m3_LinkRawFunction(module, serial, "print", "v(*i)", &m3_serial_print);

    return m3Err_none;
}
