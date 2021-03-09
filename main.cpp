#include <iostream>
#include <fstream>
#include "Lexer.h"
#include "DatalogProgram.h"
#include "Database.h"
using namespace std;

int main(int argc, char *argv[]){
    if (argc == 1){
        cout << "No input files. Program terminated." << endl;
        return 0;
    }

    ifstream fin(argv[1]);
    string input((std::istreambuf_iterator<char>(fin)), (std::istreambuf_iterator<char>()));

    Lexer lexer;
    vector<Token> Tokens = lexer.Run(input);
    
    for (unsigned int i = 0; i < Tokens.size(); i++){
        while(Tokens[i].type == COMMENT){
            Tokens.erase(Tokens.begin() + i);
        }
    }

    DatalogProgram program(Tokens);
    program.parse();

    Database database;
    database.populate(program);

    string str = "";
    for(auto it = database.data.begin(); it != database.data.end(); it++){
        str += (it->first + ", " + it->second.toString());
    }
    cout << str << endl;

    return 0;
}