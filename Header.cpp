#include "Header.h"

Header::Header(const Header &old){
    for(unsigned int i; i < old.attributes.size(); i++){
        this->attributes[i] = old.attributes[i];
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
