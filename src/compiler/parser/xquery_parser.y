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
**  The parser definition file starts by asking for the C++ LALR(1)
**  skeleton, the creation of the parser header file, and specifies the
**  name of the parser class.  Because the C++ skeleton changes, it is
**  safer to require the version.
*/

%skeleton "lalr1.cc"  /*  -*- C++ -*- */
%require "2.4"
%defines
%name-prefix="zorba"
%define "parser_class_name" "xquery_parser"
%error-verbose

// Expect shift/reduce conflicts
%expect 63


%code requires {

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

#include <list>
#include <string>
#include <vector>

#include "compiler/parsetree/parsenodes.h"
#include "zorbatypes/zstring.h"

#ifdef __GNUC__
    // disable a warning in location.hh which comes with bison
    // position.hh:141: warning: suggest parentheses around && within ||
#   pragma GCC diagnostic ignored "-Wparentheses"
#endif

#include "location.hh"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

typedef std::list<zorba::zstring> string_list_t;
typedef std::pair<zorba::zstring,zorba::zstring> string_pair_t;


} // %code requires


/*
**  Because the parser uses the xquery_driver and reciprocally, both
**  cannot include the header of the other. Because the driver's header
**  needs detailed knowledge about the parser class (in particular its
**  inner types), it is the parser's header which will use a forward
**  declaration of the driver.
*/

%{

#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/xquery_driver.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_declare, *the_create;

}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;

%}

%pure-parser

/*
**  The driver is passed by reference to the parser and to the scanner.
**  This provides a simple but effective pure interface, not relying on
**  global variables.
*/
%parse-param { xquery_driver& driver }


/*
**  Request the location tracking feature, and initialize the
**  first location's file name. Afterwards new locations are computed
**  relatively to the previous locations: the file name will be
**  automatically propagated.
*/
%locations
%initial-action
{
    @$.begin.filename = @$.end.filename = &(driver.theFilename2);
};

/*
%{
static void print_token_value(FILE *, int, YYSTYPE);
#define YYPRINT(file, type, value) print_token_value(file, type, value)
%}
*/

/*
**  Semantic values cannot use real objects, but only pointers to them.
*/
%union
{
    zorba::parsenode *node;
    zorba::exprnode *expr;
    zorba::FunctionSig *fnsig;
    zorba::VarNameAndType *varnametype;
    off_t sval;
    const char *strval;
    xs_integer *ival;
    xs_double *dval;
    xs_decimal *decval;
    ZorbaParserError *err;
    string_list_t *strlist;
    string_pair_t *strpair;
    std::vector<string_pair_t> *vstrpair;
    CatchExpr::NameTestList *name_test_list;
    FTStopWordOption::incl_excl_list_t *incl_excl_list;
    FTSelection::pos_filter_list_t *pos_filter_list;
    FTThesaurusOption::thesaurus_id_list_t *thesaurus_id_list;
    ft_anyall_mode::type ft_anyall_value;
};


/*
**  The token numbered as 0 corresponds to end of file; the following line
**  allows for nicer error messages referring to end of file instead of
**  $end. Similarly user friendly names are provided for each symbol.
*/

%token _EOF   0                             "'end of file'"

%token <err>  UNRECOGNIZED                  "'unrecognized'"

%type <node>  ERROR                         "'error'"

/* constant string tokens */
%type <strval> WindowType
%type <strval> FLWORWinCondType

/* tokens that contain embedded string literals */
/* -------------------------------------------- */
%token <sval> APOS_ATTR_CONTENT             "'apos attribute content'"
%token <sval> CHAR_LITERAL                  "'char literal'"
%token <sval> CHAR_LITERAL_AND_CDATA_END    "'char literal]]>'"
%token <sval> CHAR_LITERAL_AND_PI_END       "'char literal and pi end'"
%token <sval> CHAR_REF_LITERAL              "'&#charref;'"
%token <sval> ELEMENT_CONTENT               "'element content'"
%token <sval> ELEM_WILDCARD                 "'pref:*'"
%token <sval> ELEM_EQNAME_WILDCARD          "'ns:*'"
%token <sval> ENTITY_REF                    "'&entity;'"
%token <sval> EXPR_COMMENT_LITERAL          "'comment literal'"

%token <sval> PI_NCNAME_LBRACE              "'pi <NCName {>'"
%token <sval> NCNAME_SVAL                   "'NCName_sval'"
%token <sval> PRAGMA_LITERAL_AND_END_PRAGMA "'pragma literal'"
%token <sval> QNAME_SVAL_AND_END_PRAGMA     "'QName #)'"
%token <sval> EQNAME_SVAL_AND_END_PRAGMA     "'EQName #)'"
%token <sval> PREFIX_WILDCARD               "'*:QName'"
%token <sval> COMP_ELEMENT_QNAME_LBRACE     "'element QName {'"
%token <sval> COMP_ATTRIBUTE_QNAME_LBRACE   "'attribute QName {'"
%token <sval> COMP_PI_NCNAME_LBRACE         "'processing-instruction NCName {'"
%token <sval> QNAME_SVAL                    "'QName'"
%token <sval> EQNAME_SVAL                   "'EQName'"
%token <sval> ANNOTATION_QNAME_SVAL         "'%QName'"
%token <sval> ANNOTATION_EQNAME_SVAL        "'%EQName'"

%token <sval> QUOTE_ATTR_CONTENT            "'quote attribute content'"
%token <sval> STRING_LITERAL                "'STRING'"
%token <sval> XML_COMMENT_LITERAL           "'XML comment'"

%type <sval> URI_LITERAL                    "'URI'"
%type <sval> NCNAME                         "'NCName'"

%token <sval> DECLARE                       "'declare'"
%token <sval> MODULE                        "'module'"

%type <strval> DecimalFormatParamName
%type <node> DecimalFormatDecl
%type <strpair> DecimalFormatParam
%type <vstrpair> DecimalFormatParamList
%type <name_test_list> NameTestList


/* simple tokens */
/* ------------- */

%token BLANK                            "'<blank>'"

%token ALLOWING                         "'allowing'"
%token BASE_URI                         "'base-uri'"
%token BOUNDARY_SPACE                   "'boundary-space'"
%token COMMENT                          "'comment'"
%token CONSTRUCTION                     "'construction'"
%token COPY_NAMESPACES                  "'copy-namespaces'"
%token COUNT                            "'count'"
%token DOCUMENT                         "'document'"
%token DOCUMENT_NODE                    "'document-node'"
%token ELEMENT                          "'element'"
%token FOR                              "'for'"
%token FUNCTION                         "'function'"
%token IF                               "'if'"
%token IMPORT                           "'import'"
%token INSTANCE                         "'instance'"
%token LET                              "'let'"
%token MOST                             "'most'"
%token NEXT                             "'next'"
%token NO                               "'no'"
%token ONLY                             "'only'"
%token OPTION                           "'option'"
%token ORDERING                         "'ordering'"
%token PREVIOUS                         "'previous'"
%token PROCESSING_INSTRUCTION           "'processing-instruction'"
%token SCHEMA                           "'schema'"
%token SCHEMA_ATTRIBUTE                 "'schema-attribute'"
%token SCHEMA_ELEMENT                   "'schema-element'"
%token SEQUENTIAL                       "'sequential'"
%token SET                              "'set'"
%token SIMPLE                           "'simple'"
%token SLIDING                          "'sliding'"
%token SOME                             "'some'"
%token SPACE                            "'space'"
%token STABLE                           "'stable'"
%token TEXT                             "'text'"
%token TUMBLING                         "'tumbling'"
%token SWITCH                           "'switch'"
%token TYPESWITCH                       "'typeswitch'"
%token UPDATING                         "'updating'"
%token VALIDATE                         "'validate'"
%token TYPE                             "'type'"
%token WHEN                             "'when'"
%token WORD                             "'word'"

    /* Decimal format tokens */
%token DECIMAL_FORMAT                   "'decimal-format'"
%token DECIMAL_SEPARATOR                "'decimal-separator'"
%token GROUPING_SEPARATOR               "'grouping-separator'"
%token INFINITY_VALUE                   "'infinity'"
%token MINUS_SIGN                       "'minus-sign'"
%token NaN                              "'NaN'"
%token PERCENT                          "'percent'"
%token PER_MILLE                        "'per-mille'"
%token ZERO_DIGIT                       "'zero-digit'"
%token DIGIT                            "'digit'"
%token PATTERN_SEPARATOR                "'pattern-separator'"

%token ANCESTOR                         "'ancestor'"
%token ANCESTOR_OR_SELF                 "'ancestor-or-self'"
%token AND                              "'and'"
%token APOS                             "'''"
%token AS                               "'as'"
%token ASCENDING                        "'ascending'"
%token AT                               "'at'"
%token ATTRIBUTE                        "'attribute'"
%token AT_SIGN                          "'@'"
%token CONCAT                           "'||'"
%token CASE                             "'case'"
%token CASTABLE                         "'castable'"
%token CAST                             "'cast'"
%token CDATA_BEGIN                      "'CDATA[['"
%token CDATA_END                        "']]'"
%token CHILD                            "'child'"
%token COLLATION                        "'collation'"
%token COMMA                            "','"
%token COMMENT_BEGIN                    "'(:'"
%token COMMENT_END                      "':)'"
%token <decval> DECIMAL_LITERAL         "'DECIMAL'"
%token CONTEXT                          "'context'"
%token VARIABLE                         "'variable'"
%token DEFAULT                          "'default'"
%token DESCENDANT                       "'descendant'"
%token DESCENDANT_OR_SELF               "'descendant-or-self'"
%token DESCENDING                       "'descending'"
%token DIV                              "'div'"
%token DOLLAR                           "'$'"
%token DOT                              "'.'"
%token DOT_DOT                          "'..'"
%token COLON                            "':'"
%token DOUBLE_COLON                     "'::'"
%token DOUBLE_LBRACE                    "'{{'"
%token <dval> DOUBLE_LITERAL            "'DOUBLE'"
%token DOUBLE_RBRACE                    "'<double {>'"
%token ELSE                             "'else'"
%token _EMPTY                           "'empty'"
%token GREATEST                         "'greatest'"
%token LEAST                            "'least'"
%token EMPTY_TAG_END                    "'/>'"
%token ENCODING                         "'encoding'"
%token EQUALS                           "'='"
%token ESCAPE_APOS                      "''''"
%token ESCAPE_QUOTE                     "'\"\"'"
%token EVERY                            "'every'"
%token EXCEPT                           "'except'"
%token EXTERNAL                         "'external'"
%token FOLLOWING                        "'following'"
%token FOLLOWING_SIBLING                "'following-sibling'"
%token FOLLOWS                          "'follows'"
%token GE                               "'>='"
%token GETS                             "':='"
%token GT                               "'>'"
%token HOOK                             "'?'"
%token HASH                             "'#'"
%token IDIV                             "'idiv'"
%token _IN                              "'in'"
%token INHERIT                          "'inherit'"
%token <ival> INTEGER_LITERAL           "'INTEGER'"
%token INTERSECT                        "'intersect'"
%token IS                               "'is'"
%token ITEM                             "'item'"
%token LBRACE                           "'{'"
%token LBRACK                           "'['"
%token LE                               "'<='"
%token LPAR                             "'('"
%token LT_OR_START_TAG                  "'<'"
%token MINUS                            "'-'"
%token MOD                              "'mod'"
%token NAMESPACE                        "'namespace'"
%token _NAN                             "'nan'"
%token NE                               "'!='"
%token NODECOMP                         "'nodecomp'"
%token NOT_OPERATOR_KEYWORD             "'??'"
%token NO_INHERIT                       "'<no inherit>'"
%token NO_PRESERVE                      "'<no preserve>'"
%token OR                               "'or'"
%token ORDER                            "'order'"
%token ORDERED                          "'ordered'"
%token BY                               "'by'"
%token GROUP                            "'group'"
%token PARENT                           "'parent'"
%token PERCENTAGE                       "'%'"
%token PI_BEGIN                         "'<?'"
%token PI_END                           "'?>'"
%token PLUS                             "'+'"
%token PRAGMA_BEGIN                     "'(#'"
%token PRAGMA_END                       "'#)'"
%token PRECEDES                         "'<<'"
%token PRECEDING                        "'preceding'"
%token PRECEDING_SIBLING                "'preceding-sibling'"
%token PRESERVE                         "'preserve'"
%token QUOTE                            "'\"'"
%token RBRACE                           "'}'"
%token RBRACK                           "']'"
%token RETURN                           "'return'"
%token RPAR                             "')'"
%token SATISFIES                        "'satisfies'"
%token SELF                             "'self'"
%token SEMI                             "';'"
%token SLASH                            "'/'"
%token SLASH_SLASH                      "'//'"
%token STAR                             "'*'"
%token START_TAG_END                    "'</ (start tag end)'"
%token STRIP                            "'strip'"
%token TAG_END                          "'> (tag end)'"
%token THEN                             "'then'"
%token TO                               "'to'"
%token TREAT                            "'treat'"
%token UNION                            "'union'"
%token UNORDERED                        "'unordered'"
%token VAL_EQ                           "'eq'"
%token VAL_GE                           "'ge'"
%token VAL_GT                           "'gt'"
%token VAL_LE                           "'le'"
%token VAL_LT                           "'lt'"
%token VAL_NE                           "'ne'"
%token VALUECOMP                        "'VALUECOMP'"
%token VBAR                             "'|'"
%token EMPTY_SEQUENCE                   "'empty-sequence'"
%token WHERE                            "'where'"
%token XML_COMMENT_BEGIN                "'<!--'"
%token XML_COMMENT_END                  "'-->'"
%token XQUERY                           "'xquery'"
%token VERSION                          "'version'"
%token START                            "'start'"

/* update-related */
/* -------------- */
%token AFTER                            "'after'"
%token BEFORE                           "'before'"
%token REVALIDATION                     "'revalidation'"
%token _STRICT                          "'strict'"
%token LAX                              "'lax'"
%token SKIP                             "'skip'"
%token _DELETE                          "'delete'"
%token NODE                             "'node'"
%token INSERT                           "'insert'"
%token NODES                            "'nodes'"
%token RENAME                           "'rename'"
%token REPLACE                          "'replace'"
%token VALUE                            "'value'"
%token OF                               "'of'"
%token FIRST                            "'first'"
%token INTO                             "'into'"
%token LAST                             "'last'"
%token MODIFY                           "'modify'"
%token COPY                             "'copy'"
%token WITH                             "'with'"

/* scripting-related */
/* ----------------- */
%token BREAK                            "'break'"
%token CONTINUE                         "'continue'"
%token EXIT                             "'exit'"
%token LOOP                             "'loop'"
%token RETURNING                        "'returning'"
%token WHILE                            "'while'"

/* try-catch-related */
/* ----------------- */
%token TRY                              "'try'"
%token CATCH                            "'catch'"

/* eval-related */
/* ------------ */
%token USING                            "'using'"

/* full-text-related */
/* ----------------- */
%token ALL                              "'all'"
%token ANY                              "'any'"
%token CONTAINS                         "'contains'"
%token CONTENT                          "'content'"
%token DIACRITICS                       "'diacritics'"
%token DIFFERENT                        "'different'"
%token DISTANCE                         "'distance'"
%token END                              "'end'"
%token ENTIRE                           "'entire'"
%token EXACTLY                          "'exactly'"
%token FROM                             "'from'"
%token FTAND                            "'ftand'"
%token FTNOT                            "'ftnot'"
%token NOT                              "'not'"
%token FT_OPTION                        "'ft-option'"
%token FTOR                             "'ftor'"
%token INSENSITIVE                      "'insensitive'"
%token LANGUAGE                         "'language'"
%token LEVELS                           "'levels'"
%token LOWERCASE                        "'lowercase'"
%token OCCURS                           "'occurs'"
%token PARAGRAPH                        "'paragraph'"
%token PARAGRAPHS                       "'paragraphs'"
%token PHRASE                           "'phrase'"
%token RELATIONSHIP                     "'relationship'"
%token SAME                             "'same'"
%token SCORE                            "'score'"
%token SENSITIVE                        "'sensitive'"
%token SENTENCE                         "'sentence'"
%token SENTENCES                        "'sentences'"
%token STEMMING                         "'stemming'"
%token STOP                             "'stop'"
%token THESAURUS                        "'thesaurus'"
%token TIMES                            "'times'"
%token UPPERCASE                        "'uppercase'"
%token WEIGHT                           "'weight'"
%token WILDCARDS                        "'wildcards'"
%token WINDOW                           "'window'"
%token WITHOUT                          "'without'"
%token WORDS                            "'words'"

/* Data Definition Facility */

%token COLLECTION                       "'collection'"
%token CONSTOPT                         "'const'"
%token APPEND_ONLY                      "'append-only'"
%token QUEUE                            "'queue'"
%token MUTABLE                          "'mutable'"
%token READ_ONLY                        "'read-only'"

%token UNIQUE                           "'unique'"
%token NON                              "'non'"
%token INDEX                            "'index'"
%token MANUALLY                         "'manually'"
%token AUTOMATICALLY                    "'automatically'"
%token MAINTAINED                       "'maintained'"
%token ON                               "'on'"
%token RANGE                            "'range'"
%token EQUALITY                         "'equality'"
%token GENERAL                          "'general'"

%token INTEGRITY                        "'integrity'"
%token CONSTRAINT                       "'constraint'"
%token CHECK                            "'check'"
%token KEY                              "'key'"
%token FOREACH                          "'foreach'"
%token FOREIGN                          "'foreign'"
%token KEYS                             "'keys'"


/* Byte Order Marks                  */
/* --------------------------------- */
%token BYTE_ORDER_MARK_UTF8             "'BOM_UTF8'"

/* Leading slash handling expression */
/* --------------------------------- */
%type <expr> LeadingSlash

/* placeholder node for reducing UNRECOGNIZED and generating an error */
/* ---------------------------- */
// %type <node> UnrecognizedToken


/* left-hand sides: syntax only */
/* ---------------------------- */

%type <node> AbbrevForwardStep
%type <node> AnyKindTest
%type <node> Annotation
%type <node> AnnotationList
%type <node> AnnotationLiteralList
%type <node> AposAttrContentList
%type <node> opt_AposAttrContentList
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
%type <node> FunctionDecl2
%type <node> FunctionDeclSimple
%type <node> FunctionDeclUpdating
%type <node> Import
%type <node> ItemType
%type <node> KindTest
%type <node> LetClause
%type <node> LibraryModule
%type <node> MainModule
%type <node> Module
%type <node> ModuleWithoutBOM
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
%type <node> Pragma_list
%type <node> PredicateList
%type <node> QVarInDecl
%type <node> QVarInDeclList
%type <node> QuoteAttrValueContent
%type <node> QuoteAttrContentList
%type <node> opt_QuoteAttrContentList
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
%type <node> SwitchCaseClause
%type <node> SwitchCaseClauseList
%type <node> SwitchCaseOperandList
%type <node> CaseStatement
%type <node> CaseStatementList
%type <node> SwitchCaseStatement
%type <node> SwitchCaseStatementList
%type <node> TextTest
%type <node> TypeDeclaration
%type <node> TypeName
%type <node> TypeName_WITH_HOOK
%type <node> URILiteralList
%type <node> ValueComp
%type <node> CtxItemDecl
%type <node> CtxItemDecl2
%type <node> CtxItemDecl3
%type <node> CtxItemDecl4
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
%type <node> VersionDecl
%type <node> VFO_Decl
%type <node> VFO_DeclList
%type <node> BlockVarDecl
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
%type <expr> BracedExpr
%type <expr> BlockStatement
%type <expr> Statement
%type <expr> Statements
%type <expr> StatementsAndExpr
%type <expr> StatementsAndOptionalExpr
%type <expr> StatementsAndOptionalExprTop
%type <expr> StringConcatExpr
%type <expr> SwitchStatement
%type <expr> TypeswitchStatement
%type <expr> TryStatement
%type <expr> CatchListStatement
%type <expr> CatchStatement
%type <expr> ApplyStatement
%type <expr> IfStatement
%type <expr> FLWORStatement
%type <expr> ReturnStatement
%type <expr> VarDeclStatement
%type <expr> BlockVarDeclList
%type <expr> BlockExpr
%type <expr> EnclosedStatementsAndOptionalExpr
%type <expr> Expr
%type <expr> ExprSingle
%type <expr> ExprSimple
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
%type <expr> SwitchExpr
%type <expr> TreatExpr
%type <expr> TypeswitchExpr
%type <expr> UnaryExpr
%type <expr> UnionExpr
%type <expr> UnorderedExpr
%type <expr> ValidateExpr
%type <expr> ValueExpr
%type <expr> VarRef
%type <expr> ExitStatement
%type <expr> WhileStatement
%type <expr> AssignStatement
%type <expr> FlowCtlStatement
%type <expr> QNAME
%type <expr> EQNAME
%type <expr> FUNCTION_NAME

