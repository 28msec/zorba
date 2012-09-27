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
#ifndef ZORBA_RUNTIME_ACCESSORS_ACCESSORS_H
#define ZORBA_RUNTIME_ACCESSORS_ACCESSORS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:node-name
 * Author: Zorba Team
 */
class NodeNameIterator : public NaryBaseIterator<NodeNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeNameIterator,
    NaryBaseIterator<NodeNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NodeNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeNameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:nilled
 * Author: Zorba Team
 */
class NilledIterator : public NaryBaseIterator<NilledIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NilledIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NilledIterator,
    NaryBaseIterator<NilledIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NilledIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NilledIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NilledIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:string
 * Author: Zorba Team
 */
class FnStringIteratorState : public PlanIteratorState
{
public:
  bool hasOutput; //

  FnStringIteratorState();

  ~FnStringIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnStringIterator : public NaryBaseIterator<FnStringIterator, FnStringIteratorState>
{ 
protected:
  bool theEmptyStringOnNULL; //
public:
  SERIALIZABLE_CLASS(FnStringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnStringIterator,
    NaryBaseIterator<FnStringIterator, FnStringIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnStringIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool emptyStringOnNULL)
    : 
    NaryBaseIterator<FnStringIterator, FnStringIteratorState>(sctx, loc, children),
    theEmptyStringOnNULL(emptyStringOnNULL)
  {}

  virtual ~FnStringIterator();

  bool isUpdating() const { return theEmptyStringOnNULL; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:data
 * Author: Zorba Team
 */
class FnDataIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theTypedValueIter; //

  FnDataIteratorState();

  ~FnDataIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnDataIterator : public NaryBaseIterator<FnDataIterator, FnDataIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnDataIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDataIterator,
    NaryBaseIterator<FnDataIterator, FnDataIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnDataIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnDataIterator, FnDataIteratorState>(sctx, loc, children)
  {}

  virtual ~FnDataIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:base-uri
 * Author: Zorba Team
 */
class BaseUriIterator : public NaryBaseIterator<BaseUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(BaseUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(BaseUriIterator,
    NaryBaseIterator<BaseUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  BaseUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<BaseUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~BaseUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:document-uri
 * Author: Zorba Team
 */
class DocumentUriIterator : public NaryBaseIterator<DocumentUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DocumentUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DocumentUriIterator,
    NaryBaseIterator<DocumentUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DocumentUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DocumentUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DocumentUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:root
 * Author: Zorba Team
 */
class RootIterator : public NaryBaseIterator<RootIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RootIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RootIterator,
    NaryBaseIterator<RootIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  RootIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RootIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RootIterator();

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
