#include "IDAuto.h"
#include "TokenType.h"


IDAuto::IDAuto(TokenType type) : Automaton(type){
}


int IDAuto::read(std::string& input){
    if(!isalpha(input[0])){
        return 0;
    } else {
        int i = 1;

        while(isalpha(input[i]) || isdigit(input[i])){
            i++;
        }
        return i;
    }
    
}