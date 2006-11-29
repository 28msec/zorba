/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery_parser.y,v 1.2 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 */

/*
	The parser definition file starts by asking for the C++ LALR(1) 
	skeleton, the creation of the parser header file, and specifies the 
	name of the parser class.  Because the C++ skeleton changes, it is
	safer to require the version. 
*/

%skeleton "lalr1.cc"  /*  -*- C++ -*- */
%require "2.3"
%defines
%define "parser_class_name" "xquery_parser"

/*
	Because the parser uses the xquery_driver and reciprocally, both 
	cannot include the header of the other. Because the driver's header 
	needs detailed knowledge about the parser class (in particular its 
	inner types), it is the parser's header which will use a forward
	declaration of the driver. 
*/

%{
#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "parsenodes.h"

class xquery_driver;
%}

/*
	The driver is passed by reference to the parser and to the scanner. 
	This provides a simple but effective pure interface, not relying on 
	global variables. 
*/
%parse-param { xquery_driver& driver }
%lex-param   { xquery_driver& driver }


/*
	Request the location tracking feature, and initialize the 
	first location's file name. Afterwards new locations are computed 
	relatively to the previous locations: the file name will be 
	automatically propagated. 
*/
%locations
%initial-action
{
  @$.begin.filename = @$.end.filename = &driver.file;
};


/*
	Use the two following directives to enable parser tracing and verbose 
	error messages. 
*/
%debug
%error-verbose


/*
	Semantic values cannot use real objects, but only pointers to them.
*/
%union
{
  xqp::parsenode* node;
  off_t sval;
	int ival;
	double dval;
}


/*
	The code between `%{' and `%}' after the introduction of the `%union' 
	is output in the *.cc file; it needs detailed knowledge about the 
	driver. 
*/
%{
#include "xquery_driver.h"
#include "symbol_table.h"

#define INITIAL_HEAPSIZE	1024

xqp::symbol_table symtab(INITIAL_HEAPSIZE);
%}


/*
	The token numbered as 0 corresponds to end of file; the following line 
	allows for nicer error messages referring to end of file instead of 
	$end. Similarly user friendly names are provided for each symbol.
*/

%token	END	0 "end of file"

/* tokens that contain embedded string literals */
/* -------------------------------------------- */
%token <sval> APOS_ATTR_CONTENT				"apos attribute content"
%token <sval> ATTRIBUTE_QNAME_LBRACE	"<attribute QName {>"
%token <sval> AT_URI_LITERAL					"<at URI>"
%token <sval> CHAR_LITERAL						"char literal"
%token <sval> CHAR_REF_LITERAL				"#charref;"
%token <sval> ELEMENT_CONTENT					"element content"
%token <sval> ELEMENT_QNAME_LBRACE		"<QName {>"
%token <sval> ELEM_WILDCARD						"pref:*"
%token <sval> ENTITY_REF							"&entity;"
%token <sval> EXPR_COMMENT_LITERAL		"comment literal"
%token <sval> NCNAME									"NCName"
%token <sval> PI_NCNAME_LBRACE				"pi <NCName {>"
%token <sval> PI_TARGET_LITERAL				"pi target"
%token <sval> PRAGMA_LITERAL					"pragma literal"
%token <sval> PREFIX_WILDCARD					"*:QName"
%token <sval> QNAME										"QName"
%token <sval> QNAME_LPAR							"<QName (>"
%token <sval> QUOTE_ATTR_CONTENT			"quote attribute content"
%token <sval> STRING_LITERAL					"STRING"
%token <sval> URI_LITERAL							"URI"
%token <sval> VARNAME									"variable name"
%token <sval> VALIDATE_MODE						"validate mode"
%token <sval> XML_COMMENT_LITERAL			"XML comment"


