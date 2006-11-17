/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery.l,v 1.4 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 */

	/*______________________________________________________________________
	 *                                                                      *
	 *	An implementation of the w3c proposal:                              *
	 *                                                                      *
	 *	"Building a Tokenizer for XPath or XQuery,                          *
	 *	 W3C Working Draft 4 April 2005"                                    *
	 *                                                                      *
	 *	[http://www.w3.org/TR/xquery-xpath-parsing/]                        *
	 *                                                                      *
	 *	Extensions including update, search, and XQueryP:                   *
	 *                                                                      *
	 *	[http://www.w3.org/TR/xqupdate/]                                    *
	 *	[http://www.w3.org/TR/xquery-full-text/]                            *
	 *	[http://www.ximep-2006.org/papers/Paper-Chamberlin-Carey.pdf]       *
	 *                                                                      *
	 *______________________________________________________________________*/


%{

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <cstdlib>
#include <errno.h>
#include <limits.h>
#include <iostream>
#include <string>
#include "xquery_driver.h"
#include "xquery_parser.tab.h"
     
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

/*
	The macro YY_USER_ACTION can be defined to provide an action which is 
	always executed prior to the matched rule's action.
*/
#define YY_USER_ACTION if (debug) std::cout<<"[["<<yytext<<"]]"<<std::endl;


%}


	/*______________________________________________________________________
	 *                                                                      *
   *  Scanner options                                                     *
	 *______________________________________________________________________*/

%option c++
%option outfile="xquery_scanner.yy.cpp"
%option case-insensitive
%option nostdinit
%option noyywrap
%option batch
%option debug
%option stack

	/* known expensive option */
%option yylineno


	/*______________________________________________________________________
	 *                                                                      *
   *  Definitions                                                         *
	 *______________________________________________________________________*/

blank 			[ \t]
S						[ \t\r\n\f]*
SP					[ \t\r\n\f]+
Letter			[A-Za-z]
Digit				[0-9]
EscapeApos	\'\'
EscapeQuot	\"\" 

Nmstart			({Letter}|_)
Nmchar			({Letter}|{Digit}|[._-])
NCName			{Nmstart}{Nmchar}*
QName				({NCName}":")?{NCName}
VarName			{QName}

Char									[\x09\x0A\x0D\x20-\xFD]
CharRef               "&#"([0-9]+|x([0-9]|[a-f]|[A-F])+);
PredefinedEntityRef		"&"(lt|gt|amp|quot|apos|nbsp);
DecimalLiteral				(\.[0-9]+)|([0-9]+(\.[0-9]+)?)
DoubleLiteral					((\.[0-9]+)|([0-9]+(\.[0-9]+)?))([eE][+-]?[0-9]+)?
IntegerLiteral				[0-9]+
NumericLiteral				((\.[0-9]+)|([0-9]+(\.[0-9]+)?))([eE][+-]?[0-9]+)?
StringLiteral					(\"((\"\")|[^"])*\")|(\'((\'\')|[^'])*\')
URILiteral						{StringLiteral}

NonHyphenChar					[\x09\x0D\x0A\x20-\x2C\x2E-\xFD]
XMLCommentChar				({NonHyphenChar}*)|(-{NonHyphenChar}*)
ElementContentChar		[\x09\x0A\x0D\x20-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
QuotAttrContentChar 	[\x09\x0A\x0D\x20-\x21\x23-\x25\x27-\x3B\x3D-\x7A\x7C\x7E-\xFD]
AposAttrContentChar 	[\x09\x0A\x0D\x20-\x25\x28-\x3B\x3D-\x7A\x7C\x7E-\xFD]

ValidationMode				("strict"|"lax"|"skip")

NonXChar	[\x09\x0A\x0D\x20A-WY-Za-wy-z\x7B-\xFD]
NonMChar	[\x09\x0A\x0D\x20A-LN-Za-ln-z\x7B-\xFD]
NonLChar	[\x09\x0A\x0D\x20A-KM-Za-km-z\x7B-\xFD]
PITarget	(({NonXChar}{Char}*)|((X|x){NonMChar}{Char}*)|((X|x)(M|m){NonLChar}*)|({Char}{Char}{Char}{Char}+)) 


	/*
		The following paragraph suffices to track locations accurately. Each 
		time yylex is invoked, the begin position is moved onto the end 
		position. Then when a pattern is matched, the end position is advanced 
		of its width. In case it matched ends of lines, the end cursor is 
		adjusted, and each time blanks are matched, the begin cursor is moved 
		onto the end cursor to effectively ignore the blanks preceding tokens. 
		Comments would be treated equally. 
	*/

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}


	/*______________________________________________________________________
	 *                                                                      *
   *  Exclusive start states                                              *
	 *______________________________________________________________________*/

%x APOS_ATTRIBUTE_CONTENT
%x CDATA_SECTION
%x CLOSE_KINDTEST
%x DECLAREORDERING
%x DEFAULT
%x ELEMENT_CONTENT
%x END_TAG
%x EXPR_COMMENT
%x ITEMTYPE
%x KINDTEST
%x KINDTESTFORPI
%x NAMESPACEDECL
%x NAMESPACEKEYWORD
%x OCCURRENCE_INDICATOR
%x OPERATOR
%x OPTION
%x PRAGMA
%x PRAGMACONTENTS
%x PROCESSING_INSTRUCTION
%x PROCESSING_INSTRUCTION_CONTENT 
%x QUOTE_ATTRIBUTE_CONTENT 
%x SINGLETYPE
%x START_TAG
%x URITOOPERATOR
%x VARNAME
%x XMLSPACE_DECL
%x XML_COMMENT
%x XQUERY_VERSION


%%

%{
  yylloc->step ();
  typedef yy::calcxx_parser::token token;
%}

{blank}+   { yylloc->step(); }
[\n]+      { yylloc->lines (yyleng); yylloc->step (); }

%%

	/*______________________________________________________________________
	 *                                                                      *
	 *  DEFAULT State                                                       *
	 *                                                                      *
	 *  This state is for patterns that occur at the beginning	of an				*
	 *  expression or subexpression.																				*
	 *______________________________________________________________________*/

	/* transition to OPERATOR */
	/* ---------------------- */
{DecimalLiteral}	{
	((YYSTYPE*)lvalp)->nval = decimalval(yytext, yyleng);
	BEGIN OPERATOR;
	return DECIMAL_LITERAL;
}

{DoubleLiteral}		{
	((YYSTYPE*)lvalp)->dval = doubleval(yytext, yyleng);
	BEGIN OPERATOR;
	return DOUBLE_LITERAL;
}

{IntegerLiteral}	{
	((YYSTYPE*)lvalp)->ival = intval(yytext, yyleng);
	BEGIN OPERATOR;
	return INTEGER_LITERAL;
}

"NaN" {
	BEGIN OPERATOR;
	return NAN;
}

{NCName}":*" {
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng-2);
	BEGIN OPERATOR;
	return ELEM_WILDCARD;
}

{QName} {
	BEGIN OPERATOR;
	return QNAME;
}

