#include "Relation.h"


Relation::Relation(string name, int size){
    this->size = size;
    this->name = name;
    this->rows = set<Tuple>();
}

Relation::Relation(const Relation &old){
    this->size = old.size;
    this->name = old.name;
    this->header = Header(old.header);
    this->rows = old.rows;   //Potential problems right here!!!!!
}

void Relation::addRow(Predicate fact){
    Tuple row = Tuple(fact.parameters.size());
    for (unsigned int i = 0; i < fact.parameters.size(); i++){
        row.values[i] = fact.parameters[i]->toString();
    }
    rows.insert(row);
}

Relation* Relation::select(int index, string value){
    if(index >= size){
        throw "Don't do that, that's bad.";
    }
    Relation* s = new Relation(*this);
    auto it = s->rows.begin();
    while (it != s->rows.end())
    {
        if (it->values[index] != value) {
            it = s->rows.erase(it);
        }
        else {
            ++it;
        }
    }
    return s;
}

Relation* Relation::select(int index1, int index2){
    if(index1 >= size || index2 >= size){
        throw "Don't do that, that's bad.";
    }
    Relation* s = new Relation(*this);
    auto it = s->rows.begin();
    while (it != s->rows.end())
    {
        if (it->values[index1] != it->values[index2]) {
            it = s->rows.erase(it);
        }
        else {
            ++it;
        }
    }
    return s;
}

Relation* Relation::project(Header toKeep){
    Relation* p = new Relation();
    vector<int> indices;
    for (unsigned int i = 0; i < toKeep.attributes.size(); i++){
        bool added = false;
        for (unsigned int j = 0; j < this->header.attributes.size(); j++){
            if(this->header.attributes[j] == toKeep.attributes[i]){
                indices.push_back(j);
                added = true;
                break;
            }
        }
        if (!added){
            throw 1;
        }
    }
    p->header = toKeep; //Memory issues?
    for (auto it = this->rows.begin(); it != this->rows.end(); it++){
        Tuple row = Tuple(indices.size());
        for(unsigned int i = 0; i < indices.size(); i++){
            row.values.push_back(it->values[indices[i]]);
        }
        p->rows.insert(row);
    }
    return p;
}

Relation* Relation::project(vector<int> indices){
    Relation* p = new Relation();
    p->header = Header();
    for(unsigned int i = 0; i < indices.size(); i++){
        p->header.attributes.push_back(this->header.attributes[indices[i]]);
    }
    for (auto it = this->rows.begin(); it != this->rows.end(); it++){
        Tuple row = Tuple(indices.size());
        for(unsigned int i = 0; i < indices.size(); i++){
            row.values[i]  = (it->values[indices[i]]);
        }
        p->rows.insert(row);
    }
    return p;
}

Relation* Relation::rename(vector<string> attributes){
    Relation* r = new Relation(*this);
    if(attributes.size() != r->header.attributes.size()){
        throw "Um, there's a problem...";
    }
    for(unsigned int i = 0; i < attributes.size(); i++){
        r->header.attributes[i] = attributes[i];
    }
    return r;
}

string Relation::toString(){
    string str = "";
    str += header.toString();
    for(auto it = this->rows.begin(); it != this->rows.end(); it++){
        str += "R: " + it->toString();
    }
    return str;
}