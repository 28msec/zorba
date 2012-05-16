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
#include "stdafx.h"

#include "util/stl_util.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "types/typemanager.h"

#include "store/api/item.h"

#include "context/static_context_consts.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <assert.h>
#include <algorithm>


#include "util/tracer.h"


using namespace std;

namespace zorba
{

int dummy;
void *parsenode_visitor::no_state = (void *) &dummy;

int printdepth = 0;
ostringstream __oss;

#undef  INDENT
#define INDENT      std::string(++printdepth, ' ')
#define OUTDENT     std::string(printdepth--, ' ')
#define UNDENT      printdepth--

#define BEGIN_VISITOR() void *visitor_state; if (NULL == (visitor_state = v.begin_visit (*this))) return
#define END_VISITOR() v.end_visit (*this, visitor_state)
#define ACCEPT( m ) do { if ((m) != NULL) (m)->accept (v); } while (0)
#define ACCEPT_CHK( m ) do { ZORBA_ASSERT ((m) != NULL);  (m)->accept (v); } while (0)

#define ACCEPT_SEQ(T,S) \
  for ( T::const_iterator i = S.begin(); i != S.end(); ++i ) \
    ACCEPT( *i );

#define DECLARE_VISITOR_FUNCTOR( name, type, body)                      \
  class name : public unary_function<rchandle<parsenode>, void> {       \
    parsenode_visitor &v;                                               \
  public:                                                               \
  name (parsenode_visitor &v_) : v (v_) {}                              \
  void operator () (type e) body                                        \
    }


DECLARE_VISITOR_FUNCTOR(visitor_functor, rchandle<parsenode>, { ACCEPT(e); });


/*******************************************************************************
  [1] Module ::= 	VersionDecl? (LibraryModule | MainModule)
********************************************************************************/


/*******************************************************************************
  [2] VersionDecl ::= XQUERY ENCODING STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
********************************************************************************/
VersionDecl::VersionDecl(
    const QueryLoc& loc_,
    zstring const& _version,
    zstring const& _encoding)
  :
  parsenode(loc_),
  version(_version),
  encoding(_encoding)
{
}


void VersionDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [3] MainModule ::= Prolog QueryBody | QueryBody
********************************************************************************/
MainModule::MainModule(
    const QueryLoc& loc_,
    rchandle<QueryBody> _query_body_h,
    rchandle<Prolog> _prolog_h,
    rchandle<VersionDecl> _ver)
  :
  Module(loc_, _ver),
  prolog_h(_prolog_h),
  query_body_h(_query_body_h)
{
}


void MainModule::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (version_decl_h);
  ACCEPT (prolog_h);
  ACCEPT (query_body_h);
  END_VISITOR();
}


/*******************************************************************************
  [4] LibraryModule ::= ModuleDecl  Prolog
  [*] DataModule :=     DataModuleDecl Prolog
********************************************************************************/
LibraryModule::LibraryModule(
    const QueryLoc& loc_,
    rchandle<ModuleDecl> _decl_h,
    rchandle<Prolog> _prolog_h,
    rchandle<VersionDecl> _ver)
  :
  Module(loc_, _ver),
  decl_h(_decl_h),
  prolog_h(_prolog_h)
{
}


void LibraryModule::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(version_decl_h);
  ACCEPT(decl_h);
  ACCEPT(prolog_h);
  END_VISITOR();
}


/*******************************************************************************
  [5] ModuleDecl ::= MODULE NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
********************************************************************************/
ModuleDecl::ModuleDecl(
    const QueryLoc& loc,
    zstring const& prefix,
    zstring const& target_namespace)
  :
  XQDocumentable(loc),
  thePrefix(prefix),
  theTargetNamespace(target_namespace)
{
}


void ModuleDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [6] Prolog ::= SIND_DeclList?  VFO_DeclList?

  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator

  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6c] SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl

********************************************************************************/
Prolog::Prolog(
    const QueryLoc& loc_,
    rchandle<SIND_DeclList> _sind_list_h,
    rchandle<VFO_DeclList> _vfo_list_h)
  :
  parsenode(loc_),
  sind_list_h(_sind_list_h),
  vfo_list_h(_vfo_list_h)
{
}


bool Prolog::set_sind_list(SIND_DeclList* list)
{
  bool result = true;
  if (!sind_list_h.isNull())
    result = false;
  sind_list_h = list;
  return result;
}


bool Prolog::set_vfo_list(VFO_DeclList* list)
{
  bool result = true;
  if (!vfo_list_h.isNull())
    result = false;
  vfo_list_h = list;
  return result;
}


bool Prolog::set_list(parsenode* list)
{
  SIND_DeclList* sdl = dynamic_cast<SIND_DeclList*>(list);
  if (sdl != NULL)
    return set_sind_list(sdl);

  VFO_DeclList* vdl = dynamic_cast<VFO_DeclList*>(list);
  if (vdl != NULL)
    return set_vfo_list(vdl);

  return false;
}


void Prolog::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (sind_list_h);
  ACCEPT (vfo_list_h);
  END_VISITOR();
}


/*******************************************************************************
  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator
********************************************************************************/
SIND_DeclList::SIND_DeclList(const QueryLoc& loc)
  :
  parsenode(loc)
{
}


void SIND_DeclList::push_back(rchandle<parsenode> decl)
{
  if (dynamic_cast<ModuleImport*>(decl.getp()) != NULL)
  {
    theModuleImports.push_back(decl);
  }
  else
  {
    theDecls.push_back(decl);
  }
}


void SIND_DeclList::accept(parsenode_visitor &v) const
{
  BEGIN_VISITOR();

  for (vector<rchandle<parsenode> >::const_iterator it = theDecls.begin();
       it != theDecls.end();
       ++it)
  {
    ACCEPT_CHK((*it));
  }

  for (vector<rchandle<parsenode> >::const_iterator it = theModuleImports.begin();
       it != theModuleImports.end();
       ++it)
  {
    ACCEPT_CHK((*it));
  }

  END_VISITOR();
}


/******************************************************************************
  [11] BoundarySpaceDecl ::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
********************************************************************************/
BoundarySpaceDecl::BoundarySpaceDecl(
    const QueryLoc& loc_,
    StaticContextConsts::boundary_space_mode_t _mode)
  :
  parsenode(loc_),
  mode(_mode)
{
}


void BoundarySpaceDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [14] OrderingModeDecl ::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
********************************************************************************/
OrderingModeDecl::OrderingModeDecl(
    const QueryLoc& loc_,
    StaticContextConsts::ordering_mode_t _mode)
  :
  parsenode(loc_),
  mode(_mode)
{
}


void OrderingModeDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [15] EmptyOrderDecl ::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST |
                          DECLARE_DEFAULT_ORDER  EMPTY_LEAST
********************************************************************************/
EmptyOrderDecl::EmptyOrderDecl(
    const QueryLoc& loc_,
    StaticContextConsts::empty_order_mode_t _mode)
  :
  parsenode(loc_),
  mode(_mode)
{
}


void EmptyOrderDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [16] CopyNamespacesDecl ::= DECLARE_COPY_NAMESPACES PreserveMode COMMA InheritMode

  [19] PreserveMode ::= "preserve" | "no-preserve"
  [20] InheritMode ::=  "inherit" | "no-inherit"
********************************************************************************/
CopyNamespacesDecl::CopyNamespacesDecl(
    const QueryLoc& loc_,
    StaticContextConsts::preserve_mode_t _preserve_mode,
    StaticContextConsts::inherit_mode_t  _inherit_mode)
  :
  parsenode(loc_),
  preserve_mode(_preserve_mode),
  inherit_mode(_inherit_mode)
{
}


void CopyNamespacesDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [17] DecimalFormatDecl ::= "declare"
                             (("decimal-format" QName) | ("default" "decimal-format"))
                             (DFPropertyName "=" StringLiteral)*

  [18] DFPropertyName ::= "decimal-separator" | "grouping-separator" |
                          "infinity" | "minus-sign" | "NaN" | "percent" |
                          "per-mille" | "zero-digit" | "digit" |
                          "pattern-separator"
********************************************************************************/
void DecimalFormatNode::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [21] DefaultCollationDecl ::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
********************************************************************************/
DefaultCollationDecl::DefaultCollationDecl(
    const QueryLoc& loc_,
    zstring const&  _collation)
  :
  parsenode(loc_),
  collation(_collation)
{
}


void DefaultCollationDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [22] BaseURIDecl ::= DECLARE_BASE_URI  URI_LITERAL
********************************************************************************/
BaseURIDecl::BaseURIDecl(
    const QueryLoc& loc_,
    zstring const& _base_uri)
  :
  parsenode(loc_),
  base_uri(_base_uri)
{
}


void BaseURIDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [31] ConstructionDecl ::= DECLARE CONSTRUCTION PRESERVE
                            DECLARE CONSTRUCTION STRIP
********************************************************************************/
ConstructionDecl::ConstructionDecl(
    const QueryLoc& loc_,
    StaticContextConsts::construction_mode_t _mode)
  :
  parsenode(loc_),
  mode(_mode)
{
}


void ConstructionDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/******************************************************************************
  [10] NamespaceDecl ::= ::= DECLARE NAMESPACE NCNAME EQ URI_LITERAL
********************************************************************************/
NamespaceDecl::NamespaceDecl(
    const QueryLoc& loc,
    const zstring& prefix,
    const zstring& uri)
  :
  parsenode(loc),
  thePrefix(prefix),
  theUri(uri)
{
}


void NamespaceDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [12] DefaultNamespaceDecl ::= DECLARE DEFAULT ELEMENT NAMESPACE URILiteral |
                                DECLARE DEFAULT FUNCTION NAMESPACE URILiteral
********************************************************************************/
DefaultNamespaceDecl::DefaultNamespaceDecl(
    const QueryLoc& loc,
    enum ParseConstants::default_namespace_mode_t mode,
    const zstring& uri)
  :
  parsenode(loc),
  theMode(mode),
  theUri(uri)
{
}


void DefaultNamespaceDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [23] SchemaImport ::= "import" "schema" SchemaPrefix? URILiteral
                        ("at"  URILiteralList)?
********************************************************************************/
SchemaImport::SchemaImport(
    const QueryLoc& loc,
    rchandle<SchemaPrefix> prefix,
    const zstring& uri,
    rchandle<URILiteralList> at_list)
  :
  XQDocumentable(loc),
  thePrefix(prefix),
  theUri(uri),
  theAtList(at_list)
{
}


void SchemaImport::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(thePrefix);
  ACCEPT(theAtList);
  END_VISITOR();
}


/******************************************************************************
  [23a] URLLiteralList ::= URI_LITERAL | URILiteralList  COMMA  URI_LITERAL
********************************************************************************/
URILiteralList::URILiteralList(const QueryLoc& loc)
  :
  parsenode(loc)
{
}


void URILiteralList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
#if 0
  vector<string>::const_reverse_iterator it = uri_v.rbegin();
  for (; it!=uri_v.rend(); ++it) {
    // ..do something useful
  }
#endif
  END_VISITOR();
}


/******************************************************************************
  [24] SchemaPrefix ::=	("namespace" NCName "=") | ("default" "element" "namespace")
********************************************************************************/
SchemaPrefix::SchemaPrefix(
    const QueryLoc& loc,
    bool isDefault)
  :
  parsenode(loc),
  thePrefix(""),
  theIsDefault(isDefault)
{
}


SchemaPrefix::SchemaPrefix(
    const QueryLoc& loc,
    const zstring& prefix)
  :
  parsenode(loc),
  thePrefix(prefix),
  theIsDefault(false)
{
}


void SchemaPrefix::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  [25] ModuleImport ::= "import" "module" ("namespace" NCName "=")? URILiteral
                        ("at" URILiteralList)?
********************************************************************************/
ModuleImport::ModuleImport(
    const QueryLoc& loc,
    const zstring& uri,
    rchandle<URILiteralList> atlist)
  :
  XQDocumentable(loc),
  theUri(uri),
  theAtList(atlist)
{
}


ModuleImport::ModuleImport(
    const QueryLoc& loc,
    const zstring& prefix,
    const zstring& uri,
    rchandle<URILiteralList> atlist)
  :
  XQDocumentable(loc),
  thePrefix(prefix),
  theUri(uri),
  theAtList(atlist)
{
}


void ModuleImport::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theAtList);
  END_VISITOR();
}


/*******************************************************************************
  VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl
********************************************************************************/
VFO_DeclList::VFO_DeclList(
    const QueryLoc& loc_)
  :
  parsenode(loc_)
{
}


void VFO_DeclList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  for (vector<rchandle<parsenode> >::const_iterator it = vfo_hv.begin();
       it != vfo_hv.end();
       ++it)
  {
    ACCEPT_CHK (*it);
  }
  END_VISITOR();
}


/*******************************************************************************
  OptionDecl ::= DECLARE_OPTION  QNAME  STRING_LITERAL
********************************************************************************/
OptionDecl::OptionDecl(
    const QueryLoc& loc_,
    rchandle<QName> _qname_h,
    zstring const& _val)
  :
  parsenode(loc_),
  qname_h(_qname_h),
  val(_val)
{
}


void OptionDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //qname_h->accept(v);
  END_VISITOR();
}


/*******************************************************************************
  ContextItemDecl ::= "declare" "context" "item" ("as" ItemType)?
                      ((":=" VarValue) | ("external" (":=" VarDefaultValue)?))
********************************************************************************/
void CtxItemDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theType);
  ACCEPT(theInitExpr);
  END_VISITOR();
}


/*******************************************************************************
  Global declarations:
  --------------------

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

  VarDecl ::= variable" "$" VarName TypeDeclaration?
              ((":=" VarValue) | ("external" (":=" VarDefaultValue)?))

  VarValue ::= ExprSingle

  VarDefaultValue ::= ExprSingle


  Local declarations:
  -------------------

  VarDeclStatement ::= ("local" Annotation*)? "variable"
                       "$" VarName TypeDeclaration? (":=" ExprSingle)?
                       ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)* ";"
********************************************************************************/
VarDecl::VarDecl(
    const QueryLoc& loc,
    QName* varname,
    SequenceType* type_decl,
    exprnode* init_expr,
    AnnotationListParsenode* annotations,
    bool global,
    bool external)
  :
  VarDeclWithInit(loc, varname, type_decl, init_expr),
  theIsExternal(external),
  theIsGlobal(global),
  theAnnotations(annotations)
{
}


void VarDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theAnnotations);
  ACCEPT(theType);
  ACCEPT(theInitExpr);
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
FunctionDecl::FunctionDecl(
    const QueryLoc& loc,
    QName* name,
    ParamList* params,
    SequenceType* retType,
    exprnode* body,
    bool updating,
    bool external)
  :
  XQDocumentable(loc),
  theName(name),
  theParams(params),
  theReturnType(retType),
  theBody(body),
  theIsExternal(external),
  theUpdating(updating)
{
}


void FunctionDecl::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theParams);
  ACCEPT(theReturnType);
  ACCEPT(theBody);
  END_VISITOR();
}


ulong FunctionDecl::get_param_count() const
{
  return theParams == NULL ? 0 : (ulong)theParams->size();
}


void FunctionDecl::set_annotations(AnnotationListParsenode* annotations)
{
  theAnnotations = annotations;
}

/*******************************************************************************
  [34] ParamList ::= Param ("," Param)*
********************************************************************************/
ParamList::ParamList(const QueryLoc& loc)
  :
  parsenode(loc)
{
}


void ParamList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  for (vector<rchandle<Param> >::const_iterator it = param_hv.begin();
       it != param_hv.end();
       ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


/*******************************************************************************
  [35] Param ::= "$" QName TypeDeclaration?
********************************************************************************/
Param::Param(
    const QueryLoc& loc,
    rchandle<QName> name,
    rchandle<SequenceType> type)
  :
  parsenode(loc),
  theName(name),
  theType(type)
{
}


void Param::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theType);
  END_VISITOR();
}

/*******************************************************************************
  AnnotationList ::= Annotation*
********************************************************************************/
AnnotationListParsenode::AnnotationListParsenode(
    const QueryLoc& loc,
    AnnotationParsenode* annotation)
  :
  parsenode(loc)
{
  push_back(annotation);
}

void AnnotationListParsenode::push_back(AnnotationParsenode* annotation)
{
  theAnnotations.push_back(annotation);
}

void AnnotationListParsenode::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT_SEQ(std::vector<rchandle<AnnotationParsenode> >, theAnnotations);
  END_VISITOR();
}


/*******************************************************************************
  Annotation ::= "%" EQName  ("(" Literal  ("," Literal)* ")")?
********************************************************************************/
AnnotationParsenode::AnnotationParsenode(
    const QueryLoc& loc,
    QName* qname,
    AnnotationLiteralListParsenode* literal_list)
  :
  parsenode(loc),
  theQName(qname),
  theLiteralsList(literal_list)
{
}

void AnnotationParsenode::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theLiteralsList);
  END_VISITOR();
}


AnnotationLiteralListParsenode::AnnotationLiteralListParsenode(
    const QueryLoc& loc,
    exprnode* literal)
  :
  parsenode(loc)
{
  push_back(literal);
}


void AnnotationLiteralListParsenode::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT_SEQ(std::vector<rchandle<exprnode> >, theLiterals);
  END_VISITOR();
}


/*******************************************************************************
  [*] CollectionDecl ::= "declare" %annotations "collection" QName
                         ("as" CollectionTypeDecl)?

  [*] CollectionTypeDecl ::= KindTest OccurenceIndicator?
********************************************************************************/
CollectionDecl::CollectionDecl(
    const QueryLoc& aLoc,
    QName* aName,
    rchandle<AnnotationListParsenode> aAnnotations,
    SequenceType* aTypeDecl)
  :
  parsenode(aLoc),
  theName(aName),
  theTypeDecl(aTypeDecl),
  theAnnotations(aAnnotations)
{
}

void CollectionDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theTypeDecl);
  END_VISITOR();
}


/***************************************************************************//**
  IndexDecl ::= "declare" IndexPropertyList "index" QName
                "on" "nodes" IndexDomainExpr "by" IndexKeyList

  IndexPropertyList := ("unique" | "non" "unique" |
                        "value" "range" | "value" "equality" |
                        "automatically" "maintained" | "manually" "maintained")*

  IndexDomainExpr := PathExpr

  IndexKeyList := IndexKeySpec+

  IndexKeySpec := PathExpr AtomicType IndexKeyOrderModifier

  AtomicType := QName

  IndexKeyOrderModifier := ("ascending" | "descending")? ("collation" UriLiteral)?
********************************************************************************/
AST_IndexDecl::AST_IndexDecl(
    const QueryLoc& loc,
    QName* name,
    exprnode* domainExpr,
    IndexKeyList* key,
    rchandle<AnnotationListParsenode> aAnnotations)
  :
  parsenode(loc),
  theName(name),
  theDomainExpr(domainExpr),
  theKey(key),
  theAnnotations(aAnnotations)
{
#if 0
  // Note: the DeclPropertyList has bee validated already by the parser

  if (properties == NULL)
    return;

  ulong numProperties = (ulong)properties->size();
  for (ulong i = 0; i < numProperties; ++i)
  {
    const DeclProperty* property = properties->getProperty(i);
    StaticContextConsts::declaration_property_t prop = property->getProperty();

    switch (prop)
    {
    case StaticContextConsts::decl_unique:
    case StaticContextConsts::decl_non_unique:
      theIsUnique = (prop == StaticContextConsts::decl_unique);
      break;

    case StaticContextConsts::decl_value_equality:
    case StaticContextConsts::decl_value_range:
      theIsOrdered = (prop == StaticContextConsts::decl_value_range);
      break;

    case StaticContextConsts::decl_general_equality:
    case StaticContextConsts::decl_general_range:
      theIsGeneral = true;
      theIsOrdered = (prop == StaticContextConsts::decl_general_range);
      break;

    case StaticContextConsts::decl_manual:
    case StaticContextConsts::decl_automatic:
      theIsAutomatic = (prop == StaticContextConsts::decl_automatic);
      break;

    default: /* do nothing */ ;
    } // switch
  } // for
#endif
}


