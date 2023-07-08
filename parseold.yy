
%code requires {

    
    #include "structs.hpp"
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    #include <string>
    

}

%code provides {
    void proveFile(FILE *);
    void * reqState();
    int yylex ();
    int yyerror(const char *s);
    void yyrestart(FILE *);
}

%code {
    #include "lex.yy.h"
    static bool hasDone = false;
    static struct ruleForm * curState;


}
%{
    
    #include <stdio.h>


%}
%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.2"
%language "c++"
%define api.namespace {yy}
%define api.parser.class {parser}
%glr-parser
%define parse.error detailed
%define api.token.constructor

%define api.value.type variant 

%token SEP IMP EOS EOI VAR
%token <char*> MATHTOK
%nterm <statement> state
%nterm <stateList> stategroup
%nterm <ruleForm> hypo


%start hypo
%%


hypo: stategroup EOS
    | stategroup IMP stategroup EOS
    ;
stategroup: state
    | stategroup SEP state
    ;
state: MATHTOK 
    | VAR MATHTOK
    | state state
    ;
%%




int yyerror(const char *s)
{
	return fprintf(stderr, "%s\n", s);
}



void * reqState() {
    //if (hasDone) freeState(); else hasDone = true;
    //initState();
    //yy::parser();
    return curState;
}