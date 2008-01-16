/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xquery.l,v 1.4 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 */

/*______________________________________________________________________
|                                                                       
| 	An implementation of the w3c proposal:                              
|                                                                       
| 	"Building a Tokenizer for XPath or XQuery,                          
| 	 W3C Working Draft 4 April 2005"                                    
|                                                                       
| 	[http://www.w3.org/TR/xquery-xpath-parsing/]                        
|                                                                       
| 	Extensions including update, search, and XQueryP:                   
|                                                                       
| 	[http://www.w3.org/TR/xqupdate/]                                    
| 	[http://www.w3.org/TR/xquery-full-text/]                            
| 	[http://www.ximep-2006.org/papers/Paper-Chamberlin-Carey.pdf]       
|                                                                      
|_______________________________________________________________________*/


%{ /* _*_ C++ _*_ */

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#ifndef _WIN32_WCE
#include <io.h>
#endif
#endif

#include <cstdlib>
#ifndef _WIN32_WCE
#include <errno.h>
#endif
#include <limits.h>
#include <iostream>
#include <string>

#include "compiler/parser/symbol_table.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_parser.hpp"
#include "zorba/util/properties.h"

/*
	Work around an incompatibility in flex (at least versions
	2.5.31 through 2.5.33): it generates code that does
	not conform to C89.  See Debian bug 333231
	<http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
*/
#undef yywrap
#define yywrap(yyscanner) 1
     
/*
	By default yylex returns int, we use token_type.
	Unfortunately yyterminate by default returns 0, which is
	not of token_type.
*/
#define yyterminate() return token::END

%}


	/*______________________________________________________________________
	 *                                                                      *
   *  Scanner options                                                     *
	 *______________________________________________________________________*/

%option outfile="xquery_scanner.yy.cpp"
/*%option case-insensitive*/
/*%option nostdinit*/
%option noyywrap
%option batch
%option debug
%option stack
%option reentrant
%option nounistd


	/* known expensive option */
%option yylineno


	/*_____________________________________________________________________
	|
	|  Whitespace definitions
	|______________________________________________________________________*/
blank 			[ \t]
S						[ \t\r\n\f]*
SP					[ \t\r\n\f]+

	/*_____________________________________________________________________
	|
	|  Basic character classes
	|______________________________________________________________________*/
Letter			[A-Za-z]
Digit				[0-9]
CatchAll		[^ \t\r\n]

	/*_____________________________________________________________________
	|
	|  XQuery allows '' to escape ', and "" to escape ".
	|______________________________________________________________________*/
EscapeApos	\'\'
EscapeQuot	\"\" 

	/*_____________________________________________________________________
	|
	|  NCName definition
	|______________________________________________________________________*/
Nmstart			({Letter}|_)
Nmchar			({Letter}|{Digit}|[._-])
NCName			{Nmstart}{Nmchar}*

	/*_____________________________________________________________________
	|
	|  QName definition
	|______________________________________________________________________*/
QName				({NCName}":")?{NCName}

	/*_____________________________________________________________________
	|
	|  VarName definition
	|______________________________________________________________________*/
VarName			{QName}


	/*_____________________________________________________________________
	|
	|  Entity definitions
	|______________________________________________________________________*/
CharRef               "&#"([0-9]+|x([0-9]|[a-f]|[A-F])+);
PredefinedEntityRef		"&"(lt|gt|amp|quot|apos|nbsp);

	/*_____________________________________________________________________
	|
	|  Numeric literal definitions
	|______________________________________________________________________*/
DecimalLiteral				(\.[0-9]+)|([0-9]+(\.[0-9]+)?)
DoubleLiteral					((\.[0-9]+)|([0-9]+(\.[0-9]+)?))([eE][+-]?[0-9]+)?
IntegerLiteral				[0-9]+
NumericLiteral				((\.[0-9]+)|([0-9]+(\.[0-9]+)?))([eE][+-]?[0-9]+)?

	/*_____________________________________________________________________
	|
	|  String literal definitions
	|______________________________________________________________________*/
StringLiteral					(\"((\"\")|[^"])*\")|(\'((\'\')|[^'])*\')
URILiteral						{StringLiteral}

	/*_____________________________________________________________________
	|
	|  Content character definitions
	|______________________________________________________________________*/
Char									[\x09\x0A\x0D\x20-\xFD]
NonHyphenChar					[\x09\x0D\x0A\x20-\x2C\x2E-\xFD]
XMLCommentChar				({NonHyphenChar}*)|(-{NonHyphenChar}+)
NonRParChar						[\x09\x0D\x0A\x20-\x28\x2A-\xFD]
NonColonChar					[\x09\x0D\x0A\x20-\x39\x3B-\xFD]
CommentContent				({NonColonChar}*)|(:{NonRParChar}{NonColonChar}*)
ElementContentChar		[\x09\x0A\x0D\x20-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
QuotAttrContentChar 	[\x09\x0A\x0D\x20-\x21\x23-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
AposAttrContentChar 	[\x09\x0A\x0D\x20-\x25\x28-\x3B\x3D-\x7A\x7C\x7E-\xFD]

  /*
  NonXChar	[\x09\x0A\x0D\x20A-WY-Za-wy-z\x7B-\xFD]
  NonMChar	[\x09\x0A\x0D\x20A-LN-Za-ln-z\x7B-\xFD]
  NonLChar	[\x09\x0A\x0D\x20A-KM-Za-km-z\x7B-\xFD]
  
  PITarget	(({NonXChar}{Char}*)|((X|x){NonMChar}{Char}*)|((X|x)(M|m){NonLChar}*)|({Char}{Char}{Char}{Char}+)) 
  */
  
PITargetStart     [_:A-\xFF]
PITargetName      [.-_:0-9A-\xFF]
PITarget          {PITargetStart}{PITargetName}*

NonQuestionMarkChar                 [\x09\x0A\x0D\x20-\x3E\x40-\xFD]
NonGreaterThanNonQuestionMarkChar   [\x09\x0A\x0D\x20-\x3D\x40-\xFD]

PIChars           ({NonQuestionMarkChar}*|"?"+{NonGreaterThanNonQuestionMarkChar})*"?"*


ValidationMode				("strict"|"lax"|"skip")


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
typedef yy::xquery_parser::token token;
%}



	/*______________________________________________________________________
	 |
	 |  INITIAL State
	 |
	 |  This state is for patterns that occur at the beginning	of an
	 |  expression or subexpression.
	 |______________________________________________________________________*/

	/* maintain INITIAL */
	/* ---------------- */
"validate"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::VALIDATE_LBRACE;
}

