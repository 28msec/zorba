/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xquery.l,v 1.4 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 */

/*______________________________________________________________________
 |                                                                       
 |  An implementation of the w3c proposal:                              
 |                                                                       
 |  "Building a Tokenizer for XPath or XQuery,                          
 |   W3C Working Draft 4 April 2005"                                    
 |                                                                       
 |  [http://www.w3.org/TR/xquery-xpath-parsing/]                        
 |                                                                       
 |  Extensions including update, search, and XQueryP:                   
 |                                                                       
 |  [http://www.w3.org/TR/xqupdate/]                                    
 |  [http://www.w3.org/TR/xquery-full-text/]                            
 |  [http://www.ximep-2006.org/papers/Paper-Chamberlin-Carey.pdf]       
 |                                                                      
 |_______________________________________________________________________*/


%{ /* _*_ C++ _*_ */

#if defined (WIN32)
#pragma warning(disable: 4786)
#endif

#include <zorbatypes/representations.h>

#include <zorba/common/common.h>
#include <zorba/properties.h>

#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <string>

#include "compiler/parser/xquery_parser.hpp"
#include "compiler/parser/xquery_scanner.h"
#include "compiler/parser/xquery_driver.h"

typedef zorba::xquery_parser::token token;
typedef zorba::xquery_parser::token_type token_type;

#define TRY_STR_LIT( ttype, put, yytext, yyleng )                       \
  do {                                                                  \
    off_t res = getDriver()->symtab.put (yytext, yyleng);               \
    if (res < 0) return token::UNRECOGNIZED;                            \
    else {                                                              \
      yylval->sval = res;                                               \
      return token::ttype;                                              \
    }                                                                   \
 } while (0)

#define TRY_STRINGLIT( ttype, yytext, yyleng ) TRY_STR_LIT (ttype, put_stringlit, yytext, yyleng)

#define TRY_URILIT( ttype, yytext, yyleng ) TRY_STR_LIT (ttype, put_uri, yytext, yyleng)

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
#define yyterminate() return token::END

std::string start_state(int);

#define YY_USER_ACTION \
{ \
  if (yy_flex_debug) { \
    std::cout<<'<'<<start_state(YY_START)<<">" /* << " [["<<yytext<<"]]" */ << std::endl; \
    yylloc->columns(yyleng); \
  } \
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


/* known expensive option */
%option yylineno


  /*_____________________________________________________________________
   |
   |  Whitespace definitions
   |______________________________________________________________________*/
CommentChars    ([^:]|":"+[^:)])*":)"
Comment         "(:"{CommentChars}
blank           [ \t]
S1              [ \t\r\n\f]
S               {S1}*
SOrComment      ({S1}|{Comment})*
SP              ({S1}|{Comment})+
SPNoComment     {S1}+
WordBreak       [^a-zA-Z0-9_-]

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
VarName     {QName}


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
URILiteral            {StringLiteral}

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

ValidationMode        ("strict"|"lax"|"skip")


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

%%
%{
 yylloc->step ();
%}

{blank}+   { yylloc->step(); }
[\n]+      { yylloc->lines(yyleng); yylloc->step (); }


%{
typedef zorba::xquery_parser::token token;
%}



  /*______________________________________________________________________
   |
   |  INITIAL State
   |
   |  This state is for patterns that occur at the beginning  of an
   |  expression or subexpression.
   |______________________________________________________________________*/

  /* maintain INITIAL */
  /* ---------------- */
"validate"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VALIDATE_LBRACE" << endl;
#endif
  return token::VALIDATE_LBRACE;
}

"validate"{SP}{ValidationMode} {
  yylval->sval = getDriver()->symtab.put(yytext+9, yyleng-9);
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VALIDATE_MODE" << endl;
#endif
  return token::VALIDATE_MODE;
}

"typeswitch"{S}"(" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TYPESWITCH_LPAR" << endl;
#endif
  return token::TYPESWITCH_LPAR;
}

"element"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_LBRACE" << endl;
#endif
  return token::ELEMENT_LBRACE;
}

"attribute"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ATTRIBUTE_LBRACE" << endl;
#endif
  return token::ATTRIBUTE_LBRACE;
}

"attribute"{SP}{QName}{S}"{" {
  yylval->sval = getDriver()->symtab.put_qname(yytext+10, yyleng-11, true, true);
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ATTRIBUTE_QNAME_LBRACE" << endl;
#endif
  return token::ATTRIBUTE_QNAME_LBRACE;
}

"element"{SP}{QName}{S}"{" {
  yylval->sval = getDriver()->symtab.put_qname(yytext+8, yyleng-9, true, true);
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_QNAME_LBRACE" << endl;
#endif
  return token::ELEMENT_QNAME_LBRACE;
}

"document"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOCUMENT_LBRACE" << endl;
#endif
  return token::DOCUMENT_LBRACE;
}

"text"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TEXT_LBRACE" << endl;
#endif
  return token::TEXT_LBRACE;
}

    /* transition to MODE_PROCESSING_INSTRUCTION_CTOR */
    /* ---------------------------------------------- */
"processing-instruction"  {
  BEGIN MODE_PROCESSING_INSTRUCTION_CTOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PROCESSING_INSTRUCTION" << endl;
#endif
  return token::PROCESSING_INSTRUCTION;
}


"comment"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMENT_LBRACE" << endl;
#endif
  return token::COMMENT_LBRACE;
}

"declare"{SP}"function"{SP} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_FUNCTION" << endl;
#endif
  return token::DECLARE_FUNCTION;
}

"declare"{SP}"updating"{SP}"function"{SP} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_UPDATING_FUNCTION" << endl;
#endif
  return token::DECLARE_UPDATING_FUNCTION;
}

"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

"ordered"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ORDERED_LBRACE" << endl;
#endif
  return token::ORDERED_LBRACE;
}

"unordered"{S}"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNORDERED_LBRACE" << endl;
#endif
  return token::UNORDERED_LBRACE;
}

";" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SEMI" << endl;
#endif
  return token::SEMI;
}
"," {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}
"(" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LPAR" << endl;
#endif
  return token::LPAR;
}
"if"{SOrComment}"(" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IF_LPAR" << endl;
#endif
  return token::IF_LPAR;
}


  /* transition to KINDTEST */
  /* ---------------------- */
"element"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_LPAR" << endl;
#endif
  return token::ELEMENT_LPAR;
}

"attribute"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ATTRIBUTE_LPAR" << endl;
#endif
  return token::ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCHEMA_ELEMENT_LPAR" << endl;
#endif
  return token::SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCHEMA_ATTRIBUTE_LPAR" << endl;
#endif
  return token::SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMENT_LPAR" << endl;
#endif
  return token::COMMENT_LPAR;
}

"text"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TEXT_LPAR" << endl;
#endif
  return token::TEXT_LPAR;
}

"node"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NODE_LPAR" << endl;
#endif
  return token::NODE_LPAR;
}

"document-node"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOCUMENT_NODE_LPAR" << endl;
#endif
  return token::DOCUMENT_NODE_LPAR;
}


  /* transition to KINDTESTFORPI */
  /* --------------------------- */
"processing-instruction"{S}"(" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_KINDTESTFORPI);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_LPAR" << endl;
#endif
  return token::PI_LPAR;
}

  /* order dependence: this must follow the rules: xxx{S}"(" */
  /* {QName}{S}"(" {
   yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng-1, false, true);
 #ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME_LPAR" << endl;
#endif
  return token::QNAME_LPAR;
  }*/

"-" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MINUS" << endl;
#endif
  return token::MINUS;
}
"+" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PLUS" << endl;
#endif
  return token::PLUS;
}
"/" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SLASH" << endl;
#endif
  return token::SLASH;
}
"/ " {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LEADING_LONE_SLASH" << endl;
#endif
  return token::LEADING_LONE_SLASH;
}
"//" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SLASH_SLASH" << endl;
#endif
  return token::SLASH_SLASH;
}
"ancestor-or-self::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANCESTOR_OR_SELF_AXIS" << endl;
#endif
  return token::ANCESTOR_OR_SELF_AXIS;
}
"ancestor::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANCESTOR_AXIS" << endl;
#endif
  return token::ANCESTOR_AXIS;
}
"attribute::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ATTRIBUTE_AXIS" << endl;
#endif
  return token::ATTRIBUTE_AXIS;
}
"child::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CHILD_AXIS" << endl;
#endif
  return token::CHILD_AXIS;
}
"descendant-or-self::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DESCENDANT_OR_SELF_AXIS" << endl;
#endif
  return token::DESCENDANT_OR_SELF_AXIS;
}
"descendant::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DESCENDANT_AXIS" << endl;
#endif
  return token::DESCENDANT_AXIS;
}
"following-sibling::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOLLOWING_SIBLING_AXIS" << endl;
#endif
  return token::FOLLOWING_SIBLING_AXIS;
}
"following::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOLLOWING_AXIS" << endl;
#endif
  return token::FOLLOWING_AXIS;
}
"parent::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PARENT_AXIS" << endl;
#endif
  return token::PARENT_AXIS;
}
"preceding-sibling::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRECEDING_SIBLING_AXIS" << endl;
#endif
  return token::PRECEDING_SIBLING_AXIS;
}
"preceding::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRECEDING_AXIS" << endl;
#endif
  return token::PRECEDING_AXIS;
}
"self::" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SELF_AXIS" << endl;
#endif
  return token::SELF_AXIS;
}
"@" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_SIGN" << endl;
#endif
  return token::AT_SIGN;
}


  /* transition to OPERATOR */
  /* ---------------------- */

