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
/*
**	The parser definition file starts by asking for the C++ LALR(1) 
**	skeleton, the creation of the parser header file, and specifies the 
**	name of the parser class.  Because the C++ skeleton changes, it is
**	safer to require the version. 
*/

%skeleton "lalr1.cc"  /*  -*- C++ -*- */
%require "2.3"
%defines
%name-prefix="zorba"
%define "parser_class_name" "xquery_parser"
%error-verbose

/*
**	Because the parser uses the xquery_driver and reciprocally, both 
**	cannot include the header of the other. Because the driver's header 
**	needs detailed knowledge about the parser class (in particular its 
**	inner types), it is the parser's header which will use a forward
**	declaration of the driver. 
*/

%{

#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <string>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "store/api/update_consts.h"


#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba {
  class xquery_driver;

  class FunctionSig {
  public:
    rchandle<ParamList> param;
    rchandle<SequenceType> ret;
    FunctionSig (ParamList *param_, SequenceType *ret_ = NULL)
      : param (param_), ret (ret_)
    {}
  };
}

#define YYDEBUG 1

%}

%pure-parser

/*
**	The driver is passed by reference to the parser and to the scanner. 
**	This provides a simple but effective pure interface, not relying on 
**	global variables. 
*/
%parse-param { xquery_driver& driver }


/*
**	Request the location tracking feature, and initialize the 
**	first location's file name. Afterwards new locations are computed 
**	relatively to the previous locations: the file name will be 
**	automatically propagated. 
*/
%locations
%initial-action
{
  @$.begin.filename = @$.end.filename = &(driver.theFilename);
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
  zorba::parsenode * node;
  zorba::exprnode * expr;
  zorba::FunctionSig *fnsig;
  off_t sval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
};




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
%token <sval> CHAR_LITERAL_AND_CDATA_END  "'char literal]]>'"
%token <sval> CHAR_LITERAL_AND_PI_END "'char literal and pi end'"
%token <sval> CHAR_REF_LITERAL				"'#charref;'"
%token <sval> ELEMENT_CONTENT					"'element content'"
%token <sval> ELEMENT_QNAME_LBRACE		"'<QName {>'"
%token <sval> ELEM_WILDCARD						"'pref:*'"
%token <sval> ENTITY_REF							"'&entity;'"
%token <sval> EXPR_COMMENT_LITERAL		"'comment literal'"
%token <sval> NCNAME									"'NCName'"
%token <sval> PI_NCNAME_LBRACE				"'pi <NCName {>'"
%token <sval> PI_TARGET_LITERAL				"'pi target'"
%token <sval> PRAGMA_LITERAL_AND_END  "'pragma literal and end'"
%token <sval> PREFIX_WILDCARD					"'*:QName'"
%token <sval> QNAME										"'QName'"
%token <sval> QNAME_AND_END_PRAGMA    "'QName #)'"
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
%token <decval> DECIMAL_LITERAL	  "'DECIMAL'"
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
%token DECLARE_SEQ_FUNCTION       "'<declare sequential function>'"
%token EXIT_WITH                  "'<exit with>'"
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
%token <dval> DOUBLE_LITERAL			"'DOUBLE'"
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
%token <ival> INTEGER_LITERAL			"'INTEGER'"
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
%token GROUP_BY                   "'<group by>'"
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
%token DECLARE_REVALIDATION	      "'<declare revalidation>'"
%token REVAL_STRICT								"'strict'"
%token REVAL_LAX							  	"'lax'"
%token REVAL_SKIP							  	"'skip'"
%token DELETE_NODE                "'<delete node>'"           
%token DELETE_NODES               "'<delete nodes>'"          
%token INSERT_NODE                "'<insert node>'"           
%token INSERT_NODES               "'<insert nodes>'"          
%token RENAME                     "'<rename>'"                
%token REPLACE                    "'<replace node>'"          
%token REPLACE_VALUE_OF           "'<replace value of node>'" 
%token FIRST_INTO                 "'<as first into>'"               
%token INTO												"'into'"
%token LAST_INTO							  	"'<as last into>'"
%token MODIFY 										"'modify'"
%token COPY_DOLLAR          			"'<copy $>'"
%token WITH												"'with'"

/* try-catch-related */
/* ----------------- */
%token TRY                        "'<try>'"   
%token CATCH_LPAR                 "'<catch (>'" 


/* eval-related */
/* ------------ */
%token USING_DOLLAR               "'<using $>'"
%token EVAL_LBRACE                "'<eval {>'"

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
%type <node> GroupByClause
%type <node> GroupSpecList
%type <node> GroupSpec
%type <node> GroupCollationSpec
%type <node> LetClauseList
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
%type <node> EvalVarDecl
%type <node> EvalVarDeclList
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
%type <expr> BracedExpr
%type <expr> Block;
%type <expr> BlockBody;
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
%type <expr> ExitExpr


/* update-related */
/* -------------- */
%type <expr> DeleteExpr
%type <expr> InsertExpr
%type <expr> RenameExpr
%type <expr> ReplaceExpr
%type <node> RevalidationDecl
%type <expr> TransformExpr
%type <expr> VarNameList
%type <expr> VarNameDecl

/* try-catch-related */
/* ----------------- */
%type <expr> TryExpr
%type <expr> CatchListExpr
%type <expr> CatchExpr

/* eval-related      */
/* ----------------- */
%type <expr> EvalExpr

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

%type <fnsig> FunctionSig

// destructors for token values
%destructor { delete $$; } INTEGER_LITERAL
%destructor { delete $$; } DOUBLE_LITERAL
%destructor { delete $$; } DECIMAL_LITERAL

// Module must not be destroyed since it is returned by the parser
// TODO: FT stuff, update stuff
// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
%destructor { RCHelper::addReference ($$); RCHelper::removeReference ($$); } AbbrevForwardStep AnyKindTest AposAttrContentList Opt_AposAttrContentList AposAttrValueContent ArgList AtomicType AttributeTest BaseURIDecl BoundarySpaceDecl CaseClause CaseClauseList CommentTest ConstructionDecl CopyNamespacesDecl DefaultCollationDecl DefaultNamespaceDecl DirAttr DirAttributeList DirAttributeValue DirElemContentList DocumentTest ElementTest EmptyOrderDecl ForClause ForLetClause ForLetClauseList ForwardAxis ForwardStep FunctionDecl GeneralComp Import ItemType KindTest LetClause LibraryModule MainModule /* Module */ ModuleDecl ModuleImport NameTest NamespaceDecl NodeComp NodeTest OccurrenceIndicator OptionDecl GroupByClause GroupSpecList GroupSpec GroupCollationSpec LetClauseList OrderByClause OrderCollationSpec OrderDirSpec OrderEmptySpec OrderModifier OrderSpec OrderSpecList OrderingModeDecl PITest Param ParamList PositionalVar Pragma PragmaList PredicateList Prolog QVarInDecl QVarInDeclList QuoteAttrValueContent QuoteAttrContentList Opt_QuoteAttrContentList ReverseAxis ReverseStep SIND_Decl SIND_DeclList SchemaAttributeTest SchemaElementTest SchemaImport SchemaPrefix SequenceType Setter SignList SingleType TextTest TypeDeclaration TypeName TypeName_WITH_HOOK URILiteralList ValueComp VarDecl VarGetsDecl VarGetsDeclList VarInDecl VarInDeclList EvalVarDecl EvalVarDeclList VersionDecl VFO_Decl VFO_DeclList WhereClause Wildcard // RevalidationDecl FTAnd FTAnyallOption FTBigUnit FTCaseOption FTContent FTDiacriticsOption FTDistance FTIgnoreOption FTInclExclStringLiteral FTInclExclStringLiteralList FTLanguageOption FTMatchOption FTMatchOptionProximityList FTMildnot FTOptionDecl FTOr FTOrderedIndicator FTProximity FTRange FTRefOrList FTScope FTScoreVar FTSelection FTStemOption FTStopwordOption FTStringLiteralList FTThesaurusID FTThesaurusList FTThesaurusOption FTTimes FTUnaryNot FTUnit FTWildcardOption FTWindow FTWords FTWordsSelection FTWordsValue  FTContainsExpr
%destructor { RCHelper::addReference ($$); RCHelper::removeReference ($$); } AdditiveExpr AndExpr AxisStep CDataSection CastExpr CastableExpr CommonContent ComparisonExpr CompAttrConstructor CompCommentConstructor CompDocConstructor CompElemConstructor CompPIConstructor CompTextConstructor ComputedConstructor Constructor ContextItemExpr DirCommentConstructor DirElemConstructor DirElemContent DirPIConstructor DirectConstructor BracedExpr Block BlockBody EnclosedExpr Expr ExprSingle ExtensionExpr FLWORExpr FilterExpr FunctionCall IfExpr InstanceofExpr IntersectExceptExpr Literal MultiplicativeExpr NumericLiteral OrExpr OrderedExpr ParenthesizedExpr PathExpr Predicate PrimaryExpr QuantifiedExpr QueryBody RangeExpr RelativePathExpr StepExpr StringLiteral TreatExpr TypeswitchExpr UnaryExpr UnionExpr UnorderedExpr ValidateExpr ValueExpr VarRef TryExpr CatchListExpr CatchExpr EvalExpr DeleteExpr InsertExpr RenameExpr ReplaceExpr TransformExpr VarNameList VarNameDecl ExitExpr
%destructor { delete $$; } FunctionSig;

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
// FIXME COMMA_DOLLAR is not defined anymore
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
**	The code between `%{' and `%}' after the introduction of the `%union' 
**	is output in the *.cc file; it needs detailed knowledge about the 
**	driver. 
*/
%{
#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex
%}