"validate"{SP}{ValidationMode} {
	yylval->sval = driver.symtab.put(yytext+9, yyleng-9);
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::VALIDATE_MODE;
}

"typeswitch"{S}"(" {
	return token::TYPESWITCH_LPAR;
}

"element"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::ELEMENT_LBRACE;
}

"attribute"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::ATTRIBUTE_LBRACE;
}

"attribute"{SP}{QName}{S}"{" {
	yylval->sval = driver.symtab.put_qname(yytext+10, yyleng-11, true, true);
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::ATTRIBUTE_QNAME_LBRACE;
}

"element"{SP}{QName}{S}"{" {
	yylval->sval = driver.symtab.put_qname(yytext+8, yyleng-9, true, true);
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::ELEMENT_QNAME_LBRACE;
}

"document"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::DOCUMENT_LBRACE;
}

"text"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::TEXT_LBRACE;
}

"processing-instruction"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::PI_LBRACE;
}

"processing-instruction"{SP}NCName{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::PI_NCNAME_LBRACE;
}

"comment"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::COMMENT_LBRACE;
}

"declare"{SP}"function" {
	return token::DECLARE_FUNCTION;
}

"declare"{SP}"updating"{SP}"function" {
	return token::DECLARE_UPDATING_FUNCTION;
}

"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

"ordered"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::ORDERED_LBRACE;
}

"unordered"{S}"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::UNORDERED_LBRACE;
}

";" {
	return token::SEMI;
}
"," {
	return token::COMMA;
}
"(" {
  return token::LPAR;
}
"if"{S}"(" {
	return token::IF_LPAR;
}


	/* transition to KINDTEST */
	/* ---------------------- */
"element"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::ELEMENT_LPAR;
}

"attribute"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::COMMENT_LPAR;
}

"text"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::TEXT_LPAR;
}

"node"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::NODE_LPAR;
}

"document-node"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::DOCUMENT_NODE_LPAR;
}


	/* transition to KINDTESTFORPI */
	/* --------------------------- */
"processing-instruction"{S}"(" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_KINDTESTFORPI, yyscanner);
	return token::PI_LPAR;
}



	/* order dependence: this must follow the rules: xxx{S}"(" */
{QName}{S}"(" {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng-1, false, true);
	return token::QNAME_LPAR;
}


"-" {
	return token::MINUS;
}
"+" {
	return token::PLUS;
}
"/" {
	return token::SLASH;
}
"/ " {
	return token::LEADING_LONE_SLASH;
}
"//" {
	return token::SLASH_SLASH;
}
"ancestor-or-self::" {
	return token::ANCESTOR_OR_SELF_AXIS;
}
"ancestor::" {
	return token::ANCESTOR_AXIS;
}
"attribute::" {
	return token::ATTRIBUTE_AXIS;
}
"child::" {
	return token::CHILD_AXIS;
}
"descendant-or-self::" {
	return token::DESCENDANT_OR_SELF_AXIS;
}
"descendant::" {
	return token::DESCENDANT_AXIS;
}
"following-sibling::" {
	return token::FOLLOWING_SIBLING_AXIS;
}
"following::" {
	return token::FOLLOWING_AXIS;
}
"parent::" {
	return token::PARENT_AXIS;
}
"preceding-sibling::" {
	return token::PRECEDING_SIBLING_AXIS;
}
"preceding::" {
	return token::PRECEDING_AXIS;
}
"self::" {
	return token::SELF_AXIS;
}
"@" {
	return token::AT_SIGN;
}


	/* transition to OPERATOR */
	/* ---------------------- */
{IntegerLiteral}	{
	yylval->ival = driver.symtab.intval(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::INTEGER_LITERAL;
}

{DecimalLiteral}	{
	yylval->decval = driver.symtab.decimalval(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::DECIMAL_LITERAL;
}

{DoubleLiteral}		{
	yylval->dval = driver.symtab.doubleval(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::DOUBLE_LITERAL;
}

"NaN" {
	BEGIN MODE_OPERATOR;
	return token::_NAN;
}

{NCName}":*" {
	yylval->sval = driver.symtab.put_ncname(yytext, yyleng-2);
	BEGIN MODE_OPERATOR;
	return token::ELEM_WILDCARD;
}

{QName} {
	yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::QNAME;
}

")" {
	BEGIN MODE_OPERATOR;
	return token::RPAR;
}

"*:"{NCName} {
	yylval->sval = driver.symtab.put_ncname(yytext+2, yyleng-2);
	BEGIN MODE_OPERATOR;
	return token::PREFIX_WILDCARD;
}

"*" {
	BEGIN MODE_OPERATOR;
	return token::STAR;
}

{StringLiteral} {
	yylval->sval = driver.symtab.put_stringlit(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::STRING_LITERAL;
}

"declare"{SP}"construction" {
	BEGIN MODE_OPERATOR;
	return token::DECLARE_CONSTRUCTION;
}

"declare"{SP}"default"{SP}"order" {
	BEGIN MODE_OPERATOR;
	return token::DECLARE_DEFAULT_ORDER;
}

".." {
	BEGIN MODE_OPERATOR;
	return token::DOT_DOT;
}

"." {
	BEGIN MODE_OPERATOR;
	return token::DOT;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"declare"{SP}"default"{SP}"collation" {
	BEGIN MODE_NAMESPACEDECL;
	return token::DECLARE_DEFAULT_COLLATION;
}

"declare"{SP}"namespace" {
	BEGIN MODE_NAMESPACEDECL;
	return token::DECLARE_NAMESPACE;
}

"module"{SP}"namespace" {
	BEGIN MODE_NAMESPACEDECL;
	return token::MODULE_NAMESPACE;
}

"declare"{SP}"base-uri" {
	BEGIN MODE_NAMESPACEDECL;
	return token::DECLARE_BASE_URI;
}


	/* transition to NAMESPACEKEYWORD */
	/* ------------------------------ */
"declare"{SP}"default"{SP}"element" {
	BEGIN MODE_NAMESPACEKEYWORD;
	return token::DECLARE_DEFAULT_ELEMENT;
}

"declare"{SP}"default"{SP}"function" {
	BEGIN MODE_NAMESPACEKEYWORD;
	return token::DECLARE_DEFAULT_FUNCTION;
}

"import"{SP}"schema" {
	BEGIN MODE_NAMESPACEKEYWORD;
	return token::IMPORT_SCHEMA;
}

"import"{SP}"module" {
	BEGIN MODE_NAMESPACEKEYWORD;
	return token::IMPORT_MODULE;
}

"declare"{SP}"copy-namespaces" {
	BEGIN MODE_NAMESPACEKEYWORD;
	return token::DECLARE_COPY_NAMESPACES;
}


	/* transition to VARNAME */
	/* --------------------- */
"$" {
	BEGIN MODE_VARNAME;
	return token::DOLLAR;
}

"for"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::FOR_DOLLAR;
}

"let"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::LET_DOLLAR;
}

"some"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::SOME_DOLLAR;
}

"every"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::EVERY_DOLLAR;
}

"declare"{SP}"variable"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::DECLARE_VARIABLE_DOLLAR;
}

	/* update rule */
