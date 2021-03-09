#pragma once
#include <string>
#include <vector>
#include "Predicate.h"
using namespace std;

class Rule{

    private:
    public:
    Predicate headPredicate;
    vector<Predicate> bodyPredicates;

    Rule(Predicate headPredicate, vector<Predicate> bodyPredicates);
    std::string toString();
};