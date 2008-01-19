/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: xquery_parser.y,v 1.2 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *	Author: Paul Pedersen
 */


/*
**	The parser definition file starts by asking for the C++ LALR(1) 
**	skeleton, the creation of the parser header file, and specifies the 
**	name of the parser class.  Because the C++ skeleton changes, it is
**	safer to require the version. 
*/

%skeleton "lalr1.cc"  /*  -*- C++ -*- */
%require "2.3"
%defines
%define "parser_class_name" "xquery_parser"

/*
**	Because the parser uses the xquery_driver and reciprocally, both 
**	cannot include the header of the other. Because the driver's header 
**	needs detailed knowledge about the parser class (in particular its 
**	inner types), it is the parser's header which will use a forward
**	declaration of the driver. 
*/

%{

#include "zorba/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#ifndef _WIN32_WCE
#include <io.h>
#endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

//#include "context/static_context.h"
#include "zorba_api.h"
#include "context/dynamic_context.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"


using namespace std;
using namespace xqp;

namespace xqp {
	class xquery_driver;
	class parsenode;
	class exprnode;
}


%}

%pure-parser

/*
**	The driver is passed by reference to the parser and to the scanner. 
**	This provides a simple but effective pure interface, not relying on 
**	global variables. 
*/
%parse-param { xquery_driver& driver }
%parse-param { void* yyscanner }
%lex-param   { xquery_driver& driver } 
%lex-param   { void* yyscanner }


/*
**	Request the location tracking feature, and initialize the 
**	first location's file name. Afterwards new locations are computed 
**	relatively to the previous locations: the file name will be 
**	automatically propagated. 
*/
%locations
%initial-action
{
  @$.begin.filename = @$.end.filename = driver.filename.getStore();
};


/* 
**	The two following directives to enable parser tracing and verbose 
**	error messages. 
*/
/*
%debug
%error-verbose
*/

/*
%{
static void print_token_value(FILE *, int, YYSTYPE);
#define YYPRINT(file, type, value) print_token_value(file, type, value)
%}
*/


/*
**	Semantic values cannot use real objects, but only pointers to them.
*/
%union
{
  xqp::parsenode * node;
  xqp::exprnode * expr;
  off_t sval;
	int ival;
	double dval;
	long double decval;
};


/*
**	The code between `%{' and `%}' after the introduction of the `%union' 
**	is output in the *.cc file; it needs detailed knowledge about the 
**	driver. 
*/
%{
#include "compiler/parser/xquery_driver.h"
%}


/*
**	The token numbered as 0 corresponds to end of file; the following line 
**	allows for nicer error messages referring to end of file instead of 
**	$end. Similarly user friendly names are provided for each symbol.
*/

%token	END	0 "end of file"

/* tokens that contain embedded string literals */
/* -------------------------------------------- */
%token <sval> APOS_ATTR_CONTENT				"'apos attribute content'"
%token <sval> ATTRIBUTE_QNAME_LBRACE	"'<attribute QName {>'"
%token <sval> AT_URI_LITERAL					"'<at URI>'"
%token <sval> CHAR_LITERAL						"'char literal'"
%token <sval> CHAR_REF_LITERAL				"'#charref;'"
%token <sval> ELEMENT_CONTENT					"'element content'"
%token <sval> ELEMENT_QNAME_LBRACE		"'<QName {>'"
%token <sval> ELEM_WILDCARD						"'pref:*'"
%token <sval> ENTITY_REF							"'&entity;'"
%token <sval> EXPR_COMMENT_LITERAL		"'comment literal'"
%token <sval> NCNAME									"'NCName'"
%token <sval> PI_NCNAME_LBRACE				"'pi <NCName {>'"
%token <sval> PI_TARGET_LITERAL				"'pi target'"
%token <sval> PRAGMA_LITERAL					"'pragma literal'"
%token <sval> PREFIX_WILDCARD					"'*:QName'"
%token <sval> QNAME										"'QName'"
%token <sval> QNAME_LPAR							"'<QName (>'"
%token <sval> QUOTE_ATTR_CONTENT			"'quote attribute content'"
%token <sval> STRING_LITERAL					"'STRING'"
%token <sval> URI_LITERAL							"'URI'"
%token <sval> VARNAME									"'variable name'"
%token <sval> VALIDATE_MODE						"'validate mode'"
%token <sval> XML_COMMENT_LITERAL			"'XML comment'"


/* simple tokens */
/* ------------- */
%token ANCESTOR_AXIS							"'ancestor::'"
%token ANCESTOR_OR_SELF_AXIS			"'ancestor-or-self::'"
%token AND												"'and'"
%token APOS												"'''"
%token AS													"'as'"
%token ASCENDING									"'ascending'"
%token AT													"'at'"
%token ATTRIBUTE									"'attribute'"
%token ATTRIBUTE_AXIS							"'attribute::'"
%token ATTRIBUTE_LBRACE						"'<attribute {>'"
%token ATTRIBUTE_LPAR							"'<attribute (>'"
%token AT_SIGN										"'@'"
%token CASE												"'case'"
%token CASTABLE_AS								"'<castable as>'"
%token CAST_AS										"'<cast as>'"
%token CDATA_BEGIN								"'CDATA[['"
%token CDATA_END									"']]'"
%token CHILD_AXIS									"'child::'"
%token COLLATION									"'collation'"
%token COMMA											"','"
%token COMMENT_BEGIN							"'(:'"
%token COMMENT_END								"':)'"
%token COMMENT_LBRACE							"'<comment {>'"
%token COMMENT_LPAR								"'<comment (>'"
%token DECIMAL_LITERAL						"'DECIMAL'"
%token DECLARE_BASE_URI						"'<declare base URI>'"
%token DECLARE_BOUNDARY_SPACE			"'<declare boundary space>'"
%token DECLARE_CONSTRUCTION				"'<declare construction>'"
%token DECLARE_COPY_NAMESPACES		"'<declare copy namespaces>'"
%token DECLARE_DEFAULT_COLLATION	"'<declare default collation>'"
%token DECLARE_DEFAULT_ELEMENT		"'<declare default element>'"
%token DECLARE_DEFAULT_FUNCTION		"'<declare default function>'"
%token DECLARE_DEFAULT_ORDER			"'<declare default order>'"
%token DECLARE_FUNCTION						"'<declare function>'"
%token DECLARE_NAMESPACE					"'<declare namespace>'"
%token DECLARE_OPTION							"'<declare option>'"
%token DECLARE_ORDERING						"'<declare ordering>'"
%token DECLARE_UPDATING_FUNCTION	"'<declare updating function>'"
%token DECLARE_VARIABLE_DOLLAR		"'<declare var $>'"
%token DEFAULT										"'default'"
%token DEFAULT_ELEMENT						"'<default element>'"
%token DESCENDANT_AXIS						"'descendant::'"
%token DESCENDANT_OR_SELF_AXIS		"'descendant-or-self::'"
%token DESCENDING									"'descending'"
%token DIV												"'div'"
%token DOCUMENT_LBRACE						"'<document {>'"
%token DOCUMENT_NODE_LPAR					"'<document node (>'"
%token DOLLAR											"'$'"
%token DOT												"'.'"
%token DOT_DOT										"'..'"
%token DOUBLE_LBRACE							"'{{'"
%token DOUBLE_LITERAL							"'DOUBLE'"
%token DOUBLE_RBRACE							"'<double {>'"
%token ELEMENT_LBRACE							"'<element {>'"
%token ELEMENT_LPAR								"'<element (>'"
%token ELSE												"'else'"
%token EMPTY_GREATEST							"'<empty greatest>'"
%token EMPTY_LEAST								"'<empty least>'"
%token EMPTY_TAG_END							"'/>'"
%token ENCODING										"'encoding'"
%token EQUALS											"'='"
%token ESCAPE_APOS								"''''"
%token ESCAPE_QUOTE								"'\"\"'"
%token EVERY_DOLLAR								"'<every $>'"
%token EXCEPT											"'except'"
%token EXTERNAL										"'external'"
%token FOLLOWING_AXIS							"'following::'"
%token FOLLOWING_SIBLING_AXIS			"'following-sibling::'"
%token FOLLOWS										"'follows'"
%token FOR_DOLLAR									"'<for $>'"
%token GENERALCOMP								"'general comp'"
%token GE													"'>='"
%token GETS												"':='"
%token GT													"'>'"
%token HOOK												"'?'"
%token IDIV												"'idiv'"
%token IF_LPAR										"'<if (>'"
%token IMPORT_MODULE							"'<import module>"	
%token IMPORT_SCHEMA							"'<import schema>'"
%token _IN_													"'in'"
%token INHERIT										"'inherit'"
%token INSTANCE_OF								"'<instance of>'"
%token INTEGER_LITERAL						"'INTEGER'"
%token INTERSECT									"'intersect'"
%token IS													"'is'"
%token ITEM_TEST									"'item()'"
%token LBRACE											"'{'"
%token LBRACK											"'['"
%token LE													"'<='"
%token LEADING_LONE_SLASH					"'[ / ]'"
%token LET_DOLLAR									"'<let $>'"
%token LET_SCORE_DOLLAR	  				"'<let score $>'"
%token LPAR												"'('"
%token LT													"'<'"
%token MINUS											"'-'"
%token MOD												"'mod'"
%token MODULE_NAMESPACE						"'<module namespace>'"
%token NAMESPACE									"'namespace'"
%token _NAN												"'nan'"
%token NE													"'!='"
%token NODECOMP										"'nodecomp'"
%token NODE_LPAR									"'<node (>'"
%token NOT_OPERATOR_KEYWORD				"'??'"
%token NO_INHERIT									"'<no inherit>'"
%token NO_PRESERVE								"'<no preserve>'"
%token OCCURS_HOOK								"'occurs ?'"
%token OCCURS_PLUS								"'occurs +'"
%token OCCURS_STAR								"'occurs *'"
%token OR													"'or'"
%token ORDERED										"'ordered'"
%token ORDERED_LBRACE							"'ordered {'"
%token ORDER_BY										"'<order by>'"
%token PARENT_AXIS								"'parent::'"
%token PI_BEGIN										"'<?'"
%token PI_END											"'?>'"
%token PI_LBRACE									"'<pi {>'"
%token PI_LPAR										"'<pi (>'"
%token PI_TARGET									"'PI TARGET'"
%token PLUS												"'+'"
%token PRAGMA_BEGIN								"'PRAGMA BEGIN'"
%token PRAGMA_END									"'PRAGMA END'"
%token PRECEDES										"'<<'"
%token PRECEDING_AXIS							"'preceding::'"
%token PRECEDING_SIBLING_AXIS			"'preceding-sibling::'"
%token PRESERVE										"'preserve'"
%token PROCESSING_INSTRUCTION			"'processing instruction'"
%token QUOTE											"'\"'"
%token RBRACE											"'}'"
%token RBRACK											"']'"
%token RETURN											"'return'"
%token RPAR												"')'"
%token RPAR_AS										"'<) as>'"
%token SATISFIES									"'satisfies'"
%token SCHEMA_ATTRIBUTE_LPAR			"'<schema attribute ('"
%token SCHEMA_ELEMENT_LPAR				"'<schema element (>'"
%token SELF_AXIS									"'self::'"
%token SEMI												"';'"
%token SLASH											"'/'"
%token SLASH_SLASH								"'//'"
%token SOME_DOLLAR								"'<some $>'"
%token STABLE_ORDER_BY						"'<stable order by>'"
%token STAR												"'*'"
%token START_TAG_END							"'start tag end >'"
%token START_TAG									"'start tag <'"
%token STRIP											"'strip'"
%token TAG_END										"'</'"
%token TEXT_LBRACE								"'<text {>'"
%token TEXT_LPAR									"'<text (>'"
%token THEN												"'then'"
%token TO													"'to'"
%token TREAT_AS										"'<treat as>'"
%token TYPESWITCH_LPAR						"'<typeswitch (>'"
%token UNION											"'union'"
%token UNORDERED									"'unordered'"
%token UNORDERED_LBRACE						"'<unordered (>'"
%token UNRECOGNIZED								"'unrecognized'"
%token VAL_EQ											"'eq'"
%token VAL_GE											"'ge'"
%token VAL_GT											"'gt'"
%token VAL_LE											"'le'"
%token VAL_LT											"'lt'"
%token VAL_NE											"'ne'"
%token VALIDATE_LBRACE						"'<validate {>'"
%token VALUECOMP									"'VALUECOMP'"
%token VBAR												"'|'"
%token VOID_TEST									"'void()'"
%token WHERE											"'where'"
%token XML_COMMENT_BEGIN					"'<!--'"
%token XML_COMMENT_END						"'-->'"
%token XQUERY_VERSION							"'<XQuery Version>'"


