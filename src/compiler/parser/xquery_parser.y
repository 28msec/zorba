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
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba {
  namespace parser {
    extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor;
  }

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
  const char *strval;
	xqp_integer* ival;
	xqp_double* dval;
	xqp_decimal* decval;
};




/*
**	The token numbered as 0 corresponds to end of file; the following line 
**	allows for nicer error messages referring to end of file instead of 
**	$end. Similarly user friendly names are provided for each symbol.
*/

%token	_EOF	0 "end of file"

/* constant string tokens */
%type <strval> WindowType
%type <strval> ForDollar
%type <strval> FLWORWinCondType

/* tokens that contain embedded string literals */
/* -------------------------------------------- */

    /* %token <sval> ATTRIBUTE_QNAME_LBRACE  "'<attribute QName {>'" */
    /* %token <sval> ELEMENT_QNAME_LBRACE    "'<QName {>'" */
    /* %token <sval> AT_URI_LITERAL         "'<at URI>'" */
    /* %token <sval> VARNAME                  "'variable name'" */
      
%token <sval> APOS_ATTR_CONTENT             "'apos attribute content'"
%token <sval> CHAR_LITERAL                  "'char literal'"
%token <sval> CHAR_LITERAL_AND_CDATA_END    "'char literal]]>'"
%token <sval> CHAR_LITERAL_AND_PI_END       "'char literal and pi end'"
%token <sval> CHAR_REF_LITERAL				      "'#charref;'"
%token <sval> ELEMENT_CONTENT					      "'element content'"
%token <sval> ELEM_WILDCARD						      "'pref:*'"
%token <sval> ENTITY_REF							      "'&entity;'"
%token <sval> EXPR_COMMENT_LITERAL		      "'comment literal'"

%token <sval> PI_NCNAME_LBRACE              "'pi <NCName {>'"
%token <sval> PI_TARGET_LITERAL             "'pi target'"
%token <sval> PRAGMA_LITERAL_AND_END_PRAGMA "'pragma literal'"
%token <sval> QNAME_SVAL_AND_END_PRAGMA     "'QName #)'"
%token <sval> PREFIX_WILDCARD					      "'*:QName'"
%token <sval> QNAME_SVAL							      "'QName_sval'"
%token <sval> QUOTE_ATTR_CONTENT			      "'quote attribute content'"
%token <sval> STRING_LITERAL					      "'STRING'"
%token <sval> XML_COMMENT_LITERAL			      "'XML comment'"

%type <sval> QNAME                          "'QName'"
%type <sval> URI_LITERAL                    "'URI'"
%type <sval> NCNAME                         "'NCName'"

/* simple tokens */
/* ------------- */

%token BLANK                      "<blank>"

%token EXIT                       "'exit'"
%token BREAK                      "'break'"
%token LOOP                       "'loop'"
%token CONTINUE                   "'continue'"
%token WHILE                      "'while'"
%token VALIDATE                   "'validate'"
%token TYPESWITCH                 "'typeswitch'"
%token ELEMENT                    "'element'"
%token DOCUMENT                   "'document'"
%token TEXT                       "'text'"
%token COMMENT                    "'comment'"
%token DECLARE                    "'declare'"
%token FUNCTION                   "'function'"
%token UPDATING                   "'updating'"
%token SEQUENTIAL                 "'sequential'"
%token IF                         "'if'"
%token PROCESSING_INSTRUCTION     "'processing-instruction'"
%token MOST                       "'most'"
%token IMPORT                     "'import'"
%token SOME                       "'some'"
%token STABLE                     "'stable'"
%token MODULE                     "'module'"
%token OPTION                     "'option'"
%token WORD                       "'word'"
%token SCHEMA                     "'schema'"
%token SPACE                      "'space'"
%token LET                        "'let'"
%token CONSTRUCTION               "'construction'"
%token EVAL                       "'eval'"
%token FOR                        "'for'"
%token OUTER                       "'outer'"
%token SLIDING                    "'sliding'"
%token TUMBLING                   "'tumbling'"
%token PREVIOUS  "'previous'"
%token NEXT  "'next'"
%token ONLY  "'only'"
%token WHEN  "'when'"
%token COUNT  "'count'"
%token ORDERING                   "'ordering'"
%token CONT                       "'cont'"
%token BASE_URI                   "'base-uri'"
%token SCHEMA_ELEMENT             "'schema-element'"
%token DOCUMENT_NODE              "'document-node'"
%token COPY_NAMESPACES            "'copy-namespaces'"
%token INSTANCE                   "'instance'"
%token SCHEMA_ATTRIBUTE           "'schema-attribute'"
%token BOUNDARY_SPACE             "'boundary-space'"
    
%token ANCESTOR_AXIS							"'ancestor::'"
%token ANCESTOR_OR_SELF_AXIS			"'ancestor-or-self::'"
%token AND												"'and'"
%token APOS												"'''"
%token AS													"'as'"
%token ASCENDING									"'ascending'"
%token AT													"'at'"
%token ATTRIBUTE									"'attribute'"
%token ATTRIBUTE_AXIS							"'attribute::'"
%token AT_SIGN										"'@'"
%token CASE												"'case'"
%token CASTABLE                   "'castable'"
%token CAST                       "'cast'"
%token CDATA_BEGIN								"'CDATA[['"
%token CDATA_END									"']]'"
%token CHILD_AXIS									"'child::'"
%token COLLATION									"'collation'"
%token COMMA											"','"
%token COMMENT_BEGIN							"'(:'"
%token COMMENT_END								"':)'"
%token <decval> DECIMAL_LITERAL	  "'DECIMAL'"

%token VARIABLE                   "'variable'"
%token DEFAULT										"'default'"
%token DESCENDANT_AXIS						"'descendant::'"
%token DESCENDANT_OR_SELF_AXIS		"'descendant-or-self::'"
%token DESCENDING									"'descending'"
%token DIV												"'div'"
%token DOLLAR											"'$'"
%token DOT												"'.'"
%token DOT_DOT										"'..'"
%token DOUBLE_LBRACE							"'{{'"
%token <dval> DOUBLE_LITERAL			"'DOUBLE'"
%token DOUBLE_RBRACE							"'<double {>'"
%token ELSE												"'else'"
%token _EMPTY                     "'empty'"
%token GREATEST                   "'greatest'"
%token LEAST                      "'least'"
%token EMPTY_TAG_END							"'/>'"
%token ENCODING										"'encoding'"
%token EQUALS											"'='"
%token ESCAPE_APOS								"''''"
%token ESCAPE_QUOTE								"'\"\"'"
%token EVERY                      "'every'"
%token EXCEPT											"'except'"
%token EXTERNAL										"'external'"
%token FOLLOWING_AXIS							"'following::'"
%token FOLLOWING_SIBLING_AXIS			"'following-sibling::'"
%token FOLLOWS										"'follows'"
%token GE													"'>='"
%token GETS												"':='"
%token GT													"'>'"
%token HOOK												"'?'"
%token IDIV												"'idiv'"
%token _IN                         "'in'"
%token INHERIT										"'inherit'"
%token <ival> INTEGER_LITERAL			"'INTEGER'"
%token INTERSECT									"'intersect'"
%token IS													"'is'"
%token ITEM                       "'item'"
%token LBRACE											"'{'"
%token LBRACK											"'['"
%token LE													"'<='"
%token LPAR												"'('"
%token LT_OR_START_TAG            "'<'"
%token MINUS											"'-'"
%token MOD												"'mod'"
%token NAMESPACE									"'namespace'"
%token _NAN												"'nan'"
%token NE													"'!='"
%token NODECOMP										"'nodecomp'"
%token NOT_OPERATOR_KEYWORD				"'??'"
%token NO_INHERIT									"'<no inherit>'"
%token NO_PRESERVE								"'<no preserve>'"
%token OR													"'or'"
%token ORDERED										"'ordered'"
%token ORDER                      "'order'"
%token BY                         "'by'"
%token GROUP                      "'group'"
%token PARENT_AXIS								"'parent::'"
%token PI_BEGIN										"'<?'"
%token PI_END											"'?>'"
%token PLUS												"'+'"
%token PRAGMA_BEGIN								"'PRAGMA BEGIN'"
%token PRAGMA_END									"'PRAGMA END'"
%token PRECEDES										"'<<'"
%token PRECEDING_AXIS							"'preceding::'"
%token PRECEDING_SIBLING_AXIS			"'preceding-sibling::'"
%token PRESERVE										"'preserve'"
%token QUOTE											"'\"'"
%token RBRACE											"'}'"
%token RBRACK											"']'"
%token RETURN											"'return'"
%token RPAR												"')'"
%token SATISFIES									"'satisfies'"
%token SCHEMA_ATTRIBUTE_LPAR			"'<schema attribute ('"
%token SELF_AXIS									"'self::'"
%token SEMI												"';'"
%token SLASH											"'/'"
%token SLASH_SLASH								"'//'"
%token STAR												"'*'"
%token START_TAG_END							"</ (start tag end)"
%token STRIP											"'strip'"
%token TAG_END										"> (tag end)"
%token THEN												"'then'"
%token TO													"'to'"
%token TREAT  										"'treat'"
%token UNION											"'union'"
%token UNORDERED									"'unordered'"
%token UNRECOGNIZED								"'unrecognized'"
%token VAL_EQ											"'eq'"
%token VAL_GE											"'ge'"
%token VAL_GT											"'gt'"
%token VAL_LE											"'le'"
%token VAL_LT											"'lt'"
%token VAL_NE											"'ne'"
%token VALUECOMP									"'VALUECOMP'"
%token VBAR												"'|'"
%token EMPTY_SEQUENCE             "'empty-sequence'"
%token WHERE											"'where'"
%token XML_COMMENT_BEGIN					"'<!--'"
%token XML_COMMENT_END						"'-->'"
%token XQUERY                     "'xquery'"
%token VERSION                    "'version'"
%token END_PRAGMA                 "'#)'"
%token START                      "'start'"

