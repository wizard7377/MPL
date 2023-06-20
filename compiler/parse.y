
%code requires {

    #include "structs.h"
    
    #include <stdio.h>
    

}

%code provides {
    void proveFile(FILE *);
    int yylex ();
    int yyerror(const char *s);
    void yyrestart(FILE *);
}

%code {
    
    static struct ruleForm * curState;


}
%{
    
    #include <stdio.h>


%}

%define api.value.type union

%token NUM
%nterm exp
%%

exp: NUM

%%

void proveFile(FILE * inFile) {
    yyrestart(inFile);
}
int yyerror(const char *s)
{
	return fprintf(stderr, "%s\n", s);
}