"transform"{SP}"copy"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::TRANSFORM_COPY_DOLLAR;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
")"{SP}"as"  {
	BEGIN MODE_ITEMTYPE;
	return token::RPAR_AS;
}	


	/* transition to XML_COMMENT */
	/* ------------------------- */
"<!--" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_XML_COMMENT, yyscanner);
	return token::XML_COMMENT_BEGIN;
}


	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
"<?" {	
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_PROCESSING_INSTRUCTION, yyscanner);
	return token::PI_BEGIN;
}


	/* transition to CDATA_SECTION */
	/* --------------------------- */
"<![CDATA[" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_CDATA_SECTION, yyscanner);
	return token::CDATA_BEGIN;
}


	/* transition to START_TAG */
	/* ----------------------- */
"<" { 	
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ MODE_START_TAG, yyscanner);
	return token::START_TAG;
}


	/* transition to XMLSPACE_DECL */
	/* --------------------------- */
"declare"{SP}"boundary-space" {
	BEGIN MODE_XMLSPACE_DECL;
	return token::DECLARE_BOUNDARY_SPACE;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}


	/* transition to DECLAREORDERING */
	/* ----------------------------- */
"declare"{SP}"ordering" {
	BEGIN MODE_DECLAREORDERING;
	return token::DECLARE_ORDERING;
}


	/* transition to XQUERY_VERSION */
	/* ---------------------------- */
"xquery"{SP}"version" {
	BEGIN MODE_XQUERY_VERSION;
	return token::XQUERY_VERSION;
}


	/* transition to PRAGMA */
	/* -------------------- */
"(#" { 	
	BEGIN MODE_PRAGMA;
	return token::PRAGMA_BEGIN;
}


	/* transition to OPTION */
	/* -------------------- */