#if 0
Error const& AST_IndexDecl::validatePropertyList(DeclPropertyList* props)
{
  if (props == NULL)
    return zerr::ZXQP0000_NO_ERROR;

  bool setUnique = false;
  bool setUsage = false;
  bool setMaintenance = false;

  for (ulong i = 0; i < props->size(); ++i)
  {
    switch (props->getProperty(i)->getProperty())
    {
      case StaticContextConsts::decl_unique:
      case StaticContextConsts::decl_non_unique:
      {
        if (setUnique)
          return zerr::ZDST0024_INDEX_MULTIPLE_PROPERTY_VALUES;

        setUnique = true;
        break;
      }
      case StaticContextConsts::decl_value_equality:
      case StaticContextConsts::decl_value_range:
      case StaticContextConsts::decl_general_equality:
      case StaticContextConsts::decl_general_range:
      {
        if (setUsage)
          return zerr::ZDST0024_INDEX_MULTIPLE_PROPERTY_VALUES;

        setUsage = true;
        break;
      }
      case StaticContextConsts::decl_manual:
      case StaticContextConsts::decl_automatic:
      {
        if (setMaintenance)
          return zerr::ZDST0024_INDEX_MULTIPLE_PROPERTY_VALUES;

        setMaintenance = true;
        break;
      }
      default:
        return zerr::ZDST0026_INDEX_INVALID_PROPERTY_VALUE;
    }
  }

  return zerr::ZXQP0000_NO_ERROR;
}
#endif

void AST_IndexDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  ACCEPT(theDomainExpr);
  ACCEPT(theKey);

  END_VISITOR();
}


/***************************************************************************//**
  IndexKeyList ::= IndexKeySpec ("," IndexKeySpec)*
********************************************************************************/
void IndexKeyList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  for (vector<rchandle<IndexKeySpec> >::const_iterator i = theKeySpecs.begin();
       i != theKeySpecs.end();
       ++i)
  {
    ACCEPT(*i);
  }

  END_VISITOR();
}


/***************************************************************************//**
  IndexKeySpec ::= PathExpr "as" AtomicType IndexKeyOrderModifier

  IndexKeyOrderModifier ::= OrderDirSpec? OrderCollationSpec?

  OrderDirSpec ::= "ascending" | "descending"

  OrderCollationSpec ::= "collation" URILiteral
********************************************************************************/
void IndexKeySpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  ACCEPT(theExpr);
  ACCEPT(theType);

  END_VISITOR();
}


/*******************************************************************************
  IntegrityConstraintDecl ::= "declare" "integrity" "constraint"
      QName ICType
  ICType ::= ICCollSimpleCheck | ICCollUniqueKey | ICCollForeachNode |
             ICNodeOfType | ICForeighKey
  ICCollSimpleCheck ::= "on" "collection" QName "$" QName "check" ExprSimple
  ICCollUniqueKey   ::= "on" "collection" QNAME "$" QName "check" "unique"
                        "key" "(" Expr ")"
  ICCollForeachNode ::= "on" "collection" QNAME "foreach" "node" "$" QName
                        "check" ExprSingle
  ICNodeOfType      ::= "on" "node" QName "of""type" KindTest "check" ExprSingle
  ICForeighKey      ::= "on" "foreign" "key"
                        "from" "collection" QName "node" "$" QName "keys"
                           "(" Expr ")"
                        "to" "collection" QName "node" "$" QName "keys"
                           "(" Expr ")"
*******************************************************************************/
IntegrityConstraintDecl::IntegrityConstraintDecl (
    const QueryLoc& loc,
    QName* name,
    ICKind icKind)
  :
  parsenode(loc),
  theICName(name),
  theICKind(icKind)
{
}

/*void IntegrityConstraintDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
  }*/

void ICCollSimpleCheck::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(getExpr());
  END_VISITOR();
}

void ICCollUniqueKeyCheck::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(getExpr());
  END_VISITOR();
}

void ICCollForeachNode::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(getExpr());
  END_VISITOR();
}

void ICForeignKey::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(getFromExpr());
  ACCEPT_CHK(getToExpr());
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
QueryBody::QueryBody(const QueryLoc& loc, exprnode* expr)
  :
  exprnode(loc),
  theExpr(expr)
{
}


void QueryBody::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theExpr);
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
void BlockBody::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  for (ulong i = 0; i < size(); ++i)
    (*this)[i]->accept(v);

  END_VISITOR();
}


void BlockBody::add(parsenode* statement)
{
  if (dynamic_cast<VarDeclStmt*>(statement) != NULL)
  {
    VarDeclStmt* vdecl = static_cast<VarDeclStmt*>(statement);

    ulong numDecls = vdecl->size();

    for (ulong i = 0; i < numDecls; ++i)
    {
      theStatements.push_back(vdecl->getDecl(i));
    }

    delete vdecl;
  }
  else
  {
    theStatements.push_back(statement);
  }
}


/*******************************************************************************

********************************************************************************/
VarDeclStmt::VarDeclStmt(const QueryLoc& loc, AnnotationListParsenode* annotations)
  :
  exprnode(loc),
  theAnnotations(annotations)
{
}

void VarDeclStmt::add(parsenode* decl)
{
  VarDecl* varDecl = dynamic_cast<VarDecl*>(decl);
  if (varDecl != NULL)
  {
    varDecl->set_annotations(theAnnotations);
  }

  theDecls.push_back(decl);
}

void VarDeclStmt::accept(parsenode_visitor& v) const
{
  assert(false);
}


/*******************************************************************************

********************************************************************************/
void AssignExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theValue);
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
void ApplyExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  ACCEPT(theExpr);

  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
void ExitExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(theValue);
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
void WhileExpr::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT (cond);
  ACCEPT (body);
  END_VISITOR();
}


/*******************************************************************************

********************************************************************************/
void FlowCtlStatement::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************
  Expr ::= ExprSingle | Expr  COMMA  ExprSingle
********************************************************************************/
Expr::Expr(const QueryLoc& loc)
  :
  exprnode(loc)
{
}


void Expr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  vector<rchandle<exprnode> >::const_reverse_iterator it = expr_hv.rbegin();
  for (; it != expr_hv.rend(); ++it)
  {
    const exprnode* e_p = &**it;
    ACCEPT_CHK(e_p);
  }

  END_VISITOR();
}


int Expr::numberOfChildren() const
{
  return (int)expr_hv.size();
}


FLWORExpr::FLWORExpr(
    const QueryLoc& loc_,
    rchandle<FLWORClauseList> clauses_,
    rchandle<exprnode> ret_,
    const QueryLoc& return_loc_,
    bool force_general)
  :
  exprnode (loc_),
  clauses (clauses_),
  return_val_h (ret_),
  return_location(return_loc_)
{
  for (unsigned i = 0; i < clauses->size (); i++)
  {
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

  compute_general ();

  if (force_general)
    general = true;
}


void FLWORExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (clauses);
  ACCEPT (return_val_h);
  END_VISITOR();
}


template<class T> void get_flwor_clause (const FLWORExpr &f, T **p)
{
  *p = NULL;
  rchandle<FLWORClauseList> clauses = f.get_clause_list ();
  for (unsigned i = 0; i < clauses->size (); i++)
  {
    FLWORClause* cp = (*clauses) [i].getp ();
    *p = dynamic_cast<T *> (cp);
    if (*p != NULL)
      return;
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



//#define ZORBA_FORCE_GFLWOR


void FLWORExpr::compute_general ()
{
  general = non_10 = false;
#ifdef ZORBA_FORCE_GFLWOR
  general = true;
#endif

  bool has_where = false, has_order = false, has_group = false;

  for (unsigned i = 0; i < clauses->size(); i++)
  {
    const FLWORClause* cp = (*clauses)[i].getp();

    if (typeid (*cp) == typeid (ForClause))
    {
      // any preceding non-initial clause triggers GFLWOR
      if (has_group || has_where || has_order)
        non_10 = general = true;

      const ForClause* fc = static_cast<const ForClause*>(cp);
      for (int j=0; j<fc->get_decl_count(); j++)
      {
        if (fc->get_vardecl_list()->operator[](j)->get_allowing_empty())
          non_10 = general = true;
      }
    }
    else if (typeid (*cp) == typeid (LetClause))
    {
      // any preceding non-initial clause triggers GFLWOR
      if (has_group || has_where || has_order)
        non_10 = general = true;
    }
    else if (typeid (*cp) == typeid (WindowClause))
    {
      non_10 = general =true;
    }
    else if (typeid (*cp) == typeid (WhereClause))
    {
      if (has_where || has_group || has_order) non_10 = general = true;
      has_where = true;
    }
    else if (typeid (*cp) == typeid (OrderByClause))
    {
      if (has_order) non_10 = general = true;
      has_order = true;
    }
    else if (typeid (*cp) == typeid (GroupByClause))
    {
      if (has_group || has_order) non_10 = general = true;
      has_group = true;
    }
    else if (typeid (*cp) == typeid (CountClause))
    {
      non_10 = general = true;
    }
  }
}


/*******************************************************************************
  WindowClause ::= "for" (TumblingWindowClause | SlidingWindowClause)

  TumblingWindowClause ::= "tumbling" "window" WindowVarDecl
                           WindowStartCondition WindowEndCondition?

  SlidingWindowClause ::= "sliding" "window" WindowVarDecl
                          WindowStartCondition WindowEndCondition
********************************************************************************/
void WindowClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  ACCEPT(var->get_initexpr());

  v.intermediate_visit(*this, visitor_state);

  for (int i = 0; i < 2; i++)
    ACCEPT(conditions [i]);

  ACCEPT(var);

  END_VISITOR();
}


/*******************************************************************************
  WindowVarDecl ::= "$" VarName TypeDeclaration? "in"  ExprSingle
********************************************************************************/
void WindowVarDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theType);
  // The domain expr has been translated already.
  END_VISITOR();
}


