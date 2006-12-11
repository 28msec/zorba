/* -*- mode:: c++ indent-tabs-mode: nil -*-
 *
 *  $Id:: parsenodes.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "parsenodes.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../util/rchandle.h"
#include "xquery_parser.tab.h"

using namespace std;
namespace xqp {




// [1] Module
// ----------
Module::Module(
	rchandle<static_context> _static_context_h)
:
	static_context_h(_static_context_h)
{
}

Module::~Module()
{
}


// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _version,
	std::string const& _encoding)
:
	parsenode(_loc),
	version(_version),
	encoding(_encoding)
{
}

VersionDecl::~VersionDecl()
{
}



// [3] MainModule
// --------------
MainModule::MainModule(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Prolog> _prolog_h,
	rchandle<QueryBody> _query_body_h)
:
	parsenode(_loc),
	prolog_h(_prolog_h),
	query_body_h(_query_body_h)
{
}

MainModule::MainModule(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QueryBody> _query_body_h)
:
	parsenode(_loc),
	prolog_h(NULL),
	query_body_h(_query_body_h)
{
}

MainModule::~MainModule()
{
}



// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ModuleDecl> _decl_h, 
	rchandle<Prolog> _prolog_h)
:
	parsenode(_loc),
	decl_h(_decl_h),
	prolog_h(_prolog_h)
{
}


LibraryModule::~LibraryModule()
{
}



// [5] ModuleDecl
// --------------
ModuleDecl::ModuleDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _prefix,
	std::string const& _target_namespace)
:
	parsenode(_loc),
	prefix(_prefix),
	target_namespace(_target_namespace)
{
}

ModuleDecl::~ModuleDecl()
{
}



// [6] Prolog
// ----------
Prolog::Prolog(
	yy::xquery_parser::location_type const& _loc,
	rchandle<SIND_DeclList> _sind_list_h,
	rchandle<VFO_DeclList> _vfo_list_h)
:
	parsenode(_loc),
	sind_list_h(_sind_list_h),
	vfo_list_h(_vfo_list_h)
{
}

Prolog::~Prolog()
{
}



// [6a] SIDN_DeclList
// ------------------
SIND_DeclList::SIND_DeclList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

SIND_DeclList::~SIND_DeclList()
{
}



// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

VFO_DeclList::~VFO_DeclList()
{
}



// [6c] SIND_Decl
// --------------
SIND_Decl::SIND_Decl(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

SIND_Decl::~SIND_Decl()
{
}



// [6d] VFO_Decl
// -------------
VFO_Decl::VFO_Decl(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

VFO_Decl::~VFO_Decl()
{
}


// [7] Setter
// ----------
Setter::Setter(
	yy::xquery_parser::location_type const& _loc)
:
	SIND_Decl(_loc)
{
}

Setter::~Setter()
{
}



// [8] Import
// ----------
Import::Import(
	yy::xquery_parser::location_type const& _loc)
:
	SIND_Decl(_loc)
{
}
	
Import::~Import()
{
}



// [9] Separator
// -------------
// (Lexical rule)



// [10] NamespaceDecl
// ------------------
NamespaceDecl::NamespaceDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _prefix,
	std::string const& _uri)
:
	SIND_Decl(_loc),
	prefix(_prefix),
	uri(_uri)
{
}

NamespaceDecl::~NamespaceDecl()
{
}



// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
	yy::xquery_parser::location_type const& _loc,
	static_context::boundary_space_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

BoundarySpaceDecl::~BoundarySpaceDecl()
{
}



// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
	yy::xquery_parser::location_type const& _loc,
	enum default_namespace_mode_t _mode,
	std::string const& _default_namespace)
:
	SIND_Decl(_loc),
	mode(_mode),
	default_namespace(_default_namespace)
{
}


DefaultNamespaceDecl::~DefaultNamespaceDecl()
{
}



// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h,
	std::string const& _val)
:
	parsenode(_loc),
	qname_h(_qname_h),
	val(_val)
{
}

OptionDecl::~OptionDecl()
{
}



// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl(
	yy::xquery_parser::location_type const& _loc,
	static_context::ordering_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

OrderingModeDecl::~OrderingModeDecl()
{
}



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
	yy::xquery_parser::location_type const& _loc,
	static_context::order_empty_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

EmptyOrderDecl::~EmptyOrderDecl()
{
}



// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
	yy::xquery_parser::location_type const& _loc,
	rchandle<PreserveMode> _preserve_h,
	rchandle<InheritMode> _inherit_h)
:
	Setter(_loc),
	preserve_h(_preserve_h),
	inherit_h(_inherit_h)
{
}

CopyNamespacesDecl::~CopyNamespacesDecl()
{
}



// [17] PreserveMode
// -----------------
PreserveMode::PreserveMode(
	yy::xquery_parser::location_type const& _loc,
	static_context::copy_ns_mode_t _preserve_mode)
:
	parsenode(_loc),
	preserve_mode(_preserve_mode)
{
}

PreserveMode::~PreserveMode()
{
}



// [18] InheritMode
// ----------------
InheritMode::InheritMode(
	yy::xquery_parser::location_type const& _loc,
	static_context::copy_ns_mode_t _inherit_mode)
:
	parsenode(_loc),
	inherit_mode(_inherit_mode)
{
}

InheritMode::~InheritMode()
{
}



// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string const&  _collation)
:
	Setter(_loc),
	collation(_collation)
{
}

DefaultCollationDecl::~DefaultCollationDecl()
{
}



// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _base_uri)
:
	Setter(_loc),
	base_uri(_base_uri)
{
}

BaseURIDecl::~BaseURIDecl()
{
}



// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
	yy::xquery_parser::location_type const& _loc,
	rchandle<SchemaPrefix> _prefix_h,
	std::string const& _uri,
	rchandle<URILiteralList> _at_list_h)
:
	Import(_loc),
	prefix_h(_prefix_h),
	uri(_uri),
	at_list_h(_at_list_h)
{
}

SchemaImport::~SchemaImport()
{
}



// [21a] URLLiteralList
// --------------------
URILiteralList::URILiteralList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

URILiteralList::~URILiteralList()
{
}



// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix(
	yy::xquery_parser::location_type const& _loc,
	bool _default_b)
:
	parsenode(_loc),
	prefix(""),
	default_b(_default_b)
{
}

SchemaPrefix::SchemaPrefix(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _prefix) 
:
	parsenode(_loc),
	prefix(_prefix),
	default_b(false)
{
}

SchemaPrefix::~SchemaPrefix()
{
}



// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
	yy::xquery_parser::location_type const& _loc,
	std::string const& uri,
	rchandle<URILiteralList> _uri_list_h)
:
	Import(_loc),
	uri_list_h(_uri_list_h)
{
}

ModuleImport::ModuleImport(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _prefix,
	std::string const& _uri,
	rchandle<URILiteralList> _uri_list_h)
:
	Import(_loc),
	prefix(_prefix),
	uri(_uri),
	uri_list_h(_uri_list_h)
{
}

ModuleImport::~ModuleImport()
{
}



// [24] VarDecl
// ------------
VarDecl::VarDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<ExprSingle> _initexpr_h)
:
	parsenode(_loc),
	varname(_varname),
	typedecl_h(_typedecl_h),
	initexpr_h(_initexpr_h)
{
}

VarDecl::~VarDecl()
{
}



// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl(
	yy::xquery_parser::location_type const& _loc,
	enum static_context::boundary_space_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

ConstructionDecl::~ConstructionDecl()
{
}



// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _name_h,
	rchandle<ParamList> _paramlist_h,
	rchandle<SequenceType> _return_type_h,
	rchandle<EnclosedExpr> _body_h,
	enum function_type_t _type)
:
	parsenode(_loc),
	name_h(_name_h),
	paramlist_h(_paramlist_h),
	return_type_h(_return_type_h),
	body_h(_body_h),
	type(_type)
{
}

FunctionDecl::~FunctionDecl()
{
}



// [27] ParamList
// --------------
ParamList::ParamList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

ParamList::~ParamList()
{
}



// [28] Param
// ----------
Param::Param(
	yy::xquery_parser::location_type const& _loc,
	std::string _name,
	rchandle<TypeDeclaration> _typedecl_h)
:
	parsenode(_loc),
	name(_name),
	typedecl_h(_typedecl_h)
{
}

Param::~Param()
{
}



// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

EnclosedExpr::~EnclosedExpr()
{
}



// [30] QueryBody
// --------------
QueryBody::QueryBody(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

QueryBody::~QueryBody()
{
}



// [31] Expr
// ---------
Expr::Expr(
	yy::xquery_parser::location_type const& _loc)
:
	exprnode(_loc)
{
}

Expr::~Expr()
{
}



// [32] ExprSingle
// ---------------
ExprSingle::ExprSingle(
	yy::xquery_parser::location_type const& _loc)
:
	exprnode(_loc)
{
}

ExprSingle::~ExprSingle()
{
}



// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ForLetClauseList> _forlet_list_h,
	rchandle<WhereClause> _where_h,
	rchandle<OrderByClause> _orderby_h,
	rchandle<ExprSingle> _return_val_h)
:
	ExprSingle(_loc),
	forlet_list_h(_forlet_list_h),
	where_h(_where_h),
	orderby_h(_orderby_h),
	return_val_h(_return_val_h)
{
}

FLWORExpr::~FLWORExpr()
{
}



// [33a] ForLetClauseList
// ----------------------
ForLetClauseList::ForLetClauseList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

ForLetClauseList::~ForLetClauseList()
{
}



// [33b] ForLetClause
// ------------------
ForLetClause::ForLetClause(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

ForLetClause::~ForLetClause()
{
}



// [34] ForClause
// --------------
ForClause::ForClause(
	yy::xquery_parser::location_type const& _loc,
	rchandle<VarInDeclList> _vardecl_list_h)
:
	ForLetClause(_loc),
	vardecl_list_h(_vardecl_list_h)
{
}

ForClause::~ForClause()
{
}



// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

VarInDeclList::~VarInDeclList()
{
}



// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<PositionalVar> _posvar_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<ExprSingle> _valexpr_h)
:
	parsenode(_loc),
	varname(_varname),
	typedecl_h(_typedecl_h),
	posvar_h(_posvar_h),
	ftscorevar_h(_ftscorevar_h),
	valexpr_h(_valexpr_h)
{
}

VarInDecl::~VarInDecl()
{
}



// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _varname)
:
	parsenode(_loc),
	varname(_varname)
{
}

PositionalVar::~PositionalVar()
{
}



// [36] LetClause
// --------------
LetClause::LetClause(
	yy::xquery_parser::location_type const& _loc,
	rchandle<VarGetsDeclList> _vardecl_list_h)
:
	ForLetClause(_loc),
	vardecl_list_h(_vardecl_list_h)
{
}

LetClause::~LetClause()
{
}



// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

VarGetsDeclList::~VarGetsDeclList()
{
}



// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<ExprSingle> _valexpr_h)
:
	parsenode(_loc),
	varname(_varname),
	typedecl_h(_typedecl_h),
	ftscorevar_h(_ftscorevar_h),
	valexpr_h(_valexpr_h)
{
}

VarGetsDecl::~VarGetsDecl()
{
}


// [36c] FTScoreVar
// ----------------
FTScoreVar::FTScoreVar(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname)
:
	parsenode(_loc),
	varname(_varname)
{
}

FTScoreVar::~FTScoreVar()
{
}



// [37] WhereClause
// ----------------
WhereClause::WhereClause(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _predicate_h)
:
	parsenode(_loc),
	predicate_h(_predicate_h)
{
}

WhereClause::~WhereClause()
{
}



// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause(
	yy::xquery_parser::location_type const& _loc,
	rchandle<OrderSpecList> _spec_list_h,
	bool _stable_b)
:
	parsenode(_loc),
	spec_list_h(_spec_list_h),
	stable_b(_stable_b)
{
}


OrderByClause::OrderByClause(
	yy::xquery_parser::location_type const& _loc,
	rchandle<OrderSpecList> _spec_list_h)
:
	parsenode(_loc),
	spec_list_h(_spec_list_h)
{
}

OrderByClause::~OrderByClause()
{
}



// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

OrderSpecList::~OrderSpecList()
{
}



// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _spec_h,
	rchandle<OrderModifier> _modifier_h)
:
	parsenode(_loc),
	spec_h(_spec_h),
	modifier_h(_modifier_h)
{
}

OrderSpec::~OrderSpec()
{
}



// [41] OrderModifier
// ------------------
OrderModifier::OrderModifier(
	yy::xquery_parser::location_type const& _loc,
	rchandle<OrderDirSpec> _dir_spec_h,
	rchandle<OrderEmptySpec> _empty_spec_h,
	rchandle<OrderCollationSpec> _collation_spec_h)
:
	parsenode(_loc),
	dir_spec_h(_dir_spec_h),
	empty_spec_h(_empty_spec_h),
	collation_spec_h(_collation_spec_h)
{
}

OrderModifier::~OrderModifier()
{
}



// [41a] OrderDirSpec
// ------------------
OrderDirSpec::OrderDirSpec(
	yy::xquery_parser::location_type const& _loc,
	enum dir_spec_t _dir_spec)
:
	parsenode(_loc),
	dir_spec(_dir_spec)
{
}

OrderDirSpec::~OrderDirSpec()
{
}
	


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
	yy::xquery_parser::location_type const& _loc,
	static_context::order_empty_mode_t _empty_order_spec)
:
	parsenode(_loc),
	empty_order_spec(_empty_order_spec)
{
}

OrderEmptySpec::~OrderEmptySpec()
{
}



// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _uri)
:
	parsenode(_loc),
	uri(_uri)
{
}

OrderCollationSpec::~OrderCollationSpec()
{
}



// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr::QuantifiedExpr(
	yy::xquery_parser::location_type const& _loc,
	quantification_mode_t _qmode,
	rchandle<QVarInDeclList> _decl_list_h,
	rchandle<ExprSingle> _expr_h)
:
	exprnode(_loc),
	qmode(_qmode),
	decl_list_h(_decl_list_h),
	expr_h(_expr_h)
{
}

QuantifiedExpr::~QuantifiedExpr()
{
}


// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

QVarInDeclList::~QVarInDeclList()
{
}



// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
	yy::xquery_parser::location_type const& _loc,
	std::string _name,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	typedecl_h(_typedecl_h),
	val_h(_val_h)
{
}

QVarInDecl::~QVarInDecl()
{
}



// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	rchandle<ExprSingle> _default_clause_h)
:
	exprnode(_loc),
	switch_expr_h(_switch_expr_h),
	clause_list_h(_clause_list_h),
	default_clause_h(_default_clause_h)
{
}


TypeswitchExpr::TypeswitchExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	std::string _default_varname,
	rchandle<ExprSingle> _default_clause_h)
:
	exprnode(_loc),
	switch_expr_h(_switch_expr_h),
	clause_list_h(_clause_list_h),
	default_varname(_default_varname),
	default_clause_h(_default_clause_h)
{
}

TypeswitchExpr::~TypeswitchExpr()
{
}



// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

CaseClauseList::~CaseClauseList()
{
}



// [44] CaseClause
// ---------------
CaseClause::CaseClause(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname,
	rchandle<SequenceType> _type_h,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	varname(_varname),
	type_h(_type_h),
	val_h(_val_h)
{
}

CaseClause::~CaseClause()
{
}



// [45] IfExpr
// -----------
IfExpr::IfExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _cond_expr_h,
	rchandle<ExprSingle> _then_expr_h,
	rchandle<ExprSingle> _else_expr_h)
:
	exprnode(_loc),
	cond_expr_h(_cond_expr_h),
	then_expr_h(_then_expr_h),
	else_expr_h(_else_expr_h)
{
}

IfExpr::~IfExpr()
{
}



// [46] OrExpr
// -----------
OrExpr::OrExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<OrExpr> _or_expr_h,
	rchandle<AndExpr> _and_expr_h)
:
	exprnode(_loc),
	or_expr_h(_or_expr_h),
	and_expr_h(_and_expr_h)
{
}

OrExpr::~OrExpr()
{
}



// [47] AndExpr
// ------------
AndExpr::AndExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AndExpr> _and_expr_h,
	rchandle<ComparisonExpr> _comp_expr_h)
:
	exprnode(_loc),
	and_expr_h(_and_expr_h),
	comp_expr_h(_comp_expr_h)
{
}

AndExpr::~AndExpr()
{
}


// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTContainsExpr> _left_h,
	rchandle<ValueComp> _valcomp_h,
	rchandle<FTContainsExpr> _right_h)
:
	exprnode(_loc),
	left_h(_left_h),
	right_h(_right_h),
	valcomp_h(_valcomp_h),
	gencomp_h(NULL),
	nodecomp_h(NULL)
{
}

ComparisonExpr::ComparisonExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTContainsExpr> _left_h,
	rchandle<GeneralComp> _gencomp_h,
	rchandle<FTContainsExpr> _right_h)
:
	exprnode(_loc),
	left_h(_left_h),
	right_h(_right_h),
	valcomp_h(NULL),
	gencomp_h(_gencomp_h),
	nodecomp_h(NULL)
{
}

ComparisonExpr::ComparisonExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTContainsExpr> _left_h,
	rchandle<NodeComp> _nodecomp_h,
	rchandle<FTContainsExpr> _right_h)
:
	exprnode(_loc),
	left_h(_left_h),
	right_h(_right_h),
	valcomp_h(NULL),
	gencomp_h(NULL),
	nodecomp_h(_nodecomp_h)
{
}

ComparisonExpr::~ComparisonExpr()
{
}



// [48a] FTContainsExpr
// --------------------
FTContainsExpr::FTContainsExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<RangeExpr> _range_expr_h,
	rchandle<FTSelection> _ftselect_h,
	rchandle<FTIgnoreOption> _ftignore_h)
:
	exprnode(_loc),
	range_expr_h(_range_expr_h),
	ftselect_h(_ftselect_h),
	ftignore_h(_ftignore_h)
{
}

FTContainsExpr::~FTContainsExpr()
{
}



// [49] RangeExpr
// --------------
RangeExpr::RangeExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AdditiveExpr> _from_expr_h,
	rchandle<AdditiveExpr> _to_expr_h)
:
	exprnode(_loc),
	from_expr_h(_from_expr_h),
	to_expr_h(_to_expr_h)
{
}

RangeExpr::~RangeExpr()
{
}



// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AdditiveExpr> _add_expr_h,
	enum add_op_t _add_op,
	rchandle<MultiplicativeExpr> _mult_expr_h)
:
	exprnode(_loc),
	add_expr_h(_add_expr_h),
	add_op(_add_op),
	mult_expr_h(_mult_expr_h)
{
}

AdditiveExpr::~AdditiveExpr()
{
}



// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<MultiplicativeExpr> _mult_expr_h,
	enum mult_op_t _mult_op,
	rchandle<UnionExpr> _union_expr_h)
:
	exprnode(_loc),
	mult_expr_h(_mult_expr_h),
	mult_op(_mult_op),
	union_expr_h(_union_expr_h)
{
}

MultiplicativeExpr::~MultiplicativeExpr()
{
}



// [52] UnionExpr
// --------------
UnionExpr::UnionExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<UnionExpr> _union_expr_h,
	rchandle<IntersectExceptExpr> _intex_expr_h)
:
	exprnode(_loc),
	union_expr_h(_union_expr_h),
	intex_expr_h(_intex_expr_h)
{
}

UnionExpr::~UnionExpr()
{
}



// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<IntersectExceptExpr> _intex_expr_h,
	enum intex_op_t _intex_op,
	rchandle<InstanceofExpr> _instof_expr_h)
:
	exprnode(_loc),
	intex_expr_h(_intex_expr_h),
	instof_expr_h(_instof_expr_h),
	intex_op(_intex_op)
{
}

IntersectExceptExpr::~IntersectExceptExpr()
{
}



// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<TreatExpr> _treat_expr_h,
	rchandle<SequenceType> _seqtype_h)
:
	exprnode(_loc),
	treat_expr_h(_treat_expr_h),
	seqtype_h(_seqtype_h)
{
}

InstanceofExpr::~InstanceofExpr()
{
}



// [55] TreatExpr
// --------------
TreatExpr::TreatExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<CastableExpr> _castable_expr_h,
	rchandle<SequenceType> _seqtype_h)
:
	exprnode(_loc),
	castable_expr_h(_castable_expr_h),
	seqtype_h(_seqtype_h)
{
}

TreatExpr::~TreatExpr()
{
}



// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<CastExpr> _cast_expr_h,
	rchandle<SingleType> _singletype_h)
:
	exprnode(_loc),
	cast_expr_h(_cast_expr_h),
	singletype_h(_singletype_h)
{
}

CastableExpr::~CastableExpr()
{
}



// [57] CastExpr 	   
// -------------
CastExpr::CastExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<UnaryExpr> _unary_expr_h,
	rchandle<SingleType> _singletype_h)
:
	exprnode(_loc),
	unary_expr_h(_unary_expr_h),
	singletype_h(_singletype_h)
{
}

CastExpr::~CastExpr()
{
}



// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ValueExpr> _value_expr_h,
	rchandle<SignList> _signlist_h)
:
	exprnode(_loc),
	value_expr_h(_value_expr_h),
	signlist_h(_signlist_h)
{
}

UnaryExpr::~UnaryExpr()
{
}



// [58a] SignList
// --------------
SignList::SignList(
	yy::xquery_parser::location_type const& _loc,
	bool _sign)
:
	parsenode(_loc),
	sign(_sign)
{
}

SignList::~SignList()
{
}



// [59] ValueExpr
// --------------
ValueExpr::ValueExpr(
	yy::xquery_parser::location_type const& _loc)
:
	exprnode(_loc)
{
}

ValueExpr::~ValueExpr()
{
}



// [60] GeneralComp
// ----------------
GeneralComp::GeneralComp(
	yy::xquery_parser::location_type const& _loc,
	enum gencomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

GeneralComp::~GeneralComp()
{
}



// [61] ValueComp
// --------------
ValueComp::ValueComp(
	yy::xquery_parser::location_type const& _loc,
	enum valcomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

ValueComp::~ValueComp()
{
}



// [62] NodeComp
// -------------
NodeComp::NodeComp(
	yy::xquery_parser::location_type const& _loc,
	enum nodecomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

NodeComp::~NodeComp()
{
}




// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
	yy::xquery_parser::location_type const& _loc,
	string const& _valmode,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	valmode(_valmode=="lax" ? lax : strict),
	expr_h(_expr_h)
{
}

ValidateExpr::~ValidateExpr()
{
}



// [64] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<PragmaList> _pragma_list_h,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	pragma_list_h(_pragma_list_h),
	expr_h(_expr_h)
{
}

ExtensionExpr::~ExtensionExpr()
{
}



// [64a] PragmaList
// ----------------
PragmaList::PragmaList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

PragmaList::~PragmaList()
{
}



// [65] Pragma
// -----------
Pragma::Pragma(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _name,
	std::string _pragma_lit)
:
	parsenode(_loc),
	name(_name),
	pragma_lit(_pragma_lit)
{
}

Pragma::~Pragma()
{
}



// [66] PragmaContents
// -------------------
/* folded into [65] */



