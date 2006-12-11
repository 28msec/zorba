/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery_parser.y,v 1.2 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
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

#include "../context/static_context.h"
#include "parsenodes.h"

class xquery_driver;

using namespace std;
using namespace xqp;

namespace xqp {
	class parsenode;
}

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
  off_t sval;
	int ival;
	double dval;
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
%type <node> CommentTest
%type <node> CommonContent
%type <node> CompAttrConstructor
%type <node> CompCommentConstructor
%type <node> CompDocConstructor
%type <node> CompElemConstructor
%type <node> CompPIConstructor
%type <node> CompTextConstructor
%type <node> ComputedConstructor
%type <node> ConstructionDecl
%type <node> Constructor
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
%type <node> ForLetClause
%type <node> ForLetClauseList
%type <node> ForwardAxis
%type <node> ForwardStep
%type <node> FunctionCall
%type <node> FunctionDecl
%type <node> GeneralComp
%type <node> Import
%type <node> InheritMode
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
%type <node> Predicate
%type <node> PredicateList
%type <node> PreserveMode
%type <node> Prolog
%type <node> QVarInDecl
%type <node> QVarInDeclList
%type <node> QueryBody
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
%type <node> VarRef
%type <node> VersionDecl
%type <node> VFO_Decl
%type <node> VFO_DeclList
%type <node> WhereClause
%type <node> Wildcard


/* left-hand sides: expressions */
/* ---------------------------- */
%type <node> AdditiveExpr
%type <node> AndExpr
%type <node> CastExpr
%type <node> CastableExpr
%type <node> ComparisonExpr
//%type <node> ContentExpr
%type <node> ContextItemExpr
%type <node> EnclosedExpr
%type <node> Expr
%type <node> ExprSingle
%type <node> ExtensionExpr
%type <node> FLWORExpr
%type <node> FilterExpr
%type <node> ForClause
%type <node> IfExpr
%type <node> InstanceofExpr
%type <node> IntersectExceptExpr
%type <node> Literal
%type <node> MultiplicativeExpr
%type <node> NumericLiteral
%type <node> OrExpr
%type <node> OrderedExpr
%type <node> ParenthesizedExpr
%type <node> PathExpr
%type <node> PrimaryExpr
%type <node> QuantifiedExpr
%type <node> RangeExpr
%type <node> RelativePathExpr
%type <node> StepExpr
%type <node> TreatExpr
%type <node> TypeswitchExpr
%type <node> UnaryExpr
%type <node> UnionExpr
%type <node> UnorderedExpr
%type <node> ValidateExpr
%type <node> ValueExpr


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
			$$ = new SIND_DeclList(@$,
								dynamic_cast<SIND_Decl*>($1));
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
			if (debug) cout << "SIND_DeclList [list]\n";
			SIND_DeclList* sindList_p = dynamic_cast<SIND_DeclList*>($1);
			if (sindList_p) {
				sindList_p->push_back(dynamic_cast<SIND_Decl*>($3));
			}
			$$ = sindList_p;
		}
	;


// [6b] VFO_DeclList
// -----------------
VFO_DeclList :
		VFO_Decl
		{
			if (debug) cout << "VFO_DeclList [single]\n";
			$$ = new VFO_DeclList(@$,
								dynamic_cast<VFO_Decl*>($1));
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
			if (debug) cout << "VFO_DeclList [list]\n";
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>($1);
			if (vfoList_p) {
				vfoList_p->push_back(dynamic_cast<VFO_Decl*>($3));
			}
			$$ = vfoList_p;
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
								static_context::preserve);
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
			if (debug) cout << "BoundarySpaceDecl [strip]\n";
			$$ = new BoundarySpaceDecl(@$,
								static_context::strip);
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
			if (debug) cout << "DefaultNamespaceDecl [element]\n";
			$$ = new DefaultNamespaceDecl(
								DefaultNamespaceDecl::element,
								driver.symtab.get($3));
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
			if (debug) cout << "DefaultNamespaceDecl [function]\n";
			$$ = new DefaultNamespaceDecl(
								DefaultNamespaceDecl::function,
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
								new QName(driver.symtab.get($2)),
								driver.symtab.get($3));
		}
	;


