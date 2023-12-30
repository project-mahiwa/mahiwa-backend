#include <lib/wasm-functions/mahiwa/display/display.hpp>

// coremark-minimalに必要な関数を用意する
//   (import "env" "clock_ms" (func (;0;) (type 8)))
//   (type (;8;) (func (result i64)))
m3ApiRawFunction(m3_clock_ms)
{
    // cppcheck-suppress cstyleCast
    m3ApiReturnType(int64_t);
    m3ApiReturn(millis());
    m3ApiSuccess();
}

M3Result mahiwa_LinkDisplay(IM3Runtime runtime)
{
    IM3Module modules = runtime->modules;
    const char *module = "display";

    m3_LinkRawFunction(modules, module, "init", "v()", &m3_clock_ms);
    m3_LinkRawFunction(modules, module, "init", "v()", &m3_clock_ms);

    return m3Err_none;
}
