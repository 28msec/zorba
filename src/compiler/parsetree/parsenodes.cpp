/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id:: parsenodes.cpp,v 1.1.1.1 2006/11/06 08:42:18 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR FOundation.
 *
 */

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>

#include "compiler/parsetree/parsenode_visitor.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "errors/error_factory.h"
#include "store/api/item.h"

#include "util/utf8/Unicode_util.h"

using namespace std;
namespace xqp {

int printdepth = 0;
ostringstream __oss;

#define INDENT      std::string(++printdepth, ' ')
#define OUTDENT     std::string(printdepth--, ' ')
#define UNDENT      printdepth--

#define BEGIN_VISITOR() void *visitor_state; if (NULL == (visitor_state = v.begin_visit (*this))) return
#define END_VISITOR() v.end_visit (*this, visitor_state)
#define ACCEPT( m ) do { if ((m) != NULL) (m)->accept (v); } while (0)
#define ACCEPT_CHK( m ) do { ZORBA_ASSERT ((m) != NULL);  (m)->accept (v); } while (0)



// [1] Module
// ----------
Module::Module(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

Module::~Module()
{
}

// ostream& Module::put(ostream& os) const
// {
//   return os;
// }

//-Module::

void Module::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl(
  const yy::location& _loc,
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

// ostream& VersionDecl::put(ostream& os) const
// {
//   return os;
// }

//-VersionDecl::

void VersionDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}





// [3] MainModule
// --------------
MainModule::MainModule(
  const yy::location& _loc,
  rchandle<Prolog> _prolog_h,
  rchandle<QueryBody> _query_body_h)
:
  parsenode(_loc),
  prolog_h(_prolog_h),
  query_body_h(_query_body_h)
{
}

MainModule::MainModule(
  const yy::location& _loc,
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

// ostream& MainModule::put(ostream& s) const
// {
//   s << INDENT << "MainModule[" << endl;
//   if (prolog_h!=NULL) prolog_h->put(s);
//   query_body_h->put(s);
//   return s << OUTDENT << "]\n";
// }

//-MainModule::

void MainModule::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (prolog_h);
  ACCEPT (query_body_h);
  END_VISITOR ();
}





// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule(
  const yy::location& _loc,
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

// ostream& LibraryModule::put(ostream& s) const
// {
//   s << INDENT << "LibraryModule[" << endl;
//   if (decl_h!=NULL) decl_h->put(s);
//   prolog_h->put(s);
//   return s << OUTDENT << "]\n";
// }

//-LibraryModule::

void LibraryModule::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (decl_h);
  ACCEPT (prolog_h);
  END_VISITOR ();
}





// [5] ModuleDecl
// --------------
ModuleDecl::ModuleDecl(
  const yy::location& _loc,
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



//-ModuleDecl::

void ModuleDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}





// [6] Prolog
// ----------
Prolog::Prolog(
  const yy::location& _loc,
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

// ostream& Prolog::put(ostream& s) const
// {
//   s << INDENT << "Prolog[" << endl;
//   if (sind_list_h!=NULL) sind_list_h->put(s);
//   if (vfo_list_h!=NULL) vfo_list_h->put(s);
//   return s << OUTDENT << "]\n";
// }

//-Prolog::

void Prolog::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (sind_list_h);
  ACCEPT (vfo_list_h);
  END_VISITOR ();
}



// [6a] SIND_DeclList
// ------------------
SIND_DeclList::SIND_DeclList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

SIND_DeclList::~SIND_DeclList()
{
}

// ostream& SIND_DeclList::put(ostream& s) const
// {
//   s << INDENT << "SIND_DeclList[" << endl;
//   vector<rchandle<parsenode> >::const_iterator it = sind_hv.begin();
//   for (; it!=sind_hv.end(); ++it) { if (*it!=NULL) (*it)->put(s); }
//   return s << OUTDENT << "]\n";
// }

//-SIND_DeclList::

void SIND_DeclList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  
  for (vector<rchandle<parsenode> >::const_reverse_iterator it = sind_hv.rbegin();
       it!=sind_hv.rend(); ++it)
  {
    ACCEPT_CHK ((*it));
  }
  END_VISITOR ();
}



// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

VFO_DeclList::~VFO_DeclList()
{
}

//-VFO_DeclList::

void VFO_DeclList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  
  for (vector<rchandle<parsenode> >::const_iterator it = vfo_hv.begin();
       it!=vfo_hv.end(); ++it)
  {
    ACCEPT_CHK (*it);
  }
  END_VISITOR ();
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

NamespaceDecl::NamespaceDecl(
  const yy::location& loc,
  std::string const& prefix,
  std::string const& uri)
:
  parsenode(loc),
  thePrefix(prefix),
  theUri(uri)
  //  theUri(uri, 1, uri.size()-2)
{
}


NamespaceDecl::~NamespaceDecl()
{
}


void NamespaceDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
  const yy::location& _loc,
  StaticQueryContext::boundary_space_mode_t _mode)
:
  parsenode(_loc),
  mode(_mode)
{
}

BoundarySpaceDecl::~BoundarySpaceDecl()
{
}

// ostream& BoundarySpaceDecl::put(ostream& s) const
// {
//   s << INDENT << "BoundarySpaceDecl[";
//   switch (mode) {
//   case StaticQueryContext::preserve_space: s << "preserve"; break;
//   case StaticQueryContext::strip_space: s << "strip"; break;
//   default: s << "???";
//   }
//   return s << OUTDENT << "]\n";
// }

//-BoundarySpaceDecl::

void BoundarySpaceDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
  const yy::location& _loc,
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

// ostream& DefaultNamespaceDecl::put(ostream& s) const
// {
//   s << INDENT << "DefaultNamespaceDecl[";
//   switch (mode) {
//   case ns_element_default: s << "element: "; break;
//   case ns_function_default: s << "function: "; break;
//   default: s << "???";
//   }
//   return s << default_namespace << "]\n";
// }

//-DefaultNamespaceDecl::

void DefaultNamespaceDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl(
  const yy::location& _loc,
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

// ostream& OptionDecl::put(ostream& s) const
// {
//   s << INDENT << "OptionDecl[";
//   if (qname_h!=NULL) qname_h->put(s);
//   s << " " << val << endl;
//   return s << OUTDENT << "]\n";
// }

//-OptionDecl::

void OptionDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //qname_h->accept(v);
  END_VISITOR ();
}



// [13a] FTOptionDecl
// ------------------
FTOptionDecl::FTOptionDecl(
  const yy::location& _loc,
  rchandle<parsenode> _match_option_h)
:
  parsenode(_loc),
  match_option_h(_match_option_h)
{
}

FTOptionDecl::~FTOptionDecl()
{
}

// ostream& FTOptionDecl::put(ostream& s) const
// {
//   s << INDENT << "FTOptionDecl[";
//   if (match_option_h!=NULL) match_option_h->put(s);
//   return s << OUTDENT << "]\n";
// }

//-FTOptionDecl::

void FTOptionDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (match_option_h);
  END_VISITOR ();
}



// [14] OrderingModeDecl
// ---------------------
OrderingModeDecl::OrderingModeDecl(
  const yy::location& _loc,
  StaticQueryContext::ordering_mode_t _mode)
:
  parsenode(_loc),
  mode(_mode)
{
}

OrderingModeDecl::~OrderingModeDecl()
{
}

// ostream& OrderingModeDecl::put(ostream& s) const
// {
//   s << INDENT << "OrderingModeDecl[";
//   switch (mode) {
//   case StaticQueryContext::ordered: s << "ordered"; break;
//   case StaticQueryContext::unordered: s << "unordered"; break;
//   default: s << "???";
//   }
//   return s << OUTDENT << "]\n";
// }

//-OrderingModeDecl::

void OrderingModeDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
  const yy::location& _loc,
  StaticQueryContext::order_empty_mode_t _mode)
:
  parsenode(_loc),
  mode(_mode)
{
}

EmptyOrderDecl::~EmptyOrderDecl()
{
}

// ostream& EmptyOrderDecl::put(ostream& s) const
// {
//   s << INDENT << "EmptyOrderDecl[";
//   switch (mode) {
//   case StaticQueryContext::empty_greatest: s << "greatest"; break;
//   case StaticQueryContext::empty_least: s << "least"; break;
//   default: s << "???";
//   }
//   return s << OUTDENT << "]\n";
// }

