class LibraryInterface
{
private:
    String libraryName; // 正式名称

public:
    LibraryInterface() {} // コンストラクタ
    virtual void addLibraryFunctions() = 0;

protected:
    // ここに関数を実装して，addLibraryFunctionsで呼び出す
};
