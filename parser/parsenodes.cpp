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

#include "../exprtree/parsenode_visitor.h"
#include "../util/rchandle.h"
#include "../util/tracer.h"
#include "../values/values.h"
#include "indent.h"

using namespace std;
using namespace yy;

namespace xqp {

int printdepth = 0;
ostringstream	__oss;

#define INDENT		indent[++printdepth % 30]
#define OUTDENT		indent[printdepth-- % 30]
#define UNDENT		printdepth--

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
	location const& _loc)
:
	parsenode(_loc)
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

void Module::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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

ostream& VersionDecl::put(ostream& os) const
{
	return os;
}

//-VersionDecl::

void VersionDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}





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
	s << INDENT << "MainModule[" << endl;
	if (prolog_h!=NULL) prolog_h->put(s);
	query_body_h->put(s);
	return s << OUTDENT << "]\n";
}

//-MainModule::

void MainModule::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	prolog_h->accept(v);
	query_body_h->accept(v);
	v.end_visit(*this); 
}





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
	s << INDENT << "LibraryModule[" << endl;
	if (decl_h!=NULL) decl_h->put(s);
	prolog_h->put(s);
	return s << OUTDENT << "]\n";
}

//-LibraryModule::

void LibraryModule::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	decl_h->accept(v);
	prolog_h->accept(v);
	v.end_visit(*this); 
}





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
	s << INDENT << "ModuleDecl[";
	s << prefix << " = " << target_namespace;
	return s << OUTDENT << "]\n";
}

//-ModuleDecl::

void ModuleDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}





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
	s << INDENT << "Prolog[" << endl;
	if (sind_list_h!=NULL) sind_list_h->put(s);
	if (vfo_list_h!=NULL) vfo_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-Prolog::

void Prolog::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	sind_list_h->accept(v);
	vfo_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "SIND_DeclList[" << endl;
	vector<rchandle<parsenode> >::const_iterator it = sind_hv.begin();
	for (; it!=sind_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-SIND_DeclList::

void SIND_DeclList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<parsenode> >::const_reverse_iterator it = sind_hv.rbegin();
	for (; it!=sind_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



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
	s << INDENT << "VFO_DeclList[" << endl;
	vector<rchandle<parsenode> >::const_iterator it = vfo_hv.begin();
	for (; it!=vfo_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VFO_DeclList::

void VFO_DeclList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<parsenode> >::const_reverse_iterator it = vfo_hv.rbegin();
	for (; it!=vfo_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}


// pass-through rules generate no classes

// [6c] SIND_Decl
// --------------
// [6d] VFO_Decl
// -------------
// [7] Setter
// ----------
// [8] Import
// ----------
// [9] Separator (Lexical rule)
// -------------



// [10] NamespaceDecl
// ------------------
NamespaceDecl::NamespaceDecl(
	location const& _loc,
	std::string const& _prefix,
	std::string const& _uri)
:
	parsenode(_loc),
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

void NamespaceDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
	location const& _loc,
	static_context::boundary_space_mode_t _mode)
:
	parsenode(_loc),
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
	case static_context::preserve_space: s << "preserve"; break;
	case static_context::strip_space:	s << "strip"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-BoundarySpaceDecl::

void BoundarySpaceDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
	location const& _loc,
	enum default_namespace_mode_t _mode,
	std::string const& _default_namespace)
:
	parsenode(_loc),
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

void DefaultNamespaceDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "OptionDecl[";
	if (qname_h!=NULL) qname_h->put(s);
	s << " " << val << endl;
	return s << OUTDENT << "]\n";
}

//-OptionDecl::

void OptionDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//qname_h->accept(v);
	v.end_visit(*this); 
}



// [13a] FTOptionDecl
// ------------------
FTOptionDecl::FTOptionDecl(
  yy::location const& _loc,
  rchandle<parsenode> _match_option_h)
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
	s << INDENT << "FTOptionDecl[";
	if (match_option_h!=NULL) match_option_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTOptionDecl::

void FTOptionDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	match_option_h->accept(v);
	v.end_visit(*this); 
}



// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl(
	location const& _loc,
	dynamic_context::ordering_mode_t _mode)
:
	parsenode(_loc),
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
	case dynamic_context::ordered: s << "ordered"; break;
	case dynamic_context::unordered: s << "unordered"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderingModeDecl::

void OrderingModeDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
	location const& _loc,
	static_context::order_empty_mode_t _mode)
:
	parsenode(_loc),
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
	case static_context::empty_greatest: s << "greatest"; break;
	case static_context::empty_least: s << "least"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-EmptyOrderDecl::

void EmptyOrderDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
	location const& _loc,
	static_context::preserve_mode_t _preserve_mode,
	static_context::inherit_mode_t  _inherit_mode)
:
	parsenode(_loc),
	preserve_mode(_preserve_mode),
	inherit_mode(_inherit_mode)
{
}

CopyNamespacesDecl::~CopyNamespacesDecl()
{
}

ostream& CopyNamespacesDecl::put(ostream& s) const
{
	s << INDENT << "CopyNamespacesDecl[";
	switch (preserve_mode) {
	case static_context::preserve_ns: s << "preserve"; break;
	case static_context::no_preserve_ns: s << "no preserve"; break;
	}
	s << ", ";
	switch (inherit_mode) {
	case static_context::inherit_ns: s << "inherit"; break;
	case static_context::no_inherit_ns: s << "no inherit"; break;
	}
	return s << OUTDENT << "]\n";
}

//-CopyNamespacesDecl::

void CopyNamespacesDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [17] PreserveMode
// -----------------

// [18] InheritMode
// ----------------



// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl(
	location const& _loc,
	std::string const&  _collation)
:
	parsenode(_loc),
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

void DefaultCollationDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
	location const& _loc,
	std::string const& _base_uri)
:
	parsenode(_loc),
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

void BaseURIDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
	location const& _loc,
	rchandle<SchemaPrefix> _prefix_h,
	std::string const& _uri,
	rchandle<URILiteralList> _at_list_h)
:
	parsenode(_loc),
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

void SchemaImport::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	prefix_h->accept(v);
	at_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "URILiteralList[" << endl;
	++printdepth;
	vector<string>::const_iterator it = uri_v.begin();
	for (; it!=uri_v.end(); ++it) { s << *it << endl; }
	return s << OUTDENT << "]\n";
}

//-URILiteralList::

void URILiteralList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<string>::const_reverse_iterator it = uri_v.rbegin();
	for (; it!=uri_v.rend(); ++it) {
		// ..do something useful
	}
	v.end_visit(*this); 
}



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
	s << INDENT << "SchemaPrefix[";
	s << "prefix=" << prefix << endl;
	s << "default_b=" << default_b << endl;
	return s << OUTDENT << "]\n";
}

//-SchemaPrefix::

void SchemaPrefix::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
	location const& _loc,
	std::string const& uri,
	rchandle<URILiteralList> _uri_list_h)
:
	parsenode(_loc),
	uri_list_h(_uri_list_h)
{
}

ModuleImport::ModuleImport(
	location const& _loc,
	std::string const& _prefix,
	std::string const& _uri,
	rchandle<URILiteralList> _uri_list_h)
:
	parsenode(_loc),
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

void ModuleImport::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	uri_list_h->accept(v);
	v.end_visit(*this); 
}



// [24] VarDecl
// ------------
VarDecl::VarDecl(
	location const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<exprnode> _initexpr_h)
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
	s << INDENT << "VarDecl[";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (initexpr_h!=NULL) initexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarDecl::

void VarDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	typedecl_h->accept(v);
	initexpr_h->accept(v);
	v.end_visit(*this); 
}



// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl(
	location const& _loc,
	static_context::construction_mode_t _mode)
:
	parsenode(_loc),
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
	case static_context::cons_preserve: os << "preserve"; break;
	case static_context::cons_strip: os << "strip"; break;
	default: os << "???";
	}
	return os << OUTDENT << "]\n";
}

//-ConstructionDecl::

void ConstructionDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	if (name_h!=NULL) name_h->put(s);
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

void FunctionDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//name_h->accept(v);
	paramlist_h->accept(v);
	return_type_h->accept(v);
	body_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "ParamList[" << endl;
	++printdepth;
	vector<rchandle<Param> >::const_iterator it = param_hv.begin();
	for (; it!=param_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ParamList::

void ParamList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<Param> >::const_reverse_iterator it = param_hv.rbegin();
	for (; it!=param_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



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
	s << INDENT << "Param[";
	s << "name=" << name << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	return s << OUTDENT << "]\n";
}

//-Param::

void Param::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	typedecl_h->accept(v);
	v.end_visit(*this); 
}



// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr(
	location const& _loc,
	rchandle<exprnode> _expr_h)
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
	s << INDENT << "EnclosedExpr[\n";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-EnclosedExpr::

void EnclosedExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [30] QueryBody
// --------------
QueryBody::QueryBody(
	location const& _loc,
	rchandle<exprnode> _expr_h)
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
	s << INDENT << "QueryBody[\n";
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QueryBody::

void QueryBody::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "Expr[\n";
	vector<rchandle<exprnode> >::const_iterator it = expr_hv.begin();
	for (; it!=expr_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-Expr::

void Expr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<exprnode> >::const_reverse_iterator it = expr_hv.rbegin();
	for (; it!=expr_hv.rend(); ++it) {
		exprnode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}


// [32] ExprSingle
// ---------------


// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr(
	location const& _loc,
	rchandle<ForLetClauseList> _forlet_list_h,
	rchandle<WhereClause> _where_h,
	rchandle<OrderByClause> _orderby_h,
	rchandle<exprnode> _return_val_h)
:
	exprnode(_loc),
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

void FLWORExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	forlet_list_h->accept(v);
	where_h->accept(v);
	orderby_h->accept(v);
	return_val_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "ForLetClauseList[\n";
	vector<rchandle<parsenode> >::const_iterator it = forlet_hv.begin();
	for (; it!=forlet_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ForLetClauseList::

void ForLetClauseList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<parsenode> >::const_reverse_iterator it = forlet_hv.rbegin();
	for (; it!=forlet_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [33b] ForLetClause
// ------------------



// [34] ForClause
// --------------
ForClause::ForClause(
	location const& _loc,
	rchandle<VarInDeclList> _vardecl_list_h)
:
	parsenode(_loc),
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

void ForClause::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vardecl_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "VarInDeclList[\n";
	vector<rchandle<VarInDecl> >::const_iterator it = vardecl_hv.begin();
	for (; it!=vardecl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarInDeclList::

void VarInDeclList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<VarInDecl> >::const_reverse_iterator it = vardecl_hv.rbegin();
	for (; it!=vardecl_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
	location const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<PositionalVar> _posvar_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<exprnode> _valexpr_h)
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
	s << INDENT << "VarInDecl[";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (posvar_h!=NULL) posvar_h->put(s);
	if (ftscorevar_h!=NULL) ftscorevar_h->put(s);
	if (valexpr_h!=NULL) valexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarInDecl::

void VarInDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	typedecl_h->accept(v);
	posvar_h->accept(v);
	ftscorevar_h->accept(v);
	valexpr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "PositionalVar[";
	s << "varname=" << varname << endl;
	return s << OUTDENT << "]\n";
}

//-PositionalVar::

void PositionalVar::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [36] LetClause
// --------------
LetClause::LetClause(
	location const& _loc,
	rchandle<VarGetsDeclList> _vardecl_list_h)
:
	parsenode(_loc),
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

void LetClause::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vardecl_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "VarGetsDeclList[\n";
	vector<rchandle<VarGetsDecl> >::const_iterator it = vardecl_hv.begin();
	for (; it!=vardecl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarGetsDeclList::

void VarGetsDeclList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<VarGetsDecl> >::const_reverse_iterator it = vardecl_hv.rbegin();
	for (; it!=vardecl_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl(
	location const& _loc,
	std::string _varname,
	rchandle<TypeDeclaration> _typedecl_h,
	rchandle<FTScoreVar> _ftscorevar_h,
	rchandle<exprnode> _valexpr_h)
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
	s << INDENT << "VarGetsDecl[";
	s << "varname=" << varname << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (ftscorevar_h!=NULL) ftscorevar_h->put(s);
	if (valexpr_h!=NULL) valexpr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarGetsDecl::

void VarGetsDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	typedecl_h->accept(v);
	ftscorevar_h->accept(v);
	valexpr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTScoreVar[";
	s << "varname=" << varname << endl;
	return s << OUTDENT << "]\n";
}

//-FTScoreVar::

void FTScoreVar::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [37] WhereClause
// ----------------
WhereClause::WhereClause(
	location const& _loc,
	rchandle<exprnode> _predicate_h)
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
	s << INDENT << "WhereClause[\n";
	if (predicate_h!=NULL) predicate_h->put(s);
	return s << OUTDENT << "]\n";
}

//-WhereClause::

void WhereClause::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	predicate_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderByClause[\n";
	if (spec_list_h!=NULL) spec_list_h->put(s);
	s << "stable_b=" << stable_b << endl;
	return s << OUTDENT << "]\n";
}

//-OrderByClause::

void OrderByClause::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	spec_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderSpecList[\n";
	vector<rchandle<OrderSpec> >::const_iterator it = spec_hv.begin();
	for (; it!=spec_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-OrderSpecList::

void OrderSpecList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<OrderSpec> >::const_reverse_iterator it = spec_hv.rbegin();
	for (; it!=spec_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
	location const& _loc,
	rchandle<exprnode> _spec_h,
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
	s << INDENT << "OrderSpec[\n";
	if (spec_h!=NULL) spec_h->put(s);
	if (modifier_h!=NULL) modifier_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrderSpec::

void OrderSpec::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	spec_h->accept(v);
	modifier_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderModifier[";
	if (dir_spec_h!=NULL) dir_spec_h->put(s);
	if (empty_spec_h!=NULL) empty_spec_h->put(s);
	if (collation_spec_h!=NULL) collation_spec_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrderModifier::

void OrderModifier::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	dir_spec_h->accept(v);
	empty_spec_h->accept(v);
	collation_spec_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderDirSpec[";
	switch (dir_spec) {
	case dir_ascending: s << "ascending"; break;
	case dir_descending: s << "descending"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderDirSpec::

void OrderDirSpec::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderEmptySpec[";
	switch (empty_order_spec) {
	case static_context::empty_greatest: s << "empty_greatest"; break;
	case static_context::empty_least: s << "empty_least"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-OrderEmptySpec::

void OrderEmptySpec::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "OrderCollationSpec[";
	s << "uri=" << uri << endl;
	return s << OUTDENT << "]\n";
}

//-OrderCollationSpec::

void OrderCollationSpec::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [42] QuantifiedExpr 	   
// -------------------
QuantifiedExpr::QuantifiedExpr(
	location const& _loc,
	quantification_mode_t _qmode,
	rchandle<QVarInDeclList> _decl_list_h,
	rchandle<exprnode> _expr_h)
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

void QuantifiedExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	decl_list_h->accept(v);
	expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "QVarInDeclList[\n";
	vector<rchandle<QVarInDecl> >::const_iterator it = qvar_decl_hv.begin();
	for (; it!=qvar_decl_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-QVarInDeclList::

void QVarInDeclList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<QVarInDecl> >::const_reverse_iterator it = qvar_decl_hv.rbegin();
	for (; it!=qvar_decl_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
	location const& _loc,
	std::string _name,
	rchandle<exprnode> _val_h)
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
	rchandle<exprnode> _val_h)
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
	s << INDENT << "QVarInDecl[";
	s << "name=" << name << endl;
	if (typedecl_h!=NULL) typedecl_h->put(s);
	if (val_h!=NULL) val_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QVarInDecl::

void QVarInDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	val_h->accept(v);
	v.end_visit(*this); 
}



// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
	location const& _loc,
	rchandle<exprnode> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	rchandle<exprnode> _default_clause_h)
:
	exprnode(_loc),
	switch_expr_h(_switch_expr_h),
	clause_list_h(_clause_list_h),
	default_clause_h(_default_clause_h)
{
}


TypeswitchExpr::TypeswitchExpr(
	location const& _loc,
	rchandle<exprnode> _switch_expr_h,
	rchandle<CaseClauseList> _clause_list_h,
	std::string _default_varname,
	rchandle<exprnode> _default_clause_h)
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

ostream& TypeswitchExpr::put(ostream& os) const
{
	os << INDENT << "TypeswitchExpr[\n";
	if (switch_expr_h!=NULL) switch_expr_h->put(os);
	if (clause_list_h!=NULL) clause_list_h->put(os);
	if (default_clause_h!=NULL) {
  	os << INDENT << "DEFAULT\n";
  	if (default_varname.length()>0) {
  	  os << INDENT << "VARNAME=" 
          << default_varname << OUTDENT << endl;
    }
  	default_clause_h->put(os);
  	UNDENT;
	}
	return os << OUTDENT << "]\n";
}

//-TypeswitchExpr::

void TypeswitchExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	switch_expr_h->accept(v);
	clause_list_h->accept(v);
	default_clause_h->accept(v);

	Assert<null_pointer>(switch_expr_h!=NULL,LOCATION);
	switch_expr_h->accept(v);

	Assert<null_pointer>(default_clause_h!=NULL,LOCATION);
	default_clause_h->accept(v);

	Assert<null_pointer>(clause_list_h!=NULL,LOCATION);
	vector<rchandle<CaseClause> >::const_reverse_iterator it = clause_list_h->rbegin();
	for (; it!=clause_list_h->rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



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

ostream& CaseClauseList::put(ostream& os) const
{
	os << INDENT << "CaseClauseList[("<<size()<<")\n";
	vector<rchandle<CaseClause> >::const_iterator it = clause_hv.begin();
	for (; it!=clause_hv.end(); ++it) { 
  	if (*it!=NULL) {
    	(*it)->put(os);
  	}
  	else { 
    	os << INDENT << "CASE CLAUSE == NULL!\n"; 
    	UNDENT; 
    }
  }
	return os << OUTDENT << "]\n";
}

//-CaseClauseList::

void CaseClauseList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<CaseClause> >::const_reverse_iterator it = clause_hv.rbegin();
	for (; it!=clause_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [44] CaseClause
// ---------------
CaseClause::CaseClause(
	location const& _loc,
	std::string _varname,
	rchandle<SequenceType> _type_h,
	rchandle<exprnode> _val_h)
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
	rchandle<exprnode> _val_h)
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

ostream& CaseClause::put(ostream& os) const
{
	os << INDENT << "CaseClause[\n";
	if (varname.length()>0) os << "VARNAME=" << varname;
	if (type_h!=NULL) { 
  	os << INDENT << "AS\n"; 
  	type_h->put(os); UNDENT;
  }
	if (val_h!=NULL) {
  	os << INDENT << "RETURN\n"; 
  	val_h->put(os); UNDENT;
  }
	return os << OUTDENT << "]\n";
}

//-CaseClause::

void CaseClause::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	type_h->accept(v);
	val_h->accept(v);
	v.end_visit(*this); 
}



// [45] IfExpr
// -----------
IfExpr::IfExpr(
	location const& _loc,
	rchandle<exprnode> _cond_expr_h,
	rchandle<exprnode> _then_expr_h,
	rchandle<exprnode> _else_expr_h)
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
	s << INDENT << "IfExpr[\n";
	if (cond_expr_h!=NULL) cond_expr_h->put(s);
	if (then_expr_h!=NULL) then_expr_h->put(s);
	if (else_expr_h!=NULL) else_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-IfExpr::

void IfExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	cond_expr_h->accept(v);
	then_expr_h->accept(v);
	else_expr_h->accept(v);
	v.end_visit(*this); 
}



// [46] OrExpr
// -----------
OrExpr::OrExpr(
	location const& _loc,
	rchandle<exprnode> _or_expr_h,
	rchandle<exprnode> _and_expr_h)
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
	s << INDENT << "OrExpr[\n";
	if (or_expr_h!=NULL) or_expr_h->put(s);
	if (and_expr_h!=NULL) and_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-OrExpr::

void OrExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	or_expr_h->accept(v);
	and_expr_h->accept(v);
	v.end_visit(*this); 
}



// [47] AndExpr
// ------------
AndExpr::AndExpr(
	location const& _loc,
	rchandle<exprnode> _and_expr_h,
	rchandle<exprnode> _comp_expr_h)
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
	s << INDENT << "AndExpr[\n";
	if (and_expr_h!=NULL) and_expr_h->put(s);
	if (comp_expr_h!=NULL) comp_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AndExpr::

void AndExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	and_expr_h->accept(v);
	comp_expr_h->accept(v);
	v.end_visit(*this); 
}



// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr(
	location const& _loc,
	rchandle<ValueComp> _valcomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
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
	rchandle<GeneralComp> _gencomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
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
	rchandle<NodeComp> _nodecomp_h,
	rchandle<exprnode> _left_h,
	rchandle<exprnode> _right_h)
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
	s << INDENT << "ComparisonExpr[\n";
	if (left_h!=NULL) left_h->put(s);
	if (valcomp_h!=NULL) valcomp_h->put(s);
	if (gencomp_h!=NULL) gencomp_h->put(s);
	if (nodecomp_h!=NULL) nodecomp_h->put(s);
	if (right_h!=NULL) right_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ComparisonExpr::

void ComparisonExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	left_h->accept(v);
	right_h->accept(v);
	v.end_visit(*this); 
}



// [48a] FTContainsExpr
// --------------------
FTContainsExpr::FTContainsExpr(
	location const& _loc,
	rchandle<exprnode> _range_expr_h,
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
	s << INDENT << "FTContainsExpr[\n";
	if (range_expr_h!=NULL) range_expr_h->put(s);
	if (ftselect_h!=NULL) ftselect_h->put(s);
	if (ftignore_h!=NULL) ftignore_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTContainsExpr::

void FTContainsExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	range_expr_h->accept(v);
	ftselect_h->accept(v);
	ftignore_h->accept(v);
	v.end_visit(*this); 
}



// [49] RangeExpr
// --------------
RangeExpr::RangeExpr(
	location const& _loc,
	rchandle<exprnode> _from_expr_h,
	rchandle<exprnode> _to_expr_h)
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
	s << INDENT << "RangeExpr[\n";
	if (from_expr_h!=NULL) from_expr_h->put(s);
	s << " TO ";
	if (to_expr_h!=NULL) to_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-RangeExpr::

void RangeExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	from_expr_h->accept(v);
	to_expr_h->accept(v);
	v.end_visit(*this); 
}



// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr(
	location const& _loc,
	enum add_op_t _add_op,
	rchandle<exprnode> _add_expr_h,
	rchandle<exprnode> _mult_expr_h)
:
	exprnode(_loc),
	add_op(_add_op),
	add_expr_h(_add_expr_h),
	mult_expr_h(_mult_expr_h)
{
}

AdditiveExpr::~AdditiveExpr()
{
}

ostream& AdditiveExpr::put(ostream& os) const
{
	os << INDENT << "AdditiveExpr[\n";
	if (add_expr_h!=NULL) {
		add_expr_h->put(os);
		switch(add_op) {
		case op_plus: os << INDENT << " plus\n"; break;
		case op_minus: os << INDENT << " minus\n"; break;
		default: os << INDENT << "???";
		}
	}
	if (mult_expr_h!=NULL) mult_expr_h->put(os);
	return os << OUTDENT << "]\n";
}

//-AdditiveExpr::

void AdditiveExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	add_expr_h->accept(v);
	mult_expr_h->accept(v);
	v.end_visit(*this); 
}



// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr(
	location const& _loc,
	enum mult_op_t _mult_op,
	rchandle<exprnode> _mult_expr_h,
	rchandle<exprnode> _union_expr_h)
:
	exprnode(_loc),
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
	case op_mul: s << " mul\n"; break;
	case op_div: s << " div\n"; break;
	case op_idiv: s << " idiv\n"; break;
	case op_mod: s << " mod\n"; break;
	default: s << "???";
	}
	if (union_expr_h!=NULL) union_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-MultiplicativeExpr::

void MultiplicativeExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	mult_expr_h->accept(v);
	union_expr_h->accept(v);
	v.end_visit(*this); 
}



// [52] UnionExpr
// --------------
UnionExpr::UnionExpr(
	location const& _loc,
	rchandle<exprnode> _union_expr_h,
	rchandle<exprnode> _intex_expr_h)
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
	s << INDENT << "UnionExpr[\n";
	if (union_expr_h!=NULL) union_expr_h->put(s);
	if (intex_expr_h!=NULL) intex_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-UnionExpr::

void UnionExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	union_expr_h->accept(v);
	intex_expr_h->accept(v);
	v.end_visit(*this); 
}



// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr(
	location const& _loc,
	enum intex_op_t _intex_op,
	rchandle<exprnode> _intex_expr_h,
	rchandle<exprnode> _instof_expr_h)
:
	exprnode(_loc),
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

void IntersectExceptExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	intex_expr_h->accept(v);
	instof_expr_h->accept(v);
	v.end_visit(*this); 
}



// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr(
	location const& _loc,
	rchandle<exprnode> _treat_expr_h,
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
	s << INDENT << "InstanceofExpr[\n";
	if (treat_expr_h!=NULL) treat_expr_h->put(s);
	if (seqtype_h!=NULL) seqtype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-InstanceofExpr::

void InstanceofExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	treat_expr_h->accept(v);
	seqtype_h->accept(v);
	v.end_visit(*this); 
}



// [55] TreatExpr
// --------------
TreatExpr::TreatExpr(
	location const& _loc,
	rchandle<exprnode> _castable_expr_h,
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
	s << INDENT << "TreatExpr[\n";
	if (castable_expr_h!=NULL) castable_expr_h->put(s);
	if (seqtype_h!=NULL) seqtype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TreatExpr::

void TreatExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	castable_expr_h->accept(v);
	seqtype_h->accept(v);
	v.end_visit(*this); 
}



// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr(
	location const& _loc,
	rchandle<exprnode> _cast_expr_h,
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
	s << INDENT << "CastableExpr[\n";
	if (cast_expr_h!=NULL) cast_expr_h->put(s);
	if (singletype_h!=NULL) singletype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CastableExpr::

void CastableExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	cast_expr_h->accept(v);
	singletype_h->accept(v);
	v.end_visit(*this); 
}



// [57] CastExpr 	   
// -------------
CastExpr::CastExpr(
	location const& _loc,
	rchandle<exprnode> _unary_expr_h,
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
	s << INDENT << "CastExpr[\n";
	if (unary_expr_h!=NULL) unary_expr_h->put(s);
	if (singletype_h!=NULL) singletype_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CastExpr::

void CastExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	unary_expr_h->accept(v);
	singletype_h->accept(v);
	v.end_visit(*this); 
}



// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr(
	location const& _loc,
	rchandle<SignList> _signlist_h,
	rchandle<exprnode> _value_expr_h)
:
	exprnode(_loc),
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

void UnaryExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	signlist_h->accept(v);
	value_expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "Sign[";
	s << (sign ? "+" : "-");
	return s << OUTDENT << "]\n";
}

//-SignList::

void SignList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [59] ValueExpr
// --------------


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

void GeneralComp::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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

void ValueComp::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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

void NodeComp::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
	location const& _loc,
	string const& _valmode,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc),
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

void ValidateExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [65] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr(
	location const& _loc,
	rchandle<PragmaList> _pragma_list_h,
	rchandle<exprnode> _expr_h)
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
	s << INDENT << "ExtensionExpr[\n";
	if (pragma_list_h!=NULL) pragma_list_h->put(s);
	if (expr_h!=NULL) expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ExtensionExpr::

void ExtensionExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	pragma_list_h->accept(v);
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [65a] PragmaList
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
	s << INDENT << "PragmaList[\n";
	vector<rchandle<Pragma> >::const_iterator it = pragma_hv.begin();
	for (; it!=pragma_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-PragmaList::

void PragmaList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<Pragma> >::const_reverse_iterator it = pragma_hv.rbegin();
	for (; it!=pragma_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [66] Pragma
// -----------
Pragma::Pragma(
	location const& _loc,
	rchandle<QName> _name_h,
	std::string _pragma_lit)
:
	parsenode(_loc),
	name_h(_name_h),
	pragma_lit(_pragma_lit)
{
}

Pragma::~Pragma()
{
}

ostream& Pragma::put(ostream& s) const
{
	s << INDENT << "Pragma[";
	if (name_h!=NULL) name_h->put(s);
	s << "pragma_lit=" << pragma_lit << endl;
	return s << OUTDENT << "]\n";
}

//-Pragma::

void Pragma::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//name->accept(v);
	v.end_visit(*this); 
}



// [67] PragmaContents
// -------------------
/* folded into [66] */



// [68] PathExpr
// -------------
PathExpr::PathExpr(
	location const& _loc,
	enum pathtype_t _type,
	rchandle<exprnode> _relpath_expr_h)
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

void PathExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	relpath_expr_h->accept(v);
	v.end_visit(*this); 
}



// [69] RelativePathExpr
// ---------------------
RelativePathExpr::RelativePathExpr(
	location const& _loc,
	enum steptype_t _step_type,
	rchandle<exprnode> _step_expr_h,
	rchandle<exprnode> _relpath_expr_h)
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

void RelativePathExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	step_expr_h->accept(v);
	relpath_expr_h->accept(v);
	v.end_visit(*this); 
}



// [70] StepExpr
// -------------



// [71] AxisStep
// -------------
AxisStep::AxisStep(
	location const& _loc,
	rchandle<ForwardStep> _forward_step_h,
	rchandle<PredicateList> _predicate_list_h)
:
	exprnode(_loc),
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
	exprnode(_loc),
	forward_step_h(NULL),
	reverse_step_h(_reverse_step_h),
	predicate_list_h(_predicate_list_h)
{
}

AxisStep::~AxisStep()
{
}

ostream& AxisStep::put(ostream& os) const
{
	os << INDENT << "AxisStep[\n";
	if (forward_step_h!=NULL) forward_step_h->put(os);
	if (reverse_step_h!=NULL) reverse_step_h->put(os);
	if (predicate_list_h!=NULL) predicate_list_h->put(os);
	return os << OUTDENT << "]\n";
}

//-AxisStep::

void AxisStep::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	if (forward_step_h!=NULL) forward_step_h->accept(v);
	if (reverse_step_h!=NULL) reverse_step_h->accept(v);
	if (predicate_list_h!=NULL) predicate_list_h->accept(v);
	v.end_visit(*this); 
}



// [72] ForwardStep
// ----------------
ForwardStep::ForwardStep(
	location const& _loc,
	rchandle<ForwardAxis> _forward_axis_h,
	rchandle<parsenode> _node_test_h)
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

ostream& ForwardStep::put(ostream& os) const
{
	os << INDENT << "ForwardStep[\n";
	if (forward_axis_h!=NULL) forward_axis_h->put(os);
	if (node_test_h!=NULL) node_test_h->put(os);
	if (abbrev_step_h!=NULL) abbrev_step_h->put(os);
	return os << OUTDENT << "]\n";
}

//-ForwardStep::

void ForwardStep::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	if (forward_axis_h!=NULL) forward_axis_h->accept(v);
	if (node_test_h!=NULL) node_test_h->accept(v);
	if (abbrev_step_h!=NULL) abbrev_step_h->accept(v);
	v.end_visit(*this); 
}



// [73] ForwardAxis
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

ostream& ForwardAxis::put(ostream& os) const
{
	os << INDENT << "ForwardAxis[";
	switch(axis) {
	case axis_child:							os << "CHILD"; break;
	case axis_descendant:					os << "DESCENDANT"; break;
	case axis_attribute:					os << "ATTRIBUTE"; break;
	case axis_self:								os << "SELF"; break;
	case axis_descendant_or_self:	os << "DESCENDANT_OR_SELF"; break;
	case axis_following_sibling:	os << "FOLLOWING_SIBLING"; break;
	case axis_following:					os << "FOLLOWING"; break;
	default: os << "???";
	}
	return os << OUTDENT << "]\n";
}

//-ForwardAxis::

void ForwardAxis::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [74] AbbrevForwardStep
// ----------------------
AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	rchandle<parsenode> _node_test_h,
	bool _attr_b)
:
	parsenode(_loc),
	node_test_h(_node_test_h),
	attr_b(_attr_b)
{
}

AbbrevForwardStep::AbbrevForwardStep(
	location const& _loc,
	rchandle<parsenode> _node_test_h)
:
	parsenode(_loc),
	node_test_h(_node_test_h),
	attr_b(false)
{
}

AbbrevForwardStep::~AbbrevForwardStep()
{
}

ostream& AbbrevForwardStep::put(ostream& os) const
{
	os << INDENT << "AbbrevForwardStep[";
	os << (attr_b ? "@\n" : "\n");
	if (node_test_h!=NULL) node_test_h->put(os);
	return os << OUTDENT << "]\n";
}

//-AbbrevForwardStep::

void AbbrevForwardStep::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	if (node_test_h!=NULL) node_test_h->accept(v);
	v.end_visit(*this); 
}



// [75] ReverseStep
// ----------------
ReverseStep::ReverseStep(
	location const& _loc,
	rchandle<ReverseAxis> _axis_h,
	rchandle<parsenode> _node_test_h)
