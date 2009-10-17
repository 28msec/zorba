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

#ifndef ZORBA_RUNTIME_ACCESSORS_ACCESSORS_H
#define ZORBA_RUNTIME_ACCESSORS_ACCESSORS_H

#include "common/shared_types.h"

#include "runtime/base/narybase.h"

namespace zorba {



/**
 * fn:node-name
 * 
 * Author: Zorba Team * 
 */
class NodeNameIterator: public NaryBaseIterator <NodeNameIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(NodeNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeNameIterator,
  NaryBaseIterator<NodeNameIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeNameIterator, PlanIteratorState>*)this);

  }

  NodeNameIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<NodeNameIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~NodeNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:nilled
 * 
 * Author: Zorba Team * 
 */
class NilledIterator: public NaryBaseIterator <NilledIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(NilledIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NilledIterator,
  NaryBaseIterator<NilledIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<NilledIterator, PlanIteratorState>*)this);

  }

  NilledIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<NilledIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~NilledIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:string
 * 
 * Author: Zorba Team * 
 */
class StringIteratorState : public PlanIteratorState
{
public:
  bool hasOutput; //

  void init(PlanState&);
  void reset(PlanState&);
};

class StringIterator: public NaryBaseIterator <StringIterator, StringIteratorState> {
protected:
  bool theEmptyStringOnNULL; //
public:
  SERIALIZABLE_CLASS(StringIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(StringIterator,
  NaryBaseIterator<StringIterator, StringIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<StringIterator, StringIteratorState>*)this);

    ar & theEmptyStringOnNULL;
  }

  StringIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren,
  bool emptyStringOnNULL)
  :
  NaryBaseIterator<StringIterator, StringIteratorState>
  (sctx, loc, aChildren),
  theEmptyStringOnNULL(emptyStringOnNULL){}

  virtual ~StringIterator();

  virtual bool isUpdating() const { return theEmptyStringOnNULL; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:base-uri
 * 
 * Author: Zorba Team * 
 */
class BaseUriIterator: public NaryBaseIterator <BaseUriIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(BaseUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(BaseUriIterator,
  NaryBaseIterator<BaseUriIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<BaseUriIterator, PlanIteratorState>*)this);

  }

  BaseUriIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<BaseUriIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~BaseUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:document-uri
 * 
 * Author: Zorba Team * 
 */
class DocumentUriIterator: public NaryBaseIterator <DocumentUriIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(DocumentUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DocumentUriIterator,
  NaryBaseIterator<DocumentUriIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<DocumentUriIterator, PlanIteratorState>*)this);

  }

  DocumentUriIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<DocumentUriIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~DocumentUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:root
 * 
 * Author: Zorba Team * 
 */
class RootIterator: public NaryBaseIterator <RootIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(RootIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RootIterator,
  NaryBaseIterator<RootIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<RootIterator, PlanIteratorState>*)this);

  }

  RootIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<RootIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~RootIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};



}

#endif 