/* update-related */
/* -------------- */
%token AFTER											"'after'"
%token BEFORE											"'before'"
%token COMMA_DOLLAR 							"'<, $>'"
%token DECLARE_REVALIDATION_MODE	"'<declare revalidation mode>'"
%token DO_DELETE									"'<do delete>'"
%token DO_INSERT									"'<do insert>'"
%token DO_RENAME									"'<do rename>'"
%token DO_REPLACE									"'<do replace>'"
%token FIRST_INTO									"'<first into>'"
%token INTO												"'into'"
%token LAST_INTO									"'<lastinto>'"
%token MODIFY 										"'modify'"
%token TRANSFORM_COPY_DOLLAR 			"'<transform copy $>'"
%token VALUE_OF										"'<value of>'"
%token WITH												"'with'"


/* full-text-related */
/* ----------------- */
%token ALL												"'all'"
%token ALL_WORDS									"'<all words>'"
%token ANY												"'any'"
%token ANY_WORD										"'<any words>'"
%token AT_END											"'<at end>'"
%token AT_LEAST										"'<at least>'"
%token AT_MOST										"'<at most>'"
%token AT_START										"'<at start>'"
%token CASE_INSENSITIVE						"'<case insensitive>'"
%token CASE_SENSITIVE							"'<casesensitive>'"
%token DECLARE_FTOPTION						"'<declare ftoption>'"
%token DIACRITICS_INSENSITIVE			"'<diacritics insensitive>'"
%token DIACRITICS_SENSITIVE				"'<diacritics sensitive>'"
%token DIFFERENT									"'different'"
%token DISTANCE										"'distance'"
%token ENTIRE_CONTENT							"'<entire content>'"
%token EXACTLY										"'exactly'"
%token FROM												"'from'"
%token FTAND											"'&&'"
%token FTCONTAINS 								"'ftcontains'"
%token FTNOT											"'ftnot'"
%token FTOR												"'||'"
%token LANGUAGE 									"'language'"
%token LEVELS											"'levels'"
%token LOWERCASE									"'lowercase'"
%token FTNOT_IN										"'<not in>'"
%token OCCURS											"'occurs'"
%token PARAGRAPH									"'paragraph'"
%token PHRASE											"'phrase'"
%token RELATIONSHIP								"'relationship'"
%token SAME												"'same'"
%token SCORE											"'score'"
%token SENTENCE										"'sentence'"
%token SENTENCES									"'sentences'"
%token TIMES											"'times'"
%token UPPERCASE									"'uppercase'"
%token WEIGHT											"'weight'"
%token WINDOW											"'window'"
%token WITHOUT_CONTENT						"'<without content>'"
%token WITHOUT_DIACRITICS					"'<without diacritics>'"
%token WITHOUT_STEMMING						"'<without stemming>'"
%token WITHOUT_STOP_WORDS					"'<without stop words>'"
%token WITHOUT_THESAURUS					"'<without thesaurus>'"
%token WITHOUT_WILDCARDS					"'<without wildcards>'"
%token WITH_DEFAULT_STOP_WORDS 		"'<with default stop words>'"
%token WITH_DIACRITICS						"'<with diacritics>'"
%token WITH_STEMMING							"'<with stemming>'"
%token WITH_STOP_WORDS 						"'<with stop words>'"
%token WITH_THESAURUS							"'<with thesaurus>'"
%token WITH_WILDCARDS							"'<with wildcards>'"
%token WORDS											"'words'"


/* left-hand sides: syntax only */
/* ---------------------------- */
%type <node> AbbrevForwardStep
%type <node> AnyKindTest
%type <node> AposAttrContentList
%type <node> Opt_AposAttrContentList
%type <node> AposAttrValueContent
%type <node> ArgList
%type <node> AtomicType
%type <node> AttributeTest
%type <node> BaseURIDecl
%type <node> BoundarySpaceDecl
%type <node> CaseClause
%type <node> CaseClauseList
%type <node> CommentTest
%type <node> ConstructionDecl
%type <node> CopyNamespacesDecl
%type <node> DefaultCollationDecl
%type <node> DefaultNamespaceDecl
%type <node> DirAttr
%type <node> DirAttributeList
%type <node> DirAttributeValue
%type <node> DirElemContentList
%type <node> DocumentTest
%type <node> ElementTest
%type <node> EmptyOrderDecl
%type <node> ForClause
%type <node> ForLetClause
%type <node> ForLetClauseList
%type <node> ForwardAxis
%type <node> ForwardStep
%type <node> FunctionDecl
%type <node> GeneralComp
%type <node> Import
%type <node> ItemType
%type <node> KindTest
%type <node> LetClause
%type <node> LibraryModule
%type <node> MainModule 
%type <node> Module
%type <node> ModuleDecl
%type <node> ModuleImport
%type <node> NameTest
%type <node> NamespaceDecl
%type <node> NodeComp
%type <node> NodeTest
%type <node> OccurrenceIndicator
%type <node> OptionDecl
%type <node> OrderByClause
%type <node> OrderCollationSpec
%type <node> OrderDirSpec
%type <node> OrderEmptySpec
%type <node> OrderModifier
%type <node> OrderSpec
%type <node> OrderSpecList
%type <node> OrderingModeDecl
%type <node> PITest
%type <node> Param
%type <node> ParamList
%type <node> PositionalVar
%type <node> Pragma
%type <node> PragmaList
%type <node> PredicateList
%type <node> Prolog
%type <node> QVarInDecl
%type <node> QVarInDeclList
%type <node> QuoteAttrValueContent
%type <node> QuoteAttrContentList
%type <node> Opt_QuoteAttrContentList
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
%type <node> TextTest
%type <node> TypeDeclaration
%type <node> TypeName
%type <node> TypeName_WITH_HOOK
%type <node> URILiteralList
%type <node> ValueComp
%type <node> VarDecl
%type <node> VarGetsDecl
%type <node> VarGetsDeclList
%type <node> VarInDecl
%type <node> VarInDeclList
%type <node> VersionDecl
%type <node> VFO_Decl
%type <node> VFO_DeclList
%type <node> WhereClause
%type <node> Wildcard


/* left-hand sides: expressions */
/* ---------------------------- */
%type <expr> AdditiveExpr
%type <expr> AndExpr
%type <expr> AxisStep
%type <expr> CDataSection
%type <expr> CastExpr
%type <expr> CastableExpr
%type <expr> CommonContent
%type <expr> ComparisonExpr
%type <expr> CompAttrConstructor
%type <expr> CompCommentConstructor
%type <expr> CompDocConstructor
%type <expr> CompElemConstructor
%type <expr> CompPIConstructor
%type <expr> CompTextConstructor
%type <expr> ComputedConstructor
%type <expr> Constructor
%type <expr> ContextItemExpr
%type <expr> DirCommentConstructor
%type <expr> DirElemConstructor
%type <expr> DirElemContent
%type <expr> DirPIConstructor
%type <expr> DirectConstructor
%type <expr> EnclosedExpr
%type <expr> Expr
%type <expr> ExprSingle
%type <expr> ExtensionExpr
%type <expr> FLWORExpr
%type <expr> FilterExpr
%type <expr> FunctionCall
%type <expr> IfExpr
%type <expr> InstanceofExpr
%type <expr> IntersectExceptExpr
%type <expr> Literal
%type <expr> MultiplicativeExpr
%type <expr> NumericLiteral
%type <expr> OrExpr
%type <expr> OrderedExpr
%type <expr> ParenthesizedExpr
%type <expr> PathExpr
%type <expr> Predicate
%type <expr> PrimaryExpr
%type <expr> QuantifiedExpr
%type <expr> QueryBody
%type <expr> RangeExpr
%type <expr> RelativePathExpr
%type <expr> StepExpr
%type <expr> StringLiteral
%type <expr> TreatExpr
%type <expr> TypeswitchExpr
%type <expr> UnaryExpr
%type <expr> UnionExpr
%type <expr> UnorderedExpr
%type <expr> ValidateExpr
%type <expr> ValueExpr
%type <expr> VarRef


/* update-related */
/* -------------- */
%type <expr> DeleteExpr
%type <expr> InsertExpr
%type <expr> RenameExpr
%type <expr> ReplaceExpr
%type <node> RevalidationDecl
%type <expr> TransformExpr
%type <expr> VarNameList


/* full-text-related */
/* ----------------- */
%type <node> FTAnd
%type <node> FTAnyallOption
%type <node> FTBigUnit
%type <node> FTCaseOption
%type <expr> FTContainsExpr
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
%type <node> FTWildcardOption
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
%nonassoc UNARY_PREC

/*_____________________________________________________________________
 *
 * resolve shift-reduce conflict for
 * [119] SequenceType ::= ItemType | ItemType OccurrenceIndicator
 *_____________________________________________________________________*/
%nonassoc SEQUENCE_TYPE_REDUCE
%nonassoc OCCURS_HOOK OCCURS_PLUS OCCURS_STAR

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

%%
%start Module;



// [1] Module
// ----------
Module :
    MainModule
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [main]\n";
#endif
			$$ = $1;
			driver.set_expr($$);
		}
  | VersionDecl MainModule
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.main]\n";
#endif
		}
  | LibraryModule 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [library]\n";
#endif
		}
  | VersionDecl LibraryModule 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Module [version.library]\n";
#endif
		}
  ;


// [2] VersionDecl
// ---------------
VersionDecl :
		XQUERY_VERSION  STRING_LITERAL  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version]\n";
#endif
		}
	|	XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VersionDecl [version.encoding]\n";
#endif
		}
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [prolog.querybody]\n";
#endif
			$$ = new MainModule(@$,
								static_cast<Prolog*>($1),
								static_cast<QueryBody*>($2));
		}
	|
    QueryBody
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MainModule [querybody]\n";
#endif
			$$ = new MainModule(@$,
								NULL,
								static_cast<QueryBody*>($1));
		}
  ;


// [4] LibraryModule
// -----------------
LibraryModule :
		ModuleDecl  Prolog
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LibraryModule [ ]\n";
#endif
			$$ = new LibraryModule(@$,
								static_cast<ModuleDecl*>($1),
								static_cast<Prolog*>($2));
		}
	;


// [5] ModuleDecl
// --------------
ModuleDecl :
		MODULE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleDecl [ ]\n";
#endif
			$$ = new ModuleDecl(@$,
								driver.symtab.get((off_t)$2), 
								driver.symtab.get((off_t)$4));
		}
	;


// [6] Prolog
// ----------
Prolog :
		SIND_DeclList  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind]\n";
#endif
			$$ = new Prolog(@$,
								static_cast<SIND_DeclList*>($1),
								NULL);
		}
	|	VFO_DeclList  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [vfo]\n";
#endif
			$$ = new Prolog(@$,
								NULL,
								static_cast<VFO_DeclList*>($1));
		}
	|	SIND_DeclList  SEMI  VFO_DeclList  SEMI
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Prolog [sind.vfo]\n";
#endif
			$$ = new Prolog(@$,
								static_cast<SIND_DeclList*>($1),
								static_cast<VFO_DeclList*>($3));
		}
	;


// [6a] SIDN_DeclList
// ------------------
SIND_DeclList :
		SIND_Decl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [single]\n";
#endif
			SIND_DeclList* sindList_p = new SIND_DeclList(@$);
			sindList_p->push_back($1);
			$$ = sindList_p;
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_DeclList [list]\n";
#endif
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>($1);
			if (sindList_p) {
				sindList_p->push_back($3);
			}
			$$ = $1;
		}
	;


