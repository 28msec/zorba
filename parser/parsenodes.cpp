/* -*- mode:: c++ indent-tabs-mode: nil -*-
 *
 *  $Id:: parsenodes.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "parsenodes.h"
#include "parse_constants.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "../context/context.h"
#include "../values/qname_value.h"
#include "../util/rchandle.h"
#include "indent.h"

using namespace std;
using namespace yy;

namespace xqp {

int printdepth = 0;
#define INDENT	indent[++printdepth % 30]
#define OUTDENT	indent[printdepth-- % 30]
#define UNDENT	printdepth--



ostream& parsenode::put(ostream& s) const
{
	s << INDENT << "parsenode[]\n"; UNDENT;
	return s;
}

ostream& exprnode::put(ostream& s) const
{
	s << INDENT << "exprnode[]\n"; UNDENT;
	return s;
}



// [1] Module
// ----------
Module::Module(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

Module::~Module()
{
}

ostream& Module::put(ostream& os) const
{
	return os;
}

//-Module::



// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl(
	location const& _loc,
	context const& _ctx,
	std::string const& _version,
	std::string const& _encoding)
:
	parsenode(_loc,_ctx),
	version(_version),
	encoding(_encoding)
{
}

VersionDecl::~VersionDecl()
{
}

ostream& VersionDecl::put(ostream& os) const
{
	return os;
}

//-VersionDecl::





// [3] MainModule
// --------------
MainModule::MainModule(
	location const& _loc,
	context const& _ctx,
	rchandle<Prolog> _prolog_h,
	rchandle<QueryBody> _query_body_h)
:
	parsenode(_loc,_ctx),
	prolog_h(_prolog_h),
	query_body_h(_query_body_h)
{
}

MainModule::MainModule(
	location const& _loc,
	context const& _ctx,
	rchandle<QueryBody> _query_body_h)
:
	parsenode(_loc,_ctx),
	prolog_h(NULL),
	query_body_h(_query_body_h)
{
}

MainModule::~MainModule()
{
}

ostream& MainModule::put(ostream& s) const
{
	s << INDENT << "MainModule[" << endl;
	if (prolog_h!=NULL) prolog_h->put(s);
	query_body_h->put(s);
	return s << OUTDENT << "]\n";
}

//-MainModule::





// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule(
	location const& _loc,
	context const& _ctx,
	rchandle<ModuleDecl> _decl_h, 
	rchandle<Prolog> _prolog_h)
:
	parsenode(_loc,_ctx),
	decl_h(_decl_h),
	prolog_h(_prolog_h)
{
}


LibraryModule::~LibraryModule()
{
}

ostream& LibraryModule::put(ostream& s) const
{
	s << INDENT << "LibraryModule[" << endl;
	if (decl_h!=NULL) decl_h->put(s);
	prolog_h->put(s);
	return s << OUTDENT << "]\n";
}

//-LibraryModule::





// [5] ModuleDecl
// --------------
ModuleDecl::ModuleDecl(
	location const& _loc,
	context const& _ctx,
	std::string const& _prefix,
	std::string const& _target_namespace)
:
	parsenode(_loc,_ctx),
	prefix(_prefix),
	target_namespace(_target_namespace)
{
}

ModuleDecl::~ModuleDecl()
{
}

ostream& ModuleDecl::put(ostream& s) const
{
	s << INDENT << "ModuleDecl[";
	s << prefix << " = " << target_namespace;
	return s << OUTDENT << "]\n";
}

//-ModuleDecl::





// [6] Prolog
// ----------
Prolog::Prolog(
	location const& _loc,
	context const& _ctx,
	rchandle<SIND_DeclList> _sind_list_h,
	rchandle<VFO_DeclList> _vfo_list_h)
:
	parsenode(_loc,_ctx),
	sind_list_h(_sind_list_h),
	vfo_list_h(_vfo_list_h)
{
}

Prolog::~Prolog()
{
}

ostream& Prolog::put(ostream& s) const
{
	s << INDENT << "Prolog[" << endl;
	if (sind_list_h!=NULL) sind_list_h->put(s);
	if (vfo_list_h!=NULL) vfo_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-Prolog::





// [6a] SIDN_DeclList
// ------------------
SIND_DeclList::SIND_DeclList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

SIND_DeclList::~SIND_DeclList()
{
}

ostream& SIND_DeclList::put(ostream& s) const
{
	s << INDENT << "SIND_DeclList[" << endl;
	std::vector<rchandle<parsenode> >::const_iterator it = sind_hv.begin();
	for (; it!=sind_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-SIND_DeclList::





// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

VFO_DeclList::~VFO_DeclList()
{
}

ostream& VFO_DeclList::put(ostream& s) const
{
	s << INDENT << "VFO_DeclList[" << endl;
	std::vector<rchandle<parsenode> >::const_iterator it = vfo_hv.begin();
	for (; it!=vfo_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VFO_DeclList::




// [6c] SIND_Decl
// --------------
SIND_Decl::SIND_Decl(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

SIND_Decl::~SIND_Decl()
{
}

ostream& SIND_Decl::put(ostream& os) const
{
	return os;
}

//-SIND_Decl::




// [6d] VFO_Decl
// -------------
VFO_Decl::VFO_Decl(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

VFO_Decl::~VFO_Decl()
{
}

ostream& VFO_Decl::put(ostream& os) const
{
	return os;
}

//-VFO_Decl::




// [7] Setter
// ----------
Setter::Setter(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

Setter::~Setter()
{
}

ostream& Setter::put(ostream& os) const
{
	return os;
}

//-Setter::




// [8] Import
// ----------
Import::Import(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}
	
Import::~Import()
{
}

ostream& Import::put(ostream& os) const
{
	return os;
}

//-Import::




// [9] Separator
// -------------
// (Lexical rule)




// [10] NamespaceDecl
// ------------------
NamespaceDecl::NamespaceDecl(
	location const& _loc,
	context const& _ctx,
	std::string const& _prefix,
	std::string const& _uri)
:
	parsenode(_loc,_ctx),
	prefix(_prefix),
	uri(_uri)
{
}

NamespaceDecl::~NamespaceDecl()
{
}

ostream& NamespaceDecl::put(ostream& s) const
{
	s << INDENT << "NamespaceDecl[";
	s << prefix << " = " << uri;
	return s << OUTDENT << "]\n";
}

//-NamespaceDecl::




// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
	location const& _loc,
	context const& _ctx,
	context::boundary_space_mode_t _mode)
:
	parsenode(_loc,_ctx),
	mode(_mode)
{
}

BoundarySpaceDecl::~BoundarySpaceDecl()
{
}

ostream& BoundarySpaceDecl::put(ostream& s) const
{
	s << INDENT << "BoundarySpaceDecl[";
	switch (mode) {
	case context::preserve_space: s << "preserve"; break;
	case context::strip_space:	s << "strip"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-BoundarySpaceDecl::




// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
	location const& _loc,
	context const& _ctx,
	enum default_namespace_mode_t _mode,
	std::string const& _default_namespace)
:
	parsenode(_loc,_ctx),
	mode(_mode),
	default_namespace(_default_namespace)
{
}

DefaultNamespaceDecl::~DefaultNamespaceDecl()
{
}

ostream& DefaultNamespaceDecl::put(ostream& s) const
{
	s << INDENT << "DefaultNamespaceDecl[";
	switch (mode) {
	case ns_element_default: s << "element: "; break;
	case ns_function_default: s << "function: "; break;
	default: s << "???";
	}
	return s << default_namespace << "]\n";
}

//-DefaultNamespaceDecl::




// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h,
	std::string const& _val)
:
	parsenode(_loc,_ctx),
	qname_h(_qname_h),
	val(_val)
{
}

OptionDecl::~OptionDecl()
{
}

ostream& OptionDecl::put(ostream& s) const
{
	s << INDENT << "OptionDecl[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	s << " " << val << endl;
	return s << OUTDENT << "]\n";
}

//-OptionDecl::




// [13a] FTOptionDecl
// ------------------
FTOptionDecl::FTOptionDecl(
  yy::location const& _loc,
	context const& _ctx,
  rchandle<parsenode> _match_option_h)
:
  parsenode(_loc,_ctx),
 	match_option_h(_match_option_h)
{
}

FTOptionDecl::~FTOptionDecl()
{
}

ostream& FTOptionDecl::put(ostream& s) const
{
	s << INDENT << "FTOptionDecl[";
	if (match_option_h!=NULL) match_option_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTOptionDecl::





// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl(
	location const& _loc,
	context const& _ctx,
	context::ordering_mode_t _mode)
:
	parsenode(_loc,_ctx),
	mode(_mode)
{
}

OrderingModeDecl::~OrderingModeDecl()
{
}

ostream& OrderingModeDecl::put(ostream& s) const
{
	s << INDENT << "OrderingModeDecl[";
	switch (mode) {
	case context::ordered: s << "ordered"; break;
	case context::unordered: s << "unordered"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderingModeDecl::




// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
	location const& _loc,
	context const& _ctx,
	context::order_empty_mode_t _mode)
:
	parsenode(_loc,_ctx),
	mode(_mode)
{
}

EmptyOrderDecl::~EmptyOrderDecl()
{
}

ostream& EmptyOrderDecl::put(ostream& s) const
{
	s << INDENT << "EmptyOrderDecl[";
	switch (mode) {
	case context::empty_greatest: s << "greatest"; break;
	case context::empty_least: s << "least"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-EmptyOrderDecl::




// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
	location const& _loc,
	context const& _ctx,
	rchandle<PreserveMode> _preserve_h,
	rchandle<InheritMode> _inherit_h)
:
	parsenode(_loc,_ctx),
	preserve_h(_preserve_h),
	inherit_h(_inherit_h)
{
}

CopyNamespacesDecl::~CopyNamespacesDecl()
{
}

ostream& CopyNamespacesDecl::put(ostream& s) const
{
	s << INDENT << "CopyNamespacesDecl[";
	if (preserve_h!=NULL) preserve_h->put(s);
	if (inherit_h!=NULL) inherit_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CopyNamespacesDecl::




// [17] PreserveMode
// -----------------
PreserveMode::PreserveMode(
	location const& _loc,
	context const& _ctx,
	context::copy_ns_mode_t _preserve_mode)
:
	parsenode(_loc,_ctx),
	preserve_mode(_preserve_mode)
{
}

PreserveMode::~PreserveMode()
{
}

ostream& PreserveMode::put(ostream& s) const
{
	s << INDENT << "PreserveMode[";
	switch (preserve_mode) {
	case context::inherit_ns: s << "inherit"; break;
	case context::no_inherit_ns: s << "no-inherit"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-PreserveMode::




// [18] InheritMode
// ----------------
InheritMode::InheritMode(
	location const& _loc,
	context const& _ctx,
	context::copy_ns_mode_t _inherit_mode)
:
	parsenode(_loc,_ctx),
	inherit_mode(_inherit_mode)
{
}

InheritMode::~InheritMode()
{
}

ostream& InheritMode::put(ostream& s) const
{
	s << INDENT << "InheritMode[";
	switch (inherit_mode) {
	case context::preserve_ns: s << "preserve"; break;
	case context::no_preserve_ns: s << "no-preserve"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-InheritMode::





// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl(
	location const& _loc,
	context const& _ctx,
	std::string const&  _collation)
:
	parsenode(_loc,_ctx),
	collation(_collation)
{
}

DefaultCollationDecl::~DefaultCollationDecl()
{
}

ostream& DefaultCollationDecl::put(ostream& s) const
{
	s << INDENT << "DefaultCollationDecl[";
	s << "collation=" << collation << endl;
	return s << OUTDENT << "]\n";
}

//-DefaultCollationDecl::





// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
	location const& _loc,
	context const& _ctx,
	std::string const& _base_uri)
:
	parsenode(_loc,_ctx),
	base_uri(_base_uri)
{
}

BaseURIDecl::~BaseURIDecl()
{
}

ostream& BaseURIDecl::put(ostream& s) const
{
	s << INDENT << "BaseURIDecl[";
	s << base_uri;
	return s << OUTDENT << "]\n";
}

//-BaseURIDecl::





// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
	location const& _loc,
	context const& _ctx,
	rchandle<SchemaPrefix> _prefix_h,
	std::string const& _uri,
	rchandle<URILiteralList> _at_list_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "SchemaImport[";
	if (prefix_h!=NULL) prefix_h->put(s);
	s << "uri=" << uri << endl;
	if (at_list_h!=NULL) at_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-SchemaImport::





// [21a] URLLiteralList
// --------------------
URILiteralList::URILiteralList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

URILiteralList::~URILiteralList()
{
}

ostream& URILiteralList::put(ostream& s) const
{
	s << INDENT << "URILiteralList[" << endl;
	++printdepth;
	std::vector<string>::const_iterator it = uri_v.begin();
	for (; it!=uri_v.end(); ++it) { s << *it << endl; }
	return s << OUTDENT << "]\n";
}

//-URILiteralList::





// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix(
	location const& _loc,
	context const& _ctx,
	bool _default_b)
:
	parsenode(_loc,_ctx),
	prefix(""),
	default_b(_default_b)
{
}

SchemaPrefix::SchemaPrefix(
	location const& _loc,
	context const& _ctx,
	std::string const& _prefix) 
:
	parsenode(_loc,_ctx),
	prefix(_prefix),
	default_b(false)
{
}

SchemaPrefix::~SchemaPrefix()
{
}

ostream& SchemaPrefix::put(ostream& s) const
{
	s << INDENT << "SchemaPrefix[";
	s << "prefix=" << prefix << endl;
	s << "default_b=" << default_b << endl;
	return s << OUTDENT << "]\n";
}

//-SchemaPrefix::





// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
	location const& _loc,
	context const& _ctx,
	std::string const& uri,
	rchandle<URILiteralList> _uri_list_h)
:
	parsenode(_loc,_ctx),
	uri_list_h(_uri_list_h)
{
}

ModuleImport::ModuleImport(
	location const& _loc,
	context const& _ctx,
	std::string const& _prefix,
	std::string const& _uri,
	rchandle<URILiteralList> _uri_list_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "ModuleImport[";
	s << "prefix=" << prefix << endl;
	s << "uri=" << uri << endl;
	if (uri_list_h!=NULL) uri_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ModuleImport::





// [24] VarDecl
// ------------
VarDecl::VarDecl(
	location const& _loc,
	context const& _ctx,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<exprnode> _initexpr_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "VarDecl[";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (initexpr_h!=NULL) initexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarDecl::





// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl(
	location const& _loc,
	context const& _ctx,
	enum context::construction_mode_t _mode)
:
	parsenode(_loc,_ctx),
	mode(_mode)
{
}

ConstructionDecl::~ConstructionDecl()
{
}

ostream& ConstructionDecl::put(ostream& os) const
{
	os << INDENT << "ConstructionDecl[";
	switch (mode) {
	case context::cons_preserve: os << "preserve"; break;
	case context::cons_strip: os << "strip"; break;
	default: os << "???";
	}
	return os << OUTDENT << "]\n";
}

//-ConstructionDecl::




// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _name_h,
	rchandle<ParamList> _paramlist_h,
	rchandle<SequenceType> _return_type_h,
	rchandle<EnclosedExpr> _body_h,
	enum function_type_t _type)
:
	parsenode(_loc,_ctx),
	type(_type),
	name_h(_name_h),
	paramlist_h(_paramlist_h),
	body_h(_body_h),
	return_type_h(_return_type_h)
{
}

FunctionDecl::~FunctionDecl()
{
}

ostream& FunctionDecl::put(ostream& s) const
{
	s << INDENT << "Xxxx[";
	if (name_h!=NULL) name_h->put(s,ctx);
	if (paramlist_h!=NULL) paramlist_h->put(s);
	if (return_type_h!=NULL) return_type_h->put(s);
	if (body_h!=NULL) body_h->put(s);
	switch (type) {
	case fn_extern: s << "fn_extern"; break;
	case fn_read: s << "fn_read"; break;
	case fn_update: s << "fn_update"; break;
	case fn_extern_update: s << "fn_extern_update"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-FunctionDecl::




// [27] ParamList
// --------------
ParamList::ParamList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

ParamList::~ParamList()
{
}

ostream& ParamList::put(ostream& s) const
{
	s << INDENT << "ParamList[" << endl;
	++printdepth;
	std::vector<rchandle<Param> >::const_iterator it = param_hv.begin();
	for (; it!=param_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ParamList::





// [28] Param
// ----------
Param::Param(
	location const& _loc,
	context const& _ctx,
	std::string _name,
	rchandle<TypeDeclaration> _typedecl_h)
:
	parsenode(_loc,_ctx),
	name(_name),
	typedecl_h(_typedecl_h)
{
}

Param::~Param()
{
}

ostream& Param::put(ostream& s) const
{
	s << INDENT << "Param[";
	s << "name=" << name << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	return s << OUTDENT << "]\n";
}

//-Param::





// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

EnclosedExpr::~EnclosedExpr()
{
}

ostream& EnclosedExpr::put(ostream& s) const
{
	s << INDENT << "EnclosedExpr[\n";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-EnclosedExpr::





// [30] QueryBody
// --------------
QueryBody::QueryBody(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

QueryBody::~QueryBody()
{
}

ostream& QueryBody::put(ostream& s) const
{
	s << INDENT << "QueryBody[\n";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QueryBody::





// [31] Expr
// ---------
Expr::Expr(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

Expr::~Expr()
{
}

ostream& Expr::put(ostream& s) const
{
	s << INDENT << "Expr[\n";
	std::vector<rchandle<exprnode> >::const_iterator it = expr_hv.begin();
	for (; it!=expr_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-Expr::





// [32] ExprSingle
// ---------------
ExprSingle::ExprSingle(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

ExprSingle::~ExprSingle()
{
}

ostream& ExprSingle::put(ostream& s) const
{
	s << INDENT << "ExprSingle[";
	return s << OUTDENT << "]\n";
}

//-ExprSingle::





// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ForLetClauseList> _forlet_list_h,
	rchandle<WhereClause> _where_h,
	rchandle<OrderByClause> _orderby_h,
	rchandle<exprnode> _return_val_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "FLWORExpr[\n";
	if (forlet_list_h!=NULL) forlet_list_h->put(s);
	if (where_h!=NULL) {
		s << INDENT << "WHERE\n"; UNDENT;
		where_h->put(s);
	}
	if (orderby_h!=NULL) {
		s << INDENT << "ORDERBY\n"; UNDENT;
		orderby_h->put(s);
	}
	if (return_val_h!=NULL) {
		s << INDENT << "RETURN\n"; UNDENT;
		return_val_h->put(s);
	}
	return s << OUTDENT << "]\n";
}

//-FLWORExpr::





// [33a] ForLetClauseList
// ----------------------
ForLetClauseList::ForLetClauseList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

ForLetClauseList::~ForLetClauseList()
{
}

ostream& ForLetClauseList::put(ostream& s) const
{
	s << INDENT << "ForLetClauseList[\n";
	std::vector<rchandle<parsenode> >::const_iterator it = forlet_hv.begin();
	for (; it!=forlet_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ForLetClauseList::





// [33b] ForLetClause
// ------------------
ForLetClause::ForLetClause(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

ForLetClause::~ForLetClause()
{
}

ostream& ForLetClause::put(ostream& s) const
{
	s << INDENT << "ForLetClause[\n";
	return s << OUTDENT << "]\n";
}

//-ForLetClause::





// [34] ForClause
// --------------
ForClause::ForClause(
	location const& _loc,
	context const& _ctx,
	rchandle<VarInDeclList> _vardecl_list_h)
:
	parsenode(_loc,_ctx),
	vardecl_list_h(_vardecl_list_h)
{
}

ForClause::~ForClause()
{
}

ostream& ForClause::put(ostream& s) const
{
	s << INDENT << "ForClause[\n";
	if (vardecl_list_h!=NULL) vardecl_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ForClause::





// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

VarInDeclList::~VarInDeclList()
{
}

ostream& VarInDeclList::put(ostream& s) const
{
	s << INDENT << "VarInDeclList[\n";
	std::vector<rchandle<VarInDecl> >::const_iterator it = vardecl_hv.begin();
	for (; it!=vardecl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarInDeclList::





// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
	location const& _loc,
	context const& _ctx,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<PositionalVar> _posvar_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<exprnode> _valexpr_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "VarInDecl[";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (posvar_h!=NULL) posvar_h->put(s);
	if (ftscorevar_h!=NULL) ftscorevar_h->put(s);
	if (valexpr_h!=NULL) valexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarInDecl::





// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
	location const& _loc,
	context const& _ctx,
	std::string const& _varname)
:
	parsenode(_loc,_ctx),
	varname(_varname)
{
}

PositionalVar::~PositionalVar()
{
}

ostream& PositionalVar::put(ostream& s) const
{
	s << INDENT << "PositionalVar[";
	s << "varname=" << varname << endl;
	return s << OUTDENT << "]\n";
}

//-PositionalVar::





// [36] LetClause
// --------------
LetClause::LetClause(
	location const& _loc,
	context const& _ctx,
	rchandle<VarGetsDeclList> _vardecl_list_h)
:
	parsenode(_loc,_ctx),
	vardecl_list_h(_vardecl_list_h)
{
}

LetClause::~LetClause()
{
}

ostream& LetClause::put(ostream& s) const
{
	s << INDENT << "LetClause[\n";
	if (vardecl_list_h!=NULL) vardecl_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-LetClause::





// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

VarGetsDeclList::~VarGetsDeclList()
{
}

ostream& VarGetsDeclList::put(ostream& s) const
{
	s << INDENT << "VarGetsDeclList[\n";
	std::vector<rchandle<VarGetsDecl> >::const_iterator it = vardecl_hv.begin();
	for (; it!=vardecl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarGetsDeclList::





// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl(
	location const& _loc,
	context const& _ctx,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<exprnode> _valexpr_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "VarGetsDecl[\n";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (ftscorevar_h!=NULL) ftscorevar_h->put(s);
	if (valexpr_h!=NULL) valexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarGetsDecl::





// [36c] FTScoreVar
// ----------------
FTScoreVar::FTScoreVar(
	location const& _loc,
	context const& _ctx,
	std::string _varname)
:
	parsenode(_loc,_ctx),
	varname(_varname)
{
}

FTScoreVar::~FTScoreVar()
{
}

ostream& FTScoreVar::put(ostream& s) const
{
	s << INDENT << "FTScoreVar[";
	s << "varname=" << varname << endl;
	return s << OUTDENT << "]\n";
}

//-FTScoreVar::





// [37] WhereClause
// ----------------
WhereClause::WhereClause(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _predicate_h)
:
	parsenode(_loc,_ctx),
	predicate_h(_predicate_h)
{
}

WhereClause::~WhereClause()
{
}

ostream& WhereClause::put(ostream& s) const
{
	s << INDENT << "WhereClause[\n";
	if (predicate_h!=NULL) predicate_h->put(s);
	return s << OUTDENT << "]\n";
}

//-WhereClause::





// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause(
	location const& _loc,
	context const& _ctx,
	rchandle<OrderSpecList> _spec_list_h,
	bool _stable_b)
:
	parsenode(_loc,_ctx),
	spec_list_h(_spec_list_h),
	stable_b(_stable_b)
{
}


OrderByClause::OrderByClause(
	location const& _loc,
	context const& _ctx,
	rchandle<OrderSpecList> _spec_list_h)
:
	parsenode(_loc,_ctx),
	spec_list_h(_spec_list_h)
{
}

OrderByClause::~OrderByClause()
{
}

ostream& OrderByClause::put(ostream& s) const
{
	s << INDENT << "OrderByClause[\n";
	if (spec_list_h!=NULL) spec_list_h->put(s);
	s << "stable_b=" << stable_b << endl;
	return s << OUTDENT << "]\n";
}

//-OrderByClause::





// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

OrderSpecList::~OrderSpecList()
{
}

ostream& OrderSpecList::put(ostream& s) const
{
	s << INDENT << "OrderSpecList[\n";
	std::vector<rchandle<OrderSpec> >::const_iterator it = spec_hv.begin();
	for (; it!=spec_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-OrderSpecList::





// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _spec_h,
	rchandle<OrderModifier> _modifier_h)
:
	parsenode(_loc,_ctx),
	spec_h(_spec_h),
	modifier_h(_modifier_h)
{
}

OrderSpec::~OrderSpec()
{
}

ostream& OrderSpec::put(ostream& s) const
{
	s << INDENT << "OrderSpec[\n";
	if (spec_h!=NULL) spec_h->put(s);
	if (modifier_h!=NULL) modifier_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrderSpec::





// [41] OrderModifier
// ------------------
OrderModifier::OrderModifier(
	location const& _loc,
	context const& _ctx,
	rchandle<OrderDirSpec> _dir_spec_h,
	rchandle<OrderEmptySpec> _empty_spec_h,
	rchandle<OrderCollationSpec> _collation_spec_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "OrderModifier[";
	if (dir_spec_h!=NULL) dir_spec_h->put(s);
	if (empty_spec_h!=NULL) empty_spec_h->put(s);
	if (collation_spec_h!=NULL) collation_spec_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrderModifier::





// [41a] OrderDirSpec
// ------------------
OrderDirSpec::OrderDirSpec(
	location const& _loc,
	context const& _ctx,
	enum dir_spec_t _dir_spec)
:
	parsenode(_loc,_ctx),
	dir_spec(_dir_spec)
{
}

OrderDirSpec::~OrderDirSpec()
{
}
	
ostream& OrderDirSpec::put(ostream& s) const
{
	s << INDENT << "OrderDirSpec[";
	switch (dir_spec) {
	case dir_ascending: s << "ascending"; break;
	case dir_descending: s << "descending"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderDirSpec::





// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
	location const& _loc,
	context const& _ctx,
	context::order_empty_mode_t _empty_order_spec)
:
	parsenode(_loc,_ctx),
	empty_order_spec(_empty_order_spec)
{
}

OrderEmptySpec::~OrderEmptySpec()
{
}

ostream& OrderEmptySpec::put(ostream& s) const
{
	s << INDENT << "OrderEmptySpec[";
	switch (empty_order_spec) {
	case context::empty_greatest: s << "empty_greatest"; break;
	case context::empty_least: s << "empty_least"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderEmptySpec::





// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
	location const& _loc,
	context const& _ctx,
	std::string const& _uri)
:
	parsenode(_loc,_ctx),
	uri(_uri)
{
}

OrderCollationSpec::~OrderCollationSpec()
{
}

ostream& OrderCollationSpec::put(ostream& s) const
{
	s << INDENT << "OrderCollationSpec[";
	s << "uri=" << uri << endl;
	return s << OUTDENT << "]\n";
}

//-OrderCollationSpec::





// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr::QuantifiedExpr(
	location const& _loc,
	context const& _ctx,
	quantification_mode_t _qmode,
	rchandle<QVarInDeclList> _decl_list_h,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "QuantifiedExpr[";
	switch(qmode) {
	case quant_some: s << "some\n"; break;
	case quant_every: s << "every\n"; break;
	default: s << "???\n";
	}
	if (decl_list_h!=NULL) decl_list_h->put(s);
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QuantifiedExpr::





// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

QVarInDeclList::~QVarInDeclList()
{
}

ostream& QVarInDeclList::put(ostream& s) const
{
	s << INDENT << "QVarInDeclList[\n";
	std::vector<rchandle<QVarInDecl> >::const_iterator it = qvar_decl_hv.begin();
	for (; it!=qvar_decl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-QVarInDeclList::





// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
	location const& _loc,
	context const& _ctx,
	std::string _name,
	rchandle<exprnode> _val_h)
:
	parsenode(_loc,_ctx),
	name(_name),
	typedecl_h(NULL),
	val_h(_val_h)
{
}

QVarInDecl::QVarInDecl(
	location const& _loc,
	context const& _ctx,
	std::string _name,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<exprnode> _val_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "QVarInDecl[";
	s << "name=" << name << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (val_h!=NULL) val_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QVarInDecl::





// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	rchandle<exprnode> _default_clause_h)
:
	exprnode(_loc,_ctx),
	switch_expr_h(_switch_expr_h),
	clause_list_h(_clause_list_h),
	default_clause_h(_default_clause_h)
{
}


TypeswitchExpr::TypeswitchExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	std::string _default_varname,
	rchandle<exprnode> _default_clause_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "TypeswitchExpr[\n";
	if (switch_expr_h!=NULL) switch_expr_h->put(s);
	if (clause_list_h!=NULL) clause_list_h->put(s);
	s << "default_varname=" << default_varname << endl;
	if (default_clause_h!=NULL) default_clause_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TypeswitchExpr::




// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

CaseClauseList::~CaseClauseList()
{
}

ostream& CaseClauseList::put(ostream& s) const
{
	s << INDENT << "CaseClauseList[\n";
	std::vector<rchandle<CaseClause> >::const_iterator it = clause_hv.begin();
	for (; it!=clause_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-CaseClauseList::




// [44] CaseClause
// ---------------
CaseClause::CaseClause(
	location const& _loc,
	context const& _ctx,
	std::string _varname,
	rchandle<SequenceType> _type_h,
	rchandle<exprnode> _val_h)
:
	parsenode(_loc,_ctx),
	varname(_varname),
	type_h(_type_h),
	val_h(_val_h)
{
}

CaseClause::CaseClause(
	location const& _loc,
	context const& _ctx,
	rchandle<SequenceType> _type_h,
	rchandle<exprnode> _val_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "CaseClause[\n";
	s << "varname=" << varname << endl;
	if (type_h!=NULL) type_h->put(s);
	if (val_h!=NULL) val_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CaseClause::




// [45] IfExpr
// -----------
IfExpr::IfExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _cond_expr_h,
	rchandle<exprnode> _then_expr_h,
	rchandle<exprnode> _else_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "IfExpr[\n";
	if (cond_expr_h!=NULL) cond_expr_h->put(s);
	if (then_expr_h!=NULL) then_expr_h->put(s);
	if (else_expr_h!=NULL) else_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-IfExpr::




// [46] OrExpr
// -----------
OrExpr::OrExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _or_expr_h,
	rchandle<exprnode> _and_expr_h)
:
	exprnode(_loc,_ctx),
	or_expr_h(_or_expr_h),
	and_expr_h(_and_expr_h)
{
}

OrExpr::~OrExpr()
{
}

ostream& OrExpr::put(ostream& s) const
{
	s << INDENT << "OrExpr[\n";
	if (or_expr_h!=NULL) or_expr_h->put(s);
	if (and_expr_h!=NULL) and_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrExpr::




// [47] AndExpr
// ------------
AndExpr::AndExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _and_expr_h,
	rchandle<exprnode> _comp_expr_h)
:
	exprnode(_loc,_ctx),
	and_expr_h(_and_expr_h),
	comp_expr_h(_comp_expr_h)
{
}

AndExpr::~AndExpr()
{
}

ostream& AndExpr::put(ostream& s) const
{
	s << INDENT << "AndExpr[\n";
	if (and_expr_h!=NULL) and_expr_h->put(s);
	if (comp_expr_h!=NULL) comp_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AndExpr::




// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ValueComp> _valcomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
:
	exprnode(_loc,_ctx),
	left_h(_left_h),
	right_h(_right_h),
	valcomp_h(_valcomp_h),
	gencomp_h(NULL),
	nodecomp_h(NULL)
{
}

ComparisonExpr::ComparisonExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<GeneralComp> _gencomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
:
	exprnode(_loc,_ctx),
	left_h(_left_h),
	right_h(_right_h),
	valcomp_h(NULL),
	gencomp_h(_gencomp_h),
	nodecomp_h(NULL)
{
}

ComparisonExpr::ComparisonExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<NodeComp> _nodecomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "ComparisonExpr[\n";
	if (left_h!=NULL) left_h->put(s);
	if (valcomp_h!=NULL) valcomp_h->put(s);
	if (gencomp_h!=NULL) gencomp_h->put(s);
	if (nodecomp_h!=NULL) nodecomp_h->put(s);
	if (right_h!=NULL) right_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ComparisonExpr::




// [48a] FTContainsExpr
// --------------------
FTContainsExpr::FTContainsExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _range_expr_h,
	rchandle<FTSelection> _ftselect_h,
	rchandle<FTIgnoreOption> _ftignore_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "FTContainsExpr[\n";
	if (range_expr_h!=NULL) range_expr_h->put(s);
	if (ftselect_h!=NULL) ftselect_h->put(s);
	if (ftignore_h!=NULL) ftignore_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTContainsExpr::




// [49] RangeExpr
// --------------
RangeExpr::RangeExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _from_expr_h,
	rchandle<exprnode> _to_expr_h)
:
	exprnode(_loc,_ctx),
	from_expr_h(_from_expr_h),
	to_expr_h(_to_expr_h)
{
}

RangeExpr::~RangeExpr()
{
}

ostream& RangeExpr::put(ostream& s) const
{
	s << INDENT << "RangeExpr[\n";
	if (from_expr_h!=NULL) from_expr_h->put(s);
	s << " TO ";
	if (to_expr_h!=NULL) to_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-RangeExpr::





// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr(
	location const& _loc,
	context const& _ctx,
	enum add_op_t _add_op,
	rchandle<exprnode> _add_expr_h,
	rchandle<exprnode> _mult_expr_h)
:
	exprnode(_loc,_ctx),
	add_op(_add_op),
	add_expr_h(_add_expr_h),
	mult_expr_h(_mult_expr_h)
{
}

AdditiveExpr::~AdditiveExpr()
{
}

ostream& AdditiveExpr::put(ostream& s) const
{
	s << INDENT << "AdditiveExpr[\n";
	if (add_expr_h!=NULL) {
		add_expr_h->put(s);
		switch(add_op) {
		case op_plus: s << "plus"; break;
		case op_minus: s << "minus"; break;
		default: s << "???";
		}
	}
	if (mult_expr_h!=NULL) mult_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AdditiveExpr::





// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr(
	location const& _loc,
	context const& _ctx,
	enum mult_op_t _mult_op,
	rchandle<exprnode> _mult_expr_h,
	rchandle<exprnode> _union_expr_h)
:
	exprnode(_loc,_ctx),
	mult_op(_mult_op),
	mult_expr_h(_mult_expr_h),
	union_expr_h(_union_expr_h)
{
}

MultiplicativeExpr::~MultiplicativeExpr()
{
}

ostream& MultiplicativeExpr::put(ostream& s) const
{
	s << INDENT << "MultiplicativeExpr[\n";
	if (mult_expr_h!=NULL) mult_expr_h->put(s);
	switch(mult_op) {
	case op_times: s << "times"; break;
	case op_div: s << "div"; break;
	case op_idiv: s << "idiv"; break;
	case op_mod: s << "mod"; break;
	default: s << "???";
	}
	if (union_expr_h!=NULL) union_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-MultiplicativeExpr::





// [52] UnionExpr
// --------------
UnionExpr::UnionExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _union_expr_h,
	rchandle<exprnode> _intex_expr_h)
:
	exprnode(_loc,_ctx),
	union_expr_h(_union_expr_h),
	intex_expr_h(_intex_expr_h)
{
}

UnionExpr::~UnionExpr()
{
}

ostream& UnionExpr::put(ostream& s) const
{
	s << INDENT << "UnionExpr[\n";
	if (union_expr_h!=NULL) union_expr_h->put(s);
	if (intex_expr_h!=NULL) intex_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-UnionExpr::





// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr(
	location const& _loc,
	context const& _ctx,
	enum intex_op_t _intex_op,
	rchandle<exprnode> _intex_expr_h,
	rchandle<exprnode> _instof_expr_h)
:
	exprnode(_loc,_ctx),
	intex_op(_intex_op),
	intex_expr_h(_intex_expr_h),
	instof_expr_h(_instof_expr_h)
{
}

IntersectExceptExpr::~IntersectExceptExpr()
{
}

ostream& IntersectExceptExpr::put(ostream& s) const
{
	s << INDENT << "IntersectExceptExpr[\n";
	if (intex_expr_h!=NULL) intex_expr_h->put(s);
	switch(intex_op) {
	case op_intersect: s << "intersect"; break;
	case op_except: s << "except"; break;
	default: s << "???";
	}
	if (instof_expr_h!=NULL) instof_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-IntersectExceptExpr::





// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _treat_expr_h,
	rchandle<SequenceType> _seqtype_h)
:
	exprnode(_loc,_ctx),
	treat_expr_h(_treat_expr_h),
	seqtype_h(_seqtype_h)
{
}

InstanceofExpr::~InstanceofExpr()
{
}

ostream& InstanceofExpr::put(ostream& s) const
{
	s << INDENT << "InstanceofExpr[\n";
	if (treat_expr_h!=NULL) treat_expr_h->put(s);
	if (seqtype_h!=NULL) seqtype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-InstanceofExpr::





// [55] TreatExpr
// --------------
TreatExpr::TreatExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _castable_expr_h,
	rchandle<SequenceType> _seqtype_h)
:
	exprnode(_loc,_ctx),
	castable_expr_h(_castable_expr_h),
	seqtype_h(_seqtype_h)
{
}

TreatExpr::~TreatExpr()
{
}

ostream& TreatExpr::put(ostream& s) const
{
	s << INDENT << "TreatExpr[\n";
	if (castable_expr_h!=NULL) castable_expr_h->put(s);
	if (seqtype_h!=NULL) seqtype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TreatExpr::




// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _cast_expr_h,
	rchandle<SingleType> _singletype_h)
:
	exprnode(_loc,_ctx),
	cast_expr_h(_cast_expr_h),
	singletype_h(_singletype_h)
{
}

CastableExpr::~CastableExpr()
{
}

ostream& CastableExpr::put(ostream& s) const
{
	s << INDENT << "CastableExpr[\n";
	if (cast_expr_h!=NULL) cast_expr_h->put(s);
	if (singletype_h!=NULL) singletype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CastableExpr::




// [57] CastExpr 	   
// -------------
CastExpr::CastExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _unary_expr_h,
	rchandle<SingleType> _singletype_h)
:
	exprnode(_loc,_ctx),
	unary_expr_h(_unary_expr_h),
	singletype_h(_singletype_h)
{
}

CastExpr::~CastExpr()
{
}

ostream& CastExpr::put(ostream& s) const
{
	s << INDENT << "CastExpr[\n";
	if (unary_expr_h!=NULL) unary_expr_h->put(s);
	if (singletype_h!=NULL) singletype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CastExpr::





// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<SignList> _signlist_h,
	rchandle<exprnode> _value_expr_h)
:
	exprnode(_loc,_ctx),
	value_expr_h(_value_expr_h),
	signlist_h(_signlist_h)
{
}

UnaryExpr::~UnaryExpr()
{
}

ostream& UnaryExpr::put(ostream& s) const
{
	s << INDENT << "UnaryExpr[\n";
	if (signlist_h!=NULL) signlist_h->put(s);
	if (value_expr_h!=NULL) value_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-UnaryExpr::





// [58a] SignList
// --------------
SignList::SignList(
	location const& _loc,
	context const& _ctx,
	bool _sign)
:
	parsenode(_loc,_ctx),
	sign(_sign)
{
}

SignList::~SignList()
{
}

ostream& SignList::put(ostream& s) const
{
	s << INDENT << "Sign[";
	s << (sign ? "+" : "-");
	return s << OUTDENT << "]\n";
}

//-SignList::





// [59] ValueExpr
// --------------
ValueExpr::ValueExpr(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

ValueExpr::~ValueExpr()
{
}

ostream& ValueExpr::put(ostream& s) const
{
	s << INDENT << "ValueExpr[";
	return s << OUTDENT << "]\n";
}

//-ValueExpr::





// [60] GeneralComp
// ----------------
GeneralComp::GeneralComp(
	location const& _loc,
	context const& _ctx,
	enum gencomp_t _type)
:
	parsenode(_loc,_ctx),
	type(_type)
{
}

GeneralComp::~GeneralComp()
{
}

ostream& GeneralComp::put(ostream& s) const
{
	s << INDENT << "GeneralComp[";
	switch(type) {
	case op_eq: s << "eq"; break;
	case op_ne: s << "ne"; break;
	case op_lt: s << "lt"; break;
	case op_le: s << "le"; break;
	case op_gt: s << "gt"; break;
	case op_ge: s << "ge"; break;
	default: s << "???";
	}
	s << "]\n";
	UNDENT;
	return s;
}

//-GeneralComp::




// [61] ValueComp
// --------------
ValueComp::ValueComp(
	location const& _loc,
	context const& _ctx,
	enum valcomp_t _type)
:
	parsenode(_loc,_ctx),
	type(_type)
{
}

ValueComp::~ValueComp()
{
}

ostream& ValueComp::put(ostream& s) const
{
	s << INDENT << "ValueComp[";
	switch(type) {
	case op_val_eq: s << "val_eq"; break;
	case op_val_ne: s << "val_ne"; break;
	case op_val_lt: s << "val_lt"; break;
	case op_val_le: s << "val_le"; break;
	case op_val_gt: s << "val_gt"; break;
	case op_val_ge: s << "val_ge"; break;
	default: s << "???";
	}
	s << "]\n";
	UNDENT;
	return s;
}

//-ValueComp::




// [62] NodeComp
// -------------
NodeComp::NodeComp(
	location const& _loc,
	context const& _ctx,
	enum nodecomp_t _type)
:
	parsenode(_loc,_ctx),
	type(_type)
{
}

NodeComp::~NodeComp()
{
}

ostream& NodeComp::put(ostream& s) const
{
	s << INDENT << "NodeComp[";
	switch(type) {
	case op_is: s << "is"; break;
	case op_precedes: s << "precedes"; break;
	case op_follows: s << "follows"; break;
	default: s << "???";
	}
	s << "]\n";
	UNDENT;
	return s;
}

//-NodeComp::




// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
	location const& _loc,
	context const& _ctx,
	string const& _valmode,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	valmode(_valmode=="lax" ? val_lax : val_strict),
	expr_h(_expr_h)
{
}

ValidateExpr::~ValidateExpr()
{
}

ostream& ValidateExpr::put(ostream& s) const
{
	s << INDENT << "ValidateExpr[";
	switch(valmode) {
	case val_strict: s << "strict\n"; break;
	case val_lax: s << "lax\n"; break;
	default: s << "???\n";
	}
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ValidateExpr::





// [64] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<PragmaList> _pragma_list_h,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	pragma_list_h(_pragma_list_h),
	expr_h(_expr_h)
{
}

ExtensionExpr::~ExtensionExpr()
{
}

ostream& ExtensionExpr::put(ostream& s) const
{
	s << INDENT << "ExtensionExpr[\n";
	if (pragma_list_h!=NULL) pragma_list_h->put(s);
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ExtensionExpr::




// [64a] PragmaList
// ----------------
PragmaList::PragmaList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

PragmaList::~PragmaList()
{
}

ostream& PragmaList::put(ostream& s) const
{
	s << INDENT << "PragmaList[\n";
	std::vector<rchandle<Pragma> >::const_iterator it = pragma_hv.begin();
	for (; it!=pragma_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-PragmaList::




// [65] Pragma
// -----------
Pragma::Pragma(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _name,
	std::string _pragma_lit)
:
	parsenode(_loc,_ctx),
	name(_name),
	pragma_lit(_pragma_lit)
{
}

Pragma::~Pragma()
{
}

ostream& Pragma::put(ostream& s) const
{
	s << INDENT << "Pragma[";
	if (name!=NULL) name->put(s,ctx);
	s << "pragma_lit=" << pragma_lit << endl;
	return s << OUTDENT << "]\n";
}

//-Pragma::




// [66] PragmaContents
// -------------------
/* folded into [65] */



