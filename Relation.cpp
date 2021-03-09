#include "Relation.h"


Relation::Relation(string name){
    this->name = name;
    this->rows = set<Tuple>();
}

Relation::Relation(const Relation &old){
    this->name = old.name;
    this->header = Header(old.header);
    this->rows = old.rows;
}

void Relation::addRow(Predicate fact){
    int i = 0;
    cout << i << endl;

    Tuple row = Tuple();
    for (unsigned int i = 0; i < fact.parameters.size(); i++){
        row.values.push_back(fact.parameters[i]->toString());
    }
    Tuple other;
    cout << "Before segfault" << endl;
    rows.insert(Tuple(row));
    cout << "Inserted one just fine" << endl;
    rows.insert(row);
    cout << "After segfault" << endl;
}

Relation Relation::select(int index, string value){
    Relation s;
    return s;
}

Relation Relation::select(int index1, int index2){
    Relation s;
    return s;
}

Relation Relation::project(Header toKeep){
    Relation p;
    return p;
}

string Relation::toString(){
    string str = "";
    str += header.toString();
    for(auto it = this->rows.begin(); it != this->rows.end(); it++){
        str += it->toString();
    }
    return str;
}