/* simple tokens */
/* ------------- */
%token ANCESTOR_AXIS							"ancestor::"
%token ANCESTOR_OR_SELF_AXIS			"ancestor-or-self::"
%token AND												"and"
%token APOS												"'"
%token AS													"as"
%token ASCENDING									"ascending"
%token AT													"at"
%token ATTRIBUTE									"attribute"
%token ATTRIBUTE_AXIS							"attribute::"
%token ATTRIBUTE_LBRACE						"<attribute {>"
%token ATTRIBUTE_LPAR							"<attribute (>"
%token AT_SIGN										"@"
%token CASE												"case"
%token CASTABLE_AS								"<castable as>"
%token CAST_AS										"<cast as>"
%token CDATA_BEGIN								"CDATA[["
%token CDATA_END									"]]"
%token CHILD_AXIS									"child::"
%token COLLATION									"collation"
%token COMMA											","
%token COMMENT_BEGIN							"(:"
%token COMMENT_END								":)"
%token COMMENT_LBRACE							"<comment {>"
%token COMMENT_LPAR								"<comment (>"
%token DECIMAL_LITERAL						"DECIMAL"
%token DECLARE_BASE_URI						"<declare base URI>"
%token DECLARE_BOUNDARY_SPACE			"<declare boundary space>"
%token DECLARE_CONSTRUCTION				"<declare construction>"
%token DECLARE_COPY_NAMESPACES		"<declare copy namespaces>"
%token DECLARE_DEFAULT_COLLATION	"<declare default collation>"
%token DECLARE_DEFAULT_ELEMENT		"<declare default element>"
%token DECLARE_DEFAULT_FUNCTION		"<declare default function>"
%token DECLARE_DEFAULT_ORDER			"<declare default order>"
%token DECLARE_FUNCTION						"<declare function>"
%token DECLARE_NAMESPACE					"<declare namespace>"
%token DECLARE_OPTION							"<declare option>"
%token DECLARE_ORDERING						"<declare ordering>"
%token DECLARE_VARIABLE_DOLLAR		"<declare var $>"
%token DEFAULT										"default"
%token DEFAULT_ELEMENT						"<default element>"
%token DESCENDANT_AXIS						"descendant::"
%token DESCENDANT_OR_SELF_AXIS		"descendant-or-self::"
%token DESCENDING									"descending"
%token DIV												"div"
%token DOCUMENT_LBRACE						"<document {>"
%token DOCUMENT_NODE_LPAR					"<document node (>"
%token DOLLAR											"$"
%token DOT												"."
%token DOT_DOT										".."
%token DOUBLE_LBRACE							"{{"
%token DOUBLE_LITERAL							"DOUBLE"
%token DOUBLE_RBRACE							"<double {>"
%token ELEMENT_LBRACE							"<element {>"
%token ELEMENT_LPAR								"<element (>"
%token ELSE												"else"
%token EMPTY_GREATEST							"<empty greatest>"
%token EMPTY_LEAST								"<empty least>"
%token ENCODING										"encoding"
%token EQUALS											"="
%token ESCAPE_APOS								"''"
%token ESCAPE_QUOTE								"\"\""
%token EVERY_DOLLAR								"<every $>"
%token EXCEPT											"except"
%token EXTERNAL										"external"
%token F_EQ												"eq"
%token F_GE												"ge"
%token F_GT												"gt"
%token F_LE												"le"
%token F_LT												"lt"
%token F_NE												"ne"
%token FOLLOWING_AXIS							"following::"
%token FOLLOWING_SIBLING_AXIS			"following-sibling::"
%token FOLLOWS										"follows"
%token FOR_DOLLAR									"<for $>"
%token GENERALCOMP								"general comp"
%token GE													">="
%token GETS												":="
%token GT													">"
%token HOOK												"?"
%token IDIV												"idiv"
%token IF_LPAR										"<if (>"
%token IMPORT_MODULE							"<import module>"	
%token IMPORT_SCHEMA							"<import schema>"
%token IN													"in"
%token INHERIT										"inherit"
%token INSTANCE_OF								"<instance of>"
%token INTEGER_LITERAL						"INTEGER"
%token INTERSECT									"intersect"
%token IS													"is"
%token ITEM_TEST									"item()"
%token LBRACE											"{"
%token LBRACK											"["
%token LE													"<="
%token LEADING_LONE_SLASH					"[ / ]"
%token LET_DOLLAR									"<let $>"
%token LPAR												"("
%token LT													"<"
%token MINUS											"-"
%token MOD												"mod"
%token MODULE_NAMESPACE						"<module namespace>"
%token NAMESPACE									"namespace"
%token NAN												"nan"
%token NE													"!="
%token NODECOMP										"nodecomp"
%token NODE_LPAR									"<node (>"
%token NOT_OPERATOR_KEYWORD				"??"
%token NO_INHERIT									"<no inherit>"
%token NO_PRESERVE								"<no preserve>"
%token OR													"or"
%token ORDERED										"ordered"
%token ORDERED_LBRACE							"ordered {"
%token ORDER_BY										"<order by>"
%token PARENT_AXIS								"parent::"
%token PI_BEGIN										"<?"
%token PI_END											"?>"
%token PI_LBRACE									"<pi {>"
%token PI_LPAR										"<pi (>"
%token PI_TARGET									"PI TARGET"
%token PLUS												"+"
%token PRAGMA_BEGIN								"PRAGMA BEGIN"
%token PRAGMA_END									"PRAGMA END"
%token PRECEDES										"<<"
%token PRECEDING_AXIS							"preceding::"
%token PRECEDING_SIBLING_AXIS			"preceding-sibling::"
%token PRESERVE										"preserve"
%token PROCESSING_INSTRUCTION			"<processing instruction>"
%token QUOTE											"\""
%token RBRACE											"}"
%token RBRACK											"]"
%token RETURN											"return"
%token RPAR												")"
%token RPAR_AS										"<) as>"
%token SATISFIES									"satisfies"
%token SCHEMA_ATTRIBUTE_LPAR			"<schema attribute ("
%token SCHEMA_ELEMENT_LPAR				"<schema element (>"
%token SELF_AXIS									"self::"
%token SEMI												";"
%token SGT												"/>"
%token SLASH											"/"
%token SLASH_SLASH								"//"
%token SOME_DOLLAR								"<some $>"
%token STABLE_ORDER_BY						"<stable order by>"
%token STAR												"*"
%token START_TAG_END							"start tag end >"
%token START_TAG									"start tag <"
%token STRIP											"strip"
%token TAG_END										"</"
%token TEXT_LBRACE								"<text {>"
%token TEXT_LPAR									"<text (>"
%token THEN												"then"
%token TO													"to"
%token TREAT_AS										"<treat as>"
%token TYPESWITCH_LPAR						"<typeswitch (>"
%token UNION											"union"
%token UNORDERED									"unordered"
%token UNORDERED_LBRACE						"<unordered (>"
%token UNRECOGNIZED								"unrecognized"
%token VALIDATE_LBRACE						"<validate {>"
%token VALUECOMP									"VALUECOMP"
%token VBAR												"|"
%token VOID_TEST									"void()"
%token WHERE											"where"
%token XML_COMMENT_BEGIN					"<!"
%token XML_COMMENT_END						"-->"
%token XQUERY_VERSION							"<XQuery Version>"


/* update-related */
/* -------------- */
%token AFTER											"after"
%token BEFORE											"before"
%token COMMA_DOLLAR 							"<, $>"
%token DECLARE_REVALIDATION_MODE	"<declare revalidation mode>"
%token DO_DELETE									"<do delete>"
%token DO_INSERT									"<do insert>"
%token DO_RENAME									"<do rename>"
%token DO_REPLACE									"<do replace>"
%token FIRST_INTO									"<first into>"
%token INTO												"into"
%token LAST_INTO									"<lastinto>"
%token MODIFY 										"modify"
%token TRANSFORM_COPY_DOLLAR 			"<transform copy $>"
%token VALUE_OF										"<value of>"
%token WITH												"with"


/* full-text-related */
/* ----------------- */
%token ALL												"all"
%token ALL_WORDS									"<all words>"
%token ANY												"any"
%token ANY_WORD										"<any words>"
%token AT_END											"<at end>"
%token AT_LEAST										"<at least>"
%token AT_MOST										"<at most>"
%token AT_START										"<at start>"
%token CASE_INSENSITIVE						"<case insensitive>"
%token CASE_SENSITIVE							"<casesensitive>"
%token DECLARE_FTOPTION						"<declare ftoption>"
%token DIACRITICS_INSENSITIVE			"<diacritics insensitive>"
%token DIACRITICS_SENSITIVE				"<diacritics sensitive>"
%token DIFFERENT									"different"
%token DISTANCE										"distance"
%token ENTIRE_CONTENT							"<entire content>"
%token EXACTLY										"exactly"
%token FROM												"from"
%token FTAND											"&&"
%token FTCONTAINS 								"ftcontains"
%token FTNOT											"ftnot"
%token FTOR												"||"
%token LANGUAGE 									"language"
%token LEVELS											"levels"
%token LOWERCASE									"lowercase"
%token NOT_IN											"<not in>"
%token OCCURS											"occurs"
%token PARAGRAPH									"paragraph"
%token PHRASE											"phrase"
%token RELATIONSHIP								"relationship"
%token SAME												"same"
%token SCORE											"score"
%token SENTENCE										"sentence"
%token SENTENCES									"sentences"
%token TIMES											"times"
%token UPPERCASE									"uppercase"
%token WEIGHT											"weight"
%token WINDOW											"window"
%token WITHOUT_CONTENT						"<without content>"
%token WITHOUT_DIACRITICS					"<without diacritics>"
%token WITHOUT_STEMMING						"<without stemming>"
%token WITHOUT_STOP_WORDS					"<without stop words>"
%token WITHOUT_THESAURUS					"<without thesaurus>"
%token WITHOUT_WILDCARDS					"<without wildcards>"
%token WITH_DEFAULT_STOP_WORDS 		"<with default stop words>"
%token WITH_DIACRITICS						"<with diacritics>"
%token WITH_STEMMING							"<with stemming>"
%token WITH_STOP_WORDS 						"<with stop words>"
%token WITH_THESAURUS							"<with thesaurus>"
%token WITH_WILDCARDS							"<with wildcards>"
%token WORDS											"words"