// [67] PathExpr
// -------------
PathExpr::PathExpr(
	location const& _loc,
	context const& _ctx,
	enum pathtype_t _type,
	rchandle<exprnode> _relpath_expr_h)
:
	exprnode(_loc,_ctx),
	type(_type),
	relpath_expr_h(_relpath_expr_h)
{
}

PathExpr::~PathExpr()
{
}

ostream& PathExpr::put(ostream& s) const
{
	s << INDENT << "PathExpr[";
	switch(type) {
	case path_leading_lone_slash: s << "leading_lone_slash\n"; break;
	case path_leading_slash: s << "leading_slash\n"; break;
	case path_leading_slashslash: s << "leading_slashslash\n"; break;
	case path_relative: s << "relative\n"; break;
	default: s << "???\n";
	}
	if (relpath_expr_h!=NULL) relpath_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-PathExpr::




// [68] RelativePathExpr
// ---------------------
RelativePathExpr::RelativePathExpr(
	location const& _loc,
	context const& _ctx,
	enum steptype_t _step_type,
	rchandle<exprnode> _step_expr_h,
	rchandle<exprnode> _relpath_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "RelativePathExpr[\n";
	if (step_expr_h!=NULL) {
		step_expr_h->put(s);
	}
	if (relpath_expr_h!=NULL) {
		switch(step_type) {
		case st_slash: s << INDENT << "SLASH\n"; UNDENT; break;
		case st_slashslash: s << INDENT << "SLASHSLASH\n"; UNDENT;  break;
		default: s << "\n";
		}
		relpath_expr_h->put(s);
	}
	return s << OUTDENT << "]\n";
}

//-RelativePathExpr::




// [69] StepExpr
// -------------
StepExpr::StepExpr(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

StepExpr::~StepExpr()
{
}

ostream& StepExpr::put(ostream& s) const
{
	s << INDENT << "StepExpr[";
	return s << OUTDENT << "]\n";
}

//-StepExpr::




// [70] AxisStep
// -------------
AxisStep::AxisStep(
	location const& _loc,
	context const& _ctx,
	rchandle<ForwardStep> _forward_step_h,
	rchandle<PredicateList> _predicate_list_h)
:
	exprnode(_loc,_ctx),
	forward_step_h(_forward_step_h),
	reverse_step_h(NULL),
	predicate_list_h(_predicate_list_h)
{
}

AxisStep::AxisStep(
	location const& _loc,
	context const& _ctx,
	rchandle<ReverseStep> _reverse_step_h,
	rchandle<PredicateList> _predicate_list_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "AxisStep[\n";
	if (forward_step_h!=NULL) forward_step_h->put(s);
	if (reverse_step_h!=NULL) reverse_step_h->put(s);
	if (predicate_list_h!=NULL) predicate_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AxisStep::




// [71] ForwardStep
// ----------------
ForwardStep::ForwardStep(
	location const& _loc,
	context const& _ctx,
	rchandle<ForwardAxis> _forward_axis_h,
	rchandle<parsenode> _node_test_h)
:
	parsenode(_loc,_ctx),
	forward_axis_h(_forward_axis_h),
	node_test_h(_node_test_h),
	abbrev_step_h(NULL)
{
}

ForwardStep::ForwardStep(
	location const& _loc,
	context const& _ctx,
	rchandle<AbbrevForwardStep> _abbrev_step_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "ForwardStep[\n";
	if (forward_axis_h!=NULL) forward_axis_h->put(s);
	if (node_test_h!=NULL) node_test_h->put(s);
	if (abbrev_step_h!=NULL) abbrev_step_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ForwardStep::




// [72] ForwardAxis
// ----------------
ForwardAxis::ForwardAxis(
	location const& _loc,
	context const& _ctx,
	enum forward_axis_t _axis)
:
	parsenode(_loc,_ctx),
	axis(_axis)
{
}

ForwardAxis::~ForwardAxis()
{
}

ostream& ForwardAxis::put(ostream& s) const
{
	s << INDENT << "ForwardAxis[\n";
	switch(axis) {
	case axis_child: s << "child,"; break;
	case axis_descendant: s << "descendant"; break;
	case axis_attribute: s << "attribute"; break;
	case axis_self: s << "self"; break;
	case axis_descendant_or_self: s << "descendant_or_self"; break;
	case axis_following_sibling: s << "following_sibling"; break;
	case axis_following: s << "following"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-ForwardAxis::




// [73] AbbrevForwardStep
// ----------------------
AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	context const& _ctx,
	rchandle<parsenode> _node_test_h,
	bool _attr_b)
:
	parsenode(_loc,_ctx),
	node_test_h(_node_test_h),
	attr_b(_attr_b)
{
}

AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	context const& _ctx,
	rchandle<parsenode> _node_test_h)
:
	parsenode(_loc,_ctx),
	node_test_h(_node_test_h),
	attr_b(false)
{
}

AbbrevForwardStep::~AbbrevForwardStep()
{
}

ostream& AbbrevForwardStep::put(ostream& s) const
{
	s << INDENT << "AbbrevForwardStep[";
	s << (attr_b ? "@\n" : "\n");
	if (node_test_h!=NULL) node_test_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AbbrevForwardStep::




// [74] ReverseStep
// ----------------
ReverseStep::ReverseStep(
	location const& _loc,
	context const& _ctx,
	rchandle<ReverseAxis> _axis_h,
	rchandle<parsenode> _node_test_h)
:
	parsenode(_loc,_ctx),
	axis_h(_axis_h),
	node_test_h(_node_test_h)
{
}

ReverseStep::~ReverseStep()
{
}

ostream& ReverseStep::put(ostream& s) const
{
	s << INDENT << "ReverseStep[\n";
	if (axis_h!=NULL) axis_h->put(s);
	if (node_test_h!=NULL) node_test_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ReverseStep::




// [75] ReverseAxis
// ----------------
ReverseAxis::ReverseAxis(
	location const& _loc,
	context const& _ctx,
	enum reverse_axis_t _axis)
:
	parsenode(_loc,_ctx),
	axis(_axis)
{
}

ReverseAxis::~ReverseAxis()
{
}

ostream& ReverseAxis::put(ostream& s) const
{
	s << INDENT << "ReverseAxis[\n";
	switch(axis) {
	case axis_parent: s << "parent"; break;
	case axis_ancestor: s << "ancestor"; break;
	case axis_preceding_sibling: s << "preceding_sibling"; break;
	case axis_preceding: s << "preceding"; break;
	case axis_ancestor_or_self: s << "ancestor_or_self"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-ReverseAxis::




// [76] AbbrevReverseStep
// ----------------------
/* folded into [74] */



// [77] NodeTest
// -------------
NodeTest::NodeTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

NodeTest::~NodeTest()
{
}

ostream& NodeTest::put(ostream& s) const
{
	s << INDENT << "NodeTest[]\n"; UNDENT;
	return s;
}

//-NodeTest::




// [78] NameTest
// -------------
NameTest::NameTest(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h)
:
	parsenode(_loc,_ctx),
	qname_h(_qname_h),
	wild_h(NULL)
{
}

NameTest::NameTest(
	location const& _loc,
	context const& _ctx,
	rchandle<Wildcard> _wild_h)
:
	parsenode(_loc,_ctx),
	qname_h(NULL),
	wild_h(_wild_h)
{
}

NameTest::~NameTest()
{
}

ostream& NameTest::put(ostream& s) const
{
	s << INDENT << "NameTest[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	if (wild_h!=NULL) wild_h->put(s);
	s << "]\n";
	UNDENT;
	return s;
}

//-NameTest::




// [79] Wildcard
// -------------
Wildcard::Wildcard(
	location const& _loc,
	context const& _ctx,
	enum wildcard_t _type)
:
	parsenode(_loc,_ctx),
	type(_type),
	prefix(""),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	location const& _loc,
	context const& _ctx,
	std::string const& _prefix)
:
	parsenode(_loc,_ctx),
	type(wild_prefix),
	prefix(_prefix),
	qname_h(NULL)
{
}

Wildcard::Wildcard(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h)
:
	parsenode(_loc,_ctx),
	type(wild_elem),
	prefix(""),
	qname_h(_qname_h)
{
}
	
Wildcard::~Wildcard()
{
}

ostream& Wildcard::put(ostream& s) const
{
	s << INDENT << "Wildcard[";
	switch(type) {
	case wild_all: s << "wild_all"; break;
	case wild_elem: s << "wild_elem"; break;
	case wild_prefix: s << "wild_prefix"; break;
	default: s << "???";
	}
	s << ", prefix=" << prefix << endl;
	if (qname_h!=NULL) { s << ", "; qname_h->put(s,ctx); }
	s << endl;
	UNDENT;
	return s;
}

//-Wildcard::




// [80] FilterExpr
// ---------------
FilterExpr::FilterExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _primary_h,
	rchandle<PredicateList> _pred_list_h)
:
	exprnode(_loc,_ctx),
	primary_h(_primary_h),
	pred_list_h(_pred_list_h)
{
}

FilterExpr::~FilterExpr()
{
}

ostream& FilterExpr::put(ostream& s) const
{
	s << INDENT << "FilterExpr[\n";
	if (primary_h!=NULL) primary_h->put(s);
	if (pred_list_h!=NULL) pred_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FilterExpr::




// [81] PredicateList
// ------------------
PredicateList::PredicateList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

PredicateList::~PredicateList()
{
}

ostream& PredicateList::put(ostream& s) const
{
	s << INDENT << "PredicateList[\n";
	std::vector<rchandle<Predicate> >::const_iterator it = pred_hv.begin();
	for (; it!=pred_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-PredicateList::




// [82] Predicate
// --------------
Predicate::Predicate(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _pred_h)
:
	exprnode(_loc,_ctx),
	pred_h(_pred_h)
{
}

Predicate::~Predicate()
{
}

ostream& Predicate::put(ostream& s) const
{
	s << INDENT << "Predicate[\n";
	if (pred_h!=NULL) pred_h->put(s);
	return s << OUTDENT << "]\n";
}

//-Predicate::




// [83] PrimaryExpr
// ----------------
PrimaryExpr::PrimaryExpr(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

PrimaryExpr::~PrimaryExpr()
{
}

ostream& PrimaryExpr::put(ostream& s) const
{
	s << INDENT << "PrimaryExpr[]\n"; UNDENT;
	return s;
}

//-PrimaryExpr::





// [84] Literal
// ------------
Literal::Literal(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

Literal::~Literal()
{
}

ostream& Literal::put(ostream& s) const
{
	s << INDENT << "Literal[]\n"; UNDENT;
	return s;
}

//-Literal::




// [85] NumericLiteral
// -------------------
NumericLiteral::NumericLiteral(
	location const& _loc,
	context const& _ctx,
	int _ival)
:
	exprnode(_loc,_ctx),
	type(num_integer),
	ival(_ival)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
	context const& _ctx,
	double _dval)
:
	exprnode(_loc,_ctx),
	type(num_double),
	dval(_dval)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
	context const& _ctx,
	decimal _decval)
:
	exprnode(_loc,_ctx),
	type(num_decimal),
	decval(_decval)
{
}

NumericLiteral::~NumericLiteral()
{
}

ostream& NumericLiteral::put(ostream& s) const
{
	s << INDENT << "NumericLiteral[";
	switch(type) {
	case num_integer: s << "num_integer=" << ival; break;
	case num_decimal: s << "num_decimal=" << decval; break;
	case num_double: s << "num_double=" << dval; break;
	default: s << "???";
	}
	s << "]\n"; UNDENT; 
	return s;
}

//-NumericLiteral::




// [86] VarRef
// -----------
VarRef::VarRef(
	location const& _loc,
	context const& _ctx,
	std::string _varname)
:
	exprnode(_loc,_ctx),
	varname(_varname)
{
}

VarRef::~VarRef()
{
}

ostream& VarRef::put(ostream& s) const
{
	s << INDENT<<"VarRef[varname="<<varname<<"]\n"; UNDENT;
	return s;
}

//-VarRef::




// [87] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

ParenthesizedExpr::~ParenthesizedExpr()
{
}

ostream& ParenthesizedExpr::put(ostream& s) const
{
	s << INDENT << "ParenthesizedExpr[\n";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ParenthesizedExpr::




// [88] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

ContextItemExpr::~ContextItemExpr()
{
}

ostream& ContextItemExpr::put(ostream& s) const
{
	s << INDENT << "ContextItemExpr[]\n"; UNDENT;
	return s;
}

//-ContextItemExpr::





// [89] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

OrderedExpr::~OrderedExpr()
{
}

ostream& OrderedExpr::put(ostream& s) const
{
	s << INDENT << "OrderedExpr[";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrderedExpr::




// [90] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

UnorderedExpr::~UnorderedExpr()
{
}

ostream& UnorderedExpr::put(ostream& s) const
{
	s << INDENT << "UnorderedExpr[";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-UnorderedExpr::




// [91] FunctionCall
// -----------------

FunctionCall::FunctionCall(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _fname_h,
	rchandle<ArgList> _arg_list_h)
:
	exprnode(_loc,_ctx),
	fname_h(_fname_h),
	arg_list_h(_arg_list_h)
{
}

FunctionCall::~FunctionCall()
{
}

ostream& FunctionCall::put(ostream& s) const
{
	s << INDENT << "FunctionCall[";
	if (fname_h!=NULL) fname_h->put(s,ctx);
	s << endl;
	if (arg_list_h!=NULL) arg_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FunctionCall::




// [91a] ArgList
// -------------
ArgList::ArgList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

ArgList::~ArgList()
{
}

ostream& ArgList::put(ostream& s) const
{
	s << INDENT << "ArgList[" << endl;
	std::vector<rchandle<exprnode> >::const_iterator it = arg_hv.begin();
	for (; it!=arg_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ArgList::




// [92] Constructor
// ----------------
Constructor::Constructor(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

Constructor::~Constructor()
{
}

ostream& Constructor::put(ostream& s) const
{
	s << INDENT << "Constructor[";
	return s << OUTDENT << "]\n";
}

//-Constructor::




// [93] DirectConstructor
// ----------------------
DirectConstructor::DirectConstructor(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

DirectConstructor::~DirectConstructor()
{
}

ostream& DirectConstructor::put(ostream& s) const
{
	s << INDENT << "DirectConstructor[";
	return s << OUTDENT << "]\n";
}

//-DirectConstructor::


 

// [94] DirElemConstructor
// -----------------------

DirElemConstructor::DirElemConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _open_name_h,
	rchandle<QName> _close_name_h,
	rchandle<DirAttributeList> _attr_list_h,
	rchandle<DirElemContentList> _dir_content_list_h)
:
	exprnode(_loc,_ctx),
	elem_name_h(_open_name_h),
	attr_list_h(_attr_list_h),
	dir_content_list_h(_dir_content_list_h)
{
	// assert: open_name == close_name
	if (dir_content_list_h!=NULL) dir_content_list_h->put(cout);
	else cout << "content list empty!\n";
}

DirElemConstructor::~DirElemConstructor()
{
}

ostream& DirElemConstructor::put(ostream& s) const
{
	s << INDENT << "DirElemConstructor[";
	if (elem_name_h!=NULL) elem_name_h->put(s,ctx);
	s << endl;
	if (attr_list_h!=NULL) attr_list_h->put(s);
	if (dir_content_list_h!=NULL) dir_content_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirElemConstructor::




// [94a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

DirElemContentList::~DirElemContentList()
{
}

ostream& DirElemContentList::put(ostream& s) const
{
	s << INDENT << "DirElemContentList[" << endl;
	std::vector<rchandle<exprnode> >::const_iterator it = dir_content_hv.begin();
	for (; it!=dir_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-DirElemContentList::




// [95] DirAttributeList
// ---------------------
DirAttributeList::DirAttributeList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

DirAttributeList::~DirAttributeList()
{
}

ostream& DirAttributeList::put(ostream& s) const
{
	s << INDENT << "DirAttributeList[\n";
	std::vector<rchandle<DirAttr> >::const_iterator it = dir_attr_hv.begin();
	for (; it!=dir_attr_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-DirAttributeList::




// [95a] DirAttr
// -------------
	
DirAttr::DirAttr(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _atname_h,
	rchandle<DirAttributeValue> _dir_atval_h)
:
	parsenode(_loc,_ctx),
	atname_h(_atname_h),
	dir_atval_h(_dir_atval_h)
{
}

DirAttr::~DirAttr()
{
}

ostream& DirAttr::put(ostream& s) const
{
	s << INDENT << "DirAttr[";
	if (atname_h!=NULL) atname_h->put(s,ctx);
	s << endl;
	if (dir_atval_h!=NULL) dir_atval_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirAttr::




// [96] DirAttributeValue
// ----------------------
DirAttributeValue::DirAttributeValue(
	location const& _loc,
	context const& _ctx,
	rchandle<QuoteAttrContentList> _quot_attr_content_h)
:
	parsenode(_loc,_ctx),
	quot_attr_content_h(_quot_attr_content_h),
	apos_attr_content_h(NULL)
{
}

DirAttributeValue::DirAttributeValue(
	location const& _loc,
	context const& _ctx,
	rchandle<AposAttrContentList> _apos_attr_content_h)
:
	parsenode(_loc,_ctx),
	quot_attr_content_h(NULL),
	apos_attr_content_h(_apos_attr_content_h)
{
}

DirAttributeValue::~DirAttributeValue()
{
}

ostream& DirAttributeValue::put(ostream& s) const
{
	s << INDENT << "DirAttributeValue\n";
	if (quot_attr_content_h!=NULL) quot_attr_content_h->put(s);
	if (apos_attr_content_h!=NULL) apos_attr_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirAttributeValue::




// [96a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

QuoteAttrContentList::~QuoteAttrContentList()
{
}

ostream& QuoteAttrContentList::put(ostream& s) const
{
	s << INDENT << "QuoteAttrContentList[" << endl;
	std::vector<rchandle<QuoteAttrValueContent> >::const_iterator it = quot_atval_content_hv.begin();
	for (; it!=quot_atval_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-QuoteAttrContentList::




// [96b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

AposAttrContentList::~AposAttrContentList()
{
}

ostream& AposAttrContentList::put(ostream& s) const
{
	s << INDENT << "AposAttrContentList[" << endl;
	std::vector<rchandle<AposAttrValueContent> >::const_iterator it = apos_atval_content_hv.begin();
	for (; it!=apos_atval_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-AposAttrContentList::




// [97] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent(
	location const& _loc,
	context const& _ctx,
	std::string _quot_atcontent)
:
	parsenode(_loc,_ctx),
	quot_atcontent(_quot_atcontent),
	common_content_h(NULL)
{
}

QuoteAttrValueContent::QuoteAttrValueContent(
	location const& _loc,
	context const& _ctx,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc,_ctx),
	quot_atcontent(""),
	common_content_h(_common_content_h)
{
}

QuoteAttrValueContent::~QuoteAttrValueContent()
{
}

ostream& QuoteAttrValueContent::put(ostream& s) const
{
	s << INDENT << "QuoteAttrValueContent[";
	s << "quot_atcontent=" << quot_atcontent << endl;
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QuoteAttrValueContent::




// [98] AposAttrValueContent
// -------------------------
AposAttrValueContent::AposAttrValueContent(
	location const& _loc,
	context const& _ctx,
	std::string _apos_atcontent)
:
	parsenode(_loc,_ctx),
	apos_atcontent(_apos_atcontent),
	common_content_h(NULL)
{
}

AposAttrValueContent::AposAttrValueContent(
	location const& _loc,
	context const& _ctx,
	rchandle<CommonContent> _common_content_h)
:
	parsenode(_loc,_ctx),
	apos_atcontent(""),
	common_content_h(_common_content_h)
{
}

AposAttrValueContent::~AposAttrValueContent()
{
}

ostream& AposAttrValueContent::put(ostream& s) const
{
	s << INDENT << "AposAttrValueContent[";
	s << "apos_atcontent=" << apos_atcontent << endl;
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AposAttrValueContent::




// [99] DirElemContent
// -------------------
DirElemContent::DirElemContent(
	location const& _loc,
	context const& _ctx,
	rchandle<DirectConstructor> _direct_cons_h)
:
	exprnode(_loc,_ctx),
	direct_cons_h(_direct_cons_h)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	context const& _ctx,
	std::string _elem_content)
:
	exprnode(_loc,_ctx),
	elem_content(_elem_content)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	context const& _ctx,
	rchandle<CDataSection> _cdata_h)
:
	exprnode(_loc,_ctx),
	cdata_h(_cdata_h)
{
}

DirElemContent::DirElemContent(
	location const& _loc,
	context const& _ctx,
	rchandle<CommonContent> _common_content_h)
:
	exprnode(_loc,_ctx),
	common_content_h(_common_content_h)
{
}

DirElemContent::~DirElemContent()
{
}

ostream& DirElemContent::put(ostream& s) const
{
	s << INDENT << "DirElemContent[";
	if (direct_cons_h!=NULL) direct_cons_h->put(s);
	s << "elem_content=" << elem_content << endl;
	if (cdata_h!=NULL) cdata_h->put(s);
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirElemContent::




// [100] CommonContent
// -------------------
CommonContent::CommonContent(
	location const& _loc,
	context const& _ctx,
	enum common_content_t _type,
	std::string _ref)
:
	exprnode(_loc,_ctx),
	type(_type),
	ref(_ref),
	expr_h(NULL)
{
}

CommonContent::CommonContent(
	location const& _loc,
	context const& _ctx,
	rchandle<EnclosedExpr> _expr_h)
:
	exprnode(_loc,_ctx),
	type(cont_expr),
	ref(""),
	expr_h(_expr_h)
{
}

CommonContent::CommonContent(
	location const& _loc,
	context const& _ctx,
	enum common_content_t _type)
:
	exprnode(_loc,_ctx),
	type(cont_expr),
	ref(""),
	expr_h(NULL)
{
}

CommonContent::~CommonContent()
{
}

ostream& CommonContent::put(ostream& s) const
{
	s << INDENT << "CommonContent[";
	switch(type) {
	case cont_entity: s << "entity"; break;
	case cont_charref: s << "charref"; break;
	case cont_escape_lbrace: s << "escape_lbrace"; break;
	case cont_escape_rbrace: s << "escape_rbrace"; break;
	case cont_expr: s << "expr\n"; break;
	default: s << "???";
	}
	if (type!=cont_expr)
		s << ", ref=" << ref << endl;
	else
		if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CommonContent::




// [101] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
	location const& _loc,
	context const& _ctx,
	std::string const& _comment)
:
	exprnode(_loc,_ctx),
	comment(_comment)
{
}

DirCommentConstructor::~DirCommentConstructor()
{
}

ostream& DirCommentConstructor::put(ostream& s) const
{
	s << INDENT << "DirCommentConstructor[";
	s << "comment=" << comment << endl;
	return s << OUTDENT << "]\n";
}

//-DirCommentConstructor::




// [102] DirCommentContents
// ------------------------
/* lexical rule */



// [103] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor(
	location const& _loc,
	context const& _ctx,
	std::string const& _pi_target)
:
	exprnode(_loc,_ctx),
	pi_target(_pi_target),
	pi_content("")
{
}

DirPIConstructor::DirPIConstructor(
	location const& _loc,
	context const& _ctx,
	std::string const& _pi_target,
	std::string const& _pi_content)
:
	exprnode(_loc,_ctx),
	pi_target(_pi_target),
	pi_content(_pi_content)
{
}

DirPIConstructor::~DirPIConstructor()
{
}

ostream& DirPIConstructor::put(ostream& s) const
{
	s << INDENT << "DirPIConstructor[";
	s << "pi_target=" << pi_target << endl;
	s << "pi_content=" << pi_content << endl;
	return s << OUTDENT << "]\n";
}

//-DirPIConstructor::




// [104] DirPIContents
// -------------------
/* lexical rule */




// [105] CDataSection
// ------------------
CDataSection::CDataSection(
	location const& _loc,
	context const& _ctx,
	std::string _cdata_content)
:
	exprnode(_loc,_ctx),
	cdata_content(_cdata_content)
{
}

CDataSection::~CDataSection()
{
}

ostream& CDataSection::put(ostream& s) const
{
	s << INDENT << "CDataSection[";
	s << "cdata_content=" << cdata_content << endl;
	return s << OUTDENT << "]\n";
}

//-CDataSection::




// [106] CDataSectionContents
// --------------------------
/* lexical rule */




// [107] ComputedConstructor
// -------------------------
ComputedConstructor::ComputedConstructor(
	location const& _loc,
	context const& _ctx)
:
	exprnode(_loc,_ctx)
{
}

ComputedConstructor::~ComputedConstructor()
{
}

ostream& ComputedConstructor::put(ostream& s) const
{
	s << INDENT << "ComputedConstructor[";
	return s << OUTDENT << "]\n";
}

//-ComputedConstructor::




// [108] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

CompDocConstructor::~CompDocConstructor()
{
}

ostream& CompDocConstructor::put(ostream& s) const
{
	s << INDENT << "CompDocConstructor[";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompDocConstructor::




// [109] CompElemConstructor
// -------------------------
CompElemConstructor::CompElemConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc,_ctx),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

CompElemConstructor::CompElemConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _qname_expr_h,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "CompElemConstructor[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	if (qname_expr_h!=NULL) qname_expr_h->put(s);
	if (content_expr_h!=NULL) content_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompElemConstructor::




// [110] ContentExpr
// -----------------
/*
ContentExpr::ContentExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc,_ctx),
	expr_h(_expr_h)
{
}

ContentExpr::~ContentExpr()
{
}

ostream& ContentExpr::put(ostream& s) const
{
	s << INDENT << "ContentExpr[";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ContentExpr::
*/




// [111] CompAttrConstructor
// -------------------------
CompAttrConstructor::CompAttrConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h,
	rchandle<exprnode> _val_expr_h)
:
	exprnode(_loc,_ctx),
	qname_h(_qname_h),
	qname_expr_h(NULL),
	val_expr_h(_val_expr_h)
{
}

CompAttrConstructor::CompAttrConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _qname_expr_h,
	rchandle<exprnode> _val_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "CompAttrConstructor[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	if (qname_expr_h!=NULL) qname_expr_h->put(s);
	if (val_expr_h!=NULL) val_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompAttrConstructor::




// [112] CompTextConstructor
// -------------------------
CompTextConstructor::CompTextConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _text_expr_h)
:
	exprnode(_loc,_ctx),
	text_expr_h(_text_expr_h)
{
}

CompTextConstructor::~CompTextConstructor()
{
}

ostream& CompTextConstructor::put(ostream& s) const
{
	s << INDENT << "CompTextConstructor[";
	if (text_expr_h!=NULL) text_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompTextConstructor::




// [113] CompCommentConstructor
// ----------------------------
CompCommentConstructor::CompCommentConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _comment_expr_h)
:
	exprnode(_loc,_ctx),
	comment_expr_h(_comment_expr_h)
{
}

CompCommentConstructor::~CompCommentConstructor()
{
}

ostream& CompCommentConstructor::put(ostream& s) const
{
	s << INDENT << "CompCommentConstructor[";
	if (comment_expr_h!=NULL) comment_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompCommentConstructor::




// [114] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
	location const& _loc,
	context const& _ctx,
	std::string _target,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc,_ctx),
	target(_target),
	target_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

CompPIConstructor::CompPIConstructor(
	location const& _loc,
	context const& _ctx,
	rchandle<exprnode> _target_expr_h,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "CompPIConstructor[";
	s << "target=" << target << endl;
	if (target_expr_h!=NULL) target_expr_h->put(s);
	if (content_expr_h!=NULL) content_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompPIConstructor::




// [115] SingleType
// ----------------
SingleType::SingleType(
	location const& _loc,
	context const& _ctx,
	rchandle<AtomicType> _atomic_type_h,
	bool _hook_b)
:
	parsenode(_loc,_ctx),
	atomic_type_h(_atomic_type_h),
	hook_b(_hook_b)
{
}

SingleType::~SingleType()
{
}

ostream& SingleType::put(ostream& s) const
{
	s << INDENT << "SingleType[";
	if (atomic_type_h!=NULL) atomic_type_h->put(s);
	s << "hook_b=" << hook_b << endl;
	return s << OUTDENT << "]\n";
}

//-SingleType::




// [116] TypeDeclaration
// ---------------------
TypeDeclaration::TypeDeclaration(
	location const& _loc,
	context const& _ctx,
	rchandle<SequenceType> _seqtype_h)
:
	parsenode(_loc,_ctx),
	seqtype_h(_seqtype_h)
{
}

TypeDeclaration::~TypeDeclaration()
{
}

ostream& TypeDeclaration::put(ostream& s) const
{
	s << INDENT << "TypeDeclaration[";
	if (seqtype_h!=NULL) seqtype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TypeDeclaration::




// [117] SequenceType
// ------------------
SequenceType::SequenceType(
	location const& _loc,
	context const& _ctx,
	rchandle<ItemType> _itemtype_h,
	rchandle<OccurrenceIndicator> _occur_h)
:
	parsenode(_loc,_ctx),
	itemtype_h(_itemtype_h),
	occur_h(_occur_h)
{
}

SequenceType::~SequenceType()
{
}

ostream& SequenceType::put(ostream& s) const
{
	s << INDENT << "SequenceType[";
	if (itemtype_h!=NULL) itemtype_h->put(s);
	if (occur_h!=NULL) occur_h->put(s);
	return s << OUTDENT << "]\n";
}

//-SequenceType::




// [118] OccurrenceIndicator
// -------------------------
OccurrenceIndicator::OccurrenceIndicator(
	location const& _loc,
	context const& _ctx,
	enum occurrence_t _type)
:
	parsenode(_loc,_ctx),
	type(_type)
{
}

OccurrenceIndicator::~OccurrenceIndicator()
{
}

ostream& OccurrenceIndicator::put(ostream& s) const
{
	s << INDENT << "OccurrenceIndicator[";
	switch(type) {
	case occurs_optionally: s << "(?)"; break;
	case occurs_zero_or_more: s << "(*)"; break;
	case occurs_one_or_more: s << "(+)"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OccurrenceIndicator::




// [119] ItemType
// --------------
ItemType::ItemType(
	location const& _loc,
	context const& _ctx,
	bool _item_test_b)
:
	parsenode(_loc,_ctx),
	item_test_b(_item_test_b)
{
}

ItemType::ItemType(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx),
	item_test_b(false)
{
}

ItemType::~ItemType()
{
}

ostream& ItemType::put(ostream& s) const
{
	s << INDENT << "ItemType[";
	s << "item_test_b=" << item_test_b << endl;
	return s << OUTDENT << "]\n";
}

//-ItemType::




// [120] AtomicType
// ----------------
AtomicType::AtomicType(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _qname_h)
:
	parsenode(_loc,_ctx),
	qname_h(_qname_h)
{
}

AtomicType::~AtomicType()
{
}

ostream& AtomicType::put(ostream& s) const
{
	s << INDENT << "AtomicType[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	return s << OUTDENT << "]\n";
}

//-AtomicType::




// [121] KindTest
// --------------
KindTest::KindTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

KindTest::~KindTest()
{
}

ostream& KindTest::put(ostream& s) const
{
	s << INDENT << "KindTest[]\n"; UNDENT;
	return s;
}

//-KindTest::




// [122] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

AnyKindTest::~AnyKindTest()
{
}

ostream& AnyKindTest::put(ostream& s) const
{
	s << INDENT << "AnyKindTest[]\n"; UNDENT;
	return s;
}

//-AnyKindTest::


 

// [123] DocumentTest
// ------------------
DocumentTest::DocumentTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx),
	elem_test_h(NULL),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementTest> _elem_test_h)
:
	parsenode(_loc,_ctx),
	elem_test_h(_elem_test_h),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	context const& _ctx,
	rchandle<SchemaElementTest> _schema_elem_test_h)
:
	parsenode(_loc,_ctx),
	elem_test_h(NULL),
	schema_elem_test_h(_schema_elem_test_h)
{
}

DocumentTest::~DocumentTest()
{
}

ostream& DocumentTest::put(ostream& s) const
{
	s << INDENT << "DocumentTest[";
	if (elem_test_h!=NULL) elem_test_h->put(s);
	if (schema_elem_test_h!=NULL) schema_elem_test_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DocumentTest::




// [124] TextTest
// --------------
TextTest::TextTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

TextTest::~TextTest()
{
}

ostream& TextTest::put(ostream& s) const
{
	s << INDENT << "TextTest[]\n"; UNDENT;
	return s;
}

//-TextTest::




// [125] CommentTest
// -----------------
CommentTest::CommentTest(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

CommentTest::~CommentTest()
{
}

ostream& CommentTest::put(ostream& s) const
{
	s << INDENT << "CommentTest[]\n"; UNDENT;
	return s;
}

//-CommentTest::


 

// [126] PITest
// ------------
PITest::PITest(
	location const& _loc,
	context const& _ctx,
	std::string _target,
	std::string _content)
:
	parsenode(_loc,_ctx),
	target(_target),
	content(_content)
{
}

PITest::~PITest()
{
}

ostream& PITest::put(ostream& s) const
{
	s << INDENT << "PITest[";
	s << "target=" << target << endl;
	s << ", content=" << content << endl;
	return s << OUTDENT << "]\n";
}

//-PITest::




// [127] AttributeTest
// -------------------
AttributeTest::AttributeTest(
	location const& _loc,
	context const& _ctx,
	rchandle<AttribNameOrWildcard> _attr_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h)
:
	parsenode(_loc,_ctx),
	attr_name_or_wildcard_h(_attr_name_or_wildcard_h),
	type_name_h(_type_name_h)
{
}

AttributeTest::~AttributeTest()
{
}

ostream& AttributeTest::put(ostream& s) const
{
	s << INDENT << "AttributeTest[";
	if (attr_name_or_wildcard_h!=NULL) attr_name_or_wildcard_h->put(s);
	if (type_name_h!=NULL) type_name_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AttributeTest::




// [128] AttribNameOrWildcard
// --------------------------
AttribNameOrWildcard::AttribNameOrWildcard(
	location const& _loc,
	context const& _ctx,
	rchandle<AttributeName> _attr_name_h)
:
	parsenode(_loc,_ctx),
	attr_name_h(_attr_name_h),
	star_b(_attr_name_h==NULL)
{
}

AttribNameOrWildcard::~AttribNameOrWildcard()
{
}

ostream& AttribNameOrWildcard::put(ostream& s) const
{
	s << INDENT << "AttribNameOrWildcard[";
	if (attr_name_h!=NULL) attr_name_h->put(s);
	s << "star_b=" << star_b << endl;
	return s << OUTDENT << "]\n";
}

//-AttribNameOrWildcard::




// [129] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
	location const& _loc,
	context const& _ctx,
	rchandle<AttributeDeclaration> _attr_decl_h)
:
	parsenode(_loc,_ctx),
	attr_decl_h(_attr_decl_h)
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}

ostream& SchemaAttributeTest::put(ostream& s) const
{
	s << INDENT << "SchemaAttributeTest[";
	if (attr_decl_h!=NULL) attr_decl_h->put(s);
	return s << OUTDENT << "]\n";
}

//-SchemaAttributeTest::




// [130] AttributeDeclaration
// --------------------------
AttributeDeclaration::AttributeDeclaration(
	location const& _loc,
	context const& _ctx,
	rchandle<AttributeName> _attr_name_h)
:
	parsenode(_loc,_ctx),
	attr_name_h(_attr_name_h)
{
}

AttributeDeclaration::~AttributeDeclaration()
{
}

ostream& AttributeDeclaration::put(ostream& s) const
{
	s << INDENT << "AttributeDeclaration[";
	if (attr_name_h!=NULL) attr_name_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AttributeDeclaration::




// [131] ElementTest
// -----------------
ElementTest::ElementTest(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementNameOrWildcard> _elem_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h)
:
	parsenode(_loc,_ctx),
	elem_name_or_wildcard_h(_elem_name_or_wildcard_h),
	type_name_h(_type_name_h),
	optional_b(false)
{
}

ElementTest::ElementTest(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementNameOrWildcard> _elem_name_or_wildcard_h,
	rchandle<TypeName> _type_name_h,
	bool _optional_b)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "ElementTest[";
	if (elem_name_or_wildcard_h!=NULL) elem_name_or_wildcard_h->put(s);
	if (type_name_h!=NULL) type_name_h->put(s);
	s << "optional_b=" << optional_b << endl;
	return s << OUTDENT << "]\n";
}

//-ElementTest::




// [132] ElementNameOrWildcard
// ---------------------------
ElementNameOrWildcard::ElementNameOrWildcard(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementName> _elem_name_h)
:
	parsenode(_loc,_ctx),
	elem_name_h(_elem_name_h),
	star_b(_elem_name_h==NULL)
{
}

ElementNameOrWildcard::~ElementNameOrWildcard()
{
}

ostream& ElementNameOrWildcard::put(ostream& s) const
{
	s << INDENT << "ElementNameOrWildcard[";
	if (elem_name_h!=NULL) elem_name_h->put(s);
	s << "star_b=" << star_b << endl;
	return s << OUTDENT << "]\n";
}

//-ElementNameOrWildcard::




// [133] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementDeclaration> _elem_decl_h)
:
	parsenode(_loc,_ctx),
	elem_decl_h(_elem_decl_h)
{
}

SchemaElementTest::~SchemaElementTest()
{
}

ostream& SchemaElementTest::put(ostream& s) const
{
	s << INDENT << "SchemaElementTest[";
	if (elem_decl_h!=NULL) elem_decl_h->put(s);
	return s << OUTDENT << "]\n";
}

//-SchemaElementTest::




// [134] ElementDeclaration
// ------------------------
ElementDeclaration::ElementDeclaration(
	location const& _loc,
	context const& _ctx,
	rchandle<ElementName> _elem_name_h)
:
	parsenode(_loc,_ctx),
	elem_name_h(_elem_name_h)
{
}

ElementDeclaration::~ElementDeclaration()
{
}

ostream& ElementDeclaration::put(ostream& s) const
{
	s << INDENT << "ElementDeclaration[";
	if (elem_name_h!=NULL) elem_name_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ElementDeclaration::




// [135] AttributeName
// -------------------
AttributeName::AttributeName(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _attr_qname_h)
:
	parsenode(_loc,_ctx),
	attr_qname_h(_attr_qname_h)
{
}

AttributeName::~AttributeName()
{
}

ostream& AttributeName::put(ostream& s) const
{
	s << INDENT << "AttributeName[";
	if (attr_qname_h!=NULL) attr_qname_h->put(s,ctx);
	return s << OUTDENT << "]\n";
}

//-AttributeName::




// [136] ElementName
// -----------------
ElementName::ElementName(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _elem_qname_h)
:
	parsenode(_loc,_ctx),
	elem_qname_h(_elem_qname_h)
{
}

ElementName::~ElementName()
{
}

ostream& ElementName::put(ostream& s) const
{
	s << INDENT << "ElementName[";
	if (elem_qname_h!=NULL) elem_qname_h->put(s,ctx);
	return s << OUTDENT << "]\n";
}

//-ElementName::




// [137] TypeName
// --------------
TypeName::TypeName(
	location const& _loc,
	context const& _ctx,
	rchandle<QName> _type_qname_h)
:
	parsenode(_loc,_ctx),
	type_qname_h(_type_qname_h)
{
}

TypeName::~TypeName()
{
}

ostream& TypeName::put(ostream& s) const
{
	s << INDENT << "TypeName[";
	if (type_qname_h!=NULL) type_qname_h->put(s,ctx);
	return s << OUTDENT << "]\n";
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
	context const& _ctx,
	string const& _strval)
:
	exprnode(_loc,_ctx),
	strval(_strval)
{
}

StringLiteral::~StringLiteral()
{
}

ostream& StringLiteral::put(ostream& s) const
{
	s << INDENT << "StringLiteral[";
	s << "strval=" << strval << endl;
	return s << OUTDENT << "]\n";
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

/* a type */
// [156] QName

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
	context const& _ctx,
	rchandle<QName> _qname_h)
:
	parsenode(_loc,_ctx),
	qname_h(_qname_h)
{
}

RevalidationDecl::~RevalidationDecl()
{
}

ostream& RevalidationDecl::put(ostream& s) const
{
	s << INDENT << "RevalidationDecl[";
	if (qname_h!=NULL) qname_h->put(s,ctx);
	return s << OUTDENT << "]\n";
}

//-RevalidationDecl::




// [242]	InsertExpr
// ----------------
InsertExpr::InsertExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc,_ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

InsertExpr::~InsertExpr()
{
}

ostream& InsertExpr::put(ostream& s) const
{
	s << INDENT << "InsertExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-InsertExpr::




// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc,_ctx),
	target_expr_h(_target_expr_h)
{
}

DeleteExpr::~DeleteExpr()
{
}

ostream& DeleteExpr::put(ostream& s) const
{
	s << INDENT << "DeleteExpr[";
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DeleteExpr::




// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc,_ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

ReplaceExpr::~ReplaceExpr()
{
}

ostream& ReplaceExpr::put(ostream& s) const
{
	s << INDENT << "ReplaceExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ReplaceExpr::




// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
	location const& _loc,
	context const& _ctx,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc,_ctx),
	source_expr_h(_source_expr_h),
	target_expr_h(_target_expr_h)
{
}

RenameExpr::~RenameExpr()
{
}

ostream& RenameExpr::put(ostream& s) const
{
	s << INDENT << "RenameExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
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
	context const& _ctx,
	rchandle<VarNameList> _varname_list_h,
	rchandle<ExprSingle> _source_expr_h,
	rchandle<ExprSingle> _target_expr_h)
:
	exprnode(_loc,_ctx),
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
	s << INDENT << "TransformExpr[";
	if (varname_list_h!=NULL) varname_list_h->put(s);
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TransformExpr::






// [249a] VarNameList
// ------------------
VarNameList::VarNameList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

VarNameList::~VarNameList()
{
}

ostream& VarNameList::put(ostream& s) const
{
	s << INDENT << "VarNameList[" << endl;
	std::vector<rchandle<VarBinding> >::const_iterator it = varbinding_hv.begin();
	for (; it!=varbinding_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarNameList::






// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
	location const& _loc,
	context const& _ctx,
	std::string _varname,
	rchandle<ExprSingle> _val_h)
:
	parsenode(_loc,_ctx),
	varname(_varname),
	val_h(_val_h)
{
}

VarBinding::~VarBinding()
{
}

ostream& VarBinding::put(ostream& s) const
{
	s << INDENT << "VarBinding[";
	s << "varname=" << varname << endl;
	if (val_h!=NULL) val_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarBinding::









/*
 *
 *  Full-text productions
 *	[http://www.w3.org/TR/xquery-full-text/]
 *
 */


// [344] FTSelection
// -----------------
FTSelection::FTSelection(
	location const& _loc,
	context const& _ctx,
	rchandle<FTOr> _ftor_h,
	rchandle<FTMatchOptionProximityList> _option_list_h,
	rchandle<RangeExpr> _weight_expr_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "FTSelection[";
	if (ftor_h!=NULL) ftor_h->put(s);
	if (option_list_h!=NULL) option_list_h->put(s);
	if (weight_expr_h!=NULL) weight_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTSelection::




// [344a] FTMatchOptionProximityList
// ---------------------------------
FTMatchOptionProximityList::FTMatchOptionProximityList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTMatchOptionProximityList::~FTMatchOptionProximityList()
{
}

ostream& FTMatchOptionProximityList::put(ostream& s) const
{
	s << INDENT << "FTMatchOptionProximityList[" << endl;
	std::vector<rchandle<FTMatchOptionProximity> >::const_iterator it = opt_prox_hv.begin();
	for (; it!=opt_prox_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTMatchOptionProximityList::




// [344b] FTMatchOptionProximity
// -----------------------------
FTMatchOptionProximity::FTMatchOptionProximity(
	rchandle<FTMatchOption> _opt_h,
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx),
	opt_h(_opt_h),
	prox_h(NULL)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
	rchandle<FTProximity> _prox_h,
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx),
	opt_h(NULL),
	prox_h(_prox_h)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx),
	opt_h(NULL),
	prox_h(NULL)
{
}

FTMatchOptionProximity::~FTMatchOptionProximity()
{
}

ostream& FTMatchOptionProximity::put(ostream& s) const
{
	s << INDENT << "FTMatchOptionProximityList[";
	if (opt_h!=NULL) opt_h->put(s);
	if (prox_h!=NULL) prox_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTMatchOptionProximityList::




// [345] FTOr
// ----------
FTOr::FTOr(
	location const& _loc,
	context const& _ctx,
	rchandle<FTOr> _ftor_h,
	rchandle<FTAnd> _ftand_h)
:
	parsenode(_loc,_ctx),
	ftor_h(_ftor_h),
	ftand_h(_ftand_h)
{
}

FTOr::~FTOr()
{
}

ostream& FTOr::put(ostream& s) const
{
	s << INDENT << "FTOr[";
	if (ftor_h!=NULL) ftor_h->put(s);
	if (ftand_h!=NULL) ftand_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTOr::




// [346] FTAnd
// -----------
FTAnd::FTAnd(
	location const& _loc,
	context const& _ctx,
	rchandle<FTAnd> _ftand_h,
	rchandle<FTMildnot> _ftmild_not_h)
:
	parsenode(_loc,_ctx),
	ftand_h(_ftand_h),
	ftmild_not_h(_ftmild_not_h)
{
}

FTAnd::~FTAnd()
{
}

ostream& FTAnd::put(ostream& s) const
{
	s << INDENT << "FTAnd[";
	if (ftand_h!=NULL) ftand_h->put(s);
	if (ftmild_not_h!=NULL) ftmild_not_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTAnd::




// [347] FTMildnot
// ---------------
FTMildnot::FTMildnot(
	location const& _loc,
	context const& _ctx,
	rchandle<FTMildnot> _ftmild_not_h,
	rchandle<FTUnaryNot> _ftunary_not_h)
:
	parsenode(_loc,_ctx),
	ftmild_not_h(_ftmild_not_h),
	ftunary_not_h(_ftunary_not_h)
{
}

FTMildnot::~FTMildnot()
{
}

ostream& FTMildnot::put(ostream& s) const
{
	s << INDENT << "FTMildnot[";
	if (ftmild_not_h!=NULL) ftmild_not_h->put(s);
	if (ftunary_not_h!=NULL) ftunary_not_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTMildnot::




// [348] FTUnaryNot
// ----------------
FTUnaryNot::FTUnaryNot(
	location const& _loc,
	context const& _ctx,
	rchandle<FTWordsSelection> _words_selection_h,
	bool _not_b)
:
	parsenode(_loc,_ctx),
	words_selection_h(_words_selection_h),
	not_b(_not_b)
{
}

FTUnaryNot::~FTUnaryNot()
{
}

ostream& FTUnaryNot::put(ostream& s) const
{
	s << INDENT << "FTUnaryNot[";
	if (words_selection_h!=NULL) words_selection_h->put(s);
	s << "not_b=" << not_b << endl;
	return s << OUTDENT << "]\n";
}

//-FTUnaryNot::





// [349] FTWordsSelection
// ----------------------
FTWordsSelection::FTWordsSelection(
	location const& _loc,
	context const& _ctx,
	rchandle<FTWords> _words_h,
	rchandle<FTTimes> _times_h,
	rchandle<FTSelection> _selection_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "Xxxx[";
	return s << OUTDENT << "]\n";
}

//-FTWordsSelection::






// [350] FTWords
// -------------
FTWords::FTWords(
	location const& _loc,
	context const& _ctx,
	rchandle<FTWordsValue> _words_val_h,
	rchandle<FTAnyallOption> _any_all_option_h)
:
	parsenode(_loc,_ctx),
	words_val_h(_words_val_h),
	any_all_option_h(_any_all_option_h)
{
}

FTWords::~FTWords()
{
}

ostream& FTWords::put(ostream& s) const
{
	s << INDENT << "Xxxx[";
	return s << OUTDENT << "]\n";
}

//-FTWords::



// [351] FTWordsValue
// ------------------
FTWordsValue::FTWordsValue(
	location const& _loc,
	context const& _ctx,
	rchandle<Literal> _lit_h,
	rchandle<Expr> _expr_h)
:
	parsenode(_loc,_ctx),
	lit_h(_lit_h),
	expr_h(_expr_h)
{
}

FTWordsValue::~FTWordsValue()
{
}

ostream& FTWordsValue::put(ostream& s) const
{
	s << INDENT << "FTWordsValue[";
	return s << OUTDENT << "]\n";
}

//-FTWordsValue::



// [352] FTProximity
// -----------------
FTProximity::FTProximity(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTProximity::~FTProximity()
{
}

ostream& FTProximity::put(ostream& s) const
{
	s << INDENT << "FTProximity[";
	return s << OUTDENT << "]\n";
}

//-FTProximity::



// [353] FTOrderedIndicator
// ------------------------
FTOrderedIndicator::FTOrderedIndicator(
	location const& _loc,
	context const& _ctx)
:
	FTProximity(_loc,_ctx)
{
}

FTOrderedIndicator::~FTOrderedIndicator()
{
}

ostream& FTOrderedIndicator::put(ostream& s) const
{
	s << INDENT << "FTOrderedIndicator[";
	return s << OUTDENT << "]\n";
}

//-FTOrderedIndicator::



// [354] FTMatchOption 	
// -------------------
FTMatchOption::FTMatchOption(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTMatchOption::~FTMatchOption()
{
}

ostream& FTMatchOption::put(ostream& s) const
{
	s << INDENT << "FTMatchOption[";
	return s << OUTDENT << "]\n";
}

//-FTMatchOption::



// [355] FTCaseOption
// ------------------
FTCaseOption::FTCaseOption(
	location const& _loc,
	context const& _ctx,
	ft_case_mode_t _mode)
:
	FTMatchOption(_loc,_ctx),
	mode(_mode)
{
}

FTCaseOption::~FTCaseOption()
{
}

ostream& FTCaseOption::put(ostream& s) const
{
	s << INDENT << "FTCaseOption[";
	return s << OUTDENT << "]\n";
}

//-FTCaseOption::



// [356] FTDiacriticsOption
// ------------------------
FTDiacriticsOption::FTDiacriticsOption(
	location const& _loc,
	context const& _ctx,
	ft_diacritics_mode_t _mode)
:
	FTMatchOption(_loc,_ctx),
	mode(_mode)
{
}

FTDiacriticsOption::~FTDiacriticsOption()
{
}

ostream& FTDiacriticsOption::put(ostream& s) const
{
	s << INDENT << "FTDiacriticsOptino[";
	return s << OUTDENT << "]\n";
}

//-FTDiacriticsOption::



// [357] FTStemOption
// ------------------
FTStemOption::FTStemOption(
	location const& _loc,
	context const& _ctx,
	ft_stem_mode_t _mode)
:
	FTMatchOption(_loc,_ctx),
	mode(_mode)
{
}

FTStemOption::~FTStemOption()
{
}

ostream& FTStemOption::put(ostream& s) const
{
	s << INDENT << "FTStemOption[";
	return s << OUTDENT << "]\n";
}

//-FTStemOption::



// [358] FTThesaurusOption
// -----------------------
FTThesaurusOption::FTThesaurusOption(
	location const& _loc,
	context const& _ctx,
	rchandle<FTThesaurusID> _thesaurusid_h,
	rchandle<FTThesaurusList> _thesaurus_list_h,
	bool _default_b,
	bool _without_b)
:
	FTMatchOption(_loc,_ctx),
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
	s << INDENT << "FTThesaurusOption[";
	return s << OUTDENT << "]\n";
}

//-FTThesaurusOption::



// [358a] FTThesaurusList
// ----------------------
FTThesaurusList::FTThesaurusList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTThesaurusList::~FTThesaurusList()
{
}

ostream& FTThesaurusList::put(ostream& s) const
{
	s << INDENT << "FTThesaurusIDList[" << endl;
	++printdepth;
	std::vector<rchandle<FTThesaurusID> >::const_iterator it = thesaurus_hv.begin();
	for (; it!=thesaurus_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTThesaurusList::



// [359] FTThesaurusID
// -------------------
FTThesaurusID::FTThesaurusID(
	location const& _loc,
	context const& _ctx,
	std::string _thesaurus_name,
	std::string _relationship_name,
	rchandle<FTRange> _levels_h)
:
	parsenode(_loc,_ctx),
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
	s << INDENT << "FTThesaurusID[";
	return s << OUTDENT << "]\n";
}

//-FTThesaurusID::



// [360] FTStopwordOption
// ----------------------
FTStopwordOption::FTStopwordOption(
	location const& _loc,
	context const& _ctx,
	rchandle<FTRefOrList> _refor_list_h,
	rchandle<FTInclExclStringLiteralList> _incl_excl_list_h,
	stop_words_mode_t _mode)
:
	FTMatchOption(_loc,_ctx),
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
	s << INDENT << "FTStopwordOption[";
	return s << OUTDENT << "]\n";
}

//-FTStopwordOption::



// [360a] FTInclExclStringLiteralList
// ----------------------------------
FTInclExclStringLiteralList::FTInclExclStringLiteralList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTInclExclStringLiteralList::~FTInclExclStringLiteralList()
{
}

ostream& FTInclExclStringLiteralList::put(ostream& s) const
{
	s << INDENT << "FTInclExclStringLiteralList[" << endl;
	++printdepth;
	std::vector<rchandle<FTInclExclStringLiteral> >::const_iterator it =
		incl_excl_lit_hv.begin();
	for (; it!=incl_excl_lit_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTInclExclStringLiteralList::



// [361] FTRefOrList
// -----------------
FTRefOrList::FTRefOrList(
	location const& _loc,
	context const& _ctx,
	std::string _at_str,
	rchandle<FTStringLiteralList> _stringlit_list_h)
:
	parsenode(_loc,_ctx),
	at_str(_at_str),
	stringlit_list_h(_stringlit_list_h)
{
}

FTRefOrList::~FTRefOrList()
{
}

ostream& FTRefOrList::put(ostream& s) const
{
	s << INDENT << "FTRefOrList[";
	return s << OUTDENT << "]\n";
}

//-FTRefOrList::



// [361a] FTStringLiteralList
// --------------------------
FTStringLiteralList::FTStringLiteralList(
	location const& _loc,
	context const& _ctx)
:
	parsenode(_loc,_ctx)
{
}

FTStringLiteralList::~FTStringLiteralList()
{
}

ostream& FTStringLiteralList::put(ostream& s) const
{
	s << INDENT << "FTStringLiteralList[" << endl;
	++printdepth;
	std::vector<string>::const_iterator it = strlit_v.begin();
	for (; it!=strlit_v.end(); ++it) { s << (*it); }
	return s << OUTDENT << "]\n";
}

//-FTStringLiteralList::



// [362] FTInclExclStringLiteral
// -----------------------------
FTInclExclStringLiteral::FTInclExclStringLiteral(
	location const& _loc,
	context const& _ctx,
	rchandle<FTRefOrList> _ref_or_list_h,
	intex_op_t _mode)
:
	parsenode(_loc,_ctx),
	ref_or_list_h(_ref_or_list_h),
	mode(_mode)
{
}

FTInclExclStringLiteral::~FTInclExclStringLiteral()
{
}

ostream& FTInclExclStringLiteral::put(ostream& s) const
{
	s << INDENT << "FTInclExclStringLiteral[";
	return s << OUTDENT << "]\n";
}

//-FTInclExclStringLiteral::



// [363] FTLanguageOption
// ----------------------
FTLanguageOption::FTLanguageOption(
	location const& _loc,
	context const& _ctx,
	std::string _lang)
:
	FTMatchOption(_loc,_ctx),
	lang(_lang)
{
}

FTLanguageOption::~FTLanguageOption()
{
}

ostream& FTLanguageOption::put(ostream& s) const
{
	s << INDENT << "FTLanguageOption[";
	return s << OUTDENT << "]\n";
}

//-FTLanguageOption::



// [364] FTWildcardOption
// ----------------------
FTWildcardOption::FTWildcardOption(
	location const& _loc,
	context const& _ctx,
	bool _with_b)
:
	FTMatchOption(_loc,_ctx),
	with_b(_with_b)
{
}

FTWildcardOption::~FTWildcardOption()
{
}

ostream& FTWildcardOption::put(ostream& s) const
{
	s << INDENT << "FTWildcardOption[";
	return s << OUTDENT << "]\n";
}

//-FTWildcardOption::



// [365]	FTContent
// ---------------
FTContent::FTContent(
	location const& _loc,
	context const& _ctx,
	ft_content_mode_t _mode)
:
	FTProximity(_loc,_ctx),
	mode(_mode)
{
}

FTContent::~FTContent()
{
}

ostream& FTContent::put(ostream& s) const
{
	s << INDENT << "FTContent[";
	return s << OUTDENT << "]\n";
}

//-FTContent::



// [366]	FTAnyallOption
// --------------------
FTAnyallOption::FTAnyallOption(
	location const& _loc,
	context const& _ctx,
	ft_anyall_option_t _option)
:
	parsenode(_loc,_ctx),
	option(_option)
{
}

FTAnyallOption::~FTAnyallOption()
{
}

ostream& FTAnyallOption::put(ostream& s) const
{
	s << INDENT << "FTAnyallOption[";
	return s << OUTDENT << "]\n";
}

//-FTAnyallOption::



// [367] FTRange
// -------------
FTRange::FTRange(
	location const& _loc,
	context const& _ctx,
	rchandle<UnionExpr> _src_expr_h,
	rchandle<UnionExpr> _dst_expr_h)
:
	parsenode(_loc,_ctx),
	src_expr_h(_src_expr_h),
	dst_expr_h(_dst_expr_h)
{
}

FTRange::~FTRange()
{
}

ostream& FTRange::put(ostream& s) const
{
	s << INDENT << "FTRange[";
	return s << OUTDENT << "]\n";
}

//-FTRange::



// [368] FTDistance
// ----------------
FTDistance::FTDistance(
	location const& _loc,
	context const& _ctx,
	rchandle<FTRange> _dist_h,
	rchandle<FTUnit> _unit_h)
:
	FTProximity(_loc,_ctx),
	dist_h(_dist_h),
	unit_h(_unit_h)
{
}

FTDistance::~FTDistance()
{
}

ostream& FTDistance::put(ostream& s) const
{
	s << INDENT << "FTDistance[";
	return s << OUTDENT << "]\n";
}

//-FTDistance::



// [369] FTWindow
// --------------
FTWindow::FTWindow(
	location const& _loc,
	context const& _ctx,
	rchandle<UnionExpr> _window_h,
	rchandle<FTUnit> _unit_h)
:
	FTProximity(_loc,_ctx),
	window_h(_window_h),
	unit_h(_unit_h)
{
}

FTWindow::~FTWindow()
{
}

ostream& FTWindow::put(ostream& s) const
{
	s << INDENT << "FTWindow[";
	return s << OUTDENT << "]\n";
}

//-FTWindow::



// [370] FTTimes
// -------------
FTTimes::FTTimes(
	location const& _loc,
	context const& _ctx,
	rchandle<FTRange> _range_h)
:
	parsenode(_loc,_ctx),
	range_h(_range_h)
{
}

FTTimes::~FTTimes()
{
}

ostream& FTTimes::put(ostream& s) const
{
	s << INDENT << "FTTimes[";
	return s << OUTDENT << "]\n";
}

//-FTTimes::



// [371] FTScope
// -------------
FTScope::FTScope(
	location const& _loc,
	context const& _ctx,
	ft_scope_t _scope)
:
	FTProximity(_loc,_ctx),
	scope(_scope)
{
}

FTScope::~FTScope()
{
}

ostream& FTScope::put(ostream& s) const
{
	s << INDENT << "FTScope[";
	return s << OUTDENT << "]\n";
}

//-FTScope::



// [372] FTUnit
// ------------
FTUnit::FTUnit(
	location const& _loc,
	context const& _ctx,
	ft_unit_t _unit)
:
	parsenode(_loc,_ctx),
	unit(_unit)
{
}

FTUnit::~FTUnit()
{
}

ostream& FTUnit::put(ostream& s) const
{
	s << INDENT << "FTUnit[";
	return s << OUTDENT << "]\n";
}

//-FTUnit::



// [373] FTBigUnit
// ---------------
FTBigUnit::FTBigUnit(
	location const& _loc,
	context const& _ctx,
	enum ft_big_unit_t _unit)
:
	parsenode(_loc,_ctx),
	unit(_unit)
{
}

FTBigUnit::~FTBigUnit()
{
}

ostream& FTBigUnit::put(ostream& s) const
{
	s << INDENT << "FTBigUnit[";
	return s << OUTDENT << "]\n";
}

//-FTBigUnit::



// [374] FTIgnoreOption
// --------------------
FTIgnoreOption::FTIgnoreOption(
	location const& _loc,
	context const& _ctx,
	rchandle<UnionExpr> _union_h)
:
	parsenode(_loc,_ctx),
	union_h(_union_h)
{
}

FTIgnoreOption::~FTIgnoreOption()
{
}

ostream& FTIgnoreOption::put(ostream& s) const
{
	s << INDENT << "FTBigUnit[";
	return s << OUTDENT << "]\n";
}

//-FTIgnoreOption::



}	/* namespace xqp */

