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

#include "compiler/parser/xquery_parser.hpp"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

#include "compiler/parser/xquery_scanner.h"


typedef zorba::xquery_parser::token token;
typedef zorba::xquery_parser::token_type token_type;

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

#define TRY_STRING_LITERAL(ttype, yytext, yyleng) \
  TRY_TOKEN_INTERNAL(ttype, put_stringlit(yytext, yyleng), yytext, invalidCharRef)

#define TRY_URI_LITERAL(ttype, yytext, yyleng ) \
  TRY_TOKEN_INTERNAL(ttype, put_uri(yytext, yyleng), yytext, unrecognizedToken)

  // Returns 0 on success, non-zero on error
int checkXmlRefs(zorba::ZorbaParserError** err, char* yytext, int yyleng, zorba::xquery_scanner* scanner, zorba::xquery_parser::location_type* yylloc)
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
    if (invoke_yy_less)                                                 \
      yyless(0);                                                        \
    if (yy_comp_constr_qname != "") {                                   \
      unput(' ');                                                       \
      for (int i=yy_comp_constr_qname.size()-1; i>=0; i--)              \
        unput(yy_comp_constr_qname[i]);                                 \
      yy_comp_constr_qname = "";                                        \
    }                                                                   \
    return _STATE==MODE_ELEM_COMP_CONSTR? token::ELEMENT : (            \
           _STATE==MODE_ATTR_COMP_CONSTR? token::ATTRIBUTE :            \
                                    token::PROCESSING_INSTRUCTION);     \
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


std::string start_state(int);   /* forward declaration, used by YY_USER_ACTION */

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
    std::cerr << "<" << start_state(YY_START) << ">" << "\""<<yytext<<"\"" << std::endl; \
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


%}


  /*______________________________________________________________________
   *                                                                      *
   *  Scanner options                                                     *
   *______________________________________________________________________*/

%option outfile="xquery_scanner.yy.cpp"
%option noyywrap
%option batch
%option debug
%option stack
%option nounistd
%option c++
%option prefix="Zorba"

  /*_____________________________________________________________________
   |
   |  UTF-8 characters definitions
   |______________________________________________________________________*/


  /* UTF8_1Byte    [\x00-\x7F] -- not used anywhere */

BaseChar_1Byte  ([\x41-\x5A]|[\x61-\x7A])
UTF8_2Bytes     ([\xC0-\xDF][\x80-\xBF])
UTF8_3Bytes     ([\xE0-\xEF][\x80-\xBF][\x80-\xBF])
UTF8_4Bytes     ([\xF0-\xF7][\x80-\xBF][\x80-\xBF][\x80-\xBF])

UTF8_MultiByte  ({UTF8_2Bytes}|{UTF8_3Bytes}|{UTF8_4Bytes})


  /*_____________________________________________________________________
   |
   |  Whitespace definitions
   |______________________________________________________________________*/
CommentChars    ([^:]|":"+[^:)])*":)"
Comment         "(:"{CommentChars}
blank           [ \t]
S1              [ \t\r\n\f]
S               {S1}*
SP              ({S1}|{Comment})+
SPNoComment     {S1}+

  /*_____________________________________________________________________
   |
   |  Basic character classes
   |______________________________________________________________________*/
Letter      ({BaseChar_1Byte}|{UTF8_MultiByte})
Digit       [0-9]
Apos        \'
Quote       \"
Dot         [.]
CatchAll    [^ \t\r\n]

  /*_____________________________________________________________________
   |
   |  XQuery allows '' to escape ', and "" to escape ".
   |______________________________________________________________________*/
EscapeApos  {Apos}{Apos}
EscapeQuot  {Quote}{Quote}

  /*_____________________________________________________________________
   |
   |  NCName definition
   |______________________________________________________________________*/
NCNameStartChar       ({Letter}|"_")
NCNameChar            ({Letter}|{Digit}|[._-])

NCName                ({NCNameStartChar}{NCNameChar}*)

  /*_____________________________________________________________________
   |
   |  QName definition
   |______________________________________________________________________*/
QName       ({NCName}":")?{NCName}

  /*_____________________________________________________________________
   |
   |  Annotation QName definition
   |______________________________________________________________________*/
AnnotationQName  "%"({NCName}":")?{NCName}

AnnotationEQName "%"{StringLiteral}":"{NCName}

  /*_____________________________________________________________________
   |
   |  Entity definitions
   |______________________________________________________________________*/
CharRef               "&#"([0-9]+|x([0-9]|[a-f]|[A-F])+)";"
PredefinedEntityRef   "&"(lt|gt|amp|quot|apos|nbsp)";"
Ref                   {CharRef}|{PredefinedEntityRef}

  /*_____________________________________________________________________
   |
   |  Numeric literal definitions
   |______________________________________________________________________*/
DecimalLiteral        ({Dot}[0-9]+)|([0-9]+({Dot}[0-9]*)?)
DoubleLiteral         (({Dot}[0-9]+)|([0-9]+({Dot}[0-9]*)?))([eE][+-]?[0-9]+)?
IntegerLiteral        [0-9]+

  /*_____________________________________________________________________
   |
   |  String literal definitions
   |______________________________________________________________________*/
NonQuotAnd                      [^""&]
NonAposAnd                      [^''&]
StringLiteral                   ({Quote}({EscapeQuot}|{Ref}|{NonQuotAnd})*{Quote})|({Apos}({EscapeApos}|{Ref}|{NonAposAnd})*{Apos})

  /* Invalid strings */