/* left-hand sides */
/* --------------- */
%type <node> AbbrevForwardStep
%type <node> AdditiveExpr
%type <node> AndExpr
%type <node> AnyKindTest
%type <node> AposAttrContentList
%type <node> AposAttrValueContent
%type <node> ArgList
%type <node> AtomicType
%type <node> AttribNameOrWildcard
%type <node> AttributeDeclaration
%type <node> AttributeName
%type <node> AttributeTest
%type <node> AxisStep
%type <node> BaseURIDecl
%type <node> BoundarySpaceDecl
%type <node> CDataSection
%type <node> CaseClause
%type <node> CaseClauseList
%type <node> CastExpr
%type <node> CastableExpr
%type <node> CommentTest
%type <node> CommonContent
%type <node> CompAttrConstructor
%type <node> CompCommentConstructor
%type <node> CompDocConstructor
%type <node> CompElemConstructor
%type <node> CompPIConstructor
%type <node> CompTextConstructor
%type <node> ComparisonExpr
%type <node> ComputedConstructor
%type <node> ConstructionDecl
%type <node> Constructor
%type <node> ContentExpr
%type <node> ContextItemExpr
%type <node> CopyNamespacesDecl
%type <node> DefaultCollationDecl
%type <node> DefaultNamespaceDecl
%type <node> DirAttr
%type <node> DirAttributeList
%type <node> DirAttributeValue
%type <node> DirCommentConstructor
%type <node> DirElemConstructor
%type <node> DirElemContent
%type <node> DirElemContentList
%type <node> DirPIConstructor
%type <node> DirectConstructor
%type <node> DocumentTest
%type <node> ElementDeclaration
%type <node> ElementName
%type <node> ElementNameOrWildcard
%type <node> ElementTest
%type <node> EmptyOrderDecl
%type <node> EnclosedExpr
%type <node> ExtensionExpr
%type <node> FilterExpr
%type <node> ForLetClause
%type <node> ForLetClauseList
%type <node> ForwardAxis
%type <node> ForwardStep
%type <node> FunctionCall
%type <node> FunctionDecl
%type <node> IfExpr
%type <node> Import
%type <node> InheritMode
%type <node> InstanceofExpr
%type <node> IntersectExceptExpr
%type <node> ItemType
%type <node> KindTest
%type <node> LetClause
%type <node> LibraryModule
%type <node> Literal
%type <node> MainModule 
%type <node> Module
%type <node> ModuleDecl
%type <node> ModuleImport
%type <node> MultiplicativeExpr
%type <node> NameTest
%type <node> NamespaceDecl
%type <node> NodeTest
%type <node> NumericLiteral
%type <node> OccurrenceIndicator
%type <node> OptionDecl
%type <node> OrExpr
%type <node> OrderByClause
%type <node> OrderCollationSpec
%type <node> OrderDirSpec
%type <node> OrderModifier
%type <node> OrderSpec
%type <node> OrderSpecList
%type <node> OrderedExpr
%type <node> OrderingModeDecl
%type <node> PITest
%type <node> Param
%type <node> ParamList
%type <node> ParenthesizedExpr
%type <node> PathExpr
%type <node> PositionalVar
%type <node> Pragma
%type <node> PragmaList
%type <node> Predicate
%type <node> PredicateList
%type <node> PreserveMode
%type <node> PrimaryExpr
%type <node> Prolog
%type <node> QVarInDecl
%type <node> QVarInDeclList
%type <node> QueryBody
%type <node> QuoteAttrValueContent
%type <node> QuoteAttrContentList
%type <node> RelativePathExpr
%type <node> ReverseAxis
%type <node> ReverseStep
%type <node> SIND_Decl
%type <node> SIND_DeclList
%type <node> SchemaAttributeTest
%type <node> SchemaElementTest
%type <node> SchemaImport
%type <node> SchemaPrefix
%type <node> SequenceType
%type <node> Setter
%type <node> SignList
%type <node> SingleType
%type <node> StepExpr
%type <node> TextTest
%type <node> TreatExpr
%type <node> TypeDeclaration
%type <node> TypeName
%type <node> TypeswitchExpr
%type <node> UnaryExpr
%type <node> UnionExpr
%type <node> UnorderedExpr
%type <node> ValidateExpr
%type <node> ValueExpr
%type <node> VarDecl
%type <node> VarGetsDecl
%type <node> VarInDecl
%type <node> VarInDeclList
%type <node> VarRef
%type <node> VersionDecl
%type <node> VFO_Decl
%type <node> VFO_DeclList
%type <node> WhereClause
%type <node> Wildcard

%type <node> ExprSingle
%type <node> FLWORExpr
%type <node> QuantifiedExpr
%type <node> ForClause


/* update-related */
/* -------------- */
%type <node> DeleteExpr
%type <node> InsertExpr
%type <node> RenameExpr
%type <node> ReplaceExpr
%type <node> RevalidationDecl
%type <node> TransformExpr
%type <node> VarNameList


/* full-text-related */
/* ----------------- */
%type <node> FTAnd
%type <node> FTAnyallOption
%type <node> FTBigUnit
%type <node> FTCaseOption
%type <node> FTContainsExpr
%type <node> FTContent
%type <node> FTDiacriticsOption
%type <node> FTDistance
%type <node> FTIgnoreOption
%type <node> FTInclExclStringLiteral
%type <node> FTInclExclStringLiteralList
%type <node> FTLanguageOption
%type <node> FTMatchOption
%type <node> FTMatchOptionProximityList
%type <node> FTMildnot
%type <node> FTOptionDecl
%type <node> FTOr
%type <node> FTOrderedIndicator
%type <node> FTProximity
%type <node> FTRange
%type <node> FTRefOrList
%type <node> FTScope
%type <node> FTScoreVar
%type <node> FTSelection
%type <node> FTStemOption
%type <node> FTStopwordOption
%type <node> FTStringLiteralList
%type <node> FTThesaurusID
%type <node> FTThesaurusList
%type <node> FTThesaurusOption
%type <node> FTTimes
%type <node> FTUnaryNot
%type <node> FTUnit
%type <node> FTWildCardOption
%type <node> FTWindow
%type <node> FTWords
%type <node> FTWordsSelection
%type <node> FTWordsValue


/*_____________________________________________________________________
 *
 *  Precedence
 *_____________________________________________________________________*/

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [48a] FTContainsExpr ::= RangeExpr ( "ftcontains" FTSelection FTIgnoreOption? )?
 *_____________________________________________________________________*/
%nonassoc FTCONTAINS_REDUCE
%left FTCONTAINS 

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [49] RangeExpr ::= AdditiveExpr ( "to" AdditiveExpr )?
 *_____________________________________________________________________*/
%nonassoc RANGE_REDUCE
%nonassoc TO

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [50] AdditiveExpr ::= MultiplicativeExpr ( ("+" | "-") MultiplicativeExpr )*
 *_____________________________________________________________________*/
%nonassoc ADDITIVE_REDUCE
%left PLUS MINUS

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [51] MultiplicativeExpr ::= UnionExpr ( ("*" | "div" | "idiv" | "mod") UnionExpr )*
 *_____________________________________________________________________*/
%nonassoc MULTIPLICATIVE_REDUCE
%left STAR DIV IDIV MOD

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [52] UnionExpr ::= IntersectExceptExpr ( ("union" | "|") IntersectExceptExpr )*
 *_____________________________________________________________________*/