/*
	The grammar
*/

%%
%start Module;



// [1] Module
// ----------
// TODO: use VersionDecl's when available
Module :
    MainModule
		{
			$$ = $1;
			driver.set_expr ($$);
		}
  | VersionDecl MainModule
		{
      dynamic_cast<MainModule *> ($2)->set_version_decl (static_cast<VersionDecl *> ($1));
			$$ = $2;
			driver.set_expr ($$);
		}
  | LibraryModule 
		{
       $$ = $1;
       driver.set_expr ($$);
		}
  | VersionDecl LibraryModule 
		{
       dynamic_cast<LibraryModule *> ($2)->set_version_decl (static_cast<VersionDecl *> ($1));
       $$ = $2;
       driver.set_expr ($$);
		}
  ;


// [2] VersionDecl
// ---------------
VersionDecl :
		XQUERY_VERSION  STRING_LITERAL  SEMI
		{
       std::string encoding = "utf-8";
       $$ = new VersionDecl (LOC (@$), SYMTAB ($2), encoding);
		}
	|	XQUERY_VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
       $$ = new VersionDecl (LOC (@$), SYMTAB ($2), SYMTAB ($4));
    }
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
			$$ = new MainModule(LOC (@$),
								static_cast<Prolog*>($1),
								static_cast<QueryBody*>($2));
		}
	|
    QueryBody
		{
			$$ = new MainModule(LOC (@$),
								NULL,
								static_cast<QueryBody*>($1));
		}
  ;


// [4] LibraryModule
// -----------------
LibraryModule :
		ModuleDecl  Prolog
		{
			$$ = new LibraryModule(LOC (@$),
								static_cast<ModuleDecl*>($1),
								static_cast<Prolog*>($2));
		}
	;


// [5] ModuleDecl
// --------------
ModuleDecl :
		MODULE_NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
			$$ = new ModuleDecl(LOC (@$),
								driver.symtab.get((off_t)$2), 
								driver.symtab.get((off_t)$4));
		}
	;


// [6] Prolog
// ----------
Prolog :
		SIND_DeclList  SEMI
		{
			$$ = new Prolog(LOC (@$),
								static_cast<SIND_DeclList*>($1),
								NULL);
		}
	|	VFO_DeclList  SEMI
		{
			$$ = new Prolog(LOC (@$),
								NULL,
								static_cast<VFO_DeclList*>($1));
		}
	|	SIND_DeclList  SEMI  VFO_DeclList  SEMI
		{
			$$ = new Prolog(LOC (@$),
								static_cast<SIND_DeclList*>($1),
								static_cast<VFO_DeclList*>($3));
		}
	;


// [6a] SIDN_DeclList
// ------------------
SIND_DeclList :
		SIND_Decl
		{
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC (@$));
			sindList_p->push_back($1);
			$$ = sindList_p;
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
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
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC (@$));
			vfoList_p->push_back($1);
			$$ = vfoList_p;
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
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
			$$ = $1;
		}
	| Import
		{
			$$ = $1;
		}
	| NamespaceDecl
		{
			$$ = $1;
		}
	| DefaultNamespaceDecl
		{
			$$ = $1;
		}
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl
		{
			$$ = $1;
		}
	| FunctionDecl
		{
			$$ = $1;
		}
	| OptionDecl
		{
			$$ = $1;
		}
	
	/* full-text extension */
	| FTOptionDecl
		{
			$$ = $1;
		}
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl
		{
			$$ = $1;
		}
	| DefaultCollationDecl
		{
			$$ = $1;
		}
	| BaseURIDecl
		{
			$$ = $1;
		}
	| ConstructionDecl
		{
			$$ = $1;
		}
	| OrderingModeDecl
		{
			$$ = $1;
		}
	| EmptyOrderDecl
		{
			$$ = $1;
		}
	| CopyNamespacesDecl
		{
			$$ = $1;
		}

	/* update extension */
	| RevalidationDecl
		{
			$$ = $1;
		}
	;


// [8] Import
// ----------
Import :
		SchemaImport
		{
			$$ = $1;
		}
	| ModuleImport
		{
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
			$$ = new NamespaceDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								driver.symtab.get((off_t)$4));
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE_BOUNDARY_SPACE  PRESERVE
		{
			$$ = new BoundarySpaceDecl(LOC (@$),
								StaticContextConsts::preserve_space);
		}
	|	DECLARE_BOUNDARY_SPACE  STRIP
		{
			$$ = new BoundarySpaceDecl(LOC (@$),
								StaticContextConsts::strip_space);
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE_DEFAULT_ELEMENT  NAMESPACE  URI_LITERAL
		{
			$$ = new DefaultNamespaceDecl(LOC (@$),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)$3));
		}
	| DECLARE_DEFAULT_FUNCTION  NAMESPACE  URI_LITERAL
		{
			$$ = new DefaultNamespaceDecl(LOC (@$),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)$3));
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE_OPTION  QNAME  STRING_LITERAL
		{
			$$ = new OptionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								driver.symtab.get((off_t)$3));
		}
	;


/* full-text extension */
// [13a] FTOptionDecl
// ------------------
FTOptionDecl :
		DECLARE_FTOPTION  FTMatchOption
		{
			$$ = new FTOptionDecl(LOC (@$),
								$2);
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE_ORDERING  ORDERED
		{
			$$ = new OrderingModeDecl(LOC (@$),
								StaticContextConsts::ordered);
		}
	| DECLARE_ORDERING  UNORDERED
		{
			$$ = new OrderingModeDecl(LOC (@$),
								StaticContextConsts::unordered);
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE_DEFAULT_ORDER  EMPTY_GREATEST
		{
			$$ = new EmptyOrderDecl(LOC (@$),
								StaticContextConsts::empty_greatest);
		}
	|	DECLARE_DEFAULT_ORDER  EMPTY_LEAST
		{
			$$ = new EmptyOrderDecl(LOC (@$),
								StaticContextConsts::empty_least);
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  PRESERVE  COMMA  NO_INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
	| DECLARE_COPY_NAMESPACES  NO_PRESERVE  COMMA  NO_INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
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
			$$ = new DefaultCollationDecl(LOC (@$),
								driver.symtab.get((off_t)$2));
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE_BASE_URI  URI_LITERAL
		{
			$$ = new BaseURIDecl(LOC (@$),
								driver.symtab.get((off_t)$2));
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT_SCHEMA  URI_LITERAL
		{
			$$ = new SchemaImport(LOC (@$),
								NULL,
								driver.symtab.get((off_t)$2),
								NULL);
		}
	| IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL
		{
			$$ = new SchemaImport(LOC (@$),
								dynamic_cast<SchemaPrefix*>($2),
								driver.symtab.get((off_t)$3),
								NULL);
		}
	|	IMPORT_SCHEMA  URI_LITERAL  AT  URILiteralList
		{
			$$ = new SchemaImport(LOC (@$),
								NULL,
								driver.symtab.get((off_t)$2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
		{
			$$ = new SchemaImport(LOC (@$),
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
			URILiteralList* uri_list_p = new URILiteralList(LOC (@$));
			uri_list_p->push_back(driver.symtab.get((off_t)$1));
			$$ = uri_list_p;
		}
	| URILiteralList  COMMA  URI_LITERAL
		{
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
			$$ = new SchemaPrefix(LOC (@$), driver.symtab.get((off_t)$2));
		}
	|	DEFAULT_ELEMENT  NAMESPACE
		{
			$$ = new SchemaPrefix(LOC (@$), true);
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT_MODULE  URI_LITERAL 
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$3),
								driver.symtab.get((off_t)$5),
								NULL);
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URILiteralList
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$2),
								dynamic_cast<URILiteralList*>($4));
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URILiteralList
		{
			$$ = new ModuleImport(LOC (@$),
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
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL,
								$4);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  EXTERNAL
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL,
								NULL);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3),
								$5);
		}
	|	DECLARE_VARIABLE_DOLLAR  VARNAME  TypeDeclaration  EXTERNAL
		{
			$$ = new VarDecl(LOC (@$),
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
			$$ = new ConstructionDecl(LOC (@$),
								StaticContextConsts::cons_preserve);
		}
	|	DECLARE_CONSTRUCTION  STRIP
		{
			$$ = new ConstructionDecl(LOC (@$),
								StaticContextConsts::cons_strip);
		}
	;


// [26] FunctionDecl
// -----------------

FunctionSig :
    LPAR RPAR
    {
      $$ = new FunctionSig (NULL);
    }
  | LPAR ParamList RPAR
    {
      $$ = new FunctionSig (dynamic_cast<ParamList *> ($2));
    }
  | LPAR RPAR AS SequenceType
    {
      $$ = new FunctionSig (NULL, dynamic_cast<SequenceType *> ($4));
    }
  | LPAR ParamList RPAR AS SequenceType
    {
      $$ = new FunctionSig (dynamic_cast<ParamList *> ($2), dynamic_cast<SequenceType *> ($5));
    }
  ;

Block :
    LBRACE BlockBody RBRACE
    {
      $$ = $2;
    }
  ;

BlockBody :
    Expr SEMI
    {
      BlockBody *blk = new BlockBody (LOC (@$));
      blk->add ($1);
      $$ = blk;
    }
  | BlockBody Expr SEMI
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ($1);
      blk->add ($2);
      $$ = blk;
    }
  ;

ExitExpr :
    EXIT_WITH ExprSingle
    {
      $$ = $2;
    }
  ;

FunctionDecl :
		DECLARE_FUNCTION  QNAME FunctionSig EXTERNAL
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
                &* $3->param, &* $3->ret, NULL,
								ParseConstants::fn_extern);
		}
	|	DECLARE_FUNCTION  QNAME FunctionSig BracedExpr
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
                &* $3->param, &* $3->ret, 
								$4,
								ParseConstants::fn_read);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME FunctionSig EXTERNAL
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								&* $3->param, &* $3->ret, 
								NULL,
								ParseConstants::fn_extern_update);
		}
	|	DECLARE_UPDATING_FUNCTION  QNAME FunctionSig BracedExpr
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
                &* $3->param, &* $3->ret, 
								$4,
								ParseConstants::fn_update);
		}
  | DECLARE_SEQ_FUNCTION QNAME FunctionSig Block
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
                &* $3->param, &* $3->ret, 
								$4,
								ParseConstants::fn_sequential);
		}
	;


