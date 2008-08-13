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

#include "zorbatypes/representations.h"

#include "common/common.h"
#include "util/properties.h"

#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <string>

using namespace std;

#include "compiler/parser/xquery_parser.hpp"
#include "compiler/parser/xquery_scanner.h"
#include "compiler/parser/xquery_driver.h"

typedef zorba::xquery_parser::token token;
typedef zorba::xquery_parser::token_type token_type;

#define PUSH_STATE(state) \
    do { \
        yy_push_state(state); \
        getDriver()->push_state_stack(); \
    } while(0)

#define POP_STATE() \
    do { \
        yy_pop_state(); \
        getDriver()->pop_state_stack(); \
    } while(0)

#define PUSH_AND_BEGIN( pushed, new ) \
    do { \
        BEGIN new; \
        PUSH_STATE(pushed); \
    } while(0)

#define TRY_SVAL_TOKEN( ttype, put )                                    \
  do {                                                                  \
    off_t res = getDriver()->symtab.put;                                \
    if (res < 0) return token::UNRECOGNIZED;                            \
    else {                                                              \
      yylval->sval = res;                                               \
      return token::ttype;                                              \
    }                                                                   \
  } while (0)

#define TRY_STR_LIT( ttype, put, yytext, yyleng ) \
  TRY_SVAL_TOKEN (ttype, put (yytext, yyleng))

#define TRY_STRINGLIT( ttype, yytext, yyleng ) \
  TRY_STR_LIT (ttype, put_stringlit, yytext, yyleng)

#define TRY_URILIT( ttype, yytext, yyleng ) \
  TRY_STR_LIT (ttype, put_uri, yytext, yyleng)

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

std::string start_state(int);
    
