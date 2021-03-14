#include "Id.h"

Id::Id(string name){
    this->name = name;
}

string Id::toString(){
    return name;
}

bool Id::isConstant(){
    return false;
}