// [27] ParamList
// --------------
ParamList :
		Param
		{
			ParamList* plist_p = new ParamList(LOC (@$));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>($1));
			}
			$$ = plist_p;
		}
	|	ParamList  COMMA  Param
		{
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
			$$ = new Param(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	DOLLAR  VARNAME  TypeDeclaration
		{
			$$ = new Param(LOC (@$),
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3));
		}
	;


// [29] EnclosedExpr
// -----------------
EnclosedExpr :
		LBRACE  Expr  RBRACE
		{
			$$ = new EnclosedExpr(LOC (@$),
								$2);
		}
	;

BracedExpr :
		LBRACE  Expr  RBRACE
		{
			$$ = $2;
		}
	;



// [30] QueryBody
// --------------
QueryBody :
		Expr
		{
			$$ = new QueryBody(LOC (@$),
								$1);
		}
	;


// [31] Expr
// ---------
Expr :
		ExprSingle 
		{
			Expr* expr_p = new Expr(LOC (@$));
			expr_p->push_back($1);
			$$ = expr_p;
		}
	|	Expr  COMMA  ExprSingle
		{
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
  | TryExpr
    {
      $$ = $1;
    }
  | EvalExpr
    {
      $$ = $1;
    }
  | ExitExpr
    {
      $$ = $1;
    }
    ;


// [33] FLWORExpr
// --------------
FLWORExpr :
	  ForLetClauseList  RETURN  ExprSingle
		{
			$$ = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								NULL,NULL,NULL,
								$3);
		}
	|	ForLetClauseList  WhereClause  RETURN  ExprSingle
		{
			$$ = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
								NULL,NULL,
								$4);
		}
	|	ForLetClauseList  OrderByClause  RETURN  ExprSingle
		{
			$$ = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								NULL,NULL,
								dynamic_cast<OrderByClause*>($2),
								$4);
		}
	|	ForLetClauseList  WhereClause  OrderByClause  RETURN  ExprSingle
		{
			$$ = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
                NULL,
								dynamic_cast<OrderByClause*>($3),
								$5);
		}
  | ForLetClauseList GroupByClause RETURN ExprSingle
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>($2);
			FLWORExpr* lFLWOR = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								NULL,
                lGroupBy,
								NULL,
								$4);
      lGroupBy->set_flwor(lFLWOR);
      $$ = lFLWOR;
    }
  | ForLetClauseList WhereClause GroupByClause RETURN ExprSingle
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>($3);
			FLWORExpr* lFLWOR = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
                lGroupBy,
								NULL,
								$5);
      lGroupBy->set_flwor(lFLWOR);
      $$ = lFLWOR;
    }
  | ForLetClauseList GroupByClause OrderByClause RETURN ExprSingle
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>($2);
			FLWORExpr* lFLWOR = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								NULL,
                lGroupBy,
								dynamic_cast<OrderByClause*>($3),
								$5);
      lGroupBy->set_flwor(lFLWOR);
      $$ = lFLWOR;
    }
  | ForLetClauseList WhereClause GroupByClause OrderByClause RETURN ExprSingle
    {
      GroupByClause* lGroupBy = dynamic_cast<GroupByClause*>($3);
			FLWORExpr* lFLWOR = new FLWORExpr(LOC (@$),
								dynamic_cast<ForLetClauseList*>($1),
								dynamic_cast<WhereClause*>($2),
                lGroupBy,
								dynamic_cast<OrderByClause*>($4),
								$6);
      lGroupBy->set_flwor(lFLWOR);
      $$ = lFLWOR;
    }
	;


// [33a] ForLetClauseList
// ----------------------
ForLetClauseList :
		ForLetClause
		{
			ForLetClauseList* flc_list_p = new ForLetClauseList(LOC (@$));
			flc_list_p->push_back(dynamic_cast<ForOrLetClause *> ($1));
			$$ = flc_list_p;
		}
	|	ForLetClauseList  ForLetClause
		{
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
			$$ = new ForClause(LOC (@$),
								dynamic_cast<VarInDeclList*>($2));
		}
	;


// [34a] VarInDeclList
// -------------------
VarInDeclList :
		VarInDecl
		{
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC (@$));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>($1));
			$$ = vardecl_list_p;
		}
	|	VarInDeclList  COMMA  DOLLAR  VarInDecl
		{
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
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,NULL,NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,NULL,
								$4);
		}
	|	VARNAME  PositionalVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								NULL,
								$4);
		}
	|	VARNAME  TypeDeclaration  PositionalVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								NULL,
								$5);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  PositionalVar  FTScoreVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| VARNAME  TypeDeclaration  PositionalVar  FTScoreVar  _IN_  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
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
			$$ = new PositionalVar(LOC (@$),
								driver.symtab.get((off_t)$3));
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  VARNAME
		{
			$$ = new FTScoreVar(LOC (@$),
								driver.symtab.get((off_t)$3));
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET_DOLLAR VarGetsDeclList
		{
			$$ = new LetClause(LOC (@$),
								dynamic_cast<VarGetsDeclList*>($2));
			
		}
	;


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList :
		VarGetsDecl
		{
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC (@$));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($1));
			$$ = vgdl_p;
		}
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
		{
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>($1);
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($4));
			}
			$$ = $1;
		}
	;


EvalVarDeclList :
		EvalVarDecl
		{
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC (@$));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>($1));
			$$ = vgdl_p;
		}
	|	EvalVarDeclList  COMMA  DOLLAR  EvalVarDecl
		{
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
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								NULL,
								$3);
		}
	|	VARNAME  TypeDeclaration  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								$4);
		}
	/* full-text extensions */
	| VARNAME  FTScoreVar  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| VARNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	;


EvalVarDecl :
    VARNAME
    {
      std::string name = driver.symtab.get ((off_t)$1);
      $$ = new VarGetsDecl(LOC (@$),
                           name, NULL, NULL,
                           new VarRef (LOC (@$), name),
                           VarGetsDecl::eval_var);
                           
    }
    ;


// [37] WhereClause
// ----------------
WhereClause :
		WHERE  ExprSingle
		{
			$$ = new WhereClause(LOC (@$),
								$2);
		}
	;

GroupByClause :
    GROUP_BY GroupSpecList
    {
      $$ = new GroupByClause(LOC(@$),
                 dynamic_cast<GroupSpecList*>($2),
                 NULL,
                 NULL);
    }
  | GROUP_BY GroupSpecList LetClauseList
    {
      $$ = new GroupByClause(LOC(@$),
                 dynamic_cast<GroupSpecList*>($2),
                 dynamic_cast<LetClauseList*>($3),
                 NULL);
    }
  | GROUP_BY GroupSpecList WhereClause
    {
      $$ = new GroupByClause(LOC(@$),
                 dynamic_cast<GroupSpecList*>($2),
                 NULL,
                 dynamic_cast<WhereClause*>($3));
    }
  | GROUP_BY GroupSpecList LetClauseList WhereClause
    {
      $$ = new GroupByClause(LOC(@$),
                 dynamic_cast<GroupSpecList*>($2),
                 dynamic_cast<LetClauseList*>($3),
                 dynamic_cast<WhereClause*>($4));
    }
  ;