/* full-text extension */
// [13a] OptionDecl
// ---------------
FTOptionDecl :
		DECLARE_FTOPTION  QNAME  FTMatchOption
		{
			if (debug) cout << "FTOptionDecl [ ]\n";
			$$ = new FTOptionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<FTMatchOption*>($3));
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
			if (debug) cout << "OrderingDecl [ordered]\n";
			$$ = new OrderingModeDecl(@$,
								static_context::ordered);
		}
	| DECLARE_ORDERING  UNORDERED
		{
			if (debug) cout << "OrderingDecl [unordered]\n";
			$$ = new OrderingModeDecl(@$,
								static_context::unordered);
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
			if (debug) cout << "EmptyOrderDecl [empty greatest]\n";
			$$ = new EmptyOrderDecl(@$,
								static_context::greatest);
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
			if (debug) cout << "EmptyOrderDecl [empty least]\n";
			$$ = new EmptyOrderDecl(@$,
								static_context::least);
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
		{
			if (debug) cout << "CopyNamespacesDecl [ ]\n";
			$$ = new CopyNamespacesDecl(@$,
								dynamic_cast<PreserveMode*>($2),
								dynamic_cast<InheritMode*>($4));
		}
	;


// [17] PreserveMode
// -----------------
PreserveMode :
		PRESERVE
		{
			if (debug) cout << "PreserveMode [preserve]\n";
			$$ = new PreserveMode(@$,
								static_context::preserve);
		}
	| NO_PRESERVE
		{
			if (debug) cout << "PreserveMode [no preserve]\n";
			$$ = new PreserveMode(@$,
								static_context::no_preserve);
		}
	;


// [18] InheritMode
// ----------------
InheritMode :
		INHERIT
		{
			if (debug) cout << "InheritMode [inherit]\n";
			$$ = new InheritMode(@$,
								static_context::inherit);
		}
	| NO_INHERIT
		{
			if (debug) cout << "InheritMode [no inherit]\n";
			$$ = new InheritMode(@$,
								static_context::no_inherit);
		}
	;


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
								dynamic_cast<SchemaPrefix>($2),
								driver.symtab.get($2),
								NULL);
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "SchemaImport [uri.urilist]\n";
			$$ = new SchemaImport(@$,
								NULL,
								driver.symtab.get($2),
								dynamic_cast<URILIteralList*>($4),
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
		{
			if (debug) cout << "SchemaImport [prefix.uri.aturi]\n";
			$$ = new SchemaImport(@$,
								dynamic_cast<SchemaPrefix>($2),
								driver.symtab.get($3),
								dynamic_cast<URILIteralList*>($5),
		}
	;


// [21a] URLLiteralList
// --------------------
URILiteralList :
		URI_LITERAL
		{
			if (debug) cout << "URILiteralList [single]\n";
			URLLiteralList* uri_list_p = new URILiteralList(@$);
			uri_list_p->push_back(driver.symtab.get($1));
			return uri_list_p;
		}
	| URILiteralList  COMMA  URI_LITERAL
		{
			if (debug) cout << "URILiteralList [list]\n";
			URLLiteralList* uri_list_p = dynamic_cast<URILiteralList*>($1);
			if (uri_list_p) {
				uri_list_p->push_back(driver.symtab.get($3));
			}
			return $1;
		}
	;



// [22] SchemaPrefix
// -----------------
SchemaPrefix :
		NAMESPACE  NCNAME  EQUALS
		{
			if (debug) cout << "SchemaPrefix [namespace]\n";
			$$ = new SchemaPrefix(@$,
								driver.symtab.get($2));
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
			if (debug) cout << "SchemaPrefix [default element]\n";
			$$ = new SchemaPrefix(@$,
								true);
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
								dynamic_cast<ExprSingle*>($4));
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
			if (debug) cout << "VarDecl [external]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								NULL,
								true);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			if (debug) cout << "VarDecl [type.expr]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								dynamic_cast<TypeDeclaration*>($3),
								dynamic_cast<ExprSingle*>($5));
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
			if (debug) cout << "VarDecl [type.external]\n";
			$$ = new VarDecl(@$,
								driver.symtab.get($2),
								dynamic_cast<TypeDeclaration*>($3),
								true);
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE_CONSTRUCTION  PRESERVE
		{
			if (debug) cout << "ConstructionDecl [preserve]\n";
			$$ = new ContructionDecl(@$,
								static_context::preserve);
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
			if (debug) cout << "ConstructionDecl [strip]\n";
			$$ = new ContructionDecl(@$,
								static_context::strip);
		}
	;


// [26] FunctionDecl
// -----------------
FunctionDecl :
		DECLARE_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,NULL,NULL,
								FunctionDecl::fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								FunctionDecl::fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [paramlist.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								FunctionDecl::fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [paramlist.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								FunctionDecl::fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								FunctionDecl::fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								FunctionDecl::fn_read);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [paramlist.as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								FunctionDecl::fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [paramlist.as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<EnclosedExpr*>($6),
								FunctionDecl::fn_read);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,NULL,NULL,
								FunctionDecl::fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,NULL,
								dynamic_cast<EnclosedExpr*>($4),
								FunctionDecl::fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,NULL,
								FunctionDecl::fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								NULL,
								dynamic_cast<EnclosedExpr*>($5),
								FunctionDecl::fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								NULL,
								FunctionDecl::fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								NULL,
								dynamic_cast<SequenceType*>($4),
								dynamic_cast<EnclosedExpr*>($5),
								FunctionDecl::fn_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								NULL,
								FunctionDecl::fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			if (debug) cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
			$$ = new FunctionDecl(@$,
								new QName(driver.symtab.get($2)),
								dynamic_cast<ParamList*>($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<EnclosedExpr*>($6),
								FunctionDecl::fn_update);
		}
	;


// [27] ParamList
// --------------
ParamList :
		Param
		{
			if (debug) cout << "ParamList [single]\n";
			ParamList* plist_p = new ParamList(@$,);
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($1));
			}
			return plist_p;
		}
	|	ParamList  COMMA  Param
		{
			if (debug) cout << "ParamList [list]\n";
			ParamList* plist_p = dynamic_cast<ParamList*>($1);
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($3));
			}
			return $1;
		}
	;


// [28] Param
// ----------
Param :
		DOLLAR  VARNAME
		{
			if (debug) cout << "Param [varname]\n";
			$$ = new Param(@$,
								driver.symtab.get($2));
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
								dynamic_cast<Expr*>($2));
		}
	;


// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
			if (debug) cout << "QueryBody [expr]\n";
			$$ = new QueryBody(@$,
								dynamic_cast<Expr*>($1));
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
			if (debug) cout << "Expr [single]\n";
			Expr* expr_p = new Expr(@$,);
			expr_p->push_back(dynamic_cast<ExprSingle*>($1));
			$$ = expr_p;
		}
	|	Expr  COMMA  ExprSingle
		{
			if (debug) cout << "Expr [expr.single]\n";
			Expr* expr_p = dynamic_cast<Expr*>($1);
			if (expr_p) { 
				expr_p->push_back(dynamic_cast<ExprSingle*>($3));
			}
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
								dynamic_cast<ExprSingle*>($3));
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [where.return]\n";
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								NULL,
								dynamic_cast<ExprSingle*>($4));
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [orderby.return]\n";
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								NULL,
								dynamic_cast<OrderByClause*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
			if (debug) cout << "FLWORExpr [where.orderby.return]\n";
			$$ = new FLWORExpr(@$,
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								dynamic_cast<OrderByClause*>($3),
								dynamic_cast<ExprSingle*>($5));
		}
	;


// [33a] ForLetClauseList
// ----------------------
ForLetClauseList :
		ForLetClause
		{
			if (debug) cout << "ForLetClauseList [single]\n";
			ForLetClauseList* flc_list_p = new ForLetClauseList(@$,);
			flc_list_p->push_back(dynamic_cast<ForLetClause*>($1);
			$$ = flc_list_p;
		}
	|	ForLetClauseList  ForLetClause
		{
			if (debug) cout << "ForLetClauseList [list]\n";
			ForLetClauseList* flc_list_p = dynamic_cast<ForLetClauseList*>($1);
			if (flc_list_p) {
				flc_list_p->push_back(dynamic_cast<ForLetClause*>($2);
			}
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
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
			if (debug) cout << "VarInDeclList [list]\n";
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
								dynamic_cast<ExprSingle*>($3));
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,NULL,
								dynamic_cast<ExprSingle*>($4));
		}
	|	VARNAME  PositionalVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [posvar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								NULL,
								dynamic_cast<ExprSingle*>($4));
		}
	|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.posvar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								NULL,
								dynamic_cast<ExprSingle*>($5));
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	| VARNAME  TypeDeclaration  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								dynamic_cast<FTScoreVar*>($3),
								dynamic_cast<ExprSingle*>($5));
		}
	| VARNAME  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [posvar.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								dynamic_cast<FTScoreVar*>($3),
								dynamic_cast<ExprSingle*>($5));
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			if (debug) cout << "VarInDecl [type.posvar.scorevar.in]\n";
			$$ = new VarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								dynamic_cast<FTScoreVar*>($4),
								dynamic_cast<ExprSingle*>($6));
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
			VarGetsDeclList vgdl_p = new VarGetsDeclList(@$,);
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($1));
			$$ = vgdl_p;
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
			if (debug) cout << "VarGetsDeclList [list.single]\n";
			VarGetsDeclList vgdl_p = dynamic_cast<VarGetsDeclList*>($1);
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
								dynamic_cast<ExprSingle*>($3));
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [type.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [scorevar.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<FTScoreVar*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
			if (debug) cout << "VarGetsDecl [type.scorevar.gets]\n";
			$$ = new VarGetsDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<FTScoreVar*>($3),
								dynamic_cast<ExprSingle*>($5));
		}
	;



