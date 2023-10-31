#include <lib/wasm-functions/arduino.hpp>

m3ApiRawFunction(m3_arduino_delay)
{
    m3ApiGetArg(uint32_t, ms);
    delay(ms);
    m3ApiSuccess();
}

m3ApiRawFunction(m3_serial_print)
{
    m3ApiGetArgMem(const byte *, out);
    m3ApiGetArg(int32_t, out_len);
    byte buff[out_len + 1];
    memcpy(buff, out, out_len);
    buff[out_len] = '\0';
    Serial.print((char *)buff);
    m3ApiSuccess();
}

M3Result mahiwa_LinkArduino(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;
    const char *arduino = "arduino";
    const char *serial = "serial";

    m3_LinkRawFunction(module, arduino, "delay", "v(i)", &m3_arduino_delay);
    m3_LinkRawFunction(module, serial, "print", "v(*i)", &m3_serial_print);

    return m3Err_none;
}
