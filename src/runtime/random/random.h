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
#ifndef ZORBA_RUNTIME_RANDOM_RANDOM_H
#define ZORBA_RUNTIME_RANDOM_RANDOM_H


#include "common/shared_types.h"


#include "runtime/base/noarybase.h"
#include "runtime/base/narybase.h"


namespace zorba {

/**
 * Helper Iterator to produce a defined amount of integer items for testing purposes
 * 
 * Author: Zorba Team * 
 */
class NumGenIteratorState : public PlanIteratorState
{
public:
  int32_t theCurNumber; //the current number

  NumGenIteratorState();

  ~NumGenIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class NumGenIterator : public NoaryBaseIterator <NumGenIterator, NumGenIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NumGenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NumGenIterator,
    NoaryBaseIterator <NumGenIterator, NumGenIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NoaryBaseIterator <NumGenIterator, NumGenIteratorState>*)this);
  }

  NumGenIterator(
    static_context* sctx,
    const QueryLoc& loc
    )
    : NoaryBaseIterator <NumGenIterator, NumGenIteratorState>
    (sctx, loc) {}

  virtual ~NumGenIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Function for generating a random integer.
 * 
 * Author: Zorba Team * 
 */
class RandomIterator : public NaryBaseIterator <RandomIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RandomIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RandomIterator,
    NaryBaseIterator <RandomIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <RandomIterator, PlanIteratorState>*)this);
  }

  RandomIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <RandomIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~RandomIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * generates UUID
 * 
 * Author: Zorba Team * 
 */
class UuidIterator : public NaryBaseIterator <UuidIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(UuidIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(UuidIterator,
    NaryBaseIterator <UuidIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <UuidIterator, PlanIteratorState>*)this);
  }

  UuidIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator <UuidIterator, PlanIteratorState>
    (sctx, loc, aChildren) {}

  virtual ~UuidIterator();

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