/*******************************************************************************
  WindowStartCondition ::= "start" WindowVars "when" ExprSingle

  WindowEndCondition ::= "only"? "end" WindowVars "when" ExprSingle
********************************************************************************/
void FLWORWinCond::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(get_winvars());
  ACCEPT(get_val());
  END_VISITOR();
}


/*******************************************************************************
  WindowVars ::= ("$" CurrentItem)? PositionalVar?
                 ("previous" "$" PreviousItem)?
                 ("next" "$" NextItem)?
********************************************************************************/
void WindowVars::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(posvar);
  END_VISITOR();
}



FLWORClauseList::FLWORClauseList(const QueryLoc& loc)
  :
  parsenode(loc)
{
}


void FLWORClauseList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<FLWORClause> >::const_iterator it = theClauses.begin();
  for (; it != theClauses.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}



// [34] ForClause
// --------------
ForClause::ForClause(
  const QueryLoc& loc_,
  rchandle<VarInDeclList> _vardecl_list_h)
:
  ForOrLetClause(loc_),
  vardecl_list_h(_vardecl_list_h),
  allowing_empty(false)
{
  for (unsigned int j=0; j<_vardecl_list_h->size(); j++)
  {
    if (_vardecl_list_h->operator[](j)->get_allowing_empty())
      allowing_empty = true;
  }
}


//-ForClause::

void ForClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (vardecl_list_h);
  END_VISITOR();
}

int ForClause::get_decl_count () const { return (int)vardecl_list_h->size (); }


// [34a] VarInDeclList
// -------------------
VarInDeclList::VarInDeclList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-VarInDeclList::

void VarInDeclList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<VarInDecl> >::const_iterator it = vardecl_hv.begin();
  for (; it!=vardecl_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [34b] VarInDecl
// ---------------
VarInDecl::VarInDecl(
  const QueryLoc& loc,
  rchandle<QName> varname,
  rchandle<SequenceType> typedecl_h,
  rchandle<PositionalVar> _posvar_h,
  rchandle<FTScoreVar> _ftscorevar_h,
  rchandle<exprnode> valexpr_h,
  bool _allowing_empty)
:
  VarDeclWithInit (loc, varname, typedecl_h, valexpr_h),
  posvar_h(_posvar_h),
  ftscorevar_h(_ftscorevar_h),
  allowing_empty(_allowing_empty)
{
}


void VarInDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theType);
  ACCEPT(posvar_h);
  ACCEPT(ftscorevar_h);
  ACCEPT(get_initexpr());
  END_VISITOR();
}


// [35] PositionalVar
// ------------------
PositionalVar::PositionalVar(
  const QueryLoc& loc,
  rchandle<QName> varname)
:
  parsenode(loc),
  theName(varname)
{
}


void PositionalVar::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void LetClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (vardecl_list_h);
  END_VISITOR();
}

int LetClause::get_decl_count () const { return (int)vardecl_list_h->size (); }


// [36a] VarGetsDeclList
// ---------------------
VarGetsDeclList::VarGetsDeclList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void VarGetsDeclList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<VarGetsDecl> >::const_iterator it = vardecl_hv.begin();
  for (; it!=vardecl_hv.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [36b] VarGetsDecl
// ------------------

void VarGetsDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theType);
  ACCEPT(ftscorevar_h);
  ACCEPT(get_initexpr());
  END_VISITOR();
}


FTScoreVar::FTScoreVar(
  QueryLoc const &loc,
  rchandle<QName> _var_name_h)
  :
  parsenode( loc ),
  var_name_h(_var_name_h)
{
}


void FTScoreVar::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void WhereClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (predicate_h);
  END_VISITOR();
}


void CountClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}

GroupByClause::GroupByClause(
  const QueryLoc& loc_,
  rchandle<GroupSpecList> _spec_list_h)
:
  FLWORClause(loc_),
  spec_list_h(_spec_list_h)
{
}

void GroupByClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (spec_list_h);
  END_VISITOR();
}


GroupSpecList::GroupSpecList(const QueryLoc& loc)
  :
  parsenode(loc)
{
}


void GroupSpecList::push_back(rchandle<GroupSpec> spec)
{
  vector<rchandle<GroupSpec> >::const_iterator ite = theSpecs.begin();
  vector<rchandle<GroupSpec> >::const_iterator end = theSpecs.end();

  //If no expression is given, then it'll just be the variable.
  //If this is the case, and the variable is already defined as a
  //grouping variable, it makes no sense to add it, so this is a
  //quick optimization.
  if(spec->get_var_expr() == NULL)
  {
    for (; ite != end; ++ite)
    {
      const GroupSpec* currSpec = (*ite).getp();

      if (*currSpec->get_var_name() == *spec->get_var_name() &&
          currSpec->get_var_expr() == NULL)
        break;
    }

    if (ite == end)
      theSpecs.push_back(spec);
  }
  else
  {
    theSpecs.push_back(spec);
  }
}


void GroupSpecList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  vector<rchandle<GroupSpec> >::const_iterator it = theSpecs.begin();
  for (; it != theSpecs.end(); ++it)
  {
    const GroupSpec* e_p = &**it;
    ACCEPT_CHK (e_p);
  }

  END_VISITOR();
}


GroupSpec::GroupSpec(
  const QueryLoc& loc_,
  rchandle<QName> _var_name_h,
  rchandle<SequenceType> _var_type_h,
  rchandle<exprnode> _var_value_h,
  rchandle<GroupCollationSpec> _group_coll_spec_h)
  :
  parsenode(loc_),
  var_name_h(_var_name_h),
  var_type_h(_var_type_h),
  var_init_expr_h(_var_value_h),
  group_coll_spec_h(_group_coll_spec_h)
{
}


void GroupSpec::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT (var_type_h);
  ACCEPT (group_coll_spec_h);
  ACCEPT (var_init_expr_h);
  END_VISITOR();
}

GroupCollationSpec::GroupCollationSpec(
  const QueryLoc& loc_,
  const zstring& _uri)
  :
  parsenode(loc_),
  uri(_uri)
{
}


void GroupCollationSpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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
{
}


void OrderByClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(spec_list_h);
  END_VISITOR();
}


// [39] OrderSpecList
// ------------------
OrderSpecList::OrderSpecList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void OrderSpecList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<OrderSpec> >::const_iterator it = spec_hv.begin();
  for (; it!=spec_hv.end(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [40] OrderSpec
// --------------
OrderSpec::OrderSpec(
    const QueryLoc& loc_,
    exprnode* _spec_h,
    OrderModifierPN* _modifier_h)
  :
  parsenode(loc_),
  spec_h(_spec_h),
  modifier_h(_modifier_h)
{
}


void OrderSpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (spec_h);
  ACCEPT (modifier_h);
  END_VISITOR();
}


// [41] OrderModifier
// ------------------
OrderModifierPN::OrderModifierPN(
    const QueryLoc& loc_,
    OrderDirSpec* _dir_spec_h,
    OrderEmptySpec* _empty_spec_h,
    OrderCollationSpec* _collation_spec_h)
  :
  parsenode(loc_),
  dir_spec_h(_dir_spec_h),
  empty_spec_h(_empty_spec_h),
  collation_spec_h(_collation_spec_h)
{
}


void OrderModifierPN::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (dir_spec_h);
  ACCEPT (empty_spec_h);
  ACCEPT (collation_spec_h);
  END_VISITOR();
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

void OrderDirSpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [41b] OrderEmptySpec
// --------------------
OrderEmptySpec::OrderEmptySpec(
  const QueryLoc& loc_,
  StaticContextConsts::empty_order_mode_t _empty_order_spec)
:
  parsenode(loc_),
  empty_order_spec(_empty_order_spec)
{}


//-OrderEmptySpec::

void OrderEmptySpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [41c] OrderCollationSpec
// ------------------------
OrderCollationSpec::OrderCollationSpec(
  const QueryLoc& loc_,
  zstring const& _uri)
:
  parsenode(loc_),
  uri(_uri)
{}


//-OrderCollationSpec::

void OrderCollationSpec::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void QuantifiedExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (decl_list_h);
  ACCEPT (expr_h);
  END_VISITOR();
}


// [42a] QVarInDeclList
// --------------------
QVarInDeclList::QVarInDeclList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void QVarInDeclList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  std::for_each (qvar_decl_hv.begin (), qvar_decl_hv.end (), visitor_functor (v));
  END_VISITOR();
}


// [42b] QVarInDecl
// ----------------
QVarInDecl::QVarInDecl(
  const QueryLoc& loc_,
  rchandle<QName> _name,
  rchandle<exprnode> _val_h)
  :
  parsenode(loc_),
  name(_name),
  typedecl_h(NULL),
  val_h(_val_h)
{
}


QVarInDecl::QVarInDecl(
  const QueryLoc& loc_,
  rchandle<QName> _name,
  rchandle<SequenceType> _typedecl_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  name(_name),
  typedecl_h(_typedecl_h),
  val_h(_val_h)
{
}


void QVarInDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (val_h);
  ACCEPT (typedecl_h);
  END_VISITOR();
}


// [71] SwitchExpr
// -------------------
SwitchExpr::SwitchExpr(
  const QueryLoc& loc_,
  rchandle<exprnode> _switch_expr_h,
  rchandle<SwitchCaseClauseList> _clause_list_h,
  rchandle<exprnode> _default_expr_h)