//-EmptyOrderDecl::

void EmptyOrderDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
  const yy::location& _loc,
  StaticQueryContext::preserve_mode_t _preserve_mode,
  StaticQueryContext::inherit_mode_t  _inherit_mode)
:
  parsenode(_loc),
  preserve_mode(_preserve_mode),
  inherit_mode(_inherit_mode)
{
}

CopyNamespacesDecl::~CopyNamespacesDecl()
{
}

// ostream& CopyNamespacesDecl::put(ostream& s) const
// {
//   s << INDENT << "CopyNamespacesDecl[";
//   switch (preserve_mode) {
//   case StaticQueryContext::preserve_ns: s << "preserve"; break;
//   case StaticQueryContext::no_preserve_ns: s << "no preserve"; break;
//   }
//   s << ", ";
//   switch (inherit_mode) {
//   case StaticQueryContext::inherit_ns: s << "inherit"; break;
//   case StaticQueryContext::no_inherit_ns: s << "no inherit"; break;
//   }
//   return s << OUTDENT << "]\n";
// }

//-CopyNamespacesDecl::

void CopyNamespacesDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [17] PreserveMode
// -----------------

// [18] InheritMode
// ----------------



// [19] DefaultCollationDecl
// -------------------------
DefaultCollationDecl::DefaultCollationDecl(
  const yy::location& _loc,
  std::string const&  _collation)
:
  parsenode(_loc),
  collation(_collation)
{
}

DefaultCollationDecl::~DefaultCollationDecl()
{
}

// ostream& DefaultCollationDecl::put(ostream& s) const
// {
//   s << INDENT << "DefaultCollationDecl[";
//   s << "collation=" << collation << endl;
//   return s << OUTDENT << "]\n";
// }

//-DefaultCollationDecl::

void DefaultCollationDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
  const yy::location& _loc,
  std::string const& _base_uri)
:
  parsenode(_loc),
  base_uri(_base_uri)
{
}

BaseURIDecl::~BaseURIDecl()
{
}

// ostream& BaseURIDecl::put(ostream& s) const
// {
//   s << INDENT << "BaseURIDecl[";
//   s << base_uri;
//   return s << OUTDENT << "]\n";
// }

//-BaseURIDecl::

void BaseURIDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
  const yy::location& _loc,
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

// ostream& SchemaImport::put(ostream& s) const
// {
//   s << INDENT << "SchemaImport[";
//   if (prefix_h!=NULL) prefix_h->put(s);
//   s << "uri=" << uri << endl;
//   if (at_list_h!=NULL) at_list_h->put(s);
//   return s << OUTDENT << "]\n";
// }

//-SchemaImport::

void SchemaImport::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (prefix_h);
  ACCEPT (at_list_h);
  END_VISITOR ();
}



// [21a] URLLiteralList
// --------------------
URILiteralList::URILiteralList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

URILiteralList::~URILiteralList()
{
}

// ostream& URILiteralList::put(ostream& s) const
// {
//   s << INDENT << "URILiteralList[" << endl;
//   ++printdepth;
//   vector<string>::const_iterator it = uri_v.begin();
//   for (; it!=uri_v.end(); ++it) { s << *it << endl; }
//   return s << OUTDENT << "]\n";
// }

//-URILiteralList::

void URILiteralList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<string>::const_reverse_iterator it = uri_v.rbegin();
  for (; it!=uri_v.rend(); ++it) {
    // ..do something useful
  }
  END_VISITOR ();
}



// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix(
  const yy::location& _loc,
  bool _default_b)
:
  parsenode(_loc),
  prefix(""),
  default_b(_default_b)
{
}

SchemaPrefix::SchemaPrefix(
  const yy::location& _loc,
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



//-SchemaPrefix::

void SchemaPrefix::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
  const yy::location& _loc,
  std::string const& uri,
  rchandle<URILiteralList> _uri_list_h)
:
  parsenode(_loc),
  uri_list_h(_uri_list_h)
{
}

ModuleImport::ModuleImport(
  const yy::location& _loc,
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



//-ModuleImport::

void ModuleImport::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (uri_list_h);
  END_VISITOR ();
}



// [24] VarDecl
// ------------
VarDecl::VarDecl(
  const yy::location& _loc,
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



//-VarDecl::

void VarDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  ACCEPT (initexpr_h);
  END_VISITOR ();
}



// [25] ConstructionDecl
// ---------------------
ConstructionDecl::ConstructionDecl(
  const yy::location& _loc,
  StaticQueryContext::construction_mode_t _mode)
:
  parsenode(_loc),
  mode(_mode)
{
}

ConstructionDecl::~ConstructionDecl()
{
}



//-ConstructionDecl::

void ConstructionDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl(
  const yy::location& _loc,
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



//-FunctionDecl::

void FunctionDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (paramlist_h);
  ACCEPT (return_type_h);
  // Avoid EnclosedExpr
  if (body_h != NULL)
    ACCEPT (body_h->get_expr ());
  END_VISITOR ();
}



// [27] ParamList
// --------------
ParamList::ParamList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

ParamList::~ParamList()
{
}



//-ParamList::

void ParamList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<Param> >::const_reverse_iterator it = param_hv.rbegin();
  for (; it!=param_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [28] Param
// ----------
Param::Param(
  const yy::location& _loc,
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



//-Param::

void Param::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  END_VISITOR ();
}



// [29] EnclosedExpr
// -----------------
EnclosedExpr::EnclosedExpr(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

EnclosedExpr::~EnclosedExpr()
{
}



//-EnclosedExpr::

void EnclosedExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [30] QueryBody
// --------------
QueryBody::QueryBody(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

QueryBody::~QueryBody()
{
}



//-QueryBody::

void QueryBody::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [31] Expr
// ---------
Expr::Expr(
  const yy::location& _loc)
:
  exprnode(_loc)
{
}

Expr::~Expr()
{
}



//-Expr::

void Expr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<exprnode> >::const_reverse_iterator it = expr_hv.rbegin();
  for (; it!=expr_hv.rend(); ++it) {
    const exprnode* e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}

int Expr::numberOfChildren() const
{
    return expr_hv.size();
}


// [32] ExprSingle
// ---------------


// [33] FLWORExpr
// --------------
FLWORExpr::FLWORExpr(
  const yy::location& _loc,
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



//-FLWORExpr::

void FLWORExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (forlet_list_h);
  ACCEPT (where_h);
  ACCEPT (orderby_h);
  ACCEPT (return_val_h);
  END_VISITOR ();
}



// [33a] ForLetClauseList
// ----------------------
ForLetClauseList::ForLetClauseList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

ForLetClauseList::~ForLetClauseList()
{
}



//-ForLetClauseList::

void ForLetClauseList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<ForOrLetClause> >::const_iterator it = forlet_hv.begin();
  for (; it!=forlet_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [33b] ForOrLetClause
// ------------------



// [34] ForClause
// --------------
ForClause::ForClause(
  const yy::location& _loc,
  rchandle<VarInDeclList> _vardecl_list_h)
:
  ForOrLetClause(_loc),
  vardecl_list_h(_vardecl_list_h)
{
}

ForClause::~ForClause()
{
}



//-ForClause::

void ForClause::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (vardecl_list_h);
  END_VISITOR ();
}

int ForClause::get_decl_count () const { return vardecl_list_h->size (); }


// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

VarInDeclList::~VarInDeclList()
{
}



//-VarInDeclList::

void VarInDeclList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<VarInDecl> >::const_iterator it = vardecl_hv.begin();
  for (; it!=vardecl_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
  const yy::location& _loc,
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



//-VarInDecl::

void VarInDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  ACCEPT (posvar_h);
  ACCEPT (ftscorevar_h);
  ACCEPT (valexpr_h);
  END_VISITOR ();
}



// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
  const yy::location& _loc,
  std::string const& _varname)
:
  parsenode(_loc),
  varname(_varname)
{
}

PositionalVar::~PositionalVar()
{
}



//-PositionalVar::

void PositionalVar::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [36] LetClause
// --------------
LetClause::LetClause(
  const yy::location& _loc,
  rchandle<VarGetsDeclList> _vardecl_list_h)
:
  ForOrLetClause(_loc),
  vardecl_list_h(_vardecl_list_h)
{
}

LetClause::~LetClause()
{
}



//-LetClause::

void LetClause::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (vardecl_list_h);
  END_VISITOR ();
}

int LetClause::get_decl_count () const { return vardecl_list_h->size (); }


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

VarGetsDeclList::~VarGetsDeclList()
{
}



//-VarGetsDeclList::

void VarGetsDeclList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<VarGetsDecl> >::const_iterator it = vardecl_hv.begin();
  for (; it!=vardecl_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [36b] VarGetsDecl
// ------------------
VarGetsDecl::VarGetsDecl(
  const yy::location& _loc,
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



//-VarGetsDecl::

void VarGetsDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  if (typedecl_h != 0)
          typedecl_h->accept(v);
        if (ftscorevar_h != 0)
          ftscorevar_h->accept(v);
  ACCEPT (valexpr_h);
  END_VISITOR ();
}



// [36c] FTScoreVar
// ----------------
FTScoreVar::FTScoreVar(
  const yy::location& _loc,
  std::string _varname)
:
  parsenode(_loc),
  varname(_varname)
{
}

FTScoreVar::~FTScoreVar()
{
}



//-FTScoreVar::

void FTScoreVar::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [37] WhereClause
// ----------------
WhereClause::WhereClause(
  const yy::location& _loc,
  rchandle<exprnode> _predicate_h)
:
  parsenode(_loc),
  predicate_h(_predicate_h)
{
}

WhereClause::~WhereClause()
{
}



//-WhereClause::

void WhereClause::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (predicate_h);
  END_VISITOR ();
}



// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause(
  const yy::location& _loc,
  rchandle<OrderSpecList> _spec_list_h,
  bool _stable_b)
