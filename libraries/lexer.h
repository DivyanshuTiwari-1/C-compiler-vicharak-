#ifndef _LEXER_H_
#define _LEXER_H_
#include<iostream>
using namespace std;
#include"token.h"
class Lexer{
   private:
    string src;
    int src_size;
    char c;
    unsigned int i;
    public:
    Lexer(string src);
    void lexer_advance();
    Token *lexer_advance_with(Token *token);
    Token *lexer_advance_current(Type type);
    void lexer_skip_whitspace();
    char lexer_peek(int);
    Token*lexer_next_token();
    Token *lexer_parse_id();
    Token *lexer_parse_number();


    
};
#endif