:
  exprnode(loc_),
  switch_expr_h(_switch_expr_h),
  clause_list_h(_clause_list_h),
  default_expr_h(_default_expr_h)
{}

void SwitchExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(switch_expr_h);
  ACCEPT_CHK(default_expr_h);
  ACCEPT_CHK(clause_list_h);
  END_VISITOR();
}


// [71a] SwitchCaseClauseList
// --------------------
SwitchCaseClauseList::SwitchCaseClauseList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{
}

void SwitchCaseClauseList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<SwitchCaseClause> >::const_reverse_iterator it = clause_hv.rbegin();
  for (; it!=clause_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [72] SwitchCaseClause
// -------------------
SwitchCaseClause::SwitchCaseClause(
  const QueryLoc& loc_,
  rchandle<SwitchCaseOperandList> _operand_list_h,
  rchandle<exprnode> _return_expr_h)
:
  exprnode(loc_),
  operand_list_h(_operand_list_h),
  return_expr_h(_return_expr_h)
{}

void SwitchCaseClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK(return_expr_h);
  ACCEPT_CHK(operand_list_h);
  END_VISITOR();
}

// [72a] SwitchCaseOperandList
// --------------------
SwitchCaseOperandList::SwitchCaseOperandList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{
}

void SwitchCaseOperandList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<exprnode> >::const_reverse_iterator it = operand_hv.rbegin();
  for (; it!=operand_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
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
  rchandle<QName> _default_varname,
  rchandle<exprnode> _default_clause_h)
:
  exprnode(loc_),
  switch_expr_h(_switch_expr_h),
  clause_list_h(_clause_list_h),
  default_varname(_default_varname),
  default_clause_h(_default_clause_h)
{}


//-TypeswitchExpr::

void TypeswitchExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_CHK (switch_expr_h);
  ACCEPT_CHK (default_clause_h);
  ACCEPT_CHK (clause_list_h);

  END_VISITOR();
}


// [43a] CaseClauseList
// --------------------
CaseClauseList::CaseClauseList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{
}


void CaseClauseList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<CaseClause> >::const_reverse_iterator it = clause_hv.rbegin();
  for (; it!=clause_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [44] CaseClause
// ---------------
CaseClause::CaseClause(
  const QueryLoc& loc_,
  rchandle<QName> _varname,
  rchandle<SequenceType> _type_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  varname(_varname),
  type_h(_type_h),
  val_h(_val_h)
{
}

CaseClause::CaseClause(
  const QueryLoc& loc_,
  rchandle<SequenceType> _type_h,
  rchandle<exprnode> _val_h)
:
  parsenode(loc_),
  varname(NULL),
  type_h(_type_h),
  val_h(_val_h)
{
}


void CaseClause::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (type_h);
  ACCEPT (val_h);
  END_VISITOR();
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

void IfExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (cond_expr_h);
  ACCEPT (then_expr_h);
  ACCEPT (else_expr_h);
  END_VISITOR();
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

void OrExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (or_expr_h);
  ACCEPT (and_expr_h);
  END_VISITOR();
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

void AndExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (and_expr_h);
  ACCEPT (comp_expr_h);
  END_VISITOR();
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

void ComparisonExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (gencomp_h);
  ACCEPT (nodecomp_h);
  ACCEPT (valcomp_h);
  ACCEPT (left_h);
  ACCEPT (right_h);
  END_VISITOR();
}


FTContainsExpr::FTContainsExpr(
  QueryLoc const &loc,
  exprnode const *range_expr,
  FTSelection const *ftselection,
  FTIgnoreOption const *ftignore
) :
  exprnode( loc ),
  range_expr_( range_expr ),
  ftselection_( ftselection ),
  ftignore_( ftignore )
{
  ZORBA_ASSERT( range_expr );
}

FTContainsExpr::~FTContainsExpr() {
  delete range_expr_;
  delete ftselection_;
  delete ftignore_;
}

void FTContainsExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( range_expr_ );
  ACCEPT( ftselection_ );
  ACCEPT( ftignore_ );
  END_VISITOR();
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

void RangeExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (from_expr_h);
  ACCEPT (to_expr_h);
  END_VISITOR();
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

void AdditiveExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (add_expr_h);
  ACCEPT (mult_expr_h);
  END_VISITOR();
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

void MultiplicativeExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (mult_expr_h);
  ACCEPT (union_expr_h);
  END_VISITOR();
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

void UnionExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (union_expr_h);
  ACCEPT (intex_expr_h);
  END_VISITOR();
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

void IntersectExceptExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (intex_expr_h);
  ACCEPT (instof_expr_h);
  END_VISITOR();
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

void InstanceofExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (treat_expr_h);
  ACCEPT (seqtype_h);
  END_VISITOR();
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

void TreatExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (castable_expr_h);
  ACCEPT (seqtype_h);
  END_VISITOR();
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

void CastableExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (cast_expr_h);
  ACCEPT (singletype_h);
  END_VISITOR();
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

void CastExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (unary_expr_h);
  ACCEPT (singletype_h);
  END_VISITOR();
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

void UnaryExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (signlist_h);
  ACCEPT (value_expr_h);
  END_VISITOR();
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

void SignList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void GeneralComp::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void ValueComp::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void NodeComp::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [63] ValidateExpr
// -----------------
ValidateExpr::ValidateExpr(
  const QueryLoc& loc_,
  zstring const& _valmode,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  valmode(_valmode=="lax" ? ParseConstants::val_lax : ParseConstants::val_strict),
  expr_h(_expr_h)
{}

ValidateExpr::ValidateExpr(
  const QueryLoc& loc_,
  rchandle<QName> _valmode,
  rchandle<exprnode> _expr_h)
:
  exprnode(loc_),
  expr_h(_expr_h)
{
  if (_valmode->get_qname() == "lax")
    valmode = ParseConstants::val_lax;
  else if (_valmode->get_qname() == "strict")
    valmode = ParseConstants::val_strict;
  else
  {
    valmode = ParseConstants::val_typename;
    type_name = _valmode;
  }
}


//-ValidateExpr::

void ValidateExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
}


// [65]
ExtensionExpr::ExtensionExpr(
  const QueryLoc& loc_,
  rchandle<PragmaList> const &pragmas,
  rchandle<exprnode> const &expr)
:
  exprnode(loc_),
  pragmas_(pragmas),
  expr_(expr)
{}


//-ExtensionExpr::

void ExtensionExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (pragmas_);
  ACCEPT (expr_);
  END_VISITOR();
}


// [65a] PragmaList
// ----------------
PragmaList::PragmaList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-PragmaList::

void PragmaList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  list_t::const_reverse_iterator it = pragmas_.rbegin();
  for ( ; it != pragmas_.rend(); ++it ) {
    const parsenode *const p = *it;
    ACCEPT_CHK(p);
  }
  END_VISITOR();
}


// [66] Pragma
// -----------
Pragma::Pragma(
  const QueryLoc& loc_,
  rchandle<QName> _name_h,
  zstring const &_pragma_lit)
:
  parsenode(loc_),
  name_h(_name_h),
  pragma_lit(_pragma_lit)
{
}


//-Pragma::

void Pragma::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //name->accept(v);
  END_VISITOR();
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


void PathExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (relpath_expr_h);
  END_VISITOR();
}


/*******************************************************************************

  [69] RelativePathExpr ::= StepExpr |
                            StepExpr  SLASH  RelativePathExpr |
                            StepExpr  SLASH_SLASH  RelativePathExpr

  Note: for the 1st alternative production, a RelativePathExpr node is generated
  whose left child is a ContextItemExpr and its right child is the StepExpr.

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
    {
      // step/  ./...  --> step/...
      // step/  .//... --> step//...
      relpath_expr_h = rpep->relpath_expr_h;
      if (!dot->is_placeholder())
        step_type = rpep->get_step_type();
    }
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


void RelativePathExpr::accept( parsenode_visitor &v ) const
{
  void* visitor_state = v.begin_visit(*this);

  if (visitor_state == NULL)
  {
    return;
  }

  ACCEPT (step_expr_h);
  v.intermediate_visit(*this, visitor_state);
  ACCEPT (relpath_expr_h);
  END_VISITOR();
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
{
}


enum ParseConstants::axis_kind_t AxisStep::get_axis_kind() const
{
  if (forward_step_h)
    return forward_step_h->get_axis_kind();

  return reverse_step_h->get_axis_kind();
}


void AxisStep::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();

  if (forward_step_h != NULL) forward_step_h->accept(v);
  if (reverse_step_h != NULL) reverse_step_h->accept(v);

  v.post_axis_visit(*this, visitor_state);

  if (predicate_list_h != NULL) predicate_list_h->accept(v);

  END_VISITOR();
}


/*******************************************************************************

   [72] ForwardStep ::= ForwardAxis  NodeTest | AbbrevForwardStep

********************************************************************************/
ForwardStep::ForwardStep(
    const QueryLoc& loc,
    rchandle<ForwardAxis> forward_axis,
    rchandle<parsenode> node_test)
  :
  parsenode(loc),
  theForwardAxis(forward_axis),
  node_test_h(node_test),
  theAbbrevStep(NULL)
{
}


ForwardStep::ForwardStep(
    const QueryLoc& loc,
    rchandle<AbbrevForwardStep> abbrev_step)
  :
  parsenode(loc),
  theForwardAxis(NULL),
  node_test_h(NULL),
  theAbbrevStep(abbrev_step)
{
}


enum ParseConstants::axis_kind_t ForwardStep::get_axis_kind() const
{
  if (theForwardAxis)
    return theForwardAxis->get_axis();

  return (theAbbrevStep->get_attr_bit() ?
          ParseConstants::axis_attribute :
          ParseConstants::axis_child);
}


void ForwardStep::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  if (theForwardAxis != NULL) theForwardAxis->accept(v);
  if (node_test_h != NULL) node_test_h->accept(v);
  if (theAbbrevStep != NULL) theAbbrevStep->accept(v);
  END_VISITOR();
}


