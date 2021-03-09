#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Parameter.h"
using namespace std;

class Predicate{

    private:
    public:
    string ID;
    vector<Parameter*> parameters;

    Predicate();
    Predicate(string ID, vector<Parameter*> parameters);
    ~Predicate();
    std::string toString();
};