%type <expr> FunctionItemExpr
%type <expr> LiteralFunctionItem
%type <expr> InlineFunction
%type <node> FunctionTest
%type <node> TypedFunctionTest
%type <node> AnyFunctionTest
%type <node> TypeList
%type <node> ParenthesizedItemType

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

/* collection-reladed */
%type <node> CollectionDecl
%type <node> CollectionTypeDecl

/* index-related     */
/* ----------------- */
%type <node> IndexDecl
%type <node> IndexKeySpec
%type <node> IndexKeyList

/* integrityconstraint-related */
/* --------------------------- */
%type <node> IntegrityConstraintDecl

/* full-text-related */
/* ----------------- */
%type <node> FTAnd
%type <node> FTAnyallOption opt_FTAnyallOption
%type <ft_anyall_value> opt_word opt_words
%type <node> FTBigUnit
%type <node> FTCaseOption
%type <expr> FTContainsExpr
%type <node> FTContent
%type <node> FTDiacriticsOption
%type <node> FTDistance
%type <node> FTExtensionOption
%type <node> FTExtensionSelection
%type <node> FTIgnoreOption opt_FTIgnoreOption
%type <node> FTLanguageOption
%type <node> FTMatchOption
%type <node> FTMatchOptions opt_FTMatchOptions
%type <node> FTMildNot
%type <node> FTOptionDecl
%type <node> FTOr
%type <node> FTOrder
%type <node> FTPosFilter
%type <pos_filter_list> FTPosFilter_list opt_FTPosFilter_list
%type <node> FTPrimary
%type <node> FTPrimaryWithOptions
%type <node> FTRange
%type <node> FTScope
%type <node> FTScoreVar
%type <node> FTSelection opt_FTSelection
%type <node> FTStemOption
%type <node> FTStopWords
%type <node> FTStopWordOption
%type <node> FTStopWordsInclExcl
%type <incl_excl_list> FTStopWordsInclExcl_list opt_FTStopWordsInclExcl_list
%type <node> FTThesaurusID FTThesaurusID_or_default
%type <sval> opt_relationship
%type <node> opt_levels
%type <thesaurus_id_list> FTThesaurus_list opt_FTThesaurus_list
%type <node> FTThesaurusOption
%type <node> FTTimes opt_FTTimes
%type <node> FTUnaryNot
%type <node> FTUnit
%type <node> FTWeight opt_FTWeight
%type <node> FTWildCardOption
%type <node> FTWindow
%type <node> FTWords
%type <node> FTWordsValue

%type <fnsig> FunctionSig
%type <varnametype> VarNameAndType
%type <strlist> STRING_LITERAL_list;



/*
 *  To enable memory deallocation during error recovery, use %destructor.
 */

// Module must not be destroyed since it is returned by the parser

/*%printer    { debug_stream() << *$$; }    */
/*%printer    { debug_stream () << $$; }    */
/*%destructor { delete $$; }              */

// destructors for token values
%destructor { delete $$; } INTEGER_LITERAL
%destructor { delete $$; } DOUBLE_LITERAL
%destructor { delete $$; } DECIMAL_LITERAL

%{
// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
%}

// parsenodes
%destructor { release_hack( $$ ); } AbbrevForwardStep AnyKindTest Annotation AnnotationList AnnotationLiteralList AposAttrContentList opt_AposAttrContentList AposAttrValueContent ArgList AtomicType AttributeTest BaseURIDecl BoundarySpaceDecl CaseClause CaseClauseList CommentTest ConstructionDecl CopyNamespacesDecl DefaultCollationDecl DefaultNamespaceDecl DirAttr DirAttributeList DirAttributeValue DirElemContentList DocumentTest ElementTest EmptyOrderDecl WindowClause ForClause ForLetWinClause FLWORClauseList ForwardAxis ForwardStep FunctionDecl FunctionDecl2 FunctionDeclSimple FunctionDeclUpdating Import ItemType KindTest LetClause LibraryModule MainModule /* Module */ ModuleDecl ModuleImport NameTest NamespaceDecl NodeComp NodeTest OccurrenceIndicator OptionDecl GroupByClause GroupSpecList GroupSpec GroupCollationSpec OrderByClause OrderCollationSpec OrderDirSpec OrderEmptySpec OrderModifier OrderSpec OrderSpecList OrderingModeDecl PITest Param ParamList PositionalVar Pragma Pragma_list PredicateList QVarInDecl QVarInDeclList QuoteAttrValueContent QuoteAttrContentList opt_QuoteAttrContentList ReverseAxis ReverseStep SIND_Decl SIND_DeclList SchemaAttributeTest SchemaElementTest SchemaImport SchemaPrefix SequenceType Setter SignList SingleType TextTest TypeDeclaration TypeName TypeName_WITH_HOOK URILiteralList ValueComp CollectionDecl IndexDecl IndexKeySpec IndexKeyList IntegrityConstraintDecl CtxItemDecl CtxItemDecl2 CtxItemDecl3 CtxItemDecl4 VarDecl VarGetsDecl VarGetsDeclList VarInDecl VarInDeclList WindowVarDecl WindowVars WindowVars2 WindowVars3 FLWORWinCond VersionDecl VFO_Decl VFO_DeclList WhereClause CountClause Wildcard DecimalFormatDecl TypedFunctionTest AnyFunctionTest TypeList SwitchCaseClause SwitchCaseClauseList SwitchCaseOperandList

// parsenodes: Full-Text
%destructor { release_hack( $$ ); } FTAnd FTAnyallOption FTBigUnit FTCaseOption FTContent FTDiacriticsOption FTDistance FTExtensionOption FTExtensionSelection FTIgnoreOption opt_FTIgnoreOption FTLanguageOption FTMatchOption FTMatchOptions opt_FTMatchOptions FTMildNot FTOptionDecl FTOr FTOrder FTPosFilter FTPrimary FTPrimaryWithOptions FTRange FTScope FTScoreVar FTSelection FTStemOption FTStopWords FTStopWordOption FTStopWordsInclExcl FTThesaurusID FTThesaurusOption FTTimes opt_FTTimes FTUnaryNot FTUnit FTWeight FTWildCardOption FTWindow FTWords FTWordsValue

// exprnodes
%destructor { release_hack( $$ ); } AdditiveExpr AndExpr AxisStep CDataSection CastExpr CastableExpr CommonContent ComparisonExpr CompAttrConstructor CompCommentConstructor CompDocConstructor CompElemConstructor CompPIConstructor CompTextConstructor ComputedConstructor Constructor ContextItemExpr DirCommentConstructor DirElemConstructor DirElemContent DirPIConstructor DirectConstructor BracedExpr BlockExpr EnclosedStatementsAndOptionalExpr BlockStatement Statement Statements StatementsAndExpr StatementsAndOptionalExpr StatementsAndOptionalExprTop SwitchStatement TypeswitchStatement TryStatement CatchListStatement CatchStatement ApplyStatement IfStatement FLWORStatement ReturnStatement VarDeclStatement Expr ExprSingle ExprSimple ExtensionExpr FLWORExpr ReturnExpr FilterExpr FunctionCall IfExpr InstanceofExpr IntersectExceptExpr Literal MultiplicativeExpr NumericLiteral OrExpr OrderedExpr ParenthesizedExpr PathExpr Predicate PrimaryExpr QuantifiedExpr QueryBody RangeExpr RelativePathExpr StepExpr StringLiteral TreatExpr StringConcatExpr SwitchExpr TypeswitchExpr UnaryExpr UnionExpr UnorderedExpr ValidateExpr ValueExpr VarRef TryExpr CatchListExpr CatchExpr DeleteExpr InsertExpr RenameExpr ReplaceExpr TransformExpr VarNameList VarNameDecl AssignStatement ExitStatement WhileStatement FlowCtlStatement QNAME EQNAME FUNCTION_NAME FTContainsExpr

// internal non-terminals with values
%destructor { delete $$; } FunctionSig VarNameAndType NameTestList DecimalFormatParam DecimalFormatParamList

/*_____________________________________________________________________
 *
 *  Precedence
 *_____________________________________________________________________*/

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
**  The code between `%{' and `%}' after the introduction of the `%union'
**  is output in the *.cc file; it needs detailed knowledge about the
**  driver.
*/
%{
#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex

%}

/*
    The grammar
*/

%%
%start Module;

Module :
      ModuleWithoutBOM
  |   BYTE_ORDER_MARK_UTF8  ModuleWithoutBOM
      {
        $$ = $2;
      }
;

ERROR :
      // Special rule to get Bison out of some infinte loops. This can happen when the lexer
      // throws an error and Bison finds an error too.
      error UNRECOGNIZED
      {
        $$ = NULL; YYABORT;
      }
;


// [1]
ModuleWithoutBOM :
    MainModule
    {
      $$ = $1;
      driver.set_expr( $$ );
    }
  |
    VersionDecl MainModule
    {
      MainModule* mm = dynamic_cast<MainModule*>($2);
      mm->set_version_decl( static_cast<VersionDecl*>($1) );
      $$ = $2;
      driver.set_expr( $$ );
    }
  |
    LibraryModule
    {
      $$ = $1;
      driver.set_expr( $$ );
    }
  |
    VersionDecl LibraryModule
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>($2);
      lm->set_version_decl( static_cast<VersionDecl*>($1) );
      $$ = $2;
      driver.set_expr( $$ );
    }
;


VersionDecl :
    XQUERY VERSION STRING_LITERAL SEMI
    {
      $$ = new VersionDecl( LOC(@$), SYMTAB($3), "utf-8" );
    }
  |
    XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
    {
      $$ = new VersionDecl( LOC(@$), SYMTAB($3), SYMTAB($5) );
    }
;


