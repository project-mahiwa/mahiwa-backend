#include <lib/roader/wasm-roader.hpp>
// cppcheck-suppress unusedFunction
void setup()
{
  Serial.begin(115200);
  delay(1000);
  // シリアル通信準備待ち
  while (!Serial)
  {
  }
  Serial.println(cos(0));

  Serial.println("Project Mahiwa started🎉");
#ifdef ESP32
  Serial.println("ESP32 Mode");
  Serial.print("CPU Frequency:");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");
  // xTaskCreatePinnedToCoreはFreeRTOSの関数
  // ESP32ではデフォルトでFreeRTOSが組み込まれているため下記のような形となる．
  // wasm3-arduinoのexampleでは16kbごとに区切るためと書かれている．
  xTaskCreatePinnedToCore(&wasm_task, "wasm3", NATIVE_STACK_SIZE, NULL, 5, NULL,
                          1);
#else
  wasm_task(NULL);
#endif
}

// cppcheck-suppress unusedFunction
void loop()
{
  // wasm3が実行するとすべてを終える仕様のようなので，繰り返し実行できない
}