// [67] PathExpr
// -------------
PathExpr::PathExpr(
	yy::xquery_parser::location_type const& _loc,
	enum pathtype_t _type,
	rchandle<RelativePathExpr> _relpath_expr_h)
:
	exprnode(_loc),
	type(_type),
	relpath_expr_h(_relpath_expr_h)
{
}

PathExpr::~PathExpr()
{
}



// [68] RelativePathExpr
// ---------------------
RelativePathExpr::RelativePathExpr(
	yy::xquery_parser::location_type const& _loc,
	enum steptype_t _step_type,
	rchandle<StepExpr> _step_expr_h,
	rchandle<RelativePathExpr> _relpath_expr_h)
:
	exprnode(_loc),
	step_type(_step_type),
	step_expr_h(_step_expr_h),
	relpath_expr_h(_relpath_expr_h)
{
}

RelativePathExpr::~RelativePathExpr()
{
}



// [69] StepExpr
// -------------
StepExpr::StepExpr(
	yy::xquery_parser::location_type const& _loc)
:
	exprnode(_loc)
{
}

StepExpr::~StepExpr()
{
}



// [70] AxisStep
// -------------
AxisStep::AxisStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ForwardStep> _forward_step_h,
	rchandle<PredicateList> _predicate_list_h)
:
	StepExpr(_loc),
	forward_step_h(_forward_step_h),
	reverse_step_h(NULL),
	predicate_list_h(_predicate_list_h)
{
}