#define YY_USER_ACTION \
{ \
  if (yy_flex_debug) { \
    std::cout<<'<'<<start_state(YY_START)<<">" /* << " [["<<yytext<<"]]" */ << std::endl; \
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
/* %option case-insensitive */
/* %option nostdinit */
%option noyywrap
%option batch
%option debug
%option stack
/* %option reentrant */
%option nounistd
%option c++
%option prefix="Zorba"
      

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
Letter      [A-Za-z]
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
Nmstart     ({Letter}|_)
Nmchar      ({Letter}|{Digit}|[._-])
NCName      {Nmstart}{Nmchar}*

  /*_____________________________________________________________________
   |
   |  QName definition
   |______________________________________________________________________*/
QName       ({NCName}":")?{NCName}

  /*_____________________________________________________________________
   |
   |  VarName definition
   |______________________________________________________________________*/
  /* VarName     {QName} */


  /*_____________________________________________________________________
   |
   |  Entity definitions
   |______________________________________________________________________*/
CharRef               "&#"([0-9]+|x([0-9]|[a-f]|[A-F])+);
PredefinedEntityRef   "&"(lt|gt|amp|quot|apos|nbsp);
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
NonQuotAnd            [^""&]
NonAposAnd            [^''&]
StringLiteral         ({Quote}({EscapeQuot}|{Ref}|{NonQuotAnd})*{Quote})|({Apos}({EscapeApos}|{Ref}|{NonAposAnd})*{Apos})

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

  /*
  NonXChar  [\x09\x0A\x0D\x20A-WY-Za-wy-z\x7B-\xFD]
  NonMChar  [\x09\x0A\x0D\x20A-LN-Za-ln-z\x7B-\xFD]
  NonLChar  [\x09\x0A\x0D\x20A-KM-Za-km-z\x7B-\xFD]

  PITarget  (({NonXChar}{Char}*)|((X|x){NonMChar}{Char}*)|((X|x)(M|m){NonLChar}*)|({Char}{Char}{Char}{Char}+))
  */

PITargetStart         [_:A-\xFF]
PITargetName          [.\-_:0-9A-\xFF]
PITarget              {PITargetStart}{PITargetName}*

NonQuestionMarkChar                 [\x09\x0A\x0D\x20-\x3E\x40-\xFD]
NonGreaterThanNonQuestionMarkChar   [\x09\x0A\x0D\x20-\x3D\x40-\xFD]
PIChars                             ({NonQuestionMarkChar}|"?"+{NonGreaterThanNonQuestionMarkChar})*"?"*

NonSharpPragmaChar                  [\x09\x0A\x0D\x20-\x22\x24-\xFD]
NonSharpNonParPragmaChar            [\x09\x0A\x0D\x20-\x28\x2A-\xFD]
PragmaChars                         ({NonSharpPragmaChar}|"#"+{NonSharpNonParPragmaChar})*"#"*

  /*______________________________________________________________________
   |
   |  Exclusive start states
   |______________________________________________________________________*/

%x MODE_APOS_ATTRIBUTE_CONTENT
%x MODE_CDATA_SECTION
%x MODE_CLOSE_KINDTEST
%x MODE_DECLAREORDERING
%x MODE_ELEMENT_CONTENT
%x MODE_END_TAG
%x MODE_EXPR_COMMENT
%x MODE_ITEMTYPE
%x MODE_KINDTEST
%x MODE_KINDTESTFORPI
%x MODE_NAMESPACEDECL
%x MODE_NAMESPACEKEYWORD
%x MODE_OCCURRENCE_INDICATOR
%x MODE_OPERATOR
%x MODE_OPTION
%x MODE_PRAGMA
%x MODE_PRAGMACONTENTS
%x MODE_PROCESSING_INSTRUCTION_CTOR
%x MODE_PROCESSING_INSTRUCTION
%x MODE_PROCESSING_INSTRUCTION_CONTENT
%x MODE_QUOTE_ATTRIBUTE_CONTENT
%x MODE_SINGLETYPE
%x MODE_START_TAG
%x MODE_URITOOPERATOR
%x MODE_VARNAME
%x MODE_XMLSPACE_DECL
%x MODE_XML_COMMENT
%x MODE_XQUERY_VERSION

/* Update Modes */
%x MODE_DECLAREREVALIDATION

/* Try-Catch Modes */
%x MODE_CATCH


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
"/ " { return token::LEADING_LONE_SLASH; }
"//" { return token::SLASH_SLASH; }
"@" { return token::AT_SIGN; }
")" { return token::RPAR; }
"*" { return token::STAR; }
".." { return token::DOT_DOT; }
"." { return token::DOT; }
"?" { return token::HOOK; }
"]" { return token::RBRACK; }
"$" { return token::DOLLAR; }

"if" { return token::IF; }
"exit" { return token::EXIT; }
"with" { return token::WITH; }
"break" { return token::BREAK; }
"loop" { return token::LOOP; }
"continue" { return token::CONTINUE; }
"while" { return token::WHILE; }
"validate" { return token::VALIDATE; }
"typeswitch" { return token::TYPESWITCH; }
"eval" { return token::EVAL; }
"element" { return token::ELEMENT; }
"attribute" { return token::ATTRIBUTE; }
"document" { return token::DOCUMENT; }
"text" { return token::TEXT; }
"processing-instruction" { return token::PROCESSING_INSTRUCTION; }
"comment" { return token::COMMENT; }
"declare" { return token::DECLARE; }
"function" { return token::FUNCTION; }
"updating" { return token::UPDATING; }
"sequential" { return token::SEQUENTIAL; }
"ordered" { return token::ORDERED;}
"unordered" { return token::UNORDERED; }
"schema-element"  { return token::SCHEMA_ELEMENT; }
"schema-attribute" { return token::SCHEMA_ATTRIBUTE; }
"node" { return token::NODE; }
"document-node" { return token::DOCUMENT_NODE; }

"ancestor-or-self::" { return token::ANCESTOR_OR_SELF_AXIS; }
"ancestor::" { return token::ANCESTOR_AXIS; }
"attribute::" { return token::ATTRIBUTE_AXIS; }
"child::" { return token::CHILD_AXIS; }
"descendant-or-self::" { return token::DESCENDANT_OR_SELF_AXIS; }
"descendant::" { return token::DESCENDANT_AXIS; }
"following-sibling::" { return token::FOLLOWING_SIBLING_AXIS; }
"following::" { return token::FOLLOWING_AXIS; }
"parent::" { return token::PARENT_AXIS; }
"preceding-sibling::" { return token::PRECEDING_SIBLING_AXIS; }
"preceding::" { return token::PRECEDING_AXIS; }
"self::" { return token::SELF_AXIS;}

"construction" { return token::CONSTRUCTION; }
"default" { return token::DEFAULT; }
"order" { return token::ORDER; }
"collation" { return token::COLLATION; }
"namespace" { return token::NAMESPACE; }
"module" { return token::MODULE; }
"base-uri" { return token::BASE_URI; }
"import" { return token::IMPORT; }
"schema" { return token::SCHEMA; }
"copy-namespaces" { return token::COPY_NAMESPACES; }
"for" { return token::FOR; }
"let" { return token::LET; }
"using" { return token::USING; }
"some" { return token::SOME; }
"every" { return token::EVERY; }
"variable" { return token::VARIABLE; }
"boundary-space" { return token::BOUNDARY_SPACE; }
"ordering" { return token::ORDERING; }
"xquery" { return token::XQUERY; }
"version" { return token::VERSION; }
"option" { return token::OPTION; }
"at" { return token::AT; }
"revalidation" { return token::REVALIDATION;}
"as" { return token::AS; }

"try" { return token::TRY;}
 
    /*______________________________________________________________________
     |
     | FT tokens
     |______________________________________________________________________*/

"&&" { return token::FTAND; }
"!" { return token::FTNOT; }
"||" { return token::FTOR; }
"not" { return token::FTNOT; }
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
"occurs" { return token::OCCURS; }
"paragraph" { return token::PARAGRAPH; }
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
"rename" {
  // TODO:
  // getDriver()->set_rename(true);
  return token::RENAME;
}
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

"ftcontains" {
  // TODO: this flag should not be needed anymore
  // BEGIN INITIAL;
  // getDriver()->set_ftcontains(true);
  return token::FTCONTAINS;
}


  /* TODO: fix 'if (1) then 2 else processing-instruction' */


  /*______________________________________________________________________
   |
   | Tokens with values
   |______________________________________________________________________*/

{IntegerLiteral}  {
  yylval->ival = getDriver()->symtab.integerval(yytext, yyleng);
  return token::INTEGER_LITERAL;
}

{DecimalLiteral}  {
  yylval->decval = getDriver()->symtab.decimalval(yytext, yyleng);
  return token::DECIMAL_LITERAL;
}

{DoubleLiteral}   {
  yylval->dval = getDriver()->symtab.doubleval(yytext, yyleng);
  return token::DOUBLE_LITERAL;
}

{IntegerLiteral}[a-zA-Z_][0-9a-zA-Z_]* {
  /* invalid integer literal */
  return token::UNRECOGNIZED;
}

{NCName}":*" {
  TRY_SVAL_TOKEN (ELEM_WILDCARD, put_ncname(yytext, yyleng-2));
}

{QName} {
  TRY_SVAL_TOKEN(QNAME_SVAL, put_qname(yytext, yyleng));
}

"*:"{NCName} {
  TRY_SVAL_TOKEN (PREFIX_WILDCARD, put_ncname(yytext+2, yyleng-2));
}

{StringLiteral} { 
  TRY_STRINGLIT (STRING_LITERAL, yytext, yyleng);
}

  /*______________________________________________________________________
   |
   | State transitions
   |______________________________________________________________________*/

"<!--" { PUSH_STATE(MODE_XML_COMMENT); return token::XML_COMMENT_BEGIN; }

  /* transition to PROCESSING_INSTRUCTION */
  /* ------------------------------------ */
"<?" {
  PUSH_STATE(MODE_PROCESSING_INSTRUCTION);
  return token::PI_BEGIN;
}

  /* transition to CDATA_SECTION */
  /* --------------------------- */
"<![CDATA[" {
  // PUSH_AND_BEGIN (MODE_CDATA_SECTION, MODE_OPERATOR);
  return token::CDATA_BEGIN;
}

"<" { PUSH_STATE(MODE_START_TAG); return token::LT_OR_START_TAG; }

"(:" { PUSH_STATE(MODE_EXPR_COMMENT); }

  /* transition to PRAGMA */
  /* -------------------- */
"(#" {
  BEGIN MODE_PRAGMA;
  return token::PRAGMA_BEGIN;
}

  /* push initial state */
  /* ------------------ */
"{" { PUSH_STATE(INITIAL); return token::LBRACE; }

  /* pop previous state */
  /* ------------------ */
"}" { POP_STATE(); return token::RBRACE; }

{S} {
  /* eat up whitespace */
}

  /* END <MODE INITIAL> */


  /*______________________________________________________________________
   |
   |  The PROCESSING_INSTRUCTION_CTOR State
   |
   |  transition to MODE_OPERATOR
   |______________________________________________________________________*/

  /* <MODE_PROCESSING_INSTRUCTION_CTOR>{ */


  /* } */  /* END <MODE_PROCESSING_INSTRUCTION_CTOR> */


  /*______________________________________________________________________
   |
   |  OPERATOR State
   |
   |  This state is for patterns that are defined for operators.
   |______________________________________________________________________*/

  /* <MODE_OPERATOR>{ */


  /*______________________________________________________________________
   |
   | FT rules <OPERATOR>
   |______________________________________________________________________*/

  /* } */  /* END <MODE_OPERATOR> */

  /*______________________________________________________________________
   |
   | XQUERY_VERSION State
   |
   | This state is for recognition of XQuery version specific keywords.
   |______________________________________________________________________*/

  /* <MODE_XQUERY_VERSION>{ */

  /* } */ /* END <MODE_XQUERY_VERSION> */

  /*______________________________________________________________________
   |
   | NAMESPACEDECL State
   |
   | This state occurs inside of a namespace declaration, and is needed
   | to recognize a NCName that is to be used as the prefix, as opposed
   | to allowing a QName to occur. (Otherwise, the difference between
   | NCName and QName becomes ambiguous.)
   |______________________________________________________________________*/

  /* <MODE_NAMESPACEDECL>{ */

  /* } */ /* END <MODE_NAMESPACEDECL> */ 


  /*______________________________________________________________________
   |
   | URITOOPERATOR State
   |
   | This state is to recognize a URILiteral that transitions to the
   | OPERATOR state.
   |______________________________________________________________________*/


  /*______________________________________________________________________
   |
   | NAMESPACEKEYWORD State
   |
   | This state occurs at places where the keyword "namespace" is
   | expected, which would otherwise be ambiguous compared to a QName.
   | QNames can not occur in this state.
   |______________________________________________________________________*/

  /* <MODE_NAMESPACEKEYWORD>{ */

  /* } */  /* END <MODE_NAMESPACEKEYWORD> */

  
   /*______________________________________________________________________
    |
    | XMLSPACE_DECL State
    |
    | This state occurs at places where the keywords "preserve" and
    | "strip" is expected to support "declare xmlspace". QNames cannot
    | occur in this state.
    |______________________________________________________________________*/

  /* <MODE_XMLSPACE_DECL>{ */

  /* transition to INITIAL */
  /* --------------------- */

  /* } */ /* END <MODE_XMLSPACE_DECL> */


  /*______________________________________________________________________
   |
   | SINGLETYPE State
   |
   | This state distinguishes tokens that can occur only inside the
   | SingleType production.
   |______________________________________________________________________*/

  /* <MODE_SINGLETYPE>{ */

  /* } */  /* END <MODE_SINGLETYPE> */


  /*______________________________________________________________________
   |
   | ITEMTYPE State
   |
   | This state distinguishes tokens that can occur only inside the
   | ItemType production.
   |______________________________________________________________________*/

  /* <MODE_ITEMTYPE>{ */

  /* } */ /* END <MODE_ITEMTYPE> */


  /*______________________________________________________________________
   |
   | KINDTEST State
   |
   | This state is for the psuedo-parameters for the KindTest productions
   |______________________________________________________________________*/

  /* <MODE_KINDTEST>{ */

  /* } */ /* END <MODE_KINDTEST> */


  /*______________________________________________________________________
   |
   | KINDTESTFORPI
   |
   | This state is similar to KINDTEST, but recognizes NCNames instead of
   | QNames.
   |______________________________________________________________________*/

  /* <MODE_KINDTESTFORPI>{ */

  /* } */  /* END <MODE_KINDTESTFORPI> */


  /*______________________________________________________________________
   |
   | CLOSE_KINDTEST State
   |
   | This state is expecting to close a KINDTEST sequence.
   |______________________________________________________________________*/

  /* <MODE_CLOSE_KINDTEST>{ */

  /* } */  /* END <MODE_CLOSE_KINDTEST> */


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
   | OPTION State
   |
   | This state is entered in the prolog for an option declaration, and
   | recognizes a QName that transits to a INITIAL state rather than a
   | OPERATOR state.
   |______________________________________________________________________*/

  /* <MODE_OPTION>{ */

  /* } */  /* END <MODE_OPTION> */


  /*______________________________________________________________________
   |
   | PRAGMA State
   |
   | This state is entered in a a pragma expression, and recognizes
   | a QName that transits to a PRAGMACONTENTS state rather than an
   | OPERATOR state.
   |______________________________________________________________________*/

  /* <MODE_PRAGMA>{  */

<MODE_PRAGMA>{QName}{SPNoComment} { BEGIN MODE_PRAGMACONTENTS; TRY_SVAL_TOKEN(QNAME_SVAL, put_qname(yytext, yyleng, true, true)); }
<MODE_PRAGMA>{QName}"#)" { BEGIN INITIAL; TRY_SVAL_TOKEN(QNAME_SVAL_AND_END_PRAGMA, put_qname(yytext, yyleng-2)); }
<MODE_PRAGMA>{S} { /* continue lexing */ }

  /* } */  /* END <MODE_PRAGMA> */

  
  /*______________________________________________________________________
   |
   | PRAGMACONTENTS State
   |
   | This state recognizes characters in pragma content and transitions
   | out of this state when a '#)' pattern is recognized.
   |______________________________________________________________________*/

  /* <MODE_PRAGMACONTENTS>{  */

<MODE_PRAGMACONTENTS>{PragmaChars}"#)" { BEGIN INITIAL; TRY_SVAL_TOKEN(PRAGMA_LITERAL_AND_END_PRAGMA, put(yytext, yyleng-2)); }

  /* } */  /* END <MODE_PRAGMACONTENTS> */


  /*______________________________________________________________________
   |
   | VARNAME State
   |
   | This state differentiates variable names from qualified names. This
   | allows only the pattern of a QName to be recognized when otherwise
   | ambiguities could occur.
   |______________________________________________________________________*/

  /* <MODE_VARNAME>{ */

  /* } */ /* END <MODE_VARNAME> */


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

  /* <MODE_START_TAG>{ */  /* TODO: this one is needed */

<MODE_START_TAG>">" { BEGIN MODE_ELEMENT_CONTENT; return token::TAG_END; }
<MODE_START_TAG>\" { BEGIN MODE_QUOTE_ATTRIBUTE_CONTENT; return token::QUOTE; }
<MODE_START_TAG>\' { BEGIN MODE_APOS_ATTRIBUTE_CONTENT; return token::APOS; }
<MODE_START_TAG>"=" { return token::EQUALS; }
<MODE_START_TAG>{S} { return token::BLANK; }
<MODE_START_TAG>"/>" { POP_STATE(); return token::EMPTY_TAG_END; }
<MODE_START_TAG>{QName} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng)); }
<MODE_START_TAG>{CatchAll} { return token::UNRECOGNIZED; }

  /* } */  /* END <MODE_START_TAG> */


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

  /* <MODE_ELEMENT_CONTENT>{ */