MainModule :
    SIND_DeclList SEMI QueryBody
    {
      Prolog* prolog = new Prolog(LOC(@$), static_cast<SIND_DeclList*>($1), NULL);

      $$ = new MainModule(LOC(@$), static_cast<QueryBody*>($3), prolog);
    }
  |
    VFO_DeclList SEMI QueryBody
    {
      Prolog* prolog = new Prolog(LOC(@$), NULL, static_cast<VFO_DeclList*>($1));

      $$ = new MainModule(LOC(@$), static_cast<QueryBody*>($3), prolog);
    }
  |
    SIND_DeclList SEMI VFO_DeclList SEMI QueryBody
    {
      Prolog* prolog = new Prolog(LOC(@$),
                                  static_cast<SIND_DeclList*>($1),
                                  static_cast<VFO_DeclList*>($3));

      $$ = new MainModule(LOC(@$), static_cast<QueryBody*>($5), prolog);
    }
  |
    QueryBody
    {
      $$ = new MainModule( LOC(@$), static_cast<QueryBody*>($1), NULL );
    }

  //  ============================ Improved error messages ============================
  |
    SIND_DeclList ERROR QueryBody
    {
      $$ = $1; $$ = $3; // to prevent the Bison warning
      @1.step();
      error(@1, "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
  |
    VFO_DeclList ERROR QueryBody
    {
      $$ = $1; $$ = $3; // to prevent the Bison warning
      @1.step();
      error(@1, "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
  |
    SIND_DeclList SEMI VFO_DeclList ERROR QueryBody
    {
      $$ = $1; $$ = $3; $$ = $5; // to prevent the Bison warning
      @3.step();
      error(@3, "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
  |
    SIND_DeclList ERROR VFO_DeclList SEMI QueryBody
    {
      $$ = $1; $$ = $3; $$ = $5; // to prevent the Bison warning
      @1.step();
      error(@1, "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
;


LibraryModule :
    ModuleDecl
    {
      $$ = new LibraryModule(LOC(@$), static_cast<ModuleDecl*>($1), NULL);
    }
  |
    ModuleDecl SIND_DeclList SEMI
    {
      Prolog* prolog = new Prolog(LOC(@$), static_cast<SIND_DeclList*>($2), NULL);

      $$ = new LibraryModule(LOC(@$), static_cast<ModuleDecl*>($1), prolog);
    }
  |
    ModuleDecl VFO_DeclList SEMI
    {
      Prolog* prolog = new Prolog(LOC(@$), NULL, static_cast<VFO_DeclList*>($2));

      $$ = new LibraryModule(LOC(@$), static_cast<ModuleDecl*>($1), prolog);
    }
  |
    ModuleDecl SIND_DeclList SEMI VFO_DeclList SEMI
    {
      Prolog* prolog = new Prolog(LOC(@$),
                                  static_cast<SIND_DeclList*>($2),
                                  static_cast<VFO_DeclList*>($4));

      $$ = new LibraryModule(LOC(@$), static_cast<ModuleDecl*>($1), prolog);
    }
;


ModuleDecl :
    MODULE NAMESPACE NCNAME EQUALS URI_LITERAL SEMI
    {
      $$ = new ModuleDecl( LOC(@$), SYMTAB($3), SYMTAB($5) );

      dynamic_cast<ModuleDecl*>($$)->setComment( SYMTAB($1) );
    }
;


SIND_DeclList :
    SIND_Decl
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC(@$) );
      sdl->push_back( $1 );
      $$ = sdl;
    }
  |
    SIND_DeclList SEMI SIND_Decl
    {
      ((SIND_DeclList*)$1)->push_back( $3 );
      $$ = $1;
    }
  //  ============================ Improved error messages ============================
  |
    SIND_DeclList ERROR SIND_Decl
    {
      // error
      $$ = $1; $$ = $3; // to prevent the Bison warning
      @1.step();
      error(@1, "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
;


SIND_Decl :
    Setter
  | Import
  | NamespaceDecl
  | DefaultNamespaceDecl
  | FTOptionDecl
;


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


BoundarySpaceDecl :
    DECLARE BOUNDARY_SPACE PRESERVE
    {
      $$ = new BoundarySpaceDecl(LOC(@$), StaticContextConsts::preserve_space);
    }
  |
    DECLARE BOUNDARY_SPACE STRIP
    {
      $$ = new BoundarySpaceDecl(LOC(@$), StaticContextConsts::strip_space);
    }
;


DefaultCollationDecl :
    DECLARE DEFAULT COLLATION URI_LITERAL
    {
      $$ = new DefaultCollationDecl( LOC(@$), SYMTAB($4) );
    }
;


BaseURIDecl :
    DECLARE BASE_URI URI_LITERAL
    {
      $$ = new BaseURIDecl( LOC(@$), SYMTAB($3) );
    }
;


ConstructionDecl :
    DECLARE CONSTRUCTION PRESERVE
    {
      $$ = new ConstructionDecl(LOC(@$), StaticContextConsts::cons_preserve);
    }
  |
    DECLARE CONSTRUCTION STRIP
    {
      $$ = new ConstructionDecl(LOC(@$), StaticContextConsts::cons_strip);
    }
;


OrderingModeDecl :
    DECLARE ORDERING ORDERED
    {
      $$ = new OrderingModeDecl(LOC(@$), StaticContextConsts::ordered);
    }
  |
    DECLARE ORDERING UNORDERED
    {
      $$ = new OrderingModeDecl(LOC(@$), StaticContextConsts::unordered);
    }
;


EmptyOrderDecl :
    DECLARE DEFAULT ORDER _EMPTY GREATEST
    {
      $$ = new EmptyOrderDecl(LOC(@$), StaticContextConsts::empty_greatest);
    }
  |
    DECLARE DEFAULT ORDER _EMPTY LEAST
    {
      $$ = new EmptyOrderDecl(LOC(@$), StaticContextConsts::empty_least);
    }
;


CopyNamespacesDecl :
    DECLARE COPY_NAMESPACES  PRESERVE  COMMA  INHERIT
    {
      $$ = new CopyNamespacesDecl(LOC(@$),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
  |
    DECLARE COPY_NAMESPACES  PRESERVE  COMMA  NO_INHERIT
    {
      $$ = new CopyNamespacesDecl(LOC(@$),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
  |
    DECLARE COPY_NAMESPACES  NO_PRESERVE  COMMA  INHERIT
    {
      $$ = new CopyNamespacesDecl(LOC(@$),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
  |
    DECLARE COPY_NAMESPACES  NO_PRESERVE  COMMA  NO_INHERIT
    {
      $$ = new CopyNamespacesDecl(LOC(@$),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
;


Import :
    SchemaImport
  |
    ModuleImport
    //  ============================ Improved error messages ============================
  |
    IMPORT QNAME_SVAL error
    {
      $$ = $$; // to prevent the Bison warning
      error(@2, "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
;


SchemaImport :
    IMPORT SCHEMA URI_LITERAL
    {
      $$ = new SchemaImport( LOC(@$), NULL, SYMTAB($3), NULL );
    }
  |
    IMPORT SCHEMA SchemaPrefix URI_LITERAL
    {
      $$ = new SchemaImport(LOC(@$),
                            dynamic_cast<SchemaPrefix*>($3),
                            SYMTAB($4),
                            NULL);
    }
  |
    IMPORT SCHEMA URI_LITERAL AT URILiteralList
    {
      $$ = new SchemaImport(LOC(@$),
                            NULL,
                            SYMTAB($3),
                            dynamic_cast<URILiteralList*>($5));
    }
  |
    IMPORT SCHEMA SchemaPrefix URI_LITERAL AT URILiteralList
    {
      $$ = new SchemaImport(LOC(@$),
                            dynamic_cast<SchemaPrefix*>($3),
                            SYMTAB($4),
                            dynamic_cast<URILiteralList*>($6));
    }
;


URILiteralList :
    URI_LITERAL
    {
      URILiteralList *ull = new URILiteralList( LOC(@$));
      ull->push_back( SYMTAB($1) );
      $$ = ull;
    }
  |
    URILiteralList COMMA URI_LITERAL
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>($1) )
        ull->push_back( SYMTAB($3) );

      $$ = $1;
    }
;


SchemaPrefix :
    NAMESPACE NCNAME EQUALS
    {
      $$ = new SchemaPrefix( LOC(@$), SYMTAB($2) );
    }
  |
    DEFAULT ELEMENT NAMESPACE
    {
      $$ = new SchemaPrefix( LOC(@$), true );
    }
;


ModuleImport :
    IMPORT MODULE URI_LITERAL
    {
      $$ = new ModuleImport(LOC(@$), SYMTAB($3), NULL);

      dynamic_cast<ModuleImport *>($$)->setComment(SYMTAB($2));
    }
  |
    IMPORT MODULE NAMESPACE  NCNAME  EQUALS  URI_LITERAL
    {
      $$ = new ModuleImport(LOC(@$), SYMTAB($4), SYMTAB($6), NULL);

      dynamic_cast<ModuleImport *>($$)->setComment(SYMTAB($2));
    }
  |
    IMPORT MODULE URI_LITERAL AT URILiteralList
    {
      $$ = new ModuleImport(LOC(@$),
                            SYMTAB($3),
                            dynamic_cast<URILiteralList*>($5));

      dynamic_cast<ModuleImport *>($$)->setComment(SYMTAB($2));
    }
  |
    IMPORT MODULE NAMESPACE  NCNAME  EQUALS  URI_LITERAL  AT  URILiteralList
    {
      $$ = new ModuleImport(LOC(@$),
                            SYMTAB($4),
                            SYMTAB($6),
                            dynamic_cast<URILiteralList*>($8));

      dynamic_cast<ModuleImport *>($$)->setComment(SYMTAB($2));
    }
;


NamespaceDecl :
    DECLARE NAMESPACE NCNAME EQUALS URI_LITERAL
    {
      $$ = new NamespaceDecl( LOC(@$), SYMTAB($3), SYMTAB($5) );
    }
;


DefaultNamespaceDecl :
    DECLARE DEFAULT ELEMENT NAMESPACE URI_LITERAL
    {
      $$ = new DefaultNamespaceDecl(LOC(@$),
                                    ParseConstants::ns_element_default,
                                    SYMTAB($5));
    }
  |
    DECLARE DEFAULT FUNCTION NAMESPACE URI_LITERAL
    {
      $$ = new DefaultNamespaceDecl(LOC(@$),
                                    ParseConstants::ns_function_default,
                                    SYMTAB($5));
    }
;


VFO_DeclList :
    VFO_Decl
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC(@$));
      vdl->push_back( $1 );
      $$ = vdl;
    }
  |
    VFO_DeclList SEMI VFO_Decl
    {
      ((VFO_DeclList*)$1)->push_back( $3 );
      $$ = $1;
    }
//  ============================ Improved error messages ============================
  |
    VFO_DeclList ERROR VFO_Decl    //error catching
    {
      $$ = $1; $$ = $3; // to prevent the Bison warning
      @1.step();
      error(@1, "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
;


VFO_Decl :
    DecimalFormatDecl
  | OptionDecl
  | CtxItemDecl
  | VarDecl
  | FunctionDecl
  | CollectionDecl
  | IndexDecl
  | IntegrityConstraintDecl
;


DecimalFormatDecl :
    DECLARE  DEFAULT  DECIMAL_FORMAT  DecimalFormatParamList
    {
      $$ = new DecimalFormatNode(LOC(@$), $4);
      delete $4;
    }
  |
    DECLARE  DECIMAL_FORMAT  QNAME  DecimalFormatParamList
    {
      $$ = new DecimalFormatNode(LOC(@$), static_cast<QName*>($3), $4);
      delete $4;
    }
;


DecimalFormatParamList :
    DecimalFormatParam
    {
      $$ = new vector<string_pair_t>();
      $$->push_back( *$1 );
      delete $1;
    }
  |
    DecimalFormatParamList DecimalFormatParam
    {
      $1->push_back( *$2 );
      delete $2;
      $$ = $1;
    }
;


DecimalFormatParam :
    DecimalFormatParamName EQUALS StringLiteral
    {
      StringLiteral *sl = static_cast<StringLiteral*>($3);
      $$ = new string_pair_t( $1, sl->get_strval().str() );
      delete sl;
    }
;


DecimalFormatParamName :
      DECIMAL_SEPARATOR   { $$ = "decimal-separator"; }
    | DIGIT               { $$ = "digit"; }
    | GROUPING_SEPARATOR  { $$ = "grouping-separator"; }
    | INFINITY_VALUE      { $$ = "infinty"; }
    | MINUS_SIGN          { $$ = "minus-sign"; }
    | NaN                 { $$ = "NaN"; }
    | PATTERN_SEPARATOR   { $$ = "pattern-separator"; }
    | PERCENT             { $$ = "percent"; }
    | PER_MILLE           { $$ = "per-mille"; }
    | ZERO_DIGIT          { $$ = "zero-digit"; }
    ;


OptionDecl :
    DECLARE OPTION QNAME STRING_LITERAL
    {
      $$ = new OptionDecl(LOC(@$), static_cast<QName*>($3), SYMTAB($4));
    }
;


FTOptionDecl :
    DECLARE FT_OPTION FTMatchOptions
    {
      $$ = new FTOptionDecl( LOC(@$), dynamic_cast<FTMatchOptions*>($3) );
    }
;


CtxItemDecl :
    DECLARE CONTEXT ITEM CtxItemDecl2
    {
      $$ = $4;
    }
;


CtxItemDecl2 :
    AS ItemType CtxItemDecl3
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>($3);
      d->theType = $2;
      $$ = d;
    }
  |
    CtxItemDecl3
    {
      $$ = $1;
    }
;


CtxItemDecl3 :
    CtxItemDecl4
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>($1);
      d->theIsExternal = false;
      $$ = d;
    }
  |
    EXTERNAL
    {
      $$ = new CtxItemDecl(LOC(@$), NULL);
    }
  |
    EXTERNAL CtxItemDecl4
    {
      $$ = $2;
    }
;


CtxItemDecl4 :
    GETS ExprSingle
    {
      $$ = new CtxItemDecl(LOC(@$), $2);
    }
;


VarDecl :
    DECLARE VarNameAndType GETS ExprSingle
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>($2));

      $$ = new VarDecl(LOC(@$),
                       nt->theName,
                       nt->theType,
                       $4,
                       nt->get_annotations(),
                       true,    // global
                       false);  // not external

      dynamic_cast<VarDecl*>($$)->setComment(SYMTAB($1));
    }
  |
    DECLARE VarNameAndType EXTERNAL
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>($2));

      $$ = new VarDecl(LOC(@$),
                       nt->theName,
                       nt->theType,
                       NULL,   // no init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>($$)->setComment(SYMTAB($1));
    }
  |
    DECLARE VarNameAndType EXTERNAL GETS ExprSingle
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>($2));

      $$ = new VarDecl(LOC(@$),
                       nt->theName,
                       nt->theType,
                       $5,     // init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>($$)->setComment(SYMTAB($1));
    }
;


VarNameAndType :
    VARIABLE DOLLAR QNAME
    {
      $$ = new VarNameAndType(LOC(@$), static_cast<QName*>($3), NULL, NULL);
    }
  |
    VARIABLE DOLLAR QNAME TypeDeclaration
    {
      $$ = new VarNameAndType(LOC(@$),
                              static_cast<QName*>($3),
                              dynamic_cast<SequenceType *>($4),
                              NULL);
    }
  |
    AnnotationList VARIABLE DOLLAR QNAME
    {
      $$ = new VarNameAndType(LOC(@$),
                              static_cast<QName*>($4),
                              NULL,
                              static_cast<AnnotationListParsenode*>($1));
    }
  |
    AnnotationList VARIABLE DOLLAR QNAME TypeDeclaration
    {
      $$ = new VarNameAndType(LOC(@$),
                              static_cast<QName*>($4),
                              dynamic_cast<SequenceType *>($5),
                              static_cast<AnnotationListParsenode*>($1));
    }
;


AnnotationList :
    Annotation
    {
      $$ = new AnnotationListParsenode(LOC(@$), static_cast<AnnotationParsenode*>($1));
    }
  |
    AnnotationList Annotation
    {
      static_cast<AnnotationListParsenode*>($1)->push_back(static_cast<AnnotationParsenode*>($2));
      $$ = $1;
    }
;


Annotation :
    ANNOTATION_QNAME_SVAL
    {
      $$ = new AnnotationParsenode(LOC(@$), new QName(LOC(@$), SYMTAB($1)), NULL);
    }
  |
    ANNOTATION_QNAME_SVAL LPAR AnnotationLiteralList RPAR
    {
      $$ = new AnnotationParsenode(LOC(@$),
                                   new QName(LOC(@$), SYMTAB($1)),
                                   static_cast<AnnotationLiteralListParsenode*>($3));
    }
  |
    ANNOTATION_EQNAME_SVAL
    {
      $$ = new AnnotationParsenode(LOC(@$), new QName(LOC(@$), SYMTAB($1), true), NULL);
    }
  |
    ANNOTATION_EQNAME_SVAL LPAR AnnotationLiteralList RPAR
    {
      $$ = new AnnotationParsenode(LOC(@$),
                                   new QName(LOC(@$), SYMTAB($1), true),
                                   static_cast<AnnotationLiteralListParsenode*>($3));
    }
;


AnnotationLiteralList :
    Literal
    {
      $$ = new AnnotationLiteralListParsenode(LOC(@$), $1);
    }
  |
    AnnotationLiteralList COMMA Literal
    {
      static_cast<AnnotationLiteralListParsenode*>($1)->push_back($3);
      $$ = $1;
    }
;


FunctionDecl :
    DECLARE FunctionDecl2
    {
      static_cast<FunctionDecl*>($2)->setComment( SYMTAB($1) );
      $$ = $2;
    }
  |
    DECLARE AnnotationList FunctionDecl2
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>($3);

      fdecl->setComment( SYMTAB($1) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>($2));
      $$ = $3;
    }
;


FunctionDecl2 :
    FunctionDeclSimple
    {
      $$ = $1;
    }
  |
    FunctionDeclUpdating
    {
      $$ = $1;
    }
;


FunctionDeclSimple :
    FUNCTION FUNCTION_NAME FunctionSig EnclosedStatementsAndOptionalExpr
    {
      $$ = new FunctionDecl(LOC(@$),
                            static_cast<QName*>($2),
                            &* $3->theParams,
                            &* $3->theReturnType,
                            $4,      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete $3;
    }
  | FUNCTION FUNCTION_NAME FunctionSig EXTERNAL
    {
      $$ = new FunctionDecl(LOC (@$),
                            static_cast<QName*>($2),
                            $3->theParams.getp(),
                            $3->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete $3;
    }
  ;


FunctionDeclUpdating :
    UPDATING FUNCTION FUNCTION_NAME FunctionSig EnclosedStatementsAndOptionalExpr
    {
      $$ = new FunctionDecl(LOC (@$),
                            static_cast<QName*>($3),
                            $4->theParams.getp(),
                            $4->theReturnType.getp(),
                            $5,    // body
                            true,  // updating
                            false);// not external
      delete $4;
    }
  |
    UPDATING FUNCTION FUNCTION_NAME FunctionSig EXTERNAL
    {
      $$ = new FunctionDecl(LOC(@$),
                            static_cast<QName*>($3),
                            $4->theParams.getp(),
                            $4->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete $4;
    }
;


FunctionSig :
    LPAR RPAR
    {
      $$ = new FunctionSig(NULL);
    }
  |
    LPAR ParamList RPAR
    {
      $$ = new FunctionSig(dynamic_cast<ParamList*>($2));
    }
  |
    LPAR RPAR AS SequenceType
    {
      $$ = new FunctionSig(NULL, dynamic_cast<SequenceType*>($4));
    }
  |
    LPAR ParamList RPAR AS SequenceType
    {
      $$ = new FunctionSig(dynamic_cast<ParamList*>($2), dynamic_cast<SequenceType*>($5));
    }
;


ParamList :
    Param
    {
      ParamList *pl = new ParamList( LOC(@$) );
      pl->push_back( dynamic_cast<Param*>($1) );
      $$ = pl;
    }
  |
    ParamList COMMA Param
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>($1) )
        pl->push_back( dynamic_cast<Param*>($3) );

      $$ = $1;
    }
;


Param :
    DOLLAR  QNAME
    {
      $$ = new Param(LOC(@$), static_cast<QName*>($2), NULL);
    }
  |
    DOLLAR  QNAME  TypeDeclaration
    {
      $$ = new Param(LOC(@$),
                     static_cast<QName*>($2),
                     dynamic_cast<SequenceType *>($3));
    }
;


CollectionDecl :
    DECLARE COLLECTION QNAME
    {
      $$ = new CollectionDecl( LOC(@$),
                              static_cast<QName*>($3),
                              NULL,
                              NULL);
    }
  | DECLARE COLLECTION QNAME AS CollectionTypeDecl
    {
      $$ = new CollectionDecl( LOC(@$),
                              static_cast<QName*>($3),
                              0,
                              static_cast<SequenceType*>($5));
    }
  | DECLARE AnnotationList COLLECTION QNAME
    {
      $$ = new CollectionDecl( LOC(@$),
                               static_cast<QName*>($4),
                               static_cast<AnnotationListParsenode*>($2),
                               0);
    }
  | DECLARE AnnotationList COLLECTION QNAME AS CollectionTypeDecl
    {
      $$ = new CollectionDecl( LOC(@$),
                               static_cast<QName*>($4),
                               static_cast<AnnotationListParsenode*>($2),
                               static_cast<SequenceType*>($6));
    }
;

CollectionTypeDecl :
    KindTest
    {
      $$ = static_cast<parsenode*>(new SequenceType(LOC(@$), $1, NULL));
    }
  | KindTest OccurrenceIndicator
    {
      $$ = static_cast<parsenode*>(new SequenceType(LOC(@$),
                                                    $1,
                                                    dynamic_cast<OccurrenceIndicator*>($2)));
    }
;


IndexDecl :
    DECLARE INDEX QNAME ON NODES PathExpr BY IndexKeyList
    {
      $$ = new AST_IndexDecl(LOC(@$),
                             static_cast<QName*>($3),
                             $6,
                             dynamic_cast<IndexKeyList*>($8),
                             NULL);
    }
  | DECLARE AnnotationList INDEX QNAME ON NODES PathExpr BY IndexKeyList
    {
      $$ = new AST_IndexDecl(LOC(@$),
                             static_cast<QName*>($4),
                             $7,
                             dynamic_cast<IndexKeyList*>($9),
                             static_cast<AnnotationListParsenode*>($2));
    }
  ;

IndexKeyList :
    IndexKeySpec
    {
      IndexKeyList* keyList = new IndexKeyList(LOC(@$));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>($1));
      $$ = keyList;
    }
  | IndexKeyList COMMA IndexKeySpec
    {
      dynamic_cast<IndexKeyList*>($1)->addKeySpec(dynamic_cast<IndexKeySpec*>($3));
      $$ = $1;
    }
;


IndexKeySpec :
    PathExpr
    {
      $$ = new IndexKeySpec(LOC(@$), $1, NULL, NULL);
    }
  |
    PathExpr TypeDeclaration
    {
      $$ = new IndexKeySpec(LOC(@$),
                            $1,
                            dynamic_cast<SequenceType*>($2),
                            NULL);
    }
  | PathExpr OrderCollationSpec
    {
      $$ = new IndexKeySpec(LOC(@$),
                            $1,
                            NULL,
                            dynamic_cast<OrderCollationSpec*>($2));
    }
  | PathExpr TypeDeclaration OrderCollationSpec
    {
      $$ = new IndexKeySpec(LOC(@$),
                            $1,
                            dynamic_cast<SequenceType*>($2),
                            dynamic_cast<OrderCollationSpec*>($3));
    }
  ;


IntegrityConstraintDecl :
    DECLARE INTEGRITY CONSTRAINT QNAME ON COLLECTION QNAME
    DOLLAR QNAME CHECK ExprSingle
    {
      $$ = new ICCollSimpleCheck(LOC(@$),
                                 static_cast<QName*>($4),
                                 static_cast<QName*>($7),
                                 static_cast<QName*>($9),
                                 $11);
    }
  |
    DECLARE INTEGRITY CONSTRAINT QNAME ON COLLECTION QNAME
    NODE DOLLAR QNAME CHECK UNIQUE KEY PathExpr
    {
      $$ = new ICCollUniqueKeyCheck(LOC(@$),
                                    static_cast<QName*>($4),
                                    static_cast<QName*>($7),
                                    static_cast<QName*>($10),
                                    $14);
    }
  |
    DECLARE INTEGRITY CONSTRAINT QNAME ON COLLECTION QNAME
    FOREACH NODE DOLLAR QNAME CHECK ExprSingle
    {
      $$ = new ICCollForeachNode(LOC(@$),
                                 static_cast<QName*>($4),
                                 static_cast<QName*>($7),
                                 static_cast<QName*>($11),
                                 $13);
    }
  |
    DECLARE INTEGRITY CONSTRAINT QNAME FOREIGN KEY
      FROM COLLECTION QNAME NODE DOLLAR QNAME KEY PathExpr
      TO   COLLECTION QNAME NODE DOLLAR QNAME KEY PathExpr
    {
      $$ = new ICForeignKey( LOC(@$),
                            static_cast<QName*>($4),
                            static_cast<QName*>($9),
                            static_cast<QName*>($12),
                            $14,
                            static_cast<QName*>($17),
                            static_cast<QName*>($20),
                            $22);
    }
  ;



QueryBody :
    StatementsAndOptionalExprTop
    {
      if ($1 == NULL)
      {
        error(@1, "syntax error, unexpected end of file, the query should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>($1) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>($1);
        blk->setTopLevel(true);
      }

      $$ = new QueryBody(LOC(@$), $1);
    }
;


StatementsAndOptionalExprTop :
    StatementsAndExpr
    {
      $$ = $1;
    }
  |
    Statements
    {
      $$ = $1;
    }
  |
    {
      $$ =  NULL;
    }
;


StatementsAndOptionalExpr :
    StatementsAndExpr
    {
      $$ = $1;
    }
  |
    Statements
    {
      $$ = $1;
    }
  |
    {
      $$ =  new BlockBody(LOC(@$));
    }
;


StatementsAndExpr :
    Expr
    {
      $$ = $1;
    }
  |
    Statements Expr
    {
      BlockBody* blk = static_cast<BlockBody*>($1);

      blk->add($2);

      $$ = blk;
    }
;


Statements :
    Statement
    {
      BlockBody* blk = new BlockBody(LOC(@$));
      blk->add($1);
      $$ = blk;
    }
  |
    Statements Statement
    {
      BlockBody* blk = static_cast<BlockBody*>($1);

      blk->add($2);

      $$ = blk;
    }
;


Statement :
    BlockStatement
  | VarDeclStatement
  | AssignStatement
  | ApplyStatement
  | ExitStatement
  | WhileStatement
  | FlowCtlStatement

  | FLWORStatement
  | IfStatement
  | TypeswitchStatement
  | SwitchStatement
  | TryStatement
;


BlockStatement :
    LBRACE Statements RBRACE
    {
      $$ = $2;
    }
  |
    LBRACE RBRACE
    {
      $$ = new BlockBody(LOC(@$));
    }
;


BlockExpr :
    LBRACE StatementsAndOptionalExpr RBRACE
    {
      if (dynamic_cast<BlockBody*>($2) == NULL)
      {
        BlockBody* blk = new BlockBody(LOC(@$));
        blk->add($2);
        $$ = blk;
      }
      else
      {
        $$ = $2;
      }
    }
;


EnclosedStatementsAndOptionalExpr :
    LBRACE StatementsAndOptionalExpr RBRACE
    {
      $$ = $2;
    }
;


VarDeclStatement :
    BlockVarDeclList SEMI
    {
      $$ = $1;
    }
;


BlockVarDeclList :
    BlockVarDeclList COMMA BlockVarDecl
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>($1);
      vdecl->add($3);
      $$ = vdecl;
    }
  |
    VARIABLE BlockVarDecl
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(@$), NULL);
      vdecl->add($2);
      $$ = vdecl;
    }
  |
    AnnotationList VARIABLE BlockVarDecl
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC(@$), static_cast<AnnotationListParsenode*>($1));
      vdecl->add($3);
      $$ = vdecl;
    }
  ;


BlockVarDecl :
    DOLLAR QNAME
    {
      VarDecl* vd = new VarDecl(LOC(@$),
                                static_cast<QName*>($2),
                                NULL,  // no type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      $$ = vd;
    }
  | DOLLAR QNAME TypeDeclaration
    {
      VarDecl* vd = new VarDecl(LOC(@$),
                                static_cast<QName*>($2),
                                dynamic_cast<SequenceType*>($3), // type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external

      vd->set_global(false);
      $$ = vd;
    }
  | DOLLAR QNAME GETS ExprSingle
    {
      VarDecl* vd = new VarDecl(LOC(@$),
                                static_cast<QName*>($2),
                                NULL,  // no type
                                $4,    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      $$ = vd;
    }
  | DOLLAR QNAME TypeDeclaration GETS ExprSingle
    {
      VarDecl* vd = new VarDecl(LOC(@$),
                                static_cast<QName*>($2),
                                dynamic_cast<SequenceType*>($3), // type
                                $5,    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      $$ = vd;
    }
  ;


AssignStatement :
    DOLLAR QNAME GETS ExprSingle SEMI
    {
      $$ = new AssignExpr(LOC(@$), static_cast<QName*>($2), $4);
    }
;


ApplyStatement :
    ExprSimple SEMI
    {
      $$ = new ApplyExpr(LOC(@$), $1);
    }
;


ExitStatement :
    EXIT RETURNING ExprSingle SEMI
    {
      $$ = new ExitExpr(LOC(@$), $3);
    }
;


WhileStatement :
    WHILE LPAR Expr RPAR Statement
    {
      BlockBody* bb = dynamic_cast<BlockBody *>($5);
      if (bb == NULL)
      {
        bb = new BlockBody($5->get_location());
        bb->add($5);
      }

      $$ = new WhileExpr(LOC(@$), $3, bb);
    }
;


FlowCtlStatement :
    BREAK LOOP SEMI
    {
      $$ = new FlowCtlStatement(LOC(@$), FlowCtlStatement::BREAK);
    }
  |
    CONTINUE LOOP SEMI
    {
      $$ = new FlowCtlStatement( LOC(@$), FlowCtlStatement::CONTINUE );
    }
;


FLWORStatement :
    FLWORClauseList ReturnStatement
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>($2);
      $$ = new FLWORExpr(LOC(@$),
                         dynamic_cast<FLWORClauseList*>($1),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete $2;
    }
;


ReturnStatement :
    RETURN Statement
    {
      exprnode* retExpr = $2;

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(@$));
        blk->add(retExpr);
        retExpr = blk;
      }

      $$ = new ReturnExpr(LOC(@$), retExpr);
    }
;


IfStatement :
    IF LPAR Expr RPAR THEN Statement ELSE Statement
    {
      exprnode* thenExpr = $6;
      exprnode* elseExpr = $8;

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(@$));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC(@$));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      $$ = new IfExpr(LOC(@$), $3, thenExpr, elseExpr);
    }
;


TryStatement :
    TRY BlockStatement CatchListStatement
    {
      $$ = new TryExpr(LOC(@$), $2, $3);
    }
;


CatchListStatement :
    CatchStatement
    {
      CatchListExpr* cle = new CatchListExpr( LOC(@$) );
      cle->push_back( static_cast<CatchExpr*>($1) );
      $$ = cle;
    }
  |
    CatchListStatement CatchStatement
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>($1);
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>($2) );
      $$ = $1;
    }
;


CatchStatement :
    CATCH NameTestList BlockStatement
    {
       $$ = new CatchExpr(LOC(@$), *$2, $3);
       delete $2;
    }
  ;



Expr :
    ExprSingle
    {
      $$ = $1;
    }
  |
    Expr COMMA ExprSingle
    {
      Expr* expr = dynamic_cast<Expr*>($1);
      if ( !expr )
      {
        expr = new Expr( LOC(@$) );
        expr->push_back( $1 );
      }
      expr->push_back( $3 );
      $$ = expr;
    }
;


ExprSingle :
        FLWORExpr
    |   SwitchExpr
    |   TypeswitchExpr
    |   IfExpr
    |   TryExpr
    |   ExprSimple
;


ExprSimple :
        OrExpr
    |   QuantifiedExpr

    /* update extensions */
    |   InsertExpr
    |   DeleteExpr
    |   RenameExpr
    |   ReplaceExpr
    |   TransformExpr
;


FLWORExpr :
    FLWORClauseList ReturnExpr
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>($2);
      $$ = new FLWORExpr(LOC(@$),
                         dynamic_cast<FLWORClauseList*>($1),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete $2;
    }
;


ReturnExpr :
    RETURN ExprSingle
    {
      $$ = new ReturnExpr( LOC(@$), $2 );
    }
;


WindowType :
    SLIDING WINDOW
    {
      $$ = parser::the_sliding;
    }
  |
    TUMBLING WINDOW
    {
      $$ = parser::the_tumbling;
    }
;


FLWORWinCondType :
    START
    {
      $$ = parser::the_start;
    }
  |
    END
    {
      $$ = parser::the_end;
    }
  |
    ONLY END
  {
    $$ = parser::the_only_end;
  }
;


FLWORWinCond :
    FLWORWinCondType WindowVars WHEN ExprSingle
    {
      $$ = new FLWORWinCond(LOC(@$),
                            dynamic_cast<WindowVars*>($2),
                            $4,
                            $1 == parser::the_start,
                            $1 == parser::the_only_end);
    }
  |
    FLWORWinCondType WHEN ExprSingle
    {
      $$ = new FLWORWinCond(LOC(@$),
                            NULL,
                            $3,
                            $1 == parser::the_start,
                            $1 == parser::the_only_end);
    }
;


WindowClause :
    FOR WindowType WindowVarDecl FLWORWinCond FLWORWinCond
    {
      $$ = new WindowClause (LOC (@$),
                             ($2 == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ($3),
                             dynamic_cast<FLWORWinCond *> ($4),
                             dynamic_cast<FLWORWinCond *> ($5));
    }
  | FOR WindowType WindowVarDecl FLWORWinCond
    {
      $$ = new WindowClause (LOC (@$),
                             ($2 == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ($3),
                             dynamic_cast<FLWORWinCond *> ($4), NULL);
    }
;


CountClause :
    COUNT DOLLAR QNAME
    {
      $$ = new CountClause(LOC(@$), static_cast<QName*>($3));
    }
;


ForLetWinClause :
    ForClause
  | LetClause
  | WindowClause
;


FLWORClause :
    ForLetWinClause
  | WhereClause
  | OrderByClause
  | GroupByClause
  | CountClause
;


FLWORClauseList :
    ForLetWinClause
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC(@$) );
      fcl->push_back( dynamic_cast<FLWORClause*>($1) );
      $$ = fcl;
    }
  |
    FLWORClauseList FLWORClause
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>($1);
      fcl->push_back( dynamic_cast<FLWORClause*>($2) );
      $$ = fcl;
    }
;


ForClause :
    FOR DOLLAR VarInDeclList
    {
      $$ = new ForClause(LOC(@$), dynamic_cast<VarInDeclList*>($3));
    }
;


VarInDeclList :
    VarInDecl
    {
      VarInDeclList *vdl = new VarInDeclList( LOC(@$) );
      vdl->push_back( dynamic_cast<VarInDecl*>($1) );
      $$ = vdl;
    }
  |
    VarInDeclList COMMA DOLLAR VarInDecl
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>($1) )
        vdl->push_back( dynamic_cast<VarInDecl*>($4) );
      $$ = $1;
    }