AxisStep::AxisStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ReverseStep> _reverse_step_h,
	rchandle<PredicateList> _predicate_list_h)
:
	StepExpr(_loc),
	forward_step_h(NULL),
	reverse_step_h(_reverse_step_h),
	predicate_list_h(_predicate_list_h)
{
}

AxisStep::~AxisStep()
{
}



// [71] ForwardStep
// ----------------
ForwardStep::ForwardStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ForwardAxis> _forward_axis_h,
	rchandle<NodeTest> _node_test_h)
:
	parsenode(_loc),
	forward_axis_h(_forward_axis_h),
	node_test_h(_node_test_h),
	abbrev_step_h(NULL)
{
}

ForwardStep::ForwardStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AbbrevForwardStep> _abbrev_step_h)
:
	parsenode(_loc),
	forward_axis_h(NULL),
	node_test_h(NULL),
	abbrev_step_h(_abbrev_step_h)
{
}

ForwardStep::~ForwardStep()
{
}



// [72] ForwardAxis
// ----------------
ForwardAxis::ForwardAxis(
	yy::xquery_parser::location_type const& _loc,
	enum forward_axis_t _axis)
:
	parsenode(_loc),
	axis(_axis)
{
}

ForwardAxis::~ForwardAxis()
{
}



// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep::AbbrevForwardStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<NodeTest> _node_test_h,
	bool _attr_b)
:
	parsenode(_loc),
	node_test_h(node_test_h),
	attr_b(attr_b)
{
}

AbbrevForwardStep::AbbrevForwardStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<NodeTest> _node_test_h)
:
	parsenode(_loc),
	node_test_h(node_test_h),
	attr_b(false)
{
}

AbbrevForwardStep::~AbbrevForwardStep()
{
}



// [74] ReverseStep
// ----------------
ReverseStep::ReverseStep(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ReverseAxis> _axis_h,
	rchandle<NodeTest> _node_test_h)
:
	parsenode(_loc),
	axis_h(_axis_h),
	node_test_h(_node_test_h)
{
}

ReverseStep::~ReverseStep()
{
}



// [75] ReverseAxis
// ----------------
ReverseAxis::ReverseAxis(
	yy::xquery_parser::location_type const& _loc,
	enum reverse_axis_t _axis)
:
	parsenode(_loc),
	axis(_axis)
{
}

ReverseAxis::~ReverseAxis()
{
}



// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */



// [77] NodeTest
// -------------
NodeTest::NodeTest(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

NodeTest::~NodeTest()
{
}



// [78] NameTest
// -------------
NameTest::NameTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h),
	wild_h(NULL)
{
}

NameTest::NameTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Wildcard> _wild_h)
:
	parsenode(_loc),
	qname_h(NULL),
	wild_h(_wild_h)
{
}

NameTest::~NameTest()
{
}



// [79] Wildcard
// -------------
Wildcard::Wildcard(
	yy::xquery_parser::location_type const& _loc,
	enum wildcard_t _type)
:
	parsenode(_loc),
	type(_type),
	prefix(""),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _prefix)
