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
using namespace yy;
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

ostream& Module::put(ostream& s) const
{
}

//-Module::




// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl(
	location const& _loc,
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

ostream& VersionDecl::put(ostream& s) const
{
}

//-VersionDecl::





// [3] MainModule
// --------------
MainModule::MainModule(
	location const& _loc,
	rchandle<Prolog> _prolog_h,
	rchandle<QueryBody> _query_body_h)
:
	parsenode(_loc),
	prolog_h(_prolog_h),
	query_body_h(_query_body_h)
{
}

MainModule::MainModule(
	location const& _loc,
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

ostream& MainModule::put(ostream& s) const
{
}

//-MainModule::





// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule(
	location const& _loc,
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

ostream& LibraryModule::put(ostream& s) const
{
}

//-LibraryModule::





// [5] ModuleDecl
// --------------
ModuleDecl::ModuleDecl(
	location const& _loc,
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

ostream& ModuleDecl::put(ostream& s) const
{
}

//-ModuleDecl::





// [6] Prolog
// ----------
Prolog::Prolog(
	location const& _loc,
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

ostream& Prolog::put(ostream& s) const
{
}

//-Prolog::





// [6a] SIDN_DeclList
// ------------------
SIND_DeclList::SIND_DeclList(
	location const& _loc)
:
	parsenode(_loc)
{
}

SIND_DeclList::~SIND_DeclList()
{
}

ostream& SIND_DeclList::put(ostream& s) const
{
}

//-SIND_DeclList::





// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList(
	location const& _loc)
:
	parsenode(_loc)
{
}

VFO_DeclList::~VFO_DeclList()
{
}

ostream& VFO_DeclList::put(ostream& s) const
{
}

//-VFO_DeclList::





// [6c] SIND_Decl
// --------------
SIND_Decl::SIND_Decl(
	location const& _loc)
:
	parsenode(_loc)
{
}

SIND_Decl::~SIND_Decl()
{
}

ostream& SIND_Decl::put(ostream& s) const
{
}

//-SIND_Decl::





// [6d] VFO_Decl
// -------------
VFO_Decl::VFO_Decl(
	location const& _loc)
:
	parsenode(_loc)
{
}

VFO_Decl::~VFO_Decl()
{
}

ostream& VFO_Decl::put(ostream& s) const
{
}

//-VFO_Decl::





// [7] Setter
// ----------
Setter::Setter(
	location const& _loc)
:
	SIND_Decl(_loc)
{
}

Setter::~Setter()
{
}

ostream& Setter::put(ostream& s) const
{
}

//-Setter::





// [8] Import
// ----------
Import::Import(
	location const& _loc)
:
	SIND_Decl(_loc)
{
}
	
Import::~Import()
{
}

ostream& Import::put(ostream& s) const
{
}

//-Import::





// [9] Separator
// -------------
// (Lexical rule)



// [10] NamespaceDecl
// ------------------
NamespaceDecl::NamespaceDecl(
	location const& _loc,
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

ostream& NamespaceDecl::put(ostream& s) const
{
}

//-NamespaceDecl::





// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
	location const& _loc,
	static_context::boundary_space_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

BoundarySpaceDecl::~BoundarySpaceDecl()
{
}

ostream& BoundarySpaceDecl::put(ostream& s) const
{
}

//-BoundarySpaceDecl::





// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
	location const& _loc,
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

ostream& DefaultNamespaceDecl::put(ostream& s) const
{
}

//-DefaultNamespaceDecl::





// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl(
	location const& _loc,
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

ostream& OptionDecl::put(ostream& s) const
{
}

//-OptionDecl::





// [13a] FTOptionDecl
// ------------------
FTOptionDecl::FTOptionDecl(
  yy::location const& _loc,
  rchandle<FTMatchOption> _match_option_h)
:
  parsenode(_loc),
 	match_option_h(_match_option_h)
{
}

FTOptionDecl::~FTOptionDecl()
{
}

ostream& FTOptionDecl::put(ostream& s) const
{
}

//-FTOptionDecl::





// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl(
	location const& _loc,
	static_context::ordering_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

OrderingModeDecl::~OrderingModeDecl()
{
}

ostream& OrderingModeDecl::put(ostream& s) const
{
}

//-OrderingModeDecl::





// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
	location const& _loc,
	static_context::order_empty_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

EmptyOrderDecl::~EmptyOrderDecl()
{
}

ostream& EmptyOrderDecl::put(ostream& s) const
{
}

//-EmptyOrderDecl::





// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
	location const& _loc,
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

ostream& CopyNamespacesDecl::put(ostream& s) const
{
}

//-CopyNamespacesDecl::





// [17] PreserveMode
// -----------------
PreserveMode::PreserveMode(
	location const& _loc,
	static_context::copy_ns_mode_t _preserve_mode)
:
	parsenode(_loc),
	preserve_mode(_preserve_mode)
{
}

PreserveMode::~PreserveMode()
{
}

ostream& PreserveMode::put(ostream& s) const
{
}

//-PreserveMode::





// [18] InheritMode
// ----------------
InheritMode::InheritMode(
	location const& _loc,
	static_context::copy_ns_mode_t _inherit_mode)
:
	parsenode(_loc),
	inherit_mode(_inherit_mode)
{
}

InheritMode::~InheritMode()
{
}

ostream& InheritMode::put(ostream& s) const
{
}

//-InheritMode::





// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl(
	location const& _loc,
	std::string const&  _collation)
:
	Setter(_loc),
	collation(_collation)
{
}

DefaultCollationDecl::~DefaultCollationDecl()
{
}

ostream& DefaultCollationDecl::put(ostream& s) const
{
}

//-DefaultCollationDecl::





// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
	location const& _loc,
	std::string const& _base_uri)
:
	Setter(_loc),
	base_uri(_base_uri)
{
}

BaseURIDecl::~BaseURIDecl()
{
}

ostream& BaseURIDecl::put(ostream& s) const
{
}

//-BaseURIDecl::





// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
	location const& _loc,
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

ostream& SchemaImport::put(ostream& s) const
{
}

//-SchemaImport::





// [21a] URLLiteralList
// --------------------
URILiteralList::URILiteralList(
	location const& _loc)
:
	parsenode(_loc)
{
}

URILiteralList::~URILiteralList()
{
}

ostream& URILiteralList::put(ostream& s) const
{
}

//-URILiteralList::





// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix(
	location const& _loc,
	bool _default_b)
:
	parsenode(_loc),
	prefix(""),
	default_b(_default_b)
{
}

SchemaPrefix::SchemaPrefix(
	location const& _loc,
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

ostream& SchemaPrefix::put(ostream& s) const
{
}

//-SchemaPrefix::





// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
	location const& _loc,
	std::string const& uri,
	rchandle<URILiteralList> _uri_list_h)
:
	Import(_loc),
	uri_list_h(_uri_list_h)
{
}

