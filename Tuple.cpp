#include "Tuple.h"

Tuple::Tuple(int order) {
    this->values = vector<string>();
    this->values.resize(order);
}

Tuple::Tuple(const Tuple &old){
    this->values = old.values;
}


bool Tuple::operator< (const Tuple & other) const{
    if (this->values.size() != other.values.size()){
        throw "Tuples do not have the same order";
    }
    for(unsigned int i = 0; i < this->values.size(); i++){
        if (this->values[i] < other.values[i]){
            return true;
        } else if (this->values[i] > other.values[i]) {
            return false;
        }
    }
    return false;
}

string Tuple::toString() const{
    string str = "";
    for(unsigned int i = 0; i < this->values.size(); i++){
        str += " " + values[i];
    }
    str += "\n";
    return str;
}