<MODE_ELEMENT_CONTENT>"</" { BEGIN MODE_END_TAG; return token::START_TAG_END; }
<MODE_ELEMENT_CONTENT>"{" { PUSH_STATE(INITIAL); return token::LBRACE; }
<MODE_ELEMENT_CONTENT>"<!--" { PUSH_STATE(MODE_XML_COMMENT); return token::XML_COMMENT_BEGIN; }
<MODE_ELEMENT_CONTENT>"<?" { PUSH_STATE(MODE_PROCESSING_INSTRUCTION); return token::PI_BEGIN; }
<MODE_ELEMENT_CONTENT>"<![CDATA[" { PUSH_STATE(MODE_CDATA_SECTION); return token::CDATA_BEGIN; }
<MODE_ELEMENT_CONTENT>"<" { PUSH_STATE(MODE_START_TAG); return token::LT_OR_START_TAG; }
<MODE_ELEMENT_CONTENT>{ElementContentChar}+ { TRY_SVAL_TOKEN (ELEMENT_CONTENT, put(yytext, yyleng, true)); }
<MODE_ELEMENT_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN (ELEMENT_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_ELEMENT_CONTENT>{CharRef}+ { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_ELEMENT_CONTENT>"{{" { return token::DOUBLE_LBRACE; }
<MODE_ELEMENT_CONTENT>"}}" { return token::DOUBLE_RBRACE; }

  /* } */ /* MODE_ELEMENT_CONTENT> */


  /*______________________________________________________________________
   |
   | END_TAG State
   |
   | When the end tag is terminated, the state is popped to the state
   | that was pushed at the start of the corresponding start tag.
   |______________________________________________________________________*/

  /* <MODE_END_TAG>{ */

<MODE_END_TAG>">" { POP_STATE(); return token::TAG_END; }
<MODE_END_TAG>{QName}{S} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng, false, true)); }

  /* } */  /* END <MODE_END_TAG> */


  /*______________________________________________________________________
   |
   | XML_COMMENT State
   | The "<--" token marks the beginning of an XML Comment, and the "-->"
   | token marks the end. This allows no special interpretation of other
   | characters in this state.
   |______________________________________________________________________*/

  /* <MODE_XML_COMMENT>{  */
  
