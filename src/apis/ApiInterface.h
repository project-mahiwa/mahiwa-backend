class APIInterface
{
private:
    String apiName;

public:
    virtual void addAPIFunctions() = 0;

protected:
    // ここに関数を実装して，addAPIFunctionsで呼び出す
};
