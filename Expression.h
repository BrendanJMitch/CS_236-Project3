#pragma once
#include "Parameter.h"
using namespace std;

class Expression : public Parameter {
    private:
    public:
    Parameter *Left;
    string _operator;
    Parameter *Right;
    Expression(Parameter *Left, string _operator, Parameter *Right);
    virtual ~Expression();
    virtual bool isConstant();
    virtual std::string toString();
};