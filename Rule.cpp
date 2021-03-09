#include "Rule.h"

Rule::Rule(Predicate headPredicate, vector<Predicate> bodyPredicates){
    this->headPredicate = headPredicate;
    this->bodyPredicates = bodyPredicates;
}

std::string Rule::toString(){
    string text = "";
    text += headPredicate.toString() + " :- ";
     for (unsigned int i = 0; i < bodyPredicates.size(); i++){
        text += bodyPredicates[i].toString();
        if(i < bodyPredicates.size()-1){
            text += ",";
        }
    }
    return text;
}