:
  parsenode(_loc),
  spec_list_h(_spec_list_h),
  stable_b(_stable_b)
{
}


OrderByClause::~OrderByClause()
{
}



//-OrderByClause::

void OrderByClause::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (spec_list_h);
  END_VISITOR ();
}



// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

OrderSpecList::~OrderSpecList()
{
}



//-OrderSpecList::

void OrderSpecList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<OrderSpec> >::const_reverse_iterator it = spec_hv.rbegin();
  for (; it!=spec_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
  const yy::location& _loc,
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



//-OrderSpec::

void OrderSpec::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (spec_h);
  ACCEPT (modifier_h);
  END_VISITOR ();
}



// [41] OrderModifier
// ------------------
OrderModifier::OrderModifier(
  const yy::location& _loc,
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



//-OrderModifier::

void OrderModifier::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (dir_spec_h);
  ACCEPT (empty_spec_h);
  ACCEPT (collation_spec_h);
  END_VISITOR ();
}



// [41a] OrderDirSpec
// ------------------
OrderDirSpec::OrderDirSpec(
  const yy::location& _loc,
  enum dir_spec_t _dir_spec)
:
  parsenode(_loc),
  dir_spec(_dir_spec)
{
}

OrderDirSpec::~OrderDirSpec()
{
}
  


//-OrderDirSpec::

void OrderDirSpec::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
  const yy::location& _loc,
  StaticQueryContext::order_empty_mode_t _empty_order_spec)
:
  parsenode(_loc),
  empty_order_spec(_empty_order_spec)
{
}

OrderEmptySpec::~OrderEmptySpec()
{
}



//-OrderEmptySpec::

void OrderEmptySpec::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
  const yy::location& _loc,
  std::string const& _uri)
:
  parsenode(_loc),
  uri(_uri)
{
}

OrderCollationSpec::~OrderCollationSpec()
{
}



//-OrderCollationSpec::