InvalidRefStringLiteral         ({Quote}({EscapeQuot}|"&"|{NonQuotAnd})*{Quote})|({Apos}({EscapeApos}|"&"|{NonAposAnd})*{Apos})
UnterminatedStringLiteral       ({Quote}({EscapeQuot}|"&"|{NonQuotAnd})*)|({Apos}({EscapeApos}|"&"|{NonAposAnd})*)


  /*_____________________________________________________________________
   |
   |  Content character definitions
   |______________________________________________________________________*/
Char                  [\x09\x0A\x0D\x20-\xFD]
NonHyphenChar         [\x09\x0D\x0A\x20-\x2C\x2E-\xFD]
XMLCommentChar        ({NonHyphenChar}*)|(-{NonHyphenChar}+)
NonRParChar           [\x09\x0D\x0A\x20-\x28\x2A-\xFD]
NonColonChar          [\x09\x0D\x0A\x20-\x39\x3B-\xFD]
ElementContentChar    [\x09\x0A\x0D\x20-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
QuotAttrContentChar   [\x09\x0A\x0D\x20-\x21\x23-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
AposAttrContentChar   [\x09\x0A\x0D\x20-\x25\x28-\x3B\x3D-\x7A\x7C\x7E-\xFD]

PITarget              {NCName}

NonQuestionMarkChar                 [\x09\x0A\x0D\x20-\x3E\x40-\xFD]
NonGreaterThanNonQuestionMarkChar   [\x09\x0A\x0D\x20-\x3D\x40-\xFD]
PIChars                             ({NonQuestionMarkChar}|"?"+{NonGreaterThanNonQuestionMarkChar})*"?"*

NonSharpPragmaChar                  [\x09\x0A\x0D\x20-\x22\x24-\xFD]
NonSharpNonParPragmaChar            [\x09\x0A\x0D\x20-\x28\x2A-\xFD]
PragmaChars                         ({NonSharpPragmaChar}|"#"+{NonSharpNonParPragmaChar})*"#"*

	/* Char ranges and definitions used for parsing CDATA contents */
NonClosingSquareBracketChar					[\x09\x0A\x0D\x20-\x5C\x5E-\xFD]
NonGreaterThenChar									[\x09\x0A\x0D\x20-\x3D\x3F-\xFD]
NonSqBraNonGTChar				            [\x09\x0A\x0D\x20-\x3D\x3F-\x5C\x5E-\xFD]
CDataChars													({NonClosingSquareBracketChar}|"]"{NonSqBraNonGTChar}|"]]"{NonGreaterThenChar})*"]"*


  /*______________________________________________________________________
   |
   |  Exclusive start states
   |______________________________________________________________________*/

%x MODE_APOS_ATTRIBUTE_CONTENT
%x MODE_QUOTE_ATTRIBUTE_CONTENT
%x MODE_ELEM_COMP_CONSTR
%x MODE_ATTR_COMP_CONSTR
%x MODE_PI_COMP_CONSTR
%x MODE_CDATA_SECTION
%x MODE_ELEMENT_CONTENT
%x MODE_END_TAG
%x MODE_EXPR_COMMENT
%x MODE_EXPR_DOC_COMMENT
%x MODE_OCCURRENCE_INDICATOR
%x MODE_PRAGMA
%x MODE_PRAGMACONTENTS
%x MODE_PROCESSING_INSTRUCTION
%x MODE_PROCESSING_INSTRUCTION_CONTENT
%x MODE_START_TAG
%x MODE_XML_COMMENT


%{
  typedef zorba::xquery_parser::token token;
%}


%%

  /*______________________________________________________________________
   |
   |  INITIAL State
   |
   |  This state is for patterns that occur at the beginning  of an
   |  expression or subexpression.
   |______________________________________________________________________*/

"(" { return token::LPAR; }
";" { return token::SEMI; }
"," { return token::COMMA; }
"-" { return token::MINUS; }
"+" { return token::PLUS; }
"/" { return token::SLASH; }
"//" { return token::SLASH_SLASH; }
"@" { return token::AT_SIGN; }
")" { return token::RPAR; }
"*" { return token::STAR; }
".." { return token::DOT_DOT; }
"." { return token::DOT; }
"?" { return token::HOOK; }
"]" { return token::RBRACK; }
"$" { return token::DOLLAR; }
"#" { return token::HASH; }
":" { return token::COLON; }
"::" { return token::DOUBLE_COLON; }
"%" { return token::PERCENTAGE; }
"||" { return token::CONCAT; }

"declare" {
  std::string lDocComment = theDriver->theDocComment.str();
  yylval->sval = getDriver()->symtab.put_commentcontent(lDocComment.c_str(), lDocComment.length());
  theDriver->theDocComment.str("");
  return token::DECLARE;
}

"module" {
  std::string lDocComment = theDriver->theDocComment.str();
  yylval->sval = getDriver()->symtab.put_commentcontent(lDocComment.c_str(), lDocComment.length());
  theDriver->theDocComment.str("");
  return token::MODULE;
}
    /* Tokens with state transitions */
"element" {  PUSH_STATE(MODE_ELEM_COMP_CONSTR); }
"attribute" { PUSH_STATE(MODE_ATTR_COMP_CONSTR); }
"processing-instruction" { PUSH_STATE(MODE_PI_COMP_CONSTR); }


"if" { return token::IF; }
"returning" { return token::RETURNING; }

"exit" { return token::EXIT; }
"with" { return token::WITH; }
"break" { return token::BREAK; }
"loop" { return token::LOOP; }
"continue" { return token::CONTINUE; }
"while" { return token::WHILE; }
"set" { return token::SET; }
"validate" { return token::VALIDATE; }
"type" { return token::TYPE; }
"switch" { return token::SWITCH; }
"typeswitch" { return token::TYPESWITCH; }
"document" { return token::DOCUMENT; }
"text" { return token::TEXT; }
"comment" { return token::COMMENT; }
"function" { return token::FUNCTION; }
"simple" { return token::SIMPLE; }
"updating" { return token::UPDATING; }
"sequential" { return token::SEQUENTIAL; }
"ordered" { return token::ORDERED;}
"unordered" { return token::UNORDERED; }
"schema-element"  { return token::SCHEMA_ELEMENT; }
"schema-attribute" { return token::SCHEMA_ATTRIBUTE; }
"node" { return token::NODE; }
"document-node" { return token::DOCUMENT_NODE; }
"construction" { return token::CONSTRUCTION; }
"default" { return token::DEFAULT; }
"order" { return token::ORDER; }
"collation" { return token::COLLATION; }
"namespace" { return token::NAMESPACE; }
"base-uri" { return token::BASE_URI; }
"import" { return token::IMPORT; }
"schema" { return token::SCHEMA; }
"copy-namespaces" { return token::COPY_NAMESPACES; }
"for" { return token::FOR; }
"let" { return token::LET; }
"allowing" { return token::ALLOWING; }
"sliding" { return token::SLIDING; }
"tumbling" { return token::TUMBLING; }
"previous" { return token::PREVIOUS; }
"next" { return token::NEXT; }
"only" { return token::ONLY; }
"when" { return token::WHEN; }
"count" { return token::COUNT; }
"using" { return token::USING; }
"some" { return token::SOME; }
"every" { return token::EVERY; }
"context" { return token::CONTEXT; }
"variable" { return token::VARIABLE; }
"boundary-space" { return token::BOUNDARY_SPACE; }
"ordering" { return token::ORDERING; }
"xquery" { return token::XQUERY; }
"version" { return token::VERSION; }
"option" { return token::OPTION; }
"at" { return token::AT; }
"revalidation" { return token::REVALIDATION; }
"as" { return token::AS; }
"try" { return token::TRY; }

  /* Axes */
"ancestor-or-self" { return token::ANCESTOR_OR_SELF; }
"ancestor" { return token::ANCESTOR; }
"child" { return token::CHILD; }
"descendant-or-self" { return token::DESCENDANT_OR_SELF; }
"descendant" { return token::DESCENDANT; }
"following-sibling" { return token::FOLLOWING_SIBLING; }
"following" { return token::FOLLOWING; }
"parent" { return token::PARENT; }
"preceding-sibling" { return token::PRECEDING_SIBLING; }
"preceding" { return token::PRECEDING; }
"self" { return token::SELF;}

  /* Decimal format */
"decimal-format" { return token::DECIMAL_FORMAT; }
"decimal-separator" { return token::DECIMAL_SEPARATOR; }
"grouping-separator" { return token::GROUPING_SEPARATOR; }
"infinity" { return token::INFINITY_VALUE; }
"minus-sign" { return token::MINUS_SIGN; }
"NaN" { return token::NaN; }
"percent" { return token::PERCENT; }
"per-mille" { return token::PER_MILLE; }
"zero-digit" { return token::ZERO_DIGIT; }
"digit" { return token::DIGIT; }
"pattern-separator" { return token::PATTERN_SEPARATOR; }

  /*______________________________________________________________________
   |
   |  Data Definition Facility tokens
   |______________________________________________________________________*/

"collection" { return token::COLLECTION; }
"const" { return token::CONSTOPT; }
"append-only" { return token::APPEND_ONLY; }
"queue" { return token::QUEUE; }
"mutable" { return token::MUTABLE; }
"read-only" { return token::READ_ONLY; }

"index" { return token::INDEX; }
"unique" { return token::UNIQUE; }
"non" { return token::NON; }
"manually" { return token::MANUALLY; }
"automatically" { return token::AUTOMATICALLY; }
"maintained" { return token::MAINTAINED; }
"range" { return token::RANGE; }
"equality" { return token::EQUALITY; }
"on" { return token::ON; }
"general" { return token::GENERAL; }

"integrity" { return token::INTEGRITY; }
"constraint" { return token::CONSTRAINT; }
"check" { return token::CHECK; }
"key" { return token::KEY; }
"foreach" { return token::FOREACH; }
"foreign" { return token::FOREIGN; }
"keys" { return token::KEYS; }


    /*______________________________________________________________________
     |
     | FT tokens
     |______________________________________________________________________*/

"contains" { return token::CONTAINS; }
"ftand" { return token::FTAND; }
"ftor" { return token::FTOR; }
"ftnot" { return token::FTNOT; }
"not" { return token::NOT; }
"in" { return token::_IN; }
"all" { return token::ALL; }
"words" { return token::WORDS; }
"any" { return token::ANY; }
"word" { return token::WORD; }
"end" { return token::END; }
"least" { return token::LEAST; }
"most" { return token::MOST; }
"start" { return token::START; }
"case" { return token::CASE; }
"insensitive" { return token::INSENSITIVE; }
"sensitive" { return token::SENSITIVE; }
"ft-option" { return token::FT_OPTION; }
"diacritics" { return token::DIACRITICS; }
"different" { return token::DIFFERENT; }
"distance" { return token::DISTANCE; }
"entire" { return token::ENTIRE; }
"content" { return token::CONTENT; }
"exactly" { return token::EXACTLY; }
"from" { return token::FROM; }
"language" { return token::LANGUAGE; }
"levels" { return token::LEVELS; }
"lowercase" { return token::LOWERCASE; }
"no" { return token::NO; }
"occurs" { return token::OCCURS; }
"paragraph" { return token::PARAGRAPH; }
"paragraphs" { return token::PARAGRAPHS; }
"phrase" { return token::PHRASE; }
"relationship" { return token::RELATIONSHIP; }
"same" { return token::SAME; }
"score" { return token::SCORE; }
"sentence" { return token::SENTENCE; }
"sentences" { return token::SENTENCES; }
"times" { return token::TIMES; }
"uppercase" { return token::UPPERCASE; }
"weight" { return token::WEIGHT; }
"window" { return token::WINDOW; }
"without" { return token::WITHOUT; }
"stemming" { return token::STEMMING; }
"stop" { return token::STOP; }
"thesaurus" { return token::THESAURUS; }
"wildcards" { return token::WILDCARDS; }
":=" { return token::GETS; }
"div" { return token::DIV; }
"=" { return token::EQUALS; }
"except" { return token::EXCEPT; }
"eq" { return token::VAL_EQ; }
"ge" { return token::VAL_GE; }
"gt" { return token::VAL_GT; }
"le" { return token::VAL_LE; }
"lt" { return token::VAL_LT; }
"ne" { return token::VAL_NE; }
">=" { return token::GE; }
">>" { return token::FOLLOWS; }
">" { return token::GT; }
"idiv" { return token::IDIV; }
"intersect" { return token::INTERSECT; }
"is" { return token::IS; }
"[" { return token::LBRACK; }
"<=" { return token::LE; }
"<<" { return token::PRECEDES; }
"mod" { return token::MOD; }
"!=" { return token::NE; }
"group" { return token::GROUP; }
"by" { return token::BY; }
"stable" { return token::STABLE; }
"or" { return token::OR; }
"return" { return token::RETURN; }
"satisfies" { return token::SATISFIES; }
"to" { return token::TO; }
"union" { return token::UNION; }
"|" { return token::VBAR; }
"where" { return token::WHERE; }
"preserve" { return token::PRESERVE; }
"strip" { return token::STRIP; }


  /*______________________________________________________________________
   |
   | Update rules
   |______________________________________________________________________*/

"insert" { return token::INSERT; }
"delete" { return token::_DELETE; }
"replace" { return token::REPLACE; }
"value" { return token::VALUE; }
"of" { return token::OF; }
"rename" { return token::RENAME; }
"copy" { return token::COPY; }
"nodes" { return token::NODES; }
"into" { return token::INTO; }
"after" { return token::AFTER; }
"before" { return token::BEFORE; }
"modify" { return token::MODIFY; }

"strict" { return token::_STRICT; }
"lax" { return token::LAX; }
"skip" { return token::SKIP; }
"then" { return token::THEN; }
"else" { return token::ELSE; }
"external" { return token::EXTERNAL; }
"and" { return token::AND; }

"inherit" { return token::INHERIT; }
"no-inherit" { return token::NO_INHERIT; }
"no-preserve" { return token::NO_PRESERVE; }
"empty-sequence" { return token::EMPTY_SEQUENCE; }
"item" { return token::ITEM; }
"cast" { return token::CAST; }
"castable" { return token::CASTABLE; }
"instance" { return token::INSTANCE;}
"treat" { return token::TREAT; }
"first" { return token::FIRST; }
"last" { return token::LAST; }
"catch" { return token::CATCH; }
"empty" { return token::_EMPTY; }
"greatest" { return token::GREATEST; }
"ascending" { return token::ASCENDING; }
"descending" { return token::DESCENDING; }
"encoding" { return token::ENCODING; }


  /*______________________________________________________________________
   |
   | Tokens with values
   |______________________________________________________________________*/

{IntegerLiteral}  {
  yylval->ival = getDriver()->symtab.integerval(yytext, yyleng);
  if (yylval->ival == NULL)
  {
    yylval->err = getDriver()->parserErr(yytext, *yylloc, err::FOAR0002);
    return token::UNRECOGNIZED;
  }
  else
    return token::INTEGER_LITERAL;
}

{DecimalLiteral}  {
  yylval->decval = getDriver()->symtab.decimalval(yytext, yyleng);
  return token::DECIMAL_LITERAL;
}

{DoubleLiteral}   {
  yylval->dval = getDriver()->symtab.doubleval(yytext, yyleng);
  if (yylval->dval == NULL)
  {
    // TODO: pjl: needs correct error code
    yylval->err = getDriver()->parserErr(yytext, *yylloc, err::FOAR0002);
    return token::UNRECOGNIZED;
  }
  else
    return token::DOUBLE_LITERAL;
}

{IntegerLiteral}[a-zA-Z_][0-9a-zA-Z_]* {
  /* invalid integer literal */
  yylval->err = getDriver()->parserErr(std::string("syntax error, unexpected \"") + yytext + "\", separator needed after numeric literal", *yylloc);
  return token::UNRECOGNIZED;
}

{NCName}":*"                  { TRY_SVAL_TOKEN(ELEM_WILDCARD, put_ncname(yytext, yyleng-2), yytext); }

{StringLiteral}":*"           { TRY_SVAL_TOKEN(ELEM_EQNAME_WILDCARD, put_ncname(yytext+1, yyleng-4), yytext+1); }

{QName}                       { TRY_SVAL_TOKEN(QNAME_SVAL, put_qname(yytext, yyleng), yytext); }

{AnnotationQName}             { TRY_SVAL_TOKEN(ANNOTATION_QNAME_SVAL, put_qname(yytext+1, yyleng-1), yytext+1); /* skip the % sign */ }

{AnnotationEQName}            { TRY_SVAL_TOKEN(ANNOTATION_EQNAME_SVAL, put_qname(yytext+1, yyleng-1, false, false, true), yytext+1); /* skip the % sign */ }

"*:"{NCName}                  { TRY_SVAL_TOKEN (PREFIX_WILDCARD, put_ncname(yytext+2, yyleng-2), yytext); }

{StringLiteral}               { if (checkXmlRefs(&yylval->err, yytext, yyleng, this, yylloc)) return token::UNRECOGNIZED; TRY_STRING_LITERAL(STRING_LITERAL, yytext, yyleng); }

  /* Invalid string literals */
{InvalidRefStringLiteral}     { yylval->err = getDriver()->invalidCharRef(yytext, *yylloc); return token::UNRECOGNIZED; }
{UnterminatedStringLiteral}   { yylval->err = getDriver()->parserErr(std::string("syntax error, unterminated string literal \"") + yytext + "\"", *yylloc); return token::UNRECOGNIZED; }

  /*______________________________________________________________________
   |
   | State transitions
   |______________________________________________________________________*/

  /* transition to MODE_XML_COMMENT */
  /* ------------------------------ */
"<!--" { PUSH_STATE(MODE_XML_COMMENT); return token::XML_COMMENT_BEGIN; }


  /* transition to PROCESSING_INSTRUCTION */
  /* ------------------------------------ */
"<?" { PUSH_STATE(MODE_PROCESSING_INSTRUCTION);return token::PI_BEGIN; }


  /* transition to CDATA_SECTION */
  /* --------------------------- */
"<![CDATA[" { /* PUSH_AND_BEGIN (MODE_CDATA_SECTION, MODE_OPERATOR); */ return token::CDATA_BEGIN; }


  /* transition to MODE_START_TAG */
  /* ---------------------------- */
"<" { PUSH_STATE(MODE_START_TAG); return token::LT_OR_START_TAG; }


  /* transition to MODE_EXPR_DOC_COMMENT */
  /* ----------------------------------- */
"(:~" { PUSH_STATE(MODE_EXPR_DOC_COMMENT); }


  /* transition to MODE_EXPR_COMMENT */
  /* ------------------------------- */
"(:" { PUSH_STATE(MODE_EXPR_COMMENT); }


  /* transition to PRAGMA */
  /* -------------------- */
"(#" { BEGIN MODE_PRAGMA; return token::PRAGMA_BEGIN;}

  /* push initial state */
  /* ------------------ */
"{" { PUSH_STATE(INITIAL); return token::LBRACE; }


  /* pop previous state */
  /* ------------------ */
"}" {
  if (yy_get_start_stack_ptr() > 0)   // The lexer will catch the unexpected right brace and generate a syntax error
    POP_STATE();
  return token::RBRACE;
}


{S} {
  /* eat up whitespace */
}

  /* END <MODE INITIAL> */


  /*______________________________________________________________________
   |
   | OCCURRENCE_INDICATOR State
   |
   | This special state is needed to distinguish occurrence indicators
   | that appear in the SequenceType production. For instance, compare
   | "foo instance of baz*" to "baz*foo". In the first case, the "*" is
   | interpreted as an occurrence indicator, and in the second case, it
   | must be interpreted as a multiplication operator. But, when in the
   | OCCURRENCEINDICATOR state, if anything else other than "?", "*",
   | "+", those symbols must be interpreted in the OPERATOR state. For
   | instance, this would occur with the expression "foo instance of baz
   | and $x", with the operator "and".
   |______________________________________________________________________*/

  /* <MODE_OCCURRENCE_INDICATOR>{ */

  /* transition to OPERATOR */
  /* ---------------------- */

  /* "?" {
  // TODO:
  return token::OCCURS_HOOK;
}

"*" {
  // TODO:
  return token::OCCURS_STAR;
}

"+" {
  // TODO:
  return token::OCCURS_PLUS;
} */


  /* } */ /* MODE_OCCURRENCE_INDICATOR> */

   /*______________________________________________________________________
    |
    | MODE_ELEM_COMP_CONSTR, MODE_ATTR_COMP_CONSTR and MODE_PI_COMP_CONSTR
    | states
    |
    |______________________________________________________________________*/

<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR>{QName}                     {
  if (yy_comp_constr_qname == "")
    yy_comp_constr_qname = yytext;
  else
    COMP_CONSTR_ROLLBACK(true);
}
<MODE_PI_COMP_CONSTR>{NCName}                                            {
  if (yy_comp_constr_qname == "")
    yy_comp_constr_qname = yytext;
  else
    COMP_CONSTR_ROLLBACK(true);
}
<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR,MODE_PI_COMP_CONSTR>"{"     {
  if ( yy_comp_constr_qname == "")
    COMP_CONSTR_ROLLBACK(true);
  else
  {
    int _STATE = YY_START;
    BEGIN INITIAL;
    std::string temp = yy_comp_constr_qname;
    yy_comp_constr_qname = "";
    if (_STATE == MODE_ELEM_COMP_CONSTR)
      TRY_SVAL_TOKEN(COMP_ELEMENT_QNAME_LBRACE, put_qname(temp.c_str(), temp.size()), temp.c_str());
    else if (_STATE == MODE_ATTR_COMP_CONSTR)
      TRY_SVAL_TOKEN(COMP_ATTRIBUTE_QNAME_LBRACE, put_qname(temp.c_str(), temp.size()), temp.c_str());
    else
      TRY_SVAL_TOKEN(COMP_PI_NCNAME_LBRACE, put_ncname(temp.c_str(), temp.size()), temp.c_str());
  }
}
<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR,MODE_PI_COMP_CONSTR>"(:"       { PUSH_STATE(MODE_EXPR_COMMENT); }
<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR,MODE_PI_COMP_CONSTR>{S}        { /* continue lexing */ }
<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR,MODE_PI_COMP_CONSTR><<EOF>>    { COMP_CONSTR_ROLLBACK(false); }
<MODE_ELEM_COMP_CONSTR,MODE_ATTR_COMP_CONSTR,MODE_PI_COMP_CONSTR>{CatchAll} { COMP_CONSTR_ROLLBACK(true); }


  /*______________________________________________________________________
   |
   | PRAGMA State
   |
   | This state is entered in a a pragma expression, and recognizes
   | a QName that transits to a PRAGMACONTENTS state rather than an
   | OPERATOR state.
   |______________________________________________________________________*/

<MODE_PRAGMA>{QName}{SPNoComment}                    { BEGIN MODE_PRAGMACONTENTS; TRY_SVAL_TOKEN(QNAME_SVAL,  put_qname(yytext, yyleng, true, true), yytext); }
<MODE_PRAGMA>{StringLiteral}":"{NCName}{SPNoComment} { BEGIN MODE_PRAGMACONTENTS; TRY_SVAL_TOKEN(EQNAME_SVAL, put_qname(yytext, yyleng, true, true), yytext); }
<MODE_PRAGMA>{QName}"#)"                             { BEGIN INITIAL; TRY_SVAL_TOKEN(QNAME_SVAL_AND_END_PRAGMA,  put_qname(yytext, yyleng-2), yytext); }
<MODE_PRAGMA>{StringLiteral}":"{NCName}"#)"          { BEGIN INITIAL; TRY_SVAL_TOKEN(EQNAME_SVAL_AND_END_PRAGMA, put_qname(yytext, yyleng-2), yytext); }
<MODE_PRAGMA>{S} { /* continue lexing */ }


  /*______________________________________________________________________
   |
   | PRAGMACONTENTS State
   |
   | This state recognizes characters in pragma content and transitions
   | out of this state when a '#)' pattern is recognized.
   |______________________________________________________________________*/

<MODE_PRAGMACONTENTS>{PragmaChars}"#)" { BEGIN INITIAL; TRY_SVAL_TOKEN(PRAGMA_LITERAL_AND_END_PRAGMA, put(yytext, yyleng-2), yytext); }


  /*______________________________________________________________________
   |
   | START_TAG State
   |
   | This state allows attributes in the native XML syntax, and marks the
   | beginning of an element construction. Element constructors also push
   | the current state, popping it at the conclusion of an end tag. In
   | the START_TAG state, the string ">" is recognized as a token which
   | is associated with the transition to the original state.
   |______________________________________________________________________*/

<MODE_START_TAG>">" { BEGIN MODE_ELEMENT_CONTENT; return token::TAG_END; }
<MODE_START_TAG>\" { BEGIN MODE_QUOTE_ATTRIBUTE_CONTENT; return token::QUOTE; }
<MODE_START_TAG>\' { BEGIN MODE_APOS_ATTRIBUTE_CONTENT; return token::APOS; }
<MODE_START_TAG>"=" { return token::EQUALS; }
<MODE_START_TAG>{S} { return token::BLANK; }
<MODE_START_TAG>"/>" { POP_STATE(); return token::EMPTY_TAG_END; }
<MODE_START_TAG>{QName} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng), yytext); }
<MODE_START_TAG>{CatchAll} { yylval->err = getDriver()->unrecognizedCharErr(yytext, *yylloc); return token::UNRECOGNIZED; }
<MODE_START_TAG><<EOF>> { yylval->err = getDriver()->unterminatedElementConstructor(*yylloc); return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | ELEMENT_CONTENT State
   |
   | This state allows XML-like content, without these characters being
   | misinterpreted as expressions. The character "{" marks a transition
   | to the INITIAL state, i.e. the start of an embedded expression, and
   | the "}" character pops back to the ELEMENT_CONTENT state. To allow
   | curly braces to be used as character content, a double left or right
   | curly brace is interpreted as a single curly brace character. The
   | string "</" is interpreted as the beginning of an end tag, which is
   | associated with a transition to the END_TAG state.
   |______________________________________________________________________*/

<MODE_ELEMENT_CONTENT>"</" { BEGIN MODE_END_TAG; return token::START_TAG_END; }
<MODE_ELEMENT_CONTENT>"{" { PUSH_STATE(INITIAL); return token::LBRACE; }
<MODE_ELEMENT_CONTENT>"<!--" { PUSH_STATE(MODE_XML_COMMENT); return token::XML_COMMENT_BEGIN; }
<MODE_ELEMENT_CONTENT>"<?" { PUSH_STATE(MODE_PROCESSING_INSTRUCTION); return token::PI_BEGIN; }
<MODE_ELEMENT_CONTENT>"<![CDATA[" { PUSH_STATE(MODE_CDATA_SECTION); return token::CDATA_BEGIN; }
<MODE_ELEMENT_CONTENT>"<" { PUSH_STATE(MODE_START_TAG); return token::LT_OR_START_TAG; }
<MODE_ELEMENT_CONTENT>{ElementContentChar}+ { TRY_SVAL_TOKEN(ELEMENT_CONTENT, put(yytext, yyleng, 1), yytext); }
<MODE_ELEMENT_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN(ELEMENT_CONTENT, put_entityref(yytext, yyleng), yytext); }
<MODE_ELEMENT_CONTENT>{CharRef}+ { TRY_CHARREF_LITERAL(CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_ELEMENT_CONTENT>"{{" { return token::DOUBLE_LBRACE; }
<MODE_ELEMENT_CONTENT>"}}" { return token::DOUBLE_RBRACE; }
<MODE_ELEMENT_CONTENT><<EOF>> { yylval->err = getDriver()->noClosingTagForElementConstructor(*yylloc); return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | END_TAG State
   |
   | When the end tag is terminated, the state is popped to the state
   | that was pushed at the start of the corresponding start tag.
   |______________________________________________________________________*/

<MODE_END_TAG>">" { POP_STATE(); return token::TAG_END; }
<MODE_END_TAG>{QName}{S} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng, false, true), yytext); }
<MODE_END_TAG><<EOF>> { yylval->err = getDriver()->noClosingTagForElementConstructor(*yylloc); return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | XML_COMMENT State
   | The "<--" token marks the beginning of an XML Comment, and the "-->"
   | token marks the end. This allows no special interpretation of other
   | characters in this state.
   |______________________________________________________________________*/

<MODE_XML_COMMENT>"-->" { POP_STATE(); return token::XML_COMMENT_END; }
<MODE_XML_COMMENT>{XMLCommentChar}* { TRY_SVAL_TOKEN (XML_COMMENT_LITERAL, put(yytext, yyleng, 1), yytext); }


  /*______________________________________________________________________
   |
   | EXPR_COMMENT State
   |
   | The "(:" token marks the beginning of an expression Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

<MODE_EXPR_COMMENT>":)"    { POP_STATE(); }
<MODE_EXPR_COMMENT>"(:"    { PUSH_STATE(MODE_EXPR_COMMENT); }
<MODE_EXPR_COMMENT>[^:)(]+ { /* do nothing */ }
<MODE_EXPR_COMMENT>.       { /* do nothing */ }
<MODE_EXPR_COMMENT><<EOF>> { yylval->err = getDriver()->unterminatedCommentErr(*yylloc); return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | EXPR_DOC_COMMENT State
   |
   | The "(:~" token marks the beginning of a doc Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

<MODE_EXPR_DOC_COMMENT>[^:]*    { getDriver()->theDocComment << yytext; }
<MODE_EXPR_DOC_COMMENT>":"+[^)] { getDriver()->theDocComment << yytext; }
<MODE_EXPR_DOC_COMMENT>":"+")"  { POP_STATE(); }
<MODE_EXPR_DOC_COMMENT><<EOF>>  { yylval->err = getDriver()->unterminatedCommentErr(*yylloc); return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION State
   |
   | In this state, only patterns that are legal in a processing
   | instruction name are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION>{SP} { BEGIN MODE_PROCESSING_INSTRUCTION_CONTENT; /* continue lexing */ }
<MODE_PROCESSING_INSTRUCTION>"?>" { POP_STATE(); return token::PI_END; }
<MODE_PROCESSING_INSTRUCTION>{NCName} /* PITarget */    { TRY_SVAL_TOKEN (NCNAME_SVAL, put(yytext, yyleng), yytext); }


  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION_CONTENT State
   |
   | In this state, only characters are that are legal in processing
   | instruction content are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION_CONTENT>{PIChars}"?>" {
  POP_STATE();
  TRY_SVAL_TOKEN (CHAR_LITERAL_AND_PI_END, put(yytext, yyleng-2), yytext);
}


  /*______________________________________________________________________
   |
   | CDATA_SECTION State
   |
   | In this state, only lexemes that are legal in a CDATA section are
   | recognized.
   |______________________________________________________________________*/

<MODE_CDATA_SECTION>{CDataChars}"]]>" { POP_STATE(); TRY_SVAL_TOKEN (CHAR_LITERAL_AND_CDATA_END, put(yytext, yyleng-3, 1), yytext); }


  /*______________________________________________________________________
   |
   | QUOTE_ATTRIBUTE_CONTENT State
   |
   | This state allows content legal for attributes. The character "{"
   | marks a transition to the INITIAL state, i.e. the start of an
   | embedded expression, and the "}" character pops back to the original
   | state.  To allow curly braces to be used as character content, a
   | double left or right curly brace is interpreted as a single curly
   | brace character. This state is the same as APOS_ATTRIBUTE_CONTENT,
   | except that apostrophes are allowed without escaping, and an
   | unescaped quote marks the end of the state.
   |______________________________________________________________________*/

<MODE_QUOTE_ATTRIBUTE_CONTENT>\" { BEGIN MODE_START_TAG; return token::QUOTE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"{" { PUSH_STATE(INITIAL); return token::LBRACE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{EscapeQuot} { return token::ESCAPE_QUOTE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{QuotAttrContentChar}+ { TRY_SVAL_TOKEN(QUOTE_ATTR_CONTENT, put(yytext, yyleng, 2), yytext); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN(QUOTE_ATTR_CONTENT, put_entityref(yytext, yyleng), yytext); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{CharRef}+ { TRY_CHARREF_LITERAL(CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"{{" { return token::DOUBLE_LBRACE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"}}" { return token::DOUBLE_RBRACE; }


  /*______________________________________________________________________
   |
   | APOS_ATTRIBUTE_CONTENT State
   |
   | This state is the same as QUOT_ATTRIBUTE_CONTENT, except that
   | quotes are allowed, and an unescaped apostrophe marks the end of
   | the state.
   |______________________________________________________________________*/

<MODE_APOS_ATTRIBUTE_CONTENT>\'                     { BEGIN MODE_START_TAG; return token::APOS; }
<MODE_APOS_ATTRIBUTE_CONTENT>"{"                    { PUSH_AND_BEGIN (INITIAL, MODE_APOS_ATTRIBUTE_CONTENT); return token::LBRACE; }
<MODE_APOS_ATTRIBUTE_CONTENT>{EscapeApos}           { return token::ESCAPE_APOS; }
<MODE_APOS_ATTRIBUTE_CONTENT>{AposAttrContentChar}+ { TRY_SVAL_TOKEN(APOS_ATTR_CONTENT, put(yytext, yyleng, 2), yytext); }
<MODE_APOS_ATTRIBUTE_CONTENT>{PredefinedEntityRef}  { TRY_SVAL_TOKEN(APOS_ATTR_CONTENT, put_entityref(yytext, yyleng), yytext); }
<MODE_APOS_ATTRIBUTE_CONTENT>{CharRef}+             { TRY_CHARREF_LITERAL(CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_APOS_ATTRIBUTE_CONTENT>"{{"                   { return token::DOUBLE_LBRACE; }
<MODE_APOS_ATTRIBUTE_CONTENT>"}}"                   { return token::DOUBLE_RBRACE; }


  /*______________________________________________________________________
   |
   | Catch-all rule
   |______________________________________________________________________*/


<*>. {
    yylval->err = getDriver()->unrecognizedCharErr(yytext, *yylloc);
    return token::UNRECOGNIZED;
}


  /* END OF FLEX RULES */


%%


std::string start_state(int state)
{
  switch (state)
  {
    case INITIAL: return "INITIAL";
    case MODE_APOS_ATTRIBUTE_CONTENT: return "MODE_APOS_ATTRIBUTE_CONTENT";
    case MODE_ELEM_COMP_CONSTR: return "MODE_ELEM_COMP_CONSTR";
    case MODE_ATTR_COMP_CONSTR: return "MODE_ATTR_COMP_CONSTR";
    case MODE_CDATA_SECTION: return "MODE_CDATA_SECTION";
    case MODE_ELEMENT_CONTENT: return "MODE_ELEMENT_CONTENT";
    case MODE_END_TAG: return "MODE_END_TAG";
    case MODE_EXPR_DOC_COMMENT: return "MODE_EXPR_DOC_COMMENT";
    case MODE_EXPR_COMMENT: return "MODE_EXPR_COMMENT";
    case MODE_OCCURRENCE_INDICATOR: return "MODE_OCCURRENCE_INDICATOR";
    case MODE_PRAGMA: return "MODE_PRAGMA";
    case MODE_PRAGMACONTENTS: return "MODE_PRAGMACONTENTS";
    case MODE_PROCESSING_INSTRUCTION: return "MODE_PROCESSING_INSTRUCTION";
    case MODE_PROCESSING_INSTRUCTION_CONTENT: return "MODE_PROCESSING_INSTRUCTION_CONTENT";
    case MODE_QUOTE_ATTRIBUTE_CONTENT: return "MODE_QUOTE_ATTRIBUTE_CONTENT";
    case MODE_START_TAG: return "MODE_START_TAG";
    case MODE_XML_COMMENT: return "MODE_XML_COMMENT";
    default: return "[zorba] Unrecognized start state. If a new state has been created, translation should be added to start_state() in xquery_scanner.l \n";
  }
}


namespace zorba {

xquery_scanner::xquery_scanner(
  xquery_driver* aDriver,
  std::istream* i,
  std::ostream* o)
  :
  ZorbaFlexLexer(i, o), theDriver(aDriver), cond_stk_depth(0), yy_comp_constr_qname("")
{
}

xquery_scanner::~xquery_scanner()
{
}

void xquery_scanner::set_yy_flex_debug(bool aBool)
{
  yy_flex_debug = aBool;
}

int xquery_scanner::interpretAsLessThan()
{
  BEGIN INITIAL;
  POP_STATE();
  return 0;
}

int xquery_scanner::yy_get_start_stack_ptr() const
{
  return yy_start_stack_ptr;
}

} /* namespace zorba */

#ifdef yylex
#undef yylex
#endif

int ZorbaFlexLexer::yylex()
{
  return 0;
}
