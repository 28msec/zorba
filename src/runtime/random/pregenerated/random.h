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
 * 
 *    Function for generating pseudo random integers
 *  
 * Author: Zorba Team
 */
class SeededRandomIteratorState : public PlanIteratorState
{
public:
  xs_integer theSeqLength; //
  xs_integer theCurrCounter; //

  SeededRandomIteratorState();

  ~SeededRandomIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SeededRandomIterator : public NaryBaseIterator<SeededRandomIterator, SeededRandomIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeededRandomIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeededRandomIterator,
    NaryBaseIterator<SeededRandomIterator, SeededRandomIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<SeededRandomIterator, SeededRandomIteratorState>*)this);
  }

  SeededRandomIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeededRandomIterator, SeededRandomIteratorState>(sctx, loc, children)
  {}

  virtual ~SeededRandomIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    Function for generating random integers.
 *    The function uses srand and passes the current time in millis as seed
 *  
 * Author: Zorba Team
 */
class RandomIteratorState : public PlanIteratorState
{
public:
  xs_integer theSeqLength; //
  xs_integer theCurrCounter; //

  RandomIteratorState();

  ~RandomIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class RandomIterator : public NaryBaseIterator<RandomIterator, RandomIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RandomIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RandomIterator,
    NaryBaseIterator<RandomIterator, RandomIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<RandomIterator, RandomIteratorState>*)this);
  }

  RandomIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RandomIterator, RandomIteratorState>(sctx, loc, children)
  {}

  virtual ~RandomIterator();

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