:
	parsenode(_loc),
	type(Wildcard::wild_prefix),
	prefix(_prefix),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	type(Wildcard::wild_elem),
	prefix(""),
	qname_h(_qname_h)
{
}
	
Wildcard::~Wildcard()
{
}



// [80] FilterExpr
// ---------------
FilterExpr::FilterExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<PrimaryExpr> _primary_h,
	rchandle<PredicateList> _pred_list_h)
:
	StepExpr(_loc),
	primary_h(_primary_h),
	pred_list_h(_pred_list_h)
{
}

FilterExpr::~FilterExpr()
{
}



// [81] PredicateList
// ------------------
PredicateList::PredicateList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

PredicateList::~PredicateList()
{
}



// [82] Predicate
// --------------
Predicate::Predicate(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _pred_h)
:
	exprnode(_loc),
	pred_h(_pred_h)
{
}

Predicate::~Predicate()
{
}



// [83] PrimaryExpr
// ----------------
PrimaryExpr::PrimaryExpr(
	yy::xquery_parser::location_type const& _loc)
:
	exprnode(_loc)
{
}

PrimaryExpr::~PrimaryExpr()
{
}



// [84] Literal
// ------------
Literal::Literal(
	yy::xquery_parser::location_type const& _loc)
:
	PrimaryExpr(_loc)
{
}

Literal::~Literal()
{
}




// [85] NumericLiteral
// -------------------
NumericLiteral::NumericLiteral(
	yy::xquery_parser::location_type const& _loc,
	int _ival)
:
	Literal(_loc),
	type(NumericLiteral::num_integer),
	ival(_ival)
{
}

NumericLiteral::NumericLiteral(
	yy::xquery_parser::location_type const& _loc,
	double _dval)
:
	Literal(_loc),
	type(NumericLiteral::num_double),
	dval(_dval)
{
}

NumericLiteral::NumericLiteral(
	yy::xquery_parser::location_type const& _loc,
	decimal _decval)
:
	Literal(_loc),
	type(NumericLiteral::num_decimal),
	decval(_decval)
{
}

NumericLiteral::~NumericLiteral()
{
}




// [86] VarRef
// -----------
VarRef::VarRef(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname)
:
	PrimaryExpr(_loc),
	varname(_varname)
{
}

VarRef::~VarRef()
{
}




// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

ParenthesizedExpr::~ParenthesizedExpr()
{
}




// [88] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
	yy::xquery_parser::location_type const& _loc)
:
	PrimaryExpr(_loc)
{
}

ContextItemExpr::~ContextItemExpr()
{
}



// [89] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

OrderedExpr::~OrderedExpr()
{
}




// [90] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

UnorderedExpr::~UnorderedExpr()
{
}




// [91] FunctionCall
// -----------------

FunctionCall::FunctionCall(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _fname_h,
	rchandle<ArgList> _arg_list_h)
:
	PrimaryExpr(_loc),
	fname_h(_fname_h),
	arg_list_h(_arg_list_h)
{
}

FunctionCall::~FunctionCall()
{
}




// [91a] ArgList
// -------------
ArgList::ArgList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

ArgList::~ArgList()
{
}




// [92] Constructor
// ----------------
Constructor::Constructor(
	yy::xquery_parser::location_type const& _loc)
:
	PrimaryExpr(_loc)
{
}

Constructor::~Constructor()
{
}




// [93] DirectConstructor
// ----------------------
DirectConstructor::DirectConstructor(
	yy::xquery_parser::location_type const& _loc)
:
	Constructor(_loc)
{
}

DirectConstructor::~DirectConstructor()
{
}


 

// [94] DirElemConstructor
// -----------------------

DirElemConstructor::DirElemConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _elem_name_h,
	rchandle<DirAttributeList> _attr_list_h,
	rchandle<DirElemContentList> _dir_content_list_h)
:
	DirectConstructor(_loc),
	elem_name_h(_elem_name_h),
	attr_list_h(_attr_list_h),
	dir_content_list_h(_dir_content_list_h)
{
}

DirElemConstructor::~DirElemConstructor()
{
}




// [94a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

DirElemContentList::~DirElemContentList()
{
}




// [95] DirAttributeList
// ---------------------
DirAttributeList::DirAttributeList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

DirAttributeList::~DirAttributeList()
{
}




// [95a] DirAttr
// -------------
	
DirAttr::DirAttr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _atname_h,
	rchandle<DirAttributeValue> _dir_atval_h)
:
	parsenode(_loc),
	atname_h(_atname_h),
	dir_atval_h(_dir_atval_h)
{
}

DirAttr::~DirAttr()
{
}




// [96] DirAttributeValue
// ----------------------
DirAttributeValue::DirAttributeValue(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QuoteAttrContentList> _quot_attr_content_h,
	rchandle<AposAttrContentList> _apos_attr_content_h)
:
	parsenode(_loc),
	quot_attr_content_h(_quot_attr_content_h),
	apos_attr_content_h(_apos_attr_content_h)
{
}

DirAttributeValue::~DirAttributeValue()
{
}




// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

QuoteAttrContentList::~QuoteAttrContentList()
{
}




// [96b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

AposAttrContentList::~AposAttrContentList()
{
}




// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent(
	yy::xquery_parser::location_type const& _loc,
	std::string _quot_atcontent,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc),
	quot_atcontent(_quot_atcontent),
	common_content_h(_common_content_h)
{
}

QuoteAttrValueContent::~QuoteAttrValueContent()
{
}




// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent::AposAttrValueContent(
	yy::xquery_parser::location_type const& _loc,
	std::string _apos_atcontent,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc),
	apos_atcontent(_apos_atcontent),
	common_content_h(_common_content_h)
{
}

AposAttrValueContent::~AposAttrValueContent()
{
}




// [99] DirElemContent
// -------------------
DirElemContent::DirElemContent(
	yy::xquery_parser::location_type const& _loc,
	std::string _elem_content)
:
	exprnode(_loc),
	elem_content(_elem_content)
{
}

DirElemContent::~DirElemContent()
{
}




// [100] CommonContent
// -------------------
CommonContent::CommonContent(
	yy::xquery_parser::location_type const& _loc,
	enum common_content_t _type,
	std::string _ref)
:
	exprnode(_loc),
	type(_type),
	ref(_ref),
	expr_h(NULL)
{
}

CommonContent::CommonContent(
	yy::xquery_parser::location_type const& _loc,
	rchandle<EnclosedExpr> _expr_h)
:
	exprnode(_loc),
	type(CommonContent::expr),
	ref(""),
	expr_h(_expr_h)
{
}

CommonContent::CommonContent(
	yy::xquery_parser::location_type const& _loc,
	enum common_content_t _type)
:
	exprnode(_loc),
	type(CommonContent::expr),
	ref(""),
	expr_h(NULL)
{
}

CommonContent::~CommonContent()
{
}




// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _comment)
:
	DirectConstructor(_loc),
	comment(_comment)
{
}

DirCommentConstructor::~DirCommentConstructor()
{
}




// [102] DirCommentContents
// ------------------------
/* lexical rule */



// [103] DirPIConstructor
// ----------------------