// [6b] VFO_DeclList
// -----------------
VFO_DeclList :
		VFO_Decl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [single]\n";
#endif
			VFO_DeclList* vfoList_p = new VFO_DeclList(@$);
			vfoList_p->push_back($1);
			$$ = vfoList_p;
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_DeclList [list]\n";
#endif
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>($1);
			if (vfoList_p) {
				vfoList_p->push_back($3);
			}
			$$ = $1;
		}
	;


// [6c] SIND_Decl
// --------------
SIND_Decl :
		Setter
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [setter]\n";
#endif
			$$ = $1;
		}
	| Import
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [import]\n";
#endif
			$$ = $1;
		}
	| NamespaceDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [namespace]\n";
#endif
			$$ = $1;
		}
	| DefaultNamespaceDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SIND_Decl [default namespace]\n";
#endif
			$$ = $1;
		}
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [var]\n";
#endif
			$$ = $1;
		}
	| FunctionDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [function]\n";
#endif
			$$ = $1;
		}
	| OptionDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [option]\n";
#endif
			$$ = $1;
		}
	
	/* full-text extension */
	| FTOptionDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VFO_Decl [ftoption]\n";
#endif
			$$ = $1;
		}
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [boundary space]\n";
#endif
			$$ = $1;
		}
	| DefaultCollationDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [default collation]\n";
#endif
			$$ = $1;
		}
	| BaseURIDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [base uri]\n";
#endif
			$$ = $1;
		}
	| ConstructionDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [construction]\n";
#endif
			$$ = $1;
		}
	| OrderingModeDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [ordering mode]\n";
#endif
			$$ = $1;
		}
	| EmptyOrderDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [empty order]\n";
#endif
			$$ = $1;
		}
	| CopyNamespacesDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [copy namespaces]\n";
#endif
			$$ = $1;
		}

	/* update extension */
	| RevalidationDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Setter [revalidation]\n";
#endif
			$$ = $1;
		}
	;


// [8] Import
// ----------
Import :
		SchemaImport
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [schema]\n";
#endif
			$$ = $1;
		}
	| ModuleImport
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Import [module]\n";
#endif
			$$ = $1;
		}
	;


// [9] Separator
// -------------
// (= SEMI)


// [10] NamespaceDecl
// ------------------
NamespaceDecl :
		DECLARE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NamespaceDecl [ ]\n";
#endif
			$$ = new NamespaceDecl(@$,
								driver.symtab.get((off_t)$2),
								driver.symtab.get((off_t)$4));
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE_BOUNDARY_SPACE  PRESERVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [preserve]\n";
#endif
			$$ = new BoundarySpaceDecl(@$,
								StaticQueryContext::preserve_space);
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BoundarySpaceDecl [strip]\n";
#endif
			$$ = new BoundarySpaceDecl(@$,
								StaticQueryContext::strip_space);
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [element]\n";
#endif
			$$ = new DefaultNamespaceDecl(@$,
								ns_element_default,
								driver.symtab.get((off_t)$3));
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultNamespaceDecl [function]\n";
#endif
			$$ = new DefaultNamespaceDecl(@$,
								ns_function_default,
								driver.symtab.get((off_t)$3));
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE_OPTION  QNAME  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OptionDecl [ ]\n";
#endif
			$$ = new OptionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								driver.symtab.get((off_t)$3));
		}
	;


/* full-text extension */
// [13a] FTOptionDecl
// ------------------
FTOptionDecl :
		DECLARE_FTOPTION  FTMatchOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOptionDecl [ ]\n";
#endif
			$$ = new FTOptionDecl(@$,
								$2);
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [ordered]\n";
#endif
			$$ = new OrderingModeDecl(@$,
								StaticQueryContext::ordered);
		}
	| DECLARE_ORDERING  UNORDERED
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderingDecl [unordered]\n";
#endif
			$$ = new OrderingModeDecl(@$,
								StaticQueryContext::unordered);
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty greatest]\n";
#endif
			$$ = new EmptyOrderDecl(@$,
								StaticQueryContext::empty_greatest);
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EmptyOrderDecl [empty least]\n";
#endif
			$$ = new EmptyOrderDecl(@$,
								StaticQueryContext::empty_least);
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  INHERIT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			$$ = new CopyNamespacesDecl(@$,
								StaticQueryContext::preserve_ns,
								StaticQueryContext::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  NO_INHERIT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			$$ = new CopyNamespacesDecl(@$,
								StaticQueryContext::preserve_ns,
								StaticQueryContext::no_inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  INHERIT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			$$ = new CopyNamespacesDecl(@$,
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  NO_INHERIT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CopyNamespacesDecl [ ]\n";
#endif
			$$ = new CopyNamespacesDecl(@$,
								StaticQueryContext::no_preserve_ns,
								StaticQueryContext::no_inherit_ns);
		}
	;


// [17] PreserveMode
// -----------------

// [18] InheritMode
// ----------------


// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl :
		DECLARE_DEFAULT_COLLATION  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DefaultCollationMode [ ]\n";
#endif
			$$ = new DefaultCollationDecl(@$,
								driver.symtab.get((off_t)$2));
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE_BASE_URI  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "BaseURIDecl [ ]\n";
#endif
			$$ = new BaseURIDecl(@$,
								driver.symtab.get((off_t)$2));
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT_SCHEMA  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri]\n";
#endif
			$$ = new SchemaImport(@$,
								NULL,
								driver.symtab.get((off_t)$2),
								NULL);
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri]\n";
#endif
			$$ = new SchemaImport(@$,
								dynamic_cast<SchemaPrefix*>($2),
								driver.symtab.get((off_t)$3),
								NULL);
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URILiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [uri.urilist]\n";
#endif
			$$ = new SchemaImport(@$,
								NULL,
								driver.symtab.get((off_t)$2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaImport [prefix.uri.aturi]\n";
#endif
			$$ = new SchemaImport(@$,
								dynamic_cast<SchemaPrefix*>($2),
								driver.symtab.get((off_t)$3),
								dynamic_cast<URILiteralList*>($5));
		}
	;


// [21a] URILiteralList
// --------------------
URILiteralList :
		URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [single]\n";
#endif
			URILiteralList* uri_list_p = new URILiteralList(@$);
			uri_list_p->push_back(driver.symtab.get((off_t)$1));
			$$ = uri_list_p;
		}
	| URILiteralList  COMMA  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "URILiteralList [list]\n";
#endif
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>($1);
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get((off_t)$3));
			}
			$$ = $1;
		}
	;



// [22] SchemaPrefix
// -----------------
SchemaPrefix :
		NAMESPACE  NCNAME  EQUALS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [namespace]\n";
#endif
			$$ = new SchemaPrefix(@$, driver.symtab.get((off_t)$2));
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaPrefix [default element]\n";
#endif
			$$ = new SchemaPrefix(@$, true);
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT_MODULE  URI_LITERAL 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri]\n";
#endif
			$$ = new ModuleImport(@$,
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri]\n";
#endif
			$$ = new ModuleImport(@$,
								driver.symtab.get((off_t)$3),
								driver.symtab.get((off_t)$5),
								NULL);
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URILiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [uri.at_uri.list]\n";
#endif
			$$ = new ModuleImport(@$,
								driver.symtab.get((off_t)$2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URILiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ModuleImport [namespace.uri.at_uri.list]\n";
#endif
			$$ = new ModuleImport(@$,
								driver.symtab.get((off_t)$3),
								driver.symtab.get((off_t)$5),
								dynamic_cast<URILiteralList*>($7));
		}
	;



// [24] VarDecl
// ------------
VarDecl :
		DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [expr]\n";
#endif
			$$ = new VarDecl(@$,
								driver.symtab.get((off_t)$2),
								NULL,
								$4);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [external]\n";
#endif
			$$ = new VarDecl(@$,
								driver.symtab.get((off_t)$2),
								NULL,
								NULL);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.expr]\n";
#endif
			$$ = new VarDecl(@$,
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3),
								$5);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarDecl [type.external]\n";
#endif
			$$ = new VarDecl(@$,
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3),
								NULL);
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE_CONSTRUCTION  PRESERVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [preserve]\n";
#endif
			$$ = new ConstructionDecl(@$,
								StaticQueryContext::cons_preserve);
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ConstructionDecl [strip]\n";
#endif
			$$ = new ConstructionDecl(@$,
								StaticQueryContext::cons_strip);
		}
	;


// [26] FunctionDecl
// -----------------
FunctionDecl :
		DECLARE_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,NULL,NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [as_type.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [paramlist.as_type.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<EnclosedExpr*>($6),
								fn_read);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,NULL,NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) as_type.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
#endif
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<EnclosedExpr*>($6),
								fn_update);
		}
	;


// [27] ParamList
// --------------
ParamList :
		Param
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [single]\n";
#endif
			ParamList* plist_p = new ParamList(@$);
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($1));
			}
			$$ = plist_p;
		}
	|	ParamList  COMMA  Param
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParamList [list]\n";
#endif
			ParamList* plist_p = dynamic_cast<ParamList*>($1);
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($3));
			}
			$$ = $1;
		}
	;


// [28] Param
// ----------
Param :
		DOLLAR  VARNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname]\n";
#endif
			$$ = new Param(@$,
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Param [varname.type]\n";
#endif
			$$ = new Param(@$,
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3));
		}
	;


// [29] EnclosedExpr
// -----------------
EnclosedExpr :
		LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "EnclosedExpr [ ]\n";
#endif
			$$ = new EnclosedExpr(@$,
								$2);
		}
	;


// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QueryBody [expr]\n";
#endif
			$$ = new QueryBody(@$,
								$1);
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [single]\n";
#endif
			Expr* expr_p = new Expr(@$);
			expr_p->push_back($1);
			$$ = expr_p;
		}
	|	Expr  COMMA  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Expr [expr.single]\n";
#endif
			Expr* expr_p = dynamic_cast<Expr*>($1);
			if (expr_p) expr_p->push_back($3);
			$$ = $1;
		}
	;


// [32] ExprSingle
// ---------------
ExprSingle :
		FLWORExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [FLWORExpr]\n";
#endif
			$$ = $1;
		}
	|	QuantifiedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [QuantifiedExpr]\n";
#endif
			$$ = $1;
		}
	|	TypeswitchExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TypeswitchExpr]\n";
#endif
			$$ = $1;
		}
	|	IfExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [IfExpr]\n";
#endif
			$$ = $1;
		}
	|	OrExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [OrExpr]\n";
#endif
			$$ = $1;
		}

		/* update extensions */
	| InsertExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [InsertExpr]\n";
#endif
			$$ = $1;
		}
	| DeleteExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [DeleteExpr]\n";
#endif
			$$ = $1;
		}
	| RenameExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [RenameExpr]\n";
#endif
			$$ = $1;
		}
	| ReplaceExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [ReplaceExpr]\n";
#endif
			$$ = $1;
		}
	| TransformExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExprSingle [TransformExpr]\n";
#endif
			$$ = $1;
		}
	;


// [33] FLWORExpr
// --------------
FLWORExpr :
	  ForLetClauseList  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [return]\n";
#endif
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								NULL,NULL,
								$3);
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.return]\n";
#endif
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								NULL,
								$4);
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [orderby.return]\n";
#endif
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								NULL,
								dynamic_cast<OrderByClause*>($2),
								$4);
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FLWORExpr [where.orderby.return]\n";
#endif
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								dynamic_cast<OrderByClause*>($3),
								$5);
		}
	;


// [33a] ForLetClauseList
// ----------------------
ForLetClauseList :
		ForLetClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [single]\n";
#endif
			ForLetClauseList* flc_list_p = new ForLetClauseList(@$);
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ($1));
			$$ = flc_list_p;
		}
	|	ForLetClauseList  ForLetClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClauseList [list]\n";
#endif
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>($1);
			if (flc_list_p) flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ($2));
			$$ = $1;
		}
	;


// [33b] ForLetClause
// ------------------
ForLetClause :
		ForClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [for]\n";
#endif
			$$ = $1;
		}
	|	LetClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForLetClause [let]\n";
#endif
			$$ = $1;
		}
	;


