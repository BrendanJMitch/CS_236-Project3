#include "String.h"

String::String(std::string val){
    this->val = val;
}

std::string String::toString(){
    return val;
}