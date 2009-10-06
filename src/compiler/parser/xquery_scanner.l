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
std::string start_state(int);   /* forward declaration, used by YY_USER_ACTION */
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

PITarget              {NCName}

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
%x MODE_EXPR_DOC_COMMENT
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
"returning" { return token::RETURNING; }
"block" { return token::BLOCK; }
"exit" { return token::EXIT; }
"with" { return token::WITH; }
"break" { return token::BREAK; }
"loop" { return token::LOOP; }
"continue" { return token::CONTINUE; }
"while" { return token::WHILE; }
"set" { return token::SET; }
"validate" { return token::VALIDATE; }
"typeswitch" { return token::TYPESWITCH; }
"eval" { return token::EVAL; }
"element" { return token::ELEMENT; }
"attribute" { return token::ATTRIBUTE; }
"document" { return token::DOCUMENT; }
"text" { return token::TEXT; }
"processing-instruction" { return token::PROCESSING_INSTRUCTION; }
"comment" { return token::COMMENT; }
"declare" {
  std::string lDocComment = theDriver->theDocComment;
  yylval->sval = getDriver()->symtab.put_stringlit2(lDocComment.c_str(), lDocComment.length());
  theDriver->theDocComment = "";
  return token::DECLARE;
}
"function" { return token::FUNCTION; }
"deterministic" { return token::DETERMINISTIC; }
"nondeterministic" { return token::NONDETERMINISTIC; }
"simple" { return token::SIMPLE; }
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
"module" {
  std::string lDocComment = theDriver->theDocComment;
  yylval->sval = getDriver()->symtab.put_stringlit2(lDocComment.c_str(), lDocComment.length());
  theDriver->theDocComment = "";
  return token::MODULE;
}

"base-uri" { return token::BASE_URI; }
"import" { 
  return token::IMPORT;
}
"schema" { return token::SCHEMA; }
"copy-namespaces" { return token::COPY_NAMESPACES; }
"for" { return token::FOR; }
"outer" { return token::OUTER; }
"let" { return token::LET; }
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
"revalidation" { return token::REVALIDATION;}
"as" { return token::AS; }

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

"try" { return token::TRY;}

  /*______________________________________________________________________
   |
   |  Data Definition Facility tokens 
   |______________________________________________________________________*/

"datamodule" { return token::DATAMODULE; }

"collection" { return token::COLLECTION; }
"node-type" { return token::NODE_TYPE; }
"collection-modifier" { return token::COLLECTION_MODIFIER; }
"node-modifier" { return token::NODE_MODIFIER; }
"const" { return token::CONST; }
"append-only" { return token::APPEND_ONLY; }
"queue" { return token::QUEUE; }
"mutable" { return token::MUTABLE; }
"read-only" { return token::READ_ONLY; }

"index" { return token::INDEX; }
"unique" { return token::UNIQUE; }
"manual" { return token::MANUAL; }
"automatic" { return token::AUTOMATIC; }
"on" { return token::ON; }

 
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
"ftcontains" { return token::FTCONTAINS; }


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
   | PRAGMA State
   |
   | This state is entered in a a pragma expression, and recognizes
   | a QName that transits to a PRAGMACONTENTS state rather than an
   | OPERATOR state.
   |______________________________________________________________________*/

<MODE_PRAGMA>{QName}{SPNoComment} { BEGIN MODE_PRAGMACONTENTS; TRY_SVAL_TOKEN(QNAME_SVAL, put_qname(yytext, yyleng, true, true)); }
<MODE_PRAGMA>{QName}"#)" { BEGIN INITIAL; TRY_SVAL_TOKEN(QNAME_SVAL_AND_END_PRAGMA, put_qname(yytext, yyleng-2)); }
<MODE_PRAGMA>{S} { /* continue lexing */ }
  
  
  /*______________________________________________________________________
   |
   | PRAGMACONTENTS State
   |
   | This state recognizes characters in pragma content and transitions
   | out of this state when a '#)' pattern is recognized.
   |______________________________________________________________________*/

