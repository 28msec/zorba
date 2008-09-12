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

#include "store/api/item.h"


#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "context/static_context_consts.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>
#include <algorithm>

#include "compiler/parsetree/parsenode_visitor.h"
#include "util/tracer.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"
#include "types/typemanager.h"


using namespace std;
namespace zorba {

int dummy;
void *parsenode_visitor::no_state = (void *) &dummy;

int printdepth = 0;
ostringstream __oss;

#define INDENT      std::string(++printdepth, ' ')
#define OUTDENT     std::string(printdepth--, ' ')
#define UNDENT      printdepth--

#define BEGIN_VISITOR() void *visitor_state; if (NULL == (visitor_state = v.begin_visit (*this))) return
#define END_VISITOR() v.end_visit (*this, visitor_state)
#define ACCEPT( m ) do { if ((m) != NULL) (m)->accept (v); } while (0)
#define ACCEPT_CHK( m ) do { ZORBA_ASSERT ((m) != NULL);  (m)->accept (v); } while (0)


#define DECLARE_VISITOR_FUNCTOR( name, type, body)                      \
  class name : public unary_function<rchandle<parsenode>, void> {       \
    parsenode_visitor &v;                                               \
  public:                                                               \
  name (parsenode_visitor &v_) : v (v_) {}                              \
  void operator () (type e) body                                        \
    }


DECLARE_VISITOR_FUNCTOR(visitor_functor, rchandle<parsenode>, { ACCEPT(e); });


// [1] Module
// ----------
//-Module::

void Module::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [2] VersionDecl
// ---------------
VersionDecl::VersionDecl(
  const QueryLoc& loc_,
  std::string const& _version,
  std::string const& _encoding)
:
  parsenode(loc_),
  version(_version),
  encoding(_encoding)
{}


//-VersionDecl::

void VersionDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [3] MainModule
// --------------
MainModule::MainModule(
  const QueryLoc& loc_,
  rchandle<QueryBody> _query_body_h,
  rchandle<Prolog> _prolog_h,
  rchandle<VersionDecl> _ver)
:
  Module(loc_, _ver),
  prolog_h(_prolog_h),
  query_body_h(_query_body_h)  
{}


//-MainModule::

void MainModule::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (version_decl_h);
  ACCEPT (prolog_h);
  ACCEPT (query_body_h);
  END_VISITOR ();
}


// [4] LibraryModule
// -----------------
LibraryModule::LibraryModule(
  const QueryLoc& loc_,
  rchandle<ModuleDecl> _decl_h,
  rchandle<Prolog> _prolog_h,
  rchandle<VersionDecl> _ver)
:
  Module(loc_, _ver),
  decl_h(_decl_h),
  prolog_h(_prolog_h)
{}


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
  const QueryLoc& loc_,
  std::string const& _prefix,
  std::string const& _target_namespace)
:
  parsenode(loc_),
  prefix(_prefix),
  target_namespace(_target_namespace)
{}


//-ModuleDecl::

void ModuleDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [6] Prolog
// ----------
Prolog::Prolog(
  const QueryLoc& loc_,
  rchandle<SIND_DeclList> _sind_list_h,
  rchandle<VFO_DeclList> _vfo_list_h)
:
  parsenode(loc_),
  sind_list_h(_sind_list_h),
  vfo_list_h(_vfo_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-SIND_DeclList::

void SIND_DeclList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();

  for (vector<rchandle<parsenode> >::const_iterator it = sind_hv.begin();
       it!=sind_hv.end(); ++it)
  {
    ACCEPT_CHK ((*it));
  }
  END_VISITOR ();
}


// [6b] VFO_DeclList
// -----------------
VFO_DeclList::VFO_DeclList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc,
  std::string const& prefix,
  std::string const& uri)
:
  parsenode(loc),
  thePrefix(prefix),
  theUri(uri)
{}


void NamespaceDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [11] BoundarySpaceDecl
// ----------------------
BoundarySpaceDecl::BoundarySpaceDecl(
  const QueryLoc& loc_,
  StaticContextConsts::boundary_space_mode_t _mode)
:
  parsenode(loc_),
  mode(_mode)
{}


//-BoundarySpaceDecl::

void BoundarySpaceDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [12] DefaultNamespaceDecl
// -------------------------
DefaultNamespaceDecl::DefaultNamespaceDecl(
  const QueryLoc& loc_,
  enum ParseConstants::default_namespace_mode_t _mode,
  std::string const& _default_namespace)
:
  parsenode(loc_),
  mode(_mode),
  default_namespace(_default_namespace)
{}


//-DefaultNamespaceDecl::

void DefaultNamespaceDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [13] OptionDecl
// ---------------
OptionDecl::OptionDecl(
  const QueryLoc& loc_,
  rchandle<QName> _qname_h,
  std::string const& _val)
:
  parsenode(loc_),
  qname_h(_qname_h),
  val(_val)
{}


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
  const QueryLoc& loc_,
  rchandle<parsenode> _match_option_h)
:
  parsenode(loc_),
  match_option_h(_match_option_h)
{}


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
  const QueryLoc& loc_,
  StaticContextConsts::ordering_mode_t _mode)
:
  parsenode(loc_),
  mode(_mode)
{}


//-OrderingModeDecl::

void OrderingModeDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [15] EmptyOrderDecl
// -------------------
EmptyOrderDecl::EmptyOrderDecl(
  const QueryLoc& loc_,
  StaticContextConsts::order_empty_mode_t _mode)
:
  parsenode(loc_),
  mode(_mode)
{}


//-EmptyOrderDecl::

void EmptyOrderDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [16] CopyNamespacesDecl
// -----------------------
CopyNamespacesDecl::CopyNamespacesDecl(
  const QueryLoc& loc_,
  StaticContextConsts::preserve_mode_t _preserve_mode,
  StaticContextConsts::inherit_mode_t  _inherit_mode)
:
  parsenode(loc_),
  preserve_mode(_preserve_mode),
  inherit_mode(_inherit_mode)
{}


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
  const QueryLoc& loc_,
  std::string const&  _collation)
:
  parsenode(loc_),
  collation(_collation)
{}


//-DefaultCollationDecl::

void DefaultCollationDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [20] BaseURIDecl
// ----------------
BaseURIDecl::BaseURIDecl(
  const QueryLoc& loc_,
  std::string const& _base_uri)
:
  parsenode(loc_),
  base_uri(_base_uri)
{}


//-BaseURIDecl::

void BaseURIDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [21] SchemaImport
// -----------------
SchemaImport::SchemaImport(
  const QueryLoc& loc_,
  rchandle<SchemaPrefix> _prefix_h,
  std::string const& _uri,
  rchandle<URILiteralList> _at_list_h)
:
  parsenode(loc_),
  prefix_h(_prefix_h),
  uri(_uri),
  at_list_h(_at_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-URILiteralList::

void URILiteralList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
#if 0
  vector<string>::const_reverse_iterator it = uri_v.rbegin();
  for (; it!=uri_v.rend(); ++it) {
    // ..do something useful
  }
#endif
  END_VISITOR ();
}


// [22] SchemaPrefix
// -----------------
SchemaPrefix::SchemaPrefix(
  const QueryLoc& loc_,
  bool _default_b)
:
  parsenode(loc_),
  prefix(""),
  default_b(_default_b)
{}

