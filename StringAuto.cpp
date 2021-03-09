#include "StringAuto.h"
#include "TokenType.h"


StringAuto::StringAuto(TokenType type) : Automaton(type){
}

int StringAuto::read(std::string& input){
    newLines = 0;
    if (input[0] != '\''){
        return 0;
    } else {
        for(unsigned int i = 1; i < input.size(); i++){
            if (input[i] == '\''){
                if (input[i + 1]!= '\''){
                    return i + 1;
                } else {
                    i++;
                }
            } else if (input[i] == '\n'){
                newLines++;
            }
        }
        return 0;
    }
}