DirPIConstructor::DirPIConstructor(
	yy::xquery_parser::location_type const& _loc,
	std::string const& _pi_target,
	std::string const& _pi_content)
:
	DirectConstructor(_loc),
	pi_target(_pi_target),
	pi_content(_pi_content)
{
}

DirPIConstructor::~DirPIConstructor()
{
}




// [104] DirPIContents
// -------------------
/* lexical rule */



// [105] CDataSection
// ------------------
CDataSection::CDataSection(
	yy::xquery_parser::location_type const& _loc,
	std::string _cdata_content)
:
	exprnode(_loc),
	cdata_content(_cdata_content)
{
}

CDataSection::~CDataSection()
{
}




// [106] CDataSectionContents
// --------------------------
/* lexical rule */



// [107] ComputedConstructor
// -------------------------
ComputedConstructor::ComputedConstructor(
	yy::xquery_parser::location_type const& _loc)
:
	Constructor(_loc)
{
}

ComputedConstructor::~ComputedConstructor()
{
}




// [108] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

CompDocConstructor::~CompDocConstructor()
{
}




// [109] CompElemConstructor
// -------------------------
CompElemConstructor::CompElemConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h,
	rchandle<Expr> _qname_expr_h,
	rchandle<ContentExpr> _content_expr_h)
:
	exprnode(_loc),
	qname_h(_qname_h),
	qname_expr_h(_qname_expr_h),
	content_expr_h(_content_expr_h)
{
}

CompElemConstructor::~CompElemConstructor()
{
}




// [110] ContentExpr
// -----------------
ContentExpr::ContentExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

ContentExpr::~ContentExpr()
{
}




// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor::CompAttrConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h,
	rchandle<Expr> _qname_expr_h,
	rchandle<Expr> _val_expr_h)
:
	exprnode(_loc),
	qname_h(_qname_h),
	qname_expr_h(_qname_expr_h),
	val_expr_h(_val_expr_h)
{
}

CompAttrConstructor::~CompAttrConstructor()
{
}




// [112] CompTextConstructor
// -------------------------
CompTextConstructor::CompTextConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _text_expr_h)
:
	exprnode(_loc),
	text_expr_h(_text_expr_h)
{
}

CompTextConstructor::~CompTextConstructor()
{
}




// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor::CompCommentConstructor(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Expr> _comment_expr_h)
:
	exprnode(_loc),
	comment_expr_h(_comment_expr_h)
{
}

CompCommentConstructor::~CompCommentConstructor()
{
}




// [114] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
	yy::xquery_parser::location_type const& _loc,
	std::string _target,
	rchandle<Expr> _target_expr_h,
	rchandle<Expr> _content_expr_h)
:
	exprnode(_loc),
	target(_target),
	target_expr_h(_target_expr_h),
	content_expr_h(_content_expr_h)
{
}

CompPIConstructor::~CompPIConstructor()
{
}



// [115] SingleType
// ----------------
SingleType::SingleType(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AtomicType> _atomic_type_h,
	bool _hook_b)
:
	parsenode(_loc),
	atomic_type_h(_atomic_type_h),
	hook_b(_hook_b)
{
}

SingleType::~SingleType()
{
}



// [116] TypeDeclaration
// ---------------------
TypeDeclaration::TypeDeclaration(
	yy::xquery_parser::location_type const& _loc,
	rchandle<SequenceType> _seqtype_h)
:
	parsenode(_loc),
	seqtype_h(_seqtype_h)
{
}

TypeDeclaration::~TypeDeclaration()
{
}



// [117] SequenceType
// ------------------
SequenceType::SequenceType(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ItemType> _itemtype_h,
	rchandle<OccurrenceIndicator> _occur_h,
	bool _void_b)
:
	parsenode(_loc),
	itemtype_h(_itemtype_h),
	occur_h(_occur_h),
	void_b(_void_b)
{
}

SequenceType::~SequenceType()
{
}



// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator::OccurrenceIndicator(
	yy::xquery_parser::location_type const& _loc,
	enum occurrence_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

OccurrenceIndicator::~OccurrenceIndicator()
{
}



// [119] ItemType
// --------------
ItemType::ItemType(
	yy::xquery_parser::location_type const& _loc,
	std::string _item_test)
:
	parsenode(_loc),
	item_test(_item_test)
{
}

ItemType::~ItemType()
{
}



// [120] AtomicType
// ----------------
AtomicType::AtomicType(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h)
:
	ItemType(_loc),
	qname_h(_qname_h)
{
}

AtomicType::~AtomicType()
{
}



// [121] KindTest
// --------------
KindTest::KindTest(
	yy::xquery_parser::location_type const& _loc)
:
	ItemType(_loc)
{
}

KindTest::~KindTest()
{
}



// [122] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest(
	yy::xquery_parser::location_type const& _loc)
:
	KindTest(_loc)
{
}

AnyKindTest::~AnyKindTest()
{
}

 

// [123] DocumentTest
// ------------------
DocumentTest::DocumentTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ElementTest> _elem_test_h,
	rchandle<SchemaElementTest> _schema_elem_test_h)
:
	KindTest(_loc),
	elem_test_h(_elem_test_h),
	schema_elem_test_h(_schema_elem_test_h)
{
}

DocumentTest::~DocumentTest()
{
}



// [124] TextTest
// --------------
TextTest::TextTest(
	yy::xquery_parser::location_type const& _loc)
:
	KindTest(_loc)
{
}

TextTest::~TextTest()
{
}



// [125] CommentTest
// -----------------
CommentTest::CommentTest(
	yy::xquery_parser::location_type const& _loc)
:
	KindTest(_loc)
{
}

CommentTest::~CommentTest()
{
}

 

// [126] PITest
// ------------
PITest::PITest(
	yy::xquery_parser::location_type const& _loc,
	std::string _target,
	std::string _content)
:
	KindTest(_loc),
	target(_target),
	content(_content)
{
}

PITest::~PITest()
{
}



// [127] AttributeTest
// -------------------
AttributeTest::AttributeTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AttribNameOrWildcard> _attr_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h)
:
	KindTest(_loc),
	attr_name_or_wildcard_h(_attr_name_or_wildcard_h),
	type_name_h(_type_name_h)
{
}

AttributeTest::~AttributeTest()
{
}



// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard::AttribNameOrWildcard(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AttributeName> _attr_name_h,
	bool _star_b)
:
	parsenode(_loc),
	attr_name_h(_attr_name_h),
	star_b(_star_b)
{
}

AttribNameOrWildcard::~AttribNameOrWildcard()
{
}



// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AttributeDeclaration> _attr_decl_h)
:
	parsenode(_loc),
	attr_decl_h(_attr_decl_h)
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}



// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration::AttributeDeclaration(
	yy::xquery_parser::location_type const& _loc,
	rchandle<AttributeName> _attr_name_h)
:
	parsenode(_loc),
	attr_name_h(_attr_name_h)
{
}

AttributeDeclaration::~AttributeDeclaration()
{
}



