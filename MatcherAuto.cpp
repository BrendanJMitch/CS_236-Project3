#include "MatcherAuto.h"
#include "TokenType.h"


MatcherAuto::MatcherAuto(TokenType type) : Automaton(type){
}

MatcherAuto::MatcherAuto(TokenType type, std::string ID) : Automaton(type){
    this->ID = ID;
}

int MatcherAuto::read(std::string& input){
    newLines = 0;
    bool accept = true;
    for (int i = 0; i < (int)ID.size() && accept; i++){
        if(input[i] != ID[i]){
            accept = false;
        }
        if(input[i] == '\n'){
            newLines++;
        }
    }
    if (accept){
        return (int)ID.size();
    } else  {
        return 0;
    }
}