// [37] WhereClause
// ----------------
WhereClause :
		WHERE  ExprSingle
		{
			if (debug) cout << "WhereClause [ ]\n";
			$$ = new WhereClause(@$,
								dynamic_cast<ExprSingle*>($2));
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
			OrderSpecList osl_p = new OrderSpecList(@$,);
			osl_p->push_back(dynamic_cast<OrderSpec*>($1));
			$$ = osl_p;
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
			if (debug) cout << "OrderSpecList [list]\n";
			OrderSpecList osl_p = dynamic_cast<OrderSpecList*>($1);
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
								dynamic_cast<ExprSingle*>($1));
		}
	|	ExprSingle OrderModifier
		{
			if (debug) cout << "OrderSpec [single.modifier]\n";
			$$ = new OrderSpec(@$,
								dynamic_cast<ExprSingle*>($1),
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
								dynamic_cast<OrderDirSpec*>($1));
		}
	|	OrderEmptySpec
		{
			if (debug) cout << "OrderModifier [empty]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderEmptySpec*>($1));
		}
	|	OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [collation]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderCollationSpec*>($1));
		}
	|	OrderDirSpec  OrderEmptySpec
		{
			if (debug) cout << "OrderModifier [dir.empty]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderEmptySpec*>($2));
		}
	|	OrderDirSpec  OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [dir.collation]\n";
			$$ = new OrderModifier(@$,
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
			if (debug) cout << "OrderModifier [empty.collation]\n";
			$$ = new OrderModifier(@$,
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
			$$ = new OrderDirSpec(@$,
								OrderDirSpec::ascending);
		}
	|	DESCENDING
		{
			if (debug) cout << "OrderDirSpec [descending]\n";
			$$ = new OrderDirSpec(@$,
								OrderDirSpec::descending);
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
			if (debug) cout << "OrderEmptySpec [greatest]\n";
			$$ = new OrderEmptySpec(@$,
								static_context::greatest);
		}
	|	EMPTY_LEAST
		{
			if (debug) cout << "OrderEmptySpec [least]\n";
			$$ = new OrderEmptySpec(@$,
								static_context::least);
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
								QuantifiedExpr::some,
								dynamic_cast<QVarInDeclList*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	|	EVERY_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			if (debug) cout << "QuantifiedExpr [every]\n";
			$$ = new QuantifiedExpr(@$,
								QuantifiedExpr::every,
								dynamic_cast<QVarInDeclList*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	;


// [42a] QVarInDeclList
// --------------------
QVarInDeclList :
		QVarInDecl  %prec QVARINDECLLIST_REDUCE
		{
			if (debug) cout << "QVarInDeclList [single]\n";
			QVarInDeclList* qvid_list_p = new QVarInDeclList(@$,);
			qvid_list_p->push_back(dyamic_cast<QVarInDecl*>($1));
			$$ = qvid_list_p;
				
		}
	|	QVarInDecl  COMMA_DOLLAR  QVarInDeclList
		{
			if (debug) cout << "QVarInDeclList [list]\n";
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>($1);
			if (qvid_list_p) {
				qvid_list_p->push_back(dyamic_cast<QVarInDecl*>($3));
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
								dynamic_cast<ExprSingle*>($3));
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle 
		{
			if (debug) cout << "QVarInDecl [type.in]\n";
			$$ = new QVarInDecl(@$,
								driver.symtab.get($1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<ExprSingle*>($4));
		}
	;


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
			if (debug) cout << "TypeswitchExpr [cases.default.return]\n";
			$$ = new TypeswitchExpr(@$,
								dynamic_cast<Expr*>($2),
								dynamic_cast<CaseClauseList*>($4),
								dynamic_cast<ExprSingle*>($7));
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
			if (debug) cout << "TypeswitchExpr [cases.default.varname.return]\n";
			$$ = new TypeswitchExpr(@$,
								dynamic_cast<Expr*>($2),
								dynamic_cast<CaseClauseList*>($4),
								driver.symtab.get($7),
								dynamic_cast<ExprSingle*>($9));
		}
	;


// [43a] CaseClauseList
// --------------------
CaseClauseList :
		CaseClause
		{
			if (debug) cout << "CaseClauseList [single]\n";
			CaseClauseList* cc_list_p = new CaseClauseList(@$,);
			cc_list_p->push_back(dyamic_cast<CaseClause*>($1));
			$$ = cc_list_p;
		}
	|	CaseClauseList  CaseClause
		{
			if (debug) cout << "CaseClauseList [list]\n";
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>($1);
			cc_list_p->push_back(dyamic_cast<CaseClause*>($1));
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
								dynamic_cast<ExprSingle*>($4));
		}
	|	CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
			if (debug) cout << "CaseClause [case.as.return]\n";
			$$ = new CaseClause(@$,
								drive.symtab.get($3),
								dynamic_cast<SequenceType*>($5),
								dynamic_cast<ExprSingle*>($7));
		}
	;


// [45] IfExpr
// -----------
IfExpr :
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
			if (debug) cout << "IfExpr [ ]\n";
			$$ = new IfExpr(@$,
								dynamic_cast<Expr*>($2),
								dynamic_cast<ExprSingle*>($5),
								dynamic_cast<ExprSingle*>($7));
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
								dynamic_cast<OrExpr*>($1),
								dynamic_cast<AndExpr*>($3));
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
			$$ = new OrExpr(@$,
								dynamic_cast<AndExpr*>($1),
								dynamic_cast<ComparisonExpr*>($3));
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
								dynamic_cast<FTContainsExpr*>($1),
								dynamic_cast<ValueComp*>($2),
								dynamic_cast<FTContainsExpr*>($3));
		}
	| FTContainsExpr  GeneralComp  FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			if (debug) cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
			$$ = new ComparisonExpr(@$,
								dynamic_cast<FTContainsExpr*>($1),
								dynamic_cast<GeneralComp*>($2),
								dynamic_cast<FTContainsExpr*>($3));
		}
	| FTContainsExpr  NodeComp  FTContainsExpr
		{
			/*  ::=  "is" | "<<" | ">>" */
			if (debug) cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
			$$ = new ComparisonExpr(@$,
								dynamic_cast<FTContainsExpr*>($1),
								dynamic_cast<NodeComp*>($2),
								dynamic_cast<FTContainsExpr*>($3));
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
								dynamic_cast<RangeExpr*>($1),
								dynamic_cast<FTSelection*>($3));
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
			if (debug) cout << "FTContainsExpr [range.ftselect.ftignore]\n";
			$$ = new FTContainsExpr(@$,
								dynamic_cast<RangeExpr*>($1),
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
								dynamic_cast<AdditiveExpr*>($1),
								dynamic_cast<AdditiveExpr*>($3));
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
			$$ = new AdditiveExpr(@$,
								AdditiveExpr::plus,
								dynamic_cast<AdditiveExpr*>($1),
								dynamic_cast<MultiplicativeExpr*>($3));
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
			if (debug) cout << "AdditiveExpr [mult-mult]\n";
			$$ = new AdditiveExpr(@$,
								AdditiveExpr::minus,
								dynamic_cast<AdditiveExpr*>($1),
								dynamic_cast<MultiplicativeExpr*>($3));
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
			$$ = new MultiplicativeExpr(@$,
								MultiplicativeExpr::times,
								dynamic_cast<MultiplicativeExpr*>($1),
								dynamic_cast<UnionExpr*>($3));
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.div.union]\n";
			$$ = new MultiplicativeExpr(@$,
								MultiplicativeExpr::div,
								dynamic_cast<MultiplicativeExpr*>($1),
								dynamic_cast<UnionExpr*>($3));
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.idiv.union]\n";
			$$ = new MultiplicativeExpr(@$,
								MultiplicativeExpr::idiv,
								dynamic_cast<MultiplicativeExpr*>($1),
								dynamic_cast<UnionExpr*>($3));
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
			if (debug) cout << "MultiplicativeExpr [mult.mod.union]\n";
			$$ = new MultiplicativeExpr(@$,
								MultiplicativeExpr::mod,
								dynamic_cast<MultiplicativeExpr*>($1),
								dynamic_cast<UnionExpr*>($3));
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
								dynamic_cast<UnionExpr*>($1),
								dynamic_cast<IntersectExceptExpr*>($3));
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
			if (debug) cout << "UnionExpr [union|interexcept]\n";
			$$ = new UnionExpr(@$,
								dynamic_cast<UnionExpr*>($1),
								dynamic_cast<IntersectExceptExpr*>($3));
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
			$$ = new IntersectExceptExpr(@$,
								dynamic_cast<IntersectExceptExpr*>($1),
								IntersectExceptExpr::intersect,
								dynamic_cast<InstanceofExpr*>($3));
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
			if (debug) cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
			$$ = new IntersectExceptExpr(@$,
								dynamic_cast<IntersectExceptExpr*>($1),
								IntersectExceptExpr::except,
								dynamic_cast<InstanceofExpr*>($3));
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
								dynamic_cast<Treat*>($1),
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
								dynamic_cast<CastableExpr*>($1),
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
								dynamic_cast<CastExpr*>($1),
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
								dynamic_cast<UnaryExpr*>($1),
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
								dynamic_cast<ValueExpr*>($2));
		}
	;