%nonassoc UNION_REDUCE
%left UNION VBAR

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [53] IntersectExceptExpr ::= InstanceofExpr ( ("intersect" | "except") InstanceofExpr )*
 *_____________________________________________________________________*/
%nonassoc INTERSECT_EXCEPT_REDUCE
%left INTERSECT EXCEPT

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [42a] QVarInDeclList ::= QVarInDecl ( "," "$" QVarInDeclList )*
 *_____________________________________________________________________*/
%nonassoc QVARINDECLLIST_REDUCE
%left COMMA_DOLLAR 

%nonassoc  UNARY_PREC

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [119] SequenceType ::= ItemType | ItemType OccurrenceIndicator
 *_____________________________________________________________________*/
%nonassoc SEQUENCE_TYPE_REDUCE
%nonassoc  HOOK 

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [69] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*
 *_____________________________________________________________________*/
%nonassoc STEP_REDUCE
%left SLASH SLASH_SLASH


/*
	To enable memory deallocation during error recovery, use %destructor.
*/
/*%printer    { debug_stream() << *$$; }	*/
/*%printer    { debug_stream () << $$; }	*/
/*%destructor { delete $$; }              */


/*
	The grammar
*/

%{
using namespace xqp;
%}

%%
%start Module;


/*______________________________________________________________________

	Code pattern:

	NonTerminal1  TOKEN  NonTerminal2
		{
			NonTerminal* nt1_p = dynamic_cast<NonTerminal1*>(&$1);
				// &$1 returns the pointer within rchandle<exprparsenode> $1
			nt1_p->push_back(dynamic_cast<NonTerminal2*>(&$2));
				// &$2 returns the pointer within rchandle<exprparsenode> $2
				// push_back() arg gets coerced to rchandle<NonTerminal2>
			$$ = nt1_p;
				// operator=() arg gets coerced to rchandle<NonTerminal1>
		}
  ______________________________________________________________________*/


// [1] Module
// ----------
Module :
    MainModule
		{
			$$ = $1;
		}
  | VersionDecl MainModule
		{
		}
  | LibraryModule 
		{
		}
  | VersionDecl LibraryModule 
		{
		}
  ;


// [2] VersionDecl
// ---------------
VersionDecl :
		XQUERY_VERSION  STRING_LITERAL  SEMI
		{
		}
	|	XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
		}
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
		}
  ;


// [4] LibraryModule
// -----------------
LibraryModule :
		ModuleDecl  Prolog
		{
		}
	;


// [5] ModuleDecl
// --------------
ModuleDecl :
		MODULE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
		}
	;


// [6] Prolog
// ----------
Prolog :
		SIND_DeclList  VFO_DeclList
		{
		}
	;


// [6a] SIDN_DeclList
// ------------------
SIND_DeclList :
		SIND_Decl
		{
			$$ = new SIND_DeclList(dynamic_cast<SIND_Decl*>($1));
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
			SIND_DeclList* sindList_p = dynamic_cast<SIND_DeclList*>($1);
			sindList_p->push_back(dynamic_cast<SIND_Decl*>($3));
			$$ = sindList_p;
		}
	;


// [6b] VFO_DeclList
// -----------------
VFO_DeclList :
		VFO_Decl
		{
			$$ = new VFO_DeclList(dynamic_cast<VFO_Decl*>($1));
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>($1);
			vfoList_p->push_back(dynamic_cast<VFO_Decl*>($3));
			$$ = vfoList_p;
		}
	;


// [6c] SIND_Decl
// --------------
SIND_Decl :
		Setter								{ $$ = $1; }
	| Import								{ $$ = $1; }
	| NamespaceDecl					{ $$ = $1; }
	| DefaultNamespaceDecl	{ $$ = $1; }
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl								{ $$ = $1; }
	| FunctionDecl					{ $$ = $1; }
	| OptionDecl						{ $$ = $1; }
	
	/* full-text extension */
	| FTOptionDecl					{ $$ = $1; }
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl			{ $$ = $1; }
	| DefaultCollationDecl	{ $$ = $1; }
	| BaseURIDecl						{ $$ = $1; }
	| ConstructionDecl			{ $$ = $1; }
	| OrderingModeDecl			{ $$ = $1; }
	| EmptyOrderDecl				{ $$ = $1; }
	| CopyNamespacesDecl		{ $$ = $1; }

	/* update extension */
	| RevalidationDecl			{ $$ = $1; }
	;


// [8] Import
// ----------
Import :
		SchemaImport					{ $$ = $1; }
	| ModuleImport					{ $$ = $1; }
	;


// [9] Separator
// -------------
// (= SEMI)