:
	parsenode(_loc),
	axis_h(_axis_h),
	node_test_h(_node_test_h)
{
}

ReverseStep::ReverseStep(
	location const& _loc,
	rchandle<ReverseAxis> _axis_h)
:
	parsenode(_loc),
	axis_h(_axis_h),
	node_test_h(NULL)
{
}

ReverseStep::~ReverseStep()
{
}

ostream& ReverseStep::put(ostream& os) const
{
	os << INDENT << "ReverseStep[\n";
	if (axis_h!=NULL) axis_h->put(os);
	if (node_test_h!=NULL) node_test_h->put(os);
	return os << OUTDENT << "]\n";
}

//-ReverseStep::

void ReverseStep::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	if (axis_h!=NULL) axis_h->accept(v);
	if (node_test_h!=NULL) node_test_h->accept(v);
	v.end_visit(*this); 
}



// [76] ReverseAxis
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
	s << INDENT << "ReverseAxis[";
	switch(axis) {
	case axis_parent:							s << "PARENT"; break;
	case axis_ancestor:						s << "ANCESTOR"; break;
	case axis_preceding_sibling:	s << "PRECEDING_SIBLING"; break;
	case axis_preceding:					s << "PRECEDING"; break;
	case axis_ancestor_or_self:		s << "ANCESTOR_OR_SELF"; break;
	default: s << "???";
	}
	return s << OUTDENT << "]\n";
}

//-ReverseAxis::

void ReverseAxis::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [77] AbbrevReverseStep
// ----------------------
/* folded into [74] */

// [78] NodeTest
// -------------



// [79] NameTest
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

ostream& NameTest::put(ostream& os) const
{
	os << INDENT << "NameTest[";
	if (qname_h!=NULL) qname_h->put(os);
	if (wild_h!=NULL) wild_h->put(os);
	os << "]\n"; UNDENT;
	return os;
}

//-NameTest::

void NameTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//if (qname_h!=NULL) qname_h->accept(v);
	if (wild_h!=NULL) wild_h->accept(v);
	v.end_visit(*this); 
}



// [80] Wildcard
// -------------
Wildcard::Wildcard(
	location const& _loc,
	rchandle<QName> _qname_h,
	enum wildcard_t _type)
:
	parsenode(_loc),
	type(_type),
	qname_h(_qname_h)
{
}
	
Wildcard::~Wildcard()
{
}

ostream& Wildcard::put(ostream& os) const
{
	os << "Wildcard[ ";
	switch(type) {
	case wild_all:		os << "* ]"; break;
	case wild_prefix:	os << "*:" << qname_h->get_localname() << " ]"; break;
	case wild_elem:		os << qname_h->get_prefix() << ":* ]"; break;
	default: os << "???";
	}
	UNDENT; return os;
}

//-Wildcard::

void Wildcard::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [81] FilterExpr
// ---------------
FilterExpr::FilterExpr(
	location const& _loc,
	rchandle<exprnode> _primary_h,
	rchandle<PredicateList> _pred_list_h)
:
	exprnode(_loc),
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

void FilterExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	primary_h->accept(v);
	pred_list_h->accept(v);
	v.end_visit(*this); 
}



// [82] PredicateList
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
	s << INDENT << "PredicateList[\n";
	vector<rchandle<exprnode> >::const_iterator it = pred_hv.begin();
	for (; it!=pred_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-PredicateList::

void PredicateList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<exprnode> >::const_reverse_iterator it = pred_hv.rbegin();
	for (; it!=pred_hv.rend(); ++it) {
		exprnode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [83] Predicate
// --------------

// [84] PrimaryExpr
// ----------------

// [85] Literal
// ------------



// [86] NumericLiteral
// -------------------
NumericLiteral::NumericLiteral(
	location const& _loc,
	int _ival)
:
	exprnode(_loc),
	type(num_integer),
	ival(_ival)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
	double _dval)
:
	exprnode(_loc),
	type(num_double),
	dval(_dval)
{
}

NumericLiteral::NumericLiteral(
	location const& _loc,
	decimal _decval)
:
	exprnode(_loc),
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

void NumericLiteral::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [87] VarRef
// -----------
VarRef::VarRef(
	location const& _loc,
	std::string _varname)
:
	exprnode(_loc),
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

void VarRef::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}


// [88] VarName
// ------------


// [89] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr(
	location const& _loc,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc),
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

void ParenthesizedExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [90] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
	location const& _loc)
:
	exprnode(_loc)
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

void ContextItemExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [91] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
	location const& _loc,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc),
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

void OrderedExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [92] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr(
	location const& _loc,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc),
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

void UnorderedExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [93] FunctionCall
// -----------------

FunctionCall::FunctionCall(
	location const& _loc,
	rchandle<QName> _fname_h,
	rchandle<ArgList> _arg_list_h)
:
	exprnode(_loc),
	fname_h(_fname_h),
	arg_list_h(_arg_list_h)
{
}

FunctionCall::~FunctionCall()
{
}

ostream& FunctionCall::put(ostream& os) const
{
	os << INDENT << "FunctionCall[";
	if (fname_h!=NULL) { os << endl; fname_h->put(os); }
	if (arg_list_h!=NULL) { os << endl; arg_list_h->put(os); }
	return os << OUTDENT << "]\n";
}

//-FunctionCall::

void FunctionCall::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//fname_h->accept(v);
	arg_list_h->accept(v);
	v.end_visit(*this); 
}



