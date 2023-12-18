#include <lib/wasm-functions/mahiwa/coremark/coremark.hpp>

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

M3Result mahiwa_LinkCoremark(IM3Runtime runtime)
{
    Serial.println("link coremark function");
    IM3Module module = runtime->modules;

    m3_LinkRawFunction(module, "env", "clock_ms", "I()", &m3_clock_ms);

    return m3Err_none;
}
