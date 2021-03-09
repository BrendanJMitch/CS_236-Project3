#pragma once
#include <string>
#include "Automaton.h"

class CommentAuto : public Automaton {
    private:
    std::string ID;
    int multiLine(string input);
    int singleLine(string input);

    public:
    CommentAuto(TokenType type);
    virtual int read(std::string& input);
};
