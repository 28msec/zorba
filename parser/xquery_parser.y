/* -*- mode: c++; indent-tabs-mode: nil -*-
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
#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include "context/context.h"
#include "parsenodes.h"
#include "parse_constants.h"

class xquery_driver;

using namespace std;
using namespace xqp;

namespace xqp {
	class parsenode;
	class exprnode;
}

static bool debug = true;

%}

/*
**	The driver is passed by reference to the parser and to the scanner. 
**	This provides a simple but effective pure interface, not relying on 
**	global variables. 
*/
%parse-param { xquery_driver& driver }
%lex-param   { xquery_driver& driver }


/*
**	Request the location tracking feature, and initialize the 
**	first location's file name. Afterwards new locations are computed 
**	relatively to the previous locations: the file name will be 
**	automatically propagated. 
*/
%locations
%initial-action
{
  @$.begin.filename = @$.end.filename = &driver.file;
};


/*
**	The two following directives to enable parser tracing and verbose 
**	error messages. 
*/
%debug
%error-verbose

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
	long long decval;
};


/*
**	The code between `%{' and `%}' after the introduction of the `%union' 
**	is output in the *.cc file; it needs detailed knowledge about the 
**	driver. 
*/
%{
#include "xquery_driver.h"
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
%token IN													"'in'"
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
%token NAN												"'nan'"
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
%token PROCESSING_INSTRUCTION			"'<processing instruction>'"
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
%token XML_COMMENT_BEGIN					"'<!'"
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
//%type <expr> ContentExpr
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
			if (debug) cout << "Module [main]\n";
			$$ = $1;
			driver.set_expr($$);
		}
  | VersionDecl MainModule
		{
			if (debug) cout << "Module [version.main]\n";
		}
  | LibraryModule 
		{
			if (debug) cout << "Module [library]\n";
		}
  | VersionDecl LibraryModule 
		{
			if (debug) cout << "Module [version.library]\n";
		}
  ;


// [2] VersionDecl
// ---------------
VersionDecl :
		XQUERY_VERSION  STRING_LITERAL  SEMI
		{
			if (debug) cout << "VersionDecl [version]\n";
		}
	|	XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
			if (debug) cout << "VersionDecl [version.encoding]\n";
		}
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
			if (debug) cout << "MainModule [prolog.querybody]\n";
			$$ = new MainModule(@$,
								dynamic_cast<Prolog*>($1),
								dynamic_cast<QueryBody*>($2));
		}
	|
    QueryBody
		{
			if (debug) cout << "MainModule [querybody]\n";
			$$ = new MainModule(@$,
								NULL,
								dynamic_cast<QueryBody*>($1));
		}
  ;


// [4] LibraryModule
// -----------------
LibraryModule :
		ModuleDecl  Prolog
		{
			if (debug) cout << "LibraryModule [ ]\n";
			$$ = new LibraryModule(@$,
								dynamic_cast<ModuleDecl*>($1),
								dynamic_cast<Prolog*>($2));
		}
	;


// [5] ModuleDecl
// --------------
ModuleDecl :
		MODULE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
			if (debug) cout << "ModuleDecl [ ]\n";
			$$ = new ModuleDecl(@$,
								driver.symtab.get($2), 
								driver.symtab.get($4));
		}
	;


// [6] Prolog
// ----------
Prolog :
		SIND_DeclList  SEMI
		{
			if (debug) cout << "Prolog [sind]\n";
			$$ = new Prolog(@$,
								dynamic_cast<SIND_DeclList*>($1),
								NULL);
		}
	|	VFO_DeclList  SEMI
		{
			if (debug) cout << "Prolog [vfo]\n";
			$$ = new Prolog(@$,
								NULL,
								dynamic_cast<VFO_DeclList*>($1));
		}
	|	SIND_DeclList  SEMI  VFO_DeclList  SEMI
		{
			if (debug) cout << "Prolog [sind.vfo]\n";
			$$ = new Prolog(@$,
								dynamic_cast<SIND_DeclList*>($1),
								dynamic_cast<VFO_DeclList*>($3));
		}
	;


// [6a] SIDN_DeclList
// ------------------
SIND_DeclList :
		SIND_Decl
		{
			if (debug) cout << "SIND_DeclList [single]\n";
			SIND_DeclList* sindList_p = new SIND_DeclList(@$);
			sindList_p->push_back(dynamic_cast<SIND_Decl*>($1));
			$$ = sindList_p;
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
			if (debug) cout << "SIND_DeclList [list]\n";
			SIND_DeclList* sindList_p = dynamic_cast<SIND_DeclList*>($1);
			if (sindList_p) {
				sindList_p->push_back(dynamic_cast<SIND_Decl*>($3));
			}
			$$ = $1;
		}
	;


// [6b] VFO_DeclList
// -----------------
VFO_DeclList :
		VFO_Decl
		{
			if (debug) cout << "VFO_DeclList [single]\n";
			VFO_DeclList* vfoList_p = new VFO_DeclList(@$);
			vfoList_p->push_back(dynamic_cast<VFO_Decl*>($1));
			$$ = vfoList_p;
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
			if (debug) cout << "VFO_DeclList [list]\n";
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>($1);
			if (vfoList_p) {
				vfoList_p->push_back(dynamic_cast<VFO_Decl*>($3));
			}
			$$ = $1;
		}
	;


// [6c] SIND_Decl
// --------------
SIND_Decl :
		Setter
		{
			if (debug) cout << "SIND_Decl [setter]\n";
			$$ = $1;
		}
	| Import
		{
			if (debug) cout << "SIND_Decl [import]\n";
			$$ = $1;
		}
	| NamespaceDecl
		{
			if (debug) cout << "SIND_Decl [namespace]\n";
			$$ = $1;
		}
	| DefaultNamespaceDecl
		{
			if (debug) cout << "SIND_Decl [default namespace]\n";
			$$ = $1;
		}
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl
		{
			if (debug) cout << "VFO_Decl [var]\n";
			$$ = $1;
		}
	| FunctionDecl
		{
			if (debug) cout << "VFO_Decl [function]\n";
			$$ = $1;
		}
	| OptionDecl
		{
			if (debug) cout << "VFO_Decl [option]\n";
			$$ = $1;
		}
	
	/* full-text extension */
	| FTOptionDecl
		{
			if (debug) cout << "VFO_Decl [ftoption]\n";
			$$ = $1;
		}
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl
		{
			if (debug) cout << "Setter [boundary space]\n";
			$$ = $1;
		}
	| DefaultCollationDecl
		{
			if (debug) cout << "Setter [default collation]\n";
			$$ = $1;
		}
	| BaseURIDecl
		{
			if (debug) cout << "Setter [base uri]\n";
			$$ = $1;
		}
	| ConstructionDecl
		{
			if (debug) cout << "Setter [construction]\n";
			$$ = $1;
		}
	| OrderingModeDecl
		{
			if (debug) cout << "Setter [ordering mode]\n";
			$$ = $1;
		}
	| EmptyOrderDecl
		{
			if (debug) cout << "Setter [empty order]\n";
			$$ = $1;
		}
	| CopyNamespacesDecl
		{
			if (debug) cout << "Setter [copy namespaces]\n";
			$$ = $1;
		}

	/* update extension */
	| RevalidationDecl
		{
			if (debug) cout << "Setter [revalidation]\n";
			$$ = $1;
		}
	;


