#pragma once
#include <string>
#include "Automaton.h"

class StringAuto : public Automaton {
    private:
    std::string ID;

    public:
    StringAuto(TokenType type);
    virtual int read(std::string& input);
};
