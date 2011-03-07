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



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * Function for generating a random integer.
 * Author: Zorba Team
 */
class RandomIterator : public NaryBaseIterator<RandomIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RandomIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RandomIterator,
    NaryBaseIterator<RandomIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<RandomIterator, PlanIteratorState>*)this);
  }

  RandomIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RandomIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RandomIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Function for generating a random integer.
 * Author: Zorba Team
 */
class PseudoRandomIterator : public NaryBaseIterator<PseudoRandomIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(PseudoRandomIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PseudoRandomIterator,
    NaryBaseIterator<PseudoRandomIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<PseudoRandomIterator, PlanIteratorState>*)this);
  }

  PseudoRandomIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<PseudoRandomIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~PseudoRandomIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * generates UUID
 * Author: Zorba Team
 */
class UuidIterator : public NaryBaseIterator<UuidIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(UuidIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(UuidIterator,
    NaryBaseIterator<UuidIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<UuidIterator, PlanIteratorState>*)this);
  }

  UuidIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<UuidIterator, PlanIteratorState>(sctx, loc, children)
  {}

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