// [10] NamespaceDecl
// ------------------
NamespaceDecl :
		DECLARE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE_BOUNDARY_SPACE  PRESERVE
		{
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE_OPTION  QNAME  STRING_LITERAL
		{
		}
	;


/* full-text extension */
// [13a] OptionDecl
// ---------------
FTOptionDecl :
		DECLARE_FTOPTION  QNAME  FTMatchOption
		{
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
		}
	| DECLARE_ORDERING  UNORDERED
		{
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
		{
		}
	;


// [17] PreserveMode
// -----------------
PreserveMode :
		PRESERVE
		{
		}
	| NO_PRESERVE
		{
		}
	;


// [18] InheritMode
// ----------------
InheritMode :
		INHERIT
		{
		}
	| NO_INHERIT
		{
		}
	;


// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl :
		DECLARE_DEFAULT_COLLATION  URI_LITERAL
		{
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE_BASE_URI  URI_LITERAL
		{
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT_SCHEMA  URI_LITERAL
		{
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URI_LITERALList
		{
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URI_LITERALList
		{
		}
	;


// [21a] URLLiteralList
// --------------------
URI_LITERALList :
		URI_LITERAL
		{
		}
	| URI_LITERALList  COMMA  URI_LITERAL
		{
		}
	;



// [22] SchemaPrefix
// -----------------
SchemaPrefix :
		NAMESPACE  NCNAME  EQUALS
		{
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT_MODULE  URI_LITERAL 
		{
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URI_LITERALList
		{
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URI_LITERALList
		{
		}
	;



// [24] VarDecl
// ------------
VarDecl :
		DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE_CONSTRUCTION  PRESERVE
		{
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
		}
	;


// [26] FunctionDecl
// -----------------
FunctionDecl :
		DECLARE_FUNCTION  QNAME  LPAR  RPAR  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  RPAR  AS  SequenceType  EnclosedExpr
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EXTERNAL
		{
		}
	|	DECLARE_FUNCTION  QNAME  LPAR  ParamList  RPAR  AS  SequenceType  EnclosedExpr
		{
		}
	;



// [27] ParamList
// --------------
ParamList :
		Param
		{
		}
	|	ParamList  COMMA  Param
		{
		}
	;


// [28] Param
// ----------
Param :
		DOLLAR  VARNAME
		{
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
		}
	;


// [29] EnclosedExpr
// -----------------
EnclosedExpr :
		LBRACE  Expr  RBRACE
		{
		}
	;


// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
		}
	|	Expr  COMMA  ExprSingle
		{
		}
	;


// [32] ExprSingle
// ---------------
ExprSingle :
		FLWORExpr
		{
			$$ = $1;
		}
	|	QuantifiedExpr
		{
			$$ = $1;
		}
	|	TypeswitchExpr
		{
			$$ = $1;
		}
	|	IfExpr
		{
			$$ = $1;
		}
	|	OrExpr
		{
			$$ = $1;
		}

		/* update extensions */
	| InsertExpr
		{
			$$ = $1;
		}
	| DeleteExpr
		{
			$$ = $1;
		}
	| RenameExpr
		{
			$$ = $1;
		}
	| ReplaceExpr
		{
			$$ = $1;
		}
	| TransformExpr
		{
			$$ = $1;
		}
	;


// [33] FLWORExpr
// --------------
FLWORExpr :
	  ForLetClauseList  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
		}
	;


// [33a] ForLetClauseList
// ----------------------
ForLetClauseList :
		ForLetClause
		{
		}
	|	ForLetClause  ForLetClauseList
		{
		}
	;


// [33b] ForLetClause
// ------------------
ForLetClause :
		ForClause
		{
			$$ = $1;
		}
	|	LetClause
		{
			$$ = $1;
		}
	;


// [34] ForClause
// --------------
ForClause :
		FOR_DOLLAR  VarInDeclList
		{
		}
	;


// [34a] VarInDeclList
// -------------------
VarInDeclList :
		VarInDecl
		{
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
		}
	;


// [34b] VarInDecl
// ---------------
VarInDecl :
		VARNAME  IN  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle
		{
		}
	|	VARNAME  PositionalVar  IN  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
		{
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  IN  ExprSingle
		{
		}
	| VARNAME  TypeDeclaration  FTScoreVar  IN  ExprSingle
		{
		}
	| VARNAME  PositionalVar  FTScoreVar  IN  ExprSingle
		{
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  IN  ExprSingle
		{
		}
	;


// [35] PositionalVar
// ------------------
PositionalVar :
		AT  DOLLAR  VARNAME
		{
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  VARNAME
		{
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET_DOLLAR VarGetsDeclList
		{
		}
	;


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList :
		VarGetsDecl
		{
		}
	|	VarGetsDeclList  COMMA_DOLLAR  VarGetsDecl
		{
		}
	;


// [36b] VarGetsDecl
// ------------------
VarGetsDecl :
		VARNAME  GETS  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
		}
	|	VARNAME  PositionalVar  GETS  ExprSingle
		{
		}
	|	VARNAME  TypeDeclaration  PositionalVar  GETS  ExprSingle
		{
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
		}
	| VARNAME  PositionalVar  FTScoreVar  GETS  ExprSingle
		{
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  GETS  ExprSingle
		{
		}
	;


// [37] WhereClause
// ----------------
WhereClause :
		WHERE  ExprSingle
		{
		}
	;


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER_BY  OrderSpecList
		{
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
		}
	;


// [39] OrderSpecList
// ------------------
OrderSpecList :
		OrderSpec 
		{
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
		}
	;


// [40] OrderSpec
// --------------
OrderSpec :
		ExprSingle
		{
		}
	|	ExprSingle OrderModifier
		{
		}
	;


// [41] OrderModifier
// ------------------
OrderModifier :
		OrderDirSpec
		{
		}
	|	OrderEmptySpec
		{
		}
	|	OrderCollationSpec
		{
		}
	|	OrderDirSpec  OrderEmptySpec
		{
		}
	|	OrderDirSpec  OrderCollationSpec
		{
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
		}
	;


// [41a] OrderDirSpec
// ------------------
OrderDirSpec :
		ASCENDING
		{
		}
	|	DESCENDING
		{
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
		}
	|	EMPTY_LEAST
		{
		}
	;


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec :
		COLLATION  URI_LITERAL
		{
		}
	;


// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr :
		SOME_DOLLAR  QVarInDeclList
		{
		}
	|	EVERY_DOLLAR  QVarInDeclList
		{
		}
	;


// [42a] QVarInDeclList
// --------------------
QVarInDeclList :
		QVarInDecl  %prec QVARINDECLLIST_REDUCE
		{
		}
	|	QVarInDecl  COMMA_DOLLAR  QVarInDeclList
		{
		}
	;


// [42b] QVarInDecl
// ----------------
QVarInDecl :
		VARNAME  IN  ExprSingle 
		{
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle 
		{
		}
	;


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
		}
	;


// [43a] CaseClauseList
// --------------------
CaseClauseList :
		CaseClause
		{
		}
	|	CaseClauseList  CaseClause
		{
		}
	;


// [44] CaseClause
// ---------------
CaseClause :
		CASE  SequenceType  RETURN  ExprSingle
		{
		}
		CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
		}
	;


// [45] IfExpr
// -----------
IfExpr :
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
		}
	;


// [46] OrExpr
// -----------
OrExpr :
		AndExpr
		{
		}
	|	OrExpr  OR  AndExpr
		{
		}
	;


// [47] AndExpr
// ------------
AndExpr :
		ComparisonExpr
		{
		}
	|	AndExpr  AND  ComparisonExpr
		{
		}
	;


// [48] ComparisonExpr
// -------------------
/* replaced by full-text extension productions */
//ComparisonExpr : RangeExpr | ValueCompExpr | GeneralCompExpr | NodeCompExpr



/* full-text extension */
//[48] ComparisonExpr
//-------------------
ComparisonExpr :
		FTContainsExpr
		{
		}
	| FTContainsExpr  VALUECOMP  FTContainsExpr
		{
		}
	| FTContainsExpr  GENERALCOMP  FTContainsExpr
		{
		}
	| FTContainsExpr  NODECOMP  FTContainsExpr
		{
		}
	;


//[48a] FTContainsExpr
//-------------------
FTContainsExpr :
		RangeExpr  %prec FTCONTAINS_REDUCE
		{
		}
	|	RangeExpr  FTCONTAINS  FTSelection 
		{
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
		}
	;


// [49] RangeExpr
// --------------
RangeExpr :
		AdditiveExpr  %prec RANGE_REDUCE
		{
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr  %prec ADDITIVE_REDUCE
		{
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
		}
	;


// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr :
		UnionExpr  %prec MULTIPLICATIVE_REDUCE
		{
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
		}
	;


// [52] UnionExpr
// --------------
UnionExpr :
		IntersectExceptExpr  %prec UNION_REDUCE
		{
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
		}
	;


// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr :
		InstanceofExpr  %prec INTERSECT_EXCEPT_REDUCE
		{
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
		}
	;


// [54] InstanceofExpr
// -------------------
InstanceofExpr :
		TreatExpr
		{
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
		}
	;


// [55] TreatExpr
// --------------
TreatExpr :
		CastableExpr
		{
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
		}
	;


// [56] CastableExpr
// -----------------
CastableExpr :
		CastExpr
		{
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
		}
	;


// [57] CastExpr 	   
// -------------
CastExpr :
		UnaryExpr
		{
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
		}
	;


// [58] UnaryExpr
// --------------
UnaryExpr :
		ValueExpr
		{
		}
	|	SignList  ValueExpr
		{
		}
	;


// [58a] SignList
// --------------
SignList :
		PLUS
		{
		}
	|	MINUS
		{
		}
	|	SignList  PLUS
		{
		}
	|	SignList  MINUS
		{
		}
	;


// [59] ValueExpr
// --------------
ValueExpr :
		ValidateExpr
		{
		}
	|	PathExpr
		{
		}
	|	ExtensionExpr
		{
		}
	;



// [60] GeneralComp
// ----------------
/* lexical rule */

// [61] ValueComp
// --------------
/* lexical rule */

// [62] NodeComp
// -------------
/* lexical rule */



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
		}
	;


// [64] ExtensionExpr
// ------------------
ExtensionExpr :
		PragmaList  LBRACE  RBRACE
		{
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
		}
	;


// [64a] PragmaList
// ----------------
PragmaList :
		Pragma
		{
		}
	|	PragmaList  Pragma
		{
		}
	;


// [65] Pragma
// -----------
Pragma :
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL  PRAGMA_END
		{
		}
	;	/* ws: explicit */


// [66] PragmaContents
// -------------------
/* folded into [65] */


/*
* Constraint: leading-lone-slash
*
* A single slash may appear either as a complete path expression or as the first
* part of a path expression in which it is followed by a RelativePathExpr, which
* can take the form of a NameTest ("*" or a QName). In contexts where operators
* like "*", "union", etc., can occur, parsers may have difficulty distinguishing
* operators from NameTests. For example, without lookahead the first part of the
* expression "/ * 5", for example is easily taken to be a complete expression,
* "/ *", which has a very different interpretation (the child nodes of "/").
* 
* To reduce the need for lookahead, therefore, if the token immediately following
* a slash is "*" or a keyword, then the slash must be the beginning, but not the
* entirety, of a PathExpr (and the following token must be a NameTest, not an
* operator).
* 
* A single slash may be used as the left-hand argument of an operator by
* parenthesizing it: (/) * 5. The expression 5 * /, on the other hand, is legal
* without parentheses.
*/

// [67] PathExpr
// -------------
PathExpr :
		LEADING_LONE_SLASH
		{
		}
	|	SLASH  RelativePathExpr
		{
		}
	|	SLASH_SLASH  RelativePathExpr
		{
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
		}
	|	StepExpr  SLASH  RelativePathExpr 
		{
		}
	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
		}
	;


// [69] StepExpr
// -------------
StepExpr :
		AxisStep
		{
		}
	|	FilterExpr
		{
		}
	;


// [70] AxisStep
// -------------
AxisStep :
		ForwardStep 
		{
		}
	|	ForwardStep  PredicateList
		{
		}
	|	ReverseStep
		{
		}
	|	ReverseStep  PredicateList
		{
		}
	;


// [71] ForwardStep
// ----------------
ForwardStep :
		ForwardAxis  NodeTest
		{
		}
	|	AbbrevForwardStep
		{
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
		}
	| DESCENDANT_AXIS
		{
		}
	| ATTRIBUTE_AXIS
		{
		}
	| SELF_AXIS
		{
		}
	| DESCENDANT_OR_SELF_AXIS
		{
		}
	| FOLLOWING_SIBLING_AXIS
		{
		}
	| FOLLOWING_AXIS
		{
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
		}
	|	AT_SIGN  NodeTest
		{
		}
	;


// [74] ReverseStep
// ----------------
ReverseStep :
		ReverseAxis  NodeTest
		{
		}
	|	DOT_DOT
		{
		}
	;


// [75] ReverseAxis
// ----------------
ReverseAxis :
		PARENT_AXIS
		{
		}
	| ANCESTOR_AXIS
		{
		}
	| PRECEDING_SIBLING_AXIS
		{
		}
	| PRECEDING_AXIS
		{
		}
	| ANCESTOR_OR_SELF_AXIS
		{
		}
	;


// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */


// [77] NodeTest
// -------------
NodeTest :
		KindTest
		{
		}
	|	NameTest
		{
		}
	;
 

// [78] NameTest
// -------------
NameTest :
		QNAME
		{
		}
	|	Wildcard
		{
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
		}
	|	ELEM_WILDCARD
		{
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr  PredicateList
		{
		}
	;


// [81] PredicateList
// ------------------
PredicateList :
		Predicate
		{
		}
	|	PredicateList  Predicate
		{
		}
	;


// [82] Predicate
// --------------
Predicate :
		LBRACK  Expr  RBRACK
		{
		}
	;



// [83] PrimaryExpr
// ----------------
PrimaryExpr :
		Literal
		{
			$$ = $1;
		}
	|	VarRef
		{
			$$ = $1;
		}
	|	ParenthesizedExpr
		{
			$$ = $1;
		}
	|	ContextItemExpr
		{
			$$ = $1;
		}
	|	FunctionCall
		{
			$$ = $1;
		}
	|	Constructor
		{
			$$ = $1;
		}
	|	OrderedExpr
		{
			$$ = $1;
		}
	|	UnorderedExpr
		{
			$$ = $1;
		}
	;


// [84] Literal
// ------------
Literal :
		NumericLiteral
		{
		}
	|	STRING_LITERAL
		{
		}
	;


// [85] NumericLiteral
// -------------------
NumericLiteral :
		INTEGER_LITERAL
		{
		}
	|	DECIMAL_LITERAL
		{
		}
	|	DOUBLE_LITERAL
		{
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
		}
	|	LPAR  Expr  RPAR
		{
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
		}
	;


// [91] FunctionCall
// -----------------
FunctionCall :
		QNAME_LPAR  ArgList  RPAR 	/* gn: parensXQ */
		{
		}
				/* gn: reserved-function-namesXQ */
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
		}
	|	ArgList  COMMA  ExprSingle
		{
		}
	;


// [92] Constructor
// ----------------
Constructor :
		DirectConstructor
		{
		}
	|	ComputedConstructor
		{
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
		}
	|	DirCommentConstructor
		{
		}
	|	DirPIConstructor
		{
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  DirAttributeList SGT /* ws: explicitXQ */
		{
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
		}
			/* ws: explicitXQ */
			/* gn: ltXQ */
	;


// [94a] DirElemContentList
// ------------------------
DirElemContentList :
		DirElemContent
		{
		}
	|	DirElemContentList  DirElemContent
		{
		}
	;


// [95] DirAttributeList
// ---------------------
DirAttributeList :
		DirAttr
		{
		}
	|	DirAttributeList  DirAttr
		{
		}
	;


// [95a] DirAttr
// -------------
DirAttr :
		QNAME  EQUALS  DirAttributeValue 	/* ws: explicitXQ */
		{
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  QuoteAttrContentList  QUOTE
		{
		}
	|	APOS  AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList :
		ESCAPE_QUOTE
		{
		}
	|	QuoteAttrValueContent
		{
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
		}
	;


// [96b] AposAttrContentList
// -------------------------
AposAttrContentList :
		ESCAPE_APOS
		{
		}
	|	AposAttrValueContent
		{
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
		}
	|	AposAttrContentList  AposAttrValueContent
		{
		}
	;


// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent :
		QUOTE_ATTR_CONTENT
		{
		}
	|	CommonContent
		{
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
		}
	|	CommonContent
		{
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
		}
	|	ELEMENT_CONTENT
		{
		}
	|	CDataSection
		{
		}
	|	CommonContent
		{
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
		ENTITY_REF
		{
		}
	|	CHAR_REF_LITERAL
		{
		}
	|	DOUBLE_LBRACE
		{
		}
	|	DOUBLE_RBRACE
		{
		}
	|	EnclosedExpr
		{
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		COMMENT_BEGIN  EXPR_COMMENT_LITERAL  COMMENT_END 	/* ws: explicitXQ */
		{
		}
	;


// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
DirPIConstructor :
		PI_BEGIN  PI_TARGET  PI_END 	/* ws: explicitXQ */
		{
		}
	|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
		}
	;


// [104] DirPIContents
// -------------------
/* lexical rule */


// [105] CDataSection
// ------------------
CDataSection :
		CDATA_BEGIN  CHAR_LITERAL  CDATA_END 	/* ws: explicitXQ */
		{
		}
	;


// [106] CDataSectionContents
// --------------------------
/* lexical rule */


// [107] ComputedConstructor
// -------------------------
ComputedConstructor :
		CompDocConstructor
		{
			$$ = $1;
		}
	|	CompElemConstructor
		{
			$$ = $1;
		}
	|	CompAttrConstructor
		{
			$$ = $1;
		}
	|	CompTextConstructor
		{
			$$ = $1;
		}
	|	CompCommentConstructor
		{
			$$ = $1;
		}
	|	CompPIConstructor
		{
			$$ = $1;
		}
	;


// [108] CompDocConstructor
// ------------------------
CompDocConstructor :
		DOCUMENT_LBRACE  Expr  RBRACE
		{
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
		}
	|	ELEMENT_QNAME_LBRACE  ContentExpr  RBRACE
		{
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  ContentExpr  RBRACE
		{
		}
	;


// [110] ContentExpr
// -----------------
ContentExpr :
		Expr
		{
		}
	;


// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor :
		ATTRIBUTE  QNAME  LBRACE  RBRACE
		{
		}
	|	ATTRIBUTE  QNAME  LBRACE  Expr  RBRACE
		{
		}
	|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
		}
	|	ATTRIBUTE  LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
		}
	|	AtomicType  HOOK
		{
		}
	;


// [116] TypeDeclaration
// ---------------------
TypeDeclaration :
		AS  SequenceType
		{
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
		}
	|	ItemType OccurrenceIndicator
		{
		}
	|	VOID_TEST
		{
		}
	;


// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator :
		HOOK
		{
		}
	|	STAR
		{
		}
	|	PLUS 	/* gn: occurrence-indicatorsXQ */
		{
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
		}
	|	KindTest
		{
		}
	|	ITEM_TEST
		{
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
		}
	;


// [121] KindTest
// --------------
KindTest :
		DocumentTest
		{
			$$ = $1;
		}
	| ElementTest
		{
			$$ = $1;
		}
	| AttributeTest
		{
			$$ = $1;
		}
	| SchemaElementTest
		{
			$$ = $1;
		}
	| SchemaAttributeTest
		{
			$$ = $1;
		}
	| PITest
		{
			$$ = $1;
		}
	| CommentTest
		{
			$$ = $1;
		}
	| TextTest
		{
			$$ = $1;
		}
	| AnyKindTest
		{
			$$ = $1;
		}
	;


// [122] AnyKindTest
// -----------------
AnyKindTest :
		NODE_LPAR  RPAR
		{
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
		}
	|	PI_LPAR  NCNAME  RPAR
		{
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
		{
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
		{
		}
	;


// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard :
		AttributeName
		{
		}
	|	STAR
		{
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  AttributeDeclaration  RPAR
		{
		}
	;


// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration :
		AttributeName
		{
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR
		{
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR
		{
		}
	;


// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard :
		ElementName
		{
		}
	|	STAR
		{
		}
	;


// [133] SchemaElementTest
// -----------------------
SchemaElementTest :
		SCHEMA_ELEMENT_LPAR  ElementDeclaration  RPAR
		{
		}
	;


// [134] ElementDeclaration
// ------------------------
ElementDeclaration :
		ElementName
		{
		}
	;


// [135] AttributeName
// -------------------
AttributeName :
		QNAME
		{
		}
	;


// [136] ElementName
// -----------------
ElementName :
		QNAME
		{
		}
	;


// [137] TypeName
// --------------
TypeName :
		QNAME
		{
		}
	;


/* lexical rules, see xquery.l */
/* --------------------------- */

// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 
// [142] StringLiteral
// [143] PITarget
// [144] VarName
// [145] ValidationMode
// [146] Digits
// [147] PredefinedEntityRef
// [148] CharRef
// [149] EscapeQuot
// [150] EscapeApos
// [151] ElementContentChar
// [152] QuotAttrContentChar
// [153] AposAttrContentChar
// [154] Comment
// [155] CommentContents
// [156] QName
// [157] NCName
// [158] S  (WS)
// [159] Char


/*_______________________________________________________________________
 *                                                                       *
 *  Update productions                                                   *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/


// [241]	RevalidationDecl
// ----------------------
RevalidationDecl :
		DECLARE_REVALIDATION_MODE
		{
		}
	;


// [242]	InsertExpr
// ----------------
InsertExpr :
		DO_INSERT  ExprSingle  INTO  ExprSingle
		{
		}
	|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
		{
		}
	|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
		{
		}
	| DO_INSERT  ExprSingle  AFTER  ExprSingle
		{
		}
	| DO_INSERT  ExprSingle  BEFORE  ExprSingle
		{
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		DO_DELETE  ExprSingle
		{
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		DO_REPLACE  ExprSingle  WITH  ExprSingle
		{
		}
	|	DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
		{
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		DO_RENAME  ExprSingle  AS  ExprSingle
		{
		}
	;


// [246] SourceExpr
// ----------------
// folded


// [247] TargetExpr
// ----------------
// folded


// [248] NewNameExpr
// -----------------
// folded into [245] RenameExpr


// [249] TransformExpr
// -------------------
TransformExpr :
		TRANSFORM_COPY_DOLLAR  VarNameList  MODIFY  ExprSingle  RETURN  ExprSingle
		{
		}
	;


// [249a] VarNameList
// ------------------
VarNameList :
		VARNAME	 GETS  ExprSingle
		{
		}
	|	VarNameList  COMMA_DOLLAR  VARNAME  GETS  ExprSingle
		{
		}
	;


/*_______________________________________________________________________
 *                                                                       *
 *  Full-text productions                                                *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/


//[344] FTSelection
//-----------------
FTSelection :
		FTOr
		{
		}
	|	FTOr  FTMatchOptionProximityList
		{
		}
	|	FTOr  WEIGHT  RangeExpr
		{
		}
	|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
		{
		}
	;


//[344a] FTMatchOptionProximityList
//---------------------------------
FTMatchOptionProximityList :
		FTMatchOption
		{
		}
	| FTProximity
		{
		}
	| FTMatchOptionProximityList  FTMatchOption
		{
		}
	| FTMatchOptionProximityList  FTProximity
		{
		}
	;


//[345]	FTOr
//----------
FTOr :
		FTAnd
		{
		}
	|	FTOr  FTOR  FTAnd
		{
		}
	;


//[346]	FTAnd
//-----------
FTAnd :
		FTMildnot
		{
		}
	|	FTAnd  FTAND  FTMildnot
		{
		}
	;


//[347]	FTMildnot
//---------------
FTMildnot :
		FTUnaryNot
		{
		}
	|	FTMildnot  NOT_IN  FTUnaryNot
		{
		}
	;


//[348]	FTUnaryNot
//----------------
FTUnaryNot :
		FTWordsSelection
		{
		}
	|	FTNOT  FTWordsSelection
		{
		}
	;


//[349]	FTWordsSelection
//----------------------
FTWordsSelection :
		FTWords
		{
		}
	|	FTWords FTTimes
		{
		}
	| LPAR  FTSelection  RPAR
		{
		}
	;


//[350]	FTWords
//-------------
FTWords :
		FTWordsValue 
		{
		}
	|	FTWordsValue  FTAnyallOption
		{
		}
	;


//[351]	FTWordsValue
//------------------
FTWordsValue :
		Literal
		{
		}
	| LBRACE  Expr  RBRACE
		{
		}
	;


//[352]	FTProximity
//-----------------
FTProximity :
		FTOrderedIndicator
		{
		}
	| FTWindow
		{
		}
	| FTDistance
		{
		}
	| FTScope
		{
		}
	| FTContent
		{
		}
	;


//[353]	FTOrderedIndicator
//------------------------
FTOrderedIndicator :
		ORDERED
		{
		}
	;


//[354] FTMatchOption 	
//-------------------
FTMatchOption :
		FTCaseOption
		{
			$$ = $1;
		}
	| FTDiacriticsOption
		{
			$$ = $1;
		}
	| FTStemOption
		{
			$$ = $1;
		}
	| FTThesaurusOption
		{
			$$ = $1;
		}
	| FTStopwordOption
		{
			$$ = $1;
		}
	| FTLanguageOption
		{
			$$ = $1;
		}
	| FTWildCardOption
		{
			$$ = $1;
		}
	;


//[355] FTCaseOption
//------------------
FTCaseOption :
		LOWERCASE
		{
		}
	| UPPERCASE
		{
		}
	| CASE_SENSITIVE
		{
		}
	| CASE_INSENSITIVE
		{
		}
	;


//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption :
		WITH_DIACRITICS
		{
		}
	| WITHOUT_DIACRITICS
		{
		}
	| DIACRITICS_SENSITIVE
		{
		}
	| DIACRITICS_INSENSITIVE
		{
		}
	;


//[357] FTStemOption
//------------------
FTStemOption :
		WITH_STEMMING
		{
		}
	| WITHOUT_STEMMING
		{
		}
	;


//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption :
		WITH_THESAURUS  FTThesaurusID
		{
		}
	|	WITH_THESAURUS  DEFAULT
		{
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID  RPAR
		{
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
		{
		}
	| WITH_THESAURUS  LPAR  DEFAULT  RPAR
		{
		}
	| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
		{
		}
	| WITHOUT_THESAURUS
		{
		}
	;


//[358a] FTThesaurusIDList
//------------------------
FTThesaurusList :
		FTThesaurusID
		{
		}
	| FTThesaurusList  COMMA  FTThesaurusID
		{
		}
	;


//[359] FTThesaurusID
//-------------------
FTThesaurusID :
		AT  STRING_LITERAL
		{
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
		{
		}
	|	AT  STRING_LITERAL  FTRange  LEVELS
		{
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
		{
		}
	;


//[360] FTStopwordOption
//----------------------
FTStopwordOption :
		WITH_STOP_WORDS  FTRefOrList
		{
		}
		WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
		{
		}
	| WITH_DEFAULT_STOP_WORDS 
		{
		}
	| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
		{
		}
	| WITHOUT_STOP_WORDS
		{
		}
	;


//[360a] FTInclExclStringLiteralList
//----------------------------------
FTInclExclStringLiteralList :
		FTInclExclStringLiteral
		{
		}
	| FTInclExclStringLiteralList  FTInclExclStringLiteral
		{
		}
	;


//[361] FTRefOrList
//-----------------
FTRefOrList :
		AT  STRING_LITERAL
		{
		}
	| LPAR  FTStringLiteralList  RPAR 
		{
		}
	;


//[361a] FTStringLiteralList
//--------------------------
FTStringLiteralList :
		STRING_LITERAL
		{
		}
	|	FTStringLiteralList  STRING_LITERAL
		{
		}
	;


//[362] FTInclExclStringLiteral
//-----------------------------
FTInclExclStringLiteral :
		UNION  FTRefOrList
		{
		}
	|	EXCEPT  FTRefOrList
		{
		}
	;


//[363] FTLanguageOption
//----------------------
FTLanguageOption :
		LANGUAGE  STRING_LITERAL
		{
		}
	;


//[364] FTWildCardOption
//----------------------
FTWildCardOption :
		WITH_WILDCARDS
		{
		}
	| WITHOUT_WILDCARDS
		{
		}
	;


//[365]	FTContent
//---------------
FTContent :
		AT_START
		{
		}
	| AT_END
		{
		}
	| ENTIRE_CONTENT
		{
		}
	;


//[366]	FTAnyallOption
//--------------------
FTAnyallOption :
		ANY
		{
		}
	|	ANY_WORD
		{
		}
	| ALL
		{
		}
	| ALL_WORDS
		{
		}
	| PHRASE
		{
		}
	;


//[367]	FTRange
//-------------
FTRange :
		EXACTLY  UnionExpr
		{
		}
	| AT_LEAST  UnionExpr
		{
		}
	| AT_MOST  UnionExpr
		{
		}
	| FROM  UnionExpr  TO  UnionExpr
		{
		}
	;


//[368]	FTDistance
//----------------
FTDistance :
		DISTANCE  FTRange  FTUnit
		{
		}
	;


//[369]	FTWindow
//--------------
FTWindow :
		WINDOW  UnionExpr  FTUnit
		{
		}
	;


//[370]	FTTimes
//-------------
FTTimes :
		OCCURS  FTRange  TIMES
		{
		}
	;


//[371]	FTScope
//-------------
FTScope :
		SAME  FTBigUnit
		{
		}
	|	DIFFERENT  FTBigUnit
		{
		}
	;


//[372]	FTUnit
//------------
FTUnit :
		WORDS
		{
		}
	| SENTENCES
		{
		}
	| PARAGRAPH
		{
		}
	;


//[373]	FTBigUnit
//---------------
FTBigUnit :
		SENTENCE
		{
		}
	| PARAGRAPH
		{
		}
	;


//[374]	FTIgnoreOption
//--------------------
FTIgnoreOption :
		WITHOUT_CONTENT  UnionExpr
		{
		}
	;



%%



/*
	The error member function registers the errors to the driver.
*/

void yy::xquery_parser::error(
	yy::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.error(loc, msg);
}