// [34] ForClause
// --------------
ForClause :
		FOR_DOLLAR  VarInDeclList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForClause [ ]\n";
#endif
			$$ = new ForClause(@$,
								dynamic_cast<VarInDeclList*>($2));
		}
	;


// [34a] VarInDeclList
// -------------------
VarInDeclList :
		VarInDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [single]\n";
#endif
			VarInDeclList* vardecl_list_p = new VarInDeclList(@$);
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>($1));
			$$ = vardecl_list_p;
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDeclList [list]\n";
#endif
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>($1);
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>($4));
			}
			$$ = $1;
		}
	;


// [34b] VarInDecl
// ---------------
VarInDecl :
		VARNAME  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,NULL,NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,NULL,
								$4);
		}
	|	VARNAME  PositionalVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								NULL,
								$4);
		}
	|	VARNAME  TypeDeclaration  PositionalVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								NULL,
								$5);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [scorevar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.scorevar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  PositionalVar  FTScoreVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [posvar.scorevar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  _IN_  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarInDecl [type.posvar.scorevar.in]\n";
#endif
			$$ = new VarInDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								dynamic_cast<FTScoreVar*>($4),
								$6);
		}
	;


// [35] PositionalVar
// ------------------
PositionalVar :
		AT  DOLLAR  VARNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PositionalVar [ ]\n";
#endif
			$$ = new PositionalVar(@$,
								driver.symtab.get((off_t)$3));
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  VARNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTScoreVar [ ]\n";
#endif
			$$ = new FTScoreVar(@$,
								driver.symtab.get((off_t)$3));
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET_DOLLAR VarGetsDeclList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "LetClause [ ]\n";
#endif
			$$ = new LetClause(@$,
								dynamic_cast<VarGetsDeclList*>($2));
			
		}
	;


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList :
		VarGetsDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [single]\n";
#endif
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(@$);
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($1));
			$$ = vgdl_p;
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDeclList [list.single]\n";
#endif
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>($1);
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($4));
			}
			$$ = $1;
		}
	;


// [36b] VarGetsDecl
// ------------------
VarGetsDecl :
		VARNAME  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [gets]\n";
#endif
			$$ = new VarGetsDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,
								NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.gets]\n";
#endif
			$$ = new VarGetsDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								$4);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [scorevar.gets]\n";
#endif
			$$ = new VarGetsDecl(@$,
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarGetsDecl [type.scorevar.gets]\n";
#endif
			$$ = new VarGetsDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	;



// [37] WhereClause
// ----------------
WhereClause :
		WHERE  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "WhereClause [ ]\n";
#endif
			$$ = new WhereClause(@$,
								$2);
		}
	;


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER_BY  OrderSpecList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [ ]\n";
#endif
			$$ = new OrderByClause(@$,
								dynamic_cast<OrderSpecList*>($2));
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderByClause [stable]\n";
#endif
			$$ = new OrderByClause(@$,
								dynamic_cast<OrderSpecList*>($2),
								true);
		}
	;


// [39] OrderSpecList
// ------------------
OrderSpecList :
		OrderSpec 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [single]\n";
#endif
			OrderSpecList* osl_p = new OrderSpecList(@$);
			osl_p->push_back(dynamic_cast<OrderSpec*>($1));
			$$ = osl_p;
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpecList [list]\n";
#endif
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>($1);
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>($3));
			}
			$$ = $1;
		}
	;


// [40] OrderSpec
// --------------
OrderSpec :
		ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single]\n";
#endif
			$$ = new OrderSpec(@$,
								$1,
								NULL);
		}
	|	ExprSingle OrderModifier
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderSpec [single.modifier]\n";
#endif
			$$ = new OrderSpec(@$,
								$1,
								dynamic_cast<OrderModifier*>($2));
		}
	;


// [41] OrderModifier
// ------------------
OrderModifier :
		OrderDirSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir]\n";
#endif
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								NULL);
		}
	|	OrderEmptySpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty]\n";
#endif
			$$ = new OrderModifier(@$,
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								NULL);
		}
	|	OrderCollationSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [collation]\n";
#endif
			$$ = new OrderModifier(@$,
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>($1));
		}
	|	OrderDirSpec  OrderEmptySpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty]\n";
#endif
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderEmptySpec*>($2),
								NULL);
		}
	|	OrderDirSpec  OrderCollationSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.collation]\n";
#endif
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [empty.collation]\n";
#endif
			$$ = new OrderModifier(@$,
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderModifier [dir.empty.collation]\n";
#endif
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderEmptySpec*>($2),
								dynamic_cast<OrderCollationSpec*>($3));
		}
	;


// [41a] OrderDirSpec
// ------------------
OrderDirSpec :
		ASCENDING
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [ascending]\n";
#endif
			$$ = new OrderDirSpec(@$, dir_ascending);
		}
	|	DESCENDING
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderDirSpec [descending]\n";
#endif
			$$ = new OrderDirSpec(@$, dir_descending);
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [greatest]\n";
#endif
			$$ = new OrderEmptySpec(@$,
								StaticQueryContext::empty_greatest);
		}
	|	EMPTY_LEAST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderEmptySpec [least]\n";
#endif
			$$ = new OrderEmptySpec(@$,
								StaticQueryContext::empty_least);
		}
	;


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec :
		COLLATION  URI_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderCollationSpec [ ]\n";
#endif
			$$ = new OrderCollationSpec(@$,
								driver.symtab.get((off_t)$2));
		}
	;


// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr :
		SOME_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [some]\n";
#endif
			$$ = new QuantifiedExpr(@$,
								quant_some,
								dynamic_cast<QVarInDeclList*>($2),
								$4);
		}
	|	EVERY_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuantifiedExpr [every]\n";
#endif
			$$ = new QuantifiedExpr(@$,
								quant_every,
								dynamic_cast<QVarInDeclList*>($2),
								$4);
		}
	;


// [42a] QVarInDeclList
// --------------------
QVarInDeclList :
		QVarInDecl  %prec QVARINDECLLIST_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [single]\n";
#endif
			QVarInDeclList* qvid_list_p = new QVarInDeclList(@$);
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>($1));
			$$ = qvid_list_p;
				
		}
	|	QVarInDeclList  COMMA DOLLAR  QVarInDecl
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDeclList [list]\n";
#endif
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>($1);
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>($4));
			$$ = $1;
		}
	;


// [42b] QVarInDecl
// ----------------
QVarInDecl :
		VARNAME  _IN_  ExprSingle 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [in]\n";
#endif
			$$ = new QVarInDecl(@$,
								driver.symtab.get((off_t)$1),
								$3);
		}
	|	VARNAME  TypeDeclaration  _IN_  ExprSingle 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QVarInDecl [type.in]\n";
#endif
			$$ = new QVarInDecl(@$,
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								$4);
		}
	;


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.return]\n";
#endif
			$$ = new TypeswitchExpr(@$,
								$2,
								dynamic_cast<CaseClauseList*>($4),
								$7);
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeswitchExpr [cases.default.varname.return]\n";
#endif
			$$ = new TypeswitchExpr(@$,
								$2,
								dynamic_cast<CaseClauseList*>($4),
								driver.symtab.get((off_t)$7),
								$9);
		}
	;


// [43a] CaseClauseList
// --------------------
CaseClauseList :
		CaseClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [single]\n";
#endif
			CaseClauseList* cc_list_p = new CaseClauseList(@$);
			cc_list_p->push_back(dynamic_cast<CaseClause*>($1));
			$$ = cc_list_p;
		}
	|	CaseClauseList  CaseClause
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClauseList [list]\n";
#endif
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>($1);
			cc_list_p->push_back(dynamic_cast<CaseClause*>($2));
			$$ = $1;
		}
	;


// [44] CaseClause
// ---------------
CaseClause :
		CASE  SequenceType  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.return]\n";
#endif
			$$ = new CaseClause(@$,
								dynamic_cast<SequenceType*>($2),
								$4);
		}
	|	CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CaseClause [case.as.return]\n";
#endif
			$$ = new CaseClause(@$,
								driver.symtab.get((off_t)$3),
								dynamic_cast<SequenceType*>($5),
								$7);
		}
	;


// [45] IfExpr
// -----------
IfExpr :
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IfExpr [ ]\n";
#endif
			$$ = new IfExpr(@$,
								$2, $5, $7);
		}
	;


// [46] OrExpr
// -----------
OrExpr :
		AndExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [and]\n";
#endif
			$$ = $1;
		}
	|	OrExpr  OR  AndExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrExpr [or.and]\n";
#endif
			$$ = new OrExpr(@$,
								$1, $3);
		}
	;


// [47] AndExpr
// ------------
AndExpr :
		ComparisonExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [comp]\n";
#endif
			$$ = $1;
		}
	|	AndExpr  AND  ComparisonExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AndExpr [and.comp]\n";
#endif
			$$ = new AndExpr(@$,
								$1, $3);
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains]\n";
#endif
			$$ = $1;
		}
	| FTContainsExpr  ValueComp  FTContainsExpr
		{
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]\n";
#endif
			$$ = new ComparisonExpr(@$,
								dynamic_cast<ValueComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  GeneralComp  FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
#endif
			$$ = new ComparisonExpr(@$,
								dynamic_cast<GeneralComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  NodeComp  FTContainsExpr
		{
			/*  ::=  "is" | "<<" | ">>" */
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
#endif
			$$ = new ComparisonExpr(@$,
								dynamic_cast<NodeComp*>($2),
								$1,
								$3);
		}
	;


//[48a] FTContainsExpr
//-------------------
FTContainsExpr :
		RangeExpr  %prec FTCONTAINS_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range]\n";
#endif
			$$ = $1;
		}
	|	RangeExpr  FTCONTAINS  FTSelection 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect]\n";
#endif
			$$ = new FTContainsExpr(@$,
								$1,
								dynamic_cast<FTSelection*>($3),
								NULL);
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContainsExpr [range.ftselect.ftignore]\n";
#endif
			$$ = new FTContainsExpr(@$,
								$1,
								dynamic_cast<FTSelection*>($3),
								dynamic_cast<FTIgnoreOption*>($4));
		}
	;


// [49] RangeExpr
// --------------
RangeExpr :
		AdditiveExpr  %prec RANGE_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add]\n";
#endif
			$$ = $1;
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RangeExpr [add.to.add]\n";
#endif
			$$ = new RangeExpr(@$,
								$1, $3);
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr  %prec ADDITIVE_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult]\n";
#endif
			$$ = $1;
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult+mult]\n";
#endif
			$$ = new AdditiveExpr(@$, op_plus, $1, $3);
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AdditiveExpr [mult-mult]\n";
#endif
			$$ = new AdditiveExpr(@$, op_minus, $1, $3);
		}
	;


// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr :
		UnionExpr  %prec MULTIPLICATIVE_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [union]\n";
#endif
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult*union]\n";
#endif
			$$ = new MultiplicativeExpr(@$, op_mul, $1, $3);
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.div.union]\n";
#endif
			$$ = new MultiplicativeExpr(@$, op_div, $1, $3);
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.idiv.union]\n";
#endif
			$$ = new MultiplicativeExpr(@$, op_idiv, $1, $3);
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "MultiplicativeExpr [mult.mod.union]\n";
#endif
			$$ = new MultiplicativeExpr(@$, op_mod, $1, $3);
		}
	;


// [52] UnionExpr
// --------------
UnionExpr :
		IntersectExceptExpr  %prec UNION_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [interexcept]\n";
#endif
			$$ = $1;
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union.union.interexcept]\n";
#endif
			$$ = new UnionExpr(@$,
								$1, $3);
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnionExpr [union|interexcept]\n";
#endif
			$$ = new UnionExpr(@$,
								$1, $3);
		}
	;


// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr :
		InstanceofExpr  %prec INTERSECT_EXCEPT_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [instanceof]\n";
#endif
			$$ = $1;
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
#endif
			$$ = new IntersectExceptExpr(@$, op_intersect, $1, $3);
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
#endif
			$$ = new IntersectExceptExpr(@$, op_except, $1, $3);
		}
	;