// [93a] ArgList
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
	s << INDENT << "ArgList[" << endl;
	vector<rchandle<exprnode> >::const_iterator it = arg_hv.begin();
	for (; it!=arg_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-ArgList::

void ArgList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<exprnode> >::const_iterator it = arg_hv.begin();
	for (; it!=arg_hv.end(); ++it) {
		exprnode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [94] Constructor
// ----------------

// [95] DirectConstructor
// ----------------------



// [96] DirElemConstructor
// -----------------------

DirElemConstructor::DirElemConstructor(
	location const& _loc,
	rchandle<QName> _open_name_h,
	rchandle<QName> _close_name_h,
	rchandle<DirAttributeList> _attr_list_h,
	rchandle<DirElemContentList> _dir_content_list_h)
:
	exprnode(_loc),
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
	if (elem_name_h!=NULL) elem_name_h->put(s);
	s << endl;
	if (attr_list_h!=NULL) attr_list_h->put(s);
	if (dir_content_list_h!=NULL) dir_content_list_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirElemConstructor::

void DirElemConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//open_name_h->accept(v);
	//close_name_h->accept(v);
	attr_list_h->accept(v);
	dir_content_list_h->accept(v);
	v.end_visit(*this); 
}



// [96a] DirElemContentList
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
	s << INDENT << "DirElemContentList[" << endl;
	vector<rchandle<exprnode> >::const_iterator it = dir_content_hv.begin();
	for (; it!=dir_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-DirElemContentList::

void DirElemContentList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<exprnode> >::const_reverse_iterator it = dir_content_hv.rbegin();
	for (; it!=dir_content_hv.rend(); ++it) {
		exprnode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [97] DirAttributeList
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
	s << INDENT << "DirAttributeList[\n";
	vector<rchandle<DirAttr> >::const_iterator it = dir_attr_hv.begin();
	for (; it!=dir_attr_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-DirAttributeList::

void DirAttributeList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<DirAttr> >::const_reverse_iterator it = dir_attr_hv.rbegin();
	for (; it!=dir_attr_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [97a] DirAttr
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
	s << INDENT << "DirAttr[";
	if (atname_h!=NULL) atname_h->put(s);
	s << endl;
	if (dir_atval_h!=NULL) dir_atval_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirAttr::

void DirAttr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//atname_h->accept(v);
	dir_atval_h->accept(v);
	v.end_visit(*this); 
}



// [98] DirAttributeValue
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
	s << INDENT << "DirAttributeValue\n";
	if (quot_attr_content_h!=NULL) quot_attr_content_h->put(s);
	if (apos_attr_content_h!=NULL) apos_attr_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirAttributeValue::

void DirAttributeValue::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	quot_attr_content_h->accept(v);
	v.end_visit(*this); 
}




// [98a] QuoteAttrContentList
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
	s << INDENT << "QuoteAttrContentList[" << endl;
	vector<rchandle<QuoteAttrValueContent> >::const_iterator it =
		quot_atval_content_hv.begin();
	for (; it!=quot_atval_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-QuoteAttrContentList::

void QuoteAttrContentList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<QuoteAttrValueContent> >::const_reverse_iterator it =
		quot_atval_content_hv.rbegin();
	for (; it!=quot_atval_content_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [98b] AposAttrContentList
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
	s << INDENT << "AposAttrContentList[" << endl;
	vector<rchandle<AposAttrValueContent> >::const_iterator it =
		apos_atval_content_hv.begin();
	for (; it!=apos_atval_content_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-AposAttrContentList::

void AposAttrContentList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<AposAttrValueContent> >::const_reverse_iterator it =
		apos_atval_content_hv.rbegin();
	for (; it!=apos_atval_content_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [99] QuotAttrValueContent
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
	s << INDENT << "QuoteAttrValueContent[";
	s << "quot_atcontent=" << quot_atcontent << endl;
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-QuoteAttrValueContent::

void QuoteAttrValueContent::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [100] AposAttrValueContent
// --------------------------
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
	s << INDENT << "AposAttrValueContent[";
	s << "apos_atcontent=" << apos_atcontent << endl;
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AposAttrValueContent::

void AposAttrValueContent::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [101] DirElemContent
// --------------------
DirElemContent::DirElemContent(
	location const& _loc,
	rchandle<exprnode> _direct_cons_h)
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
	s << INDENT << "DirElemContent[";
	if (direct_cons_h!=NULL) direct_cons_h->put(s);
	s << "elem_content=" << elem_content << endl;
	if (cdata_h!=NULL) cdata_h->put(s);
	if (common_content_h!=NULL) common_content_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DirElemContent::

void DirElemContent::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	direct_cons_h->accept(v);
	v.end_visit(*this); 
}



// [102] CommonContent
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
	type(cont_expr),
	ref(""),
	expr_h(_expr_h)
{
}

CommonContent::CommonContent(
	location const& _loc,
	enum common_content_t _type)
:
	exprnode(_loc),
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

void CommonContent::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [103] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
	location const& _loc,
	std::string const& _comment)
:
	exprnode(_loc),
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

void DirCommentConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [104] DirCommentContents
// ------------------------
/* lexical rule */



// [105] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor(
	location const& _loc,
	std::string const& _pi_target)
:
	exprnode(_loc),
	pi_target(_pi_target),
	pi_content("")
{
}

DirPIConstructor::DirPIConstructor(
	location const& _loc,
	std::string const& _pi_target,
	std::string const& _pi_content)
:
	exprnode(_loc),
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

void DirPIConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [106] DirPIContents
// -------------------
/* lexical rule */



// [107] CDataSection
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
	s << INDENT << "CDataSection[";
	s << "cdata_content=" << cdata_content << endl;
	return s << OUTDENT << "]\n";
}

//-CDataSection::

void CDataSection::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [108] CDataSectionContents
// --------------------------
/* lexical rule */



// [109] ComputedConstructor
// -------------------------



// [110] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor(
	location const& _loc,
	rchandle<exprnode> _expr_h)
:
	exprnode(_loc),
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

void CompDocConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	expr_h->accept(v);
	v.end_visit(*this); 
}



// [111] CompElemConstructor
// -------------------------
CompElemConstructor::CompElemConstructor(
	location const& _loc,
	rchandle<exprnode> _qname_expr_h,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc),
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
	if (qname_h!=NULL) qname_h->put(s);
	if (qname_expr_h!=NULL) qname_expr_h->put(s);
	if (content_expr_h!=NULL) content_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompElemConstructor::

void CompElemConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//qname_h->accept(v);
	content_expr_h->accept(v);
	v.end_visit(*this); 
}



// [112] ContentExpr
// -----------------



// [113] CompAttrConstructor
// -------------------------
CompAttrConstructor::CompAttrConstructor(
	location const& _loc,
	rchandle<exprnode> _qname_expr_h,
	rchandle<exprnode> _val_expr_h)
:
	exprnode(_loc),
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
	if (qname_h!=NULL) qname_h->put(s);
	if (qname_expr_h!=NULL) qname_expr_h->put(s);
	if (val_expr_h!=NULL) val_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-CompAttrConstructor::

void CompAttrConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//qname_h->accept(v);
	val_expr_h->accept(v);
	v.end_visit(*this); 
}



// [114] CompTextConstructor
// -------------------------
CompTextConstructor::CompTextConstructor(
	location const& _loc,
	rchandle<exprnode> _text_expr_h)
:
	exprnode(_loc),
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

void CompTextConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	text_expr_h->accept(v);
	v.end_visit(*this); 
}



// [115] CompCommentConstructor
// ----------------------------
CompCommentConstructor::CompCommentConstructor(
	location const& _loc,
	rchandle<exprnode> _comment_expr_h)
:
	exprnode(_loc),
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

void CompCommentConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	comment_expr_h->accept(v);
	v.end_visit(*this); 
}



// [116] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
	location const& _loc,
	std::string _target,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc),
	target(_target),
	target_expr_h(NULL),
	content_expr_h(_content_expr_h)
{
}

CompPIConstructor::CompPIConstructor(
	location const& _loc,
	rchandle<exprnode> _target_expr_h,
	rchandle<exprnode> _content_expr_h)
:
	exprnode(_loc),
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

void CompPIConstructor::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	content_expr_h->accept(v);
	v.end_visit(*this); 
}



// [117] SingleType
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
	s << INDENT << "SingleType[";
	if (atomic_type_h!=NULL) atomic_type_h->put(s);
	s << "hook_b=" << hook_b << endl;
	return s << OUTDENT << "]\n";
}

//-SingleType::

void SingleType::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	atomic_type_h->accept(v);
	v.end_visit(*this); 
}



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

ostream& TypeDeclaration::put(ostream& os) const
{
	os << INDENT << "TypeDeclaration[";
	if (seqtype_h!=NULL) seqtype_h->put(os);
	return os << OUTDENT << "]\n";
}

//-TypeDeclaration::

void TypeDeclaration::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	seqtype_h->accept(v);
	v.end_visit(*this); 
}



// [119] SequenceType
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

ostream& SequenceType::put(ostream& os) const
{
	os << INDENT << "SequenceType[";
	if (itemtype_h!=NULL) itemtype_h->put(os);
	if (occur_h!=NULL) occur_h->put(os);
	return os << OUTDENT << "]\n";
}

//-SequenceType::

void SequenceType::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	itemtype_h->accept(v);
	occur_h->accept(v);
	v.end_visit(*this); 
}



// [120] OccurrenceIndicator
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

void OccurrenceIndicator::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [121] ItemType
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
	s << INDENT << "ItemType[";
	s << "item_test_b=" << item_test_b << endl;
	return s << OUTDENT << "]\n";
}

//-ItemType::

void ItemType::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [122] AtomicType
// ----------------
AtomicType::AtomicType(
	location const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h)
{
}

AtomicType::~AtomicType()
{
}

ostream& AtomicType::put(ostream& s) const
{
	s << INDENT << "AtomicType[";
	if (qname_h!=NULL) qname_h->put(s);
	return s << OUTDENT << "]\n";
}

//-AtomicType::

void AtomicType::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//qname_h->accept(v);
	v.end_visit(*this); 
}



// [123] KindTest
// --------------



// [124] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest(
	location const& _loc)
:
	parsenode(_loc)
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

void AnyKindTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [125] DocumentTest
// ------------------
DocumentTest::DocumentTest(
	location const& _loc)
:
	parsenode(_loc),
	elem_test_h(NULL),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	rchandle<ElementTest> _elem_test_h)
:
	parsenode(_loc),
	elem_test_h(_elem_test_h),
	schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
	location const& _loc,
	rchandle<SchemaElementTest> _schema_elem_test_h)
:
	parsenode(_loc),
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

void DocumentTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [126] TextTest
// --------------
TextTest::TextTest(
	location const& _loc)
:
	parsenode(_loc)
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

void TextTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [127] CommentTest
// -----------------
CommentTest::CommentTest(
	location const& _loc)
:
	parsenode(_loc)
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

void CommentTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}

 

// [128] PITest
// ------------
PITest::PITest(
	location const& _loc,
	std::string _target,
	std::string _content)
:
	parsenode(_loc),
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

void PITest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [129] AttributeTest
// -------------------
AttributeTest::AttributeTest(
	location const& _loc,
	rchandle<QName> _attr_h,
	rchandle<TypeName> _type_h)
:
	parsenode(_loc),
	attr_h(_attr_h),
	type_h(_type_h)
{
}

AttributeTest::~AttributeTest()
{
}

