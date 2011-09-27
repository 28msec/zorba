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
#ifndef ZORBA_RUNTIME_STORE_IDENTIFIERS_H
#define ZORBA_RUNTIME_STORE_IDENTIFIERS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 * Author: Zorba Team
 */
class NodeIdentifierIterator : public NaryBaseIterator<NodeIdentifierIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeIdentifierIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeIdentifierIterator,
    NaryBaseIterator<NodeIdentifierIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeIdentifierIterator, PlanIteratorState>*)this);
  }

  NodeIdentifierIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeIdentifierIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeIdentifierIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class HasIdentifierIterator : public NaryBaseIterator<HasIdentifierIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HasIdentifierIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HasIdentifierIterator,
    NaryBaseIterator<HasIdentifierIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HasIdentifierIterator, PlanIteratorState>*)this);
  }

  HasIdentifierIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HasIdentifierIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HasIdentifierIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class NodeByIdentifierIterator : public NaryBaseIterator<NodeByIdentifierIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeByIdentifierIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeByIdentifierIterator,
    NaryBaseIterator<NodeByIdentifierIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeByIdentifierIterator, PlanIteratorState>*)this);
  }

  NodeByIdentifierIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeByIdentifierIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeByIdentifierIterator();

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