;


VarInDecl :
    QNAME  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         NULL,
                         NULL,
                         NULL,
                         $3,
                         false);
    }
  | QNAME  ALLOWING  _EMPTY  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         NULL,
                         NULL,
                         NULL,
                         $5,
                         true);
    }
  | QNAME  TypeDeclaration  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         NULL,
                         NULL,
                         $4,
                         false);
    }
  | QNAME  TypeDeclaration  ALLOWING  _EMPTY  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         NULL,
                         NULL,
                         $6,
                         true);
    }
  | QNAME  PositionalVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         NULL,
                         dynamic_cast<PositionalVar*>($2),
                         NULL,
                         $4,
                         false);
    }
  | QNAME  ALLOWING  _EMPTY  PositionalVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         NULL,
                         dynamic_cast<PositionalVar*>($4),
                         NULL,
                         $6,
                         true);
    }
  | QNAME  TypeDeclaration  PositionalVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         dynamic_cast<PositionalVar*>($3),
                         NULL,
                         $5,
                         false);
    }
  | QNAME  TypeDeclaration  ALLOWING  _EMPTY  PositionalVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         dynamic_cast<PositionalVar*>($5),
                         NULL,
                         $7,
                         true);
    }
/* full-text extensions */
  | QNAME FTScoreVar _IN ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>($2),
                         $4,
                         false);
    }
  | QNAME  TypeDeclaration  FTScoreVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC(@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         NULL,
                         dynamic_cast<FTScoreVar*>($3),
                         $5,
                         false);
    }
  | QNAME  PositionalVar  FTScoreVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC (@$),
                         static_cast<QName*>($1),
                         NULL,
                         dynamic_cast<PositionalVar*>($2),
                         dynamic_cast<FTScoreVar*>($3),
                         $5,
                         false);
    }
  | QNAME  TypeDeclaration  PositionalVar  FTScoreVar  _IN  ExprSingle
    {
      $$ = new VarInDecl(LOC (@$),
                         static_cast<QName*>($1),
                         dynamic_cast<SequenceType *>($2),
                         dynamic_cast<PositionalVar*>($3),
                         dynamic_cast<FTScoreVar*>($4),
                         $6,
                         false);
    }
;


// [35] PositionalVar
// ------------------
PositionalVar :
    AT  DOLLAR  QNAME
    {
      $$ = new PositionalVar(LOC(@$), static_cast<QName*>($3));
    }
;


// [37]
FTScoreVar :
    SCORE DOLLAR QNAME
    {
      $$ = new FTScoreVar(LOC(@$), static_cast<QName*>($3));
    }
;


// [36]
LetClause :
        LET  VarGetsDeclList
        {
            $$ = new LetClause( LOC(@$), dynamic_cast<VarGetsDeclList*>($2) );
        }
;

// [36a]
VarGetsDeclList :
        VarGetsDecl
        {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC(@$) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>($1) );
            $$ = vgdl;
        }
    |   VarGetsDeclList COMMA VarGetsDecl
        {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>($1) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>($3) );
            $$ = $1;
        }
;


// [36b] VarGetsDecl
// ------------------
VarGetsDecl :
    DOLLAR  QNAME  GETS  ExprSingle
    {
      $$ = new VarGetsDecl(LOC (@$),
                           static_cast<QName*>($2),
                           NULL,
                           NULL,
                           $4);
    }
  | DOLLAR  QNAME  TypeDeclaration  GETS  ExprSingle
    {
      $$ = new VarGetsDecl(LOC (@$),
                           static_cast<QName*>($2),
                           dynamic_cast<SequenceType *>($3),
                           NULL,
                           $5);
    }

    /* full-text extensions */
  | FTScoreVar  GETS  ExprSingle
    {
      $$ = new VarGetsDecl(LOC (@$),
                           dynamic_cast<FTScoreVar*>($1)->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>($1),
                           $3);
     }
  | DOLLAR  QNAME  TypeDeclaration  FTScoreVar  GETS  ExprSingle
    {
      $$ = new VarGetsDecl(LOC (@$),
                           static_cast<QName*>($2),
                           dynamic_cast<SequenceType *>($3),
                           dynamic_cast<FTScoreVar*>($4),
                           $6);
    }
;


WindowVarDecl :
    DOLLAR QNAME  _IN  ExprSingle
    {
      $$ = new WindowVarDecl(LOC (@$),
                             static_cast<QName*>($2),
                             NULL, $4);
    }
  | DOLLAR QNAME  TypeDeclaration  _IN  ExprSingle
    {
      $$ = new WindowVarDecl(LOC (@$),
                             static_cast<QName*>($2),
                             dynamic_cast<SequenceType *>($3),
                             $5);
    }
;


WindowVars :
    WindowVars3

  | DOLLAR QNAME
    {
      $$ = new WindowVars(LOC(@$), NULL, static_cast<QName*>($2), NULL, NULL);
    }
  | DOLLAR QNAME WindowVars3
    {
      $$ = $3;
      dynamic_cast<WindowVars *>($$)->set_curr(static_cast<QName*>($2));
    }
  ;

WindowVars3 :
    PositionalVar
    {
      $$ = new WindowVars(LOC(@$), dynamic_cast<PositionalVar*>($1), NULL, NULL, NULL);
    }
  | PositionalVar WindowVars2
    {
      $$ = $2;
      dynamic_cast<WindowVars *>($$)->set_posvar(dynamic_cast<PositionalVar*>($1));
    }
  | WindowVars2
  ;

WindowVars2 :
    PREVIOUS DOLLAR QNAME NEXT DOLLAR QNAME
    {
      $$ = new WindowVars(LOC(@$), NULL, NULL, static_cast<QName*>($3), static_cast<QName*>($6));
    }
  | NEXT DOLLAR QNAME
    {
      $$ = new WindowVars(LOC(@$), NULL, NULL, NULL, static_cast<QName*>($3));
    }
  | PREVIOUS DOLLAR QNAME
    {
      $$ = new WindowVars(LOC(@$), NULL, NULL, static_cast<QName*>($3), NULL);
    }
;


// [37] WhereClause
// ----------------
WhereClause :
    WHERE  ExprSingle
    {
      $$ = new WhereClause(LOC (@$), $2);
    }
;


GroupByClause :
    GROUP BY GroupSpecList
    {
      $$ = new GroupByClause(LOC(@$), dynamic_cast<GroupSpecList*>($3));
    }
  ;

GroupSpecList :
    GroupSpec
    {
      GroupSpecList* gsl = new GroupSpecList(LOC(@$));
      gsl->push_back(static_cast<GroupSpec*>($1));
      $$ = gsl;
    }
  | GroupSpecList COMMA GroupSpec
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>($1);
      gsl->push_back(static_cast<GroupSpec*>($3));
      $$ = gsl;
    }
  ;


GroupSpec :
    DOLLAR QNAME
    {
      $$ = new GroupSpec(LOC(@$), static_cast<QName*>($2), NULL, NULL, NULL);
    }
  | DOLLAR QNAME GETS ExprSingle
    {
      $$ = new GroupSpec(LOC(@$), static_cast<QName*>($2), NULL, $4, NULL);
    }
  | DOLLAR QNAME TypeDeclaration GETS ExprSingle
    {
      $$ = new GroupSpec(LOC(@$),
                         static_cast<QName*>($2),
                         static_cast<SequenceType*>($3),
                         $5,
                         NULL);
    }
  | DOLLAR QNAME TypeDeclaration GETS ExprSingle GroupCollationSpec
    {
      $$ = new GroupSpec(LOC(@$),
                         static_cast<QName*>($2),
                         static_cast<SequenceType*>($3),
                         $5,
                         static_cast<GroupCollationSpec*>($6));
    }
  | DOLLAR QNAME GETS ExprSingle GroupCollationSpec
    {
      $$ = new GroupSpec(LOC(@$),
                         static_cast<QName*>($2),
                         NULL,
                         $4,
                         static_cast<GroupCollationSpec*>($5));
    }
  | DOLLAR QNAME GroupCollationSpec
    {
      $$ = new GroupSpec(LOC(@$),
                         static_cast<QName*>($2),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>($3));
    }
  ;


GroupCollationSpec :
    COLLATION URI_LITERAL
    {
      $$ = new GroupCollationSpec( LOC(@$), SYMTAB($2) );
    }
  ;


OrderByClause :
        ORDER BY OrderSpecList
        {
            $$ = new OrderByClause(
                LOC(@$), dynamic_cast<OrderSpecList*>($3)
            );
        }
    |   STABLE ORDER BY OrderSpecList
        {
            $$ = new OrderByClause(
                LOC(@$), dynamic_cast<OrderSpecList*>($4), true
            );
        }
    ;

// [39]
OrderSpecList :
        OrderSpec
        {
            OrderSpecList *osl = new OrderSpecList( LOC(@$) );
            osl->push_back( dynamic_cast<OrderSpec*>($1) );
            $$ = osl;
        }
    |   OrderSpecList  COMMA  OrderSpec
        {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>($1) )
                osl->push_back( dynamic_cast<OrderSpec*>($3) );
            $$ = $1;
        }
    ;

// [40]
OrderSpec :
        ExprSingle
        {
            $$ = new OrderSpec( LOC(@$), $1, NULL );
        }
    |   ExprSingle OrderModifier
        {
            $$ = new OrderSpec(
                LOC(@$), $1, dynamic_cast<OrderModifierPN*>($2)
            );
        }
    ;

// [41]
OrderModifier :
        OrderDirSpec
        {
            $$ = new OrderModifierPN(
                LOC(@$), dynamic_cast<OrderDirSpec*>($1), NULL, NULL
            );
        }
    |   OrderEmptySpec
        {
            $$ = new OrderModifierPN(
                LOC(@$), NULL, dynamic_cast<OrderEmptySpec*>($1), NULL
            );
        }
    |   OrderCollationSpec
        {
            $$ = new OrderModifierPN(
                LOC(@$), NULL, NULL, dynamic_cast<OrderCollationSpec*>($1)
            );
        }
    |   OrderDirSpec OrderEmptySpec
        {
            $$ = new OrderModifierPN(
                LOC(@$),
                dynamic_cast<OrderDirSpec*>($1),
                dynamic_cast<OrderEmptySpec*>($2),
                NULL
            );
        }
    |   OrderDirSpec OrderCollationSpec
        {
            $$ = new OrderModifierPN(
                LOC(@$),
                dynamic_cast<OrderDirSpec*>($1),
                NULL,
                dynamic_cast<OrderCollationSpec*>($2)
            );
        }
    |   OrderEmptySpec OrderCollationSpec
        {
            $$ = new OrderModifierPN(
                LOC(@$),
                NULL,
                dynamic_cast<OrderEmptySpec*>($1),
                dynamic_cast<OrderCollationSpec*>($2)
            );
        }
    |   OrderDirSpec OrderEmptySpec OrderCollationSpec
        {
            $$ = new OrderModifierPN(
                LOC(@$),
                dynamic_cast<OrderDirSpec*>($1),
                dynamic_cast<OrderEmptySpec*>($2),
                dynamic_cast<OrderCollationSpec*>($3)
            );
        }
    ;

// [41a]
OrderDirSpec :
        ASCENDING
        {
            $$ = new OrderDirSpec( LOC(@$), ParseConstants::dir_ascending );
        }
    |   DESCENDING
        {
            $$ = new OrderDirSpec( LOC(@$), ParseConstants::dir_descending );
        }
    ;

// [41b]
OrderEmptySpec :
        _EMPTY GREATEST
        {
            $$ = new OrderEmptySpec(
                LOC(@$), StaticContextConsts::empty_greatest
            );
        }
    |   _EMPTY LEAST
        {
            $$ = new OrderEmptySpec(
                LOC(@$), StaticContextConsts::empty_least
            );
        }
    ;

// [41c]
OrderCollationSpec :
        COLLATION URI_LITERAL
        {
            $$ = new OrderCollationSpec( LOC(@$), SYMTAB($2) );
        }
    ;

// [42]
QuantifiedExpr :
        SOME DOLLAR QVarInDeclList SATISFIES ExprSingle
        {
            $$ = new QuantifiedExpr(
                LOC(@$),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>($3),
                $5
            );
        }
    |   EVERY DOLLAR QVarInDeclList SATISFIES ExprSingle
        {
            $$ = new QuantifiedExpr(
                LOC(@$),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>($3),
                $5
            );
        }
    ;

// [42a]
QVarInDeclList :
    QVarInDecl %prec QVARINDECLLIST_REDUCE
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC(@$) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>($1) );
      $$ = qvidl;

    }
  | QVarInDeclList COMMA DOLLAR QVarInDecl
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>($1);
      qvidl->push_back( dynamic_cast<QVarInDecl*>($4) );
      $$ = $1;
    }
;


// [42b] QVarInDecl
// ----------------
QVarInDecl :
    QNAME _IN  ExprSingle
    {
      $$ = new QVarInDecl(LOC(@$), static_cast<QName*>($1), $3);
    }
  | QNAME TypeDeclaration _IN  ExprSingle
    {
      $$ = new QVarInDecl(LOC(@$),
                          static_cast<QName*>($1),
                          dynamic_cast<SequenceType *>($2),
                          $4);
    }
;

// SwitchExpr
// -------------------
SwitchExpr :
    SWITCH  LPAR  Expr  RPAR  SwitchCaseClauseList  DEFAULT  RETURN  ExprSingle
    {
      $$ = new SwitchExpr(LOC(@$), $3, static_cast<SwitchCaseClauseList*>($5), $8);
    }
  ;

SwitchCaseClauseList :
    SwitchCaseClause
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(@$));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>($1));
      $$ = scc_list_p;
    }
  | SwitchCaseClauseList SwitchCaseClause
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>($1);
      scc_list_p->push_back(static_cast<SwitchCaseClause*>($2));
      $$ = $1;
    }
  ;

SwitchCaseClause :
    SwitchCaseOperandList  RETURN  ExprSingle
    {
      $$ = new SwitchCaseClause(LOC(@$), dynamic_cast<SwitchCaseOperandList*>($1), $3);
    }
  ;

SwitchCaseOperandList :
    CASE  ExprSingle
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC(@$));
      sco_list_p->push_back($2);
      $$ = sco_list_p;
    }
  | SwitchCaseOperandList CASE  ExprSingle
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>($1);
      sco_list_p->push_back($3);
      $$ = $1;
    }
  ;

