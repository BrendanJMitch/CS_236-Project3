#include "Tuple.h"

Tuple::Tuple(const Tuple &old){
    for(unsigned int i; i < old.values.size(); i++){
        this->values[i] = old.values[i];
    }
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
        cout << "In a tuple, " << values[i] << endl;
        str += " " + values[i];
    }
    str += "\n";
    return str;
}