void OrderCollationSpec::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [42] QuantifiedExpr     
// -------------------
QuantifiedExpr::QuantifiedExpr(
  const yy::location& _loc,
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



//-QuantifiedExpr::

void QuantifiedExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (decl_list_h);
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

QVarInDeclList::~QVarInDeclList()
{
}



//-QVarInDeclList::

void QVarInDeclList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<QVarInDecl> >::const_reverse_iterator it = qvar_decl_hv.rbegin();
  for (; it!=qvar_decl_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
  const yy::location& _loc,
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
  const yy::location& _loc,
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



//-QVarInDecl::

void QVarInDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (val_h);
  END_VISITOR ();
}



// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
  const yy::location& _loc,
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
  const yy::location& _loc,
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



//-TypeswitchExpr::

void TypeswitchExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (switch_expr_h);
  ACCEPT (clause_list_h);
  ACCEPT (default_clause_h);

  ACCEPT_CHK (switch_expr_h);

  ACCEPT_CHK (default_clause_h);

  Assert(clause_list_h!=NULL);
  
  for (vector<rchandle<CaseClause> >::const_reverse_iterator it = clause_list_h->rbegin();
       it!=clause_list_h->rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

CaseClauseList::~CaseClauseList()
{
}



//-CaseClauseList::

void CaseClauseList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<CaseClause> >::const_reverse_iterator it = clause_hv.rbegin();
  for (; it!=clause_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [44] CaseClause
// ---------------
CaseClause::CaseClause(
  const yy::location& _loc,
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
  const yy::location& _loc,
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



//-CaseClause::

void CaseClause::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (type_h);
  ACCEPT (val_h);
  END_VISITOR ();
}



// [45] IfExpr
// -----------
IfExpr::IfExpr(
  const yy::location& _loc,
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



//-IfExpr::

void IfExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (cond_expr_h);
  ACCEPT (then_expr_h);
  ACCEPT (else_expr_h);
  END_VISITOR ();
}



// [46] OrExpr
// -----------
OrExpr::OrExpr(
  const yy::location& _loc,
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



//-OrExpr::

void OrExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (or_expr_h);
  ACCEPT (and_expr_h);
  END_VISITOR ();
}



// [47] AndExpr
// ------------
AndExpr::AndExpr(
  const yy::location& _loc,
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



//-AndExpr::

void AndExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (and_expr_h);
  ACCEPT (comp_expr_h);
  END_VISITOR ();
}



// [48] ComparisonExpr
// -------------------
ComparisonExpr::ComparisonExpr(
  const yy::location& _loc,
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
  const yy::location& _loc,
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
  const yy::location& _loc,
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



//-ComparisonExpr::

void ComparisonExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (gencomp_h);
  ACCEPT (nodecomp_h);
  ACCEPT (valcomp_h);
  ACCEPT (left_h);
  ACCEPT (right_h);
  END_VISITOR ();
}



// [48a] FTContainsExpr
// --------------------
FTContainsExpr::FTContainsExpr(
  const yy::location& _loc,
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



//-FTContainsExpr::

void FTContainsExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (range_expr_h);
  ACCEPT (ftselect_h);
  ACCEPT (ftignore_h);
  END_VISITOR ();
}



// [49] RangeExpr
// --------------
RangeExpr::RangeExpr(
  const yy::location& _loc,
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



//-RangeExpr::

void RangeExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (from_expr_h);
  ACCEPT (to_expr_h);
  END_VISITOR ();
}



// [50] AdditiveExpr
// -----------------
AdditiveExpr::AdditiveExpr(
  const yy::location& _loc,
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



//-AdditiveExpr::

void AdditiveExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (add_expr_h);
  ACCEPT (mult_expr_h);
  END_VISITOR ();
}



// [51] MultiplicativeExpr
// -----------------------
MultiplicativeExpr::MultiplicativeExpr(
  const yy::location& _loc,
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



//-MultiplicativeExpr::

void MultiplicativeExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (mult_expr_h);
  ACCEPT (union_expr_h);
  END_VISITOR ();
}



// [52] UnionExpr
// --------------
UnionExpr::UnionExpr(
  const yy::location& _loc,
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



//-UnionExpr::

void UnionExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (union_expr_h);
  ACCEPT (intex_expr_h);
  END_VISITOR ();
}



// [53] IntersectExceptExpr
// ------------------------
IntersectExceptExpr::IntersectExceptExpr(
  const yy::location& _loc,
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



//-IntersectExceptExpr::

void IntersectExceptExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (intex_expr_h);
  ACCEPT (instof_expr_h);
  END_VISITOR ();
}



// [54] InstanceofExpr
// -------------------
InstanceofExpr::InstanceofExpr(
  const yy::location& _loc,
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



//-InstanceofExpr::

void InstanceofExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (treat_expr_h);
  ACCEPT (seqtype_h);
  END_VISITOR ();
}



// [55] TreatExpr
// --------------
TreatExpr::TreatExpr(
  const yy::location& _loc,
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



//-TreatExpr::

void TreatExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (castable_expr_h);
  ACCEPT (seqtype_h);
  END_VISITOR ();
}



// [56] CastableExpr
// -----------------
CastableExpr::CastableExpr(
  const yy::location& _loc,
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



//-CastableExpr::

void CastableExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (cast_expr_h);
  ACCEPT (singletype_h);
  END_VISITOR ();
}



// [57] CastExpr     
// -------------
CastExpr::CastExpr(
  const yy::location& _loc,
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



//-CastExpr::

void CastExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (unary_expr_h);
  ACCEPT (singletype_h);
  END_VISITOR ();
}



// [58] UnaryExpr
// --------------
UnaryExpr::UnaryExpr(
  const yy::location& _loc,
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



//-UnaryExpr::

void UnaryExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (signlist_h);
  ACCEPT (value_expr_h);
  END_VISITOR ();
}



// [58a] SignList
// --------------
SignList::SignList(
  const yy::location& _loc,
  bool _sign)
:
  parsenode(_loc),
  sign(_sign)
{
}

SignList::~SignList()
{
}



//-SignList::

void SignList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [59] ValueExpr
// --------------


// [60] GeneralComp
// ----------------
GeneralComp::GeneralComp(
  const yy::location& _loc,
  enum gencomp_t _type)
:
  parsenode(_loc),
  type(_type)
{
}

GeneralComp::~GeneralComp()
{
}



//-GeneralComp::

void GeneralComp::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [61] ValueComp
// --------------
ValueComp::ValueComp(
  const yy::location& _loc,
  enum valcomp_t _type)
:
  parsenode(_loc),
  type(_type)
{
}

ValueComp::~ValueComp()
{
}



//-ValueComp::

void ValueComp::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [62] NodeComp
// -------------
NodeComp::NodeComp(
  const yy::location& _loc,
  enum nodecomp_t _type)
:
  parsenode(_loc),
  type(_type)
{
}

NodeComp::~NodeComp()
{
}



//-NodeComp::

void NodeComp::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
  const yy::location& _loc,
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



//-ValidateExpr::

void ValidateExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [65] ExtensionExpr
// ------------------
ExtensionExpr::ExtensionExpr(
  const yy::location& _loc,
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



//-ExtensionExpr::

void ExtensionExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (pragma_list_h);
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [65a] PragmaList
// ----------------
PragmaList::PragmaList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

PragmaList::~PragmaList()
{
}



//-PragmaList::

void PragmaList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<Pragma> >::const_reverse_iterator it = pragma_hv.rbegin();
  for (; it!=pragma_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [66] Pragma
// -----------
Pragma::Pragma(
  const yy::location& _loc,
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



//-Pragma::

void Pragma::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //name->accept(v);
  END_VISITOR ();
}



// [67] PragmaContents
// -------------------
/* folded into [66] */



/*******************************************************************************

  [68] PathExpr ::= LEADING_LONE_SLASH |
                    SLASH  RelativePathExpr |
                    SLASH_SLASH  RelativePathExpr |
                    RelativePathExpr
********************************************************************************/
PathExpr::PathExpr(
  const yy::location& _loc,
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


void PathExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (relpath_expr_h);
  END_VISITOR ();
}


/*******************************************************************************

  [69] RelativePathExpr ::= StepExpr |
                            StepExpr  SLASH  RelativePathExpr |
                            StepExpr  SLASH_SLASH  RelativePathExpr 

********************************************************************************/
RelativePathExpr::RelativePathExpr(
  const yy::location& _loc,
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


void RelativePathExpr::accept(parsenode_visitor& v) const 
{
  void* visitor_state = v.begin_visit(*this);

  if (visitor_state == NULL)
  {
    return;
  }

  // Skip this rpe if it is not the root of an rpe subtree and its left child
  // is a dot expression.
  else if (!v.is_root_rpe(this) &&
           dynamic_cast<const ContextItemExpr*>(step_expr_h.get_ptr()) != NULL)
  {
    ACCEPT (relpath_expr_h);
  }

  else
  {
    ACCEPT (step_expr_h);
    v.intermediate_visit(*this, visitor_state);
    ACCEPT (relpath_expr_h);
    END_VISITOR ();
  }
}


/*******************************************************************************

[70] StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

 [71] AxisStep ::= (ForwardStep | ReverseStep)  PredicateList?

********************************************************************************/
AxisStep::AxisStep(
    const yy::location& _loc,
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
    const yy::location& _loc,
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





void AxisStep::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  if (forward_step_h!=NULL) forward_step_h->accept(v);
  if (reverse_step_h!=NULL) reverse_step_h->accept(v);
  v.post_step_visit(*this, visitor_state);
  if (predicate_list_h!=NULL) predicate_list_h->accept(v);
  END_VISITOR ();
}


/*******************************************************************************

   [72] ForwardStep ::= ForwardAxis  NodeTest | AbbrevForwardStep

********************************************************************************/
ForwardStep::ForwardStep(
    const yy::location& _loc,
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
    const yy::location& _loc,
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





void ForwardStep::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  if (forward_axis_h!=NULL) forward_axis_h->accept(v);
  if (node_test_h!=NULL) node_test_h->accept(v);
  if (abbrev_step_h!=NULL) abbrev_step_h->accept(v);
  END_VISITOR ();
}



/*******************************************************************************

  [73] ForwardAxis ::= CHILD_AXIS | ....

********************************************************************************/
ForwardAxis::ForwardAxis(
    const yy::location& _loc,
    enum forward_axis_t _axis)
  :
  parsenode(_loc),
  axis(_axis)
{
}


ForwardAxis::~ForwardAxis()
{
}





void ForwardAxis::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [74] AbbrevForwardStep ::= NodeTest | AT_SIGN  NodeTest

********************************************************************************/
AbbrevForwardStep::AbbrevForwardStep(
    const yy::location& _loc,
    rchandle<parsenode> _node_test_h,
    bool _attr_b)
  :
  parsenode(_loc),
  node_test_h(_node_test_h),
  attr_b(_attr_b)
{
}


AbbrevForwardStep::AbbrevForwardStep(
    const yy::location& _loc,
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





void AbbrevForwardStep::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  if (node_test_h!=NULL) node_test_h->accept(v);
  END_VISITOR ();
}


/*******************************************************************************

  [75] ReverseStep ::= ReverseAxis  NodeTest |  DOT_DOT

********************************************************************************/
ReverseStep::ReverseStep(
    const yy::location& _loc,
    rchandle<ReverseAxis> _axis_h,
    rchandle<parsenode> _node_test_h)
  :
  parsenode(_loc),
  axis_h(_axis_h),
  node_test_h(_node_test_h)
{
}


ReverseStep::ReverseStep(
    const yy::location& _loc,
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





void ReverseStep::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  if (axis_h!=NULL) axis_h->accept(v);
  if (node_test_h!=NULL) node_test_h->accept(v);
  END_VISITOR ();
}


/*******************************************************************************

 [76] ReverseAxis ::= PARENT_AXIS | ....

********************************************************************************/
ReverseAxis::ReverseAxis(
    const yy::location& _loc,
    enum reverse_axis_t _axis)
  :
  parsenode(_loc),
  axis(_axis)
{
}


ReverseAxis::~ReverseAxis()
{
}





void ReverseAxis::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [77] AbbrevReverseStep ::= folded into [75]

********************************************************************************/


/*******************************************************************************

  [78] NodeTest ::= KindTest | NameTest

********************************************************************************/


/*******************************************************************************

  [79] NameTest ::= QNAME | Wildcard

********************************************************************************/
NameTest::NameTest(const yy::location& loc, rchandle<QName> qname)
  :
  parsenode(loc),
  theQName(qname),
  theWildcard(NULL)
{
}


NameTest::NameTest(const yy::location& loc, rchandle<Wildcard> wild)
  :
  parsenode(loc),
  theQName(NULL),
  theWildcard(wild)
{
}


NameTest::~NameTest()
{
}





void NameTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [80] Wildcard ::= STAR | ELEM_WILDCARD | PREFIX_WILDCARD 

********************************************************************************/
Wildcard::Wildcard(
  const yy::location& loc,
  const xqp_string& prefix,
  const xqp_string& lname,
  enum wildcard_t kind)
  :
  parsenode(loc),
  theKind(kind),
  thePrefix(prefix),
  theLocalName(lname)
{
}


Wildcard::~Wildcard()
{
}





void Wildcard::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [81] FilterExpr
// ---------------
FilterExpr::FilterExpr(
  const yy::location& _loc,
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



//-FilterExpr::

void FilterExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (primary_h);
  ACCEPT (pred_list_h);
  END_VISITOR ();
}



// [82] PredicateList
// ------------------
PredicateList::PredicateList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

PredicateList::~PredicateList()
{
}



//-PredicateList::

void PredicateList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<exprnode> >::const_reverse_iterator it = pred_hv.rbegin();
  for (; it!=pred_hv.rend(); ++it) {
    const exprnode* e_p = &**it;
    Assert(e_p!=NULL);
    v.pre_predicate_visit(*this, visitor_state);
    e_p->accept(v);
    v.post_predicate_visit(*this, visitor_state);
  }
  END_VISITOR ();
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
  const yy::location& _loc,
  int _ival)
:
  exprnode(_loc),
  type(num_integer),
  ival(_ival)
{
}

NumericLiteral::NumericLiteral(
  const yy::location& _loc,
  double _dval)
:
  exprnode(_loc),
  type(num_double),
  dval(_dval)
{
}

NumericLiteral::NumericLiteral(
  const yy::location& _loc,
  decimal _decval)
:
  exprnode(_loc),
  type(num_decimal),
  decval(_decval)
{
}

string NumericLiteral::toString () const {
  switch (type) {
  case num_integer: return to_string (ival);
  case num_decimal: return to_string (decval);
  case num_double:  return to_string (dval);
  default: return "??";
  }
}

NumericLiteral::~NumericLiteral()
{
}



//-NumericLiteral::

void NumericLiteral::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [87] VarRef
// -----------
VarRef::VarRef(
  const yy::location& _loc,
  std::string _varname)
:
  exprnode(_loc),
  varname(_varname)
{
}

VarRef::~VarRef()
{
}



//-VarRef::

void VarRef::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [88] VarName
// ------------


// [89] ParenthesizedExpr
// ----------------------
ParenthesizedExpr::ParenthesizedExpr(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

ParenthesizedExpr::~ParenthesizedExpr()
{
}



//-ParenthesizedExpr::

void ParenthesizedExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [90] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
  const yy::location& _loc)
:
  exprnode(_loc)
{
}

ContextItemExpr::~ContextItemExpr()
{
}



//-ContextItemExpr::

void ContextItemExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [91] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

OrderedExpr::~OrderedExpr()
{
}



//-OrderedExpr::

void OrderedExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [92] UnorderedExpr
// ------------------
UnorderedExpr::UnorderedExpr(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

UnorderedExpr::~UnorderedExpr()
{
}



//-UnorderedExpr::

void UnorderedExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [93] FunctionCall
// -----------------

FunctionCall::FunctionCall(
  const yy::location& _loc,
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



//-FunctionCall::

void FunctionCall::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //fname_h->accept(v);
  ACCEPT (arg_list_h);
  END_VISITOR ();
}



// [93a] ArgList
// -------------
ArgList::ArgList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

ArgList::~ArgList()
{
}



//-ArgList::

void ArgList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<exprnode> >::const_iterator it = arg_hv.begin();
  for (; it!=arg_hv.end(); ++it) {
    const exprnode* e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [94] Constructor
// ----------------

// [95] DirectConstructor
// ----------------------



// [96] DirElemConstructor
// -----------------------

DirElemConstructor::DirElemConstructor(
  const yy::location& _loc,
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
}

DirElemConstructor::~DirElemConstructor()
{
}



//-DirElemConstructor::

void DirElemConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //open_name_h->accept(v);
  //close_name_h->accept(v);

  if( attr_list_h != NULL )
      attr_list_h->accept(v);

  ACCEPT (dir_content_list_h);
  END_VISITOR ();
}



// [96a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

DirElemContentList::~DirElemContentList()
{
}



//-DirElemContentList::

void DirElemContentList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<DirElemContent> >::const_reverse_iterator it = dir_content_hv.rbegin();
  const DirElemContent* lPrev = 0;
  // To find out if a DirElemContent is boundary whitespace, the current item cannot be accepted till
  // the next item (relative to the current item) is passed to check_boundary_whitespace.
  v.begin_check_boundary_whitespace();
  for (; it!=dir_content_hv.rend(); ++it)
  {
    const DirElemContent* e_p = &**it;
    v.check_boundary_whitespace (*e_p);
    if (lPrev != 0) {
      ACCEPT_CHK(lPrev);
    }
    lPrev = e_p;
  }
  v.end_check_boundary_whitespace();
  if (lPrev != 0) {
    ACCEPT_CHK(lPrev);
  }
  END_VISITOR ();
}



// [97] DirAttributeList

DirAttributeList::DirAttributeList(
  const yy::location& loc)
:
  parsenode(loc)
{
}

DirAttributeList::~DirAttributeList()
{
}


void DirAttributeList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<DirAttr> >::const_iterator it = theAttributes.begin();
  for (; it != theAttributes.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [97a] DirAttr
  
DirAttr::DirAttr(
  const yy::location& loc,
  rchandle<QName> name,
  rchandle<DirAttributeValue> value)
:
  parsenode(loc),
  theName(name),
  theValue(value)
{
}

DirAttr::~DirAttr()
{
}

void DirAttr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT(theValue);
  END_VISITOR ();
}



// [98] DirAttributeValue

DirAttributeValue::DirAttributeValue(
  const yy::location& _loc,
  rchandle<QuoteAttrContentList> _quot_attr_content_h)
:
  parsenode(_loc),
  quot_attr_content_h(_quot_attr_content_h),
  apos_attr_content_h(NULL)
{
}

DirAttributeValue::DirAttributeValue(
  const yy::location& _loc,
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



//-DirAttributeValue::

void DirAttributeValue::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (quot_attr_content_h);
  ACCEPT (apos_attr_content_h);
  END_VISITOR ();
}




// [98a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

QuoteAttrContentList::~QuoteAttrContentList()
{
}



//-QuoteAttrContentList::

void QuoteAttrContentList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<QuoteAttrValueContent> >::const_reverse_iterator it =
    quot_atval_content_hv.rbegin();
  for (; it!=quot_atval_content_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [98b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

AposAttrContentList::~AposAttrContentList()
{
}



//-AposAttrContentList::

void AposAttrContentList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<AposAttrValueContent> >::const_reverse_iterator it =
    apos_atval_content_hv.rbegin();
  for (; it!=apos_atval_content_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [99] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent(
  const yy::location& _loc,
  std::string _quot_atcontent)
:
  parsenode(_loc),
  quot_atcontent(_quot_atcontent),
  common_content_h(NULL)
{
}

QuoteAttrValueContent::QuoteAttrValueContent(
  const yy::location& _loc,
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



//-QuoteAttrValueContent::

void QuoteAttrValueContent::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (common_content_h);
  END_VISITOR ();
}



// [100] AposAttrValueContent
// --------------------------
AposAttrValueContent::AposAttrValueContent(
  const yy::location& _loc,
  std::string _apos_atcontent)
:
  parsenode(_loc),
  apos_atcontent(_apos_atcontent),
  common_content_h(NULL)
{
}

AposAttrValueContent::AposAttrValueContent(
  const yy::location& _loc,
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



//-AposAttrValueContent::

void AposAttrValueContent::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [101] DirElemContent
// --------------------
DirElemContent::DirElemContent(
  const yy::location& _loc,
  rchandle<exprnode> _direct_cons_h)
:
  exprnode(_loc),
  direct_cons_h(_direct_cons_h)
{
}

DirElemContent::DirElemContent(
  const yy::location& _loc,
  std::string _elem_content)
:
  exprnode(_loc),
  elem_content(_elem_content)
{
}

DirElemContent::DirElemContent(
  const yy::location& _loc,
  rchandle<CDataSection> _cdata_h)
:
  exprnode(_loc),
  cdata_h(_cdata_h)
{
}

DirElemContent::DirElemContent(
  const yy::location& _loc,
  rchandle<CommonContent> _common_content_h)
:
  exprnode(_loc),
  common_content_h(_common_content_h)
{
}

DirElemContent::~DirElemContent()
{
}



//-DirElemContent::

void DirElemContent::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();

  ACCEPT (direct_cons_h);

  ACCEPT (cdata_h);
    
  ACCEPT (common_content_h);
  END_VISITOR ();
}



// [102] CommonContent
// -------------------
CommonContent::CommonContent(
  const yy::location& _loc,
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
  const yy::location& _loc,
  rchandle<EnclosedExpr> _expr_h)
:
  exprnode(_loc),
  type(cont_expr),
  ref(""),
  expr_h(_expr_h)
{
}

CommonContent::CommonContent(
  const yy::location& _loc,
  enum common_content_t _type)
:
  exprnode(_loc),
  type(_type),
  ref(""),
  expr_h(NULL)
{
}

CommonContent::~CommonContent()
{
}



//-CommonContent::

void CommonContent::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [103] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
  const yy::location& _loc,
  std::string const& _comment)
:
  exprnode(_loc),
  comment(_comment)
{  
}

DirCommentConstructor::~DirCommentConstructor()
{
}



//-DirCommentConstructor::

void DirCommentConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [104] DirCommentContents
// ------------------------
/* lexical rule */



// [105] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor(
  const yy::location& _loc,
  std::string const& _pi_target)
:
  exprnode(_loc),
  pi_target(_pi_target),
  pi_content("")
{
}

DirPIConstructor::DirPIConstructor(
  const yy::location& _loc,
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



//-DirPIConstructor::

void DirPIConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [106] DirPIContents
// -------------------
/* lexical rule */



// [107] CDataSection
// ------------------
CDataSection::CDataSection(
  const yy::location& _loc,
  std::string _cdata_content)
:
  exprnode(_loc),
  cdata_content(_cdata_content)
{
}

CDataSection::~CDataSection()
{
}



//-CDataSection::

void CDataSection::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [108] CDataSectionContents
// --------------------------
/* lexical rule */



// [109] ComputedConstructor
// -------------------------



// [110] CompDocConstructor
// ------------------------
CompDocConstructor::CompDocConstructor(
  const yy::location& _loc,
  rchandle<exprnode> _expr_h)
:
  exprnode(_loc),
  expr_h(_expr_h)
{
}

CompDocConstructor::~CompDocConstructor()
{
}


void CompDocConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [111] CompElemConstructor

CompElemConstructor::CompElemConstructor(
    const yy::location& _loc,
    rchandle<exprnode> _qname_expr_h,
    rchandle<exprnode> _content_expr_h)
  :
  exprnode(_loc),
  qname_expr_h(_qname_expr_h),
  content_expr_h(_content_expr_h)
{
}


CompElemConstructor::~CompElemConstructor()
{
}


void CompElemConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR();
  if (dynamic_cast<QName*>(qname_expr_h.get_ptr()) == NULL)
    ACCEPT(qname_expr_h);
  ACCEPT(content_expr_h);
  END_VISITOR();
}


// [113] CompAttrConstructor

CompAttrConstructor::CompAttrConstructor(
    const yy::location& _loc,
    rchandle<exprnode> _qname_expr_h,
    rchandle<exprnode> _val_expr_h)
  :
  exprnode(_loc),
  qname_expr_h(_qname_expr_h),
  val_expr_h(_val_expr_h)
{
}


CompAttrConstructor::~CompAttrConstructor()
{
}


void CompAttrConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR();
  if (dynamic_cast<QName*>(qname_expr_h.get_ptr()) == NULL)
    ACCEPT(qname_expr_h);
  ACCEPT(val_expr_h);
  END_VISITOR();
}



// [114] CompTextConstructor

CompTextConstructor::CompTextConstructor(
  const yy::location& _loc,
  rchandle<exprnode> _text_expr_h)
:
  exprnode(_loc),
  text_expr_h(_text_expr_h)
{
}

CompTextConstructor::~CompTextConstructor()
{
}


void CompTextConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (text_expr_h);
  END_VISITOR ();
}



// [115] CompCommentConstructor

CompCommentConstructor::CompCommentConstructor(
  const yy::location& _loc,
  rchandle<exprnode> _comment_expr_h)
:
  exprnode(_loc),
  comment_expr_h(_comment_expr_h)
{
}

CompCommentConstructor::~CompCommentConstructor()
{
}



//-CompCommentConstructor::

void CompCommentConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (comment_expr_h);
  END_VISITOR ();
}



// [116] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
  const yy::location& _loc,
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
  const yy::location& _loc,
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



//-CompPIConstructor::

void CompPIConstructor::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (content_expr_h);
  ACCEPT (target_expr_h);
  END_VISITOR ();
}



// [117] SingleType
// ----------------
SingleType::SingleType(
  const yy::location& _loc,
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



//-SingleType::

void SingleType::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (atomic_type_h);
  END_VISITOR ();
}



// [116] TypeDeclaration
// ---------------------
TypeDeclaration::TypeDeclaration(
  const yy::location& _loc,
  rchandle<SequenceType> _seqtype_h)
:
  parsenode(_loc),
  seqtype_h(_seqtype_h)
{
}

TypeDeclaration::~TypeDeclaration()
{
}



//-TypeDeclaration::

void TypeDeclaration::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (seqtype_h);
  END_VISITOR ();
}



// [119] SequenceType
// ------------------
SequenceType::SequenceType(
  const yy::location& _loc,
  rchandle<parsenode> _itemtype_h,
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



//-SequenceType::

void SequenceType::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (itemtype_h);
  ACCEPT (occur_h);
  END_VISITOR ();
}



// [120] OccurrenceIndicator
// -------------------------
OccurrenceIndicator::OccurrenceIndicator(
  const yy::location& _loc,
  enum occurrence_t _type)
:
  parsenode(_loc),
  type(_type)
{
}

OccurrenceIndicator::~OccurrenceIndicator()
{
}



//-OccurrenceIndicator::

void OccurrenceIndicator::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [121] ItemType
// --------------
ItemType::ItemType(
  const yy::location& _loc,
  bool _item_test_b)
:
  parsenode(_loc),
  item_test_b(_item_test_b)
{
}

ItemType::ItemType(
  const yy::location& _loc)
:
  parsenode(_loc),
  item_test_b(false)
{
}

ItemType::~ItemType()
{
}



//-ItemType::

void ItemType::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [122] AtomicType
// ----------------
AtomicType::AtomicType(
  const yy::location& _loc,
  rchandle<QName> _qname_h)
:
  parsenode(_loc),
  qname_h(_qname_h)
{
}

AtomicType::~AtomicType()
{
}



//-AtomicType::

void AtomicType::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //qname_h->accept(v);
  END_VISITOR ();
}



