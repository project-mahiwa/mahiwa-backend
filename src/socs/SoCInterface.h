#pragma once
class SoCInterface
{
private:
    int clock;      // クロック周波数
    String socName; // 正式名称

public:
    virtual void addSoCFunctions() = 0; // wasm3へのinit処理

protected:
    // ここに関数を実装して，addSoCFunctionsで呼び出す
};
