#pragma once
#include <string>
#include "Automaton.h"

class IDAuto : public Automaton {
    private:
    std::string ID;

    public:
    IDAuto(TokenType type);
    virtual int read(std::string& input);
};
