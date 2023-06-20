
%define api.pure full
%code requires {

    #include "structs.h"
    //#include "lang.h"
    #define YYLTYPE YYLTYPE
    typedef struct YYLTYPE
    {
        int first_line;
        int first_column;
        int last_line;
        int last_column;
        char *filename;
    } YYLTYPE;
   

}

%code provides {
    
    int yylex ();
    int yyerror(const char *s);
    void yyrestart();
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

int yyerror(const char *s)
{
	return fprintf(stderr, "%s\n", s);
}