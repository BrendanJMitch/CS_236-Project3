#pragma once
#include <unordered_map>
#include "DatalogProgram.h"
#include "Header.h"
#include "Relation.h"
#include "Tuple.h"

class Database{
    private:
    public:
    unordered_map<string, Relation> data;
    void populate(DatalogProgram program);
    string evaluate(vector<Predicate> queries);
};