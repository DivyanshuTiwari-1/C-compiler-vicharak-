#include "libraries/parser.h"
#include "string"
#include "Types.cpp"
#include "syntaxTree.h"
using namespace std;
Parser Parser(Lexer *Lexer){
    this->lexer= lexer;
    this->token= lexer->lexer_next_token();
}

Token *Parser parser_in(Type type){
    if(this->token->getTypes()!=type){
        cout<< "Parser unexpected token"<<this-token->getTypes()<<endl;
        exit(1);
    }
    this->token=this->lexer->lexer_next_token();
    return this->token;
}

SyntaxTree *Parser ::parser_parse(){
    return this->parser_parse_compound();
}
SyntaxTree *Parser :: parser_parse_id(){
   string value= this->token->getValue();
   this->parser_in(TOKEN_ID);
   if(value == "print"){
    SyntaxTree *st= new SyntaxTree(ST_CALL);
    st->setname(value);
    st->setvalue(this->parser_parse_block());
    return st;
   }
    if(value = "scan"){
    SyntaxTree *st= new SyntaxTree(ST_CALL);
    st->setname(value);
    st->setvalue(this->parser_parse_block());
    return st;
   }
   if(this->token->gettypes() == TOKEN_EQUALS){
    this->parser_in(TOKEN_EQUALS);
    SyntaxTree *st =new SyntaxTree(ST_ASSIGNMENT);
    st->setName(value);
    st->setvalue(this->parser_parse_expression());
    return st;
   }
   SyntaxTree *st= new SyntaxTree(ST_VARIABLE);
   st->setvalue(ST_FUNCTION);
   st->setvalue(this->parser_parse_block());
   return st;
}
SyntaxTree *Parser:: Parser_parse_block(){
    this->parser_in(TOKEN_LEFT_PAREN);
    syntaxTree *st= new SyntaxTree(ST_COMPOUND);
    while(this->token->getType()!=TOKEN_RIGHT_PAREN){
        (st->getChildren())->list_push(this->parser_parse_expression());
    }
    this->parser_in(TOKEN_RIGHT_PAREN);
    if(this->token->getType()=TOKEN_LEFT_BRACE){
        st->setType(ST_FUNCTION);
        st->setValue(this->parser_parse_compound());
    }
    else{
    st->setType(ST_CALL);

    }
    return st;
}

SyntaxTree *Parser:: Parser_parse_expression(){
    SyntaxTree *st= new SyntaxTree(ST_COMPOUND);
    (st->getChildren())->list_push(this->parser_parse_statement);
    while (this->token->getType()==TOKEN_COMMA){
        this->parser_in(TOKEN_COMMA);
    (st->getChildren())->list_push(this->parser_parse_statement);

    }
    return st;
}

SynTaxTree *Parser:: parser_parse_return(){
    this->parser_in(TOKEN_RETRUN);
    SyntaxTree *st= new SyntaxTree(ST_CALL);
    st->setName("return");
    st->setValue(this->parser_parse_expression());
    return st;
}

SyntaxTree *Perser::parser_parse_definition(){
    this->parser_in(TOKEN_LET);
    return this->parser_parse_id();
}
SyntaxTree *parser::parser_parse_int(){
    int int_value =stoi(this->token->getvalue());
    this->parser_in(TOKEN_INT);
    SyntaxTree *st= new SyntaxTree(ST_INT);
    st->setIntValue(int_value);
    return st;
}

SyntaxTree *parser::parser_parse_string(){
    string string_value = this->token->getValue();
    this->parser_in(TOKEN_STRING);

    SyntaxTree *st =new SyntaxTree(ST_STRING);
    st->setName(string_value);
    return st;
}

SyntaxTree *parser::parser_parse_statement(){
    switch (this->token->getType())
    {
    case TOKEN_ID:
     return this->parser_parse_id();

     case TOKEN_LEFT_PAREN:
     return this->parser_parse_block();

     case TOKEN_INT:
     return this->parser_parse_int();

     case TOKEN_IF:
     return this->parser_parse_conditional();

     case TOKEN_WHILE:
     return this->parser_parse_loop();
    
    case TOKEN_RETRUN:
     return this->parser_parse_return();

     case TOKEN_LET:
     return this->parser_parse_definition();

     case TOKEN_STRING:
     return this->parser_parse_string();
    default:
        {
            cout<<"parser:unexpexted token"<<this->token->getValue()<<" "<<endl;
            exit(1);
        }
    }
}

SyntaxTree *parser::parser_parse_compound(){
   bool should_close= false;
   if(this->token->getTypes()== TOKEN_LEFT_PAREN){
    this->parser_in(TOKEN_LEFT_BRACE);
    should_close= true;

   }
   SyntaxTree *compound= new SyntaxTree(ST_COMPOUND);
   while(this->token->getTypes()!=TOKEN_END_OF_FILE && this->token->getTypes()!=TOKEN_RIGHT_BRACE)
   {
    (compound->getChildren())->list_push(this_parser_parse_statement());
    if(this->token->getTypes() == TOKEN_SEMICOLON){
        this->parser_in(TOKEN_SEMICOLON);
    }
   }
   if(should_close){
    this->parser_in(TOKEN_RIGHT_BRACE);
   }
   return compound;
}
