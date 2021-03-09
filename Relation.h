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
    Header header;

    public:
    set<Tuple> rows;
    Relation(){}
    Relation(string name);
    Relation(const Relation &old);
    void addRow(Predicate fact);
    Relation select(int index, string value);
    Relation select(int index1, int index2);
    Relation project(Header toKeep);
    string toString();

};
