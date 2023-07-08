// cllang.cpp generated by reflex 3.3.5 from grams/cllang.ll

#define REFLEX_VERSION "3.3.5"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  OPTIONS USED                                                              //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#undef REFLEX_OPTION_YYLTYPE
#undef REFLEX_OPTION_YYSTYPE
#undef REFLEX_OPTION_bison
#undef REFLEX_OPTION_bison_cc
#undef REFLEX_OPTION_bison_cc_namespace
#undef REFLEX_OPTION_bison_cc_parser
#undef REFLEX_OPTION_bison_complete
#undef REFLEX_OPTION_debug
#undef REFLEX_OPTION_dotall
#undef REFLEX_OPTION_freespace
#undef REFLEX_OPTION_header_file
#undef REFLEX_OPTION_lex
#undef REFLEX_OPTION_lexer
#undef REFLEX_OPTION_namespace
#undef REFLEX_OPTION_nodefault
#undef REFLEX_OPTION_noyywrap
#undef REFLEX_OPTION_outfile
#undef REFLEX_OPTION_perf_report
#undef REFLEX_OPTION_reentrant
#undef REFLEX_OPTION_token_eof
#undef REFLEX_OPTION_token_type
#undef REFLEX_OPTION_unicode
#undef REFLEX_OPTION_verbose

#define REFLEX_OPTION_YYLTYPE             cl::location
#define REFLEX_OPTION_YYSTYPE             cl::parser::semantic_type
#define REFLEX_OPTION_bison               true
#define REFLEX_OPTION_bison_cc            true
#define REFLEX_OPTION_bison_cc_namespace  cl
#define REFLEX_OPTION_bison_cc_parser     parser
#define REFLEX_OPTION_bison_complete      true
#define REFLEX_OPTION_debug               true
#define REFLEX_OPTION_dotall              true
#define REFLEX_OPTION_freespace           true
#define REFLEX_OPTION_header_file         "cllang.hpp"
#define REFLEX_OPTION_lex                 yylex
#define REFLEX_OPTION_lexer               Scanner
#define REFLEX_OPTION_namespace           cl
#define REFLEX_OPTION_nodefault           true
#define REFLEX_OPTION_noyywrap            true
#define REFLEX_OPTION_outfile             "cllang.cpp"
#define REFLEX_OPTION_perf_report         true
#define REFLEX_OPTION_reentrant           true
#define REFLEX_OPTION_token_eof           cl::parser::symbol_type(0)
#define REFLEX_OPTION_token_type          cl::parser::symbol_type
#define REFLEX_OPTION_unicode             true
#define REFLEX_OPTION_verbose             true

// --debug option enables ASSERT:
#define ASSERT(c) assert(c)

// --perf-report option requires a timer:
#include <reflex/timer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %top user code                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 12 "grams/cllang.ll"


    #include <stdio.h>
    #include "clparse.hpp"
    #include <string.h>
    using tty = cl::parser::token::token_kind_type;


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS INCLUDE                                                       //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "cllang.hpp"

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 1: %{ user code %}                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#line 2 "grams/cllang.ll"
/*%option nounput noinput*/
#line 20 "grams/cllang.ll"




////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  SECTION 2: rules                                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

