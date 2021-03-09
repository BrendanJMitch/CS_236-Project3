#pragma once
#include <string>
#include "Automaton.h"

class UndefAuto : public Automaton {
    private:
    std::string ID;
    int badComment(std::string input);
    int badString(std::string input);

    public:
    UndefAuto(TokenType type);
    virtual int read(std::string& input);
};