// [8] Import
// ----------
Import :
		SchemaImport
		{
			if (debug) cout << "Import [schema]\n";
			$$ = $1;
		}
	| ModuleImport
		{
			if (debug) cout << "Import [module]\n";
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
			if (debug) cout << "NamespaceDecl [ ]\n";
			$$ = new NamespaceDecl(@$,
								driver.symtab.get($2),
								driver.symtab.get($4));
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE_BOUNDARY_SPACE  PRESERVE
		{
			if (debug) cout << "BoundarySpaceDecl [preserve]\n";
			$$ = new BoundarySpaceDecl(@$,
								static_context::preserve_space);
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
			if (debug) cout << "BoundarySpaceDecl [strip]\n";
			$$ = new BoundarySpaceDecl(@$,
								static_context::strip_space);
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
			if (debug) cout << "DefaultNamespaceDecl [element]\n";
			$$ = new DefaultNamespaceDecl(@$,
								ns_element_default,
								driver.symtab.get($3));
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
			if (debug) cout << "DefaultNamespaceDecl [function]\n";
			$$ = new DefaultNamespaceDecl(@$,
								ns_function_default,
								driver.symtab.get($3));
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE_OPTION  QNAME  STRING_LITERAL
		{
			if (debug) cout << "OptionDecl [ ]\n";
			$$ = new OptionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								driver.symtab.get($3));
		}
	;


/* full-text extension */
// [13a] FTOptionDecl
// ------------------
FTOptionDecl :
		DECLARE_FTOPTION  FTMatchOption
		{
			if (debug) cout << "FTOptionDecl [ ]\n";
			$$ = new FTOptionDecl(@$,
								$2);
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
			if (debug) cout << "OrderingDecl [ordered]\n";
			$$ = new OrderingModeDecl(@$,
								dynamic_context::ordered);
		}
	| DECLARE_ORDERING  UNORDERED
		{
			if (debug) cout << "OrderingDecl [unordered]\n";
			$$ = new OrderingModeDecl(@$,
								dynamic_context::unordered);
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
			if (debug) cout << "EmptyOrderDecl [empty greatest]\n";
			$$ = new EmptyOrderDecl(@$,
								static_context::empty_greatest);
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
			if (debug) cout << "EmptyOrderDecl [empty least]\n";
			$$ = new EmptyOrderDecl(@$,
								static_context::empty_least);
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  INHERIT
		{
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			$$ = new CopyNamespacesDecl(@$,
								static_context::preserve_ns,
								static_context::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  NO_INHERIT
		{
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			$$ = new CopyNamespacesDecl(@$,
								static_context::preserve_ns,
								static_context::no_inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  INHERIT
		{
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			$$ = new CopyNamespacesDecl(@$,
								static_context::no_preserve_ns,
								static_context::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  NO_INHERIT
		{
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			$$ = new CopyNamespacesDecl(@$,
								static_context::no_preserve_ns,
								static_context::no_inherit_ns);
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
			if (debug) cout << "DefaultCollationMode [ ]\n";
			$$ = new DefaultCollationDecl(@$,
								driver.symtab.get($2));
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE_BASE_URI  URI_LITERAL
		{
			if (debug) cout << "BaseURIDecl [ ]\n";
			$$ = new BaseURIDecl(@$,
								driver.symtab.get($2));
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT_SCHEMA  URI_LITERAL
		{
			if (debug) cout << "SchemaImport [uri]\n";
			$$ = new SchemaImport(@$,
								NULL,
								driver.symtab.get($2),
								NULL);
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
			if (debug) cout << "SchemaImport [prefix.uri]\n";
			$$ = new SchemaImport(@$,
								dynamic_cast<SchemaPrefix*>($2),
								driver.symtab.get($3),
								NULL);
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "SchemaImport [uri.urilist]\n";
			$$ = new SchemaImport(@$,
								NULL,
								driver.symtab.get($2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "SchemaImport [prefix.uri.aturi]\n";
			$$ = new SchemaImport(@$,
								dynamic_cast<SchemaPrefix*>($2),
								driver.symtab.get($3),
								dynamic_cast<URILiteralList*>($5));
		}
	;


// [21a] URILiteralList
// --------------------
URILiteralList :
		URI_LITERAL
		{
			if (debug) cout << "URILiteralList [single]\n";
			URILiteralList* uri_list_p = new URILiteralList(@$);
			uri_list_p->push_back(driver.symtab.get($1));
			$$ = uri_list_p;
		}
	| URILiteralList  COMMA  URI_LITERAL
		{
			if (debug) cout << "URILiteralList [list]\n";
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>($1);
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get($3));
			}
			$$ = $1;
		}
	;



// [22] SchemaPrefix
// -----------------
SchemaPrefix :
		NAMESPACE  NCNAME  EQUALS
		{
			if (debug) cout << "SchemaPrefix [namespace]\n";
			$$ = new SchemaPrefix(@$, driver.symtab.get($2));
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
			if (debug) cout << "SchemaPrefix [default element]\n";
			$$ = new SchemaPrefix(@$, true);
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT_MODULE  URI_LITERAL 
		{
			if (debug) cout << "ModuleImport [uri]\n";
			$$ = new ModuleImport(@$,
								driver.symtab.get($2),
								NULL);
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
			if (debug) cout << "ModuleImport [namespace.uri]\n";
			$$ = new ModuleImport(@$,
								driver.symtab.get($3),
								driver.symtab.get($5),
								NULL);
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "ModuleImport [uri.at_uri.list]\n";
			$$ = new ModuleImport(@$,
								driver.symtab.get($2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "ModuleImport [namespace.uri.at_uri.list]\n";
			$$ = new ModuleImport(@$,
								driver.symtab.get($3),
								driver.symtab.get($5),
								dynamic_cast<URILiteralList*>($7));
		}
	;



// [24] VarDecl
// ------------
VarDecl :
		DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
		{
			if (debug) cout << "VarDecl [expr]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								NULL,
								$4);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
			if (debug) cout << "VarDecl [external]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								NULL,
								NULL);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			if (debug) cout << "VarDecl [type.expr]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								dynamic_cast<TypeDeclaration*>($3),
								$5);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
			if (debug) cout << "VarDecl [type.external]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								dynamic_cast<TypeDeclaration*>($3),
								NULL);
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE_CONSTRUCTION  PRESERVE
		{
			if (debug) cout << "ConstructionDecl [preserve]\n";
			$$ = new ConstructionDecl(@$,
								static_context::cons_preserve);
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
			if (debug) cout << "ConstructionDecl [strip]\n";
			$$ = new ConstructionDecl(@$,
								static_context::cons_strip);
		}
	;


// [26] FunctionDecl
// -----------------
FunctionDecl :
		DECLARE_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,NULL,NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [paramlist.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [paramlist.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [paramlist.as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [paramlist.as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<EnclosedExpr*>($6),
								fn_read);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,NULL,NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(@$,driver.symtab.get($2)),
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
			if (debug) cout << "ParamList [single]\n";
			ParamList* plist_p = new ParamList(@$);
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($1));
			}
			$$ = plist_p;
		}
	|	ParamList  COMMA  Param
		{
			if (debug) cout << "ParamList [list]\n";
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
			if (debug) cout << "Param [varname]\n";
			$$ = new Param(@$,
								driver.symtab.get($2),
								NULL);
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
			if (debug) cout << "Param [varname.type]\n";
			$$ = new Param(@$,
								driver.symtab.get($2),
								dynamic_cast<TypeDeclaration*>($3));
		}
	;


// [29] EnclosedExpr
// -----------------
EnclosedExpr :
		LBRACE  Expr  RBRACE
		{
			if (debug) cout << "EnclosedExpr [ ]\n";
			$$ = new EnclosedExpr(@$,
								$2);
		}
	;


// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
			if (debug) cout << "QueryBody [expr]\n";
			$$ = new QueryBody(@$,
								$1);
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
			if (debug) cout << "Expr [single]\n";
			Expr* expr_p = new Expr(@$);
			expr_p->push_back($1);
			$$ = expr_p;
		}
	|	Expr  COMMA  ExprSingle
		{
			if (debug) cout << "Expr [expr.single]\n";
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
			if (debug) cout << "ExprSingle [FLWORExpr]\n";
			$$ = $1;
		}
	|	QuantifiedExpr
		{
			if (debug) cout << "ExprSingle [QuantifiedExpr]\n";
			$$ = $1;
		}
	|	TypeswitchExpr
		{
			if (debug) cout << "ExprSingle [TypeswitchExpr]\n";
			$$ = $1;
		}
	|	IfExpr
		{
			if (debug) cout << "ExprSingle [IfExpr]\n";
			$$ = $1;
		}
	|	OrExpr
		{
			if (debug) cout << "ExprSingle [OrExpr]\n";
			$$ = $1;
		}

		/* update extensions */
	| InsertExpr
		{
			if (debug) cout << "ExprSingle [InsertExpr]\n";
			$$ = $1;
		}
	| DeleteExpr
		{
			if (debug) cout << "ExprSingle [DeleteExpr]\n";
			$$ = $1;
		}
	| RenameExpr
		{
			if (debug) cout << "ExprSingle [RenameExpr]\n";
			$$ = $1;
		}
	| ReplaceExpr
		{
			if (debug) cout << "ExprSingle [ReplaceExpr]\n";
			$$ = $1;
		}
	| TransformExpr
		{
			if (debug) cout << "ExprSingle [TransformExpr]\n";
			$$ = $1;
		}
	;


// [33] FLWORExpr
// --------------
FLWORExpr :
	  ForLetClauseList  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [return]\n";
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								NULL,NULL,
								$3);
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [where.return]\n";
			cout << "ExprSingle typeid = " << typeid(*$4).name() << endl;
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								NULL,
								$4);
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [orderby.return]\n";
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								NULL,
								dynamic_cast<OrderByClause*>($2),
								$4);
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [where.orderby.return]\n";
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
			if (debug) cout << "ForLetClauseList [single]\n";
			ForLetClauseList* flc_list_p = new ForLetClauseList(@$);
			flc_list_p->push_back($1);
			$$ = flc_list_p;
		}
	|	ForLetClauseList  ForLetClause
		{
			if (debug) cout << "ForLetClauseList [list]\n";
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>($1);
			if (flc_list_p) flc_list_p->push_back($2);
			$$ = $1;
		}
	;


// [33b] ForLetClause
// ------------------
ForLetClause :
		ForClause
		{
			if (debug) cout << "ForLetClause [for]\n";
			$$ = $1;
		}
	|	LetClause
		{
			if (debug) cout << "ForLetClause [let]\n";
			$$ = $1;
		}
	;


// [34] ForClause
// --------------
ForClause :
		FOR_DOLLAR  VarInDeclList
		{
			if (debug) cout << "ForClause [ ]\n";
			$$ = new ForClause(@$,
								dynamic_cast<VarInDeclList*>($2));
		}
	;


// [34a] VarInDeclList
// -------------------
VarInDeclList :
		VarInDecl
		{
			if (debug) cout << "VarInDeclList [single]\n";
			VarInDeclList* vardecl_list_p = new VarInDeclList(@$);
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>($1));
			$$ = vardecl_list_p;
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
			if (debug) cout << "VarInDeclList [list]\n";
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
		VARNAME  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,NULL,NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,NULL,
								$4);
		}
	|	VARNAME  PositionalVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [posvar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								NULL,
								$4);
		}
	|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.posvar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								NULL,
								$5);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [posvar.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.posvar.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
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
			if (debug) cout << "PositionalVar [ ]\n";
			$$ = new PositionalVar(@$,
								driver.symtab.get($3));
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  VARNAME
		{
			if (debug) cout << "FTScoreVar [ ]\n";
			$$ = new FTScoreVar(@$,
								driver.symtab.get($3));
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET_DOLLAR VarGetsDeclList
		{
			if (debug) cout << "LetClause [ ]\n";
			$$ = new LetClause(@$,
								dynamic_cast<VarGetsDeclList*>($2));
			
		}
	;


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList :
		VarGetsDecl
		{
			if (debug) cout << "VarGetsDeclList [single]\n";
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(@$);
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($1));
			$$ = vgdl_p;
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
			if (debug) cout << "VarGetsDeclList [list.single]\n";
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
			if (debug) cout << "VarGetsDecl [gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								NULL,
								NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [type.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								$4);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [scorevar.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [type.scorevar.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
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
			if (debug) cout << "WhereClause [ ]\n";
			$$ = new WhereClause(@$,
								$2);
		}
	;


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER_BY  OrderSpecList
		{
			if (debug) cout << "OrderByClause [ ]\n";
			$$ = new OrderByClause(@$,
								dynamic_cast<OrderSpecList*>($2));
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
			if (debug) cout << "OrderByClause [stable]\n";
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
			if (debug) cout << "OrderSpecList [single]\n";
			OrderSpecList* osl_p = new OrderSpecList(@$);
			osl_p->push_back(dynamic_cast<OrderSpec*>($1));
			$$ = osl_p;
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
			if (debug) cout << "OrderSpecList [list]\n";
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
			if (debug) cout << "OrderSpec [single]\n";
			$$ = new OrderSpec(@$,
								$1,
								NULL);
		}
	|	ExprSingle OrderModifier
		{
			if (debug) cout << "OrderSpec [single.modifier]\n";
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
			if (debug) cout << "OrderModifier [dir]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								NULL);
		}
	|	OrderEmptySpec
		{
			if (debug) cout << "OrderModifier [empty]\n";
			$$ = new OrderModifier(@$,
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								NULL);
		}
	|	OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [collation]\n";
			$$ = new OrderModifier(@$,
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>($1));
		}
	|	OrderDirSpec  OrderEmptySpec
		{
			if (debug) cout << "OrderModifier [dir.empty]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderEmptySpec*>($2),
								NULL);
		}
	|	OrderDirSpec  OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [dir.collation]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [empty.collation]\n";
			$$ = new OrderModifier(@$,
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [dir.empty.collation]\n";
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
			if (debug) cout << "OrderDirSpec [ascending]\n";
			$$ = new OrderDirSpec(@$, dir_ascending);
		}
	|	DESCENDING
		{
			if (debug) cout << "OrderDirSpec [descending]\n";
			$$ = new OrderDirSpec(@$, dir_descending);
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
			if (debug) cout << "OrderEmptySpec [greatest]\n";
			$$ = new OrderEmptySpec(@$,
								static_context::empty_greatest);
		}
	|	EMPTY_LEAST
		{
			if (debug) cout << "OrderEmptySpec [least]\n";
			$$ = new OrderEmptySpec(@$,
								static_context::empty_least);
		}
	;


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec :
		COLLATION  URI_LITERAL
		{
			if (debug) cout << "OrderCollationSpec [ ]\n";
			$$ = new OrderCollationSpec(@$,
								driver.symtab.get($2));
		}
	;


// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr :
		SOME_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			if (debug) cout << "QuantifiedExpr [some]\n";
			$$ = new QuantifiedExpr(@$,
								quant_some,
								dynamic_cast<QVarInDeclList*>($2),
								$4);
		}
	|	EVERY_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			if (debug) cout << "QuantifiedExpr [every]\n";
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
			if (debug) cout << "QVarInDeclList [single]\n";
			QVarInDeclList* qvid_list_p = new QVarInDeclList(@$);
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>($1));
			$$ = qvid_list_p;
				
		}
	|	QVarInDecl  COMMA_DOLLAR  QVarInDeclList
		{
			if (debug) cout << "QVarInDeclList [list]\n";
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>($1);
			if (qvid_list_p) {
				qvid_list_p->push_back(dynamic_cast<QVarInDecl*>($3));
			}
			$$ = $1;
		}
	;


