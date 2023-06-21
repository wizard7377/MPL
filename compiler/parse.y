
%code requires {

    
    #include "structs.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <string.h>
    

}

%code provides {
    void proveFile(FILE *);
    void * reqState();
    int yylex ();
    int yyerror(const char *s);
    void yyrestart(FILE *);
}

%code {
    
    static bool hasDone = false;
    static struct ruleForm * curState;


}
%{
    
    #include <stdio.h>


%}

%glr-parser
%define parse.error detailed


%define api.value.type union
%token SEP IMP EOS EOI VAR
%token <char*> MATHTOK
%nterm <struct statement> state
%nterm <struct stateList> stategroup
%nterm <struct ruleForm> hypo


%start hypo
%%


hypo: stategroup EOS
    | stategroup IMP stategroup EOS
    ;
stategroup: state
    | stategroup SEP state
    ;
state: MATHTOK { $$.len = 1; $$.tokPart = malloc(sizeof(struct statement)); $$.tokPart[0].tType = T_LIT; $$.tokPart[0].txt = $1; }
    | VAR MATHTOK { $$.len = 1; $$.tokPart = malloc(sizeof(struct statement)); $$.tokPart[0].tType = T_VAR; $$.tokPart[0].txt = $2; }
    | state state { 
        $$.len = ($1).len + ($2).len; 
        $$.tokPart = malloc($$.len * sizeof(struct statement)); 
        memcpy($$.tokPart,($1).tokPart,($1).len);
        memcpy(($$.tokPart+((($1).len)*sizeof(struct statement))),($2).tokPart,($2).len);
    }
    ;
%%



void proveFile(FILE * inFile) {
    yyrestart(inFile);
}
int yyerror(const char *s)
{
	return fprintf(stderr, "%s\n", s);
}

/*
void freeState() {
    free(curState->preState.lState);
    free(curState->proveState.lState);
    free(curState->pState);
    free(curState);
}
void initState() {
    curState = malloc(sizeof(struct ruleForm));
    curState->pState = malloc(sizeof(struct statement));
    curState->pState->tokPart = malloc(sizeof(char **));
    curState->nPre = 0; curState->nPre = 0;
    //Not done
}
*/
/*

enum tokenTypes {
    T_VAR,
    T_LIT
};
struct mathToken {
    enum tokenTypes tokenType;
    int len;
    char * txt;
};
struct statement {
    int len;
    struct mathToken * tokPart;
};
struct ruleForm {
    int nPre;
    int nPro;
    struct statement * pState;
};

*/

void * reqState() {
    //if (hasDone) freeState(); else hasDone = true;
    //initState();
    yyparse();
    return curState;
}