// [54] InstanceofExpr
// -------------------
InstanceofExpr :
		TreatExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat]\n";
#endif
			$$ = $1;
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InstanceofExpr [treat.seqtype]\n";
#endif
			$$ = new InstanceofExpr(@$,
								$1,
								dynamic_cast<SequenceType*>($3));
		}
	;


// [55] TreatExpr
// --------------
TreatExpr :
		CastableExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable]\n";
#endif
			$$ = $1;
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TreatExpr [castable.seqtype]\n";
#endif
			$$ = new TreatExpr(@$,
								$1,
								dynamic_cast<SequenceType*>($3));
		}
	;


// [56] CastableExpr
// -----------------
CastableExpr :
		CastExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast]\n";
#endif
			$$ = $1;
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastableExpr [cast.singletype]\n";
#endif
			$$ = new CastableExpr(@$,
								$1,
								dynamic_cast<SingleType*>($3));
		}
	;


// [57] CastExpr 	   
// -------------
CastExpr :
		UnaryExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary]\n";
#endif
			$$ = $1;
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CastExpr [unary.singletype]\n";
#endif
			$$ = new CastExpr(@$,
								$1,
								dynamic_cast<SingleType*>($3));
		}
	;


// [58] UnaryExpr
// --------------
UnaryExpr :
		ValueExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [value]\n";
#endif
			$$ = $1;
		}
	|	SignList  ValueExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnaryExpr [signlist.value]\n";
#endif
			$$ = new UnaryExpr(@$,
								dynamic_cast<SignList*>($1),
								$2);
		}
	;


// [58a] SignList
// --------------
SignList :
		PLUS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [+]\n";
#endif
			$$ = new SignList(@$, true);
		}
	|	MINUS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [-]\n";
#endif
			$$ = new SignList(@$, false);
		}
	|	SignList  PLUS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.+]\n";
#endif
			$$ = $1;
		}
	|	SignList  MINUS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SignList [signlist.-]\n";
#endif
			SignList* slist_p = dynamic_cast<SignList*>($1);
			if (slist_p) slist_p->negate();
			$$ = $1;
		}
	;


// [59] ValueExpr
// --------------
ValueExpr :
		ValidateExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [validate]\n";
#endif
			$$ = $1;
		}
	|	PathExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [path]\n";
#endif
			$$ = $1;
		}
	|	ExtensionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueExpr [extension]\n";
#endif
			$$ = $1;
		}
	;



// [60] GeneralComp
// ----------------
GeneralComp :
		EQUALS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [=]\n";
#endif
			$$ = new GeneralComp(@$, op_eq);
		}
	| NE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [!=]\n";
#endif
			$$ = new GeneralComp(@$, op_ne);
		}
	| LT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<]\n";
#endif
			$$ = new GeneralComp(@$, op_lt);
		}
	| LE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [<=]\n";
#endif
			$$ = new GeneralComp(@$, op_le);
		}
	| GT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>]\n";
#endif
			$$ = new GeneralComp(@$, op_gt);
		}
	| GE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "GeneralComp [>=]\n";
#endif
			$$ = new GeneralComp(@$, op_ge);
		}
	;


// [61] ValueComp
// --------------
ValueComp :
		VAL_EQ
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [eq]\n";
#endif
			$$ = new ValueComp(@$, op_val_eq);
		}
	| VAL_NE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ne]\n";
#endif
			$$ = new ValueComp(@$, op_val_ne);
		}
	| VAL_LT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [lt]\n";
#endif
			$$ = new ValueComp(@$, op_val_lt);
		}
	| VAL_LE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [le]\n";
#endif
			$$ = new ValueComp(@$, op_val_le);
		}
	| VAL_GT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [gt]\n";
#endif
			$$ = new ValueComp(@$, op_val_gt);
		}
	| VAL_GE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValueComp [ge]\n";
#endif
			$$ = new ValueComp(@$, op_val_ge);
		}
	;


// [62] NodeComp
// -------------
NodeComp :
		IS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [is]\n";
#endif
			$$ = new NodeComp(@$, op_is);
		}
	| PRECEDES
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [<<]\n";
#endif
			$$ = new NodeComp(@$, op_precedes);
		}
	| FOLLOWS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeComp [>>]\n";
#endif
			$$ = new NodeComp(@$, op_follows);
		}
	;



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [expr]\n";
#endif
			$$ = new ValidateExpr(@$, "strict", $2);
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ValidateExpr [mode.expr]\n";
#endif
			$$ = new ValidateExpr(@$,
								driver.symtab.get((off_t)$1),
								$3);
		}
	;


// [64] ExtensionExpr
// ------------------
ExtensionExpr :
		PragmaList  LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist]\n";
#endif
			$$ = new ExtensionExpr(@$,
								dynamic_cast<PragmaList*>($1),
								NULL);
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ExtensionExpr [pragmalist.expr]\n";
#endif
			$$ = new ExtensionExpr(@$,
								dynamic_cast<PragmaList*>($1),
								$3);
		}
	;


// [64a] PragmaList
// ----------------
PragmaList :
		Pragma
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [single]\n";
#endif
			PragmaList* pragma_list_p = new PragmaList(@$);
			pragma_list_p->push_back(dynamic_cast<Pragma*>($1));
			$$ = pragma_list_p;
		}
	|	PragmaList  Pragma
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PragmaList [list]\n";
#endif
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>($1);
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>($2));
			}
			$$ = $1;
		}
	;


// [65] Pragma
// -----------
Pragma :
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL  PRAGMA_END
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Pragma [ ]\n";
#endif
			$$ = new Pragma(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								driver.symtab.get((off_t)$3));

		}
	;	/* ws: explicit */


// [66] PragmaContents
// -------------------
/* folded into [65] */

/*______________________________________________________________________
|
| Constraint: leading-lone-slash
|	
|	A single slash may appear either as a complete path expression or as 
|	the first part of a path expression in which it is followed by a 
|	RelativePathExpr, which can take the form of a NameTest ("*" or a 
|	QName). In contexts where operators like "*", "union", etc., can 
|	occur, parsers may have difficulty distinguishing operators from 
|	NameTests. For example, without lookahead the first part of the 
|	expression "/ * 5", for example is easily taken to be a complete 
|	expression, "/ *", which has a very different interpretation (the 
|	child nodes of "/"). 
|	
|	To reduce the need for lookahead, therefore, if the token immediately 
|	following a slash is "*" or a keyword, then the slash must be the 
|	beginning, but not the entirety, of a PathExpr (and the following 
|	token must be a NameTest, not an operator). 
|	
|	A single slash may be used as the left-hand argument of an operator by 
|	parenthesizing it: (/) * 5. The expression 5 * /, on the other hand, 
|	is legal without parentheses. 
|	
|_______________________________________________________________________*/


// [67] PathExpr
// -------------
PathExpr :
		LEADING_LONE_SLASH
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/]\n";
#endif
			$$ = new PathExpr(@$, path_leading_lone_slash, NULL);
		}
	|	SLASH  RelativePathExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [/relative]\n";
#endif
			$$ = new PathExpr(@$, path_leading_slash, $2);
		}
	|	SLASH_SLASH  RelativePathExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [//relative]\n";
#endif
			$$ = new PathExpr(@$, path_leading_slashslash, $2);
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PathExpr [relative]\n";
#endif
            RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>($1);
            $$ = rpe == NULL ? $1 : new PathExpr(@$, path_relative, $1);
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step]\n";
#endif
            AxisStep *as = dynamic_cast<AxisStep *>($1);
            $$ = as != NULL ? new RelativePathExpr(@$, st_slash, new ContextItemExpr(@$), $1) : $1;
		}
	|	StepExpr  SLASH  RelativePathExpr 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step/relative]\n";
#endif
			$$ = new RelativePathExpr(@$, st_slash, $1, $3);
		}
	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RelativePathExpr [step//relative]\n";
#endif
			$$ = new RelativePathExpr(@$, st_slashslash, $1, $3);
		}
	;


// [69] StepExpr
// -------------
StepExpr :
		AxisStep
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [axis]\n";
#endif
			$$ = $1;
		}
	|	FilterExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StepExpr [filter]\n";
#endif
			$$ = $1;
		}
	;


// [70] AxisStep
// -------------
AxisStep :
		ForwardStep 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward]\n";
#endif
			$$ = new AxisStep(@$,
								dynamic_cast<ForwardStep*>($1),
								NULL);
		}
	|	ForwardStep  PredicateList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [forward.predlist]\n";
#endif
			$$ = new AxisStep(@$,
								dynamic_cast<ForwardStep*>($1),
								dynamic_cast<PredicateList*>($2));
		}
	|	ReverseStep
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse]\n";
#endif
			$$ = new AxisStep(@$,
								dynamic_cast<ReverseStep*>($1),
								NULL);
		}
	|	ReverseStep  PredicateList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AxisStep [reverse.predlist]\n";
#endif
			$$ = new AxisStep(@$,
								dynamic_cast<ReverseStep*>($1),
								dynamic_cast<PredicateList*>($2));
		}
	;


// [71] ForwardStep
// ----------------
ForwardStep :
		ForwardAxis  NodeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [nodetest]\n";
#endif
			$$ = new ForwardStep(@$,
								dynamic_cast<ForwardAxis*>($1),
								$2);
		}
	|	AbbrevForwardStep
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardStep [abbrev]\n";
#endif
			$$ = new ForwardStep(@$,
								dynamic_cast<AbbrevForwardStep*>($1));
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [child]\n";
#endif
			$$ = new ForwardAxis(@$, axis_child);
		}
	| DESCENDANT_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant]\n";
#endif
			$$ = new ForwardAxis(@$, axis_descendant);
		}
	| ATTRIBUTE_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [attribute]\n";
#endif
			$$ = new ForwardAxis(@$, axis_attribute);
		}
	| SELF_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [self]\n";
#endif
			$$ = new ForwardAxis(@$, axis_self);
		}
	| DESCENDANT_OR_SELF_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [descendant_or_self]\n";
#endif
			$$ = new ForwardAxis(@$, axis_descendant_or_self);
		}
	| FOLLOWING_SIBLING_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following_sibling]\n";
#endif
			$$ = new ForwardAxis(@$, axis_following_sibling);
		}
	| FOLLOWING_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ForwardAxis [following]\n";
#endif
			$$ = new ForwardAxis(@$, axis_following);
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [nodetest]\n";
#endif
			$$ = new AbbrevForwardStep(@$, $1);
		}
	|	AT_SIGN  NodeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AbbrevForwardStep [@ nodetest]\n";
#endif
			$$ = new AbbrevForwardStep(@$, $2, true);
		}
	;


// [74] ReverseStep
// ----------------
ReverseStep :
		ReverseAxis  NodeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [nodetest]\n";
#endif
			$$ = new ReverseStep(@$,
								dynamic_cast<ReverseAxis*>($1),
								$2);
		}
	|	DOT_DOT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseStep [..]\n";
#endif
			ReverseAxis* rev_p = new ReverseAxis(@$, axis_parent);
			$$ = new ReverseStep(@$,
								rev_p);
		}
	;


// [75] ReverseAxis
// ----------------
ReverseAxis :
		PARENT_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [parent]\n";
#endif
			$$ = new ReverseAxis(@$, axis_parent);
		}
	| ANCESTOR_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor]\n";
#endif
			$$ = new ReverseAxis(@$, axis_ancestor);
		}
	| PRECEDING_SIBLING_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding_sibling]\n";
#endif
			$$ = new ReverseAxis(@$, axis_preceding_sibling);
		}
	| PRECEDING_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [preceding]\n";
#endif
			$$ = new ReverseAxis(@$, axis_preceding);
		}
	| ANCESTOR_OR_SELF_AXIS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReverseAxis [ancestor_or_self]\n";
#endif
			$$ = new ReverseAxis(@$, axis_ancestor_or_self);
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [kindtest]\n";
#endif
			$$ = $1;
		}
	|	NameTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NodeTest [nametest]\n";
#endif
			$$ = $1;
		}
	;
 

// [78] NameTest
// -------------
NameTest :
		QNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [qname]\n";
