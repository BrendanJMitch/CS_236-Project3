#pragma once
#include <string>
#include "Token.h"
#include "TokenType.h"
using namespace std;

class Automaton {

    protected:
    int newLines = 0;
    TokenType type;

    public:
    Automaton(TokenType type);
    virtual ~Automaton();
    virtual int read(string& input) = 0;
    virtual Token CreateToken(std::string input, int lineNumber);
    virtual int NewLinesRead() const;
};