/* update-related */
/* -------------- */
%token AFTER											"'after'"
%token BEFORE											"'before'"
%token REVALIDATION	              "'revalidation'"
%token _STRICT                     "'strict'"
%token LAX                        "'lax'"
%token SKIP                       "'skip'"
%token _DELETE                     "'delete'"
%token NODE                       "'node'"
%token INSERT                     "'insert'"
%token NODES                      "'nodes'"
%token RENAME                     "'rename'"
%token REPLACE                    "'replace'"
%token VALUE                      "'value'"
%token OF                         "'of'"
%token FIRST                      "'first'"
%token INTO												"'into'"
%token LAST                       "'last'"
%token MODIFY 										"'modify'"
%token COPY                       "'copy'"
%token WITH												"'with'"

/* try-catch-related */
/* ----------------- */
%token TRY                        "'try'"
%token CATCH                      "'catch'"

/* eval-related */
/* ------------ */
%token USING                      "'using'"

/* full-text-related */
/* ----------------- */
%token ALL												"'all'"
%token ANY												"'any'"
%token SENSITIVE                  "'casesensitive'"
%token FT_OPTION                  "'ft-option'"
%token DIACRITICS                 "'diacritics'"
%token INSENSITIVE                "'insensitive'"
%token DIFFERENT									"'different'"
%token DISTANCE										"'distance'"
%token ENTIRE                     "'entire'"
%token END                        "'end'"
%token CONTENT                    "'content'"
%token EXACTLY										"'exactly'"
%token FROM												"'from'"
%token FTAND											"'&&'"
%token FTCONTAINS 								"'ftcontains'"
%token FTNOT                      "'not'"
%token FTOR												"'||'"
%token LANGUAGE 									"'language'"
%token LEVELS											"'levels'"
%token LOWERCASE									"'lowercase'"
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
%token WITHOUT                    "'without'"
%token STEMMING                   "'stemming'"
%token STOP                       "'stop'"
%token WORDS                      "'words'"
%token THESAURUS                  "'thesaurus'"
%token WILDCARDS	         				"'wildcards'"

/* Leading slash handling expression */
/* --------------------------------- */
%type <expr> LeadingSlash
    
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
%type <node> WindowClause
%type <node> ForClause
%type <node> ForLetWinClause
%type <node> FLWORClause
%type <node> FLWORClauseList
%type <node> ForwardAxis
%type <node> ForwardStep
%type <node> FunctionDecl
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
%type <node> WindowVarDecl
%type <node> WindowVars
%type <node> WindowVars2
%type <node> WindowVars3
%type <node> FLWORWinCond
%type <node> EvalVarDecl
%type <node> EvalVarDeclList
%type <node> VersionDecl
%type <node> VFO_Decl
%type <node> VFO_DeclList
%type <node> WhereClause
%type <node> CountClause
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
%type <expr> ReturnExpr
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
%type <expr> WhileExpr
%type <expr> FlowCtlStatement

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

// parsenodes
%destructor { RCHelper::addReference ($$); RCHelper::removeReference ($$); } AbbrevForwardStep AnyKindTest AposAttrContentList Opt_AposAttrContentList AposAttrValueContent ArgList AtomicType AttributeTest BaseURIDecl BoundarySpaceDecl CaseClause CaseClauseList CommentTest ConstructionDecl CopyNamespacesDecl DefaultCollationDecl DefaultNamespaceDecl DirAttr DirAttributeList DirAttributeValue DirElemContentList DocumentTest ElementTest EmptyOrderDecl WindowClause ForClause ForLetWinClause FLWORClauseList ForwardAxis ForwardStep FunctionDecl Import ItemType KindTest LetClause LibraryModule MainModule /* Module */ ModuleDecl ModuleImport NameTest NamespaceDecl NodeComp NodeTest OccurrenceIndicator OptionDecl GroupByClause GroupSpecList GroupSpec GroupCollationSpec OrderByClause OrderCollationSpec OrderDirSpec OrderEmptySpec OrderModifier OrderSpec OrderSpecList OrderingModeDecl PITest Param ParamList PositionalVar Pragma PragmaList PredicateList Prolog QVarInDecl QVarInDeclList QuoteAttrValueContent QuoteAttrContentList Opt_QuoteAttrContentList ReverseAxis ReverseStep SIND_Decl SIND_DeclList SchemaAttributeTest SchemaElementTest SchemaImport SchemaPrefix SequenceType Setter SignList SingleType TextTest TypeDeclaration TypeName TypeName_WITH_HOOK URILiteralList ValueComp VarDecl VarGetsDecl VarGetsDeclList VarInDecl VarInDeclList WindowVarDecl WindowVars WindowVars2 WindowVars3 FLWORWinCond EvalVarDecl EvalVarDeclList VersionDecl VFO_Decl VFO_DeclList WhereClause CountClause Wildcard // RevalidationDecl FTAnd FTAnyallOption FTBigUnit FTCaseOption FTContent FTDiacriticsOption FTDistance FTIgnoreOption FTInclExclStringLiteral FTInclExclStringLiteralList FTLanguageOption FTMatchOption FTMatchOptionProximityList FTMildnot FTOptionDecl FTOr FTOrderedIndicator FTProximity FTRange FTRefOrList FTScope FTScoreVar FTSelection FTStemOption FTStopwordOption FTStringLiteralList FTThesaurusID FTThesaurusList FTThesaurusOption FTTimes FTUnaryNot FTUnit FTWildcardOption FTWindow FTWords FTWordsSelection FTWordsValue
// exprnodes
%destructor { RCHelper::addReference ($$); RCHelper::removeReference ($$); } AdditiveExpr AndExpr AxisStep CDataSection CastExpr CastableExpr CommonContent ComparisonExpr CompAttrConstructor CompCommentConstructor CompDocConstructor CompElemConstructor CompPIConstructor CompTextConstructor ComputedConstructor Constructor ContextItemExpr DirCommentConstructor DirElemConstructor DirElemContent DirPIConstructor DirectConstructor BracedExpr Block BlockBody EnclosedExpr Expr ExprSingle ExtensionExpr FLWORExpr FilterExpr FunctionCall IfExpr InstanceofExpr IntersectExceptExpr Literal MultiplicativeExpr NumericLiteral OrExpr OrderedExpr ParenthesizedExpr PathExpr Predicate PrimaryExpr QuantifiedExpr QueryBody RangeExpr RelativePathExpr StepExpr StringLiteral TreatExpr TypeswitchExpr UnaryExpr UnionExpr UnorderedExpr ValidateExpr ValueExpr VarRef TryExpr CatchListExpr CatchExpr EvalExpr DeleteExpr InsertExpr RenameExpr ReplaceExpr TransformExpr VarNameList VarNameDecl ExitExpr WhileExpr FlowCtlStatement FTContainsExpr
// internal class
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
		XQUERY VERSION  STRING_LITERAL  SEMI
		{
       std::string encoding = "utf-8";
       $$ = new VersionDecl (LOC (@$), SYMTAB ($3), encoding);
		}
	|	XQUERY VERSION  STRING_LITERAL  ENCODING  STRING_LITERAL  SEMI
		{
       $$ = new VersionDecl (LOC (@$), SYMTAB ($3), SYMTAB ($5));
    }
	;