GroupSpecList :
    GroupSpec
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC(@$));
      gsl_p->push_back(dynamic_cast<GroupSpec*>($1));
      $$ = gsl_p;
    }
  | GroupSpecList COMMA GroupSpec
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>($1);
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>($3));
      }
      $$ = gsl_p;
    }
  ;

GroupSpec :
    DOLLAR VARNAME
    {
      $$ = new GroupSpec(LOC(@$),
                 driver.symtab.get((off_t)$2),
                 NULL);
    }
  | DOLLAR VARNAME GroupCollationSpec
    {
      $$ = new GroupSpec(LOC(@$), 
                 driver.symtab.get((off_t)$2), 
                 dynamic_cast<GroupCollationSpec*>($3)); 
    }
  ;

GroupCollationSpec :
    COLLATION  URI_LITERAL
    {
      $$ = new GroupCollationSpec(LOC(@$), driver.symtab.get((off_t)$2));
    }
  ;

LetClauseList :
    LetClause
    {
      LetClauseList* lc_list_p = new LetClauseList(LOC(@$));
      lc_list_p->push_back(dynamic_cast<LetClause*>($1));
      $$ = lc_list_p;
    }
  |
    LetClauseList LetClause 
    {
      LetClauseList* lc_list_p = dynamic_cast<LetClauseList*>($1);
      if (lc_list_p) lc_list_p->push_back(dynamic_cast<LetClause*>($2));
      $$ = $1;
    }
  ;


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER_BY  OrderSpecList
		{
			$$ = new OrderByClause(LOC (@$),
								dynamic_cast<OrderSpecList*>($2));
		}
	|	STABLE_ORDER_BY  OrderSpecList
		{
			$$ = new OrderByClause(LOC (@$),
								dynamic_cast<OrderSpecList*>($2),
								true);
		}
	;


// [39] OrderSpecList
// ------------------
OrderSpecList :
		OrderSpec 
		{
			OrderSpecList* osl_p = new OrderSpecList(LOC (@$));
			osl_p->push_back(dynamic_cast<OrderSpec*>($1));
			$$ = osl_p;
		}
	|	OrderSpecList  COMMA  OrderSpec
		{
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
			$$ = new OrderSpec(LOC (@$),
								$1,
								NULL);
		}
	|	ExprSingle OrderModifier
		{
			$$ = new OrderSpec(LOC (@$),
								$1,
								dynamic_cast<OrderModifier*>($2));
		}
	;


// [41] OrderModifier
// ------------------
OrderModifier :
		OrderDirSpec
		{
			$$ = new OrderModifier(LOC (@$),
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								NULL);
		}
	|	OrderEmptySpec
		{
			$$ = new OrderModifier(LOC (@$),
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								NULL);
		}
	|	OrderCollationSpec
		{
			$$ = new OrderModifier(LOC (@$),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>($1));
		}
	|	OrderDirSpec  OrderEmptySpec
		{
			$$ = new OrderModifier(LOC (@$),
								dynamic_cast<OrderDirSpec*>($1),
								dynamic_cast<OrderEmptySpec*>($2),
								NULL);
		}
	|	OrderDirSpec  OrderCollationSpec
		{
			$$ = new OrderModifier(LOC (@$),
								dynamic_cast<OrderDirSpec*>($1),
								NULL,
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderEmptySpec  OrderCollationSpec
		{
			$$ = new OrderModifier(LOC (@$),
								NULL,
								dynamic_cast<OrderEmptySpec*>($1),
								dynamic_cast<OrderCollationSpec*>($2));
		}
	|	OrderDirSpec  OrderEmptySpec  OrderCollationSpec
		{
			$$ = new OrderModifier(LOC (@$),
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
			$$ = new OrderDirSpec(LOC (@$), ParseConstants::dir_ascending);
		}
	|	DESCENDING
		{
			$$ = new OrderDirSpec(LOC (@$), ParseConstants::dir_descending);
		}
	;


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec:
		EMPTY_GREATEST
		{
			$$ = new OrderEmptySpec(LOC (@$),
								StaticContextConsts::empty_greatest);
		}
	|	EMPTY_LEAST
		{
			$$ = new OrderEmptySpec(LOC (@$),
								StaticContextConsts::empty_least);
		}
	;


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec :
		COLLATION  URI_LITERAL
		{
			$$ = new OrderCollationSpec(LOC (@$),
								driver.symtab.get((off_t)$2));
		}
	;


// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr :
		SOME_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			$$ = new QuantifiedExpr(LOC (@$),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>($2),
								$4);
		}
	|	EVERY_DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			$$ = new QuantifiedExpr(LOC (@$),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>($2),
								$4);
		}
	;


// [42a] QVarInDeclList
// --------------------
QVarInDeclList :
		QVarInDecl  %prec QVARINDECLLIST_REDUCE
		{
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC (@$));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>($1));
			$$ = qvid_list_p;
				
		}
	|	QVarInDeclList  COMMA DOLLAR  QVarInDecl
		{
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
			$$ = new QVarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								$3);
		}
	|	VARNAME  TypeDeclaration  _IN_  ExprSingle 
		{
			$$ = new QVarInDecl(LOC (@$),
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
			$$ = new TypeswitchExpr(LOC (@$),
								$2,
								dynamic_cast<CaseClauseList*>($4),
								$7);
		}
	|	TYPESWITCH_LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  VARNAME  RETURN  ExprSingle
		{
			$$ = new TypeswitchExpr(LOC (@$),
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
			CaseClauseList* cc_list_p = new CaseClauseList(LOC (@$));
			cc_list_p->push_back(dynamic_cast<CaseClause*>($1));
			$$ = cc_list_p;
		}
	|	CaseClauseList  CaseClause
		{
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
			$$ = new CaseClause(LOC (@$),
								dynamic_cast<SequenceType*>($2),
								$4);
		}
	|	CASE  DOLLAR  VARNAME  AS  SequenceType  RETURN  ExprSingle
		{
			$$ = new CaseClause(LOC (@$),
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
			$$ = new IfExpr(LOC (@$),
								$2, $5, $7);
		}
	;


// [46] OrExpr
// -----------
OrExpr :
		AndExpr
		{
			$$ = $1;
		}
	|	OrExpr  OR  AndExpr
		{
			$$ = new OrExpr(LOC (@$),
								$1, $3);
		}
	;


// [47] AndExpr
// ------------
AndExpr :
		ComparisonExpr
		{
			$$ = $1;
		}
	|	AndExpr  AND  ComparisonExpr
		{
			$$ = new AndExpr(LOC (@$),
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
			$$ = $1;
		}
	| FTContainsExpr  ValueComp  FTContainsExpr
		{
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			$$ = new ComparisonExpr(LOC (@$),
								dynamic_cast<ValueComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  GeneralComp  FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			$$ = new ComparisonExpr(LOC (@$),
								dynamic_cast<GeneralComp*>($2),
								$1,
								$3);
		}
	| FTContainsExpr  NodeComp  FTContainsExpr
		{
			/*  ::=  "is" | "<<" | ">>" */
			$$ = new ComparisonExpr(LOC (@$),
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
			$$ = $1;
		}
	|	RangeExpr  FTCONTAINS  FTSelection 
		{
			$$ = new FTContainsExpr(LOC (@$),
								$1,
								dynamic_cast<FTSelection*>($3),
								NULL);
		}
	|	RangeExpr  FTCONTAINS  FTSelection  FTIgnoreOption
		{
			$$ = new FTContainsExpr(LOC (@$),
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
			$$ = $1;
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
			$$ = new RangeExpr(LOC (@$),
								$1, $3);
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr  %prec ADDITIVE_REDUCE
		{
			$$ = $1;
		}
	|	AdditiveExpr  PLUS  MultiplicativeExpr
		{
			$$ = new AdditiveExpr(LOC (@$), ParseConstants::op_plus, $1, $3);
		}
	|	AdditiveExpr  MINUS  MultiplicativeExpr
		{
			$$ = new AdditiveExpr(LOC (@$), ParseConstants::op_minus, $1, $3);
		}
	;


// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr :
		UnionExpr  %prec MULTIPLICATIVE_REDUCE
		{
       $$ = $1;
		}
	|	MultiplicativeExpr  STAR  UnionExpr
		{
			$$ = new MultiplicativeExpr(LOC (@$), ParseConstants::op_mul, $1, $3);
		}
	|	MultiplicativeExpr  DIV  UnionExpr
		{
			$$ = new MultiplicativeExpr(LOC (@$), ParseConstants::op_div, $1, $3);
		}
	|	MultiplicativeExpr  IDIV  UnionExpr
		{
			$$ = new MultiplicativeExpr(LOC (@$), ParseConstants::op_idiv, $1, $3);
		}
	|	MultiplicativeExpr  MOD  UnionExpr
		{
			$$ = new MultiplicativeExpr(LOC (@$), ParseConstants::op_mod, $1, $3);
		}
	;


// [52] UnionExpr
// --------------
UnionExpr :
		IntersectExceptExpr  %prec UNION_REDUCE
		{
			$$ = $1;
		}
	|	UnionExpr  UNION  IntersectExceptExpr
		{
			$$ = new UnionExpr(LOC (@$),
								$1, $3);
		}
	|	UnionExpr  VBAR  IntersectExceptExpr
		{
			$$ = new UnionExpr(LOC (@$),
								$1, $3);
		}
	;


// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr :
		InstanceofExpr  %prec INTERSECT_EXCEPT_REDUCE
		{
			$$ = $1;
		}
	|	IntersectExceptExpr  INTERSECT  InstanceofExpr
		{
			$$ = new IntersectExceptExpr(LOC (@$), ParseConstants::op_intersect, $1, $3);
		}
	|	IntersectExceptExpr  EXCEPT  InstanceofExpr
		{
			$$ = new IntersectExceptExpr(LOC (@$), ParseConstants::op_except, $1, $3);
		}
	;


// [54] InstanceofExpr
// -------------------
InstanceofExpr :
		TreatExpr
		{
			$$ = $1;
		}
	|	TreatExpr  INSTANCE_OF  SequenceType
		{
			$$ = new InstanceofExpr(LOC (@$),
								$1,
								dynamic_cast<SequenceType*>($3));
		}
	;


// [55] TreatExpr
// --------------
TreatExpr :
		CastableExpr
		{
			$$ = $1;
		}
	|	CastableExpr  TREAT_AS  SequenceType
		{
			$$ = new TreatExpr(LOC (@$),
								$1,
								dynamic_cast<SequenceType*>($3));
		}
	;


// [56] CastableExpr
// -----------------
CastableExpr :
		CastExpr
		{
			$$ = $1;
		}
	|	CastExpr  CASTABLE_AS  SingleType
		{
			$$ = new CastableExpr(LOC (@$),
								$1,
								dynamic_cast<SingleType*>($3));
		}
	;


// [57] CastExpr 	   
// -------------
CastExpr :
		UnaryExpr
		{
			$$ = $1;
		}
	|	UnaryExpr  CAST_AS  SingleType
		{
			$$ = new CastExpr(LOC (@$),
								$1,
								dynamic_cast<SingleType*>($3));
		}
	;


// [58] UnaryExpr
// --------------
UnaryExpr :
		ValueExpr
		{
			$$ = $1;
		}
	|	SignList  ValueExpr
		{
			$$ = new UnaryExpr(LOC (@$),
								dynamic_cast<SignList*>($1),
								$2);
		}
	;


// [58a] SignList
// --------------
SignList :
		PLUS
		{
			$$ = new SignList(LOC (@$), true);
		}
	|	MINUS
		{
			$$ = new SignList(LOC (@$), false);
		}
	|	SignList  PLUS
		{
			$$ = $1;
		}
	|	SignList  MINUS
		{
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
			$$ = $1;
		}
	|	PathExpr
		{
			$$ = $1;
		}
	|	ExtensionExpr
		{
			$$ = $1;
		}
	;



// [60] GeneralComp
// ----------------
GeneralComp :
		EQUALS
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_eq);
		}
	| NE
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_ne);
		}
	| LT
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_lt);
		}
	| LE
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_le);
		}
	| GT
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_gt);
		}
	| GE
		{
			$$ = new GeneralComp(LOC (@$), ParseConstants::op_ge);
		}
	;


