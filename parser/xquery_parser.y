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
	The two following directives to enable parser tracing and verbose 
	error messages. 
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
%}


/*
	The token numbered as 0 corresponds to end of file; the following line 
	allows for nicer error messages referring to end of file instead of 
	$end. Similarly user friendly names are provided for each symbol.
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
//%type <node> ContentExpr
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
%type <node> GeneralComp
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
%type <node> NodeComp
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
%type <node> URILiteralList
%type <node> ValidateExpr
%type <node> ValueComp
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

%{
using namespace xqp;
%}

%%
%start Module;



// [1] Module
// ----------
Module :
    MainModule
		{
			cout << "Module [main]\n";
			$$ = $1;
		}
  | VersionDecl MainModule
		{
			cout << "Module [version.main]\n";
		}
  | LibraryModule 
		{
			cout << "Module [library]\n";
		}
  | VersionDecl LibraryModule 
		{
			cout << "Module [version.library]\n";
		}
  ;


// [2] VersionDecl
// ---------------
VersionDecl :
		XQUERY_VERSION  STRING_LITERAL  SEMI
		{
			cout << "VersionDecl [version]\n";
		}
	|	XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
			cout << "VersionDecl [version.encoding]\n";
		}
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
			cout << "MainModule [prolog.querybody]\n";
		}
	|
    QueryBody
		{
			cout << "MainModule [querybody]\n";
		}
  ;


// [4] LibraryModule
// -----------------
LibraryModule :
		ModuleDecl  Prolog
		{
			cout << "LibraryModule [ ]\n";
		}
	;


// [5] ModuleDecl
// --------------
ModuleDecl :
		MODULE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
			cout << "ModuleDecl [ ]\n";
		}
	;


// [6] Prolog
// ----------
Prolog :
		SIND_DeclList  SEMI
		{
			cout << "Prolog [sind]\n";
		}
	|	VFO_DeclList  SEMI
		{
			cout << "Prolog [vfo]\n";
		}
	|	SIND_DeclList  SEMI  VFO_DeclList  SEMI
		{
			cout << "Prolog [sind.vfo]\n";
		}
	;


// [6a] SIDN_DeclList
// ------------------
SIND_DeclList :
		SIND_Decl
		{
			cout << "SIND_DeclList [single]\n";
			$$ = new SIND_DeclList(); //dynamic_cast<SIND_Decl*>($1));
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
			cout << "SIND_DeclList [list]\n";
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
			cout << "VFO_DeclList [single]\n";
			$$ = new VFO_DeclList(); // dynamic_cast<VFO_Decl*>($1));
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
			cout << "VFO_DeclList [list]\n";
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
			cout << "SIND_Decl [setter]\n";
			$$ = $1;
		}
	| Import
		{
			cout << "SIND_Decl [import]\n";
			$$ = $1;
		}
	| NamespaceDecl
		{
			cout << "SIND_Decl [namespace]\n";
			$$ = $1;
		}
	| DefaultNamespaceDecl
		{
			cout << "SIND_Decl [default namespace]\n";
			$$ = $1;
		}
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl
		{
			cout << "VFO_Decl [var]\n";
			$$ = $1;
		}
	| FunctionDecl
		{
			cout << "VFO_Decl [function]\n";
			$$ = $1;
		}
	| OptionDecl
		{
			cout << "VFO_Decl [option]\n";
			$$ = $1;
		}
	
	/* full-text extension */
	| FTOptionDecl
		{
			cout << "VFO_Decl [ftoption]\n";
			$$ = $1;
		}
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl
		{
			cout << "Setter [boundary space]\n";
			$$ = $1;
		}
	| DefaultCollationDecl
		{
			cout << "Setter [default collation]\n";
			$$ = $1;
		}
	| BaseURIDecl
		{
			cout << "Setter [base uri]\n";
			$$ = $1;
		}
	| ConstructionDecl
		{
			cout << "Setter [construction]\n";
			$$ = $1;
		}
	| OrderingModeDecl
		{
			cout << "Setter [ordering mode]\n";
			$$ = $1;
		}
	| EmptyOrderDecl
		{
			cout << "Setter [empty order]\n";
			$$ = $1;
		}
	| CopyNamespacesDecl
		{
			cout << "Setter [copy namespaces]\n";
			$$ = $1;
		}

	/* update extension */
	| RevalidationDecl
		{
			cout << "Setter [revalidation]\n";
			$$ = $1;
		}
	;