ModuleImport::ModuleImport(
	location const& _loc,
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

ostream& ModuleImport::put(ostream& s) const
{
}

//-ModuleImport::





// [24] VarDecl
// ------------
VarDecl::VarDecl(
	location const& _loc,
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

ostream& VarDecl::put(ostream& s) const
{
}

//-VarDecl::





// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl(
	location const& _loc,
	enum static_context::construction_mode_t _mode)
:
	Setter(_loc),
	mode(_mode)
{
}

ConstructionDecl::~ConstructionDecl()
{
}

ostream& ConstructionDecl::put(ostream& s) const
{
}

//-ConstructionDecl::





// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl(
	location const& _loc,
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

ostream& FunctionDecl::put(ostream& s) const
{
}

//-FunctionDecl::





// [27] ParamList
// --------------
ParamList::ParamList(
	location const& _loc)
:
	parsenode(_loc)
{
}

ParamList::~ParamList()
{
}

ostream& ParamList::put(ostream& s) const
{
}

//-ParamList::





// [28] Param
// ----------
Param::Param(
	location const& _loc,
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

ostream& Param::put(ostream& s) const
{
}

//-Param::





// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

EnclosedExpr::~EnclosedExpr()
{
}

ostream& EnclosedExpr::put(ostream& s) const
{
}

//-EnclosedExpr::





// [30] QueryBody
// --------------
QueryBody::QueryBody(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

QueryBody::~QueryBody()
{
}

ostream& QueryBody::put(ostream& s) const
{
}

//-QueryBody::





// [31] Expr
// ---------
Expr::Expr(
	location const& _loc)
:
	exprnode(_loc)
{
}

Expr::~Expr()
{
}

ostream& Expr::put(ostream& s) const
{
}

//-Expr::





// [32] ExprSingle
// ---------------
ExprSingle::ExprSingle(
	location const& _loc)
:
	exprnode(_loc)
{
}

ExprSingle::~ExprSingle()
{
}

ostream& ExprSingle::put(ostream& s) const
{
}

//-ExprSingle::





// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr(
	location const& _loc,
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

ostream& FLWORExpr::put(ostream& s) const
{
}

//-FLWORExpr::





// [33a] ForLetClauseList
// ----------------------
ForLetClauseList::ForLetClauseList(
	location const& _loc)
:
	parsenode(_loc)
{
}

ForLetClauseList::~ForLetClauseList()
{
}

ostream& ForLetClauseList::put(ostream& s) const
{
}

//-ForLetClauseList::





// [33b] ForLetClause
// ------------------
ForLetClause::ForLetClause(
	location const& _loc)
:
	parsenode(_loc)
{
}

ForLetClause::~ForLetClause()
{
}

ostream& ForLetClause::put(ostream& s) const
{
}

//-ForLetClause::





// [34] ForClause
// --------------
ForClause::ForClause(
	location const& _loc,
	rchandle<VarInDeclList> _vardecl_list_h)
:
	ForLetClause(_loc),
	vardecl_list_h(_vardecl_list_h)
{
}

ForClause::~ForClause()
{
}

ostream& ForClause::put(ostream& s) const
{
}

//-ForClause::





// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList(
	location const& _loc)
:
	parsenode(_loc)
{
}

VarInDeclList::~VarInDeclList()
{
}

ostream& VarInDeclList::put(ostream& s) const
{
}

//-VarInDeclList::





// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
	location const& _loc,
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

ostream& VarInDecl::put(ostream& s) const
{
}

//-VarInDecl::





// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
	location const& _loc,
	std::string const& _varname)
:
	parsenode(_loc),
	varname(_varname)
{
}

PositionalVar::~PositionalVar()
{
}

ostream& PositionalVar::put(ostream& s) const
{
}

//-PositionalVar::





// [36] LetClause
// --------------
LetClause::LetClause(
	location const& _loc,
	rchandle<VarGetsDeclList> _vardecl_list_h)
:
	ForLetClause(_loc),
	vardecl_list_h(_vardecl_list_h)
{
}

LetClause::~LetClause()
{
}

ostream& LetClause::put(ostream& s) const
{
}

//-LetClause::





// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList(
	location const& _loc)
:
	parsenode(_loc)
{
}

VarGetsDeclList::~VarGetsDeclList()
{
}

ostream& VarGetsDeclList::put(ostream& s) const
{
}

//-VarGetsDeclList::





// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl(
	location const& _loc,
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

ostream& VarGetsDecl::put(ostream& s) const
{
}

//-VarGetsDecl::





// [36c] FTScoreVar
// ----------------
FTScoreVar::FTScoreVar(
	location const& _loc,
	std::string _varname)
:
	parsenode(_loc),
	varname(_varname)
{
}

FTScoreVar::~FTScoreVar()
{
}

ostream& FTScoreVar::put(ostream& s) const
{
}

//-FTScoreVar::





// [37] WhereClause
// ----------------
WhereClause::WhereClause(
	location const& _loc,
	rchandle<ExprSingle> _predicate_h)
:
	parsenode(_loc),
	predicate_h(_predicate_h)
{
}

WhereClause::~WhereClause()
{
}

ostream& WhereClause::put(ostream& s) const
{
}

//-WhereClause::





// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause(
	location const& _loc,
	rchandle<OrderSpecList> _spec_list_h,
	bool _stable_b)
:
	parsenode(_loc),
	spec_list_h(_spec_list_h),
	stable_b(_stable_b)
{
}


OrderByClause::OrderByClause(
	location const& _loc,
	rchandle<OrderSpecList> _spec_list_h)
:
	parsenode(_loc),
	spec_list_h(_spec_list_h)
{
}

OrderByClause::~OrderByClause()
{
}

ostream& OrderByClause::put(ostream& s) const
{
}

//-OrderByClause::





// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList(
	location const& _loc)
:
	parsenode(_loc)
{
}

OrderSpecList::~OrderSpecList()
{
}

ostream& OrderSpecList::put(ostream& s) const
{
}

//-OrderSpecList::





// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
	location const& _loc,
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

ostream& OrderSpec::put(ostream& s) const
{
}

//-OrderSpec::





// [41] OrderModifier
// ------------------
OrderModifier::OrderModifier(
	location const& _loc,
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

ostream& OrderModifier::put(ostream& s) const
{
}

//-OrderModifier::





// [41a] OrderDirSpec
// ------------------
OrderDirSpec::OrderDirSpec(
	location const& _loc,
	enum dir_spec_t _dir_spec)
:
	parsenode(_loc),
	dir_spec(_dir_spec)
{
}

OrderDirSpec::~OrderDirSpec()
{
}
	
ostream& OrderDirSpec::put(ostream& s) const
{
}

//-OrderDirSpec::





// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
	location const& _loc,
	static_context::order_empty_mode_t _empty_order_spec)
:
	parsenode(_loc),
	empty_order_spec(_empty_order_spec)
{
}

OrderEmptySpec::~OrderEmptySpec()
{
}

ostream& OrderEmptySpec::put(ostream& s) const
{
}

//-OrderEmptySpec::





// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
	location const& _loc,
	std::string const& _uri)
:
	parsenode(_loc),
	uri(_uri)
{
}

OrderCollationSpec::~OrderCollationSpec()
{
}

ostream& OrderCollationSpec::put(ostream& s) const
{
}

//-OrderCollationSpec::





// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr::QuantifiedExpr(
	location const& _loc,
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

ostream& QuantifiedExpr::put(ostream& s) const
{
}

//-QuantifiedExpr::





// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList(
	location const& _loc)
:
	parsenode(_loc)
{
}

QVarInDeclList::~QVarInDeclList()
{
}

