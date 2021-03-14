#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Parameter.h"
using namespace std;

class Header {
    private:

    public:
    Header(){}
    Header(const Header &old);
    void fill(vector<Parameter*> &varnames);
    string toString();
    vector<string> attributes;
};