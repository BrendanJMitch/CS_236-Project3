#include "String.h"

String::String(std::string val){
    this->val = val;
}

bool String::isConstant(){
    return true;
}

std::string String::toString(){
    return val;
}