// [123] KindTest
// --------------



// [124] AnyKindTest
// -----------------
AnyKindTest::AnyKindTest(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

AnyKindTest::~AnyKindTest()
{
}



//-AnyKindTest::

void AnyKindTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [125] DocumentTest
// ------------------
DocumentTest::DocumentTest(
  const yy::location& _loc)
:
  parsenode(_loc),
  elem_test_h(NULL),
  schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
  const yy::location& _loc,
  rchandle<ElementTest> _elem_test_h)
:
  parsenode(_loc),
  elem_test_h(_elem_test_h),
  schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
  const yy::location& _loc,
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



//-DocumentTest::

void DocumentTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [126] TextTest
// --------------
TextTest::TextTest(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

TextTest::~TextTest()
{
}



//-TextTest::

void TextTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [127] CommentTest
// -----------------
CommentTest::CommentTest(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

CommentTest::~CommentTest()
{
}



//-CommentTest::

void CommentTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}

 

// [128] PITest

PITest::PITest(
  const yy::location& _loc,
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

void PITest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [129] AttributeTest

AttributeTest::AttributeTest(
  const yy::location& loc,
  rchandle<QName> attrName,
  rchandle<TypeName> typeName)
  :
  parsenode(loc),
  theAttrName(attrName),
  theTypeName(typeName)
{
}

AttributeTest::~AttributeTest()
{
}


void AttributeTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR();
  END_VISITOR();
}


// [130] AttribNameOrWildcard



// [131] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
  const yy::location& _loc,
  rchandle<QName> _attr_h)
