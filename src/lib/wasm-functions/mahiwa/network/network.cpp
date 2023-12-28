#include <lib/wasm-functions/mahiwa/network/network.hpp>
m3ApiRawFunction(m3_)
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

M3Result mahiwa_LinkNetwork(IM3Runtime runtime)
{
    IM3Module modules = runtime->modules;
    const char *module = "network";

    m3_LinkRawFunction(modules, module, "mode", "v(*i)", &m3_print);
    m3_LinkRawFunction(modules, module, "begin", "v(*i)", &m3_print);
    m3_LinkRawFunction(modules, module, "status", "v(*i)", &m3_print);
    m3_LinkRawFunction(modules, module, "localIp", "v(*i)", &m3_print);

    return m3Err_none;
}