// [3] MainModule
// --------------
MainModule : 
    Prolog  QueryBody
		{
			$$ = new MainModule(LOC (@$),
								static_cast<QueryBody*>($2),
								static_cast<Prolog*>($1));
		}
	|
    QueryBody
		{
			$$ = new MainModule(LOC (@$),
								static_cast<QueryBody*>($1),
                NULL);
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
		MODULE NAMESPACE  NCNAME  EQUALS  URI_LITERAL  SEMI
		{
			$$ = new ModuleDecl(LOC (@$),
								driver.symtab.get((off_t)$3), 
								driver.symtab.get((off_t)$5));
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
	| Import
	| NamespaceDecl
	| DefaultNamespaceDecl
	;


// [6d] VFO_Decl
VFO_Decl :
		VarDecl
	| FunctionDecl
	| OptionDecl

	/* full-text extension */
	| FTOptionDecl
	;


// [7] Setter
// ----------
Setter :
		BoundarySpaceDecl
	| DefaultCollationDecl
	| BaseURIDecl
	| ConstructionDecl
	| OrderingModeDecl
	| EmptyOrderDecl
	| CopyNamespacesDecl

	/* update extension */
	| RevalidationDecl
	;


// [8] Import
// ----------
Import :
		SchemaImport
	| ModuleImport
	;


// [9] Separator
// -------------
// (= SEMI)


// [10] NamespaceDecl
// ------------------
NamespaceDecl :
		DECLARE NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
			$$ = new NamespaceDecl(LOC (@$),
								driver.symtab.get((off_t)$3),
								driver.symtab.get((off_t)$5));
		}
	;


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl :
		DECLARE BOUNDARY_SPACE  PRESERVE
		{
			$$ = new BoundarySpaceDecl(LOC (@$),
								StaticContextConsts::preserve_space);
		}
	|	DECLARE BOUNDARY_SPACE  STRIP
		{
			$$ = new BoundarySpaceDecl(LOC (@$),
								StaticContextConsts::strip_space);
		}
	;


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl :
		DECLARE DEFAULT ELEMENT  NAMESPACE  URI_LITERAL
		{
			$$ = new DefaultNamespaceDecl(LOC (@$),
								ParseConstants::ns_element_default,
								driver.symtab.get((off_t)$5));
		}
	| DECLARE DEFAULT FUNCTION  NAMESPACE  URI_LITERAL
		{
			$$ = new DefaultNamespaceDecl(LOC (@$),
								ParseConstants::ns_function_default,
								driver.symtab.get((off_t)$5));
		}
	;


// [13] OptionDecl
// ---------------
OptionDecl :
		DECLARE OPTION  QNAME  STRING_LITERAL
		{
			$$ = new OptionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$3)),
								driver.symtab.get((off_t)$4));
		}
	;


/* full-text extension */
// [13a] FTOptionDecl
// ------------------
FTOptionDecl :
		DECLARE FT_OPTION  FTMatchOption
		{
			$$ = new FTOptionDecl(LOC (@$),
								$3);
		}
	;


// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl :
		DECLARE ORDERING  ORDERED
		{
			$$ = new OrderingModeDecl(LOC (@$),
								StaticContextConsts::ordered);
		}
	| DECLARE ORDERING  UNORDERED
		{
			$$ = new OrderingModeDecl(LOC (@$),
								StaticContextConsts::unordered);
		}
	;



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl :
		DECLARE DEFAULT ORDER _EMPTY GREATEST
		{
			$$ = new EmptyOrderDecl(LOC (@$),
								StaticContextConsts::empty_greatest);
		}
	|	DECLARE DEFAULT ORDER _EMPTY LEAST
		{
			$$ = new EmptyOrderDecl(LOC (@$),
								StaticContextConsts::empty_least);
		}
	;


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl :
		DECLARE COPY_NAMESPACES  PRESERVE  COMMA  INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
	| DECLARE COPY_NAMESPACES  PRESERVE  COMMA  NO_INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
	| DECLARE COPY_NAMESPACES  NO_PRESERVE  COMMA  INHERIT
		{
			$$ = new CopyNamespacesDecl(LOC (@$),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
	| DECLARE COPY_NAMESPACES  NO_PRESERVE  COMMA  NO_INHERIT
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
		DECLARE DEFAULT COLLATION  URI_LITERAL
		{
			$$ = new DefaultCollationDecl(LOC (@$),
								driver.symtab.get((off_t)$4));
		}
	;


// [20] BaseURIDecl
// ----------------
BaseURIDecl :
		DECLARE BASE_URI  URI_LITERAL
		{
			$$ = new BaseURIDecl(LOC (@$),
								driver.symtab.get((off_t)$3));
		}
	;


// [21] SchemaImport
// -----------------
SchemaImport :
		IMPORT SCHEMA  URI_LITERAL
		{
			$$ = new SchemaImport(LOC (@$),
								NULL,
								driver.symtab.get((off_t)$3),
								NULL);
		}
	| IMPORT SCHEMA  SchemaPrefix  URI_LITERAL
		{
			$$ = new SchemaImport(LOC (@$),
								dynamic_cast<SchemaPrefix*>($3),
								driver.symtab.get((off_t)$4),
								NULL);
		}
	|	IMPORT SCHEMA  URI_LITERAL  AT  URILiteralList
		{
			$$ = new SchemaImport(LOC (@$),
								NULL,
								driver.symtab.get((off_t)$3),
								dynamic_cast<URILiteralList*>($5));
		}
	|	IMPORT SCHEMA  SchemaPrefix  URI_LITERAL  AT  URILiteralList
		{
			$$ = new SchemaImport(LOC (@$),
								dynamic_cast<SchemaPrefix*>($3),
								driver.symtab.get((off_t)$4),
								dynamic_cast<URILiteralList*>($6));
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
	|	DEFAULT ELEMENT NAMESPACE
		{
			$$ = new SchemaPrefix(LOC (@$), true);
		}
	;


// [23] ModuleImport
// -----------------
ModuleImport :
		IMPORT MODULE  URI_LITERAL
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$3),
								NULL);
		}
	|	IMPORT MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$4),
								driver.symtab.get((off_t)$6),
								NULL);
		}
	|	IMPORT MODULE  URI_LITERAL  AT  URILiteralList
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$3),
								dynamic_cast<URILiteralList*>($5));
		}
	|	IMPORT MODULE  NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URILiteralList
		{
			$$ = new ModuleImport(LOC (@$),
								driver.symtab.get((off_t)$4),
								driver.symtab.get((off_t)$6),
								dynamic_cast<URILiteralList*>($8));
		}
	;



// [24] VarDecl
// ------------
VarDecl :
    DECLARE  VARIABLE  DOLLAR  QNAME  GETS  ExprSingle
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$4),
								NULL,
								$6);
		}
	|	DECLARE  VARIABLE  DOLLAR  QNAME  EXTERNAL
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$4),
								NULL,
								NULL);
		}
	|	DECLARE  VARIABLE  DOLLAR  QNAME  TypeDeclaration  GETS  ExprSingle
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$4),
								dynamic_cast<TypeDeclaration*>($5),
								$7);
		}
	|	DECLARE  VARIABLE  DOLLAR  QNAME  TypeDeclaration  EXTERNAL
		{
			$$ = new VarDecl(LOC (@$),
								driver.symtab.get((off_t)$4),
								dynamic_cast<TypeDeclaration*>($5),
								NULL);
		}
	;


// [25] ConstructionDecl
// ---------------------
ConstructionDecl :
		DECLARE  CONSTRUCTION  PRESERVE
		{
			$$ = new ConstructionDecl(LOC (@$),
								StaticContextConsts::cons_preserve);
		}
	|	DECLARE  CONSTRUCTION  STRIP
		{
			$$ = new ConstructionDecl(LOC (@$),
								StaticContextConsts::cons_strip);
		}
	;


// [26] FunctionDecl
// -----------------