// [42b] QVarInDecl
// ----------------
QVarInDecl :
		VARNAME  IN  ExprSingle 
		{
			if (debug) cout << "QVarInDecl [in]\n";
			$$ = new QVarInDecl(@$,
								driver.symtab.get($1),
								$3);
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle 
		{
			if (debug) cout << "QVarInDecl [type.in]\n";
			$$ = new QVarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								$4);
		}
	;


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
			if (debug) cout << "TypeswitchExpr [cases.default.return]\n";
			$$ = new TypeswitchExpr(@$,
								$2,
								dynamic_cast<CaseClauseList*>($4),
								$7);
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
			if (debug) cout << "TypeswitchExpr [cases.default.varname.return]\n";
			$$ = new TypeswitchExpr(@$,
								$2,
								dynamic_cast<CaseClauseList*>($4),
								driver.symtab.get($7),
								$9);
		}
	;


// [43a] CaseClauseList
// --------------------
CaseClauseList :
		CaseClause
		{
			if (debug) cout << "CaseClauseList [single]\n";
			CaseClauseList* cc_list_p = new CaseClauseList(@$);
			cc_list_p->push_back(dynamic_cast<CaseClause*>($1));
			$$ = cc_list_p;
		}
	|	CaseClauseList  CaseClause
		{
			if (debug) cout << "CaseClauseList [list]\n";
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
			if (debug) cout << "CaseClause [case.return]\n";
			$$ = new CaseClause(@$,
								dynamic_cast<SequenceType*>($2),
								$4);
		}
	|	CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
			if (debug) cout << "CaseClause [case.as.return]\n";
			$$ = new CaseClause(@$,
								driver.symtab.get($3),
								dynamic_cast<SequenceType*>($5),
								$7);
		}
	;


// [45] IfExpr
// -----------
IfExpr :
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
			if (debug) cout << "IfExpr [ ]\n";
			$$ = new IfExpr(@$,
								$2, $5, $7);
		}
	;


// [46] OrExpr
// -----------
OrExpr :
		AndExpr
		{
			if (debug) cout << "OrExpr [and]\n";
			$$ = $1;
		}
	|	OrExpr  OR  AndExpr
		{
			if (debug) cout << "OrExpr [or.and]\n";
			$$ = new OrExpr(@$,
								$1, $3);
		}
	;


// [47] AndExpr
// ------------
AndExpr :
		ComparisonExpr
		{
			if (debug) cout << "AndExpr [comp]\n";
			$$ = $1;
		}
	|	AndExpr  AND  ComparisonExpr
		{
			if (debug) cout << "AndExpr [and.comp]\n";
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
			if (debug) cout << "ComparisonExpr [ftcontains]\n";
			$$ = $1;
		}
	| FTContainsExpr  ValueComp  FTContainsExpr
		{
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			if (debug) cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]\n";
			$$ = new ComparisonExpr(@$,
								dynamic_cast<ValueComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  GeneralComp  FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			if (debug) cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
			$$ = new ComparisonExpr(@$,
								dynamic_cast<GeneralComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  NodeComp  FTContainsExpr
		{
			/*  ::=  "is" | "<<" | ">>" */
			if (debug) cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
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
			if (debug) cout << "FTContainsExpr [range]\n";
			$$ = $1;
		}
	|	RangeExpr  FTCONTAINS  FTSelection 
		{
			if (debug) cout << "FTContainsExpr [range.ftselect]\n";
			$$ = new FTContainsExpr(@$,
								$1,
								dynamic_cast<FTSelection*>($3),
								NULL);
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
			if (debug) cout << "FTContainsExpr [range.ftselect.ftignore]\n";
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
			if (debug) cout << "RangeExpr [add]\n";
			$$ = $1;
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
			if (debug) cout << "RangeExpr [add.to.add]\n";
			$$ = new RangeExpr(@$,
								$1, $3);
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr  %prec ADDITIVE_REDUCE
		{
			if (debug) cout << "AdditiveExpr [mult]\n";
			$$ = $1;
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
			if (debug) cout << "AdditiveExpr [mult+mult]\n";
			$$ = new AdditiveExpr(@$, op_plus, $1, $3);
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
			if (debug) cout << "AdditiveExpr [mult-mult]\n";
			$$ = new AdditiveExpr(@$, op_minus, $1, $3);
		}
	;


// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr :
		UnionExpr  %prec MULTIPLICATIVE_REDUCE
		{
			if (debug) cout << "MultiplicativeExpr [union]\n";
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult*union]\n";
			$$ = new MultiplicativeExpr(@$, op_times, $1, $3);
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.div.union]\n";
			$$ = new MultiplicativeExpr(@$, op_div, $1, $3);
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.idiv.union]\n";
			$$ = new MultiplicativeExpr(@$, op_idiv, $1, $3);
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.mod.union]\n";
			$$ = new MultiplicativeExpr(@$, op_mod, $1, $3);
		}
	;


// [52] UnionExpr
// --------------
UnionExpr :
		IntersectExceptExpr  %prec UNION_REDUCE
		{
			if (debug) cout << "UnionExpr [interexcept]\n";
			$$ = $1;
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
			if (debug) cout << "UnionExpr [union.union.interexcept]\n";
			$$ = new UnionExpr(@$,
								$1, $3);
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
			if (debug) cout << "UnionExpr [union|interexcept]\n";
			$$ = new UnionExpr(@$,
								$1, $3);
		}
	;


// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr :
		InstanceofExpr  %prec INTERSECT_EXCEPT_REDUCE
		{
			if (debug) cout << "IntersectExceptExpr [instanceof]\n";
			$$ = $1;
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
			if (debug) cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
			$$ = new IntersectExceptExpr(@$, op_intersect, $1, $3);
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
			if (debug) cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
			$$ = new IntersectExceptExpr(@$, op_except, $1, $3);
		}
	;