#endif
			$$ = new NameTest(@$, new QName(@$,driver.symtab.get((off_t)$1)));
		}
	|	Wildcard
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NameTest [wildcard]\n";
#endif
			$$ = new NameTest(@$, dynamic_cast<Wildcard*>($1));
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*]\n";
#endif
			$$ = new Wildcard(@$,
                        "",
                        "",
                        wild_all);
		}
	|	ELEM_WILDCARD
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [pref:*]\n";
#endif
			$$ = new Wildcard(@$,
                        driver.symtab.get((off_t)$1),
                        "",
                        wild_elem);
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Wildcard [*:qname]\n";
#endif
			$$ = new Wildcard(@$,
                        "",
                        driver.symtab.get((off_t)$1),
                        wild_prefix);
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary]\n";
#endif
			$$ = $1;
		}
	|	PrimaryExpr  PredicateList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FilterExpr [primary.predlist]\n";
#endif
			$$ = new FilterExpr(@$,
								$1,
								dynamic_cast<PredicateList*>($2));
		}
	;


// [81] PredicateList
// ------------------
PredicateList :
		Predicate
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [single]\n";
#endif
			PredicateList* pred_list_p = new PredicateList(@$);
			pred_list_p->push_back(dynamic_cast<exprnode*>($1));
			$$ = pred_list_p;
		}
	|	PredicateList  Predicate
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PredicateList [list]\n";
#endif
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>($1);
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>($2));
			}
			$$ = $1;
		}
	;


// [82] Predicate
// --------------
Predicate :
		LBRACK  Expr  RBRACK
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Predicate [ ]\n";
#endif
			$$ = $2;
		}
	;



// [83] PrimaryExpr
// ----------------
PrimaryExpr :
		Literal
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [literal]\n";
#endif
			$$ = $1;
		}
	|	VarRef
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [varref]\n";
#endif
			$$ = $1;
		}
	|	ParenthesizedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [paren]\n";
#endif
			$$ = $1;
		}
	|	ContextItemExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [context_item]\n";
#endif
			$$ = $1;
		}
	|	FunctionCall
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [funcall]\n";
#endif
			$$ = $1;
		}
	|	Constructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [cons]\n";
#endif
			$$ = $1;
		}
	|	OrderedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [ordered]\n";
#endif
			$$ = $1;
		}
	|	UnorderedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PrimaryExpr [unordered]\n";
#endif
			$$ = $1;
		}
	;


// [84] Literal
// ------------
Literal :
		NumericLiteral
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [numeric]\n";
#endif
			$$ = $1;
		}
	|	StringLiteral
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Literal [string]\n";
#endif
			$$ = $1;
		}
	;


// [85] NumericLiteral
// -------------------
NumericLiteral :
		DECIMAL_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [decimal]\n";
#endif
			$$ = new NumericLiteral(@$, decimal(yylval.decval));
		}
	| INTEGER_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [int]\n";
#endif
			$$ = new NumericLiteral(@$, yylval.ival);
		}
	|	DOUBLE_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "NumericLiteral [double]\n";
#endif
			$$ = new NumericLiteral(@$, yylval.dval);
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarRef [ ]\n";
#endif
			$$ = new VarRef(@$, driver.symtab.get((off_t)$2));
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [()]\n";
#endif
			$$ = new ParenthesizedExpr(@$, NULL);
		}
	|	LPAR  Expr  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ParenthesizedExpr [(expr)]\n";
#endif
			$$ = new ParenthesizedExpr(@$,
								$2);
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContextItemExpr [.]\n";
#endif
			$$ = new ContextItemExpr(@$);
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OrderedExpr [expr]\n";
#endif
			$$ = new OrderedExpr(@$,
								$2);
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "UnorderedExpr [expr]\n";
#endif
			$$ = new UnorderedExpr(@$,
								$2);
		}
	;


// [91] FunctionCall
// -----------------
/*___________________________________________________________________
|	gn: reserved-function-namesXQ
|	Constraint: reserved-function-names
|	
|	Unprefixed function names spelled the same way as language keywords 
|	could make the language harder to recognize. For instance, if(foo) 
|	could be taken either as a FunctionCall or as the beginning of an 
|	IfExpr. Therefore it is not legal syntax for a user to invoke 
|	functions with unprefixed names which match any of the names:
|		attribute
|		comment
|		document-node
|		element
|		empty-sequence
|		if
|		item
| 	node
|		processing-instruction
|		schema-attribute
|		schema-element
|		text
|		typeswitch
|	
|	A function named "if" can be called by binding its namespace to a 
|	prefix and using the prefixed form: "library:if(foo)" instead of 
|	"if(foo)". 
|____________________________________________________________________*/

/*___________________________________________________________________
|	gn: parensXQ
|	Grammar-note: parens
|	
|	Look-ahead is required to distinguish FunctionCall from a QName or 
|	keyword followed by a Pragma or Comment. For example:
|
|		address (: this may be empty :)
|
|	may be mistaken for a call to a function named 
|	"address" unless this lookahead is employed. Another example is
|
|		for (: whom the bell :) $tolls in 3 return $tolls,
|
|	where the keyword "for" must not be mistaken for a function name. 
|
|____________________________________________________________________*/
FunctionCall :
		QNAME_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [ ]\n";
#endif
			$$ = new FunctionCall(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	QNAME_LPAR  ArgList  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FunctionCall [arglist]\n";
#endif
			$$ = new FunctionCall(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								dynamic_cast<ArgList*>($2));
		}
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [single]\n";
#endif
			ArgList* a_list_p = new ArgList(@$); 
			a_list_p->push_back($1);
			$$ = a_list_p;
		}
	|	ArgList  COMMA  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ArgList [list]\n";
#endif
			ArgList* a_list_p = dynamic_cast<ArgList*>($1);
			if (a_list_p) a_list_p->push_back($3);
			$$ = $1;
		}
	;


// [92] Constructor
// ----------------
Constructor :
		DirectConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [direct]\n";
#endif
			$$ = $1;
		}
	|	ComputedConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "Constructor [computed]\n";
#endif
			$$ = $1;
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [element]\n";
#endif
			$$ = $1;
		}
	|	DirCommentConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [comment]\n";
#endif
			$$ = $1;
		}
	|	DirPIConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirectConstructor [pi]\n";
#endif
			$$ = $1;
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  EMPTY_TAG_END /* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname/> ]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								NULL,
								NULL);
		}
	| START_TAG  QNAME  DirAttributeList EMPTY_TAG_END /* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist/> ]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<DirAttributeList*>($3), 
								NULL);
		}
	| START_TAG  QNAME  TAG_END  START_TAG_END  QNAME  TAG_END
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname></qname>]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								new QName(@$,driver.symtab.get((off_t)$5)),
								NULL,
								NULL);
		}
	|	START_TAG  QNAME  TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname>content</qname>]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								new QName(@$,driver.symtab.get((off_t)$6)),
								NULL,
								dynamic_cast<DirElemContentList*>($4));
		}
	| START_TAG  QNAME  DirAttributeList TAG_END  START_TAG_END  QNAME TAG_END
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist></qname>]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								new QName(@$,driver.symtab.get((off_t)$6)),
								dynamic_cast<DirAttributeList*>($3),
								NULL);
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
#endif
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								new QName(@$,driver.symtab.get((off_t)$7)),
								dynamic_cast<DirAttributeList*>($3), 
								dynamic_cast<DirElemContentList*>($5));
		}
			/* ws: explicitXQ */
	;


// [94a] DirElemContentList
// ------------------------
DirElemContentList :
	DirElemContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [single]\n";
#endif
			DirElemContentList* elem_content_list_p = new DirElemContentList(@$);
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>($1));
			$$ = elem_content_list_p;
		}
	|	DirElemContentList  DirElemContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContentList [list]\n";
#endif
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>($1);
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>($2));
			$$ = $1;
		}
	;


// [95] DirAttributeList
// ---------------------
DirAttributeList :
		DirAttr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [single]\n";
#endif
			DirAttributeList* at_list_p = new DirAttributeList(@$);
			at_list_p->push_back(dynamic_cast<DirAttr*>($1));
			$$ = at_list_p;
		}
	|	DirAttributeList  DirAttr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeList [list]\n";
#endif
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>($1);
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>($2));
			}
			$$ = $1;
		}
	;


// [95a] DirAttr
// -------------
DirAttr :
		QNAME  EQUALS  DirAttributeValue 	/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttr [ ]\n";
#endif
			$$ = new DirAttr(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								dynamic_cast<DirAttributeValue*>($3));
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  Opt_QuoteAttrContentList  QUOTE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [quote]\n";
#endif
			$$ = new DirAttributeValue(@$,
								dynamic_cast<QuoteAttrContentList*>($2));
		}
	|	APOS  Opt_AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirAttributeValue [apos]\n";
#endif
			$$ = new DirAttributeValue(@$,
								dynamic_cast<AposAttrContentList*>($2));
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
Opt_QuoteAttrContentList :
		/* empty */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList[empty]\n";
#endif
			$$ = new QuoteAttrContentList(@$);
		}
	|	QuoteAttrContentList
		{
			$$ = $1;
		}
	;

QuoteAttrContentList :	
		ESCAPE_QUOTE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [""]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(@$);
			qo_list_p->push_back(new QuoteAttrValueContent(@$,string("\"")));
			$$ = qo_list_p;
		}
	|	QuoteAttrValueContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [single]\n";
#endif
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(@$);
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($1));
			$$ = qo_list_p;
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list ""]\n";
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(@$,string("\"")));
			}
			$$ = $1;
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrContentList [list]\n";
#endif
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($2));
			}
		}
	;


// [96b] AposAttrContentList
// -------------------------
Opt_AposAttrContentList :
		/* empty */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			$$ = new AposAttrContentList(@$);
		}
	|	AposAttrContentList
		{
			$$ = $1;
		}
	;

AposAttrContentList :
		ESCAPE_APOS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList ['']\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(@$);
			at_list_p->push_back(new AposAttrValueContent(@$,"'"));
			$$ = at_list_p;
		}
	|	AposAttrValueContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [single]\n";
#endif
			AposAttrContentList* at_list_p = new AposAttrContentList(@$);
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>($1));
			$$ = at_list_p;
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.'']\n";
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>($1);
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(@$,"'"));
			}
			$$ = $1;
		}
	|	AposAttrContentList  AposAttrValueContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrContentList [list.single]\n";
#endif
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>($1);
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>($2));
			}
			$$ = $1;
		}
	;


// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent :
		QUOTE_ATTR_CONTENT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [quote_attr_content]\n";
#endif
			$$ = new QuoteAttrValueContent(@$,
								driver.symtab.get((off_t)$1));
		}
	|	CommonContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "QuoteAttrValueContent [common_content]\n";
#endif
			$$ = new QuoteAttrValueContent(@$,
								dynamic_cast<CommonContent*>($1));
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [apos_attr_content]\n";
#endif
			$$ = new AposAttrValueContent(@$,
								driver.symtab.get((off_t)$1));
		}
	|	CommonContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AposAttrValueContent [common_content]\n";
#endif
			$$ = new AposAttrValueContent(@$,
								dynamic_cast<CommonContent*>($1));
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cons]\n";
#endif
			$$ = new DirElemContent(@$,
								$1);
		}
	|	ELEMENT_CONTENT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [elem_content]\n";
#endif
			$$ = new DirElemContent(@$,
								driver.symtab.get((off_t)$1));
		}
	|	CDataSection
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [cdata]\n";
#endif
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>($1);
			$$ = new DirElemContent(@$,
								cdata_h);
		}
	|	CommonContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirElemContent [common_content]\n";
#endif
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>($1);
			$$ = new DirElemContent(@$,
								cont_h);
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
		ENTITY_REF
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [entity_ref]\n";
#endif
			$$ = new CommonContent(@$,
								cont_entity,
								driver.symtab.get((off_t)$1));
		}
	|	CHAR_REF_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [char_ref]\n";
