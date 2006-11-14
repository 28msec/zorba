/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery.y,v 1.2 2006/11/14 05:24:43 Paul Pedersen Exp $
 *
 */

%{

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const unsigned debug = 0;


#if defined(NEW_BISON_VERSION)
typedef struct {
  Handle<ParseNode> node;
  Handle<Expr> expr;
  Handle<Value> xval;
  unsigned sval;
} xqueryYYSTYPE;
#endif


#define YYERROR_VERBOSE
#define lineno lexer.lineno
#define YYSTYPE xqpYYSTYPE
#define yyparse xqp

%}


%pure_parser

%union {
  node* node;
  expr_node* expr;
  value* val;
  char* sval;
}


/* tokens that contain embedded string literals */
/* -------------------------------------------- */
%token <sval> APOS_ATTR_CONTENT
%token <sval> ATTRIBUTE_QNAME_LBRACE
%token <sval> AT_URI_LITERAL
%token <sval> CHAR_LITERAL
%token <sval> CHAR_REF_LITERAL
%token <sval> ELEMENT_CONTENT
%token <sval> ELEMENT_QNAME_LBRACE
%token <sval> ELEM_WILDCARD
%token <sval> ENTITY_REF
%token <sval> EXPR_COMMENT_LITERAL
%token <sval> NCNAME
%token <sval> PI_NCNAME_LBRACE
%token <sval> PI_TARGET_LITERAL
%token <sval> PRAGMA_LITERAL
%token <sval> PREFIX_WILDCARD
%token <sval> QNAME
%token <sval> QUOTE_ATTR_CONTENT
%token <sval> STRING_LITERAL
%token <sval> URI_LITERAL
%token <sval> VARNAME
%token <sval> VALIDATE_MODE
%token <sval> XML_COMMENT_LITERAL

/* simple tokens */
/* ------------- */
%token ANCESTOR_AXIS
%token ANCESTOR_OR_SELF_AXIS
%token AND
%token APOS
%token AS
%token ASCENDING
%token AT
%token ATTRIBUTE
%token ATTRIBUTE_AXIS
%token ATTRIBUTE_LBRACE
%token ATTRIBUTE_LPAR
%token AT_SIGN
%token CASE
%token CASTABLE_AS
%token CAST_AS
%token CDATA_BEGIN
%token CDATA_END
%token CHILD_AXIS
%token COLLATION
%token COMMA
%token COMMENT_BEGIN
%token COMMENT_END
%token COMMENT_LBRACE
%token COMMENT_LPAR
%token DECIMAL_LITERAL
%token DECLARE_BASE_URI
%token DECLARE_BOUNDARY_SPACE
%token DECLARE_CONSTRUCTION
%token DECLARE_COPY_NAMESPACES
%token DECLARE_DEFAULT_COLLATION
%token DECLARE_DEFAULT_ELEMENT
%token DECLARE_DEFAULT_FUNCTION
%token DECLARE_DEFAULT_ORDER
%token DECLARE_FUNCTION
%token DECLARE_NAMESPACE
%token DECLARE_OPTION
%token DECLARE_ORDERING
%token DECLARE_VARIABLE_DOLLAR
%token DEFAULT
%token DEFAULT_ELEMENT
%token DESCENDANT_AXIS
%token DESCENDANT_OR_SELF_AXIS
%token DESCENDING
%token DIV
%token DOCUMENT_LBRACE
%token DOCUMENT_NODE_LPAR
%token DOLLAR
%token DOT
%token DOT_DOT
%token DOUBLE_LBRACE
%token DOUBLE_LITERAL
%token DOUBLE_RBRACE
%token ELEMENT_LBRACE
%token ELEMENT_LPAR
%token ELSE
%token EMPTY_GREATEST
%token EMPTY_LEAST
%token ENCODING
%token EQ
%token ESCAPE_APOS
%token ESCAPE_QUOTE
%token EVERY_DOLLAR
%token EXCEPT
%token EXTERNAL
%token FOLLOWING_AXIS
%token FOLLOWING_SIBLING_AXIS
%token FOLLOWS
%token FOR_DOLLAR
%token F_EQ
%token F_GE
%token F_GT
%token F_LE
%token F_LT
%token F_NE
%token GE
%token GETS
%token GT
%token HOOK
%token IDIV
%token IF_LPAR
%token IMPORT_MODULE
%token IMPORT_SCHEMA
%token IN
%token INHERIT
%token INSTANCE_OF
%token INTEGER_LITERAL
%token INTERSECT
%token IS
%token ITEM_TEST
%token LBRACE
%token LBRACK
%token LE
%token LEADING_LONE_SLASH
%token LET_DOLLAR
%token LPAR
%token LT
%token LTS
%token MINUS
%token MOD
%token MODULE_NAMESPACE
%token NAN
%token NAMESPACE
%token NE
%token NODE_LPAR
%token NOT_OPERATOR_KEYWORD
%token NO_INHERIT
%token NO_PRESERVE
%token OR
%token ORDERED
%token ORDERED_LBRACE
%token ORDER_BY
%token PARENT_AXIS
%token PI_BEGIN
%token PI_END
%token PI_LBRACE
%token PI_LPAR
%token PI_TARGET
%token PLUS
%token PRAGMA_BEGIN
%token PRAGMA_END
%token PRECEDES
%token PRECEDING_AXIS
%token PRECEDING_SIBLING_AXIS
%token PRESERVE
%token PROCESSING_INSTRUCTION
%token QUOTE
%token RBRACE
%token RBRACK
%token RETURN
%token RPAR
%token RPAR_AS
%token SATISFIES
%token SCHEMA_ATTRIBUTE_LPAR
%token SCHEMA_ELEMENT_LPAR
%token SELF_AXIS
%token SEMI
%token SGT
%token SLASH
%token SLASH_SLASH
%token SOME_DOLLAR
%token STABLE_ORDER_BY
%token STAR
%token START_TAG
%token STRIP
%token TEXT_LBRACE
%token TEXT_LPAR
%token THEN
%token TO
%token TREAT_AS
%token TYPESWITCH_LPAR
%token UNION
%token UNORDERED
%token UNORDERED_LBRACE
%token UNRECOGNIZED
%token VALIDATE_LBRACE
%token VBAR
%token VOID_TEST
%token WHERE
%token XML_COMMENT_BEGIN
%token XML_COMMENT_END
%token XQUERY_VERSION