:
  parsenode(_loc),
  attr_h(_attr_h)
{
}

SchemaAttributeTest::~SchemaAttributeTest()
{
}



//-SchemaAttributeTest::

void SchemaAttributeTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //if (attr_h!=NULL) attr_h->accept(v);
  END_VISITOR ();
}


/*******************************************************************************

  [133] ElementTest ::= ELEMENT_LPAR  RPAR |
                        ELEMENT_LPAR  ElementNameOrWildcard  RPAR |
                        ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  RPAR |
                        ELEMENT_LPAR  ElementNameOrWildcard  COMMA  TypeName  HOOK  RPAR

********************************************************************************/
ElementTest::ElementTest(
    const yy::location& loc,
    rchandle<QName> ename,
    rchandle<TypeName> tname,
    bool na)
  :
  parsenode(loc),
  theElementName(ename),
  theTypeName(tname),
  theNilledAllowed(na)
{
}

ElementTest::~ElementTest()
{
}


void ElementTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [135] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
  const yy::location& _loc,
  rchandle<QName> _elem_h)
:
  parsenode(_loc),
  elem_h(_elem_h)
{
}

SchemaElementTest::~SchemaElementTest()
{
}



//-SchemaElementTest::

void SchemaElementTest::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //if (elem_h!=NULL) elem_h->accept(v);
  END_VISITOR ();
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
  const yy::location& _loc,
  rchandle<QName> _qname_h)