ostream& AttributeTest::put(ostream& os) const
{
	os << INDENT << "AttributeTest[";
	if (attr_h!=NULL) attr_h->put(os); else os << '*';
	if (type_h!=NULL) {
		os << ", ";
		type_h->put(os);
	}
	return os << OUTDENT << "]\n";
}

//-AttributeTest::

void AttributeTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}


// [130] AttribNameOrWildcard
// --------------------------


// [131] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
	location const& _loc,
	rchandle<QName> _attr_h)
:
	parsenode(_loc),
	attr_h(_attr_h)
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}

ostream& SchemaAttributeTest::put(ostream& os) const
{
	os << INDENT << "SchemaAttributeTest[";
	if (attr_h!=NULL) attr_h->put(os);
	return os << OUTDENT << "]\n";
}

//-SchemaAttributeTest::

void SchemaAttributeTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//if (attr_h!=NULL) attr_h->accept(v);
	v.end_visit(*this); 
}



// [133] ElementTest
// -----------------
ElementTest::ElementTest(
	location const& _loc,
	rchandle<QName> _elem_h,
	rchandle<TypeName> _type_h)
:
	parsenode(_loc),
	elem_h(_elem_h),
	type_h(_type_h),
	optional_b(false)
{
}

ElementTest::ElementTest(
	location const& _loc,
	rchandle<QName> _elem_h,
	rchandle<TypeName> _type_h,
	bool _b)
:
	parsenode(_loc),
	elem_h(_elem_h),
	type_h(_type_h),
	optional_b(_b)
{
}

ElementTest::~ElementTest()
{
}

ostream& ElementTest::put(ostream& os) const
{
	os << INDENT << "ElementTest[\n";
	if (elem_h!=NULL) elem_h->put(os); else os << '*';
	if (type_h!=NULL) {
		os << ", ";
		type_h->put(os);
	}
	if (optional_b) os << "?";
	return os << OUTDENT << "]\n";
}

//-ElementTest::

void ElementTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [135] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
	location const& _loc,
	rchandle<QName> _elem_h)
:
	parsenode(_loc),
	elem_h(_elem_h)
{
}

SchemaElementTest::~SchemaElementTest()
{
}

ostream& SchemaElementTest::put(ostream& os) const
{
	os << INDENT << "SchemaElementTest[";
	if (elem_h!=NULL) elem_h->put(os);
	return os << OUTDENT << "]\n";
}

//-SchemaElementTest::

void SchemaElementTest::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//if (elem_h!=NULL) elem_h->accept(v);
	v.end_visit(*this); 
}



/* inlined productions */
/* ------------------- */
// [130] AttribNameOrWildcard ::= AttributeName | STAR
// [132] AttributeDeclaration ::= AttributeName
// [134] ElementNameOrWildcard ::= ElementName | STAR
// [136] ElementDeclaration ::= ElementName
// [137] AttributeName ::= QNAME
// [138] ElementName ::= QNAME



// [139] TypeName
// --------------
TypeName::TypeName(
	location const& _loc,
	rchandle<QName> _qname_h)
:
	parsenode(_loc),
	qname_h(_qname_h),
	optional_b(false)
{
}

TypeName::TypeName(
	location const& _loc,
	rchandle<QName> _qname_h,
	bool _b)
:
	parsenode(_loc),
	qname_h(_qname_h),
	optional_b(_b)
{
}

TypeName::~TypeName()
{
}

ostream& TypeName::put(ostream& os) const
{
	os << INDENT << "TypeName[";
	if (qname_h!=NULL) qname_h->put(os);
	if (optional_b) os << "?";
	return os << OUTDENT << "]\n";
}

//-TypeName::

void TypeName::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//if (qname_h!=NULL) qname_h->accept(v);
	v.end_visit(*this); 
}



/* lexical rules, see xquery.l */
/* --------------------------- */
// [140] URILiteral 
// [141] IntegerLiteral
// [142] DecimalLiteral
// [143] DoubleLiteral



// [144] StringLiteral
// -------------------
StringLiteral::StringLiteral(
	yy::location const& _loc,
	string const& _strval)
:
	exprnode(_loc),
	strval(_strval)
{
}

StringLiteral::~StringLiteral()
{
}

ostream& StringLiteral::put(ostream& s) const
{
	s << INDENT << "StringLiteral[";
	s << "strval=\"" << strval << "\"\n";
	return s << OUTDENT << "]\n";
}

//-StringLiteral::

void StringLiteral::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



/* lexical rules, see xquery.l */
/* --------------------------- */

// [145] PredefinedEntityRef
// [146] EscapeQuot
// [147] EscapeApos
// [148] ElementContentChar
// [149] QuotAttrContentChar
// [150] AposAttrContentChar
// [151] Comment
// [152] PITarget
// [153] CharRef

// [155] NCName
// [156] S  (WS)
// [157] Char
// [158] Digits
// [159] CommentContents



// [154] QName
// -----------
QName::QName(
	const yy::location& _loc,
	const string& _qname)
:
	exprnode(_loc),
	qname(_qname),
	theURI("")
{
}

QName::QName(
	const yy::location& _loc,
	const string& _qname,
	const string& _uri)
:
	exprnode(_loc),
	qname(_qname),
	theURI(_uri)
{
}

QName::~QName()
{
}

string QName::get_localname() const
{
	string::size_type n = qname.find(':');
	return (n!=string::npos ? qname.substr(n+1) : qname);
}

string QName::get_prefix() const
{
	string::size_type n = qname.find(':');
	return (n!=string::npos ? qname.substr(0,n) : "");
}

ostream& QName::put(ostream& s) const
{
	s << INDENT << "QName[ " << qname;
	return s << OUTDENT << "]\n";
}

//-QName::

void QName::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}





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
	s << INDENT << "RevalidationDecl[";
	if (qname_h!=NULL) qname_h->put(s);
	return s << OUTDENT << "]\n";
}

//-RevalidationDecl::

void RevalidationDecl::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	//qname_h->accept(v);
	v.end_visit(*this); 
}



// [242]	InsertExpr
// ----------------
InsertExpr::InsertExpr(
	location const& _loc,
	rchandle<exprnode> _source_expr_h,
	rchandle<exprnode> _target_expr_h)
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
	s << INDENT << "InsertExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-InsertExpr::

void InsertExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
	location const& _loc,
	rchandle<exprnode> _target_expr_h)
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
	s << INDENT << "DeleteExpr[";
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-DeleteExpr::

void DeleteExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	target_expr_h->accept(v);
	v.end_visit(*this); 
}



// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
	location const& _loc,
	rchandle<exprnode> _source_expr_h,
	rchandle<exprnode> _target_expr_h)
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
	s << INDENT << "ReplaceExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-ReplaceExpr::

void ReplaceExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	source_expr_h->accept(v);
	target_expr_h->accept(v);
	v.end_visit(*this); 
}



// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
	location const& _loc,
	rchandle<exprnode> _source_expr_h,
	rchandle<exprnode> _target_expr_h)
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
	s << INDENT << "RenameExpr[";
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-RenameExpr::

void RenameExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	source_expr_h->accept(v);
	target_expr_h->accept(v);
	v.end_visit(*this); 
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
	location const& _loc,
	rchandle<VarNameList> _varname_list_h,
	rchandle<exprnode> _source_expr_h,
	rchandle<exprnode> _target_expr_h)
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
	s << INDENT << "TransformExpr[";
	if (varname_list_h!=NULL) varname_list_h->put(s);
	if (source_expr_h!=NULL) source_expr_h->put(s);
	if (target_expr_h!=NULL) target_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-TransformExpr::

void TransformExpr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	varname_list_h->accept(v);
	source_expr_h->accept(v);
	target_expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "VarNameList[" << endl;
	vector<rchandle<VarBinding> >::const_iterator it = varbinding_hv.begin();
	for (; it!=varbinding_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-VarNameList::

void VarNameList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<VarBinding> >::const_reverse_iterator it = varbinding_hv.rbegin();
	for (; it!=varbinding_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
	location const& _loc,
	std::string _varname,
	rchandle<exprnode> _val_h)
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
	s << INDENT << "VarBinding[";
	s << "varname=" << varname << endl;
	if (val_h!=NULL) val_h->put(s);
	return s << OUTDENT << "]\n";
}

//-VarBinding::

