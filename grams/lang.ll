%option noyywrap 
/*%option nounput noinput*/
%option dotall
%option bison bison-cc
%option unicode
%option namespace=yy
%option lexer=Scanner
%option lex=yylex    
%option freespace
%option bison-complete
%top{

    #include <stdio.h>
    #include "parse.hpp"
    #include <string.h>
    using tty = yy::parser::token::token_kind_type;
}

%{
    
%}


 
%%


@c.+?\n
@\[(.+?)@\] { return yy::parser::make_MATHTOK(str().substr(2,size()-4)); }
\h|\n
[\u\l\d]+ { return yy::parser::make_MATHTOK(str()); }
"::" { return yy::parser::make_CAL(); }
":" { return yy::parser::make_IMP(); }
";;" { return yy::parser::make_EOS(); }
";" { return yy::parser::make_SEP(); }
"$" { return yy::parser::make_VAR(); }

<<EOF>>  { return yy::parser::make_YYEOF(); }
[^\u\l\d\h\n";"":""$"]+ { return yy::parser::make_MATHTOK(str()); }
.  { throw yy::parser::syntax_error("Unknown token."); }

%%