")" {
	BEGIN OPERATOR;
	return RPAR;
}

"*:"{NCName} {
	((YYSTYPE*)lvalp)->sval = ncname(yytext[2], yyleng-2);
	BEGIN OPERATOR;
	return PREFIX_WILDCARD;
}

"*" {
	BEGIN OPERATOR;
	return STAR;
}

{StringLiteral} {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	BEGIN OPERATOR;
	return STRING_LITERAL;
}

"declare"{SP}"construction" {
	BEGIN OPERATOR;
	return DECLARE_CONSTRUCTION;
}

"declare"{SP}"default"{SP}"order" {
	BEGIN OPERATOR;
	return DECLARE_DEFAULT_ORDER;
}

".." {
	BEGIN OPERATOR;
	return DOT_DOT;
}

"." {
	BEGIN OPERATOR;
	return DOT;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"declare"{SP}"default"{SP}"collation" {
	BEGIN NAMESPACEDECL;
	return DECLARE_DEFAULT_COLLATION;
}

"declare"{SP}"namespace" {
	BEGIN NAMESPACEDECL;
	return DECLARE_NAMESPACE;
}

"module"{SP}"namespace" {
	BEGIN NAMESPACEDECL;
	return MODULE_NAMESPACE;
}

"declare"{SP}"base-uri" {
	BEGIN NAMESPACEDECL;
	return DECLARE_BASE_URI;
}


	/* transition to NAMESPACEKEYWORD */
	/* ------------------------------ */
"declare"{SP}"default"{SP}"element" {
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_DEFAULT_ELEMENT;
}

"declare"{SP}"default"{SP}"function" {
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_DEFAULT_FUNCTION;
}

"import"{SP}"schema" {
	BEGIN NAMESPACEKEYWORD;
	return IMPORT_SCHEMA;
}

"import"{SP}"module" {
	BEGIN NAMESPACEKEYWORD;
	return IMPORT_MODULE;
}

"declare"{SP}"copy-namespaces" {
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_COPY_NAMESPACES;
}


	/* transition to VARNAME */
	/* --------------------- */
"$" {
	BEGIN VARNAME;
	return DOLLAR;
}

"for"{SP}"$" {
	BEGIN VARNAME;
	return FOR_DOLLAR;
}

"let"{SP}"$" {
	BEGIN VARNAME;
	return LET_DOLLAR;
}

"some"{SP}"$" {
	BEGIN VARNAME;
	return SOME_DOLLAR;
}

"every"{SP}"$" {
	BEGIN VARNAME;
	return EVERY_DOLLAR;
}

"declare"{SP}"variable"{SP}"$" {
	BEGIN VARNAME;
	return DECLARE_VARIABLE_DOLLAR;
}

	/* update rule */
"transform"{SP}"copy"{SP}"$" {
	begin VARNAME;
	return TRANSFORM_COPY_DOLLAR;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
")"{SP}"as"  {
	BEGIN ITEMTYPE;
	return RPAR_AS;
}	


	/* transition to KINDTEST */
	/* ---------------------- */
"element"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return ELEMENT_LPAR;
}

"attribute"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return COMMENT_LPAR;
}

"text"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return TEXT_LPAR;
}

"node"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return NODE_LPAR;
}

"document-node"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTEST);
	return DOCUMENT_NODE_LPAR;
}


	/* transition to KINDTESTFORPI */
	/* --------------------------- */
"processing-instruction"{S}"(" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */KINDTESTFORPI);
	return PROCESSING_INSTRUCTION;
}


	/* transition to XML_COMMENT */
	/* ------------------------- */
"<!--" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */XML_COMMENT);
	return XML_COMMENT_BEGIN;
}


	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
"<?" {	
	BEGIN OPERATOR;
	yy_push_state(/* and goto */PROCESSING_INSTRUCTION);
	return PI_BEGIN;
}


	/* transition to CDATA_SECTION */
	/* --------------------------- */
"<![CDATA[" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */CDATA_SECTION);
	return CDATA_BEGIN;
}


	/* transition to START_TAG */
	/* ----------------------- */
"<" { 	
	RETURN START_TAG;
	BEGIN OPERATOR;
	yy_push_state(/* and goto */START_TAG);
	RETURN START_TAG;
}


	/* transition to XMLSPACE_DECL */
	/* --------------------------- */
"declare"{SP}"boundary-space" {
	BEGIN XMLSPACE_DECL;
	return DECLARE_BOUNDARY_SPACE;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}


	/* transition to DECLAREORDERING */
	/* ----------------------------- */
"declare"{SP}"ordering" {
	BEGIN DECLAREORDERING;
	return DECLARE_ORDERING;
}


	/* transition to XQUERY_VERSION */
	/* ---------------------------- */
"xquery"{SP}"version" {
	BEGIN XQUERY_VERSION;
	return XQUERY_VERSION:
}


	/* transition to PRAGMA */
	/* -------------------- */
"(#" { 	
	BEGIN PRAGMA;
	return PRAGMA_BEGIN;
}


	/* transition to OPTION */
	/* -------------------- */
"declare"{SP}"option" {
	BEGIN OPTION;
	return DECLARE_OPTION;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"at"{SP}{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	BEGIN NAMESPACEDECL;
	return AT_URI_LITERAL;
}


	/* pop previous state */
	/* ------------------ */
"}" { 	
	pop_state();
	return RBRACE;
}


	/* maintain DEFAULT */
	/* ---------------- */
"validate"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return VALIDATE_LBRACE;
}

"validate"{SP}{ValidationMode} {
	((YYSTYPE*)lvalp)->sval = valmode(yytext[9], yyleng-9);
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return VALIDATE_MODE;
}

"typeswitch"{S}"(" {
	return TYPESWITCH_LPAR;
}

"element"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return ELEMENT_LBRACE;
}

"attribute"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return ATTRIBUTE_LBRACE;
}

"attribute"{SP}{QName}{S}"{" {
	((YYSTYPE*)lvalp)->sval = qname(yytext[10], yyleng-10);
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return ATTRIBUTE_QNAME_LBRACE;
}

"element"{SP}{QName}{S}"{" {
	((YYSTYPE*)lvalp)->sval = qname(yytext[8], yyleng-8);
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return ELEMENT_QNAME_LBRACE;
}

"document"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return DOCUMENT_LBRACE;
}

"text"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return TEXT_LBRACE;
}

"processing-instruction"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return PI_LBRACE;
}

"processing-instruction"{SP}NCName{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return PI_NCNAME_LBRACE;
}

"comment"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return COMMENT_LBRACE;
}

"declare"{SP}"function" {
	return DECLARE_FUNCTION;
}

"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

"ordered"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return ORDERED_LBRACE;
}

"unordered"{S}"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return UNORDERED_LBRACE;
}

";" {
	return SEMI;
}

"," {
	return COMMA;
}

"(" {
	return LPAR;
}

QName{S}"(" {
	return QNAME_LPAR;
}

if"{S}"(" {
	return IF_LPAR;
}

"-" {
	return MINUS;
}

"+" {
	return PLUS;
}

"/" {
	return SLASH;
}