SchemaPrefix::SchemaPrefix(
  const QueryLoc& loc_,
  std::string const& _prefix)
:
  parsenode(loc_),
  prefix(_prefix),
  default_b(false)
{}


//-SchemaPrefix::

void SchemaPrefix::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [23] ModuleImport
// -----------------
ModuleImport::ModuleImport(
  const QueryLoc& loc_,
  std::string const& _uri,
  rchandle<URILiteralList> _uri_list_h)
:
  parsenode(loc_),
  uri (_uri),
  uri_list_h(_uri_list_h)
{}

ModuleImport::ModuleImport(
  const QueryLoc& loc_,
  std::string const& _prefix,
  std::string const& _uri,
  rchandle<URILiteralList> _uri_list_h)
:
  parsenode(loc_),
  prefix(_prefix),
  uri(_uri),
  uri_list_h(_uri_list_h)
{}


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
  const QueryLoc& loc_,
  std::string _varname,
  rchandle<TypeDeclaration> _typedecl_h,
  rchandle<exprnode> _initexpr_h)
:
  VarDeclWithInit (loc_, _varname, _typedecl_h, _initexpr_h)
{}


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
  const QueryLoc& loc_,
  StaticContextConsts::construction_mode_t _mode)
:
  parsenode(loc_),
  mode(_mode)
{}


//-ConstructionDecl::

void ConstructionDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [26] FunctionDecl
// -----------------
FunctionDecl::FunctionDecl(
  const QueryLoc& loc_,
  rchandle<QName> _name_h,
  rchandle<ParamList> _paramlist_h,
  rchandle<SequenceType> _return_type_h,
  rchandle<exprnode> _body_h,
  enum ParseConstants::function_type_t _type)
:
  parsenode(loc_),
  type(_type),
  name_h(_name_h),
  paramlist_h(_paramlist_h),
  body_h(_body_h),
  return_type_h(_return_type_h)
{}


//-FunctionDecl::

void FunctionDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (paramlist_h);
  ACCEPT (return_type_h);
  ACCEPT (body_h);
  END_VISITOR ();
}


int FunctionDecl::get_param_count() const {
  return paramlist_h == NULL ? 0 : paramlist_h->size ();
}

// [27] ParamList
// --------------
ParamList::ParamList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-ParamList::

void ParamList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();

  for (vector<rchandle<Param> >::const_iterator it = param_hv.begin();
       it!=param_hv.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}


// [28] Param
// ----------
Param::Param(
  const QueryLoc& loc_,
  std::string _name,
  rchandle<TypeDeclaration> _typedecl_h)
:
  parsenode(loc_),
  name(_name),
  typedecl_h(_typedecl_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


//-EnclosedExpr::

void EnclosedExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


void BlockBody::accept (parsenode_visitor& v) const {
  BEGIN_VISITOR ();
  for (int i = 0; i < size (); i++)
    (*this) [i]->accept (v);
  END_VISITOR ();
}


// [30] QueryBody
// --------------
QueryBody::QueryBody(
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_)
:
  exprnode(loc_)
{}


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


//-FLWORExpr::

  FLWORExpr::FLWORExpr(const QueryLoc& loc_, rchandle<FLWORClauseList> clauses_, rchandle<exprnode> ret_, bool force_general)
    : exprnode (loc_), clauses (clauses_), return_val_h (ret_)
  {
    for (unsigned i = 0; i < clauses->size (); i++) {
      {
        GroupByClause *c = dynamic_cast<GroupByClause *> ((*clauses) [i].getp ());
        if (c != NULL)
          c->set_flwor (this);
      }
      {
        OrderByClause *c = dynamic_cast<OrderByClause *> ((*clauses) [i].getp ());
        if (c != NULL)
          c->set_flwor (this);
      }
    }
    general = force_general ? true : compute_general ();
  }

void FLWORExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (clauses);
  ACCEPT (return_val_h);
  END_VISITOR ();
}

template<class T> void get_flwor_clause (const FLWORExpr &f, T **p) {
  *p = NULL;
  rchandle<FLWORClauseList> clauses = f.get_clause_list ();
  for (unsigned i = 0; i < clauses->size (); i++) {
    FLWORClause* cp = (*clauses) [i].getp ();
    *p = dynamic_cast<T *> (cp);
    if (*p != NULL) return;
  }
}

#define DEF_FLWOR_GETTER( T, name )             \
  T *FLWORExpr::get_##name () const {           \
    T *p;                                       \
    get_flwor_clause (*this, &p);               \
    return p;                                   \
  }

DEF_FLWOR_GETTER (GroupByClause, groupby)
DEF_FLWOR_GETTER (OrderByClause, orderby)
DEF_FLWOR_GETTER (WhereClause, where)

void FLWORWinCond::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (get_winvars ());
  ACCEPT (get_val ());
  END_VISITOR ();
}

bool FLWORExpr::compute_general () const {
#ifdef ZORBA_FORCE_GFLWOR
  return true;
#endif

  bool has_where = false, has_order = false, has_group = false;
  for (unsigned i = 0; i < clauses->size (); i++) {
    const FLWORClause* cp = (*clauses) [i].getp ();
    if (dynamic_cast<const FLWORInitialClause *> (cp) != NULL) {
      // any preceding non-initial clause triggers GFLWOR
      if (has_group || has_where || has_order)
        return true;

      if (typeid (*cp) == typeid (ForClause)) {
        if (static_cast<const ForClause *> (cp)->is_outer ())
          return true;
      } else if (typeid (*cp) == typeid (WindowClause)) {
        return true;
      }
    } else if (typeid (*cp) == typeid (WhereClause)) {
      if (has_where || has_group) return true;
      has_where = true;
    } else if (typeid (*cp) == typeid (OrderByClause)) {
      if (has_order) return true;
      has_order = true;
    } else if (typeid (*cp) == typeid (GroupByClause)) {
      if (has_group || has_order) return true;
      has_group = true;
    } else if (typeid (*cp) == typeid (CountClause))
      return true;
  }
  return false;
}

void WindowVarDecl::accept(parsenode_visitor& v) const {
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  ACCEPT (get_valexpr ());
  END_VISITOR ();
}

void WindowClause::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  for (int i = 0; i < 2; i++)
    ACCEPT (conditions [i]);
  ACCEPT (var);
  END_VISITOR ();
}

void WindowVars::accept(parsenode_visitor& v) const {
  BEGIN_VISITOR ();
  ACCEPT (posvar);
  END_VISITOR ();
}

// [33a] FLWORClauseList
// ----------------------
FLWORClauseList::FLWORClauseList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-FLWORClauseList::

void FLWORClauseList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  vector<rchandle<FLWORClause> >::const_iterator it = forlet_hv.begin();
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
  const QueryLoc& loc_,
  rchandle<VarInDeclList> _vardecl_list_h,
  bool outer_)
:
  ForOrLetClause(loc_),
  vardecl_list_h(_vardecl_list_h),
  outer (outer_)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  std::string _varname,
  rchandle<TypeDeclaration> _typedecl_h,
  rchandle<PositionalVar> _posvar_h,
  rchandle<FTScoreVar> _ftscorevar_h,
  rchandle<exprnode> _valexpr_h)
:
  VarDeclWithInit (loc_, _varname, _typedecl_h, _valexpr_h),
  posvar_h(_posvar_h),
  ftscorevar_h(_ftscorevar_h)
{}