{IntegerLiteral}/[a-zA-Z_]  {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}
{IntegerLiteral}  {
  yylval->ival = getDriver()->symtab.integerval(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INTEGER_LITERAL" << endl;
#endif
  return token::INTEGER_LITERAL;
}

{DecimalLiteral}/[a-zA-Z_]  {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}
{DecimalLiteral}  {
  yylval->decval = getDriver()->symtab.decimalval(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECIMAL_LITERAL" << endl;
#endif
  return token::DECIMAL_LITERAL;
}

{DoubleLiteral}/[a-zA-Z_] {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}
{DoubleLiteral}   {
  yylval->dval = getDriver()->symtab.doubleval(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_LITERAL" << endl;
#endif
  return token::DOUBLE_LITERAL;
}

{NCName}":*" {
  yylval->sval = getDriver()->symtab.put_ncname(yytext, yyleng-2);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEM_WILDCARD" << endl;
#endif
  return token::ELEM_WILDCARD;
}

{QName} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

")" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}

"*:"{NCName} {
  yylval->sval = getDriver()->symtab.put_ncname(yytext+2, yyleng-2);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PREFIX_WILDCARD" << endl;
#endif
  return token::PREFIX_WILDCARD;
}

"*" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STAR" << endl;
#endif
  return token::STAR;
}

{StringLiteral} {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "scanner::TRY_STRINGLIT" << std::endl;
#endif
  TRY_STRINGLIT (STRING_LITERAL, yytext, yyleng);
}

"declare"{SP}"construction"{SP} {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_CONSTRUCTION" << endl;
#endif
  return token::DECLARE_CONSTRUCTION;
}

"declare"{SP}"default"{SP}"order"{SP} {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_DEFAULT_ORDER" << endl;
#endif
  return token::DECLARE_DEFAULT_ORDER;
}

".." {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOT_DOT" << endl;
#endif
  return token::DOT_DOT;
}

"." {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOT" << endl;
#endif
  return token::DOT;
}


  /* transition to NAMESPACEDECL */
  /* --------------------------- */
"declare"{SP}"default"{SP}"collation"{SP} {
  BEGIN MODE_NAMESPACEDECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_DEFAULT_COLLATION" << endl;
#endif
  return token::DECLARE_DEFAULT_COLLATION;
}

"declare"{SP}"namespace"{SP} {
  BEGIN MODE_NAMESPACEDECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_NAMESPACE" << endl;
#endif
  return token::DECLARE_NAMESPACE;
}

"module"{SP}"namespace"/{WordBreak} {
  BEGIN MODE_NAMESPACEDECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MODULE_NAMESPACE" << endl;
#endif
  return token::MODULE_NAMESPACE;
}

"declare"{SP}"base-uri"/{WordBreak} {
  BEGIN MODE_NAMESPACEDECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_BASE_URI" << endl;
#endif
  return token::DECLARE_BASE_URI;
}


  /* transition to NAMESPACEKEYWORD */
  /* ------------------------------ */
"declare"{SP}"default"{SP}"element"{SP} {
  BEGIN MODE_NAMESPACEKEYWORD;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_DEFAULT_ELEMENT" << endl;
#endif
  return token::DECLARE_DEFAULT_ELEMENT;
}

"declare"{SP}"default"{SP}"function"{SP} {
  BEGIN MODE_NAMESPACEKEYWORD;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_DEFAULT_FUNCTION" << endl;
#endif
  return token::DECLARE_DEFAULT_FUNCTION;
}

"import"{SP}"schema"/{WordBreak} {
  BEGIN MODE_NAMESPACEKEYWORD;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IMPORT_SCHEMA" << endl;
#endif
  return token::IMPORT_SCHEMA;
}

"import"{SP}"module"/{WordBreak} {
  BEGIN MODE_NAMESPACEKEYWORD;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IMPORT_MODULE" << endl;
#endif
  return token::IMPORT_MODULE;
}

"declare"{SP}"copy-namespaces"{SP} {
  BEGIN MODE_NAMESPACEKEYWORD;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_COPY_NAMESPACES" << endl;
#endif
  return token::DECLARE_COPY_NAMESPACES;
}


  /* transition to VARNAME */
  /* --------------------- */
"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOLLAR" << endl;
#endif
  return token::DOLLAR;
}

"for"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOR_DOLLAR" << endl;
#endif
  return token::FOR_DOLLAR;
}

"let"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LET_DOLLAR" << endl;
#endif
  return token::LET_DOLLAR;
}

"some"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SOME_DOLLAR" << endl;
#endif
  return token::SOME_DOLLAR;
}

"every"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EVERY_DOLLAR" << endl;
#endif
  return token::EVERY_DOLLAR;
}

"declare"{SP}"variable"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_VARIABLE_DOLLAR" << endl;
#endif
  return token::DECLARE_VARIABLE_DOLLAR;
}


  /* transition to ITEMTYPE */
  /* ---------------------- */
")"{S}"as"/{WordBreak} {
  BEGIN MODE_ITEMTYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR_AS" << endl;
#endif
  return token::RPAR_AS;
} 


  /* transition to XML_COMMENT */
  /* ------------------------- */
"<!--" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_XML_COMMENT);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::XML_COMMENT_BEGIN" << endl;
#endif
  return token::XML_COMMENT_BEGIN;
}


  /* transition to PROCESSING_INSTRUCTION */
  /* ------------------------------------ */
"<?" {  
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_PROCESSING_INSTRUCTION);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_BEGIN" << endl;
#endif
  return token::PI_BEGIN;
}


  /* transition to CDATA_SECTION */
  /* --------------------------- */
"<![CDATA[" {
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_CDATA_SECTION);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CDATA_BEGIN" << endl;
#endif
  return token::CDATA_BEGIN;
}


"<"{SP} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}
  /* transition to START_TAG */
  /* ----------------------- */
"<" {   
  BEGIN MODE_OPERATOR;
  yy_push_state(MODE_START_TAG);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::START_TAG" << endl;
#endif
  return token::START_TAG;
}


  /* transition to XMLSPACE_DECL */
  /* --------------------------- */
"declare"{SP}"boundary-space"{SP} {
  BEGIN MODE_XMLSPACE_DECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_BOUNDARY_SPACE" << endl;
#endif
  return token::DECLARE_BOUNDARY_SPACE;
}


  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}


  /* transition to DECLAREORDERING */
  /* ----------------------------- */
"declare"{SP}"ordering"{SP} {
  BEGIN MODE_DECLAREORDERING;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_ORDERING" << endl;
#endif
  return token::DECLARE_ORDERING;
}


  /* transition to XQUERY_VERSION */
  /* ---------------------------- */
"xquery"{SP}"version"/{WordBreak} {
  BEGIN MODE_XQUERY_VERSION;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::XQUERY_VERSION" << endl;
#endif
  return token::XQUERY_VERSION;
}


  /* transition to PRAGMA */
  /* -------------------- */
"(#" {  
  BEGIN MODE_PRAGMA;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRAGMA_BEGIN" << endl;
#endif
  return token::PRAGMA_BEGIN;
}


  /* transition to OPTION */
  /* -------------------- */
"declare"{SP}"option"{SP} {
  BEGIN MODE_OPTION;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_OPTION" << endl;
#endif
  return token::DECLARE_OPTION;
}


  /* transition to NAMESPACEDECL */
  /* --------------------------- */
"at"{SP}{URILiteral} {
  const char *p = yytext + 2;
  for (; *p != '\'' && *p != '"'; p++);
  BEGIN MODE_NAMESPACEDECL;
  TRY_URILIT (AT_URI_LITERAL, p, yyleng + (p - yytext));
}


  /* pop previous state */
  /* ------------------ */
"}" {   
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RBRACE" << endl;
#endif
  return token::RBRACE;
}


  /*______________________________________________________________________  
   |
   | Update rules <INITIAL,MODE_OPERATOR>
   |______________________________________________________________________*/

