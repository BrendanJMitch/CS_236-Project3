#include "Automaton.h"

Automaton::Automaton(TokenType type){
    this->type = type;
}

Automaton::~Automaton(){}

Token Automaton::CreateToken(std::string input, int lineNumber) {
    return Token(type, input, lineNumber); 
}

int Automaton::NewLinesRead() const { 
    return newLines; 
}