// SwitchStatement
// -------------------
SwitchStatement :
    SWITCH  LPAR  Expr  RPAR  SwitchCaseStatementList  DEFAULT  RETURN  Statement
    {
      $$ = new SwitchExpr(LOC(@$), $3, static_cast<SwitchCaseClauseList*>($5), $8);
    }
  ;

SwitchCaseStatementList :
    SwitchCaseStatement
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC(@$));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>($1));
      $$ = scc_list_p;
    }
  | SwitchCaseStatementList SwitchCaseStatement
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>($1);
      scc_list_p->push_back(static_cast<SwitchCaseClause*>($2));
      $$ = $1;
    }
  ;

SwitchCaseStatement :
    SwitchCaseOperandList  RETURN  Statement
    {
      $$ = new SwitchCaseClause(LOC(@$), dynamic_cast<SwitchCaseOperandList*>($1), $3);
    }
  ;

// [43] TypeswitchExpr
// -------------------
TypeswitchExpr :
    TYPESWITCH LPAR  Expr  RPAR  CaseClauseList  DEFAULT  RETURN  ExprSingle
    {
      $$ = new TypeswitchExpr(LOC(@$),
                              $3,
                              dynamic_cast<CaseClauseList*>($5),
                              $8);
    }
  | TYPESWITCH LPAR Expr RPAR CaseClauseList DEFAULT DOLLAR QNAME RETURN ExprSingle
    {
      $$ = new TypeswitchExpr(LOC (@$),
                              $3,
                              dynamic_cast<CaseClauseList*>($5),
                              static_cast<QName*>($8),
                              $10);
    }
;

TypeswitchStatement :
    TYPESWITCH LPAR  Expr  RPAR  CaseStatementList  DEFAULT  RETURN  Statement
    {
      $$ = new TypeswitchExpr(LOC(@$),
                              $3,
                              dynamic_cast<CaseClauseList*>($5),
                              $8);
    }
  | TYPESWITCH LPAR Expr RPAR CaseClauseList DEFAULT DOLLAR QNAME RETURN Statement
    {
      $$ = new TypeswitchExpr(LOC (@$),
                              $3,
                              dynamic_cast<CaseClauseList*>($5),
                              static_cast<QName*>($8),
                              $10);
    }
;

// [43a]
CaseClauseList :
    CaseClause
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (@$));
      cc_list_p->push_back(dynamic_cast<CaseClause*>($1));
      $$ = cc_list_p;
    }
  | CaseClauseList  CaseClause
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
  | CASE  DOLLAR  QNAME  AS  SequenceType  RETURN  ExprSingle
    {
      $$ = new CaseClause(LOC (@$),
                          static_cast<QName*>($3),
                          dynamic_cast<SequenceType*>($5),
                          $7);
     }
;

// [43a]
CaseStatementList :
    CaseStatement
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC (@$));
      cc_list_p->push_back(dynamic_cast<CaseClause*>($1));
      $$ = cc_list_p;
    }
  | CaseStatementList  CaseStatement
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>($1);
      cc_list_p->push_back(dynamic_cast<CaseClause*>($2));
      $$ = $1;
    }
;

// [44] CaseClause
// ---------------
CaseStatement :
    CASE  SequenceType  RETURN  Statement
    {
      $$ = new CaseClause(LOC (@$),
                          dynamic_cast<SequenceType*>($2),
                          $4);
    }
  | CASE  DOLLAR  QNAME  AS  SequenceType  RETURN  Statement
    {
      $$ = new CaseClause(LOC (@$),
                          static_cast<QName*>($3),
                          dynamic_cast<SequenceType*>($5),
                          $7);
     }
;

// [45]
IfExpr :
    IF LPAR Expr RPAR THEN ExprSingle ELSE ExprSingle
    {
      $$ = new IfExpr(LOC (@$), $3, $6, $8);
    }
;


// [46]
OrExpr :
    AndExpr
    {
      $$ = $1;
    }
  | OrExpr OR AndExpr
    {
      $$ = new OrExpr( LOC(@$), $1, $3 );
    }
;


// [47]
AndExpr :
        ComparisonExpr
        {
            $$ = $1;
        }
    |   AndExpr  AND  ComparisonExpr
        {
            $$ = new AndExpr( LOC(@$), $1, $3 );
        }
    ;

// [50]
ComparisonExpr :
        FTContainsExpr
        {
            $$ = $1;
        }
    |   FTContainsExpr ValueComp FTContainsExpr
        {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            $$ = new ComparisonExpr(
                LOC(@$),
                dynamic_cast<ValueComp*>($2),
                $1,
                $3
            );
        }
    |   FTContainsExpr NodeComp FTContainsExpr
        {
            /*  ::=  "is" | "<<" | ">>" */
            $$ = new ComparisonExpr(
                LOC(@$), dynamic_cast<NodeComp*>($2), $1, $3
            );
        }
    |   FTContainsExpr EQUALS FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_eq ),
                $1,
                $3
            );
        }
    |   FTContainsExpr NE FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_ne ),
                $1,
                $3
            );
        }
    |   FTContainsExpr LT_OR_START_TAG
        {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
        FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_lt ),
                $1,
                $4
            );
        }
    |   FTContainsExpr LE FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_le ),
                $1,
                $3
            );
        }
    |   FTContainsExpr GT FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_gt ),
                $1,
                $3
            );
        }
    |   FTContainsExpr GE FTContainsExpr
        {
            $$ = new ComparisonExpr(
                LOC(@$),
                new GeneralComp( LOC(@$), ParseConstants::op_ge ),
                $1,
                $3
            );
        }
    ;

// [51]
FTContainsExpr :
        StringConcatExpr
        {
            $$ = $1;
        }
    |   StringConcatExpr CONTAINS TEXT FTSelection opt_FTIgnoreOption
        {
            $$ = new FTContainsExpr(
                LOC(@$),
                $1,
                dynamic_cast<FTSelection*>($4),
                dynamic_cast<FTIgnoreOption*>($5)
            );
        }
    ;

StringConcatExpr :
        RangeExpr
        {
          $$ = $1;
        }
    |   RangeExpr CONCAT StringConcatExpr
        {
          $$ = new StringConcatExpr(LOC(@$), $1, $3);
        }
    ;

opt_FTIgnoreOption :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTIgnoreOption
        {
            $$ = $1;
        }
    ;

RangeExpr :
        AdditiveExpr %prec RANGE_REDUCE
        {
            $$ = $1;
        }
    |   AdditiveExpr TO AdditiveExpr
        {
            $$ = new RangeExpr( LOC(@$), $1, $3 );
        }
    ;


// [50]
AdditiveExpr :
        MultiplicativeExpr %prec ADDITIVE_REDUCE
        {
            $$ = $1;
        }
    |   AdditiveExpr PLUS MultiplicativeExpr
        {
            $$ = new AdditiveExpr( LOC(@$), ParseConstants::op_plus, $1, $3 );
        }
    |   AdditiveExpr MINUS MultiplicativeExpr
        {
            $$ = new AdditiveExpr( LOC(@$), ParseConstants::op_minus, $1, $3 );
        }
    ;


// [51]
MultiplicativeExpr :
        UnionExpr %prec MULTIPLICATIVE_REDUCE
        {
            $$ = $1;
        }
    |   MultiplicativeExpr STAR UnionExpr
        {
            $$ = new MultiplicativeExpr(
                LOC(@$), ParseConstants::op_mul, $1, $3
            );
        }
    |   MultiplicativeExpr DIV UnionExpr
        {
            $$ = new MultiplicativeExpr(
                LOC(@$), ParseConstants::op_div, $1, $3
            );
        }
    |   MultiplicativeExpr IDIV UnionExpr
        {
            $$ = new MultiplicativeExpr(
                LOC(@$), ParseConstants::op_idiv, $1, $3
            );
        }
    |   MultiplicativeExpr MOD UnionExpr
        {
            $$ = new MultiplicativeExpr(
                LOC(@$), ParseConstants::op_mod, $1, $3
            );
        }
    ;


// [52]
UnionExpr :
        IntersectExceptExpr %prec UNION_REDUCE
        {
            $$ = $1;
        }
    |   UnionExpr UNION IntersectExceptExpr
        {
            $$ = new UnionExpr( LOC(@$), $1, $3 );
        }
    |   UnionExpr VBAR IntersectExceptExpr
        {
            $$ = new UnionExpr( LOC(@$), $1, $3 );
        }
    ;

// [53]
IntersectExceptExpr :
        InstanceofExpr %prec INTERSECT_EXCEPT_REDUCE
        {
            $$ = $1;
        }
    |   IntersectExceptExpr INTERSECT InstanceofExpr
        {
            $$ = new IntersectExceptExpr(
                LOC(@$), ParseConstants::op_intersect, $1, $3
            );
        }
    |   IntersectExceptExpr EXCEPT InstanceofExpr
        {
            $$ = new IntersectExceptExpr(
                LOC(@$), ParseConstants::op_except, $1, $3
            );
        }
    ;

// [54]
InstanceofExpr :
        TreatExpr
        {
            $$ = $1;
        }
    |   TreatExpr INSTANCE OF SequenceType
        {
            $$ = new InstanceofExpr(
                LOC(@$), $1, dynamic_cast<SequenceType*>($4)
            );
        }
    ;

// [55]
TreatExpr :
        CastableExpr
        {
            $$ = $1;
        }
    |   CastableExpr TREAT AS SequenceType
        {
            $$ = new TreatExpr(
                LOC(@$), $1, dynamic_cast<SequenceType*>($4)
            );
        }
    ;

// [56]
CastableExpr :
        CastExpr
        {
            $$ = $1;
        }
    |   CastExpr CASTABLE AS SingleType
        {
            $$ = new CastableExpr(
                LOC(@$), $1, dynamic_cast<SingleType*>($4)
            );
        }
    ;

// [57]
CastExpr :
        UnaryExpr
        {
            $$ = $1;
        }
    |   UnaryExpr CAST AS SingleType
        {
            $$ = new CastExpr(
                LOC(@$), $1, dynamic_cast<SingleType*>($4)
            );
        }
    ;

// [58]
UnaryExpr :
        ValueExpr
        {
            $$ = $1;
        }
    |   SignList ValueExpr
        {
            $$ = new UnaryExpr( LOC(@$), dynamic_cast<SignList*>($1), $2 );
        }
    ;

// [58a]
SignList :
        PLUS
        {
            $$ = new SignList( LOC(@$), true );
        }
    |   MINUS
        {
            $$ = new SignList( LOC(@$), false );
        }
    |   SignList PLUS
        {
            $$ = $1;
        }
    |   SignList MINUS
        {
            if ( SignList *sl = dynamic_cast<SignList*>($1) )
                sl->negate();
            $$ = $1;
        }
    ;

// [59]
ValueExpr :
        ValidateExpr
        {
            $$ = $1;
        }
    |   PathExpr
        {
            $$ = $1;
        }
    |   ExtensionExpr
        {
            $$ = $1;
        }
    ;

// [61]
ValueComp :
        VAL_EQ
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_eq );
        }
    |   VAL_NE
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_ne );
        }
    |   VAL_LT
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_lt );
        }
    |   VAL_LE
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_le );
        }
    |   VAL_GT
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_gt );
        }
    |   VAL_GE
        {
            $$ = new ValueComp( LOC(@$), ParseConstants::op_val_ge );
        }
    ;

// [62]
NodeComp :
        IS
        {
            $$ = new NodeComp( LOC(@$), ParseConstants::op_is );
        }
    |   PRECEDES
        {
            $$ = new NodeComp( LOC(@$), ParseConstants::op_precedes );
        }
    |   FOLLOWS
        {
            $$ = new NodeComp( LOC(@$), ParseConstants::op_follows );
        }
    ;

// [63]
ValidateExpr :
        VALIDATE LBRACE StatementsAndExpr RBRACE
        {
            $$ = new ValidateExpr( LOC(@$), "strict", $3 );
        }
    |   VALIDATE LAX LBRACE StatementsAndExpr RBRACE
        {
            $$ = new ValidateExpr( LOC(@$), "lax", $4 );
        }
    |   VALIDATE _STRICT LBRACE StatementsAndExpr RBRACE
        {
            $$ = new ValidateExpr( LOC(@$), "strict", $4 );
        }
    |   VALIDATE TYPE TypeName LBRACE StatementsAndExpr RBRACE
        {
            $$ = new ValidateExpr(
                LOC(@$), dynamic_cast<TypeName*>($3)->get_name(), $5
            );
            delete $3;
        }
    ;

// [64]
ExtensionExpr :
        Pragma_list LBRACE RBRACE
        {
            $$ = new ExtensionExpr(
                LOC(@$), dynamic_cast<PragmaList*>($1), NULL
            );
        }
    |   Pragma_list LBRACE Expr RBRACE
        {
            $$ = new ExtensionExpr(
                LOC(@$), dynamic_cast<PragmaList*>($1), $3
            );
        }
    ;

// [64a]
Pragma_list :
        Pragma
        {
            PragmaList *pl = new PragmaList( LOC(@$) );
            pl->push_back( dynamic_cast<Pragma*>($1) );
            $$ = pl;
        }
    |   Pragma_list Pragma
        {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>($1) )
                pl->push_back( dynamic_cast<Pragma*>($2) );
            $$ = $1;
        }
    ;

// [69]
Pragma :
        PRAGMA_BEGIN QNAME PRAGMA_LITERAL_AND_END_PRAGMA
        {
            $$ = new Pragma( LOC(@$), static_cast<QName*>($2), SYMTAB($3) );
        }
    |   PRAGMA_BEGIN QNAME_SVAL_AND_END_PRAGMA
        {
            $$ = new Pragma( LOC(@$), new QName( LOC(@$), SYMTAB($2) ), "" );
        }
    |   PRAGMA_BEGIN EQNAME_SVAL_AND_END_PRAGMA
        {
            $$ = new Pragma( LOC(@$), new QName( LOC(@$), SYMTAB($2), true ), "" );
        }
    ;   /* ws: explicit */

// [66] PragmaContents
// -------------------
/* folded into [65] */

/*______________________________________________________________________
|
| Constraint: leading-lone-slash
|
|   A single slash may appear either as a complete path expression or as
|   the first part of a path expression in which it is followed by a
|   RelativePathExpr, which can take the form of a NameTest ("*" or a
|   QName). In contexts where operators like "*", "union", etc., can
|   occur, parsers may have difficulty distinguishing operators from
|   NameTests. For example, without lookahead the first part of the
|   expression "/ * 5", for example is easily taken to be a complete
|   expression, "/ *", which has a very different interpretation (the
|   child nodes of "/").
|
|   To reduce the need for lookahead, therefore, if the token immediately
|   following a slash is "*" or a keyword, then the slash must be the
|   beginning, but not the entirety, of a PathExpr (and the following
|   token must be a NameTest, not an operator).
|
|   A single slash may be used as the left-hand argument of an operator by
|   parenthesizing it: (/) * 5. The expression 5 * /, on the other hand,
|   is legal without parentheses.
|
|_______________________________________________________________________*/


// [67]
PathExpr :
    LeadingSlash
    {
      $$ = new PathExpr(LOC(@$), ParseConstants::path_leading_lone_slash, NULL);
    }
  | LeadingSlash RelativePathExpr
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC(@$), ParseConstants::st_slash, NULL, $2);

      $$ = new PathExpr(LOC(@$),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
  | SLASH_SLASH RelativePathExpr
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC(@$), ParseConstants::st_slashslash, NULL, $2);

      $$ = new PathExpr(LOC(@$),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
  | RelativePathExpr        /* gn: leading-lone-slashXQ */
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>($1);
      $$ = (!rpe ?
            $1 :
            new PathExpr( LOC(@$), ParseConstants::path_relative, $1));
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


// [68]
RelativePathExpr :
    StepExpr %prec STEP_REDUCE
    {
      AxisStep* as = dynamic_cast<AxisStep*>($1);
      $$ = (as ?
            new RelativePathExpr(LOC(@$),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC(@$), true ), $1)
            :
            $1);
    }
  | StepExpr SLASH RelativePathExpr
    {
      $$ = new RelativePathExpr(LOC(@$), ParseConstants::st_slash, $1, $3);
    }
  | StepExpr SLASH_SLASH RelativePathExpr
    {
      $$ = new RelativePathExpr(LOC(@$), ParseConstants::st_slashslash, $1, $3);
    }
;


// [69]
StepExpr :
    AxisStep
    {
      $$ = $1;
    }
  | FilterExpr
    {
      $$ = $1;
    }
;


// [70]
AxisStep :
        ForwardStep
        {
            $$ = new AxisStep(
                LOC(@$), dynamic_cast<ForwardStep*>($1), NULL
            );
        }
    |   ForwardStep PredicateList
        {
            $$ = new AxisStep(
                LOC(@$),
                dynamic_cast<ForwardStep*>($1),
                dynamic_cast<PredicateList*>($2)
            );
        }
    |   ReverseStep
        {
            $$ = new AxisStep(
                LOC(@$), dynamic_cast<ReverseStep*>($1), NULL
            );
        }
    |   ReverseStep PredicateList
        {
            $$ = new AxisStep(
                LOC(@$),
                dynamic_cast<ReverseStep*>($1),
                dynamic_cast<PredicateList*>($2)
            );
        }
    ;

// [71]
ForwardStep :
        ForwardAxis NodeTest
        {
            $$ = new ForwardStep(
                LOC(@$), dynamic_cast<ForwardAxis*>($1), $2
            );
        }
    |   AbbrevForwardStep
        {
            $$ = new ForwardStep(
                LOC(@$), dynamic_cast<AbbrevForwardStep*>($1)
            );
        }
    ;

// [72]
ForwardAxis :
        CHILD  DOUBLE_COLON
        {
            $$ = new ForwardAxis( LOC(@$), ParseConstants::axis_child );
        }
    |   DESCENDANT  DOUBLE_COLON
        {
            $$ = new ForwardAxis( LOC(@$), ParseConstants::axis_descendant);
        }
    |   ATTRIBUTE  DOUBLE_COLON
        {
            $$ = new ForwardAxis( LOC(@$), ParseConstants::axis_attribute );
        }
    |   SELF  DOUBLE_COLON
        {
            $$ = new ForwardAxis( LOC(@$), ParseConstants::axis_self );
        }
    |   DESCENDANT_OR_SELF  DOUBLE_COLON
        {
            $$ = new ForwardAxis(
                LOC(@$), ParseConstants::axis_descendant_or_self
            );
        }
    |   FOLLOWING_SIBLING  DOUBLE_COLON
        {
            $$ = new ForwardAxis(
                LOC(@$), ParseConstants::axis_following_sibling
            );
        }
    |   FOLLOWING  DOUBLE_COLON
        {
            $$ = new ForwardAxis( LOC(@$), ParseConstants::axis_following );
        }
    ;

// [73]
AbbrevForwardStep :
        NodeTest
        {
            $$ = new AbbrevForwardStep( LOC(@$), $1, false );
        }
    |   AT_SIGN NodeTest
        {
            $$ = new AbbrevForwardStep( LOC(@$), $2, true );
        }
    ;

// [74]
ReverseStep :
        ReverseAxis NodeTest
        {
            $$ = new ReverseStep( LOC(@$), dynamic_cast<ReverseAxis*>($1), $2 );
        }
    |   DOT_DOT
        {
            ReverseAxis *ra = new ReverseAxis(
                LOC(@$), ParseConstants::axis_parent
            );
            $$ = new ReverseStep( LOC(@$), ra, NULL );
        }
    ;

// [75]
ReverseAxis :
        PARENT  DOUBLE_COLON
        {
            $$ = new ReverseAxis( LOC(@$), ParseConstants::axis_parent );
        }
    |   ANCESTOR  DOUBLE_COLON
        {
            $$ = new ReverseAxis( LOC(@$), ParseConstants::axis_ancestor );
        }
    |   PRECEDING_SIBLING  DOUBLE_COLON
        {
            $$ = new ReverseAxis(
                LOC(@$), ParseConstants::axis_preceding_sibling
            );
        }
    |   PRECEDING  DOUBLE_COLON
        {
            $$ = new ReverseAxis( LOC(@$), ParseConstants::axis_preceding );
        }
    |   ANCESTOR_OR_SELF  DOUBLE_COLON
        {
            $$ = new ReverseAxis(
                LOC(@$), ParseConstants::axis_ancestor_or_self
            );
        }
    ;