// [131] ElementTest
// -----------------
ElementTest::ElementTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ElementNameOrWildcard> _elem_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h)
:
	parsenode(_loc),
	elem_name_or_wildcard_h(_elem_name_or_wildcard_h),
	type_name_h(_type_name_h)
{
}

ElementTest::~ElementTest()
{
}



// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard::ElementNameOrWildcard(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ElementName> _elem_name_h,
	bool _star_b)
:
	parsenode(_loc),
	elem_name_h(_elem_name_h),
	star_b(_star_b)
{
}

ElementNameOrWildcard::~ElementNameOrWildcard()
{
}



// [133] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ElementDeclaration> _elem_decl_h)
:
	parsenode(_loc),
	elem_decl_h(_elem_decl_h)
{
}

SchemaElementTest::~SchemaElementTest()
{
}



// [134] ElementDeclaration
// ------------------------
ElementDeclaration::ElementDeclaration(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ElementName> _elem_name_h)
:
	parsenode(_loc),
	elem_name_h(_elem_name_h)
{
}

ElementDeclaration::~ElementDeclaration()
{
}



// [135] AttributeName
// -------------------
AttributeName::AttributeName(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _attr_qname_h)
:
	parsenode(_loc),
	attr_qname_h(_attr_qname_h)
{
}

AttributeName::~AttributeName()
{
}



// [136] ElementName
// -----------------
ElementName::ElementName(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _elem_qname_h)
:
	parsenode(_loc),
	elem_qname_h(_elem_qname_h)
{
}

ElementName::~ElementName()
{
}



// [137] TypeName
// --------------
TypeName::TypeName(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _type_qname_h)
:
	parsenode(_loc),
	type_qname_h(_type_qname_h)
{
}

TypeName::~TypeName()
{
}



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
// -----------
/*
QName::QName(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc),
{
}

QName::~QName()
{
}
*/


// [157] NCName
// [158] S  (WS)
// [159] Char







/*
**
**  Update productions
**  [http:://www.w3.org/TR/xqupdate/]
**
*/


// [241]	RevalidationDecl
// -----------------------
RevalidationDecl::RevalidationDecl(
	yy::xquery_parser::location_type const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h)
{
}

RevalidationDecl::~RevalidationDecl()
{
}




// [242]	InsertExpr
// ----------------
InsertExpr::InsertExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

InsertExpr::~InsertExpr()
{
}




// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	target_expr_h(_target_expr_h)
{
}

DeleteExpr::~DeleteExpr()
{
}



// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

ReplaceExpr::~ReplaceExpr()
{
}



// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

RenameExpr::~RenameExpr()
{
}



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
TransformExpr::TransformExpr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<VarNameList> _varname_list_h,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	varname_list_h(_varname_list_h),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

TransformExpr::~TransformExpr()
{
}




// [249a] VarNameList
// ------------------
VarNameList::VarNameList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

VarNameList::~VarNameList()
{
}




// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
	yy::xquery_parser::location_type const& _loc,
	std::string _varname,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	varname(_varname),
	val_h(_val_h)
{
}

VarBinding::~VarBinding()
{
}







/*
 *
 *  Full-text productions
 *  [http:://www.w3.org/TR/xqupdate/]
 *
 */


//[344] FTSelection
//-----------------
FTSelection::FTSelection(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTOr> _ftor_h,
	rchandle<FTMatchOptionProximityList> _option_list_h,
	rchandle<RangeExpr> _weight_expr_h)
:
	parsenode(_loc),
	ftor_h(_ftor_h),
	option_list_h(_option_list_h),
	weight_expr_h(_weight_expr_h)
{
}

FTSelection::~FTSelection()
{
}




//[344a] FTMatchOptionProximityList
//---------------------------------
FTMatchOptionProximityList::FTMatchOptionProximityList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTMatchOptionProximityList::~FTMatchOptionProximityList()
{
}




//[345]	FTOr
//----------
FTOr::FTOr(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTOr> _ftor_h,
	rchandle<FTAnd> _ftand_h)
:
	parsenode(_loc),
	ftor_h(_ftor_h),
	ftand_h(_ftand_h)
{
}

FTOr::~FTOr()
{
}



//[346]	FTAnd
//-----------
FTAnd::FTAnd(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTAnd> _ftand_h,
	rchandle<FTMildnot> _ftmild_not_h)
:
	parsenode(_loc),
	ftand_h(_ftand_h),
	ftmild_not_h(_ftmild_not_h)
{
}

FTAnd::~FTAnd()
{
}




//[347]	FTMildnot
//---------------
FTMildnot::FTMildnot(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTMildnot> _ftmild_not_h,
	rchandle<FTUnaryNot> _ftunary_not_h)
:
	parsenode(_loc),
	ftmild_not_h(_ftmild_not_h),
	ftunary_not_h(_ftunary_not_h)
{
}

FTMildnot::~FTMildnot()
{
}




//[348]	FTUnaryNot
//----------------
FTUnaryNot::FTUnaryNot(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTWordsSelection> _words_selection_h,
	bool _not_b)
:
	parsenode(_loc),
	words_selection_h(_words_selection_h),
	not_b(_not_b)
{
}

FTUnaryNot::~FTUnaryNot()
{
}



//[349]	FTWordsSelection
//----------------------
FTWordsSelection::FTWordsSelection(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTWords> _words_h,
	rchandle<FTTimes> _times_h,
	rchandle<FTSelection> _selection_h)
:
	parsenode(_loc),
	words_h(_words_h),
	times_h(_times_h),
	selection_h(_selection_h)
{
}

FTWordsSelection::~FTWordsSelection()
{
}




//[350]	FTWords
//-------------
FTWords::FTWords(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTWordsValue> _words_val_h,
	rchandle<FTAnyallOption> _any_all_option_h)
:
	parsenode(_loc),
	words_val_h(_words_val_h),
	any_all_option_h(_any_all_option_h)
{
}

FTWords::~FTWords()
{
}




//[351]	FTWordsValue
//------------------
FTWordsValue::FTWordsValue(
	yy::xquery_parser::location_type const& _loc,
	rchandle<Literal> _lit_h,
	rchandle<Expr> _expr_h)
:
	parsenode(_loc),
	lit_h(_lit_h),
	expr_h(_expr_h)
{
}

FTWordsValue::~FTWordsValue()
{
}