"/ " {
	return LEADING_LONE_SLASH;
}

"//" {
	return SLASH_SLASH;
}

"ancestor-or-self::" {
	return ANCESTOR_OR_SELF;
}

"ancestor::" {
	return ANCESTOR_AXIS;
}

"attribute::" {
	return ATTRIBUTE_AXIS;
}

"child::" {
	return CHILD_AXIS;
}

"descendant-or-self::" {
	return DESCENDANT_OR_SELF_AXIS;
}

"descendant::" {
	return DESCENDANT_AXIS;
}

"following-sibling::" {
	return FOLLOWING_SIBLING_AXIS;
}

"following::" {
	return FOLLOWING_AXIS;
}

"parent::" {
	return PARENT_AXIS;
}

"preceding-sibling::" {
	return PRECEDING_SIBLING_AXIS;
}

"preceding::" {
	return PRECEDING_AXIS;
}

"self::" {
	return SELF_AXIS;
}

"@" {
	return AT_SIGN;
}


	/*______________________________________________________________________  
	 *                                                                      *
	 * Update rules                                                         *
	 *______________________________________________________________________*/

"declare"{S}"revalidation"{ValidationMode} {
	return DECLARE_REVALIDATION_MODE;
}

"do"{SP}"insert" {
	return DO_INSERT_INTO;
}

"do"{SP}"delete"  {
	return DO_DELETE;
}

"do"{SP}"replace" {
	return DO_REPLACE;
}

"do"{SP}"rename" {
	return DO_RENAME;
}

"into" {
	return INTO;
}

"first"{SP}"into" {
	return FIRST_INTO;
}

"last"{SP}"into" {
	return LAST_INTO;
}

"after" {
	return AFTER;
}

"before" {
	return BEFORE;
}

"value"{SP}"of" {
	return VALUE_OF;
}

"with"  {
	return WITH;
}

"as" {
	return AS;
}