/*******************************************************************************

  [73] ForwardAxis ::= CHILD_AXIS | ....

********************************************************************************/
ForwardAxis::ForwardAxis(
    const QueryLoc& loc_,
    enum ParseConstants::axis_kind_t _axis)
  :
  parsenode(loc_),
  axis(_axis)
{
}


void ForwardAxis::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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
{
}


void AbbrevForwardStep::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  if (node_test_h!=NULL) node_test_h->accept(v);
  END_VISITOR();
}


/*******************************************************************************

  [75] ReverseStep ::= ReverseAxis  NodeTest |  DOT_DOT

********************************************************************************/
ReverseStep::ReverseStep(
    const QueryLoc& loc,
    rchandle<ReverseAxis> _axis_h,
    rchandle<parsenode> _node_test_h)
  :
  parsenode(loc),
  axis_h(_axis_h),
  node_test_h(_node_test_h)
{
  if (node_test_h == NULL)
  {
    node_test_h = new AnyKindTest(loc);
  }
}


enum ParseConstants::axis_kind_t ReverseStep::get_axis_kind() const
{
  return axis_h->get_axis();
}


void ReverseStep::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  if (axis_h!=NULL) axis_h->accept(v);
  if (node_test_h!=NULL) node_test_h->accept(v);
  END_VISITOR();
}


/*******************************************************************************

 [76] ReverseAxis ::= PARENT_AXIS | ....

********************************************************************************/
ReverseAxis::ReverseAxis(
    const QueryLoc& loc_,
    enum ParseConstants::axis_kind_t _axis)
  :
  parsenode(loc_),
  axis(_axis)
{}


void ReverseAxis::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void NameTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


/*******************************************************************************

  [80] Wildcard ::= STAR | ELEM_WILDCARD | PREFIX_WILDCARD

********************************************************************************/
Wildcard::Wildcard(
  const QueryLoc& loc,
  const zstring& nsOrPrefix,
  const zstring& lname,
  enum ParseConstants::wildcard_t kind,
  bool isEQnameMatch)
  :
  parsenode(loc),
  theKind(kind),
  theNsOrPrefix(nsOrPrefix),
  theLocalName(lname),
  theIsEQnameMatch(isEQnameMatch)
{
}


void Wildcard::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void FilterExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  ACCEPT (primary_h);
  v.post_primary_visit(*this, visitor_state);
  ACCEPT (pred_list_h);

  END_VISITOR();
}


// [82] PredicateList

PredicateList::PredicateList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void PredicateList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  for (vector<rchandle<exprnode> >::const_iterator it = pred_hv.begin();
       it!=pred_hv.end(); ++it)
  {
    const exprnode* e_p = &**it;
    ZORBA_ASSERT(e_p!=NULL);
    v.pre_predicate_visit(*this, visitor_state);
    e_p->accept(v);
    v.post_predicate_visit(*this, visitor_state);
  }
  END_VISITOR();
}


// [83] Predicate
// --------------

// [84] PrimaryExpr
// ----------------

// [85] Literal
// ------------
Literal::Literal(exprnode* expression)
  :
  exprnode(expression->get_location()),
  numeric_literal(NULL),
  string_literal(NULL),
  type((LITERAL_TYPE)0)
{
  StringLiteral* sl = dynamic_cast<StringLiteral*>(expression);
  if (sl != NULL)
  {
    string_literal = sl;
    type = (LITERAL_TYPE)1;
  }
  else
    numeric_literal = expression;
}

void Literal::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [86] NumericLiteral
// -------------------
void NumericLiteral::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [87] VarRef
// -----------
VarRef::VarRef(
  const QueryLoc& loc,
  rchandle<QName> name)
:
  exprnode(loc),
  theName(name)
{
}


void VarRef::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void ParenthesizedExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
}


// [90] ContextItemExpr
// --------------------
ContextItemExpr::ContextItemExpr(
  const QueryLoc& loc_, bool _placeholder)
:
  exprnode(loc_),
  placeholder(_placeholder)
{}


//-ContextItemExpr::

void ContextItemExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void OrderedExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
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

void UnorderedExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
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

void FunctionCall::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //fname_h->accept(v);
  ACCEPT (arg_list_h);
  END_VISITOR();
}


// [93a] ArgList
// -------------
ArgList::ArgList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-ArgList::

void ArgList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<exprnode> >::const_iterator it = arg_hv.begin();
  for (; it!=arg_hv.end(); ++it) {
    const exprnode* e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [94] Constructor
// ----------------

/*******************************************************************************
  EnclosedExpr ::= "{" Expr "}"
********************************************************************************/
EnclosedExpr::EnclosedExpr(
    const QueryLoc& loc_,
    rchandle<exprnode> _expr_h)
  :
  exprnode(loc_),
  expr_h(_expr_h)
{
}


void EnclosedExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
}


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

void DirElemConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //open_name_h->accept(v);
  //close_name_h->accept(v);

  if( attr_list_h != NULL )
      attr_list_h->accept(v);

  ACCEPT (dir_content_list_h);
  END_VISITOR();
}


// [96a] DirElemContentList
// ------------------------
DirElemContentList::DirElemContentList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-DirElemContentList::

void DirElemContentList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
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
  END_VISITOR();
}


// [97] DirAttributeList

DirAttributeList::DirAttributeList(
  const QueryLoc& loc)
:
  parsenode(loc)
{}


void DirAttributeList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<DirAttr> >::const_iterator it = theAttributes.begin();
  for (; it != theAttributes.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
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


void DirAttr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theValue);
  END_VISITOR();
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

void DirAttributeValue::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (quot_attr_content_h);
  ACCEPT (apos_attr_content_h);
  END_VISITOR();
}


// [98a] QuoteAttrContentList
// --------------------------
QuoteAttrContentList::QuoteAttrContentList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-QuoteAttrContentList::

void QuoteAttrContentList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<QuoteAttrValueContent> >::const_reverse_iterator it =
    quot_atval_content_hv.rbegin();
  for (; it!=quot_atval_content_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [98b] AposAttrContentList
// -------------------------
AposAttrContentList::AposAttrContentList(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


//-AposAttrContentList::

void AposAttrContentList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<AposAttrValueContent> >::const_reverse_iterator it =
    apos_atval_content_hv.rbegin();
  for (; it!=apos_atval_content_hv.rend(); ++it) {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


// [99] QuotAttrValueContent
// -------------------------
QuoteAttrValueContent::QuoteAttrValueContent(
  const QueryLoc& loc_,
  zstring _quot_atcontent)
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

void QuoteAttrValueContent::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (common_content_h);
  END_VISITOR();
}


// [100] AposAttrValueContent
// --------------------------
AposAttrValueContent::AposAttrValueContent(
  const QueryLoc& loc_,
  zstring _apos_atcontent)
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

void AposAttrValueContent::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (common_content_h);
  END_VISITOR();
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
  zstring _elem_content)
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

void DirElemContent::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  ACCEPT (direct_cons_h);

  ACCEPT (cdata_h);

  ACCEPT (common_content_h);
  END_VISITOR();
}


// [102] CommonContent
// -------------------
CommonContent::CommonContent(
  const QueryLoc& loc_,
  enum ParseConstants::common_content_t _type,
  zstring const &_ref)
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

void CommonContent::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
}


// [103] DirCommentConstructor
// ---------------------------
DirCommentConstructor::DirCommentConstructor(
  const QueryLoc& loc_,
  zstring const& _comment)
:
  exprnode(loc_),
  comment(_comment)
{}


//-DirCommentConstructor::

void DirCommentConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [104] DirCommentContents
// ------------------------
/* lexical rule */


// [105] DirPIConstructor
// ----------------------
DirPIConstructor::DirPIConstructor(
  const QueryLoc& loc_,
  zstring const& _pi_target)
:
  exprnode(loc_),
  pi_target(_pi_target),
  pi_content("")
{}

DirPIConstructor::DirPIConstructor(
  const QueryLoc& loc_,
  zstring const& _pi_target,
  zstring const& _pi_content)
:
  exprnode(loc_),
  pi_target(_pi_target),
  pi_content(_pi_content)
{}


//-DirPIConstructor::

void DirPIConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [106] DirPIContents
// -------------------
/* lexical rule */


// [107] CDataSection
// ------------------
CDataSection::CDataSection(
  const QueryLoc& loc_,
  zstring const& _cdata_content)
:
  exprnode(loc_),
  cdata_content(_cdata_content)
{}


//-CDataSection::

void CDataSection::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void CompDocConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr_h);
  END_VISITOR();
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


void CompElemConstructor::accept( parsenode_visitor &v ) const
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


void CompAttrConstructor::accept( parsenode_visitor &v ) const
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


void CompTextConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (text_expr_h);
  END_VISITOR();
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

void CompCommentConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (comment_expr_h);
  END_VISITOR();
}


// [116] CompPIConstructor
// -----------------------
CompPIConstructor::CompPIConstructor(
  const QueryLoc& loc_,
  zstring const& _target,
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

void CompPIConstructor::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (target_expr_h);
  ACCEPT (content_expr_h);
  END_VISITOR();
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


void SingleType::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (atomic_type_h);
  END_VISITOR();
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

void SequenceType::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (itemtype_h);
  ACCEPT (occur_h);
  END_VISITOR();
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

void OccurrenceIndicator::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void ItemType::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void AtomicType::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //qname_h->accept(v);
  END_VISITOR();
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


void AnyKindTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [125] DocumentTest
// ------------------
DocumentTest::DocumentTest(const QueryLoc& loc)
  :
  parsenode(loc),
  elem_test_h(NULL),
  schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(const QueryLoc& loc, rchandle<ElementTest> _elem_test_h)
  :
  parsenode(loc),
  elem_test_h(_elem_test_h),
  schema_elem_test_h(NULL)
{
}

DocumentTest::DocumentTest(
    const QueryLoc& loc,
    rchandle<SchemaElementTest> _schema_elem_test_h)
  :
  parsenode(loc),
  elem_test_h(NULL),
  schema_elem_test_h(_schema_elem_test_h)
{
}


void DocumentTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(elem_test_h);
  ACCEPT(schema_elem_test_h);
  END_VISITOR();
}


