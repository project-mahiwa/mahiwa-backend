# 条件付きコンパイル

マイコンに応じてplatformio.iniでDオプションでマクロ定義する

マイコンの種類の大枠判断

- M5STACK : M5Stack社のマイコン(実質ESP32シリーズ)
- RASPICOW : Raspberry Pi Picoマイコン
- GENERAL : それ以外

## m5stack

m5stackの中でもLCDのサイズや呼べる機能が違うので分ける

-
