#include "Database.h"

void Database::populate(DatalogProgram program){
        for(unsigned int i = 0; i < program.schemes.size(); i++){
            string name = program.schemes[i].ID;
            data[name] = Relation(name);
        }
        for(unsigned int i = 0; i < program.facts.size(); i++){
            string name = program.facts[i].ID;
            data[name].addRow(program.facts[i]);
        }
    }