// [76]
// AbbrevReverseStep
// folded into [74]

// [77]
NodeTest :
        KindTest
        {
            $$ = $1;
        }
    |   NameTest
        {
            $$ = $1;
        }
    ;

// [78]
NameTest :
        QNAME
        {
            $$ = new NameTest( LOC(@$), static_cast<QName*>($1) );
        }
    |   Wildcard
        {
            $$ = new NameTest( LOC(@$), dynamic_cast<Wildcard*>($1) );
        }
    ;


// [79] Wildcard
// -------------
Wildcard :
    STAR
    {
      $$ = new Wildcard(LOC(@$), "", "", ParseConstants::wild_all, false);
    }
  | ELEM_WILDCARD
    {
      $$ = new Wildcard(LOC(@$), SYMTAB($1), "", ParseConstants::wild_elem, false);
    }
  | ELEM_EQNAME_WILDCARD
    {
      $$ = new Wildcard(LOC(@$), SYMTAB($1), "", ParseConstants::wild_elem, true);
    }
  | PREFIX_WILDCARD   /* ws: explicitXQ */
    {
      $$ = new Wildcard(LOC(@$), "", SYMTAB($1), ParseConstants::wild_prefix, false);
    }
;


// [80]
FilterExpr :
     PrimaryExpr
     {
       $$ = $1;
     }
  |  FilterExpr PredicateList
     {
       $$ = new FilterExpr(LOC(@$), $1, dynamic_cast<PredicateList*>($2));
     }
  |  FilterExpr LPAR RPAR
     {
       $$ = new DynamicFunctionInvocation(LOC (@$), $1);
     }
  |  FilterExpr LPAR ArgList RPAR
     {
       $$ = new DynamicFunctionInvocation(LOC (@$), $1, dynamic_cast<ArgList*>($3));
     }
;

// [81]
PredicateList :
        Predicate
        {
            PredicateList *pl = new PredicateList( LOC(@$) );
            pl->push_back( dynamic_cast<exprnode*>($1) );
            $$ = pl;
        }
    |   PredicateList Predicate
        {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>($1) )
                pl->push_back( dynamic_cast<exprnode*>($2) );
            $$ = $1;
        }
    ;

// [82]
Predicate :
        LBRACK Expr RBRACK
        {
            $$ = $2;
        }
    ;

// [83]
PrimaryExpr :
        Literal
        {
          $$ = $1;
        }
    |   VarRef
        {
          $$ = $1;
        }
    |   ParenthesizedExpr
        {
          $$ = $1;
        }
    |   ContextItemExpr
        {
          $$ = $1;
        }
    |   FunctionCall
        {
          $$ = $1;
        }
    |   Constructor
        {
          $$ = $1;
        }
    |   OrderedExpr
        {
          $$ = $1;
        }
    |   UnorderedExpr
        {
          $$ = $1;
        }
    |   FunctionItemExpr
        {
          $$ = $1;
        }
        /*
    |   BlockVarDecl
        {
          $$ = $1;
        }
        */
    |   BlockExpr
        {
          $$ = $1;
        }
    ;

// [84]
Literal :
        NumericLiteral
        {
            $$ = $1;
        }
    |   StringLiteral
        {
            $$ = $1;
        }
    ;

// [85]
NumericLiteral :
        DECIMAL_LITERAL
        {
            $$ = NumericLiteral::new_literal(
                LOC(@$), ParseConstants::num_decimal, *$1
            );
            delete yylval.decval;
        }
    |   INTEGER_LITERAL
        {
            $$ = NumericLiteral::new_literal(
                LOC(@$), ParseConstants::num_integer, *$1
            );
            delete yylval.ival;
        }
    |   DOUBLE_LITERAL
        {
            $$ = NumericLiteral::new_literal(
                LOC(@$), ParseConstants::num_double, *$1
            );
            delete yylval.dval;
        }
    ;

// [86]
VarRef :
        DOLLAR QNAME
        {
            $$ = new VarRef(LOC(@$), static_cast<QName*>($2));
        }
    ;

// [87]
ParenthesizedExpr :
        LPAR RPAR
        {
            $$ = new ParenthesizedExpr( LOC(@$), NULL);
        }
    |   LPAR Expr RPAR
        {
            $$ = new ParenthesizedExpr( LOC(@$), $2 );
        }
    ;

// [88]
ContextItemExpr :
        DOT
        {
            $$ = new ContextItemExpr( LOC(@$) );
        }
    ;

// [89]
OrderedExpr :
        ORDERED LBRACE Expr RBRACE
        {
            $$ = new OrderedExpr( LOC(@$), $3 );
        }
    ;

// [90]
UnorderedExpr :
        UNORDERED LBRACE Expr RBRACE
        {
            $$ = new UnorderedExpr( LOC(@$), $3 );
        }
    ;

// [91] FunctionCall
// -----------------
/*___________________________________________________________________
|   gn: reserved-function-namesXQ
|   Constraint: reserved-function-names
|
|   Unprefixed function names spelled the same way as language keywords
|   could make the language harder to recognize. For instance, if(foo)
|   could be taken either as a FunctionCall or as the beginning of an
|   IfExpr. Therefore it is not legal syntax for a user to invoke
|   functions with unprefixed names which match any of the names:
|       attribute
|       comment
|       document-node
|       element
|       empty-sequence
|       if
|       item
|   node
|       processing-instruction
|       schema-attribute
|       schema-element
|       text
|       typeswitch
|
|   A function named "if" can be called by binding its namespace to a
|   prefix and using the prefixed form: "library:if(foo)" instead of
|   "if(foo)".
|____________________________________________________________________*/

/*___________________________________________________________________
|   gn: parensXQ
|   Grammar-note: parens
|
|   Look-ahead is required to distinguish FunctionCall from a QName or
|   keyword followed by a Pragma or Comment. For example:
|
|       address (: this may be empty :)
|
|   may be mistaken for a call to a function named
|   "address" unless this lookahead is employed. Another example is
|
|       for (: whom the bell :) $tolls in 3 return $tolls,
|
|   where the keyword "for" must not be mistaken for a function name.
|
|____________________________________________________________________*/
FunctionCall :
        FUNCTION_NAME LPAR RPAR
        {
            $$ = new FunctionCall( LOC(@$), static_cast<QName*>($1), NULL );
        }
    |   FUNCTION_NAME LPAR ArgList RPAR
        {
            $$ = new FunctionCall(
                LOC(@$),
                static_cast<QName*>($1),
                dynamic_cast<ArgList*>($3)
            );
        }

    ;

// [91a]
ArgList :
        ExprSingle
        {
            ArgList *al = new ArgList( LOC(@$) );
            al->push_back( $1 );
            $$ = al;
        }
    |   ArgList COMMA ExprSingle
        {
            if ( ArgList *al = dynamic_cast<ArgList*>($1) )
                al->push_back( $3 );
            $$ = $1;
        }
    ;

// [92]
Constructor :
        DirectConstructor
        {
            $$ = $1;
        }
    |   ComputedConstructor
        {
            $$ = $1;
        }
    ;

// [93]
DirectConstructor :
        DirElemConstructor
        {
            $$ = $1;
        }
    |   DirCommentConstructor
        {
            $$ = $1;
        }
    |   DirPIConstructor
        {
            $$ = $1;
        }
    ;

// [94]
DirElemConstructor :
        LT_OR_START_TAG QNAME OptionalBlank EMPTY_TAG_END /* ws: explicitXQ */
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                NULL,
                NULL,
                NULL
            );
        }
    |   LT_OR_START_TAG QNAME DirAttributeList OptionalBlank EMPTY_TAG_END /* ws: explicitXQ */
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                NULL,
                dynamic_cast<DirAttributeList*>($3),
                NULL
            );
        }
    |   LT_OR_START_TAG QNAME OptionalBlank TAG_END START_TAG_END QNAME OptionalBlank TAG_END
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                static_cast<QName*>($6),
                NULL,
                NULL
            );
        }
    | LT_OR_START_TAG QNAME OptionalBlank TAG_END DirElemContentList START_TAG_END QNAME OptionalBlank TAG_END
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                static_cast<QName*>($7),
                NULL,
                dynamic_cast<DirElemContentList*>($5)
            );
        }
    |   LT_OR_START_TAG QNAME DirAttributeList OptionalBlank TAG_END START_TAG_END QNAME OptionalBlank TAG_END
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                static_cast<QName*>($7),
                dynamic_cast<DirAttributeList*>($3),
                NULL
            );
        }
    |   LT_OR_START_TAG QNAME DirAttributeList OptionalBlank TAG_END DirElemContentList START_TAG_END QNAME OptionalBlank TAG_END
        {
            $$ = new DirElemConstructor(
                LOC(@$),
                static_cast<QName*>($2),
                static_cast<QName*>($8),
                dynamic_cast<DirAttributeList*>($3),
                dynamic_cast<DirElemContentList*>($6)
            );
        }
        /* ws: explicitXQ */
    ;

// [94a]
DirElemContentList :
        DirElemContent
        {
            DirElemContentList *decl = new DirElemContentList( LOC(@$) );
            decl->push_back( dynamic_cast<DirElemContent*>($1) );
            $$ = decl;
        }
    |   DirElemContentList DirElemContent
        {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>($1);
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>($2) );
            $$ = $1;
        }
    ;

// [95]
DirAttributeList :
        DirAttr
        {
            DirAttributeList *dal = new DirAttributeList( LOC(@$) );
            dal->push_back( dynamic_cast<DirAttr*>($1) );
            $$ = dal;
        }
    |   DirAttributeList DirAttr
        {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>($1);
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>($2) );
            $$ = $1;
        }
    ;

// [95a]
DirAttr :
        BLANK QNAME OptionalBlank EQUALS OptionalBlank DirAttributeValue /* ws: explicitXQ */
        {
            $$ = new DirAttr(
                LOC(@$),
                static_cast<QName*>($2),
                dynamic_cast<DirAttributeValue*>($6)
            );
        }
    ;

// OptionaBlank used in the DirElemConstr
OptionalBlank :
        /* empty */
    |   BLANK;

// [96]
DirAttributeValue :
        QUOTE opt_QuoteAttrContentList QUOTE
        {
            $$ = new DirAttributeValue( LOC(@$),
                                dynamic_cast<QuoteAttrContentList*>($2));
        }
    |   APOS opt_AposAttrContentList APOS     /* ws: explicitXQ */
        {
            $$ = new DirAttributeValue( LOC(@$),
                                dynamic_cast<AposAttrContentList*>($2));
        }
    ;

// [96a]
opt_QuoteAttrContentList :
        /* empty */
        {
            $$ = new QuoteAttrContentList( LOC(@$) );
        }
    |   QuoteAttrContentList
        {
            $$ = $1;
        }
    ;

QuoteAttrContentList :
        ESCAPE_QUOTE
        {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(@$) );
            qacl->push_back( new QuoteAttrValueContent( LOC(@$), "\"" ) );
            $$ = qacl;
        }
    |   QuoteAttrValueContent
        {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC(@$) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>($1) );
            $$ = qacl;
        }
    |   QuoteAttrContentList ESCAPE_QUOTE
        {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>($1);
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC(@$), "\"" ) );
            $$ = $1;
        }
    |   QuoteAttrContentList QuoteAttrValueContent
        {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>($1);
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>($2) );
            $$ = $1;
        }
    ;

// [96b]
opt_AposAttrContentList :
        /* empty */
        {
            $$ = new AposAttrContentList( LOC(@$) );
        }
    |   AposAttrContentList
        {
            $$ = $1;
        }
    ;

AposAttrContentList :
        ESCAPE_APOS
        {
            AposAttrContentList *aacl = new AposAttrContentList( LOC(@$) );
            aacl->push_back( new AposAttrValueContent( LOC(@$),"'") );
            $$ = aacl;
        }
    |   AposAttrValueContent
        {
            AposAttrContentList *aacl = new AposAttrContentList( LOC(@$) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>($1) );
            $$ = aacl;
        }
    |   AposAttrContentList ESCAPE_APOS
        {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>($1);
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC(@$),"'") );
            $$ = $1;
        }
    |   AposAttrContentList AposAttrValueContent
        {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>($1);
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>($2) );
            $$ = $1;
        }
    ;

// [97]
QuoteAttrValueContent :
        QUOTE_ATTR_CONTENT
        {
            $$ = new QuoteAttrValueContent( LOC(@$), SYMTAB($1) );
        }
    |   CommonContent
        {
            $$ = new QuoteAttrValueContent(
                LOC(@$), dynamic_cast<CommonContent*>($1)
            );
        }
    ;

// [98]
AposAttrValueContent :
        APOS_ATTR_CONTENT
        {
            $$ = new AposAttrValueContent( LOC(@$), SYMTAB($1) );
        }
    |   CommonContent
        {
            $$ = new AposAttrValueContent(
                LOC(@$), dynamic_cast<CommonContent*>($1)
            );
        }
    ;

// [99]
DirElemContent :
        DirectConstructor
        {
            $$ = new DirElemContent( LOC(@$), $1 );
        }
    |   ELEMENT_CONTENT
        {
            $$ = new DirElemContent( LOC(@$), SYMTAB($1) );
        }
    |   CDataSection
        {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>($1);
            $$ = new DirElemContent( LOC(@$), cdata_h );
        }
    |   CommonContent
        {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>($1);
            $$ = new DirElemContent( LOC(@$), cont_h );
        }
    ;

// [100]
CommonContent :
        CHAR_REF_LITERAL
        {
            $$ = new CommonContent(
                LOC(@$), ParseConstants::cont_charref, SYMTAB($1)
            );
        }
    |   DOUBLE_LBRACE
        {
            $$ = new CommonContent(
                LOC(@$), ParseConstants::cont_escape_lbrace
            );
        }
    |   DOUBLE_RBRACE
        {
            $$ = new CommonContent(
                LOC(@$), ParseConstants::cont_escape_rbrace
            );
        }
    |   LBRACE StatementsAndExpr RBRACE
        {
            $$ = new CommonContent(LOC(@$), new EnclosedExpr(LOC(@$), $2));
        }
    ;


DirCommentConstructor :
    XML_COMMENT_BEGIN XML_COMMENT_LITERAL XML_COMMENT_END /* ws: explicitXQ */
    {
      $$ = new DirCommentConstructor( LOC(@$), SYMTAB($2) );
    }
  |
    XML_COMMENT_BEGIN XML_COMMENT_END /* ws: explicitXQ */
    {
      $$ = new DirCommentConstructor( LOC(@$), "" );
    }
;


DirPIConstructor :
    PI_BEGIN NCNAME PI_END          /* ws: explicitXQ */
    {
      $$ = new DirPIConstructor( LOC(@$), SYMTAB($2) );
    }
  |
    PI_BEGIN NCNAME CHAR_LITERAL_AND_PI_END /* ws: explicitXQ */
    {
      $$ = new DirPIConstructor( LOC(@$), SYMTAB($2), SYMTAB($3) );
    }
;


CDataSection :
    CDATA_BEGIN CHAR_LITERAL_AND_CDATA_END /* ws: explicitXQ */
    {
      $$ = new CDataSection( LOC(@$),SYMTAB($2) );
    }
;


ComputedConstructor :
    CompDocConstructor
    {
      $$ = $1;
    }
  |
    CompElemConstructor
    {
      $$ = $1;
    }
  |
    CompAttrConstructor
    {
      $$ = $1;
    }
  |
    CompTextConstructor
    {
      $$ = $1;
    }
  |
    CompCommentConstructor
    {
      $$ = $1;
    }
  |
    CompPIConstructor
    {
      $$ = $1;
    }
;


// [108]
CompDocConstructor :
        DOCUMENT LBRACE StatementsAndExpr RBRACE
        {
            $$ = new CompDocConstructor( LOC(@$), $3 );
        }
    ;

// [109]
CompElemConstructor :
        COMP_ELEMENT_QNAME_LBRACE StatementsAndOptionalExpr RBRACE
        {
            $$ = new CompElemConstructor(LOC(@$), new QName(LOC(@$), SYMTAB($1)), $2);
        }
    |   ELEMENT LBRACE Expr RBRACE LBRACE StatementsAndOptionalExpr RBRACE
        {
            $$ = new CompElemConstructor( LOC(@$), $3, $6 );
        }
    ;

// [110]
/*
ContentExpr :
        Expr
        {
        }
    ;
*/

// [111]
CompAttrConstructor :
        COMP_ATTRIBUTE_QNAME_LBRACE StatementsAndOptionalExpr RBRACE
        {
          $$ = new CompAttrConstructor( LOC(@$), new QName(LOC(@$), SYMTAB($1)), $2 );
        }
    |   ATTRIBUTE LBRACE Expr RBRACE LBRACE StatementsAndOptionalExpr RBRACE
        {
            $$ = new CompAttrConstructor( LOC(@$), $3, $6 );
        }
    ;

// [112]
CompTextConstructor :
        TEXT LBRACE StatementsAndExpr RBRACE
        {
            $$ = new CompTextConstructor( LOC(@$), $3 );
        }
    ;

// [113]
CompCommentConstructor :
        COMMENT LBRACE StatementsAndExpr RBRACE
        {
            $$ = new CompCommentConstructor( LOC(@$), $3 );
        }
    ;

// [114]
CompPIConstructor :
        COMP_PI_NCNAME_LBRACE StatementsAndOptionalExpr RBRACE
        {
            $$ = new CompPIConstructor( LOC(@$), SYMTAB($1), $2 );
        }
    |   PROCESSING_INSTRUCTION LBRACE Expr RBRACE LBRACE StatementsAndOptionalExpr RBRACE
        {
            $$ = new CompPIConstructor( LOC(@$), $3, $6 );
        }
    ;

// [115]
SingleType :
        AtomicType
        {
            $$ = new SingleType(
                LOC(@$), dynamic_cast<AtomicType*>($1), false
            );
        }
    |   AtomicType HOOK
        {
            $$ = new SingleType(
                LOC(@$), dynamic_cast<AtomicType*>($1), true
            );
        }
    ;

// [116]
TypeDeclaration :
        AS SequenceType
        {
            $$ = $2;
        }
    ;

// [117]
SequenceType :
        ItemType // ItemType %prec SEQUENCE_TYPE_REDUCE
        {
            $$ = new SequenceType( LOC(@$), $1, NULL );
        }
    |   ItemType OccurrenceIndicator
        {
            $$ = new SequenceType(LOC(@$), $1, dynamic_cast<OccurrenceIndicator*>($2));
        }
    |   EMPTY_SEQUENCE LPAR RPAR
        {
            $$ = new SequenceType( LOC(@$), NULL, NULL );
        }
    ;

// [118]
/*________________________________________________________________________
|
|   gn: occurrence-indicatorsXQ
|
|   Constraint: occurrence-indicators
|
|   As written, the grammar in A XQuery Grammar is ambiguous for some
|   forms using the '+' and '*' Kleene operators. The ambiguity is
|   resolved as follows: these operators are tightly bound to the
|   SequenceType expression, and have higher precedence than other uses of
|   these symbols. Any occurrence of '+' and '*', as well as '?',
|   following a sequence type is assumed to be an occurrence indicator.
|   That is, a "+", "*", or "?" immediately following an ItemType must be
|   an OccurrenceIndicator. Thus, 4 treat as item() + - 5 must be
|   interpreted as (4 treat as item()+) - 5, taking the '+' as an
|   OccurrenceIndicator and the '-' as a subtraction operator. To force
|   the interpretation of "+" as an addition operator (and the
|   corresponding interpretation of the "-" as a unary minus), parentheses
|   may be used: the form (4 treat as item()) + -5 surrounds the
|   SequenceType expression with parentheses and leads to the desired
|   interpretation.
|
|   This rule has as a consequence that certain forms which would
|   otherwise be legal and unambiguous are not recognized: in "4 treat as
|   item() + 5", the "+" is taken as an OccurrenceIndicator, and not as an
|   operator, which means this is not a legal expression.
|_________________________________________________________________________*/
OccurrenceIndicator :
        HOOK
        {
            $$ = new OccurrenceIndicator(
                LOC(@$), ParseConstants::occurs_optionally
            );
        }
    |   STAR
        {
            $$ = new OccurrenceIndicator(
                LOC(@$), ParseConstants::occurs_zero_or_more
            );
        }
    |   PLUS                            /* gn: occurrence-indicatorsXQ */
        {
            $$ = new OccurrenceIndicator(
                LOC(@$), ParseConstants::occurs_one_or_more
            );
        }
    ;