"declare"{SP}"option" {
	BEGIN MODE_OPTION;
	return token::DECLARE_OPTION;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"at"{SP}{URILiteral} {
	yylval->sval = driver.symtab.put_uri(yytext+3, yyleng-3, true);
	BEGIN MODE_NAMESPACEDECL;
	return token::AT_URI_LITERAL;
}


	/* pop previous state */
	/* ------------------ */
"}" { 	
	yy_pop_state(yyscanner);
	return token::RBRACE;
}


	/*______________________________________________________________________  
	 |
	 | Update rules <INITIAL>
	 |______________________________________________________________________*/

"declare"{S}"revalidation"{ValidationMode} {
	return token::DECLARE_REVALIDATION_MODE;
}
"do"{SP}"insert" {
	return token::DO_INSERT;
}
"do"{SP}"delete"  {
	return token::DO_DELETE;
}
"do"{SP}"replace" {
	return token::DO_REPLACE;
}
"do"{SP}"rename" {
	driver.set_rename(true);
	return token::DO_RENAME;
}
"into" {
	return token::INTO;
}
"first"{SP}"into" {
	return token::FIRST_INTO;
}
"last"{SP}"into" {
	return token::LAST_INTO;
}
"after" {
	return token::AFTER;
}
"before" {
	return token::BEFORE;
}
"value"{SP}"of" {
	return token::VALUE_OF;
}
"with"  {
	return token::WITH;
}
"as" {
	return token::AS;
}
"modify" {
	return token::MODIFY;
}


	/*______________________________________________________________________  
	 |
	 | FT rules <INITIAL>
	 |______________________________________________________________________*/

"&&" {
	return token::FTAND;
}
"!" {
	return token::FTNOT;
}
"||" {
	return token::FTOR;
}
"not"<SP>"in" {
	return token::FTNOT_IN;
}
"all" {
	return token::ALL;
}
"all"{SP}"words" {
	return token::ALL_WORDS;
}
"any" {
	return token::ANY;
}
"any"{SP}"word" {
	return token::ANY_WORD;
}
"at"{SP}"end" {
	return token::AT_END;
}
"at"{SP}"least" {
	return token::AT_LEAST;
}
"at"{SP}"most" {
	return token::AT_MOST;
}
"at"{SP}"start" {
	return token::AT_START;
}
"case"{SP}"insensitive" {
	return token::CASE_INSENSITIVE;
}
"case"{SP}"sensitive" {
	return token::CASE_SENSITIVE;
}
"declare"{SP}"ftoption" {
	return token::DECLARE_FTOPTION;
}
"diacritics"{SP}"insensitive" {
	return token::DIACRITICS_INSENSITIVE;
}
"diacritic"{SP}"sensitive" {
	return token::DIACRITICS_SENSITIVE;
}
"different" {
	return token::DIFFERENT;
}
"distance" {
	return token::DISTANCE;
}
"entire"{SP}"content" {
	return token::ENTIRE_CONTENT;
}
"exactly" {
	return token::EXACTLY;
}
"from" {
	return token::FROM;
}
"language" {
	return token::LANGUAGE;
}
"levels" {
	return token::LEVELS;
}
"lowercase" {
	return token::LOWERCASE;
}
"occurs" {
	return token::OCCURS;
}
"paragraph" {
	return token::PARAGRAPH;
}
"phrase" {
	return token::PHRASE;
}
"relationship" {
	return token::RELATIONSHIP;
}
"same" {
	return token::SAME;
}
"score" {
	return token::SCORE;
}
"sentence" {
	return token::SENTENCE;
}
"sentences" {
	return token::SENTENCES;
}
"times" {
	return token::TIMES;
}
"uppercase" {
	return token::UPPERCASE;
}
"weight" {
	return token::WEIGHT;
}
"window" {
	return token::WINDOW;
}
"without"{SP}"content" {
	return token::WITHOUT_CONTENT;
}
"without"{SP}"diacritics" {
	return token::WITHOUT_DIACRITICS;
}
"without"{SP}"stemming" {
	return token::WITHOUT_STEMMING;
}
"without"{SP}"stop"{SP}"words" {
	return token::WITHOUT_STOP_WORDS;
}
"without"{SP}"thesaurus" {
	return token::WITHOUT_THESAURUS;
}
"without"{SP}"wildcards" {
	return token::WITHOUT_WILDCARDS;
}
"with"{SP}"default"{SP}"stop"{SP}"words" {
	return token::WITH_DEFAULT_STOP_WORDS;
}
"with"{SP}"diacritics" {
	return token::WITH_DIACRITICS;
}
"with"{SP}"stemming" {
	return token::WITH_STEMMING;
}
"with"{SP}"stop"{SP}"words" {
	return token::WITH_STOP_WORDS;
}
"with"{SP}"thesaurus" {
	return token::WITH_THESAURUS;
}
"with"{SP}"wildcards" {
	return token::WITH_WILDCARDS;
}
"words" {
	return token::WORDS;
}


  /* catch all */
{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}




	/*______________________________________________________________________  
	 |
	 |	The DECLAREORDERING State
	 |
	 |	Special state to recognize declare ordering specific keywords. 
	 |	transition to INITIAL
	 |______________________________________________________________________*/

<MODE_DECLAREORDERING>{

	/* transition to INITIAL */
	/* --------------------- */
"ordered" {
	BEGIN INITIAL;
	return token::ORDERED;
}

"unordered" {
	BEGIN INITIAL;
	return token::UNORDERED;
}

} /* <MODE_DECLAREORDERING> */




	/*______________________________________________________________________  
	 |
	 |	OPERATOR State 
	 | 
	 |  This state is for patterns that are defined for operators.
	 |______________________________________________________________________*/

<MODE_OPERATOR>{

	/* transition to INITIAL */
	/* --------------------- */
"{" {
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}
";" {
	BEGIN INITIAL;
	return token::SEMI;
}
"then" {
	BEGIN INITIAL;
	return token::THEN;
}
"else" {
	BEGIN INITIAL;
	return token::ELSE;
}
"external" {
	BEGIN INITIAL;
	return token::EXTERNAL;
}
"and" {
	BEGIN INITIAL;
	return token::AND;
}
"at" {
	if (!driver.ftcontains()) {
		BEGIN INITIAL;
	}
	return token::AT;
}


	/* full-text rule */
"score" {
	BEGIN INITIAL;
	return token::SCORE;
}


":=" {
	BEGIN INITIAL;
	return token::GETS;
}
"," {
	BEGIN INITIAL;
	return token::COMMA;
}
"div" {
	BEGIN INITIAL;
	return token::DIV;
}
"=" {
	BEGIN INITIAL;
	return token::EQUALS;
}
"except" {
	BEGIN INITIAL;
	return token::EXCEPT;
}
"eq" {
	BEGIN INITIAL;
	return token::VAL_EQ;
}
"ge" {
	BEGIN INITIAL;
	return token::VAL_GE;
}
"gt" {
	BEGIN INITIAL;
	return token::VAL_GT;
}
"le" {
	BEGIN INITIAL;
	return token::VAL_LE;
}
"lt" {
	BEGIN INITIAL;
	return token::VAL_LT;
}
"ne" {
	BEGIN INITIAL;
	return token::VAL_NE;
}
">=" {
	BEGIN INITIAL;
	return token::GE;
}
">>" {
	BEGIN INITIAL;
	return token::FOLLOWS;
}
">" {
	BEGIN INITIAL;
	return token::GT;
}
"idiv" {
	BEGIN INITIAL;
	return token::IDIV;
}
"intersect" {
	BEGIN INITIAL;
	return token::INTERSECT;
}



	/* Update rules */
"into" {
	BEGIN INITIAL;
	return token::INTO;
}
"with" {
	BEGIN INITIAL;
	return token::WITH;
}
"do"{SP}"insert" {
	BEGIN INITIAL;
	return token::DO_INSERT;
}
"do"{SP}"delete"  {
	BEGIN INITIAL;
	return token::DO_DELETE;
}
"do"{SP}"replace" {
	BEGIN INITIAL;
	return token::DO_REPLACE;
}
"do"{SP}"rename" {
	BEGIN INITIAL;
	driver.set_rename(true);
	return token::DO_RENAME;
}
"into" {
	BEGIN INITIAL;
	return token::INTO;
}
"first"{SP}"into" {
	BEGIN INITIAL;
	return token::FIRST_INTO;
}
"last"{SP}"into" {
	BEGIN INITIAL;
	return token::LAST_INTO;
}
"after" {
	BEGIN INITIAL;
	return token::AFTER;
}
"before" {
	BEGIN INITIAL;
	return token::BEFORE;
}
"value"{SP}"of" {
	BEGIN INITIAL;
	return token::VALUE_OF;
}
"modify" {
	BEGIN INITIAL;
	return token::MODIFY;
}
"in" {
	BEGIN INITIAL;
	return token::_IN_;
}
"is" {
	BEGIN INITIAL;
	return token::IS;
}
"[" {
	BEGIN INITIAL;
	return token::LBRACK;
}
"<=" {
	BEGIN INITIAL;
	return token::LE;
}
"<<" {
	BEGIN INITIAL;
	return token::PRECEDES;
}
"<" {
	BEGIN INITIAL;
	return token::LT;
}
"-" {
	BEGIN INITIAL;
	return token::MINUS;
}
"mod" {
	BEGIN INITIAL;
	return token::MOD;
}
"*" {
	BEGIN INITIAL;
	return token::STAR;
}
"!=" {
	BEGIN INITIAL;
	return token::NE;
}
"order"{SP}"by" {
	BEGIN INITIAL;
	return token::ORDER_BY;
}
"stable"{SP}"order"{SP}"by" {
	BEGIN INITIAL;
	return token::STABLE_ORDER_BY;
}
"or" {
	BEGIN INITIAL;
	return token::OR;
}
"+" {
	BEGIN INITIAL;
	return token::PLUS;
}
"return" {
	BEGIN INITIAL;
	return token::RETURN;
}
"satisfies" {
	BEGIN INITIAL;
	return token::SATISFIES;
}
"/" {
	BEGIN INITIAL;
	return token::SLASH;
}
"/ " {
	BEGIN INITIAL;
	return token::LEADING_LONE_SLASH;
}
"//" {
	BEGIN INITIAL;
	return token::SLASH_SLASH;
}
"to" {
	BEGIN INITIAL;
	return token::TO;
}
"union" {
	BEGIN INITIAL;
	return token::UNION;
}
"|" {
	BEGIN INITIAL;
	return token::VBAR;
}
"where" {
	BEGIN INITIAL;
	return token::WHERE;
}
"preserve" {
	BEGIN INITIAL;
	return token::PRESERVE;
}
"strip" {
	BEGIN INITIAL;
	return token::STRIP;
}




	/* transition to SINGLETYPE */
	/* ------------------------ */
"castable"{SP}"as" {
	BEGIN MODE_SINGLETYPE;
	return token::CASTABLE_AS;
}
"cast"{SP}"as" {
	BEGIN MODE_SINGLETYPE;
	return token::CAST_AS;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
"instance"{SP}"of" {
	BEGIN MODE_ITEMTYPE;
	return token::INSTANCE_OF;
}
"treat"{SP}"as" {
	BEGIN MODE_ITEMTYPE;
	return token::TREAT_AS;
}
"case" {
	BEGIN MODE_ITEMTYPE;
	return token::CASE;
}
"as" {
	if (driver.rename()) {
		driver.set_rename(false);
		BEGIN INITIAL;
	}
	else if (driver.ftcontains()) {
		driver.set_ftcontains(false);
	}
	else {
		BEGIN MODE_ITEMTYPE;
	}
	return token::AS;
}
")"{S}"as" {
	BEGIN MODE_ITEMTYPE;
	return token::RPAR_AS;
}


	/* transition to VARNAME */
	/* --------------------- */
"$" {
	BEGIN MODE_VARNAME;
	return token::DOLLAR;
}
"for"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::FOR_DOLLAR;
}
"let"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::LET_DOLLAR;
}
"let"{SP}"score"{SP}"$" {
	BEGIN MODE_VARNAME;
	return token::LET_SCORE_DOLLAR;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}


	/* transition to URITOOPERATOR */
	/* --------------------------- */
"collation" {
	BEGIN MODE_URITOOPERATOR;
	return token::COLLATION;
}


	/* restore previous state on closing brace */
	/* --------------------------------------- */
"}" {
	yy_pop_state(yyscanner);
	return token::RBRACE;
}


	/* maintain OPERATOR state */
	/* ----------------------- */
")" {
	return token::RPAR;
}
"?" {
	return token::HOOK;
}
"empty"{SP}"greatest" {
	return token::EMPTY_GREATEST;
}
"empty"{SP}"least" {
	return token::EMPTY_LEAST;
}
"ascending" {
	return token::ASCENDING;
}
"descending" {
	return token::DESCENDING;
}
"default" {
	return token::DEFAULT;
}
"]" {
	return token::RBRACK;
}
{StringLiteral} {
	yylval->sval = driver.symtab.put_stringlit(yytext, yyleng);
	return token::STRING_LITERAL;
}


	/*______________________________________________________________________  
	 |
	 | FT rules <OPERATOR>
	 |______________________________________________________________________*/

	/* transition to INITIAL state */
  /* --------------------------- */
	
"ftcontains" {
	BEGIN INITIAL;
	driver.set_ftcontains(true);
	return token::FTCONTAINS;
}
"&&" {
	BEGIN INITIAL;
	return token::FTAND;
}
"!" {
	BEGIN INITIAL;
	return token::FTNOT;
}
"||" {
	BEGIN INITIAL;
	return token::FTOR;
}
"not"<SP>"in" {
	BEGIN INITIAL;
	return token::FTNOT_IN;
}
"at"{SP}"least" {
  BEGIN INITIAL;
	return token::AT_LEAST;
}
"at"{SP}"most" {
  BEGIN INITIAL;
	return token::AT_MOST;
}
"distance" {
  BEGIN INITIAL;
	return token::DISTANCE;
}
"exactly" {
  BEGIN INITIAL;
	return token::EXACTLY;
}
"from" {
  BEGIN INITIAL;
	return token::FROM;
}
"occurs" {
  BEGIN INITIAL;
	return token::OCCURS;
}
"window" {
  BEGIN INITIAL;
	return token::WINDOW;
}


  /* maintain OPERATOR state */
  /* ----------------------- */
"all" {
	return token::ALL;
}
"all"{SP}"words" {
	return token::ALL_WORDS;
}
"any" {
	return token::ANY;
}
"any"{SP}"word" {
	return token::ANY_WORD;
}
"at"{SP}"end" {
	return token::AT_END;
}
"at"{SP}"start" {
	return token::AT_START;
}
"case"{SP}"insensitive" {
	return token::CASE_INSENSITIVE;
}
"case"{SP}"sensitive" {
	return token::CASE_SENSITIVE;
}
"declare"{SP}"ftoption" {
	return token::DECLARE_FTOPTION;
}
"diacritics"{SP}"insensitive" {
	return token::DIACRITICS_INSENSITIVE;
}
"diacritics"{SP}"sensitive" {
	return token::DIACRITICS_SENSITIVE;
}
"different" {
	return token::DIFFERENT;
}
"entire"{SP}"content" {
	return token::ENTIRE_CONTENT;
}
"language" {
	return token::LANGUAGE;
}
"levels" {
	return token::LEVELS;
}
"lowercase" {
	return token::LOWERCASE;
}
"paragraph" {
	return token::PARAGRAPH;
}
"phrase" {
	return token::PHRASE;
}
"relationship" {
	return token::RELATIONSHIP;
}
"same" {
	return token::SAME;
}
"score" {
	return token::SCORE;
}
"sentence" {
	return token::SENTENCE;
}
"sentences" {
	return token::SENTENCES;
}
"times" {
	return token::TIMES;
}
"uppercase" {
	return token::UPPERCASE;
}
"weight" {
	return token::WEIGHT;
}
"without"{SP}"content" {
	return token::WITHOUT_CONTENT;
}
"without"{SP}"diacritics" {
	return token::WITHOUT_DIACRITICS;
}
"without"{SP}"stemming" {
	return token::WITHOUT_STEMMING;
}
"without"{SP}"stop"{SP}"words" {
	return token::WITHOUT_STOP_WORDS;
}
"without"{SP}"thesaurus" {
	return token::WITHOUT_THESAURUS;
}
"without"{SP}"wildcards" {
	return token::WITHOUT_WILDCARDS;
}
"with"{SP}"default"{SP}"stop"{SP}"words" {
	return token::WITH_DEFAULT_STOP_WORDS;
}
"with"{SP}"diacritics" {
	return token::WITH_DIACRITICS;
}
"with"{SP}"stemming" {
	return token::WITH_STEMMING;
}
"with"{SP}"stop"{SP}"words" {
	return token::WITH_STOP_WORDS;
}
"with"{SP}"thesaurus" {
	return token::WITH_THESAURUS;
}
"with"{SP}"wildcards" {
	return token::WITH_WILDCARDS;
}
"words" {
	return token::WORDS;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_OPERATOR> */




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
	return token::SEMI;
}

	/* maintain XQUERYVERSION */
	/* ---------------------- */
{StringLiteral} {
	yylval->sval = driver.symtab.put_stringlit(yytext, yyleng);
	return token::STRING_LITERAL;
}

"encoding" {
	return token::ENCODING;
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
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

";" {
	BEGIN INITIAL;
	return token::SEMI;
}

	/* maintain NAMESPACEDECL */
	/* ---------------------- */
{URILiteral} {
	yylval->sval = driver.symtab.put_uri(yytext+1, yyleng-2);
	return token::URI_LITERAL;
}

"," {
	return token::COMMA;
}

"at" {
	return token::AT;
}

"=" {
	return token::EQUALS;
}

{NCName} {
	yylval->sval = driver.symtab.put_ncname(yytext, yyleng);
	return token::NCNAME;
}

{CatchAll} {
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

<MODE_URITOOPERATOR>{URILiteral} {
	yylval->sval = driver.symtab.put_uri(yytext+1, yyleng-2);
	BEGIN MODE_OPERATOR;
	return token::URI_LITERAL;
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
	yylval->sval = driver.symtab.put_uri(yytext+1, yyleng-2);
	BEGIN MODE_NAMESPACEDECL;
	return token::URI_LITERAL;
}

"namespace" {
	BEGIN MODE_NAMESPACEDECL;
	return token::NAMESPACE;
}

	/* transition to INITIAL */
	/* --------------------- */
"inherit" {
	BEGIN INITIAL;
	return token::INHERIT;
}

"no-inherit" {
	BEGIN INITIAL;
	return token::NO_INHERIT;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}


	/* maintain NAMESPACEKEYWORD */
	/* ------------------------- */
"default"{SP}"element" {
	return token::DEFAULT_ELEMENT;
}

"preserve" {
	return token::PRESERVE;
}

"no-preserve" {
	return token::NO_PRESERVE;
}

"," {
	return token::COMMA;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_NAMESPACEKEYWORD> */




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
"preserve" {
	BEGIN INITIAL;
	return token::PRESERVE;
}

"strip" {
	BEGIN INITIAL;
	return token::STRIP;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

{CatchAll} {
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
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

{CatchAll} {
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
	return token::DOLLAR;
}

	/* transition to OPERATOR */
	/* ---------------------- */
"void"{S}"("{S}")" {
	BEGIN MODE_OPERATOR;
	return token::VOID_TEST;
}

{QName} {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	/* BEGIN MODE_OPERATOR; */
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	return token::QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

	/* transition to KINDTEST */
	/* ---------------------- */
"element"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::ELEMENT_LPAR;
}

"attribute"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::COMMENT_LPAR;
}

"text"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::TEXT_LPAR;
}

"node"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::NODE_LPAR;
}

"document-node"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::DOCUMENT_NODE_LPAR;
}

	/* transition to KINDTESTFORPI */
	/* --------------------------- */
"processing-instruction"{S}"(" {
	BEGIN MODE_OCCURRENCE_INDICATOR; 
	yy_push_state( /*and goto*/ MODE_KINDTESTFORPI, yyscanner);
	return token::PI_LPAR;
}

	/* transition to OCCURENCE_INDICATOR */
	/* -------------------------------- */
{QName} {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	return token::QNAME;
}

"item"{S}"("{S}")" {	
	BEGIN MODE_OCCURRENCE_INDICATOR;
	return token::ITEM_TEST;
}

	/* transition to PRAGMA */
	/* -------------------- */
"(#" {
	BEGIN MODE_PRAGMA;
	return token::PRAGMA_BEGIN;
}

	/* transition to INITIAL */
	/* --------------------- */
";" {
	BEGIN INITIAL;
	return token::SEMI;
}

"then" {
	BEGIN INITIAL;
	return token::THEN;
}

"else" {
	BEGIN INITIAL;
	return token::ELSE;
}

	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"at"{SP}{URILiteral} {
	yylval->sval = driver.symtab.put_uri(yytext+3, yyleng-3, true);
	BEGIN MODE_NAMESPACEDECL;
	return token::AT_URI_LITERAL;
}

	/* transition to INITIAL */
	/* --------------------- */
"external" {
	BEGIN INITIAL;
	return token::EXTERNAL;
}

"and" {
	BEGIN INITIAL;
	return token::AND;
}

"at" {
	BEGIN INITIAL;
	return token::AT;
}

":=" {
	BEGIN INITIAL;
	return token::GETS;
}

"," {
	BEGIN INITIAL;
	return token::COMMA;
}

"div" {
	BEGIN INITIAL;
	return token::DIV;
}

"=" {
	BEGIN INITIAL;
	return token::EQUALS;
}

"except" {
	BEGIN INITIAL;
	return token::EXCEPT;
}

"eq" {
	BEGIN INITIAL;
	return token::VAL_EQ;
}

"ge" {
	BEGIN INITIAL;
	return token::VAL_GE;
}

"gt" {
	BEGIN INITIAL;
	return token::VAL_GT;
}

"le" {
	BEGIN INITIAL;
	return token::VAL_LE;
}

"lt" {
	BEGIN INITIAL;
	return token::VAL_LT;
}

"ne" {
	BEGIN INITIAL;
	return token::VAL_NE;
}

">=" {
	BEGIN INITIAL;
	return token::GE;
}

">>" {
	BEGIN INITIAL;
	return token::FOLLOWS;
}

">" {
	BEGIN INITIAL;
	return token::GT;
}

"idiv" {
	BEGIN INITIAL;
	return token::IDIV;
}

"intersect" {
	BEGIN INITIAL;
	return token::INTERSECT;
}

"in" {
	BEGIN INITIAL;
	return token::_IN_;
}

"is" {
	BEGIN INITIAL;
	return token::IS;
}

"[" {
	BEGIN INITIAL;
	return token::LBRACK;
}

"(" {
	BEGIN INITIAL;
	return token::LPAR;
}

"<=" {
	BEGIN INITIAL;
	return token::LE;
}

"<<" {
	BEGIN INITIAL;
	return token::PRECEDES;
}

"<" {
	BEGIN INITIAL;
	return token::LT;
}

"-" {
	BEGIN INITIAL;
	return token::MINUS;
}

"mod" {
	BEGIN INITIAL;
	return token::MOD;
}

"!=" {
	BEGIN INITIAL;
	return token::NE;
}

"order"{SP}"by" {
	BEGIN INITIAL;
	return token::ORDER_BY;
}

"stable"{SP}"order"{SP}"by" {
	BEGIN INITIAL;
	return token::STABLE_ORDER_BY;
}

"or" {
	BEGIN INITIAL;
	return token::OR;
}

"return" {
	BEGIN INITIAL;
	return token::RETURN;
}

"satisfies" {
	BEGIN INITIAL;
	return token::SATISFIES;
}

"to" {
	BEGIN INITIAL;
	return token::TO;
}

"union" {
	BEGIN INITIAL;
	return token::UNION;
}

"|" {
	BEGIN INITIAL;
	return token::VBAR;
}

"where" {
	BEGIN INITIAL;
	return token::WHERE;
}

	/* transition to SINGLETYPE */
	/* ------------------------ */
"castable"{SP}"as" {
	BEGIN MODE_SINGLETYPE;
	return token::CASTABLE_AS;
}

"cast"{SP}"as" {
	BEGIN MODE_SINGLETYPE;
	return token::CAST_AS;
}

	/* maintain ITEMTYPE */
	/* ----------------- */
"instance"{SP}"of" {
	return token::INSTANCE_OF;
}

"treat"{SP}"as" {
	return token::TREAT_AS;
}

"case" {
	return token::CASE;
}

"as" {
	return token::AS;
}

")"{S}"as" {
	return token::RPAR_AS;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_ITEMTYPE> */




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
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

	/* transition to CLOSE_KINDTEST */
	/* --------------------------- */
"*" {
	BEGIN MODE_CLOSE_KINDTEST;
	return token::STAR;
}

{QName} {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	BEGIN MODE_CLOSE_KINDTEST;
	return token::QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

	/* pop previous state on close paren */
	/* --------------------------------- */
")" {
	yy_pop_state(yyscanner);
	return token::RPAR;
}

	/* maintain KINDTEST */
	/* ----------------- */
"element"{S}"(" {
	BEGIN MODE_KINDTEST;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::ELEMENT_LPAR;
}

"schema-element"{S}"(" {
	BEGIN MODE_KINDTEST;
	yy_push_state( /*and goto*/ MODE_KINDTEST, yyscanner);
	return token::SCHEMA_ELEMENT_LPAR;
}

	/* catch-all */
	/* --------- */
{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_KINDTEST> */



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
	yy_pop_state(yyscanner);
	return token::RPAR;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */

"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

	/* maintain KINDTESTFORPI */
	/* ---------------------- */
{NCName} {
	yylval->sval = driver.symtab.put_ncname(yytext, yyleng);
	return token::NCNAME;
}

{StringLiteral} {
	yylval->sval = driver.symtab.put_stringlit(yytext, yyleng);
	return token::STRING_LITERAL;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_KINDTESTFORPI> */




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
	yy_pop_state(yyscanner);
	return token::RPAR;
}

	/* transition to KINDTEST */
	/* ---------------------- */
"," {
	BEGIN MODE_KINDTEST;
	return token::COMMA;
}

	/* transition to INITIAL */
	/* --------------------- */
"{" {
	BEGIN MODE_OPERATOR;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

	/* maintain CLOSE_KINDTEST */
	/* ---------------------- */
"?" {
	return token::HOOK;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_CLOSE_KINDTEST> */




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
	return token::OCCURS_HOOK;
}

"*" {
	BEGIN MODE_OPERATOR;
	return token::OCCURS_STAR;
}

"+" {
	BEGIN MODE_OPERATOR;
	return token::OCCURS_PLUS;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
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

}	/* MODE_OCCURRENCE_INDICATOR> */




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
{QName}	 {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	BEGIN INITIAL;
	return token::QNAME;
}

{CatchAll} {
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
{QName} {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	BEGIN MODE_PRAGMACONTENTS;
	return token::QNAME;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
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
"#)" {
	BEGIN MODE_OPERATOR;
	return token::PRAGMA_END;
}

	/* maintain PRAGMACONTENTS */
	/* ----------------------- */
{S} {
	/* continue lexing */
}

{Char}+ {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::PRAGMA_LITERAL;
}

{CatchAll} {
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
	yylval->sval = driver.symtab.put_varname(yytext, yyleng);
	BEGIN MODE_OPERATOR;
	return token::VARNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

{CatchAll} {
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
	return token::TAG_END;
}

	/* transition to QUOT_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
\" {
	BEGIN MODE_QUOTE_ATTRIBUTE_CONTENT;
	return token::QUOTE;
}

	/* transition to APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
\' {
	BEGIN MODE_APOS_ATTRIBUTE_CONTENT;
	return token::APOS;
}

	/* transition to START_TAG */
	/* ----------------------- */
"=" {
	BEGIN MODE_START_TAG;
	return token::EQUALS;
}

	/* pop previous state on exit */
	/* -------------------------- */
"/>" {
	yy_pop_state(yyscanner);
	return token::EMPTY_TAG_END;
}

	/* maintain START_TAG */
	/* ------------------ */
{S} {
	/* continue lexing */
}

{QName} {
  yylval->sval = driver.symtab.put_qname(yytext, yyleng);
	return token::QNAME;
}

{CatchAll} {
  return token::UNRECOGNIZED;
}

{S} {
  /* eat up whitespace */
}

}	/* <MODE_START_TAG> */




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
	return token::START_TAG_END;
}

	/* transition to INITIAL */
	/* --------------------- */
"{" {
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"<!--" {
	yy_push_state( /*and goto*/ MODE_XML_COMMENT, yyscanner);
	return token::XML_COMMENT_BEGIN;
}

	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
"<?" {
	yy_push_state( /*and goto*/ MODE_PROCESSING_INSTRUCTION, yyscanner);
	return token::PI_BEGIN;
}

	/* transition to CDATA_SECTION */
	/* --------------------------- */
"<![CDATA[" {
	yy_push_state( /*and goto*/ MODE_CDATA_SECTION, yyscanner);
	return token::CDATA_BEGIN;
}

	/* transition to START_TAG */
	/* ----------------------- */
"<" {
	yy_push_state( /*and goto*/ MODE_START_TAG, yyscanner);
	return token::START_TAG;
}

	/* maintain ELEMENT_CONTENT */
	/* ------------------------ */
{ElementContentChar}+ {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::ELEMENT_CONTENT;
}

{PredefinedEntityRef} {
	yylval->sval = driver.symtab.put_entityref(yytext, yyleng);
	return token::ENTITY_REF;
}

{CharRef}+ {
	yylval->sval = driver.symtab.put_charref(yytext, yyleng);
	return token::CHAR_REF_LITERAL;
}

"{{" {
	return token::DOUBLE_LBRACE;
}

"}}" {
	return token::DOUBLE_RBRACE;
}

	/* catch all else */
	/* -------------- */
{CatchAll} {
  return token::UNRECOGNIZED;
}

}	/* MODE_ELEMENT_CONTENT> */




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
	yy_pop_state(yyscanner);
	return token::TAG_END;
}

	/* maintain END_TAG */
	/* ---------------- */
{S} {
	/* continue lexing */
}

{QName} {
  yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::QNAME;
}

	/* catch all else */
	/* -------------- */
{CatchAll} {
  return token::UNRECOGNIZED;
}

}	/* <MODE_END_TAG> */




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
	yy_pop_state(yyscanner);
	return token::XML_COMMENT_END;
}

	/* maintain XML_COMMENT */
	/* -------------------- */
{XMLCommentChar}* {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::XML_COMMENT_LITERAL;
}

}	/* <MODE_XML_COMMENT> */




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
	yy_pop_state(yyscanner);
}

	/* maintain EXPR_COMMENT */
	/* --------------------- */
"(:" {
	yy_push_state( /*and goto*/ MODE_EXPR_COMMENT, yyscanner);
}

{CommentContent} {
	/* do nothing */
  // TODO: check if, indeed, nothing needs to be done
}

}	/* <MODE_EXPR_COMMENT> */




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
	yy_pop_state(yyscanner);
	return token::PI_END;
}

	/* maintain PROCESSING_INSTRUCTION */
	/* ------------------------------- */
{PITarget} {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	BEGIN MODE_PROCESSING_INSTRUCTION;
	return token::PI_TARGET_LITERAL;
}

}	/* <MODE_PROCESSING_INSTRUCTION> */




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
"?>" {
	yy_pop_state(yyscanner);
	return token::PI_END;
}

	/* maintain PROCESSING_INSTRUCTION_CONTENT */
	/* --------------------------------------- */
{PIChars} {
	yylval->sval = driver.symtab.put(yytext, yyleng-1);
  yyless(yyleng-1);
	return token::CHAR_LITERAL;
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
	yy_pop_state(yyscanner);
	return token::CDATA_END;
}

	/* maintain CDATA_SECTION */
	/* ---------------------- */
{Char}+ {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::CHAR_LITERAL;
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
	return token::QUOTE;
}

	/* transition to INITIAL */
	/* --------------------- */
