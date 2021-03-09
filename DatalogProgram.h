#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "Predicate.h"
#include "Rule.h"
#include "TokenType.h"
#include "Id.h"
#include "String.h"
#include "Expression.h"
#include <set>

class DatalogProgram{

    private:
    Predicate scheme();
    vector<Predicate>  schemeList();
    Predicate fact();
    vector<Predicate> factList();
    Rule rule();
    vector<Rule> ruleList();
    Predicate query();
    vector<Predicate> queryList();
    Predicate headPredicate();
    Predicate predicate();
	vector<Predicate> predicateList();
    vector<Parameter*> parameterList();
    vector<Parameter*> stringList();
    vector<Parameter*> idList();
    Parameter* parameter();
    Expression* expression();
    string operatorToken();

    string checkFor(TokenType match);

    public:
    vector<Token> input;
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules; 
    set<string> domain;
    bool isValid = true;
    DatalogProgram(vector<Token> input);
    ~DatalogProgram();
    void  parse();
    std::string toString();
};