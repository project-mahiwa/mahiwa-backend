#include <lib/roader/wasm-roader.hpp>
// wasmファイルをヘッダファイルにしたもの(ヘッダファイルでなくcpp内で読むこと @see https://github.com/project-mahiwa/mahiwa-backend/issues/49 )
#include <wasm/user.h>
// cppcheck-suppress unusedFunction
void wasm_task(void *)
{
  IM3Environment env = m3_NewEnvironment();
  if (!env)
  {
    wasm3_error_printer("m3_NewEnvironment", "Error");
  }

  IM3Runtime runtime = m3_NewRuntime(env, WASM_STACK_SLOTS, NULL);
  if (!runtime)
  {
    wasm3_error_printer("m3_NewRuntime", "Error");
  }

  IM3Module module;
  // tinygo_wasi_wasm, tinygo_wasi_wasm_lenはxxdで出せる
  M3Result result = m3_ParseModule(env, &module, user_wasm, user_wasm_len);
  if (result)
  {
    wasm3_error_printer("m3_ParseModule", result);
  }

  result = m3_LoadModule(runtime, module);
  if (result)
  {
    wasm3_error_printer("m3_LoadModule", result);
  }

  // WebAssemblyに埋め込む処理
  result = mahiwa_LinkArduino(runtime);
  if (result)
  {
    wasm3_error_printer("mahiwa_LinkArduino", result);
  }
  result = mahiwa_LinkSerial(runtime);
  if (result)
  {
    wasm3_error_printer("mahiwa_LinkSerial", result);
  }
#ifdef USE_COREMARK
  Serial.println("call coremark function link");
  result = mahiwa_LinkCoremark(runtime);
  if (result)
  {
    wasm3_error_printer("mahiwa_LinkCoremark", result);
  }
#endif

  IM3Function f;
#ifdef USE_COREMARK
  Serial.println("coremark mode is enabled!!");
  result = m3_FindFunction(&f, runtime, "run");
#else
  result = m3_FindFunction(&f, runtime, "_start");
#endif
  if (result)
  {
    wasm3_error_printer("m3_FindFunction", result);
  }

  Serial.println("Project Mahiwa : WebAssembly launch");

  // 実行が成功したら終わる
  result = m3_CallV(f);
#ifdef USE_COREMARK
  float value = 0;
  result = m3_GetResultsV(f, &value);
  Serial.println("coremark score:");
  Serial.println(value, 10);
  Serial.println("");
#endif
  // 失敗時の処理
  if (result != m3Err_none)
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

  Serial.println("Project Mahiwa : WebAssembly done");
  // 止めるとpanicするので正常に終わった後はループし続けさせる
  while (true)
  {
    delay(10000);
    Serial.println("WebAssembly already done. if you want to re run, please restart.");
  }
}
