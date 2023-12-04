class Mahiwa
{
private:
    BoardInterface board;
    SocInterface soc;
    ApiInterface api;
    // LibraryInterfaceの配列
public:
    // コンストラクタで代入
    Mahiwa(BoardInterface board, SoCInterface soc, ApiInterface api, ライブラリ){};
    void init();
    void addFunctions();
    void run();
};