FunctionSig :
    LPAR  RPAR
    {
      $$ = new FunctionSig (NULL);
    }
  | LPAR  ParamList  RPAR
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
    EXIT WITH ExprSingle
    {
      $$ = new ExitExpr (LOC (@$), $3);
    }
  ;

WhileExpr :
    WHILE LPAR ExprSingle RPAR Block
    {
      $$ = new WhileExpr (LOC (@$), $3, dynamic_cast<BlockBody *> ($5));
    }
  ;

FlowCtlStatement :
    BREAK LOOP
    {
      $$ = new FlowCtlStatement (LOC (@$), FlowCtlStatement::BREAK);
    }
  | CONT LOOP
    {
      $$ = new FlowCtlStatement (LOC (@$), FlowCtlStatement::CONTINUE);
    }
  ;

FunctionDecl :
		DECLARE FUNCTION  QNAME FunctionSig EXTERNAL
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$3)),
                &* $4->param, &* $4->ret, NULL,
								ParseConstants::fn_extern);
      delete $4;
		}
	|	DECLARE FUNCTION  QNAME FunctionSig BracedExpr
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$3)),
                &* $4->param, &* $4->ret,
								$5,
								ParseConstants::fn_read);
      delete $4;
		}
	|	DECLARE UPDATING FUNCTION  QNAME FunctionSig EXTERNAL
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$4)),
								&* $5->param, &* $5->ret,
								NULL,
								ParseConstants::fn_extern_update);
      delete $5;
		}
	|	DECLARE UPDATING FUNCTION  QNAME FunctionSig BracedExpr
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$4)),
                &* $5->param, &* $5->ret,
								$6,
								ParseConstants::fn_update);
      delete $5;
		}
  | DECLARE SEQUENTIAL FUNCTION QNAME FunctionSig Block
		{
			$$ = new FunctionDecl(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$4)),
                &* $5->param, &* $5->ret,
								$6,
								ParseConstants::fn_sequential);
      delete $5;
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
		DOLLAR  QNAME
		{
			$$ = new Param(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL);
		}
	|	DOLLAR  QNAME  TypeDeclaration
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
  | QuantifiedExpr
  | TypeswitchExpr
  | IfExpr
  | OrExpr

    /* update extensions */
  | InsertExpr
  | DeleteExpr
  | RenameExpr
  | ReplaceExpr
  | TransformExpr
  | TryExpr
  | EvalExpr
  | ExitExpr
  | WhileExpr
  | FlowCtlStatement
  | Block
    ;


// [33] FLWORExpr
// --------------
FLWORExpr :
    FLWORClauseList ReturnExpr
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>($2);
      $$ = new FLWORExpr (LOC (@$), dynamic_cast<FLWORClauseList*>($1), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete lReturnExpr
    }
    ;

ReturnExpr:
    RETURN ExprSingle
    {
      $$ = new ReturnExpr(LOC(@$), $2);
    }
    ;

WindowType :
    SLIDING WINDOW
    {
      $$ = parser::the_sliding;
    }
  | TUMBLING WINDOW
    {
      $$ = parser::the_tumbling;
    }
  ;


FLWORWinCondType :
    START
    {
      $$ = parser::the_start;
    }
  | END
    {
      $$ = parser::the_end;
    }
  | ONLY END
    {
      $$ = parser::the_only_end;
    }
  ;

FLWORWinCond :
    FLWORWinCondType WindowVars WHEN ExprSingle
    {
      $$ = new FLWORWinCond (LOC (@$), dynamic_cast<WindowVars *> ($2), $4, $1 == parser::the_start, $1 == parser::the_only_end);
    }
  | FLWORWinCondType WHEN ExprSingle
    {
      $$ = new FLWORWinCond (LOC (@$), NULL, $3, $1 == parser::the_start, $1 == parser::the_only_end);
    }
  ;

WindowClause :
    FOR WindowType WindowVarDecl FLWORWinCond FLWORWinCond
    {
      $$ = new WindowClause (LOC (@$), ($2 == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ($3),
                             dynamic_cast<FLWORWinCond *> ($4), dynamic_cast<FLWORWinCond *> ($5));
    }
  | FOR WindowType WindowVarDecl FLWORWinCond
    {
      $$ = new WindowClause (LOC (@$), ($2 == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window, dynamic_cast<WindowVarDecl *> ($3),
                             dynamic_cast<FLWORWinCond *> ($4), NULL);
    }
  ;


CountClause :
    COUNT DOLLAR QNAME
    {
      $$ = new CountClause (LOC (@$), driver.symtab.get((off_t)$3));
    }
    ;

// [33b] ForLetWinClause
// ------------------
ForLetWinClause :
		ForClause
	|	LetClause
  | WindowClause
	;

FLWORClause :
    ForLetWinClause | WhereClause | OrderByClause | GroupByClause | CountClause;

FLWORClauseList :
    ForLetWinClause
    {
      FLWORClauseList *l = new FLWORClauseList (LOC (@$));
      l->push_back (dynamic_cast<FLWORClause *> ($1));
      $$ = l;
    }
  | FLWORClauseList FLWORClause
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ($1);
      l->push_back (dynamic_cast<FLWORClause *> ($2));
      $$ = l;
    }
  ;

ForDollar :
    FOR DOLLAR
    {
      $$ = NULL;
    }
  | OUTER FOR DOLLAR
    {
      $$ = parser::the_ofor;
    }
  ;
    

// [34] ForClause
// --------------
ForClause :
		ForDollar VarInDeclList
		{
			$$ = new ForClause(LOC (@$),
                         dynamic_cast<VarInDeclList*>($2), $1 != NULL);
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
		QNAME  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,NULL,NULL,
								$3);
		}
	|	QNAME  TypeDeclaration  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,NULL,
								$4);
		}
	|	QNAME  PositionalVar  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								NULL,
								$4);
		}
	|	QNAME  TypeDeclaration  PositionalVar  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<PositionalVar*>($3),
								NULL,
								$5);
		}
	/* full-text extensions */
	| QNAME  FTScoreVar  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| QNAME  TypeDeclaration  FTScoreVar  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| QNAME  PositionalVar  FTScoreVar  _IN  ExprSingle
		{
			$$ = new VarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<PositionalVar*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	| QNAME  TypeDeclaration  PositionalVar  FTScoreVar  _IN  ExprSingle
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
		AT  DOLLAR  QNAME
		{
			$$ = new PositionalVar(LOC (@$),
								driver.symtab.get((off_t)$3));
		}
	;


/* full-text extension */
// [35a] FTScoreVar
// ----------------
FTScoreVar :
		SCORE  DOLLAR  QNAME
		{
			$$ = new FTScoreVar(LOC (@$),
								driver.symtab.get((off_t)$3));
		}
	;


// [36] LetClause
// --------------
LetClause :
		LET DOLLAR VarGetsDeclList
		{
			$$ = new LetClause(LOC (@$),
								dynamic_cast<VarGetsDeclList*>($3));
			
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
		QNAME  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								NULL,
								$3);
		}
	|	QNAME  TypeDeclaration  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								NULL,
								$4);
		}
	/* full-text extensions */
	| QNAME  FTScoreVar  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								NULL,
								dynamic_cast<FTScoreVar*>($2),
								$4);
		}
	| QNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
		{
			$$ = new VarGetsDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								dynamic_cast<TypeDeclaration*>($2),
								dynamic_cast<FTScoreVar*>($3),
								$5);
		}
	;


WindowVarDecl :
		DOLLAR QNAME  _IN  ExprSingle
		{
			$$ = new WindowVarDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								NULL, $4);
		}
	|	DOLLAR QNAME  TypeDeclaration  _IN  ExprSingle
		{
			$$ = new WindowVarDecl(LOC (@$),
								driver.symtab.get((off_t)$2),
								dynamic_cast<TypeDeclaration*>($3),
								$5);
		}


WindowVars :
    WindowVars3
  | DOLLAR QNAME
    {
      $$ = new WindowVars (LOC (@$), NULL, driver.symtab.get((off_t)$2), "", "");
    }
  | DOLLAR QNAME WindowVars3
    {
      $$ = $3;
      dynamic_cast<WindowVars *> ($$)->set_curr (driver.symtab.get((off_t)$2));
    }
  ;

