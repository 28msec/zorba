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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_INTROSPECTION_SCTX_H
#define ZORBA_RUNTIME_INTROSPECTION_SCTX_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      sc:statically-known-namespaces
 *    
 * Author: Zorba Team
 */
class StaticNamespacesIteratorState : public PlanIteratorState
{
public:
  store::NsBindings theBindings; //vector of namespace bindings
  ulong thePosition; //current position

  StaticNamespacesIteratorState();

  ~StaticNamespacesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class StaticNamespacesIterator : public NaryBaseIterator<StaticNamespacesIterator, StaticNamespacesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StaticNamespacesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StaticNamespacesIterator,
    NaryBaseIterator<StaticNamespacesIterator, StaticNamespacesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StaticNamespacesIterator, StaticNamespacesIteratorState>*)this);
  }

  StaticNamespacesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StaticNamespacesIterator, StaticNamespacesIteratorState>(sctx, loc, children)
  {}

  virtual ~StaticNamespacesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:default-function-namespace
 *    
 * Author: Zorba Team
 */
class DefaultFunctionNamespaceIterator : public NaryBaseIterator<DefaultFunctionNamespaceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DefaultFunctionNamespaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DefaultFunctionNamespaceIterator,
    NaryBaseIterator<DefaultFunctionNamespaceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DefaultFunctionNamespaceIterator, PlanIteratorState>*)this);
  }

  DefaultFunctionNamespaceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DefaultFunctionNamespaceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DefaultFunctionNamespaceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:base-uri
 *    
 * Author: Zorba Team
 */
class SctxBaseUriIterator : public NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxBaseUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxBaseUriIterator,
    NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>*)this);
  }

  SctxBaseUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxBaseUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:default-collation
 *    
 * Author: Zorba Team
 */
class SctxDefaultCollationIterator : public NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxDefaultCollationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxDefaultCollationIterator,
    NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>*)this);
  }

  SctxDefaultCollationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxDefaultCollationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:statically-known-namespace-binding
 *    
 * Author: Zorba Team
 */
class StaticNamespaceBindingIterator : public NaryBaseIterator<StaticNamespaceBindingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StaticNamespaceBindingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StaticNamespaceBindingIterator,
    NaryBaseIterator<StaticNamespaceBindingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StaticNamespaceBindingIterator, PlanIteratorState>*)this);
  }

  StaticNamespaceBindingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StaticNamespaceBindingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StaticNamespaceBindingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-variables
 *  
 * Author: Zorba Team
 */
class InscopeVariablesIteratorState : public PlanIteratorState
{
public:
  std::vector<var_expr_t> theVariables; //vector of variables
  ulong thePosition; //current position

  InscopeVariablesIteratorState();

  ~InscopeVariablesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InscopeVariablesIterator : public NaryBaseIterator<InscopeVariablesIterator, InscopeVariablesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InscopeVariablesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InscopeVariablesIterator,
    NaryBaseIterator<InscopeVariablesIterator, InscopeVariablesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InscopeVariablesIterator, InscopeVariablesIteratorState>*)this);
  }

  InscopeVariablesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InscopeVariablesIterator, InscopeVariablesIteratorState>(sctx, loc, children)
  {}

  virtual ~InscopeVariablesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:default-collection-type
 *  
 * Author: Zorba Team
 */
class DefaultCollectionTypeIterator : public NaryBaseIterator<DefaultCollectionTypeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DefaultCollectionTypeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DefaultCollectionTypeIterator,
    NaryBaseIterator<DefaultCollectionTypeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DefaultCollectionTypeIterator, PlanIteratorState>*)this);
  }

  DefaultCollectionTypeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DefaultCollectionTypeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DefaultCollectionTypeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:xpath10-compatibility-mode
 *  
 * Author: Zorba Team
 */
class XPath10CompatModeIterator : public NaryBaseIterator<XPath10CompatModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(XPath10CompatModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(XPath10CompatModeIterator,
    NaryBaseIterator<XPath10CompatModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<XPath10CompatModeIterator, PlanIteratorState>*)this);
  }

  XPath10CompatModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<XPath10CompatModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~XPath10CompatModeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:statically-known-documents
 *  
 * Author: Zorba Team
 */