ostream& QVarInDeclList::put(ostream& s) const
{
}

//-QVarInDeclList::





// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
	location const& _loc,
	std::string _name,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	name(_name),
	typedecl_h(NULL),
	val_h(_val_h)
{
}

QVarInDecl::QVarInDecl(
	location const& _loc,
	std::string _name,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	name(_name),
	typedecl_h(_typedecl_h),
	val_h(_val_h)
{
}

QVarInDecl::~QVarInDecl()
{
}

ostream& QVarInDecl::put(ostream& s) const
{
}

//-QVarInDecl::





// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
	location const& _loc,
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
	location const& _loc,
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

ostream& TypeswitchExpr::put(ostream& s) const
{
}

//-TypeswitchExpr::





// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
	location const& _loc)
:
	parsenode(_loc)
{
}

CaseClauseList::~CaseClauseList()
{
}

ostream& CaseClauseList::put(ostream& s) const
{
}

//-CaseClauseList::





// [44] CaseClause
// ---------------
CaseClause::CaseClause(
	location const& _loc,
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

CaseClause::CaseClause(
	location const& _loc,
	rchandle<SequenceType> _type_h,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc),
	varname(""),
	type_h(_type_h),
	val_h(_val_h)
{
}

CaseClause::~CaseClause()
{
}

ostream& CaseClause::put(ostream& s) const
{
}

//-CaseClause::





// [45] IfExpr
// -----------
IfExpr::IfExpr(
	location const& _loc,
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

ostream& IfExpr::put(ostream& s) const
{
}

//-IfExpr::





// [46] OrExpr
// -----------
OrExpr::OrExpr(
	location const& _loc,
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

ostream& OrExpr::put(ostream& s) const
{
}

//-OrExpr::





// [47] AndExpr
// ------------
AndExpr::AndExpr(
	location const& _loc,
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

ostream& AndExpr::put(ostream& s) const
{
}

//-AndExpr::





// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr(
	location const& _loc,
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
	location const& _loc,
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
	location const& _loc,
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

ostream& ComparisonExpr::put(ostream& s) const
{
}

//-ComparisonExpr::





// [48a] FTContainsExpr
// --------------------
FTContainsExpr::FTContainsExpr(
	location const& _loc,
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

ostream& FTContainsExpr::put(ostream& s) const
{
}

//-FTContainsExpr::





// [49] RangeExpr
// --------------
RangeExpr::RangeExpr(
	location const& _loc,
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

ostream& RangeExpr::put(ostream& s) const
{
}

//-RangeExpr::





// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr(
	location const& _loc,
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

ostream& AdditiveExpr::put(ostream& s) const
{
}

//-AdditiveExpr::





// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr(
	location const& _loc,
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

ostream& MultiplicativeExpr::put(ostream& s) const
{
}

//-MultiplicativeExpr::





// [52] UnionExpr
// --------------
UnionExpr::UnionExpr(
	location const& _loc,
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

ostream& UnionExpr::put(ostream& s) const
{
}

//-UnionExpr::





// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr(
	location const& _loc,
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

ostream& IntersectExceptExpr::put(ostream& s) const
{
}

//-IntersectExceptExpr::





// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr(
	location const& _loc,
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

ostream& InstanceofExpr::put(ostream& s) const
{
}

//-InstanceofExpr::





// [55] TreatExpr
// --------------
TreatExpr::TreatExpr(
	location const& _loc,
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

ostream& TreatExpr::put(ostream& s) const
{
}

//-TreatExpr::





// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr(
	location const& _loc,
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

ostream& CastableExpr::put(ostream& s) const
{
}

//-CastableExpr::





// [57] CastExpr 	   
// -------------
CastExpr::CastExpr(
	location const& _loc,
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

ostream& CastExpr::put(ostream& s) const
{
}

//-CastExpr::





// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr(
	location const& _loc,
	rchandle<SignList> _signlist_h,
	rchandle<ValueExpr> _value_expr_h)
:
	exprnode(_loc),
	signlist_h(_signlist_h),
	value_expr_h(_value_expr_h)
{
}

UnaryExpr::~UnaryExpr()
{
}

ostream& UnaryExpr::put(ostream& s) const
{
}

//-UnaryExpr::





// [58a] SignList
// --------------
SignList::SignList(
	location const& _loc,
	bool _sign)
:
	parsenode(_loc),
	sign(_sign)
{
}

SignList::~SignList()
{
}

ostream& SignList::put(ostream& s) const
{
}

//-SignList::





// [59] ValueExpr
// --------------
ValueExpr::ValueExpr(
	location const& _loc)
:
	exprnode(_loc)
{
}

ValueExpr::~ValueExpr()
{
}

ostream& ValueExpr::put(ostream& s) const
{
}

//-ValueExpr::





// [60] GeneralComp
// ----------------
GeneralComp::GeneralComp(
	location const& _loc,
	enum gencomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

GeneralComp::~GeneralComp()
{
}

ostream& GeneralComp::put(ostream& s) const
{
}

//-GeneralComp::





// [61] ValueComp
// --------------
ValueComp::ValueComp(
	location const& _loc,
	enum valcomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

ValueComp::~ValueComp()
{
}

ostream& ValueComp::put(ostream& s) const
{
}

//-ValueComp::





// [62] NodeComp
// -------------
NodeComp::NodeComp(
	location const& _loc,
	enum nodecomp_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

NodeComp::~NodeComp()
{
}

ostream& NodeComp::put(ostream& s) const
{
}

//-NodeComp::






// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
	location const& _loc,
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

ostream& ValidateExpr::put(ostream& s) const
{
}

//-ValidateExpr::





// [64] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr(
	location const& _loc,
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

ostream& ExtensionExpr::put(ostream& s) const
{
}

//-ExtensionExpr::





// [64a] PragmaList
// ----------------
PragmaList::PragmaList(
	location const& _loc)
:
	parsenode(_loc)
{
}

PragmaList::~PragmaList()
{
}

ostream& PragmaList::put(ostream& s) const
{
}

//-PragmaList::





// [65] Pragma
// -----------
Pragma::Pragma(
	location const& _loc,
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

ostream& Pragma::put(ostream& s) const
{
}

//-Pragma::





// [66] PragmaContents
// -------------------
/* folded into [65] */



// [67] PathExpr
// -------------
PathExpr::PathExpr(
	location const& _loc,
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

ostream& PathExpr::put(ostream& s) const
{
}

//-PathExpr::





// [68] RelativePathExpr
// ---------------------
RelativePathExpr::RelativePathExpr(
	location const& _loc,
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

ostream& RelativePathExpr::put(ostream& s) const
{
}

//-RelativePathExpr::





// [69] StepExpr
// -------------
StepExpr::StepExpr(
	location const& _loc)
:
	exprnode(_loc)
{
}

StepExpr::~StepExpr()
{
}

ostream& StepExpr::put(ostream& s) const
{
}

//-StepExpr::





// [70] AxisStep
// -------------
AxisStep::AxisStep(
	location const& _loc,
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
	location const& _loc,
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

ostream& AxisStep::put(ostream& s) const
{
}

//-AxisStep::





// [71] ForwardStep
// ----------------
ForwardStep::ForwardStep(
	location const& _loc,
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
	location const& _loc,
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

ostream& ForwardStep::put(ostream& s) const
{
}

//-ForwardStep::





// [72] ForwardAxis
// ----------------
ForwardAxis::ForwardAxis(
	location const& _loc,
	enum forward_axis_t _axis)
:
	parsenode(_loc),
	axis(_axis)
{
}

ForwardAxis::~ForwardAxis()
{
}

ostream& ForwardAxis::put(ostream& s) const
{
}

//-ForwardAxis::





// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	rchandle<NodeTest> _node_test_h,
	bool _attr_b)
:
	parsenode(_loc),
	node_test_h(_node_test_h),
	attr_b(_attr_b)
{
}

AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	rchandle<NodeTest> _node_test_h)
:
	parsenode(_loc),
	node_test_h(_node_test_h),
	attr_b(false)
{
}

AbbrevForwardStep::~AbbrevForwardStep()
{
}

ostream& AbbrevForwardStep::put(ostream& s) const
{
}

//-AbbrevForwardStep::





// [74] ReverseStep
// ----------------
ReverseStep::ReverseStep(
	location const& _loc,
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

ostream& ReverseStep::put(ostream& s) const
{
}

//-ReverseStep::





// [75] ReverseAxis
// ----------------
ReverseAxis::ReverseAxis(
	location const& _loc,
	enum reverse_axis_t _axis)
:
	parsenode(_loc),
	axis(_axis)
{
}

ReverseAxis::~ReverseAxis()
{
}

ostream& ReverseAxis::put(ostream& s) const
{
}

//-ReverseAxis::





// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */



// [77] NodeTest
// -------------
NodeTest::NodeTest(
	location const& _loc)
:
	parsenode(_loc)
{
}

NodeTest::~NodeTest()
{
}

ostream& NodeTest::put(ostream& s) const
{
}

//-NodeTest::





// [78] NameTest
// -------------
NameTest::NameTest(
	location const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h),
	wild_h(NULL)
{
}

NameTest::NameTest(
	location const& _loc,
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

ostream& NameTest::put(ostream& s) const
{
}

//-NameTest::





// [79] Wildcard
// -------------
Wildcard::Wildcard(
	location const& _loc,
	enum wildcard_t _type)
:
	parsenode(_loc),
	type(_type),
	prefix(""),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	location const& _loc,
	std::string const& _prefix)
:
	parsenode(_loc),
	type(Wildcard::wild_prefix),
	prefix(_prefix),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	location const& _loc,
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

ostream& Wildcard::put(ostream& s) const
{
}

//-Wildcard::





// [80] FilterExpr
// ---------------
FilterExpr::FilterExpr(
	location const& _loc,
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

ostream& FilterExpr::put(ostream& s) const
{
}

//-FilterExpr::





// [81] PredicateList
// ------------------
PredicateList::PredicateList(
	location const& _loc)
:
	parsenode(_loc)
{
}

PredicateList::~PredicateList()
{
}

ostream& PredicateList::put(ostream& s) const
{
}

//-PredicateList::





// [82] Predicate
// --------------
Predicate::Predicate(
	location const& _loc,
	rchandle<Expr> _pred_h)
:
	exprnode(_loc),
	pred_h(_pred_h)
{
}

Predicate::~Predicate()
{
}

ostream& Predicate::put(ostream& s) const
{
}

//-Predicate::





// [83] PrimaryExpr
// ----------------
PrimaryExpr::PrimaryExpr(
	location const& _loc)
:
	exprnode(_loc)
{
}

PrimaryExpr::~PrimaryExpr()
{
}

ostream& PrimaryExpr::put(ostream& s) const
{
}

//-PrimaryExpr::





// [84] Literal
// ------------
Literal::Literal(
	location const& _loc)
:
	PrimaryExpr(_loc)
{
}

Literal::~Literal()
{
}

ostream& Literal::put(ostream& s) const
{
}

//-Literal::





// [85] NumericLiteral
// -------------------
NumericLiteral::NumericLiteral(
	location const& _loc,
	int _ival)
:
	Literal(_loc),
	type(NumericLiteral::num_integer),
	ival(_ival)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
	double _dval)
:
	Literal(_loc),
	type(NumericLiteral::num_double),
	dval(_dval)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
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

ostream& NumericLiteral::put(ostream& s) const
{
}

//-NumericLiteral::





// [86] VarRef
// -----------
VarRef::VarRef(
	location const& _loc,
	std::string _varname)
:
	PrimaryExpr(_loc),
	varname(_varname)
{
}

VarRef::~VarRef()
{
}

ostream& VarRef::put(ostream& s) const
{
}

//-VarRef::





// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

ParenthesizedExpr::~ParenthesizedExpr()
{
}

ostream& ParenthesizedExpr::put(ostream& s) const
{
}

//-ParenthesizedExpr::





// [88] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
	location const& _loc)
:
	PrimaryExpr(_loc)
{
}

ContextItemExpr::~ContextItemExpr()
{
}

ostream& ContextItemExpr::put(ostream& s) const
{
}

//-ContextItemExpr::





// [89] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

OrderedExpr::~OrderedExpr()
{
}

ostream& OrderedExpr::put(ostream& s) const
{
}

//-OrderedExpr::





// [90] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	PrimaryExpr(_loc),
	expr_h(_expr_h)
{
}

UnorderedExpr::~UnorderedExpr()
{
}

ostream& UnorderedExpr::put(ostream& s) const
{
}

//-UnorderedExpr::






// [91] FunctionCall
// -----------------

FunctionCall::FunctionCall(
	location const& _loc,
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

ostream& FunctionCall::put(ostream& s) const
{
}

//-FunctionCall::






// [91a] ArgList
// -------------
ArgList::ArgList(
	location const& _loc)
:
	parsenode(_loc)
{
}

ArgList::~ArgList()
{
}

ostream& ArgList::put(ostream& s) const
{
}

//-ArgList::






// [92] Constructor
// ----------------
Constructor::Constructor(
	location const& _loc)
:
	PrimaryExpr(_loc)
{
}

Constructor::~Constructor()
{
}

ostream& Constructor::put(ostream& s) const
{
}

//-Constructor::





// [93] DirectConstructor
// ----------------------
DirectConstructor::DirectConstructor(
	location const& _loc)
:
	Constructor(_loc)
{
}

DirectConstructor::~DirectConstructor()
{
}

ostream& DirectConstructor::put(ostream& s) const
{
}

//-DirectConstructor::



 

// [94] DirElemConstructor
// -----------------------

DirElemConstructor::DirElemConstructor(
	location const& _loc,
	rchandle<QName> _open_name_h,
	rchandle<QName> _close_name_h,
	rchandle<DirAttributeList> _attr_list_h,
	rchandle<DirElemContentList> _dir_content_list_h)
:
	DirectConstructor(_loc),
	elem_name_h(_open_name_h),
	attr_list_h(_attr_list_h),
	dir_content_list_h(_dir_content_list_h)
{
	// assert: open_name == close_name
}

DirElemConstructor::~DirElemConstructor()
{
}

ostream& DirElemConstructor::put(ostream& s) const
{
}

//-DirElemConstructor::





// [94a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList(
	location const& _loc)
:
	parsenode(_loc)
{
}

DirElemContentList::~DirElemContentList()
{
}

ostream& DirElemContentList::put(ostream& s) const
{
}

//-DirElemContentList::





// [95] DirAttributeList
// ---------------------
DirAttributeList::DirAttributeList(
	location const& _loc)
:
	parsenode(_loc)
{
}

DirAttributeList::~DirAttributeList()
{
}

ostream& DirAttributeList::put(ostream& s) const
{
}

//-DirAttributeList::






// [95a] DirAttr
// -------------
	
DirAttr::DirAttr(
	location const& _loc,
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

ostream& DirAttr::put(ostream& s) const
{
}

//-DirAttr::






// [96] DirAttributeValue
// ----------------------
DirAttributeValue::DirAttributeValue(
	location const& _loc,
	rchandle<QuoteAttrContentList> _quot_attr_content_h)
:
	parsenode(_loc),
	quot_attr_content_h(_quot_attr_content_h),
	apos_attr_content_h(NULL)
{
}

DirAttributeValue::DirAttributeValue(
	location const& _loc,
	rchandle<AposAttrContentList> _apos_attr_content_h)
:
	parsenode(_loc),
	quot_attr_content_h(NULL),
	apos_attr_content_h(_apos_attr_content_h)
{
}

DirAttributeValue::~DirAttributeValue()
{
}

ostream& DirAttributeValue::put(ostream& s) const
{
}

//-DirAttributeValue::






// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList(
	location const& _loc)
:
	parsenode(_loc)
{
}

QuoteAttrContentList::~QuoteAttrContentList()
{
}

ostream& QuoteAttrContentList::put(ostream& s) const
{
}

//-QuoteAttrContentList::






// [96b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList(
	location const& _loc)
:
	parsenode(_loc)
{
}

AposAttrContentList::~AposAttrContentList()
{
}

ostream& AposAttrContentList::put(ostream& s) const
{
}

//-AposAttrContentList::






// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent(
	location const& _loc,
	std::string _quot_atcontent)
:
	parsenode(_loc),
	quot_atcontent(_quot_atcontent),
	common_content_h(NULL)
{
}

QuoteAttrValueContent::QuoteAttrValueContent(
	location const& _loc,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc),
	quot_atcontent(""),
	common_content_h(_common_content_h)
{
}

QuoteAttrValueContent::~QuoteAttrValueContent()
{
}

ostream& QuoteAttrValueContent::put(ostream& s) const
{
}

//-QuoteAttrValueContent::






// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent::AposAttrValueContent(
	location const& _loc,
	std::string _apos_atcontent)
:
	parsenode(_loc),
	apos_atcontent(_apos_atcontent),
	common_content_h(NULL)
{
}

AposAttrValueContent::AposAttrValueContent(
	location const& _loc,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc),
	apos_atcontent(""),
	common_content_h(_common_content_h)
{
}

AposAttrValueContent::~AposAttrValueContent()
{
}

ostream& AposAttrValueContent::put(ostream& s) const
{
}

//-AposAttrValueContent::






// [99] DirElemContent
// -------------------
DirElemContent::DirElemContent(
	location const& _loc,
	rchandle<DirectConstructor> _direct_cons_h)
:
	exprnode(_loc),
	direct_cons_h(_direct_cons_h)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	std::string _elem_content)
:
	exprnode(_loc),
	elem_content(_elem_content)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	rchandle<CDataSection> _cdata_h)
:
	exprnode(_loc),
	cdata_h(_cdata_h)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	rchandle<CommonContent> _common_content_h)
:
	exprnode(_loc),
	common_content_h(_common_content_h)
{
}

DirElemContent::~DirElemContent()
{
}

ostream& DirElemContent::put(ostream& s) const
{
}

//-DirElemContent::






// [100] CommonContent
// -------------------
CommonContent::CommonContent(
	location const& _loc,
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
	location const& _loc,
	rchandle<EnclosedExpr> _expr_h)
:
	exprnode(_loc),
	type(CommonContent::expr),
	ref(""),
	expr_h(_expr_h)
{
}

CommonContent::CommonContent(
	location const& _loc,
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

ostream& CommonContent::put(ostream& s) const
{
}

//-CommonContent::






// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
	location const& _loc,
	std::string const& _comment)
:
	DirectConstructor(_loc),
	comment(_comment)
{
}

DirCommentConstructor::~DirCommentConstructor()
{
}

ostream& DirCommentConstructor::put(ostream& s) const
{
}

//-DirCommentConstructor::






// [102] DirCommentContents
// ------------------------
/* lexical rule */



// [103] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor(
	location const& _loc,
	std::string const& _pi_target)
:
	DirectConstructor(_loc),
	pi_target(_pi_target),
	pi_content("")
{
}

DirPIConstructor::DirPIConstructor(
	location const& _loc,
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

ostream& DirPIConstructor::put(ostream& s) const
{
}

//-DirPIConstructor::






// [104] DirPIContents
// -------------------
/* lexical rule */



// [105] CDataSection
// ------------------
CDataSection::CDataSection(
	location const& _loc,
	std::string _cdata_content)
:
	exprnode(_loc),
	cdata_content(_cdata_content)
{
}

CDataSection::~CDataSection()
{
}

ostream& CDataSection::put(ostream& s) const
{
}

//-CDataSection::






// [106] CDataSectionContents
// --------------------------
/* lexical rule */



// [107] ComputedConstructor
// -------------------------
ComputedConstructor::ComputedConstructor(
	location const& _loc)
:
	Constructor(_loc)
{
}

ComputedConstructor::~ComputedConstructor()
{
}

ostream& ComputedConstructor::put(ostream& s) const
{
}

//-ComputedConstructor::






// [108] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	ComputedConstructor(_loc),
	expr_h(_expr_h)
{
}

CompDocConstructor::~CompDocConstructor()
{
}

ostream& CompDocConstructor::put(ostream& s) const
{
}

//-CompDocConstructor::






// [109] CompElemConstructor
// -------------------------
CompElemConstructor::CompElemConstructor(
	location const& _loc,
	rchandle<QName> _qname_h,
	rchandle<Expr> _content_expr_h)
:
	ComputedConstructor(_loc),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

CompElemConstructor::CompElemConstructor(
	location const& _loc,
	rchandle<Expr> _qname_expr_h,
	rchandle<Expr> _content_expr_h)
:
	ComputedConstructor(_loc),
	qname_h(NULL),
	qname_expr_h(_qname_expr_h),
	content_expr_h(_content_expr_h)
{
}

CompElemConstructor::~CompElemConstructor()
{
}

ostream& CompElemConstructor::put(ostream& s) const
{
}

//-CompElemConstructor::






// [110] ContentExpr
// -----------------
/*
ContentExpr::ContentExpr(
	location const& _loc,
	rchandle<Expr> _expr_h)
:
	exprnode(_loc),
	expr_h(_expr_h)
{
}

ContentExpr::~ContentExpr()
{
}

ostream& ContentExpr::put(ostream& s) const
{
}

//-ContentExpr::



*/



// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor::CompAttrConstructor(
	location const& _loc,
	rchandle<QName> _qname_h,
	rchandle<Expr> _val_expr_h)
:
	ComputedConstructor(_loc),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	val_expr_h(_val_expr_h)
{
}

CompAttrConstructor::CompAttrConstructor(
	location const& _loc,
	rchandle<Expr> _qname_expr_h,
	rchandle<Expr> _val_expr_h)
:
	ComputedConstructor(_loc),
	qname_h(NULL),
	qname_expr_h(_qname_expr_h),
	val_expr_h(_val_expr_h)
{
}

CompAttrConstructor::~CompAttrConstructor()
{
}

ostream& CompAttrConstructor::put(ostream& s) const
{
}

//-CompAttrConstructor::






// [112] CompTextConstructor
// -------------------------
CompTextConstructor::CompTextConstructor(
	location const& _loc,
	rchandle<Expr> _text_expr_h)
:
	ComputedConstructor(_loc),
	text_expr_h(_text_expr_h)
{
}

CompTextConstructor::~CompTextConstructor()
{
}

ostream& CompTextConstructor::put(ostream& s) const
{
}

//-CompTextConstructor::






// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor::CompCommentConstructor(
	location const& _loc,
	rchandle<Expr> _comment_expr_h)
:
	ComputedConstructor(_loc),
	comment_expr_h(_comment_expr_h)
{
}

CompCommentConstructor::~CompCommentConstructor()
{
}

ostream& CompCommentConstructor::put(ostream& s) const
{
}

//-CompCommentConstructor::






// [114] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
	location const& _loc,
	std::string _target,
	rchandle<Expr> _content_expr_h)
:
	ComputedConstructor(_loc),
	target(_target),
	target_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

CompPIConstructor::CompPIConstructor(
	location const& _loc,
	rchandle<Expr> _target_expr_h,
	rchandle<Expr> _content_expr_h)
:
	ComputedConstructor(_loc),
	target(""),
	target_expr_h(_target_expr_h),
	content_expr_h(_content_expr_h)
{
}

CompPIConstructor::~CompPIConstructor()
{
}

ostream& CompPIConstructor::put(ostream& s) const
{
}

//-CompPIConstructor::





// [115] SingleType
// ----------------
SingleType::SingleType(
	location const& _loc,
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

ostream& SingleType::put(ostream& s) const
{
}

//-SingleType::





// [116] TypeDeclaration
// ---------------------
TypeDeclaration::TypeDeclaration(
	location const& _loc,
	rchandle<SequenceType> _seqtype_h)
:
	parsenode(_loc),
	seqtype_h(_seqtype_h)
{
}

TypeDeclaration::~TypeDeclaration()
{
}

ostream& TypeDeclaration::put(ostream& s) const
{
}

//-TypeDeclaration::





// [117] SequenceType
// ------------------
SequenceType::SequenceType(
	location const& _loc,
	rchandle<ItemType> _itemtype_h,
	rchandle<OccurrenceIndicator> _occur_h)
:
	parsenode(_loc),
	itemtype_h(_itemtype_h),
	occur_h(_occur_h)
{
}

SequenceType::~SequenceType()
{
}

ostream& SequenceType::put(ostream& s) const
{
}

//-SequenceType::





// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator::OccurrenceIndicator(
	location const& _loc,
	enum occurrence_t _type)
:
	parsenode(_loc),
	type(_type)
{
}

OccurrenceIndicator::~OccurrenceIndicator()
{
}

ostream& OccurrenceIndicator::put(ostream& s) const
{
}

//-OccurrenceIndicator::





// [119] ItemType
// --------------
ItemType::ItemType(
	location const& _loc,
	bool _item_test_b)
:
	parsenode(_loc),
	item_test_b(_item_test_b)
{
}

ItemType::ItemType(
	location const& _loc)
:
	parsenode(_loc),
	item_test_b(false)
{
}

ItemType::~ItemType()
{
}

ostream& ItemType::put(ostream& s) const
{
}

//-ItemType::





// [120] AtomicType
// ----------------
AtomicType::AtomicType(
	location const& _loc,
	rchandle<QName> _qname_h)
:
	ItemType(_loc),
	qname_h(_qname_h)
{
}

AtomicType::~AtomicType()
{
}

ostream& AtomicType::put(ostream& s) const
{
}

//-AtomicType::





// [121] KindTest
// --------------
KindTest::KindTest(
	location const& _loc)
:
	ItemType(_loc)
{
}

KindTest::~KindTest()
{
}

ostream& KindTest::put(ostream& s) const
{
}

//-KindTest::





// [122] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest(
	location const& _loc)
:
	KindTest(_loc)
{
}

AnyKindTest::~AnyKindTest()
{
}

ostream& AnyKindTest::put(ostream& s) const
{
}

//-AnyKindTest::



 

// [123] DocumentTest
// ------------------
DocumentTest::DocumentTest(
	location const& _loc)
:
	KindTest(_loc),
	elem_test_h(NULL),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	rchandle<ElementTest> _elem_test_h)
:
	KindTest(_loc),
	elem_test_h(_elem_test_h),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	rchandle<SchemaElementTest> _schema_elem_test_h)
:
	KindTest(_loc),
	elem_test_h(NULL),
	schema_elem_test_h(_schema_elem_test_h)
{
}

DocumentTest::~DocumentTest()
{
}

ostream& DocumentTest::put(ostream& s) const
{
}

//-DocumentTest::





// [124] TextTest
// --------------
TextTest::TextTest(
	location const& _loc)
:
	KindTest(_loc)
{
}

TextTest::~TextTest()
{
}

ostream& TextTest::put(ostream& s) const
{
}

//-TextTest::





// [125] CommentTest
// -----------------
CommentTest::CommentTest(
	location const& _loc)
:
	KindTest(_loc)
{
}

CommentTest::~CommentTest()
{
}

ostream& CommentTest::put(ostream& s) const
{
}

//-CommentTest::



 

// [126] PITest
// ------------
PITest::PITest(
	location const& _loc,
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

ostream& PITest::put(ostream& s) const
{
}

//-PITest::





// [127] AttributeTest
// -------------------
AttributeTest::AttributeTest(
	location const& _loc,
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

ostream& AttributeTest::put(ostream& s) const
{
}

//-AttributeTest::





// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard::AttribNameOrWildcard(
	location const& _loc,
	rchandle<AttributeName> _attr_name_h)
:
	parsenode(_loc),
	attr_name_h(_attr_name_h),
	star_b(_attr_name_h==NULL)
{
}

AttribNameOrWildcard::~AttribNameOrWildcard()
{
}

ostream& AttribNameOrWildcard::put(ostream& s) const
{
}

//-AttribNameOrWildcard::





// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
	location const& _loc,
	rchandle<AttributeDeclaration> _attr_decl_h)
:
	parsenode(_loc),
	attr_decl_h(_attr_decl_h)
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}

ostream& SchemaAttributeTest::put(ostream& s) const
{
}

//-SchemaAttributeTest::





// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration::AttributeDeclaration(
	location const& _loc,
	rchandle<AttributeName> _attr_name_h)