WindowVars3 :
    PositionalVar
    {
      $$ = new WindowVars (LOC (@$), dynamic_cast<PositionalVar *> ($1), "", "", "");
    }
  | PositionalVar WindowVars2
    {
      $$ = $2;
      dynamic_cast<WindowVars *> ($$)->set_posvar (dynamic_cast<PositionalVar *> ($1));
    }
  | WindowVars2
  ;

WindowVars2 :
    PREVIOUS DOLLAR QNAME NEXT DOLLAR QNAME
    {
      $$ = new WindowVars (LOC (@$), NULL, "", driver.symtab.get((off_t)$3), driver.symtab.get((off_t)$6));
    }
  | NEXT DOLLAR QNAME
    {
      $$ = new WindowVars (LOC (@$), NULL, "", "", driver.symtab.get((off_t)$3));
    }
  | PREVIOUS DOLLAR QNAME
    {
      $$ = new WindowVars (LOC (@$), NULL, "", driver.symtab.get((off_t)$3), "");
    }
    ;

EvalVarDecl :
    QNAME
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
    GROUP BY GroupSpecList
    {
      $$ = new GroupByClause(LOC(@$),
                 dynamic_cast<GroupSpecList*>($3),
                 NULL,
                 NULL);
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
    DOLLAR QNAME
    {
      $$ = new GroupSpec(LOC(@$),
                 driver.symtab.get((off_t)$2),
                 NULL);
    }
  | DOLLAR QNAME GroupCollationSpec
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


// [38] OrderByClause
// ------------------
OrderByClause :
		ORDER BY  OrderSpecList
		{
			$$ = new OrderByClause(LOC (@$),
								dynamic_cast<OrderSpecList*>($3));
		}
	|	STABLE ORDER BY  OrderSpecList
		{
			$$ = new OrderByClause(LOC (@$),
								dynamic_cast<OrderSpecList*>($4),
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
		_EMPTY GREATEST
		{
			$$ = new OrderEmptySpec(LOC (@$),
								StaticContextConsts::empty_greatest);
		}
	|	_EMPTY LEAST
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
		SOME DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			$$ = new QuantifiedExpr(LOC (@$),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>($3),
								$5);
		}
	|	EVERY DOLLAR  QVarInDeclList  SATISFIES  ExprSingle
		{
			$$ = new QuantifiedExpr(LOC (@$),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>($3),
								$5);
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
		QNAME  _IN  ExprSingle
		{
			$$ = new QVarInDecl(LOC (@$),
								driver.symtab.get((off_t)$1),
								$3);
		}
	|	QNAME  TypeDeclaration  _IN  ExprSingle
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
		TYPESWITCH LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
		{
			$$ = new TypeswitchExpr(LOC (@$),
								$3,
								dynamic_cast<CaseClauseList*>($5),
								$8);
		}
	|	TYPESWITCH LPAR  Expr  RPAR  CaseClauseList  DEFAULT  DOLLAR  QNAME  RETURN  ExprSingle
		{
			$$ = new TypeswitchExpr(LOC (@$),
								$3,
								dynamic_cast<CaseClauseList*>($5),
								driver.symtab.get((off_t)$8),
								$10);
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
	|	CASE  DOLLAR  QNAME  AS  SequenceType  RETURN  ExprSingle
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
		IF LPAR  Expr  RPAR  THEN  ExprSingle  ELSE  ExprSingle
		{
			$$ = new IfExpr(LOC (@$),
								$3, $6, $8);
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
	| FTContainsExpr ValueComp FTContainsExpr
		{
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			$$ = new ComparisonExpr(LOC (@$),
								dynamic_cast<ValueComp*>($2),
								$1,
								$3);
		}
  | FTContainsExpr NodeComp FTContainsExpr
    {
      /*  ::=  "is" | "<<" | ">>" */
      $$ = new ComparisonExpr(LOC (@$),
                dynamic_cast<NodeComp*>($2),
                $1,
                $3);
    }  
	| FTContainsExpr EQUALS FTContainsExpr
		{
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			$$ = new ComparisonExpr(LOC (@$),
								new GeneralComp(LOC (@$), ParseConstants::op_eq),
								$1,
								$3);
		}
  | FTContainsExpr NE FTContainsExpr
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      $$ = new ComparisonExpr(LOC (@$),
                new GeneralComp(LOC (@$), ParseConstants::op_ne),
                $1,
                $3);
    }  
  | FTContainsExpr LT_OR_START_TAG { /* this call is needed */  driver.lexer->interpretAsLessThan(); } FTContainsExpr
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      $$ = new ComparisonExpr(LOC (@$),
                new GeneralComp(LOC (@$), ParseConstants::op_lt),
                $1,
                $4);
    }
  | FTContainsExpr LE FTContainsExpr
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      $$ = new ComparisonExpr(LOC (@$),
                new GeneralComp(LOC (@$), ParseConstants::op_le),
                $1,
                $3);
    }
  | FTContainsExpr GT FTContainsExpr
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      $$ = new ComparisonExpr(LOC (@$),
                new GeneralComp(LOC (@$), ParseConstants::op_gt),
                $1,
                $3);
    }
  | FTContainsExpr GE FTContainsExpr
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      $$ = new ComparisonExpr(LOC (@$),
                new GeneralComp(LOC (@$), ParseConstants::op_ge),
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
	|	TreatExpr  INSTANCE OF  SequenceType
		{
			$$ = new InstanceofExpr(LOC (@$),
								$1,
								dynamic_cast<SequenceType*>($4));
		}
	;


// [55] TreatExpr
// --------------
TreatExpr :
		CastableExpr
		{
			$$ = $1;
		}
	|	CastableExpr  TREAT AS  SequenceType
		{
			$$ = new TreatExpr(LOC (@$),
								$1,
								dynamic_cast<SequenceType*>($4));
		}
	;


// [56] CastableExpr
// -----------------
CastableExpr :
		CastExpr
		{
			$$ = $1;
		}
	|	CastExpr  CASTABLE AS  SingleType
		{
			$$ = new CastableExpr(LOC (@$),
								$1,
								dynamic_cast<SingleType*>($4));
		}
	;


// [57] CastExpr 	   
// -------------
CastExpr :
		UnaryExpr
		{
			$$ = $1;
		}
	|	UnaryExpr  CAST AS  SingleType
		{
			$$ = new CastExpr(LOC (@$),
								$1,
								dynamic_cast<SingleType*>($4));
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
		VALIDATE LBRACE  Expr  RBRACE
		{
			$$ = new ValidateExpr(LOC (@$), "strict", $3);
		}
	|	VALIDATE _STRICT  LBRACE  Expr  RBRACE
		{
			$$ = new ValidateExpr(LOC (@$),
                "strict",
								$4);
		}
  | VALIDATE LAX  LBRACE  Expr  RBRACE
    {
      $$ = new ValidateExpr(LOC (@$),
                "lax",
                $4);
    }
  | VALIDATE SKIP  LBRACE  Expr  RBRACE
    {
      $$ = new ValidateExpr(LOC (@$),
                "skip",
                $4);
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
		PRAGMA_BEGIN  QNAME  PRAGMA_LITERAL_AND_END_PRAGMA
		{
			$$ = new Pragma(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								driver.symtab.get((off_t)$3));

		}
  | PRAGMA_BEGIN QNAME_SVAL_AND_END_PRAGMA {
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
		LeadingSlash
		{
			$$ = new PathExpr(LOC (@$), ParseConstants::path_leading_lone_slash, NULL);
		}
	|	LeadingSlash RelativePathExpr
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

// Leading slash promotion
// -----------------------
LeadingSlash :
    SLASH
    {
      $$ = NULL;
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
			$$ = NumericLiteral::new_literal(LOC (@$), ParseConstants::num_decimal, *$1);
      delete yylval.decval;
		}
	| INTEGER_LITERAL
		{
			$$ = NumericLiteral::new_literal(LOC (@$), ParseConstants::num_integer, *$1);
      delete yylval.ival;
		}
	|	DOUBLE_LITERAL
		{
			$$ = NumericLiteral::new_literal(LOC (@$), ParseConstants::num_double, *$1);
      delete yylval.dval;
		}
	;


// [86] VarRef
// -----------
VarRef :
		DOLLAR  QNAME
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
		ORDERED LBRACE  Expr  RBRACE
		{
			$$ = new OrderedExpr(LOC (@$),
								$3);
		}
	;


// [90] UnorderedExpr
// ------------------
UnorderedExpr :
		UNORDERED LBRACE  Expr  RBRACE
		{
			$$ = new UnorderedExpr(LOC (@$),
								$3);
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
    LT_OR_START_TAG  QNAME  OptionalBlank  EMPTY_TAG_END /* ws: explicitXQ */
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL,
								NULL,
								NULL);
		}
  | LT_OR_START_TAG  QNAME  DirAttributeList  OptionalBlank  EMPTY_TAG_END /* ws: explicitXQ */
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL,
								dynamic_cast<DirAttributeList*>($3), 
								NULL);
		}
  | LT_OR_START_TAG  QNAME  OptionalBlank  TAG_END  START_TAG_END  QNAME OptionalBlank TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$6)),
								NULL,
								NULL);
		}
  |	LT_OR_START_TAG  QNAME  OptionalBlank  TAG_END  DirElemContentList  START_TAG_END  QNAME  OptionalBlank  TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$7)),
								NULL,
								dynamic_cast<DirElemContentList*>($5));
		}
  | LT_OR_START_TAG  QNAME  DirAttributeList  OptionalBlank  TAG_END  START_TAG_END  QNAME  OptionalBlank  TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$7)),
								dynamic_cast<DirAttributeList*>($3),
								NULL);
		}
    |	LT_OR_START_TAG  QNAME  DirAttributeList  OptionalBlank  TAG_END  DirElemContentList  START_TAG_END  QNAME  OptionalBlank  TAG_END
		{
			$$ = new DirElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								new QName(LOC (@$),driver.symtab.get((off_t)$8)),
								dynamic_cast<DirAttributeList*>($3), 
								dynamic_cast<DirElemContentList*>($6));
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
    BLANK  QNAME  OptionalBlank  EQUALS  OptionalBlank  DirAttributeValue 	/* ws: explicitXQ */
		{
			$$ = new DirAttr(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								dynamic_cast<DirAttributeValue*>($6));
		}
	;