:
  parsenode(_loc),
  qname_h(_qname_h),
  optional_b(false)
{
}

TypeName::TypeName(
  const yy::location& _loc,
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



//-TypeName::

void TypeName::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //if (qname_h!=NULL) qname_h->accept(v);
  END_VISITOR ();
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
  const yy::location& _loc,
  string const& _strval)
:
  exprnode(_loc),
  strval(_strval)
{
}

StringLiteral::~StringLiteral()
{
}



//-StringLiteral::

void StringLiteral::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
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
  qname(_qname)
{
}

QName::~QName()
{
}

string QName::get_localname() const
{
  string::size_type n = qname.find(':');
  return (n != string::npos ? qname.substr(n+1) : qname);
}

string QName::get_prefix() const
{
  string::size_type n = qname.find(':');
  return (n != string::npos ? qname.substr(0,n) : "");
}



//-QName::

void QName::accept(parsenode_visitor& v) const 
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}





/*
**
**  Update productions
**  [http:://www.w3.org/TR/xqupdate/]
**
*/

// [241]  RevalidationDecl
// -----------------------
RevalidationDecl::RevalidationDecl(
  const yy::location& _loc,
  rchandle<QName> _qname_h)
:
  parsenode(_loc),
  qname_h(_qname_h)
{
}

RevalidationDecl::~RevalidationDecl()
{
}



//-RevalidationDecl::

void RevalidationDecl::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  //qname_h->accept(v);
  END_VISITOR ();
}



// [242]  InsertExpr
// ----------------
InsertExpr::InsertExpr(
  const yy::location& _loc,
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



//-InsertExpr::

void InsertExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
  const yy::location& _loc,
  rchandle<exprnode> _target_expr_h)
:
  exprnode(_loc),
  target_expr_h(_target_expr_h)
{
}

DeleteExpr::~DeleteExpr()
{
}



//-DeleteExpr::

void DeleteExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (target_expr_h);
  END_VISITOR ();
}



// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
  const yy::location& _loc,
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



//-ReplaceExpr::

void ReplaceExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (source_expr_h);
  ACCEPT (target_expr_h);
  END_VISITOR ();
}



// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
  const yy::location& _loc,
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



//-RenameExpr::

void RenameExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (source_expr_h);
  ACCEPT (target_expr_h);
  END_VISITOR ();
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
  const yy::location& _loc,
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



//-TransformExpr::

void TransformExpr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (varname_list_h);
  ACCEPT (source_expr_h);
  ACCEPT (target_expr_h);
  END_VISITOR ();
}



// [249a] VarNameList
// ------------------
VarNameList::VarNameList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

VarNameList::~VarNameList()
{
}



//-VarNameList::

void VarNameList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<VarBinding> >::const_reverse_iterator it = varbinding_hv.rbegin();
  for (; it!=varbinding_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
  const yy::location& _loc,
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



//-VarBinding::

void VarBinding::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (val_h);
  END_VISITOR ();
}






/*
 *
 *  Full-text productions
 *  [http://www.w3.org/TR/xquery-full-text/]
 *
 */

// [344] FTSelection
// -----------------
FTSelection::FTSelection(
  const yy::location& _loc,
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



//-FTSelection::

void FTSelection::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (ftor_h);
  ACCEPT (option_list_h);
  ACCEPT (weight_expr_h);
  END_VISITOR ();
}



// [344a] FTMatchOptionProximityList
// ---------------------------------
FTMatchOptionProximityList::FTMatchOptionProximityList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTMatchOptionProximityList::~FTMatchOptionProximityList()
{
}



//-FTMatchOptionProximityList::

void FTMatchOptionProximityList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<FTMatchOptionProximity> >::const_reverse_iterator it =
    opt_prox_hv.rbegin();
  for (; it!=opt_prox_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [344b] FTMatchOptionProximity
// -----------------------------
FTMatchOptionProximity::FTMatchOptionProximity(
  rchandle<FTMatchOption> _opt_h,
  const yy::location& _loc)
:
  parsenode(_loc),
  opt_h(_opt_h),
  prox_h(NULL)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
  rchandle<FTProximity> _prox_h,
  const yy::location& _loc)
:
  parsenode(_loc),
  opt_h(NULL),
  prox_h(_prox_h)
{
}

FTMatchOptionProximity::FTMatchOptionProximity(
  const yy::location& _loc)
:
  parsenode(_loc),
  opt_h(NULL),
  prox_h(NULL)
{
}

FTMatchOptionProximity::~FTMatchOptionProximity()
{
}



//-FTMatchOptionProximity::

void FTMatchOptionProximity::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (opt_h);
  END_VISITOR ();
}



// [345] FTOr
// ----------
FTOr::FTOr(
  const yy::location& _loc,
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



//-FTOr::

void FTOr::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (ftor_h);
  ACCEPT (ftand_h);
  END_VISITOR ();
}



// [346] FTAnd
// -----------
FTAnd::FTAnd(
  const yy::location& _loc,
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



//-FTAnd::

void FTAnd::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (ftand_h);
  ACCEPT (ftmild_not_h);
  END_VISITOR ();
}



// [347] FTMildnot
// ---------------
FTMildnot::FTMildnot(
  const yy::location& _loc,
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



//-FTMildnot::

void FTMildnot::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (ftmild_not_h);
  ACCEPT (ftunary_not_h);
  END_VISITOR ();
}



// [348] FTUnaryNot
// ----------------
FTUnaryNot::FTUnaryNot(
  const yy::location& _loc,
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



//-FTUnaryNot::

void FTUnaryNot::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (words_selection_h);
  END_VISITOR ();
}



// [349] FTWordsSelection
// ----------------------
FTWordsSelection::FTWordsSelection(
  const yy::location& _loc,
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



//-FTWordsSelection::

void FTWordsSelection::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (words_h);
  ACCEPT (times_h);
  ACCEPT (selection_h);
  END_VISITOR ();
}



// [350] FTWords
// -------------
FTWords::FTWords(
  const yy::location& _loc,
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



//-FTWords::

void FTWords::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (words_val_h);
  ACCEPT (any_all_option_h);
  END_VISITOR ();
}



// [351] FTWordsValue
// ------------------
FTWordsValue::FTWordsValue(
  const yy::location& _loc,
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



//-FTWordsValue::

void FTWordsValue::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (lit_h);
  ACCEPT (expr_h);
  END_VISITOR ();
}