void VarBinding::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	val_h->accept(v);
	v.end_visit(*this); 
}






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
	s << INDENT << "FTSelection[";
	if (ftor_h!=NULL) ftor_h->put(s);
	if (option_list_h!=NULL) option_list_h->put(s);
	if (weight_expr_h!=NULL) weight_expr_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTSelection::

void FTSelection::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	ftor_h->accept(v);
	option_list_h->accept(v);
	weight_expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTMatchOptionProximityList[" << endl;
	vector<rchandle<FTMatchOptionProximity> >::const_iterator it =
		opt_prox_hv.begin();
	for (; it!=opt_prox_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTMatchOptionProximityList::

void FTMatchOptionProximityList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<FTMatchOptionProximity> >::const_reverse_iterator it =
		opt_prox_hv.rbegin();
	for (; it!=opt_prox_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



// [344b] FTMatchOptionProximity
// -----------------------------
FTMatchOptionProximity::FTMatchOptionProximity(
	rchandle<FTMatchOption> _opt_h,
	location const& _loc)
:
	parsenode(_loc),
	opt_h(_opt_h),
	prox_h(NULL)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
	rchandle<FTProximity> _prox_h,
	location const& _loc)
:
	parsenode(_loc),
	opt_h(NULL),
	prox_h(_prox_h)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
	location const& _loc)
:
	parsenode(_loc),
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

//-FTMatchOptionProximity::

void FTMatchOptionProximity::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	opt_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTOr[";
	if (ftor_h!=NULL) ftor_h->put(s);
	if (ftand_h!=NULL) ftand_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTOr::

void FTOr::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	ftor_h->accept(v);
	ftand_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTAnd[";
	if (ftand_h!=NULL) ftand_h->put(s);
	if (ftmild_not_h!=NULL) ftmild_not_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTAnd::

void FTAnd::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	ftand_h->accept(v);
	ftmild_not_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTMildnot[";
	if (ftmild_not_h!=NULL) ftmild_not_h->put(s);
	if (ftunary_not_h!=NULL) ftunary_not_h->put(s);
	return s << OUTDENT << "]\n";
}

//-FTMildnot::

void FTMildnot::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	ftmild_not_h->accept(v);
	ftunary_not_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTUnaryNot[";
	if (words_selection_h!=NULL) words_selection_h->put(s);
	s << "not_b=" << not_b << endl;
	return s << OUTDENT << "]\n";
}

//-FTUnaryNot::

void FTUnaryNot::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	words_selection_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "Xxxx[";
	return s << OUTDENT << "]\n";
}

//-FTWordsSelection::

void FTWordsSelection::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	words_h->accept(v);
	times_h->accept(v);
	selection_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "Xxxx[";
	return s << OUTDENT << "]\n";
}

//-FTWords::

void FTWords::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	words_val_h->accept(v);
	any_all_option_h->accept(v);
	v.end_visit(*this); 
}



// [351] FTWordsValue
// ------------------
FTWordsValue::FTWordsValue(
	location const& _loc,
	rchandle<StringLiteral> _lit_h,
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
	s << INDENT << "FTWordsValue[";
	return s << OUTDENT << "]\n";
}

//-FTWordsValue::

void FTWordsValue::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	lit_h->accept(v);
	expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTProximity[";
	return s << OUTDENT << "]\n";
}

//-FTProximity::

void FTProximity::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTOrderedIndicator[";
	return s << OUTDENT << "]\n";
}

//-FTOrderedIndicator::

void FTOrderedIndicator::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTMatchOption[";
	return s << OUTDENT << "]\n";
}

//-FTMatchOption::

void FTMatchOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTCaseOption[";
	return s << OUTDENT << "]\n";
}

//-FTCaseOption::

void FTCaseOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTDiacriticsOptino[";
	return s << OUTDENT << "]\n";
}

//-FTDiacriticsOption::

void FTDiacriticsOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTStemOption[";
	return s << OUTDENT << "]\n";
}

//-FTStemOption::

void FTStemOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTThesaurusOption[";
	return s << OUTDENT << "]\n";
}

//-FTThesaurusOption::

void FTThesaurusOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	thesaurusid_h->accept(v);
	thesaurus_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTThesaurusIDList[" << endl;
	++printdepth;
	vector<rchandle<FTThesaurusID> >::const_iterator it = thesaurus_hv.begin();
	for (; it!=thesaurus_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTThesaurusList::

void FTThesaurusList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<FTThesaurusID> >::const_reverse_iterator it = thesaurus_hv.rbegin();
	for (; it!=thesaurus_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



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
	s << INDENT << "FTThesaurusID[";
	return s << OUTDENT << "]\n";
}

//-FTThesaurusID::

void FTThesaurusID::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	levels_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTStopwordOption[";
	return s << OUTDENT << "]\n";
}

//-FTStopwordOption::

void FTStopwordOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	refor_list_h->accept(v);
	incl_excl_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTInclExclStringLiteralList[" << endl;
	++printdepth;
	vector<rchandle<FTInclExclStringLiteral> >::const_iterator it =
		incl_excl_lit_hv.begin();
	for (; it!=incl_excl_lit_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
	return s << OUTDENT << "]\n";
}

//-FTInclExclStringLiteralList::

void FTInclExclStringLiteralList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<rchandle<FTInclExclStringLiteral> >::const_reverse_iterator it =
		incl_excl_lit_hv.rbegin();
	for (; it!=incl_excl_lit_hv.rend(); ++it) {
		parsenode* e_p = &**it;
		Assert<null_pointer>(e_p!=NULL,LOCATION);
		e_p->accept(v);
	}
	v.end_visit(*this); 
}



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
	s << INDENT << "FTRefOrList[";
	return s << OUTDENT << "]\n";
}

//-FTRefOrList::

void FTRefOrList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	stringlit_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTStringLiteralList[" << endl;
	++printdepth;
	vector<string>::const_iterator it = strlit_v.begin();
	for (; it!=strlit_v.end(); ++it) { s << (*it); }
	return s << OUTDENT << "]\n";
}

//-FTStringLiteralList::

void FTStringLiteralList::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	vector<string>::const_reverse_iterator it = strlit_v.rbegin();
	for (; it!=strlit_v.rend(); ++it) {
		// ..do something useful..
	}
	v.end_visit(*this); 
}



// [362] FTInclExclStringLiteral
// -----------------------------
FTInclExclStringLiteral::FTInclExclStringLiteral(
	location const& _loc,
	rchandle<FTRefOrList> _ref_or_list_h,
	intex_op_t _mode)
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
	s << INDENT << "FTInclExclStringLiteral[";
	return s << OUTDENT << "]\n";
}

//-FTInclExclStringLiteral::

void FTInclExclStringLiteral::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	ref_or_list_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTLanguageOption[";
	return s << OUTDENT << "]\n";
}

//-FTLanguageOption::

void FTLanguageOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTWildcardOption[";
	return s << OUTDENT << "]\n";
}

//-FTWildcardOption::

void FTWildcardOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTContent[";
	return s << OUTDENT << "]\n";
}

//-FTContent::

void FTContent::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTAnyallOption[";
	return s << OUTDENT << "]\n";
}

//-FTAnyallOption::

void FTAnyallOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTRange[";
	return s << OUTDENT << "]\n";
}

//-FTRange::

void FTRange::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	src_expr_h->accept(v);
	dst_expr_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTDistance[";
	return s << OUTDENT << "]\n";
}

//-FTDistance::

void FTDistance::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	dist_h->accept(v);
	unit_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTWindow[";
	return s << OUTDENT << "]\n";
}

//-FTWindow::

void FTWindow::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	window_h->accept(v);
	unit_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTTimes[";
	return s << OUTDENT << "]\n";
}

//-FTTimes::

void FTTimes::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	range_h->accept(v);
	v.end_visit(*this); 
}



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
	s << INDENT << "FTScope[";
	return s << OUTDENT << "]\n";
}

//-FTScope::

void FTScope::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTUnit[";
	return s << OUTDENT << "]\n";
}

//-FTUnit::

void FTUnit::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTBigUnit[";
	return s << OUTDENT << "]\n";
}

//-FTBigUnit::

void FTBigUnit::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	v.end_visit(*this); 
}



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
	s << INDENT << "FTBigUnit[";
	return s << OUTDENT << "]\n";
}

//-FTIgnoreOption::

void FTIgnoreOption::accept(parsenode_visitor& v) const 
{ 
	if (!v.begin_visit(*this)) return;
	union_h->accept(v);
	v.end_visit(*this); 
}



}	/* namespace xqp */


