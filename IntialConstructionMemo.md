# 初期構築 v2 (platformio)

## プロジェクト初期化

https://docs.platformio.org/en/stable/core/quickstart.html

```
pio project init --board pico --board m5stack-atoms3 --board seeed_xiao_esp32c3
```

M5stamp c3はないので，SoCが同じseedのboradとして利用

## ライブラリ追加

```
pio pkg install -l wasm3/wasm3
```

# 改修

### ボード検索

https://docs.platformio.org/en/stable/boards/index.html

```
pio boards
```

### パッケージ検索 & ダウンロード

https://registry.platformio.org/

```
pio pkg search
```

```
pio pkg install
```

- -eで環境指定できる

# 初期構築 v1 (esp-idf)

https://github.com/bytecodealliance/wasm-micro-runtime/tree/main/build-scripts/esp-idf  
これをもとに作成．

```

idf.py set-target esp32c3
```
