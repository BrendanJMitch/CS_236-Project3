#include "Expression.h"



Expression::Expression(Parameter *Left, string _operator, Parameter *Right){
    this->Left = Left;
    this->_operator = _operator;
    this->Right = Right;
}

Expression::~Expression(){
    delete Left;
    delete Right;
}

string Expression::toString(){
    return ("(" + Left->toString() + _operator + Right->toString() + ")");
}