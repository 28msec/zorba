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
#include "xquery.tab.h"

#define ECHO

void pushState(int);
void popState();

%}


	/*______________________________________________________________________
	 *                                                                      *
   *  Scanner options                                                     *
	 *______________________________________________________________________*/

%option c++
%option outfile="xquery.yy.cpp"
%option case-insensitive
%option nostdinit
%option noyywrap
%option yylineno


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


	/*______________________________________________________________________
	 *                                                                      *
   *  Definitions                                                         *
	 *______________________________________________________________________*/

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
	debug_put("DECIMAL_LITERAL");
	((YYSTYPE*)lvalp)->nval = decimalval(yytext, yyleng);
	BEGIN OPERATOR;
	return DECIMAL_LITERAL;
}

{DoubleLiteral}		{
	debug_put("DOUBLE_LITERAL");
	((YYSTYPE*)lvalp)->dval = doubleval(yytext, yyleng);
	BEGIN OPERATOR;
	return DOUBLE_LITERAL;
}

{IntegerLiteral}	{
	debug_put("INTEGER_LITERAL");
	((YYSTYPE*)lvalp)->ival = intval(yytext, yyleng);
	BEGIN OPERATOR;
	return INTEGER_LITERAL;
}

"NaN" {
	debug_put("NAN");
	BEGIN OPERATOR;
	return NAN;
}

{NCName}":*" {
	debug_put("ELEM_WILDCARD");
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng-2);
	BEGIN OPERATOR;
	return ELEM_WILDCARD;
}

{QName} {
	debug_put("QNAME");
	BEGIN OPERATOR;
	return QNAME;
}

")" {
	debug_put("RPAR");
	BEGIN OPERATOR;
	return RPAR;
}

"*:"{NCName} {
	debug_put("PREFIX_WILDCARD");
	((YYSTYPE*)lvalp)->sval = ncname(yytext[2], yyleng-2);
	BEGIN OPERATOR;
	return PREFIX_WILDCARD;
}

"*" {
	debug_put("STAR");
	BEGIN OPERATOR;
	return STAR;
}

{StringLiteral} {
	debug_put("STRING_LITERAL");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	BEGIN OPERATOR;
	return STRING_LITERAL;
}

"declare"{SP}"construction" {
	debug_put("DECLARE_CONSTRUCTION");
	BEGIN OPERATOR;
	return DECLARE_CONSTRUCTION;
}

"declare"{SP}"default"{SP}"order" {
	debug_put("DECLARE_DEFAULT_ORDER");
	BEGIN OPERATOR;
	return DECLARE_DEFAULT_ORDER;
}

".." {
	debug_put("DOT_DOT");
	BEGIN OPERATOR;
	return DOT_DOT;
}

