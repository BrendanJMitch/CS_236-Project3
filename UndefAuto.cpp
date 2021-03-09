#include "UndefAuto.h"
#include "TokenType.h"
#include <iostream>
using namespace std;



UndefAuto::UndefAuto(TokenType type) : Automaton(type){
}

int UndefAuto::badComment(string input){
    if (input[1] != '|'){
        return 1;
    } else {
        for(unsigned int i = 3; i < input.size(); i++){
            if (input[i] == '#' && input[i-1] == '|'){
                return 0;
            } else if (input[i-1] == '\n'){
                newLines++;
            }
        }
        if (input[input.size() - 1] == '\n'){
            newLines++;
        }
        return input.size();
    }
}

int UndefAuto::badString(string input){
    for(unsigned int i = 1; i < input.size(); i++){
        if(input[i] == '\''){
            if(i + 1 < input.size() && input[i + 1] == '\''){
                i++;
            } else {
                return 0;
            }
        } else if (input[i] == '\n'){
            newLines++;
        }
    }
    return input.size();
}

int UndefAuto::read(std::string& input){
    newLines = 0;
    if (input[0] == '\''){
        return badString(input);
    } else if (input[0] == '#'){
        return badComment(input);
    } else {
        return (input.size() > 0);
    }
}