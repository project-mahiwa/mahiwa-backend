#include <apis/impl/Serial.h>

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
};
M3Result M_Serial::addApiFunctions(IM3Runtime runtime)
{
    M3Result result = M_Serial::print(runtime);
}
M3Result M_Serial::print(IM3Runtime runtime)
{
    IM3Module module = runtime->modules;

    m3_LinkRawFunction(module, M_Serial::apiName, "print", "v(*i)", &m3_serial_print);

    return m3Err_none;
}