// [54] InstanceofExpr
// -------------------
InstanceofExpr :
		TreatExpr
		{
			if (debug) cout << "InstanceofExpr [treat]\n";
			$$ = $1;
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
			if (debug) cout << "InstanceofExpr [treat.seqtype]\n";
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
			if (debug) cout << "TreatExpr [castable]\n";
			$$ = $1;
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
			if (debug) cout << "TreatExpr [castable.seqtype]\n";
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
			if (debug) cout << "CastableExpr [cast]\n";
			$$ = $1;
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
			if (debug) cout << "CastableExpr [cast.singletype]\n";
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
			if (debug) cout << "CastExpr [unary]\n";
			$$ = $1;
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
			if (debug) cout << "CastExpr [unary.singletype]\n";
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
			if (debug) cout << "UnaryExpr [value]\n";
			$$ = $1;
		}
	|	SignList  ValueExpr
		{
			if (debug) cout << "UnaryExpr [signlist.value]\n";
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
			if (debug) cout << "SignList [+]\n";
			$$ = new SignList(@$, true);
		}
	|	MINUS
		{
			if (debug) cout << "SignList [-]\n";
			$$ = new SignList(@$, false);
		}
	|	SignList  PLUS
		{
			if (debug) cout << "SignList [signlist.+]\n";
			$$ = $1;
		}
	|	SignList  MINUS
		{
			if (debug) cout << "SignList [signlist.-]\n";
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
			if (debug) cout << "ValueExpr [validate]\n";
			$$ = $1;
		}
	|	PathExpr
		{
			if (debug) cout << "ValueExpr [path]\n";
			$$ = $1;
		}
	|	ExtensionExpr
		{
			if (debug) cout << "ValueExpr [extension]\n";
			$$ = $1;
		}
	;



// [60] GeneralComp
// ----------------
GeneralComp :
		EQUALS
		{
			if (debug) cout << "GeneralComp [=]\n";
			$$ = new GeneralComp(@$, op_eq);
		}
	| NE
		{
			if (debug) cout << "GeneralComp [!=]\n";
			$$ = new GeneralComp(@$, op_ne);
		}
	| LT
		{
			if (debug) cout << "GeneralComp [<]\n";
			$$ = new GeneralComp(@$, op_lt);
		}
	| LE
		{
			if (debug) cout << "GeneralComp [<=]\n";
			$$ = new GeneralComp(@$, op_le);
		}
	| GT
		{
			if (debug) cout << "GeneralComp [>]\n";
			$$ = new GeneralComp(@$, op_gt);
		}
	| GE
		{
			if (debug) cout << "GeneralComp [>=]\n";
			$$ = new GeneralComp(@$, op_ge);
		}
	;


// [61] ValueComp
// --------------
ValueComp :
		VAL_EQ
		{
			if (debug) cout << "ValueComp [eq]\n";
			$$ = new ValueComp(@$, op_val_eq);
		}
	| VAL_NE
		{
			if (debug) cout << "ValueComp [ne]\n";
			$$ = new ValueComp(@$, op_val_ne);
		}
	| VAL_LT
		{
			if (debug) cout << "ValueComp [lt]\n";
			$$ = new ValueComp(@$, op_val_lt);
		}
	| VAL_LE
		{
			if (debug) cout << "ValueComp [le]\n";
			$$ = new ValueComp(@$, op_val_le);
		}
	| VAL_GT
		{
			if (debug) cout << "ValueComp [gt]\n";
			$$ = new ValueComp(@$, op_val_gt);
		}
	| VAL_GE
		{
			if (debug) cout << "ValueComp [ge]\n";
			$$ = new ValueComp(@$, op_val_ge);
		}
	;


// [62] NodeComp
// -------------
NodeComp :
		IS
		{
			if (debug) cout << "NodeComp [is]\n";
			$$ = new NodeComp(@$, op_is);
		}
	| PRECEDES
		{
			if (debug) cout << "NodeComp [<<]\n";
			$$ = new NodeComp(@$, op_precedes);
		}
	| FOLLOWS
		{
			if (debug) cout << "NodeComp [>>]\n";
			$$ = new NodeComp(@$, op_follows);
		}
	;



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "ValidateExpr [expr]\n";
			$$ = new ValidateExpr(@$, "strict", $2);
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "ValidateExpr [mode.expr]\n";
			$$ = new ValidateExpr(@$,
								driver.symtab.get($1),
								$3);
		}
	;


// [64] ExtensionExpr
// ------------------
ExtensionExpr :
		PragmaList  LBRACE  RBRACE
		{
			if (debug) cout << "ExtensionExpr [pragmalist]\n";
			$$ = new ExtensionExpr(@$,
								dynamic_cast<PragmaList*>($1),
								NULL);
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "ExtensionExpr [pragmalist.expr]\n";
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
			if (debug) cout << "PragmaList [single]\n";
			PragmaList* pragma_list_p = new PragmaList(@$);
			pragma_list_p->push_back(dynamic_cast<Pragma*>($1));
			$$ = pragma_list_p;
		}
	|	PragmaList  Pragma
		{
			if (debug) cout << "PragmaList [list]\n";
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
			if (debug) cout << "Pragma [ ]\n";
			$$ = new Pragma(@$,
								new QName(@$,driver.symtab.get($2)),
								driver.symtab.get($3));

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
			if (debug) cout << "PathExpr [/]\n";
			$$ = new PathExpr(@$, path_leading_lone_slash, NULL);
		}
	|	SLASH  RelativePathExpr
		{
			if (debug) cout << "PathExpr [/relative]\n";
			$$ = new PathExpr(@$, path_leading_slash, $2);
		}
	|	SLASH_SLASH  RelativePathExpr
		{
			if (debug) cout << "PathExpr [//relative]\n";
			$$ = new PathExpr(@$, path_leading_slashslash, $2);
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
			if (debug) cout << "PathExpr [relative]\n";
			$$ = $1;
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
			if (debug) cout << "RelativePathExpr [step]\n";
			$$ = $1;						
		}
	|	StepExpr  SLASH  RelativePathExpr 
		{
			if (debug) cout << "RelativePathExpr [step/relative]\n";
			$$ = new RelativePathExpr(@$, st_slash, $1, $3);
		}
	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
			if (debug) cout << "RelativePathExpr [step//relative]\n";
			$$ = new RelativePathExpr(@$, st_slashslash, $1, $3);
		}
	;


// [69] StepExpr
// -------------
StepExpr :
		AxisStep
		{
			if (debug) cout << "StepExpr [axis]\n";
			$$ = $1;
		}
	|	FilterExpr
		{
			if (debug) cout << "StepExpr [filter]\n";
			$$ = $1;
		}
	;


// [70] AxisStep
// -------------
AxisStep :
		ForwardStep 
		{
			if (debug) cout << "AxisStep [forward]\n";
			$$ = new AxisStep(@$,
								dynamic_cast<ForwardStep*>($1),
								NULL);
		}
	|	ForwardStep  PredicateList
		{
			if (debug) cout << "AxisStep [forward.predlist]\n";
			$$ = new AxisStep(@$,
								dynamic_cast<ForwardStep*>($1),
								dynamic_cast<PredicateList*>($2));
		}
	|	ReverseStep
		{
			if (debug) cout << "AxisStep [reverse]\n";
			$$ = new AxisStep(@$,
								dynamic_cast<ReverseStep*>($1),
								NULL);
		}
	|	ReverseStep  PredicateList
		{
			if (debug) cout << "AxisStep [reverse.predlist]\n";
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
			if (debug) cout << "ForwardStep [nodetest]\n";
			$$ = new ForwardStep(@$,
								dynamic_cast<ForwardAxis*>($1),
								$2);
		}
	|	AbbrevForwardStep
		{
			if (debug) cout << "ForwardStep [abbrev]\n";
			$$ = new ForwardStep(@$,
								dynamic_cast<AbbrevForwardStep*>($1));
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
			if (debug) cout << "ForwardAxis [child]\n";
			$$ = new ForwardAxis(@$, axis_child);
		}
	| DESCENDANT_AXIS
		{
			if (debug) cout << "ForwardAxis [descendant]\n";
			$$ = new ForwardAxis(@$, axis_descendant);
		}
	| ATTRIBUTE_AXIS
		{
			if (debug) cout << "ForwardAxis [attribute]\n";
			$$ = new ForwardAxis(@$, axis_attribute);
		}
	| SELF_AXIS
		{
			if (debug) cout << "ForwardAxis [self]\n";
			$$ = new ForwardAxis(@$, axis_self);
		}
	| DESCENDANT_OR_SELF_AXIS
		{
			if (debug) cout << "ForwardAxis [descendant_or_self]\n";
			$$ = new ForwardAxis(@$, axis_descendant_or_self);
		}
	| FOLLOWING_SIBLING_AXIS
		{
			if (debug) cout << "ForwardAxis [following_sibling]\n";
			$$ = new ForwardAxis(@$, axis_following_sibling);
		}
	| FOLLOWING_AXIS
		{
			if (debug) cout << "ForwardAxis [following]\n";
			$$ = new ForwardAxis(@$, axis_following);
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
			if (debug) cout << "AbbrevForwardStep [nodetest]\n";
			$$ = new AbbrevForwardStep(@$,
								dynamic_cast<NodeTest*>($1));
		}
	|	AT_SIGN  NodeTest
		{
			if (debug) cout << "AbbrevForwardStep [@ nodetest]\n";
			$$ = new AbbrevForwardStep(@$,
								dynamic_cast<NodeTest*>($2), true);
		}
	;


// [74] ReverseStep
// ----------------
ReverseStep :
		ReverseAxis  NodeTest
		{
			if (debug) cout << "ReverseStep [nodetest]\n";
			$$ = new ReverseStep(@$,
								dynamic_cast<ReverseAxis*>($1),
								dynamic_cast<NodeTest*>($2));
		}
	|	DOT_DOT
		{
			if (debug) cout << "ReverseStep [..]\n";
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
			if (debug) cout << "ReverseAxis [parent]\n";
			$$ = new ReverseAxis(@$, axis_parent);
		}
	| ANCESTOR_AXIS
		{
			if (debug) cout << "ReverseAxis [ancestor]\n";
			$$ = new ReverseAxis(@$, axis_ancestor);
		}
	| PRECEDING_SIBLING_AXIS
		{
			if (debug) cout << "ReverseAxis [preceding_sibling]\n";
			$$ = new ReverseAxis(@$, axis_preceding_sibling);
		}
	| PRECEDING_AXIS
		{
			if (debug) cout << "ReverseAxis [preceding]\n";
			$$ = new ReverseAxis(@$, axis_preceding);
		}
	| ANCESTOR_OR_SELF_AXIS
		{
			if (debug) cout << "ReverseAxis [ancestor_or_self]\n";
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
			if (debug) cout << "NodeTest [kindtest]\n";
			$$ = $1;
		}
	|	NameTest
		{
			if (debug) cout << "NodeTest [nametest]\n";
			$$ = $1;
		}
	;
 