"{" {
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

	/* maintain QUOTE_ATTRIBUTE_CONTENT */
	/* -------------------------------- */
{EscapeQuot} {
	return token::ESCAPE_QUOTE;
}

{QuotAttrContentChar}+ {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::QUOTE_ATTR_CONTENT;
}

{PredefinedEntityRef} {
	return token::ENTITY_REF;
}

{CharRef}+ {
	yylval->sval = driver.symtab.put_charref(yytext, yyleng);
	return token::CHAR_REF_LITERAL;
}

"{{" {
	return token::DOUBLE_LBRACE;
}

"}}" {
	return token::DOUBLE_RBRACE;
}

}	/* <MODE_QUOTE_ATTRIBUTE_CONTENT> */




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
	return token::APOS;
}

	/* transition to INITIAL */
	/* --------------------- */
"{" {
	BEGIN MODE_APOS_ATTRIBUTE_CONTENT;
	yy_push_state( /*and goto*/ INITIAL, yyscanner);
	return token::LBRACE;
}

	/* maintain APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------- */
{EscapeApos} {
	return token::ESCAPE_APOS;
}

{AposAttrContentChar}+ {
	yylval->sval = driver.symtab.put(yytext, yyleng);
	return token::APOS_ATTR_CONTENT;
}

{PredefinedEntityRef} {
	return token::ENTITY_REF;
}