:
	parsenode(_loc),
	attr_name_h(_attr_name_h)
{
}

AttributeDeclaration::~AttributeDeclaration()
{
}

ostream& AttributeDeclaration::put(ostream& s) const
{
}

//-AttributeDeclaration::





// [131] ElementTest
// -----------------
ElementTest::ElementTest(
	location const& _loc,
	rchandle<ElementNameOrWildcard> _elem_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h)
:
	parsenode(_loc),
	elem_name_or_wildcard_h(_elem_name_or_wildcard_h),
	type_name_h(_type_name_h),
	optional_b(false)
{
}

ElementTest::ElementTest(
	location const& _loc,
	rchandle<ElementNameOrWildcard> _elem_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h,
	bool _optional_b)
:
	parsenode(_loc),
	elem_name_or_wildcard_h(_elem_name_or_wildcard_h),
	type_name_h(_type_name_h),
	optional_b(_optional_b)
{
}

ElementTest::~ElementTest()
{
}

ostream& ElementTest::put(ostream& s) const
{
}

//-ElementTest::





// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard::ElementNameOrWildcard(
	location const& _loc,
	rchandle<ElementName> _elem_name_h)
:
	parsenode(_loc),
	elem_name_h(_elem_name_h),
	star_b(_elem_name_h==NULL)
{
}