"modify" {
	return MODIFY;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * FT rules                                                             * 
	 *______________________________________________________________________*/

"all" {
	return ALL;
}

"all"{SP}"words" {
	return ALL_WORDS;
}

"any" {
	return ANY;
}

"any"{SP}"word" {
	return ANY_WORD;
}

"at"{SP}"end" {
	return AT_END;
}

"at"{SP}"least" {
	return AT_LEAST;
}

"at"{SP}"most" {
	return AT_MOST;
}

"at"{SP}"start" {
	return AT_START;
}

"case"{SP}"insensitive" {
	return CASE_INSENSITIVE;
}

"case"{SP}"sensitive" {
	return CASE_SENSITIVE;
}

"declare"{SP}"ftoption" {
	return DECLARE_FTOPTION;
}

"diacritics"{SP}"insensitive" {
	return DIACRITICS_INSENSITIVE;
}

"diacritic"{SP}"sensitive" {
	return DIACRITICS_SENSITIVE;
}

"different" {
	return DIFFERENT;
}

"distance" {
	return DISTANCE;
}

"entire"{SP}"content" {
	return ENTIRE_CONTENT;
}

"exactly" {
	return EXACTLY;
}

"from" {
	return FROM;
}

"language" {
	return LANGUAGE;
}

"levels" {
	return LEVELS;
}

"lowercase" {
	return LOWERCASE;
}

"occurs" {
	return OCCURS;
}

"paragraph" {
	return PARAGRAPH;
}

"phrase" {
	return PHRASE;
}

"relationship" {
	return RELATIONSHIP;
}
	
"same" {
	return SAME;
}

"score" {
	return SCORE;
}

"sentence" {
	return SENTENCE;
}

"sentences" {
	return SENTENCES;
}

"times" {
	return TIMES;
}

"uppercase" {
	return UPPERCASE;
}

"weight" {
	return WEIGHT;
}

"window" {
	return WINDOW;
}

"without"{SP}"content" {
	return WITHOUT_CONTENT;
}

"without"{SP}"diacritics" {
	return WITHOUT_DIACRITICS;
}

"without"{SP}"stemming" {
	return WITHOUT_STEMMING;
}

"without"{SP}"stop"{SP}"words" {
	return WITHOUT_STOP_WORDS;
}

"without"{SP}"thesaurus" {
	return WITHOUT_THESAURUS;
}

"without"{SP}"wildcards" {
	return WITHOUT_WILDCARDS;
}

"with"{SP}"default"{SP}"stop"{SP}"words" {
	return WITH_DEFAULT_STOP_WORDS;
}

"with"{SP}"diacritics" {
	return WITH_DIACRITICS;
}

"with"{SP}"stemming" {
	return WITH_STEMMING;
}

"with"{SP}"stop"{SP}"words" {
	return WITH_STOP_WORDS;
}

"with"{SP}"thesaurus" {
	return WITH_THESAURUS;
}

"with"{SP}"wildcards" {
	return WITH_WILDCARDS;
}

"words" {
	return WORDS;
}



	/* catch all */
[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 *	The DECLAREORDERING State                                           * 
	 *                                                                      * 
	 *	Special state to recognize declare ordering specific keywords.      * 
	 *	transition to DEFAULT                                               * 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<DECLAREORDERING>"ordered" {
	BEGIN DEFAULT;
	return ORDERED;
}

<DECLAREORDERING>"unordered" {
	BEGIN DEFAULT;
	return UNORDERED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 *	OPERATOR State                                                      * 
	 *                                                                      * 
	 *  This state is for patterns that are defined for operators.          * 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<OPERATOR>"{" {
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

<OPERATOR>";" {
	BEGIN DEFAULT;
	return SEMI;
}

<OPERATOR>"then" {
	BEGIN DEFAULT;
	return THEN;
}

<OPERATOR>"else" {
	BEGIN DEFAULT;
	return ELSE;
}

<OPERATOR>"external" {
	BEGIN DEFAULT;
	return EXTERNAL;
}

<OPERATOR>"and" {
	BEGIN DEFAULT;
	return AND;
}

<OPERATOR>"at" {
	BEGIN DEFAULT;
	return AT;
}

	/* full-text rule */
"score" {
	BEGIN DEFAULT;
	return SCORE;
}


<OPERATOR>":=" {
	BEGIN DEFAULT;
	return GETS;
}

<OPERATOR>"," {
	BEGIN DEFAULT;
	return COMMA;
}

<OPERATOR>"div" {
	BEGIN DEFAULT;
	return DIV;
}

<OPERATOR>"=" {
	BEGIN DEFAULT;
	return EQ;
}

<OPERATOR>"except" {
	BEGIN DEFAULT;
	return EXCEPT;
}

<OPERATOR>"eq" {
	BEGIN DEFAULT;
	return F_EQ;
}

<OPERATOR>"ge" {
	BEGIN DEFAULT;
	return F_GE;
}

<OPERATOR>"gt" {
	BEGIN DEFAULT;
	return F_GT;
}

<OPERATOR>"le" {
	BEGIN DEFAULT;
	return F_LE;
}

<OPERATOR>"lt" {
	BEGIN DEFAULT;
	return F_LT;
}

<OPERATOR>"ne" {
	BEGIN DEFAULT;
	return F_NE;
}

<OPERATOR>">=" {
	BEGIN DEFAULT;
	return GE;
}

<OPERATOR>">>" {
	BEGIN DEFAULT;
	return FOLLOWS;
}

<OPERATOR>">" {
	BEGIN DEFAULT;
	return GT;
}

<OPERATOR>"idiv" {
	BEGIN DEFAULT;
	return IDIV;
}

<OPERATOR>"intersect" {
	BEGIN DEFAULT;
	return INTERSECT;
}

<OPERATOR>"in" {
	BEGIN DEFAULT;
	return IN;
}

<OPERATOR>"is" {
	BEGIN DEFAULT;
	return IS;
}

<OPERATOR>"[" {
	BEGIN DEFAULT;
	return LBRACK;
}

<OPERATOR>"<=" {
	BEGIN DEFAULT;
	return LE;
}

<OPERATOR>"<<" {
	BEGIN DEFAULT;
	return PRECEDES;
}

<OPERATOR>"<" {
	BEGIN DEFAULT;
	return LT;
}

<OPERATOR>"-" {
	BEGIN DEFAULT;
	return MINUS;
}

<OPERATOR>"mod" {
	BEGIN DEFAULT;
	return MOD;
}

<OPERATOR>"*" {
	BEGIN DEFAULT;
	return STAR;
}

<OPERATOR>"!=" {
	BEGIN DEFAULT;
	return NE;
}

<OPERATOR>"order"{SP}"by" {
	BEGIN DEFAULT;
	return ORDER_BY;
}

<OPERATOR>"stable"{SP}"order"{SP}"by" {
	BEGIN DEFAULT;
	return STABLE_ORDER_BY;
}

<OPERATOR>"or" {
	BEGIN DEFAULT;
	return OR;
}

<OPERATOR>"+" {
	BEGIN DEFAULT;
	return PLUS;
}

<OPERATOR>"return" {
	BEGIN DEFAULT;
	return RETURN;
}

<OPERATOR>"satisfies" {
	BEGIN DEFAULT;
	return SATISFIES;
}

<OPERATOR>"/" {
	BEGIN DEFAULT;
	return SLASH;
}

<OPERATOR>"/ " {
	BEGIN DEFAULT;
	return LEADING_LONE_SLASH;
}

<OPERATOR>"//" {
	BEGIN DEFAULT;
	return SLASH_SLASH;
}

<OPERATOR>"to" {
	BEGIN DEFAULT;
	return TO;
}

<OPERATOR>"union" {
	BEGIN DEFAULT;
	return UNION;
}

<OPERATOR>"|" {
	BEGIN DEFAULT;
	return VBAR;
}

<OPERATOR>"where" {
	BEGIN DEFAULT;
	return WHERE;
}

<OPERATOR>"preserve" {
	BEGIN DEFAULT;
	return PRESERVE;
}

<OPERATOR>"strip" {
	BEGIN DEFAULT;
	return STRIP;
}

	/* full-text rules */
<OPERATOR>"ftcontains" {
	begin DEFAULT;
	return FTCONTAINS;
}
<OPERATOR>"&&" {
	begin DEFAULT;
	return FTAND;
}
<OPERATOR>"!" {
	begin DEFAULT;
	return FTNOT;
}
<OPERATOR>"||" {
	begin DEFAULT;
	return FTOR;
}
<OPERATOR>"not"<SP>"in" {
	begin DEFAULT;
	return NOT_IN;
}


	/* transition to SINGLETYPE */
	/* ------------------------ */
<OPERATOR>"castable"{SP}"as" {
	BEGIN SINGLETYPE;
	return CASTABLE_AS;
}

<OPERATOR>"cast"{SP}"as" {
	BEGIN SINGLETYPE;
	return CAST_AS;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
<OPERATOR>"instance"{SP}"of" {
	BEGIN ITEMTYPE;
	return INSTANCE_OF;
}

<OPERATOR>"treat"{SP}"as" {
	BEGIN ITEMTYPE;
	return TREAT_AS;
}

<OPERATOR>"case" {
	BEGIN ITEMTYPE;
	return CASE;
}

<OPERATOR>"as" {
	BEGIN ITEMTYPE;
	return AS;
}

<OPERATOR>")"{S}"as" {
	BEGIN ITEMTYPE;
	return RPAR_AS;
}


	/* transition to VARNAME */
	/* --------------------- */
<OPERATOR>"$" {
	BEGIN VARNAME;
	return DOLLAR;
}

<OPERATOR>"for"{SP}"$" {
	BEGIN VARNAME;
	return FOR_DOLLAR;
}

<OPERATOR>"let"{SP}"$" {
	BEGIN VARNAME;
	return LET_DOLLAR;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<OPERATOR>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}


	/* transition to URITOOPERATOR */
	/* --------------------------- */
<OPERATOR>"collation" {
	BEGIN URITOOPERATOR;
	return COLLATION;
}


	/* restore previous state on closing brace */
	/* --------------------------------------- */
<OPERATOR>"}" {
	pop_state();
	return RBRACE;
}


	/* maintain OPERATOR state */
	/* ----------------------- */
<OPERATOR>")" {
	return RPAR;
}

<OPERATOR>"?" {
	return HOOK;
}

<OPERATOR>"empty"{SP}"greatest" {
	return EMPTY_GREATEST;
}

<OPERATOR>"empty"{SP}"least" {
	return EMPTY_LEAST;
}

<OPERATOR>"ascending" {
	return ASCENDING;
}

<OPERATOR>"descending" {
	return DESCENDING;
}

<OPERATOR>"default" {
	return DEFAULT;
}

<OPERATOR>"]" {
	return RBRACK;
}

<OPERATOR>{StringLiteral} {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return STRING_LITERAL;
}

<OPERATOR>{NotOperatorKeyword} {
	return NOT_OPERATOR_KEYWORD;
}

[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * XQUERY_VERSION State                                                 * 
	 *                                                                      * 
	 * This state is for recognition of XQuery version specific keywords.   * 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<XQUERY_VERSION>";" 	
	begin DEFAULT;
	return SEMI;
}

	/* maintain XQUERYVERSION */
	/* ---------------------- */
<XQUERY_VERSION>{StringLiteral} {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return STRING_LITERAL;
}

<XQUERY_VERSION>"encoding" {
	return ENCODING;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * NAMESPACEDECL State                                                  * 
	 *                                                                      * 
	 * This state occurs inside of a namespace declaration, and is needed		* 
	 * to recognize a NCName that is to be used as the prefix, as opposed 	* 
	 * to allowing a QName to occur. (Otherwise, the difference between			* 
	 * NCName and QName becomes ambiguous.)																	* 
	 *______________________________________________________________________*/

<NAMESPACEDECL>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<NAMESPACEDECL>";" {
	BEGIN DEFAULT;
	return SEMI;
}


	/* maintain NAMESPACEDECL */
	/* ---------------------- */
<NAMESPACEDECL>{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext, yyleng);
	return URI_LITERAL;
}

<NAMESPACEDECL>"," {
	return COMMA;
}

<NAMESPACEDECL>"at"{SP}{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	return AT_URI_LITERAL;
}

<NAMESPACEDECL>"=" {
	return EQ;
}

<NAMESPACEDECL>{NCName} {
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng);
	return NCNAME;
}

<NAMESPACEDECL>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * URITOOPERATOR State                                                  * 
	 *                                                                      * 
	 * This state is to recognize a URILiteral that transitions to the			* 
	 * OPERATOR state.																											* 
	 *______________________________________________________________________*/

<URITOOPERATOR>{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext, yyleng);
	BEGIN OPERATOR;
	return URI_LITERAL;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * NAMESPACEKEYWORD State                                               * 
	 *                                                                      * 
	 * This state occurs at places where the keyword "namespace" is					* 
	 * expected, which would otherwise be ambiguous compared to a QName.		* 
	 * QNames can not occur in this state.																	* 
	 *______________________________________________________________________*/

	/* transition to NAMESPACEDECL */
	/* --------------------------- */
<NAMESPACEKEYWORD>{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext, yyleng);
	BEGIN NAMESPACEDECL;
	return URI_LITERAL;
}

<NAMESPACEKEYWORD>"namespace" {
	BEGIN NAMESPACEDECL;
	return NAMESPACE:
}

	/* transition to DEFAULT */
	/* --------------------- */
<NAMESPACEKEYWORD>"inherit" {
	BEGIN DEFAULT;
	return INHERIT;
}

<NAMESPACEKEYWORD>"no-inherit" {
	BEGIN DEFAULT;
	return NO_INHERIT;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<NAMESPACEKEYWORD>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}


	/* maintain NAMESPACEKEYWORD */
	/* ------------------------- */
<NAMESPACEKEYWORD>"default"{SP}"element" {
	return DEFAULT_ELEMENT;
}

<NAMESPACEKEYWORD>"preserve" {
	return PRESERVE;
}

<NAMESPACEKEYWORD>"no-preserve" {
	return NO_PRESERVE;
}

<NAMESPACEKEYWORD>"," {
	return COMMA;
}

<NAMESPACEKEYWORD>[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * XMLSPACE_DECL State                                                  * 
	 *                                                                      * 
	 * This state occurs at places where the keywords "preserve" and				* 
	 * "strip" is expected to support "declare xmlspace". QNames cannot			* 
	 * occur in this state.																									* 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<XMLSPACE_DECL>"preserve" {
	BEGIN DEFAULT
	return PRESERVE;
}

<XMLSPACE_DECL>"strip" {
	BEGIN DEFAULT;
	return STRIP;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<XMLSPACE_DECL>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<XMLSPACE_DECL>[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * SINGLETYPE State                                                     * 
	 *                                                                      * 
	 * This state distinguishes tokens that can occur only inside the				* 
	 * SingleType production.																								* 
	 *______________________________________________________________________*/

	/* transition to OPERATOR */
	/* ---------------------- */
<SINGLETYPE>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN OPERATOR;
	return QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<SINGLETYPE>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<SINGLETYPE>[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * ITEMTYPE State                                                       * 
	 *                                                                      * 
	 * This state distinguishes tokens that can occur only inside the				* 
	 * ItemType production.																									* 
	 *______________________________________________________________________*/

	/* transition to VARNAME */
	/* --------------------- */
<ITEMTYPE>"$" {
	BEGIN VARNAME;
	return DOLLAR;
}


	/* transition to OPERATOR */
	/* ---------------------- */
<ITEMTYPE>"void"{S}"("{S}")" {
	BEGIN OPERATOR;
	return VOID_TEST;
}

<ITEMTYPE>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN OPERATOR;
	return QNAME;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<ITEMTYPE>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}


	/* transition to KINDTEST */
	/* ---------------------- */
<ITEMTYPE>"element"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return ELEMENT_LPAR;
}

<ITEMTYPE>"attribute"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return ATTRIBUTE_LPAR;
}

<ITEMTYPE>"schema-element"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return SCHEMA_ELEMENT_LPAR;
}

<ITEMTYPE>"schema-attribute"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return SCHEMA_ATTRIBUTE_LPAR;
}

<ITEMTYPE>"comment"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return COMMENT_LPAR;
}

<ITEMTYPE>"text"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return TEXT_LPAR;
}