// OptionaBlank used in the DirElemConstr
OptionalBlank :
    /* nothing */
    | BLANK;


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
		DOCUMENT LBRACE  Expr  RBRACE
		{
			$$ = new CompDocConstructor(LOC (@$),
								$3);
		}
	;


// [109] CompElemConstructor
// -------------------------
CompElemConstructor :
		ELEMENT QNAME LBRACE  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL);
		}
	|	ELEMENT QNAME LBRACE  Expr  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								$4);
		}
	|	ELEMENT LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								$3, NULL);
		}
	|	ELEMENT LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			$$ = new CompElemConstructor(LOC (@$),
								$3, $6);
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
		ATTRIBUTE QNAME LBRACE  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								NULL);
		}
	|	ATTRIBUTE QNAME LBRACE  Expr  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$2)),
								$4);
		}
	|	ATTRIBUTE LBRACE  Expr  RBRACE  LBRACE  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								$3, NULL);
		}
	|	ATTRIBUTE LBRACE  Expr  RBRACE  LBRACE  Expr  RBRACE
		{
			$$ = new CompAttrConstructor(LOC (@$),
								$3, $6);
		}
	;


// [112] CompTextConstructor
// -------------------------
CompTextConstructor :
		TEXT LBRACE  Expr  RBRACE
		{
			$$ = new CompTextConstructor(LOC (@$),
								dynamic_cast<Expr*>($3));
		}
	;


// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor :
		COMMENT LBRACE  Expr  RBRACE
		{
			$$ = new CompCommentConstructor(LOC (@$),
								dynamic_cast<Expr*>($3));
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
		// ItemType  %prec SEQUENCE_TYPE_REDUCE
    ItemType  
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
  |	EMPTY_SEQUENCE LPAR RPAR
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
		HOOK
		{
			$$ = new OccurrenceIndicator(LOC (@$),
								ParseConstants::occurs_optionally);
		}
	|	STAR
		{
			$$ = new OccurrenceIndicator(LOC (@$),
								ParseConstants::occurs_zero_or_more);
		}
	|	PLUS 	/* gn: occurrence-indicatorsXQ */
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
	|	ITEM LPAR RPAR
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
		NODE LPAR  RPAR
		{
			$$ = new AnyKindTest(LOC (@$));
		}
	;
 

// [123] DocumentTest
// ------------------
DocumentTest :
		DOCUMENT_NODE LPAR  RPAR
		{
			$$ = new DocumentTest(LOC (@$));
		}
	|	DOCUMENT_NODE LPAR  ElementTest  RPAR
		{
			$$ = new DocumentTest(LOC (@$),
								dynamic_cast<ElementTest*>($3));
		}
	|	DOCUMENT_NODE LPAR  SchemaElementTest  RPAR
		{
			$$ = new DocumentTest(LOC (@$),
								dynamic_cast<SchemaElementTest*>($3));
		}
	;


// [124] TextTest
// --------------
TextTest :
		TEXT LPAR  RPAR
		{
			$$ = new TextTest(LOC (@$));
		}
	;


// [125] CommentTest
// -----------------
CommentTest :
		COMMENT LPAR  RPAR
		{
			$$ = new CommentTest(LOC (@$));
		}
	;
 

// [126] PITest
// ------------
PITest :
		PROCESSING_INSTRUCTION LPAR  RPAR
		{
			$$ = new PITest(LOC (@$), "");
		}
	|	PROCESSING_INSTRUCTION LPAR  NCNAME  RPAR
		{
			$$ = new PITest(LOC (@$), driver.symtab.get((off_t)$3));
		}
  |	PROCESSING_INSTRUCTION LPAR  STRING_LITERAL  RPAR
		{
			$$ = new PITest(LOC (@$), driver.symtab.get((off_t)$3));
		}
	;


// [127] AttributeTest
// -------------------
AttributeTest :
		ATTRIBUTE LPAR  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								NULL);
		}
	|	ATTRIBUTE LPAR  QNAME  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$3)),
								NULL);
		}
	|	ATTRIBUTE LPAR  QNAME  COMMA  TypeName  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								new QName(LOC (@$),driver.symtab.get((off_t)$3)),
								dynamic_cast<TypeName*>($5));
		}
	|	ATTRIBUTE LPAR  STAR  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								NULL);
		}
	|	ATTRIBUTE LPAR  STAR  COMMA  TypeName  RPAR
		{
			$$ = new AttributeTest(LOC (@$),
								NULL,
								dynamic_cast<TypeName*>($5));
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
		ELEMENT LPAR  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									NULL);
		}
	|	ELEMENT LPAR  QNAME  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$3)),
									NULL);
		}
	|	ELEMENT LPAR  QNAME  COMMA  TypeName  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$3)),
									dynamic_cast<TypeName*>($5));
		}
	|	ELEMENT LPAR  QNAME  COMMA  TypeName_WITH_HOOK RPAR
		{
			$$ = new ElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$3)),
									dynamic_cast<TypeName*>($5));
		}
	|	ELEMENT LPAR  STAR  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									NULL,
									true);
		}
	|	ELEMENT LPAR  STAR  COMMA  TypeName  RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									dynamic_cast<TypeName*>($5),
									true);
		}
	|	ELEMENT LPAR  STAR  COMMA  TypeName_WITH_HOOK RPAR
		{
			$$ = new ElementTest(LOC (@$),
									NULL,
									dynamic_cast<TypeName*>($5),
									true);
		}
	;


// [133] SchemaElementTest
// -----------------------
SchemaElementTest :
		SCHEMA_ELEMENT LPAR  QNAME  RPAR
		{
			$$ = new SchemaElementTest(LOC (@$),
									new QName(LOC (@$),driver.symtab.get((off_t)$3)));
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
		DECLARE REVALIDATION _STRICT
		{
//			$$ = new OrderingModeDecl(@$,
//								StaticQueryContext::ordered);
		}
    | DECLARE REVALIDATION LAX
    {
    }
    | DECLARE REVALIDATION SKIP
    {
    }
	;

// [242]	InsertExpr
// ----------------
InsertExpr :
		INSERT NODE ExprSingle INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::INTO, $3, $5);
		}
	|	INSERT NODE ExprSingle AS FIRST INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_FIRST_INTO, $3, $7);
		}
	|	INSERT NODE ExprSingle AS LAST INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_LAST_INTO, $3, $7);
		}
	| INSERT NODE ExprSingle AFTER ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AFTER, $3, $5);
		}
	| INSERT NODE ExprSingle BEFORE ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::BEFORE, $3, $5);
		}
  |
		INSERT NODES ExprSingle INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::INTO, $3, $5);
		}
	|	INSERT NODES ExprSingle AS FIRST INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_FIRST_INTO, $3, $7);
		}
	|	INSERT NODES ExprSingle AS LAST INTO ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AS_LAST_INTO, $3, $7);
		}
	| INSERT NODES ExprSingle AFTER ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::AFTER, $3, $5);
		}
	| INSERT NODES ExprSingle BEFORE ExprSingle
		{
       $$ = new InsertExpr(
                  LOC (@$),
                  store::UpdateConsts::BEFORE, $3, $5);
		}
	;