"declare"{SP}"revalidation"{SP} {
  BEGIN MODE_DECLAREREVALIDATION;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_REVALIDATION" << endl;
#endif
  return token::DECLARE_REVALIDATION;
}


<INITIAL,MODE_OPERATOR>{

"insert"{SP}"node"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INSERT_NODE" << endl;
#endif
  return token::INSERT_NODE;
}
"insert"{SP}"nodes"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INSERT_NODES" << endl;
#endif
  return token::INSERT_NODES;
}
"delete"{SP}"node"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DELETE_NODE" << endl;
#endif
  return token::DELETE_NODE;
}
"delete"{SP}"nodes"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DELETE_NODES" << endl;
#endif
  return token::DELETE_NODES;
}
"replace"{SP}"node"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::REPLACE" << endl;
#endif
  return token::REPLACE;
}
"replace"{SP}"value"{SP}"of"{SP}"node"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::REPLACE_VALUE_OF" << endl;
#endif
  return token::REPLACE_VALUE_OF;
}
"rename"{SP}"node"/{WordBreak} {
  BEGIN INITIAL; 
  getDriver()->set_rename(true);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RENAME" << endl;
#endif
  return token::RENAME;
}

"copy"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COPY_DOLLAR" << endl;
#endif
  return token::COPY_DOLLAR;
}
"into"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INTO" << endl;
#endif
  return token::INTO;
}
"first"{SP}"into"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FIRST_INTO" << endl;
#endif
  return token::FIRST_INTO;
}
"last"{SP}"into"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LAST_INTO" << endl;
#endif
  return token::LAST_INTO;
}
"after"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AFTER" << endl;
#endif
  return token::AFTER;
}
"before"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::BEFORE" << endl;
#endif
  return token::BEFORE;
}
"with"/{WordBreak}  {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH" << endl;
#endif
  return token::WITH;
}
"modify"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MODIFY" << endl;
#endif
  return token::MODIFY;
}

}

"as"/{WordBreak} {
  BEGIN INITIAL; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AS" << endl;
#endif
  return token::AS;
}

  /*______________________________________________________________________  
   |
   | TRY-CATCH rules <INITIAL>
   |______________________________________________________________________*/

"try"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TRY" << endl;
#endif
  return token::TRY;
}

<MODE_OPERATOR>{
"catch"{S}"(" {
  yy_push_state(MODE_CATCH);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CATCH_LPAR" << endl;
#endif
  return token::CATCH_LPAR;
}
}

<MODE_CATCH>{

")" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}

{QName}  {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

"*" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STAR" << endl;
#endif
  return token::STAR;
}

{NCName}":*" {
  yylval->sval = getDriver()->symtab.put_ncname(yytext, yyleng-2);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEM_WILDCARD" << endl;
#endif
  return token::ELEM_WILDCARD;
}

"*:"{NCName} {
  yylval->sval = getDriver()->symtab.put_ncname(yytext+2, yyleng-2);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PREFIX_WILDCARD" << endl;
#endif
  return token::PREFIX_WILDCARD;
}

}


  /*______________________________________________________________________  
   |
   | FT rules <INITIAL>
   |______________________________________________________________________*/

"&&" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTAND" << endl;
#endif
  return token::FTAND;
}
"!" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTNOT" << endl;
#endif
  return token::FTNOT;
}
"||" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTOR" << endl;
#endif
  return token::FTOR;
}
"not"<SP>"in"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTNOT_IN" << endl;
#endif
  return token::FTNOT_IN;
}
"all"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ALL" << endl;
#endif
  return token::ALL;
}
"all"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ALL_WORDS" << endl;
#endif
  return token::ALL_WORDS;
}
"any"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANY" << endl;
#endif
  return token::ANY;
}
"any"{SP}"word"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANY_WORD" << endl;
#endif
  return token::ANY_WORD;
}
"at"{SP}"end"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_END" << endl;
#endif
  return token::AT_END;
}
"at"{SP}"least"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_LEAST" << endl;
#endif
  return token::AT_LEAST;
}
"at"{SP}"most"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_MOST" << endl;
#endif
  return token::AT_MOST;
}
"at"{SP}"start"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_START" << endl;
#endif
  return token::AT_START;
}
"case"{SP}"insensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE_INSENSITIVE" << endl;
#endif
  return token::CASE_INSENSITIVE;
}
"case"{SP}"sensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE_SENSITIVE" << endl;
#endif
  return token::CASE_SENSITIVE;
}
"declare"{SP}"ftoption"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_FTOPTION" << endl;
#endif
  return token::DECLARE_FTOPTION;
}
"diacritics"{SP}"insensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIACRITICS_INSENSITIVE" << endl;
#endif
  return token::DIACRITICS_INSENSITIVE;
}
"diacritic"{SP}"sensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIACRITICS_SENSITIVE" << endl;
#endif
  return token::DIACRITICS_SENSITIVE;
}
"different"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIFFERENT" << endl;
#endif
  return token::DIFFERENT;
}
"distance"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DISTANCE" << endl;
#endif
  return token::DISTANCE;
}
"entire"{SP}"content"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENTIRE_CONTENT" << endl;
#endif
  return token::ENTIRE_CONTENT;
}
"exactly"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXACTLY" << endl;
#endif
  return token::EXACTLY;
}
"from"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FROM" << endl;
#endif
  return token::FROM;
}
"language"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LANGUAGE" << endl;
#endif
  return token::LANGUAGE;
}
"levels"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LEVELS" << endl;
#endif
  return token::LEVELS;
}
"lowercase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LOWERCASE" << endl;
#endif
  return token::LOWERCASE;
}
"occurs"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OCCURS" << endl;
#endif
  return token::OCCURS;
}
"paragraph"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PARAGRAPH" << endl;
#endif
  return token::PARAGRAPH;
}
"phrase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PHRASE" << endl;
#endif
  return token::PHRASE;
}
"relationship"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RELATIONSHIP" << endl;
#endif
  return token::RELATIONSHIP;
}
"same"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SAME" << endl;
#endif
  return token::SAME;
}
"score"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCORE" << endl;
#endif
  return token::SCORE;
}
"sentence"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SENTENCE" << endl;
#endif
  return token::SENTENCE;
}
"sentences"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SENTENCES" << endl;
#endif
  return token::SENTENCES;
}
"times"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TIMES" << endl;
#endif
  return token::TIMES;
}
"uppercase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UPPERCASE" << endl;
#endif
  return token::UPPERCASE;
}
"weight"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WEIGHT" << endl;
#endif
  return token::WEIGHT;
}
"window"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WINDOW" << endl;
#endif
  return token::WINDOW;
}
"without"{SP}"content"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_CONTENT" << endl;
#endif
  return token::WITHOUT_CONTENT;
}
"without"{SP}"diacritics"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_DIACRITICS" << endl;
#endif
  return token::WITHOUT_DIACRITICS;
}
"without"{SP}"stemming"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_STEMMING" << endl;
#endif
  return token::WITHOUT_STEMMING;
}
"without"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_STOP_WORDS" << endl;
#endif
  return token::WITHOUT_STOP_WORDS;
}
"without"{SP}"thesaurus"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_THESAURUS" << endl;
#endif
  return token::WITHOUT_THESAURUS;
}
"without"{SP}"wildcards"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_WILDCARDS" << endl;
#endif
  return token::WITHOUT_WILDCARDS;
}
"with"{SP}"default"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_DEFAULT_STOP_WORDS" << endl;
#endif
  return token::WITH_DEFAULT_STOP_WORDS;
}
"with"{SP}"diacritics"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_DIACRITICS" << endl;
#endif
  return token::WITH_DIACRITICS;
}
"with"{SP}"stemming"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_STEMMING" << endl;
#endif
  return token::WITH_STEMMING;
}
"with"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_STOP_WORDS" << endl;
#endif
  return token::WITH_STOP_WORDS;
}
"with"{SP}"thesaurus"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_THESAURUS" << endl;
#endif
  return token::WITH_THESAURUS;
}
"with"{SP}"wildcards"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_WILDCARDS" << endl;
#endif
  return token::WITH_WILDCARDS;
}
"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WORDS" << endl;
#endif
  return token::WORDS;
}

{S} {
  /* eat up whitespace */
}

  /* catch all */
{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

  /* END MODE INITIAL */

  
  /*______________________________________________________________________  
   |
   |  The PROCESSING_INSTRUCTION_CTOR State
   |
   |  transition to MODE_OPERATOR
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION_CTOR>{

"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

{NCName}  {
  yylval->sval = getDriver()->symtab.put_ncname(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NCNAME" << endl;
#endif
  return token::NCNAME;
}

{S} {
  /* eat up whitespace */
}

}

  /*______________________________________________________________________  
   |
   |  The DECLAREORDERING State
   |
   |  Special state to recognize declare ordering specific keywords. 
   |  transition to INITIAL
   |______________________________________________________________________*/