// [78] NameTest
// -------------
NameTest :
		QNAME
		{
			if (debug) cout << "NameTest [qname]\n";
			$$ = new NameTest(@$,
								new QName(@$,driver.symtab.get($1)));
		}
	|	Wildcard
		{
			if (debug) cout << "NameTest [wildcard]\n";
			$$ = new NameTest(@$,
								dynamic_cast<Wildcard*>($1));
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
			if (debug) cout << "Wildcard [*]\n";
			$$ = new Wildcard(@$,
									new QName(@$,""),
									wild_all);
		}
	|	ELEM_WILDCARD
		{
			if (debug) cout << "Wildcard [pref:*]\n";
			$$ = new Wildcard(@$,
									new QName(@$,driver.symtab.get($1)),
									wild_elem);
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
			if (debug) cout << "Wildcard [*:qname]\n";
			$$ = new Wildcard(@$,
									new QName(@$,""),
									wild_prefix);
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr 
		{
			if (debug) cout << "FilterExpr [primary]\n";
			$$ = $1;
		}
	|	PrimaryExpr  PredicateList
		{
			if (debug) cout << "FilterExpr [primary.predlist]\n";
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
			if (debug) cout << "PredicateList [single]\n";
			PredicateList* pred_list_p = new PredicateList(@$);
			pred_list_p->push_back(dynamic_cast<exprnode*>($1));
			$$ = pred_list_p;
		}
	|	PredicateList  Predicate
		{
			if (debug) cout << "PredicateList [list]\n";
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
			if (debug) cout << "Predicate [ ]\n";
			$$ = $2;
		}
	;



// [83] PrimaryExpr
// ----------------
PrimaryExpr :
		Literal
		{
			if (debug) cout << "PrimaryExpr [literal]\n";
			$$ = $1;
		}
	|	VarRef
		{
			if (debug) cout << "PrimaryExpr [varref]\n";
			$$ = $1;
		}
	|	ParenthesizedExpr
		{
			if (debug) cout << "PrimaryExpr [paren]\n";
			$$ = $1;
		}
	|	ContextItemExpr
		{
			if (debug) cout << "PrimaryExpr [context_item]\n";
			$$ = $1;
		}
	|	FunctionCall
		{
			if (debug) cout << "PrimaryExpr [funcall]\n";
			$$ = $1;
		}
	|	Constructor
		{
			if (debug) cout << "PrimaryExpr [cons]\n";
			$$ = $1;
		}
	|	OrderedExpr
		{
			if (debug) cout << "PrimaryExpr [ordered]\n";
			$$ = $1;
		}
	|	UnorderedExpr
		{
			if (debug) cout << "PrimaryExpr [unordered]\n";
			$$ = $1;
		}
	;


// [84] Literal
// ------------
Literal :
		NumericLiteral
		{
			if (debug) cout << "Literal [numeric]\n";
			$$ = $1;
		}
	|	StringLiteral
		{
			if (debug) cout << "Literal [string]\n";
			$$ = $1;
		}
	;


// [85] NumericLiteral
// -------------------
NumericLiteral :
		DECIMAL_LITERAL
		{
			if (debug) cout << "NumericLiteral [decimal]\n";
			$$ = new NumericLiteral(@$, yylval.decval);
		}
	| INTEGER_LITERAL
		{
			if (debug) cout << "NumericLiteral [int]\n";
			$$ = new NumericLiteral(@$, yylval.ival);
		}
	|	DOUBLE_LITERAL
		{
			if (debug) cout << "NumericLiteral [double]\n";
			$$ = new NumericLiteral(@$, yylval.dval);
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
			if (debug) cout << "VarRef [ ]\n";
			$$ = new VarRef(@$, driver.symtab.get($2));
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
			if (debug) cout << "ParenthesizedExpr [()]\n";
			$$ = new ParenthesizedExpr(@$, NULL);
		}
	|	LPAR  Expr  RPAR
		{
			if (debug) cout << "ParenthesizedExpr [(expr)]\n";
			$$ = new ParenthesizedExpr(@$,
								$2);
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
			if (debug) cout << "ContextItemExpr [.]\n";
			$$ = new ContextItemExpr(@$);
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "OrderedExpr [expr]\n";
			$$ = new OrderedExpr(@$,
								$2);
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "UnorderedExpr [expr]\n";
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
			if (debug) cout << "FunctionCall [ ]\n";
			$$ = new FunctionCall(@$,
								new QName(@$,driver.symtab.get($1)),
								NULL);
		}
	|	QNAME_LPAR  ArgList  RPAR
		{
			if (debug) cout << "FunctionCall [arglist]\n";
			$$ = new FunctionCall(@$,
								new QName(@$,driver.symtab.get($1)),
								dynamic_cast<ArgList*>($2));
		}
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
			if (debug) cout << "ArgList [single]\n";
			ArgList* a_list_p = new ArgList(@$); 
			a_list_p->push_back($1);
			$$ = a_list_p;
		}
	|	ArgList  COMMA  ExprSingle
		{
			if (debug) cout << "ArgList [list]\n";
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
			if (debug) cout << "Constructor [direct]\n";
			$$ = $1;
		}
	|	ComputedConstructor
		{
			if (debug) cout << "Constructor [computed]\n";
			$$ = $1;
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
			if (debug) cout << "DirectConstructor [element]\n";
			$$ = $1;
		}
	|	DirCommentConstructor
		{
			if (debug) cout << "DirectConstructor [comment]\n";
			$$ = $1;
		}
	|	DirPIConstructor
		{
			if (debug) cout << "DirectConstructor [pi]\n";
			$$ = $1;
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  EMPTY_TAG_END /* ws: explicitXQ */
		{
			if (debug) cout << "DirElemConstructor [<qname/> ]\n";
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								NULL,
								NULL);
		}
	| START_TAG  QNAME  DirAttributeList EMPTY_TAG_END /* ws: explicitXQ */
		{
			if (debug) cout << "DirElemConstructor [<qname attrlist/> ]\n";
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL,
								dynamic_cast<DirAttributeList*>($3), 
								NULL);
		}
	|	START_TAG  QNAME  TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			if (debug) cout << "DirElemConstructor [<qname>content</qname>]\n";
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get($2)),
								new QName(@$,driver.symtab.get($6)),
								NULL,
								dynamic_cast<DirElemContentList*>($4));
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			if (debug) cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
			$$ = new DirElemConstructor(@$,
								new QName(@$,driver.symtab.get($2)),
								new QName(@$,driver.symtab.get($7)),
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
			if (debug) cout << "DirElemContentList [single]\n";
			DirElemContentList* elem_content_list_p = new DirElemContentList(@$);
			elem_content_list_p->push_back($1);
			$$ = elem_content_list_p;
		}
	|	DirElemContentList  DirElemContent
		{
			if (debug) cout << "DirElemContentList [list]\n";
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>($1);
			if (elem_content_list_p) elem_content_list_p->push_back($2);
			$$ = $1;
		}
	;


// [95] DirAttributeList
// ---------------------
DirAttributeList :
		DirAttr
		{
			if (debug) cout << "DirAttributeList [single]\n";
			DirAttributeList* at_list_p = new DirAttributeList(@$);
			at_list_p->push_back(dynamic_cast<DirAttr*>($1));
			$$ = at_list_p;
		}
	|	DirAttributeList  DirAttr
		{
			if (debug) cout << "DirAttributeList [list]\n";
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
			if (debug) cout << "DirAttr [ ]\n";
			$$ = new DirAttr(@$,
								new QName(@$,driver.symtab.get($1)),
								dynamic_cast<DirAttributeValue*>($3));
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  QuoteAttrContentList  QUOTE
		{
			if (debug) cout << "DirAttributeValue [quote]\n";
			$$ = new DirAttributeValue(@$,
								dynamic_cast<QuoteAttrContentList*>($2));
		}
	|	APOS  AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirAttributeValue [apos]\n";
			$$ = new DirAttributeValue(@$,
								dynamic_cast<AposAttrContentList*>($2));
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList :
		ESCAPE_QUOTE
		{
			if (debug) cout << "QuoteAttrContentList [""]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(@$);
			qo_list_p->push_back(new QuoteAttrValueContent(@$,string("\"")));
			$$ = qo_list_p;
		}
	|	QuoteAttrValueContent
		{
			if (debug) cout << "QuoteAttrContentList [single]\n";
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(@$);
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($1));
			$$ = qo_list_p;
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
			if (debug) cout << "QuoteAttrContentList [list ""]\n";
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(@$,string("\"")));
			}
			$$ = $1;
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
			if (debug) cout << "QuoteAttrContentList [list]\n";
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($2));
			}
		}
	;


