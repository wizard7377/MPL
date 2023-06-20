%option noyywrap nounput noinput
/*%option noyyalloc noyyrealloc noyyfree*/
/*%option reentrant bison-bridge bison-locations*/

%{
    #include <stdio.h>
    #include "parse.h"
%}

%%

cot { printf("portable bed"); }
cat { printf("thankless pet"); }
cats { printf("anti-herd"); }
. { return *yytext; }
