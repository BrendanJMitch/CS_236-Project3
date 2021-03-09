#pragma once
#include <string>
#include "Automaton.h"

class MatcherAuto : public Automaton {
    private:
    std::string ID;

    public:
    MatcherAuto(TokenType type);
    MatcherAuto(TokenType type, std::string ID);
    virtual int read(std::string& input);
};