// [352] FTProximity
// -----------------
FTProximity::FTProximity(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTProximity::~FTProximity()
{
}



//-FTProximity::

void FTProximity::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [353] FTOrderedIndicator
// ------------------------
FTOrderedIndicator::FTOrderedIndicator(
  const yy::location& _loc)
:
  FTProximity(_loc)
{
}

FTOrderedIndicator::~FTOrderedIndicator()
{
}



//-FTOrderedIndicator::

void FTOrderedIndicator::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [354] FTMatchOption  
// -------------------
FTMatchOption::FTMatchOption(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTMatchOption::~FTMatchOption()
{
}



//-FTMatchOption::

void FTMatchOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [355] FTCaseOption
// ------------------
FTCaseOption::FTCaseOption(
  const yy::location& _loc,
  ft_case_mode_t _mode)
:
  FTMatchOption(_loc),
  mode(_mode)
{
}

FTCaseOption::~FTCaseOption()
{
}



//-FTCaseOption::

void FTCaseOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [356] FTDiacriticsOption
// ------------------------
FTDiacriticsOption::FTDiacriticsOption(
  const yy::location& _loc,
  ft_diacritics_mode_t _mode)
:
  FTMatchOption(_loc),
  mode(_mode)
{
}

FTDiacriticsOption::~FTDiacriticsOption()
{
}



//-FTDiacriticsOption::

void FTDiacriticsOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [357] FTStemOption
// ------------------
FTStemOption::FTStemOption(
  const yy::location& _loc,
  ft_stem_mode_t _mode)
:
  FTMatchOption(_loc),
  mode(_mode)
{
}

FTStemOption::~FTStemOption()
{
}



//-FTStemOption::

void FTStemOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [358] FTThesaurusOption
// -----------------------
FTThesaurusOption::FTThesaurusOption(
  const yy::location& _loc,
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



//-FTThesaurusOption::

void FTThesaurusOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (thesaurusid_h);
  ACCEPT (thesaurus_list_h);
  END_VISITOR ();
}



// [358a] FTThesaurusList
// ----------------------
FTThesaurusList::FTThesaurusList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTThesaurusList::~FTThesaurusList()
{
}



//-FTThesaurusList::

void FTThesaurusList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<FTThesaurusID> >::const_reverse_iterator it = thesaurus_hv.rbegin();
  for (; it!=thesaurus_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [359] FTThesaurusID
// -------------------
FTThesaurusID::FTThesaurusID(
  const yy::location& _loc,
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



//-FTThesaurusID::

void FTThesaurusID::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (levels_h);
  END_VISITOR ();
}



// [360] FTStopwordOption
// ----------------------
FTStopwordOption::FTStopwordOption(
  const yy::location& _loc,
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



//-FTStopwordOption::

void FTStopwordOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (refor_list_h);
  ACCEPT (incl_excl_list_h);
  END_VISITOR ();
}



// [360a] FTInclExclStringLiteralList
// ----------------------------------
FTInclExclStringLiteralList::FTInclExclStringLiteralList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTInclExclStringLiteralList::~FTInclExclStringLiteralList()
{
}



//-FTInclExclStringLiteralList::

void FTInclExclStringLiteralList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<rchandle<FTInclExclStringLiteral> >::const_reverse_iterator it =
    incl_excl_lit_hv.rbegin();
  for (; it!=incl_excl_lit_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}



// [361] FTRefOrList
// -----------------
FTRefOrList::FTRefOrList(
  const yy::location& _loc,
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



//-FTRefOrList::

void FTRefOrList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (stringlit_list_h);
  END_VISITOR ();
}



// [361a] FTStringLiteralList
// --------------------------
FTStringLiteralList::FTStringLiteralList(
  const yy::location& _loc)
:
  parsenode(_loc)
{
}

FTStringLiteralList::~FTStringLiteralList()
{
}



//-FTStringLiteralList::

void FTStringLiteralList::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  vector<string>::const_reverse_iterator it = strlit_v.rbegin();
  for (; it!=strlit_v.rend(); ++it) {
    // ..do something useful..
  }
  END_VISITOR ();
}



// [362] FTInclExclStringLiteral
// -----------------------------
FTInclExclStringLiteral::FTInclExclStringLiteral(
  const yy::location& _loc,
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



//-FTInclExclStringLiteral::

void FTInclExclStringLiteral::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (ref_or_list_h);
  END_VISITOR ();
}



// [363] FTLanguageOption
// ----------------------
FTLanguageOption::FTLanguageOption(
  const yy::location& _loc,
  std::string _lang)
:
  FTMatchOption(_loc),
  lang(_lang)
{
}

FTLanguageOption::~FTLanguageOption()
{
}



//-FTLanguageOption::

void FTLanguageOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [364] FTWildcardOption
// ----------------------
FTWildcardOption::FTWildcardOption(
  const yy::location& _loc,
  bool _with_b)
:
  FTMatchOption(_loc),
  with_b(_with_b)
{
}

FTWildcardOption::~FTWildcardOption()
{
}



//-FTWildcardOption::

void FTWildcardOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [365]  FTContent
// ---------------
FTContent::FTContent(
  const yy::location& _loc,
  ft_content_mode_t _mode)
:
  FTProximity(_loc),
  mode(_mode)
{
}

FTContent::~FTContent()
{
}



//-FTContent::

void FTContent::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [366]  FTAnyallOption
// --------------------
FTAnyallOption::FTAnyallOption(
  const yy::location& _loc,
  ft_anyall_option_t _option)
:
  parsenode(_loc),
  option(_option)
{
}

FTAnyallOption::~FTAnyallOption()
{
}



//-FTAnyallOption::

void FTAnyallOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [367] FTRange
// -------------
FTRange::FTRange(
  const yy::location& _loc,
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



//-FTRange::

void FTRange::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (src_expr_h);
  ACCEPT (dst_expr_h);
  END_VISITOR ();
}



// [368] FTDistance
// ----------------
FTDistance::FTDistance(
  const yy::location& _loc,
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



//-FTDistance::

void FTDistance::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (dist_h);
  ACCEPT (unit_h);
  END_VISITOR ();
}



// [369] FTWindow
// --------------
FTWindow::FTWindow(
  const yy::location& _loc,
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



//-FTWindow::

void FTWindow::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (window_h);
  ACCEPT (unit_h);
  END_VISITOR ();
}



// [370] FTTimes
// -------------
FTTimes::FTTimes(
  const yy::location& _loc,
  rchandle<FTRange> _range_h)
:
  parsenode(_loc),
  range_h(_range_h)
{
}

FTTimes::~FTTimes()
{
}



//-FTTimes::

void FTTimes::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (range_h);
  END_VISITOR ();
}



// [371] FTScope
// -------------
FTScope::FTScope(
  const yy::location& _loc,
  ft_scope_t _scope)
:
  FTProximity(_loc),
  scope(_scope)
{
}

FTScope::~FTScope()
{
}



//-FTScope::

void FTScope::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [372] FTUnit
// ------------
FTUnit::FTUnit(
  const yy::location& _loc,
  ft_unit_t _unit)
:
  parsenode(_loc),
  unit(_unit)
{
}

FTUnit::~FTUnit()
{
}



//-FTUnit::

void FTUnit::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [373] FTBigUnit
// ---------------
FTBigUnit::FTBigUnit(
  const yy::location& _loc,
  enum ft_big_unit_t _unit)
:
  parsenode(_loc),
  unit(_unit)
{
}

FTBigUnit::~FTBigUnit()
{
}



//-FTBigUnit::

void FTBigUnit::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [374] FTIgnoreOption
// --------------------
FTIgnoreOption::FTIgnoreOption(
  const yy::location& _loc,
  rchandle<UnionExpr> _union_h)
:
  parsenode(_loc),
  union_h(_union_h)
{
}

FTIgnoreOption::~FTIgnoreOption()
{
}



//-FTIgnoreOption::

void FTIgnoreOption::accept(parsenode_visitor& v) const 
{ 
  BEGIN_VISITOR ();
  ACCEPT (union_h);
  END_VISITOR ();
}



} /* namespace xqp */