"." {
	debug_put("DOT");
	BEGIN OPERATOR;
	return DOT;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"declare"{SP}"default"{SP}"collation" {
	debug_put("DECLARE_DEFAULT_COLLATION");
	BEGIN NAMESPACEDECL;
	return DECLARE_DEFAULT_COLLATION;
}

"declare"{SP}"namespace" {
	debug_put("DECLARE_NAMESPACE");
	BEGIN NAMESPACEDECL;
	return DECLARE_NAMESPACE;
}

"module"{SP}"namespace" {
	debug_put("MODULE_NAMESPACE");
	BEGIN NAMESPACEDECL;
	return MODULE_NAMESPACE;
}

"declare"{SP}"base-uri" {
	debug_put("DECLARE_BASE_URI");
	BEGIN NAMESPACEDECL;
	return DECLARE_BASE_URI;
}


	/* transition to NAMESPACEKEYWORD */
	/* ------------------------------ */
"declare"{SP}"default"{SP}"element" {
	debug_put("DECLARE_DEFAULT_ELEMENT");
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_DEFAULT_ELEMENT;
}

"declare"{SP}"default"{SP}"function" {
	debug_put("DECLARE_DEFAULT_FUNCTION");
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_DEFAULT_FUNCTION;
}

"import"{SP}"schema" {
	debug_put("IMPORT_SCHEMA");
	BEGIN NAMESPACEKEYWORD;
	return IMPORT_SCHEMA;
}

"import"{SP}"module" {
	debug_put("IMPORT_MODULE");
	BEGIN NAMESPACEKEYWORD;
	return IMPORT_MODULE;
}

"declare"{SP}"copy-namespaces" {
	debug_put("DECLARE_COPY_NAMESPACES");
	BEGIN NAMESPACEKEYWORD;
	return DECLARE_COPY_NAMESPACES;
}


	/* transition to VARNAME */
	/* --------------------- */
"$" {
	debug_put("DOLLAR");
	BEGIN VARNAME;
	return DOLLAR;
}

"for"{SP}"$" {
	debug_put("FOR_DOLLAR");
	BEGIN VARNAME;
	return FOR_DOLLAR;
}

"let"{SP}"$" {
	debug_put("LET_DOLLAR");
	BEGIN VARNAME;
	return LET_DOLLAR;
}

"some"{SP}"$" {
	debug_put("SOME_DOLLAR");
	BEGIN VARNAME;
	return SOME_DOLLAR;
}

"every"{SP}"$" {
	debug_put("EVERY_DOLLAR");
	BEGIN VARNAME;
	return EVERY_DOLLAR;
}

"declare"{SP}"variable"{SP}"$" {
	debug_put("DECLARE_VARIABLE_DOLLAR");
	BEGIN VARNAME;
	return DECLARE_VARIABLE_DOLLAR;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
")"{SP}"as"  {
	debug_put("RPAR_AS");
	BEGIN ITEMTYPE;
	return RPAR_AS;
}	


	/* transition to KINDTEST */
	/* ---------------------- */
"element"{S}"(" {
	debug_put("ELEMENT_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return ELEMENT_LPAR;
}

"attribute"{S}"(" {
	debug_put("ATTRIBUTE_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return ATTRIBUTE_LPAR;
}

"schema-element"{S}"(" {
	debug_put("SCHEMA_ELEMENT_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return SCHEMA_ELEMENT_LPAR;
}

"schema-attribute"{S}"(" {
	debug_put("SCHEMA_ATTRIBUTE_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return SCHEMA_ATTRIBUTE_LPAR;
}

"comment"{S}"(" {
	debug_put("COMMENT_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return COMMENT_LPAR;
}

"text"{S}"(" {
	debug_put("TEXT_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return TEXT_LPAR;
}

"node"{S}"(" {
	debug_put("NODE_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return NODE_LPAR;
}

"document-node"{S}"(" {
	debug_put("DOCUMENT_NODE_LPAR");
	pushState(OPERATOR);
	BEGIN KINDTEST;
	return DOCUMENT_NODE_LPAR;
}


	/* transition to KINDTESTFORPI */
	/* --------------------------- */
"processing-instruction"{S}"(" {
	debug_put("PROCESSING_INSTRUCTION");
	pushState(OPERATOR);
	BEGIN KINDTESTFORPI;
	return PROCESSING_INSTRUCTION;
}


	/* transition to XML_COMMENT */
	/* ------------------------- */
"<!--" {
	debug_put("XML_COMMENT_BEGIN");
	pushState(OPERATOR);
	BEGIN XML_COMMENT;
	return XML_COMMENT_BEGIN;
}


	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
"<?" {	
	debug_put("PI_BEGIN");
	pushState(OPERATOR)
	BEGIN PROCESSING_INSTRUCTION;
	return PI_BEGIN;
}


	/* transition to CDATA_SECTION */
	/* --------------------------- */
"<![CDATA[" {
	debug_put("CDATA_BEGIN");
	pushState(OPERATOR);
	BEGIN CDATA_SECTION;
	return CDATA_BEGIN;
}


	/* transition to START_TAG */
	/* ----------------------- */
"<" { 	
	RETURN START_TAG;
	pushState(OPERATOR);
	START_TAG;
	RETURN START_TAG;
}


	/* transition to XMLSPACE_DECL */
	/* --------------------------- */
"declare"{SP}"boundary-space" {
	debug_put("DECLARE_BOUNDARY_SPACE");
	BEGIN XMLSPACE_DECL;
	return DECLARE_BOUNDARY_SPACE;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
"(:" {
	debug_put("COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}


	/* transition to DECLAREORDERING */
	/* ----------------------------- */
"declare"{SP}"ordering" {
	debug_put("DECLARE_ORDERING");
	BEGIN DECLAREORDERING;
	return DECLARE_ORDERING;
}


	/* transition to XQUERY_VERSION */
	/* ---------------------------- */
"xquery"{SP}"version" {
	debug_put("XQUERY_VERSION");
	BEGIN XQUERY_VERSION;
	return XQUERY_VERSION:
}


	/* transition to PRAGMA */
	/* -------------------- */
"(#" { 	
	debug_put("PRAGMA_BEGIN");
	BEGIN PRAGMA;
	return PRAGMA_BEGIN;
}


	/* transition to OPTION */
	/* -------------------- */
"declare"{SP}"option" {
	debug_put("DECLARE_OPTION");
	BEGIN OPTION;
	return DECLARE_OPTION;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
"at"{SP}{URILiteral} {
	debug_put("AT_URI_LITERAL");
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	BEGIN NAMESPACEDECL;
	return AT_URI_LITERAL;
}


	/* pop previous state */
	/* ------------------ */
"}" { 	
	debug_put("RBRACE");
	popState();
	return RBRACE;
}


	/* maintain DEFAULT */
	/* ---------------- */
"validate"{S}"{" {
	debug_put("VALIDATE_LBRACE");
	pushState(OPERATOR);
	return VALIDATE_LBRACE;
}

"validate"{SP}{ValidationMode} {
	debug_put("VALIDATE_MODE");
	((YYSTYPE*)lvalp)->sval = valmode(yytext[9], yyleng-9);
	pushState(OPERATOR);
	return VALIDATE_MODE;
}

"typeswitch"{S}"(" {
	debug_put("TYPESWITCH_LPAR");
	return TYPESWITCH_LPAR;
}

"element"{S}"{" {
	debug_put("ELEMENT_LBRACE");
	pushState(OPERATOR);
	return ELEMENT_LBRACE;
}

"attribute"{S}"{" {
	debug_put("ATTRIBUTE_LBRACE");
	pushState(OPERATOR);
	return ATTRIBUTE_LBRACE;
}

"attribute"{SP}{QName}{S}"{" {
	debug_put("ATTRIBUTE_QNAME_LBRACE");
	((YYSTYPE*)lvalp)->sval = qname(yytext[10], yyleng-10);
	pushState(OPERATOR);
	return ATTRIBUTE_QNAME_LBRACE;
}

"element"{SP}{QName}{S}"{" {
	debug_put("ELEMENT_QNAME_LBRACE");
	((YYSTYPE*)lvalp)->sval = qname(yytext[8], yyleng-8);
	pushState(OPERATOR);
	return ELEMENT_QNAME_LBRACE;
}

"document"{S}"{" {
	debug_put("DOCUMENT_LBRACE");
	pushState(OPERATOR);
	return DOCUMENT_LBRACE;
}

"text"{S}"{" {
	debug_put("TEXT_LBRACE");
	pushState(OPERATOR);
	return TEXT_LBRACE;
}

"processing-instruction"{S}"{" {
	debug_put("PI_LBRACE");
	pushState(OPERATOR);
	return PI_LBRACE;
}

"processing-instruction"{SP}NCName{S}"{" {
	debug_put("PI_NCNAME_LBRACE");
	pushState(OPERATOR);
	return PI_NCNAME_LBRACE;
}

"comment"{S}"{" {
	debug_put("COMMENT_LBRACE");
	pushState(OPERATOR);
	return COMMENT_LBRACE;
}

"declare"{SP}"function" {
	debug_put("DECLARE_FUNCTION");
	return DECLARE_FUNCTION;
}

"{" {
	debug_put("LBRACE");
	pushState(OPERATOR)
	return LBRACE;
}

"ordered"{S}"{" {
	debug_put("ORDERED_LBRACE");
	pushState(OPERATOR)
	return ORDERED_LBRACE;
}

"unordered"{S}"{" {
	debug_put("UNORDERED_LBRACE");
	pushState(OPERATOR)
	return UNORDERED_LBRACE;
}

";" {
	debug_put("SEMI");
	return SEMI;
}

"," {
	debug_put("COMMA);
	return COMMA;
}

"(" {
	debug_put("LPAR");
	return LPAR;
}

QName{S}"(" {
	debug_put("QNAME_LPAR");
	return QNAME_LPAR;
}

if"{S}"(" {
	debug_put("IF_LPAR");
	return IF_LPAR;
}

"-" {
	debug_put("MINUS");
	return MINUS;
}

"+" {
	debug_put("PLUS");
	return PLUS;
}

"/" {
	debug_put("SLASH");
	return SLASH;
}

"/ " {
	debug_put("SLASH");
	return LEADING_LONE_SLASH;
}

"//" {
	debug_put("SLASH_SLASH");
	return SLASH_SLASH;
}

"ancestor-or-self::" {
	debug_put("ANCESTOR_OR_SELF");
	return ANCESTOR_OR_SELF;
}

"ancestor::" {
	debug_put("ANCESTOR");
	return ANCESTOR_AXIS;
}

"attribute::" {
	debug_put("ATTRIBUTE");
	return ATTRIBUTE_AXIS;
}

"child::" {
	debug_put("CHILD");
	return CHILD_AXIS;
}

"descendant-or-self::" {
	debug_put("DESCENDANT_OR_SELF");
	return DESCENDANT_OR_SELF_AXIS;
}

"descendant::" {
	debug_put("DESCENDANT");
	return DESCENDANT_AXIS;
}

"following-sibling::" {
	debug_put("FOLLOWING_SIBLING");
	return FOLLOWING_SIBLING_AXIS;
}

"following::" {
	debug_put("FOLLOWING");
	return FOLLOWING_AXIS;
}

"parent::" {
	debug_put("PARENT");
	return PARENT_AXIS;
}

"preceding-sibling::" {
	debug_put("PRECEDING_SIBLING");
	return PRECEDING_SIBLING_AXIS;
}

"preceding::" {
	debug_put("PRECEDING");
	return PRECEDING_AXIS;
}

"self::" {
	debug_put("SELF");
	return SELF_AXIS;
}

"@" {
	debug_put("AT_SIGN");
	return AT_SIGN;
}


	/*______________________________________________________________________  
	 *                                                                      * 
	 *	Update-related token                                                * 
	 *                                                                      * 
	 *______________________________________________________________________*/

"declare"{S}"revalidation"{ValidationMode} {
	debug_put("DECLARE_REVALIDATION");
	return DECLARE_REVALIDATION_MODE;
}


"do"{SP}"insert" {
	debug_put("DO_INSERT_INTO");
	return DO_INSERT_INTO;
}

"do"{SP}"delete"  {
	debug_put("DO_DELETE");
	return DO_DELETE;
}

"do"{SP}"replace" {
	debug_put("DO_REPLACE");
	return DO_REPLACE;
}

"do"{SP}"rename" {
	debug_put("DO_RENAME");
	return DO_RENAME;
}

"into" {
	debug_put("INTO");
	return INTO;
}

"first"{SP}"into" {
	debug_put("FIRST_INTO");
	return FIRST_INTO;
}

"last"{SP}"into" {
	debug_put("LAST_INTO");
	return LAST_INTO;
}

"after" {
	debug_put("AFTER");
	return AFTER;
}

"before" {
	debug_put("BEFORE");
	return BEFORE;
}

"value"{SP}"of" {
	debug_put("VALUE_OF");
	return VALUE_OF;
}

"with"  {
	debug_put("WITH");
	return WITH;
}

"as" {
	debug_put("AS");
	return AS;
}

"transform"{SP}"copy"{SP}"$" {
	debug_put("TRANSFORM_COPY_DOLLAR");
	return TRANSFORM_COPY_DOLLAR;
}

"modify" {
	debug_put("MODIFY");
	return MODIFY;
}


[^ \t\r\n] {
  debug_put("UNRECOGNIZED");
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
	debug_put("<DECLAREORDERING>ORDERED");
	BEGIN DEFAULT;
	return ORDERED;
}

<DECLAREORDERING>"unordered" {
	debug_put("<DECLAREORDERING>UNORDERED");
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
	debug_put("<OPERATOR>LBRACE");
	pushState(OPERATOR);
	BEGIN DEFAULT;
	return LBRACE;
}

<OPERATOR>";" {
	debug_put("<OPERATOR>SEMI");
	BEGIN DEFAULT;
	return SEMI;
}

<OPERATOR>"then" {
	debug_put("<OPERATOR>THEN");
	BEGIN DEFAULT;
	return THEN;
}

<OPERATOR>"else" {
	debug_put("<OPERATOR>ELSE");
	BEGIN DEFAULT;
	return ELSE;
}

<OPERATOR>"external" {
	debug_put("<OPERATOR>EXTERNAL");
	BEGIN DEFAULT;
	return EXTERNAL;
}

<OPERATOR>"and" {
	debug_put("<OPERATOR>AND");
	BEGIN DEFAULT;
	return AND;
}

<OPERATOR>"at" {
	debug_put("<OPERATOR>AT");
	BEGIN DEFAULT;
	return AT;
}

<OPERATOR>":=" {
	debug_put("<OPERATOR>GETS");
	BEGIN DEFAULT;
	return GETS;
}

<OPERATOR>"," {
	debug_put("<OPERATOR>COMMA");
	BEGIN DEFAULT;
	return COMMA;
}

<OPERATOR>"div" {
	debug_put("<OPERATOR>DIV");
	BEGIN DEFAULT;
	return DIV;
}

<OPERATOR>"=" {
	debug_put("<OPERATOR>EQ");
	BEGIN DEFAULT;
	return EQ;
}

<OPERATOR>"except" {
	debug_put("<OPERATOR>EXCEPT");
	BEGIN DEFAULT;
	return EXCEPT;
}

<OPERATOR>"eq" {
	debug_put("<OPERATOR>F_EQ");
	BEGIN DEFAULT;
	return F_EQ;
}

<OPERATOR>"ge" {
	debug_put("<OPERATOR>F_GE");
	BEGIN DEFAULT;
	return F_GE;
}

<OPERATOR>"gt" {
	debug_put("<OPERATOR>F_GT");
	BEGIN DEFAULT;
	return F_GT;
}

<OPERATOR>"le" {
	debug_put("<OPERATOR>F_LE");
	BEGIN DEFAULT;
	return F_LE;
}

<OPERATOR>"lt" {
	debug_put("<OPERATOR>F_LT");
	BEGIN DEFAULT;
	return F_LT;
}

<OPERATOR>"ne" {
	debug_put("<OPERATOR>F_NE");
	BEGIN DEFAULT;
	return F_NE;
}

<OPERATOR>">=" {
	debug_put("<OPERATOR>GE");
	BEGIN DEFAULT;
	return GE;
}

<OPERATOR>">>" {
	debug_put("<OPERATOR>FOLLOWS");
	BEGIN DEFAULT;
	return FOLLOWS;
}

<OPERATOR>">" {
	debug_put("<OPERATOR>GT");
	BEGIN DEFAULT;
	return GT;
}

<OPERATOR>"idiv" {
	debug_put("<OPERATOR>IDIV");
	BEGIN DEFAULT;
	return IDIV;
}

<OPERATOR>"intersect" {
	debug_put("<OPERATOR>INTERSECT");
	BEGIN DEFAULT;
	return INTERSECT;
}

<OPERATOR>"in" {
	debug_put("<OPERATOR>IN");
	BEGIN DEFAULT;
	return IN;
}

<OPERATOR>"is" {
	debug_put("<OPERATOR>IS");
	BEGIN DEFAULT;
	return IS;
}

<OPERATOR>"[" {
	debug_put("<OPERATOR>LBRACK");
	BEGIN DEFAULT;
	return LBRACK;
}

<OPERATOR>"<=" {
	debug_put("<OPERATOR>LE");
	BEGIN DEFAULT;
	return LE;
}

<OPERATOR>"<<" {
	debug_put("<OPERATOR>PRECEDES");
	BEGIN DEFAULT;
	return PRECEDES;
}

<OPERATOR>"<" {
	debug_put("<OPERATOR>LT");
	BEGIN DEFAULT;
	return LT;
}

<OPERATOR>"-" {
	debug_put("<OPERATOR>MINUS");
	BEGIN DEFAULT;
	return MINUS;
}

<OPERATOR>"mod" {
	debug_put("<OPERATOR>MOD");
	BEGIN DEFAULT;
	return MOD;
}

<OPERATOR>"*" {
	debug_put("<OPERATOR>STAR");
	BEGIN DEFAULT;
	return STAR;
}

<OPERATOR>"!=" {
	debug_put("<OPERATOR>NE");
	BEGIN DEFAULT;
	return NE;
}

<OPERATOR>"order"{SP}"by" {
	debug_put("<OPERATOR>ORDER_BY");
	BEGIN DEFAULT;
	return ORDER_BY;
}

<OPERATOR>"stable"{SP}"order"{SP}"by" {
	debug_put("<OPERATOR>STABLE_ORDER_BY");
	BEGIN DEFAULT;
	return STABLE_ORDER_BY;
}

<OPERATOR>"or" {
	debug_put("<OPERATOR>OR");
	BEGIN DEFAULT;
	return OR;
}

<OPERATOR>"+" {
	debug_put("<OPERATOR>PLUS");
	BEGIN DEFAULT;
	return PLUS;
}

<OPERATOR>"return" {
	debug_put("<OPERATOR>RETURN");
	BEGIN DEFAULT;
	return RETURN;
}

<OPERATOR>"satisfies" {
	debug_put("<OPERATOR>SATISFIES");
	BEGIN DEFAULT;
	return SATISFIES;
}

<OPERATOR>"/" {
	debug_put("<OPERATOR>SLASH");
	BEGIN DEFAULT;
	return SLASH;
}

<OPERATOR>"/ " {
	debug_put("<OPERATOR>SLASH");
	BEGIN DEFAULT;
	return LEADING_LONE_SLASH;
}

<OPERATOR>"//" {
	debug_put("<OPERATOR>SLASH_SLASH");
	BEGIN DEFAULT;
	return SLASH_SLASH;
}

<OPERATOR>"to" {
	debug_put("<OPERATOR>TO");
	BEGIN DEFAULT;
	return TO;
}

<OPERATOR>"union" {
	debug_put("<OPERATOR>UNION");
	BEGIN DEFAULT;
	return UNION;
}

<OPERATOR>"|" {
	debug_put("<OPERATOR>VBAR");
	BEGIN DEFAULT;
	return VBAR;
}

<OPERATOR>"where" {
	debug_put("<OPERATOR>WHERE");
	BEGIN DEFAULT;
	return WHERE;
}

<OPERATOR>"preserve" {
	debug_put("<OPERATOR>PRESERVE");
	BEGIN DEFAULT;
	return PRESERVE;
}

<OPERATOR>"strip" {
	debug_put("<OPERATOR>STRIP");
	BEGIN DEFAULT;
	return STRIP;
}


	/* transition to SINGLETYPE */
	/* ------------------------ */
<OPERATOR>"castable"{SP}"as" {
	debug_put("<OPERATOR>CASTABLE_AS");
	BEGIN SINGLETYPE;
	return CASTABLE_AS;
}

<OPERATOR>"cast"{SP}"as" {
	debug_put("<OPERATOR>CAST_AS");
	BEGIN SINGLETYPE;
	return CAST_AS;
}


	/* transition to ITEMTYPE */
	/* ---------------------- */
<OPERATOR>"instance"{SP}"of" {
	debug_put("<OPERATOR>INSTANCE_OF");
	BEGIN ITEMTYPE;
	return INSTANCE_OF;
}

<OPERATOR>"treat"{SP}"as" {
	debug_put("<OPERATOR>TREAT_AS");
	BEGIN ITEMTYPE;
	return TREAT_AS;
}

<OPERATOR>"case" {
	debug_put("<OPERATOR>CASE");
	BEGIN ITEMTYPE;
	return CASE;
}

<OPERATOR>"as" {
	debug_put("<OPERATOR>AS");
	BEGIN ITEMTYPE;
	return AS;
}

<OPERATOR>")"{S}"as" {
	debug_put("<OPERATOR>RPAR_AS");
	BEGIN ITEMTYPE;
	return RPAR_AS;
}


	/* transition to VARNAME */
	/* --------------------- */
<OPERATOR>"$" {
	debug_put("<OPERATOR>DOLLAR");
	BEGIN VARNAME;
	return DOLLAR;
}

<OPERATOR>"for"{SP}"$" {
	debug_put("<OPERATOR>FOR_DOLLAR");
	BEGIN VARNAME;
	return FOR_DOLLAR;
}

<OPERATOR>"let"{SP}"$" {
	debug_put("<OPERATOR>LET_DOLLAR");
	BEGIN VARNAME;
	return LET_DOLLAR;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<OPERATOR>"(:" {
	debug_put("<OPERATOR>COMMENT_BEGIN");
	pushState(OPERATOR);
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}


	/* transition to URITOOPERATOR */
	/* --------------------------- */
<OPERATOR>"collation" {
	debug_put("<OPERATOR>COLLATION");
	BEGIN URITOOPERATOR;
	return COLLATION;
}


	/* restore previous state on closing brace */
	/* --------------------------------------- */
<OPERATOR>"}" {
	debug_put("<OPERATOR>RBRACE");
	popState();
	return RBRACE;
}


	/* maintain OPERATOR state */
	/* ----------------------- */
<OPERATOR>")" {
	debug_put("<OPERATOR>RPAR");
	return RPAR;
}

<OPERATOR>"?" {
	debug_put("<OPERATOR>HOOK");
	return HOOK;
}

<OPERATOR>"empty"{SP}"greatest" {
	debug_put("<OPERATOR>EMPTY_GREATEST");
	return EMPTY_GREATEST;
}

<OPERATOR>"empty"{SP}"least" {
	debug_put("<OPERATOR>EMPTY_LEAST");
	return EMPTY_LEAST;
}

<OPERATOR>"ascending" {
	debug_put("<OPERATOR>ASCENDING");
	return ASCENDING;
}

<OPERATOR>"descending" {
	debug_put("<OPERATOR>DESCENDING");
	return DESCENDING;
}

<OPERATOR>"default" {
	debug_put("<OPERATOR>DEFAULT");
	return DEFAULT;
}

<OPERATOR>"]" {
	debug_put("<OPERATOR>RBRACK");
	return RBRACK;
}

<OPERATOR>{StringLiteral} {
	debug_put("<OPERATOR>STRING_LITERAL");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return STRING_LITERAL;
}

<OPERATOR>{NotOperatorKeyword} {
	debug_put("<OPERATOR>NOT_OPERATOR_KEYWORD");
	return NOT_OPERATOR_KEYWORD;
}

[^ \t\r\n] {
  debug_put("<OPERATOR>UNRECOGNIZED");
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
	debug_put("<XQUERYVERSION>SEMI");
	begin DEFAULT;
	return SEMI;
}

	/* maintain XQUERYVERSION */
	/* ---------------------- */
<XQUERY_VERSION>{StringLiteral} {
	debug_put("<XQUERYVERSION>STRING_LITERAL");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return STRING_LITERAL;
}

<XQUERY_VERSION>"encoding" {
	debug_put("<XQUERYVERSION>ENCODING");
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
	debug_put("<NAMESPACEDECL>COMMENT_BEGIN");
	pushState(NAMESPACEDECL);
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

<NAMESPACEDECL>";" {
	debug_put("<NAMESPACEDECL>SEMI");
	BEGIN DEFAULT;
	return SEMI;
}


	/* maintain NAMESPACEDECL */
	/* ---------------------- */
<NAMESPACEDECL>{URILiteral} {
	debug_put("<NAMESPACEDECL>URI_LITERAL");
	((YYSTYPE*)lvalp)->sval = urilit(yytext, yyleng);
	return URI_LITERAL;
}

<NAMESPACEDECL>"," {
	debug_put("<NAMESPACEDECL>COMMA");
	return COMMA;
}

<NAMESPACEDECL>"at"{SP}{URILiteral} {
	debug_put("<NAMESPACEDECL>AT_URI_LITERAL");
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	return AT_URI_LITERAL;
}

<NAMESPACEDECL>"=" {
	debug_put("<NAMESPACEDECL>EQ");
	return EQ;
}

<NAMESPACEDECL>{NCName} {
	debug_put("<NAMESPACEDECL>NCNAME");
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng);
	return NCNAME;
}

<NAMESPACEDECL>[^ \t\r\n] {
  debug_put("<NAMESPACEDECL>UNRECOGNIZED");
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
	debug_put("<URITOOPERATOR>URI_LITERAL");
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
	debug_put("<NAMESPACEKEYWORD>URI_LITERAL");  
	((YYSTYPE*)lvalp)->sval = urilit(yytext, yyleng);
	BEGIN NAMESPACEDECL;
	return URI_LITERAL;
}

<NAMESPACEKEYWORD>"namespace" {
	debug_put("<NAMESPACEKEYWORD>NAMESPACE");
	BEGIN NAMESPACEDECL;
	return NAMESPACE:
}

	/* transition to DEFAULT */
	/* --------------------- */
<NAMESPACEKEYWORD>"inherit" {
	debug_put("<NAMESPACEKEYWORD>INHERIT");
	BEGIN DEFAULT;
	return INHERIT;
}

<NAMESPACEKEYWORD>"no-inherit" {
	debug_put("<NAMESPACEKEYWORD>NO_INHERIT");
	BEGIN DEFAULT;
	return NO_INHERIT;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<NAMESPACEKEYWORD>"(:" {
	debug_put("<NAMESPACEKEYWORD>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}


	/* maintain NAMESPACEKEYWORD */
	/* ------------------------- */
<NAMESPACEKEYWORD>"default"{SP}"element" {
	debug_put("<NAMESPACEKEYWORD>DEFAULT_ELEMENT");
	return DEFAULT_ELEMENT;
}

<NAMESPACEKEYWORD>"preserve" {
	debug_put("<NAMESPACEKEYWORD>PRESERVE");
	return PRESERVE;
}

<NAMESPACEKEYWORD>"no-preserve" {
	debug_put("<NAMESPACEKEYWORD>NO_PRESERVE");
	return NO_PRESERVE;
}

<NAMESPACEKEYWORD>"," {
	debug_put("<NAMESPACEKEYWORD>COMMA");
	return COMMA;
}

<NAMESPACEKEYWORD>[^ \t\r\n] {
  debug_put("<NAMESPACEKEYWORD>UNRECOGNIZED");
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
	debug_put("<XMLSPACE_DECL>PRESERVE");
	BEGIN DEFAULT
	return PRESERVE;
}

<XMLSPACE_DECL>"strip" {
	debug_put("<XMLSPACE_DECL>STRIP");
	BEGIN DEFAULT;
	return STRIP;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<XMLSPACE_DECL>"(:" {
	debug_put("<XMLSPACE_DECL>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

<XMLSPACE_DECL>[^ \t\r\n] {
  debug_put("<XMLSPACE_DECL>UNRECOGNIZED");
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
	debug_put("<SINGLETYPE>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN OPERATOR;
	return QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<SINGLETYPE>"(:" {
	debug_put("<SINGLETYPE>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

<SINGLETYPE>[^ \t\r\n] {
  debug_put("<SINGLETYPE>UNRECOGNIZED");
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
	debug_put("<ITEMTYPE>DOLLAR");
	BEGIN VARNAME;
	return DOLLAR;
}


	/* transition to OPERATOR */
	/* ---------------------- */
<ITEMTYPE>"void"{S}"("{S}")" {
	debug_put("<ITEMTYPE>VOID_TEST");
	BEGIN OPERATOR;
	return VOID_TEST;
}

<ITEMTYPE>{QName} {
	debug_put("<ITEMTYPE>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN OPERATOR;
	return QNAME;
}


	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<ITEMTYPE>"(:" {
	debug_put("<ITEMTYPE>COMMENT_BEGIN");
	pushState(ITEMTYPE);
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}


	/* transition to KINDTEST */
	/* ---------------------- */
<ITEMTYPE>"element"{S}"(" {
	debug_put("<ITEMTYPE>ELEMENT_LPAR");
	pushState(OCCURRENCE_INDICATOR); 
	BEGIN KINDTEST;
	return ELEMENT_LPAR;
}

<ITEMTYPE>"attribute"{S}"(" {
	debug_put("<ITEMTYPE>ATTRIBUTE_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return ATTRIBUTE_LPAR;
}

<ITEMTYPE>"schema-element"{S}"(" {
	debug_put("<ITEMTYPE>SCHEMA_ELEMENT_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return SCHEMA_ELEMENT_LPAR;
}

<ITEMTYPE>"schema-attribute"{S}"(" {
	debug_put("<ITEMTYPE>SCHEMA_ATTRIBUTE_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return SCHEMA_ATTRIBUTE_LPAR;
}

<ITEMTYPE>"comment"{S}"(" {
	debug_put("<ITEMTYPE>COMMENT_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return COMMENT_LPAR;
}

<ITEMTYPE>"text"{S}"(" {
	debug_put("<ITEMTYPE>TEXT_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return TEXT_LPAR;
}

<ITEMTYPE>"node"{S}"(" {
	debug_put("<ITEMTYPE>NODE_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return NODE_LPAR;
}

<ITEMTYPE>"document-node"{S}"(" {
	debug_put("<ITEMTYPE>DOCUMENT_NODE_LPAR");
	pushState(OCCURRENCE_INDICATOR);
	BEGIN KINDTEST;
	return DOCUMENT_NODE_LPAR;
}


	/* transition to KINDTESTFORPI */
	/* --------------------------- */
<ITEMTYPE>"processing-instruction"{S}"(" {
	debug_put("<ITEMTYPE>PI_LPAR");
	pushState(OCCURRENCE_INDICATOR)
	BEGIN KINDTESTFORPI;
	return PI_LPAR;
}


	/* transition to OCCURENCE_INDICATOR */
	/* -------------------------------- */
<ITEMTYPE>{QName} {
	debug_put("<ITEMTYPE>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	return QNAME;
}

<ITEMTYPE>"item"{S}"("{S}")" {	
	debug_put("<ITEMTYPE>ITEM");
	BEGIN OCCURRENCE_INDICATOR;
	return ITEM_TEST;
}


	/* transition to PRAGMA */
	/* -------------------- */
<ITEMTYPE>"(#" {
	debug_put("<ITEMTYPE>PRAGMA_BEGIN");
	BEGIN PRAGMA;
	return PRAGMA_BEGIN;
}


	/* transition to DEFAULT */
	/* --------------------- */
<ITEMTYPE>";" {
	debug_put("<ITEMTYPE>SEMI");
	BEGIN DEFAULT;
	return SEMI;
}

<ITEMTYPE>"then" {
	debug_put("<ITEMTYPE>THEN");
	BEGIN DEFAULT;
	return THEN;
}

<ITEMTYPE>"else" {
	debug_put("<ITEMTYPE>ELSE");
	BEGIN DEFAULT;
	return ELSE;
}


	/* transition to NAMESPACEDECL */
	/* --------------------------- */
<ITEMTYPE>"at"{SP}{URILiteral} {
	debug_put("<ITEMTYPE>AT_URI_LITERAL");
	((YYSTYPE*)lvalp)->sval = urilit(yytext[3], yyleng-3);
	BEGIN NAMESPACEDECL;
	return AT_URI_LITERAL;
}


	/* transition to DEFAULT */
	/* --------------------- */
<ITEMTYPE>"external" {
	debug_put("<ITEMTYPE>EXTERNAL");
	BEGIN DEFAULT;
	return EXTERNAL;
}

<ITEMTYPE>"and" {
	debug_put("<ITEMTYPE>AND");
	BEGIN DEFAULT;
	return AND;
}

<ITEMTYPE>"at" {
	debug_put("<ITEMTYPE>AT");
	BEGIN DEFAULT;
	return AT;
}

<ITEMTYPE>":=" {
	debug_put("<ITEMTYPE>GETS");
	BEGIN DEFAULT;
	return GETS;
}

<ITEMTYPE>"," {
	debug_put("<ITEMTYPE>COMMA");
	BEGIN DEFAULT;
	return COMMA;
}

<ITEMTYPE>"div" {
	debug_put("<ITEMTYPE>DIV");
	BEGIN DEFAULT;
	return DIV;
}

<ITEMTYPE>"=" {
	debug_put("<ITEMTYPE>EQ");
	BEGIN DEFAULT;
	return EQ;
}

<ITEMTYPE>"except" {
	debug_put("<ITEMTYPE>EXCEPT");
	BEGIN DEFAULT;
	return EXCEPT;
}

<ITEMTYPE>"eq" {
	debug_put("<ITEMTYPE>F_EQ");
	BEGIN DEFAULT;
	return F_EQ;
}

<ITEMTYPE>"ge" {
	debug_put("<ITEMTYPE>F_GE");
	BEGIN DEFAULT;
	return F_GE;
}

<ITEMTYPE>"gt" {
	debug_put("<ITEMTYPE>F_GT");
	BEGIN DEFAULT;
	return F_GT;
}

<ITEMTYPE>"le" {
	debug_put("<ITEMTYPE>F_LE");
	BEGIN DEFAULT;
	return F_LE;
}

<ITEMTYPE>"lt" {
	debug_put("<ITEMTYPE>F_LT");
	BEGIN DEFAULT;
	return F_LT;
}

<ITEMTYPE>"ne" {
	debug_put("<ITEMTYPE>F_NE");
	BEGIN DEFAULT;
	return F_NE;
}

<ITEMTYPE>">=" {
	debug_put("<ITEMTYPE>GE");
	BEGIN DEFAULT;
	return GE;
}

<ITEMTYPE>">>" {
	debug_put("<ITEMTYPE>FOLLOWS");
	BEGIN DEFAULT;
	return FOLLOWS;
}

<ITEMTYPE>">" {
	debug_put("<ITEMTYPE>GT");
	BEGIN DEFAULT;
	return GT;
}

<ITEMTYPE>"idiv" {
	debug_put("<ITEMTYPE>IDIV");
	BEGIN DEFAULT;
	return IDIV;
}

<ITEMTYPE>"intersect" {
	debug_put("<ITEMTYPE>INTERSECT");
	BEGIN DEFAULT;
	return INTERSECT;
}

<ITEMTYPE>"in" {
	debug_put("<ITEMTYPE>IN");
	BEGIN DEFAULT;
	return IN;
}

<ITEMTYPE>"is" {
	debug_put("<ITEMTYPE>IS");
	BEGIN DEFAULT;
	return IS;
}

<ITEMTYPE>"[" {
	debug_put("<ITEMTYPE>LBRACK");
	BEGIN DEFAULT;
	return LBRACK;
}

<ITEMTYPE>"(" {
	debug_put("<ITEMTYPE>LPAR");
	BEGIN DEFAULT;
	return LPAR;
}

<ITEMTYPE>"<=" {
	debug_put("<ITEMTYPE>LE");
	BEGIN DEFAULT;
	return LE;
}

<ITEMTYPE>"<<" {
	debug_put("<ITEMTYPE>PRECEDES");
	BEGIN DEFAULT;
	return PRECEDES;
}

<ITEMTYPE>"<" {
	debug_put("<ITEMTYPE>LT");
	BEGIN DEFAULT;
	return LT;
}

<ITEMTYPE>"-" {
	debug_put("<ITEMTYPE>MINUS");
	BEGIN DEFAULT;
	return MINUS;
}

<ITEMTYPE>"mod" {
	debug_put("<ITEMTYPE>MOD");
	BEGIN DEFAULT;
	return MOD;
}

<ITEMTYPE>"!=" {
	debug_put("<ITEMTYPE>NE");
	BEGIN DEFAULT;
	return NE;
}

<ITEMTYPE>"order"{SP}"by" {
	debug_put("<ITEMTYPE>ORDER_BY");
	BEGIN DEFAULT;
	return ORDER_BY;
}

<ITEMTYPE>"stable"{SP}"order"{SP}"by" {
	debug_put("<ITEMTYPE>STABLE_ORDER_BY");
	BEGIN DEFAULT;
	return STABLE_ORDER_BY;
}

<ITEMTYPE>"or" {
	debug_put("<ITEMTYPE>OR");
	BEGIN DEFAULT;
	return OR;
}

<ITEMTYPE>"return" {
	debug_put("<ITEMTYPE>RETURN");
	BEGIN DEFAULT;
	return RETURN;
}

<ITEMTYPE>"satisfies" {
	debug_put("<ITEMTYPE>SATISFIES");
	BEGIN DEFAULT;
	return SATISFIES;
}

<ITEMTYPE>"to" {
	debug_put("<ITEMTYPE>TO");
	BEGIN DEFAULT;
	return TO;
}

<ITEMTYPE>"union" {
	debug_put("<ITEMTYPE>UNION");
	BEGIN DEFAULT;
	return UNION;
}

<ITEMTYPE>"|" {
	debug_put("<ITEMTYPE>VBAR");
	BEGIN DEFAULT;
	return VBAR;
}

<ITEMTYPE>"where" {
	debug_put("<ITEMTYPE>WHERE");
	BEGIN DEFAULT;
	return WHERE;
}


	/* transition to SINGLETYPE */
	/* ------------------------ */
<ITEMTYPE>"castable"{SP}"as" {
	debug_put("<ITEMTYPE>CASTABLE_AS");
	BEGIN SINGLETYPE;
	return CASTABLE_AS;
}

<ITEMTYPE>"cast"{SP}"as" {
	debug_put("<ITEMTYPE>CAST_AS");
	BEGIN SINGLETYPE;
	return CAST_AS;
}


	/* maintain ITEMTYPE */
	/* ----------------- */
<ITEMTYPE>"instance"{SP}"of" {
	debug_put("<ITEMTYPE>INSTANCE_OF");
	return INSTANCE_OF;
}

<ITEMTYPE>"treat"{SP}"as" {
	debug_put("<ITEMTYPE>TREAT_AS");
	return TREAT_AS;
}

<ITEMTYPE>"case" {
	debug_put("<ITEMTYPE>CASE");
	return CASE;
}

<ITEMTYPE>"as" {
	debug_put("<ITEMTYPE>AS");
	return AS;
}

<ITEMTYPE>")"{S}"as" {
	debug_put("<ITEMTYPE>RPAR_AS");
	return RPAR_AS;
}

<ITEMTYPE>[^ \t\r\n] {
  debug_put("<ITEMTYPE>UNRECOGNIZED");
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
	debug_put("<KINDTEST>LBRACE");
	pushState(OPERATOR)
	BEGIN DEFAULT;
	return LBRACE;
}

	/* transition to CLOSE_KINDTEST */
	/* --------------------------- */
<KINDTEST>"*" {
	debug_put("<KINDTEST>STAR");
	BEGIN CLOSE_KINDTEST;
	return STAR;
}

<KINDTEST>{QName} {
	debug_put("<KINDTEST>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN CLOSE_KINDTEST;
	return QNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<KINDTEST>"(:" {
	debug_put("<KINDTEST>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

	/* pop previous state on close paren */
	/* --------------------------------- */
<KINDTEST>")" {
	debug_put("<KINDTEST>RPAR");
	popState();
	return RPAR;
}

	/* maintain KINDTEST */
	/* ----------------- */
<KINDTEST>"element"{S}"(" {
	debug_put("<KINDTEST>ELEMENT_LPAR");
	return ELEMENT_LPAR;
}

<KINDTEST>"schema-element"{S}"(" {
	debug_put("<KINDTEST>SCHEMA_ELEMENT_LPAR");
	pushState(KINDTEST);
	return SCHEMA_ELEMENT_LPAR;
}

<KINDTEST>[^ \t\r\n] {
  debug_put("<KINDTEST>UNRECOGNIZED");
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
	debug_put("<KINDTESTFORPI>RPAR");
	popState();
	return RPAR;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */

<KINDTESTFORPI>"(:" {
	debug_put("<KINDTESTFORPI>COMMENT_BEGIN");
	pushState(KINDTESTFORPI);
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

	/* maintain KINDTESTFORPI */
	/* ---------------------- */
<KINDTESTFORPI>{NCName} {
	debug_put("<KINDTESTFORPI>NCNAME");
	((YYSTYPE*)lvalp)->sval = ncname(yytext, yyleng);
	return NCNAME;
}

<KINDTESTFORPI>{StringLiteral} {
	debug_put("<KINDTESTFORPI>STRING_LITERAL");
	((YYSTYPE*)lvalp)->sval = stringlit(yytext, yyleng);
	return STRING_LITERAL;
}

<KINDTESTFORPI>[^ \t\r\n] {
  debug_put("<KINDTESTFORPI>UNRECOGNIZED");
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
	debug_put("<CLOSEDKINDTEST>RPAR");
	popState();
	return RPAR;
}

	/* transition to KINDTEST */
	/* ---------------------- */
<CLOSE_KINDTEST>"," {
	debug_put("<CLOSEDKINDTEST>COMMA");
	BEGIN KINDTEST;
	return COMMA;
}

	/* transition to DEFAULT */
	/* --------------------- */
<CLOSE_KINDTEST>"{" {
	debug_put("<CLOSEDKINDTEST>LBRACE");
	pushState(OPERATOR);
	BEGIN DEFAULT;
	return LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<CLOSE_KINDTEST>"(:" {
	debug_put("<CLOSEDKINDTEST>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

	/* maintain CLOSE_KINDTEST */
	/* ---------------------- */
<CLOSE_KINDTEST>"?" {
	debug_put("<CLOSEDKINDTEST>HOOK");
	return HOOK;
}

<CLOSE_KINDTEST>[^ \t\r\n] {
  debug_put("<CLOSE_KINDTEST>UNRECOGNIZED");
  return UNRECOGNIZED;
}



	/*______________________________________________________________________  
	 *                                                                      * 
	 * OCCURRENCEINDICATOR State                                            * 
	 *                                                                      * 
	 * This special state is needed to distinguish occurrence indicators    * 
	 * thta appear in the SequenceType production. For instance, compare    * 
	 * "foo instance of baz*" to "baz*foo". In the first case, the "*" is   * 
	 * interpreted as an occurrence indicator, and in the second case, it   * 
	 * must be interpreted as a multiplication operator. But, when in the   * 
	 * OCCURRENCEINDICATOR state, if anything else other than "?", "*",     * 
	 * "+", those symbols must be interpreted in the OPERATOR state. For    * 
	 * instance, this would occur with the expression "foo instance of baz  * 
	 * and $x", with the operator "and". This backing up of the lexical     * 
	 * characters in order to reset the state is symbolized by the notation * 
	 * "input_stream.backup(1)". NotOccurrenceIndicator is a special symbol	* 
	 * for any character that is not an occurrence indicator.								* 
	 *______________________________________________________________________*/

	/* <OCCURRENCE_INDICATOR>{NotOccurrenceIndicator} { */
	/* input_stream.backup(1);	*/
	/* BEGIN OPERATOR;					*/
	/* don't return anything		*/
	/* }												*/

	/* transition to OPERATOR */
	/* ---------------------- */
<OCCURRENCE_INDICATOR>"?" {
	debug_put("<OCCURRENCE_INDICATOR>HOOK");
	BEGIN OPERATOR;
	return HOOK;
}

<OCCURRENCE_INDICATOR>"*" {
	debug_put("<OCCURRENCE_INDICATOR>STAR");
	BEGIN OPERATOR;
	return STAR;
}

<OCCURRENCE_INDICATOR>"+" {
	debug_put("<OCCURRENCE_INDICATOR>PLUS");
	BEGIN OPERATOR;
	return PLUS;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<OCCURRENCE_INDICATOR>"(:" {
	debug_put("<OCCURRENCE_INDICATOR>COMMENT_BEGIN");
	pushState();
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

<OCCURRENCE_INDICATOR>[^ \t\r\n] {
  debug_put("<OCCURRENCE_INDICATOR>UNRECOGNIZED");
  return UNRECOGNIZED;
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
	debug_put("<OPTION>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN DEFAULT;
	return QNAME;
}

<OPTION>[^ \t\r\n] {
  debug_put("<OPTION>UNRECOGNIZED");
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
	debug_put("<PRAGMA>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	BEGIN PRAGMACONTENTS;
	return QNAME;
}

<PRAGMA>[^ \t\r\n] {
  debug_put("<PRAGMA>UNRECOGNIZED");
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
	debug_put("<PRAGMACONTENTS>PRAGMA_END");
	BEGIN OPERATOR;
	return PRAGMA_END;
}

	/* maintain PRAGMACONTENTS */
	/* ----------------------- */
<PRAGMACONTENTS>{S} {
	debug_put("<PRAGMACONTENTS>WS");
	/* continue lexing */
}

<PRAGMACONTENTS>{Char}+ {
	debug_put("<PRAGMACONTENTS>CHAR");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return PRAGMA_LITERAL;
}

<PRAGMACONTENTS>[^ \t\r\n] {
  debug_put("<PRAGMACONTENTS>UNRECOGNIZED");
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
	debug_put("<VARNAME>VARNAME");
	((YYSTYPE*)lvalp)->sval = varname(yytext, yyleng);
	BEGIN OPERATOR;
	return VARNAME;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<VARNAME>"(:" {
	debug_put("<VARNAME>COMMENT_BEGIN");
	pushState(VARNAME);
	BEGIN EXPR_COMMENT;
	return COMMENT_BEGIN;
}

<VARNAME>[^ \t\r\n] {
  debug_put("<VARNAME>UNRECOGNIZED");
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
	debug_put("<START_TAG>GT");
	BEGIN ELEMENT_CONTENT;
	return GT;
}

	/* transition to QUOT_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
<START_TAG>\" {
	debug_put("<START_TAG>QUOTE");
	QUOT_ATTRIBUTE_CONTENT
	return QUOTE;
}

	/* transition to APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------------ */
<START_TAG>\' {
	debug_put("<START_TAG>APOS");
	BEGIN APOS_ATTRIBUTE_CONTENT;
	return APOS;
}

	/* transition to START_TAG */
	/* ----------------------- */
<START_TAG>"=" {
	debug_put("<START_TAG>EQ");
	BEGIN START_TAG;
	return EQ;
}

	/* pop previous state on exit */
	/* -------------------------- */
<START_TAG>"/>" {
	debug_put("<START_TAG>SGT");
	popState();
	return SGT;
}

	/* maintain START_TAG */
	/* ------------------ */
<START_TAG>{S} {
	debug_put("<START_TAG>WS");
	/* continue lexing */
}

<START_TAG>{QName} {
	debug_put("<START_TAG>QNAME");
	((YYSTYPE*)lvalp)->sval = qname(yytext, yyleng);
	return QNAME;
}

<START_TAG>[^ \t\r\n] {
  debug_put("<START_TAG>UNRECOGNIZED");
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
	debug_put("<ELEMENT_CONTENT>LTS");
	BEGIN END_TAG;
	return LTS;
}

	/* transition to DEFAULT */
	/* --------------------- */
<ELEMENT_CONTENT>"{" {
	debug_put("<ELEMENT_CONTENT>LBRACE");
	pushState();
	BEGIN DEFAULT;
	return LBRACE;
}

	/* transition to EXPR_COMMENT */
	/* -------------------------- */
<ELEMENT_CONTENT>"<!--" {
	debug_put("<ELEMENT_CONTENT>XML_COMMENT_BEGIN");
	pushState();
	BEGIN XML_COMMENT;
	return XML_COMMENT_BEGIN;
}

	/* transition to PROCESSING_INSTRUCTION */
	/* ------------------------------------ */
<ELEMENT_CONTENT>"<?" {
	debug_put("<ELEMENT_CONTENT>PI_BEGIN");
	pushState()
	BEGIN PROCESSING_INSTRUCTION;
	return PI_BEGIN;
}

	/* transition to CDATA_SECTION */
	/* --------------------------- */
<ELEMENT_CONTENT>"<![CDATA[" {
	debug_put("<ELEMENT_CONTENT>CDATA_BEGIN");
	pushState()
	BEGIN CDATA_SECTION;
	return CDATA_BEGIN;
}

	/* transition to START_TAG */
	/* ----------------------- */
<ELEMENT_CONTENT>"<" {
	debug_put("<ELEMENT_CONTENT>START_TAG");
	pushState();
	BEGIN START_TAG;
	return START_TAG;
}

	/* maintain ELEMENT_CONTENT */
	/* ------------------------ */
<ELEMENT_CONTENT>{ElementContentChar}+ {
	debug_put("<ELEMENT_CONTENT>ELEMENT_CONTENT_CHAR");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return ELEMENT_CONTENT;
}

<ELEMENT_CONTENT>{PredefinedEntityRef} {
	debug_put("<ELEMENT_CONTENT>ENTITY_REF");
	((YYSTYPE*)lvalp)->sval = entityref(yytext, yyleng);
	return ENTITY_REF;
}

<ELEMENT_CONTENT>{CharRef}+ {
	debug_put("<ELEMENT_CONTENT>CHAR_REF");
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<ELEMENT_CONTENT>"{{" {
	debug_put("<ELEMENT_CONTENT>DOUBLE_LBRACE");
	return DOUBLE_LBRACE;
}

<ELEMENT_CONTENT>"}}" {
	debug_put("<ELEMENT_CONTENT>DOUBLE_RBRACE");
	return DOUBLE_RBRACE;
}

<ELEMENT_CONTENT>[^ \t\r\n] {
  debug_put("<ELEMENT_CONTENT>UNRECOGNIZED");
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
	debug_put("<END_TAG>GT");
	popState();
	return GT;
}

	/* maintain END_TAG */
	/* ---------------- */
<END_TAG>{S} {
	debug_put("<END_TAG>WS");
	/* continue lexing */
}

<END_TAG>{QName} {
	debug_put("<END_TAG>QNAME");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return QNAME;
}

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
	debug_put("<XML_COMMENT>XML_COMMENT_END");
	popState();
	return XML_COMMENT_END;
}

	/* maintain XML_COMMENT */
	/* -------------------- */
<XML_COMMENT>{XMLCommentChar}* {
	debug_put("<XML_COMMENT>XML_COMMENT_LIT");
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
	debug_put("<EXPR_COMMENT>COMMENT_END");
	popState();
	return COMMENT_END;
}

	/* maintain EXPR_COMMENT */
	/* --------------------- */
<EXPR_COMMENT>"(:" {
	debug_put("<EXPR_COMMENT>COMMENT_BEGIN");
	pushState(EXPR_COMMENT);
	return COMMENT_BEGIN;
}

<EXPR_COMMENT>{Char}+ {
	debug_put("<EXPR_COMMENT>EXPR_COMMENT_CHAR");
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
	debug_put("<PROCESSING_INSTRUCTION>WS");
	BEGIN PROCESSING_INSTRUCTION_CONTENT; 
	/* continue lexing */
}

	/* pop previous state on exit */
	/* -------------------------- */
<PROCESSING_INSTRUCTION>"?>" {
	debug_put("<PROCESSING_INSTRUCTION>PI_END");
	popState();
	return PI_END;
}

	/* maintain PROCESSING_INSTRUCTION */
	/* ------------------------------- */
<PROCESSING_INSTRUCTION>{PITarget} {
	debug_put("<PROCESSING_INSTRUCTION>PI_TARGET");
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
	debug_put("<PROCESSING_INSTRUCTION_CONTENT>PI_END");
	popState();
	return PI_BEGIN;
}

	/* maintain PROCESSING_INSTRUCTION_CONTENT */
	/* --------------------------------------- */
<PROCESSING_INSTRUCTION_CONTENT>{Char}+ {
	debug_put("<PROCESSING_INSTRUCTION_CONTENT>CHAR_LITERAL");
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
	debug_put("<CDATA_SECTION>CDATA_END");
	popState();
	return CDATA_END;
}

	/* maintain CDATA_SECTION */
	/* ---------------------- */
<CDATA_SECTION>{Char}+ {
	debug_put("<CDATA_SECTION>CHAR_LITERAL");
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
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>QUOTE");
	BEGIN START_TAG;
	return QUOTE;
}

	/* transition to DEFAULT */
	/* --------------------- */
<QUOTE_ATTRIBUTE_CONTENT>"{" {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>LBRACE");
	pushState(QUOTE_ATTRIBUTE_CONTENT);
	BEGIN DEFAULT;
	return LBRACE;
}

	/* maintain QUOTE_ATTRIBUTE_CONTENT */
	/* -------------------------------- */
<QUOTE_ATTRIBUTE_CONTENT>{EscapeQuot} {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>ESCAPE_QUOTE");
	return ESCAPE_QUOTE;
}

<QUOTE_ATTRIBUTE_CONTENT>{QuotAttrContentChar}+ {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>QUOTE_ATTR_CONTENT");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return QUOTE_ATTR_CONTENT;
}

<QUOTE_ATTRIBUTE_CONTENT>{PredefinedEntityRef} {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>ENTITY_REF");
	return ENTITY_REF;
}

<QUOTE_ATTRIBUTE_CONTENT>{CharRef}+ {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>CHAR_REF_LITERAL");
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<QUOTE_ATTRIBUTE_CONTENT>"{{" {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>DOUBLE_LBRACE");
	return DOUBLE_LBRACE;
}

<QUOTE_ATTRIBUTE_CONTENT>"}}" {
	debug_put("<QUOTE_ATTRIBUTE_CONTENT>DOUBLE_RBRACE");
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
	debug_put("<APOS_ATTRIBUTE_CONTENT>APOS");
	BEGIN START_TAG;
	return APOS;
}

	/* transition to DEFAULT */
	/* --------------------- */
<APOS_ATTRIBUTE_CONTENT>"{" {
	debug_put("<APOS_ATTRIBUTE_CONTENT>BRACE");
	pushState(APOS_ATTRIBUTE_CONTENT);
	BEGIN DEFAULT;
	return LBRACE;
}

	/* maintain APOS_ATTRIBUTE_CONTENT */
	/* ------------------------------- */
<APOS_ATTRIBUTE_CONTENT>{EscapeApos} {
	debug_put("<APOS_ATTRIBUTE_CONTENT>ESCAPE_APOS");
	return ESCAPE_APOS;
}

<APOS_ATTRIBUTE_CONTENT>{AposAttrContentChar}+ {
	debug_put("<APOS_ATTRIBUTE_CONTENT>APOS_ATTR_CONTENT");
	((YYSTYPE*)lvalp)->sval = sval(yytext, yyleng);
	return APOS_ATTR_CONTENT;
}

<APOS_ATTRIBUTE_CONTENT>PredefinedEntityRef {
	debug_put("<APOS_ATTRIBUTE_CONTENT>ENTITY_REF");
	return ENTITY_REF;
}

<APOS_ATTRIBUTE_CONTENT>{CharRef}+ {
	debug_put("<APOS_ATTRIBUTE_CONTENT>CHAR_REF_LITERAL");
	((YYSTYPE*)lvalp)->sval = charref(yytext, yyleng);
	return CHAR_REF_LITERAL;
}

<APOS_ATTRIBUTE_CONTENT>"{{" {
	debug_put("<APOS_ATTRIBUTE_CONTENT>DOUBLE_LBRACE");
	return DOUBLE_LBRACE;
}

<APOS_ATTRIBUTE_CONTENT>"}}" {
	debug_put("<APOS_ATTRIBUTE_CONTENT>DOUBLE_RBRACE");
	return DOUBLE_RBRACE;
}



%%