// [96b] AposAttrContentList
// -------------------------
AposAttrContentList :
		ESCAPE_APOS
		{
			if (debug) cout << "AposAttrContentList ['']\n";
			AposAttrContentList* at_list_p = new AposAttrContentList(@$);
			at_list_p->push_back(new AposAttrValueContent(@$,"'"));
			$$ = at_list_p;
		}
	|	AposAttrValueContent
		{
			if (debug) cout << "AposAttrContentList [single]\n";
			AposAttrContentList* at_list_p = new AposAttrContentList(@$);
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>($1));
			$$ = at_list_p;
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
			if (debug) cout << "AposAttrContentList [list.'']\n";
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>($1);
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(@$,"'"));
			}
			$$ = $1;
		}
	|	AposAttrContentList  AposAttrValueContent
		{
			if (debug) cout << "AposAttrContentList [list.single]\n";
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
			if (debug) cout << "QuoteAttrValueContent [quote_attr_content]\n";
			$$ = new QuoteAttrValueContent(@$,
								driver.symtab.get($1));
		}
	|	CommonContent
		{
			if (debug) cout << "QuoteAttrValueContent [common_content]\n";
			$$ = new QuoteAttrValueContent(@$,
								dynamic_cast<CommonContent*>($1));
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
			if (debug) cout << "AposAttrValueContent [apos_attr_content]\n";
			$$ = new AposAttrValueContent(@$,
								driver.symtab.get($1));
		}
	|	CommonContent
		{
			if (debug) cout << "AposAttrValueContent [common_content]\n";
			$$ = new AposAttrValueContent(@$,
								dynamic_cast<CommonContent*>($1));
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
			if (debug) cout << "DirElemContent [cons]\n";
			$$ = new DirElemContent(@$,
								dynamic_cast<DirectConstructor*>($1));
		}
	|	ELEMENT_CONTENT
		{
			if (debug) cout << "DirElemContent [elem_content]\n";
			$$ = new DirElemContent(@$,
								driver.symtab.get($1));
		}
	|	CDataSection
		{
			if (debug) cout << "DirElemContent [cdata]\n";
			$$ = new DirElemContent(@$,
								dynamic_cast<CDataSection*>($1));
		}
	|	CommonContent
		{
			if (debug) cout << "DirElemContent [common_content]\n";
			$$ = new DirElemContent(@$,
								dynamic_cast<CommonContent*>($1));
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
		ENTITY_REF
		{
			if (debug) cout << "CommonContent [entity_ref]\n";
			$$ = new CommonContent(@$,
								cont_entity,
								driver.symtab.get($1));
		}
	|	CHAR_REF_LITERAL
		{
			if (debug) cout << "CommonContent [char_ref]\n";
			$$ = new CommonContent(@$,
								cont_charref,
								driver.symtab.get($1));
		}
	|	DOUBLE_LBRACE
		{
			if (debug) cout << "CommonContent [{{]\n";
			$$ = new CommonContent(@$,
								cont_escape_lbrace);
		}
	|	DOUBLE_RBRACE
		{
			if (debug) cout << "CommonContent [}}]\n";
			$$ = new CommonContent(@$,
								cont_escape_rbrace);
		}
	|	EnclosedExpr
		{
			if (debug) cout << "CommonContent [expr]\n";
			$$ = new CommonContent(@$,
								dynamic_cast<EnclosedExpr*>($1));
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		XML_COMMENT_BEGIN  EXPR_COMMENT_LITERAL  XML_COMMENT_END 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirCommentConstructor [ ]\n";
			$$ = new DirCommentConstructor(@$,
								driver.symtab.get($2));
		}
	;


// [102] DirCommentContents
// ------------------------
/* lexical rule */


// [103] DirPIConstructor
// ----------------------
DirPIConstructor :
		PI_BEGIN  PI_TARGET_LITERAL  PI_END 								/* ws: explicitXQ */
		{
			if (debug) cout << "DirPIConstructor [target]\n";
			$$ = new DirPIConstructor(@$,
								driver.symtab.get($2));
		}
	|	PI_BEGIN  PI_TARGET_LITERAL  CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirPIConstructor [target.charlit]\n";
			$$ = new DirPIConstructor(@$,
								driver.symtab.get($2),
								driver.symtab.get($3));
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
			if (debug) cout << "CDataSection [ ]\n";
			$$ = new CDataSection(@$,driver.symtab.get($2));
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
			if (debug) cout << "ComputedConstructor [doc]\n";
			$$ = $1;
		}
	|	CompElemConstructor
		{
			if (debug) cout << "ComputedConstructor [elem]\n";
			$$ = $1;
		}
	|	CompAttrConstructor
		{
			if (debug) cout << "ComputedConstructor [attr]\n";
			$$ = $1;
		}
	|	CompTextConstructor
		{
			if (debug) cout << "ComputedConstructor [text]\n";
			$$ = $1;
		}
	|	CompCommentConstructor
		{
			if (debug) cout << "ComputedConstructor [comment]\n";
			$$ = $1;
		}
	|	CompPIConstructor
		{
			if (debug) cout << "ComputedConstructor [pi]\n";
			$$ = $1;
		}
	;


// [108] CompDocConstructor
// ------------------------
CompDocConstructor :
		DOCUMENT_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompDocConstructor [ ]\n";
			$$ = new CompDocConstructor(@$,
								$2);
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
			if (debug) cout << "CompElemConstructor [ ]\n";
			$$ = new CompElemConstructor(@$,
								new QName(@$,driver.symtab.get($1)),
								NULL);
		}
	|	ELEMENT_QNAME_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompElemConstructor [content]\n";
			$$ = new CompElemConstructor(@$,
								new QName(@$,driver.symtab.get($1)),
								$2);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			if (debug) cout << "CompElemConstructor [name]\n";
			$$ = new CompElemConstructor(@$,
								$2, NULL);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompElemConstructor [name.content]\n";
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
			if (debug) cout << "ContentExpr [ ]\n";
		}
	;
*/


// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor :
		ATTRIBUTE_QNAME_LBRACE  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [ ]\n";
			$$ = new CompAttrConstructor(@$,
								new QName(@$,driver.symtab.get($1)),
								NULL);
		}
	|	ATTRIBUTE_QNAME_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [val]\n";
			$$ = new CompAttrConstructor(@$,
								new QName(@$,driver.symtab.get($1)),
								$2);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [name]\n";
			$$ = new CompAttrConstructor(@$,
								$2, NULL);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [name.val]\n";
			$$ = new CompAttrConstructor(@$,
								$2, $5);
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompTextConstructor [content]\n";
			$$ = new CompTextConstructor(@$,
								dynamic_cast<Expr*>($2));
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompCommentConstructor [content]\n";
			$$ = new CompCommentConstructor(@$,
								dynamic_cast<Expr*>($2));
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
			if (debug) cout << "CompPIConstructor [ ]\n";
			$$ = new CompPIConstructor(@$,
								driver.symtab.get($2),
								NULL);
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompPIConstructor [content]\n";
			$$ = new CompPIConstructor(@$,
								driver.symtab.get($2),
								$4);
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
			if (debug) cout << "CompPIConstructor [target]\n";
			$$ = new CompPIConstructor(@$,
								$3, NULL);
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompPIConstructor [target.content]\n";
			$$ = new CompPIConstructor(@$,
								$3, $6);
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
			if (debug) cout << "SingleType [atomic]\n";
			$$ = new SingleType(@$,
								dynamic_cast<AtomicType*>($1),
								false);
		}
	|	AtomicType  HOOK
		{
			if (debug) cout << "SingleType [atomic ?]\n";
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
			if (debug) cout << "TypeDeclaration [as seqtype]\n";
			$$ = new TypeDeclaration(@$,
								dynamic_cast<SequenceType*>($2));
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
			if (debug) cout << "ItemType [type]\n";
			$$ = new SequenceType(@$,
								dynamic_cast<ItemType*>($1),
								NULL);
		}
	|	ItemType  OccurrenceIndicator
		{
			if (debug) cout << "ItemType [type.occurs]\n";
			$$ = new SequenceType(@$,
								dynamic_cast<ItemType*>($1),
								dynamic_cast<OccurrenceIndicator*>($2));
		}
	|	VOID_TEST
		{
			if (debug) cout << "ItemType [void]\n";
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
			if (debug) cout << "OccurrenceIndicator [?]\n";
			$$ = new OccurrenceIndicator(@$,
								occurs_optionally);
		}
	|	OCCURS_STAR
		{
			if (debug) cout << "OccurrenceIndicator [*]\n";
			$$ = new OccurrenceIndicator(@$,
								occurs_zero_or_more);
		}
	|	OCCURS_PLUS 	/* gn: occurrence-indicatorsXQ */
		{
			if (debug) cout << "OccurrenceIndicator [+]\n";
			$$ = new OccurrenceIndicator(@$,
								occurs_one_or_more);
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
			if (debug) cout << "ItemType [atomic]\n";
			$$ = $1;
		}
	|	KindTest
		{
			if (debug) cout << "ItemType [kind]\n";
			$$ = $1;
		}
	|	ITEM_TEST
		{
			if (debug) cout << "ItemType [item]\n";
			$$ = new ItemType(@$,true);
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
			if (debug) cout << "AtomicType [qname]\n";
			$$ = new AtomicType(@$,
								new QName(@$, driver.symtab.get($1)));
		}
	;


// [121] KindTest
// --------------
KindTest :
		DocumentTest
		{
			if (debug) cout << "KindTest [doc]\n";
			$$ = $1;
		}
	| ElementTest
		{
			if (debug) cout << "KindTest [elem]\n";
			$$ = $1;
		}
	| AttributeTest
		{
			if (debug) cout << "KindTest [attr]\n";
			$$ = $1;
		}
	| SchemaElementTest
		{
			if (debug) cout << "KindTest [schema_elem]\n";
			$$ = $1;
		}
	| SchemaAttributeTest
		{
			if (debug) cout << "KindTest [schema_attr]\n";
			$$ = $1;
		}
	| PITest
		{
			if (debug) cout << "KindTest [pi]\n";
			$$ = $1;
		}
	| CommentTest
		{
			if (debug) cout << "KindTest [comment]\n";
			$$ = $1;
		}
	| TextTest
		{
			if (debug) cout << "KindTest [text]\n";
			$$ = $1;
		}
	| AnyKindTest
		{
			if (debug) cout << "KindTest [any]\n";
			$$ = $1;
		}
	;