//-VarInDecl::

void VarInDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  ACCEPT (posvar_h);
  ACCEPT (ftscorevar_h);
  ACCEPT (get_valexpr ());
  END_VISITOR ();
}


// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
  const QueryLoc& loc_,
  std::string const& _varname)
:
  parsenode(loc_),
  varname(_varname)
{}


//-PositionalVar::

void PositionalVar::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [36] LetClause
// --------------
LetClause::LetClause(
  const QueryLoc& loc_,
  rchandle<VarGetsDeclList> _vardecl_list_h)
:
  ForOrLetClause(loc_),
  vardecl_list_h(_vardecl_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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

//-VarGetsDecl::

void VarGetsDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (typedecl_h);
  ACCEPT (ftscorevar_h);
  ACCEPT (get_valexpr ());
  END_VISITOR ();
}


// [36c] FTScoreVar
// ----------------
FTScoreVar::FTScoreVar(
  const QueryLoc& loc_,
  std::string _varname)
:
  parsenode(loc_),
  varname(_varname)
{}


//-FTScoreVar::

void FTScoreVar::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [37] WhereClause
// ----------------
WhereClause::WhereClause(
  const QueryLoc& loc_,
  rchandle<exprnode> _predicate_h)
:
  FLWORClause(loc_),
  predicate_h(_predicate_h)
{}


//-WhereClause::

void WhereClause::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (predicate_h);
  END_VISITOR ();
}


void CountClause::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}

GroupByClause::GroupByClause(
  const QueryLoc& loc_,
  rchandle<GroupSpecList> _spec_list_h,
  rchandle<LetClauseList> _let_h,
  rchandle<WhereClause> _where_h)
:
  FLWORClause(loc_),
  spec_list_h(_spec_list_h),
  let_h(_let_h),
  where_h(_where_h)
{}

void GroupByClause::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (spec_list_h);
//  ACCEPT (let_h);
  ACCEPT (where_h);
  END_VISITOR ();
}

GroupSpecList::GroupSpecList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}

void GroupSpecList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  vector<rchandle<GroupSpec> >::const_iterator it = spec_hv.begin();
  for (; it!=spec_hv.end(); ++it) {
    const GroupSpec *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}

GroupSpec::GroupSpec(
  const QueryLoc& loc_,
  std::string _var_name_h,
  rchandle<GroupCollationSpec> _group_coll_spec_h)
:
  parsenode(loc_),
  var_name_h(_var_name_h),
  group_coll_spec_h(_group_coll_spec_h)
{}

void GroupSpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (group_coll_spec_h);
  END_VISITOR ();
}

GroupCollationSpec::GroupCollationSpec (
  const QueryLoc& loc_,
  const std::string& _uri)
:
  parsenode(loc_),
  uri(_uri)
{}

void GroupCollationSpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}

LetClauseList::LetClauseList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}

void LetClauseList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  vector<rchandle<LetClause> >::const_reverse_iterator it = let_hv.rbegin();
  for (; it!=let_hv.rend(); ++it) {
    const LetClause *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}


// [38] OrderByClause
// ------------------
OrderByClause::OrderByClause(
  const QueryLoc& loc_,
  rchandle<OrderSpecList> _spec_list_h,
  bool _stable_b)
:
  FLWORClause(loc_),
  spec_list_h(_spec_list_h),
  stable_b(_stable_b)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-OrderSpecList::

void OrderSpecList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  vector<rchandle<OrderSpec> >::const_iterator it = spec_hv.begin();
  for (; it!=spec_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}


// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
  const QueryLoc& loc_,
  rchandle<exprnode> _spec_h,
  rchandle<OrderModifier> _modifier_h)
:
  parsenode(loc_),
  spec_h(_spec_h),
  modifier_h(_modifier_h)
{}


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
  const QueryLoc& loc_,
  rchandle<OrderDirSpec> _dir_spec_h,
  rchandle<OrderEmptySpec> _empty_spec_h,
  rchandle<OrderCollationSpec> _collation_spec_h)
:
  parsenode(loc_),
  dir_spec_h(_dir_spec_h),
  empty_spec_h(_empty_spec_h),
  collation_spec_h(_collation_spec_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::dir_spec_t _dir_spec)
:
  parsenode(loc_),
  dir_spec(_dir_spec)
{}




//-OrderDirSpec::

void OrderDirSpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
  const QueryLoc& loc_,
  StaticContextConsts::order_empty_mode_t _empty_order_spec)
:
  parsenode(loc_),
  empty_order_spec(_empty_order_spec)
{}


//-OrderEmptySpec::

void OrderEmptySpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
  const QueryLoc& loc_,
  std::string const& _uri)
:
  parsenode(loc_),
  uri(_uri)
{}


//-OrderCollationSpec::

void OrderCollationSpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [42] QuantifiedExpr
// -------------------
QuantifiedExpr::QuantifiedExpr(
  const QueryLoc& loc_,
  ParseConstants::quantification_mode_t _qmode,
  rchandle<QVarInDeclList> _decl_list_h,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  qmode(_qmode),
  decl_list_h(_decl_list_h),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-QVarInDeclList::

void QVarInDeclList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  std::for_each (qvar_decl_hv.begin (), qvar_decl_hv.end (), visitor_functor (v));
  END_VISITOR ();
}


// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
  const QueryLoc& loc_,
  std::string _name,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  name(_name),
  typedecl_h(NULL),
  val_h(_val_h)
{}

QVarInDecl::QVarInDecl(
  const QueryLoc& loc_,
  std::string _name,
  rchandle<TypeDeclaration> _typedecl_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  name(_name),
  typedecl_h(_typedecl_h),
  val_h(_val_h)
{}


//-QVarInDecl::

void QVarInDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (val_h);
  ACCEPT (typedecl_h);
  END_VISITOR ();
}


// [43] TypeswitchExpr
// -------------------
TypeswitchExpr::TypeswitchExpr(
  const QueryLoc& loc_,
  rchandle<exprnode> _switch_expr_h,
  rchandle<CaseClauseList> _clause_list_h,
  rchandle<exprnode> _default_clause_h)
:
  exprnode(loc_),
  switch_expr_h(_switch_expr_h),
  clause_list_h(_clause_list_h),
  default_clause_h(_default_clause_h)
{}


TypeswitchExpr::TypeswitchExpr(
  const QueryLoc& loc_,
  rchandle<exprnode> _switch_expr_h,
  rchandle<CaseClauseList> _clause_list_h,
  std::string _default_varname,
  rchandle<exprnode> _default_clause_h)
:
  exprnode(loc_),
  switch_expr_h(_switch_expr_h),
  clause_list_h(_clause_list_h),
  default_varname(_default_varname),
  default_clause_h(_default_clause_h)
{}


//-TypeswitchExpr::

void TypeswitchExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT_CHK (switch_expr_h);
  ACCEPT_CHK (default_clause_h);
  ACCEPT_CHK (clause_list_h);

  END_VISITOR ();
}


// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  std::string _varname,
  rchandle<SequenceType> _type_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  varname(_varname),
  type_h(_type_h),
  val_h(_val_h)
{}