<MODE_DECLAREORDERING>{

  /* transition to INITIAL */
  /* --------------------- */
"ordered"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ORDERED" << endl;
#endif
  return token::ORDERED;
}

"unordered"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNORDERED" << endl;
#endif
  return token::UNORDERED;
}

} /* <MODE_DECLAREORDERING> */


  /*______________________________________________________________________  
   |
   |  The DECLAREREVALIDATION State
   |
   |  Special state to recognize declare revalidation specific keywords. 
   |  transition to INITIAL
   |______________________________________________________________________*/

<MODE_DECLAREREVALIDATION>{

  /* transition to INITIAL */
  /* --------------------- */
"strict"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::REVAL_STRICT" << endl;
#endif
  return token::REVAL_STRICT;
}

"lax"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::REVAL_LAX" << endl;
#endif
  return token::REVAL_LAX;
}

"skip"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::REVAL_SKIP" << endl;
#endif
  return token::REVAL_SKIP;
}

} /* <MODE_DECLAREORDERING> */


  /*______________________________________________________________________  
   |
   |  OPERATOR State 
   | 
   |  This state is for patterns that are defined for operators.
   |______________________________________________________________________*/

<MODE_OPERATOR>{

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}
"(" {
  BEGIN INITIAL;
  /* yy_push_state(INITIAL); */
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LPAR" << endl;
#endif
  return token::LPAR;
}
";" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SEMI" << endl;
#endif
  return token::SEMI;
}
"then"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::THEN" << endl;
#endif
  return token::THEN;
}
"else"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELSE" << endl;
#endif
  return token::ELSE;
}
"external"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXTERNAL" << endl;
#endif
  return token::EXTERNAL;
}
"and"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AND" << endl;
#endif
  return token::AND;
}
"at"/{WordBreak} {
  if (!getDriver()->ftcontains()) {
    BEGIN INITIAL;
  }
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT" << endl;
#endif
  return token::AT;
}


  /* full-text rule */
"score"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCORE" << endl;
#endif
  return token::SCORE;
}


":=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GETS" << endl;
#endif
  return token::GETS;
}
"," {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}
"div"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIV" << endl;
#endif
  return token::DIV;
}
"=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EQUALS" << endl;
#endif
  return token::EQUALS;
}
"except"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXCEPT" << endl;
#endif
  return token::EXCEPT;
}
"eq"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_EQ" << endl;
#endif
  return token::VAL_EQ;
}
"ge"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_GE" << endl;
#endif
  return token::VAL_GE;
}
"gt"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_GT" << endl;
#endif
  return token::VAL_GT;
}
"le"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_LE" << endl;
#endif
  return token::VAL_LE;
}
"lt"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_LT" << endl;
#endif
  return token::VAL_LT;
}
"ne"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_NE" << endl;
#endif
  return token::VAL_NE;
}
">=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GE" << endl;
#endif
  return token::GE;
}
">>" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOLLOWS" << endl;
#endif
  return token::FOLLOWS;
}
">" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GT" << endl;
#endif
  return token::GT;
}
"idiv"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IDIV" << endl;
#endif
  return token::IDIV;
}
"intersect"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INTERSECT" << endl;
#endif
  return token::INTERSECT;
}



"in"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::_IN_" << endl;
#endif
  return token::_IN_;
}
"is"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IS" << endl;
#endif
  return token::IS;
}
"[" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACK" << endl;
#endif
  return token::LBRACK;
}
"<=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LE" << endl;
#endif
  return token::LE;
}
"<<" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRECEDES" << endl;
#endif
  return token::PRECEDES;
}
"<" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LT" << endl;
#endif
  return token::LT;
}
"-" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MINUS" << endl;
#endif
  return token::MINUS;
}
"mod"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MOD" << endl;
#endif
  return token::MOD;
}
"*" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STAR" << endl;
#endif
  return token::STAR;
}
"!=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NE" << endl;
#endif
  return token::NE;
}
"order"{SP}"by"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ORDER_BY" << endl;
#endif
  return token::ORDER_BY;
}
"stable"{SP}"order"{SP}"by"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STABLE_ORDER_BY" << endl;
#endif
  return token::STABLE_ORDER_BY;
}
"or"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OR" << endl;
#endif
  return token::OR;
}
"+" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PLUS" << endl;
#endif
  return token::PLUS;
}
"return"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RETURN" << endl;
#endif
  return token::RETURN;
}
"satisfies"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SATISFIES" << endl;
#endif
  return token::SATISFIES;
}
"/" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SLASH" << endl;
#endif
  return token::SLASH;
}
"/ " {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LEADING_LONE_SLASH" << endl;
#endif
  return token::LEADING_LONE_SLASH;
}
"//" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SLASH_SLASH" << endl;
#endif
  return token::SLASH_SLASH;
}
"to"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TO" << endl;
#endif
  return token::TO;
}
"union"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNION" << endl;
#endif
  return token::UNION;
}
"|" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VBAR" << endl;
#endif
  return token::VBAR;
}
"where"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WHERE" << endl;
#endif
  return token::WHERE;
}
"preserve"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRESERVE" << endl;
#endif
  return token::PRESERVE;
}
"strip"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STRIP" << endl;
#endif
  return token::STRIP;
}




  /* transition to SINGLETYPE */
  /* ------------------------ */
"castable"{SP}"as"/{WordBreak} {
  BEGIN MODE_SINGLETYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASTABLE_AS" << endl;
#endif
  return token::CASTABLE_AS;
}
"cast"{SP}"as"/{WordBreak} {
  BEGIN MODE_SINGLETYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CAST_AS" << endl;
#endif
  return token::CAST_AS;
}


  /* transition to ITEMTYPE */
  /* ---------------------- */
"instance"{SP}"of"/{WordBreak} {
  BEGIN MODE_ITEMTYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INSTANCE_OF" << endl;
#endif
  return token::INSTANCE_OF;
}
"treat"{SP}"as"/{WordBreak} {
  BEGIN MODE_ITEMTYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TREAT_AS" << endl;
#endif
  return token::TREAT_AS;
}
"case"/{WordBreak} {
  BEGIN MODE_ITEMTYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE" << endl;
#endif
  return token::CASE;
}
"as"/{WordBreak} {
  if (getDriver()->rename()) {
    getDriver()->set_rename(false);
    BEGIN INITIAL;
  }
  else if (getDriver()->ftcontains()) {
    getDriver()->set_ftcontains(false);
  }
  else {
    BEGIN MODE_ITEMTYPE;
  }
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AS" << endl;
#endif
  return token::AS;
}
")"{S}"as"{SP} {
  BEGIN MODE_ITEMTYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR_AS" << endl;
#endif
  return token::RPAR_AS;
}


  /* transition to VARNAME */
  /* --------------------- */
"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOLLAR" << endl;
#endif
  return token::DOLLAR;
}
"for"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOR_DOLLAR" << endl;
#endif
  return token::FOR_DOLLAR;
}
"let"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LET_DOLLAR" << endl;
#endif
  return token::LET_DOLLAR;
}
"let"{SP}"score"{SP}"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LET_SCORE_DOLLAR" << endl;
#endif
  return token::LET_SCORE_DOLLAR;
}


  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}


  /* transition to URITOOPERATOR */
  /* --------------------------- */
"collation"/{WordBreak} {
  BEGIN MODE_URITOOPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COLLATION" << endl;
#endif
  return token::COLLATION;
}


  /* restore previous state on closing brace */
  /* --------------------------------------- */
"}" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RBRACE" << endl;
#endif
  return token::RBRACE;
}


  /* maintain OPERATOR state */
  /* ----------------------- */
")" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}
"?" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::HOOK" << endl;
#endif
  return token::HOOK;
}
"empty"{SP}"greatest"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EMPTY_GREATEST" << endl;
#endif
  return token::EMPTY_GREATEST;
}
"empty"{SP}"least"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EMPTY_LEAST" << endl;
#endif
  return token::EMPTY_LEAST;
}
"ascending"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ASCENDING" << endl;
#endif
  return token::ASCENDING;
}
"descending"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DESCENDING" << endl;
#endif
  return token::DESCENDING;
}
"default"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DEFAULT" << endl;
#endif
  return token::DEFAULT;
}
"]" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RBRACK" << endl;
#endif
  return token::RBRACK;
}
{StringLiteral} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "scanner::TRY_STRINGLIT" << std::endl;
#endif
  TRY_STRINGLIT (STRING_LITERAL, yytext, yyleng);
}


  /*______________________________________________________________________  
   |
   | FT rules <OPERATOR>
   |______________________________________________________________________*/

  /* transition to INITIAL state */
  /* --------------------------- */
  