ElementNameOrWildcard::~ElementNameOrWildcard()
{
}

ostream& ElementNameOrWildcard::put(ostream& s) const
{
}

//-ElementNameOrWildcard::





// [133] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
	location const& _loc,
	rchandle<ElementDeclaration> _elem_decl_h)
:
	parsenode(_loc),
	elem_decl_h(_elem_decl_h)
{
}

SchemaElementTest::~SchemaElementTest()
{
}

ostream& SchemaElementTest::put(ostream& s) const
{
}

//-SchemaElementTest::





// [134] ElementDeclaration
// ------------------------
ElementDeclaration::ElementDeclaration(
	location const& _loc,
	rchandle<ElementName> _elem_name_h)
:
	parsenode(_loc),
	elem_name_h(_elem_name_h)
{
}

ElementDeclaration::~ElementDeclaration()
{
}

ostream& ElementDeclaration::put(ostream& s) const
{
}

//-ElementDeclaration::





// [135] AttributeName
// -------------------
AttributeName::AttributeName(
	location const& _loc,
	rchandle<QName> _attr_qname_h)
:
	parsenode(_loc),
	attr_qname_h(_attr_qname_h)
{
}

AttributeName::~AttributeName()
{
}

ostream& AttributeName::put(ostream& s) const
{
}

