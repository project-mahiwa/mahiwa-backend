#include "wasm-roader.hpp"
void wasm_task(void *)
{
    M3Result result = m3Err_none;

    IM3Environment env = m3_NewEnvironment();
    if (!env)
    {
        Serial.println("m3_NewEnvironment Error");
    }

    IM3Runtime runtime = m3_NewRuntime(env, WASM_STACK_SLOTS, NULL);
    if (!runtime)
    {
        Serial.println("m3_NewRuntime Error");
    }

    IM3Module module;
    result = m3_ParseModule(env, &module, app_wasm, app_wasm_len);
    if (result)
    {
        Serial.println("m3_ParseModule Error");
    }

    result = m3_LoadModule(runtime, module);
    if (result)
    {
        Serial.println("m3_LoadModule Error");
    }

    // WebAssemblyに埋め込む処理
    result = mahiwa_LinkArduino(runtime);
    if (result)
    {
        Serial.println("mahiwa_LinkArduino Error");
    }

    IM3Function f;
    result = m3_FindFunction(&f, runtime, "_start");
    if (result)
    {
        Serial.println("m3_FindFunction Error");
    }

    Serial.println("Project Mahiwa : WebAssembly running");

    // 実行が成功したら終わる
    result = m3_CallV(f);

    // 失敗時の処理
    if (result)
    {
        M3ErrorInfo info;
        m3_GetErrorInfo(runtime, &info);
        Serial.print("Error: ");
        Serial.print(result);
        Serial.print(" (");
        Serial.print(info.message);
        Serial.println(")");
        if (info.file && strlen(info.file) && info.line)
        {
            Serial.print("At ");
            Serial.print(info.file);
            Serial.print(":");
            Serial.println(info.line);
        }
    }
}
