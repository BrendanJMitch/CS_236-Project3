#include "CommentAuto.h"
#include "TokenType.h"



CommentAuto::CommentAuto(TokenType type) : Automaton(type){
}

int CommentAuto::multiLine(string input){
    for (unsigned int i = 2; i < input.size(); i++){
        if (input[i] == '|'){
            if (i + 1 == input.size()){
                return 0;
            } else if (input[i+1] == '#'){
                return i + 2;
            } else {
                return 0;
            }
        } else if (input[i] == '\n'){
            newLines++;
        }
    }
    return 0;
}

int CommentAuto::singleLine(string input){
    unsigned int i;
    for (i = 1; i < input.size(); i++){
        if(input[i] == '\n'){
            return i;
        }
    }
    return i + 1;
}

int CommentAuto::read(std::string& input){
    newLines = 0;
    
    if (input[0] != '#'){
        return 0;
    } else {
        if(input.size() == 1){
            return 1;
        } else if (input[1] == '|'){
            return multiLine(input);
        } else {
            return singleLine(input);
        }
    }
}