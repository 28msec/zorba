/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
%{ /* _*_ C++ _*_ */

#undef SCANNER_CLASS
#undef PARSER_CLASS

#ifdef XQUERY_SCANNER
#define SCANNER_CLASS xquery_scanner
#define PARSER_CLASS xquery_parser
#else
#define SCANNER_CLASS jsoniq_scanner
#define PARSER_CLASS jsoniq_parser
#endif

#if defined (WIN32)
#pragma warning(disable: 4786)
#endif

#include <zorba/diagnostic_list.h>

#include "zorbatypes/schema_types.h"
#include "common/common.h"

#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <string>

#include "compiler/parser/xquery_driver.h"

#include "util/xml_util.h"

#ifdef __GNUC__
  // disable a warning in location.hh which comes with bison
  // position.hh:141: warning: suggest parentheses around && within ||
#  pragma GCC diagnostic ignored "-Wparentheses"
#endif

#ifdef XQUERY_SCANNER
#include "compiler/parser/xquery_parser.hpp"
#else
#include "compiler/parser/jsoniq_parser.hpp"
#endif

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

#ifdef XQUERY_SCANNER
#include "compiler/parser/xquery_scanner.h"
#else
#include "compiler/parser/jsoniq_scanner.h"
#endif

typedef zorba::PARSER_CLASS::token token;
typedef zorba::PARSER_CLASS::token_type token_type;


  /*______________________________________________________________________
   |
   |  Scanner states management
   |______________________________________________________________________*/

#define PUSH_STATE(state) \
  do { \
    yy_push_state(state); \
  } while(0)

#define POP_STATE() \
  do { \
    if (yy_get_start_stack_ptr() > 0) \
      yy_pop_state(); \
  } while(0)

#define PUSH_AND_BEGIN( pushed, new ) \
  do { \
    BEGIN new; \
    PUSH_STATE(pushed); \
  } while(0)


  /*______________________________________________________________________
   |
   |  String literals processing
   |______________________________________________________________________*/

#define TRY_TOKEN_INTERNAL(ttype, put, yytext, err_func)                \
  do {                                                                  \
    off_t res = getDriver()->symtab.put;                                \
    if (res < 0) {                                                      \
      yylval->err = getDriver()->err_func(yytext, *yylloc);             \
      return token::UNRECOGNIZED;                                       \
    } else {                                                            \
      yylval->sval = res;                                               \
      return token::ttype;                                              \
    }                                                                   \
  } while (0)

#define TRY_SVAL_TOKEN(ttype, put, yytext) \
    TRY_TOKEN_INTERNAL(ttype, put, yytext, unrecognizedToken)

#define TRY_CHARREF_LITERAL(ttype, put, yytext, yyleng) \
  TRY_TOKEN_INTERNAL(ttype, put (yytext, yyleng), yytext, unrecognizedToken)

#define TRY_URI_LITERAL(ttype, yytext, yyleng ) \
  TRY_TOKEN_INTERNAL(ttype, put_uri(yytext, yyleng), yytext, unrecognizedToken)

#ifdef XQUERY_SCANNER  
#define TRY_STRING_LITERAL(ttype, yytext, yyleng) \
  TRY_TOKEN_INTERNAL(ttype, put_stringlit(yytext, yyleng), yytext, invalidCharRef)
#else
#define TRY_STRING_LITERAL(ttype, yytext, yyleng) \
  TRY_TOKEN_INTERNAL(ttype, put_json_stringliteral(yytext, yyleng), yytext, invalidCharRef)
#endif
  

  // Returns 0 on success, non-zero on error
int checkXmlRefs(zorba::ZorbaParserError** err, char* yytext, int yyleng, zorba::SCANNER_CLASS* scanner, zorba::PARSER_CLASS::location_type* yylloc)
{
  std::string entity;
  const char* temp;
  char* pos = yytext;

  while (pos < yytext+yyleng)
  {
    if (*pos == '&')
    {
      pos += zorba::xml::parse_entity((const char*)pos, &entity);
      temp = entity.c_str();
      zorba::unicode::code_point cp = zorba::utf8::next_char(temp);
      if (!zorba::xml::is_valid(cp))
      {
        *err = scanner->getDriver()->parserErr(std::string("Invalid XML v1.0 codepoint in the string literal \"") + yytext + "\"", *yylloc, zorba::err::XQST0090);
        return 1;
      }
    }
    else
      pos++;
  }

  return 0;
}


#define COMP_CONSTR_ROLLBACK(invoke_yy_less)                            \
  do {                                                                  \
    int _STATE = YY_START;                                              \
    POP_STATE();                                                        \
    if (invoke_yy_less) {                                               \
      yylloc->columns(-1 * yyleng);                                     \
      yyless(0);                                                        \
    }                                                                   \
    if (yy_comp_constr_qname != "") {                                   \
      unput(' ');                                                       \
      for (int i=yy_comp_constr_qname.size()-1; i>=0; i--)              \
        unput(yy_comp_constr_qname[i]);                                 \
      yylloc->columns(-1 * (yy_comp_constr_qname.size()+1));            \
      yy_comp_constr_qname = "";                                        \
    }                                                                   \
    if (_STATE == MODE_ELEM_COMP_CONSTR)                                \
      return token::ELEMENT;                                            \
    else if (_STATE == MODE_ATTR_COMP_CONSTR)                           \
      return token::ATTRIBUTE;                                          \
    else if (_STATE == MODE_PI_COMP_CONSTR)                             \
      return token::PROCESSING_INSTRUCTION;                             \
    else                                                                \
      return token::NAMESPACE;                                          \
  } while (0)

/*
  Work around an incompatibility in flex (at least versions
  2.5.31 through 2.5.33): it generates code that does
  not conform to C89.  See Debian bug 333231
  <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
*/
#undef yywrap
#define yywrap() 1

/*
  By default yylex returns int, we use token_type.
  Unfortunately yyterminate by default returns 0, which is
  not of token_type.
*/
#define yyterminate() return token::_EOF


std::string start_xquery_state(int);   /* forward declaration, used by YY_USER_ACTION */

/*
  The macro YY_USER_ACTION can be defined to provide an action which is
  always executed prior to the matched rule's action.

  The following paragraph suffices to track locations accurately. Each
  time yylex is invoked, the begin position is moved onto the end
  position. Then when a pattern is matched, the end position is advanced
  of its width. In case it matched ends of lines, the end cursor is
  adjusted, and each time blanks are matched, the begin cursor is moved
  onto the end cursor to effectively ignore the blanks preceding tokens.
  Comments would be treated equally.
*/
#ifdef YY_USER_ACTION
#undef YY_USER_ACTION
#endif

#define YY_USER_ACTION \
{ \
  if (yy_flex_debug) { \
    std::cerr << "<" << start_xquery_state(YY_START) << ">" << "\""<<yytext<<"\"" << std::endl; \
  } \
  \
  int last_endl = 0;\
  for (int i=0; i<yyleng; i++) \
    if (yytext[i] == '\n')  \
    { \
      yylloc->lines(1);\
      last_endl = i+1;\
    }\
  \
  yylloc->step();\
  yylloc->columns(yyleng - last_endl);\
}

  /*______________________________________________________________________
   |
   |  Override Flex's starting state here.
   |______________________________________________________________________*/
#define YY_USER_INIT      \
{                         \
  BEGIN MODE_SHEBANG;     \
}

%}
