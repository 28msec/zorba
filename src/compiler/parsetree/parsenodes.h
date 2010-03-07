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
#ifndef ZORBA_PARSENODES_H
#define ZORBA_PARSENODES_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#include <cassert>

#include "compiler/parser/ft_types.h"
#include "compiler/parsetree/parsenode_base.h"

#include "store/api/item.h"

#include "zorbatypes/rchandle.h"
#include "zorbatypes/representations.h"
#include "zorbautils/strutil.h"

#include "context/static_context_consts.h"
#include "context/dynamic_context.h"

namespace zorba {

class AbbrevForwardStep;
class AdditiveExpr;
class AndExpr;
class AnyKindTest;
class AposAttrContentList;
class AposAttrValueContent;
class ArgList;
class AtomicType;
class AttributeTest;
class AxisStep;
class BaseURIDecl;
class BoundarySpaceDecl;
class CaseClause;
class CaseClauseList;
class CastableExpr;
class CastExpr;
class CatchExpr;
class CatchListExpr;
class CDataSection;
class CollectionModifier;
class CommentTest;
class CommonContent;
class ComparisonExpr;
class CompAttrConstructor;
class CompCommentConstructor;
class CompDocConstructor;
class CompElemConstructor;
class CompPIConstructor;
class CompTextConstructor;
class ConstructionDecl;
class ContextItemExpr;
class CopyNamespacesDecl;
class DeclProperty;
class DefaultCollationDecl;
class DefaultNamespaceDecl;
class DeleteExpr;
class DirAttr;
class DirAttributeList;
class DirAttributeValue;
class DirCommentConstructor;
class DirElemConstructor;
class DirElemContent;
class DirElemContentList;
class DirPIConstructor;
class DocumentTest;
class ElementTest;
class EnclosedExpr;
class Expr;
class ExtensionExpr;
class FilterExpr;
class ForwardAxis;
class ForwardStep;
class FTAnd;
class FTAnyallOption;
class FTBigUnit;
class FTCaseOption;
class FTContainsExpr;
class FTContent;
class FTDiacriticsOption;
class FTDistance;
class FTExtensionOption;
class FTExtensionSelection;
class FTIgnoreOption;
class FTLanguageOption;
class FTMatchOption;
class FTMatchOptions;
class FTMildNot;
class FTOptionDecl;
class FTOr;
class FTOrder;
class FTPosFilter;
class FTPrimary;
class FTPrimaryWithOptions;
class FTRange;
class FTScope;
class FTScoreVar;
class FTSelection;
class FTStemOption;
class FTStopWordOption;
class FTStopWords;
class FTStopWordsInclExcl;
class FTThesaurusID;
class FTThesaurusOption;
class FTTimes;
class FTUnaryNot;
class FTUnit;
class FTWeight;
class FTWildCardOption;
class FTWindow;
class FTWords;
class FTWordsTimes;
class FTWordsValue;
class FunctionCall;
class FunctionDecl;
class GeneralComp;
class IfExpr;
class IndexKeyList;
class IndexKeySpec;
class IndexProperty;
class IndexPropertyList;
class InsertExpr;
class InstanceofExpr;
class IntegrityConstraintDecl;
class IntersectExceptExpr;
class ItemType;
class ModuleDecl;
class MultiplicativeExpr;
class NamespaceDecl;
class NameTest;
class NodeComp;
class NodeModifier;
class NumericLiteral;
class OccurrenceIndicator;
class OptionDecl;
class OrderingModeDecl;
class OrExpr;

class FLWORExpr;
class FLWORClauseList;
class FLWORClause;
class ForOrLetClause;
class ForClause;
class VarInDeclList;
class VarInDecl;
class PositionalVar;
class LetClause;
class VarGetsDeclList;
class VarGetsDecl;
class FTScoreVar;
class WhereClause;
class GroupByClause;
class GroupSpecList;
class GroupSpec;
class GroupCollationSpec;
class OrderByClause;
class OrderSpecList;
class OrderSpec;
class OrderModifierPN;
class OrderCollationSpec;
class OrderDirSpec;
class OrderEmptySpec;
class EmptyOrderDecl;
class WindowClause;
class WindowVarDecl;
class FLWORWinCond;
class WindowVars;
class CountClause;

class PITest;
class Param;
class ParamList;
class ParenthesizedExpr;
class PathExpr;
class PositionalVar;
class Pragma;
class PragmaList;
class PredicateList;
class Prolog;
class QName;
class QuantifiedExpr;
class QueryBody;
class QuoteAttrContentList;
class QuoteAttrValueContent;
class QVarInDecl;
class QVarInDeclList;
class RangeExpr;
class RelativePathExpr;
class RenameExpr;
class ReplaceExpr;
class RevalidationDecl;
class ReverseAxis;
class ReverseStep;
class SIND_DeclList;
class SchemaAttributeTest;
class SchemaElementTest;
class SchemaImport;
class SchemaPrefix;
class SequenceType;
class SignList;
class SingleType;
class TextTest;
class TransformExpr;
class TreatExpr;
class TypeName;
class UnaryExpr;
class UnionExpr;
class UnorderedExpr;
class URILiteralList;
class VFO_DeclList;
class ValidateExpr;
class ValueComp;
class VarBinding;
class VarDecl;
class VersionDecl;

class CopyVarList;
class Wildcard;
class DecimalFormatNode;


// [] Moved here the definitions for FunctionSig and VarNameAndType from the
// Bison parser file
// ---------------
class FunctionSig 
{
public:
  rchandle<ParamList> param;
  rchandle<SequenceType> ret;

  FunctionSig(ParamList* param_, SequenceType* ret_ = NULL)
    :
    param (param_), ret (ret_)
  {
  }
};


class VarNameAndType 
{
public:
  rchandle<QName>        theName;
  rchandle<SequenceType> theType;


  VarNameAndType(rchandle<QName> name, rchandle<SequenceType> type)
    :
    theName(name),
    theType(type)
  {
  }
};


/*******************************************************************************
  [1] Module ::=   VersionDecl? (LibraryModule | MainModule)
********************************************************************************/
class Module : public parsenode
{
protected:
  rchandle<VersionDecl> version_decl_h;

public:
  Module(const QueryLoc& loc_, rchandle<VersionDecl> vd_)
    :
    parsenode (loc_),
    version_decl_h (vd_)
  {
  }

  rchandle<VersionDecl> get_version_decl() const { return version_decl_h; }

  void set_version_decl(rchandle<VersionDecl> vd) { version_decl_h = vd; }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [2] VersionDecl ::= XQUERY ENCODING STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
********************************************************************************/
class VersionDecl : public parsenode
{
protected:
  std::string version;
  std::string encoding;

  friend class ParseNodePrintXMLVisitor;

public:
  VersionDecl(
    const QueryLoc&,
    std::string const& version,
    std::string const& encoding);

