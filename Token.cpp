#include "Token.h"
#include "TokenType.h"
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;


Token::Token(TokenType type, string input, int lineNumber){
    this->type = type;
    this->input = input;
    this->lineNumber = lineNumber;
}

void Token::print(){
    cout << this->toString();
}

string Token::toString(){
    string typestr;
    switch(type){
        case 0: typestr = "COMMA"; break;
        case 1: typestr = "PERIOD"; break;
        case 2: typestr = "Q_MARK"; break;
        case 3: typestr = "LEFT_PAREN"; break;
        case 4: typestr = "RIGHT_PAREN"; break;
        case 5: typestr = "COLON"; break;
        case 6: typestr = "COLON_DASH"; break;
        case 7: typestr = "MULTIPLY"; break;
        case 8: typestr = "ADD"; break;
        case 9: typestr = "SCHEMES"; break;
        case 10: typestr = "FACTS"; break;
        case 11: typestr = "RULES"; break;
        case 12: typestr = "QUERIES"; break;
        case 13: typestr = "ID"; break;
        case 14: typestr = "STRING"; break;
        case 15: typestr = "COMMENT"; break;
        case 16: typestr = "UNDEFINED"; break;
        case 17: typestr = "EOF"; break;
    }
    return "(" + typestr + ",\"" + input + "\"," + to_string(lineNumber) + ")\n";
}