CaseClause::CaseClause(
  const QueryLoc& loc_,
  rchandle<SequenceType> _type_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  varname(""),
  type_h(_type_h),
  val_h(_val_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _cond_expr_h,
  rchandle<exprnode> _then_expr_h,
  rchandle<exprnode> _else_expr_h)
:
  exprnode(loc_),
  cond_expr_h(_cond_expr_h),
  then_expr_h(_then_expr_h),
  else_expr_h(_else_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _or_expr_h,
  rchandle<exprnode> _and_expr_h)
:
  exprnode(loc_),
  or_expr_h(_or_expr_h),
  and_expr_h(_and_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _and_expr_h,
  rchandle<exprnode> _comp_expr_h)
:
  exprnode(loc_),
  and_expr_h(_and_expr_h),
  comp_expr_h(_comp_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<ValueComp> _valcomp_h,
  rchandle<exprnode> _left_h,
  rchandle<exprnode> _right_h)
:
  exprnode(loc_),
  left_h(_left_h),
  right_h(_right_h),
  valcomp_h(_valcomp_h),
  gencomp_h(NULL),
  nodecomp_h(NULL)
{}

ComparisonExpr::ComparisonExpr(
  const QueryLoc& loc_,
  rchandle<GeneralComp> _gencomp_h,
  rchandle<exprnode> _left_h,
  rchandle<exprnode> _right_h)
:
  exprnode(loc_),
  left_h(_left_h),
  right_h(_right_h),
  valcomp_h(NULL),
  gencomp_h(_gencomp_h),
  nodecomp_h(NULL)
{}

ComparisonExpr::ComparisonExpr(
  const QueryLoc& loc_,
  rchandle<NodeComp> _nodecomp_h,
  rchandle<exprnode> _left_h,
  rchandle<exprnode> _right_h)
:
  exprnode(loc_),
  left_h(_left_h),
  right_h(_right_h),
  valcomp_h(NULL),
  gencomp_h(NULL),
  nodecomp_h(_nodecomp_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _range_expr_h,
  rchandle<FTSelection> _ftselect_h,
  rchandle<FTIgnoreOption> _ftignore_h)
:
  exprnode(loc_),
  range_expr_h(_range_expr_h),
  ftselect_h(_ftselect_h),
  ftignore_h(_ftignore_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _from_expr_h,
  rchandle<exprnode> _to_expr_h)
:
  exprnode(loc_),
  from_expr_h(_from_expr_h),
  to_expr_h(_to_expr_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::add_op_t _add_op,
  rchandle<exprnode> _add_expr_h,
  rchandle<exprnode> _mult_expr_h)
:
  exprnode(loc_),
  add_op(_add_op),
  add_expr_h(_add_expr_h),
  mult_expr_h(_mult_expr_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::mult_op_t _mult_op,
  rchandle<exprnode> _mult_expr_h,
  rchandle<exprnode> _union_expr_h)
:
  exprnode(loc_),
  mult_op(_mult_op),
  mult_expr_h(_mult_expr_h),
  union_expr_h(_union_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _union_expr_h,
  rchandle<exprnode> _intex_expr_h)
:
  exprnode(loc_),
  union_expr_h(_union_expr_h),
  intex_expr_h(_intex_expr_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::intex_op_t _intex_op,
  rchandle<exprnode> _intex_expr_h,
  rchandle<exprnode> _instof_expr_h)
:
  exprnode(loc_),
  intex_op(_intex_op),
  intex_expr_h(_intex_expr_h),
  instof_expr_h(_instof_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _treat_expr_h,
  rchandle<SequenceType> _seqtype_h)
:
  exprnode(loc_),
  treat_expr_h(_treat_expr_h),
  seqtype_h(_seqtype_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _castable_expr_h,
  rchandle<SequenceType> _seqtype_h)
:
  exprnode(loc_),
  castable_expr_h(_castable_expr_h),
  seqtype_h(_seqtype_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _cast_expr_h,
  rchandle<SingleType> _singletype_h)
:
  exprnode(loc_),
  cast_expr_h(_cast_expr_h),
  singletype_h(_singletype_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _unary_expr_h,
  rchandle<SingleType> _singletype_h)
:
  exprnode(loc_),
  unary_expr_h(_unary_expr_h),
  singletype_h(_singletype_h)
{}


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
  const QueryLoc& loc_,
  rchandle<SignList> _signlist_h,
  rchandle<exprnode> _value_expr_h)
:
  exprnode(loc_),
  value_expr_h(_value_expr_h),
  signlist_h(_signlist_h)
{}


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
  const QueryLoc& loc_,
  bool _sign)
:
  parsenode(loc_),
  sign(_sign)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::gencomp_t _type)
:
  parsenode(loc_),
  type(_type)
{}


//-GeneralComp::

void GeneralComp::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [61] ValueComp
// --------------
ValueComp::ValueComp(
  const QueryLoc& loc_,
  enum ParseConstants::valcomp_t _type)
:
  parsenode(loc_),
  type(_type)
{}


//-ValueComp::

void ValueComp::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [62] NodeComp
// -------------
NodeComp::NodeComp(
  const QueryLoc& loc_,
  enum ParseConstants::nodecomp_t _type)
:
  parsenode(loc_),
  type(_type)
{}


//-NodeComp::

void NodeComp::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
  const QueryLoc& loc_,
  string const& _valmode,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  valmode(_valmode=="lax" ? ParseConstants::val_lax : ParseConstants::val_strict),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<PragmaList> _pragma_list_h,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  pragma_list_h(_pragma_list_h),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  rchandle<QName> _name_h,
  std::string _pragma_lit)
:
  parsenode(loc_),
  name_h(_name_h),
  pragma_lit(_pragma_lit)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::pathtype_t _type,
  rchandle<exprnode> _relpath_expr_h)
  :
  exprnode(loc_),
  type(_type),
  relpath_expr_h(_relpath_expr_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::steptype_t _step_type,
  rchandle<exprnode> step,
  rchandle<exprnode> rpe)
  :
  exprnode(loc_),
  step_type(_step_type),
  step_expr_h(step)
{
  RelativePathExpr* rpep = dynamic_cast<RelativePathExpr*>(rpe.getp());
  if (rpep != NULL)
  {
    ContextItemExpr* dot = dynamic_cast<ContextItemExpr*>(rpep->step_expr_h.getp());
    if (dot != NULL)
      relpath_expr_h = rpep->relpath_expr_h;
    else
      relpath_expr_h = rpe;
  }
  else
  {
    relpath_expr_h = rpe;
  }

  FilterExpr* filter = dynamic_cast<FilterExpr*>(step.getp());
  if (filter != NULL)
    filter->setIsPathStep();
}


void RelativePathExpr::accept(parsenode_visitor& v) const
{
  void* visitor_state = v.begin_visit(*this);

  if (visitor_state == NULL)
  {
    return;
  }

  ACCEPT (step_expr_h);
  v.intermediate_visit(*this, visitor_state);
  ACCEPT (relpath_expr_h);
  END_VISITOR ();
}


/*******************************************************************************

[70] StepExpr ::= AxisStep  |  FilterExpr

********************************************************************************/


/*******************************************************************************

 [71] AxisStep ::= (ForwardStep | ReverseStep)  PredicateList?

********************************************************************************/
AxisStep::AxisStep(
    const QueryLoc& loc_,
    rchandle<ForwardStep> _forward_step_h,
    rchandle<PredicateList> _predicate_list_h)
  :
  exprnode(loc_),
  forward_step_h(_forward_step_h),
  reverse_step_h(NULL),
  predicate_list_h(_predicate_list_h)
{}