//-AttributeName::





// [136] ElementName
// -----------------
ElementName::ElementName(
	location const& _loc,
	rchandle<QName> _elem_qname_h)
:
	parsenode(_loc),
	elem_qname_h(_elem_qname_h)
{
}

ElementName::~ElementName()
{
}

ostream& ElementName::put(ostream& s) const
{
}

//-ElementName::





// [137] TypeName
// --------------
TypeName::TypeName(
	location const& _loc,
	rchandle<QName> _type_qname_h)
:
	parsenode(_loc),
	type_qname_h(_type_qname_h)
{
}

TypeName::~TypeName()
{
}

ostream& TypeName::put(ostream& s) const
{
}

//-TypeName::





/* lexical rules, see xquery.l */
/* --------------------------- */
// [138] IntegerLiteral
// [139] DecimalLiteral
// [140] DoubleLiteral
// [141] URILiteral 





// [142] StringLiteral
// -------------------
StringLiteral::StringLiteral(
	yy::location const& _loc,
	string const& _strval)
:
	Literal(_loc),
	strval(_strval)
{
}

StringLiteral::~StringLiteral()
{
}

ostream& StringLiteral::put(ostream& s) const
{
}

//-StringLiteral::




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
// -----------
/*
QName::QName(
	location const& _loc)
:
	parsenode(_loc),
{
}

QName::~QName()
{
}

ostream& QName::put(ostream& s) const
{
}

//-QName::



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
	location const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h)
{
}

RevalidationDecl::~RevalidationDecl()
{
}

ostream& RevalidationDecl::put(ostream& s) const
{
}

//-RevalidationDecl::






// [242]	InsertExpr
// ----------------
InsertExpr::InsertExpr(
	location const& _loc,
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

ostream& InsertExpr::put(ostream& s) const
{
}

//-InsertExpr::






// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
	location const& _loc,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc),
	target_expr_h(_target_expr_h)
{
}

DeleteExpr::~DeleteExpr()
{
}

ostream& DeleteExpr::put(ostream& s) const
{
}

//-DeleteExpr::





// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
	location const& _loc,
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

ostream& ReplaceExpr::put(ostream& s) const
{
}

//-ReplaceExpr::





// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
	location const& _loc,
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

ostream& RenameExpr::put(ostream& s) const
{
}

//-RenameExpr::





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
	location const& _loc,
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

ostream& TransformExpr::put(ostream& s) const
{
}

//-TransformExpr::






// [249a] VarNameList
// ------------------
VarNameList::VarNameList(
	location const& _loc)
:
	parsenode(_loc)
{
}

VarNameList::~VarNameList()
{
}

ostream& VarNameList::put(ostream& s) const
{
}

//-VarNameList::






// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
	location const& _loc,
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

ostream& VarBinding::put(ostream& s) const
{
}

//-VarBinding::









/*
 *
 *  Full-text productions
 *  [http:://www.w3.org/TR/xqupdate/]
 *
 */