// [126] TextTest
// --------------
TextTest::TextTest(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void TextTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


// [127] CommentTest
// -----------------
CommentTest::CommentTest(
  const QueryLoc& loc_)
:
  parsenode(loc_)
{}


void CommentTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}



// [128] PITest

PITest::PITest(
  const QueryLoc& loc_,
  zstring const& _target)
:
  parsenode(loc_),
  target(_target)
{}


void PITest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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


void AttributeTest::accept( parsenode_visitor &v ) const
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

void SchemaAttributeTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //if (attr_h!=NULL) attr_h->accept(v);
  END_VISITOR();
}


/*******************************************************************************

  ElementTest ::= ELEMENT_LPAR  RPAR |
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


void ElementTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void SchemaElementTest::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //if (elem_h!=NULL) elem_h->accept(v);
  END_VISITOR();
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

void TypeName::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  //if (qname_h!=NULL) qname_h->accept(v);
  END_VISITOR();
}

void StringConcatExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (left);
  ACCEPT (right);
  END_VISITOR();
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
  zstring const& _strval)
:
  exprnode(loc_),
  strval(_strval)
{}


//-StringLiteral::

void StringLiteral::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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
  const QueryLoc& loc,
  const zstring& qname,
  bool isEQName)
  :
  exprnode(loc),
  theQName(qname),
  theIsEQName(isEQName)
{
  zstring::size_type n = qname.rfind(':');

  if (n == zstring::npos)
  {
    theNamespace = "";
    thePrefix = "";
    theLocalName = qname;
  }
  else if (theIsEQName)
  {
    theNamespace = qname.substr(0, n);
    thePrefix = "";
    theLocalName = qname.substr(n+1);
  }
  else
  {
    theNamespace = "";
    thePrefix = qname.substr(0, n);
    theLocalName = qname.substr(n+1);
  }
}


void QName::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


bool QName::operator==(const QName& other) const
{
  if (theIsEQName != other.theIsEQName)
    return false;

  if (theIsEQName)
  {
    return (theLocalName == other.theLocalName &&
            theNamespace == other.theNamespace);
  }
  else
  {
    return (theLocalName == other.theLocalName &&
            thePrefix == other.thePrefix);
  }
}


/*
**
**  Update productions
**  [http:://www.w3.org/TR/xqupdate/]
**
*/

// [241]  RevalidationDecl
// -----------------------

//-RevalidationDecl::

void RevalidationDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
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

void InsertExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theSourceExpr);
  ACCEPT(theTargetExpr);
  END_VISITOR();
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

void DeleteExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (theTargetExpr);
  END_VISITOR();
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

void ReplaceExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (theTargetExpr);
  ACCEPT (theReplaceExpr);
  END_VISITOR();
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

void RenameExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (theTargetExpr);
  ACCEPT (theNameExpr);
  END_VISITOR();
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


/*******************************************************************************
  TransformExpr := "copy" "$" CopyVarList "modify" ExprSingle "return"  ExprSingle

  CopyVarList := VarBinding |	CopyVarList "," "$"  VarBinding
********************************************************************************/
TransformExpr::TransformExpr(
  const QueryLoc& loc,
  rchandle<CopyVarList> var_list_h,
  rchandle<exprnode> source_expr_h,
  rchandle<exprnode> target_expr_h)
  :
  exprnode(loc),
  var_list(var_list_h),
  source_expr(source_expr_h),
  target_expr(target_expr_h)
{
}


void TransformExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (var_list);
  ACCEPT (source_expr);
  ACCEPT (target_expr);
  END_VISITOR();
}


CopyVarList::CopyVarList(const QueryLoc& loc)
  :
  exprnode(loc)
{
}


void CopyVarList::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  vector<rchandle<VarBinding> >::const_iterator it;
  for (it = var_bindings.begin(); it != var_bindings.end(); ++it)
  {
    const parsenode *e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR();
}


VarBinding::VarBinding(
  const QueryLoc& loc,
  rchandle<QName> varname,
  rchandle<exprnode> expr_h)
  :
  exprnode(loc),
  var_name(varname),
  expr(expr_h)
{
}


void VarBinding::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT (expr);
  END_VISITOR();
}


// TryExpr
// ---
void TryExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT(theExprSingle);
  ACCEPT(theCatchListExpr);
  END_VISITOR();
}

// CatchListExpr
// -------------
void CatchListExpr::accept( parsenode_visitor &v ) const
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
void CatchExpr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();

  for(NameTestList::const_iterator i = theNameTests.begin(); i != theNameTests.end(); ++i) {
    ACCEPT(*i);
  }

  ACCEPT(theExprSingle);
  END_VISITOR();
}



/*
 *
 *  Full-text productions
 *  [http://www.w3.org/TR/xquery-full-text/]
 *
 */

FTSelection::FTSelection(
  QueryLoc const &loc,
  parsenode const *ftor,
  pos_filter_list_t *pos_filter_list )
:
  FTPrimary( loc ),
  ftor_( ftor )
{
  ZORBA_ASSERT( ftor );
  if ( pos_filter_list )
    pos_filter_list_.swap( *pos_filter_list );
}

FTSelection::~FTSelection() {
  delete ftor_;
  ztd::delete_ptr_seq( pos_filter_list_ );
}

void FTSelection::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( ftor_ );
  ACCEPT_SEQ( pos_filter_list_t, pos_filter_list_ );
  END_VISITOR();
}


FTAnd::FTAnd(
  QueryLoc const &loc,
  parsenode const *left,
  parsenode const *right
) :
  parsenode( loc ),
  left_( left ),
  right_( right )
{
  ZORBA_ASSERT( left );
  ZORBA_ASSERT( right );
}

FTAnd::~FTAnd() {
  delete left_;
  delete right_;
}

void FTAnd::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( left_ );
  ACCEPT( right_ );
  END_VISITOR();
}


FTOr::FTOr(
  QueryLoc const &loc,
  parsenode const *left,
  parsenode const *right
) :
  parsenode( loc ),
  left_( left ),
  right_( right )
{
  ZORBA_ASSERT( left );
  ZORBA_ASSERT( right );
}

FTOr::~FTOr() {
  delete left_;
  delete right_;
}

void FTOr::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( left_ );
  ACCEPT( right_ );
  END_VISITOR();
}


FTMildNot::FTMildNot(
  QueryLoc const &loc,
  parsenode const *left,
  parsenode const *right
) :
  parsenode( loc ),
  left_( left ),
  right_( right )
{
  ZORBA_ASSERT( left );
  ZORBA_ASSERT( right );
}

FTMildNot::~FTMildNot() {
  delete left_;
  delete right_;
}

void FTMildNot::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( left_ );
  ACCEPT( right_ );
  END_VISITOR();
}


FTUnaryNot::FTUnaryNot(
  QueryLoc const &loc,
  FTPrimaryWithOptions const *primary_with_options
) :
  parsenode( loc ),
  primary_with_options_( primary_with_options )
{
  ZORBA_ASSERT( primary_with_options );
}

FTUnaryNot::~FTUnaryNot() {
  delete primary_with_options_;
}

void FTUnaryNot::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( primary_with_options_ );
  END_VISITOR();
}


FTPrimaryWithOptions::FTPrimaryWithOptions(
  QueryLoc const &loc,
  FTPrimary const *primary,
  FTMatchOptions const *match_options,
  FTWeight const *weight
) :
  parsenode( loc ),
  primary_( primary ),
  match_options_( match_options ),
  weight_( weight )
{
  ZORBA_ASSERT( primary );
}

FTPrimaryWithOptions::~FTPrimaryWithOptions() {
  delete primary_;
  delete match_options_;
  delete weight_;
}

void FTPrimaryWithOptions::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( primary_ );
  ACCEPT( match_options_ );
  ACCEPT( weight_ );
  END_VISITOR();
}


FTMatchOptions::FTMatchOptions(
  QueryLoc const &loc
) :
  parsenode( loc )
{
}

FTMatchOptions::~FTMatchOptions() {
  ztd::delete_ptr_seq( match_options_ );
}

void FTMatchOptions::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_SEQ( match_option_list_t, match_options_ );
  END_VISITOR();
}

FTWeight::FTWeight(
  const QueryLoc &loc,
  exprnode *expr
) :
  parsenode( loc ),
  expr_( expr )
{
  ZORBA_ASSERT( expr );
}

void FTWeight::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( expr_ );
  END_VISITOR();
}


FTWords::FTWords(
  QueryLoc const &loc,
  FTWordsValue const *words_value,
  FTAnyallOption const *any_all_option
) :
  parsenode( loc ),
  words_value_( words_value ),
  any_all_option_( any_all_option )
{
  ZORBA_ASSERT( words_value );
}

FTWords::~FTWords() {
  delete words_value_;
  delete any_all_option_;
}

void FTWords::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( words_value_ );
  ACCEPT( any_all_option_ );
  END_VISITOR();
}

FTWordsTimes::FTWordsTimes(
  QueryLoc const &loc,
  FTWords const *words,
  FTTimes const *times
) :
  FTPrimary( loc ),
  words_( words ),
  times_( times )
{
  ZORBA_ASSERT( words );
}

FTWordsTimes::~FTWordsTimes() {
  delete words_;
  delete times_;
}

void FTWordsTimes::accept( parsenode_visitor &v ) const {
  BEGIN_VISITOR();
  ACCEPT( words_ );
  ACCEPT( times_ );
  END_VISITOR();
}


FTWordsValue::FTWordsValue(
  QueryLoc const &loc,
  StringLiteral *literal,
  exprnode *expr
) :
  parsenode( loc ),
  literal_( literal ),
  expr_( expr )
{
  ZORBA_ASSERT( literal || expr );
}

