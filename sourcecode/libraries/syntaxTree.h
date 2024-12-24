#ifndef _SYNTAX_TREE_H
#define _SYNTAX_TREE_H
#include<iostream>
#include "list.h"

using namespace std;
enum SyntaxType{
    ST_COMPOUND,
    ST_FUNCTION,
    ST_CALL,
    ST_ASSIGNMENT,
    ST_DEFINATION_TYPE,
    ST_VARIABLE,
    ST_STATEMENT,
    ST_INT,
    ST_STRING,
    ST_NOOP,
};
class SyntaxTree
{
    private:
    SyntaxType type;
    List *children;
    string name;
    SyntaxTree *value;
    int int_value;
    int data_type;
    public:
    SyntaxTree(SyntaxType);
    void setName(string);
    string getName();
    void setValue(SyntaxTree *);
    SyntaxTree *getValue();
    void setDataType(int);
    int getDataType();
    SyntaxType getType();
    void setType(SyntaxType);
    List *getChildren(){return this->children ;}
    void setIntValue(int);
    int getIntValue() {return this->int_value;};
   
};
#endif