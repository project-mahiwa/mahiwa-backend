#include <lib/wasm-functions/esp32/esp32.hpp>

m3ApiRawFunction(m3_esp32_random)
{
    // cppcheck-suppress cstyleCast
    m3ApiReturnType(int64_t);

    // CPUクロックが最低の10MHzのときでも生成まで待てるように2μs待つ
    // 出典:https://lang-ship.com/blog/work/esp32-rand/
    delayMicroseconds(2);
    m3ApiReturn(READ_PERI_REG(DR_REG_RNG_BASE));

    m3ApiSuccess();
}

M3Result mahiwa_LinkESP32(IM3Runtime runtime)
{
    IM3Module modules = runtime->modules;
    const char *module = "esp32";

    m3_LinkRawFunction(modules, module, "random", "I()", &m3_esp32_random);

    return m3Err_none;
}