// [58a] SignList
// --------------
SignList :
		PLUS
		{
			if (debug) cout << "SignList [+]\n";
			$$ = new SignList(
								true);
		}
	|	MINUS
		{
			if (debug) cout << "SignList [-]\n";
			$$ = new SignList(
								false);
		}
	|	SignList  PLUS
		{
			if (debug) cout << "SignList [signlist.+]\n";
			return $1;
		}
	|	SignList  MINUS
		{
			if (debug) cout << "SignList [signlist.-]\n";
			SignList* slist = dynamic_cast<SignList*>($1);
			if (slist) slist_p->negate();
			return $1;
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
			$$ = new GeneralComp(@$,
								GeneralComp::eq);
		}
	| NE
		{
			if (debug) cout << "GeneralComp [!=]\n";
			$$ = new GeneralComp(@$,
								GeneralComp::ne);
		}
	| LT
		{
			if (debug) cout << "GeneralComp [<]\n";
			$$ = new GeneralComp(@$,
								GeneralComp::lt);
		}
	| LE
		{
			if (debug) cout << "GeneralComp [<=]\n";
			$$ = new GeneralComp(@$,
								GeneralComp::le);
		}
	| GT
		{
			if (debug) cout << "GeneralComp [>]\n";
			$$ = new GeneralComp(@$,
								GeneralComp::gt);
		}
	| GE
		{
			if (debug) cout << "GeneralComp [>=]\n";
			$$ = new GeneralComp(@$,
								GeneralComp::ge);
		}
	;


// [61] ValueComp
// --------------
ValueComp :
		VAL_EQ
		{
			if (debug) cout << "ValueComp [eq]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_eq);
		}
	| VAL_NE
		{
			if (debug) cout << "ValueComp [ne]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_ne);
		}
	| VAL_LT
		{
			if (debug) cout << "ValueComp [lt]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_lt);
		}
	| VAL_LE
		{
			if (debug) cout << "ValueComp [le]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_le);
		}
	| VAL_GT
		{
			if (debug) cout << "ValueComp [gt]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_gt);
		}
	| VAL_GE
		{
			if (debug) cout << "ValueComp [ge]\n";
			$$ = new GeneralComp(@$,
								ValueComp::val_ge);
		}
	;