AxisStep::AxisStep(
    const QueryLoc& loc_,
    rchandle<ReverseStep> _reverse_step_h,
    rchandle<PredicateList> _predicate_list_h)
  :
  exprnode(loc_),
  forward_step_h(NULL),
  reverse_step_h(_reverse_step_h),
  predicate_list_h(_predicate_list_h)
{}


void AxisStep::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();

  if (forward_step_h != NULL) forward_step_h->accept(v);
  if (reverse_step_h != NULL) reverse_step_h->accept(v);

  v.post_axis_visit(*this, visitor_state);

  if (predicate_list_h != NULL) predicate_list_h->accept(v);

  END_VISITOR ();
}


/*******************************************************************************

   [72] ForwardStep ::= ForwardAxis  NodeTest | AbbrevForwardStep

********************************************************************************/
ForwardStep::ForwardStep(
    const QueryLoc& loc_,
    rchandle<ForwardAxis> _forward_axis_h,
    rchandle<parsenode> _node_test_h)
  :
  parsenode(loc_),
  forward_axis_h(_forward_axis_h),
  node_test_h(_node_test_h),
  abbrev_step_h(NULL)
{}


ForwardStep::ForwardStep(
    const QueryLoc& loc_,
    rchandle<AbbrevForwardStep> _abbrev_step_h)
  :
  parsenode(loc_),
  forward_axis_h(NULL),
  node_test_h(NULL),
  abbrev_step_h(_abbrev_step_h)
{}




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
    const QueryLoc& loc_,
    enum ParseConstants::forward_axis_t _axis)
  :
  parsenode(loc_),
  axis(_axis)
{}




void ForwardAxis::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [74] AbbrevForwardStep ::= NodeTest | AT_SIGN  NodeTest

********************************************************************************/
AbbrevForwardStep::AbbrevForwardStep(
    const QueryLoc& loc_,
    rchandle<parsenode> _node_test_h,
    bool _attr_b)
  :
  parsenode(loc_),
  node_test_h(_node_test_h),
  attr_b(_attr_b)
{}


AbbrevForwardStep::AbbrevForwardStep(
    const QueryLoc& loc_,
    rchandle<parsenode> _node_test_h)
  :
  parsenode(loc_),
  node_test_h(_node_test_h),
  attr_b(false)
{}




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
    const QueryLoc& loc_,
    rchandle<ReverseAxis> _axis_h,
    rchandle<parsenode> _node_test_h)
  :
  parsenode(loc_),
  axis_h(_axis_h),
  node_test_h(_node_test_h)
{}


ReverseStep::ReverseStep(
    const QueryLoc& loc_,
    rchandle<ReverseAxis> _axis_h)
  :
  parsenode(loc_),
  axis_h(_axis_h),
  node_test_h(NULL)
{}




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
    const QueryLoc& loc_,
    enum ParseConstants::reverse_axis_t _axis)
  :
  parsenode(loc_),
  axis(_axis)
{}




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
NameTest::NameTest(const QueryLoc& loc, rchandle<QName> qname)
  :
  parsenode(loc),
  theQName(qname),
  theWildcard(NULL)
{}


NameTest::NameTest(const QueryLoc& loc, rchandle<Wildcard> wild)
  :
  parsenode(loc),
  theQName(NULL),
  theWildcard(wild)
{}




void NameTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [80] Wildcard ::= STAR | ELEM_WILDCARD | PREFIX_WILDCARD

********************************************************************************/
Wildcard::Wildcard(
  const QueryLoc& loc,
  const xqp_string& prefix,
  const xqp_string& lname,
  enum ParseConstants::wildcard_t kind)
  :
  parsenode(loc),
  theKind(kind),
  thePrefix(prefix),
  theLocalName(lname)
{}




void Wildcard::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


/*******************************************************************************

  [81] FilterExpr ::= PrimaryExpr  PredicateList?

********************************************************************************/

FilterExpr::FilterExpr(
    const QueryLoc& loc_,
    rchandle<exprnode> _primary_h,
    rchandle<PredicateList> _pred_list_h)
  :
  exprnode(loc_),
  primary_h(_primary_h),
  pred_list_h(_pred_list_h),
  theIsPathStep(false)
{}


void FilterExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();

  ACCEPT (primary_h);
  v.post_primary_visit(*this, visitor_state);
  ACCEPT (pred_list_h);

  END_VISITOR ();
}


// [82] PredicateList

PredicateList::PredicateList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void PredicateList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  
  for (vector<rchandle<exprnode> >::const_iterator it = pred_hv.begin();
       it!=pred_hv.end(); ++it) 
  {
    const exprnode* e_p = &**it;
    ZORBA_ASSERT(e_p!=NULL);
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
void NumericLiteral::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [87] VarRef
// -----------
VarRef::VarRef(
  const QueryLoc& loc_,
  std::string _varname)
:
  exprnode(loc_),
  varname(_varname)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_)
:
  exprnode(loc_)
{}


//-ContextItemExpr::

void ContextItemExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [91] OrderedExpr
// ----------------

OrderedExpr::OrderedExpr(
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<QName> _fname_h,
  rchandle<ArgList> _arg_list_h)
:
  exprnode(loc_),
  fname_h(_fname_h),
  arg_list_h(_arg_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  rchandle<QName> _open_name_h,
  rchandle<QName> _close_name_h,
  rchandle<DirAttributeList> _attr_list_h,
  rchandle<DirElemContentList> _dir_content_list_h)
:
  exprnode(loc_),
  elem_name_h(_open_name_h),
  end_name_h(_close_name_h),
  attr_list_h(_attr_list_h),
  dir_content_list_h(_dir_content_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc)
:
  parsenode(loc)
{}


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
  const QueryLoc& loc,
  rchandle<QName> name,
  rchandle<DirAttributeValue> value)
:
  parsenode(loc),
  theName(name),
  theValue(value)
{}


void DirAttr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT(theValue);
  END_VISITOR ();
}


// [98] DirAttributeValue

DirAttributeValue::DirAttributeValue(
  const QueryLoc& loc_,
  rchandle<QuoteAttrContentList> _quot_attr_content_h)
:
  parsenode(loc_),
  quot_attr_content_h(_quot_attr_content_h),
  apos_attr_content_h(NULL)
{}

DirAttributeValue::DirAttributeValue(
  const QueryLoc& loc_,
  rchandle<AposAttrContentList> _apos_attr_content_h)
:
  parsenode(loc_),
  quot_attr_content_h(NULL),
  apos_attr_content_h(_apos_attr_content_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  std::string _quot_atcontent)
:
  parsenode(loc_),
  quot_atcontent(_quot_atcontent),
  common_content_h(NULL)
{}

QuoteAttrValueContent::QuoteAttrValueContent(
  const QueryLoc& loc_,
  rchandle<CommonContent> _common_content_h)
:
  parsenode(loc_),
  quot_atcontent(""),
  common_content_h(_common_content_h)
{}


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
  const QueryLoc& loc_,
  std::string _apos_atcontent)
:
  parsenode(loc_),
  apos_atcontent(_apos_atcontent),
  common_content_h(NULL)
{}

