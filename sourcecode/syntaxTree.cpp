#include "syntaxTree.h"

SyntaxTree::SyntaxTree(SyntaxType)
{
    this->type= type;
    if(type ==ST_COMPOUND){
        this->children = new List(sizeof(SyntaxTree*));
    }
}

void SyntaxTree::setName(string name)
{ 
    this->name= name;
}
void SyntaxTree::getName()
{ 
   return  this->name;
}

void SyntaxTree::setValue(SyntaxTree *vlaue)
{
    this->value =value;

}

SyntaxTree *SyntaxTree::getValue()
{
    return this->value;
}

void SyntaxTree::setDataType(int data)
{
   this->data_type =data;
}

SyntaxType SyntaxTree::getType()
{
  return this->data_type;
}

void SyntaxTree::setType(SyntaxType)
{
    this->type=type;
}

SyntaxType SyntaxTree::getType(SyntaxType)
{
   return this->type;
}

void SyntaxTree::setIntValue(int int_value)
{
    this->int_value=int_value;
}
