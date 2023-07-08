%option noyywrap 
/*%option nounput noinput*/
%option dotall
%option bison bison-cc
%option unicode
%option namespace=cl
%option bison-cc-namespace=cl
%option lexer=Scanner
%option lex=yylex    
%option freespace
%option bison-complete
%top{

    #include <stdio.h>
    #include "clparse.hpp"
    #include <string.h>
    using tty = cl::parser::token::token_kind_type;
}

%{
    
%}


 
%%


\"(.+?)\" { return cl::parser::make_MATHSTATE(str().substr(1,size()-2)); }
"[" { return cl::parser::make_LBAR(); }
"]" { return cl::parser::make_RBAR(); }
\h
[\u\l\d]+ { return cl::parser::make_CMDPART(str()); }
"," { return cl::parser::make_SEP(); }

[^\u\l\d\h\n";"":""$"]+ { return cl::parser::make_CMDPART(str()); }

<<EOF>> { std::cout << "Found EOF\n"; return cl::parser::make_YYEOF(); }
.  { throw cl::parser::syntax_error("Unknown token."); }

%%