// [61] ValueComp
// --------------
ValueComp :
		VAL_EQ
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_eq);
		}
	| VAL_NE
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_ne);
		}
	| VAL_LT
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_lt);
		}
	| VAL_LE
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_le);
		}
	| VAL_GT
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_gt);
		}
	| VAL_GE
		{
			$$ = new ValueComp(LOC (@$), ParseConstants::op_val_ge);
		}
	;


// [62] NodeComp
// -------------
NodeComp :
		IS
		{
			$$ = new NodeComp(LOC (@$), ParseConstants::op_is);
		}
	| PRECEDES
		{
			$$ = new NodeComp(LOC (@$), ParseConstants::op_precedes);
		}
	| FOLLOWS
		{
			$$ = new NodeComp(LOC (@$), ParseConstants::op_follows);
		}
	;



// [63] ValidateExpr
// -----------------
ValidateExpr :
		VALIDATE_LBRACE  Expr  RBRACE
		{
			$$ = new ValidateExpr(LOC (@$), "strict", $2);
		}
	|	VALIDATE_MODE  LBRACE  Expr  RBRACE
		{
			$$ = new ValidateExpr(LOC (@$),
								driver.symtab.get((off_t)$1),
								$3);
		}
	;


// [64] ExtensionExpr
// ------------------
ExtensionExpr :
		PragmaList  LBRACE  RBRACE
		{
			$$ = new ExtensionExpr(LOC (@$),
								dynamic_cast<PragmaList*>($1),
								NULL);
		}
	|	PragmaList  LBRACE  Expr  RBRACE
		{
			$$ = new ExtensionExpr(LOC (@$),
								dynamic_cast<PragmaList*>($1),
								$3);
		}
	;


// [64a] PragmaList
// ----------------
PragmaList :
		Pragma
		{
			PragmaList* pragma_list_p = new PragmaList(LOC (@$));
			pragma_list_p->push_back(dynamic_cast<Pragma*>($1));
			$$ = pragma_list_p;
		}
	|	PragmaList  Pragma
		{
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
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL_AND_END
		{
			$$ = new Pragma(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								driver.symtab.get((off_t)$3));

		} | PRAGMA_BEGIN QNAME_AND_END_PRAGMA {
			$$ = new Pragma(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								"");      
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
		//LEADING_LONE_SLASH
    SLASH
		{
			$$ = new PathExpr(LOC (@$), ParseConstants::path_leading_lone_slash, NULL);
		}
	|	SLASH  RelativePathExpr
		{
			$$ = new PathExpr(LOC (@$), ParseConstants::path_leading_slash, $2);
		}
	|	SLASH_SLASH  RelativePathExpr
		{
			$$ = new PathExpr(LOC (@$), ParseConstants::path_leading_slashslash, $2);
		}
	|	RelativePathExpr	 	/* gn: leading-lone-slashXQ */
		{
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>($1);
       $$ = (rpe == NULL ?
             $1 :
             new PathExpr(LOC(@$), ParseConstants::path_relative, $1));
		}
	;


// [68] RelativePathExpr
// ---------------------
RelativePathExpr :
		StepExpr  %prec STEP_REDUCE
		{
       AxisStep *as = dynamic_cast<AxisStep *>($1);
       $$ = (as != NULL ?
             new RelativePathExpr(LOC (@$),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC(@$)),
                                  $1) :
             $1);
		}

	|	StepExpr  SLASH  RelativePathExpr 
		{
			$$ = new RelativePathExpr(LOC(@$), ParseConstants::st_slash, $1, $3);
		}

	|	StepExpr  SLASH_SLASH  RelativePathExpr
		{
			$$ = new RelativePathExpr(LOC(@$), ParseConstants::st_slashslash, $1, $3);
		}
	;


// [69] StepExpr
// -------------
StepExpr :
		AxisStep
		{
			$$ = $1;
		}
	|	FilterExpr
		{
			$$ = $1;
		}
	;


// [70] AxisStep
// -------------
AxisStep :
		ForwardStep 
		{
			$$ = new AxisStep(LOC (@$),
								dynamic_cast<ForwardStep*>($1),
								NULL);
		}
	|	ForwardStep  PredicateList
		{
			$$ = new AxisStep(LOC (@$),
								dynamic_cast<ForwardStep*>($1),
								dynamic_cast<PredicateList*>($2));
		}
	|	ReverseStep
		{
			$$ = new AxisStep(LOC (@$),
								dynamic_cast<ReverseStep*>($1),
								NULL);
		}
	|	ReverseStep  PredicateList
		{
			$$ = new AxisStep(LOC (@$),
								dynamic_cast<ReverseStep*>($1),
								dynamic_cast<PredicateList*>($2));
		}
	;


// [71] ForwardStep
// ----------------
ForwardStep :
		ForwardAxis  NodeTest
		{
			$$ = new ForwardStep(LOC (@$),
								dynamic_cast<ForwardAxis*>($1),
								$2);
		}
	|	AbbrevForwardStep
		{
			$$ = new ForwardStep(LOC (@$),
								dynamic_cast<AbbrevForwardStep*>($1));
		}
	;


// [72] ForwardAxis
// ----------------
ForwardAxis :
		CHILD_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_child);
		}
	| DESCENDANT_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_descendant);
		}
	| ATTRIBUTE_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_attribute);
		}
	| SELF_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_self);
		}
	| DESCENDANT_OR_SELF_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_descendant_or_self);
		}
	| FOLLOWING_SIBLING_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_following_sibling);
		}
	| FOLLOWING_AXIS
		{
			$$ = new ForwardAxis(LOC (@$), ParseConstants::axis_following);
		}
	;


// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep :
		NodeTest
		{
			$$ = new AbbrevForwardStep(LOC (@$), $1);
		}
	|	AT_SIGN  NodeTest
		{
			$$ = new AbbrevForwardStep(LOC (@$), $2, true);
		}
	;


// [74] ReverseStep
// ----------------
ReverseStep :
		ReverseAxis  NodeTest
		{
			$$ = new ReverseStep(LOC (@$),
								dynamic_cast<ReverseAxis*>($1),
								$2);
		}
	|	DOT_DOT
		{
			ReverseAxis* rev_p = new ReverseAxis(LOC (@$), ParseConstants::axis_parent);
			$$ = new ReverseStep(LOC (@$),
								rev_p);
		}
	;


// [75] ReverseAxis
// ----------------
ReverseAxis :
		PARENT_AXIS
		{
			$$ = new ReverseAxis(LOC (@$), ParseConstants::axis_parent);
		}
	| ANCESTOR_AXIS
		{
			$$ = new ReverseAxis(LOC (@$), ParseConstants::axis_ancestor);
		}
	| PRECEDING_SIBLING_AXIS
		{
			$$ = new ReverseAxis(LOC (@$), ParseConstants::axis_preceding_sibling);
		}
	| PRECEDING_AXIS
		{
			$$ = new ReverseAxis(LOC (@$), ParseConstants::axis_preceding);
		}
	| ANCESTOR_OR_SELF_AXIS
		{
			$$ = new ReverseAxis(LOC (@$), ParseConstants::axis_ancestor_or_self);
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
			$$ = $1;
		}
	|	NameTest
		{
			$$ = $1;
		}
	;
 

// [78] NameTest
// -------------
NameTest :
		QNAME
		{
			$$ = new NameTest(LOC (@$), new QName(LOC (@$),driver.symtab.get((off_t)$1)));
		}
	|	Wildcard
		{
			$$ = new NameTest(LOC (@$), dynamic_cast<Wildcard*>($1));
		}
	;


// [79] Wildcard
// -------------
Wildcard :
		STAR
		{
			$$ = new Wildcard(LOC (@$),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
	|	ELEM_WILDCARD
		{
			$$ = new Wildcard(LOC (@$),
                        driver.symtab.get((off_t)$1),
                        "",
                        ParseConstants::wild_elem);
		}
	|	PREFIX_WILDCARD   /* ws: explicitXQ */
		{
			$$ = new Wildcard(LOC (@$),
                        "",
                        driver.symtab.get((off_t)$1),
                        ParseConstants::wild_prefix);
		}
	;


// [80] FilterExpr
// ---------------
FilterExpr :
		PrimaryExpr 
		{
       $$ = $1;
		}
	|	PrimaryExpr  PredicateList
		{
			$$ = new FilterExpr(LOC (@$),
                          $1,
                          dynamic_cast<PredicateList*>($2));
		}
	;


// [81] PredicateList
// ------------------
PredicateList :
		Predicate
		{
			PredicateList* pred_list_p = new PredicateList(LOC (@$));
			pred_list_p->push_back(dynamic_cast<exprnode*>($1));
			$$ = pred_list_p;
		}
	|	PredicateList  Predicate
		{
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
			$$ = $2;
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
			$$ = $1;
		}
	|	StringLiteral
		{
			$$ = $1;
		}
	;


// [85] NumericLiteral
// -------------------
NumericLiteral :
		DECIMAL_LITERAL
		{
			$$ = new NumericLiteral(LOC (@$), *$1);
      delete yylval.decval;
		}
	| INTEGER_LITERAL
		{
			$$ = new NumericLiteral(LOC (@$), *$1);
      delete yylval.ival;
		}
	|	DOUBLE_LITERAL
		{
			$$ = new NumericLiteral(LOC (@$), *$1);
      delete yylval.dval;
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  VARNAME
		{
			$$ = new VarRef(LOC (@$), driver.symtab.get((off_t)$2));
		}
	;


// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr :
		LPAR  RPAR
		{
			$$ = new ParenthesizedExpr(LOC (@$), NULL);
		}
	|	LPAR  Expr  RPAR
		{
			$$ = new ParenthesizedExpr(LOC (@$),
								$2);
		}
	;	


// [88] ContextItemExpr
// --------------------
ContextItemExpr :
		DOT
		{
			$$ = new ContextItemExpr(LOC (@$));
		}
	;	


// [89] OrderedExpr
// ----------------
OrderedExpr :
		ORDERED_LBRACE  Expr  RBRACE
		{
			$$ = new OrderedExpr(LOC (@$),
								$2);
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED_LBRACE  Expr  RBRACE
		{
			$$ = new UnorderedExpr(LOC (@$),
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
		QNAME LPAR  RPAR
		{
			$$ = new FunctionCall(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	QNAME LPAR  ArgList  RPAR
		{
			$$ = new FunctionCall(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								dynamic_cast<ArgList*>($3));
		}
	;


// [91a] ArgList
// -------------
ArgList :
		ExprSingle
		{
			ArgList* a_list_p = new ArgList(LOC (@$)); 
			a_list_p->push_back($1);
			$$ = a_list_p;
		}
	|	ArgList  COMMA  ExprSingle
		{
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
			$$ = $1;
		}
	|	ComputedConstructor
		{
			$$ = $1;
		}
	;


// [93] DirectConstructor
// ----------------------
DirectConstructor :
		DirElemConstructor
		{
			$$ = $1;
		}
	|	DirCommentConstructor
		{
			$$ = $1;
		}
	|	DirPIConstructor
		{
			$$ = $1;
		}
	;

 
// [94] DirElemConstructor
// -----------------------
DirElemConstructor :
		START_TAG  QNAME  EMPTY_TAG_END /* ws: explicitXQ */
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL,
								NULL,
								NULL);
		}
	| START_TAG  QNAME  DirAttributeList EMPTY_TAG_END /* ws: explicitXQ */
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<DirAttributeList*>($3), 
								NULL);
		}
	| START_TAG  QNAME  TAG_END  START_TAG_END  QNAME  TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$5)),
								NULL,
								NULL);
		}
	|	START_TAG  QNAME  TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$6)),
								NULL,
								dynamic_cast<DirElemContentList*>($4));
		}
	| START_TAG  QNAME  DirAttributeList TAG_END  START_TAG_END  QNAME TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$6)),
								dynamic_cast<DirAttributeList*>($3),
								NULL);
		}
	|	START_TAG  QNAME  DirAttributeList TAG_END  DirElemContentList  START_TAG_END  QNAME  TAG_END 
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$7)),
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
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC (@$));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>($1));
			$$ = elem_content_list_p;
		}
	|	DirElemContentList  DirElemContent
		{
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
			DirAttributeList* at_list_p = new DirAttributeList(LOC (@$));
			at_list_p->push_back(dynamic_cast<DirAttr*>($1));
			$$ = at_list_p;
		}
	|	DirAttributeList  DirAttr
		{
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
			$$ = new DirAttr(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								dynamic_cast<DirAttributeValue*>($3));
		}
	;


// [96] DirAttributeValue
// ----------------------
DirAttributeValue :
		QUOTE  Opt_QuoteAttrContentList  QUOTE
		{
			$$ = new DirAttributeValue(LOC (@$),
								dynamic_cast<QuoteAttrContentList*>($2));
		}
	|	APOS  Opt_AposAttrContentList  APOS 	/* ws: explicitXQ */
		{
			$$ = new DirAttributeValue(LOC (@$),
								dynamic_cast<AposAttrContentList*>($2));
		}
	;


// [96a] QuoteAttrContentList
// --------------------------
Opt_QuoteAttrContentList :
		/* empty */
		{
			$$ = new QuoteAttrContentList(LOC (@$));
		}
	|	QuoteAttrContentList
		{
			$$ = $1;
		}
	;

QuoteAttrContentList :	
		ESCAPE_QUOTE
		{
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC (@$));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC (@$),std::string("\"")));
			$$ = qo_list_p;
		}
	|	QuoteAttrValueContent
		{
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC (@$));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($1));
			$$ = qo_list_p;
		}
	|	QuoteAttrContentList  ESCAPE_QUOTE
		{
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC (@$),std::string("\"")));
			}
			$$ = $1;
		}
	|	QuoteAttrContentList  QuoteAttrValueContent
		{
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>($1);
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>($2));
			}
			$$ = $1;
		}
	;


// [96b] AposAttrContentList
// -------------------------
Opt_AposAttrContentList :
		/* empty */
		{
			$$ = new AposAttrContentList(LOC (@$));
		}
	|	AposAttrContentList
		{
			$$ = $1;
		}
	;

