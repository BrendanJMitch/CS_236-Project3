#include "Lexer.h"
#include <string>
#include <iostream>
using namespace std;

Lexer::Lexer(){
    Autos.push_back(new MatcherAuto(COMMA, ","));
    Autos.push_back(new MatcherAuto(PERIOD, "."));
    Autos.push_back(new MatcherAuto(Q_MARK, "?"));
    Autos.push_back(new MatcherAuto(LEFT_PAREN, "("));
    Autos.push_back(new MatcherAuto(RIGHT_PAREN, ")"));
    Autos.push_back(new MatcherAuto(COLON, ":"));
    Autos.push_back(new MatcherAuto(COLON_DASH, ":-"));
    Autos.push_back(new MatcherAuto(MULTIPLY, "*"));
    Autos.push_back(new MatcherAuto(ADD, "+"));
    Autos.push_back(new MatcherAuto(SCHEMES, "Schemes"));
    Autos.push_back(new MatcherAuto(FACTS, "Facts"));
    Autos.push_back(new MatcherAuto(RULES, "Rules"));
    Autos.push_back(new MatcherAuto(QUERIES, "Queries"));
    Autos.push_back(new IDAuto(ID));
    Autos.push_back(new StringAuto(STRING));
    Autos.push_back(new CommentAuto(COMMENT));
    Autos.push_back(new UndefAuto(UNDEFINED));
}

Lexer::~Lexer(){
    for(unsigned int i = 0; i < Autos.size(); i++){
        delete Autos[i];
    }
}

vector<Token> Lexer::Run(string input){
    lineNumber = 1;
    int numAutos = Autos.size();
    int charsRead = 0;
    int maxCharsRead;
    int maxIndex;
    int maxNewlines;
    while (input.size()){
        maxCharsRead = 0;
        maxIndex = 0;
        maxNewlines = 0;

        while(isspace(input[0])){
            if(input[0] == '\n'){
                lineNumber++;
            }
            input.erase(0,1);
        }

        for (int i = 0; i < numAutos; i++){
            charsRead = Autos[i]->read(input);
            if (charsRead > maxCharsRead){
                maxCharsRead = charsRead;
                maxIndex = i;
                maxNewlines = Autos[i]->NewLinesRead();
            }
        }

        if (maxCharsRead > 0){
            Tokens.push_back(Autos[maxIndex]->CreateToken(input.substr(0,maxCharsRead), lineNumber));
            lineNumber += maxNewlines;
        }                                                                           

        input.erase(0,maxCharsRead);
        
    }
    Tokens.push_back(Token(FEND, "", lineNumber));
    return Tokens;
}