<ITEMTYPE>"node"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return NODE_LPAR;
}

<ITEMTYPE>"document-node"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTEST);
	return DOCUMENT_NODE_LPAR;
}


	/* transition to KINDTESTFORPI */
	/* --------------------------- */
<ITEMTYPE>"processing-instruction"{S}"(" {
	BEGIN OCCURRENCE_INDICATOR; 
	yy_push_state(/* and goto */KINDTESTFORPI);
	return PI_LPAR;
}


	/* transition to OCCURENCE_INDICATOR */
	/* -------------------------------- */
<ITEMTYPE>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	return QNAME;
}

<ITEMTYPE>"item"{S}"("{S}")" {	
	BEGIN OCCURRENCE_INDICATOR;
	return ITEM_TEST;
}


	/* transition to PRAGMA */
	/* -------------------- */
<ITEMTYPE>"(#" {
	BEGIN PRAGMA;
	return PRAGMA_BEGIN;
}


	/* transition to DEFAULT */
	/* --------------------- */
<ITEMTYPE>";" {
	BEGIN DEFAULT;
	return SEMI;
}

<ITEMTYPE>"then" {
	BEGIN DEFAULT;
	return THEN;
}

<ITEMTYPE>"else" {
	BEGIN DEFAULT;
	return ELSE;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
<ITEMTYPE>"at"{SP}{URILiteral} {
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	BEGIN NAMESPACEDECL;
	return AT_URI_LITERAL;
}


	/* transition to DEFAULT */
	/* --------------------- */
<ITEMTYPE>"external" {
	BEGIN DEFAULT;
	return EXTERNAL;
}

<ITEMTYPE>"and" {
	BEGIN DEFAULT;
	return AND;
}

<ITEMTYPE>"at" {
	BEGIN DEFAULT;
	return AT;
}

<ITEMTYPE>":=" {
	BEGIN DEFAULT;
	return GETS;
}

<ITEMTYPE>"," {
	BEGIN DEFAULT;
	return COMMA;
}

<ITEMTYPE>"div" {
	BEGIN DEFAULT;
	return DIV;
}

<ITEMTYPE>"=" {
	BEGIN DEFAULT;
	return EQ;
}

<ITEMTYPE>"except" {
	BEGIN DEFAULT;
	return EXCEPT;
}

<ITEMTYPE>"eq" {
	BEGIN DEFAULT;
	return F_EQ;
}

<ITEMTYPE>"ge" {
	BEGIN DEFAULT;
	return F_GE;
}

<ITEMTYPE>"gt" {
	BEGIN DEFAULT;
	return F_GT;
}

<ITEMTYPE>"le" {
	BEGIN DEFAULT;
	return F_LE;
}

<ITEMTYPE>"lt" {
	BEGIN DEFAULT;
	return F_LT;
}

<ITEMTYPE>"ne" {
	BEGIN DEFAULT;
	return F_NE;
}

<ITEMTYPE>">=" {
	BEGIN DEFAULT;
	return GE;
}

<ITEMTYPE>">>" {
	BEGIN DEFAULT;
	return FOLLOWS;
}

<ITEMTYPE>">" {
	BEGIN DEFAULT;
	return GT;
}

<ITEMTYPE>"idiv" {
	BEGIN DEFAULT;
	return IDIV;
}

<ITEMTYPE>"intersect" {
	BEGIN DEFAULT;
	return INTERSECT;
}

<ITEMTYPE>"in" {
	BEGIN DEFAULT;
	return IN;
}

<ITEMTYPE>"is" {
	BEGIN DEFAULT;
	return IS;
}

<ITEMTYPE>"[" {
	BEGIN DEFAULT;
	return LBRACK;
}

<ITEMTYPE>"(" {
	BEGIN DEFAULT;
	return LPAR;
}

<ITEMTYPE>"<=" {
	BEGIN DEFAULT;
	return LE;
}

<ITEMTYPE>"<<" {
	BEGIN DEFAULT;
	return PRECEDES;
}

<ITEMTYPE>"<" {
	BEGIN DEFAULT;
	return LT;
}

<ITEMTYPE>"-" {
	BEGIN DEFAULT;
	return MINUS;
}

<ITEMTYPE>"mod" {
	BEGIN DEFAULT;
	return MOD;
}

<ITEMTYPE>"!=" {
	BEGIN DEFAULT;
	return NE;
}

<ITEMTYPE>"order"{SP}"by" {
	BEGIN DEFAULT;
	return ORDER_BY;
}

<ITEMTYPE>"stable"{SP}"order"{SP}"by" {
	BEGIN DEFAULT;
	return STABLE_ORDER_BY;
}

<ITEMTYPE>"or" {
	BEGIN DEFAULT;
	return OR;
}

<ITEMTYPE>"return" {
	BEGIN DEFAULT;
	return RETURN;
}

<ITEMTYPE>"satisfies" {
	BEGIN DEFAULT;
	return SATISFIES;
}

<ITEMTYPE>"to" {
	BEGIN DEFAULT;
	return TO;
}

<ITEMTYPE>"union" {
	BEGIN DEFAULT;
	return UNION;
}

<ITEMTYPE>"|" {
	BEGIN DEFAULT;
	return VBAR;
}

<ITEMTYPE>"where" {
	BEGIN DEFAULT;
	return WHERE;
}


	/* transition to SINGLETYPE */
	/* ------------------------ */
<ITEMTYPE>"castable"{SP}"as" {
	BEGIN SINGLETYPE;
	return CASTABLE_AS;
}

<ITEMTYPE>"cast"{SP}"as" {
	BEGIN SINGLETYPE;
	return CAST_AS;
}


	/* maintain ITEMTYPE */
	/* ----------------- */
<ITEMTYPE>"instance"{SP}"of" {
	return INSTANCE_OF;
}

<ITEMTYPE>"treat"{SP}"as" {
	return TREAT_AS;
}

<ITEMTYPE>"case" {
	return CASE;
}

<ITEMTYPE>"as" {
	return AS;
}

<ITEMTYPE>")"{S}"as" {
	return RPAR_AS;
}

<ITEMTYPE>[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * KINDTEST State                                                       * 
	 *                                                                      * 
	 * This state is for the psuedo-parameters for the KindTest productions	* 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<KINDTEST>"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

	/* transition to CLOSE_KINDTEST */
	/* --------------------------- */
<KINDTEST>"*" {
	BEGIN CLOSE_KINDTEST;
	return STAR;
}

<KINDTEST>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN CLOSE_KINDTEST;
	return QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<KINDTEST>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

	/* pop previous state on close paren */
	/* --------------------------------- */
<KINDTEST>")" {
	pop_state();
	return RPAR;
}

	/* maintain KINDTEST */
	/* ----------------- */
<KINDTEST>"element"{S}"(" {
	BEGIN KINDTEST;
	yy_push_state(/* and goto */KINDTEST);
	return ELEMENT_LPAR;
}

<KINDTEST>"schema-element"{S}"(" {
	BEGIN KINDTEST;
	yy_push_state(/* and goto */KINDTEST);
	return SCHEMA_ELEMENT_LPAR;
}

	/* catch-all */
	/* --------- */
<KINDTEST>[^ \t\r\n] {
  return UNRECOGNIZED;
}

	/*______________________________________________________________________  
	 *                                                                      * 
	 * KINDTESTFORPI                                                        * 
	 *                                                                      * 
	 * This state is similar to KINDTEST, but recognizes NCNames instead of	* 
	 * QNames.																															* 
	 *______________________________________________________________________*/

	/* pop previous state on close paren */
	/* --------------------------------- */
<KINDTESTFORPI>")" {
	pop_state();
	return RPAR;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */

<KINDTESTFORPI>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

	/* maintain KINDTESTFORPI */
	/* ---------------------- */
<KINDTESTFORPI>{NCName} {
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng);
	return NCNAME;
}

<KINDTESTFORPI>{StringLiteral} {
	((YYSTYPE*)lvalp)->sval = stringlit(yytext, yyleng);
	return STRING_LITERAL;
}

<KINDTESTFORPI>[^ \t\r\n] {
  return UNRECOGNIZED;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 * CLOSE_KINDTEST State                                                 * 
	 *                                                                      * 
	 * This state is expecting to close a KINDTEST sequence. 								* 
	 *______________________________________________________________________*/ 

	/* pop previous state */
	/* ------------------ */
<CLOSE_KINDTEST>")" {
	pop_state();
	return RPAR;
}

	/* transition to KINDTEST */
	/* ---------------------- */
<CLOSE_KINDTEST>"," {
	BEGIN KINDTEST;
	return COMMA;
}

	/* transition to DEFAULT */
	/* --------------------- */
<CLOSE_KINDTEST>"{" {
	BEGIN OPERATOR;
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<CLOSE_KINDTEST>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

	/* maintain CLOSE_KINDTEST */
	/* ---------------------- */
<CLOSE_KINDTEST>"?" {
	return HOOK;
}

<CLOSE_KINDTEST>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * OCCURRENCEINDICATOR State                                            * 
	 *                                                                      * 
	 * This special state is needed to distinguish occurrence indicators    * 
	 * that appear in the SequenceType production. For instance, compare    * 
	 * "foo instance of baz*" to "baz*foo". In the first case, the "*" is   * 
	 * interpreted as an occurrence indicator, and in the second case, it   * 
	 * must be interpreted as a multiplication operator. But, when in the   * 
	 * OCCURRENCEINDICATOR state, if anything else other than "?", "*",     * 
	 * "+", those symbols must be interpreted in the OPERATOR state. For    * 
	 * instance, this would occur with the expression "foo instance of baz  * 
	 * and $x", with the operator "and".                                    * 
	 *______________________________________________________________________*/

	/* transition to OPERATOR */
	/* ---------------------- */
<OCCURRENCE_INDICATOR>"?" {
	BEGIN OPERATOR;
	return HOOK;
}

<OCCURRENCE_INDICATOR>"*" {
	BEGIN OPERATOR;
	return STAR;
}

<OCCURRENCE_INDICATOR>"+" {
	BEGIN OPERATOR;
	return PLUS;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<OCCURRENCE_INDICATOR>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

	/* anything else: push back, goto OPERATOR */
	/* --------------------------------------- */
<OCCURRENCE_INDICATOR>[^ \t\r\n] {
	yyless();
	BEGIN OPERATOR;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * OPTION State                                                         * 
	 *                                                                      * 
	 * This state is entered in the prolog for an option declaration, and   * 
	 * recognizes a QName that transits to a DEFAULT state rather than a    * 
	 * OPERATOR state.                                                      * 
	 *______________________________________________________________________*/

	/* transition to DEFAULT */
	/* --------------------- */
<OPTION>{QName}	 {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN DEFAULT;
	return QNAME;
}

<OPTION>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * PRAGMA State                                                         * 
	 *                                                                      * 
	 * This state is entered in a a pragma expression, and recognizes       * 
	 * a QName that transits to a PRAGMACONTENTS state rather than an       * 
	 * OPERATOR state.                                                      * 
	 *______________________________________________________________________*/

	/* transition to PRAGMACONTENTS */
	/* ---------------------------- */
<PRAGMA>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN PRAGMACONTENTS;
	return QNAME;
}

<PRAGMA>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * PRAGMACONTENTS State                                                 * 
	 *                                                                      * 
	 * This state recognizes characters in pragma content and transitions   * 
	 * out of this state when a '#)' pattern is recognized.                 * 
	 *______________________________________________________________________*/

	/* transition to OPERATOR */
	/* ---------------------- */
<PRAGMACONTENTS>"#)" {
	BEGIN OPERATOR;
	return PRAGMA_END;
}

	/* maintain PRAGMACONTENTS */
	/* ----------------------- */
<PRAGMACONTENTS>{S} {
	/* continue lexing */
}

<PRAGMACONTENTS>{Char}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return PRAGMA_LITERAL;
}

<PRAGMACONTENTS>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * VARNAME State                                                        * 
	 *                                                                      * 
	 * This state differentiates variable names from qualified names. This  * 
	 * allows only the pattern of a QName to be recognized when otherwise   * 
	 * ambiguities could occur.                                             * 
	 *______________________________________________________________________*/

	/* transition to OPERATOR */
	/* ---------------------- */
<VARNAME>{VarName} {
	((YYSTYPE*)lvalp)->sval = varname(yytext, yyleng);
	BEGIN OPERATOR;
	return VARNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<VARNAME>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<VARNAME>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * START_TAG State                                                      * 
	 *                                                                      * 
	 * This state allows attributes in the native XML syntax, and marks the * 
	 * beginning of an element construction. Element constructors also push * 
	 * the current state, popping it at the conclusion of an end tag. In    * 
	 * the START_TAG state, the string ">" is recognized as a token which   * 
	 * is associated with the transition to the original state.             * 
	 *______________________________________________________________________*/

	/* transition to ELEMENT_CONTENT */
	/* ----------------------------- */
<START_TAG>">" {
	BEGIN ELEMENT_CONTENT;
	return GT;
}

	/* transition to QUOT_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
<START_TAG>\" {
	QUOT_ATTRIBUTE_CONTENT
	return QUOTE;
}

	/* transition to APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
<START_TAG>\' {
	BEGIN APOS_ATTRIBUTE_CONTENT;
	return APOS;
}

	/* transition to START_TAG */
	/* ----------------------- */
<START_TAG>"=" {
	BEGIN START_TAG;
	return EQ;
}

	/* pop previous state on exit */
	/* -------------------------- */
<START_TAG>"/>" {
	pop_state();
	return SGT;
}

	/* maintain START_TAG */
	/* ------------------ */
<START_TAG>{S} {
	/* continue lexing */
}

<START_TAG>{QName} {
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	return QNAME;
}

<START_TAG>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * ELEMENT_CONTENT State                                                * 
	 *                                                                      * 
	 * This state allows XML-like content, without these characters being   * 
	 * misinterpreted as expressions. The character "{" marks a transition  * 
	 * to the DEFAULT state, i.e. the start of an embedded expression, and  * 
	 * the "}" character pops back to the ELEMENT_CONTENT state. To allow   * 
	 * curly braces to be used as character content, a double left or right * 
	 * curly brace is interpreted as a single curly brace character. The    * 
	 * string "</" is interpreted as the beginning of an end tag, which is  * 
	 * associated with a transition to the END_TAG state.                   * 
	 *______________________________________________________________________*/

	/* transition to END_TAG */
	/* --------------------- */
<ELEMENT_CONTENT>"</" {
	BEGIN END_TAG;
	return START_END_TAG;
}

	/* transition to DEFAULT */
	/* --------------------- */
<ELEMENT_CONTENT>"{" {
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<ELEMENT_CONTENT>"<!--" {
	yy_push_state(/* and goto */XML_COMMENT);
	return XML_COMMENT_BEGIN;
}

	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
<ELEMENT_CONTENT>"<?" {
	yy_push_state(/* and goto */PROCESSING_INSTRUCTION);
	return PI_BEGIN;
}

	/* transition to CDATA_SECTION */
	/* --------------------------- */
<ELEMENT_CONTENT>"<![CDATA[" {
	yy_push_state(/* and goto */CDATA_SECTION);
	return CDATA_BEGIN;
}

	/* transition to START_TAG */
	/* ----------------------- */
<ELEMENT_CONTENT>"<" {
	yy_push_state(/* and goto */START_TAG);
	return START_TAG;
}

	/* maintain ELEMENT_CONTENT */
	/* ------------------------ */
<ELEMENT_CONTENT>{ElementContentChar}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return ELEMENT_CONTENT;
}

<ELEMENT_CONTENT>{PredefinedEntityRef} {
	((YYSTYPE*)lvalp)->sval = entityref(yytext, yyleng);
	return ENTITY_REF;
}

<ELEMENT_CONTENT>{CharRef}+ {
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<ELEMENT_CONTENT>"{{" {
	return DOUBLE_LBRACE;
}

<ELEMENT_CONTENT>"}}" {
	return DOUBLE_RBRACE;
}

	/* catch all else */
	/* -------------- */
<ELEMENT_CONTENT>[^ \t\r\n] {
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * END_TAG State                                                        * 
	 *                                                                      * 
	 * When the end tag is terminated, the state is popped to the state     * 
	 * that was pushed at the start of the corresponding start tag.         * 
	 *______________________________________________________________________*/

	/* pop previous state on exit */
	/* -------------------------- */
<END_TAG>">" {
	pop_state();
	return TAG_END;
}

	/* maintain END_TAG */
	/* ---------------- */
<END_TAG>{S} {
	/* continue lexing */
}

<END_TAG>{QName} {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return QNAME;
}

	/* catch all else */
	/* -------------- */
<END_TAG>[^ \t\r\n] {
  p("<END_TAG>UNRECOGNIZED");
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * XML_COMMENT State                                                    * 
	 * The "<--" token marks the beginning of an XML Comment, and the "-->" * 
	 * token marks the end. This allows no special interpretation of other  * 
	 * characters in this state.                                            * 
	 *______________________________________________________________________*/

	/* pop previous state on exit */
	/* -------------------------- */
<XML_COMMENT>"-->" {
	pop_state();
	return XML_COMMENT_END;
}

	/* maintain XML_COMMENT */
	/* -------------------- */
<XML_COMMENT>{XMLCommentChar}* {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return XML_COMMENT_LIT;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * EXPR_COMMENT State                                                   * 
	 *                                                                      * 
	 * The "(:" token marks the beginning of an expression Comment, and     * 
	 * the ":)" token marks the end. This allows no special interpretation  * 
	 * of other characters in this state.                                   * 
	 *______________________________________________________________________*/

	/* pop previous state */
	/* ------------------ */
<EXPR_COMMENT>":)" {
	pop_state();
	return COMMENT_END;
}

	/* maintain EXPR_COMMENT */
	/* --------------------- */
<EXPR_COMMENT>"(:" {
	yy_push_state(/* and goto */EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<EXPR_COMMENT>{Char}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return EXPR_COMMENT_LITERAL;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * PROCESSING_INSTRUCTION State                                         * 
	 *                                                                      * 
	 * In this state, only patterns that are legal in a processing          * 
	 * instruction name are recognized.                                     * 
	 *______________________________________________________________________*/

	/* transition to PROCESSING_INSTRUCTION_CONTENT */
	/* -------------------------------------------- */
<PROCESSING_INSTRUCTION>{SP} {
	BEGIN PROCESSING_INSTRUCTION_CONTENT; 
	/* continue lexing */
}

	/* pop previous state on exit */
	/* -------------------------- */
<PROCESSING_INSTRUCTION>"?>" {
	pop_state();
	return PI_END;
}

	/* maintain PROCESSING_INSTRUCTION */
	/* ------------------------------- */
<PROCESSING_INSTRUCTION>{PITarget} {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	BEGIN PROCESSING_INSTRUCTION;
	return PI_TARGET;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * PROCESSING_INSTRUCTION_CONTENT State                                 * 
	 *                                                                      * 
	 * In this state, only characters are that are legal in processing			* 
	 * instruction content are recognized.																	* 
	 *______________________________________________________________________*/

	/* pop previous state on exit */
	/* -------------------------- */
<PROCESSING_INSTRUCTION_CONTENT>"?>" {
	pop_state();
	return PI_BEGIN;
}

	/* maintain PROCESSING_INSTRUCTION_CONTENT */
	/* --------------------------------------- */
<PROCESSING_INSTRUCTION_CONTENT>{Char}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return CHAR_LITERAL;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * CDATA_SECTION State                                                  * 
	 *                                                                      * 
	 * In this state, only lexemes that are legal in a CDATA section are    * 
	 * recognized.                                                          * 
	 *______________________________________________________________________*/

	/* pop previous state on exit */
	/* -------------------------- */
<CDATA_SECTION>"]]>" {
	pop_state();
	return CDATA_END;
}

	/* maintain CDATA_SECTION */
	/* ---------------------- */
<CDATA_SECTION>{Char}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return CHAR_LITERAL;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * QUOT_ATTRIBUTE_CONTENT State                                         * 
	 *                                                                      * 
	 * This state allows content legal for attributes. The character "{"    * 
	 * marks a transition to the DEFAULT state, i.e. the start of an        * 
	 * embedded expression, and the "}" character pops back to the original * 
	 * state.  To allow curly braces to be used as character content, a     * 
	 * double left or right curly brace is interpreted as a single curly    * 
	 * brace character. This state is the same as APOS_ATTRIBUTE_CONTENT,   * 
	 * except that apostrophes are allowed without escaping, and an         * 
	 * unescaped quote marks the end of the state.                          * 
	 *______________________________________________________________________*/

	/* transition to START_TAG */
	/* ----------------------- */
<QUOTE_ATTRIBUTE_CONTENT>\" {
	BEGIN START_TAG;
	return QUOTE;
}

	/* transition to DEFAULT */
	/* --------------------- */
<QUOTE_ATTRIBUTE_CONTENT>"{" {
	BEGIN QUOTE_ATTRIBUTE_CONTENT;
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

	/* maintain QUOTE_ATTRIBUTE_CONTENT */
	/* -------------------------------- */
<QUOTE_ATTRIBUTE_CONTENT>{EscapeQuot} {
	return ESCAPE_QUOTE;
}

<QUOTE_ATTRIBUTE_CONTENT>{QuotAttrContentChar}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return QUOTE_ATTR_CONTENT;
}

<QUOTE_ATTRIBUTE_CONTENT>{PredefinedEntityRef} {
	return ENTITY_REF;
}

<QUOTE_ATTRIBUTE_CONTENT>{CharRef}+ {
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<QUOTE_ATTRIBUTE_CONTENT>"{{" {
	return DOUBLE_LBRACE;
}

<QUOTE_ATTRIBUTE_CONTENT>"}}" {
	return DOUBLE_RBRACE;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * APOS_ATTRIBUTE_CONTENT State                                         * 
	 *                                                                      * 
	 * This state is the same as QUOT_ATTRIBUTE_CONTENT, except that        * 
	 * quotes are allowed, and an unescaped apostrophe marks the end of     * 
	 * the state.                                                           * 
	 *______________________________________________________________________*/

	/* transition to START_TAG */
	/* ----------------------- */
<APOS_ATTRIBUTE_CONTENT>\' {
	BEGIN START_TAG;
	return APOS;
}

	/* transition to DEFAULT */
	/* --------------------- */
<APOS_ATTRIBUTE_CONTENT>"{" {
	BEGIN APOS_ATTRIBUTE_CONTENT;
	yy_push_state(/* and goto */DEFAULT);
	return LBRACE;
}

	/* maintain APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------- */
<APOS_ATTRIBUTE_CONTENT>{EscapeApos} {
	return ESCAPE_APOS;
}

<APOS_ATTRIBUTE_CONTENT>{AposAttrContentChar}+ {
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return APOS_ATTR_CONTENT;
}

<APOS_ATTRIBUTE_CONTENT>PredefinedEntityRef {
	return ENTITY_REF;
}

<APOS_ATTRIBUTE_CONTENT>{CharRef}+ {
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<APOS_ATTRIBUTE_CONTENT>"{{" {
	return DOUBLE_LBRACE;
}

<APOS_ATTRIBUTE_CONTENT>"}}" {
	return DOUBLE_RBRACE;
}


%%


/*
	Finally, because the scanner related driver's member function depend 
	on the scanner's data, it is simpler to implement them in this file. 
*/

void xquery_driver::scan_begin()
{
  yy_flex_debug = trace_scanning;
  if (!(yyin = fopen(file.c_str (), "r")))
    error (std::string("cannot open ") + file);
}

void xquery_driver::scan_end()
{
  fclose (yyin);
}