//[352]	FTProximity
//-----------------
FTProximity::FTProximity(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTProximity::~FTProximity()
{
}




//[353]	FTOrderedIndicator
//------------------------
FTOrderedIndicator::FTOrderedIndicator(
	yy::xquery_parser::location_type const& _loc)
:
	FTProximity(_loc)
{
}

FTOrderedIndicator::~FTOrderedIndicator()
{
}




//[354] FTMatchOption 	
//-------------------
FTMatchOption::FTMatchOption(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTMatchOption::~FTMatchOption()
{
}




//[355] FTCaseOption
//------------------
FTCaseOption::FTCaseOption(
	yy::xquery_parser::location_type const& _loc,
	ft_case_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTCaseOption::~FTCaseOption()
{
}




//[356] FTDiacriticsOption
//------------------------
FTDiacriticsOption::FTDiacriticsOption(
	yy::xquery_parser::location_type const& _loc,
	ft_diacritics_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTDiacriticsOption::~FTDiacriticsOption()
{
}




//[357] FTStemOption
//------------------
FTStemOption::FTStemOption(
	yy::xquery_parser::location_type const& _loc,
	ft_stem_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTStemOption::~FTStemOption()
{
}




//[358] FTThesaurusOption
//-----------------------
FTThesaurusOption::FTThesaurusOption(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTThesaurusID> _thesaurusid_h,
	rchandle<FTThesaurusList> _thesaurus_list_h,
	bool _default_b,
	bool _without_b)
:
	FTMatchOption(_loc),
	thesaurusid_h(_thesaurusid_h),
	thesaurus_list_h(_thesaurus_list_h),
	default_b(_default_b),
	without_b(_without_b)
{
}


FTThesaurusOption::~FTThesaurusOption()
{
}




//[358a] FTThesaurusList
//----------------------
FTThesaurusList::FTThesaurusList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTThesaurusList::~FTThesaurusList()
{
}



//[359] FTThesaurusID
//-------------------
FTThesaurusID::FTThesaurusID(
	yy::xquery_parser::location_type const& _loc,
	std::string _thesaurus_name,
	std::string _relationship_name,
	rchandle<FTRange> _levels_h)
:
	parsenode(_loc),
	thesaurus_name(_thesaurus_name),
	relationship_name(_relationship_name),
	levels_h(_levels_h)
{
}

FTThesaurusID::~FTThesaurusID()
{
}




//[360] FTStopwordOption
//----------------------
FTStopwordOption::FTStopwordOption(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTRefOrList> _refor_list_h,
	rchandle<FTInclExclStringLiteralList> _incl_excl_list_h,
	stop_words_mode_t _mode)
:
	FTMatchOption(_loc),
	refor_list_h(_refor_list_h),
	incl_excl_list_h(_incl_excl_list_h),
	mode(_mode)
{
}

FTStopwordOption::~FTStopwordOption()
{
}




//[360a] FTInclExclStringLiteralList
//----------------------------------
FTInclExclStringLiteralList::FTInclExclStringLiteralList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTInclExclStringLiteralList::~FTInclExclStringLiteralList()
{
}




//[361] FTRefOrList
//-----------------
FTRefOrList::FTRefOrList(
	yy::xquery_parser::location_type const& _loc,
	std::string _at_str,
	rchandle<FTStringLiteralList> _stringlit_list_h)
:
	parsenode(_loc),
	at_str(_at_str),
	stringlit_list_h(_stringlit_list_h)
{
}

FTRefOrList::~FTRefOrList()
{
}




//[361a] FTStringLiteralList
//--------------------------
FTStringLiteralList::FTStringLiteralList(
	yy::xquery_parser::location_type const& _loc)
:
	parsenode(_loc)
{
}

FTStringLiteralList::~FTStringLiteralList()
{
}




//[362] FTInclExclStringLiteral
//-----------------------------
FTInclExclStringLiteral::FTInclExclStringLiteral(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTRefOrList> _ref_or_list_h,
	incl_excl_mode_t _mode)
:
	parsenode(_loc),
	ref_or_list_h(_ref_or_list_h),
	mode(_mode)
{
}

FTInclExclStringLiteral::~FTInclExclStringLiteral()
{
}



//[363] FTLanguageOption
//----------------------
FTLanguageOption::FTLanguageOption(
	yy::xquery_parser::location_type const& _loc,
	std::string _lang)
:
	FTMatchOption(_loc),
	lang(_lang)
{
}

FTLanguageOption::~FTLanguageOption()
{
}




//[364] FTWildcardOption
//----------------------
FTWildcardOption::FTWildcardOption(
	yy::xquery_parser::location_type const& _loc,
	bool _with_b)
:
	FTMatchOption(_loc),
	with_b(_with_b)
{
}

FTWildcardOption::~FTWildcardOption()
{
}




//[365]	FTContent
//---------------
FTContent::FTContent(
	yy::xquery_parser::location_type const& _loc,
	ft_content_mode_t _mode)
:
	FTProximity(_loc),
	mode(_mode)
{
}

FTContent::~FTContent()
{
}




//[366]	FTAnyallOption
//--------------------
FTAnyallOption::FTAnyallOption(
	yy::xquery_parser::location_type const& _loc,
	ft_anyall_option_t _option)
:
	parsenode(_loc),
	option(_option)
{
}

FTAnyallOption::~FTAnyallOption()
{
}




//[367]	FTRange
//-------------
FTRange::FTRange(
	yy::xquery_parser::location_type const& _loc,
	rchandle<UnionExpr> _src_expr_h,
	rchandle<UnionExpr> _dst_expr_h)
:
	parsenode(_loc),
	src_expr_h(_src_expr_h),
	dst_expr_h(_dst_expr_h)
{
}

FTRange::~FTRange()
{
}




//[368]	FTDistance
//----------------
FTDistance::FTDistance(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTRange> _dist_h,
	rchandle<FTUnit> _unit_h)
:
	FTProximity(_loc),
	dist_h(_dist_h),
	unit_h(_unit_h)
{
}

FTDistance::~FTDistance()
{
}




//[369]	FTWindow
//--------------
FTWindow::FTWindow(
	yy::xquery_parser::location_type const& _loc,
	rchandle<UnionExpr> _window_h,
	rchandle<FTUnit> _unit_h)
:
	FTProximity(_loc),
	window_h(_window_h),
	unit_h(_unit_h)
{
}

FTWindow::~FTWindow()
{
}




//[370]	FTTimes
//-------------
FTTimes::FTTimes(
	yy::xquery_parser::location_type const& _loc,
	rchandle<FTRange> _range_h)
:
	parsenode(_loc),
	range_h(_range_h)
{
}

FTTimes::~FTTimes()
{
}




//[371]	FTScope
//-------------
FTScope::FTScope(
	yy::xquery_parser::location_type const& _loc,
	ft_scope_t _scope)
:
	FTProximity(_loc),
	scope(_scope)
{
}

FTScope::~FTScope()
{
}




//[372]	FTUnit
//------------
FTUnit::FTUnit(
	yy::xquery_parser::location_type const& _loc,
	ft_unit_t _unit)
:
	parsenode(_loc),
	unit(_unit)
{
}

FTUnit::~FTUnit()
{
}




//[373]	FTBigUnit
//---------------
FTBigUnit::FTBigUnit(
	yy::xquery_parser::location_type const& _loc,
	enum ft_big_unit_t _unit)
:
	parsenode(_loc),
	unit(_unit)
{
}

FTBigUnit::~FTBigUnit()
{
}




//[374]	FTIgnoreOption
//--------------------
FTIgnoreOption::FTIgnoreOption(
	yy::xquery_parser::location_type const& _loc,
	rchandle<UnionExpr> _union_h)
:
	parsenode(_loc),
	union_h(_union_h)
{
}

FTIgnoreOption::~FTIgnoreOption()
{
}






}	/* namespace xqp */
