#pragma once
#include <apis/ApiInterface.h>
#include <m3_env.h>
#include <Arduino.h>
class M_Serial : public ApiInterface
{
private:
    const char *apiName = "serial";

public:
    M3Result addApiFunctions(IM3Runtime runtime);

protected:
    // ここに関数を実装して，addAPIFunctionsで呼び出す
    M3Result print(IM3Runtime runtime);
    // void pinMode();
    // void digitalWrite();
    // void digitalRead();
    // void analogReference();
    // void analogRead();
    // void analogWrite();
    // void tone();
    // void noTone();
};