class StaticallyKnownDocumentsIteratorState : public PlanIteratorState
{
public:
  std::vector < zstring > theDocuments; //vector of document URIs
  ulong thePosition; //current position

  StaticallyKnownDocumentsIteratorState();

  ~StaticallyKnownDocumentsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class StaticallyKnownDocumentsIterator : public NaryBaseIterator<StaticallyKnownDocumentsIterator, StaticallyKnownDocumentsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StaticallyKnownDocumentsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StaticallyKnownDocumentsIterator,
    NaryBaseIterator<StaticallyKnownDocumentsIterator, StaticallyKnownDocumentsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StaticallyKnownDocumentsIterator, StaticallyKnownDocumentsIteratorState>*)this);
  }

  StaticallyKnownDocumentsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StaticallyKnownDocumentsIterator, StaticallyKnownDocumentsIteratorState>(sctx, loc, children)
  {}

  virtual ~StaticallyKnownDocumentsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:statically-known-document-type
 *  
 * Author: Zorba Team
 */
class StaticallyKnownDocumentTypeIterator : public NaryBaseIterator<StaticallyKnownDocumentTypeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StaticallyKnownDocumentTypeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StaticallyKnownDocumentTypeIterator,
    NaryBaseIterator<StaticallyKnownDocumentTypeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StaticallyKnownDocumentTypeIterator, PlanIteratorState>*)this);
  }

  StaticallyKnownDocumentTypeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StaticallyKnownDocumentTypeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~StaticallyKnownDocumentTypeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:statically-known-collations
 *  
 * Author: Zorba Team
 */
class StaticallyKnownCollationsIteratorState : public PlanIteratorState
{
public:
  std::vector < std::string > theCollations; //vector of collation uris
  ulong thePosition; //current position

  StaticallyKnownCollationsIteratorState();

  ~StaticallyKnownCollationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class StaticallyKnownCollationsIterator : public NaryBaseIterator<StaticallyKnownCollationsIterator, StaticallyKnownCollationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(StaticallyKnownCollationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StaticallyKnownCollationsIterator,
    NaryBaseIterator<StaticallyKnownCollationsIterator, StaticallyKnownCollationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<StaticallyKnownCollationsIterator, StaticallyKnownCollationsIteratorState>*)this);
  }

  StaticallyKnownCollationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<StaticallyKnownCollationsIterator, StaticallyKnownCollationsIteratorState>(sctx, loc, children)
  {}

  virtual ~StaticallyKnownCollationsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:construction-mode
 *  
 * Author: Zorba Team
 */
class ConstructionModeIterator : public NaryBaseIterator<ConstructionModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ConstructionModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ConstructionModeIterator,
    NaryBaseIterator<ConstructionModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ConstructionModeIterator, PlanIteratorState>*)this);
  }

  ConstructionModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ConstructionModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ConstructionModeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:ordering-mode
 *  
 * Author: Zorba Team
 */
class OrderingModeIterator : public NaryBaseIterator<OrderingModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(OrderingModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(OrderingModeIterator,
    NaryBaseIterator<OrderingModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<OrderingModeIterator, PlanIteratorState>*)this);
  }

  OrderingModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<OrderingModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~OrderingModeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:default-order
 *  
 * Author: Zorba Team
 */
class DefaultOrderIterator : public NaryBaseIterator<DefaultOrderIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DefaultOrderIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DefaultOrderIterator,
    NaryBaseIterator<DefaultOrderIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DefaultOrderIterator, PlanIteratorState>*)this);
  }

  DefaultOrderIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DefaultOrderIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DefaultOrderIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:boundary-space-policy
 *  
 * Author: Zorba Team
 */