// [62] NodeComp
// -------------
NodeComp :
		IS
		{
			if (debug) cout << "NodeComp [is]\n";
			$$ = new NodeComp(@$,
								NodeComp::is);
		}
	| PRECEDES
		{
			if (debug) cout << "NodeComp [<<]\n";
			$$ = new NodeComp(@$,
								NodeComp::precedes);
		}
	| FOLLOWS
		{
			if (debug) cout << "NodeComp [>>]\n";
			$$ = new NodeComp(@$,
								NodeComp::follows);
		}
	;



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "ValidateExpr [expr]\n";
			$$ = new ValidateExpr(@$,
								"strict",
								dynamic_cast<Expr*>($2));
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "ValidateExpr [mode.expr]\n";
			$$ = new ValidateExpr(@$,
								driver.symtab.get($1),
								dynamic_cast<Expr*>($3));
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
								dynamic_cast<Expr*>($3));
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
				pragma_list_p->push_back(dynamic_cast<Pragma*>($1));
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
								new QName(driver.symtab.get($2)),
								driver.symtab.get($3));

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
			if (debug) cout << "PathExpr [/]\n";
			$$ = new PathExpr(@$,
								PathExpr::leading_lone_slash,
								NULL);
		}
	|	SLASH  RelativePathExpr
		{
			if (debug) cout << "PathExpr [/relative]\n";
			$$ = new PathExpr(@$,
								PathExpr::leading_slash,
								dynamic_cast<RelativePathExpr*>($2));
		}
	|	SLASH_SLASH  RelativePathExpr
		{
			if (debug) cout << "PathExpr [//relative]\n";
			$$ = new PathExpr(@$,
								PathExpr::leading_slash_slash,
								dynamic_cast<RelativePathExpr*>($2));
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
			if (debug) cout << "PathExpr [relative]\n";
			$$ = new PathExpr(@$,
								PathExpr::relative,
								dynamic_cast<RelativePathExpr*>($1));
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
			if (debug) cout << "RelativePathExpr [step]\n";
			$$ = new RelativePathExpr(@$,
								RelativePathExpr::step,
								dynamic_cast<StepExpr*>($1),
								NULL);
		}
	|	StepExpr  SLASH  RelativePathExpr 
		{
			if (debug) cout << "RelativePathExpr [step/relative]\n";
			$$ = new RelativePathExpr(@$,
								RelativePathExpr::slash,
								dynamic_cast<StepExpr*>($1),
								dynamic_cast<RelativePathExpr*>($3));
		}
	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
			if (debug) cout << "RelativePathExpr [step//relative]\n";
			$$ = new RelativePathExpr(@$,
								RelativePathExpr::slash_slash,
								dynamic_cast<StepExpr*>($1),
								dynamic_cast<RelativePathExpr*>($3));
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
								dynamic_cast<ForwardStep*>($1));
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
								dynamic_cast<ReverseStep*>($1));
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
								dynamic_cast<NodeTest*>($2));
		}
	|	AbbrevForwardStep
		{
			if (debug) cout << "ForwardStep [abbrev]\n";
			$$ = new ForwardStep(@$,
								dynamic_cast<AbbreviatedForwardStep*>($1),
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
			if (debug) cout << "ForwardAxis [child]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::child);
		}
	| DESCENDANT_AXIS
		{
			if (debug) cout << "ForwardAxis [descendant]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::descendant);
		}
	| ATTRIBUTE_AXIS
		{
			if (debug) cout << "ForwardAxis [attribute]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::attribute);
		}
	| SELF_AXIS
		{
			if (debug) cout << "ForwardAxis [self]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::self);
		}
	| DESCENDANT_OR_SELF_AXIS
		{
			if (debug) cout << "ForwardAxis [descendant_or_self]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::descendant_or_self);
		}
	| FOLLOWING_SIBLING_AXIS
		{
			if (debug) cout << "ForwardAxis [following_sibling]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::following_sibling);
		}
	| FOLLOWING_AXIS
		{
			if (debug) cout << "ForwardAxis [following]\n";
			$$ = new ForwardAxis(@$,
								ForwardAxis::following);
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
			if (debug) cout << "AbbrevForwardStep [nodetest]\n";
			$$ = new AbbrevForwardStep(@$,
								dynmic_cast<NodeTest*>($1));
		}
	|	AT_SIGN  NodeTest
		{
			if (debug) cout << "AbbrevForwardStep [@ nodetest]\n";
			$$ = new AbbrevForwardStep(@$,
								dynmic_cast<NodeTest*>($2),
								true);
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
			$$ = new ReverseAxis(@$,
								ReverseAxis::parent);
		}
	;


// [75] ReverseAxis
// ----------------
ReverseAxis :
		PARENT_AXIS
		{
			if (debug) cout << "ReverseAxis [parent]\n";
			$$ = new ReverseAxis(@$,
								ReverseAxis::parent);
		}
	| ANCESTOR_AXIS
		{
			if (debug) cout << "ReverseAxis [ancestor]\n";
			$$ = new ReverseAxis(@$,
								ReverseAxis::ancestor);
		}
	| PRECEDING_SIBLING_AXIS
		{
			if (debug) cout << "ReverseAxis [preceding_sibling]\n";
			$$ = new ReverseAxis(@$,
								ReverseAxis::preceding_sibling);
		}
	| PRECEDING_AXIS
		{
			if (debug) cout << "ReverseAxis [preceding]\n";
			$$ = new ReverseAxis(@$,
								ReverseAxis::preceding);
		}
	| ANCESTOR_OR_SELF_AXIS
		{
			if (debug) cout << "ReverseAxis [ancestor_or_self]\n";
			$$ = new ReverseAxis(@$,
								ReverseAxis::ancestor_or_self);
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
								new QName(driver.symtab.get($1)));
		}
	|	Wildcard
		{
			if (debug) cout << "NameTest [wildcard]\n";
			$$ = new NameTest(@$,
								dynamic_cast<WIldcard*>($1));
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
			if (debug) cout << "Wildcard [*]\n";
			$$ = new Wildcard(@$,
								Wildcard::wild_all);
		}
	|	ELEM_WILDCARD
		{
			if (debug) cout << "Wildcard [pref:*]\n";
			$$ = new Wildcard(@$,
								new QName(driver.symtab.get($1)));
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
			if (debug) cout << "Wildcard [*:qname]\n";
			$$ = new Wildcard(@$,
								driver.symtab.get($1));
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr 
		{
			if (debug) cout << "FilterExpr [primary]\n";
			$$ = new FilterExpr(@$,
								dynamic_cast<PrimaryExpr*>($1),
								NULL);
		}
	|	PrimaryExpr  PredicateList
		{
			if (debug) cout << "FilterExpr [primary.predlist]\n";
			$$ = new FilterExpr(@$,
								dynamic_cast<PrimaryExpr*>($1),
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
			pred_list_p->push_back(dynamic_cast<Predicate*>($1));
			$$ = pred_list_p;
		}
	|	PredicateList  Predicate
		{
			if (debug) cout << "PredicateList [list]\n";
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>($1);
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<Predicate*>($1));
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
			$$ = new Predicate(@$,
								dynamic_cast<Expr*>($2));
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
		}
	|	STRING_LITERAL
		{
			if (debug) cout << "Literal [string]\n";
		}
	;


// [85] NumericLiteral
// -------------------
NumericLiteral :
		INTEGER_LITERAL
		{
			if (debug) cout << "NumericLiteral [int]\n";
		}
	|	DECIMAL_LITERAL
		{
			if (debug) cout << "NumericLiteral [decimal]\n";
		}
	|	DOUBLE_LITERAL
		{
			if (debug) cout << "NumericLiteral [double]\n";
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
			if (debug) cout << "VarRef [ ]\n";
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
			if (debug) cout << "ParenthesizedExpr [()]\n";
		}
	|	LPAR  Expr  RPAR
		{
			if (debug) cout << "ParenthesizedExpr [(expr)]\n";
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
			if (debug) cout << "ContextItemExpr [.]\n";
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "OrderedExpr [expr]\n";
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "UnorderedExpr [expr]\n";
		}
	;


// [91] FunctionCall
// -----------------
FunctionCall :
		QNAME_LPAR  RPAR
		{
			if (debug) cout << "FunctionCall [ ]\n";
		}
	|	QNAME_LPAR  ArgList  RPAR 	/* gn: parensXQ */
		{
			if (debug) cout << "FunctionCall [arglist]\n";
		}
				/* gn: reserved-function-namesXQ */
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
			if (debug) cout << "ArgList [single]\n";
		}
	|	ArgList  COMMA  ExprSingle
		{
			if (debug) cout << "ArgList [list]\n";
		}
	;


