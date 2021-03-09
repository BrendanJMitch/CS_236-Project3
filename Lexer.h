#pragma once
#include <vector>
#include "Automaton.h"
#include "MatcherAuto.h"
#include "IDAuto.h"
#include "StringAuto.h"
#include "CommentAuto.h"
#include "UndefAuto.h"
#include "Token.h"
#include "TokenType.h"


class Lexer {
    private:
    vector<Automaton*> Autos;
    vector<Token> Tokens;
    int lineNumber;

    public:
    Lexer();
    ~Lexer();
    vector<Token> Run(string input);




};