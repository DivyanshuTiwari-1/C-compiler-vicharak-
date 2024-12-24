#include "libraries/token.h"

using namespace std;

Token(string value,Type type){
 this->value=value;
 this->type=type;
}
Type Token:: getTypes(){
    return this->type;
}
string Token:: getValue(){
    return this->value;
}