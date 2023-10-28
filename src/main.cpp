#include <lib/roader/wasm-roader.hpp>
void setup()
{
    Serial.begin(115200);
    delay(1000);
    // シリアル通信準備待ち
    while (!Serial)
    {
    }

    Serial.println("Project Mahiwa started!!!!!");
#ifdef ESP32
    Serial.println("ESP32 Mode");
    // 既存のGitリポジトリより，ESP32だけ読み込み方変える必要があるらしい
    xTaskCreatePinnedToCore(&wasm_task, "wasm3", NATIVE_STACK_SIZE, NULL, 5, NULL, 1);
#else
    wasm_task(NULL);
#endif
}

void loop()
{
    // wasm3が実行するとすべてを終える仕様のようなので，繰り返し実行できない
    Serial.println("Task is already finished. Please restart mahiwa");
    delay(3000);
}