<MODE_PRAGMACONTENTS>{PragmaChars}"#)" { BEGIN INITIAL; TRY_SVAL_TOKEN(PRAGMA_LITERAL_AND_END_PRAGMA, put(yytext, yyleng-2)); }


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
<MODE_START_TAG>{QName} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng)); }
<MODE_START_TAG>{CatchAll} { return token::UNRECOGNIZED; }


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
<MODE_ELEMENT_CONTENT>{ElementContentChar}+ { TRY_SVAL_TOKEN (ELEMENT_CONTENT, put(yytext, yyleng, 1)); }
<MODE_ELEMENT_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN (ELEMENT_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_ELEMENT_CONTENT>{CharRef}+ { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_ELEMENT_CONTENT>"{{" { return token::DOUBLE_LBRACE; }
<MODE_ELEMENT_CONTENT>"}}" { return token::DOUBLE_RBRACE; }


  /*______________________________________________________________________
   |
   | END_TAG State
   |
   | When the end tag is terminated, the state is popped to the state
   | that was pushed at the start of the corresponding start tag.
   |______________________________________________________________________*/

<MODE_END_TAG>">" { POP_STATE(); return token::TAG_END; }
<MODE_END_TAG>{QName}{S} { TRY_SVAL_TOKEN (QNAME_SVAL, put_qname(yytext, yyleng, false, true)); }


  /*______________________________________________________________________
   |
   | XML_COMMENT State
   | The "<--" token marks the beginning of an XML Comment, and the "-->"
   | token marks the end. This allows no special interpretation of other
   | characters in this state.
   |______________________________________________________________________*/
  
<MODE_XML_COMMENT>"-->" { POP_STATE(); return token::XML_COMMENT_END; }
<MODE_XML_COMMENT>{XMLCommentChar}* { TRY_SVAL_TOKEN (XML_COMMENT_LITERAL, put(yytext, yyleng)); }


  /*______________________________________________________________________
   |
   | EXPR_COMMENT State
   |
   | The "(:" token marks the beginning of an expression Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

<MODE_EXPR_COMMENT>":)" { POP_STATE(); }
<MODE_EXPR_COMMENT>"(:" { PUSH_STATE(MODE_EXPR_COMMENT); }
<MODE_EXPR_COMMENT>.|"\n" { /* do nothing */ }
<MODE_EXPR_COMMENT><<EOF>> { return token::UNRECOGNIZED; }


  /*______________________________________________________________________
   |
   | EXPR_DOC_COMMENT State
   |
   | The "(:~" token marks the beginning of a doc Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

  /* <MODE_EXPR_COMMENT>{  */

<MODE_EXPR_DOC_COMMENT>":)" { POP_STATE(); }
<MODE_EXPR_DOC_COMMENT>.|"\n" {
  if(theDriver->theDocComment.empty())
  {
    theDriver->theMainModuleDocComment = theDriver->theDocComment;
  }
  theDriver->theDocComment += yytext;
}
<MODE_EXPR_DOC_COMMENT><<EOF>> { return token::UNRECOGNIZED; }

  /* } */  /* END <MODE_EXPR_COMMENT> */




  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION State
   |
   | In this state, only patterns that are legal in a processing
   | instruction name are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION>{SP} { BEGIN MODE_PROCESSING_INSTRUCTION_CONTENT; /* continue lexing */ }
<MODE_PROCESSING_INSTRUCTION>"?>" { POP_STATE(); return token::PI_END; }
<MODE_PROCESSING_INSTRUCTION>{NCName} /* PITarget */    { TRY_SVAL_TOKEN (NCNAME_SVAL, put(yytext, yyleng)); }


  /*______________________________________________________________________
   |
   | PROCESSING_INSTRUCTION_CONTENT State
   |
   | In this state, only characters are that are legal in processing
   | instruction content are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION_CONTENT>{PIChars}"?>" {
  POP_STATE();
  TRY_SVAL_TOKEN (CHAR_LITERAL_AND_PI_END, put(yytext, yyleng-2));
}


  /*______________________________________________________________________
   |
   | CDATA_SECTION State
   |
   | In this state, only lexemes that are legal in a CDATA section are
   | recognized.
   |______________________________________________________________________*/

<MODE_CDATA_SECTION>"]]>" { POP_STATE(); TRY_SVAL_TOKEN (CHAR_LITERAL_AND_CDATA_END, put(yytext, yyleng-3)); }
<MODE_CDATA_SECTION>{Char} { yymore(); }


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
<MODE_QUOTE_ATTRIBUTE_CONTENT>{QuotAttrContentChar}+ { TRY_SVAL_TOKEN (QUOTE_ATTR_CONTENT, put(yytext, yyleng, 2)); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{PredefinedEntityRef} { TRY_SVAL_TOKEN (QUOTE_ATTR_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_QUOTE_ATTRIBUTE_CONTENT>{CharRef}+ { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
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
<MODE_APOS_ATTRIBUTE_CONTENT>{AposAttrContentChar}+ { TRY_SVAL_TOKEN (APOS_ATTR_CONTENT, put(yytext, yyleng, 2)); }
<MODE_APOS_ATTRIBUTE_CONTENT>{PredefinedEntityRef}  { TRY_SVAL_TOKEN (APOS_ATTR_CONTENT, put_entityref(yytext, yyleng)); }
<MODE_APOS_ATTRIBUTE_CONTENT>{CharRef}+             { TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng); }
<MODE_APOS_ATTRIBUTE_CONTENT>"{{"                   { return token::DOUBLE_LBRACE; }
<MODE_APOS_ATTRIBUTE_CONTENT>"}}"                   { return token::DOUBLE_RBRACE; }


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
: ZorbaFlexLexer(i, o), theDriver(aDriver), cond_stk_depth (0)
{}

xquery_scanner::~xquery_scanner() {}

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

} /* namespace zorba */

#ifdef yylex
#undef yylex
#endif

int ZorbaFlexLexer::yylex()
{
  return 0;
}
