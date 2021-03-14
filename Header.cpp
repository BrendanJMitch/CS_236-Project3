#include "Header.h"

Header::Header(const Header &old){
    for(unsigned int i; i < old.attributes.size(); i++){
        this->attributes.push_back(old.attributes[i]);
    }
}


void Header::fill(vector<Parameter*> &varnames){
    for (unsigned int i = 0; i < varnames.size(); i++){
        this->attributes.push_back(varnames[i]->toString());
    }
}

string Header::toString(){
    string str = "";
    for(unsigned int i = 0; i < this->attributes.size(); i++){
        str += " " + attributes[i];
    }
    str += "\n";
    return str;
}