// [8] Import
// ----------
Import :
		SchemaImport
		{
			cout << "Import [schema]\n";
			$$ = $1;
		}
	| ModuleImport
		{
			cout << "Import [module]\n";
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
			cout << "NamespaceDecl [ ]\n";
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE_BOUNDARY_SPACE  PRESERVE
		{
			cout << "BoundarySpaceDecl [preserve]\n";
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
			cout << "BoundarySpaceDecl [strip]\n";
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
			cout << "DefaultNamespaceDecl [element]\n";
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
			cout << "DefaultNamespaceDecl [function]\n";
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE_OPTION  QNAME  STRING_LITERAL
		{
			cout << "OptionDecl [ ]\n";
		}
	;


/* full-text extension */
// [13a] OptionDecl
// ---------------
FTOptionDecl :
		DECLARE_FTOPTION  QNAME  FTMatchOption
		{
			cout << "FTOptionDecl [ ]\n";
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
			cout << "OrderingDecl [ordered]\n";
		}
	| DECLARE_ORDERING  UNORDERED
		{
			cout << "OrderingDecl [unordered]\n";
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
			cout << "EmptyOrderDecl [empty greatest]\n";
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
			cout << "EmptyOrderDecl [empty least]\n";
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PreserveMode  COMMA  InheritMode
		{
			cout << "CopyNamespacesDecl [ ]\n";
		}
	;


// [17] PreserveMode
// -----------------
PreserveMode :
		PRESERVE
		{
			cout << "PreserveMode [preserve]\n";
		}
	| NO_PRESERVE
		{
			cout << "PreserveMode [no preserve]\n";
		}
	;


// [18] InheritMode
// ----------------
InheritMode :
		INHERIT
		{
			cout << "InheritMode [inherit]\n";
		}
	| NO_INHERIT
		{
			cout << "InheritMode [no inherit]\n";
		}
	;


// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl :
		DECLARE_DEFAULT_COLLATION  URI_LITERAL
		{
			cout << "DefaultCollationMode [ ]\n";
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE_BASE_URI  URI_LITERAL
		{
			cout << "BaseURIDecl [ ]\n";
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT_SCHEMA  URI_LITERAL
		{
			cout << "SchemaImport [uri]\n";
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
			cout << "SchemaImport [prefix.uri]\n";
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT_URI_LITERAL
		{
			cout << "SchemaImport [uri.aturi]\n";
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT_URI_LITERAL  COMMA  URILiteralList
		{
			cout << "SchemaImport [uri.aturi.urilist]\n";
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT_URI_LITERAL
		{
			cout << "SchemaImport [prefix.uri.aturi]\n";
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT_URI_LITERAL  COMMA  URILiteralList
		{
			cout << "SchemaImport [prefix.uri.aturi.urilist]\n";
		}
	;


// [21a] URLLiteralList
// --------------------
URILiteralList :
		URI_LITERAL
		{
			cout << "URILiteralList [single]\n";
		}
	| URILiteralList  COMMA  URI_LITERAL
		{
			cout << "URILiteralList [list]\n";
		}
	;



// [22] SchemaPrefix
// -----------------
SchemaPrefix :
		NAMESPACE  NCNAME  EQUALS
		{
			cout << "SchemaPrefix [namespace]\n";
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
			cout << "SchemaPrefix [default element]\n";
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT_MODULE  URI_LITERAL 
		{
			cout << "ModuleImport [uri]\n";
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
			cout << "ModuleImport [namespace.uri]\n";
		}
	|	IMPORT_MODULE  URI_LITERAL  AT_URI_LITERAL 
		{
			cout << "ModuleImport [uri.at_uri]\n";
		}
	|	IMPORT_MODULE  URI_LITERAL  AT_URI_LITERAL  COMMA  URILiteralList
		{
			cout << "ModuleImport [uri.at_uri.list]\n";
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT_URI_LITERAL
		{
			cout << "ModuleImport [namespace.uri.at_uri]\n";
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT_URI_LITERAL  COMMA  URILiteralList
		{
			cout << "ModuleImport [namespace.uri.at_uri.list]\n";
		}
	;



// [24] VarDecl
// ------------
VarDecl :
		DECLARE_VARIABLE_DOLLAR  VARNAME  GETS  ExprSingle
		{
			cout << "VarDecl [expr]\n";
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
			cout << "VarDecl [external]\n";
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			cout << "VarDecl [type.expr]\n";
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
			cout << "VarDecl [type.external]\n";
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE_CONSTRUCTION  PRESERVE
		{
			cout << "ConstructionDecl [preserve]\n";
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
			cout << "ConstructionDecl [strip]\n";
		}
	;


// [26] FunctionDecl
// -----------------
FunctionDecl :
		DECLARE_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			cout << "FunctionDecl [external]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			cout << "FunctionDecl [expr]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			cout << "FunctionDecl [paramlist.external]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			cout << "FunctionDecl [paramlist.expr]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			cout << "FunctionDecl [as_type.external]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			cout << "FunctionDecl [as_type.expr]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			cout << "FunctionDecl [paramlist.as_type.external]\n";
		}
	|	DECLARE_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			cout << "FunctionDecl [paramlist.as_type.expr]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EXTERNAL
		{
			cout << "FunctionDecl [(update) external]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR  EnclosedExpr
		{
			cout << "FunctionDecl [(update) expr]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EXTERNAL
		{
			cout << "FunctionDecl [(update) paramlist.external]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR  EnclosedExpr
		{
			cout << "FunctionDecl [(update) paramlist.expr]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EXTERNAL
		{
			cout << "FunctionDecl [(update) as_type.external]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  RPAR_AS  SequenceType  EnclosedExpr
		{
			cout << "FunctionDecl [(update) as_type.expr]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EXTERNAL
		{
			cout << "FunctionDecl [(update) paramlist.as_type.external]\n";
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME_LPAR  ParamList  RPAR_AS  SequenceType  EnclosedExpr
		{
			cout << "FunctionDecl [(update) paramlist.as_type.expr]\n";
		}
	;



// [27] ParamList
// --------------
ParamList :
		Param
		{
			cout << "ParamList [single]\n";
		}
	|	ParamList  COMMA  Param
		{
			cout << "ParamList [list]\n";
		}
	;


// [28] Param
// ----------
Param :
		DOLLAR  VARNAME
		{
			cout << "Param [varname]\n";
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
			cout << "Param [varname.type]\n";
		}
	;


// [29] EnclosedExpr
// -----------------
EnclosedExpr :
		LBRACE  Expr  RBRACE
		{
			cout << "EnclosedExpr [ ]\n";
		}
	;


// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
			cout << "QueryBody [expr]\n";
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
			cout << "Expr [single]\n";
		}
	|	Expr  COMMA  ExprSingle
		{
			cout << "Expr [expr.single]\n";
		}
	;


// [32] ExprSingle
// ---------------
ExprSingle :
		FLWORExpr
		{
			cout << "ExprSingle [FLWORExpr]\n";
			$$ = $1;
		}
	|	QuantifiedExpr
		{
			cout << "ExprSingle [QuantifiedExpr]\n";
			$$ = $1;
		}
	|	TypeswitchExpr
		{
			cout << "ExprSingle [TypeswitchExpr]\n";
			$$ = $1;
		}
	|	IfExpr
		{
			cout << "ExprSingle [IfExpr]\n";
			$$ = $1;
		}
	|	OrExpr
		{
			cout << "ExprSingle [OrExpr]\n";
			$$ = $1;
		}

		/* update extensions */
	| InsertExpr
		{
			cout << "ExprSingle [InsertExpr]\n";
			$$ = $1;
		}
	| DeleteExpr
		{
			cout << "ExprSingle [DeleteExpr]\n";
			$$ = $1;
		}
	| RenameExpr
		{
			cout << "ExprSingle [RenameExpr]\n";
			$$ = $1;
		}
	| ReplaceExpr
		{
			cout << "ExprSingle [ReplaceExpr]\n";
			$$ = $1;
		}
	| TransformExpr
		{
			cout << "ExprSingle [TransformExpr]\n";
			$$ = $1;
		}
	;


// [33] FLWORExpr
// --------------
FLWORExpr :
	  ForLetClauseList  RETURN  ExprSingle
		{
			cout << "FLWORExpr [return]\n";
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
			cout << "FLWORExpr [where.return]\n";
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
			cout << "FLWORExpr [orderby.return]\n";
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
			cout << "FLWORExpr [where.orderby.return]\n";
		}
	;


// [33a] ForLetClauseList
// ----------------------
ForLetClauseList :
		ForLetClause
		{
			cout << "ForLetClauseList [single]\n";
		}
	|	ForLetClause  ForLetClauseList
		{
			cout << "ForLetClauseList [list]\n";
		}
	;


// [33b] ForLetClause
// ------------------
ForLetClause :
		ForClause
		{
			cout << "ForLetClause [for]\n";
			$$ = $1;
		}
	|	LetClause
		{
			cout << "ForLetClause [let]\n";
			$$ = $1;
		}
	;


// [34] ForClause
// --------------
ForClause :
		FOR_DOLLAR  VarInDeclList
		{
			cout << "ForClause [ ]\n";
		}
	;


// [34a] VarInDeclList
// -------------------
VarInDeclList :
		VarInDecl
		{
			cout << "VarInDeclList [single]\n";
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
			cout << "VarInDeclList [list]\n";
		}
	;


// [34b] VarInDecl
// ---------------
VarInDecl :
		VARNAME  IN  ExprSingle
		{
			cout << "VarInDecl [in]\n";
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle
		{
			cout << "VarInDecl [type.in]\n";
		}
	|	VARNAME  PositionalVar  IN  ExprSingle
		{
			cout << "VarInDecl [posvar.in]\n";
		}
	|	VARNAME  TypeDeclaration  PositionalVar  IN  ExprSingle
		{
			cout << "VarInDecl [type.posvar.in]\n";
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  IN  ExprSingle
		{
			cout << "VarInDecl [scorevar.in]\n";
		}
	| VARNAME  TypeDeclaration  FTScoreVar  IN  ExprSingle
		{
			cout << "VarInDecl [type.scorevar.in]\n";
		}
	| VARNAME  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			cout << "VarInDecl [posvar.scorevar.in]\n";
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  IN  ExprSingle
		{
			cout << "VarInDecl [type.posvar.scorevar.in]\n";
		}
	;


// [35] PositionalVar
// ------------------
PositionalVar :
		AT  DOLLAR  VARNAME
		{
			cout << "PositionalVar [ ]\n";
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  VARNAME
		{
			cout << "FTScoreVar [ ]\n";
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET_DOLLAR VarGetsDeclList
		{
			cout << "LetClause [ ]\n";
		}
	| LET_SCORE_DOLLAR VarGetsDeclList
		{
			cout << "LetClause [score]\n";
		}
	;


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList :
		VarGetsDecl
		{
			cout << "VarGetsDeclList [single]\n";
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
			cout << "VarGetsDeclList [list]\n";
		}
	;


// [36b] VarGetsDecl
// ------------------
VarGetsDecl :
		VARNAME  GETS  ExprSingle
		{
			cout << "VarGetsDecl [gets]\n";
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			cout << "VarGetsDecl [type.gets]\n";
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
			cout << "VarGetsDecl [scorevar.gets]\n";
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
			cout << "VarGetsDecl [type.scorevar.gets]\n";
		}
	;


// [37] WhereClause
// ----------------
WhereClause :
		WHERE  ExprSingle
		{
			cout << "WhereClause [ ]\n";
		}
	;


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER_BY  OrderSpecList
		{
			cout << "OrderByClause [ ]\n";
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
			cout << "OrderByClause [stable]\n";
		}
	;


// [39] OrderSpecList
// ------------------
OrderSpecList :
		OrderSpec 
		{
			cout << "OrderSpecList [single]\n";
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
			cout << "OrderSpecList [list]\n";
		}
	;


// [40] OrderSpec
// --------------
OrderSpec :
		ExprSingle
		{
			cout << "OrderSpec [single]\n";
		}
	|	ExprSingle OrderModifier
		{
			cout << "OrderSpec [single.modifier]\n";
		}
	;


// [41] OrderModifier
// ------------------
OrderModifier :
		OrderDirSpec
		{
			cout << "OrderModifier [dir]\n";
		}
	|	OrderEmptySpec
		{
			cout << "OrderModifier [empty]\n";
		}
	|	OrderCollationSpec
		{
			cout << "OrderModifier [collation]\n";
		}
	|	OrderDirSpec  OrderEmptySpec
		{
			cout << "OrderModifier [dir.empty]\n";
		}
	|	OrderDirSpec  OrderCollationSpec
		{
			cout << "OrderModifier [dir.collation]\n";
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
			cout << "OrderModifier [empty.collation]\n";
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
			cout << "OrderModifier [dir.empty.collation]\n";
		}
	;


// [41a] OrderDirSpec
// ------------------
OrderDirSpec :
		ASCENDING
		{
			cout << "OrderDirSpec [ascending]\n";
		}
	|	DESCENDING
		{
			cout << "OrderDirSpec [descending]\n";
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
			cout << "OrderEmptySpec [greatest]\n";
		}
	|	EMPTY_LEAST
		{
			cout << "OrderEmptySpec [least]\n";
		}
	;


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec :
		COLLATION  URI_LITERAL
		{
			cout << "OrderCollationSpec [ ]\n";
		}
	;


// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr :
		SOME_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			cout << "QuantifiedExpr [some]\n";
		}
	|	EVERY_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			cout << "QuantifiedExpr [every]\n";
		}
	;


// [42a] QVarInDeclList
// --------------------
QVarInDeclList :
		QVarInDecl  %prec QVARINDECLLIST_REDUCE
		{
			cout << "QVarInDeclList [single]\n";
		}
	|	QVarInDecl  COMMA_DOLLAR  QVarInDeclList
		{
			cout << "QVarInDeclList [list]\n";
		}
	;


// [42b] QVarInDecl
// ----------------
QVarInDecl :
		VARNAME  IN  ExprSingle 
		{
			cout << "QVarInDecl [in]\n";
		}
	|	VARNAME  TypeDeclaration  IN  ExprSingle 
		{
			cout << "QVarInDecl [type.in]\n";
		}
	;


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
		TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
			cout << "TypeswitchExpr [cases.default.return]\n";
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
			cout << "TypeswitchExpr [cases.default.varname.return]\n";
		}
	;


// [43a] CaseClauseList
// --------------------
CaseClauseList :
		CaseClause
		{
			cout << "CaseClauseList [single]\n";
		}
	|	CaseClauseList  CaseClause
		{
			cout << "CaseClauseList [list]\n";
		}
	;


// [44] CaseClause
// ---------------
CaseClause :
		CASE  SequenceType  RETURN  ExprSingle
		{
			cout << "CaseClause [case.return]\n";
		}
	|	CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
			cout << "CaseClause [case.as.return]\n";
		}
	;


// [45] IfExpr
// -----------
IfExpr :
		IF_LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
			cout << "IfExpr [ ]\n";
		}
	;


// [46] OrExpr
// -----------
OrExpr :
		AndExpr
		{
			cout << "OrExpr [and]\n";
		}
	|	OrExpr  OR  AndExpr
		{
			cout << "OrExpr [or.and]\n";
		}
	;


// [47] AndExpr
// ------------
AndExpr :
		ComparisonExpr
		{
			cout << "AndExpr [comp]\n";
		}
	|	AndExpr  AND  ComparisonExpr
		{
			cout << "AndExpr [and.comp]\n";
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
			cout << "ComparisonExpr [ftcontains]\n";
		}
	| FTContainsExpr  ValueComp  FTContainsExpr
		{
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			cout << "ComparisonExpr [ftcontains.valcomp.ftcontains]\n";
		}
	| FTContainsExpr  GeneralComp  FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			cout << "ComparisonExpr [ftcontains.gencomp.ftcontains]\n";
		}
	| FTContainsExpr  NodeComp  FTContainsExpr
		{
			/*  ::=  "is" | "<<" | ">>" */
			cout << "ComparisonExpr [ftcontains.nodecomp.ftcontains]\n";
		}
	;


//[48a] FTContainsExpr
//-------------------
FTContainsExpr :
		RangeExpr  %prec FTCONTAINS_REDUCE
		{
			cout << "FTContainsExpr [range]\n";
		}
	|	RangeExpr  FTCONTAINS  FTSelection 
		{
			cout << "FTContainsExpr [range.ftselect]\n";
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
			cout << "FTContainsExpr [range.ftselect.ftignore]\n";
		}
	;


// [49] RangeExpr
// --------------
RangeExpr :
		AdditiveExpr  %prec RANGE_REDUCE
		{
			cout << "RangeExpr [add]\n";
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
			cout << "RangeExpr [add.to.add]\n";
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr  %prec ADDITIVE_REDUCE
		{
			cout << "AdditiveExpr [mult]\n";
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
			cout << "AdditiveExpr [mult+mult]\n";
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
			cout << "AdditiveExpr [mult-mult]\n";
		}
	;


// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr :
		UnionExpr  %prec MULTIPLICATIVE_REDUCE
		{
			cout << "MultiplicativeExpr [union]\n";
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
			cout << "MultiplicativeExpr [mult*union]\n";
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
			cout << "MultiplicativeExpr [mult.div.union]\n";
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
			cout << "MultiplicativeExpr [mult.idiv.union]\n";
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
			cout << "MultiplicativeExpr [mult.mod.union]\n";
		}
	;


// [52] UnionExpr
// --------------
UnionExpr :
		IntersectExceptExpr  %prec UNION_REDUCE
		{
			cout << "UnionExpr [interexcept]\n";
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
			cout << "UnionExpr [union.union.interexcept]\n";
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
			cout << "UnionExpr [union|interexcept]\n";
		}
	;


// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr :
		InstanceofExpr  %prec INTERSECT_EXCEPT_REDUCE
		{
			cout << "IntersectExceptExpr [instanceof]\n";
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
			cout << "IntersectExceptExpr [interexcept.inter.instanceof]\n";
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
			cout << "IntersectExceptExpr [interexcept.except.instanceof]\n";
		}
	;


// [54] InstanceofExpr
// -------------------
InstanceofExpr :
		TreatExpr
		{
			cout << "InstanceofExpr [treat]\n";
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
			cout << "InstanceofExpr [treat.seqtype]\n";
		}
	;


// [55] TreatExpr
// --------------
TreatExpr :
		CastableExpr
		{
			cout << "TreatExpr [castable]\n";
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
			cout << "TreatExpr [castable.seqtype]\n";
		}
	;


// [56] CastableExpr
// -----------------
CastableExpr :
		CastExpr
		{
			cout << "CastableExpr [cast]\n";
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
			cout << "CastableExpr [cast.singletype]\n";
		}
	;


// [57] CastExpr 	   
// -------------
CastExpr :
		UnaryExpr
		{
			cout << "CastExpr [unary]\n";
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
			cout << "CastExpr [unary.singletype]\n";
		}
	;


// [58] UnaryExpr
// --------------
UnaryExpr :
		ValueExpr
		{
			cout << "UnaryExpr [value]\n";
		}
	|	SignList  ValueExpr
		{
			cout << "UnaryExpr [signlist.value]\n";
		}
	;


// [58a] SignList
// --------------
SignList :
		PLUS
		{
			cout << "SignList [+]\n";
		}
	|	MINUS
		{
			cout << "SignList [-]\n";
		}
	|	SignList  PLUS
		{
			cout << "SignList [signlist.+]\n";
		}
	|	SignList  MINUS
		{
			cout << "SignList [signlist.-]\n";
		}
	;


// [59] ValueExpr
// --------------
ValueExpr :
		ValidateExpr
		{
			cout << "ValueExpr [validate]\n";
		}
	|	PathExpr
		{
			cout << "ValueExpr [path]\n";
		}
	|	ExtensionExpr
		{
			cout << "ValueExpr [extension]\n";
		}
	;



// [60] GeneralComp
// ----------------
GeneralComp :
		EQUALS
		{
			cout << "GeneralComp [=]\n";
		}
	| NE
		{
			cout << "GeneralComp [!=]\n";
		}
	| LT
		{
			cout << "GeneralComp [<]\n";
		}
	| LE
		{
			cout << "GeneralComp [<=]\n";
		}
	| GT
		{
			cout << "GeneralComp [>]\n";
		}
	| GE
		{
			cout << "GeneralComp [>=]\n";
		}
	;


// [61] ValueComp
// --------------
ValueComp :
		VAL_EQ
		{
			cout << "ValueComp [eq]\n";
		}
	| VAL_NE
		{
			cout << "ValueComp [ne]\n";
		}
	| VAL_LT
		{
			cout << "ValueComp [lt]\n";
		}
	| VAL_LE
		{
			cout << "ValueComp [le]\n";
		}
	| VAL_GT
		{
			cout << "ValueComp [gt]\n";
		}
	| VAL_GE
		{
			cout << "ValueComp [ge]\n";
		}
	;


// [62] NodeComp
// -------------
NodeComp :
		IS
		{
			cout << "NodeComp [is]\n";
		}
	| PRECEDES
		{
			cout << "NodeComp [<<]\n";
		}
	| FOLLOWS
		{
			cout << "NodeComp [>>]\n";
		}
	;



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
			cout << "ValidateExpr [expr]\n";
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
			cout << "ValidateExpr [mode.expr]\n";
		}
	;


// [64] ExtensionExpr
// ------------------
ExtensionExpr :
		PragmaList  LBRACE  RBRACE
		{
			cout << "ExtensionExpr [pragmalist]\n";
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
			cout << "ExtensionExpr [pragmalist.expr]\n";
		}
	;


// [64a] PragmaList
// ----------------
PragmaList :
		Pragma
		{
			cout << "PragmaList [single]\n";
		}
	|	PragmaList  Pragma
		{
			cout << "PragmaList [list]\n";
		}
	;


// [65] Pragma
// -----------
Pragma :
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL  PRAGMA_END
		{
			cout << "Pragma [ ]\n";
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
			cout << "PathExpr [/]\n";
		}
	|	SLASH  RelativePathExpr
		{
			cout << "PathExpr [/relative]\n";
		}
	|	SLASH_SLASH  RelativePathExpr
		{
			cout << "PathExpr [//relative]\n";
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
			cout << "PathExpr [relative]\n";
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
			cout << "RelativePathExpr [step]\n";
		}
	|	StepExpr  SLASH  RelativePathExpr 
		{
			cout << "RelativePathExpr [step/relative]\n";
		}
	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
			cout << "RelativePathExpr [step//relative]\n";
		}
	;


// [69] StepExpr
// -------------
StepExpr :
		AxisStep
		{
			cout << "StepExpr [axis]\n";
		}
	|	FilterExpr
		{
			cout << "StepExpr [filter]\n";
		}
	;


// [70] AxisStep
// -------------
AxisStep :
		ForwardStep 
		{
			cout << "AxisStep [forward]\n";
		}
	|	ForwardStep  PredicateList
		{
			cout << "AxisStep [forward.predlist]\n";
		}
	|	ReverseStep
		{
			cout << "AxisStep [reverse]\n";
		}
	|	ReverseStep  PredicateList
		{
			cout << "AxisStep [reverse.predlist]\n";
		}
	;


// [71] ForwardStep
// ----------------
ForwardStep :
		ForwardAxis  NodeTest
		{
			cout << "ForwardStep [nodetest]\n";
		}
	|	AbbrevForwardStep
		{
			cout << "ForwardStep [abbrev]\n";
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
			cout << "ForwardAxis [child]\n";
		}
	| DESCENDANT_AXIS
		{
			cout << "ForwardAxis [descendant]\n";
		}
	| ATTRIBUTE_AXIS
		{
			cout << "ForwardAxis [attribute]\n";
		}
	| SELF_AXIS
		{
			cout << "ForwardAxis [self]\n";
		}
	| DESCENDANT_OR_SELF_AXIS
		{
			cout << "ForwardAxis [descendant_or_self]\n";
		}
	| FOLLOWING_SIBLING_AXIS
		{
			cout << "ForwardAxis [following_sibling]\n";
		}
	| FOLLOWING_AXIS
		{
			cout << "ForwardAxis [following]\n";
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
			cout << "AbbrevForwardStep [nodetest]\n";
		}
	|	AT_SIGN  NodeTest
		{
			cout << "AbbrevForwardStep [@ nodetest]\n";
		}
	;


// [74] ReverseStep
// ----------------
ReverseStep :
		ReverseAxis  NodeTest
		{
			cout << "ReverseStep [nodetest]\n";
		}
	|	DOT_DOT
		{
			cout << "ReverseStep [..]\n";
		}
	;


// [75] ReverseAxis
// ----------------
ReverseAxis :
		PARENT_AXIS
		{
			cout << "ReverseAxis [parent]\n";
		}
	| ANCESTOR_AXIS
		{
			cout << "ReverseAxis [ancestor]\n";
		}
	| PRECEDING_SIBLING_AXIS
		{
			cout << "ReverseAxis [preceding_sibling]\n";
		}
	| PRECEDING_AXIS
		{
			cout << "ReverseAxis [preceding]\n";
		}
	| ANCESTOR_OR_SELF_AXIS
		{
			cout << "ReverseAxis [ancestor_or_self]\n";
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
			cout << "NodeTest [kindtest]\n";
		}
	|	NameTest
		{
			cout << "NodeTest [nametest]\n";
		}
	;
 

// [78] NameTest
// -------------
NameTest :
		QNAME
		{
			cout << "NameTest [qname]\n";
		}
	|	Wildcard
		{
			cout << "NameTest [wildcard]\n";
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
			cout << "Wildcard [*]\n";
		}
	|	ELEM_WILDCARD
		{
			cout << "Wildcard [pref:*]\n";
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
			cout << "Wildcard [*:qname]\n";
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr 
		{
			cout << "FilterExpr [primary]\n";
		}
	|	PrimaryExpr  PredicateList
		{
			cout << "FilterExpr [primary.predlist]\n";
		}
	;


// [81] PredicateList
// ------------------
PredicateList :
		Predicate
		{
			cout << "PredicateList [single]\n";
		}
	|	PredicateList  Predicate
		{
			cout << "PredicateList [list]\n";
		}
	;


// [82] Predicate
// --------------
Predicate :
		LBRACK  Expr  RBRACK
		{
			cout << "Predicate [ ]\n";
		}
	;



// [83] PrimaryExpr
// ----------------
PrimaryExpr :
		Literal
		{
			cout << "PrimaryExpr [literal]\n";
			$$ = $1;
		}
	|	VarRef
		{
			cout << "PrimaryExpr [varref]\n";
			$$ = $1;
		}
	|	ParenthesizedExpr
		{
			cout << "PrimaryExpr [paren]\n";
			$$ = $1;
		}
	|	ContextItemExpr
		{
			cout << "PrimaryExpr [context_item]\n";
			$$ = $1;
		}
	|	FunctionCall
		{
			cout << "PrimaryExpr [funcall]\n";
			$$ = $1;
		}
	|	Constructor
		{
			cout << "PrimaryExpr [cons]\n";
			$$ = $1;
		}
	|	OrderedExpr
		{
			cout << "PrimaryExpr [ordered]\n";
			$$ = $1;
		}
	|	UnorderedExpr
		{
			cout << "PrimaryExpr [unordered]\n";
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
			cout << "NumericLiteral [int]\n";
		}
	|	DECIMAL_LITERAL
		{
			cout << "NumericLiteral [decimal]\n";
		}
	|	DOUBLE_LITERAL
		{
			cout << "NumericLiteral [double]\n";
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
			cout << "VarRef [ ]\n";
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
			cout << "ParenthesizedExpr [ ]\n";
		}
	|	LPAR  Expr  RPAR
		{
			cout << "ParenthesizedExpr [expr]\n";
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
			cout << "ContextItemExpr [.]\n";
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
			cout << "OrderedExpr [expr]\n";
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
			cout << "UnorderedExpr [expr]\n";
		}
	;


// [91] FunctionCall
// -----------------
FunctionCall :
		QNAME_LPAR  RPAR
		{
			cout << "FunctionCall [ ]\n";
		}
	|	QNAME_LPAR  ArgList  RPAR 	/* gn: parensXQ */
		{
			cout << "FunctionCall [arglist]\n";
		}
				/* gn: reserved-function-namesXQ */
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
			cout << "ArgList [single]\n";
		}
	|	ArgList  COMMA  ExprSingle
		{
			cout << "ArgList [list]\n";
		}
	;


// [92] Constructor
// ----------------
Constructor :
		DirectConstructor
		{
			cout << "Constructor [direct]\n";
		}
	|	ComputedConstructor
		{
			cout << "Constructor [computed]\n";
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
			cout << "DirectConstructor [element]\n";
		}
	|	DirCommentConstructor
		{
			cout << "DirectConstructor [comment]\n";
		}
	|	DirPIConstructor
		{
			cout << "DirectConstructor [pi]\n";
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  EMPTY_TAG_END /* ws: explicitXQ */
		{
			cout << "DirElemConstructor [<qname/> ]\n";
		}
	| START_TAG  QNAME  DirAttributeList EMPTY_TAG_END /* ws: explicitXQ */
		{
			cout << "DirElemConstructor [<qname attrlist/> ]\n";
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			cout << "DirElemConstructor [<qname attrlist>content</qname>]\n";
		}
	|	START_TAG  QNAME  TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			cout << "DirElemConstructor [<qname>content</qname>]\n";
		}
			/* ws: explicitXQ */
			/* gn: ltXQ */
	;


// [94a] DirElemContentList
// ------------------------
DirElemContentList :
		DirElemContent
		{
			cout << "DirElemContentList [single]\n";
		}
	|	DirElemContentList  DirElemContent
		{
			cout << "DirElemContentList [list]\n";
		}
	;


// [95] DirAttributeList
// ---------------------
DirAttributeList :
		DirAttr
		{
			cout << "DirAttributeList [single]\n";
		}
	|	DirAttributeList  DirAttr
		{
			cout << "DirAttributeList [list]\n";
		}
	;


// [95a] DirAttr
// -------------
DirAttr :
		QNAME  EQUALS  DirAttributeValue 	/* ws: explicitXQ */
		{
			cout << "DirAttr [ ]\n";
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  QuoteAttrContentList  QUOTE
		{
			cout << "DirAttributeValue [quote]\n";
		}
	|	APOS  AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
			cout << "DirAttributeValue [apos]\n";
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList :
		ESCAPE_QUOTE
		{
			cout << "QuoteAttrContentList [""]\n";
		}
	|	QuoteAttrValueContent
		{
			cout << "QuoteAttrContentList [single]\n";
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
			cout << "QuoteAttrContentList [list ""]\n";
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
			cout << "QuoteAttrContentList [list]\n";
		}
	;


// [96b] AposAttrContentList
// -------------------------
AposAttrContentList :
		ESCAPE_APOS
		{
			cout << "AposAttrContentList ['']\n";
		}
	|	AposAttrValueContent
		{
			cout << "AposAttrContentList [single]\n";
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
			cout << "AposAttrContentList [list '']\n";
		}
	|	AposAttrContentList  AposAttrValueContent
		{
			cout << "AposAttrContentList [list]\n";
		}
	;


// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent :
		QUOTE_ATTR_CONTENT
		{
			cout << "QuoteAttrValueContent [quote_attr_content]\n";
		}
	|	CommonContent
		{
			cout << "QuoteAttrValueContent [common_content]\n";
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
			cout << "AposAttrValueContent [apos_attr_content]\n";
		}
	|	CommonContent
		{
			cout << "AposAttrValueContent [common_content]\n";
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
			cout << "DirElemContent [cons]\n";
		}
	|	ELEMENT_CONTENT
		{
			cout << "DirElemContent [elem_content]\n";
		}
	|	CDataSection
		{
			cout << "DirElemContent [cdata]\n";
		}
	|	CommonContent
		{
			cout << "DirElemContent [common_content]\n";
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
		ENTITY_REF
		{
			cout << "CommonContent [entity_ref]\n";
		}
	|	CHAR_REF_LITERAL
		{
			cout << "CommonContent [char_ref]\n";
		}
	|	DOUBLE_LBRACE
		{
			cout << "CommonContent [{{]\n";
		}
	|	DOUBLE_RBRACE
		{
			cout << "CommonContent [}}]\n";
		}
	|	EnclosedExpr
		{
			cout << "CommonContent [expr]\n";
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		XML_COMMENT_BEGIN  EXPR_COMMENT_LITERAL  XML_COMMENT_END 	/* ws: explicitXQ */
		{
			cout << "DirCommentConstructor [ ]\n";
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
			cout << "DirPIConstructor [target]\n"
		}
	|	PI_BEGIN  PI_TARGET  CHAR_LITERAL  PI_END 	/* ws: explicitXQ */
		{
			cout << "DirPIConstructor [target.charlit]\n"
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
			cout << "CDataSection [ ]\n"
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
			cout << "ComputedConstructor [doc]\n";
			$$ = $1;
		}
	|	CompElemConstructor
		{
			cout << "ComputedConstructor [elem]\n";
			$$ = $1;
		}
	|	CompAttrConstructor
		{
			cout << "ComputedConstructor [attr]\n";
			$$ = $1;
		}
	|	CompTextConstructor
		{
			cout << "ComputedConstructor [text]\n";
			$$ = $1;
		}
	|	CompCommentConstructor
		{
			cout << "ComputedConstructor [comment]\n";
			$$ = $1;
		}
	|	CompPIConstructor
		{
			cout << "ComputedConstructor [pi]\n";
			$$ = $1;
		}
	;


// [108] CompDocConstructor
// ------------------------
CompDocConstructor :
		DOCUMENT_LBRACE  Expr  RBRACE
		{
			cout << "CompDocConstructor [ ]\n";
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
			cout << "CompElemConstructor [ ]\n";
		}
	|	ELEMENT_QNAME_LBRACE  Expr  RBRACE
		{
			cout << "CompElemConstructor [content]\n";
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			cout << "CompElemConstructor [name]\n";
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			cout << "CompElemConstructor [name.content]\n";
		}
	;


// [110] ContentExpr
// -----------------
/*
ContentExpr :
		Expr
		{
			cout << "ContentExpr [ ]\n";
		}
	;
*/


// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor :
		ATTRIBUTE_QNAME_LBRACE  RBRACE
		{
			cout << "CompAttrConstructor [ ]\n";
		}
	|	ATTRIBUTE_QNAME_LBRACE  Expr  RBRACE
		{
			cout << "CompAttrConstructor [val]\n";
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			cout << "CompAttrConstructor [name]\n";
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			cout << "CompAttrConstructor [name.val]\n";
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
			cout << "CompTextConstructor [content]\n";
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
			cout << "CompCommentConstructor [content]\n";
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
			cout << "CompPIConstructor [ ]\n";
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
			cout << "CompPIConstructor [content]\n";
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
			cout << "CompPIConstructor [target]\n";
		}
	|	PROCESSING_INSTRUCTION  LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
			cout << "CompPIConstructor [target.content]\n";
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
			cout << "SingleType [atomic]\n";
		}
	|	AtomicType  HOOK
		{
			cout << "SingleType [atomic ?]\n";
		}
	;


// [116] TypeDeclaration
// ---------------------
TypeDeclaration :
		AS  SequenceType
		{
			cout << "TypeDeclaration [as seqtype]\n";
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
			cout << "ItemType [type]\n";
		}
	|	ItemType  OccurrenceIndicator
		{
			cout << "ItemType [type.occurs]\n";
		}
	|	VOID_TEST
		{
			cout << "ItemType [void]\n";
		}
	;


// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator :
		OCCURS_HOOK
		{
			cout << "OccurrenceIndicator [?]\n";
		}
	|	OCCURS_STAR
		{
			cout << "OccurrenceIndicator [*]\n";
		}
	|	OCCURS_PLUS 	/* gn: occurrence-indicatorsXQ */
		{
			cout << "OccurrenceIndicator [+]\n";
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
			cout << "ItemType [atomic]\n";
		}
	|	KindTest
		{
			cout << "ItemType [kind]\n";
		}
	|	ITEM_TEST
		{
			cout << "ItemType [item]\n";
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
			cout << "AtomicType [qname]\n";
		}
	;


// [121] KindTest
// --------------
KindTest :
		DocumentTest
		{
			cout << "KindTest [doc]\n";
			$$ = $1;
		}
	| ElementTest
		{
			cout << "KindTest [elem]\n";
			$$ = $1;
		}
	| AttributeTest
		{
			cout << "KindTest [attr]\n";
			$$ = $1;
		}
	| SchemaElementTest
		{
			cout << "KindTest [schema_elem]\n";
			$$ = $1;
		}
	| SchemaAttributeTest
		{
			cout << "KindTest [schema_attr]\n";
			$$ = $1;
		}
	| PITest
		{
			cout << "KindTest [pi]\n";
			$$ = $1;
		}
	| CommentTest
		{
			cout << "KindTest [comment]\n";
			$$ = $1;
		}
	| TextTest
		{
			cout << "KindTest [text]\n";
			$$ = $1;
		}
	| AnyKindTest
		{
			cout << "KindTest [any]\n";
			$$ = $1;
		}
	;


// [122] AnyKindTest
// -----------------
AnyKindTest :
		NODE_LPAR  RPAR
		{
			cout << "AnyKindTest [ ]\n";
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
			cout << "DocumentTest [ ]\n";
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
			cout << "DocumentTest [elem]\n";
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
			cout << "DocumentTest [schema_elem]\n";
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
			cout << "TextTest [ ]\n";
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
			cout << "CommentTest [ ]\n";
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
			cout << "PITest [ ]\n";
		}
	|	PI_LPAR  NCNAME  RPAR
		{
			cout << "PITest [ncname]\n";
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
			cout << "PITest [stringlit]\n";
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
			cout << "AttributeTest [ ]\n";
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  RPAR
		{
			cout << "AttributeTest [name_or_wild]\n";
		}
	|	ATTRIBUTE_LPAR  AttribNameOrWildcard  COMMA  TypeName  RPAR
		{
			cout << "AttributeTest [name_or_wild.type]\n";
		}
	;


// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard :
		AttributeName
		{
			cout << "AttribNameOrWildcard [attr]\n";
		}
	|	STAR
		{
			cout << "AttribNameOrWildcard [*]\n";
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  AttributeDeclaration  RPAR
		{
			cout << "SchemaAttributeTest [ ]\n";
		}
	;


// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration :
		AttributeName
		{
			cout << "AttributeDeclaration [ ]\n";
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
			cout << "ElementTest [ ]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  RPAR
		{
			cout << "ElementTest [name_or_wild]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR
		{
			cout << "ElementTest [name_or_wild.type]\n";
		}
	|	ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR
		{
			cout << "ElementTest [name_or_wild.type ?]\n";
		}
	;


// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard :
		ElementName
		{
			cout << "ElementNameOrWildcard [elem]\n";
		}
	|	STAR
		{
			cout << "ElementNameOrWildcard [*]\n";
		}
	;


// [133] SchemaElementTest
// -----------------------
SchemaElementTest :
		SCHEMA_ELEMENT_LPAR  ElementDeclaration  RPAR
		{
			cout << "SchemaElementTest [ ]\n";
		}
	;


// [134] ElementDeclaration
// ------------------------
ElementDeclaration :
		ElementName
		{
			cout << "ElementDeclaration [ ]\n";
		}
	;


// [135] AttributeName
// -------------------
AttributeName :
		QNAME
		{
			cout << "AttributeName [ ]\n";
		}
	;


// [136] ElementName
// -----------------
ElementName :
		QNAME
		{
			cout << "ElementName [ ]\n";
		}
	;


// [137] TypeName
// --------------
TypeName :
		QNAME
		{
			cout << "TypeName [ ]\n";
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
			cout << "RevalidationDecl [ ]\n";
		}
	;


// [242]	InsertExpr
// ----------------
InsertExpr :
		DO_INSERT  ExprSingle  INTO  ExprSingle
		{
			cout << "InsertExpr [expr]\n";
		}
	|	DO_INSERT  ExprSingle  AS  FIRST_INTO  ExprSingle
		{
			cout << "InsertExpr [expr.as_first]\n";
		}
	|	DO_INSERT  ExprSingle  AS  LAST_INTO  ExprSingle
		{
			cout << "InsertExpr [expr.as_last]\n";
		}
	| DO_INSERT  ExprSingle  AFTER  ExprSingle
		{
			cout << "InsertExpr [expr.after]\n";
		}
	| DO_INSERT  ExprSingle  BEFORE  ExprSingle
		{
			cout << "InsertExpr [expr.before]\n";
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		DO_DELETE  ExprSingle
		{
			cout << "DeleteExpr [expr]\n";
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		DO_REPLACE  ExprSingle  WITH  ExprSingle
		{
			cout << "ReplaceExpr [expr.expr]\n";
		}
	|	DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
		{
			cout << "ReplaceExpr [value.expr]\n";
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		DO_RENAME  ExprSingle  AS  ExprSingle
		{
			cout << "RenameExpr [expr.expr]\n";
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
			cout << "TransformExpr [ ]\n";
		}
	;


// [249a] VarNameList
// ------------------
VarNameList :
		VARNAME	 GETS  ExprSingle
		{
			cout << "VarNameList [single]\n";
		}
	|	VarNameList  COMMA_DOLLAR  VARNAME  GETS  ExprSingle
		{
			cout << "VarNameList [list]\n";
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
			cout << "FTSelection [or]\n";
		}
	|	FTOr  FTMatchOptionProximityList
		{
			cout << "FTSelection [or.match_proximity]\n";
		}
	|	FTOr  WEIGHT  RangeExpr
		{
			cout << "FTSelection [or.weight_range]\n";
		}
	|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
		{
			cout << "FTSelection [or.match_proximity.weight_range]\n";
		}
	;


//[344a] FTMatchOptionProximityList
//---------------------------------
FTMatchOptionProximityList :
		FTMatchOption
		{
			cout << "FTMatchOptionProximityList [option_single]\n";
		}
	| FTProximity
		{
			cout << "FTMatchOptionProximityList [proximity_single]\n";
		}
	| FTMatchOptionProximityList  FTMatchOption
		{
			cout << "FTMatchOptionProximityList [option_list]\n";
		}
	| FTMatchOptionProximityList  FTProximity
		{
			cout << "FTMatchOptionProximityList [proximity_list]\n";
		}
	;


//[345]	FTOr
//----------
FTOr :
		FTAnd
		{
			cout << "FTOr [and]\n";
		}
	|	FTOr  FTOR  FTAnd
		{
			cout << "FTOr [or.and]\n";
		}
	;


//[346]	FTAnd
//-----------
FTAnd :
		FTMildnot
		{
			cout << "FTAnd [mild_not]\n";
		}
	|	FTAnd  FTAND  FTMildnot
		{
			cout << "FTAnd [and.mild_not]\n";
		}
	;


//[347]	FTMildnot
//---------------
FTMildnot :
		FTUnaryNot
		{
			cout << "FTMildNot [unary_not]\n";
		}
	|	FTMildnot  FTNOT_IN  FTUnaryNot
		{
			cout << "FTMildNot [mild_not.unary_not]\n";
		}
	;


//[348]	FTUnaryNot
//----------------
FTUnaryNot :
		FTWordsSelection
		{
			cout << "FTUnaryNot [words]\n";
		}
	|	FTNOT  FTWordsSelection
		{
			cout << "FTUnaryNot [not.words]\n";
		}
	;


//[349]	FTWordsSelection
//----------------------
FTWordsSelection :
		FTWords
		{
			cout << "FTWordsSelection [words]\n";
		}
	|	FTWords FTTimes
		{
			cout << "FTWordsSelection [words.times]\n";
		}
	| LPAR  FTSelection  RPAR
		{
			cout << "FTWordsSelection [selection]\n";
		}
	;


//[350]	FTWords
//-------------
FTWords :
		FTWordsValue 
		{
			cout << "FTWords [value]\n";
		}
	|	FTWordsValue  FTAnyallOption
		{
			cout << "FTWords [value.any_all_option]\n";
		}
	;


//[351]	FTWordsValue
//------------------
FTWordsValue :
		Literal
		{
			cout << "FTWordsValue [literal]\n";
		}
	| LBRACE  Expr  RBRACE
		{
			cout << "FTWordsValue [expr]\n";
		}
	;


//[352]	FTProximity
//-----------------
FTProximity :
		FTOrderedIndicator
		{
			cout << "FTProximity [order]\n";
		}
	| FTWindow
		{
			cout << "FTProximity [window]\n";
		}
	| FTDistance
		{
			cout << "FTProximity [distance]\n";
		}
	| FTScope
		{
			cout << "FTProximity [scope]\n";
		}
	| FTContent
		{
			cout << "FTProximity [content]\n";
		}
	;


//[353]	FTOrderedIndicator
//------------------------
FTOrderedIndicator :
		ORDERED
		{
			cout << "FTOrderedIndicator [ ]\n";
		}
	;


//[354] FTMatchOption 	
//-------------------
FTMatchOption :
		FTCaseOption
		{
			cout << "FTMatchOption [case]\n";
			$$ = $1;
		}
	| FTDiacriticsOption
		{
			cout << "FTMatchOption [diacritics]\n";
			$$ = $1;
		}
	| FTStemOption
		{
			cout << "FTMatchOption [stem]\n";
			$$ = $1;
		}
	| FTThesaurusOption
		{
			cout << "FTMatchOption [thesaurus]\n";
			$$ = $1;
		}
	| FTStopwordOption
		{
			cout << "FTMatchOption [stopword]\n";
			$$ = $1;
		}
	| FTLanguageOption
		{
			cout << "FTMatchOption [language]\n";
			$$ = $1;
		}
	| FTWildCardOption
		{
			cout << "FTMatchOption [wildcard]\n";
			$$ = $1;
		}
	;


//[355] FTCaseOption
//------------------
FTCaseOption :
		LOWERCASE
		{
			cout << "FTCaseOption [lower]\n";
		}
	| UPPERCASE
		{
			cout << "FTCaseOption [upper]\n";
		}
	| CASE_SENSITIVE
		{
			cout << "FTCaseOption [sensitive]\n";
		}
	| CASE_INSENSITIVE
		{
			cout << "FTCaseOption [insensitive]\n";
		}
	;


//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption :
		WITH_DIACRITICS
		{
			cout << "FTDiacriticsOption [with]\n";
		}
	| WITHOUT_DIACRITICS
		{
			cout << "FTDiacriticsOption [without]\n";
		}
	| DIACRITICS_SENSITIVE
		{
			cout << "FTDiacriticsOption [sensitive]\n";
		}
	| DIACRITICS_INSENSITIVE
		{
			cout << "FTDiacriticsOption [insensitive]\n";
		}
	;


//[357] FTStemOption
//------------------
FTStemOption :
		WITH_STEMMING
		{
			cout << "FTStemOption [with]\n";
		}
	| WITHOUT_STEMMING
		{
			cout << "FTStemOption [without]\n";
		}
	;


//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption :
		WITH_THESAURUS  FTThesaurusID
		{
			cout << "FTThesaurusOption [id]\n";
		}
	|	WITH_THESAURUS  DEFAULT
		{
			cout << "FTThesaurusOption [default]\n";
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID  RPAR
		{
			cout << "FTThesaurusOption [(id)]\n";
		}
	| WITH_THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
		{
			cout << "FTThesaurusOption [(id,id,..)]\n";
		}
	| WITH_THESAURUS  LPAR  DEFAULT  RPAR
		{
			cout << "FTThesaurusOption [(default)]\n";
		}
	| WITH_THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
		{
			cout << "FTThesaurusOption [(default,id,id,..)]\n";
		}
	| WITHOUT_THESAURUS
		{
			cout << "FTThesaurusOption [without]\n";
		}
	;


//[358a] FTThesaurusIDList
//------------------------
FTThesaurusList :
		FTThesaurusID
		{
			cout << "FTThesaurusList [single]\n";
		}
	| FTThesaurusList  COMMA  FTThesaurusID
		{
			cout << "FTThesaurusList [list]\n";
		}
	;


//[359] FTThesaurusID
//-------------------
FTThesaurusID :
		AT  STRING_LITERAL
		{
			cout << "FTThesaurusID [name]\n";
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL
		{
			cout << "FTThesaurusID [name.rel]\n";
		}
	|	AT  STRING_LITERAL  FTRange  LEVELS
		{
			cout << "FTThesaurusID [name.range]\n";
		}
	|	AT  STRING_LITERAL  RELATIONSHIP  STRING_LITERAL  FTRange  LEVELS
		{
			cout << "FTThesaurusID [name.rel.range]\n";
		}
	;


//[360] FTStopwordOption
//----------------------
FTStopwordOption :
		WITH_STOP_WORDS  FTRefOrList
		{
			cout << "FTStopwordOption [list]\n";
		}
	|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
		{
			cout << "FTStopwordOption [list.incl_excl]\n";
		}
	| WITH_DEFAULT_STOP_WORDS 
		{
			cout << "FTStopwordOption [default]\n";
		}
	| WITH_DEFAULT_STOP_WORDS  FTInclExclStringLiteralList
		{
			cout << "FTStopwordOption [default.incl_excl]\n";
		}
	| WITHOUT_STOP_WORDS
		{
			cout << "FTStopwordOption [without]\n";
		}
	;


//[360a] FTInclExclStringLiteralList
//----------------------------------
FTInclExclStringLiteralList :
		FTInclExclStringLiteral
		{
			cout << "FTInclExclStringLiteralList [.]\n";
		}
	| FTInclExclStringLiteralList  FTInclExclStringLiteral
		{
			cout << "FTInclExclStringLiteralList [*]\n";
		}
	;


//[361] FTRefOrList
//-----------------
FTRefOrList :
		AT  STRING_LITERAL
		{
			cout << "FTRefOrList [.]\n";
		}
	| LPAR  FTStringLiteralList  RPAR 
		{
			cout << "FTRefOrList [(*)]\n";
		}
	;


//[361a] FTStringLiteralList
//--------------------------
FTStringLiteralList :
		STRING_LITERAL
		{
			cout << "FTStringLiteralList [.]\n";
		}
	|	FTStringLiteralList  STRING_LITERAL
		{
			cout << "FTStringLiteralList [*]\n";
		}
	;


//[362] FTInclExclStringLiteral
//-----------------------------
FTInclExclStringLiteral :
		UNION  FTRefOrList
		{
			cout << "FTInclExclStringLiteral [union]\n";
		}
	|	EXCEPT  FTRefOrList
		{
			cout << "FTInclExclStringLiteral [except]\n";
		}
	;


//[363] FTLanguageOption
//----------------------
FTLanguageOption :
		LANGUAGE  STRING_LITERAL
		{
			cout << "FTLanguageOption [ ]\n";
		}
	;


//[364] FTWildCardOption
//----------------------
FTWildCardOption :
		WITH_WILDCARDS
		{
			cout << "FTWildCardOption [with]\n";
		}
	| WITHOUT_WILDCARDS
		{
			cout << "FTWildCardOption [without]\n";
		}
	;


//[365]	FTContent
//---------------
FTContent :
		AT_START
		{
			cout << "FTContent [start]\n";
		}
	| AT_END
		{
			cout << "FTContent [end]\n";
		}
	| ENTIRE_CONTENT
		{
			cout << "FTContent [entire]\n";
		}
	;


//[366]	FTAnyallOption
//--------------------
FTAnyallOption :
		ANY
		{
			cout << "FTAnyallOption [any]\n";
		}
	|	ANY_WORD
		{
			cout << "FTAnyallOption [any_word]\n";
		}
	| ALL
		{
			cout << "FTAnyallOption [all]\n";
		}
	| ALL_WORDS
		{
			cout << "FTAnyallOption [all_words]\n";
		}
	| PHRASE
		{
			cout << "FTAnyallOption [phrase]\n";
		}
	;


//[367]	FTRange
//-------------
FTRange :
		EXACTLY  UnionExpr
		{
			cout << "FTRange [exactly]\n";
		}
	| AT_LEAST  UnionExpr
		{
			cout << "FTRange [at_least]\n";
		}
	| AT_MOST  UnionExpr
		{
			cout << "FTRange [at_most]\n";
		}
	| FROM  UnionExpr  TO  UnionExpr
		{
			cout << "FTRange [range]\n";
		}
	;


//[368]	FTDistance
//----------------
FTDistance :
		DISTANCE  FTRange  FTUnit
		{
			cout << "FTDistance [ ]\n";
		}
	;


//[369]	FTWindow
//--------------
FTWindow :
		WINDOW  UnionExpr  FTUnit
		{
			cout << "FTWindow [ ]\n";
		}
	;


//[370]	FTTimes
//-------------
FTTimes :
		OCCURS  FTRange  TIMES
		{
			cout << "FTTimes [ ]\n";
		}
	;


//[371]	FTScope
//-------------
FTScope :
		SAME  FTBigUnit
		{
			cout << "FTTimes [same]\n";
		}
	|	DIFFERENT  FTBigUnit
		{
			cout << "FTTimes [different]\n";
		}
	;


//[372]	FTUnit
//------------
FTUnit :
		WORDS
		{
			cout << "FTUnit [words]\n";
		}
	| SENTENCES
		{
			cout << "FTUnit [sentences]\n";
		}
	| PARAGRAPH
		{
			cout << "FTUnit [paragraph]\n";
		}
	;


//[373]	FTBigUnit
//---------------
FTBigUnit :
		SENTENCE
		{
			cout << "FTBigUnit [sentence]\n";
		}
	| PARAGRAPH
		{
			cout << "FTBigUnit [paragraph]\n";
		}
	;


//[374]	FTIgnoreOption
//--------------------
FTIgnoreOption :
		WITHOUT_CONTENT  UnionExpr
		{
			cout << "FTIgnoreOption [ ]\n";
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