"ftcontains"/{WordBreak} {
  BEGIN INITIAL;
  getDriver()->set_ftcontains(true);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTCONTAINS" << endl;
#endif
  return token::FTCONTAINS;
}
"&&" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTAND" << endl;
#endif
  return token::FTAND;
}
"!" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTNOT" << endl;
#endif
  return token::FTNOT;
}
"||" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTOR" << endl;
#endif
  return token::FTOR;
}
"not"<SP>"in"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FTNOT_IN" << endl;
#endif
  return token::FTNOT_IN;
}
"at"{SP}"least"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_LEAST" << endl;
#endif
  return token::AT_LEAST;
}
"at"{SP}"most"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_MOST" << endl;
#endif
  return token::AT_MOST;
}
"distance"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DISTANCE" << endl;
#endif
  return token::DISTANCE;
}
"exactly"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXACTLY" << endl;
#endif
  return token::EXACTLY;
}
"from"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FROM" << endl;
#endif
  return token::FROM;
}
"occurs"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OCCURS" << endl;
#endif
  return token::OCCURS;
}
"window"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WINDOW" << endl;
#endif
  return token::WINDOW;
}


  /* maintain OPERATOR state */
  /* ----------------------- */
"all"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ALL" << endl;
#endif
  return token::ALL;
}
"all"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ALL_WORDS" << endl;
#endif
  return token::ALL_WORDS;
}
"any"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANY" << endl;
#endif
  return token::ANY;
}
"any"{SP}"word"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ANY_WORD" << endl;
#endif
  return token::ANY_WORD;
}
"at"{SP}"end"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_END" << endl;
#endif
  return token::AT_END;
}
"at"{SP}"start"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT_START" << endl;
#endif
  return token::AT_START;
}
"case"{SP}"insensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE_INSENSITIVE" << endl;
#endif
  return token::CASE_INSENSITIVE;
}
"case"{SP}"sensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE_SENSITIVE" << endl;
#endif
  return token::CASE_SENSITIVE;
}
"declare"{SP}"ftoption"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DECLARE_FTOPTION" << endl;
#endif
  return token::DECLARE_FTOPTION;
}
"diacritics"{SP}"insensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIACRITICS_INSENSITIVE" << endl;
#endif
  return token::DIACRITICS_INSENSITIVE;
}
"diacritics"{SP}"sensitive"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIACRITICS_SENSITIVE" << endl;
#endif
  return token::DIACRITICS_SENSITIVE;
}
"different"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIFFERENT" << endl;
#endif
  return token::DIFFERENT;
}
"entire"{SP}"content"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENTIRE_CONTENT" << endl;
#endif
  return token::ENTIRE_CONTENT;
}
"language"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LANGUAGE" << endl;
#endif
  return token::LANGUAGE;
}
"levels"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LEVELS" << endl;
#endif
  return token::LEVELS;
}
"lowercase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LOWERCASE" << endl;
#endif
  return token::LOWERCASE;
}
"paragraph"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PARAGRAPH" << endl;
#endif
  return token::PARAGRAPH;
}
"phrase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PHRASE" << endl;
#endif
  return token::PHRASE;
}
"relationship"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RELATIONSHIP" << endl;
#endif
  return token::RELATIONSHIP;
}
"same"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SAME" << endl;
#endif
  return token::SAME;
}
"score"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCORE" << endl;
#endif
  return token::SCORE;
}
"sentence"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SENTENCE" << endl;
#endif
  return token::SENTENCE;
}
"sentences"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SENTENCES" << endl;
#endif
  return token::SENTENCES;
}
"times"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TIMES" << endl;
#endif
  return token::TIMES;
}
"uppercase"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UPPERCASE" << endl;
#endif
  return token::UPPERCASE;
}
"weight"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WEIGHT" << endl;
#endif
  return token::WEIGHT;
}
"without"{SP}"content"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_CONTENT" << endl;
#endif
  return token::WITHOUT_CONTENT;
}
"without"{SP}"diacritics"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_DIACRITICS" << endl;
#endif
  return token::WITHOUT_DIACRITICS;
}
"without"{SP}"stemming"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_STEMMING" << endl;
#endif
  return token::WITHOUT_STEMMING;
}
"without"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_STOP_WORDS" << endl;
#endif
  return token::WITHOUT_STOP_WORDS;
}
"without"{SP}"thesaurus"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_THESAURUS" << endl;
#endif
  return token::WITHOUT_THESAURUS;
}
"without"{SP}"wildcards"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITHOUT_WILDCARDS" << endl;
#endif
  return token::WITHOUT_WILDCARDS;
}
"with"{SP}"default"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_DEFAULT_STOP_WORDS" << endl;
#endif
  return token::WITH_DEFAULT_STOP_WORDS;
}
"with"{SP}"diacritics"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_DIACRITICS" << endl;
#endif
  return token::WITH_DIACRITICS;
}
"with"{SP}"stemming"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_STEMMING" << endl;
#endif
  return token::WITH_STEMMING;
}
"with"{SP}"stop"{SP}"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_STOP_WORDS" << endl;
#endif
  return token::WITH_STOP_WORDS;
}
"with"{SP}"thesaurus"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_THESAURUS" << endl;
#endif
  return token::WITH_THESAURUS;
}
"with"{SP}"wildcards"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WITH_WILDCARDS" << endl;
#endif
  return token::WITH_WILDCARDS;
}
"words"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WORDS" << endl;
#endif
  return token::WORDS;
}
"(#" {
  BEGIN MODE_PRAGMA;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRAGMA_BEGIN" << endl;
#endif
  return token::PRAGMA_BEGIN;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_OPERATOR> */



  /*______________________________________________________________________  
   |
   | XQUERY_VERSION State
   |
   | This state is for recognition of XQuery version specific keywords. 
   |______________________________________________________________________*/

<MODE_XQUERY_VERSION>{

  /* transition to INITIAL */
  /* --------------------- */
";" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SEMI" << endl;
#endif
  return token::SEMI;
}

  /* maintain XQUERYVERSION */
  /* ---------------------- */
{StringLiteral} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "scanner::TRY_STRINGLIT" << std::endl;
#endif
  TRY_STRINGLIT (STRING_LITERAL, yytext, yyleng);
}

"encoding"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENCODING" << endl;
#endif
  return token::ENCODING;
}

{SP} {
  /* eat up whitespace */
}

} /* <MODE_XQUERY_VERSION> */




  /*______________________________________________________________________  
   |
   | NAMESPACEDECL State
   |
   | This state occurs inside of a namespace declaration, and is needed
   | to recognize a NCName that is to be used as the prefix, as opposed
   | to allowing a QName to occur. (Otherwise, the difference between
   | NCName and QName becomes ambiguous.)
   |______________________________________________________________________*/

<MODE_NAMESPACEDECL>{

"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

";" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SEMI" << endl;
#endif
  return token::SEMI;
}

  /* maintain NAMESPACEDECL */
  /* ---------------------- */
{URILiteral} {
  TRY_URILIT (URI_LITERAL, yytext, yyleng);
}

"," {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}

"at"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT" << endl;
#endif
  return token::AT;
}

"=" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EQUALS" << endl;
#endif
  return token::EQUALS;
}

{NCName} {
  yylval->sval = getDriver()->symtab.put_ncname(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NCNAME" << endl;
#endif
  return token::NCNAME;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_NAMESPACEDECL> */




  /*______________________________________________________________________  
   |
   | URITOOPERATOR State
   |
   | This state is to recognize a URILiteral that transitions to the
   | OPERATOR state.
   |______________________________________________________________________*/

<MODE_URITOOPERATOR>{S}{URILiteral} {
  BEGIN MODE_OPERATOR;
  TRY_URILIT (URI_LITERAL, yytext, yyleng);
}




  /*______________________________________________________________________  
   |
   | NAMESPACEKEYWORD State
   |
   | This state occurs at places where the keyword "namespace" is
   | expected, which would otherwise be ambiguous compared to a QName.
   | QNames can not occur in this state.
   |______________________________________________________________________*/

<MODE_NAMESPACEKEYWORD>{

  /* transition to NAMESPACEDECL */
  /* --------------------------- */
{URILiteral} {
  BEGIN MODE_NAMESPACEDECL;
  TRY_URILIT (URI_LITERAL, yytext, yyleng);
}

"namespace"/{WordBreak} {
  BEGIN MODE_NAMESPACEDECL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NAMESPACE" << endl;
#endif
  return token::NAMESPACE;
}

  /* transition to INITIAL */
  /* --------------------- */
"inherit"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INHERIT" << endl;
#endif
  return token::INHERIT;
}

"no-inherit"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NO_INHERIT" << endl;
#endif
  return token::NO_INHERIT;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}


  /* maintain NAMESPACEKEYWORD */
  /* ------------------------- */
"default"{SP}"element"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DEFAULT_ELEMENT" << endl;
#endif
  return token::DEFAULT_ELEMENT;
}