#endif
			$$ = new CommonContent(@$,
								cont_charref,
								driver.symtab.get((off_t)$1));
		}
	|	DOUBLE_LBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [{{]\n";
#endif
			$$ = new CommonContent(@$,
								cont_escape_lbrace);
		}
	|	DOUBLE_RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [}}]\n";
#endif
			$$ = new CommonContent(@$,
								cont_escape_rbrace);
		}
	|	EnclosedExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommonContent [expr]\n";
#endif
			$$ = new CommonContent(@$,
								dynamic_cast<EnclosedExpr*>($1));
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		XML_COMMENT_BEGIN  XML_COMMENT_LITERAL  XML_COMMENT_END 	/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirCommentConstructor [ ]\n";
#endif
			$$ = new DirCommentConstructor(@$,
								driver.symtab.get((off_t)$2));
		}
	;


// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
DirPIConstructor :
		PI_BEGIN  PI_TARGET_LITERAL PI_END 								/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target]\n";
#endif
			$$ = new DirPIConstructor(@$,
								driver.symtab.get((off_t)$2));
		}
    |	PI_BEGIN  PI_TARGET_LITERAL CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DirPIConstructor [target.charlit]\n";
#endif
			$$ = new DirPIConstructor(@$,
								driver.symtab.get((off_t)$2),
								driver.symtab.get((off_t)$3));
		}
	;


// [104] DirPIContents
// -------------------
/* lexical rule */


// [105] CDataSection
// ------------------
CDataSection :
		CDATA_BEGIN  CHAR_LITERAL  CDATA_END 				/* ws: explicitXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CDataSection [ ]\n";
#endif
			$$ = new CDataSection(@$,driver.symtab.get((off_t)$2));
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [doc]\n";
#endif
			$$ = $1;
		}
	|	CompElemConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [elem]\n";
#endif
			$$ = $1;
		}
	|	CompAttrConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [attr]\n";
#endif
			$$ = $1;
		}
	|	CompTextConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [text]\n";
#endif
			$$ = $1;
		}
	|	CompCommentConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [comment]\n";
#endif
			$$ = $1;
		}
	|	CompPIConstructor
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ComputedConstructor [pi]\n";
#endif
			$$ = $1;
		}
	;


// [108] CompDocConstructor
// ------------------------
CompDocConstructor :
		DOCUMENT_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompDocConstructor [ ]\n";
#endif
			$$ = new CompDocConstructor(@$,
								$2);
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [ ]\n";
#endif
			$$ = new CompElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	ELEMENT_QNAME_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [content]\n";
#endif
			$$ = new CompElemConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								$2);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name]\n";
#endif
			$$ = new CompElemConstructor(@$,
								$2, NULL);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompElemConstructor [name.content]\n";
#endif
			$$ = new CompElemConstructor(@$,
								$2, $5);
		}
	;


// [110] ContentExpr
// -----------------
/*
ContentExpr :
		Expr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ContentExpr [ ]\n";
#endif
		}
	;
*/


// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor :
		ATTRIBUTE_QNAME_LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [ ]\n";
#endif
			$$ = new CompAttrConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	ATTRIBUTE_QNAME_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [val]\n";
#endif
			$$ = new CompAttrConstructor(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								$2);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name]\n";
#endif
			$$ = new CompAttrConstructor(@$,
								$2, NULL);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompAttrConstructor [name.val]\n";
#endif
			$$ = new CompAttrConstructor(@$,
								$2, $5);
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompTextConstructor [content]\n";
#endif
			$$ = new CompTextConstructor(@$,
								dynamic_cast<Expr*>($2));
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompCommentConstructor [content]\n";
#endif
			$$ = new CompCommentConstructor(@$,
								dynamic_cast<Expr*>($2));
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [ ]\n";
#endif
			$$ = new CompPIConstructor(@$,
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [content]\n";
#endif
			$$ = new CompPIConstructor(@$,
								driver.symtab.get((off_t)$2),
								$4);
		}
	|	PROCESSING_INSTRUCTION LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target]\n";
#endif
			$$ = new CompPIConstructor(@$,
								$3, NULL);
		}
	|	PROCESSING_INSTRUCTION LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CompPIConstructor [target.content]\n";
#endif
			$$ = new CompPIConstructor(@$,
								$3, $6);
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic]\n";
#endif
			$$ = new SingleType(@$,
								dynamic_cast<AtomicType*>($1),
								false);
		}
	|	AtomicType  HOOK
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SingleType [atomic ?]\n";
#endif
			$$ = new SingleType(@$,
								dynamic_cast<AtomicType*>($1),
								true);
		}
	;


// [116] TypeDeclaration
// ---------------------
TypeDeclaration :
		AS  SequenceType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeDeclaration [as seqtype]\n";
#endif
			$$ = new TypeDeclaration(@$,
								dynamic_cast<SequenceType*>($2));
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type]\n";
#endif
			$$ = new SequenceType(@$,
								$1,
								NULL);
		}
	|	ItemType  OccurrenceIndicator
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [type.occurs]\n";
#endif
			$$ = new SequenceType(@$,
								$1,
								dynamic_cast<OccurrenceIndicator*>($2));
		}
	|	VOID_TEST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [void]\n";
#endif
			$$ = new SequenceType(@$, NULL, NULL);
		}
	;


// [118] OccurrenceIndicator
// -------------------------
/*________________________________________________________________________
|
|	gn: occurrence-indicatorsXQ
|
|	Constraint: occurrence-indicators
|
|	As written, the grammar in A XQuery Grammar is ambiguous for some 
|	forms using the '+' and '*' Kleene operators. The ambiguity is 
|	resolved as follows: these operators are tightly bound to the 
|	SequenceType expression, and have higher precedence than other uses of 
|	these symbols. Any occurrence of '+' and '*', as well as '?', 
|	following a sequence type is assumed to be an occurrence indicator. 
|	That is, a "+", "*", or "?" immediately following an ItemType must be 
|	an OccurrenceIndicator. Thus, 4 treat as item() + - 5 must be 
|	interpreted as (4 treat as item()+) - 5, taking the '+' as an 
|	OccurrenceIndicator and the '-' as a subtraction operator. To force 
|	the interpretation of "+" as an addition operator (and the 
|	corresponding interpretation of the "-" as a unary minus), parentheses 
|	may be used: the form (4 treat as item()) + -5 surrounds the 
|	SequenceType expression with parentheses and leads to the desired 
|	interpretation. 
|
|	This rule has as a consequence that certain forms which would 
|	otherwise be legal and unambiguous are not recognized: in "4 treat as 
|	item() + 5", the "+" is taken as an OccurrenceIndicator, and not as an 
|	operator, which means this is not a legal expression. 
|_________________________________________________________________________*/
OccurrenceIndicator :
		OCCURS_HOOK
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [?]\n";
#endif
			$$ = new OccurrenceIndicator(@$,
								occurs_optionally);
		}
	|	OCCURS_STAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [*]\n";
#endif
			$$ = new OccurrenceIndicator(@$,
								occurs_zero_or_more);
		}
	|	OCCURS_PLUS 	/* gn: occurrence-indicatorsXQ */
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "OccurrenceIndicator [+]\n";
#endif
			$$ = new OccurrenceIndicator(@$,
								occurs_one_or_more);
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [atomic]\n";
#endif
			$$ = $1;
		}
	|	KindTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [kind]\n";
#endif
			$$ = $1;
		}
	|	ITEM_TEST
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ItemType [item]\n";
#endif
			$$ = new ItemType(@$,true);
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AtomicType [qname]\n";
#endif
			$$ = new AtomicType(@$,
								new QName(@$, driver.symtab.get((off_t)$1)));
		}
	;


// [121] KindTest
// --------------
KindTest :
		DocumentTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [doc]\n";
#endif
			$$ = $1;
		}
	| ElementTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [elem]\n";
#endif
			$$ = $1;
		}
	| AttributeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [attr]\n";
#endif
			$$ = $1;
		}
	| SchemaElementTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_elem]\n";
#endif
			$$ = $1;
		}
	| SchemaAttributeTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [schema_attr]\n";
#endif
			$$ = $1;
		}
	| PITest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [pi]\n";
#endif
			$$ = $1;
		}
	| CommentTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [comment]\n";
#endif
			$$ = $1;
		}
	| TextTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [text]\n";
#endif
			$$ = $1;
		}
	| AnyKindTest
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "KindTest [any]\n";
#endif
			$$ = $1;
		}
	;


// [122] AnyKindTest
// -----------------
AnyKindTest :
		NODE_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AnyKindTest [ ]\n";
#endif
			$$ = new AnyKindTest(@$);
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [ ]\n";
#endif
			$$ = new DocumentTest(@$);
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [elem]\n";
#endif
			$$ = new DocumentTest(@$,
								dynamic_cast<ElementTest*>($2));
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DocumentTest [schema_elem]\n";
#endif
			$$ = new DocumentTest(@$,
								dynamic_cast<SchemaElementTest*>($2));
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TextTest [ ]\n";
#endif
			$$ = new TextTest(@$);
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "CommentTest [ ]\n";
#endif
			$$ = new CommentTest(@$);
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ ]\n";
#endif
			$$ = new PITest(@$, "", "");
		}
	|	PI_LPAR  NCNAME  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [ncname]\n";
#endif
			$$ = new PITest(@$, driver.symtab.get((off_t)$2), "");
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "PITest [stringlit]\n";
#endif
			$$ = new PITest(@$, "", driver.symtab.get((off_t)$2));
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [ ]\n";
#endif
			$$ = new AttributeTest(@$,
								NULL,
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name]\n";
#endif
			$$ = new AttributeTest(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  COMMA  TypeName  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [name.type]\n";
#endif
			$$ = new AttributeTest(@$,
								new QName(@$,driver.symtab.get((off_t)$2)),
								dynamic_cast<TypeName*>($4));
		}
	|	ATTRIBUTE_LPAR  STAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*]\n";
#endif
			$$ = new AttributeTest(@$,
								NULL,
								NULL);
		}
	|	ATTRIBUTE_LPAR  STAR  COMMA  TypeName  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "AttributeTest [*.type]\n";
#endif
			$$ = new AttributeTest(@$,
								NULL,
								dynamic_cast<TypeName*>($4));
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  QNAME  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaAttributeTest [ ]\n";
#endif
			$$ = new SchemaAttributeTest(@$,
								new QName(@$, driver.symtab.get((off_t)$2)));
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [ ]\n";
#endif
			$$ = new ElementTest(@$,
									NULL,
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name]\n";
#endif
			$$ = new ElementTest(@$,
									new QName(@$,driver.symtab.get((off_t)$2)),
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  COMMA  TypeName  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			$$ = new ElementTest(@$,
									new QName(@$,driver.symtab.get((off_t)$2)),
									dynamic_cast<TypeName*>($4));
		}
	|	ELEMENT_LPAR  QNAME  COMMA  TypeName_WITH_HOOK RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [name.type]\n";
#endif
			$$ = new ElementTest(@$,
									new QName(@$,driver.symtab.get((off_t)$2)),
									dynamic_cast<TypeName*>($4));
		}
	|	ELEMENT_LPAR  STAR  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*]\n";
#endif
			$$ = new ElementTest(@$,
									NULL,
									NULL,
									true);
		}
	|	ELEMENT_LPAR  STAR  COMMA  TypeName  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]\n";
#endif
			$$ = new ElementTest(@$,
									NULL,
									dynamic_cast<TypeName*>($4),
									true);
		}
	|	ELEMENT_LPAR  STAR  COMMA  TypeName_WITH_HOOK RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ElementTest [*.type]\n";
#endif
			$$ = new ElementTest(@$,
									NULL,
									dynamic_cast<TypeName*>($4),
									true);
		}
	;


// [133] SchemaElementTest
// -----------------------
SchemaElementTest :
		SCHEMA_ELEMENT_LPAR  QNAME  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "SchemaElementTest [ ]\n";
#endif
			$$ = new SchemaElementTest(@$,
									new QName(@$,driver.symtab.get((off_t)$2)));
		}
	;


/* productions inlined */
/* ------------------- */
// [128] AttribNameOrWildcard ::= AttributeName | "*"
// [130] AttributeDeclaration ::= AttributeName
// [132] ElementNameOrWildcard ::= ElementName | "*"
// [134] ElementDeclaration ::= ElementName
// [135] AttributeName ::= QName
// [136] ElementName ::= QName