// [92] Constructor
// ----------------
Constructor :
		DirectConstructor
		{
			if (debug) cout << "Constructor [direct]\n";
		}
	|	ComputedConstructor
		{
			if (debug) cout << "Constructor [computed]\n";
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
			if (debug) cout << "DirectConstructor [element]\n";
		}
	|	DirCommentConstructor
		{
			if (debug) cout << "DirectConstructor [comment]\n";
		}
	|	DirPIConstructor
		{
			if (debug) cout << "DirectConstructor [pi]\n";
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  EMPTY_TAG_END /* ws: explicitXQ */
		{
			if (debug) cout << "DirElemConstructor [<qname/> ]\n";
		}
	| START_TAG  QNAME  DirAttributeList EMPTY_TAG_END /* ws: explicitXQ */
		{
			if (debug) cout << "DirElemConstructor [<qname attrlist/> ]\n";
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			if (debug) cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
		}
	|	START_TAG  QNAME  TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			if (debug) cout << "DirElemConstructor [<qname>content</qname>]\n";
		}
			/* ws: explicitXQ */
			/* gn: ltXQ */
	;


// [94a] DirElemContentList
// ------------------------
DirElemContentList :
		DirElemContent
		{
			if (debug) cout << "DirElemContentList [single]\n";
		}
	|	DirElemContentList  DirElemContent
		{
			if (debug) cout << "DirElemContentList [list]\n";
		}
	;


// [95] DirAttributeList
// ---------------------
DirAttributeList :
		DirAttr
		{
			if (debug) cout << "DirAttributeList [single]\n";
		}
	|	DirAttributeList  DirAttr
		{
			if (debug) cout << "DirAttributeList [list]\n";
		}
	;


// [95a] DirAttr
// -------------
DirAttr :
		QNAME  EQUALS  DirAttributeValue 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirAttr [ ]\n";
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  QuoteAttrContentList  QUOTE
		{
			if (debug) cout << "DirAttributeValue [quote]\n";
		}
	|	APOS  AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirAttributeValue [apos]\n";
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList :
		ESCAPE_QUOTE
		{
			if (debug) cout << "QuoteAttrContentList [""]\n";
		}
	|	QuoteAttrValueContent
		{
			if (debug) cout << "QuoteAttrContentList [single]\n";
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
			if (debug) cout << "QuoteAttrContentList [list ""]\n";
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
			if (debug) cout << "QuoteAttrContentList [list]\n";
		}
	;


// [96b] AposAttrContentList
// -------------------------
AposAttrContentList :
		ESCAPE_APOS
		{
			if (debug) cout << "AposAttrContentList ['']\n";
		}
	|	AposAttrValueContent
		{
			if (debug) cout << "AposAttrContentList [single]\n";
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
			if (debug) cout << "AposAttrContentList [list '']\n";
		}
	|	AposAttrContentList  AposAttrValueContent
		{
			if (debug) cout << "AposAttrContentList [list]\n";
		}
	;


// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent :
		QUOTE_ATTR_CONTENT
		{
			if (debug) cout << "QuoteAttrValueContent [quote_attr_content]\n";
		}
	|	CommonContent
		{
			if (debug) cout << "QuoteAttrValueContent [common_content]\n";
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
			if (debug) cout << "AposAttrValueContent [apos_attr_content]\n";
		}
	|	CommonContent
		{
			if (debug) cout << "AposAttrValueContent [common_content]\n";
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
			if (debug) cout << "DirElemContent [cons]\n";
		}
	|	ELEMENT_CONTENT
		{
			if (debug) cout << "DirElemContent [elem_content]\n";
		}
	|	CDataSection
		{
			if (debug) cout << "DirElemContent [cdata]\n";
		}
	|	CommonContent
		{
			if (debug) cout << "DirElemContent [common_content]\n";
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
		ENTITY_REF
		{
			if (debug) cout << "CommonContent [entity_ref]\n";
		}
	|	CHAR_REF_LITERAL
		{
			if (debug) cout << "CommonContent [char_ref]\n";
		}
	|	DOUBLE_LBRACE
		{
			if (debug) cout << "CommonContent [{{]\n";
		}
	|	DOUBLE_RBRACE
		{
			if (debug) cout << "CommonContent [}}]\n";
		}
	|	EnclosedExpr
		{
			if (debug) cout << "CommonContent [expr]\n";
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		XML_COMMENT_BEGIN  EXPR_COMMENT_LITERAL  XML_COMMENT_END 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirCommentConstructor [ ]\n";
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
			if (debug) cout << "DirPIConstructor [target]\n"
		}
	|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
			if (debug) cout << "DirPIConstructor [target.charlit]\n"
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
			if (debug) cout << "CDataSection [ ]\n"
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
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
			if (debug) cout << "CompElemConstructor [ ]\n";
		}
	|	ELEMENT_QNAME_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompElemConstructor [content]\n";
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			if (debug) cout << "CompElemConstructor [name]\n";
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompElemConstructor [name.content]\n";
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
		}
	|	ATTRIBUTE_QNAME_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [val]\n";
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [name]\n";
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompAttrConstructor [name.val]\n";
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompTextConstructor [content]\n";
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompCommentConstructor [content]\n";
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
			if (debug) cout << "CompPIConstructor [ ]\n";
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompPIConstructor [content]\n";
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
			if (debug) cout << "CompPIConstructor [target]\n";
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
			if (debug) cout << "CompPIConstructor [target.content]\n";
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
			if (debug) cout << "SingleType [atomic]\n";
		}
	|	AtomicType  HOOK
		{
			if (debug) cout << "SingleType [atomic ?]\n";
		}
	;