"preserve"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRESERVE" << endl;
#endif
  return token::PRESERVE;
}

"no-preserve"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NO_PRESERVE" << endl;
#endif
  return token::NO_PRESERVE;
}

"," {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_NAMESPACEKEYWORD> */




  /*______________________________________________________________________  
    |
    | XMLSPACE_DECL State
    |
    | This state occurs at places where the keywords "preserve" and
    | "strip" is expected to support "declare xmlspace". QNames cannot
    | occur in this state.
    |______________________________________________________________________*/

<MODE_XMLSPACE_DECL>{

  /* transition to INITIAL */
  /* --------------------- */
"preserve"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRESERVE" << endl;
#endif
  return token::PRESERVE;
}

"strip"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STRIP" << endl;
#endif
  return token::STRIP;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_XMLSPACE_DECL> */




  /*______________________________________________________________________  
   |
   | SINGLETYPE State 
   |
   | This state distinguishes tokens that can occur only inside the
   | SingleType production.
   |______________________________________________________________________*/

<MODE_SINGLETYPE>{

  /* transition to OPERATOR */
  /* ---------------------- */
{QName} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_SINGLETYPE> */




  /*______________________________________________________________________  
   |
   | ITEMTYPE State
   |
   | This state distinguishes tokens that can occur only inside the
   | ItemType production.
   |______________________________________________________________________*/

<MODE_ITEMTYPE>{

  /* transition to VARNAME */
  /* --------------------- */
"$" {
  BEGIN MODE_VARNAME;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOLLAR" << endl;
#endif
  return token::DOLLAR;
}

"empty-sequence"{S}"("{SOrComment}")" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VOID_TEST" << endl;
#endif
  return token::VOID_TEST;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

  /* transition to KINDTEST */
  /* ---------------------- */
"element"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_LPAR" << endl;
#endif
  return token::ELEMENT_LPAR;
}

"attribute"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ATTRIBUTE_LPAR" << endl;
#endif
  return token::ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCHEMA_ELEMENT_LPAR" << endl;
#endif
  return token::SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCHEMA_ATTRIBUTE_LPAR" << endl;
#endif
  return token::SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMENT_LPAR" << endl;
#endif
  return token::COMMENT_LPAR;
}

"text"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TEXT_LPAR" << endl;
#endif
  return token::TEXT_LPAR;
}

"node"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NODE_LPAR" << endl;
#endif
  return token::NODE_LPAR;
}

"document-node"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOCUMENT_NODE_LPAR" << endl;
#endif
  return token::DOCUMENT_NODE_LPAR;
}

  /* transition to KINDTESTFORPI */
  /* --------------------------- */
"processing-instruction"{S}"(" {
  BEGIN MODE_OCCURRENCE_INDICATOR; 
  yy_push_state(MODE_KINDTESTFORPI);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_LPAR" << endl;
#endif
  return token::PI_LPAR;
}

"item"{S}"("{SOrComment}")" { 
  BEGIN MODE_OCCURRENCE_INDICATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ITEM_TEST" << endl;
#endif
  return token::ITEM_TEST;
}

  /* transition to PRAGMA */
  /* -------------------- */
"(#" {
  BEGIN MODE_PRAGMA;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRAGMA_BEGIN" << endl;
#endif
  return token::PRAGMA_BEGIN;
}

  /* transition to INITIAL */
  /* --------------------- */
";" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SEMI" << endl;
#endif
  return token::SEMI;
}

"then"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::THEN" << endl;
#endif
  return token::THEN;
}

"else"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELSE" << endl;
#endif
  return token::ELSE;
}

  /* transition to NAMESPACEDECL */
  /* --------------------------- */
"at"{SP}{URILiteral} {
  const char *p = yytext + 2;
  for (; *p != '\'' && *p != '"'; p++);
  BEGIN MODE_NAMESPACEDECL;
  TRY_URILIT (AT_URI_LITERAL, p, yyleng + (p - yytext));
}

  /* transition to INITIAL */
  /* --------------------- */
"external"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXTERNAL" << endl;
#endif
  return token::EXTERNAL;
}

"and"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AND" << endl;
#endif
  return token::AND;
}

"at"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AT" << endl;
#endif
  return token::AT;
}

":=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GETS" << endl;
#endif
  return token::GETS;
}

"," {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}

"div"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DIV" << endl;
#endif
  return token::DIV;
}

"=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EQUALS" << endl;
#endif
  return token::EQUALS;
}

"except"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EXCEPT" << endl;
#endif
  return token::EXCEPT;
}

"eq"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_EQ" << endl;
#endif
  return token::VAL_EQ;
}

"ge"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_GE" << endl;
#endif
  return token::VAL_GE;
}

"gt"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_GT" << endl;
#endif
  return token::VAL_GT;
}

"le"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_LE" << endl;
#endif
  return token::VAL_LE;
}

"lt"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_LT" << endl;
#endif
  return token::VAL_LT;
}

"ne"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VAL_NE" << endl;
#endif
  return token::VAL_NE;
}

">=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GE" << endl;
#endif
  return token::GE;
}

">>" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::FOLLOWS" << endl;
#endif
  return token::FOLLOWS;
}

">" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::GT" << endl;
#endif
  return token::GT;
}

"idiv"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IDIV" << endl;
#endif
  return token::IDIV;
}

"intersect"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INTERSECT" << endl;
#endif
  return token::INTERSECT;
}

"in"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::_IN_" << endl;
#endif
  return token::_IN_;
}

"is"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::IS" << endl;
#endif
  return token::IS;
}

"[" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACK" << endl;
#endif
  return token::LBRACK;
}

"(" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LPAR" << endl;
#endif
  return token::LPAR;
}

"<=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LE" << endl;
#endif
  return token::LE;
}

"<<" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRECEDES" << endl;
#endif
  return token::PRECEDES;
}

"<" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LT" << endl;
#endif
  return token::LT;
}

"-" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MINUS" << endl;
#endif
  return token::MINUS;
}

"mod"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::MOD" << endl;
#endif
  return token::MOD;
}

"!=" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NE" << endl;
#endif
  return token::NE;
}

"order"{SP}"by"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ORDER_BY" << endl;
#endif
  return token::ORDER_BY;
}

"stable"{SP}"order"{SP}"by"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STABLE_ORDER_BY" << endl;
#endif
  return token::STABLE_ORDER_BY;
}

"or"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OR" << endl;
#endif
  return token::OR;
}

"return"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RETURN" << endl;
#endif
  return token::RETURN;
}

"satisfies"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SATISFIES" << endl;
#endif
  return token::SATISFIES;
}

"to"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TO" << endl;
#endif
  return token::TO;
}

"union"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNION" << endl;
#endif
  return token::UNION;
}

"|" {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VBAR" << endl;
#endif
  return token::VBAR;
}

"where"/{WordBreak} {
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::WHERE" << endl;
#endif
  return token::WHERE;
}

  /* transition to SINGLETYPE */
  /* ------------------------ */
"castable"{SP}"as"/{WordBreak} {
  BEGIN MODE_SINGLETYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASTABLE_AS" << endl;
#endif
  return token::CASTABLE_AS;
}

"cast"{SP}"as"/{WordBreak} {
  BEGIN MODE_SINGLETYPE;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CAST_AS" << endl;
#endif
  return token::CAST_AS;
}

  /* maintain ITEMTYPE */
  /* ----------------- */
"instance"{SP}"of"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::INSTANCE_OF" << endl;
#endif
  return token::INSTANCE_OF;
}

"treat"{SP}"as"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TREAT_AS" << endl;
#endif
  return token::TREAT_AS;
}

"case"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CASE" << endl;
#endif
  return token::CASE;
}

"as"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::AS" << endl;
#endif
  return token::AS;
}

")"{S}"as"/{WordBreak} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR_AS" << endl;
#endif
  return token::RPAR_AS;
}

{QName} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN MODE_OCCURRENCE_INDICATOR; 
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_ITEMTYPE> */




  /*______________________________________________________________________  
   |
   | KINDTEST State
   |
   | This state is for the psuedo-parameters for the KindTest productions
   |______________________________________________________________________*/

<MODE_KINDTEST>{

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

  /* transition to CLOSE_KINDTEST */
  /* --------------------------- */
"*" {
  BEGIN MODE_CLOSE_KINDTEST;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::STAR" << endl;
#endif
  return token::STAR;
}

{QName} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN MODE_CLOSE_KINDTEST;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

  /* pop previous state on close paren */
  /* --------------------------------- */
")" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}

  /* maintain KINDTEST */
  /* ----------------- */
"element"{S}"(" {
  BEGIN MODE_KINDTEST;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_LPAR" << endl;
#endif
  return token::ELEMENT_LPAR;
}

