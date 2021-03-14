#include "Database.h"

void Database::populate(DatalogProgram program){
    for(unsigned int i = 0; i < program.schemes.size(); i++){
        string name = program.schemes[i].ID;
        int size = program.schemes[i].parameters.size();
        Relation relation(name, size);
        relation.header.fill(program.schemes[i].parameters);
        data[name] = relation;
    }
    for(unsigned int i = 0; i < program.facts.size(); i++){
        string name = program.facts[i].ID;
        data[name].addRow(program.facts[i]);
    }
}

string Database::evaluate(vector<Predicate> queries){
    string str;
    for (unsigned int i = 0; i < queries.size(); i++){
        str += queries[i].toString() + "? ";
        Relation r;
        vector<string> variables;
        vector<int> indices;
        unordered_map<string, int> variable_locations;
        if (this->data.find(queries[i].ID) != this->data.end()){
            r = this->data[queries[i].ID];
        } else {
            throw "Invalid query";
        }
        for (unsigned int j = 0; j < queries[i].parameters.size(); j++){
            string param = queries[i].parameters[j]->toString();
            if (queries[i].parameters[j]->isConstant()){
                Relation* b = r.select(j, param);
                r = *b;
            } else {
                if (variable_locations.find(param) == variable_locations.end()){
                    variables.push_back(param);
                    indices.push_back(j);
                    variable_locations[param] = j;
                } else {
                    r = *r.select(variable_locations[param], j);
                }
            }
        }
        r = *r.project(indices);
        r = *r.rename(variables);
        if(r.rows.size() > 0){
            str += "Yes(" + to_string(r.rows.size()) + ")\n";
        } else {
            str += "No\n";
        }
        for (auto it = r.rows.begin(); it != r.rows.end(); it++){
            if (it->values.size() > 0){
                str += "  ";
            }
            bool newline = false;
            for(unsigned int k = 0; k < it->values.size(); k++){
                newline = true;
                str += variables[k] + "=" + it->values[k];
                if (k < it->values.size()-1){
                    str += ", ";
                }
            }
            if (newline){
                str += "\n";
            }
        }
    }
    return str;
}