{CharRef}+ {
	yylval->sval = driver.symtab.put_charref(yytext, yyleng);
	return token::CHAR_REF_LITERAL;
}

"{{" {
	return token::DOUBLE_LBRACE;
}

"}}" {
	return token::DOUBLE_RBRACE;
}

} /* <MODE_APOS_ATTRIBUTE_CONTENT> */

%%


/*
	Finally, because the scanner related driver's member function depend 
	on the scanner's data, it is simpler to implement them in this file. 
*/
namespace xqp {
  
void xquery_driver::parse_string( const char *query_string)
{  
  yyscan_t scanner;
  yylex_init(&scanner);
  struct yyguts_t * yyg = (struct yyguts_t*)scanner;

  YY_BUFFER_STATE str_buffer = yy_scan_string(query_string, scanner);

  yy_flex_debug = Properties::instance()->traceScanning();
  yy::xquery_parser parser(*this, scanner);
  parser.set_debug_level(Properties::instance()->traceParsing());
  parser.parse();

  yy_delete_buffer(str_buffer, scanner); /* free up memory */
  yylex_destroy(scanner);
}

void xquery_driver::parse(xqp_string const fname)
{    
  yyscan_t scanner;
  yylex_init(&scanner);
  struct yyguts_t * yyg = (struct yyguts_t*)scanner;
  
  filename = fname;
  
  if (!(yyin = fopen(((std::string)fname).c_str (), "r"))) {
    error (std::string("cannot open ") + (std::string)fname);
  }

  yy_flex_debug = Properties::instance()->traceScanning();
  yy::xquery_parser parser(*this, scanner);
  parser.set_debug_level(Properties::instance()->traceParsing());
  parser.parse();
  
  fclose(yyin);  
  yylex_destroy(&scanner);
}

}


std::string start_state(yyscan_t* yyscanner)
{  
  struct yyguts_t * yyg = (struct yyguts_t*)yyscanner;
  
	switch (YY_START) {
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
/*
#define YY_USER_ACTION \
	{ \
		std::cout<<'<'<<start_state()<<"> [["<<yytext<<"]]"<<std::endl; \
		yylloc->columns(yyleng); \
	}
*/