// [243] DeleteExpr
// ----------------
DeleteExpr:
		_DELETE NODE ExprSingle
		{
       $$ = new DeleteExpr( LOC (@$), $3);
		}
  |
		_DELETE NODES ExprSingle
		{
       $$ = new DeleteExpr( LOC (@$), $3);
		}
	;


// [244] ReplaceExpr
// -----------------
ReplaceExpr :
		REPLACE NODE ExprSingle WITH ExprSingle
		{
       $$ = new ReplaceExpr(
                  LOC (@$),
                  store::UpdateConsts::NODE, $3, $5);
		}
	|	REPLACE VALUE OF NODE ExprSingle WITH ExprSingle
		{
       $$ = new ReplaceExpr(
                  LOC (@$),
                  store::UpdateConsts::VALUE_OF_NODE, $5, $7);
		}
	;


// [245] RenameExpr
// ----------------
RenameExpr :
		RENAME NODE ExprSingle AS ExprSingle
		{
       $$ = new RenameExpr(
                  LOC (@$), $3, $5);
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
		COPY DOLLAR VarNameList MODIFY ExprSingle RETURN ExprSingle
		{
      VarNameList* lList = dynamic_cast<VarNameList*>($3);
      $$ = new TransformExpr(LOC(@$), lList, $5, $7);
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
    QNAME GETS ExprSingle
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
    CATCH LPAR NameTest RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($3),
                          $5);
    }
  |
    CATCH LPAR NameTest COMMA DOLLAR QNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($3),
                          driver.symtab.get((off_t)$6),
                          $8);
    }
  |
    CATCH LPAR NameTest COMMA DOLLAR QNAME COMMA DOLLAR QNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($3),
                          driver.symtab.get((off_t)$6),
                          driver.symtab.get((off_t)$9),
                          $11);
    }
  |
    CATCH LPAR NameTest COMMA DOLLAR QNAME COMMA DOLLAR QNAME COMMA DOLLAR QNAME RPAR BracedExpr
    {
       $$ = new CatchExpr(LOC (@$),
                          static_cast<NameTest*>($3),
                          driver.symtab.get((off_t)$6),
                          driver.symtab.get((off_t)$9),
                          driver.symtab.get((off_t)$12),
                          $14);
    }
  ;


URI_LITERAL :
    STRING_LITERAL;

NCNAME :
  QNAME_SVAL
  {
    std::string tmp = driver.symtab.get((off_t)$1);
    for (unsigned int i = 0; i<tmp.size(); i++)
      if (tmp[i] == ':')
      {
        error(@1, "A NCName is expected, found a QName");
        YYERROR;
      }
    $$ = $1;
  }

/*_______________________________________________________________________
 *                                                                       *
 *  All QNames                                                           *
 *                                                                       *
 *_______________________________________________________________________*/
QNAME :
    QNAME_SVAL { $$ = $1; }
  | _EMPTY { $$ = driver.symtab.put("empty"); }
  | ATTRIBUTE { $$ = driver.symtab.put("attribute"); }
  | COMMENT { $$ = driver.symtab.put("comment"); }
  | DOCUMENT_NODE { $$ = driver.symtab.put("document-node"); }
  | ELEMENT { $$ = driver.symtab.put("element"); }
  | ITEM { $$ = driver.symtab.put("item"); }
  | IF { $$ = driver.symtab.put("if"); }
  | NODE { $$ = driver.symtab.put("node"); }
  | PROCESSING_INSTRUCTION { $$ = driver.symtab.put("processing-instruction"); }
  | SCHEMA_ATTRIBUTE { $$ = driver.symtab.put("schema-attribute"); }
  | SCHEMA_ELEMENT { $$ = driver.symtab.put("schema-element"); }
  | TEXT { $$ = driver.symtab.put("text"); }
  | TYPESWITCH { $$ = driver.symtab.put("typeswitch"); }
  | EMPTY_SEQUENCE { $$ = driver.symtab.put("empty-sequence"); }
  | BOUNDARY_SPACE { $$ = driver.symtab.put("boundary-space"); }
  | FT_OPTION { $$ = driver.symtab.put("ft-option"); }
  | BASE_URI { $$ = driver.symtab.put("base-uri"); }
  | LAX { $$ = driver.symtab.put("lax"); }
  | _STRICT { $$ = driver.symtab.put("strict"); }
  | IDIV { $$ = driver.symtab.put("idiv"); }
  | DOCUMENT { $$ = driver.symtab.put("document"); }
  | FTNOT { $$ = driver.symtab.put("not"); }
  | SENSITIVE { $$ = driver.symtab.put("sensitive"); }
  | INSENSITIVE { $$ = driver.symtab.put("insensitive"); }
  | DIACRITICS { $$ = driver.symtab.put("diacritics"); }
  | WITHOUT { $$ = driver.symtab.put("without"); }
  | STEMMING { $$ = driver.symtab.put("stemming"); }
  | THESAURUS { $$ = driver.symtab.put("thesaurus"); }
  | STOP { $$ = driver.symtab.put("stop"); }
  | WILDCARDS { $$ = driver.symtab.put("wildcards"); }
  | ENTIRE { $$ = driver.symtab.put("entire"); }
  | CONTENT { $$ = driver.symtab.put("content"); }
  | WORD { $$ = driver.symtab.put("word"); }
  | START { $$ = driver.symtab.put("start"); }
  | END { $$ = driver.symtab.put("end"); }
  | MOST { $$ = driver.symtab.put("most"); }
  | SKIP { $$ = driver.symtab.put("skip"); }
  | COPY { $$ = driver.symtab.put("copy"); }
  | VALUE { $$ = driver.symtab.put("value"); }
  | VAL_EQ { $$ = driver.symtab.put("eq"); }
  | VAL_NE { $$ = driver.symtab.put("ne"); }
  | VAL_LT { $$ = driver.symtab.put("lt"); }
  | VAL_LE { $$ = driver.symtab.put("le"); }
  | VAL_GT { $$ = driver.symtab.put("gt"); }
  | VAL_GE { $$ = driver.symtab.put("ge"); }
  | AT { $$ = driver.symtab.put("at"); }
  | VARIABLE { $$ = driver.symtab.put("variable"); }
  | RETURN { $$ = driver.symtab.put("return"); }
  | FOR { $$ = driver.symtab.put("for"); }
  | OUTER { $$ = driver.symtab.put("outer"); }
  | SLIDING { $$ = driver.symtab.put("sliding"); }
  | TUMBLING { $$ = driver.symtab.put("tumbling"); }
  | PREVIOUS { $$ = driver.symtab.put("previous"); }
  | NEXT { $$ = driver.symtab.put("next"); }
  | ONLY { $$ = driver.symtab.put("only"); }
  | WHEN { $$ = driver.symtab.put("when"); }
  | COUNT { $$ = driver.symtab.put("count"); }
  | _IN { $$ = driver.symtab.put("in"); }
  | LET { $$ = driver.symtab.put("let"); }
  | WHERE { $$ = driver.symtab.put("where"); }
  | BY { $$ = driver.symtab.put("by"); }
  | ORDER { $$ = driver.symtab.put("order"); }
  | STABLE { $$ = driver.symtab.put("stable"); }
  | ASCENDING { $$ = driver.symtab.put("ascending"); }
  | DESCENDING { $$ = driver.symtab.put("descending"); }
  | GREATEST { $$ = driver.symtab.put("greatest"); }
  | LEAST { $$ = driver.symtab.put("least"); }
  | COLLATION { $$ = driver.symtab.put("collation"); }
  | SOME { $$ = driver.symtab.put("some"); }
  | EVERY { $$ = driver.symtab.put("every"); }
  | SATISFIES { $$ = driver.symtab.put("satisfies"); }
  | CASE { $$ = driver.symtab.put("case"); }
  | AS { $$ = driver.symtab.put("as"); }
  | THEN { $$ = driver.symtab.put("then"); }
  | ELSE { $$ = driver.symtab.put("else"); }
  | OR { $$ = driver.symtab.put("or"); }
  | AND { $$ = driver.symtab.put("and"); }
  | INSTANCE { $$ = driver.symtab.put("instance"); }
  | OF { $$ = driver.symtab.put("of"); }
  | CASTABLE { $$ = driver.symtab.put("castable"); }
  | TO { $$ = driver.symtab.put("to"); }
  | DIV { $$ = driver.symtab.put("div"); }
  | MOD { $$ = driver.symtab.put("mod"); }
  | UNION { $$ = driver.symtab.put("union"); }
  | INTERSECT { $$ = driver.symtab.put("intersect"); }
  | EXCEPT { $$ = driver.symtab.put("except"); }
  | VALIDATE { $$ = driver.symtab.put("validate"); }
  | CAST { $$ = driver.symtab.put("cast"); }
  | TREAT { $$ = driver.symtab.put("treat"); }
  | IS { $$ = driver.symtab.put("is"); }
  | PRESERVE { $$ = driver.symtab.put("preserve"); }
  | STRIP { $$ = driver.symtab.put("strip"); }
  | NAMESPACE { $$ = driver.symtab.put("namespace"); }
  | EXTERNAL { $$ = driver.symtab.put("external"); }
  | ENCODING { $$ = driver.symtab.put("encoding"); }
  | NO_PRESERVE { $$ = driver.symtab.put("no-preserve"); }
  | INHERIT { $$ = driver.symtab.put("inherit"); }
  | NO_INHERIT { $$ = driver.symtab.put("no-inherit"); }
  | DECLARE { $$ = driver.symtab.put("declare"); }
  | CONSTRUCTION { $$ = driver.symtab.put("construction"); }
  | ORDERING { $$ = driver.symtab.put("ordering"); }
  | DEFAULT { $$ = driver.symtab.put("default"); }
  | COPY_NAMESPACES { $$ = driver.symtab.put("copy-namespaces"); }
  | OPTION { $$ = driver.symtab.put("option"); }
  | VERSION { $$ = driver.symtab.put("version"); }
  | IMPORT { $$ = driver.symtab.put("import"); }
  | SCHEMA { $$ = driver.symtab.put("schema"); }
  | FUNCTION { $$ = driver.symtab.put("function"); }
  | SCORE { $$ = driver.symtab.put("score"); }
  | FTCONTAINS { $$ = driver.symtab.put("ftcontains"); }
  | WEIGHT { $$ = driver.symtab.put("weight"); }
  | WINDOW { $$ = driver.symtab.put("window"); }
  | DISTANCE { $$ = driver.symtab.put("distance"); }
  | OCCURS { $$ = driver.symtab.put("occurs"); }
  | TIMES { $$ = driver.symtab.put("times"); }
  | SAME { $$ = driver.symtab.put("same"); }
  | DIFFERENT { $$ = driver.symtab.put("different"); }
  | LOWERCASE { $$ = driver.symtab.put("lowercase"); }
  | UPPERCASE { $$ = driver.symtab.put("uppercase"); }
  | RELATIONSHIP { $$ = driver.symtab.put("relationship"); }
  | LEVELS { $$ = driver.symtab.put("levels"); }
  | LANGUAGE { $$ = driver.symtab.put("language"); }
  | ANY { $$ = driver.symtab.put("any"); }
  | ALL { $$ = driver.symtab.put("all"); }
  | PHRASE { $$ = driver.symtab.put("phrase"); }
  | EXACTLY { $$ = driver.symtab.put("exactly"); }
  | FROM { $$ = driver.symtab.put("from"); }
  | WORDS { $$ = driver.symtab.put("words"); }
  | SENTENCES { $$ = driver.symtab.put("sentences"); }
  | SENTENCE { $$ = driver.symtab.put("sentence"); }
  | PARAGRAPH { $$ = driver.symtab.put("paragraph"); }
  | REPLACE { $$ = driver.symtab.put("replace"); }
  | MODIFY { $$ = driver.symtab.put("modify"); }
  | FIRST { $$ = driver.symtab.put("first"); }
  | INSERT { $$ = driver.symtab.put("insert"); }
  | BEFORE { $$ = driver.symtab.put("bofer"); }
  | AFTER { $$ = driver.symtab.put("after"); }
  | REVALIDATION { $$ = driver.symtab.put("revalidation"); }
  | WITH { $$ = driver.symtab.put("with"); }
  | NODES { $$ = driver.symtab.put("nodes"); }
  | RENAME { $$ = driver.symtab.put("rename"); }
  | LAST { $$ = driver.symtab.put("last"); }
  | _DELETE { $$ = driver.symtab.put("delete"); }
  | INTO { $$ = driver.symtab.put("into"); }
  | UPDATING { $$ = driver.symtab.put("updating"); }
  | ORDERED { $$ = driver.symtab.put("ordered"); }
  | UNORDERED { $$ = driver.symtab.put("unordered"); }
    ;