/* update-related */
/* -------------- */
%token DECLARE_REVALIDATION_MODE
%token DO_INSERT
%token DO_DELETE
%token DO_REPLACE
%token DO_RENAME
%token INTO
%token FIRST_INTO
%token LAST_INTO
%token AFTER
%token BEFORE
%token VALUE_OF
%token WITH
%token TRANSFORM_COPY_DOLLAR 
%token MODIFY 
%token COMMA_DOLLAR 


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
%type <node> GeneralCompExpr
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
%type <node> NodeCompExpr
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
%type <node> ValueCompExpr
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

/* update-related */
/* -------------- */
%type <node> RevalidationDecl
%type <node> InsertExpr
%type <node> DeleteExpr
%type <node> ReplaceExpr
%type <node> RenameExpr
%type <node> TransformExpr
%type <node> VarNameList


/* Precedence */
%nonassoc BASE
%left OR


%start Module

%%


/*______________________________________________________________________

	Code pattern:

	NonTerminal1  TOKEN  NonTerminal2
		{
			NonTerminal* nt1_p = dynamic_cast<NonTerminal1*>(&$1);
				// &$1 returns the pointer within rchandle<exprnode> $1
			nt1_p->push_back(dynamic_cast<NonTerminal2*>(&$2));
				// &$2 returns the pointer within rchandle<exprnode> $2
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
			$$ = new MainModule(
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
		MODULE_NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
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
			$$ = new SIND_DeclList(lineno, dynamic_cast<SIND_Decl*>(&$1));
		}
	| SIND_DeclList  SEMI  SIND_Decl
		{
			SIND_DeclList* sindList_p = dynamic_cast<SIND_DeclList*>(&$1);
			sindList_p->push_back(dynamic_cast<SIND_Decl*>(&$3);
			$$ = sindList_p;
		}
	;


// [6b] VFO_DeclList
// -----------------
VFO_DeclList :
		VFO_Decl
		{
			$$ = new VFO_DeclList(lineno(), dynamic_cast<VFO_Decl*>(&$1));
		}
	| VFO_DeclList  SEMI  VFO_Decl
		{
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>(&$1);
			vfoList_p->push_back(dynamic_cast<VFO_Decl*>(&$3);
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
// (Lexical rule)


// [10] NamespaceDecl
// ------------------
NamespaceDecl :
		DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
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
		NAMESPACE  NCNAME  EQ
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
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL
		{
		}
	|	IMPORT_MODULE  URI_LITERAL  AT  URI_LITERALList
		{
		}
	|	IMPORT_MODULE  NAMESPACE  NCNAME  EQ  URI_LITERAL  AT  URI_LITERALList
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
		}
	|	QuantifiedExpr
		{
		}
	|	TypeswitchExpr
		{
		}
	|	IfExpr
		{
		}
	|	OrExpr
		{
		}

		/* update extensions */
	| InsertExpr
		{
		}
	| DeleteExpr
		{
		}
	| RenameExpr
		{
		}
	| ReplaceExpr
		{
		}
	| TransformExpr
		{
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
		}
	|	LetClause
		{
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
	;


// [35] PositionalVar
// ------------------
PositionalVar :
		AT  DOLLAR  VARNAME
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
	|	VarGetsDeclList  COMMA  DOLLAR  VarGetsDecl
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
		QVarInDecl
		{
		}
	|	QVarInDeclList  COMMA  DOLLAR  QVarInDecl
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
ComparisonExpr :
		RangeExpr
		{
		}
	| ValueCompExpr
		{
		}
	| GeneralCompExpr
		{
		}
	| NodeCompExpr
		{
		}
	;


// [48a] ValueCompExpr
// -------------------
ValueCompExpr :
		ComparisonExpr  F_EQ  RangeExpr
		{
		}
	|	ComparisonExpr  F_NE  RangeExpr
		{
		}
	|	ComparisonExpr  F_LT  RangeExpr
		{
		}
	|	ComparisonExpr  F_LE  RangeExpr
		{
		}
	|	ComparisonExpr  F_GT  RangeExpr
		{
		}
	|	ComparisonExpr  F_GE  RangeExpr
		{
		}
	;


// [48b] GeneralCompExpr
// ---------------------
GeneralCompExpr :
		ComparisonExpr  EQ  RangeExpr
		{
		}
	|	ComparisonExpr  NE  RangeExpr
		{
		}
	|	ComparisonExpr  LT  RangeExpr
		{
		}
	|	ComparisonExpr  LE  RangeExpr
		{
		}
	|	ComparisonExpr  GT  RangeExpr
		{
		}
	|	ComparisonExpr  GE  RangeExpr
		{
		}
	;


// [48c] NodeComp
// --------------
NodeCompExpr :
		ComparisonExpr  IS  RangeExpr
		{
		}
	|	ComparisonExpr  PRECEDES  RangeExpr
		{
		}
	| ComparisonExpr  FOLLOWS  RangeExpr
		{
		}
	;




// [49] RangeExpr
// --------------
RangeExpr :
		AdditiveExpr
		{
		}
	|	AdditiveExpr  TO  AdditiveExpr
		{
		}
	;


// [50] AdditiveExpr
// -----------------
AdditiveExpr :
		MultiplicativeExpr
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
		UnionExpr
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
		IntersectExceptExpr
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
		InstanceofExpr
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
/* folded into [48b] */

// [61] ValueComp
// --------------
/* folded into [48a] */

// [62] NodeComp
// -------------
/* folded into [48c] */



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
		StepExpr
		{
		}
	|	RelativePathExpr SLASH  StepExpr
		{
		}
	|	RelativePathExpr SLASH_SLASH  StepExpr
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
		ForwardStep  PredicateList
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
		}
	|	VarRef
		{
		}
	|	ParenthesizedExpr
		{
		}
	|	ContextItemExpr
		{
		}
	|	FunctionCall
		{
		}
	|	Constructor
		{
		}
	|	OrderedExpr
		{
		}
	|	UnorderedExpr
		{
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
		QNAME  LPAR  ArgList  RPAR 	/* gn: parensXQ */
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
	|	START_TAG  QNAME  DirAttributeList GT  DirElemContentList  LTS  QNAME  GT
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
		QNAME  EQ  DirAttributeValue 	/* ws: explicitXQ */
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
		}
	|	CompElemConstructor
		{
		}
	|	CompAttrConstructor
		{
		}
	|	CompTextConstructor
		{
		}
	|	CompCommentConstructor
		{
		}
	|	CompPIConstructor
		{
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
		ItemType
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
		}
	| ElementTest
		{
		}
	| AttributeTest
		{
		}
	| SchemaElementTest
		{
		}
	| SchemaAttributeTest
		{
		}
	| PITest
		{
		}
	| CommentTest
		{
		}
	| TextTest
		{
		}
	| AnyKindTest
		{
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
 *  Update grammar                                                       *
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



%%
