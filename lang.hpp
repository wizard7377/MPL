// lang.hpp generated by reflex 3.3.5 from grams/lang.ll

#ifndef REFLEX_LANG_HPP
#define REFLEX_LANG_HPP
#define IN_HEADER 1
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

#define REFLEX_OPTION_YYLTYPE             yy::location
#define REFLEX_OPTION_YYSTYPE             yy::parser::semantic_type
#define REFLEX_OPTION_bison               true
#define REFLEX_OPTION_bison_cc            true
#define REFLEX_OPTION_bison_cc_namespace  yy
#define REFLEX_OPTION_bison_cc_parser     parser
#define REFLEX_OPTION_bison_complete      true
#define REFLEX_OPTION_debug               true
#define REFLEX_OPTION_dotall              true
#define REFLEX_OPTION_freespace           true
#define REFLEX_OPTION_header_file         "lang.hpp"
#define REFLEX_OPTION_lex                 yylex
#define REFLEX_OPTION_lexer               Scanner
#define REFLEX_OPTION_namespace           yy
#define REFLEX_OPTION_nodefault           true
#define REFLEX_OPTION_noyywrap            true
#define REFLEX_OPTION_outfile             "lang.cpp"
#define REFLEX_OPTION_perf_report         true
#define REFLEX_OPTION_reentrant           true
#define REFLEX_OPTION_token_eof           yy::parser::symbol_type(0)
#define REFLEX_OPTION_token_type          yy::parser::symbol_type
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

#line 11 "grams/lang.ll"


    #include <stdio.h>
    #include "parse.hpp"
    #include <string.h>
    using tty = yy::parser::token::token_kind_type;


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  REGEX MATCHER                                                             //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/matcher.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  ABSTRACT LEXER CLASS                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <reflex/abslexer.h>

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  LEXER CLASS                                                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

namespace yy {

class Scanner : public reflex::AbstractLexer<reflex::Matcher> {
 public:
  typedef reflex::AbstractLexer<reflex::Matcher> AbstractBaseLexer;
  Scanner(
      // a persistent source of input, empty by default
      const reflex::Input& input = reflex::Input(),
      // optional output stream, std::cout by default
      std::ostream& os = std::cout)
    :
      AbstractBaseLexer(input, os)
  {
    set_debug(true);
    set_perf_report();
  }
  static const int INITIAL = 0;
  // the bison-complete lexer function defined by SECTION 2
  virtual yy::parser::symbol_type yylex(void);
  void perf_report()
  {
    if (perf_report_time_pointer != NULL)
      *perf_report_time_pointer += reflex::timer_elapsed(perf_report_timer);
    std::cerr << "reflex 3.3.5 grams/lang.ll performance report:\n";
    std::cerr << "  INITIAL rules matched:\n"
      "    rule at line 28 matched " << perf_report_INITIAL_rule[0] << " times, matching " << perf_report_INITIAL_size[0] << " bytes total in " << perf_report_INITIAL_time[0] << " ms\n"
      "    rule at line 29 matched " << perf_report_INITIAL_rule[1] << " times, matching " << perf_report_INITIAL_size[1] << " bytes total in " << perf_report_INITIAL_time[1] << " ms\n"
      "    rule at line 30 matched " << perf_report_INITIAL_rule[2] << " times, matching " << perf_report_INITIAL_size[2] << " bytes total in " << perf_report_INITIAL_time[2] << " ms\n"
      "    rule at line 31 matched " << perf_report_INITIAL_rule[3] << " times, matching " << perf_report_INITIAL_size[3] << " bytes total in " << perf_report_INITIAL_time[3] << " ms\n"
      "    rule at line 32 matched " << perf_report_INITIAL_rule[4] << " times, matching " << perf_report_INITIAL_size[4] << " bytes total in " << perf_report_INITIAL_time[4] << " ms\n"
      "    rule at line 33 matched " << perf_report_INITIAL_rule[5] << " times, matching " << perf_report_INITIAL_size[5] << " bytes total in " << perf_report_INITIAL_time[5] << " ms\n"
      "    rule at line 34 matched " << perf_report_INITIAL_rule[6] << " times, matching " << perf_report_INITIAL_size[6] << " bytes total in " << perf_report_INITIAL_time[6] << " ms\n"
      "    rule at line 35 matched " << perf_report_INITIAL_rule[7] << " times, matching " << perf_report_INITIAL_size[7] << " bytes total in " << perf_report_INITIAL_time[7] << " ms\n"
      "    rule at line 36 matched " << perf_report_INITIAL_rule[8] << " times, matching " << perf_report_INITIAL_size[8] << " bytes total in " << perf_report_INITIAL_time[8] << " ms\n"
      "    rule at line 39 matched " << perf_report_INITIAL_rule[9] << " times, matching " << perf_report_INITIAL_size[9] << " bytes total in " << perf_report_INITIAL_time[9] << " ms\n"
      "    rule at line 40 matched " << perf_report_INITIAL_rule[10] << " times, matching " << perf_report_INITIAL_size[10] << " bytes total in " << perf_report_INITIAL_time[10] << " ms\n";
    std::cerr << "  WARNING: execution time measurements are relative:\n  - includes caller's execution time between matches when yylex() returns\n  - perf-report instrumentation adds overhead that increases execution times\n" << std::endl;
    set_perf_report();
  }
  void set_perf_report()
  {
    perf_report_INITIAL_rule[0] = 0;
    perf_report_INITIAL_size[0] = 0;
    perf_report_INITIAL_time[0] = 0;
    perf_report_INITIAL_rule[1] = 0;
    perf_report_INITIAL_size[1] = 0;
    perf_report_INITIAL_time[1] = 0;
    perf_report_INITIAL_rule[2] = 0;
    perf_report_INITIAL_size[2] = 0;
    perf_report_INITIAL_time[2] = 0;
    perf_report_INITIAL_rule[3] = 0;
    perf_report_INITIAL_size[3] = 0;
    perf_report_INITIAL_time[3] = 0;
    perf_report_INITIAL_rule[4] = 0;
    perf_report_INITIAL_size[4] = 0;
    perf_report_INITIAL_time[4] = 0;
    perf_report_INITIAL_rule[5] = 0;
    perf_report_INITIAL_size[5] = 0;
    perf_report_INITIAL_time[5] = 0;
    perf_report_INITIAL_rule[6] = 0;
    perf_report_INITIAL_size[6] = 0;
    perf_report_INITIAL_time[6] = 0;
    perf_report_INITIAL_rule[7] = 0;
    perf_report_INITIAL_size[7] = 0;
    perf_report_INITIAL_time[7] = 0;
    perf_report_INITIAL_rule[8] = 0;
    perf_report_INITIAL_size[8] = 0;
    perf_report_INITIAL_time[8] = 0;
    perf_report_INITIAL_rule[9] = 0;
    perf_report_INITIAL_size[9] = 0;
    perf_report_INITIAL_time[9] = 0;
    perf_report_INITIAL_rule[10] = 0;
    perf_report_INITIAL_size[10] = 0;
    perf_report_INITIAL_time[10] = 0;
    perf_report_time_pointer = NULL;
    reflex::timer_start(perf_report_timer);
  }
 protected:
  size_t perf_report_INITIAL_rule[11];
  size_t perf_report_INITIAL_size[11];
  float  perf_report_INITIAL_time[11];
  float *perf_report_time_pointer;
  reflex::timer_type perf_report_timer;
};

} // namespace yy

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  BISON C++                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#endif