/*_______________________________________________________________________
 *                                                                       *
 *  Eval productions                                                     *
 *                                                                       *
 *_______________________________________________________________________*/

EvalExpr :
    USING DOLLAR EvalVarDeclList EVAL LBRACE ExprSingle RBRACE
    {
       $$ = new EvalExpr (LOC (@$),
                          dynamic_cast<VarGetsDeclList *> ($3),
                          $6);
    }
  | EVAL LBRACE ExprSingle RBRACE
    {
      $$ = new EvalExpr (LOC (@$), new VarGetsDeclList (LOC (@$)), $3);
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
	|	FTMildnot  FTNOT _IN  FTUnaryNot
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
	| CASE SENSITIVE
		{
		}
	| CASE INSENSITIVE
		{
		}
	;


//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption :
		WITH DIACRITICS
		{
		}
	| WITHOUT   DIACRITICS
		{
		}
	| DIACRITICS SENSITIVE
		{
		}
	| DIACRITICS INSENSITIVE
		{
		}
	;


//[357] FTStemOption
//------------------
FTStemOption :
		WITH STEMMING
		{
		}
	| WITHOUT STEMMING
		{
		}
	;


//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption :
		WITH THESAURUS  FTThesaurusID
		{
		}
	|	WITH THESAURUS  DEFAULT
		{
		}
	| WITH THESAURUS  LPAR  FTThesaurusID  RPAR
		{
		}
	| WITH THESAURUS  LPAR  FTThesaurusID COMMA  FTThesaurusList  RPAR
		{
		}
	| WITH THESAURUS  LPAR  DEFAULT  RPAR
		{
		}
	| WITH THESAURUS  LPAR  DEFAULT  COMMA  FTThesaurusList  RPAR
		{
		}
	| WITHOUT THESAURUS
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
		WITH STOP WORDS  FTRefOrList
		{
		}
	|	WITH STOP WORDS  FTRefOrList  FTInclExclStringLiteralList
		{
		}
	| WITH DEFAULT STOP WORDS
		{
		}
	| WITH DEFAULT STOP WORDS  FTInclExclStringLiteralList
		{
		}
	| WITHOUT STOP WORDS
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
		WITH WILDCARDS
		{
		}
	| WITHOUT WILDCARDS
		{
		}
	;


//[365]	FTContent
//---------------
FTContent :
		AT START
		{
		}
	| AT END
		{
		}
	| ENTIRE CONTENT
		{
		}
	;


//[366]	FTAnyallOption
//--------------------
FTAnyallOption :
		ANY
		{
		}
	|	ANY WORD
		{
		}
	| ALL
		{
		}
	| ALL WORDS
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
	| AT LEAST  UnionExpr
		{
       $$ = new FTRange (LOC (@$), FTRange::at_least, $3);
		}
	| AT MOST  UnionExpr
		{
       $$ = new FTRange (LOC (@$), FTRange::at_most, $3);
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
		WITHOUT CONTENT  UnionExpr
		{
      $$ = new FTIgnoreOption (LOC (@$), static_cast<UnionExpr *> ($3));
		}
	;



%%

namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_ofor = "ofor";

}

/*
	The error member function registers the errors to the driver.
*/

void xquery_parser::error(zorba::xquery_parser::location_type const& loc, std::string const& msg)
{
  driver.set_expr (new ParseErrorNode (driver.createQueryLoc (loc), msg));
}

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