AposAttrValueContent::AposAttrValueContent(
  const QueryLoc& loc_,
  rchandle<CommonContent> _common_content_h)
:
  parsenode(loc_),
  apos_atcontent(""),
  common_content_h(_common_content_h)
{}


//-AposAttrValueContent::

void AposAttrValueContent::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [101] DirElemContent
// --------------------
DirElemContent::DirElemContent(
  const QueryLoc& loc_,
  rchandle<exprnode> _direct_cons_h)
:
  exprnode(loc_),
  direct_cons_h(_direct_cons_h)
{}

DirElemContent::DirElemContent(
  const QueryLoc& loc_,
  std::string _elem_content)
:
  exprnode(loc_),
  elem_content(_elem_content)
{}

DirElemContent::DirElemContent(
  const QueryLoc& loc_,
  rchandle<CDataSection> _cdata_h)
:
  exprnode(loc_),
  cdata_h(_cdata_h)
{}

DirElemContent::DirElemContent(
  const QueryLoc& loc_,
  rchandle<CommonContent> _common_content_h)
:
  exprnode(loc_),
  common_content_h(_common_content_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::common_content_t _type,
  std::string _ref)
:
  exprnode(loc_),
  type(_type),
  ref(_ref),
  expr_h(NULL)
{}

CommonContent::CommonContent(
  const QueryLoc& loc_,
  rchandle<EnclosedExpr> _expr_h)
:
  exprnode(loc_),
  type(ParseConstants::cont_expr),
  ref(""),
  expr_h(_expr_h)
{}

CommonContent::CommonContent(
  const QueryLoc& loc_,
  enum ParseConstants::common_content_t _type)
:
  exprnode(loc_),
  type(_type),
  ref(""),
  expr_h(NULL)
{}


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
  const QueryLoc& loc_,
  std::string const& _comment)
:
  exprnode(loc_),
  comment(_comment)
{}


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
  const QueryLoc& loc_,
  std::string const& _pi_target)
:
  exprnode(loc_),
  pi_target(_pi_target),
  pi_content("")
{}

DirPIConstructor::DirPIConstructor(
  const QueryLoc& loc_,
  std::string const& _pi_target,
  std::string const& _pi_content)
:
  exprnode(loc_),
  pi_target(_pi_target),
  pi_content(_pi_content)
{}


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
  const QueryLoc& loc_,
  std::string _cdata_content)
:
  exprnode(loc_),
  cdata_content(_cdata_content)
{}


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
  const QueryLoc& loc_,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{}


void CompDocConstructor::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (expr_h);
  END_VISITOR ();
}


// [111] CompElemConstructor

CompElemConstructor::CompElemConstructor(
    const QueryLoc& loc_,
    rchandle<exprnode> _qname_expr_h,
    rchandle<exprnode> _content_expr_h)
  :
  exprnode(loc_),
  qname_expr_h(_qname_expr_h),
  content_expr_h(_content_expr_h)
{}


void CompElemConstructor::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  if (dynamic_cast<QName*>(qname_expr_h.getp()) == NULL)
    ACCEPT(qname_expr_h);
  ACCEPT(content_expr_h);
  END_VISITOR();
}


// [113] CompAttrConstructor

CompAttrConstructor::CompAttrConstructor(
    const QueryLoc& loc_,
    rchandle<exprnode> _qname_expr_h,
    rchandle<exprnode> _val_expr_h)
  :
  exprnode(loc_),
  qname_expr_h(_qname_expr_h),
  val_expr_h(_val_expr_h)
{}


void CompAttrConstructor::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  if (dynamic_cast<QName*>(qname_expr_h.getp()) == NULL)
    ACCEPT(qname_expr_h);
  ACCEPT(val_expr_h);
  END_VISITOR();
}


// [114] CompTextConstructor

CompTextConstructor::CompTextConstructor(
  const QueryLoc& loc_,
  rchandle<exprnode> _text_expr_h)
:
  exprnode(loc_),
  text_expr_h(_text_expr_h)
{}


void CompTextConstructor::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (text_expr_h);
  END_VISITOR ();
}


// [115] CompCommentConstructor

CompCommentConstructor::CompCommentConstructor(
  const QueryLoc& loc_,
  rchandle<exprnode> _comment_expr_h)
:
  exprnode(loc_),
  comment_expr_h(_comment_expr_h)
{}


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
  const QueryLoc& loc_,
  std::string _target,
  rchandle<exprnode> _content_expr_h)
:
  exprnode(loc_),
  target(_target),
  target_expr_h(NULL),
  content_expr_h(_content_expr_h)
{}

CompPIConstructor::CompPIConstructor(
  const QueryLoc& loc_,
  rchandle<exprnode> _target_expr_h,
  rchandle<exprnode> _content_expr_h)
:
  exprnode(loc_),
  target(""),
  target_expr_h(_target_expr_h),
  content_expr_h(_content_expr_h)
{}


//-CompPIConstructor::

void CompPIConstructor::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (target_expr_h);
  ACCEPT (content_expr_h);
  END_VISITOR ();
}


// [117] SingleType
// ----------------
SingleType::SingleType(
  const QueryLoc& loc_,
  rchandle<AtomicType> _atomic_type_h,
  bool _hook_b)
:
  parsenode(loc_),
  atomic_type_h(_atomic_type_h),
  hook_b(_hook_b)
{}


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
  const QueryLoc& loc_,
  rchandle<SequenceType> _seqtype_h)
:
  parsenode(loc_),
  seqtype_h(_seqtype_h)
{}


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
  const QueryLoc& loc_,
  rchandle<parsenode> _itemtype_h,
  rchandle<OccurrenceIndicator> _occur_h)
:
  parsenode(loc_),
  itemtype_h(_itemtype_h),
  occur_h(_occur_h)
{}


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
  const QueryLoc& loc_,
  enum ParseConstants::occurrence_t _type)
:
  parsenode(loc_),
  type(_type)
{}


//-OccurrenceIndicator::

void OccurrenceIndicator::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [121] ItemType
// --------------
ItemType::ItemType(
  const QueryLoc& loc_,
  bool _item_test_b)
:
  parsenode(loc_),
  item_test_b(_item_test_b)
{}

ItemType::ItemType(
  const QueryLoc& loc_)
:
  parsenode(loc_),
  item_test_b(false)
{}


//-ItemType::

void ItemType::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [122] AtomicType
// ----------------
AtomicType::AtomicType(
  const QueryLoc& loc_,
  rchandle<QName> _qname_h)
