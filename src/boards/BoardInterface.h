#pragma once
class BoardInterface
{
private:
    int ram; // RAM
    int rom; // ROM
    String boardName;

public:
    virtual void init() = 0; // 例：M5Init
    virtual void addBoardFunctions() = 0;

protected:
    // ここに関数を実装して，addBoardFunctionsで呼び出す
};
