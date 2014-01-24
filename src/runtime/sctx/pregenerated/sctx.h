/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_RUNTIME_SCTX_SCTX_H
#define ZORBA_RUNTIME_SCTX_SCTX_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "context/static_context.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class SctxBaseUriIterator : public NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxBaseUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxBaseUriIterator,
    NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxBaseUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxBaseUriIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxBoundarySpacePolicyIterator : public NaryBaseIterator<SctxBoundarySpacePolicyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxBoundarySpacePolicyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxBoundarySpacePolicyIterator,
    NaryBaseIterator<SctxBoundarySpacePolicyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxBoundarySpacePolicyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxBoundarySpacePolicyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxBoundarySpacePolicyIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxConstructionModeIterator : public NaryBaseIterator<SctxConstructionModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxConstructionModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxConstructionModeIterator,
    NaryBaseIterator<SctxConstructionModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxConstructionModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxConstructionModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxConstructionModeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxCopyNamespacesModeIterator : public NaryBaseIterator<SctxCopyNamespacesModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxCopyNamespacesModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxCopyNamespacesModeIterator,
    NaryBaseIterator<SctxCopyNamespacesModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxCopyNamespacesModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxCopyNamespacesModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxCopyNamespacesModeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxDefaultCollationIterator : public NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxDefaultCollationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxDefaultCollationIterator,
    NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxDefaultCollationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxDefaultCollationIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxDefaultCollectionTypeIterator : public NaryBaseIterator<SctxDefaultCollectionTypeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxDefaultCollectionTypeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxDefaultCollectionTypeIterator,
    NaryBaseIterator<SctxDefaultCollectionTypeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxDefaultCollectionTypeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxDefaultCollectionTypeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxDefaultCollectionTypeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxDefaultFunctionNamespaceIterator : public NaryBaseIterator<SctxDefaultFunctionNamespaceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxDefaultFunctionNamespaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxDefaultFunctionNamespaceIterator,
    NaryBaseIterator<SctxDefaultFunctionNamespaceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxDefaultFunctionNamespaceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxDefaultFunctionNamespaceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxDefaultFunctionNamespaceIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxDefaultOrderIterator : public NaryBaseIterator<SctxDefaultOrderIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxDefaultOrderIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxDefaultOrderIterator,
    NaryBaseIterator<SctxDefaultOrderIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxDefaultOrderIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxDefaultOrderIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxDefaultOrderIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxFunctionAnnotationsIteratorState : public PlanIteratorState
{
public:
  const function* theFunction; //
  unsigned long thePosition; //

  SctxFunctionAnnotationsIteratorState();

  ~SctxFunctionAnnotationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxFunctionAnnotationsIterator : public NaryBaseIterator<SctxFunctionAnnotationsIterator, SctxFunctionAnnotationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxFunctionAnnotationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxFunctionAnnotationsIterator,
    NaryBaseIterator<SctxFunctionAnnotationsIterator, SctxFunctionAnnotationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxFunctionAnnotationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxFunctionAnnotationsIterator, SctxFunctionAnnotationsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxFunctionAnnotationsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxFunctionArgumentsCountIteratorState : public PlanIteratorState
{
public:
  std::vector<int> arities_; //
  std::vector<int>::const_iterator it_; //

  SctxFunctionArgumentsCountIteratorState();

  ~SctxFunctionArgumentsCountIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxFunctionArgumentsCountIterator : public NaryBaseIterator<SctxFunctionArgumentsCountIterator, SctxFunctionArgumentsCountIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxFunctionArgumentsCountIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxFunctionArgumentsCountIterator,
    NaryBaseIterator<SctxFunctionArgumentsCountIterator, SctxFunctionArgumentsCountIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxFunctionArgumentsCountIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxFunctionArgumentsCountIterator, SctxFunctionArgumentsCountIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxFunctionArgumentsCountIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxFunctionNamesIteratorState : public PlanIteratorState
{
public:
  std::vector<function*> theFunctions; //
  unsigned long thePosition; //

  SctxFunctionNamesIteratorState();

  ~SctxFunctionNamesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxFunctionNamesIterator : public NaryBaseIterator<SctxFunctionNamesIterator, SctxFunctionNamesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxFunctionNamesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxFunctionNamesIterator,
    NaryBaseIterator<SctxFunctionNamesIterator, SctxFunctionNamesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxFunctionNamesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxFunctionNamesIterator, SctxFunctionNamesIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxFunctionNamesIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxFunctionsIteratorState : public PlanIteratorState
{
public:
  std::vector<function*> funcs_; //
  std::vector<function*>::const_iterator it_; //

  SctxFunctionsIteratorState();

  ~SctxFunctionsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxFunctionsIterator : public NaryBaseIterator<SctxFunctionsIterator, SctxFunctionsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxFunctionsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxFunctionsIterator,
    NaryBaseIterator<SctxFunctionsIterator, SctxFunctionsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxFunctionsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxFunctionsIterator, SctxFunctionsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxFunctionsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInScopeAttributeDeclarationsIteratorState : public PlanIteratorState
{
public:
  unsigned ns_pos; //
  unsigned elem_pos; //

  SctxInScopeAttributeDeclarationsIteratorState();

  ~SctxInScopeAttributeDeclarationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInScopeAttributeDeclarationsIterator : public NaryBaseIterator<SctxInScopeAttributeDeclarationsIterator, SctxInScopeAttributeDeclarationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInScopeAttributeDeclarationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInScopeAttributeDeclarationsIterator,
    NaryBaseIterator<SctxInScopeAttributeDeclarationsIterator, SctxInScopeAttributeDeclarationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInScopeAttributeDeclarationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInScopeAttributeDeclarationsIterator, SctxInScopeAttributeDeclarationsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInScopeAttributeDeclarationsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInScopeAttributeGroupsIteratorState : public PlanIteratorState
{
public:
  unsigned ns_pos; //
  unsigned elem_pos; //

  SctxInScopeAttributeGroupsIteratorState();

  ~SctxInScopeAttributeGroupsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInScopeAttributeGroupsIterator : public NaryBaseIterator<SctxInScopeAttributeGroupsIterator, SctxInScopeAttributeGroupsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInScopeAttributeGroupsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInScopeAttributeGroupsIterator,
    NaryBaseIterator<SctxInScopeAttributeGroupsIterator, SctxInScopeAttributeGroupsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInScopeAttributeGroupsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInScopeAttributeGroupsIterator, SctxInScopeAttributeGroupsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInScopeAttributeGroupsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInScopeElementDeclarationsIteratorState : public PlanIteratorState
{
public:
  unsigned ns_pos; //
  unsigned elem_pos; //

  SctxInScopeElementDeclarationsIteratorState();

  ~SctxInScopeElementDeclarationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInScopeElementDeclarationsIterator : public NaryBaseIterator<SctxInScopeElementDeclarationsIterator, SctxInScopeElementDeclarationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInScopeElementDeclarationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInScopeElementDeclarationsIterator,
    NaryBaseIterator<SctxInScopeElementDeclarationsIterator, SctxInScopeElementDeclarationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInScopeElementDeclarationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInScopeElementDeclarationsIterator, SctxInScopeElementDeclarationsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInScopeElementDeclarationsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInScopeElementGroupsIteratorState : public PlanIteratorState
{
public:
  unsigned ns_pos; //
  unsigned elem_pos; //

  SctxInScopeElementGroupsIteratorState();

  ~SctxInScopeElementGroupsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInScopeElementGroupsIterator : public NaryBaseIterator<SctxInScopeElementGroupsIterator, SctxInScopeElementGroupsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInScopeElementGroupsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInScopeElementGroupsIterator,
    NaryBaseIterator<SctxInScopeElementGroupsIterator, SctxInScopeElementGroupsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInScopeElementGroupsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInScopeElementGroupsIterator, SctxInScopeElementGroupsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInScopeElementGroupsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInScopeSchemaTypesIteratorState : public PlanIteratorState
{
public:
  unsigned ns_pos; //
  unsigned elem_pos; //

  SctxInScopeSchemaTypesIteratorState();

  ~SctxInScopeSchemaTypesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInScopeSchemaTypesIterator : public NaryBaseIterator<SctxInScopeSchemaTypesIterator, SctxInScopeSchemaTypesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInScopeSchemaTypesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInScopeSchemaTypesIterator,
    NaryBaseIterator<SctxInScopeSchemaTypesIterator, SctxInScopeSchemaTypesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInScopeSchemaTypesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInScopeSchemaTypesIterator, SctxInScopeSchemaTypesIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInScopeSchemaTypesIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxInscopeVariablesIteratorState : public PlanIteratorState
{
public:
  std::vector<VarInfo*> vars_; //
  std::vector<VarInfo*>::const_iterator it_; //
  csize thePosition; //

  SctxInscopeVariablesIteratorState();

  ~SctxInscopeVariablesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxInscopeVariablesIterator : public NaryBaseIterator<SctxInscopeVariablesIterator, SctxInscopeVariablesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxInscopeVariablesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxInscopeVariablesIterator,
    NaryBaseIterator<SctxInscopeVariablesIterator, SctxInscopeVariablesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxInscopeVariablesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxInscopeVariablesIterator, SctxInscopeVariablesIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxInscopeVariablesIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxOptionIterator : public NaryBaseIterator<SctxOptionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxOptionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxOptionIterator,
    NaryBaseIterator<SctxOptionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxOptionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxOptionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxOptionIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxOrderingModeIterator : public NaryBaseIterator<SctxOrderingModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxOrderingModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxOrderingModeIterator,
    NaryBaseIterator<SctxOrderingModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxOrderingModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxOrderingModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxOrderingModeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxStaticallyKnownCollationsIteratorState : public PlanIteratorState
{
public:
  std::vector<std::string> coll_; //
  std::vector<std::string>::const_iterator it_; //

  SctxStaticallyKnownCollationsIteratorState();

  ~SctxStaticallyKnownCollationsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxStaticallyKnownCollationsIterator : public NaryBaseIterator<SctxStaticallyKnownCollationsIterator, SctxStaticallyKnownCollationsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxStaticallyKnownCollationsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxStaticallyKnownCollationsIterator,
    NaryBaseIterator<SctxStaticallyKnownCollationsIterator, SctxStaticallyKnownCollationsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxStaticallyKnownCollationsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxStaticallyKnownCollationsIterator, SctxStaticallyKnownCollationsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxStaticallyKnownCollationsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxStaticallyKnownDocumentsIteratorState : public PlanIteratorState
{
public:
  std::vector<zstring> docs_; //
  std::vector<zstring>::const_iterator it_; //

  SctxStaticallyKnownDocumentsIteratorState();

  ~SctxStaticallyKnownDocumentsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxStaticallyKnownDocumentsIterator : public NaryBaseIterator<SctxStaticallyKnownDocumentsIterator, SctxStaticallyKnownDocumentsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxStaticallyKnownDocumentsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxStaticallyKnownDocumentsIterator,
    NaryBaseIterator<SctxStaticallyKnownDocumentsIterator, SctxStaticallyKnownDocumentsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxStaticallyKnownDocumentsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxStaticallyKnownDocumentsIterator, SctxStaticallyKnownDocumentsIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxStaticallyKnownDocumentsIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxStaticallyKnownDocumentTypeIterator : public NaryBaseIterator<SctxStaticallyKnownDocumentTypeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxStaticallyKnownDocumentTypeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxStaticallyKnownDocumentTypeIterator,
    NaryBaseIterator<SctxStaticallyKnownDocumentTypeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxStaticallyKnownDocumentTypeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxStaticallyKnownDocumentTypeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxStaticallyKnownDocumentTypeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxStaticallyKnownNamespaceBindingIterator : public NaryBaseIterator<SctxStaticallyKnownNamespaceBindingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxStaticallyKnownNamespaceBindingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxStaticallyKnownNamespaceBindingIterator,
    NaryBaseIterator<SctxStaticallyKnownNamespaceBindingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxStaticallyKnownNamespaceBindingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxStaticallyKnownNamespaceBindingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxStaticallyKnownNamespaceBindingIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxStaticallyKnownNamespacesIteratorState : public PlanIteratorState
{
public:
  store::NsBindings bindings_; //
  store::NsBindings::const_iterator it_; //

  SctxStaticallyKnownNamespacesIteratorState();

  ~SctxStaticallyKnownNamespacesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SctxStaticallyKnownNamespacesIterator : public NaryBaseIterator<SctxStaticallyKnownNamespacesIterator, SctxStaticallyKnownNamespacesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxStaticallyKnownNamespacesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxStaticallyKnownNamespacesIterator,
    NaryBaseIterator<SctxStaticallyKnownNamespacesIterator, SctxStaticallyKnownNamespacesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxStaticallyKnownNamespacesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxStaticallyKnownNamespacesIterator, SctxStaticallyKnownNamespacesIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxStaticallyKnownNamespacesIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SctxXPath10CompatModeIterator : public NaryBaseIterator<SctxXPath10CompatModeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SctxXPath10CompatModeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SctxXPath10CompatModeIterator,
    NaryBaseIterator<SctxXPath10CompatModeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SctxXPath10CompatModeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SctxXPath10CompatModeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~SctxXPath10CompatModeIterator();

  zstring getNameAsString() const;

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
