#pragma once
#include <vector>
#include <string>
using namespace std;

class Header {
    private:
    vector<string> attributes;

    public:
    Header(){}
    Header(const Header &old);
    string toString();
};