<MODE_XML_COMMENT>"-->" { POP_STATE(); return token::XML_COMMENT_END; }
<MODE_XML_COMMENT>{XMLCommentChar}* { TRY_SVAL_TOKEN (XML_COMMENT_LITERAL, put(yytext, yyleng)); }

  /* } */  /* END <MODE_XML_COMMENT> */


  /*______________________________________________________________________
   |
   | EXPR_COMMENT State
   |
   | The "(:" token marks the beginning of an expression Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

  /* <MODE_EXPR_COMMENT>{  */

<MODE_EXPR_COMMENT>":)" { POP_STATE(); }
<MODE_EXPR_COMMENT>"(:" { PUSH_STATE(MODE_EXPR_COMMENT); }
<MODE_EXPR_COMMENT>.|"\n" { /* do nothing */ }
<MODE_EXPR_COMMENT><<EOF>> { return token::UNRECOGNIZED; }

  /* } */  /* END <MODE_EXPR_COMMENT> */


  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION State
   |
   | In this state, only patterns that are legal in a processing
   | instruction name are recognized.
   |______________________________________________________________________*/

  /* <MODE_PROCESSING_INSTRUCTION>{ */

<MODE_PROCESSING_INSTRUCTION>{SP} { BEGIN MODE_PROCESSING_INSTRUCTION_CONTENT; /* continue lexing */ }
<MODE_PROCESSING_INSTRUCTION>"?>" { POP_STATE(); return token::PI_END; }
<MODE_PROCESSING_INSTRUCTION>{PITarget} { TRY_SVAL_TOKEN (PI_TARGET_LITERAL, put(yytext, yyleng)); }

  /* } */  /* END <MODE_PROCESSING_INSTRUCTION> */


  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION_CONTENT State
   |
   | In this state, only characters are that are legal in processing
   | instruction content are recognized.
   |______________________________________________________________________*/

  /* <MODE_PROCESSING_INSTRUCTION_CONTENT>{ */

