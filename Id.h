#pragma once
#include "Parameter.h"
using namespace std;

class Id : public Parameter {
    private:
    public:
    string name;
    Id(string name);
    virtual string toString();
};