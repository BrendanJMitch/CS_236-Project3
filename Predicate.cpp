#include "Predicate.h"

Predicate::Predicate(){}

Predicate::Predicate(string ID, vector<Parameter*> parameters){
    this->ID = ID;
    this->parameters = parameters;
}

Predicate::~Predicate(){
    parameters.clear();
}

std::string Predicate::toString(){
    string text = ID + "(";
    for (unsigned int i = 0; i < parameters.size(); i++){
        text += parameters[i]->toString();
        if(i < parameters.size()-1){
            text += ",";
        }
    }
    text += ")";
    return text;
}