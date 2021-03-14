#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Tuple {
    private:
    public:
    Tuple(int order);
    Tuple(const Tuple &old);
    bool operator< (const Tuple & other) const;
    string toString() const;
    vector<string> values;
};