// [344] FTSelection
// -----------------
FTSelection::FTSelection(
	location const& _loc,
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

ostream& FTSelection::put(ostream& s) const
{
}

//-FTSelection::






// [344a] FTMatchOptionProximityList
// ---------------------------------
FTMatchOptionProximityList::FTMatchOptionProximityList(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTMatchOptionProximityList::~FTMatchOptionProximityList()
{
}

ostream& FTMatchOptionProximityList::put(ostream& s) const
{
}

//-FTMatchOptionProximityList::






// [345] FTOr
// ----------
FTOr::FTOr(
	location const& _loc,
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

ostream& FTOr::put(ostream& s) const
{
}

//-FTOr::





// [346] FTAnd
// -----------
FTAnd::FTAnd(
	location const& _loc,
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

ostream& FTAnd::put(ostream& s) const
{
}

//-FTAnd::






// [347] FTMildnot
// ---------------
FTMildnot::FTMildnot(
	location const& _loc,
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

ostream& FTMildnot::put(ostream& s) const
{
}

//-FTMildnot::






// [348] FTUnaryNot
// ----------------
FTUnaryNot::FTUnaryNot(
	location const& _loc,
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

ostream& FTUnaryNot::put(ostream& s) const
{
}

//-FTUnaryNot::





// [349] FTWordsSelection
// ----------------------
FTWordsSelection::FTWordsSelection(
	location const& _loc,
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

ostream& FTWordsSelection::put(ostream& s) const
{
}

//-FTWordsSelection::






// [350] FTWords
// -------------
FTWords::FTWords(
	location const& _loc,
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

ostream& FTWords::put(ostream& s) const
{
}

//-FTWords::






// [351] FTWordsValue
// ------------------
FTWordsValue::FTWordsValue(
	location const& _loc,
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

ostream& FTWordsValue::put(ostream& s) const
{
}

//-FTWordsValue::






// [352] FTProximity
// -----------------
FTProximity::FTProximity(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTProximity::~FTProximity()
{
}

ostream& FTProximity::put(ostream& s) const
{
}

//-FTProximity::






// [353] FTOrderedIndicator
// ------------------------
FTOrderedIndicator::FTOrderedIndicator(
	location const& _loc)
:
	FTProximity(_loc)
{
}

FTOrderedIndicator::~FTOrderedIndicator()
{
}

ostream& FTOrderedIndicator::put(ostream& s) const
{
}

//-FTOrderedIndicator::






// [354] FTMatchOption 	
// -------------------
FTMatchOption::FTMatchOption(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTMatchOption::~FTMatchOption()
{
}

ostream& FTMatchOption::put(ostream& s) const
{
}

//-FTMatchOption::






// [355] FTCaseOption
// ------------------
FTCaseOption::FTCaseOption(
	location const& _loc,
	ft_case_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTCaseOption::~FTCaseOption()
{
}

ostream& FTCaseOption::put(ostream& s) const
{
}

//-FTCaseOption::






// [356] FTDiacriticsOption
// ------------------------
FTDiacriticsOption::FTDiacriticsOption(
	location const& _loc,
	ft_diacritics_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTDiacriticsOption::~FTDiacriticsOption()
{
}

ostream& FTDiacriticsOption::put(ostream& s) const
{
}

//-FTDiacriticsOption::






// [357] FTStemOption
// ------------------
FTStemOption::FTStemOption(
	location const& _loc,
	ft_stem_mode_t _mode)
:
	FTMatchOption(_loc),
	mode(_mode)
{
}

FTStemOption::~FTStemOption()
{
}

ostream& FTStemOption::put(ostream& s) const
{
}

//-FTStemOption::






// [358] FTThesaurusOption
// -----------------------
FTThesaurusOption::FTThesaurusOption(
	location const& _loc,
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

ostream& FTThesaurusOption::put(ostream& s) const
{
}

//-FTThesaurusOption::






// [358a] FTThesaurusList
// ----------------------
FTThesaurusList::FTThesaurusList(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTThesaurusList::~FTThesaurusList()
{
}

ostream& FTThesaurusList::put(ostream& s) const
{
}

//-FTThesaurusList::





// [359] FTThesaurusID
// -------------------
FTThesaurusID::FTThesaurusID(
	location const& _loc,
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

ostream& FTThesaurusID::put(ostream& s) const
{
}

//-FTThesaurusID::






// [360] FTStopwordOption
// ----------------------
FTStopwordOption::FTStopwordOption(
	location const& _loc,
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

ostream& FTStopwordOption::put(ostream& s) const
{
}

//-FTStopwordOption::






// [360a] FTInclExclStringLiteralList
// ----------------------------------
FTInclExclStringLiteralList::FTInclExclStringLiteralList(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTInclExclStringLiteralList::~FTInclExclStringLiteralList()
{
}

ostream& FTInclExclStringLiteralList::put(ostream& s) const
{
}

//-FTInclExclStringLiteralList::






// [361] FTRefOrList
// -----------------
FTRefOrList::FTRefOrList(
	location const& _loc,
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

ostream& FTRefOrList::put(ostream& s) const
{
}

//-FTRefOrList::






// [361a] FTStringLiteralList
// --------------------------
FTStringLiteralList::FTStringLiteralList(
	location const& _loc)
:
	parsenode(_loc)
{
}

FTStringLiteralList::~FTStringLiteralList()
{
}

ostream& FTStringLiteralList::put(ostream& s) const
{
}

//-FTStringLiteralList::






// [362] FTInclExclStringLiteral
// -----------------------------
FTInclExclStringLiteral::FTInclExclStringLiteral(
	location const& _loc,
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

ostream& FTInclExclStringLiteral::put(ostream& s) const
{
}

//-FTInclExclStringLiteral::





// [363] FTLanguageOption
// ----------------------
FTLanguageOption::FTLanguageOption(
	location const& _loc,
	std::string _lang)
:
	FTMatchOption(_loc),
	lang(_lang)
{
}

FTLanguageOption::~FTLanguageOption()
{
}

ostream& FTLanguageOption::put(ostream& s) const
{
}

//-FTLanguageOption::






// [364] FTWildcardOption
// ----------------------
FTWildcardOption::FTWildcardOption(
	location const& _loc,
	bool _with_b)
:
	FTMatchOption(_loc),
	with_b(_with_b)
{
}

FTWildcardOption::~FTWildcardOption()
{
}

ostream& FTWildcardOption::put(ostream& s) const
{
}

//-FTWildcardOption::






// [365]	FTContent
// ---------------
FTContent::FTContent(
	location const& _loc,
	ft_content_mode_t _mode)
:
	FTProximity(_loc),
	mode(_mode)
{
}

FTContent::~FTContent()
{
}

ostream& FTContent::put(ostream& s) const
{
}

//-FTContent::






// [366]	FTAnyallOption
// --------------------
FTAnyallOption::FTAnyallOption(
	location const& _loc,
	ft_anyall_option_t _option)
:
	parsenode(_loc),
	option(_option)
{
}

FTAnyallOption::~FTAnyallOption()
{
}

ostream& FTAnyallOption::put(ostream& s) const
{
}

//-FTAnyallOption::






// [367] FTRange
// -------------
FTRange::FTRange(
	location const& _loc,
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

ostream& FTRange::put(ostream& s) const
{
}

//-FTRange::






// [368] FTDistance
// ----------------
FTDistance::FTDistance(
	location const& _loc,
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

ostream& FTDistance::put(ostream& s) const
{
}

//-FTDistance::






// [369] FTWindow
// --------------
FTWindow::FTWindow(
	location const& _loc,
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

ostream& FTWindow::put(ostream& s) const
{
}

//-FTWindow::






// [370] FTTimes
// -------------
FTTimes::FTTimes(
	location const& _loc,
	rchandle<FTRange> _range_h)
:
	parsenode(_loc),
	range_h(_range_h)
{
}

FTTimes::~FTTimes()
{
}

ostream& FTTimes::put(ostream& s) const
{
}

//-FTTimes::






// [371] FTScope
// -------------
FTScope::FTScope(
	location const& _loc,
	ft_scope_t _scope)
:
	FTProximity(_loc),
	scope(_scope)
{
}

FTScope::~FTScope()
{
}

ostream& FTScope::put(ostream& s) const
{
}

//-FTScope::






// [372] FTUnit
// ------------
FTUnit::FTUnit(
	location const& _loc,
	ft_unit_t _unit)
:
	parsenode(_loc),
	unit(_unit)
{
}

FTUnit::~FTUnit()
{
}

ostream& FTUnit::put(ostream& s) const
{
}

//-FTUnit::






// [373] FTBigUnit
// ---------------
FTBigUnit::FTBigUnit(
	location const& _loc,
	enum ft_big_unit_t _unit)
:
	parsenode(_loc),
	unit(_unit)
{
}

FTBigUnit::~FTBigUnit()
{
}

ostream& FTBigUnit::put(ostream& s) const
{
}

//-FTBigUnit::






// [374] FTIgnoreOption
// --------------------
FTIgnoreOption::FTIgnoreOption(
	location const& _loc,
	rchandle<UnionExpr> _union_h)
:
	parsenode(_loc),
	union_h(_union_h)
{
}

FTIgnoreOption::~FTIgnoreOption()
{
}

ostream& FTIgnoreOption::put(ostream& s) const
{
}

//-FTIgnoreOption::








}	/* namespace xqp */

