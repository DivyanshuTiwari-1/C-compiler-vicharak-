#include <unistd.h>
#include<fstream>
#include "libraries/plus.h"
#include "lexer.cpp"
#include "parsar.cpp"
#include "front.cpp"

char *sh(const char *cmd){
    char *output =(char*)calloc*(1,sizeof(char));
    output[0]='\0';

    FILE *fp;
    char path[1035];
    fp= popen(cmd,"r");
    if(fp == NULL){
        printf("failed to rum command\n");
        exit(1);
    }
    while (fgets(path,sizeof(path),fp)!=NULL){
        output = (char *)realloc(output,(strlen(output)+strlen(path)+1)*sizeof(char));
        strcat(output,path);
    }
    pclose(fp);
    return output;
}

void plus_compile(string src ){
    Lexer *lexer= new Lexer(src);
    Parser *parser= new Parser(lexer);
    SyntaxTree *root= parser->parser_parse();
    string s= as_f_root(root);
    fstream out;
    out.open("test.s",ios::out);
    if(out.good()){
        out<<s;
        out.close();
    }
    else {
        cout<<"error"<<endl;
    }
   
}
 sh("as test.s -o test.o");
 sh("id test.o -o test.out");
