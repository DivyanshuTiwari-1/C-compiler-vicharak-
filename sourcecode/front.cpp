#include<iostream>
#include <string>
#include "libraries/front.h"
using namespace std;

string section_data =".data\n";
int string_count =1;
string section_bss =".bss\n";
string constants = "";

{
return string();
}

string as_f_compound(SyntaxTree *st){
    string value ="";
    for (int i=0;i<(int)st->getChildren->getsize();i++){
           SyntaxTree *chid=(SyntaxTree *)st->getChildren->getItems(i);
           string next_value= as_f(child);
           value+ = next_value;
    }
    return value;
}

string as_f_assignment(SyntaxTree *st){
     string s= "";
     string var_name= st->getName();
     string value =((SyntaxTree *)st->getValue()->getChildren()->getItems(0)->getName());
     if(value! =""){
        string assign_string= var_name+" string \""+(value)+"\"\n"+var_name+"_str_len = .-"+var_name+"_str\n";
        section_data= assign_string;
     }
     else {
       int  value =((SyntaxTree *)st->getValue()->getChildren()->getItems(0)->getIntValue());
       string assign_int = var_name+": .int" +to_string(value)+"\n"+var_name+ "src : .ascii \" " +to_string(value)+"\"\n"+var_name+"_str_len = .-"+var_name+"_str\n";
       section_data+= assign_int;
     }
     return s;
}

string as_f_variable(SyntaxTree *st){
    string s ="";
    string value =st->getName();
    string var_declaration = value+": .space"+ value "_len\n" +value+ "str : .space" +value +"str_len\n";
   section_bss+ =var_declaration;
   constants+= value+"_len =200 \n"+value+ "_str_len=200\n";
   return s;

}

string as_f_call(){
    string s = "";
    if(st_>getName()=- "return"){

        SyntaxTree *first_arg =(SyntaxTree *)(st->getValue()->getChildren()->getSize() ?st->getValue()->getChildren()->getItems(0):nullptr);
        const string temp ="mov $"+to_string(first_arg ? first_arg->getIntValue():0)+",\%eax\n";
        s+=temp;
        return s;
    }
    if (s->getName()== "print"){
         int num_arg =(SyntaxTree *)st->getValue()->getChildren()->getItems(0)->getChildren()->get-size();
         for (int i=0;i<num_arg;i++){
          SyntaxTree *print_arg= ((SyntaxTree *))((SyntaxTree*)st->getValue()->getChildren()->getItems(0)->getItmes(i));
          if(print_arg->getType()== ST_STRING ||print_arg->getType()== ST_INT )
          {
            string value ="";
            if(print_arg->getType() == ST_INT){
                value =to_string(print_arg->getIntValue());
            }
            else {
                value = print_arg->getName();
            }

            string define = "text"+to_string(string_counter)+": .ascii \""+
            value + "\"\n""text"+
            to_string(string_counter)+"_len = .-text"+to_string(string_counter)+"\n";
            const string print = "mov $4 %eax\n"
                                 " mov $1c"
                                 " mov $text"
                                 to_string(string_counter)+".%ecx\n"+
                                 "mov $"
                                +var_name +"_str_len ,%edx\n"
                                "int $0x80\n";
             

          }
         }
         
    }
    else if (print_arg->get_Type() == ST_VARIABLE){
        
            string define = "text"+to_string(string_counter)+": .ascii \""+
            value + "\"\n""text"+
            to_string(string_counter)+"_len = .-text"+to_string(string_counter)+"\n";
            const string print = "mov $4 %eax\n"
                                 " mov $1c"
                                 " mov $text"
                                 to_string(string_counter)+".%ecx\n"+
                                 "mov $"
                                +var_name +"_str_len ,%edx\n"
                                "int $0x80\n";
          return s;
    }
    s+= "call"+st->getName()+"\n";
    return s;
}
string as_f_function(SyntaxTree *st)
{
    string s;

    if (st->getValue()->getType() == ST_CALL)
    {
        string call_func = as_f_call(st);
        return call_func;
    }

    const string temp = ".global " + st->getName() + "\n" + st->getName() + ":\n";

    s = temp;

    SyntaxTree *as_val = st->getValue();

    string as_val_val = as_f(as_val->getValue());

    s += as_val_val;
    s += "ret\n";

    return s;
}

string as_f_int(SyntaxTree *st)
{
    return "";
}

string as_f_root(SyntaxTree *st)
{
    const string section_text = ".text\n"
                                ".global _start\n"
                                "_start:\n"
                                "call main\n"
                                "mov \%eax, \%ebx\n"
                                "mov $1, \%eax\n"
                                "int $0x80\n\n";

    string value = section_text;

    string next_value = as_f(st);
    value += next_value;
    string result = "";
    result += constants;
    result += section_data;
    result += section_bss;
    result += value;
    return result;
}

string as_f(SyntaxTree *st)
{
    string value = "";
    string next_value = "";

    switch (st->getType())
    {
        case ST_COMPOUND:
            next_value = as_f_compound(st);
            break;
        case ST_ASSIGNMENT:
            next_value = as_f_assignment(st);
            break;
        case ST_VARIABLE:
            next_value = as_f_variable(st);
            break;
        case ST_CALL:
            next_value = as_f_call(st);
            break;
        case ST_INT:
            next_value = as_f_int(st);
            break;
        case ST_FUNCTION:
            next_value = as_f_function(st);
            break;
        default:
        {
            cout << "[As front]: No frontfor ST of type " << st->getType() << endl;
            exit(1);
            break;
        }
    }

    value += next_value;

    return value;
}