// [116] TypeDeclaration
// ---------------------
TypeDeclaration :
		AS  SequenceType
		{
			if (debug) cout << "TypeDeclaration [as seqtype]\n";
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
			if (debug) cout << "ItemType [type]\n";
		}
	|	ItemType  OccurrenceIndicator
		{
			if (debug) cout << "ItemType [type.occurs]\n";
		}
	|	VOID_TEST
		{
			if (debug) cout << "ItemType [void]\n";
		}
	;


// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator :
		OCCURS_HOOK
		{
			if (debug) cout << "OccurrenceIndicator [?]\n";
		}
	|	OCCURS_STAR
		{
			if (debug) cout << "OccurrenceIndicator [*]\n";
		}
	|	OCCURS_PLUS 	/* gn: occurrence-indicatorsXQ */
		{
			if (debug) cout << "OccurrenceIndicator [+]\n";
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
			if (debug) cout << "ItemType [atomic]\n";
		}
	|	KindTest
		{
			if (debug) cout << "ItemType [kind]\n";
		}
	|	ITEM_TEST
		{
			if (debug) cout << "ItemType [item]\n";
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
			if (debug) cout << "AtomicType [qname]\n";
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
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
			if (debug) cout << "DocumentTest [ ]\n";
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
			if (debug) cout << "DocumentTest [elem]\n";
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
			if (debug) cout << "DocumentTest [schema_elem]\n";
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
			if (debug) cout << "TextTest [ ]\n";
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
			if (debug) cout << "CommentTest [ ]\n";
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
			if (debug) cout << "PITest [ ]\n";
		}
	|	PI_LPAR  NCNAME  RPAR
		{
			if (debug) cout << "PITest [ncname]\n";
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
			if (debug) cout << "PITest [stringlit]\n";
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
			if (debug) cout << "AttributeTest [ ]\n";
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
		{
			if (debug) cout << "AttributeTest [name_or_wild]\n";
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
		{
			if (debug) cout << "AttributeTest [name_or_wild.type]\n";
		}
	;


// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard :
		AttributeName
		{
			if (debug) cout << "AttribNameOrWildcard [attr]\n";
		}
	|	STAR
		{
			if (debug) cout << "AttribNameOrWildcard [*]\n";
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  AttributeDeclaration  RPAR
		{
			if (debug) cout << "SchemaAttributeTest [ ]\n";
		}
	;


// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration :
		AttributeName
		{
			if (debug) cout << "AttributeDeclaration [ ]\n";
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
			if (debug) cout << "ElementTest [ ]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  RPAR
		{
			if (debug) cout << "ElementTest [name_or_wild]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR
		{
			if (debug) cout << "ElementTest [name_or_wild.type]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR
		{
			if (debug) cout << "ElementTest [name_or_wild.type ?]\n";
		}
	;


// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard :
		ElementName
		{
			if (debug) cout << "ElementNameOrWildcard [elem]\n";
		}
	|	STAR
		{
			if (debug) cout << "ElementNameOrWildcard [*]\n";
		}
	;


// [133] SchemaElementTest
// -----------------------
SchemaElementTest :
		SCHEMA_ELEMENT_LPAR  ElementDeclaration  RPAR
		{
			if (debug) cout << "SchemaElementTest [ ]\n";
		}
	;


// [134] ElementDeclaration
// ------------------------
ElementDeclaration :
		ElementName
		{
			if (debug) cout << "ElementDeclaration [ ]\n";
		}
	;


// [135] AttributeName
// -------------------
AttributeName :
		QNAME
		{
			if (debug) cout << "AttributeName [ ]\n";
		}
	;


// [136] ElementName
// -----------------
ElementName :
		QNAME
		{
			if (debug) cout << "ElementName [ ]\n";
		}
	;


// [137] TypeName
// --------------
TypeName :
		QNAME
		{
			if (debug) cout << "TypeName [ ]\n";
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
	| FTWildCardOption
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


//[364] FTWildCardOption
//----------------------
FTWildCardOption :
		WITH_WILDCARDS
		{
			if (debug) cout << "FTWildCardOption [with]\n";
		}
	| WITHOUT_WILDCARDS
		{
			if (debug) cout << "FTWildCardOption [without]\n";
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