:
  parsenode(loc_),
  qname_h(_qname_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-AnyKindTest::

void AnyKindTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [125] DocumentTest
// ------------------
DocumentTest::DocumentTest(
  const QueryLoc& loc_)
:
  parsenode(loc_),
  elem_test_h(NULL),
  schema_elem_test_h(NULL)
{}

DocumentTest::DocumentTest(
  const QueryLoc& loc_,
  rchandle<ElementTest> _elem_test_h)
:
  parsenode(loc_),
  elem_test_h(_elem_test_h),
  schema_elem_test_h(NULL)
{}

DocumentTest::DocumentTest(
  const QueryLoc& loc_,
  rchandle<SchemaElementTest> _schema_elem_test_h)
:
  parsenode(loc_),
  elem_test_h(NULL),
  schema_elem_test_h(_schema_elem_test_h)
{}


//-DocumentTest::

void DocumentTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [126] TextTest
// --------------
TextTest::TextTest(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-TextTest::

void TextTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [127] CommentTest
// -----------------
CommentTest::CommentTest(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-CommentTest::

void CommentTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}



// [128] PITest

PITest::PITest(
  const QueryLoc& loc_,
  std::string _target)
:
  parsenode(loc_),
  target(_target)
{}


void PITest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [129] AttributeTest

AttributeTest::AttributeTest(
  const QueryLoc& loc,
  rchandle<QName> attrName,
  rchandle<TypeName> typeName)
  :
  parsenode(loc),
  theAttrName(attrName),
  theTypeName(typeName)
{}


void AttributeTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [130] AttribNameOrWildcard


// [131] SchemaAttributeTest
// -------------------------
SchemaAttributeTest::SchemaAttributeTest(
  const QueryLoc& loc_,
  rchandle<QName> _attr_h)
:
  parsenode(loc_),
  attr_h(_attr_h)
{}


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
    const QueryLoc& loc,
    rchandle<QName> ename,
    rchandle<TypeName> tname,
    bool na)
  :
  parsenode(loc),
  theElementName(ename),
  theTypeName(tname),
  theNilledAllowed(na)
{}


void ElementTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [135] SchemaElementTest
// -----------------------
SchemaElementTest::SchemaElementTest(
  const QueryLoc& loc_,
  rchandle<QName> _elem_h)
:
  parsenode(loc_),
  elem_h(_elem_h)
{}


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
  const QueryLoc& loc_,
  rchandle<QName> _qname_h)
:
  parsenode(loc_),
  qname_h(_qname_h),
  optional_b(false)
{}

TypeName::TypeName(
  const QueryLoc& loc_,
  rchandle<QName> _qname_h,
  bool _b)
:
  parsenode(loc_),
  qname_h(_qname_h),
  optional_b(_b)
{}


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
  const QueryLoc& loc_,
  string const& _strval)
:
  exprnode(loc_),
  strval(_strval)
{}


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
  const QueryLoc& loc_,
  const string& _qname)
:
  exprnode(loc_),
  qname(_qname)
{}


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
  const QueryLoc& loc_,
  rchandle<QName> _qname_h)
:
  parsenode(loc_),
  qname_h(_qname_h)
{}


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
  const QueryLoc& aLoc,
  store::UpdateConsts::InsertType aInsertType,
  rchandle<exprnode> aSourceExpr,
  rchandle<exprnode> aTargetExpr)
:
  exprnode(aLoc),
  theInsertType(aInsertType),
  theSourceExpr(aSourceExpr),
  theTargetExpr(aTargetExpr)
{}


//-InsertExpr::

void InsertExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT(theSourceExpr);
  ACCEPT(theTargetExpr);
  END_VISITOR ();
}


// [243] DeleteExpr
// ----------------
DeleteExpr::DeleteExpr(
  const QueryLoc& aLoc,
  rchandle<exprnode> aTargetExpr)
:
  exprnode(aLoc),
  theTargetExpr(aTargetExpr)
{}


//-DeleteExpr::

void DeleteExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (theTargetExpr);
  END_VISITOR ();
}


// [244] ReplaceExpr
// -----------------
ReplaceExpr::ReplaceExpr(
  const QueryLoc& aLoc,
  store::UpdateConsts::ReplaceType aReplaceType,
  rchandle<exprnode> aTargetExpr,
  rchandle<exprnode> aReplaceExpr)
:
  exprnode(aLoc),
  theReplaceType(aReplaceType),
  theTargetExpr(aTargetExpr),
  theReplaceExpr(aReplaceExpr)
{}


//-ReplaceExpr::

void ReplaceExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (theTargetExpr);
  ACCEPT (theReplaceExpr);
  END_VISITOR ();
}


// [245] RenameExpr
// ----------------
RenameExpr::RenameExpr(
  const QueryLoc& aLoc,
  rchandle<exprnode> aTargetExpr,
  rchandle<exprnode> aNameExpr)
:
  exprnode(aLoc),
  theTargetExpr(aTargetExpr),
  theNameExpr(aNameExpr)
{}


//-RenameExpr::

void RenameExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (theTargetExpr);
  ACCEPT (theNameExpr);
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
  const QueryLoc& loc_,
  rchandle<VarNameList> _varname_list_h,
  rchandle<exprnode> _source_expr_h,
  rchandle<exprnode> _target_expr_h)
:
  exprnode(loc_),
  varname_list_h(_varname_list_h),
  source_expr_h(_source_expr_h),
  target_expr_h(_target_expr_h)
{}


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
  const QueryLoc& loc_)
:
  exprnode(loc_)
{}


//-VarNameList::

void VarNameList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  for (vector<rchandle<VarBinding> >::const_reverse_iterator it = varbinding_hv.rbegin();
       it!=varbinding_hv.rend(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}


// [249b] VarBinding
// -----------------
VarBinding::VarBinding(
  const QueryLoc& loc_,
  std::string _varname,
  rchandle<exprnode> _val_h)
:
  exprnode(loc_),
  varname(_varname),
  val_h(_val_h)
{}


//-VarBinding::

void VarBinding::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (val_h);
  END_VISITOR ();
}

// TryExpr
// ---
void TryExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theExprSingle);
  ACCEPT(theCatchListExpr);
  END_VISITOR();
}

// CatchListExpr
// -------------
void CatchListExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  vector<rchandle<CatchExpr> >::const_reverse_iterator it = theCatchExprs.rbegin();
  for (; it!=theCatchExprs.rend(); ++it) {
    ACCEPT_CHK(*it);
  }
  END_VISITOR();
}

// CatchExpr
// -----
void CatchExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theNameTest);
  ACCEPT(theExprSingle);
  END_VISITOR();
}


void EvalExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT (vgdl);
  ACCEPT (expr_h);
  END_VISITOR();
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
  const QueryLoc& loc_,
  rchandle<FTOr> _ftor_h,
  rchandle<FTMatchOptionProximityList> _option_list_h,
  rchandle<RangeExpr> _weight_expr_h)
:
  parsenode(loc_),
  ftor_h(_ftor_h),
  option_list_h(_option_list_h),
  weight_expr_h(_weight_expr_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_),
  opt_h(_opt_h),
  prox_h(NULL)
{}

FTMatchOptionProximity::FTMatchOptionProximity(
  rchandle<FTProximity> _prox_h,
  const QueryLoc& loc_)
:
  parsenode(loc_),
  opt_h(NULL),
  prox_h(_prox_h)
{}

FTMatchOptionProximity::FTMatchOptionProximity(
  const QueryLoc& loc_)
:
  parsenode(loc_),
  opt_h(NULL),
  prox_h(NULL)
{}


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
  const QueryLoc& loc_,
  rchandle<FTOr> _ftor_h,
  rchandle<FTAnd> _ftand_h)
:
  parsenode(loc_),
  ftor_h(_ftor_h),
  ftand_h(_ftand_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTAnd> _ftand_h,
  rchandle<FTMildnot> _ftmild_not_h)
:
  parsenode(loc_),
  ftand_h(_ftand_h),
  ftmild_not_h(_ftmild_not_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTMildnot> _ftmild_not_h,
  rchandle<FTUnaryNot> _ftunary_not_h)
