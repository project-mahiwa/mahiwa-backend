#include <lib/wasm-functions/display/display.hpp>

// coremark-minimalに必要な関数を用意する
//   (import "env" "clock_ms" (func (;0;) (type 8)))
//   (type (;8;) (func (result i64)))
m3ApiRawFunction(m3_display_init)
{
    lcd.init();
    // // 初期実装は回転固定
    // lcd.setRotation(1);
    // // 初期実装は輝度固定
    // lcd.setBrightness(128);
    // // 初期実装はカラーモード固定
    // lcd.setColorDepth(24);
    // // 初期実装はフォント固定
    // lcd.setFont(&fonts::Font0);
    // // 初期実装は色固定
    // lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    // // 初期実装はサイズ固定
    lcd.setTextSize(2);

    m3ApiSuccess();
}
m3ApiRawFunction(m3_display_print)
{
    // cppcheck-suppress cstyleCast
    m3ApiGetArgMem(const uint8_t *, out);
    // cppcheck-suppress cstyleCast
    m3ApiGetArg(uint32_t, out_len);
    // m3ApiGetArg(int32_t, x);
    // m3ApiGetArg(int32_t, y);

    byte buff[out_len + 1];
    memcpy(buff, out, out_len);
    buff[out_len] = '\0';

    lcd.println((char *)buff);

    m3ApiSuccess();
}

M3Result mahiwa_LinkDisplay(IM3Runtime runtime)
{
    IM3Module modules = runtime->modules;
    const char *module = "display";

    m3_LinkRawFunction(modules, module, "init", "v()", &m3_display_init);
    m3_LinkRawFunction(modules, module, "printD", "v(*i)", &m3_display_print);

    return m3Err_none;
}