// [122] AnyKindTest
// -----------------
AnyKindTest :
		NODE_LPAR  RPAR
		{
			if (debug) cout << "AnyKindTest [ ]\n";
			$$ = new AnyKindTest(@$);
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
			if (debug) cout << "DocumentTest [ ]\n";
			$$ = new DocumentTest(@$);
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
			if (debug) cout << "DocumentTest [elem]\n";
			$$ = new DocumentTest(@$,
								dynamic_cast<ElementTest*>($2));
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
			if (debug) cout << "DocumentTest [schema_elem]\n";
			$$ = new DocumentTest(@$,
								dynamic_cast<SchemaElementTest*>($2));
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
			if (debug) cout << "TextTest [ ]\n";
			$$ = new TextTest(@$);
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
			if (debug) cout << "CommentTest [ ]\n";
			$$ = new CommentTest(@$);
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
			if (debug) cout << "PITest [ ]\n";
			$$ = new PITest(@$, "", "");
		}
	|	PI_LPAR  NCNAME  RPAR
		{
			if (debug) cout << "PITest [ncname]\n";
			$$ = new PITest(@$, driver.symtab.get($2), "");
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
			if (debug) cout << "PITest [stringlit]\n";
			$$ = new PITest(@$, "", driver.symtab.get($2));
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
			if (debug) cout << "AttributeTest [ ]\n";
			$$ = new AttributeTest(@$,
								NULL,
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  RPAR
		{
			if (debug) cout << "AttributeTest [name]\n";
			$$ = new AttributeTest(@$,
								new QName(@$,driver.symtab.get($2)),
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  COMMA  TypeName  RPAR
		{
			if (debug) cout << "AttributeTest [name.type]\n";
			$$ = new AttributeTest(@$,
								new QName(@$,driver.symtab.get($2)),
								dynamic_cast<TypeName*>($4));
		}
	|	ATTRIBUTE_LPAR  STAR  RPAR
		{
			if (debug) cout << "AttributeTest [*]\n";
			$$ = new AttributeTest(@$,
								NULL,
								NULL,
								true);
		}
	|	ATTRIBUTE_LPAR  STAR  COMMA  TypeName  RPAR
		{
			if (debug) cout << "AttributeTest [*.type]\n";
			$$ = new AttributeTest(@$,
								NULL,
								dynamic_cast<TypeName*>($4),
								true);
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  QNAME  RPAR
		{
			if (debug) cout << "SchemaAttributeTest [ ]\n";
			$$ = new SchemaAttributeTest(@$,
								new QName(@$, driver.symtab.get($2)));
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
			if (debug) cout << "ElementTest [ ]\n";
			$$ = new ElementTest(@$,
									NULL,
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  RPAR
		{
			if (debug) cout << "ElementTest [name]\n";
			$$ = new ElementTest(@$,
									new QName(@$,driver.symtab.get($2)),
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  COMMA  TypeName  RPAR
		{
			if (debug) cout << "ElementTest [name.type]\n";
			$$ = new ElementTest(@$,
									new QName(@$,driver.symtab.get($2)),
									dynamic_cast<TypeName*>($4));
		}
	|	ELEMENT_LPAR  STAR  RPAR
		{
			if (debug) cout << "ElementTest [*]\n";
			$$ = new ElementTest(@$,
									NULL,
									NULL,
									true);
		}
	|	ELEMENT_LPAR  STAR  COMMA  TypeName  RPAR
		{
			if (debug) cout << "ElementTest [*.type]\n";
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
			if (debug) cout << "SchemaElementTest [ ]\n";
			$$ = new SchemaElementTest(@$,
									new QName(@$,driver.symtab.get($2)));
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
			if (debug) cout << "TypeName [name]\n";
			$$ = new TypeName(@$,
								new QName(@$,driver.symtab.get($1)));
		}
	| QNAME  HOOK
		{
			if (debug) cout << "TypeName [name?]\n";
			$$ = new TypeName(@$,
								new QName(@$,driver.symtab.get($1)),
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
			if (debug) cout << "StringLiteral [ ]\n";
			$$ = new StringLiteral(@$, driver.symtab.get($1));
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
			if (debug) cout << "RevalidationDecl [ ]\n";
		}
	;


// [242]	InsertExpr
// ----------------
InsertExpr :
		DO_INSERT  ExprSingle  INTO  ExprSingle
		{
			if (debug) cout << "InsertExpr [expr]\n";
		}
	|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
		{
			if (debug) cout << "InsertExpr [expr.as_first]\n";
		}
	|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
		{
			if (debug) cout << "InsertExpr [expr.as_last]\n";
		}
	| DO_INSERT  ExprSingle  AFTER  ExprSingle
		{
			if (debug) cout << "InsertExpr [expr.after]\n";
		}
	| DO_INSERT  ExprSingle  BEFORE  ExprSingle
		{
			if (debug) cout << "InsertExpr [expr.before]\n";
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		DO_DELETE  ExprSingle
		{
			if (debug) cout << "DeleteExpr [expr]\n";
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		DO_REPLACE  ExprSingle  WITH  ExprSingle
		{
			if (debug) cout << "ReplaceExpr [expr.expr]\n";
		}
	|	DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
		{
			if (debug) cout << "ReplaceExpr [value.expr]\n";
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		DO_RENAME  ExprSingle  AS  ExprSingle
		{
			if (debug) cout << "RenameExpr [expr.expr]\n";
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
			if (debug) cout << "TransformExpr [ ]\n";
		}
	;


// [249a] VarNameList
// ------------------
VarNameList :
		VARNAME	 GETS  ExprSingle
		{
			if (debug) cout << "VarNameList [single]\n";
		}
	|	VarNameList  COMMA_DOLLAR  VARNAME  GETS  ExprSingle
		{
			if (debug) cout << "VarNameList [list]\n";
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
			if (debug) cout << "FTSelection [or]\n";
		}
	|	FTOr  FTMatchOptionProximityList
		{
			if (debug) cout << "FTSelection [or.match_proximity]\n";
		}
	|	FTOr  WEIGHT  RangeExpr
		{
			if (debug) cout << "FTSelection [or.weight_range]\n";
		}
	|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
		{
			if (debug) cout << "FTSelection [or.match_proximity.weight_range]\n";
		}
	;


//[344a] FTMatchOptionProximityList
//---------------------------------
FTMatchOptionProximityList :
		FTMatchOption
		{
			if (debug) cout << "FTMatchOptionProximityList [option_single]\n";
		}
	| FTProximity
		{
			if (debug) cout << "FTMatchOptionProximityList [proximity_single]\n";
		}
	| FTMatchOptionProximityList  FTMatchOption
		{
			if (debug) cout << "FTMatchOptionProximityList [option_list]\n";
		}
	| FTMatchOptionProximityList  FTProximity
		{
			if (debug) cout << "FTMatchOptionProximityList [proximity_list]\n";
		}
	;


//[345]	FTOr
//----------
FTOr :
		FTAnd
		{
			if (debug) cout << "FTOr [and]\n";
		}
	|	FTOr  FTOR  FTAnd
		{
			if (debug) cout << "FTOr [or.and]\n";
		}
	;


//[346]	FTAnd
//-----------
FTAnd :
		FTMildnot
		{
			if (debug) cout << "FTAnd [mild_not]\n";
		}
	|	FTAnd  FTAND  FTMildnot
		{
			if (debug) cout << "FTAnd [and.mild_not]\n";
		}
	;


//[347]	FTMildnot
//---------------
FTMildnot :
		FTUnaryNot
		{
			if (debug) cout << "FTMildNot [unary_not]\n";
		}
	|	FTMildnot  FTNOT_IN  FTUnaryNot
		{
			if (debug) cout << "FTMildNot [mild_not.unary_not]\n";
		}
	;


//[348]	FTUnaryNot
//----------------
FTUnaryNot :
		FTWordsSelection
		{
			if (debug) cout << "FTUnaryNot [words]\n";
		}
	|	FTNOT  FTWordsSelection
		{
			if (debug) cout << "FTUnaryNot [not.words]\n";
		}
	;


//[349]	FTWordsSelection
//----------------------
FTWordsSelection :
		FTWords
		{
			if (debug) cout << "FTWordsSelection [words]\n";
		}
	|	FTWords FTTimes
		{
			if (debug) cout << "FTWordsSelection [words.times]\n";
		}
	| LPAR  FTSelection  RPAR
		{
			if (debug) cout << "FTWordsSelection [selection]\n";
		}
	;


//[350]	FTWords
//-------------
FTWords :
		FTWordsValue 
		{
			if (debug) cout << "FTWords [value]\n";
		}
	|	FTWordsValue  FTAnyallOption
		{
			if (debug) cout << "FTWords [value.any_all_option]\n";
		}
	;


//[351]	FTWordsValue
//------------------
FTWordsValue :
		Literal
		{
			if (debug) cout << "FTWordsValue [literal]\n";
		}
	| LBRACE  Expr  RBRACE
		{
			if (debug) cout << "FTWordsValue [expr]\n";
		}
	;


//[352]	FTProximity
//-----------------
FTProximity :
		FTOrderedIndicator
		{
			if (debug) cout << "FTProximity [order]\n";
		}
	| FTWindow
		{
			if (debug) cout << "FTProximity [window]\n";
		}
	| FTDistance
		{
			if (debug) cout << "FTProximity [distance]\n";
		}
	| FTScope
		{
			if (debug) cout << "FTProximity [scope]\n";
		}
	| FTContent
		{
			if (debug) cout << "FTProximity [content]\n";
		}
	;


//[353]	FTOrderedIndicator
//------------------------
FTOrderedIndicator :
		ORDERED
		{
			if (debug) cout << "FTOrderedIndicator [ ]\n";
		}
	;


//[354] FTMatchOption 	
//-------------------
FTMatchOption :
		FTCaseOption
		{
			if (debug) cout << "FTMatchOption [case]\n";
			$$ = $1;
		}
	| FTDiacriticsOption
		{
			if (debug) cout << "FTMatchOption [diacritics]\n";
			$$ = $1;
		}
	| FTStemOption
		{
			if (debug) cout << "FTMatchOption [stem]\n";
			$$ = $1;
		}
	| FTThesaurusOption
		{
			if (debug) cout << "FTMatchOption [thesaurus]\n";
			$$ = $1;
		}
	| FTStopwordOption
		{
			if (debug) cout << "FTMatchOption [stopword]\n";
			$$ = $1;
		}
	| FTLanguageOption
		{
			if (debug) cout << "FTMatchOption [language]\n";
			$$ = $1;
		}
	| FTWildcardOption
		{
			if (debug) cout << "FTMatchOption [wildcard]\n";
			$$ = $1;
		}
	;


//[355] FTCaseOption
//------------------
FTCaseOption :
		LOWERCASE
		{
			if (debug) cout << "FTCaseOption [lower]\n";
		}
	| UPPERCASE
		{
			if (debug) cout << "FTCaseOption [upper]\n";
		}
	| CASE_SENSITIVE
		{
			if (debug) cout << "FTCaseOption [sensitive]\n";
		}
	| CASE_INSENSITIVE
		{
			if (debug) cout << "FTCaseOption [insensitive]\n";
		}
	;


//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption :
		WITH_DIACRITICS
		{
			if (debug) cout << "FTDiacriticsOption [with]\n";
		}
	| WITHOUT_DIACRITICS
		{
			if (debug) cout << "FTDiacriticsOption [without]\n";
		}
	| DIACRITICS_SENSITIVE
		{
			if (debug) cout << "FTDiacriticsOption [sensitive]\n";
		}
	| DIACRITICS_INSENSITIVE
		{
			if (debug) cout << "FTDiacriticsOption [insensitive]\n";
		}
	;


//[357] FTStemOption
//------------------
FTStemOption :
		WITH_STEMMING
		{
			if (debug) cout << "FTStemOption [with]\n";
		}
	| WITHOUT_STEMMING
		{
			if (debug) cout << "FTStemOption [without]\n";
		}
	;


//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption :
		WITH_THESAURUS  FTThesaurusID
		{
			if (debug) cout << "FTThesaurusOption [id]\n";
		}
	|	WITH_THESAURUS  DEFAULT
		{
			if (debug) cout << "FTThesaurusOption [default]\n";
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID  RPAR
		{
			if (debug) cout << "FTThesaurusOption [(id)]\n";
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
		{
			if (debug) cout << "FTThesaurusOption [(id,id,..)]\n";
		}
	| WITH_THESAURUS  LPAR  DEFAULT  RPAR
		{
			if (debug) cout << "FTThesaurusOption [(default)]\n";
		}
	| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
		{
			if (debug) cout << "FTThesaurusOption [(default,id,id,..)]\n";
		}
	| WITHOUT_THESAURUS
		{
			if (debug) cout << "FTThesaurusOption [without]\n";
		}
	;


//[358a] FTThesaurusIDList
//------------------------
FTThesaurusList :
		FTThesaurusID
		{
			if (debug) cout << "FTThesaurusList [single]\n";
		}
	| FTThesaurusList  COMMA  FTThesaurusID
		{
			if (debug) cout << "FTThesaurusList [list]\n";
		}
	;


//[359] FTThesaurusID
//-------------------
FTThesaurusID :
		AT  STRING_LITERAL
		{
			if (debug) cout << "FTThesaurusID [name]\n";
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
		{
			if (debug) cout << "FTThesaurusID [name.rel]\n";
		}
	|	AT  STRING_LITERAL  FTRange  LEVELS
		{
			if (debug) cout << "FTThesaurusID [name.range]\n";
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
		{
			if (debug) cout << "FTThesaurusID [name.rel.range]\n";
		}
	;


//[360] FTStopwordOption
//----------------------
FTStopwordOption :
		WITH_STOP_WORDS  FTRefOrList
		{
			if (debug) cout << "FTStopwordOption [list]\n";
		}
	|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
		{
			if (debug) cout << "FTStopwordOption [list.incl_excl]\n";
		}
	| WITH_DEFAULT_STOP_WORDS 
		{
			if (debug) cout << "FTStopwordOption [default]\n";
		}
	| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
		{
			if (debug) cout << "FTStopwordOption [default.incl_excl]\n";
		}
	| WITHOUT_STOP_WORDS
		{
			if (debug) cout << "FTStopwordOption [without]\n";
		}
	;


//[360a] FTInclExclStringLiteralList
//----------------------------------
FTInclExclStringLiteralList :
		FTInclExclStringLiteral
		{
			if (debug) cout << "FTInclExclStringLiteralList [.]\n";
		}
	| FTInclExclStringLiteralList  FTInclExclStringLiteral
		{
			if (debug) cout << "FTInclExclStringLiteralList [*]\n";
		}
	;


//[361] FTRefOrList
//-----------------
FTRefOrList :
		AT  STRING_LITERAL
		{
			if (debug) cout << "FTRefOrList [.]\n";
		}
	| LPAR  FTStringLiteralList  RPAR 
		{
			if (debug) cout << "FTRefOrList [(*)]\n";
		}
	;


//[361a] FTStringLiteralList
//--------------------------
FTStringLiteralList :
		STRING_LITERAL
		{
			if (debug) cout << "FTStringLiteralList [.]\n";
		}
	|	FTStringLiteralList  STRING_LITERAL
		{
			if (debug) cout << "FTStringLiteralList [*]\n";
		}
	;


//[362] FTInclExclStringLiteral
//-----------------------------
FTInclExclStringLiteral :
		UNION  FTRefOrList
		{
			if (debug) cout << "FTInclExclStringLiteral [union]\n";
		}
	|	EXCEPT  FTRefOrList
		{
			if (debug) cout << "FTInclExclStringLiteral [except]\n";
		}
	;


//[363] FTLanguageOption
//----------------------
FTLanguageOption :
		LANGUAGE  STRING_LITERAL
		{
			if (debug) cout << "FTLanguageOption [ ]\n";
		}
	;


//[364] FTWildcardOption
//----------------------
FTWildcardOption :
		WITH_WILDCARDS
		{
			if (debug) cout << "FTWildcardOption [with]\n";
		}
	| WITHOUT_WILDCARDS
		{
			if (debug) cout << "FTWildcardOption [without]\n";
		}
	;


//[365]	FTContent
//---------------
FTContent :
		AT_START
		{
			if (debug) cout << "FTContent [start]\n";
		}
	| AT_END
		{
			if (debug) cout << "FTContent [end]\n";
		}
	| ENTIRE_CONTENT
		{
			if (debug) cout << "FTContent [entire]\n";
		}
	;


//[366]	FTAnyallOption
//--------------------
FTAnyallOption :
		ANY
		{
			if (debug) cout << "FTAnyallOption [any]\n";
		}
	|	ANY_WORD
		{
			if (debug) cout << "FTAnyallOption [any_word]\n";
		}
	| ALL
		{
			if (debug) cout << "FTAnyallOption [all]\n";
		}
	| ALL_WORDS
		{
			if (debug) cout << "FTAnyallOption [all_words]\n";
		}
	| PHRASE
		{
			if (debug) cout << "FTAnyallOption [phrase]\n";
		}
	;


//[367]	FTRange
//-------------
FTRange :
		EXACTLY  UnionExpr
		{
			if (debug) cout << "FTRange [exactly]\n";
		}
	| AT_LEAST  UnionExpr
		{
			if (debug) cout << "FTRange [at_least]\n";
		}
	| AT_MOST  UnionExpr
		{
			if (debug) cout << "FTRange [at_most]\n";
		}
	| FROM  UnionExpr  TO  UnionExpr
		{
			if (debug) cout << "FTRange [range]\n";
		}
	;


//[368]	FTDistance
//----------------
FTDistance :
		DISTANCE  FTRange  FTUnit
		{
			if (debug) cout << "FTDistance [ ]\n";
		}
	;


//[369]	FTWindow
//--------------
FTWindow :
		WINDOW  UnionExpr  FTUnit
		{
			if (debug) cout << "FTWindow [ ]\n";
		}
	;


//[370]	FTTimes
//-------------
FTTimes :
		OCCURS  FTRange  TIMES
		{
			if (debug) cout << "FTTimes [ ]\n";
		}
	;


//[371]	FTScope
//-------------
FTScope :
		SAME  FTBigUnit
		{
			if (debug) cout << "FTTimes [same]\n";
		}
	|	DIFFERENT  FTBigUnit
		{
			if (debug) cout << "FTTimes [different]\n";
		}
	;


//[372]	FTUnit
//------------
FTUnit :
		WORDS
		{
			if (debug) cout << "FTUnit [words]\n";
		}
	| SENTENCES
		{
			if (debug) cout << "FTUnit [sentences]\n";
		}
	| PARAGRAPH
		{
			if (debug) cout << "FTUnit [paragraph]\n";
		}
	;


//[373]	FTBigUnit
//---------------
FTBigUnit :
		SENTENCE
		{
			if (debug) cout << "FTBigUnit [sentence]\n";
		}
	| PARAGRAPH
		{
			if (debug) cout << "FTBigUnit [paragraph]\n";
		}
	;


//[374]	FTIgnoreOption
//--------------------
FTIgnoreOption :
		WITHOUT_CONTENT  UnionExpr
		{
			if (debug) cout << "FTIgnoreOption [ ]\n";
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




