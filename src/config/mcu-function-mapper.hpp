// マイコンの使える機能マッピング
#ifdef ESP32
#define MAHIWA_WIFI
#define MAHIWA_BlUETOOTH
#define MAHIWA_FREERTOS
#endif

#ifdef RP2040
#define MAHIWA_WIFI
#endif
