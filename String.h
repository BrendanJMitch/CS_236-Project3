#pragma once
#include "Parameter.h"
using namespace std;

class String : public Parameter {
    private:
    public:
    string val;
    String(std:: string val);
    virtual std::string toString();
};