class BoundarySpacePolicyIterator : public NaryBaseIterator<BoundarySpacePolicyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(BoundarySpacePolicyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(BoundarySpacePolicyIterator,
    NaryBaseIterator<BoundarySpacePolicyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<BoundarySpacePolicyIterator, PlanIteratorState>*)this);
  }

  BoundarySpacePolicyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<BoundarySpacePolicyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~BoundarySpacePolicyIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:copy-namespaces-mode
 *  
 * Author: Zorba Team
 */
class CopyNamespacesModeIterator : public NaryBaseIterator<CopyNamespacesModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CopyNamespacesModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CopyNamespacesModeIterator,
    NaryBaseIterator<CopyNamespacesModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<CopyNamespacesModeIterator, PlanIteratorState>*)this);
  }

  CopyNamespacesModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CopyNamespacesModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CopyNamespacesModeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:function-names
 *  
 * Author: Zorba Team
 */
class FunctionNamesIteratorState : public PlanIteratorState
{
public:
  std::vector < function *> theFunctions; //vector of functions
  ulong thePosition; //current position

  FunctionNamesIteratorState();

  ~FunctionNamesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FunctionNamesIterator : public NaryBaseIterator<FunctionNamesIterator, FunctionNamesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionNamesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionNamesIterator,
    NaryBaseIterator<FunctionNamesIterator, FunctionNamesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionNamesIterator, FunctionNamesIteratorState>*)this);
  }

  FunctionNamesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionNamesIterator, FunctionNamesIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionNamesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:function-arguments-count
 *  
 * Author: Zorba Team
 */
class FunctionArgumentsCountIteratorState : public PlanIteratorState
{
public:
  std::vector < int > arities; //vector of arities
  unsigned int position; //current position

  FunctionArgumentsCountIteratorState();

  ~FunctionArgumentsCountIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FunctionArgumentsCountIterator : public NaryBaseIterator<FunctionArgumentsCountIterator, FunctionArgumentsCountIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionArgumentsCountIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionArgumentsCountIterator,
    NaryBaseIterator<FunctionArgumentsCountIterator, FunctionArgumentsCountIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionArgumentsCountIterator, FunctionArgumentsCountIteratorState>*)this);
  }

  FunctionArgumentsCountIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionArgumentsCountIterator, FunctionArgumentsCountIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionArgumentsCountIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-schema-types
 *  
 * Author: Zorba Team
 */
class InScopeSchemaTypesIteratorState : public PlanIteratorState
{
public:
  unsigned int ns_pos; //current position
  unsigned int elem_pos; //current position

  InScopeSchemaTypesIteratorState();

  ~InScopeSchemaTypesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopeSchemaTypesIterator : public NaryBaseIterator<InScopeSchemaTypesIterator, InScopeSchemaTypesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopeSchemaTypesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopeSchemaTypesIterator,
    NaryBaseIterator<InScopeSchemaTypesIterator, InScopeSchemaTypesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InScopeSchemaTypesIterator, InScopeSchemaTypesIteratorState>*)this);
  }

  InScopeSchemaTypesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InScopeSchemaTypesIterator, InScopeSchemaTypesIteratorState>(sctx, loc, children)
  {}

  virtual ~InScopeSchemaTypesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-element-declarations
 *  
 * Author: Zorba Team
 */
class InScopeElementDeclarationsIteratorState : public PlanIteratorState
{
public:
  unsigned int ns_pos; //current position
  unsigned int elem_pos; //current position

  InScopeElementDeclarationsIteratorState();

  ~InScopeElementDeclarationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopeElementDeclarationsIterator : public NaryBaseIterator<InScopeElementDeclarationsIterator, InScopeElementDeclarationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopeElementDeclarationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopeElementDeclarationsIterator,
    NaryBaseIterator<InScopeElementDeclarationsIterator, InScopeElementDeclarationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InScopeElementDeclarationsIterator, InScopeElementDeclarationsIteratorState>*)this);
  }

  InScopeElementDeclarationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InScopeElementDeclarationsIterator, InScopeElementDeclarationsIteratorState>(sctx, loc, children)
  {}

  virtual ~InScopeElementDeclarationsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-attribute-declarations
 *  
 * Author: Zorba Team
 */
