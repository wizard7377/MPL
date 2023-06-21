%option noyywrap nounput noinput
%option dotall
%option bison bison-cc
/*%option unicode*/
%option namespace=yy
%option lexer=Scanner
%option lex=yylex    

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

\@\[(.|\n)+\@\] { return yy::parser::make_MATHTOK(str().substr(2,size()-4)); };
[\u\l\d]+ { return yy::parser::make_MATHTOK(str()); }
":" { return yy::parser::make_IMP(); }
";;" { return yy::parser::make_EOS(); }
";" { return yy::parser::make_SEP(); }
"$" { return yy::parser::make_VAR(); }
[[:blank:]] ;
<<EOF>> { return yy::parser::make_EOI(); }
[^a-zA-Z0-9]+ { return yy::parser::make_MATHTOK(str()); }
. ;

%%
