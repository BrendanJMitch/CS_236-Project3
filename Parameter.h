#pragma once
#include <iostream>
#include <string>

class Parameter{

    private:
    public:
    Parameter(){}
    virtual ~Parameter(){}
    virtual std::string toString() = 0;
};