// [119]
ItemType :
        AtomicType
        {
            $$ = $1;
        }
    |   KindTest
        {
            $$ = $1;
        }
    |   ITEM LPAR RPAR
        {
            $$ = new ItemType( LOC(@$),true );
        }
    |   FunctionTest
        {
            $$ = $1;
        }
    |   ParenthesizedItemType
        {
            $$ = $1;
        }
    ;

TypeList:
        SequenceType
        {
          TypeList* aTypeList = new TypeList(LOC (@$));
          aTypeList->push_back(dynamic_cast<SequenceType *>($1));
          $$ = aTypeList;
        }
    |   TypeList COMMA SequenceType
        {
          TypeList* aTypeList = dynamic_cast<TypeList *>($1);
          aTypeList->push_back(dynamic_cast<SequenceType *>($3));
          $$ = $1;
        }
;

// [120]
AtomicType :
        QNAME
        {
            $$ = new AtomicType( LOC(@$), static_cast<QName*>($1) );
        }
    ;

// [121]
KindTest :
        DocumentTest
        {
            $$ = $1;
        }
    |   ElementTest
        {
            $$ = $1;
        }
    |   AttributeTest
        {
            $$ = $1;
        }
    |   SchemaElementTest
        {
            $$ = $1;
        }
    |   SchemaAttributeTest
        {
            $$ = $1;
        }
    |   PITest
        {
            $$ = $1;
        }
    |   CommentTest
        {
            $$ = $1;
        }
    |   TextTest
        {
            $$ = $1;
        }
    |   AnyKindTest
        {
            $$ = $1;
        }
    ;

// [122]
AnyKindTest :
        NODE LPAR RPAR
        {
            $$ = new AnyKindTest( LOC(@$) );
        }
    ;

// [123]
DocumentTest :
        DOCUMENT_NODE LPAR RPAR
        {
            $$ = new DocumentTest( LOC(@$) );
        }
    |   DOCUMENT_NODE LPAR ElementTest RPAR
        {
            $$ = new DocumentTest( LOC(@$), dynamic_cast<ElementTest*>($3) );
        }
    |   DOCUMENT_NODE LPAR SchemaElementTest RPAR
        {
            $$ = new DocumentTest(
                LOC(@$), dynamic_cast<SchemaElementTest*>($3)
            );
        }
    ;

// [124]
TextTest :
        TEXT LPAR RPAR
        {
            $$ = new TextTest( LOC(@$) );
        }
    ;

// [125]
CommentTest :
        COMMENT LPAR RPAR
        {
            $$ = new CommentTest( LOC(@$));
        }
    ;

// [126]
PITest :
        PROCESSING_INSTRUCTION LPAR RPAR
        {
            $$ = new PITest( LOC(@$), "" );
        }
    |   PROCESSING_INSTRUCTION LPAR NCNAME RPAR
        {
            $$ = new PITest( LOC(@$), SYMTAB($3) );
        }
    |   PROCESSING_INSTRUCTION LPAR STRING_LITERAL RPAR
        {
            $$ = new PITest( LOC(@$), SYMTAB($3) );
        }
    ;

// [127]
AttributeTest :
        ATTRIBUTE LPAR RPAR
        {
            $$ = new AttributeTest( LOC(@$), NULL, NULL );
        }
    |   ATTRIBUTE LPAR QNAME RPAR
        {
            $$ = new AttributeTest(
                LOC(@$), static_cast<QName*>($3), NULL
            );
        }
    |   ATTRIBUTE LPAR QNAME COMMA TypeName RPAR
        {
            $$ = new AttributeTest(
                LOC(@$), static_cast<QName*>($3), dynamic_cast<TypeName*>($5)
            );
        }
    |   ATTRIBUTE LPAR STAR RPAR
        {
            $$ = new AttributeTest( LOC(@$), NULL, NULL );
        }
    |   ATTRIBUTE LPAR STAR COMMA TypeName RPAR
        {
            $$ = new AttributeTest(
                LOC(@$), NULL, dynamic_cast<TypeName*>($5)
            );
        }
    ;

// [129]
SchemaAttributeTest :
        SCHEMA_ATTRIBUTE LPAR QNAME RPAR
        {
            $$ = new SchemaAttributeTest( LOC(@$), static_cast<QName*>($3) );
        }
    ;

// [131]
ElementTest :
        ELEMENT LPAR RPAR
        {
            $$ = new ElementTest( LOC(@$), NULL, NULL, true );
        }
    |   ELEMENT LPAR QNAME RPAR
        {
            $$ = new ElementTest(
                LOC(@$), static_cast<QName*>($3), NULL, true
            );
        }
    |   ELEMENT LPAR QNAME COMMA TypeName RPAR
        {
            $$ = new ElementTest(
                LOC(@$),
                static_cast<QName*>($3),
                dynamic_cast<TypeName*>($5),
                false
            );
        }
    |   ELEMENT LPAR QNAME COMMA TypeName_WITH_HOOK RPAR
        {
            $$ = new ElementTest(
                LOC(@$),
                static_cast<QName*>($3),
                dynamic_cast<TypeName*>($5),
                true
            );
        }
    |   ELEMENT LPAR STAR RPAR
        {
            $$ = new ElementTest(
                LOC(@$), NULL, NULL, true
            );
        }
    |   ELEMENT LPAR STAR COMMA TypeName RPAR
        {
            $$ = new ElementTest(
                LOC(@$), NULL, dynamic_cast<TypeName*>($5), false
            );
        }
    |   ELEMENT LPAR STAR COMMA TypeName_WITH_HOOK RPAR
        {
            $$ = new ElementTest(
                LOC(@$), NULL, dynamic_cast<TypeName*>($5), true
            );
        }
    ;

// [133]
SchemaElementTest :
        SCHEMA_ELEMENT LPAR QNAME RPAR
        {
            $$ = new SchemaElementTest( LOC(@$), static_cast<QName*>($3) );
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

// [137]
TypeName :
        QNAME
        {
            $$ = new TypeName( LOC(@$), static_cast<QName*>($1) );
        }
    ;

TypeName_WITH_HOOK :
        QNAME HOOK
        {
            $$ = new TypeName( LOC(@$), static_cast<QName*>($1), true );
        }
    ;

/* lexical rules, see xquery.l */
/* --------------------------- */
// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral

// [142]
StringLiteral :
        STRING_LITERAL
        {
            $$ = new StringLiteral( LOC(@$), SYMTAB($1) );
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
 *  XQuery 3.0 productions                                               *
 *  [http://www.w3.org/TR/xquery-3/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/

// [161] FunctionItemExpr
// ------------
FunctionItemExpr :
    LiteralFunctionItem
    {
      $$ = $1;
    }
  | InlineFunction
    {
      $$ = $1;
    }
;


LiteralFunctionItem :
    QNAME HASH INTEGER_LITERAL
    {
      $$ = new LiteralFunctionItem(LOC (@$), dynamic_cast<QName*>($1), $3);
    }
;


InlineFunction :
    FUNCTION FunctionSig EnclosedStatementsAndOptionalExpr
    {
      $$ = new InlineFunction(LOC(@$),
                              &*$2->theParams,
                              &*$2->theReturnType,
                              $3);
      delete $2;
    }
;


FunctionTest :
    AnyFunctionTest
    {
      $$ = $1;
    }
  | TypedFunctionTest
    {
      $$ = $1;
    }
;


AnyFunctionTest :
    FUNCTION LPAR STAR RPAR
    {
      $$ = new AnyFunctionTest(LOC(@$));
    }
;


TypedFunctionTest :
        FUNCTION LPAR  RPAR AS SequenceType
        {
          $$ = new TypedFunctionTest(LOC (@$), dynamic_cast<SequenceType *>($5));
        }
    |   FUNCTION LPAR TypeList RPAR AS SequenceType
        {
          $$ = new TypedFunctionTest(LOC (@$),
              dynamic_cast<TypeList *>($3),
              dynamic_cast<SequenceType *>($6));
        }
    ;

// [192] ParenthesizedItemType
// ------------
ParenthesizedItemType :
        LPAR ItemType RPAR
        {
           $$ = $2;
        }
    ;


/*_______________________________________________________________________
 *                                                                       *
 *  Update productions                                                   *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/


// [241]
RevalidationDecl :
        DECLARE REVALIDATION _STRICT
        {
            $$ = new RevalidationDecl(
                LOC(@$), StaticContextConsts::strict_validation
            );
        }
    |   DECLARE REVALIDATION LAX
        {
            $$ = new RevalidationDecl(
                LOC(@$), StaticContextConsts::lax_validation
            );
        }
    |   DECLARE REVALIDATION SKIP
        {
            $$ = new RevalidationDecl(
                LOC(@$), StaticContextConsts::skip_validation
            );
        }
    ;

// [242]
InsertExpr :
        INSERT NODE ExprSingle INTO ExprSingle
        {
            $$ = new InsertExpr( LOC(@$), store::UpdateConsts::INTO, $3, $5 );
        }
    |   INSERT NODE ExprSingle AS FIRST INTO ExprSingle
        {
            $$ = new InsertExpr(
                LOC(@$), store::UpdateConsts::AS_FIRST_INTO, $3, $7
            );
        }
    |   INSERT NODE ExprSingle AS LAST INTO ExprSingle
        {
            $$ = new InsertExpr(
                LOC(@$), store::UpdateConsts::AS_LAST_INTO, $3, $7
            );
        }
    |   INSERT NODE ExprSingle AFTER ExprSingle
        {
            $$ = new InsertExpr( LOC(@$), store::UpdateConsts::AFTER, $3, $5 );
        }
    |   INSERT NODE ExprSingle BEFORE ExprSingle
        {
            $$ = new InsertExpr(
                LOC (@$), store::UpdateConsts::BEFORE, $3, $5
            );
        }
    |   INSERT NODES ExprSingle INTO ExprSingle
        {
            $$ = new InsertExpr( LOC(@$), store::UpdateConsts::INTO, $3, $5 );
        }
    |   INSERT NODES ExprSingle AS FIRST INTO ExprSingle
        {
            $$ = new InsertExpr(
                LOC(@$), store::UpdateConsts::AS_FIRST_INTO, $3, $7
            );
        }
    |   INSERT NODES ExprSingle AS LAST INTO ExprSingle
        {
            $$ = new InsertExpr(
                  LOC(@$), store::UpdateConsts::AS_LAST_INTO, $3, $7
            );
        }
    |   INSERT NODES ExprSingle AFTER ExprSingle
        {
            $$ = new InsertExpr(
                LOC (@$),
                store::UpdateConsts::AFTER, $3, $5
            );
        }
    |   INSERT NODES ExprSingle BEFORE ExprSingle
        {
            $$ = new InsertExpr(
                LOC (@$), store::UpdateConsts::BEFORE, $3, $5
            );
        }
    ;

// [243]
DeleteExpr :
        _DELETE NODE ExprSingle
        {
            $$ = new DeleteExpr( LOC (@$), $3 );
        }
    |
        _DELETE NODES ExprSingle
        {
            $$ = new DeleteExpr( LOC (@$), $3 );
        }
    ;

// [244]
ReplaceExpr :
        REPLACE NODE ExprSingle WITH ExprSingle
        {
            $$ = new ReplaceExpr(
                LOC(@$), store::UpdateConsts::NODE, $3, $5
            );
        }
    |   REPLACE VALUE OF NODE ExprSingle WITH ExprSingle
        {
            $$ = new ReplaceExpr(
                LOC(@$), store::UpdateConsts::VALUE_OF_NODE, $5, $7
            );
        }
    ;

// [245] RenameExpr
RenameExpr :
        RENAME NODE ExprSingle AS ExprSingle
        {
            $$ = new RenameExpr( LOC (@$), $3, $5 );
        }
    ;

// [246]
// SourceExpr
// folded

// [247]
// TargetExpr
// folded

// [248]
// NewNameExpr
// folded into [245] RenameExpr


// [249] TransformExpr
// -------------------
TransformExpr :
    COPY DOLLAR VarNameList MODIFY ExprSingle RETURN ExprSingle
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>($3);
      $$ = new TransformExpr( LOC(@$), cvl, $5, $7 );
    }
;

// [249a]
VarNameList :
    VarNameDecl
    {
      CopyVarList* lList = new CopyVarList(LOC(@$));
      lList->push_back (dynamic_cast<VarBinding*> ($1));
      $$ = lList;
    }
  | VarNameList  COMMA  DOLLAR  VarNameDecl
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>($1);
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
       $$ = new VarBinding(LOC(@$), static_cast<QName*>($1), $3);
    }
  ;

/*_______________________________________________________________________
 *                                                                       *
 *  Try-Catch productions                                                *
 *  [http://www.w3.org/TR/xqupdate/]                                     *
 *                                                                       *
 *_______________________________________________________________________*/

TryExpr :
        TRY LBRACE Expr RBRACE CatchListExpr
        {
            $$ = new TryExpr( LOC(@$), $3, $5 );
        }
    ;

CatchListExpr :
        CatchExpr
        {
            CatchListExpr *cle = new CatchListExpr( LOC(@$) );
            cle->push_back( static_cast<CatchExpr*>($1) );
            $$ = cle;
        }
  |     CatchListExpr CatchExpr
        {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>($1);
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>($2) );
            $$ = $1;
        }
  ;

CatchExpr :
    CATCH NameTestList BracedExpr
    {
       $$ = new CatchExpr(LOC(@$), *$2, $3);
       delete $2;
    }
  ;


BracedExpr :
    LBRACE Expr RBRACE
    {
      $$ = $2;
    }
;


NameTestList :
        NameTest
        {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>($1) );
            $$ = ntl;
        }
    |   NameTestList VBAR NameTest
        {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>($1);
            ntl->push_back( static_cast<NameTest*>($3) );
            $$ = ntl;
        }
    ;


/*_______________________________________________________________________
 *                                                                       *
 *  Full-text productions                                                *
 *  [http://www.w3.org/TR/xpath-full-text-10/]                           *
 *                                                                       *
 *_______________________________________________________________________*/

FTSelection :
        FTOr opt_FTPosFilter_list
        {
            $$ = new FTSelection( LOC(@$), $1, $2 );
            delete $2;
        }
    ;

opt_FTPosFilter_list :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTPosFilter_list
        {
            $$ = $1;
        }
    ;

FTPosFilter_list :
        FTPosFilter
        {
            $$ = new FTSelection::pos_filter_list_t;
            $$->push_back( dynamic_cast<FTPosFilter*>($1) );
        }
    |   FTPosFilter_list FTPosFilter
        {
            $1->push_back( dynamic_cast<FTPosFilter*>($2) );
            $$ = $1;
        }
    ;

FTOr :
        FTAnd
        {
            $$ = $1;
        }
    |   FTOr FTOR FTAnd
        {
            $$ = new FTOr( LOC(@$), $1, $3 );
        }
    ;

FTAnd :
        FTMildNot
        {
            $$ = $1;
        }
    |   FTAnd FTAND FTMildNot
        {
            $$ = new FTAnd( LOC(@$), $1, $3 );
        }
    ;

FTMildNot :
        FTUnaryNot
        {
            $$ = $1;
        }
    |   FTMildNot NOT _IN FTUnaryNot
        {
            $$ = new FTMildNot( LOC(@$), $1, $4 );
        }
    ;

FTUnaryNot :
        FTPrimaryWithOptions
        {
            $$ = $1;
        }
    |   FTNOT FTPrimaryWithOptions
        {
            $$ = new FTUnaryNot(
                LOC(@$), dynamic_cast<FTPrimaryWithOptions*>($2)
            );
        }
    ;

FTPrimaryWithOptions :
        FTPrimary opt_FTMatchOptions opt_FTWeight
        {
            $$ = new FTPrimaryWithOptions(
                LOC(@$),
                dynamic_cast<FTPrimary*>($1),
                dynamic_cast<FTMatchOptions*>($2),
                dynamic_cast<FTWeight*>($3)
            );
        }
    ;

opt_FTMatchOptions :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTMatchOptions
        {
            $$ = $1;
        }
    ;

opt_FTWeight :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTWeight
        {
            $$ = $1;
        }
    ;

// [145]
FTWeight :
        WEIGHT LBRACE Expr RBRACE
        {
            $$ = new FTWeight( LOC(@$), dynamic_cast<exprnode*>($3) );
        }
    ;

// [151]
FTPrimary :
        FTWords opt_FTTimes
        {
            $$ = new FTWordsTimes(
                LOC(@$),
                dynamic_cast<FTWords*>($1),
                dynamic_cast<FTTimes*>($2)
            );
        }
    |   LPAR FTSelection RPAR
        {
            $$ = $2;
        }
    |   FTExtensionSelection
        {
            $$ = $1;
        }
    ;

opt_FTTimes :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTTimes
        {
            $$ = $1;
        }
    ;

// [154]
FTExtensionSelection :
        Pragma_list LBRACE opt_FTSelection RBRACE
        {
            $$ = new FTExtensionSelection(
                LOC(@$),
                dynamic_cast<PragmaList*>($1),
                dynamic_cast<FTSelection*>($3)
            );
        }
    ;

opt_FTSelection :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTSelection
        {
            $$ = $1;
        }
    ;

// [152]
FTWords :
        FTWordsValue opt_FTAnyallOption
        {
            $$ = new FTWords(
                LOC(@$),
                dynamic_cast<FTWordsValue*>($1),
                dynamic_cast<FTAnyallOption*>($2)
            );
        }
    ;

// [153]
FTWordsValue :
        Literal
        {
            $$ = new FTWordsValue(
                LOC(@$), static_cast<StringLiteral*>($1), NULL
            );
        }
    |   LBRACE Expr RBRACE
        {
            $$ = new FTWordsValue(
                LOC(@$), NULL, dynamic_cast<exprnode*>($2)
            );
        }
    ;

opt_FTAnyallOption :
        /* empty */
        {
            $$ = new FTAnyallOption( LOC(@$), ft_anyall_mode::any );
        }
    |   FTAnyallOption
        {
            $$ = $1;
        }
    ;

// [155]
FTAnyallOption :
        ANY opt_word
        {
            $$ = new FTAnyallOption( LOC(@$), $2 );
        }
    |   ALL opt_words
        {
            $$ = new FTAnyallOption( LOC(@$), $2 );
        }
    |   PHRASE
        {
            $$ = new FTAnyallOption( LOC(@$), ft_anyall_mode::phrase );
        }
    ;

opt_word :
        /* empty */
        {
            $$ = ft_anyall_mode::any;
        }
    |   WORD
        {
            $$ = ft_anyall_mode::any_word;
        }
    ;

opt_words :
        /* empty */
        {
            $$ = ft_anyall_mode::all;
        }
    |   WORDS
        {
            $$ = ft_anyall_mode::all_words;
        }
    ;

// [158]
FTPosFilter :
        FTOrder
        {
            $$ = $1;
        }
    |   FTWindow
        {
            $$ = $1;
        }
    |   FTDistance
        {
            $$ = $1;
        }
    |   FTScope
        {
            $$ = $1;
        }
    |   FTContent
        {
            $$ = $1;
        }
    ;

// [159]
FTOrder :
        ORDERED
        {
            $$ = new FTOrder( LOC(@$) );
        }
    ;

// [160]
FTWindow :
        WINDOW AdditiveExpr FTUnit
        {
            $$ = new FTWindow(
                LOC(@$),
                static_cast<AdditiveExpr*>($2),
                static_cast<FTUnit*>($3)
            );
        }
    ;

// [161]
FTDistance :
        DISTANCE FTRange FTUnit
        {
            $$ = new FTDistance(
                LOC(@$),
                dynamic_cast<FTRange*>($2),
                dynamic_cast<FTUnit*>($3)
            );
        }
    ;

// [162]
FTUnit :
        WORDS
        {
            $$ = new FTUnit( LOC(@$), ft_unit::words );
        }
    |   SENTENCES
        {
            $$ = new FTUnit( LOC(@$), ft_unit::sentences );
        }
    |   PARAGRAPHS
        {
            $$ = new FTUnit( LOC(@$), ft_unit::paragraphs );
        }
    ;

// [166]
FTMatchOptions :
        USING FTMatchOption
        {
            FTMatchOptions *mo = new FTMatchOptions( LOC(@$) );
            mo->push_back( dynamic_cast<FTMatchOption*>($2) );
            $$ = mo;
        }
    |   FTMatchOptions USING FTMatchOption
        {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>($1);
            mo->push_back( dynamic_cast<FTMatchOption*>($3) );
            $$ = $1;
        }
    ;

// [167]
FTMatchOption :
        FTCaseOption
        {
            $$ = $1;
        }
    |   FTDiacriticsOption
        {
            $$ = $1;
        }
    |   FTExtensionOption
        {
            $$ = $1;
        }
    |   FTLanguageOption
        {
            $$ = $1;
        }
    |   FTStemOption
        {
            $$ = $1;
        }
    |   FTStopWordOption
        {
            $$ = $1;
        }
    |   FTThesaurusOption
        {
            $$ = $1;
        }
    |   FTWildCardOption
        {
            $$ = $1;
        }
    ;

// [168]
FTCaseOption :
        CASE SENSITIVE
        {
            $$ = new FTCaseOption( LOC(@$), ft_case_mode::sensitive );
        }
    |   CASE INSENSITIVE
        {
            $$ = new FTCaseOption( LOC(@$), ft_case_mode::insensitive );
        }
    |   LOWERCASE
        {
            $$ = new FTCaseOption( LOC(@$), ft_case_mode::lower );
        }
    |   UPPERCASE
        {
            $$ = new FTCaseOption( LOC(@$), ft_case_mode::upper );
        }
    ;

// [169]
FTDiacriticsOption :
        DIACRITICS SENSITIVE
        {
            $$ = new FTDiacriticsOption(
                LOC(@$), ft_diacritics_mode::sensitive
            );
        }
    |   DIACRITICS INSENSITIVE
        {
            $$ = new FTDiacriticsOption(
                LOC(@$), ft_diacritics_mode::insensitive
            );
        }
    ;

// [178]
FTExtensionOption :
        OPTION QNAME STRING_LITERAL
        {
            $$ = new FTExtensionOption(
                LOC(@$), static_cast<QName*>($2), SYMTAB($3)
            );
        }
    ;

// [170]
FTStemOption :
        STEMMING
        {
            $$ = new FTStemOption( LOC(@$), ft_stem_mode::stemming );
        }
    |   NO STEMMING
        {
            $$ = new FTStemOption( LOC(@$), ft_stem_mode::no_stemming );
        }
    ;

// [171]
FTThesaurusOption :
        THESAURUS FTThesaurusID_or_default
        {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( $2 ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>($2) );
            }
            $$ = new FTThesaurusOption( LOC(@$), til, !til );
            delete til;
        }
    |   THESAURUS LPAR FTThesaurusID_or_default opt_FTThesaurus_list RPAR
        {
            FTThesaurusOption::thesaurus_id_list_t *til = $4;
            if ( $3 ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>($3) );
            }
            $$ = new FTThesaurusOption( LOC(@$), til, !$3 );
            delete til;
        }
    |   NO THESAURUS
        {
            $$ = new FTThesaurusOption( LOC(@$), NULL, false, true );
        }
    ;

