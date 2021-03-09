#include "DatalogProgram.h"


DatalogProgram::DatalogProgram(vector<Token> input){
    this->input = input;
}
DatalogProgram::~DatalogProgram(){
    input.clear();
    schemes.clear();
    facts.clear();
    rules.clear();
    queries.clear();
    domain.clear();
}

Predicate DatalogProgram::scheme(){
    string name = checkFor(ID);
    checkFor(LEFT_PAREN);
    Id *firstParam = new Id(checkFor(ID));
    vector<Parameter*> params = idList();
    params.insert(params.begin(), firstParam);
    checkFor(RIGHT_PAREN);
    Predicate pred(name, params);
    return pred;
}
vector<Predicate> DatalogProgram::schemeList(){
    if(this->input[0].type == FACTS){
        return vector<Predicate>();
    } else {
        Predicate firstScheme = scheme();
        vector<Predicate> schemes = schemeList();
        schemes.insert(schemes.begin(), firstScheme);
        return schemes;
    }
}
Predicate DatalogProgram::fact(){
    string name = checkFor(ID);
    checkFor(LEFT_PAREN);
    String *firstParam = new String(checkFor(STRING));
    vector<Parameter*> params = stringList(); 
    params.insert(params.begin(), firstParam);
    checkFor(RIGHT_PAREN);
    checkFor(PERIOD);
    return Predicate(name, params);
}
vector<Predicate> DatalogProgram::factList(){
    if(this->input[0].type == RULES){
        return vector<Predicate>();
    } else {
        Predicate firstFact = fact();
        vector<Predicate> facts = factList();
        facts.insert(facts.begin(), firstFact);
        return facts;
    }
}
Rule DatalogProgram::rule(){
    Predicate head = headPredicate();
    checkFor(COLON_DASH);
    Predicate firstPred = predicate();
    vector<Predicate> preds = predicateList();
    preds.insert(preds.begin(), firstPred);
    checkFor(PERIOD);
    return Rule(head, preds);
}
vector<Rule> DatalogProgram::ruleList(){
    if(this->input[0].type == QUERIES){
        return vector<Rule>();
    } else {
        Rule firstRule = rule();
        vector<Rule> rules = ruleList();
        rules.insert(rules.begin(), firstRule);
        return rules;
    }
}
Predicate DatalogProgram::query(){
    Predicate pred = predicate();
    checkFor(Q_MARK);
    return pred;
}
vector<Predicate> DatalogProgram::queryList(){
    if(this->input[0].type == FEND){
        return vector<Predicate>();
    } else {
        Predicate firstQuery = query();
        vector<Predicate> queries = queryList();
        queries.insert(queries.begin(), firstQuery);
        return queries;
    }
}
Predicate DatalogProgram::headPredicate(){
    string name = checkFor(ID);
    checkFor(LEFT_PAREN);
    Id *firstParam = new Id(checkFor(ID));
    vector<Parameter*> params = idList();
    params.insert(params.begin(), firstParam);
    checkFor(RIGHT_PAREN);
    return Predicate(name, params);
}
Predicate DatalogProgram::predicate(){
    string name = checkFor(ID);
    checkFor(LEFT_PAREN);
    Parameter* firstParam = parameter();
    vector<Parameter*> params = parameterList();
    params.insert(params.begin(), firstParam);
    checkFor(RIGHT_PAREN);
    return Predicate(name, params);
}
vector<Predicate> DatalogProgram::predicateList(){
    if(this->input[0].type == PERIOD){
        return vector<Predicate>();
    } else {
        checkFor(COMMA);
        Predicate firstPred = predicate();
        vector<Predicate> preds = predicateList();
        preds.insert(preds.begin(), firstPred);
        return preds;
    }
}
vector<Parameter*>  DatalogProgram::parameterList(){
    if(this->input[0].type == RIGHT_PAREN){
        return vector<Parameter*>();
    } else {
        checkFor(COMMA);
        Parameter* firstParam = parameter();
        vector<Parameter*> params = parameterList();
        params.insert(params.begin(), firstParam);
        return params;
    }
}
vector<Parameter*> DatalogProgram::stringList(){
    if(this->input[0].type == RIGHT_PAREN){
        return vector<Parameter*>();
    } else {
        checkFor(COMMA);
        String *str = new String(checkFor(STRING));
        vector<Parameter*> strs = stringList();
        strs.insert(strs.begin(), str);
        return strs;
    }
}
vector<Parameter*> DatalogProgram::idList(){
    if(this->input[0].type == RIGHT_PAREN){
        return vector<Parameter*>();
    } else {
        checkFor(COMMA);
        Id *id = new Id(checkFor(ID));
        vector<Parameter*> ids = idList();
        ids.insert(ids.begin(), id);
        return ids;
    }
}
Parameter* DatalogProgram::parameter(){
    if(this->input[0].type == STRING){
        String *str = new String(checkFor(STRING));
        return str;
    } else if (this->input[0].type == ID){
        return new Id(checkFor(ID));
    } else {
        return expression();
    }
}
Expression* DatalogProgram::expression(){
    checkFor(LEFT_PAREN);
    Parameter* left = parameter();
    string _operator = operatorToken(); 
    Parameter* right = parameter();
    checkFor(RIGHT_PAREN);
    Expression *expr = new Expression(left, _operator, right);
    return expr;
}
string DatalogProgram::operatorToken(){
    if(this->input[0].type == ADD){
        return checkFor(ADD);
    } else {
        return checkFor(MULTIPLY);
    }
}
void DatalogProgram::parse(){
    try{
        checkFor(SCHEMES);
        checkFor(COLON);
        Predicate firstScheme = scheme();
        schemes = schemeList();
        schemes.insert(schemes.begin(), firstScheme);
        checkFor(FACTS);
        checkFor(COLON);
        facts = factList();
        checkFor(RULES);
        checkFor(COLON);
        rules = ruleList();
        checkFor(QUERIES);
        checkFor(COLON);
        Predicate firstQuery = query();
        queries = queryList();
        queries.insert(queries.begin(), firstQuery);
        checkFor(FEND);
    } catch (Token e){
        cout << "Failure!\n  " << e.toString();
        isValid = false;
    }

}

string DatalogProgram::checkFor(TokenType match){
    string text = "";
    if(this->input[0].type == match){
        text = input[0].input;
        this->input.erase(this->input.begin());
    } else {
        throw input[0];
    }
    return text;
}


std::string DatalogProgram::toString(){
    string text = "Success!\n";
    text += "Schemes(" + to_string(schemes.size()) + "):\n";
    for (unsigned int i = 0; i < schemes.size(); i++){
        text += ("  " + schemes[i].toString() + "\n");
    }
    text += "Facts(" + to_string(facts.size()) + "):\n";
    for (unsigned int i = 0; i < facts.size(); i++){
        text += ("  " + facts[i].toString() + ".\n");
        for (unsigned int j = 0; j < facts[i].parameters.size(); j++){
            domain.insert(facts[i].parameters[j]->toString());
        }
    }
    text += "Rules(" + to_string(rules.size()) + "):\n";
    for (unsigned int i = 0; i < rules.size(); i++){
        text += ("  " + rules[i].toString() + ".\n");
    }
    text += "Queries(" + to_string(queries.size()) + "):\n";
    for (unsigned int i = 0; i < queries.size(); i++){ 
        text += ("  " + queries[i].toString() + "?\n");
    }
    text += "Domain(" + to_string(domain.size()) + "):\n";
    for (set<string>::iterator it = domain.begin(); it != domain.end(); it++){
        text += ("  " + (*it) + "\n");
    }
    return text;
}