void FTWordsValue::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( literal_ );
  ACCEPT( expr_ );
  END_VISITOR();
}


FTOrder::FTOrder(
  QueryLoc const &loc
) :
  FTPosFilter( loc )
{
}

void FTOrder::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTMatchOption::FTMatchOption(
  const QueryLoc &loc
) :
  parsenode( loc )
{
}


FTCaseOption::FTCaseOption(
  QueryLoc const &loc,
  ft_case_mode::type mode
) :
  FTMatchOption( loc ),
  mode_( mode )
{
}

void FTCaseOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTDiacriticsOption::FTDiacriticsOption(
  QueryLoc const &loc,
  ft_diacritics_mode::type mode
) :
  FTMatchOption( loc ),
  mode_( mode )
{
}

void FTDiacriticsOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTStemOption::FTStemOption(
  QueryLoc const &loc,
  ft_stem_mode::type mode
) :
  FTMatchOption( loc ),
  mode_( mode )
{
}

void FTStemOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTThesaurusOption::FTThesaurusOption(
  QueryLoc const &loc,
  thesaurus_id_list_t *thesaurus_id_list,
  bool includes_default,
  bool no_thesaurus
) :
  FTMatchOption( loc ),
  includes_default_( includes_default ),
  no_thesaurus_( no_thesaurus )
{
  if ( thesaurus_id_list )
    thesaurus_id_list_.swap( *thesaurus_id_list );
}

FTThesaurusOption::~FTThesaurusOption() {
  ztd::delete_ptr_seq( thesaurus_id_list_ );
}


void FTThesaurusOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT_SEQ( thesaurus_id_list_t, thesaurus_id_list_ );
  END_VISITOR();
}


FTThesaurusID::FTThesaurusID(
  QueryLoc const &loc,
  zstring const &uri,
  zstring const &relationship,
  FTRange const *levels
) :
  parsenode( loc ),
  uri_( uri ),
  relationship_( relationship ),
  levels_( levels )
{
}

FTThesaurusID::~FTThesaurusID() {
  delete levels_;
}


void FTThesaurusID::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( levels_ );
  END_VISITOR();
}


FTStopWordOption::FTStopWordOption(
  QueryLoc const &loc,
  FTStopWords const *stop_words,
  incl_excl_list_t *incl_excl_list,
  ft_stop_words_mode::type mode
) :
  FTMatchOption( loc ),
  stop_words_( stop_words ),
  mode_( mode )
{
  if ( incl_excl_list )
    incl_excl_list_.swap( *incl_excl_list );
}

FTStopWordOption::~FTStopWordOption() {
  delete stop_words_;
  ztd::delete_ptr_seq( incl_excl_list_ );
}


void FTStopWordOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( stop_words_ );
  ACCEPT_SEQ( incl_excl_list_t, incl_excl_list_ );
  END_VISITOR();
}


FTStopWords::FTStopWords(
  QueryLoc const &loc,
  zstring const &uri,
  list_t *stop_words
) :
  parsenode( loc ),
  uri_( uri )
{
  if ( stop_words )
  {
    stop_words_.swap( *stop_words );
    delete stop_words;
  }
}


void FTStopWords::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTStopWordsInclExcl::FTStopWordsInclExcl(
  QueryLoc const &loc,
  FTStopWords const *stop_words,
  ft_stop_words_unex::type mode
) :
  parsenode( loc ),
  stop_words_( stop_words ),
  mode_( mode )
{
  ZORBA_ASSERT( stop_words );
}

FTStopWordsInclExcl::~FTStopWordsInclExcl() {
  delete stop_words_;
}


void FTStopWordsInclExcl::accept( parsenode_visitor &v ) const {
  BEGIN_VISITOR();
  ACCEPT( stop_words_ );
  END_VISITOR();
}


FTLanguageOption::FTLanguageOption(
  QueryLoc const &loc,
  zstring const &language
) :
  FTMatchOption( loc ),
  language_( language )
{
}

void FTLanguageOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTWildCardOption::FTWildCardOption(
  QueryLoc const &loc,
  ft_wild_card_mode::type mode
) :
  FTMatchOption( loc ),
  mode_( mode )
{
}

void FTWildCardOption::accept( parsenode_visitor &v ) const {
  BEGIN_VISITOR();
  END_VISITOR();
}


FTContent::FTContent(
  QueryLoc const &loc,
  ft_content_mode::type mode
) :
  FTPosFilter( loc ),
  mode_( mode )
{
}

void FTContent::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTAnyallOption::FTAnyallOption(
  QueryLoc const &loc,
  ft_anyall_mode::type option
) :
  parsenode( loc ),
  option_( option )
{
}

void FTAnyallOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTRange::FTRange(
  QueryLoc const &loc,
  ft_range_mode::type mode,
  exprnode const *expr1,
  exprnode const *expr2
) :
  parsenode( loc ),
  mode_( mode ),
  expr1_( expr1 ),
  expr2_( expr2 )
{
  ZORBA_ASSERT( expr1 );
}

FTRange::~FTRange() {
  delete expr1_;
  delete expr2_;
}

void FTRange::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( expr1_ );
  ACCEPT( expr2_ );
  END_VISITOR();
}


FTDistance::FTDistance(
  QueryLoc const &loc,
  FTRange const *distance,
  FTUnit const *unit
) :
  FTPosFilter( loc ),
  distance_( distance ),
  unit_( unit )
{
  ZORBA_ASSERT( distance );
  ZORBA_ASSERT( unit );
}

FTDistance::~FTDistance() {
  delete distance_;
  delete unit_;
}

void FTDistance::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( distance_ );
  ACCEPT( unit_ );
  END_VISITOR();
}

FTExtensionOption::FTExtensionOption(
  const QueryLoc &loc,
  QName *qname,
  zstring const &value
) :
  FTMatchOption( loc ),
  qname_( qname ),
  value_( value )
{
  ZORBA_ASSERT( qname );
}

void FTExtensionOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( qname_ );
  END_VISITOR();
}

FTExtensionSelection::FTExtensionSelection(
  QueryLoc const &loc,
  rchandle<PragmaList> const &pragmas,
  FTSelection const *ftselection
) :
  FTPrimary( loc ),
  pragmas_( pragmas ),
  ftselection_( ftselection )
{
  ZORBA_ASSERT( pragmas_.getp() );
}

FTExtensionSelection::~FTExtensionSelection() {
  delete ftselection_;
}

void FTExtensionSelection::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( pragmas_ );
  ACCEPT( ftselection_ );
  END_VISITOR();
}


FTWindow::FTWindow(
  QueryLoc const &loc,
  AdditiveExpr const *window,
  FTUnit const *unit
) :
  FTPosFilter( loc ),
  window_( window ),
  unit_( unit )
{
  ZORBA_ASSERT( window );
}

FTWindow::~FTWindow() {
  delete window_;
  delete unit_;
}

void FTWindow::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( window_ );
  ACCEPT( unit_ );
  END_VISITOR();
}


FTTimes::FTTimes(
  QueryLoc const &loc,
  FTRange const *range
) :
  parsenode( loc ),
  range_( range )
{
  ZORBA_ASSERT( range );
}

FTTimes::~FTTimes() {
  delete range_;
}

void FTTimes::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( range_ );
  END_VISITOR();
}


FTScope::FTScope(
  QueryLoc const &loc,
  ft_scope::type scope,
  FTBigUnit const *big_unit
) :
  FTPosFilter( loc ),
  scope_( scope ),
  big_unit_( big_unit )
{
  ZORBA_ASSERT( big_unit );
}

FTScope::~FTScope() {
  delete big_unit_;
}

void FTScope::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( big_unit_ );
  END_VISITOR();
}


FTUnit::FTUnit(
  QueryLoc const &loc,
  ft_unit::type unit
) :
  parsenode( loc ),
  unit_( unit )
{
}

void FTUnit::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTBigUnit::FTBigUnit(
  QueryLoc const &loc,
  ft_big_unit::type unit
) :
  parsenode( loc ),
  unit_( unit )
{
}

void FTBigUnit::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  END_VISITOR();
}


FTIgnoreOption::FTIgnoreOption(
  QueryLoc const &loc,
  exprnode const *expr
) :
  parsenode( loc ),
  expr_( expr )
{
  ZORBA_ASSERT( expr );
}

FTIgnoreOption::~FTIgnoreOption() {
  delete expr_;
}

void FTIgnoreOption::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( expr_ );
  END_VISITOR();
}


FTOptionDecl::FTOptionDecl(
  QueryLoc const &loc,
  FTMatchOptions const *match_options
) :
  parsenode( loc ),
  match_options_( match_options )
{
}

FTOptionDecl::~FTOptionDecl() {
  delete match_options_;
}

void FTOptionDecl::accept( parsenode_visitor &v ) const
{
  BEGIN_VISITOR();
  ACCEPT( match_options_ );
  END_VISITOR();
}

LiteralFunctionItem::~LiteralFunctionItem()
{
  delete theArity;
}

void LiteralFunctionItem::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}

void InlineFunction::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  ACCEPT (theReturnType);
  //ACCEPT (theParamList);
  ACCEPT (theEnclosedExpr);
  END_VISITOR ();
}

void AnyFunctionTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}

void TypeList::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  vector<rchandle<SequenceType> >::const_iterator it = theTypes.begin();
  for (; it!=theTypes.end(); ++it) {
    const parsenode* e_p = &**it;
    ACCEPT_CHK (e_p);
  }
  END_VISITOR ();
}

void TypedFunctionTest::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR ();
  END_VISITOR ();
}

void DynamicFunctionInvocation::accept(parsenode_visitor& v) const
{
  BEGIN_VISITOR();
  ACCEPT(thePrimaryExpr);
  if(theArgList != 0) ACCEPT(theArgList);
  END_VISITOR();
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