class InScopeAttributeDeclarationsIteratorState : public PlanIteratorState
{
public:
  unsigned int ns_pos; //current position
  unsigned int elem_pos; //current position

  InScopeAttributeDeclarationsIteratorState();

  ~InScopeAttributeDeclarationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopeAttributeDeclarationsIterator : public NaryBaseIterator<InScopeAttributeDeclarationsIterator, InScopeAttributeDeclarationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopeAttributeDeclarationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopeAttributeDeclarationsIterator,
    NaryBaseIterator<InScopeAttributeDeclarationsIterator, InScopeAttributeDeclarationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InScopeAttributeDeclarationsIterator, InScopeAttributeDeclarationsIteratorState>*)this);
  }

  InScopeAttributeDeclarationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InScopeAttributeDeclarationsIterator, InScopeAttributeDeclarationsIteratorState>(sctx, loc, children)
  {}

  virtual ~InScopeAttributeDeclarationsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-schema-types
 *  
 * Author: Zorba Team
 */
class InScopeElementGroupsIteratorState : public PlanIteratorState
{
public:
  unsigned int ns_pos; //current position
  unsigned int elem_pos; //current position

  InScopeElementGroupsIteratorState();

  ~InScopeElementGroupsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopeElementGroupsIterator : public NaryBaseIterator<InScopeElementGroupsIterator, InScopeElementGroupsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopeElementGroupsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopeElementGroupsIterator,
    NaryBaseIterator<InScopeElementGroupsIterator, InScopeElementGroupsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InScopeElementGroupsIterator, InScopeElementGroupsIteratorState>*)this);
  }

  InScopeElementGroupsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InScopeElementGroupsIterator, InScopeElementGroupsIteratorState>(sctx, loc, children)
  {}

  virtual ~InScopeElementGroupsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    sc:in-scope-schema-types
 *  
 * Author: Zorba Team
 */
class InScopeAttributeGroupsIteratorState : public PlanIteratorState
{
public:
  unsigned int ns_pos; //current position
  unsigned int elem_pos; //current position

  InScopeAttributeGroupsIteratorState();

  ~InScopeAttributeGroupsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopeAttributeGroupsIterator : public NaryBaseIterator<InScopeAttributeGroupsIterator, InScopeAttributeGroupsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopeAttributeGroupsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopeAttributeGroupsIterator,
    NaryBaseIterator<InScopeAttributeGroupsIterator, InScopeAttributeGroupsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InScopeAttributeGroupsIterator, InScopeAttributeGroupsIteratorState>*)this);
  }

  InScopeAttributeGroupsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InScopeAttributeGroupsIterator, InScopeAttributeGroupsIteratorState>(sctx, loc, children)
  {}

  virtual ~InScopeAttributeGroupsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:option
 *    
 * Author: Zorba Team
 */
class OptionIterator : public NaryBaseIterator<OptionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(OptionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(OptionIterator,
    NaryBaseIterator<OptionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<OptionIterator, PlanIteratorState>*)this);
  }

  OptionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<OptionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~OptionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      sc:option
 *    
 * Author: Zorba Team
 */
class FunctionAnnotationsIteratorState : public PlanIteratorState
{
public:
  const function* theFunction; //the function
  ulong thePosition; //current position

  FunctionAnnotationsIteratorState();

  ~FunctionAnnotationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FunctionAnnotationsIterator : public NaryBaseIterator<FunctionAnnotationsIterator, FunctionAnnotationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionAnnotationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionAnnotationsIterator,
    NaryBaseIterator<FunctionAnnotationsIterator, FunctionAnnotationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionAnnotationsIterator, FunctionAnnotationsIteratorState>*)this);
  }

  FunctionAnnotationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionAnnotationsIterator, FunctionAnnotationsIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionAnnotationsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