  std::string get_version() const { return version; }
  std::string get_encoding() const { return encoding; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [3] MainModule ::= Prolog QueryBody | QueryBody
********************************************************************************/
class MainModule : public Module
{
protected:
  rchandle<Prolog> prolog_h;
  rchandle<QueryBody> query_body_h;

public:
  MainModule(
    const QueryLoc&,
    rchandle<QueryBody>,
    rchandle<Prolog>,
    rchandle<VersionDecl> = NULL);
  
  rchandle<Prolog> get_prolog() const { return prolog_h; }

  rchandle<QueryBody> get_query_body() const { return query_body_h; }

  void set_prolog (rchandle<Prolog> prolog_) { prolog_h = prolog_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [4] LibraryModule ::= ModuleDecl  Prolog
********************************************************************************/
class LibraryModule : public Module
{
protected:
  rchandle<ModuleDecl> decl_h;
  rchandle<Prolog> prolog_h;

public:
  LibraryModule(
    const QueryLoc&,
    rchandle<ModuleDecl>,
    rchandle<Prolog>,
    rchandle<VersionDecl> = NULL);

  rchandle<ModuleDecl> get_decl () const { return decl_h; }

  rchandle<Prolog> get_prolog() const { return prolog_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [5] ModuleDecl ::= MODULE NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
********************************************************************************/
class ModuleDecl : public XQDocumentable
{
protected:
  xqpStringStore_t thePrefix;
  xqpStringStore_t theTargetNamespace;

public:
  ModuleDecl(
    const QueryLoc&,
    std::string const& prefix,
    std::string const& target_namespace);

  const xqpStringStore_t& get_prefix() const { return thePrefix; }

  const xqpStringStore_t& get_target_namespace() const { return theTargetNamespace; }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [6] Prolog ::= SIND_DeclList?  VFO_DeclList?

  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator

  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6c] SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl

********************************************************************************/
class Prolog : public parsenode
{
protected:
  rchandle<SIND_DeclList> sind_list_h;
  rchandle<VFO_DeclList> vfo_list_h;

public:
  Prolog(
    const QueryLoc&,
    rchandle<SIND_DeclList>,
    rchandle<VFO_DeclList>);

  rchandle<SIND_DeclList> get_sind_list() const { return sind_list_h; }

  rchandle<VFO_DeclList> get_vfo_list() const { return vfo_list_h; }

  // returns true if the value was NULL before the call
  bool set_sind_list(SIND_DeclList* list);

  bool set_vfo_list(VFO_DeclList* list);

  // sets one of the above, returns false if it was set before
  bool set_list(parsenode* list);

  void set_vfo_list(rchandle<VFO_DeclList> vfo_list_) { vfo_list_h = vfo_list_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator
********************************************************************************/
class SIND_DeclList : public parsenode
{
protected:
  std::vector<rchandle<parsenode> > sind_hv;

public:
  SIND_DeclList(const QueryLoc&);

  void push_back(rchandle<parsenode> sind_h) { sind_hv.push_back(sind_h); }

  rchandle<parsenode> operator[](int k) const { return sind_hv[k]; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [9] Separator ::= SEMI (Lexical rule)
********************************************************************************/


/******************************************************************************

  [7] Setter ::= BoundarySpaceDecl |
                 OrderingModeDecl |
                 EmptyOrderDecl |
                 CopyNamespacesDecl |
                 DecimalFormatDecl |
                 DefaultCollationDecl |
                 BaseURIDecl |
                 ConstructionDecl |

********************************************************************************/


/*******************************************************************************
  [11] BoundarySpaceDecl ::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
********************************************************************************/
class BoundarySpaceDecl : public parsenode
{
protected:
  StaticContextConsts::boundary_space_mode_t mode;

public:
  BoundarySpaceDecl(
    const QueryLoc&,
    StaticContextConsts::boundary_space_mode_t);

  StaticContextConsts::boundary_space_mode_t
  get_boundary_space_mode() const { return mode; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [14] OrderingModeDecl ::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
********************************************************************************/
class OrderingModeDecl : public parsenode
{
protected:
  StaticContextConsts::ordering_mode_t mode;
    
public:
  OrderingModeDecl(
    const QueryLoc&,
    StaticContextConsts::ordering_mode_t);

  StaticContextConsts::ordering_mode_t get_mode() const { return mode; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [15] EmptyOrderDecl ::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST |
                          DECLARE_DEFAULT_ORDER  EMPTY_LEAST
********************************************************************************/
class EmptyOrderDecl : public parsenode
{
protected:
  StaticContextConsts::empty_order_mode_t mode;

public:
  EmptyOrderDecl(
    const QueryLoc&,
    StaticContextConsts::empty_order_mode_t);

  StaticContextConsts::empty_order_mode_t get_mode() const { return mode; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [16] CopyNamespacesDecl ::= DECLARE_COPY_NAMESPACES PreserveMode COMMA InheritMode

  [19] PreserveMode ::= "preserve" | "no-preserve"
  [20] InheritMode ::=  "inherit" | "no-inherit"
********************************************************************************/
class CopyNamespacesDecl : public parsenode
{
protected:
  StaticContextConsts::preserve_mode_t preserve_mode;
  StaticContextConsts::inherit_mode_t inherit_mode;

public:
  CopyNamespacesDecl(
    const QueryLoc&,
    StaticContextConsts::preserve_mode_t preserve_mode,
    StaticContextConsts::inherit_mode_t  inherit_mode);

  StaticContextConsts::preserve_mode_t get_preserve_mode() const
  { return preserve_mode; }

  StaticContextConsts::inherit_mode_t  get_inherit_mode() const
  { return inherit_mode; }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [17] DecimalFormatDecl ::= "declare"
                             (("decimal-format" QName) | ("default" "decimal-format"))
                             (DFPropertyName "=" StringLiteral)*

  [18] DFPropertyName ::= "decimal-separator" | "grouping-separator" |
                          "infinity" | "minus-sign" | "NaN" | "percent" |
                          "per-mille" | "zero-digit" | "digit" |
                          "pattern-separator"
********************************************************************************/
class DecimalFormatNode : public parsenode
{
public:
  typedef std::vector<std::pair<std::string,std::string> > param_list_t;

  bool is_default;
  rchandle<QName> format_name;
  param_list_t param_list;

  DecimalFormatNode(
    const QueryLoc& _loc,
    rchandle<QName> qname,
    param_list_t* param_list_)
    :
    parsenode(_loc),
    is_default(false),
    format_name(qname)
  {
    param_list.swap(*param_list_);
  }

  DecimalFormatNode(
    const QueryLoc& _loc,
    param_list_t* param_list_)
    :
    parsenode(_loc),
    is_default(true)
  {
    param_list.swap(*param_list_);
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [21] DefaultCollationDecl ::=  DECLARE_DEFAULT_COLLATION  URI_LITERAL
********************************************************************************/
class DefaultCollationDecl : public parsenode
{
protected:
  std::string collation;

public:
  DefaultCollationDecl(
    const QueryLoc&,
    std::string const&  collation);

  std::string get_collation() const { return collation; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [22] BaseURIDecl ::= DECLARE_BASE_URI  URI_LITERAL
********************************************************************************/
class BaseURIDecl : public parsenode
{
protected:
  std::string base_uri;

public:
  BaseURIDecl(
    const QueryLoc&,
    std::string const& base_uri);

  const std::string& get_base_uri() const { return base_uri; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [31] ConstructionDecl ::= DECLARE_CONSTRUCTION  PRESERVE
                            DECLARE_CONSTRUCTION  STRIP
********************************************************************************/
class ConstructionDecl : public parsenode
{
protected:
  StaticContextConsts::construction_mode_t mode;

public:
  ConstructionDecl(
    const QueryLoc&,
    StaticContextConsts::construction_mode_t);

  StaticContextConsts::construction_mode_t get_mode() const { return mode; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [10] NamespaceDecl ::= ::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
********************************************************************************/
class NamespaceDecl : public parsenode
{
protected:
  xqpStringStore_t thePrefix;
  xqpStringStore_t theUri;

public:
  NamespaceDecl(
    const QueryLoc&,
    const std::string& prefix,
    const std::string& uri);

  const xqpStringStore_t& get_prefix() const { return thePrefix; }

  const xqpStringStore_t& get_uri() const { return theUri; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [12] DefaultNamespaceDecl ::= DECLARE DEFAULT ELEMENT NAMESPACE URILiteral |
                                DECLARE DEFAULT FUNCTION NAMESPACE URILiteral
********************************************************************************/
class DefaultNamespaceDecl : public parsenode
{
protected:
  enum ParseConstants::default_namespace_mode_t theMode;
  xqpStringStore_t theUri;

public:
  DefaultNamespaceDecl(
    const QueryLoc&,
    enum ParseConstants::default_namespace_mode_t mode,
    const std::string& uri);

  enum ParseConstants::default_namespace_mode_t get_mode() const { return theMode; }

  const xqpStringStore_t& get_default_namespace() const { return theUri; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [8] Import ::= SchemaImport | ModuleImport
********************************************************************************/


/*******************************************************************************
  [23] SchemaImport ::= "import" "schema" SchemaPrefix? URILiteral
                        ("at"  URILiteralList)?
********************************************************************************/
class SchemaImport : public parsenode
{
protected:
  rchandle<SchemaPrefix>   thePrefix;
  xqpStringStore_t         theUri;
  rchandle<URILiteralList> theAtList;

public:
  SchemaImport(
    const QueryLoc&,
    rchandle<SchemaPrefix>,
    std::string const& uri,
    rchandle<URILiteralList>);

  const SchemaPrefix* get_prefix() const { return thePrefix; }

  const xqpStringStore_t& get_uri() const { return theUri; }

  const URILiteralList* get_at_list() const { return theAtList; }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [23a] URILiteralList ::= URI_LITERAL | URILiteralList  COMMA  URI_LITERAL
********************************************************************************/
class URILiteralList : public parsenode
{
protected:
  std::vector<xqpStringStore_t> theUris;

public:
  URILiteralList(const QueryLoc&);

  void push_back(const std::string& uri) 
  {
    theUris.push_back(new xqpStringStore(uri)); 
  }

  const xqpStringStore_t& operator[](int i) const { return theUris[i]; }

  ulong size() const { return theUris.size(); }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [24] SchemaPrefix ::=  ("namespace" NCName "=") | ("default" "element" "namespace")
********************************************************************************/
class SchemaPrefix : public parsenode
{
protected:
  xqpStringStore_t thePrefix;
  bool             theIsDefault;

public:
  SchemaPrefix(const QueryLoc& loc, bool isDefault);

  SchemaPrefix(const QueryLoc& loc, const std::string& prefix);

  const xqpStringStore_t& get_prefix() const { return thePrefix; }

  bool get_default_bit() const { return theIsDefault; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [25] ModuleImport ::= "import" "module" ("namespace" NCName "=")? URILiteral
                        ("at" URILiteralList)?
********************************************************************************/
class ModuleImport : public XQDocumentable
{
protected:
  xqpStringStore_t         thePrefix;
  xqpStringStore_t         theUri;
  rchandle<URILiteralList> theAtList;

public:
  ModuleImport(
    const QueryLoc&,
    const std::string& uri,
    rchandle<URILiteralList> atlist);

  ModuleImport(
    const QueryLoc&,
    const std::string& prefix,
    const std::string& uri,
    rchandle<URILiteralList> atlist);

  const xqpStringStore_t& get_prefix() const { return thePrefix; }

  const xqpStringStore_t& get_uri() const { return theUri; }

  const URILiteralList* get_at_list() const { return theAtList; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl
********************************************************************************/
class VFO_DeclList : public parsenode
{
protected:
  std::vector<rchandle<parsenode> > vfo_hv;

public:
  VFO_DeclList(const QueryLoc&);

  int size () const { return vfo_hv.size (); }

  void push_front(rchandle<parsenode> vfo_h) { vfo_hv.insert(vfo_hv.begin(), vfo_h); }

  void push_back(rchandle<parsenode> vfo_h) { vfo_hv.push_back(vfo_h); }

  void push_back (const VFO_DeclList &other) { vfo_hv.insert(vfo_hv.end(), other.vfo_hv.begin(), other.vfo_hv.end()); }

  rchandle<parsenode> operator[](int k) const { return vfo_hv[k]; }

  std::vector<rchandle<parsenode> >::iterator begin() { return vfo_hv.begin(); }

  std::vector<rchandle<parsenode> >::iterator end() { return vfo_hv.end(); }

  std::vector<rchandle<parsenode> >::const_iterator begin() const { return vfo_hv.begin(); }

  std::vector<rchandle<parsenode> >::const_iterator end() const { return vfo_hv.end(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [*] DeclPropertyList ::= DeclProperty*
********************************************************************************/
class DeclPropertyList : public parsenode
{
protected:
  std::vector<rchandle<DeclProperty> > theProperties;

public:
  DeclPropertyList(const QueryLoc& aLoc) : parsenode(aLoc) { }

  void addProperty(DeclProperty* aProp) { theProperties.push_back(aProp); }

  size_t size() const { return theProperties.size(); }

  const DeclProperty* getProperty(size_t i) const { return theProperties[i].getp(); }

  void accept(parsenode_visitor&) const {}
};


/*******************************************************************************
  [*] DeclProperty ::= ("const" | "append-only" | "queue" | "mutable" | 
                        "ordered" | "unordered" |
                        "unique" | "non" "unique" |
                        "value" "range" | "value" "equality" |
                        "automatically" "maintained" | "manually" "maintained")
********************************************************************************/
class DeclProperty : public parsenode
{
protected:
  StaticContextConsts::declaration_property_t theProperty;

public:
  DeclProperty(const QueryLoc& loc, StaticContextConsts::declaration_property_t p)
    :
    parsenode(loc),
    theProperty(p)
  { 
  }

  StaticContextConsts::declaration_property_t getProperty() const { return theProperty; }

  void accept(parsenode_visitor&) const {}
};


/*******************************************************************************
  [13] OptionDecl ::= DECLARE_OPTION  QNAME  STRING_LITERAL
********************************************************************************/
class OptionDecl : public parsenode
{
protected:
  rchandle<QName> qname_h;
  std::string val;

public:
  OptionDecl(
    const QueryLoc&,
    rchandle<QName>,
    std::string const&);

  rchandle<QName> get_qname() const { return qname_h; }

  std::string const& get_val() const { return val; }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [26] VarDecl ::= "declare" "variable" "$" QName TypeDeclaration?
                   ((":=" VarValue) |
                    ("external" (":=" VarDefaultValue)?))


  [27] VarValue ::= ExprSingle

  [28] VarDefaultValue ::= ExprSingle

  Note: VarDecl is also used to represent block-local var declarations. The
  syntax for block-local var declarations is:

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*
********************************************************************************/
class VarDeclBase : public XQDocumentable
{
protected:
  rchandle<QName>        theName;
  rchandle<SequenceType> theType;

public:
  VarDeclBase(const QueryLoc& loc,  rchandle<QName> name, rchandle<SequenceType> type)
    :
    XQDocumentable(loc),
    theName(name),
    theType(type)
  {
  }

  const QName* get_name() const { return theName; }

  rchandle<SequenceType> get_typedecl() const { return theType; }
};


/*******************************************************************************

********************************************************************************/
class VarDeclWithInit : public VarDeclBase 
{
protected:
  rchandle<exprnode> initexpr_h;

public:
  VarDeclWithInit(
    const QueryLoc& loc,
    rchandle<QName> varname,
    rchandle<SequenceType> type_decl,
    rchandle<exprnode> init_expr)
    :
    VarDeclBase(loc, varname, type_decl),
    initexpr_h(init_expr)
  {
  }

  rchandle<exprnode> get_initexpr() const { return initexpr_h; }
};


/*******************************************************************************

********************************************************************************/
class VarDecl : public VarDeclWithInit
{
protected:
  bool ext;
  bool global;

public:
  VarDecl(
    const QueryLoc& loc,
    rchandle<QName> varname,
    rchandle<SequenceType> type_decl,
    rchandle<exprnode> init_expr,
    bool external = false);

  bool is_extern () const { return ext; }

  bool is_global () const { return global; }

  void set_global (bool global_) { global = global_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [29] ContextItemDecl ::= "declare" "context" "item" ("as" ItemType)?
                           ((":=" VarValue) |
                            ("external" (":=" VarDefaultValue)?))
********************************************************************************/
class CtxItemDecl : public parsenode 
{
  rchandle<exprnode> expr;

public:
  bool ext;
  rchandle<parsenode> type;

  CtxItemDecl(const QueryLoc& loc, rchandle<exprnode> expr_)
    :
    parsenode(loc),
    expr(expr_),
    ext(false)
  {
  }

  rchandle<exprnode> get_expr() const { return expr; }

  bool is_external() const { return ext; }

  rchandle<ItemType> get_type() const { return type; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [32] FunctionDecl ::= "declare"
                        ("deterministic" | "nondeterministic")?
                        ("simple" | "updating | "sequential")?
                        "function" QName "(" ParamList? ")" ("as" SequenceType)?
                        (FunctionBody | "external")

  [33] FunctionBody ::= EnclosedExpr | Block

  Note: If a function is a sequential one, then its FunctionBody must be a Block,
  otherwise its FunctionBody must be an EnclosedExpr.
********************************************************************************/
class FunctionDecl : public XQDocumentable
{
public:
  ParseConstants::function_type_t type;
protected:
  rchandle<QName> name_h;
  rchandle<ParamList> paramlist_h;
  rchandle<exprnode> body_h;
  rchandle<SequenceType> return_type_h;
public:
  bool deterministic;

public:
  FunctionDecl(
        const QueryLoc&,
        rchandle<QName>,
        rchandle<ParamList>,
        rchandle<SequenceType>,
        rchandle<exprnode>,
        ParseConstants::function_type_t type);

  rchandle<QName> get_name() const { return name_h; }

  rchandle<ParamList> get_paramlist() const { return paramlist_h; }

  int get_param_count() const;

  rchandle<exprnode> get_body() const { return body_h; }

  rchandle<SequenceType> get_return_type() const { return return_type_h; }

  ParseConstants::function_type_t get_type() const { return type; }

  void set_type(ParseConstants::function_type_t t) { type = t; }
 
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [34] ParamList ::= Param ("," Param)*
********************************************************************************/
class ParamList : public parsenode
{
protected:
  std::vector<rchandle<Param> > param_hv;

public:
  ParamList(const QueryLoc&);

  void push_back(rchandle<Param> param_h) { param_hv.push_back(param_h); }

  rchandle<Param> operator[](int i) const { return param_hv[i]; }

  std::vector<rchandle<Param> >::const_iterator begin() const { return param_hv.begin(); }

  std::vector<rchandle<Param> >::const_iterator end() const { return param_hv.end(); }

  std::vector<rchandle<Param> >::size_type size() const { return param_hv.size(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [35] Param ::= "$" QName TypeDeclaration?
********************************************************************************/
class Param : public parsenode
{
protected:
  rchandle<QName>        theName;
  rchandle<SequenceType> theType;

public:
  Param(
    const QueryLoc& loc, 
    rchandle<QName> name,
    rchandle<SequenceType> type);

  const QName* get_name() const { return theName.getp(); }

  rchandle<SequenceType> get_typedecl() const { return theType; }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [*] CollectionDecl ::= "declare" CollProperties "collection" QName 
                         ("as" CollectionTypeDecl)?
                         ("with" NodeModifier "nodes")? 

  [*] CollProperties ::= ("const" | "mutable" | "append-only" | "queue" |
                          "ordered" | "unordered")*

  [*] NodeModifier ::= ("read-only" | "mutable")

  [*] CollectionTypeDecl ::= KindTest OccurenceIndicator? 
********************************************************************************/
class CollectionDecl : public parsenode
{
protected:
  rchandle<QName>                             theName;
  rchandle<NodeModifier>                      theNodeModifier;
  rchandle<SequenceType>                      theTypeDecl;
  StaticContextConsts::declaration_property_t theOrderMode;
  StaticContextConsts::declaration_property_t theUpdateMode;

public:
  CollectionDecl(
        const QueryLoc& aLoc,
        QName* aName,
        DeclPropertyList* aPropertyList,
        NodeModifier* aNodeModifier,
        SequenceType* aTypeDecl);

  const QName* getName() const { return theName.getp(); }

  StaticContextConsts::declaration_property_t getUpdateMode() const
  {
    return theUpdateMode;
  }

  StaticContextConsts::declaration_property_t getOrderMode() const
  {
    return theOrderMode;
  }

  const NodeModifier* getNodeModifier() const 
  {
    return theNodeModifier.getp();
  }

  const SequenceType* getType() const { return theTypeDecl.getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [*] NodeModifier   ::=   ("read-only" | "mutable " )
********************************************************************************/
class NodeModifier : public parsenode
{
protected:
  StaticContextConsts::node_modifier_t theModifier;

public:
  NodeModifier(
        const QueryLoc&                      aLoc,
        StaticContextConsts::node_modifier_t aModifier)
    : 
    parsenode(aLoc),
    theModifier(aModifier)
  {}

  StaticContextConsts::node_modifier_t getModifier() const { return theModifier; }

  void accept(parsenode_visitor&) const;
};


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
class IndexDecl : public parsenode 
{
protected:
  rchandle<QName>        theName;
  rchandle<exprnode>     theDomainExpr;
  rchandle<IndexKeyList> theKey;

  bool                   theIsUnique;
  bool                   theIsOrdered;
  bool                   theIsAutomatic;

public:
  IndexDecl (
        const QueryLoc& loc,
        QName* name,
        exprnode* domainExpr,
        IndexKeyList* key,
        DeclPropertyList* props);

  const QName* getName() const { return theName.getp(); }

  const exprnode* getDomainExpr() const { return theDomainExpr; }

  bool isUnique() const { return theIsUnique; }

  bool isOrdered() const { return theIsOrdered; }

  bool isAutomatic() const { return theIsAutomatic; }

  void accept(parsenode_visitor&) const;
};



/***************************************************************************//**
  IndexKeyList ::= IndexKeySpec ("," IndexKeySpec)*
********************************************************************************/
class IndexKeyList : public parsenode 
{
protected:
  std::vector<rchandle<IndexKeySpec> > theKeySpecs;

public:
  IndexKeyList(const QueryLoc& loc) : parsenode(loc) { }

  void addKeySpec(IndexKeySpec* spec) { theKeySpecs.push_back(spec); }

  ulong size() const { return theKeySpecs.size(); }

  const IndexKeySpec* getKeySpec(ulong i) const { return theKeySpecs[i].getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  IndexKeySpec ::= PathExpr "as" AtomicType IndexKeyOrderModifier

  IndexKeyOrderModifier ::= OrderDirSpec? OrderCollationSpec?

  OrderDirSpec ::= "ascending" | "descending"

  OrderCollationSpec ::= "collation" URILiteral
********************************************************************************/
class IndexKeySpec : public parsenode 
{
protected:
  rchandle<exprnode>           theExpr;
  rchandle<AtomicType>         theType;
  rchandle<OrderCollationSpec> theCollationSpec;

public:
  IndexKeySpec(
    const QueryLoc& loc,
    exprnode* expr,
    AtomicType* type,
    OrderCollationSpec* collation)
    :
    parsenode(loc),
    theExpr(expr),
    theType(type),
    theCollationSpec(collation)
  {
  }

  const exprnode* getExpr() const { return theExpr.getp(); }

  const AtomicType* getType() const { return theType.getp(); }

  const OrderCollationSpec* getCollationSpec() const { return theCollationSpec.getp(); }

  void accept(parsenode_visitor&) const;
};


/***************************************************************************//**
  IntegrityConstraintDecl ::= "declare" "unchecked"? "integrity" "constraint" 
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
class IntegrityConstraintDecl : public parsenode 
{
public:
  enum ICKind
    { coll_check_simple, coll_check_unique_key, coll_foreach_node,
      foreign_key };

protected:
  rchandle<QName>        theICName;
  ICKind                 theICKind;

public:
  IntegrityConstraintDecl(
        const QueryLoc& loc, 
        QName* name, 
        ICKind icKind);

  const QName* getName() const { return theICName.getp(); }

  ICKind getICKind() const { return theICKind; }

  virtual void accept(parsenode_visitor&) const = 0;
};


class ICColl : public IntegrityConstraintDecl
{
protected:
  rchandle<QName> theCollName;

public:
  ICColl(
        const QueryLoc& loc, 
        QName* name, 
        ICKind icKind,
        QName* collName)
    :
    IntegrityConstraintDecl(loc, name, icKind), 
    theCollName(collName) 
  {
  }
  
  const QName* getCollName() const { return theCollName.getp(); }
};


class ICCollSimpleCheck : public ICColl
{
protected:
  rchandle<QName>     theCollVarName;
  rchandle<exprnode>  theExprSingle;  // make type exprnode_t

public:
  ICCollSimpleCheck(
        const QueryLoc& loc, 
        QName* name, 
        QName* collName,
        QName* collVarName,
        rchandle<exprnode> exprSingle)
    :
    ICColl(loc,
           name, 
           IntegrityConstraintDecl::coll_check_simple,
           collName), 
    theCollVarName(collVarName),
    theExprSingle(exprSingle)
  {
  }
  
  const QName* getCollVarName() const { return theCollVarName.getp(); }

  const exprnode* getExpr() const { return theExprSingle.getp(); }

  virtual void accept(parsenode_visitor&) const;
};


class ICCollUniqueKeyCheck 
  : public ICColl
{
protected:
  rchandle<QName>        theNodeVarName;
  rchandle<exprnode>     theExpr;

public:
  ICCollUniqueKeyCheck ( const QueryLoc& loc, 
                         QName* name, 
                         QName* collName,
                         QName* nodeVarName,
                         rchandle<exprnode> expr)
    :
    ICColl(loc, 
           name, 
           IntegrityConstraintDecl::coll_check_unique_key,
           collName), 
    theNodeVarName(nodeVarName),
    theExpr(expr)
  {
  }
  
  const QName* getNodeVarName() const { return theNodeVarName.getp(); }
  const exprnode* getExpr() const { return theExpr.getp(); }

  virtual void accept(parsenode_visitor&) const;
};


class ICCollForeachNode 
  : public ICColl
{
protected:
  rchandle<QName>        theCollVarName;
  rchandle<exprnode>     theExprSingle;

public:
  ICCollForeachNode ( const QueryLoc& loc, 
                      QName* name, 
                      QName* collName,
                      QName* collVarName,
                      rchandle<exprnode> exprSingle) 
    :
    ICColl(loc,
           name, 
           IntegrityConstraintDecl::coll_foreach_node,
           collName), 
    theCollVarName(collVarName),
    theExprSingle(exprSingle)
  {
  }
  
  const QName* getCollVarName() const { return theCollVarName.getp(); }
  const exprnode* getExpr() const { return theExprSingle.getp(); }

  virtual void accept(parsenode_visitor&) const;
};

class ICForeignKey 
  : public IntegrityConstraintDecl
{
protected:
  rchandle<QName>        theFromCollName;
  rchandle<QName>        theFromNodeVarName;
  rchandle<exprnode>     theFromExpr;
  rchandle<QName>        theToCollName;
  rchandle<QName>        theToNodeVarName;
  rchandle<exprnode>     theToExpr;

public:
  ICForeignKey ( const QueryLoc& loc, 
                 QName* name, 
                 QName* fromCollName,
                 QName* fromNodeVarName,
                 rchandle<exprnode> fromExpr,
                 QName* toCollName,
                 QName* toNodeVarName,
                 rchandle<exprnode> toExpr) 
    :
    IntegrityConstraintDecl(loc,
                            name, 
                            IntegrityConstraintDecl::foreign_key), 
    theFromCollName(fromCollName),
    theFromNodeVarName(fromNodeVarName),
    theFromExpr(fromExpr),
    theToCollName(toCollName),
    theToNodeVarName(toNodeVarName),
    theToExpr(toExpr) 
  {
  }
  
  const QName* getFromCollName() const { return theFromCollName; }
  const QName* getFromNodeVarName() const { return theFromNodeVarName; }
  const exprnode* getFromExpr() const { return theFromExpr.getp(); }
  const QName* getToCollName() const { return theToCollName; }
  const QName* getToNodeVarName() const { return theToNodeVarName; }
  const exprnode* getToExpr() const { return theToExpr.getp(); }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [36] EnclosedExpr ::= "{" Expr "}"
*******************************************************************************/
class EnclosedExpr : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  EnclosedExpr(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [37] QueryBody ::= Expr
********************************************************************************/
class QueryBody : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  QueryBody(
    const QueryLoc&,
    rchandle<exprnode>);

  QueryBody();

  rchandle<exprnode> get_expr() const { return expr_h; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [38]  Expr ::= ApplyExpr | ConcatExpr

  [38a] ApplyExpr ::= (ConcatExpr ";")+

  [38b] ConcatExpr ::= ExprSingle ("," ExprSingle)*

  There are no ApplyExpr or ConcatExpr parsenodes. Instead:

  - If the Expr is an ApplyExpr, no Expr parsenode is generated. Instead, a
    BlockBody parsenode is generated, whose children are the ConcatExprs that
    comprise the ApplyExpr. 

  - If the Expr is a ConcatExpr, then an Expr parsenode is generated, whose
    children are the ExprSingles that comparise the ConcatExpr.
********************************************************************************/
class Expr : public exprnode
{
protected:
  std::vector<rchandle<exprnode> > expr_hv;

public:
  Expr(const QueryLoc&);

  void push_back(rchandle<exprnode> expr_h) 
  {
    expr_hv.push_back(expr_h);
    // update the location of the current expression to 
    // end at the location of the last child that was added
    loc.setLineEnd(expr_h->get_location().getLineEnd());
    loc.setColumnEnd(expr_h->get_location().getColumnEnd());
  }

  rchandle<exprnode> operator[](int i) const { return expr_hv[i]; }

  int  numberOfChildren() const;

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [39] ExprSingle ::= 

  ** XQuery 1.1 exprs
                      FLWORExpr |
                      QuantifiedExpr |
                      TypeswitchExpr |
                      IfExpr |
                      OrExpr |
                      TryExpr |

  ** scripting
                      BlockExpr |
                      ExitExpr |
                      WhileExpr |
                      AssignExpr |
                      FlowCtlStatement |

  ** eval
                      EvalExpr |

  ** updates
                      InsertExpr |
                      DeleteExpr |
                      RenameExpr |
                      ReplaceExpr |
                      TransformExpr

********************************************************************************/



/*******************************************************************************

  Block ::= "{" BlockDecls BlockBody "}"

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*

  BlockBody ::= Expr


  - Synactically, BlockBody appears only in Block, and Block appears in
    BlockExpr, WhileExpr, and FunctionDecl iff the function is declared as
    sequential:

  BlockExpr ::= "block" Block

  WhileExpr ::= "while" "(" ExprSingle ")" Block

  FunctionDecl ::= "declare" ("deterministic" | "nondeterministic")?
                   "sequential" "function" QName "(" ParamList? ")" ("as" SequenceType)?
                    Bock


  - There is no parsenode class for BlockExpr or for Block; instead, the parser
    generates:

  1. BlockBody, if BlockDecls is not empty. The "decls" data member of this
     BlockBody stores the var declarations.

  2. BlockBody, if BlockDecls is empty and Expr is an ApplyExpr.

  3. Expr, if BlockDecls is empty and Expr is a ConcatExpr.

  In addition to cases 1 and 2 above, a BlockBody node is also generated

  4. In the case of any Expr that is an ApplyExpr.

  4. In the case of a WhileExpr if the Block that appears in the WhileExpr
     syntax did not generate a BlockBody itself (i.e., case 3 above). In this 
     case, the BlockBody has a single child, which is the Expr node generated
     by Block.


  - There are no parsenode classes for BlockVarDecl and BlockDecls; instead
    the parser generates VarDecl and VFO_DeclList parsenodes.

********************************************************************************/
class BlockBody : public exprnode
{
protected:
  std::vector<rchandle <exprnode> > statements;
  rchandle<VFO_DeclList> decls;

public:
  BlockBody (const QueryLoc& loc_, rchandle<VFO_DeclList> decls_ = NULL)
    :
    exprnode (loc_), decls (decls_)
  {
  }

  void add (rchandle<exprnode> statement) { statements.push_back(statement); }

  const rchandle<exprnode>& operator[](int k) const { return statements[k]; }

  rchandle<exprnode>& operator[](int k) { return statements[k]; }

  int size () const { return statements.size (); }

  rchandle<VFO_DeclList> get_decls () const { return decls; }

  void set_decls (rchandle<VFO_DeclList> decls_) { decls = decls_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  FLWORExpr ::= InitialClause FLWORClauseList? ReturnClause

  - For the Generalized FLWOR:

  InitialClause ::= ForClause | LetClause | WindowClause

  FLWORClauseList ::= FLWORClause*


  - For the traditional FLWOR:

  InitialClause ::= ForClause | LetClause

  FLWORClauseList ::= (ForClause | LetClause)* 
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?
********************************************************************************/
class FLWORExpr : public exprnode
{
protected:
  rchandle<FLWORClauseList> clauses;
  rchandle<exprnode>        return_val_h;
  bool                      general;  //< needs to be translated into gflwor_expr?
  bool                      non_10;   //< non-conformant to XQuery 1.0 spec?
  QueryLoc                  return_location;

public:
  FLWORExpr(
        const QueryLoc& loc_,
        rchandle<FLWORClauseList> clauses_,
        rchandle<exprnode> ret_,
        const QueryLoc& return_loc_,
        bool force_general = false);

  bool is_general () const { return general; }

  bool is_non_10 () const { return non_10; }

  const QueryLoc& get_return_location() const { return return_location; }

  rchandle<FLWORClauseList> get_clause_list() const { return clauses; }

  rchandle<exprnode> get_return_val() const { return return_val_h; }

  GroupByClause* get_groupby() const;

  OrderByClause* get_orderby() const;

  WhereClause* get_where() const;

  void accept(parsenode_visitor&) const;

protected:
  void compute_general ();
};


/*******************************************************************************
  - For the Generalized FLWOR:

  FLWORClauseList ::= FLWORClause*

  - For the traditional FLWOR:

  FLWORClauseList ::= (ForClause | LetClause)* 
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?
********************************************************************************/
class FLWORClauseList : public parsenode
{
protected:
  std::vector<rchandle<FLWORClause> > theClauses;

public:
  FLWORClauseList(const QueryLoc&);

public:
  void push_back(rchandle<FLWORClause> cl) { theClauses.push_back(cl); }

  rchandle<FLWORClause> operator[](int i) const { return theClauses[i]; }

  size_t size() const { return theClauses.size(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  FLWORClause ::= ForClause |
                  LetClause |
                  WindowClause |
                  WhereClause |
                  GroupByClause |
                  OrderByClause |
                  CountClause
********************************************************************************/
class FLWORClause : public parsenode 
{
public:
  FLWORClause(const QueryLoc& loc) : parsenode(loc) {}
};


/*******************************************************************************
  ForOrLetClause ::= ForClause | LetClause
********************************************************************************/
class ForOrLetClause : public FLWORClause 
{
public:
  typedef enum { for_clause, let_clause } for_or_let_t;

  ForOrLetClause (const QueryLoc& loc) : FLWORClause(loc) {}

  virtual for_or_let_t for_or_let() const = 0;

  virtual int get_decl_count() const = 0;
};


/*******************************************************************************
  ForClause ::= "outer"? "for" "$"  VarInDeclList
********************************************************************************/
class ForClause : public ForOrLetClause
{
protected:
  rchandle<VarInDeclList> vardecl_list_h;
  bool                    outer;

public:
  ForClause(const QueryLoc&, rchandle<VarInDeclList>, bool outer = false);

  for_or_let_t for_or_let () const { return for_clause; }

  bool is_outer () const { return outer; }

  rchandle<VarInDeclList> get_vardecl_list() const { return vardecl_list_h; }

  int get_decl_count () const;

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  VarInDeclList ::= VarInDecl | VarInDeclList  ","  "$"  VarInDecl
********************************************************************************/
class VarInDeclList : public parsenode
{
protected:
  std::vector<rchandle<VarInDecl> > vardecl_hv;

public:
  VarInDeclList(const QueryLoc&);

  void push_back(rchandle<VarInDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }

  rchandle<VarInDecl> operator[](int i) const { return vardecl_hv[i]; }

  size_t size () const { return vardecl_hv.size ();}

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  VarInDecl ::= VarName TypeDeclaration? PositionalVar? FTScoreVar? "in" ExprSingle
********************************************************************************/
class VarInDecl : public VarDeclWithInit
{
protected:
  rchandle<PositionalVar> posvar_h;
  rchandle<FTScoreVar>    ftscorevar_h;
  rchandle<exprnode>      valexpr_h;
  
public:
  VarInDecl(
    const QueryLoc&,
    rchandle<QName> varname,
    rchandle<SequenceType>,
    rchandle<PositionalVar>,
    rchandle<FTScoreVar>,
    rchandle<exprnode>);

  rchandle<PositionalVar> get_posvar() const { return posvar_h; }

  rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  PositionalVar ::= "at" "$"  VarName
********************************************************************************/
class PositionalVar : public parsenode
{
protected:
  rchandle<QName> theName;

public:
  PositionalVar(const QueryLoc&, rchandle<QName> varname);

  const QName* get_name() const { return theName.getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  LetClause ::= "let" "$" VarGetsDeclList |
                "let" "score $" VarGetsDeclList
********************************************************************************/
class LetClause : public ForOrLetClause
{
protected:
  rchandle<VarGetsDeclList> vardecl_list_h;

public:
  LetClause(const QueryLoc&, rchandle<VarGetsDeclList>);

  rchandle<VarGetsDeclList> get_vardecl_list() const { return vardecl_list_h; }

  for_or_let_t for_or_let () const { return let_clause; }

  int get_decl_count () const;

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  VarGetsDeclList ::= VarGetsDecl |
                      VarGetsDeclList ","  "$"  VarGetsDecl
********************************************************************************/
class VarGetsDeclList : public parsenode
{
protected:
  std::vector<rchandle<VarGetsDecl> > vardecl_hv;

public:
  VarGetsDeclList(const QueryLoc&);

  void push_back(rchandle<VarGetsDecl> vardecl_h) { vardecl_hv.push_back(vardecl_h); }

  rchandle<VarGetsDecl> operator[](int i) const { return vardecl_hv[i]; }

  size_t size () const { return vardecl_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  VarGetsDecl ::= VarName TypeDeclaration? ":=" ExprSingle |
                  VarName TypeDeclaration? FTScoreVar ":=" ExprSingle

  Note: This ast node also represents EVAL external vars
********************************************************************************/
class VarGetsDecl : public VarDeclWithInit
{
public:
  enum var_kind { let_var, eval_var };

protected:
  rchandle<FTScoreVar> ftscorevar_h;
  enum var_kind        kind;

public:
  VarGetsDecl(
    const QueryLoc& loc,
    rchandle<QName> varname,
    rchandle<SequenceType> typedecl_h,
    rchandle<FTScoreVar> ftscorevar_h,
    rchandle<exprnode> valexpr_h,
    enum var_kind kind_ = let_var)
    :
    VarDeclWithInit(loc, varname, typedecl_h, valexpr_h),
    ftscorevar_h(ftscorevar_h),
    kind (kind_)
  {
  }

  rchandle<FTScoreVar> get_ftscorevar() const { return ftscorevar_h; }


  enum var_kind get_kind () const { return kind; }
  void set_kind (enum var_kind kind_) { kind = kind_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  FTScoreVar ::= SCORE  DOLLAR  VarName
********************************************************************************/
class FTScoreVar : public parsenode
{
protected:
  std::string varname;

public:
  FTScoreVar(const QueryLoc&, std::string varname);

  std::string get_varname() const { return varname; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  WhereClause ::= "where"  ExprSingle
********************************************************************************/
class WhereClause : public FLWORClause
{
protected:
  rchandle<exprnode> predicate_h;

public:
  WhereClause(const QueryLoc&, rchandle<exprnode>);

  rchandle<exprnode> get_predicate() const { return predicate_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  GroupByClause ::= "group" "by" GroupingSpecList
********************************************************************************/
class GroupByClause : public FLWORClause
{
protected:
  FLWORExpr*              flwor_h;
  rchandle<GroupSpecList> spec_list_h;

public:
  GroupByClause(const QueryLoc&, rchandle<GroupSpecList>);

  void set_flwor(FLWORExpr* a) { flwor_h = a; }

  FLWORExpr* get_flwor() const { return flwor_h; }

  GroupSpecList* get_spec_list() const { return spec_list_h.getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  GroupSpecList ::=   GroupingSpec ("," GroupingSpec)*
********************************************************************************/
class GroupSpecList : public parsenode
{
protected:
  std::vector<rchandle<GroupSpec> > spec_hv;
 
public:
  GroupSpecList(const QueryLoc&);

  void push_back(rchandle<GroupSpec> spec_h) { spec_hv.push_back(spec_h); }

  GroupSpec* operator[](int i) const { return spec_hv[i].getp(); }

  size_t size () const { return spec_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  GroupSpec ::= "$" VarName ("collation" URILiteral)?
********************************************************************************/
class GroupSpec : public parsenode
{
protected:
  rchandle<QName>              var_name_h;
  rchandle<GroupCollationSpec> group_coll_spec_h;

public:
  GroupSpec(
    const QueryLoc&,
    rchandle<QName>,
    rchandle<GroupCollationSpec>);

  const QName* get_var_name() const { return var_name_h.getp(); }

  rchandle<GroupCollationSpec> group_coll_spec() const { return group_coll_spec_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class GroupCollationSpec : public parsenode
{
protected:
  std::string uri;

public:
  GroupCollationSpec(const QueryLoc&, std::string const& uri);

  std::string get_uri() const { return uri; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderByClause ::= (("order" "by") | ("stable" "order" "by")) OrderSpecList
********************************************************************************/
class OrderByClause : public FLWORClause
{
protected:
  rchandle<OrderSpecList> spec_list_h;
  bool stable_b;
  const FLWORExpr *flwor;
    
public:
  OrderByClause(
    const QueryLoc&,
    rchandle<OrderSpecList>,
    bool stable_b = false);

  OrderSpecList* get_spec_list() const { return spec_list_h.getp(); }

  bool get_stable_bit() const { return stable_b; }

  const FLWORExpr *get_flwor () const { return flwor; }

  void set_flwor (const FLWORExpr* flwor_) { flwor = flwor_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderSpecList ::=   OrderSpec ("," OrderSpec)*
********************************************************************************/
class OrderSpecList : public parsenode
{
protected:
  std::vector<rchandle<OrderSpec> > spec_hv;

public:
  OrderSpecList(const QueryLoc&);

  void push_back(rchandle<OrderSpec> spec_h) { spec_hv.push_back(spec_h); }

  OrderSpec* operator[](int i) const { return spec_hv[i].getp(); }

  size_t size () const { return spec_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderSpec ::=   ExprSingle OrderModifier
********************************************************************************/
class OrderSpec : public parsenode
{
protected:
  rchandle<exprnode> spec_h;
  rchandle<OrderModifierPN> modifier_h;

public:
  OrderSpec(
        const QueryLoc&,
        exprnode*,
        OrderModifierPN*);

  rchandle<exprnode> get_spec() const { return spec_h; }

  const OrderModifierPN* get_modifier() const { return modifier_h.getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderModifier ::= OrderDirSpec? OrderEmptySpec? OrderCollationSpec?
********************************************************************************/
class OrderModifierPN : public parsenode
{
protected:
  rchandle<OrderDirSpec> dir_spec_h;
  rchandle<OrderEmptySpec> empty_spec_h;
  rchandle<OrderCollationSpec> collation_spec_h;

public:
  OrderModifierPN(
        const QueryLoc&,
        OrderDirSpec*,
        OrderEmptySpec*,
        OrderCollationSpec*);

  const OrderDirSpec* get_dir_spec() const  { return dir_spec_h; }

  const OrderEmptySpec* get_empty_spec() const  { return empty_spec_h; }

  const OrderCollationSpec* get_collation_spec() const { return collation_spec_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderDirSpec ::= "ascending" | "descending"
********************************************************************************/
class OrderDirSpec : public parsenode
{
protected:
  ParseConstants::dir_spec_t dir_spec;

public:
  OrderDirSpec(const QueryLoc&, ParseConstants::dir_spec_t dir_spec);
  
  ParseConstants::dir_spec_t getValue() const { return dir_spec; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderEmptySpec ::= "empty" ("greatest" | "least")
********************************************************************************/
class OrderEmptySpec : public parsenode
{
protected:
  StaticContextConsts::empty_order_mode_t empty_order_spec;

public:
  OrderEmptySpec(
        const QueryLoc&,
        StaticContextConsts::empty_order_mode_t empty_order_spec);

  StaticContextConsts::empty_order_mode_t getValue() const
  {
    return empty_order_spec;
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  OrderCollationSpec ::= "collation" URILiteral
********************************************************************************/
class OrderCollationSpec : public parsenode
{
protected:
  std::string uri;

public:
  OrderCollationSpec(const QueryLoc&, std::string const& uri);

  std::string get_uri() const { return uri; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  ReturnExpr ::= "return" ExprSingle
********************************************************************************/
class ReturnExpr: public exprnode
{
  protected:
    rchandle<exprnode> return_val_h;

  public:
    ReturnExpr(const QueryLoc& loc_, rchandle<exprnode> ret_): exprnode(loc_), return_val_h(ret_){}
    rchandle<exprnode> get_return_val() const { return return_val_h; }
    void accept(parsenode_visitor&) const { /* do nothing... */ }
};


/*******************************************************************************
  WindowClause ::= "for" (TumblingWindowClause | SlidingWindowClause)

  TumblingWindowClause ::= "tumbling" "window" WindowVarDecl
                           WindowStartCondition WindowEndCondition?

  SlidingWindowClause ::= "sliding" "window" WindowVarDecl
                          WindowStartCondition WindowEndCondition
********************************************************************************/
class WindowClause : public FLWORClause 
{
public:
  typedef enum { tumbling_window, sliding_window } win_clause_t;

private:
  rchandle<WindowVarDecl> var;
  win_clause_t type;
  rchandle<FLWORWinCond> conditions [2];

public:
  WindowClause (
        const QueryLoc& loc,
        win_clause_t type_,
        rchandle<WindowVarDecl> var_,
        rchandle<FLWORWinCond> start_,
        rchandle<FLWORWinCond> end_)
    :
    FLWORClause(loc),
    var(var_),
    type(type_)
  {
    conditions[0] = start_;
    conditions[1] = end_;
  }

  win_clause_t get_wintype () const { return type; }

  rchandle<WindowVarDecl> get_var () const { return var; }

  rchandle<FLWORWinCond> operator[] (unsigned i) const
  {
    assert (i <= 2);
    return conditions [i];
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  WindowVarDecl ::= "$" VarName TypeDeclaration? "in"  ExprSingle
********************************************************************************/
class WindowVarDecl : public VarDeclWithInit 
{
public:
  WindowVarDecl (
        const QueryLoc& loc_,
        rchandle<QName> varname_,
        rchandle<SequenceType> td_,
        rchandle<exprnode> init_)
    :
    VarDeclWithInit (loc_, varname_, td_, init_)
  {
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  WindowStartCondition ::= "start" WindowVars "when" ExprSingle

  WindowEndCondition ::= "only"? "end" WindowVars "when" ExprSingle
********************************************************************************/
class FLWORWinCond : public parsenode 
{
  rchandle<WindowVars> winvars;
  rchandle<exprnode> val;
  bool isStart;
  bool isOnly;  // only when isStart == false

public:
  FLWORWinCond (
        const QueryLoc& loc_,
        rchandle<WindowVars> winvars_,
        rchandle<exprnode> val_,
        bool isStart_,
        bool isOnly_ = false)
    :
    parsenode (loc_),
    winvars (winvars_),
    val (val_),
    isStart (isStart_),
    isOnly (isOnly_)
  {
  }

  rchandle<WindowVars> get_winvars () const { return winvars; }
  rchandle<exprnode> get_val () const { return val; }
  bool is_start () const { return isStart; }
  bool is_only () const { return isOnly; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  WindowVars ::= ("$" CurrentItem)? PositionalVar?
                 ("previous" "$" PreviousItem)?
                 ("next" "$" NextItem)?
********************************************************************************/
class WindowVars : public parsenode 
{
  rchandle<PositionalVar> posvar;
  rchandle<QName> curr;
  rchandle<QName> prev;
  rchandle<QName> next;

public:
  WindowVars(
        const QueryLoc& loc,
        rchandle<PositionalVar> posvar_,
        rchandle<QName> curr_,
        rchandle<QName> prev_,
        rchandle<QName> next_)
    : 
    parsenode(loc),
    posvar(posvar_),
    curr(curr_),
    prev(prev_),
    next(next_)
  {
  }

  rchandle<PositionalVar> get_posvar() const { return posvar; }

  const QName* get_curr() const { return curr.getp(); }

  const QName* get_prev() const { return prev.getp(); }

  const QName* get_next() const { return next.getp(); }

  void set_curr(rchandle<QName> curr_) { curr = curr_; }

  void set_posvar(rchandle<PositionalVar> posvar_) { posvar = posvar_; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  CountClause ::= "count" "$" VarName
********************************************************************************/
class CountClause : public FLWORClause
{
  rchandle<QName> varname;

public:
  CountClause (const QueryLoc& loc, rchandle<QName> varname_)
    :
    FLWORClause(loc),
    varname(varname_)
  {
  }

  const QName* get_varname() const { return varname.getp(); }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [65] QuantifiedExpr ::= ("some" | "every") QVarInDeclList "satisfies" ExprSingle
********************************************************************************/
class QuantifiedExpr : public exprnode
{
protected:
  ParseConstants::quantification_mode_t qmode;
  rchandle<QVarInDeclList> decl_list_h;
  rchandle<exprnode> expr_h;

public:
  QuantifiedExpr(
    const QueryLoc&,
    ParseConstants::quantification_mode_t qmode,
    rchandle<QVarInDeclList>,
    rchandle<exprnode>);

  ParseConstants::quantification_mode_t get_qmode() const { return qmode; }

  rchandle<QVarInDeclList> get_decl_list() const { return decl_list_h; }

  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  QVarInDeclList := QVarInDecl ("," QVarInDecl)*
********************************************************************************/
class QVarInDeclList : public parsenode
{
protected:
  std::vector<rchandle<QVarInDecl> > qvar_decl_hv;

public:
  QVarInDeclList(const QueryLoc&);

  void push_back(rchandle<QVarInDecl> decl_h) { qvar_decl_hv.push_back(decl_h); }

  rchandle<QVarInDecl> operator[](int i) const { return qvar_decl_hv[i]; }

  int size () const { return qvar_decl_hv.size ();}

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  QVarInDecl := "$" VarName TypeDeclaration? "in" ExprSingle
********************************************************************************/
class QVarInDecl : public parsenode
{
protected:
  rchandle<QName> name;
  rchandle<SequenceType> typedecl_h;
  rchandle<exprnode> val_h;

public:
  QVarInDecl(
    const QueryLoc&,
    rchandle<QName> name,
    rchandle<exprnode>);

  QVarInDecl(
    const QueryLoc&,
    rchandle<QName> name,
    rchandle<SequenceType>,
    rchandle<exprnode>);

  const QName* get_name() const { return name.getp(); }

  rchandle<SequenceType> get_typedecl() const { return typedecl_h; }

  rchandle<exprnode> get_val() const { return val_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [66] TypeswitchExpr ::= "typeswitch" "(" Expr ")"
                          CaseClauseList
                          "default" ("$" VarName)? "return" ExprSingle
********************************************************************************/
class TypeswitchExpr : public exprnode
{
protected:
  rchandle<exprnode> switch_expr_h;
  rchandle<CaseClauseList> clause_list_h;
  rchandle<QName> default_varname;
  rchandle<exprnode> default_clause_h;

public:
  TypeswitchExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<CaseClauseList>,
    rchandle<exprnode>);

  TypeswitchExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<CaseClauseList>,
    rchandle<QName> default_varname,
    rchandle<exprnode>);

  rchandle<exprnode> get_switch_expr() const { return switch_expr_h; }

  rchandle<CaseClauseList> get_clause_list() const { return clause_list_h; }

  const QName* get_default_varname() const { return default_varname.getp(); }

  rchandle<exprnode> get_default_clause() const { return default_clause_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  CaseClauseList := CaseClause+
********************************************************************************/
class CaseClauseList : public parsenode
{
protected:
  std::vector<rchandle<CaseClause> > clause_hv;

public:
  CaseClauseList(const QueryLoc&);

  void push_back(rchandle<CaseClause> clause_h)
  { clause_hv.push_back(clause_h); }

  rchandle<CaseClause> operator[](int i) const
  { return clause_hv[i]; }

  std::vector<rchandle<CaseClause> >::const_iterator begin() const
  { return clause_hv.begin(); }

  std::vector<rchandle<CaseClause> >::const_iterator end() const
  { return clause_hv.end(); }

  std::vector<rchandle<CaseClause> >::const_reverse_iterator rbegin() const
  { return clause_hv.rbegin(); }

  std::vector<rchandle<CaseClause> >::const_reverse_iterator rend() const
  { return clause_hv.rend(); }

  uint32_t size () const
  { return clause_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [67] CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle
********************************************************************************/
class CaseClause : public parsenode
{
protected:
  rchandle<QName> varname;
  rchandle<SequenceType> type_h;
  rchandle<exprnode> val_h;

public:
  CaseClause(
    const QueryLoc&,
    rchandle<QName> varname,
    rchandle<SequenceType>,
    rchandle<exprnode>);
    
  CaseClause(
    const QueryLoc&,
    rchandle<SequenceType>,
    rchandle<exprnode>);

  const QName* get_varname() const { return varname.getp(); }

  rchandle<SequenceType> get_type() const { return type_h; }

  rchandle<exprnode> get_expr() const { return val_h; }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
class IfExpr : public exprnode
{
protected:
  rchandle<exprnode> cond_expr_h;
  rchandle<exprnode> then_expr_h;
  rchandle<exprnode> else_expr_h;

public:
  IfExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_cond_expr() const { return cond_expr_h; }
  rchandle<exprnode> get_then_expr() const { return then_expr_h; }
  rchandle<exprnode> get_else_expr() const { return else_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [69] OrExpr ::= AndExpr ( "or" AndExpr )*
********************************************************************************/
class OrExpr : public exprnode
{
protected:
  rchandle<exprnode> or_expr_h;
  rchandle<exprnode> and_expr_h;

public:
  OrExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_or_expr() const { return or_expr_h; }
  rchandle<exprnode> get_and_expr() const { return and_expr_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [70] AndExpr ::= ComparisonExpr ( "and" ComparisonExpr )*
********************************************************************************/
class AndExpr : public exprnode
{
protected:
  rchandle<exprnode> and_expr_h;
  rchandle<exprnode> comp_expr_h;

public:
  AndExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_and_expr() const { return and_expr_h; }
  rchandle<exprnode> get_comp_expr() const { return comp_expr_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [71] ComparisonExpr ::= RangeExpr
                          ((ValueComp | GeneralComp | NodeComp) RangeExpr)?

  Note: For the full-text extension, the rule for ComparisonExpr is:

  ComparisonExpr ::= FTContainsExpr
                     ((ValueComp | GeneralComp | NodeComp) FTContainsExpr)?

********************************************************************************/
class ComparisonExpr : public exprnode
{
protected:
  rchandle<exprnode> left_h;
  rchandle<exprnode> right_h;
  rchandle<ValueComp> valcomp_h;
  rchandle<GeneralComp> gencomp_h;
  rchandle<NodeComp> nodecomp_h;
  // XXX could use a union for these three

public:
  ComparisonExpr(
    const QueryLoc&,
    rchandle<ValueComp>,
    rchandle<exprnode>,
    rchandle<exprnode>);

  ComparisonExpr(
    const QueryLoc&,
    rchandle<GeneralComp>,
    rchandle<exprnode>,
    rchandle<exprnode>);

  ComparisonExpr(
    const QueryLoc&,
    rchandle<NodeComp>,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_left() const { return left_h; }
  rchandle<exprnode> get_right() const { return right_h; }

  rchandle<ValueComp> get_valcomp() const { return valcomp_h; }

  rchandle<GeneralComp> get_gencomp() const { return gencomp_h; }

  rchandle<NodeComp> get_nodecomp() const { return nodecomp_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [83] GeneralComp ::= "=" | "!=" | "<" | "<=" | ">" | ">="
********************************************************************************/
class GeneralComp : public parsenode
{
protected:
  enum ParseConstants::gencomp_t type;

public:
  GeneralComp(
    const QueryLoc&,
    enum ParseConstants::gencomp_t);

  GeneralComp();

  enum ParseConstants::gencomp_t get_type() const { return type; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [84] ValueComp ::= "eq" | "ne" | "lt" | "le" | "gt" | "ge"
********************************************************************************/
class ValueComp : public parsenode
{
protected:
  enum ParseConstants::valcomp_t type;

public:
  ValueComp(
    const QueryLoc&,
    enum ParseConstants::valcomp_t);

  ValueComp();

  enum ParseConstants::valcomp_t get_type() const { return type; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [85] NodeComp ::= "is" | "<<" | ">>"
********************************************************************************/
class NodeComp : public parsenode
{
protected:
  enum ParseConstants::nodecomp_t type;

public:
  NodeComp(
    const QueryLoc&,
    enum ParseConstants::nodecomp_t);

  NodeComp();

  enum ParseConstants::nodecomp_t get_type() const { return type; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  FTContainsExpr := RangeExpr (FTCONTAINS FTSelection FTIgnoreOption?)?
********************************************************************************/
class FTContainsExpr : public exprnode
{
protected:
  rchandle<FTRange> range_h;
  rchandle<FTSelection> ftselection_h;
  rchandle<FTIgnoreOption> ftignore_h;

public:
  FTContainsExpr(
    const QueryLoc&,
    rchandle<FTRange>,
    rchandle<FTSelection>,
    rchandle<FTIgnoreOption>);

  rchandle<FTRange> get_range() const { return range_h; }
  rchandle<FTSelection> get_selection() const { return ftselection_h; }
  rchandle<FTIgnoreOption> get_ignore() const { return ftignore_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [72] RangeExpr ::= AdditiveExpr ( "to" AdditiveExpr )?
********************************************************************************/
class RangeExpr : public exprnode
{
protected:
  rchandle<exprnode> from_expr_h;
  rchandle<exprnode> to_expr_h;

public:
  RangeExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_from_expr() const { return from_expr_h; }
  rchandle<exprnode> get_to_expr() const { return to_expr_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [73] AdditiveExpr ::= MultiplicativeExpr ( ("+" | "-") MultiplicativeExpr )*
********************************************************************************/
class AdditiveExpr : public exprnode
{
protected:
  ParseConstants::add_op_t add_op;
  rchandle<exprnode> add_expr_h;
  rchandle<exprnode> mult_expr_h;

public:
  AdditiveExpr(
    const QueryLoc&,
    ParseConstants::add_op_t add_op,
    rchandle<exprnode>,
    rchandle<exprnode>);


public:
  ParseConstants::add_op_t get_add_op() const { return add_op; }
  rchandle<exprnode> get_add_expr() const { return add_expr_h; }
  rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }

public:
  virtual void accept(parsenode_visitor&) const;

};


/*******************************************************************************
  [74] MultiplicativeExpr ::= UnionExpr (("*" | "div" | "idiv" | "mod") UnionExpr)*
********************************************************************************/
class MultiplicativeExpr : public exprnode
{
protected:
  ParseConstants::mult_op_t mult_op;
  rchandle<exprnode> mult_expr_h;
  rchandle<exprnode> union_expr_h;

public:
  MultiplicativeExpr(
    const QueryLoc&,
    ParseConstants::mult_op_t,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_mult_expr() const { return mult_expr_h; }
  rchandle<exprnode> get_union_expr() const { return union_expr_h; }
  ParseConstants::mult_op_t get_mult_op() const { return mult_op; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [75] UnionExpr ::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
********************************************************************************/
class UnionExpr : public exprnode
{
protected:
  rchandle<exprnode> union_expr_h;
  rchandle<exprnode> intex_expr_h;

public:
  UnionExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> union_expr() const { return union_expr_h; }
  rchandle<exprnode> intex_expr() const { return intex_expr_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [76] IntersectExceptExpr ::= InstanceofExpr
                               (("intersect" | "except") InstanceofExpr)*
********************************************************************************/
class IntersectExceptExpr : public exprnode
{
protected:
  enum ParseConstants::intex_op_t intex_op;
  rchandle<exprnode> intex_expr_h;
  rchandle<exprnode> instof_expr_h;

public:
  IntersectExceptExpr(
    const QueryLoc&,
    ParseConstants::intex_op_t,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_intex_expr() const { return intex_expr_h; }
  enum ParseConstants::intex_op_t get_intex_op() const { return intex_op; }
  rchandle<exprnode> get_instof_expr() const { return instof_expr_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [77] InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
class InstanceofExpr : public exprnode
{
protected:
  rchandle<exprnode> treat_expr_h;
  rchandle<SequenceType> seqtype_h;

public:
  InstanceofExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<SequenceType>);

  rchandle<exprnode> get_treat_expr() const { return treat_expr_h; }
  rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [78] TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
class TreatExpr : public exprnode
{
protected:
  rchandle<exprnode> castable_expr_h;
  rchandle<SequenceType> seqtype_h;

public:
  TreatExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<SequenceType>);

  rchandle<exprnode> get_castable_expr() const { return castable_expr_h; }
  rchandle<SequenceType> get_seqtype() const { return seqtype_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [79] CastableExpr ::= CastExpr ( "castable" "as" SingleType )?
********************************************************************************/
class CastableExpr : public exprnode
{
protected:
  rchandle<exprnode> cast_expr_h;
  rchandle<SingleType> singletype_h;

public:
  CastableExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<SingleType>);

  rchandle<exprnode> cast_expr() const { return cast_expr_h; }
  rchandle<SingleType> singletype() const { return singletype_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [80] CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?
********************************************************************************/
class CastExpr : public exprnode
{
protected:
  rchandle<exprnode> unary_expr_h;
  rchandle<SingleType> singletype_h;

public:
  CastExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<SingleType>);
  
  rchandle<exprnode> get_unary_expr() const { return unary_expr_h; }
  rchandle<SingleType> get_singletype() const { return singletype_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [81] UnaryExpr ::= SignList? ValueExpr
********************************************************************************/
class UnaryExpr : public exprnode
{
protected:
  rchandle<exprnode> value_expr_h;
  rchandle<SignList> signlist_h;

public:
  UnaryExpr(
    const QueryLoc&,
    rchandle<SignList>,
    rchandle<exprnode>);

  rchandle<exprnode> get_value_expr() const { return value_expr_h; }
  rchandle<SignList> get_signlist() const { return signlist_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  SignList := ("-" | "+")+
********************************************************************************/
class SignList : public parsenode
{
protected:
  bool sign;

public:
  SignList(
    const QueryLoc&,
    bool _sign);

  bool get_sign() const { return sign; }
  void negate() { sign = !sign; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [82] ValueExpr ::= ValidateExpr | PathExpr | ExtensionExpr
********************************************************************************/


/*******************************************************************************
  [86] ValidateExpr ::= "validate" (ValidationMode | ("as" TypeName))? "{" Expr "}"
  [87] ValidationMode ::= "lax" | "strict"
********************************************************************************/
class ValidateExpr : public exprnode
{
protected:
  enum ParseConstants::validation_mode_t valmode;
  rchandle<exprnode> expr_h;
  rchandle<QName> type_name;

public:
  ValidateExpr(
    const QueryLoc&,
    std::string const& _valmode,
    rchandle<exprnode>);

  ValidateExpr(
    const QueryLoc&,
    rchandle<QName> _valmode,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }
  rchandle<QName> get_type_name() const { return type_name; }
  enum ParseConstants::validation_mode_t get_valmode() const { return valmode; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [88] ExtensionExpr ::= PragmaList "{" Expr? "}"
********************************************************************************/
class ExtensionExpr : public exprnode
{
protected:
  rchandle<PragmaList> pragma_list_h;
  rchandle<exprnode> expr_h;

public:
  ExtensionExpr(
    const QueryLoc&,
    rchandle<PragmaList>,
    rchandle<exprnode>);

  rchandle<PragmaList> get_pragma_list() const { return pragma_list_h; }
  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  PragmaList ::= Pragma | PragmaList  Pragma
********************************************************************************/
class PragmaList : public parsenode
{
protected:
  std::vector<rchandle<Pragma> > pragma_hv;

public:
  PragmaList(const QueryLoc&);

  void push_back(rchandle<Pragma> pragma_h) { pragma_hv.push_back(pragma_h); }
  rchandle<Pragma> operator[](int i) const { return pragma_hv[i]; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [89] Pragma ::= "(#" S? QName (S PragmaContents)? "#)"  // ws: explicitXQ
  [90] PragmaContents ::= (Char* - (Char* '#)' Char*))
********************************************************************************/
class Pragma : public parsenode
{
protected:
  rchandle<QName> name_h;
  std::string pragma_lit;

public:
  Pragma(
    const QueryLoc&,
    rchandle<QName>,
    std::string pragma_lit);

  rchandle<QName> get_name() const { return name_h; }
  std::string get_pragma_lit() const { return pragma_lit; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [91] PathExpr ::= ("/" RelativePathExpr?) |
                    ("//" RelativePathExpr) |
                     RelativePathExpr   // gn: leading-lone-slashXQ

  [92] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  [93] StepExpr ::= FilterExpr | AxisStep

  [94] AxisStep ::= (ReverseStep | ForwardStep) PredicateList

  [95] ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep

  [96] ForwardAxis ::= ("child" "::") |
                       ("descendant" "::") |
                       ("attribute" "::") |
                       ("self" "::") |
                       ("descendant-or-self" "::") |
                       ("following-sibling" "::") |
                       ("following" "::")

  [97] AbbrevForwardStep ::= "@"? NodeTest

  [98] ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep

  [99] ReverseAxis ::= ("parent" "::") |
                       ("ancestor" "::") |
                       ("preceding-sibling" "::") |
                       ("preceding" "::") |
                       ("ancestor-or-self" "::")

  [100] AbbrevReverseStep ::= ".."

  [101] NodeTest ::= KindTest | NameTest

  [102] NameTest ::= QName | Wildcard

  [103] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [104] FilterExpr ::= PrimaryExpr PredicateList

  [105] PredicateList ::= Predicate*

  [106] Predicate ::= "[" Expr "]"
********************************************************************************/
class PathExpr : public exprnode
{
protected:
  enum ParseConstants::pathtype_t type;
  rchandle<exprnode> relpath_expr_h;

public:
  PathExpr(
    const QueryLoc&,
    enum ParseConstants::pathtype_t type,
    rchandle<exprnode>);

  enum ParseConstants::pathtype_t get_type() const { return type; }

  rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [92] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  Note: If a RelativePathExpr consists of a single StepExpr, a RelativePathExpr
  node is generated whose left child is a ContextItemExpr and its right child
  is the StepExpr.

********************************************************************************/
class RelativePathExpr : public exprnode
{
protected:
  enum ParseConstants::steptype_t step_type;
  rchandle<exprnode> step_expr_h;
  rchandle<exprnode> relpath_expr_h;  

public:
  RelativePathExpr(
    const QueryLoc&,
    ParseConstants::steptype_t,
    rchandle<exprnode>,
    rchandle<exprnode>);

  enum ParseConstants::steptype_t get_step_type() const { return step_type; } 

  rchandle<exprnode> get_step_expr() const { return step_expr_h; }

  rchandle<exprnode> get_relpath_expr() const { return relpath_expr_h; }  

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [93] StepExpr ::= FilterExpr | AxisStep
********************************************************************************/


/*******************************************************************************
  [94] AxisStep ::= (ReverseStep | ForwardStep) PredicateList
********************************************************************************/
class AxisStep : public exprnode
{
protected:
  rchandle<ForwardStep> forward_step_h;
  rchandle<ReverseStep> reverse_step_h;
  rchandle<PredicateList> predicate_list_h;

public:
  AxisStep(
    const QueryLoc&,
    rchandle<ForwardStep>,
    rchandle<PredicateList>);

  AxisStep(
    const QueryLoc&,
    rchandle<ReverseStep>,
    rchandle<PredicateList>);

  rchandle<ForwardStep> get_forward_step() const { return forward_step_h; }
  rchandle<ReverseStep> get_reverse_step() const { return reverse_step_h; }
  rchandle<PredicateList> get_predicate_list() const { return predicate_list_h; }

  virtual void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [95] ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep
********************************************************************************/
class ForwardStep : public parsenode
{
protected:
  rchandle<ForwardAxis> forward_axis_h;
  rchandle<parsenode> node_test_h;
  rchandle<AbbrevForwardStep> abbrev_step_h;

public:
  ForwardStep(
    const QueryLoc&,
    rchandle<ForwardAxis>,
    rchandle<parsenode> node_test_h);

  ForwardStep(
    const QueryLoc&,
    rchandle<AbbrevForwardStep>);

  rchandle<ForwardAxis> get_forward_axis() const { return forward_axis_h; }
  rchandle<parsenode> get_node_test() const { return node_test_h; }
  rchandle<AbbrevForwardStep> get_abbrev_step() const { return abbrev_step_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [96] ForwardAxis ::= ("child" "::") |
                       ("descendant" "::") |
                       ("attribute" "::") |
                       ("self" "::") |
                       ("descendant-or-self" "::") |
                       ("following-sibling" "::") |
                       ("following" "::")
********************************************************************************/
class ForwardAxis : public parsenode
{
protected:
  enum ParseConstants::forward_axis_t axis;

public:
  ForwardAxis(
    const QueryLoc&,
    enum ParseConstants::forward_axis_t);

  enum ParseConstants::forward_axis_t get_axis() const { return axis; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [97] AbbrevForwardStep ::= "@"? NodeTest
********************************************************************************/
class AbbrevForwardStep : public parsenode
{
protected:
  rchandle<parsenode> node_test_h;
  bool attr_b;
  
public:
  AbbrevForwardStep(
    const QueryLoc&,
    rchandle<parsenode>,
    bool attr_b);
    
  rchandle<parsenode> get_node_test() const { return node_test_h; }
  bool get_attr_bit() const { return attr_b; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [98] ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep
********************************************************************************/
class ReverseStep : public parsenode
{
protected:
  rchandle<ReverseAxis> axis_h;
  rchandle<parsenode> node_test_h;

public:
  ReverseStep(
    const QueryLoc&,
    rchandle<ReverseAxis>,
    rchandle<parsenode>);

  rchandle<ReverseAxis> get_axis() const { return axis_h; }
  rchandle<parsenode> get_node_test() const { return node_test_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [99] ReverseAxis ::= ("parent" "::") |
                       ("ancestor" "::") |
                       ("preceding-sibling" "::") |
                       ("preceding" "::") |
                       ("ancestor-or-self" "::")
********************************************************************************/
class ReverseAxis : public parsenode
{
protected:
  enum ParseConstants::reverse_axis_t axis;

public:
  ReverseAxis(
    const QueryLoc&,
    enum ParseConstants::reverse_axis_t);

  enum ParseConstants::reverse_axis_t get_axis() const { return axis; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [100] AbbrevReverseStep ::= ".."  (folded into [98])
********************************************************************************/


/*******************************************************************************
  [101] NodeTest ::= KindTest | NameTest
********************************************************************************/


/*******************************************************************************
  [102] NameTest ::= QName | Wildcard

  qname_h and wild_h cannot both be non-NULL
********************************************************************************/
class NameTest : public parsenode
{
protected:
  rchandle<QName>    theQName;
  rchandle<Wildcard> theWildcard;

public:
  NameTest(const QueryLoc& l, rchandle<QName> n);

  NameTest(const QueryLoc& l, rchandle<Wildcard> w);

  rchandle<QName> getQName() const { return theQName; }

  rchandle<Wildcard> getWildcard() const { return theWildcard; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [103] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  At least one of thePrefix and theLocalName will be the empty string.
********************************************************************************/
class Wildcard : public parsenode
{
protected:
  enum ParseConstants::wildcard_t theKind;
  xqpStringStore_t                thePrefix;
  xqpStringStore_t                theLocalName;
  
public:
  Wildcard(
    const QueryLoc& loc_,
    const std::string& prefix,
    const std::string& lname,
    enum ParseConstants::wildcard_t type);

  enum ParseConstants::wildcard_t getKind() const { return theKind; }

  const xqpStringStore_t& getPrefix() const { return thePrefix; }

  const xqpStringStore_t& getLocalName() const { return theLocalName; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [104] FilterExpr ::= PrimaryExpr PredicateList
********************************************************************************/
class FilterExpr : public exprnode
{
protected:
  rchandle<exprnode>      primary_h;
  rchandle<PredicateList> pred_list_h;
  bool                    theIsPathStep;

public:
  FilterExpr(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<PredicateList>);

  rchandle<exprnode> get_primary() const { return primary_h; }

  rchandle<PredicateList> get_pred_list() const { return pred_list_h; }

  bool isPathStep() const { return theIsPathStep; }

  void setIsPathStep() { theIsPathStep = true; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [105] PredicateList ::= Predicate*
********************************************************************************/
class PredicateList : public parsenode
{
protected:
  std::vector<rchandle<exprnode> > pred_hv;

public:
  PredicateList(const QueryLoc&);

  void push_back(rchandle<exprnode> pred_h) { pred_hv.push_back(pred_h); }

  rchandle<exprnode> operator[](int i) { return pred_hv[i]; }

  int size () const { return pred_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [106] Predicate ::= "[" Expr "]"
********************************************************************************/


/*******************************************************************************
  [107] PrimaryExpr ::= Literal |
                        VarRef |
                        ParenthesizedExpr |
                        ContextItemExpr |
                        FunctionCall |
                        OrderedExpr |
                        UnorderedExpr |
                        Constructor
********************************************************************************/


/*******************************************************************************
  [108] Literal ::= NumericLiteral | StringLiteral
********************************************************************************/


/*******************************************************************************
  [181] StringLiteral ::= ('"' (PredefinedEntityRef |
                                CharRef |
                                EscapeQuot |
                                [^"&])*
                           '"') |
                          ("'" (PredefinedEntityRef |
                                CharRef |
                                EscapeApos |
                                [^'&])*
                           "'")

  [182] PredefinedEntityRef ::= "&" ("lt" | "gt" | "amp" | "quot" | "apos") ";"

  [183] EscapeQuot ::= '""'

  [184] EscapeApos ::= "''"

  [190] CharRef ::= [http://www.w3.org/TR/REC-xml#NT-CharRef]
********************************************************************************/
class StringLiteral : public exprnode
{
protected:
  std::string strval;

public:
  StringLiteral(
    const QueryLoc&,
    std::string const&);

  std::string get_strval() const { return strval; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [109] NumericLiteral ::= IntegerLiteral | DecimalLiteral | DoubleLiteral

  [178] IntegerLiteral ::= Digits

  [179] DecimalLiteral :: ("." Digits) | (Digits "." [0-9]*) 

  [180] DoubleLiteral ::= (("." Digits) | (Digits ("." [0-9]*)?)) [eE] [+-]? Digits
********************************************************************************/
class NumericLiteral : public exprnode
{
protected:
  class ValueBase
  {
  public:
    virtual ~ValueBase () {}

    virtual std::string toString () const = 0;
  };

  template<typename T> class Value : public ValueBase 
  {
  public:
    T data;

    Value (const T& x) : data (x) {}

    std::string toString () const { return to_string (data); }
  };

protected:
  enum ParseConstants::numeric_type_t type;

  ValueBase * theValue;

protected:
  NumericLiteral(
        const QueryLoc& loc_,
        ParseConstants::numeric_type_t type_,
        ValueBase* val)
    :
    exprnode (loc_),
    type (type_),
    theValue (val)
  {
  }

public:
  ~NumericLiteral () { delete theValue; }

  template<typename T> static NumericLiteral* new_literal(
      const QueryLoc& loc_,
      ParseConstants::numeric_type_t type_,
      const T& x)
  {
    return new NumericLiteral(loc_, type_, new Value<T>(x));
  }

  enum ParseConstants::numeric_type_t get_type() const { return type; }

  std::string toString () const { return theValue->toString (); }

  template<typename T> T get() const { return static_cast<Value<T>*>(theValue)->data; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [110] VarRef ::= "$" VarName
  [111] VarName ::= QName
********************************************************************************/
class VarRef : public exprnode
{
protected:
	rchandle<QName> theName;

public:
	VarRef(const QueryLoc&, rchandle<QName> name);

	const QName* get_name() const { return theName.getp(); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [112] ParenthesizedExpr ::= "(" Expr? ")"
********************************************************************************/
class ParenthesizedExpr : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  ParenthesizedExpr(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};  


/*******************************************************************************
  [113] ContextItemExpr ::= "."
********************************************************************************/
class ContextItemExpr : public exprnode
{
protected:
  bool placeholder;
  
public:
  ContextItemExpr(const QueryLoc&, bool _placeholder = false);

  bool is_placeholder() const { return placeholder; }

  void accept(parsenode_visitor&) const;
};  


/*******************************************************************************
  [114] OrderedExpr ::= "ordered" "{" Expr "}"
********************************************************************************/
class OrderedExpr : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  OrderedExpr(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [115] UnorderedExpr ::= "unordered" "{" Expr "}"
********************************************************************************/
class UnorderedExpr : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  UnorderedExpr(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [116] FunctionCall ::= QName "(" ArgList? ")"
********************************************************************************/
class FunctionCall : public exprnode
{
protected:
  rchandle<QName> fname_h;
  rchandle<ArgList> arg_list_h;

public:
  FunctionCall(
    const QueryLoc&,
    rchandle<QName>,
    rchandle<ArgList>);

  rchandle<QName> get_fname() const { return fname_h; }

  rchandle<ArgList> get_arg_list() const { return arg_list_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [116a] ArgList := ExprSingle ("," ExprSingle)*
********************************************************************************/
class ArgList : public parsenode
{
protected:
  std::vector<rchandle<exprnode> > arg_hv;

public:
  ArgList(const QueryLoc&);

  void push_back(rchandle<exprnode> arg_h) { arg_hv.push_back(arg_h); }

  rchandle<exprnode> operator[](int i) const { return arg_hv[i]; }

  int size() const { return arg_hv.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

  [117] Constructor ::= DirectConstructor | ComputedConstructor

  [118] DirectConstructor ::= DirElemConstructor |
                              DirCommentConstructor |
                              DirPIConstructor

  [119]  DirElemConstructor ::= "<" QName DirAttributeList?
                                ("/>" | (">" DirElemContentList? "</" QName S? ">")) 

  [120] DirAttributeList ::= DirAttr | DirAttributeList DirAttr

  [120a] DirAttr ::= (S (QName S? "=" S? DirAttributeValue)

  [121] DirAttributeValue ::= '"' QuoteAttrContentList? '"' |
                              "'" AposAttrContentList? "'"

  [121a] QuoteAttrContentList ::= QuotAttrValueContent+

  [121b] AposAttrContentList ::= AposAttrValueContent+

  [122] QuotAttrValueContent ::= EscapeQuot | QuotAttrContentChar | CommonContent

  [123] AposAttrValueContent ::= EscapeApos | AposAttrContentChar | CommonContent

  [119a] DirElemContentList ::= DirElemContent+

  [124] DirElemContent ::= DirectConstructor |
                           CDataSection |
                           CommonContent |
                           ElementContentChar

  [125] CommonContent ::= PredefinedEntityRef | CharRef | "{{" | "}}" | EnclosedExpr

  [126] DirCommentConstructor ::= "<!--" DirCommentContents "-->"

  [127] DirCommentContents ::= ((Char - '-') | ('-' (Char - '-')))*

  [128] DirPIConstructor ::= "<?" PITarget (S DirPIContents)? "?>"

  [129] DirPIContents ::= (Char* - (Char* '?>' Char*))

  [130] CDataSection ::= "<![CDATA[" CDataSectionContents "]]>"

  [131] CDataSectionContents ::= (Char* - (Char* ']]>' Char*))

  [132] ComputedConstructor ::= CompDocConstructor |
                                CompElemConstructor |
                                CompAttrConstructor |
                                CompNamespaceConstructor |
                                CompTextConstructor |
                                CompCommentConstructor |
                                CompPIConstructor

  [133] CompDocConstructor ::= "document" "{" Expr "}"

  [134] CompElemConstructor ::= "element" (QName | ("{" Expr "}")) "{" ContentExpr? "}"

  [135] ContentExpr ::= Expr

  [136] CompAttrConstructor ::= "attribute" (QName | ("{" Expr "}")) "{" Expr? "}"

  [137] CompNamespaceConstructor ::= "namespace" (Prefix | ("{" PrefixExpr "}"))
                                     "{" URIExpr? "}"

  [138] PrefixExpr ::= Expr

  [139] URIExpr ::= Expr

  [140] CompTextConstructor ::= "text" "{" Expr "}"

  [141] CompCommentConstructor ::= "comment" "{" Expr "}"

  [142] CompPIConstructor ::= "processing-instruction" (NCName | ("{" Expr "}"))
                              "{" Expr? "}"

  [183] EscapeQuot ::= '""'
  [184] EscapeApos ::= "''"
  [185] ElementContentChar ::= Char - [{}<&]
  [186] QuotAttrContentChar ::= Char - ["{}<&]
  [187] AposAttrContentChar ::= Char - ['{}<&]
********************************************************************************/


/*******************************************************************************
  [119]  DirElemConstructor ::= "<" QName DirAttributeList
                                ("/>" |
                                 (">" DirElemContentList? "</" QName S? ">")) 
********************************************************************************/
class DirElemConstructor : public exprnode
{
protected:
  rchandle<QName> elem_name_h, end_name_h;
  rchandle<DirAttributeList> attr_list_h;
  rchandle<DirElemContentList> dir_content_list_h;

public:
  DirElemConstructor(
    const QueryLoc&,
    rchandle<QName>,
    rchandle<QName>,
    rchandle<DirAttributeList>,
    rchandle<DirElemContentList>);

  rchandle<QName> get_elem_name() const { return elem_name_h; }

  rchandle<QName> get_end_name() const { return end_name_h; }

  rchandle<DirAttributeList> get_attr_list() const { return attr_list_h; }

  rchandle<DirElemContentList> get_dir_content_list() const { return dir_content_list_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
   [120] DirAttributeList ::= DirAttr | DirAttributeList  DirAttr
********************************************************************************/
class DirAttributeList : public parsenode
{
protected:
  std::vector<rchandle<DirAttr> > theAttributes;

public:
  DirAttributeList(const QueryLoc&);

  void push_back(rchandle<DirAttr> attr) { theAttributes.push_back(attr); }

  rchandle<DirAttr> operator[](int i) { return theAttributes[i]; }

  const DirAttr *operator[] (int i) const { return theAttributes[i]; }

  int size () const { return theAttributes.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [120a] DirAttr ::= (S (QName S? "=" S? DirAttributeValue)
********************************************************************************/
class DirAttr : public parsenode
{
protected:
  rchandle<QName>             theName;
  rchandle<DirAttributeValue> theValue;
  
public:
  DirAttr(
        const QueryLoc&,
        rchandle<QName>,
        rchandle<DirAttributeValue>);


public:
  rchandle<QName> get_name() const { return theName; }
  rchandle<DirAttributeValue> get_value() const { return theValue; }

public:
  void accept(parsenode_visitor&) const;
};


/******************************************************************************

  [121] DirAttributeValue ::= '"' QuoteAttrContentList? '"' |
                              "'" AposAttrContentList? "'"

*******************************************************************************/
class DirAttributeValue : public parsenode
{
protected:
  rchandle<QuoteAttrContentList> quot_attr_content_h;
  rchandle<AposAttrContentList> apos_attr_content_h;

public:
  DirAttributeValue(
    const QueryLoc&,
    rchandle<QuoteAttrContentList>);

  DirAttributeValue(
    const QueryLoc&,
    rchandle<AposAttrContentList>);


  rchandle<QuoteAttrContentList> get_quot_attr_content() const
  {
    return quot_attr_content_h;
  }

  rchandle<AposAttrContentList> get_apos_attr_content() const
  {
    return apos_attr_content_h;
  }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [121a] QuoteAttrContentList ::= QuotAttrValueContent+
********************************************************************************/
class QuoteAttrContentList : public parsenode
{
protected:
  std::vector<rchandle<QuoteAttrValueContent> > quot_atval_content_hv;
  
public:
  QuoteAttrContentList(const QueryLoc&);

  void push_back(rchandle<QuoteAttrValueContent> quot_atval_content_h)
  {
    quot_atval_content_hv.push_back(quot_atval_content_h);
  }

  rchandle<QuoteAttrValueContent> operator[](int i) const
  {
    return quot_atval_content_hv[i];
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [121b] AposAttrContentList ::= AposAttrValueContent+
********************************************************************************/
class AposAttrContentList : public parsenode
{
protected:
  std::vector<rchandle<AposAttrValueContent> > apos_atval_content_hv;
  
public:
  AposAttrContentList(const QueryLoc&);

  void push_back(rchandle<AposAttrValueContent> apos_atval_content_h)
  {
    apos_atval_content_hv.push_back(apos_atval_content_h); 
  }

  rchandle<AposAttrValueContent> operator[](int i) const
  {
    return apos_atval_content_hv[i]; 
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [122] QuotAttrValueContent ::= EscapeQuot | QuotAttrContentChar | CommonContent

  [183] EscapeQuot ::= '""'

  [186] QuotAttrContentChar ::= Char - ["{}<&]
********************************************************************************/
class QuoteAttrValueContent : public parsenode
{
protected:
  std::string quot_atcontent;
  rchandle<CommonContent> common_content_h;

public:
  QuoteAttrValueContent(
    const QueryLoc&,
    std::string quot_atcontent);

  QuoteAttrValueContent(
    const QueryLoc&,
    rchandle<CommonContent>);

  std::string get_quot_atcontent() const { return quot_atcontent; }

  rchandle<CommonContent> get_common_content() const { return common_content_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [123] AposAttrValueContent ::= EscapeApos | AposAttrContentChar | CommonContent

  [184] EscapeApos ::= "''"

  [187] AposAttrContentChar ::= Char - ['{}<&]
********************************************************************************/
class AposAttrValueContent : public parsenode
{
protected:
  std::string apos_atcontent;
  rchandle<CommonContent> common_content_h;

public:
  AposAttrValueContent(
    const QueryLoc&,
    std::string apos_atcontent);

  AposAttrValueContent(
    const QueryLoc&,
    rchandle<CommonContent>);

  std::string get_apos_atcontent() const { return apos_atcontent; }

  rchandle<CommonContent> get_common_content() const { return common_content_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [119a] DirElemContentList ::= DirElemContent+
********************************************************************************/
class DirElemContentList : public parsenode
{
protected:
  std::vector<rchandle<DirElemContent> > dir_content_hv;

public:
  DirElemContentList(const QueryLoc&);

  void push_back(rchandle<DirElemContent> dir_content_h)
  {
    dir_content_hv.push_back(dir_content_h);
  }

  rchandle<DirElemContent> operator[](int i) const
  {
    return dir_content_hv[i];
  }

  void accept(parsenode_visitor&) const;
};


/**************************a*****************************************************
  [124] DirElemContent ::= DirectConstructor |
                           CDataSection |
                           CommonContent |
                           ElementContentChar

  [185] ElementContentChar ::= Char - [{}<&]
********************************************************************************/
class DirElemContent : public exprnode
{
protected:
  rchandle<exprnode> direct_cons_h;
  std::string elem_content;
  rchandle<CDataSection> cdata_h;
  rchandle<CommonContent> common_content_h;
  mutable bool theIsStripped;

public:
  DirElemContent(
    const QueryLoc&,
    rchandle<exprnode>);

  DirElemContent(
    const QueryLoc&,
    std::string elem_content);

  DirElemContent(
    const QueryLoc&,
    rchandle<CDataSection>);

  DirElemContent(
    const QueryLoc&,
    rchandle<CommonContent>);

  rchandle<exprnode> get_direct_cons() const { return direct_cons_h; }

  std::string get_elem_content() const { return elem_content; }

  rchandle<CDataSection> get_cdata() const { return cdata_h; }

  rchandle<CommonContent> get_common_content() const { return common_content_h; }

  bool isStripped() const { return theIsStripped; }

  void setIsStripped(bool aIsStripped) const { theIsStripped = aIsStripped; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [125] CommonContent ::= PredefinedEntityRef |
                          CharRef |
                          "{{" |
                          "}}" |
                          EnclosedExpr
********************************************************************************/
class CommonContent : public exprnode
{
protected:
  enum ParseConstants::common_content_t type;
  std::string ref;
  rchandle<EnclosedExpr> expr_h;

public:
  CommonContent(
    const QueryLoc&,
    ParseConstants::common_content_t,
    std::string ref);

  CommonContent(
    const QueryLoc&,
    rchandle<EnclosedExpr> expr_h);

  CommonContent(
    const QueryLoc&,
    enum ParseConstants::common_content_t);

  enum ParseConstants::common_content_t get_type() const { return type; }

  const std::string& get_ref() const { return ref; }

  rchandle<EnclosedExpr> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [130] CDataSection ::= "<![CDATA[" CDataSectionContents "]]>"

  [131] CDataSectionContents ::= (Char* - (Char* ']]>' Char*))
********************************************************************************/
class CDataSection : public exprnode
{
protected:
  std::string cdata_content;

public:
  CDataSection(
    const QueryLoc&,
    std::string cdata_content);

  std::string get_cdata_content() const { return cdata_content; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [126] DirCommentConstructor ::= "<!--" DirCommentContents "-->"

  [127] DirCommentContents ::= ((Char - '-') | ('-' (Char - '-')))*
********************************************************************************/
class DirCommentConstructor : public exprnode
{
protected:
  std::string comment;

public:
  DirCommentConstructor(
    const QueryLoc&,
    std::string const& comment);

  std::string get_comment() const { return comment; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [128] DirPIConstructor ::= "<?" PITarget (S DirPIContents)? "?>"

  [129] DirPIContents ::= (Char* - (Char* '?>' Char*))
********************************************************************************/
class DirPIConstructor : public exprnode
{
protected:
  std::string pi_target;
  std::string pi_content;

public:
  DirPIConstructor(
    const QueryLoc&,
    std::string const& pi_target);

  DirPIConstructor(
    const QueryLoc&,
    std::string const& pi_target,
    std::string const& pi_content);

  std::string get_pi_target() const { return pi_target; }

  std::string get_pi_content() const { return pi_content; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [132] ComputedConstructor ::= CompDocConstructor |
                                CompElemConstructor |
                                CompAttrConstructor |
                                CompTextConstructor |
                                CompCommentConstructor |
                                CompPIConstructor
********************************************************************************/


/*******************************************************************************
  [133] CompDocConstructor ::= "document" "{" Expr "}"
********************************************************************************/
class CompDocConstructor : public exprnode
{
protected:
  rchandle<exprnode> expr_h;

public:
  CompDocConstructor(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_expr() const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [134] CompElemConstructor ::= "element" (QName | ("{" Expr "}")) "{" ContentExpr? "}"

  [135] ContentExpr ::= Expr
********************************************************************************/
class CompElemConstructor : public exprnode
{
protected:
  rchandle<exprnode> qname_expr_h;
  rchandle<exprnode> content_expr_h;

public:
  CompElemConstructor(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }

  rchandle<exprnode> get_content_expr() const { return content_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
 [136] CompAttrConstructor ::= "attribute" (QName | ("{" Expr "}")) "{" Expr? "}"
********************************************************************************/
class CompAttrConstructor : public exprnode
{
protected:
  rchandle<exprnode> qname_expr_h;
  rchandle<exprnode> val_expr_h;

public:
  CompAttrConstructor(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  rchandle<exprnode> get_qname_expr() const { return qname_expr_h; }

  rchandle<exprnode> get_val_expr() const { return val_expr_h; }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [140] CompTextConstructor ::= "text" "{" Expr "}"
********************************************************************************/
class CompTextConstructor : public exprnode
{
protected:
  rchandle<exprnode> text_expr_h;

public:
  CompTextConstructor(
    const QueryLoc&,
    rchandle<exprnode> text_expr_h);

  rchandle<exprnode> get_text_expr() const { return text_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [141] CompCommentConstructor ::= "comment" "{" Expr "}"
********************************************************************************/
class CompCommentConstructor : public exprnode
{
protected:
  rchandle<exprnode> comment_expr_h;

public:
  CompCommentConstructor(
    const QueryLoc&,
    rchandle<exprnode>);

  rchandle<exprnode> get_comment_expr() const { return comment_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [142] CompPIConstructor ::= "processing-instruction" (NCName | ("{" Expr "}"))
                              "{" Expr? "}"
********************************************************************************/
class CompPIConstructor : public exprnode
{
protected:
  std::string target;
  rchandle<exprnode> target_expr_h;
  rchandle<exprnode> content_expr_h;

public:
  CompPIConstructor(
    const QueryLoc&,
    std::string target,
    rchandle<exprnode>);

  CompPIConstructor(
    const QueryLoc&,
    rchandle<exprnode>,
    rchandle<exprnode>);

  std::string get_target() const { return target; }

  rchandle<exprnode> get_target_expr() const { return target_expr_h; }

  rchandle<exprnode> get_content_expr() const { return content_expr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [143] SingleType ::= AtomicType "?"?

  [144] TypeDeclaration ::= "as" SequenceType

  [145] SequenceType ::= ("empty-sequence" "(" ")") | (ItemType OccurrenceIndicator?)

  [146] OccurrenceIndicator ::= "?" | "*" | "+"

  [147] ItemType ::= KindTest | ("item" "(" ")") | AtomicType

  [148] AtomicType ::= QName

  [149] KindTest ::= DocumentTest |
                     ElementTest |
                     AttributeTest |
                     SchemaElementTest |
                     SchemaAttributeTest |
                     PITest |
                     CommentTest |
                     TextTest |
                     AnyKindTest

  [150] AnyKindTest ::= "node" "(" ")"

  [151] DocumentTest ::= "document-node" "(" (ElementTest | SchemaElementTest)? ")"

  [152] TextTest ::= "text" "(" ")"

  [153] CommentTest ::= "comment" "(" ")"

  [154] NamespaceNodeTest ::= "namespace-node" "(" ")"

  [155] PITest ::= "processing-instruction" "(" (NCName | StringLiteral)? ")"

  [156] AttributeTest ::= "attribute" "(" (AttribNameOrWildcard ("," TypeName)?)? ")"

  [157] AttribNameOrWildcard ::= AttributeName | "*"

  [158] SchemaAttributeTest ::= "schema-attribute" "(" AttributeDeclaration ")"

  [159] AttributeDeclaration ::= AttributeName

  [160] ElementTest ::= "element" "(" (ElementNameOrWildcard ("," TypeName "?"?)?)? ")"

  [161] ElementNameOrWildcard ::= ElementName | "*"

  [162] SchemaElementTest ::= "schema-element" "(" ElementDeclaration ")"

  [163] ElementDeclaration ::= ElementName

  [164] AttributeName ::= QName

  [165] ElementName ::= QName

  [166] TypeName ::= QName

  [167] URILiteral ::= StringLiteral

  [168] Prefix ::= NCName
********************************************************************************/


/*******************************************************************************
  [143] SingleType ::= AtomicType "?"?
********************************************************************************/
class SingleType : public parsenode
{
protected:
  rchandle<AtomicType> atomic_type_h;
  bool hook_b;

public:
  SingleType(
    const QueryLoc&,
    rchandle<AtomicType>,
    bool hook_b);

  rchandle<AtomicType> get_atomic_type() const { return atomic_type_h; }

  bool get_hook_bit() const { return hook_b; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [144] TypeDeclaration ::= "as" SequenceType
********************************************************************************/


/*******************************************************************************
  [145] SequenceType ::= ("empty-sequence" "(" ")") |
                         (ItemType OccurrenceIndicator?)
********************************************************************************/
class SequenceType : public parsenode
{
protected:
  rchandle<parsenode> itemtype_h;
  rchandle<OccurrenceIndicator> occur_h;

public:
  SequenceType(
    const QueryLoc&,
    rchandle<parsenode>,
    rchandle<OccurrenceIndicator>);

  rchandle<parsenode> get_itemtype() const { return itemtype_h; }

  rchandle<OccurrenceIndicator> get_occur() const { return occur_h; }

  bool get_void_bit() const { return itemtype_h==NULL; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [146] OccurrenceIndicator ::= "?" | "*" | "+"
********************************************************************************/
class OccurrenceIndicator : public parsenode
{
protected:
  enum ParseConstants::occurrence_t type;

public:
  OccurrenceIndicator(
    const QueryLoc&,
    enum ParseConstants::occurrence_t);

  enum ParseConstants::occurrence_t get_type() const { return type; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [147] ItemType ::= KindTest | ("item" "(" ")") | AtomicType
********************************************************************************/
class ItemType : public parsenode
{
protected:
  bool item_test_b;

public:
  ItemType(
    const QueryLoc&,
    bool item_test_b);
    
  ItemType(const QueryLoc&);
    
  bool get_item_test_bit() const { return item_test_b; }

  virtual  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [148] AtomicType ::= QName
********************************************************************************/
class AtomicType : public parsenode
{
protected:
  rchandle<QName> qname_h;

public:
  AtomicType(
    const QueryLoc&,
    rchandle<QName>);
    
  rchandle<QName> get_qname() const { return qname_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [149] KindTest ::= DocumentTest |
                     ElementTest |
                     AttributeTest |
                     SchemaElementTest |
                     SchemaAttributeTest |
                     PITest |
                     CommentTest |
                     TextTest |
                     AnyKindTest
********************************************************************************/


/*******************************************************************************
  [150] AnyKindTest ::= "node" "(" ")"
********************************************************************************/
class AnyKindTest : public parsenode
{
public:
  AnyKindTest(const QueryLoc&);

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [151] DocumentTest ::= "document-node" "(" (ElementTest | SchemaElementTest)? ")"
********************************************************************************/
class DocumentTest : public parsenode
{
protected:
  rchandle<ElementTest> elem_test_h;
  rchandle<SchemaElementTest> schema_elem_test_h;

public:
  DocumentTest(const QueryLoc&);

  DocumentTest(const QueryLoc&, rchandle<ElementTest>);
  
  DocumentTest(const QueryLoc&, rchandle<SchemaElementTest>);

  rchandle<ElementTest> get_elem_test() const
  {
    return elem_test_h;
  }

  rchandle<SchemaElementTest> get_schema_elem_test() const
  {
    return schema_elem_test_h;
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [152] TextTest ::= "text" "(" ")"
********************************************************************************/
class TextTest : public parsenode
{
public:
  TextTest(const QueryLoc&);

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [153] CommentTest ::= "comment" "(" ")"
********************************************************************************/
class CommentTest : public parsenode
{
public:
  CommentTest(const QueryLoc&);

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [155] PITest ::= "processing-instruction" "(" (NCName | StringLiteral)? ")"
********************************************************************************/
class PITest : public parsenode
{
protected:
  std::string target;

public:
  PITest(
    const QueryLoc&,
    std::string target);

  std::string get_target() const { return target; }

  void accept(parsenode_visitor&) const;
};


/******************************************************************************
  [156] AttributeTest ::= "attribute" "(" (AttribNameOrWildcard ("," TypeName)?)? ")"

  [157] AttribNameOrWildcard ::= AttributeName | "*"
********************************************************************************/
class AttributeTest : public parsenode
{
protected:
  rchandle<QName> theAttrName;
  rchandle<TypeName> theTypeName;

public:
  AttributeTest(
    const QueryLoc&,
    rchandle<QName>,
    rchandle<TypeName>);

  rchandle<QName> get_attr_name() const    { return theAttrName; }

  rchandle<TypeName> get_type_name() const { return theTypeName; }

  bool is_wild() const                     { return theAttrName == NULL; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [158] SchemaAttributeTest ::= "schema-attribute" "(" AttributeDeclaration ")"

  [159] AttributeDeclaration ::= AttributeName
********************************************************************************/
class SchemaAttributeTest : public parsenode
{
protected:
  rchandle<QName> attr_h;

public:
  SchemaAttributeTest(
    const QueryLoc&,
    rchandle<QName>);

  rchandle<QName> get_attr() const { return attr_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [160] ElementTest ::= "element"
                        "(" (ElementNameOrWildcard ("," TypeName "?"?)?)? ")"

  [161] ElementNameOrWildcard ::= ElementName | "*"
********************************************************************************/
class ElementTest : public parsenode
{
protected:
  rchandle<QName>    theElementName;
  rchandle<TypeName> theTypeName;
  bool               theNilledAllowed;

public:
  ElementTest(
    const QueryLoc& l,
    rchandle<QName> qn,
    rchandle<TypeName> tn,
    bool na);

  rchandle<QName> getElementName() const { return theElementName; }

  rchandle<TypeName> getTypeName() const { return theTypeName; }

  bool isWildcard() const                { return theElementName == NULL; }

  bool isNilledAllowed() const           { return theNilledAllowed; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [162] SchemaElementTest ::= "schema-element" "(" ElementDeclaration ")"

  [163] ElementDeclaration ::= ElementName
********************************************************************************/
class SchemaElementTest : public parsenode
{
protected:
  rchandle<QName> elem_h;

public:
  SchemaElementTest(
    const QueryLoc&,
    rchandle<QName> _elem_h);

  rchandle<QName> get_elem() const { return elem_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [166] TypeName ::= QName
********************************************************************************/
class TypeName : public parsenode
{
protected:
  rchandle<QName> qname_h;
  bool optional_b;

public:
  TypeName(
    const QueryLoc&,
    rchandle<QName>);

  TypeName(
    const QueryLoc&,
    rchandle<QName>,
    bool);

  rchandle<QName> get_name() const { return qname_h; }

  bool get_optional_bit() const { return optional_b; }
  
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [169] TryCatchExpr ::= TryClause CatchClauseList

  [170] TryClause ::= "try" "{" TryTargetExpr "}"

  [171] TryTargetExpr ::= Expr
********************************************************************************/
class TryExpr : public exprnode
{
protected:
  rchandle<exprnode> theExprSingle;
  rchandle<exprnode> theCatchListExpr;

public:
  TryExpr(
    const QueryLoc& aQueryLoc,
    rchandle<exprnode> aExprSingle,
    rchandle<exprnode> aCatchListExpr)
  : exprnode(aQueryLoc),
    theExprSingle(aExprSingle),
    theCatchListExpr(aCatchListExpr)
  {}

  rchandle<exprnode> getExprSingle() const { return theExprSingle; }

  rchandle<CatchListExpr> getCatchListExpr() const 
  {
    return theCatchListExpr.cast<CatchListExpr> ();
  }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  CatchClauseList := CatchClause+
********************************************************************************/
class CatchListExpr : public exprnode
{
protected:
  std::vector<rchandle<CatchExpr> > theCatchExprs;

public:
  CatchListExpr(const QueryLoc& aQueryLoc)
  : exprnode(aQueryLoc)
  {}

  void push_back(rchandle<CatchExpr> aCatchExpr)
  {
    theCatchExprs.push_back(aCatchExpr);
  }

  rchandle<CatchExpr> operator[](int i) const
  {
    return theCatchExprs[i];
  }

  void accept(parsenode_visitor&) const;
};



/*******************************************************************************
  [172] CatchClause ::= "catch" CatchErrorList CatchVars? "{" Expr "}"

  [173] CatchErrorList ::= NameTest ("|" NameTest)*

  [174] CatchVars ::= "(" CatchErrorCode ("," CatchErrorDesc ("," CatchErrorVal)?)? ")"

  [175] CatchErrorCode ::= "$" VarName

  [176] CatchErrorDesc ::= "$" VarName

  [177] CatchErrorVal ::= "$" VarName
********************************************************************************/
class CatchExpr : public exprnode
{
public:
  typedef std::vector<rchandle<NameTest> > NameTestList;

protected:
  NameTestList        theNameTests;
  rchandle<QName>     theVarErrorCode;
  rchandle<QName>     theVarErrorDescr;
  rchandle<QName>     theVarErrorVal;
  rchandle<parsenode> theExprSingle;

public:
  CatchExpr(
    const QueryLoc& aQueryLoc,
    NameTestList& aNameTest,
    rchandle<QName> aVarErrorCode,
    rchandle<QName> aVarErrorDescr,
    rchandle<QName> aVarErrorVal,
    rchandle<parsenode> aExprSingle)
  :
    exprnode(aQueryLoc),
    theNameTests(aNameTest),
    theVarErrorCode(aVarErrorCode),
    theVarErrorDescr(aVarErrorDescr),
    theVarErrorVal(aVarErrorVal),
    theExprSingle(aExprSingle)
  {
  }

  const NameTestList &getNameTests() const { return theNameTests; }

  const QName* getVarErrorCode() const { return theVarErrorCode.getp(); }

  const QName* getVarErrorDescr() const { return theVarErrorDescr.getp(); }

  const QName* getVarErrorVal() const { return theVarErrorVal.getp(); }

  rchandle<parsenode> getExprSingle() const { return theExprSingle; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************
  [191] QName ::= [http://www.w3.org/TR/REC-xml-names/#NT-QName]

  The "qname" data member is either (a) the empty string, or (b) a single NCName,
  or (c) NCName1:NCName2. In cases (a) and (b), get_prefix() returns the empty
  string, and get_localname() returns "qname".

********************************************************************************/
class QName : public exprnode
{
protected:
  std::string       theQName;
  xqpStringStore_t  thePrefix;
  xqpStringStore_t  theLocalName;

public:
  QName(const QueryLoc&, const std::string& qname);

  const std::string& get_qname() const { return theQName; }

  const xqpStringStore_t& get_localname() const { return theLocalName; }

  const xqpStringStore_t& get_prefix() const { return thePrefix; }

  void accept(parsenode_visitor&) const;
};


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Scripting productions                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
class ExitExpr : public exprnode 
{
  rchandle<exprnode> value_h;
public:

  ExitExpr (const QueryLoc& loc_, rchandle<exprnode> val_)
    :
    exprnode (loc_),
    value_h (val_)
  {}

  rchandle<exprnode> get_value () { return value_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class AssignExpr : public exprnode 
{
  rchandle<QName>    theName;
  rchandle<exprnode> value_h;

public:
  AssignExpr (const QueryLoc& loc, rchandle<QName> name, rchandle<exprnode> val)
    :
    exprnode(loc),
    theName(name),
    value_h(val)
  {
  }

  const QName* get_name() const { return theName.getp(); }

  rchandle<exprnode> get_value () const { return value_h; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class FlowCtlStatement : public exprnode {
public:
  enum action { BREAK, CONTINUE };

private:
  enum action action;

public:
  FlowCtlStatement (const QueryLoc& loc_, enum action action_)
    : exprnode (loc_), action (action_)
  {}
  enum action get_action () const { return action; }
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class WhileExpr : public exprnode {
  rchandle<exprnode> cond;
  rchandle<BlockBody> body;

public:
  WhileExpr (const QueryLoc& loc_, rchandle<exprnode> cond_, rchandle<BlockBody> body_)
    : exprnode (loc_), cond (cond_), body (body_)
  {}
  rchandle<exprnode> get_cond () { return cond; }
  rchandle<BlockBody> get_body () { return body; }

  void accept(parsenode_visitor&) const;
};


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Eval                                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Eval := "using" EvalVarDeclList? "eval" { ExprSingle }

  EvalVarDeclList := EvalVarDecl+

  EvalVarDecl := "$" VarName

  Note: EvalVarDeclList is actually represented by a VarGetsDeclList parsenode
        and EvalVarDecls are  represented by VarGetsDec parsenodes.
********************************************************************************/
class EvalExpr : public exprnode 
{
protected:
  rchandle <VarGetsDeclList> vgdl;
  rchandle <exprnode> expr_h;

public:
  EvalExpr(
        const QueryLoc& loc_,
        rchandle <VarGetsDeclList> vgdl_,
        rchandle <parsenode> expr_)
    : exprnode(loc_),
      vgdl(vgdl_),
      expr_h(expr_.dyn_cast<exprnode> ())
  {}
  
  rchandle<VarGetsDeclList> get_vars () const { return vgdl; }

  rchandle<exprnode> get_expr () const { return expr_h; }

  void accept(parsenode_visitor&) const;
};


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Update productions                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
// [241]  RevalidationDecl
// -----------------------
class RevalidationDecl : public parsenode
/*______________________________________________________________________
|
|  ::= QNAME DECLARE_REVALIDATION_MODE
|_______________________________________________________________________*/
{
protected:
  enum StaticContextConsts::validation_mode_t mode;
public:
  RevalidationDecl(const QueryLoc& loc,
                   enum StaticContextConsts::validation_mode_t mode_)
    : parsenode (loc), mode (mode_)
  {}


public:
  enum StaticContextConsts::validation_mode_t get_mode () const { return mode; }
  void accept(parsenode_visitor&) const;

};


/*******************************************************************************

********************************************************************************/
// [242]  InsertExpr
// ----------------
class InsertExpr : public exprnode
/*______________________________________________________________________
|
|  ::= INSERT_NODE  ExprSingle  INTO  ExprSingle
|      |  INSERT_NODE  ExprSingle  AS  FIRST_INTO  ExprSingle
|      |  INSERT_NODE  ExprSingle  AS  LAST_INTO  ExprSingle
|      | INSERT_NODE  ExprSingle  AFTER  ExprSingle
|      | INSERT_NODE  ExprSingle  BEFORE  ExprSingle
|      | INSERT_NODES  ExprSingle  INTO  ExprSingle
|      |  INSERT_NODES  ExprSingle  AS  FIRST_INTO  ExprSingle
|      |  INSERT_NODES  ExprSingle  AS  LAST_INTO  ExprSingle
|      | INSERT_NODES  ExprSingle  AFTER  ExprSingle
|      | INSERT_NODES  ExprSingle  BEFORE  ExprSingle
|_______________________________________________________________________*/
{
protected:
  store::UpdateConsts::InsertType theInsertType;
  rchandle<exprnode> theSourceExpr;
  rchandle<exprnode> theTargetExpr;

public:
  InsertExpr(
    const QueryLoc&,
    store::UpdateConsts::InsertType,
    rchandle<exprnode> aSourceExpr,
    rchandle<exprnode> aTargetExpr);

public:
  rchandle<exprnode> getSourceExpr() const { return theSourceExpr; }
  rchandle<exprnode> getTargetExpr() const { return theTargetExpr; }
  store::UpdateConsts::InsertType getType() const { return theInsertType; }

public:
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
// [243] DeleteExpr
// ----------------
class DeleteExpr : public exprnode
/*______________________________________________________________________
|
|  ::= DO_DELETE  ExprSingle
|_______________________________________________________________________*/
{
protected:
  rchandle<exprnode> theTargetExpr;

public:
  DeleteExpr(
    const QueryLoc&,
    rchandle<exprnode>);

public:
  rchandle<exprnode>       getTargetExpr() const { return theTargetExpr; }

public:
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
// [244] ReplaceExpr
// -----------------
class ReplaceExpr : public exprnode
/*______________________________________________________________________
|
|  ::= DO_REPLACE  ExprSingle  WITH  ExprSingle
|      | DO_REPLACE  VALUE_OF  ExprSingle  WITH  ExprSingle
|_______________________________________________________________________*/
{
protected:
  store::UpdateConsts::ReplaceType theReplaceType;
  rchandle<exprnode> theTargetExpr;
  rchandle<exprnode> theReplaceExpr;

public:
  ReplaceExpr(
    const QueryLoc&,
    store::UpdateConsts::ReplaceType aReplaceType,
    rchandle<exprnode> aTargetExpr,
    rchandle<exprnode> aReplaceExpr);


public:
  store::UpdateConsts::ReplaceType getType() const { return theReplaceType; }
  rchandle<exprnode>        getTargetExpr() const  { return theTargetExpr; }
  rchandle<exprnode>        getReplaceExpr() const  { return theReplaceExpr; }

public:
  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
// [245] RenameExpr
// ----------------
class RenameExpr : public exprnode
/*______________________________________________________________________
|
|  ::= DO_RENAME  ExprSingle  AS  ExprSingle
|_______________________________________________________________________*/
{
protected:
  rchandle<exprnode> theTargetExpr;
  rchandle<exprnode> theNameExpr;

public:
  RenameExpr(
    const QueryLoc&,
    rchandle<exprnode> aTargetExpr,
    rchandle<exprnode> aName);


public:
  rchandle<exprnode> getTargetExpr() const { return theTargetExpr; }
  rchandle<exprnode> getNameExpr() const { return theNameExpr; }

public:
  void accept(parsenode_visitor&) const;
};



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

  CopyVarList := VarBinding |  CopyVarList "," "$"  VarBinding

  VarBinding := VarName ":=" ExprSingle
********************************************************************************/
class TransformExpr : public exprnode
{
protected:
  rchandle<CopyVarList> var_list;
  rchandle<exprnode> source_expr;
  rchandle<exprnode> target_expr;

public:
  TransformExpr(
    const QueryLoc& loc,
    rchandle<CopyVarList> var_list,
    rchandle<exprnode> source_expr,
    rchandle<exprnode> target_expr);


  rchandle<CopyVarList> get_var_list() const { return var_list; }
  rchandle<exprnode> get_source_expr() const { return source_expr; }
  rchandle<exprnode> get_target_expr() const { return target_expr; }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class CopyVarList : public exprnode
{
protected:
  std::vector<rchandle<VarBinding> > var_bindings;
  
public:
  CopyVarList(const QueryLoc& loc);

  void push_back(rchandle<VarBinding> binding) 
  {
    var_bindings.push_back(binding);
  }

  rchandle<VarBinding> operator[](int i) const 
  {
    return var_bindings[i];
  }

  size_t size () const { return var_bindings.size (); }

  void accept(parsenode_visitor&) const;
};


/*******************************************************************************

********************************************************************************/
class VarBinding : public exprnode
{
protected:
  rchandle<QName> var_name;
  rchandle<exprnode> expr;

public:
  VarBinding(
    const QueryLoc& loc,
    rchandle<QName> varname,
    rchandle<exprnode> expr);

  const QName* get_varname() const { return var_name.getp(); }

  rchandle<exprnode> get_expr() const { return expr; }

  void accept(parsenode_visitor&) const;
};


/*
 * LiteralFunctionItem := QName "#" IntegerLiteral
 */
class LiteralFunctionItem: public exprnode
{
  private:
    rchandle<QName> theQName;
    Integer& theArity;

  public:
    LiteralFunctionItem(const QueryLoc& loc_, rchandle<QName> aQName, Integer& aArity):
      exprnode(loc_), theQName(aQName), theArity(aArity){}

      rchandle<QName> getQName() const { return theQName; }
      const Integer& getArity() const { return theArity; }

    void accept(parsenode_visitor&) const;
};

/*
 * InlineFunction := "function" "(" ParamList? ")" ("as" SequenceType)? EnclosedExpr
 */
class InlineFunction: public exprnode
{
  private:
  rchandle<ParamList> theParamList;
  rchandle<SequenceType> theReturnType;
  rchandle<EnclosedExpr> theEnclosedExpr;

  public:
  InlineFunction(const QueryLoc& loc_, rchandle<ParamList> aParamList, rchandle<SequenceType> aReturnType, rchandle<EnclosedExpr> aEnclosedExpr):
    exprnode(loc_), theParamList(aParamList), theReturnType(aReturnType), theEnclosedExpr(aEnclosedExpr){}

  rchandle<ParamList> getParamList() const { return theParamList; }
  rchandle<SequenceType> getReturnType() const { return theReturnType; }
  rchandle<EnclosedExpr> getEnclosedExpr() const { return theEnclosedExpr; }

  void accept(parsenode_visitor&) const;
};


/*
 * AnyFunctionTest := "function" "(" "*" ")"
 */
class AnyFunctionTest: public parsenode
{
public:
  AnyFunctionTest(const QueryLoc& loc_): parsenode(loc_){}
  void accept(parsenode_visitor&) const;
};


/*
 * TypedFunctionTest := "(" (SequenceType ("," SequenceType)*)? ")"
 */
class TypeList: public parsenode
{
protected:
  std::vector<rchandle<parsenode> > theTypes;

public:
  TypeList(const QueryLoc& loc_): parsenode(loc_){}

  void push_back(rchandle<parsenode> aType) { theTypes.push_back(aType); }

  rchandle<parsenode> operator[](int i) const { return theTypes[i]; }

  int size() const { return theTypes.size (); }

  void accept(parsenode_visitor&) const;
};

/**
 * TypedFunctionTest := "function" "(" TypeList? ")"  "as" SequenceType
 */
class TypedFunctionTest: public parsenode
{
private:
  rchandle<TypeList> theArgTypes;
  rchandle<SequenceType> theReturnType;
  
public:
   TypedFunctionTest(const QueryLoc& loc_, rchandle<SequenceType> aReturnType):
     parsenode(loc_), theArgTypes(0), theReturnType(aReturnType){}
  TypedFunctionTest(const QueryLoc& loc_, rchandle<TypeList> aTypeList, rchandle<SequenceType> aReturnType):
     parsenode(loc_), theArgTypes(aTypeList), theReturnType(aReturnType){}
  
  rchandle<TypeList> getArgumentTypes() const { return theArgTypes; }
  rchandle<SequenceType> getReturnType() const { return theReturnType; }

    void accept(parsenode_visitor&) const;
};


/**
 * DynamicFunctionInvocation := FilterExpr LPAR ArgList RPAR
 */
class DynamicFunctionInvocation: public exprnode
{
private:
  rchandle<exprnode> thePrimaryExpr;
  rchandle<ArgList>     theArgList;

public:
  DynamicFunctionInvocation(
    const QueryLoc& loc_,
    rchandle<exprnode> aPrimaryExpr
  ): exprnode(loc_), thePrimaryExpr(aPrimaryExpr), theArgList(0){}
  
  DynamicFunctionInvocation(
    const QueryLoc& loc_,
    rchandle<exprnode> aPrimaryExpr,
    rchandle<ArgList> aArgList
  ): exprnode(loc_), thePrimaryExpr(aPrimaryExpr), theArgList(aArgList){}
  
  rchandle<exprnode> getPrimaryExpr() const { return thePrimaryExpr; }
  rchandle<ArgList> getArgList() const { return theArgList; }

    void accept(parsenode_visitor&) const;
};


///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Full-text productions                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


class FTAnd : public parsenode {
public:
  FTAnd(
    QueryLoc const&,
    FTAnd const*,
    FTMildNot const*
  );
  ~FTAnd();
  
  FTAnd const* get_ftand() const { return ftand_; }
  FTMildNot const* get_ftmild_not() const { return ftmild_not_; }

  void accept( parsenode_visitor& ) const;

private:
  FTAnd const *const ftand_;
  FTMildNot const *const ftmild_not_;
};


class FTAnyallOption : public parsenode {
public:
  FTAnyallOption(
    QueryLoc const&,
    ft_anyall_mode::type
  );

  ft_anyall_mode::type get_option() const { return option_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_anyall_mode::type const option_;
};


class FTBigUnit : public parsenode {
public:
  FTBigUnit(
    QueryLoc const&,
    ft_big_unit::type
  );

  ft_big_unit::type get_unit() const { return unit_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_big_unit::type const unit_;
};


class FTIgnoreOption : public parsenode {
public:
  FTIgnoreOption(
    QueryLoc const&,
    UnionExpr const*
  );
  ~FTIgnoreOption();

  UnionExpr const* get_union() const { return expr_; }

  void accept( parsenode_visitor& ) const;

private:
  UnionExpr const *const expr_;
};


class FTMatchOptions : public parsenode {
public:
  typedef std::list<FTMatchOption const*> match_option_list_t;

  FTMatchOptions( QueryLoc const& );
  ~FTMatchOptions();

  match_option_list_t const& get_match_options() const {
    return match_options_;
  }

  void push_back( FTMatchOption const *mo ) {
    match_options_.push_back( mo );
  }

  void accept( parsenode_visitor& ) const;

protected:
  match_option_list_t match_options_;
};


class FTMildNot : public parsenode {
public:
  FTMildNot(
    QueryLoc const&,
    FTMildNot const*,
    FTUnaryNot const*
  );
  ~FTMildNot();

  FTMildNot const* get_ftmild_not() const { return ftmild_not_; }
  FTUnaryNot const* get_ftunary_not() const { return ftunary_not_; }

  void accept( parsenode_visitor& ) const;

private:
  FTMildNot const *const ftmild_not_;
  FTUnaryNot const *const ftunary_not_;
};


class FTOptionDecl : public parsenode {
public:
  FTOptionDecl(
    QueryLoc const&,
    FTMatchOptions const*
  );
  ~FTOptionDecl();

  FTMatchOptions const* get_match_option() const { return match_options_; }

  void accept( parsenode_visitor& ) const;

private:
  FTMatchOptions const *const match_options_;
};


class FTOr : public parsenode {
public:
  FTOr(
    QueryLoc const&,
    FTOr const*,
    FTAnd const*
  );
  ~FTOr();

  FTOr const* get_ftor() const { return ftor_; }
  FTAnd const* get_ftand() const { return ftand_; }

  void accept( parsenode_visitor& ) const;

private:
  FTOr const *const ftor_;
  FTAnd const *const ftand_;
};


class FTPrimaryWithOptions : public parsenode {
public:
  FTPrimaryWithOptions(
    QueryLoc const&,
    FTPrimary const*,
    FTMatchOptions const*,
    FTWeight const*
  );
  ~FTPrimaryWithOptions();

  FTPrimary const* get_primary() const { return primary_; }
  FTMatchOptions const* get_match_options() const { return match_options_; }
  FTWeight const* get_weight() const { return weight_; }

  void accept( parsenode_visitor& ) const;

private:
  FTPrimary const *const primary_;
  FTMatchOptions const *const match_options_;
  FTWeight const *const weight_;
};


class FTRange : public parsenode {
public:
  FTRange(
    QueryLoc const&,
    ft_range_mode::type,
    AdditiveExpr const*,
    AdditiveExpr const* = NULL
  );
  ~FTRange();

  AdditiveExpr const* get_expr1() const { return expr1_; }
  AdditiveExpr const* get_expr2() const { return expr2_; }
  ft_range_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_range_mode::type mode_;
  AdditiveExpr const *const expr1_;
  AdditiveExpr const *const expr2_;
};


class FTTimes : public parsenode {
public:
  FTTimes(
    QueryLoc const&,
    FTRange const*
  );
  ~FTTimes();

  FTRange const* get_range() const { return range_; }

  void accept( parsenode_visitor& ) const;

private:
  FTRange const *const range_;
};


class FTUnaryNot : public parsenode {
public:
  FTUnaryNot(
    QueryLoc const&,
    FTPrimaryWithOptions const*
  );
  ~FTUnaryNot();

  FTPrimaryWithOptions const* get_primary_with_options() const
    { return primary_with_options_; }

  void accept( parsenode_visitor& ) const;

private:
  FTPrimaryWithOptions const *const primary_with_options_;
};


class FTUnit : public parsenode {
public:
  FTUnit( QueryLoc const&, ft_unit::type );

  ft_unit::type get_unit() const { return unit_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_unit::type const unit_;
};


class FTWeight : public parsenode {
public:
  FTWeight( QueryLoc const&, exprnode* );

  rchandle<exprnode> get_expr() const { return expr_; }

  void accept( parsenode_visitor& ) const;

private:
  rchandle<exprnode> expr_;
};


class FTWords : public parsenode {
public:
  FTWords(
    QueryLoc const&,
    FTWordsValue const*,
    FTAnyallOption const*
  );
  ~FTWords();

  FTWordsValue const* get_words_value() const { return words_value_; }
  FTAnyallOption const* get_any_all_option() const { return any_all_option_; }

  void accept( parsenode_visitor& ) const;

private:
  FTWordsValue const *const words_value_;
  FTAnyallOption const *const any_all_option_;
};


class FTWordsValue : public parsenode {
public:
  FTWordsValue(
    QueryLoc const&,
    StringLiteral*,
    exprnode*
  );

  rchandle<StringLiteral> get_literal() const { return literal_; }
  rchandle<exprnode> get_expr() const { return expr_; }

  void accept( parsenode_visitor& ) const;

private:
  rchandle<StringLiteral> literal_;
  rchandle<exprnode> expr_;
};


////////// FTPrimary & derived classes ////////////////////////////////////////

class FTPrimary : public parsenode {
protected:
  FTPrimary( QueryLoc const &loc ) : parsenode( loc ) { }
};


class FTSelection : public FTPrimary {
public:
  typedef std::list<FTPosFilter*> pos_filter_list_t;

  FTSelection(
    QueryLoc const&,
    FTOr const*,
    pos_filter_list_t*
  );
  ~FTSelection();

  FTOr const* get_ftor() const { return ftor_; }

  pos_filter_list_t const& get_pos_filter_list() const {
    return pos_filter_list_;
  }

  void accept( parsenode_visitor& ) const;

private:
  FTOr const *const ftor_;
  pos_filter_list_t pos_filter_list_;
};


class FTExtensionSelection : public FTPrimary {
public:
  FTExtensionSelection(
    QueryLoc const&,
    PragmaList const*,
    FTSelection const*
  );
  ~FTExtensionSelection();

  PragmaList const* get_pragma_list() const { return pragma_list_; }
  FTSelection const* get_selectionI() const { return ftselection_; }

  void accept( parsenode_visitor& ) const;

private:
  PragmaList const *const pragma_list_;
  FTSelection const *const ftselection_;
};


class FTWordsTimes : public FTPrimary {
public:
  FTWordsTimes(
    QueryLoc const&,
    FTWords const*,
    FTTimes const*
  );
  ~FTWordsTimes();

  FTWords const* get_words() const { return words_; }
  FTTimes const* get_times() const { return times_; }

  void accept( parsenode_visitor& ) const;

protected:
  FTWords const *words_;
  FTTimes const *times_;
};


////////// FTMatchOption & derived classes ////////////////////////////////////

class FTMatchOption : public parsenode {
protected:
  FTMatchOption( const QueryLoc& );
};


class FTCaseOption : public FTMatchOption {
public:
  FTCaseOption(
    QueryLoc const&,
    ft_case_mode::type = ft_case_mode::DEFAULT
  );

  ft_case_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_case_mode::type const mode_;
};


class FTDiacriticsOption : public FTMatchOption {
public:
  FTDiacriticsOption(
    QueryLoc const&,
    ft_diacritics_mode::type = ft_diacritics_mode::DEFAULT
  );

  ft_diacritics_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_diacritics_mode::type const mode_;
};


class FTExtensionOption : public FTMatchOption {
public:
  FTExtensionOption(
    QueryLoc const&,
    QName*,
    std::string const &value
  );

  rchandle<QName> get_qname() const { return qname_; }
  std::string const& get_val() const { return value_; }

  void accept( parsenode_visitor& ) const;

private:
  rchandle<QName> qname_;
  std::string const value_;
};


class FTLanguageOption : public FTMatchOption {
public:
  FTLanguageOption(
    QueryLoc const&,
    std::string const &language
  );

  std::string const& get_language() const { return language_; }

  void accept( parsenode_visitor& ) const;

private:
  std::string const language_;
};


class FTStemOption : public FTMatchOption {
public:
  FTStemOption(
    QueryLoc const&,
    ft_stem_mode::type = ft_stem_mode::DEFAULT
  );

  ft_stem_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_stem_mode::type const mode_;
};


class FTThesaurusOption : public FTMatchOption {
public:
  typedef std::list<FTThesaurusID*> thesaurus_id_list_t;

  FTThesaurusOption(
    QueryLoc const&,
    thesaurus_id_list_t*,
    bool includes_default,
    bool no_thesaurus = false
  );
  ~FTThesaurusOption();

  thesaurus_id_list_t const& get_thesaurus_id_list() const
    { return thesaurus_id_list_; }

  bool includes_default() const { return includes_default_; }
  bool no_thesaurus() const { return no_thesaurus_; }

  void accept( parsenode_visitor& ) const;

private:
  thesaurus_id_list_t thesaurus_id_list_;
  bool const includes_default_;
  bool const no_thesaurus_;
};


class FTThesaurusID : public parsenode {
public:
  FTThesaurusID(
    QueryLoc const&,
    std::string const &uri,
    std::string const &relationship,
    FTRange const*
  );
  ~FTThesaurusID();
  
  std::string const& get_uri() const { return uri_; }
  std::string const& get_relationship() const { return relationship_; }
  FTRange const* get_levels() const { return levels_; }

  void accept( parsenode_visitor& ) const;

private:
  std::string const uri_;
  std::string const relationship_;
  FTRange const *const levels_;
};


class FTStopWordOption : public FTMatchOption {
public:
  typedef std::list<FTStopWordsInclExcl*> incl_excl_list_t;

  FTStopWordOption(
    const QueryLoc&,
    FTStopWords const*,
    incl_excl_list_t*,
    ft_stop_words_mode::type = ft_stop_words_mode::DEFAULT
  );
  ~FTStopWordOption();

  incl_excl_list_t const& get_incl_excl_list() const { return incl_excl_list_; }
  ft_stop_words_mode::type get_mode() const { return mode_; }
  FTStopWords const* get_stop_words() const { return stop_words_; }

  void accept( parsenode_visitor& ) const;

private:
  FTStopWords const *const stop_words_;
  incl_excl_list_t incl_excl_list_;
  ft_stop_words_mode::type const mode_;
};


class FTStopWords : public parsenode {
public:
  typedef std::list<std::string> stop_word_list_t;

  FTStopWords(
    QueryLoc const&,
    std::string const &uri,
    stop_word_list_t*
  );

  std::string const& get_uri() const { return uri_; }
  stop_word_list_t const& get_stop_words() const { return stop_words_; }

  void accept( parsenode_visitor& ) const;

private:
  std::string const uri_;
  stop_word_list_t stop_words_;
};


class FTStopWordsInclExcl : public parsenode {
public:
  FTStopWordsInclExcl(
    QueryLoc const&,
    FTStopWords const*,
    ft_stop_words_unex::type
  );
  ~FTStopWordsInclExcl();

  FTStopWords const* get_stop_words() const { return stop_words_; }
  ft_stop_words_unex::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  FTStopWords const *const stop_words_;
  ft_stop_words_unex::type const mode_;
};


class FTWildCardOption : public FTMatchOption {
public:
  FTWildCardOption(
    QueryLoc const&,
    ft_wild_card_mode::type = ft_wild_card_mode::DEFAULT
  );

  ft_wild_card_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_wild_card_mode::type const mode_;
};

////////// FTPosFilter & derived classes //////////////////////////////////////

class FTPosFilter : public parsenode {
protected:
  FTPosFilter( QueryLoc const &loc ) : parsenode( loc ) { }
};


class FTContent : public FTPosFilter {
public:
  FTContent(
    QueryLoc const&,
    ft_content_mode::type
  );

  ft_content_mode::type get_mode() const { return mode_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_content_mode::type const mode_;
};


class FTDistance : public FTPosFilter {
public:
  FTDistance( const QueryLoc&, FTRange const*, FTUnit const* );
  ~FTDistance();

  FTRange const* get_distance() const { return distance_; }
  FTUnit const* get_unit() const { return unit_; }

  void accept( parsenode_visitor& ) const;

private:
  FTRange const *const distance_;
  FTUnit const *const unit_;
};


class FTOrder : public FTPosFilter {
public:
  FTOrder( QueryLoc const& );

  void accept( parsenode_visitor& ) const;
};


class FTScope : public FTPosFilter {
public:
  FTScope(
    QueryLoc const&,
    ft_scope::type,
    FTBigUnit const*
  );
  ~FTScope();

  ft_scope::type get_scope() const { return scope_; }
  FTBigUnit const* get_big_unit() const { return big_unit_; }

  void accept( parsenode_visitor& ) const;

private:
  ft_scope::type const scope_;
  FTBigUnit const *const big_unit_;
};


class FTWindow : public FTPosFilter {
public:
  FTWindow(
    QueryLoc const&,
    AdditiveExpr const *window,
    FTUnit const *unit
  );
  ~FTWindow();

  FTUnit const* get_unit() const { return unit_; }
  AdditiveExpr const* get_window() const { return window_; }

  void accept( parsenode_visitor& ) const;

private:
  AdditiveExpr const *const window_;
  FTUnit const *const unit_;
};


} // namespace zorba
#endif  /*  ZORBA_PARSENODES_H */
/* vim:set et sw=2 ts=2: */