:
  parsenode(loc_),
  ftmild_not_h(_ftmild_not_h),
  ftunary_not_h(_ftunary_not_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTWordsSelection> _words_selection_h,
  bool _not_b)
:
  parsenode(loc_),
  words_selection_h(_words_selection_h),
  not_b(_not_b)
{}


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
  const QueryLoc& loc_,
  rchandle<FTWords> _words_h,
  rchandle<FTTimes> _times_h,
  rchandle<FTSelection> _selection_h)
:
  parsenode(loc_),
  words_h(_words_h),
  times_h(_times_h),
  selection_h(_selection_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTWordsValue> _words_val_h,
  rchandle<FTAnyallOption> _any_all_option_h)
:
  parsenode(loc_),
  words_val_h(_words_val_h),
  any_all_option_h(_any_all_option_h)
{}


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
  const QueryLoc& loc_,
  rchandle<StringLiteral> _lit_h,
  rchandle<Expr> _expr_h)
:
  parsenode(loc_),
  lit_h(_lit_h),
  expr_h(_expr_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-FTProximity::

void FTProximity::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [353] FTOrderedIndicator
// ------------------------
FTOrderedIndicator::FTOrderedIndicator(
  const QueryLoc& loc_)
:
  FTProximity(loc_)
{}


//-FTOrderedIndicator::

void FTOrderedIndicator::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [354] FTMatchOption
// -------------------
FTMatchOption::FTMatchOption(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-FTMatchOption::

void FTMatchOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [355] FTCaseOption
// ------------------
FTCaseOption::FTCaseOption(
  const QueryLoc& loc_,
  ParseConstants::ft_case_mode_t _mode)
:
  FTMatchOption(loc_),
  mode(_mode)
{}


//-FTCaseOption::

void FTCaseOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [356] FTDiacriticsOption
// ------------------------
FTDiacriticsOption::FTDiacriticsOption(
  const QueryLoc& loc_,
  ParseConstants::ft_diacritics_mode_t _mode)
:
  FTMatchOption(loc_),
  mode(_mode)
{}


//-FTDiacriticsOption::

void FTDiacriticsOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [357] FTStemOption
// ------------------
FTStemOption::FTStemOption(
  const QueryLoc& loc_,
  ParseConstants::ft_stem_mode_t _mode)
:
  FTMatchOption(loc_),
  mode(_mode)
{}


//-FTStemOption::

void FTStemOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [358] FTThesaurusOption
// -----------------------
FTThesaurusOption::FTThesaurusOption(
  const QueryLoc& loc_,
  rchandle<FTThesaurusID> _thesaurusid_h,
  rchandle<FTThesaurusList> _thesaurus_list_h,
  bool _default_b,
  bool _without_b)
:
  FTMatchOption(loc_),
  thesaurusid_h(_thesaurusid_h),
  thesaurus_list_h(_thesaurus_list_h),
  default_b(_default_b),
  without_b(_without_b)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  std::string _thesaurus_name,
  std::string _relationship_name,
  rchandle<FTRange> _levels_h)
:
  parsenode(loc_),
  thesaurus_name(_thesaurus_name),
  relationship_name(_relationship_name),
  levels_h(_levels_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTRefOrList> _refor_list_h,
  rchandle<FTInclExclStringLiteralList> _incl_excl_list_h,
  ParseConstants::stop_words_mode_t _mode)
:
  FTMatchOption(loc_),
  refor_list_h(_refor_list_h),
  incl_excl_list_h(_incl_excl_list_h),
  mode(_mode)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  std::string _at_str,
  rchandle<FTStringLiteralList> _stringlit_list_h)
:
  parsenode(loc_),
  at_str(_at_str),
  stringlit_list_h(_stringlit_list_h)
{}


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
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


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
  const QueryLoc& loc_,
  rchandle<FTRefOrList> _ref_or_list_h,
  ParseConstants::intex_op_t _mode)
:
  parsenode(loc_),
  ref_or_list_h(_ref_or_list_h),
  mode(_mode)
{}


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
  const QueryLoc& loc_,
  std::string _lang)
:
  FTMatchOption(loc_),
  lang(_lang)
{}


//-FTLanguageOption::

void FTLanguageOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [364] FTWildcardOption
// ----------------------
FTWildcardOption::FTWildcardOption(
  const QueryLoc& loc_,
  bool _with_b)
:
  FTMatchOption(loc_),
  with_b(_with_b)
{}


//-FTWildcardOption::

void FTWildcardOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [365]  FTContent
// ---------------
FTContent::FTContent(
  const QueryLoc& loc_,
  ParseConstants::ft_content_mode_t _mode)
:
  FTProximity(loc_),
  mode(_mode)
{}


//-FTContent::

void FTContent::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [366]  FTAnyallOption
// --------------------
FTAnyallOption::FTAnyallOption(
  const QueryLoc& loc_,
  ParseConstants::ft_anyall_option_t _option)
:
  parsenode(loc_),
  option(_option)
{}


//-FTAnyallOption::

void FTAnyallOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [367] FTRange
// -------------
FTRange::FTRange(
  const QueryLoc& loc_,
  FTRange::ft_range_mode_t _mode,
  rchandle<exprnode> _src_expr_h,
  rchandle<exprnode> _dst_expr_h)
:
  parsenode(loc_),
  mode (_mode),
  src_expr_h(_src_expr_h),
  dst_expr_h(_dst_expr_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTRange> _dist_h,
  rchandle<FTUnit> _unit_h)
:
  FTProximity(loc_),
  dist_h(_dist_h),
  unit_h(_unit_h)
{}


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
  const QueryLoc& loc_,
  rchandle<UnionExpr> _window_h,
  rchandle<FTUnit> _unit_h)
:
  FTProximity(loc_),
  window_h(_window_h),
  unit_h(_unit_h)
{}


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
  const QueryLoc& loc_,
  rchandle<FTRange> _range_h)
:
  parsenode(loc_),
  range_h(_range_h)
{}


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
  const QueryLoc& loc_,
  ParseConstants::ft_scope_t _scope)
:
  FTProximity(loc_),
  scope(_scope)
{}


//-FTScope::

void FTScope::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [372] FTUnit
// ------------
FTUnit::FTUnit(
  const QueryLoc& loc_,
  ParseConstants::ft_unit_t _unit)
:
  parsenode(loc_),
  unit(_unit)
{}


//-FTUnit::

void FTUnit::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [373] FTBigUnit
// ---------------
FTBigUnit::FTBigUnit(
  const QueryLoc& loc_,
  enum ParseConstants::ft_big_unit_t _unit)
:
  parsenode(loc_),
  unit(_unit)
{}


//-FTBigUnit::

void FTBigUnit::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}


// [374] FTIgnoreOption
// --------------------
FTIgnoreOption::FTIgnoreOption(
  const QueryLoc& loc_,
  rchandle<UnionExpr> _union_h)
:
  parsenode(loc_),
  union_h(_union_h)
{}


//-FTIgnoreOption::

void FTIgnoreOption::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (union_h);
  END_VISITOR ();
}

void ExitExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (value_h);
  END_VISITOR ();
}

void WhileExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (cond);
  ACCEPT (body);
  END_VISITOR ();
}

void FlowCtlStatement::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}

} /* namespace zorba */