"schema-element"{S}"(" {
  BEGIN MODE_KINDTEST;
  yy_push_state(MODE_KINDTEST);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::SCHEMA_ELEMENT_LPAR" << endl;
#endif
  return token::SCHEMA_ELEMENT_LPAR;
}

  /* catch-all */
  /* --------- */
{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_KINDTEST> */



  /*______________________________________________________________________  
   |
   | KINDTESTFORPI
   |
   | This state is similar to KINDTEST, but recognizes NCNames instead of
   | QNames.
   |______________________________________________________________________*/

<MODE_KINDTESTFORPI>{

  /* pop previous state on close paren */
  /* --------------------------------- */
")" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */

"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

  /* maintain KINDTESTFORPI */
  /* ---------------------- */
{NCName} {
  yylval->sval = getDriver()->symtab.put_ncname(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::NCNAME" << endl;
#endif
  return token::NCNAME;
}

{StringLiteral} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "scanner::TRY_STRINGLIT" << endl;
#endif
  TRY_STRINGLIT (STRING_LITERAL, yytext, yyleng);
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_KINDTESTFORPI> */




  /*______________________________________________________________________  
   |
   | CLOSE_KINDTEST State
   |
   | This state is expecting to close a KINDTEST sequence.
   |______________________________________________________________________*/ 

<MODE_CLOSE_KINDTEST>{

  /* pop previous state */
  /* ------------------ */
")" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::RPAR" << endl;
#endif
  return token::RPAR;
}

  /* transition to KINDTEST */
  /* ---------------------- */
"," {
  BEGIN MODE_KINDTEST;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::COMMA" << endl;
#endif
  return token::COMMA;
}

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  BEGIN MODE_OPERATOR;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

  /* maintain CLOSE_KINDTEST */
  /* ---------------------- */
"?" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::HOOK" << endl;
#endif
  return token::HOOK;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_CLOSE_KINDTEST> */




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

<MODE_OCCURRENCE_INDICATOR>{

  /* transition to OPERATOR */
  /* ---------------------- */
"?" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OCCURS_HOOK" << endl;
#endif
  return token::OCCURS_HOOK;
}

"*" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OCCURS_STAR" << endl;
#endif
  return token::OCCURS_STAR;
}

"+" {
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::OCCURS_PLUS" << endl;
#endif
  return token::OCCURS_PLUS;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

  /* anything else: push back, goto OPERATOR */
  /* --------------------------------------- */
{CatchAll} {
  yyless(0);
  BEGIN MODE_OPERATOR;
}

{S} {
  /* eat up whitespace */
}

} /* MODE_OCCURRENCE_INDICATOR> */




  /*______________________________________________________________________  
   |
   | OPTION State
   |
   | This state is entered in the prolog for an option declaration, and
   | recognizes a QName that transits to a INITIAL state rather than a
   | OPERATOR state.
   |______________________________________________________________________*/

<MODE_OPTION>{

  /* transition to INITIAL */
  /* --------------------- */
{QName}  {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
  BEGIN INITIAL;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_OPTION> */




  /*______________________________________________________________________  
   |
   | PRAGMA State
   |
   | This state is entered in a a pragma expression, and recognizes
   | a QName that transits to a PRAGMACONTENTS state rather than an
   | OPERATOR state.
   |______________________________________________________________________*/

<MODE_PRAGMA>{

  /* transition to PRAGMACONTENTS */
  /* ---------------------------- */
{QName}{SPNoComment} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng,true,true);
  BEGIN MODE_PRAGMACONTENTS;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

{QName}"#)" {
  BEGIN MODE_OPERATOR;
  yylval->sval = getDriver()->symtab.put(yytext, yyleng-2);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME_AND_END_PRAGMA" << endl;
#endif
  return token::QNAME_AND_END_PRAGMA;
}

{S} {
  /* eat up whitespace */
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* <MODE_PRAGMA> */




  /*______________________________________________________________________  
   |
   | PRAGMACONTENTS State
   |
   | This state recognizes characters in pragma content and transitions
   | out of this state when a '#)' pattern is recognized.
   |______________________________________________________________________*/

<MODE_PRAGMACONTENTS>{

  /* transition to OPERATOR */
  /* ---------------------- */
{PragmaChars}")" {
  BEGIN MODE_OPERATOR;
  yylval->sval = getDriver()->symtab.put(yytext, yyleng-2);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PRAGMA_LITERAL_AND_END" << endl;
#endif
  return token::PRAGMA_LITERAL_AND_END;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* <MODE_PRAGMACONTENTS> */




  /*______________________________________________________________________  
   |
   | VARNAME State
   |
   | This state differentiates variable names from qualified names. This
   | allows only the pattern of a QName to be recognized when otherwise
   | ambiguities could occur.
   |______________________________________________________________________*/

<MODE_VARNAME>{

  /* transition to OPERATOR */
  /* ---------------------- */
{VarName} {
  yylval->sval = getDriver()->symtab.put_varname(yytext, yyleng);
  BEGIN MODE_OPERATOR;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::VARNAME" << endl;
#endif
  return token::VARNAME;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

} /* <MODE_VARNAME> */




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

<MODE_START_TAG>{

  /* transition to ELEMENT_CONTENT */
  /* ----------------------------- */
">" {
  BEGIN MODE_ELEMENT_CONTENT;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TAG_END" << endl;
#endif
  return token::TAG_END;
}

  /* transition to QUOT_ATTRIBUTE_CONTENT */
  /* ------------------------------------ */
\" {
  BEGIN MODE_QUOTE_ATTRIBUTE_CONTENT;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QUOTE" << endl;
#endif
  return token::QUOTE;
}

  /* transition to APOS_ATTRIBUTE_CONTENT */
  /* ------------------------------------ */
\' {
  BEGIN MODE_APOS_ATTRIBUTE_CONTENT;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::APOS" << endl;
#endif
  return token::APOS;
}

  /* transition to START_TAG */
  /* ----------------------- */
"=" {
  BEGIN MODE_START_TAG;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EQUALS" << endl;
#endif
  return token::EQUALS;
}

  /* pop previous state on exit */
  /* -------------------------- */
"/>" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::EMPTY_TAG_END" << endl;
#endif
  return token::EMPTY_TAG_END;
}

  /* maintain START_TAG */
  /* ------------------ */
{S} {
  /* continue lexing */
}

{QName} {
  yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* <MODE_START_TAG> */




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

<MODE_ELEMENT_CONTENT>{

  /* transition to END_TAG */
  /* --------------------- */
"</" {
  BEGIN MODE_END_TAG;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::START_TAG_END" << endl;
#endif
  return token::START_TAG_END;
}

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

  /* transition to EXPR_COMMENT */
  /* -------------------------- */
"<!--" {
  yy_push_state(MODE_XML_COMMENT);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::XML_COMMENT_BEGIN" << endl;
#endif
  return token::XML_COMMENT_BEGIN;
}

  /* transition to PROCESSING_INSTRUCTION */
  /* ------------------------------------ */
"<?" {
  yy_push_state(MODE_PROCESSING_INSTRUCTION);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_BEGIN" << endl;
#endif
  return token::PI_BEGIN;
}

  /* transition to CDATA_SECTION */
  /* --------------------------- */
"<![CDATA[" {
  yy_push_state(MODE_CDATA_SECTION);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CDATA_BEGIN" << endl;
#endif
  return token::CDATA_BEGIN;
}

  /* transition to START_TAG */
  /* ----------------------- */
"<" {
  yy_push_state(MODE_START_TAG);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::START_TAG" << endl;
#endif
  return token::START_TAG;
}

  /* maintain ELEMENT_CONTENT */
  /* ------------------------ */
{ElementContentChar}+ {
  yylval->sval = getDriver()->symtab.put(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_CONTENT" << endl;
#endif
  return token::ELEMENT_CONTENT;
}

{PredefinedEntityRef} {
  yylval->sval = getDriver()->symtab.put_entityref(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENTITY_REF" << endl;
#endif
  return token::ELEMENT_CONTENT;
}

{CharRef}+ {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ELEMENT_CONTENT" << endl;
#endif
  TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng);
}

"{{" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_LBRACE" << endl;
#endif
  return token::DOUBLE_LBRACE;
}

"}}" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_RBRACE" << endl;
#endif
  return token::DOUBLE_RBRACE;
}

  /* catch all else */
  /* -------------- */
{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* MODE_ELEMENT_CONTENT> */




  /*______________________________________________________________________  
   |
   | END_TAG State
   |
   | When the end tag is terminated, the state is popped to the state
   | that was pushed at the start of the corresponding start tag.
   |______________________________________________________________________*/

<MODE_END_TAG>{

  /* pop previous state on exit */
  /* -------------------------- */
">" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::TAG_END" << endl;
#endif
  return token::TAG_END;
}

  /* maintain END_TAG */
  /* ---------------- */
 {QName}{S} {
   yylval->sval = getDriver()->symtab.put_qname(yytext, yyleng, false, true);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QNAME" << endl;
#endif
  return token::QNAME;
}

  /* catch all else */
  /* -------------- */
{CatchAll} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* <MODE_END_TAG> */




  /*______________________________________________________________________  
   |
   | XML_COMMENT State
   | The "<--" token marks the beginning of an XML Comment, and the "-->"
   | token marks the end. This allows no special interpretation of other
   | characters in this state.
   |______________________________________________________________________*/

<MODE_XML_COMMENT>{

  /* pop previous state on exit */
  /* -------------------------- */
"-->" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::XML_COMMENT_END" << endl;
#endif
  return token::XML_COMMENT_END;
}

  /* maintain XML_COMMENT */
  /* -------------------- */
{XMLCommentChar}* {
  yylval->sval = getDriver()->symtab.put(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::XML_COMMENT_LITERAL" << endl;
#endif
  return token::XML_COMMENT_LITERAL;
}

 {CatchAll} {
 #ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
 }
} /* <MODE_XML_COMMENT> */




  /*______________________________________________________________________  
   |
   | EXPR_COMMENT State
   |
   | The "(:" token marks the beginning of an expression Comment, and
   | the ":)" token marks the end. This allows no special interpretation
   | of other characters in this state.
   |______________________________________________________________________*/

<MODE_EXPR_COMMENT>{

  /* pop previous state */
  /* ------------------ */
":)" {
  yy_pop_state();
}

  /* maintain EXPR_COMMENT */
  /* --------------------- */
"(:" {
  yy_push_state(MODE_EXPR_COMMENT);
}

. {
  /* do nothing */
}

<<EOF>> {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::UNRECOGNIZED" << endl;
#endif
  return token::UNRECOGNIZED;
}

} /* <MODE_EXPR_COMMENT> */




  /*______________________________________________________________________  
   |
   | PROCESSING_INSTRUCTION State
   |
   | In this state, only patterns that are legal in a processing
   | instruction name are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION>{

  /* transition to PROCESSING_INSTRUCTION_CONTENT */
  /* -------------------------------------------- */
{SP} {
  BEGIN MODE_PROCESSING_INSTRUCTION_CONTENT; 
  /* continue lexing */
}

  /* pop previous state on exit */
  /* -------------------------- */
"?>" {
  yy_pop_state();
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_END" << endl;
#endif
  return token::PI_END;
}

  /* maintain PROCESSING_INSTRUCTION */
  /* ------------------------------- */
{PITarget} {
  yylval->sval = getDriver()->symtab.put(yytext, yyleng);
  BEGIN MODE_PROCESSING_INSTRUCTION;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::PI_TARGET_LITERAL" << endl;
#endif
  return token::PI_TARGET_LITERAL;
}

} /* <MODE_PROCESSING_INSTRUCTION> */




  /*______________________________________________________________________  
   |
   | PROCESSING_INSTRUCTION_CONTENT State
   |
   | In this state, only characters are that are legal in processing
   | instruction content are recognized.
   |______________________________________________________________________*/

<MODE_PROCESSING_INSTRUCTION_CONTENT>{

  /* pop previous state on exit */
  /* -------------------------- */
{PIChars}"?>" {
  yy_pop_state();
  yylval->sval = getDriver()->symtab.put(yytext, yyleng-2);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CHAR_LITERAL_AND_PI_END" << endl;
#endif
  return token::CHAR_LITERAL_AND_PI_END;
}

} /* <MODE_PROCESSING_INSTRUCTION_CONTENT> */




  /*______________________________________________________________________  
   |
   | CDATA_SECTION State
   |
   | In this state, only lexemes that are legal in a CDATA section are
   | recognized.
   |______________________________________________________________________*/

<MODE_CDATA_SECTION>{
  
  /* pop previous state on exit */
  /* -------------------------- */
"]]>" {
  yy_pop_state();
  yylval->sval = getDriver()->symtab.put(yytext, yyleng-3);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::CHAR_LITERAL_AND_CDATA_END" << endl;
#endif
  return token::CHAR_LITERAL_AND_CDATA_END;
}

  /* maintain CDATA_SECTION */
  /* ---------------------- */
{Char} {
  yymore();
}

} /* <MODE_CDATA_SECTION> */




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

<MODE_QUOTE_ATTRIBUTE_CONTENT>{

  /* transition to START_TAG */
  /* ----------------------- */
\" {
  BEGIN MODE_START_TAG;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QUOTE" << endl;
#endif
  return token::QUOTE;
}

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

  /* maintain QUOTE_ATTRIBUTE_CONTENT */
  /* -------------------------------- */
{EscapeQuot} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ESCAPE_QUOTE" << endl;
#endif
  return token::ESCAPE_QUOTE;
}

{QuotAttrContentChar}+ {
  yylval->sval = getDriver()->symtab.put(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QUOTE_ATTR_CONTENT" << endl;
#endif
  return token::QUOTE_ATTR_CONTENT;
}

{PredefinedEntityRef} {
  yylval->sval = getDriver()->symtab.put_entityref(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENTITY_REF" << endl;
#endif
  return token::QUOTE_ATTR_CONTENT;
}

{CharRef}+ {
  TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::QUOTE_ATTR_CONTENT" << endl;
#endif
}

"{{" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_LBRACE" << endl;
#endif
  return token::DOUBLE_LBRACE;
}

"}}" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_RBRACE" << endl;
#endif
  return token::DOUBLE_RBRACE;
}

} /* <MODE_QUOTE_ATTRIBUTE_CONTENT> */




  /*______________________________________________________________________  
   |
   | APOS_ATTRIBUTE_CONTENT State
   |
   | This state is the same as QUOT_ATTRIBUTE_CONTENT, except that
   | quotes are allowed, and an unescaped apostrophe marks the end of
   | the state.
   |______________________________________________________________________*/

<MODE_APOS_ATTRIBUTE_CONTENT>{

  /* transition to START_TAG */
  /* ----------------------- */
\' {
  BEGIN MODE_START_TAG;
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::APOS" << endl;
#endif
  return token::APOS;
}

  /* transition to INITIAL */
  /* --------------------- */
"{" {
  BEGIN MODE_APOS_ATTRIBUTE_CONTENT;
  yy_push_state(INITIAL);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::LBRACE" << endl;
#endif
  return token::LBRACE;
}

  /* maintain APOS_ATTRIBUTE_CONTENT */
  /* ------------------------------- */
{EscapeApos} {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ESCAPE_APOS" << endl;
#endif
  return token::ESCAPE_APOS;
}

{AposAttrContentChar}+ {
  yylval->sval = getDriver()->symtab.put(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::APOS_ATTR_CONTENT" << endl;
#endif
  return token::APOS_ATTR_CONTENT;
}

{PredefinedEntityRef} {
  yylval->sval = getDriver()->symtab.put_entityref(yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::ENTITY_REF" << endl;
#endif
  return token::APOS_ATTR_CONTENT;
}

{CharRef}+ {
  TRY_STR_LIT (CHAR_REF_LITERAL, put_charref, yytext, yyleng);
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::APOS_ATTR_CONTENT" << endl;
#endif
}

"{{" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_LBRACE" << endl;
#endif
  return token::DOUBLE_LBRACE;
}

"}}" {
#ifdef ZORBA_DEBUG_SCANNER
  cout << "token::DOUBLE_RBRACE" << endl;
#endif
  return token::DOUBLE_RBRACE;
}

} /* <MODE_APOS_ATTRIBUTE_CONTENT> */


<*>. return token::UNRECOGNIZED;

%%


/*
  Finally, because the scanner related driver's member function depend 
  on the scanner's data, it is simpler to implement them in this file. 
*/

std::string start_state(int state)
{
  switch (state) {
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
    case MODE_QUOTE_ATTRIBUTE_CONTENT: return "MODE_QUOTE_ATTRIBUTE_CONTENT";
    case MODE_SINGLETYPE: return "MODE_SINGLETYPE";
    case MODE_START_TAG: return "MODE_START_TAG";
    case MODE_URITOOPERATOR: return "MODE_URITOOPERATOR";
    case MODE_VARNAME: return "MODE_VARNAME";
    case MODE_XMLSPACE_DECL: return "MODE_XMLSPACE_DECL";
    case MODE_XML_COMMENT: return "MODE_XML_COMMENT";
    case MODE_XQUERY_VERSION: return "MODE_XQUERY_VERSION";
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
}

#ifdef yylex
#undef yylex
#endif

int ZorbaFlexLexer::yylex()
{
  std::cerr << "in ZorbaFlexLexer::yylex() !" << std::endl;
  return 0;
}