<MODE_PROCESSING_INSTRUCTION_CONTENT>{PIChars}"?>" {
  POP_STATE();
  TRY_SVAL_TOKEN (CHAR_LITERAL_AND_PI_END, put(yytext, yyleng-2));
}

  /* } */  /* END <MODE_PROCESSING_INSTRUCTION_CONTENT> */


  /*______________________________________________________________________
   |
   | CDATA_SECTION State
   |
   | In this state, only lexemes that are legal in a CDATA section are
   | recognized.
   |______________________________________________________________________*/

  /* <MODE_CDATA_SECTION>{ */

<MODE_CDATA_SECTION>"]]>" { POP_STATE(); TRY_SVAL_TOKEN (CHAR_LITERAL_AND_CDATA_END, put(yytext, yyleng-3)); }
<MODE_CDATA_SECTION>{Char} { yymore(); }

  /* } */  /* END <MODE_CDATA_SECTION> */


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

  /* <MODE_QUOTE_ATTRIBUTE_CONTENT>{ */

<MODE_QUOTE_ATTRIBUTE_CONTENT>\" { BEGIN MODE_START_TAG; return token::QUOTE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"{" { PUSH_STATE(INITIAL); return token::LBRACE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{EscapeQuot} { return token::ESCAPE_QUOTE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{QuotAttrContentChar}+ { TRY_SVAL_TOKEN (QUOTE_ATTR_CONTENT, put(yytext, yyleng, true)); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN (QUOTE_ATTR_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{CharRef}+ { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"{{" { return token::DOUBLE_LBRACE; }
<MODE_QUOTE_ATTRIBUTE_CONTENT>"}}" { return token::DOUBLE_RBRACE; }

  /* } */  /* END <MODE_QUOTE_ATTRIBUTE_CONTENT> */


  /*______________________________________________________________________
   |
   | APOS_ATTRIBUTE_CONTENT State
   |
   | This state is the same as QUOT_ATTRIBUTE_CONTENT, except that
   | quotes are allowed, and an unescaped apostrophe marks the end of
   | the state.
   |______________________________________________________________________*/

  /* <MODE_APOS_ATTRIBUTE_CONTENT>{ */

<MODE_APOS_ATTRIBUTE_CONTENT>\'                     { BEGIN MODE_START_TAG; return token::APOS; }
<MODE_APOS_ATTRIBUTE_CONTENT>"{"                    { PUSH_AND_BEGIN (INITIAL, MODE_APOS_ATTRIBUTE_CONTENT); return token::LBRACE; }
<MODE_APOS_ATTRIBUTE_CONTENT>{EscapeApos}           { return token::ESCAPE_APOS; }
<MODE_APOS_ATTRIBUTE_CONTENT>{AposAttrContentChar}+ { TRY_SVAL_TOKEN (APOS_ATTR_CONTENT, put(yytext, yyleng, true)); }
<MODE_APOS_ATTRIBUTE_CONTENT>{PredefinedEntityRef}  { TRY_SVAL_TOKEN (APOS_ATTR_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_APOS_ATTRIBUTE_CONTENT>{CharRef}+             { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_APOS_ATTRIBUTE_CONTENT>"{{"                   { return token::DOUBLE_LBRACE; }
<MODE_APOS_ATTRIBUTE_CONTENT>"}}"                   { return token::DOUBLE_RBRACE; }

  /* } */  /* END <MODE_APOS_ATTRIBUTE_CONTENT> */


  /*______________________________________________________________________
   |
   | Catch-all rule
   |______________________________________________________________________*/


<*>. return token::UNRECOGNIZED;


  /* END OF FLEX RULES */

  
%%


std::string start_state(int state)
{
  switch (state)
  {
    case INITIAL: return "INITIAL";
    case MODE_APOS_ATTRIBUTE_CONTENT: return "MODE_APOS_ATTRIBUTE_CONTENT";
    case MODE_CDATA_SECTION: return "MODE_CDATA_SECTION";
    case MODE_CLOSE_KINDTEST: return "MODE_CLOSE_KINDTEST";
    case MODE_DECLAREORDERING: return "MODE_DECLAREORDERING";
    case MODE_ELEMENT_CONTENT: return "MODE_ELEMENT_CONTENT";
    case MODE_END_TAG: return "MODE_END_TAG";
    case MODE_EXPR_COMMENT: return "MODE_EXPR_COMMENT";
    case MODE_ITEMTYPE: return "MODE_ITEMTYPE";
    case MODE_KINDTEST: return "MODE_KINDTEST";
    case MODE_KINDTESTFORPI: return "MODE_KINDTESTFORPI";
    case MODE_NAMESPACEDECL: return "MODE_NAMESPACEDECL";
    case MODE_NAMESPACEKEYWORD: return "MODE_NAMESPACEKEYWORD";
    case MODE_OCCURRENCE_INDICATOR: return "MODE_OCCURRENCE_INDICATOR";
    case MODE_OPERATOR: return "MODE_OPERATOR";
    case MODE_OPTION: return "MODE_OPTION";
    case MODE_PRAGMA: return "MODE_PRAGMA";
    case MODE_PRAGMACONTENTS: return "MODE_PRAGMACONTENTS";
    case MODE_PROCESSING_INSTRUCTION: return "MODE_PROCESSING_INSTRUCTION";
    case MODE_PROCESSING_INSTRUCTION_CONTENT: return "MODE_PROCESSING_INSTRUCTION_CONTENT";
    case MODE_PROCESSING_INSTRUCTION_CTOR: return "MODE_PROCESSING_INSTRUCTION_CTOR";
    case MODE_QUOTE_ATTRIBUTE_CONTENT: return "MODE_QUOTE_ATTRIBUTE_CONTENT";
    case MODE_SINGLETYPE: return "MODE_SINGLETYPE";
    case MODE_START_TAG: return "MODE_START_TAG";
    case MODE_URITOOPERATOR: return "MODE_URITOOPERATOR";
    case MODE_VARNAME: return "MODE_VARNAME";
    case MODE_XMLSPACE_DECL: return "MODE_XMLSPACE_DECL";
    case MODE_XML_COMMENT: return "MODE_XML_COMMENT";
    case MODE_XQUERY_VERSION: return "MODE_XQUERY_VERSION";
    case MODE_CATCH: return "MODE_CATCH";
    default: return "Something's drastically wrong here, unrecognized start state!\n";
  }
}


namespace zorba {

xquery_scanner::xquery_scanner(
  xquery_driver* aDriver,
  std::istream* i,
  std::ostream* o)
: ZorbaFlexLexer(i, o), theDriver(aDriver)
{}

xquery_scanner::~xquery_scanner() {}


void xquery_scanner::set_yy_flex_debug(bool aBool)
{
  yy_flex_debug = aBool;
}

void xquery_scanner::interpretAsLessThan()
{
  BEGIN INITIAL;
  POP_STATE();
}

} /* namespace zorba */

#ifdef yylex
#undef yylex
#endif

int ZorbaFlexLexer::yylex()
{
  std::cout << "in ZorbaFlexLexer::yylex() !" << std::endl;
  return 0;
}