AposAttrContentList :
		ESCAPE_APOS
		{
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC (@$));
			at_list_p->push_back(new AposAttrValueContent(LOC (@$),"'"));
			$$ = at_list_p;
		}
	|	AposAttrValueContent
		{
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC (@$));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>($1));
			$$ = at_list_p;
		}
	|	AposAttrContentList  ESCAPE_APOS
		{
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>($1);
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC (@$),"'"));
			}
			$$ = $1;
		}
	|	AposAttrContentList  AposAttrValueContent
		{
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
			$$ = new QuoteAttrValueContent(LOC (@$),
								driver.symtab.get((off_t)$1));
		}
	|	CommonContent
		{
			$$ = new QuoteAttrValueContent(LOC (@$),
								dynamic_cast<CommonContent*>($1));
		}
	;


// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent :
		APOS_ATTR_CONTENT
		{
			$$ = new AposAttrValueContent(LOC (@$),
								driver.symtab.get((off_t)$1));
		}
	|	CommonContent
		{
			$$ = new AposAttrValueContent(LOC (@$),
								dynamic_cast<CommonContent*>($1));
		}
	;


// [99] DirElemContent
// -------------------
DirElemContent :
		DirectConstructor
		{
			$$ = new DirElemContent(LOC (@$),
								$1);
		}
	|	ELEMENT_CONTENT
		{
			$$ = new DirElemContent(LOC (@$),
								driver.symtab.get((off_t)$1));
		}
	|	CDataSection
		{
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>($1);
			$$ = new DirElemContent(LOC (@$),
								cdata_h);
		}
	|	CommonContent
		{
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>($1);
			$$ = new DirElemContent(LOC (@$),
								cont_h);
		}
	;


// [100] CommonContent
// -------------------
CommonContent :
	  CHAR_REF_LITERAL
		{
			$$ = new CommonContent(LOC (@$),
                ParseConstants::cont_charref,
								driver.symtab.get((off_t)$1));
		}
	|	DOUBLE_LBRACE
		{
			$$ = new CommonContent(LOC (@$),
								ParseConstants::cont_escape_lbrace);
		}
	|	DOUBLE_RBRACE
		{
			$$ = new CommonContent(LOC (@$),
								ParseConstants::cont_escape_rbrace);
		}
	|	EnclosedExpr
		{
			$$ = new CommonContent(LOC (@$),
								dynamic_cast<EnclosedExpr*>($1));
		}
	;


// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor :
		XML_COMMENT_BEGIN  XML_COMMENT_LITERAL  XML_COMMENT_END 	/* ws: explicitXQ */
		{
			$$ = new DirCommentConstructor(LOC (@$),
								driver.symtab.get((off_t)$2));
		}
  | XML_COMMENT_BEGIN  XML_COMMENT_END                        /* ws: explicitXQ */
    {
      $$ = new DirCommentConstructor(LOC (@$), "");
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
			$$ = new DirPIConstructor(LOC (@$),
								driver.symtab.get((off_t)$2));
		}
    |	PI_BEGIN  PI_TARGET_LITERAL CHAR_LITERAL_AND_PI_END 	/* ws: explicitXQ */
		{
			$$ = new DirPIConstructor(LOC (@$),
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
		CDATA_BEGIN  CHAR_LITERAL_AND_CDATA_END 				/* ws: explicitXQ */
		{
			$$ = new CDataSection(LOC (@$),driver.symtab.get((off_t)$2));
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
			$$ = new CompDocConstructor(LOC (@$),
								$2);
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT_QNAME_LBRACE  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	ELEMENT_QNAME_LBRACE  Expr  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								$2);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								$2, NULL);
		}
	|	ELEMENT_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								$2, $5);
		}
	;


// [110] ContentExpr
// -----------------
/*
ContentExpr :
		Expr
		{
		}
	;
*/


// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor :
		ATTRIBUTE_QNAME_LBRACE  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								NULL);
		}
	|	ATTRIBUTE_QNAME_LBRACE  Expr  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
								$2);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								$2, NULL);
		}
	|	ATTRIBUTE_LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								$2, $5);
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT_LBRACE  Expr  RBRACE
		{
			$$ = new CompTextConstructor(LOC (@$),
								dynamic_cast<Expr*>($2));
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT_LBRACE  Expr  RBRACE
		{
			$$ = new CompCommentConstructor(LOC (@$),
								dynamic_cast<Expr*>($2));
		}
	;


// [114] CompPIConstructor
// -----------------------
CompPIConstructor :
		PROCESSING_INSTRUCTION  NCNAME  LBRACE  RBRACE
		{
			$$ = new CompPIConstructor(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	PROCESSING_INSTRUCTION  NCNAME  LBRACE  Expr  RBRACE
		{
			$$ = new CompPIConstructor(LOC (@$),
								driver.symtab.get((off_t)$2),
								$4);
		}
	|	PROCESSING_INSTRUCTION LBRACE  Expr  RBRACE LBRACE  RBRACE
		{
			$$ = new CompPIConstructor(LOC (@$),
								$3, NULL);
		}
	|	PROCESSING_INSTRUCTION LBRACE  Expr  RBRACE LBRACE  Expr  RBRACE
		{
			$$ = new CompPIConstructor(LOC (@$),
								$3, $6);
		}
	;


// [115] SingleType
// ----------------
SingleType :
		AtomicType
		{
			$$ = new SingleType(LOC (@$),
								dynamic_cast<AtomicType*>($1),
								false);
		}
	|	AtomicType  HOOK
		{
			$$ = new SingleType(LOC (@$),
								dynamic_cast<AtomicType*>($1),
								true);
		}
	;


// [116] TypeDeclaration
// ---------------------
TypeDeclaration :
		AS  SequenceType
		{
			$$ = new TypeDeclaration(LOC (@$),
								dynamic_cast<SequenceType*>($2));
		}
	;


// [117] SequenceType
// ------------------
SequenceType :
		ItemType  %prec SEQUENCE_TYPE_REDUCE
		{
			$$ = new SequenceType(LOC (@$),
								$1,
								NULL);
		}
	|	ItemType  OccurrenceIndicator
		{
			$$ = new SequenceType(LOC (@$),
								$1,
								dynamic_cast<OccurrenceIndicator*>($2));
		}
	|	VOID_TEST
		{
			$$ = new SequenceType(LOC (@$), NULL, NULL);
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
			$$ = new OccurrenceIndicator(LOC (@$),
								ParseConstants::occurs_optionally);
		}
	|	OCCURS_STAR
		{
			$$ = new OccurrenceIndicator(LOC (@$),
								ParseConstants::occurs_zero_or_more);
		}
	|	OCCURS_PLUS 	/* gn: occurrence-indicatorsXQ */
		{
			$$ = new OccurrenceIndicator(LOC (@$),
								ParseConstants::occurs_one_or_more);
		}
	;


// [119] ItemType
// --------------
ItemType :
		AtomicType
		{
			$$ = $1;
		}
	|	KindTest
		{
			$$ = $1;
		}
	|	ITEM_TEST
		{
			$$ = new ItemType(LOC (@$),true);
		}
	;


// [120] AtomicType
// ----------------
AtomicType :
		QNAME
		{
			$$ = new AtomicType(LOC (@$),
								new QName(LOC (@$), driver.symtab.get((off_t)$1)));
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
			$$ = new AnyKindTest(LOC (@$));
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE_LPAR  RPAR
		{
			$$ = new DocumentTest(LOC (@$));
		}
	|	DOCUMENT_NODE_LPAR  ElementTest  RPAR
		{
			$$ = new DocumentTest(LOC (@$),
								dynamic_cast<ElementTest*>($2));
		}
	|	DOCUMENT_NODE_LPAR  SchemaElementTest  RPAR
		{
			$$ = new DocumentTest(LOC (@$),
								dynamic_cast<SchemaElementTest*>($2));
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT_LPAR  RPAR 
		{
			$$ = new TextTest(LOC (@$));
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT_LPAR  RPAR 
		{
			$$ = new CommentTest(LOC (@$));
		}
	;
 

// [126] PITest
// ------------
PITest :
		PI_LPAR  RPAR
		{
			$$ = new PITest(LOC (@$), "");
		}
	|	PI_LPAR  NCNAME  RPAR
		{
			$$ = new PITest(LOC (@$), driver.symtab.get((off_t)$2));
		}
	|	PI_LPAR  STRING_LITERAL  RPAR
		{
			$$ = new PITest(LOC (@$), driver.symtab.get((off_t)$2));
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE_LPAR  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL);
		}
	|	ATTRIBUTE_LPAR  QNAME  COMMA  TypeName  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								dynamic_cast<TypeName*>($4));
		}
	|	ATTRIBUTE_LPAR  STAR  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								NULL);
		}
	|	ATTRIBUTE_LPAR  STAR  COMMA  TypeName  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								dynamic_cast<TypeName*>($4));
		}
	;


// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest :
		SCHEMA_ATTRIBUTE_LPAR  QNAME  RPAR
		{
			$$ = new SchemaAttributeTest(LOC (@$),
								new QName(LOC (@$), driver.symtab.get((off_t)$2)));
		}
	;