FTThesaurusID_or_default :
        FTThesaurusID
        {
            $$ = $1;
        }
    |   DEFAULT
        {
            $$ = NULL;
        }
    ;

opt_FTThesaurus_list :
        /* empty */
        {
            $$ = NULL;
        }
    |   COMMA FTThesaurus_list
        {
            $$ = $2;
        }
    ;

FTThesaurus_list :
        FTThesaurusID
        {
            $$ = new FTThesaurusOption::thesaurus_id_list_t;
            $$->push_back( dynamic_cast<FTThesaurusID*>($1) );
        }
    |   FTThesaurus_list COMMA FTThesaurusID
        {
            $1->push_back( dynamic_cast<FTThesaurusID*>($3) );
            $$ = $1;
        }
    ;

// [172]
FTThesaurusID :
        AT STRING_LITERAL opt_relationship opt_levels
        {
            $$ = new FTThesaurusID(
                LOC(@$), SYMTAB($2), SYMTAB($3), dynamic_cast<FTRange*>($4)
            );
        }
    ;

opt_relationship :
        /* empty */
        {
            $$ = NULL;
        }
    |   RELATIONSHIP STRING_LITERAL
        {
            $$ = $2;
        }
    ;

opt_levels :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTRange LEVELS
        {
            $$ = $1;
        }
    ;

// [173]
FTStopWordOption :
        STOP WORDS FTStopWords opt_FTStopWordsInclExcl_list
        {
            $$ = new FTStopWordOption(
                LOC(@$),
                dynamic_cast<FTStopWords*>($3), $4,
                ft_stop_words_mode::with
            );
            delete $4;
        }
    |   STOP WORDS DEFAULT opt_FTStopWordsInclExcl_list
        {
            $$ = new FTStopWordOption(
                LOC(@$), NULL, $4, ft_stop_words_mode::with_default
            );
            delete $4;
        }
    |   NO STOP WORDS
        {
            $$ = new FTStopWordOption(
                LOC(@$), NULL, NULL, ft_stop_words_mode::without
            );
        }
    ;

// [174]
FTStopWords :
        AT STRING_LITERAL
        {
            $$ = new FTStopWords( LOC(@$), SYMTAB($2), NULL );
        }
    |   LPAR STRING_LITERAL_list RPAR
        {
            $$ = new FTStopWords( LOC(@$), "", $2 );
        }
    ;

STRING_LITERAL_list :
        STRING_LITERAL
        {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB($1) );
            $$ = sl;
        }
    |   STRING_LITERAL_list COMMA STRING_LITERAL
        {
            if ( $1 )
                $1->push_back( SYMTAB($3) );
            $$ = $1;
        }
    ;

opt_FTStopWordsInclExcl_list :
        /* empty */
        {
            $$ = NULL;
        }
    |   FTStopWordsInclExcl_list
        {
            $$ = $1;
        }
    ;

FTStopWordsInclExcl_list :
        FTStopWordsInclExcl
        {
            $$ = new FTStopWordOption::incl_excl_list_t;
            $$->push_back( dynamic_cast<FTStopWordsInclExcl*>($1) );
        }
    |   FTStopWordsInclExcl_list FTStopWordsInclExcl
        {
            FTStopWordOption::incl_excl_list_t *iel = $1;
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>($2) );
            $$ = iel;
        }
    ;

// [175]
FTStopWordsInclExcl :
        UNION FTStopWords
        {
            $$ = new FTStopWordsInclExcl(
                LOC(@$),
                dynamic_cast<FTStopWords*>($2),
                ft_stop_words_unex::union_
            );
        }
    |   EXCEPT FTStopWords
        {
            $$ = new FTStopWordsInclExcl(
                LOC(@$),
                dynamic_cast<FTStopWords*>($2),
                ft_stop_words_unex::except
            );
        }
    ;

// [176]
FTLanguageOption :
        LANGUAGE STRING_LITERAL
        {
            $$ = new FTLanguageOption( LOC(@$), SYMTAB($2) );
        }
    ;

// [177]
FTWildCardOption :
        WILDCARDS
        {
            $$ = new FTWildCardOption( LOC(@$), ft_wild_card_mode::with );
        }
    |   NO WILDCARDS
        {
            $$ = new FTWildCardOption( LOC(@$), ft_wild_card_mode::without );
        }
    ;

// [165]
FTContent :
        AT START
        {
            $$ = new FTContent( LOC(@$), ft_content_mode::at_start );
        }
    |   AT END
        {
            $$ = new FTContent( LOC(@$), ft_content_mode::at_end );
        }
    |   ENTIRE CONTENT
        {
            $$ = new FTContent( LOC(@$), ft_content_mode::entire );
        }
    ;

// [156]
FTTimes :
        OCCURS FTRange TIMES
        {
            $$ = new FTTimes( LOC(@$), dynamic_cast<FTRange*>($2) );
        }
    ;

// [157]
FTRange :
        EXACTLY AdditiveExpr
        {
            $$ = new FTRange( LOC(@$), ft_range_mode::exactly, $2 );
        }
    |   AT LEAST AdditiveExpr
        {
            $$ = new FTRange( LOC(@$), ft_range_mode::at_least, $3 );
        }
    |   AT MOST AdditiveExpr
        {
            $$ = new FTRange( LOC(@$), ft_range_mode::at_most, $3 );
        }
    |   FROM AdditiveExpr TO AdditiveExpr
        {
            $$ = new FTRange( LOC(@$), ft_range_mode::from_to, $2, $4 );
        }
    ;

// [163]
FTScope :
        SAME FTBigUnit
        {
            $$ = new FTScope(
                LOC(@$),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>($2)
            );
        }
    |   DIFFERENT FTBigUnit
        {
            $$ = new FTScope(
                LOC(@$),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>($2)
            );
        }
    ;

// [164]
FTBigUnit :
        SENTENCE
        {
            $$ = new FTBigUnit( LOC(@$), ft_big_unit::sentence );
        }
    |   PARAGRAPH
        {
            $$ = new FTBigUnit( LOC(@$), ft_big_unit::paragraph );
        }
    ;

// [179]
FTIgnoreOption :
        WITHOUT CONTENT UnionExpr
        {
            $$ = new FTIgnoreOption( LOC(@$), static_cast<UnionExpr*>($3) );
        }
    ;


/*_______________________________________________________________________
 *                                                                       *
 *  All QNames                                                           *
 *                                                                       *
 *_______________________________________________________________________*/
URI_LITERAL :
        STRING_LITERAL
    ;

NCNAME :
        NCNAME_SVAL
    |   QNAME
        {
          auto_ptr<QName> lQName( static_cast<QName*>($1) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error(@1, "A NCName is expected, found a QName");
            YYERROR;
          }
          $$ = SYMTAB_PUT(tmp.c_str());
        }
    ;

QNAME :
        FUNCTION_NAME
    |   ATTRIBUTE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("attribute"))); }
    |   COMMENT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("comment"))); }
    |   DOCUMENT_NODE           { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("document-node"))); }
    |   ELEMENT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("element"))); }
    |   ITEM                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("item"))); }
    |   IF                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("if"))); }
    |   NODE                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("node"))); }
    |   PROCESSING_INSTRUCTION  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    |   SCHEMA_ATTRIBUTE        { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    |   SCHEMA_ELEMENT          { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("schema-element"))); }
    |   TEXT                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("text"))); }
    |   TYPESWITCH              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    |   SWITCH                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("switch"))); }
    |   EMPTY_SEQUENCE          { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    |   WHILE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("while"))); }
    ;

FUNCTION_NAME :
        EQNAME
    |   QNAME_SVAL              { $$ = new QName(LOC(@$), SYMTAB($1)); }
    |   XQUERY                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("xquery"))); }
    |   _EMPTY                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("empty"))); }
    |   BOUNDARY_SPACE          { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    |   FT_OPTION               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ft-option"))); }
    |   BASE_URI                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("base-uri"))); }
    |   LAX                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("lax"))); }
    |   _STRICT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("strict"))); }
    |   IDIV                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("idiv"))); }
    |   DOCUMENT                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("document"))); }
    |   FTNOT                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ftnot"))); }
    |   NOT                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("not"))); }
    |   SENSITIVE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("sensitive"))); }
    |   INSENSITIVE             { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("insensitive"))); }
    |   DIACRITICS              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("diacritics"))); }
    |   WITHOUT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("without"))); }
    |   STEMMING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("stemming"))); }
    |   THESAURUS               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    |   STOP                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("stop"))); }
    |   WILDCARDS               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("wildcards"))); }
    |   ENTIRE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("entire"))); }
    |   CONTENT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("content"))); }
    |   WORD                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("word"))); }
    |   START                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("start"))); }
    |   END                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("end"))); }
    |   MOST                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("most"))); }
    |   SKIP                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("skip"))); }
    |   COPY                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("copy"))); }
    |   GENERAL                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("general"))); }
    |   VALUE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("value"))); }
    |   VAL_EQ                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("eq"))); }
    |   VAL_NE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ne"))); }
    |   VAL_LT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("lt"))); }
    |   VAL_LE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("le"))); }
    |   VAL_GT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("gt"))); }
    |   VAL_GE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ge"))); }
    |   AT                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("at"))); }
    |   CONTEXT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("context"))); }
    |   VARIABLE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("variable"))); }
    |   RETURN                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("return"))); }
    |   FOR                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("for"))); }
    |   ALLOWING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("allowing"))); }
    |   SLIDING                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("sliding"))); }
    |   TUMBLING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("tumbling"))); }
    |   PREVIOUS                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("previous"))); }
    |   NEXT                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("next"))); }
    |   ONLY                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("only"))); }
    |   WHEN                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("when"))); }
    |   COUNT                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("count"))); }
    |   _IN                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("in"))); }
    |   LET                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("let"))); }
    |   WHERE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("where"))); }
    |   BY                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("by"))); }
    |   GROUP                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("group"))); }
    |   ORDER                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("order"))); }
    |   STABLE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("stable"))); }
    |   ASCENDING               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ascending"))); }
    |   DESCENDING              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("descending"))); }
    |   GREATEST                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("greatest"))); }
    |   LEAST                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("least"))); }
    |   COLLATION               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("collation"))); }
    |   SOME                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("some"))); }
    |   EVERY                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("every"))); }
    |   SATISFIES               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("satisfies"))); }
    |   CASE                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("case"))); }
    |   AS                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("as"))); }
    |   THEN                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("then"))); }
    |   ELSE                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("else"))); }
    |   OR                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("or"))); }
    |   AND                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("and"))); }
    |   INSTANCE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("instance"))); }
    |   OF                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("of"))); }
    |   CASTABLE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("castable"))); }
    |   TO                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("to"))); }
    |   DIV                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("div"))); }
    |   MOD                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("mod"))); }
    |   UNION                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("union"))); }
    |   INTERSECT               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("intersect"))); }
    |   EXCEPT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("except"))); }
    |   VALIDATE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("validate"))); }
    |   TYPE                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("type"))); }
    |   CAST                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("cast"))); }
    |   TREAT                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("treat"))); }
    |   IS                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("is"))); }
    |   PRESERVE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("preserve"))); }
    |   STRIP                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("strip"))); }
    |   NAMESPACE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("namespace"))); }
    |   EXTERNAL                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("external"))); }
    |   ENCODING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("encoding"))); }
    |   NO_PRESERVE             { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    |   INHERIT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("inherit"))); }
    |   NO_INHERIT              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    |   DECLARE                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("declare"))); }
    |   CONSTRUCTION            { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("construction"))); }
    |   ORDERING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ordering"))); }
    |   DEFAULT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("default"))); }
    |   COPY_NAMESPACES         { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    |   OPTION                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("option"))); }
    |   VERSION                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("version"))); }
    |   IMPORT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("import"))); }
    |   SCHEMA                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("schema"))); }
    |   MODULE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("module"))); }
    |   FUNCTION                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("function"))); }
    |   SCORE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("score"))); }
    |   CONTAINS                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("contains"))); }
    |   WEIGHT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("weight"))); }
    |   WINDOW                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("window"))); }
    |   DISTANCE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("distance"))); }
    |   OCCURS                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("occurs"))); }
    |   TIMES                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("times"))); }
    |   SAME                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("same"))); }
    |   DIFFERENT               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("different"))); }
    |   LOWERCASE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("lowercase"))); }
    |   UPPERCASE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("uppercase"))); }
    |   RELATIONSHIP            { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("relationship"))); }
    |   LEVELS                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("levels"))); }
    |   LANGUAGE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("language"))); }
    |   ANY                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("any"))); }
    |   ALL                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("all"))); }
    |   EXACTLY                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("exactly"))); }
    |   FROM                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("from"))); }
    |   WORDS                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("words"))); }
    |   SENTENCES               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("sentences"))); }
    |   SENTENCE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("sentence"))); }
    |   PHRASE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("phrase"))); }
    |   PARAGRAPH               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("paragraph"))); }
    |   PARAGRAPHS              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    |   REPLACE                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("replace"))); }
    |   MODIFY                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("modify"))); }
    |   FIRST                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("first"))); }
    |   INSERT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("insert"))); }
    |   BEFORE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("before"))); }
    |   AFTER                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("after"))); }
    |   REVALIDATION            { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("revalidation"))); }
    |   WITH                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("with"))); }
    |   NODES                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("nodes"))); }
    |   RENAME                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("rename"))); }
    |   LAST                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("last"))); }
    |   _DELETE                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("delete"))); }
    |   INTO                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("into"))); }
    |   SIMPLE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("simple"))); }
    |   SEQUENTIAL              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("sequential"))); }
    |   UPDATING                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("updating"))); }
    |   ORDERED                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ordered"))); }
    |   UNORDERED               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("unordered"))); }
    |   RETURNING               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("returning"))); }
    |   EXIT                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("exit"))); }
    |   LOOP                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("loop"))); }
    |   BREAK                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("break"))); }
    |   CONTINUE                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("continue"))); }
    |   TRY                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("try"))); }
    |   CATCH                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("catch"))); }
    |   USING                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("using"))); }
    |   SET                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("set"))); }
    |   INDEX                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("index"))); }
    |   UNIQUE                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("unique"))); }
    |   NON                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("non"))); }
    |   ON                      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("on"))); }
    |   RANGE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("range"))); }
    |   EQUALITY                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("equality"))); }
    |   MANUALLY                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("manually"))); }
    |   AUTOMATICALLY           { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("automatically"))); }
    |   MAINTAINED              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("maintained"))); }
    |   DECIMAL_FORMAT          { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    |   DECIMAL_SEPARATOR       { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    |   GROUPING_SEPARATOR      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    |   INFINITY_VALUE          { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("infinity"))); }
    |   MINUS_SIGN              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    |   NaN                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("NaN"))); }
    |   PERCENT                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("percent"))); }
    |   PER_MILLE               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("per-mille"))); }
    |   ZERO_DIGIT              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    |   DIGIT                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("digit"))); }
    |   PATTERN_SEPARATOR       { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    |   COLLECTION              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("collection"))); }
    |   CONSTOPT                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("const"))); }
    |   APPEND_ONLY             { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("append-only"))); }
    |   QUEUE                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("queue"))); }
    |   MUTABLE                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("mutable"))); }
    |   READ_ONLY               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("read-only"))); }
    |   INTEGRITY               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("integrity"))); }
    |   CONSTRAINT              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("constraint"))); }
    |   CHECK                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("check"))); }
    |   KEY                     { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("key"))); }
    |   FOREACH                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("foreach"))); }
    |   FOREIGN                 { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("foreign"))); }
    |   KEYS                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("keys"))); }
    |   ANCESTOR                { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ancestor"))); }
    |   CHILD                   { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("child"))); }
    |   DESCENDANT              { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("descendant"))); }
    |   PARENT                  { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("parent"))); }
    |   PRECEDING               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("preceding"))); }
    |   SELF                    { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("self"))); }
    |   FOLLOWING               { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("following"))); }
    |   ANCESTOR_OR_SELF        { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    |   DESCENDANT_OR_SELF      { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    |   FOLLOWING_SIBLING       { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    |   PRECEDING_SIBLING       { $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    ;

// [196]
EQNAME :
        URI_LITERAL COLON NCNAME
        {
          // EQName's namespace URI value is whitespace normalized according to the rules for the xs:anyURI type
          std::string uri = "\"" + SYMTAB($1) + "\"";
          std::string eqname = SYMTAB(driver.symtab.put_uri(uri.c_str(), uri.size())) + ":" + SYMTAB($3);
          $$ = new QName(LOC(@$), SYMTAB(SYMTAB_PUT(eqname.c_str())), true);
        }
    |   EQNAME_SVAL	{ $$ = new QName(LOC(@$), SYMTAB($1), true); }
    ;


%%

namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba
