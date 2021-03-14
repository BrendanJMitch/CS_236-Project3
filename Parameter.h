#pragma once
#include <iostream>
#include <string>

class Parameter{

    private:
    public:
    Parameter(){}
    virtual ~Parameter(){}
    virtual bool isConstant() = 0;
    virtual std::string toString() = 0;

};