// [131] ElementTest
// -----------------
ElementTest :
		ELEMENT_LPAR  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$2)),
									NULL);
		}
	|	ELEMENT_LPAR  QNAME  COMMA  TypeName  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$2)),
									dynamic_cast<TypeName*>($4));
		}
	|	ELEMENT_LPAR  QNAME  COMMA  TypeName_WITH_HOOK RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$2)),
									dynamic_cast<TypeName*>($4));
		}
	|	ELEMENT_LPAR  STAR  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									NULL,
									true);
		}
	|	ELEMENT_LPAR  STAR  COMMA  TypeName  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									dynamic_cast<TypeName*>($4),
									true);
		}
	|	ELEMENT_LPAR  STAR  COMMA  TypeName_WITH_HOOK RPAR
		{
			$$ = new ElementTest(LOC (@$),
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
			$$ = new SchemaElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$2)));
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
			$$ = new TypeName(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)));
		};
    
TypeName_WITH_HOOK :
	  QNAME  HOOK
		{
			$$ = new TypeName(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$1)),
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
			$$ = new StringLiteral(LOC (@$), driver.symtab.get((off_t)$1));
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
// TODO: $$ = something
RevalidationDecl :
		DECLARE_REVALIDATION REVAL_STRICT
		{
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		}
    | DECLARE_REVALIDATION REVAL_LAX
    {
    }
    | DECLARE_REVALIDATION REVAL_SKIP
    {
    }
	;

// [242]	InsertExpr
// ----------------
InsertExpr :
		INSERT_NODE  ExprSingle  INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::INTO, $2, $4);
		}
	|	INSERT_NODE  ExprSingle  FIRST_INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_FIRST_INTO, $2, $4);
		}
	|	INSERT_NODE  ExprSingle  LAST_INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_LAST_INTO, $2, $4);
		}
	| INSERT_NODE  ExprSingle  AFTER  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AFTER, $2, $4);
		}
	| INSERT_NODE  ExprSingle  BEFORE  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::BEFORE, $2, $4);
		}
  |
		INSERT_NODES  ExprSingle  INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::INTO, $2, $4);
		}
	|	INSERT_NODES  ExprSingle  FIRST_INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_FIRST_INTO, $2, $4);
		}
	|	INSERT_NODES  ExprSingle  LAST_INTO  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_LAST_INTO, $2, $4);
		}
	| INSERT_NODES  ExprSingle  AFTER  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AFTER, $2, $4);
		}
	| INSERT_NODES  ExprSingle  BEFORE  ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::BEFORE, $2, $4);
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		DELETE_NODE  ExprSingle
		{
       $$ = new DeleteExpr( LOC (@$), $2);
		}
  |
		DELETE_NODES  ExprSingle
		{
       $$ = new DeleteExpr( LOC (@$), $2);
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		REPLACE  ExprSingle  WITH  ExprSingle
		{
       $$ = new ReplaceExpr(
                  LOC (@$),
                  store::UpdateConsts::NODE, $2, $4);
		}
	|	REPLACE_VALUE_OF  ExprSingle  WITH  ExprSingle
		{
       $$ = new ReplaceExpr(
                  LOC (@$),
                  store::UpdateConsts::VALUE_OF_NODE, $2, $4);
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		RENAME  ExprSingle  AS  ExprSingle
		{
       $$ = new RenameExpr(
                  LOC (@$), $2, $4);
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
		COPY_DOLLAR  VarNameList  MODIFY  ExprSingle  RETURN  ExprSingle
		{
      VarNameList* lList = dynamic_cast<VarNameList*>($2);
      $$ = new TransformExpr(LOC(@$), lList, $4, $6);
		}
	;


// [249a] VarNameList
// ------------------
VarNameList :
    VarNameDecl
		{
       VarNameList* lList = new VarNameList(LOC(@$));
       lList->push_back (dynamic_cast<VarBinding*> ($1));
       $$ = lList;
		}
	|	VarNameList  COMMA  DOLLAR  VarNameDecl 
		{
       VarNameList* lList = dynamic_cast<VarNameList*>($1);
       VarBinding* lBinding = dynamic_cast<VarBinding*>($4);
       lList->push_back(lBinding);
       $$ = lList;
		}
	;


// [249b] VarNameElem
// ------------------
VarNameDecl :
    VARNAME GETS ExprSingle
    {
       $$ = new VarBinding(LOC(@$), driver.symtab.get((off_t)$1), $3);  
    }
  ; 

/*_______________________________________________________________________
 *                                                                       *
 *  Try-Catch productions                                                *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/

TryExpr :
    TRY LBRACE ExprSingle RBRACE CatchListExpr
    {
       $$ = new TryExpr(LOC (@$),
								       $3, $5);
    }

CatchListExpr:
    CatchExpr
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC (@$));
       aCatchListExpr->push_back(static_cast<CatchExpr*>($1));
       $$ = aCatchListExpr;
    }
  |
    CatchListExpr CatchExpr
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>($1);
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>($2));
      }
      $$ = $1;
    }
  ;

CatchExpr :
    CATCH_LPAR NameTest RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($2),
                          $4);
    }
  |
    CATCH_LPAR NameTest COMMA DOLLAR VARNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($2),
                          driver.symtab.get((off_t)$5),
                          $7);
    }
  |
    CATCH_LPAR NameTest COMMA DOLLAR VARNAME COMMA DOLLAR VARNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($2),
                          driver.symtab.get((off_t)$5),
                          driver.symtab.get((off_t)$8),
                          $10);
    }
  |
    CATCH_LPAR NameTest COMMA DOLLAR VARNAME COMMA DOLLAR VARNAME COMMA DOLLAR VARNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($2),
                          driver.symtab.get((off_t)$5),
                          driver.symtab.get((off_t)$8),
                          driver.symtab.get((off_t)$11),
                          $13);
    }
  ;


/*_______________________________________________________________________
 *                                                                       *
 *  Eval productions                                                     *
 *                                                                       *
 *_______________________________________________________________________*/

EvalExpr :
    USING_DOLLAR EvalVarDeclList EVAL_LBRACE ExprSingle RBRACE
    {
       $$ = new EvalExpr (LOC (@$),
                          dynamic_cast<VarGetsDeclList *> ($2),
                          $4);
    }
  | EVAL_LBRACE ExprSingle RBRACE
    {
      $$ = new EvalExpr (LOC (@$), new VarGetsDeclList (LOC (@$)), $2);
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
      $$ = new FTSelection (LOC (@$), static_cast<FTOr *> ($1), NULL, NULL);
		}
	|	FTOr  FTMatchOptionProximityList
		{
      $$ = new FTSelection (LOC (@$), static_cast<FTOr *> ($1), static_cast<FTMatchOptionProximityList *> ($2), NULL);
		}
	|	FTOr  WEIGHT  RangeExpr
		{
      $$ = new FTSelection (LOC (@$), static_cast<FTOr *> ($1), NULL, static_cast<RangeExpr *> ($3));
		}
	|	FTOr  FTMatchOptionProximityList  WEIGHT  RangeExpr
		{
      $$ = new FTSelection (LOC (@$), static_cast<FTOr *> ($1), static_cast<FTMatchOptionProximityList *> ($2), static_cast<RangeExpr *> ($4));
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
	|	FTMildnot  FTNOT_IN  FTUnaryNot
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
      $$ = new FTWordsValue (LOC (@$), static_cast<StringLiteral *> ($1), NULL);
		}
	| LBRACE  Expr  RBRACE
		{
      $$ = new FTWordsValue (LOC (@$), NULL, static_cast<Expr *> ($2));
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
	| FTWildcardOption
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
	|	WITH_STOP_WORDS  FTRefOrList  FTInclExclStringLiteralList
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


//[364] FTWildcardOption
//----------------------
FTWildcardOption :
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
       $$ = new FTRange (LOC (@$), FTRange::exactly, $2);
		}
	| AT_LEAST  UnionExpr
		{
       $$ = new FTRange (LOC (@$), FTRange::at_least, $2);
		}
	| AT_MOST  UnionExpr
		{
       $$ = new FTRange (LOC (@$), FTRange::at_most, $2);
		}
	| FROM  UnionExpr  TO  UnionExpr
		{
       $$ = new FTRange (LOC (@$), FTRange::from_to, $2, $4);
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
      $$ = new FTWindow (LOC (@$), static_cast<UnionExpr *> ($2), static_cast<FTUnit *> ($3));
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
      $$ = new FTIgnoreOption (LOC (@$), static_cast<UnionExpr *> ($2));
		}
	;



%%


/*
	The error member function registers the errors to the driver.
*/

void zorba::xquery_parser::error(
	zorba::xquery_parser::location_type const& loc,
	std::string const& msg)
{
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), msg));
}


#if 0
static void print_token_value(FILE *file, int type, YYSTYPE value)
{
	if (type==VAR) {
		fprintf (file, "%s", value.tptr->name);
	}
	else if (type==NUM) {
		fprintf (file, "%d", value.val);
	}
}
#endif
