#pragma once
#include <m3_env.h>
class ApiInterface
{
private:
    const char *apiName;

public:
    virtual M3Result addApiFunctions(IM3Runtime runtime) = 0;

protected:
    // ここに関数を実装して，addAPIFunctionsで呼び出す
};
