#pragma once
#include "TokenType.h"
#include <string>
using namespace std;

class Token{

    private:

    public:
    string input;
    int lineNumber;
    TokenType type;
    Token(TokenType type, string input, int lineNumber);
    void print();
    string toString();
};