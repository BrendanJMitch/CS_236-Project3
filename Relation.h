#pragma once
#include <string>
#include <set>
#include "Predicate.h"
#include "Header.h"
#include "Tuple.h"
using namespace std;

class Relation {
    private:
    string name;

    public:
    int size;
    Header header;
    set<Tuple> rows;
    Relation(){}
    Relation(string name, int size);
    Relation(const Relation &old);
    void addRow(Predicate fact);
    Relation* select(int index, string value);
    Relation* select(int index1, int index2);
    Relation* project(Header toKeep);
    Relation* project(vector<int> indices);
    Relation* rename(vector<string> attributes);
    string toString();

};