cl::parser::symbol_type cl::Scanner::yylex(void)
{
  static const char *REGEX_INITIAL = "(?msx)(\"(?:[\\x00-\\xff]+?)\")|((?:\\Q[\\E))|((?:\\Q]\\E))|((?:\\x09|\\x20))|((?:[0-9]|[A-Z]|[a-z]|\\xc2\\xb5|\\xc3[\\x80-\\x96]|\\xc3[\\x98-\\xb6]|\\xc3[\\xb8-\\xbf]|[\\xc4\\xc5][\\x80-\\xbf]|\\xc6[\\x80-\\xba]|\\xc6[\\xbc-\\xbf]|\\xc7\\x84|\\xc7[\\x86\\x87]|\\xc7[\\x89\\x8a]|\\xc7[\\x8c-\\xb1]|\\xc7[\\xb3-\\xbf]|[\\xc8\\xc9][\\x80-\\xbf]|\\xca[\\x80-\\x93]|\\xca[\\x95-\\xaf]|\\xcd[\\xb0-\\xb3]|\\xcd[\\xb6\\xb7]|\\xcd[\\xbb-\\xbd]|\\xcd\\xbf|\\xce\\x86|\\xce[\\x88-\\x8a]|\\xce\\x8c|\\xce[\\x8e-\\xa1]|\\xce[\\xa3-\\xbf]|\\xcf[\\x80-\\xb5]|\\xcf[\\xb7-\\xbf]|[\\xd0\\xd1][\\x80-\\xbf]|\\xd2[\\x80\\x81]|\\xd2[\\x8a-\\xbf]|\\xd3[\\x80-\\xbf]|\\xd4[\\x80-\\xaf]|\\xd4[\\xb1-\\xbf]|\\xd5[\\x80-\\x96]|\\xd5[\\xa0-\\xbf]|\\xd6[\\x80-\\x88]|\\xd9[\\xa0-\\xa9]|\\xdb[\\xb0-\\xb9]|\\xdf[\\x80-\\x89]|\\xe0\\xa5[\\xa6-\\xaf]|\\xe0\\xa7[\\xa6-\\xaf]|\\xe0\\xa9[\\xa6-\\xaf]|\\xe0\\xab[\\xa6-\\xaf]|\\xe0\\xad[\\xa6-\\xaf]|\\xe0\\xaf[\\xa6-\\xaf]|\\xe0\\xb1[\\xa6-\\xaf]|\\xe0\\xb3[\\xa6-\\xaf]|\\xe0\\xb5[\\xa6-\\xaf]|\\xe0\\xb7[\\xa6-\\xaf]|\\xe0\\xb9[\\x90-\\x99]|\\xe0\\xbb[\\x90-\\x99]|\\xe0\\xbc[\\xa0-\\xa9]|\\xe1\\x81[\\x80-\\x89]|\\xe1\\x82[\\x90-\\x99]|\\xe1(?:\\x82[\\xa0-\\xbf]|\\x83[\\x80-\\x85])|\\xe1\\x83\\x87|\\xe1\\x83\\x8d|\\xe1\\x83[\\x90-\\xba]|\\xe1\\x83[\\xbd-\\xbf]|\\xe1(?:\\x8e[\\xa0-\\xbf]|\\x8f[\\x80-\\xb5])|\\xe1\\x8f[\\xb8-\\xbd]|\\xe1\\x9f[\\xa0-\\xa9]|\\xe1\\xa0[\\x90-\\x99]|\\xe1\\xa5[\\x86-\\x8f]|\\xe1\\xa7[\\x90-\\x99]|\\xe1\\xaa[\\x80-\\x89]|\\xe1\\xaa[\\x90-\\x99]|\\xe1\\xad[\\x90-\\x99]|\\xe1\\xae[\\xb0-\\xb9]|\\xe1\\xb1[\\x80-\\x89]|\\xe1\\xb1[\\x90-\\x99]|\\xe1\\xb2[\\x80-\\x88]|\\xe1\\xb2[\\x90-\\xba]|\\xe1\\xb2[\\xbd-\\xbf]|\\xe1\\xb4[\\x80-\\xab]|\\xe1\\xb5[\\xab-\\xb7]|\\xe1(?:\\xb5[\\xb9-\\xbf]|\\xb6[\\x80-\\x9a])|\\xe1(?:[\\xb8-\\xbb][\\x80-\\xbf]|\\xbc[\\x80-\\x95])|\\xe1\\xbc[\\x98-\\x9d]|\\xe1(?:\\xbc[\\xa0-\\xbf]|\\xbd[\\x80-\\x85])|\\xe1\\xbd[\\x88-\\x8d]|\\xe1\\xbd[\\x90-\\x97]|\\xe1\\xbd\\x99|\\xe1\\xbd\\x9b|\\xe1\\xbd\\x9d|\\xe1\\xbd[\\x9f-\\xbd]|\\xe1\\xbe[\\x80-\\x87]|\\xe1\\xbe[\\x90-\\x97]|\\xe1\\xbe[\\xa0-\\xa7]|\\xe1\\xbe[\\xb0-\\xb4]|\\xe1\\xbe[\\xb6-\\xbb]|\\xe1\\xbe\\xbe|\\xe1\\xbf[\\x82-\\x84]|\\xe1\\xbf[\\x86-\\x8b]|\\xe1\\xbf[\\x90-\\x93]|\\xe1\\xbf[\\x96-\\x9b]|\\xe1\\xbf[\\xa0-\\xac]|\\xe1\\xbf[\\xb2-\\xb4]|\\xe1\\xbf[\\xb6-\\xbb]|\\xe2\\x84\\x82|\\xe2\\x84\\x87|\\xe2\\x84[\\x8a-\\x93]|\\xe2\\x84\\x95|\\xe2\\x84[\\x99-\\x9d]|\\xe2\\x84\\xa4|\\xe2\\x84\\xa6|\\xe2\\x84\\xa8|\\xe2\\x84[\\xaa-\\xad]|\\xe2\\x84[\\xaf-\\xb4]|\\xe2\\x84\\xb9|\\xe2\\x84[\\xbc-\\xbf]|\\xe2\\x85[\\x85-\\x89]|\\xe2\\x85\\x8e|\\xe2\\x86[\\x83\\x84]|\\xe2(?:\\xb0[\\x80-\\xbf]|\\xb1[\\x80-\\xbb])|\\xe2(?:\\xb1[\\xbe\\xbf]|\\xb2[\\x80-\\xbf]|\\xb3[\\x80-\\xa4])|\\xe2\\xb3[\\xab-\\xae]|\\xe2\\xb3[\\xb2\\xb3]|\\xe2\\xb4[\\x80-\\xa5]|\\xe2\\xb4\\xa7|\\xe2\\xb4\\xad|\\xea\\x98[\\xa0-\\xa9]|\\xea\\x99[\\x80-\\xad]|\\xea\\x9a[\\x80-\\x9b]|\\xea(?:\\x9c[\\xa2-\\xbf]|\\x9d[\\x80-\\xaf])|\\xea(?:\\x9d[\\xb1-\\xbf]|\\x9e[\\x80-\\x87])|\\xea\\x9e[\\x8b-\\x8e]|\\xea(?:\\x9e[\\x90-\\xbf]|\\x9f[\\x80-\\x8a])|\\xea\\x9f[\\x90\\x91]|\\xea\\x9f\\x93|\\xea\\x9f[\\x95-\\x99]|\\xea\\x9f[\\xb5\\xb6]|\\xea\\x9f\\xba|\\xea\\xa3[\\x90-\\x99]|\\xea\\xa4[\\x80-\\x89]|\\xea\\xa7[\\x90-\\x99]|\\xea\\xa7[\\xb0-\\xb9]|\\xea\\xa9[\\x90-\\x99]|\\xea(?:\\xac[\\xb0-\\xbf]|\\xad[\\x80-\\x9a])|\\xea\\xad[\\xa0-\\xa8]|\\xea(?:\\xad[\\xb0-\\xbf]|\\xae[\\x80-\\xbf])|\\xea\\xaf[\\xb0-\\xb9]|\\xef\\xac[\\x80-\\x86]|\\xef\\xac[\\x93-\\x97]|\\xef\\xbc[\\x90-\\x99]|\\xef\\xbc[\\xa1-\\xba]|\\xef\\xbd[\\x81-\\x9a]|\\xf0\\x90(?:\\x90[\\x80-\\xbf]|\\x91[\\x80-\\x8f])|\\xf0\\x90\\x92[\\xa0-\\xa9]|\\xf0\\x90(?:\\x92[\\xb0-\\xbf]|\\x93[\\x80-\\x93])|\\xf0\\x90\\x93[\\x98-\\xbb]|\\xf0\\x90\\x95[\\xb0-\\xba]|\\xf0\\x90(?:\\x95[\\xbc-\\xbf]|\\x96[\\x80-\\x8a])|\\xf0\\x90\\x96[\\x8c-\\x92]|\\xf0\\x90\\x96[\\x94\\x95]|\\xf0\\x90\\x96[\\x97-\\xa1]|\\xf0\\x90\\x96[\\xa3-\\xb1]|\\xf0\\x90\\x96[\\xb3-\\xb9]|\\xf0\\x90\\x96[\\xbb\\xbc]|\\xf0\\x90\\xb2[\\x80-\\xb2]|\\xf0\\x90\\xb3[\\x80-\\xb2]|\\xf0\\x90\\xb4[\\xb0-\\xb9]|\\xf0\\x91\\x81[\\xa6-\\xaf]|\\xf0\\x91\\x83[\\xb0-\\xb9]|\\xf0\\x91\\x84[\\xb6-\\xbf]|\\xf0\\x91\\x87[\\x90-\\x99]|\\xf0\\x91\\x8b[\\xb0-\\xb9]|\\xf0\\x91\\x91[\\x90-\\x99]|\\xf0\\x91\\x93[\\x90-\\x99]|\\xf0\\x91\\x99[\\x90-\\x99]|\\xf0\\x91\\x9b[\\x80-\\x89]|\\xf0\\x91\\x9c[\\xb0-\\xb9]|\\xf0\\x91(?:\\xa2[\\xa0-\\xbf]|\\xa3[\\x80-\\xa9])|\\xf0\\x91\\xa5[\\x90-\\x99]|\\xf0\\x91\\xb1[\\x90-\\x99]|\\xf0\\x91\\xb5[\\x90-\\x99]|\\xf0\\x91\\xb6[\\xa0-\\xa9]|\\xf0\\x96\\xa9[\\xa0-\\xa9]|\\xf0\\x96\\xab[\\x80-\\x89]|\\xf0\\x96\\xad[\\x90-\\x99]|\\xf0\\x96\\xb9[\\x80-\\xbf]|\\xf0\\x9d(?:\\x90[\\x80-\\xbf]|\\x91[\\x80-\\x94])|\\xf0\\x9d(?:\\x91[\\x96-\\xbf]|\\x92[\\x80-\\x9c])|\\xf0\\x9d\\x92[\\x9e\\x9f]|\\xf0\\x9d\\x92\\xa2|\\xf0\\x9d\\x92[\\xa5\\xa6]|\\xf0\\x9d\\x92[\\xa9-\\xac]|\\xf0\\x9d\\x92[\\xae-\\xb9]|\\xf0\\x9d\\x92\\xbb|\\xf0\\x9d(?:\\x92[\\xbd-\\xbf]|\\x93[\\x80-\\x83])|\\xf0\\x9d(?:\\x93[\\x85-\\xbf]|\\x94[\\x80-\\x85])|\\xf0\\x9d\\x94[\\x87-\\x8a]|\\xf0\\x9d\\x94[\\x8d-\\x94]|\\xf0\\x9d\\x94[\\x96-\\x9c]|\\xf0\\x9d\\x94[\\x9e-\\xb9]|\\xf0\\x9d\\x94[\\xbb-\\xbe]|\\xf0\\x9d\\x95[\\x80-\\x84]|\\xf0\\x9d\\x95\\x86|\\xf0\\x9d\\x95[\\x8a-\\x90]|\\xf0\\x9d(?:\\x95[\\x92-\\xbf]|[\\x96-\\x99][\\x80-\\xbf]|\\x9a[\\x80-\\xa5])|\\xf0\\x9d(?:\\x9a[\\xa8-\\xbf]|\\x9b\\x80)|\\xf0\\x9d\\x9b[\\x82-\\x9a]|\\xf0\\x9d\\x9b[\\x9c-\\xba]|\\xf0\\x9d(?:\\x9b[\\xbc-\\xbf]|\\x9c[\\x80-\\x94])|\\xf0\\x9d\\x9c[\\x96-\\xb4]|\\xf0\\x9d(?:\\x9c[\\xb6-\\xbf]|\\x9d[\\x80-\\x8e])|\\xf0\\x9d\\x9d[\\x90-\\xae]|\\xf0\\x9d(?:\\x9d[\\xb0-\\xbf]|\\x9e[\\x80-\\x88])|\\xf0\\x9d\\x9e[\\x8a-\\xa8]|\\xf0\\x9d(?:\\x9e[\\xaa-\\xbf]|\\x9f[\\x80-\\x82])|\\xf0\\x9d\\x9f[\\x84-\\x8b]|\\xf0\\x9d\\x9f[\\x8e-\\xbf]|\\xf0\\x9d\\xbc[\\x80-\\x89]|\\xf0\\x9d\\xbc[\\x8b-\\x9e]|\\xf0\\x9e\\x85[\\x80-\\x89]|\\xf0\\x9e\\x8b[\\xb0-\\xb9]|\\xf0\\x9e(?:\\xa4[\\x80-\\xbf]|\\xa5[\\x80-\\x83])|\\xf0\\x9e\\xa5[\\x90-\\x99]|\\xf0\\x9f\\xaf[\\xb0-\\xb9])+)|((?:\\Q,\\E))|((?:[\\x00-\\x08]|[\\x0b-\\x1f]|!|\\x23|[%-/]|[<-@]|[\\x5b-`]|[{-\\x7f]|\\xc2[\\x80-\\xb4]|\\xc2[\\xb6-\\xbf]|\\xc3\\x97|\\xc3\\xb7|\\xc6\\xbb|\\xc7[\\x80-\\x83]|\\xc7\\x85|\\xc7\\x88|\\xc7\\x8b|\\xc7\\xb2|\\xca\\x94|\\xca[\\xb0-\\xbf]|[\\xcb\\xcc][\\x80-\\xbf]|\\xcd[\\x80-\\xaf]|\\xcd[\\xb4\\xb5]|\\xcd[\\xb8-\\xba]|\\xcd\\xbe|\\xce[\\x80-\\x85]|\\xce\\x87|\\xce\\x8b|\\xce\\x8d|\\xce\\xa2|\\xcf\\xb6|\\xd2[\\x82-\\x89]|\\xd4\\xb0|\\xd5[\\x97-\\x9f]|\\xd6[\\x89-\\xbf]|[\\xd7\\xd8][\\x80-\\xbf]|\\xd9[\\x80-\\x9f]|\\xd9[\\xaa-\\xbf]|\\xda[\\x80-\\xbf]|\\xdb[\\x80-\\xaf]|\\xdb[\\xba-\\xbf]|[\\xdc-\\xde][\\x80-\\xbf]|\\xdf[\\x8a-\\xbf]|\\xe0(?:[\\xa0-\\xa4][\\x80-\\xbf]|\\xa5[\\x80-\\xa5])|\\xe0(?:\\xa5[\\xb0-\\xbf]|\\xa6[\\x80-\\xbf]|\\xa7[\\x80-\\xa5])|\\xe0(?:\\xa7[\\xb0-\\xbf]|\\xa8[\\x80-\\xbf]|\\xa9[\\x80-\\xa5])|\\xe0(?:\\xa9[\\xb0-\\xbf]|\\xaa[\\x80-\\xbf]|\\xab[\\x80-\\xa5])|\\xe0(?:\\xab[\\xb0-\\xbf]|\\xac[\\x80-\\xbf]|\\xad[\\x80-\\xa5])|\\xe0(?:\\xad[\\xb0-\\xbf]|\\xae[\\x80-\\xbf]|\\xaf[\\x80-\\xa5])|\\xe0(?:\\xaf[\\xb0-\\xbf]|\\xb0[\\x80-\\xbf]|\\xb1[\\x80-\\xa5])|\\xe0(?:\\xb1[\\xb0-\\xbf]|\\xb2[\\x80-\\xbf]|\\xb3[\\x80-\\xa5])|\\xe0(?:\\xb3[\\xb0-\\xbf]|\\xb4[\\x80-\\xbf]|\\xb5[\\x80-\\xa5])|\\xe0(?:\\xb5[\\xb0-\\xbf]|\\xb6[\\x80-\\xbf]|\\xb7[\\x80-\\xa5])|\\xe0(?:\\xb7[\\xb0-\\xbf]|\\xb8[\\x80-\\xbf]|\\xb9[\\x80-\\x8f])|\\xe0(?:\\xb9[\\x9a-\\xbf]|\\xba[\\x80-\\xbf]|\\xbb[\\x80-\\x8f])|\\xe0(?:\\xbb[\\x9a-\\xbf]|\\xbc[\\x80-\\x9f])|\\xe0(?:[\\xbd-\\xbf][\\x80-\\xbf]|\\xbc[\\xaa-\\xbf])|\\xe1\\x80[\\x80-\\xbf]|\\xe1(?:\\x81[\\x8a-\\xbf]|\\x82[\\x80-\\x8f])|\\xe1\\x82[\\x9a-\\x9f]|\\xe1\\x83\\x86|\\xe1\\x83[\\x88-\\x8c]|\\xe1\\x83[\\x8e\\x8f]|\\xe1\\x83[\\xbb\\xbc]|\\xe1(?:[\\x84-\\x8d][\\x80-\\xbf]|\\x8e[\\x80-\\x9f])|\\xe1\\x8f[\\xb6\\xb7]|\\xe1(?:\\x8f[\\xbe\\xbf]|[\\x90-\\x9e][\\x80-\\xbf]|\\x9f[\\x80-\\x9f])|\\xe1(?:\\x9f[\\xaa-\\xbf]|\\xa0[\\x80-\\x8f])|\\xe1(?:\\xa0[\\x9a-\\xbf]|[\\xa1-\\xa4][\\x80-\\xbf]|\\xa5[\\x80-\\x85])|\\xe1(?:\\xa5[\\x90-\\xbf]|\\xa6[\\x80-\\xbf]|\\xa7[\\x80-\\x8f])|\\xe1(?:\\xa7[\\x9a-\\xbf]|[\\xa8\\xa9][\\x80-\\xbf])|\\xe1\\xaa[\\x8a-\\x8f]|\\xe1(?:\\xaa[\\x9a-\\xbf]|[\\xab\\xac][\\x80-\\xbf]|\\xad[\\x80-\\x8f])|\\xe1(?:\\xad[\\x9a-\\xbf]|\\xae[\\x80-\\xaf])|\\xe1(?:\\xae[\\xba-\\xbf]|[\\xaf\\xb0][\\x80-\\xbf])|\\xe1\\xb1[\\x8a-\\x8f]|\\xe1\\xb1[\\x9a-\\xbf]|\\xe1\\xb2[\\x89-\\x8f]|\\xe1\\xb2[\\xbb\\xbc]|\\xe1\\xb3[\\x80-\\xbf]|\\xe1(?:\\xb4[\\xac-\\xbf]|\\xb5[\\x80-\\xaa])|\\xe1\\xb5\\xb8|\\xe1(?:\\xb6[\\x9b-\\xbf]|\\xb7[\\x80-\\xbf])|\\xe1\\xbc[\\x96\\x97]|\\xe1\\xbc[\\x9e\\x9f]|\\xe1\\xbd[\\x86\\x87]|\\xe1\\xbd[\\x8e\\x8f]|\\xe1\\xbd\\x98|\\xe1\\xbd\\x9a|\\xe1\\xbd\\x9c|\\xe1\\xbd\\x9e|\\xe1\\xbd[\\xbe\\xbf]|\\xe1\\xbe[\\x88-\\x8f]|\\xe1\\xbe[\\x98-\\x9f]|\\xe1\\xbe[\\xa8-\\xaf]|\\xe1\\xbe\\xb5|\\xe1\\xbe[\\xbc\\xbd]|\\xe1(?:\\xbe\\xbf|\\xbf[\\x80\\x81])|\\xe1\\xbf\\x85|\\xe1\\xbf[\\x8c-\\x8f]|\\xe1\\xbf[\\x94\\x95]|\\xe1\\xbf[\\x9c-\\x9f]|\\xe1\\xbf[\\xad-\\xb1]|\\xe1\\xbf\\xb5|\\xe1\\xbf[\\xbc-\\xbf]|\\xe2(?:[\\x80-\\x83][\\x80-\\xbf]|\\x84[\\x80\\x81])|\\xe2\\x84[\\x83-\\x86]|\\xe2\\x84[\\x88\\x89]|\\xe2\\x84\\x94|\\xe2\\x84[\\x96-\\x98]|\\xe2\\x84[\\x9e-\\xa3]|\\xe2\\x84\\xa5|\\xe2\\x84\\xa7|\\xe2\\x84\\xa9|\\xe2\\x84\\xae|\\xe2\\x84[\\xb5-\\xb8]|\\xe2\\x84[\\xba\\xbb]|\\xe2\\x85[\\x80-\\x84]|\\xe2\\x85[\\x8a-\\x8d]|\\xe2(?:\\x85[\\x8f-\\xbf]|\\x86[\\x80-\\x82])|\\xe2(?:\\x86[\\x85-\\xbf]|[\\x87-\\xaf][\\x80-\\xbf])|\\xe2\\xb1[\\xbc\\xbd]|\\xe2\\xb3[\\xa5-\\xaa]|\\xe2\\xb3[\\xaf-\\xb1]|\\xe2\\xb3[\\xb4-\\xbf]|\\xe2\\xb4\\xa6|\\xe2\\xb4[\\xa8-\\xac]|\\xe2(?:[\\xb5-\\xbf][\\x80-\\xbf]|\\xb4[\\xae-\\xbf])|[\\xe3-\\xe9][\\x80-\\xbf][\\x80-\\xbf]|\\xea(?:[\\x80-\\x97][\\x80-\\xbf]|\\x98[\\x80-\\x9f])|\\xea\\x98[\\xaa-\\xbf]|\\xea\\x99[\\xae-\\xbf]|\\xea(?:\\x9a[\\x9c-\\xbf]|\\x9b[\\x80-\\xbf]|\\x9c[\\x80-\\xa1])|\\xea\\x9d\\xb0|\\xea\\x9e[\\x88-\\x8a]|\\xea\\x9e\\x8f|\\xea\\x9f[\\x8b-\\x8f]|\\xea\\x9f\\x92|\\xea\\x9f\\x94|\\xea\\x9f[\\x9a-\\xb4]|\\xea\\x9f[\\xb7-\\xb9]|\\xea(?:\\x9f[\\xbb-\\xbf]|[\\xa0-\\xa2][\\x80-\\xbf]|\\xa3[\\x80-\\x8f])|\\xea\\xa3[\\x9a-\\xbf]|\\xea(?:\\xa4[\\x8a-\\xbf]|[\\xa5\\xa6][\\x80-\\xbf]|\\xa7[\\x80-\\x8f])|\\xea\\xa7[\\x9a-\\xaf]|\\xea(?:\\xa7[\\xba-\\xbf]|\\xa8[\\x80-\\xbf]|\\xa9[\\x80-\\x8f])|\\xea(?:\\xa9[\\x9a-\\xbf]|[\\xaa\\xab][\\x80-\\xbf]|\\xac[\\x80-\\xaf])|\\xea\\xad[\\x9b-\\x9f]|\\xea\\xad[\\xa9-\\xaf]|\\xea\\xaf[\\x80-\\xaf]|\\xea(?:[\\xb0-\\xbf][\\x80-\\xbf]|\\xaf[\\xba-\\xbf])|[\\xeb\\xec][\\x80-\\xbf][\\x80-\\xbf]|\\xed[\\x80-\\x9f][\\x80-\\xbf]|\\xee[\\x80-\\xbf][\\x80-\\xbf]|\\xef[\\x80-\\xab][\\x80-\\xbf]|\\xef\\xac[\\x87-\\x92]|\\xef(?:\\xac[\\x98-\\xbf]|[\\xad-\\xbb][\\x80-\\xbf]|\\xbc[\\x80-\\x8f])|\\xef\\xbc[\\x9a-\\xa0]|\\xef(?:\\xbc[\\xbb-\\xbf]|\\xbd\\x80)|\\xef(?:\\xbd[\\x9b-\\xbf]|[\\xbe\\xbf][\\x80-\\xbf])|\\xf0\\x90(?:[\\x80-\\x8f][\\x80-\\xbf])|\\xf0\\x90(?:\\x91[\\x90-\\xbf]|\\x92[\\x80-\\x9f])|\\xf0\\x90\\x92[\\xaa-\\xaf]|\\xf0\\x90\\x93[\\x94-\\x97]|\\xf0\\x90(?:\\x93[\\xbc-\\xbf]|\\x94[\\x80-\\xbf]|\\x95[\\x80-\\xaf])|\\xf0\\x90\\x95\\xbb|\\xf0\\x90\\x96\\x8b|\\xf0\\x90\\x96\\x93|\\xf0\\x90\\x96\\x96|\\xf0\\x90\\x96\\xa2|\\xf0\\x90\\x96\\xb2|\\xf0\\x90\\x96\\xba|\\xf0\\x90(?:\\x96[\\xbd-\\xbf]|[\\x97-\\xb1][\\x80-\\xbf])|\\xf0\\x90\\xb2[\\xb3-\\xbf]|\\xf0\\x90(?:\\xb3[\\xb3-\\xbf]|\\xb4[\\x80-\\xaf])|\\xf0(?:\\x90(?:[\\xb5-\\xbf][\\x80-\\xbf]|\\xb4[\\xba-\\xbf])|\\x91(?:\\x80[\\x80-\\xbf]|\\x81[\\x80-\\xa5]))|\\xf0\\x91(?:\\x81[\\xb0-\\xbf]|\\x82[\\x80-\\xbf]|\\x83[\\x80-\\xaf])|\\xf0\\x91(?:\\x83[\\xba-\\xbf]|\\x84[\\x80-\\xb5])|\\xf0\\x91(?:[\\x85\\x86][\\x80-\\xbf]|\\x87[\\x80-\\x8f])|\\xf0\\x91(?:\\x87[\\x9a-\\xbf]|[\\x88-\\x8a][\\x80-\\xbf]|\\x8b[\\x80-\\xaf])|\\xf0\\x91(?:\\x8b[\\xba-\\xbf]|[\\x8c-\\x90][\\x80-\\xbf]|\\x91[\\x80-\\x8f])|\\xf0\\x91(?:\\x91[\\x9a-\\xbf]|\\x92[\\x80-\\xbf]|\\x93[\\x80-\\x8f])|\\xf0\\x91(?:\\x93[\\x9a-\\xbf]|[\\x94-\\x98][\\x80-\\xbf]|\\x99[\\x80-\\x8f])|\\xf0\\x91(?:\\x99[\\x9a-\\xbf]|\\x9a[\\x80-\\xbf])|\\xf0\\x91(?:\\x9b[\\x8a-\\xbf]|\\x9c[\\x80-\\xaf])|\\xf0\\x91(?:\\x9c[\\xba-\\xbf]|[\\x9d-\\xa1][\\x80-\\xbf]|\\xa2[\\x80-\\x9f])|\\xf0\\x91(?:\\xa3[\\xaa-\\xbf]|\\xa4[\\x80-\\xbf]|\\xa5[\\x80-\\x8f])|\\xf0\\x91(?:\\xa5[\\x9a-\\xbf]|[\\xa6-\\xb0][\\x80-\\xbf]|\\xb1[\\x80-\\x8f])|\\xf0\\x91(?:\\xb1[\\x9a-\\xbf]|[\\xb2-\\xb4][\\x80-\\xbf]|\\xb5[\\x80-\\x8f])|\\xf0\\x91(?:\\xb5[\\x9a-\\xbf]|\\xb6[\\x80-\\x9f])|\\xf0(?:\\x91(?:[\\xb7-\\xbf][\\x80-\\xbf]|\\xb6[\\xaa-\\xbf])|[\\x92-\\x95][\\x80-\\xbf][\\x80-\\xbf]|\\x96(?:[\\x80-\\xa8][\\x80-\\xbf]|\\xa9[\\x80-\\x9f]))|\\xf0\\x96(?:\\xa9[\\xaa-\\xbf]|\\xaa[\\x80-\\xbf])|\\xf0\\x96(?:\\xab[\\x8a-\\xbf]|\\xac[\\x80-\\xbf]|\\xad[\\x80-\\x8f])|\\xf0\\x96(?:\\xad[\\x9a-\\xbf]|[\\xae-\\xb8][\\x80-\\xbf])|\\xf0(?:\\x96[\\xba-\\xbf][\\x80-\\xbf]|[\\x97-\\x9c][\\x80-\\xbf][\\x80-\\xbf]|\\x9d[\\x80-\\x8f][\\x80-\\xbf])|\\xf0\\x9d\\x91\\x95|\\xf0\\x9d\\x92\\x9d|\\xf0\\x9d\\x92[\\xa0\\xa1]|\\xf0\\x9d\\x92[\\xa3\\xa4]|\\xf0\\x9d\\x92[\\xa7\\xa8]|\\xf0\\x9d\\x92\\xad|\\xf0\\x9d\\x92\\xba|\\xf0\\x9d\\x92\\xbc|\\xf0\\x9d\\x93\\x84|\\xf0\\x9d\\x94\\x86|\\xf0\\x9d\\x94[\\x8b\\x8c]|\\xf0\\x9d\\x94\\x95|\\xf0\\x9d\\x94\\x9d|\\xf0\\x9d\\x94\\xba|\\xf0\\x9d\\x94\\xbf|\\xf0\\x9d\\x95\\x85|\\xf0\\x9d\\x95[\\x87-\\x89]|\\xf0\\x9d\\x95\\x91|\\xf0\\x9d\\x9a[\\xa6\\xa7]|\\xf0\\x9d\\x9b\\x81|\\xf0\\x9d\\x9b\\x9b|\\xf0\\x9d\\x9b\\xbb|\\xf0\\x9d\\x9c\\x95|\\xf0\\x9d\\x9c\\xb5|\\xf0\\x9d\\x9d\\x8f|\\xf0\\x9d\\x9d\\xaf|\\xf0\\x9d\\x9e\\x89|\\xf0\\x9d\\x9e\\xa9|\\xf0\\x9d\\x9f\\x83|\\xf0\\x9d\\x9f[\\x8c\\x8d]|\\xf0\\x9d(?:[\\xa0-\\xbb][\\x80-\\xbf])|\\xf0\\x9d\\xbc\\x8a|\\xf0(?:\\x9d(?:[\\xbd-\\xbf][\\x80-\\xbf]|\\xbc[\\x9f-\\xbf])|\\x9e[\\x80-\\x84][\\x80-\\xbf])|\\xf0\\x9e(?:\\x85[\\x8a-\\xbf]|[\\x86-\\x8a][\\x80-\\xbf]|\\x8b[\\x80-\\xaf])|\\xf0\\x9e(?:\\x8b[\\xba-\\xbf]|[\\x8c-\\xa3][\\x80-\\xbf])|\\xf0\\x9e\\xa5[\\x84-\\x8f]|\\xf0(?:\\x9e(?:[\\xa6-\\xbf][\\x80-\\xbf]|\\xa5[\\x9a-\\xbf])|\\x9f(?:[\\x80-\\xae][\\x80-\\xbf]|\\xaf[\\x80-\\xaf]))|\\xf0(?:[\\xa0-\\xbf][\\x80-\\xbf][\\x80-\\xbf]|\\x9f(?:[\\xb0-\\xbf][\\x80-\\xbf]|\\xaf[\\xba-\\xbf]))|[\\xf1-\\xf3][\\x80-\\xbf][\\x80-\\xbf][\\x80-\\xbf]|\\xf4[\\x80-\\x8f][\\x80-\\xbf][\\x80-\\xbf])+)|((?:[\\x00-\\xff][\\x80-\\xbf]*))";
  static const reflex::Pattern PATTERN_INITIAL(REGEX_INITIAL);
  if (!has_matcher())
  {
    matcher(new Matcher(PATTERN_INITIAL, stdinit(), this));
  }
  while (true)
  {
    if (perf_report_time_pointer != NULL)
      *perf_report_time_pointer += reflex::timer_elapsed(perf_report_timer);
        switch (matcher().scan())
        {
          case 0:
            if (matcher().at_end())
            {
              if (debug()) std::cerr << "--\033[1;35mEOF rule grams/cllang.ll:38\033[0m start(" << start() << ")\n";
#line 38 "grams/cllang.ll"
{ std::cout << "Found EOF\n"; return cl::parser::make_YYEOF(); }
              perf_report();
            }
            else
            {
              if (debug()) std::cerr << "--\033[1;31mdefault rule\033[0m\n";
              char ch = matcher().input();
              if (debug()) std::cerr << "--\033[1;31msuppressed default rule \033[0m" << matcher().lineno() << "," << matcher().columno() << ":'" << (ch > 32 && ch < 127 ? ch : ' ') << "'(" << (int)ch << ")\n";
            }
            break;
          case 1: // rule grams/cllang.ll:29: \"(.+?)\" :
            ++perf_report_INITIAL_rule[0];
            perf_report_INITIAL_size[0] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[0];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:29\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 29 "grams/cllang.ll"
{ return cl::parser::make_MATHSTATE(str().substr(1,size()-2)); }
            break;
          case 2: // rule grams/cllang.ll:30: "[" :
            ++perf_report_INITIAL_rule[1];
            perf_report_INITIAL_size[1] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[1];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:30\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 30 "grams/cllang.ll"
{ return cl::parser::make_LBAR(); }
            break;
          case 3: // rule grams/cllang.ll:31: "]" :
            ++perf_report_INITIAL_rule[2];
            perf_report_INITIAL_size[2] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[2];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:31\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 31 "grams/cllang.ll"
{ return cl::parser::make_RBAR(); }
            break;
          case 4: // rule grams/cllang.ll:32: \h :
            ++perf_report_INITIAL_rule[3];
            perf_report_INITIAL_size[3] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[3];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:32\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 32 "grams/cllang.ll"
            break;
          case 5: // rule grams/cllang.ll:33: [\u\l\d]+ :
            ++perf_report_INITIAL_rule[4];
            perf_report_INITIAL_size[4] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[4];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:33\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 33 "grams/cllang.ll"
{ return cl::parser::make_CMDPART(str()); }
            break;
          case 6: // rule grams/cllang.ll:34: "," :
            ++perf_report_INITIAL_rule[5];
            perf_report_INITIAL_size[5] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[5];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:34\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 34 "grams/cllang.ll"
{ return cl::parser::make_SEP(); }

            break;
          case 7: // rule grams/cllang.ll:36: [^\u\l\d\h\n";"":""$"]+ :
            ++perf_report_INITIAL_rule[6];
            perf_report_INITIAL_size[6] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[6];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:36\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 36 "grams/cllang.ll"
{ return cl::parser::make_CMDPART(str()); }

            break;
          case 8: // rule grams/cllang.ll:39: . :
            ++perf_report_INITIAL_rule[7];
            perf_report_INITIAL_size[7] += size();
            perf_report_time_pointer = &perf_report_INITIAL_time[7];
            if (debug()) std::cerr << "--\033[1;35mrule grams/cllang.ll:39\033[0m start(" << start() << ") " << matcher().lineno() << "," << matcher().columno() << ":\"\033[1m" << matcher().text() << "\033[0m\"\n";
#line 39 "grams/cllang.ll"
{ throw cl::parser::syntax_error("Unknown token."); }

            break;
        }
  }
}