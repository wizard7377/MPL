%option noyywrap nounput noinput
/*%option noyyalloc noyyrealloc noyyfree*/
/*%option reentrant bison-bridge bison-locations*/

%{
    #include <stdio.h>
    #include "parse.h"
    #include <string.h>
%}

%%

\@\[(.|\n)+\@\] { yylval.MATHTOK = strndup(yytext+(2*sizeof(char)),yyleng-4); return MATHTOK; }

    /* [a-zA-Z0-9]+ { strncpy(yylval.MATHTOK,yytext,yyleng); return MATHTOK; } */
[a-zA-Z0-9]+ { yylval.MATHTOK = strdup(yytext); return MATHTOK; }
":" { return IMP; }
";;" { return EOS; }
";" { return SEP; }
"$" { return VAR; }
[[:blank:]];
<<EOF>> { return EOF; }
[^a-zA-Z0-9]+ { yylval.MATHTOK = strndup(yytext,yyleng); return MATHTOK; }
. { return *yytext; }

%%