// [137] TypeName */
/* -------------- */
TypeName :
		QNAME
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name]\n";
#endif
			$$ = new TypeName(@$,
								new QName(@$,driver.symtab.get((off_t)$1)));
		};
    
TypeName_WITH_HOOK :
	  QNAME  HOOK
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TypeName [name?]\n";
#endif
			$$ = new TypeName(@$,
								new QName(@$,driver.symtab.get((off_t)$1)),
								true);
		}
	;


/* lexical rules, see xquery.l */
/* --------------------------- */
// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 


// [142] StringLiteral
// -------------------
StringLiteral :
		STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "StringLiteral [ ]\n";
#endif
			$$ = new StringLiteral(@$, driver.symtab.get((off_t)$1));
		}
	;


/* lexical rules, see xquery.l */
/* --------------------------- */
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RevalidationDecl [ ]\n";
#endif
		}
	;


// [242]	InsertExpr
// ----------------
InsertExpr :
		DO_INSERT  ExprSingle  INTO  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr]\n";
#endif
		}
	|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_first]\n";
#endif
		}
	|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.as_last]\n";
#endif
		}
	| DO_INSERT  ExprSingle  AFTER  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.after]\n";
#endif
		}
	| DO_INSERT  ExprSingle  BEFORE  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "InsertExpr [expr.before]\n";
#endif
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		DO_DELETE  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "DeleteExpr [expr]\n";
#endif
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		DO_REPLACE  ExprSingle  WITH  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [expr.expr]\n";
#endif
		}
	|	DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "ReplaceExpr [value.expr]\n";
#endif
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		DO_RENAME  ExprSingle  AS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "RenameExpr [expr.expr]\n";
#endif
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "TransformExpr [ ]\n";
#endif
		}
	;


// [249a] VarNameList
// ------------------
VarNameList :
		VARNAME	 GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [single]\n";
#endif
		}
	|	VarNameList  COMMA_DOLLAR  VARNAME  GETS  ExprSingle
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "VarNameList [list]\n";
#endif
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
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or]\n";
#endif
		}
	|	FTOr  FTMatchOptionProximityList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity]\n";
#endif
		}
	|	FTOr  WEIGHT  RangeExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.weight_range]\n";
#endif
		}
	|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTSelection [or.match_proximity.weight_range]\n";
#endif
		}
	;


//[344a] FTMatchOptionProximityList
//---------------------------------
FTMatchOptionProximityList :
		FTMatchOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_single]\n";
#endif
		}
	| FTProximity
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_single]\n";
#endif
		}
	| FTMatchOptionProximityList  FTMatchOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [option_list]\n";
#endif
		}
	| FTMatchOptionProximityList  FTProximity
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOptionProximityList [proximity_list]\n";
#endif
		}
	;


//[345]	FTOr
//----------
FTOr :
		FTAnd
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [and]\n";
#endif
		}
	|	FTOr  FTOR  FTAnd
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOr [or.and]\n";
#endif
		}
	;


//[346]	FTAnd
//-----------
FTAnd :
		FTMildnot
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [mild_not]\n";
#endif
		}
	|	FTAnd  FTAND  FTMildnot
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnd [and.mild_not]\n";
#endif
		}
	;


//[347]	FTMildnot
//---------------
FTMildnot :
		FTUnaryNot
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [unary_not]\n";
#endif
		}
	|	FTMildnot  FTNOT_IN  FTUnaryNot
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMildNot [mild_not.unary_not]\n";
#endif
		}
	;


//[348]	FTUnaryNot
//----------------
FTUnaryNot :
		FTWordsSelection
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [words]\n";
#endif
		}
	|	FTNOT  FTWordsSelection
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnaryNot [not.words]\n";
#endif
		}
	;


//[349]	FTWordsSelection
//----------------------
FTWordsSelection :
		FTWords
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words]\n";
#endif
		}
	|	FTWords FTTimes
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [words.times]\n";
#endif
		}
	| LPAR  FTSelection  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsSelection [selection]\n";
#endif
		}
	;


//[350]	FTWords
//-------------
FTWords :
		FTWordsValue 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value]\n";
#endif
		}
	|	FTWordsValue  FTAnyallOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWords [value.any_all_option]\n";
#endif
		}
	;


//[351]	FTWordsValue
//------------------
FTWordsValue :
		Literal
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [literal]\n";
#endif
		}
	| LBRACE  Expr  RBRACE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWordsValue [expr]\n";
#endif
		}
	;


//[352]	FTProximity
//-----------------
FTProximity :
		FTOrderedIndicator
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [order]\n";
#endif
		}
	| FTWindow
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [window]\n";
#endif
		}
	| FTDistance
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [distance]\n";
#endif
		}
	| FTScope
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [scope]\n";
#endif
		}
	| FTContent
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTProximity [content]\n";
#endif
		}
	;


//[353]	FTOrderedIndicator
//------------------------
FTOrderedIndicator :
		ORDERED
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTOrderedIndicator [ ]\n";
#endif
		}
	;


//[354] FTMatchOption 	
//-------------------
FTMatchOption :
		FTCaseOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [case]\n";
#endif
			$$ = $1;
		}
	| FTDiacriticsOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [diacritics]\n";
#endif
			$$ = $1;
		}
	| FTStemOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stem]\n";
#endif
			$$ = $1;
		}
	| FTThesaurusOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [thesaurus]\n";
#endif
			$$ = $1;
		}
	| FTStopwordOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [stopword]\n";
#endif
			$$ = $1;
		}
	| FTLanguageOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [language]\n";
#endif
			$$ = $1;
		}
	| FTWildcardOption
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTMatchOption [wildcard]\n";
#endif
			$$ = $1;
		}
	;


//[355] FTCaseOption
//------------------
FTCaseOption :
		LOWERCASE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [lower]\n";
#endif
		}
	| UPPERCASE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [upper]\n";
#endif
		}
	| CASE_SENSITIVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [sensitive]\n";
#endif
		}
	| CASE_INSENSITIVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTCaseOption [insensitive]\n";
#endif
		}
	;


//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption :
		WITH_DIACRITICS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [with]\n";
#endif
		}
	| WITHOUT_DIACRITICS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [without]\n";
#endif
		}
	| DIACRITICS_SENSITIVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [sensitive]\n";
#endif
		}
	| DIACRITICS_INSENSITIVE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDiacriticsOption [insensitive]\n";
#endif
		}
	;


//[357] FTStemOption
//------------------
FTStemOption :
		WITH_STEMMING
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [with]\n";
#endif
		}
	| WITHOUT_STEMMING
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStemOption [without]\n";
#endif
		}
	;


//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption :
		WITH_THESAURUS  FTThesaurusID
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [id]\n";
#endif
		}
	|	WITH_THESAURUS  DEFAULT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [default]\n";
#endif
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id)]\n";
#endif
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(id,id,..)]\n";
#endif
		}
	| WITH_THESAURUS  LPAR  DEFAULT  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default)]\n";
#endif
		}
	| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [(default,id,id,..)]\n";
#endif
		}
	| WITHOUT_THESAURUS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusOption [without]\n";
#endif
		}
	;


//[358a] FTThesaurusIDList
//------------------------
FTThesaurusList :
		FTThesaurusID
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [single]\n";
#endif
		}
	| FTThesaurusList  COMMA  FTThesaurusID
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusList [list]\n";
#endif
		}
	;


//[359] FTThesaurusID
//-------------------
FTThesaurusID :
		AT  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name]\n";
#endif
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel]\n";
#endif
		}
	|	AT  STRING_LITERAL  FTRange  LEVELS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.range]\n";
#endif
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTThesaurusID [name.rel.range]\n";
#endif
		}
	;


//[360] FTStopwordOption
//----------------------
FTStopwordOption :
		WITH_STOP_WORDS  FTRefOrList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list]\n";
#endif
		}
	|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [list.incl_excl]\n";
#endif
		}
	| WITH_DEFAULT_STOP_WORDS 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default]\n";
#endif
		}
	| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [default.incl_excl]\n";
#endif
		}
	| WITHOUT_STOP_WORDS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStopwordOption [without]\n";
#endif
		}
	;


//[360a] FTInclExclStringLiteralList
//----------------------------------
FTInclExclStringLiteralList :
		FTInclExclStringLiteral
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [.]\n";
#endif
		}
	| FTInclExclStringLiteralList  FTInclExclStringLiteral
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteralList [*]\n";
#endif
		}
	;


//[361] FTRefOrList
//-----------------
FTRefOrList :
		AT  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [.]\n";
#endif
		}
	| LPAR  FTStringLiteralList  RPAR 
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRefOrList [(*)]\n";
#endif
		}
	;


//[361a] FTStringLiteralList
//--------------------------
FTStringLiteralList :
		STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [.]\n";
#endif
		}
	|	FTStringLiteralList  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTStringLiteralList [*]\n";
#endif
		}
	;


//[362] FTInclExclStringLiteral
//-----------------------------
FTInclExclStringLiteral :
		UNION  FTRefOrList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [union]\n";
#endif
		}
	|	EXCEPT  FTRefOrList
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTInclExclStringLiteral [except]\n";
#endif
		}
	;


//[363] FTLanguageOption
//----------------------
FTLanguageOption :
		LANGUAGE  STRING_LITERAL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTLanguageOption [ ]\n";
#endif
		}
	;


//[364] FTWildcardOption
//----------------------
FTWildcardOption :
		WITH_WILDCARDS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [with]\n";
#endif
		}
	| WITHOUT_WILDCARDS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWildcardOption [without]\n";
#endif
		}
	;


//[365]	FTContent
//---------------
FTContent :
		AT_START
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [start]\n";
#endif
		}
	| AT_END
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [end]\n";
#endif
		}
	| ENTIRE_CONTENT
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTContent [entire]\n";
#endif
		}
	;


//[366]	FTAnyallOption
//--------------------
FTAnyallOption :
		ANY
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any]\n";
#endif
		}
	|	ANY_WORD
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [any_word]\n";
#endif
		}
	| ALL
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all]\n";
#endif
		}
	| ALL_WORDS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [all_words]\n";
#endif
		}
	| PHRASE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTAnyallOption [phrase]\n";
#endif
		}
	;


//[367]	FTRange
//-------------
FTRange :
		EXACTLY  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [exactly]\n";
#endif
		}
	| AT_LEAST  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_least]\n";
#endif
		}
	| AT_MOST  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [at_most]\n";
#endif
		}
	| FROM  UnionExpr  TO  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTRange [range]\n";
#endif
		}
	;


//[368]	FTDistance
//----------------
FTDistance :
		DISTANCE  FTRange  FTUnit
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTDistance [ ]\n";
#endif
		}
	;


//[369]	FTWindow
//--------------
FTWindow :
		WINDOW  UnionExpr  FTUnit
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTWindow [ ]\n";
#endif
		}
	;


//[370]	FTTimes
//-------------
FTTimes :
		OCCURS  FTRange  TIMES
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [ ]\n";
#endif
		}
	;


//[371]	FTScope
//-------------
FTScope :
		SAME  FTBigUnit
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [same]\n";
#endif
		}
	|	DIFFERENT  FTBigUnit
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTTimes [different]\n";
#endif
		}
	;


//[372]	FTUnit
//------------
FTUnit :
		WORDS
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [words]\n";
#endif
		}
	| SENTENCES
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [sentences]\n";
#endif
		}
	| PARAGRAPH
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTUnit [paragraph]\n";
#endif
		}
	;


//[373]	FTBigUnit
//---------------
FTBigUnit :
		SENTENCE
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [sentence]\n";
#endif
		}
	| PARAGRAPH
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTBigUnit [paragraph]\n";
#endif
		}
	;


//[374]	FTIgnoreOption
//--------------------
FTIgnoreOption :
		WITHOUT_CONTENT  UnionExpr
		{
#ifdef ZORBA_DEBUG_PARSER
			 cout << "FTIgnoreOption [ ]\n";
#endif
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


/*
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
*/




