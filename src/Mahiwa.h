#pragma once
#include <apis/ApiInterface.h>
#include <Arduino.h>
class Mahiwa
{
private:
    // BoardInterface board;
    // SocInterface soc;
    ApiInterface *api;
    // LibraryInterfaceの配列
public:
    // コンストラクタで代入
    Mahiwa(ApiInterface *api) { this->api = api; };
    void init();
    // void addFunctions();
    // void run();
};
