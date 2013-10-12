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
#ifndef ZORBA_RUNTIME_SEQ_SEQ_H
#define ZORBA_RUNTIME_SEQ_SEQ_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/seq/seq_util.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class SeqValueIntersectIteratorState : public PlanIteratorState
{
public:
  Item_set_type* set_[2]; //

  SeqValueIntersectIteratorState();

  ~SeqValueIntersectIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SeqValueIntersectIterator : public NaryBaseIterator<SeqValueIntersectIterator, SeqValueIntersectIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqValueIntersectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqValueIntersectIterator,
    NaryBaseIterator<SeqValueIntersectIterator, SeqValueIntersectIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqValueIntersectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqValueIntersectIterator, SeqValueIntersectIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqValueIntersectIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SeqValueUnionIteratorState : public PlanIteratorState
{
public:
  int child_; //
  Item_set_type* set_; //

  SeqValueUnionIteratorState();

  ~SeqValueUnionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SeqValueUnionIterator : public NaryBaseIterator<SeqValueUnionIterator, SeqValueUnionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqValueUnionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqValueUnionIterator,
    NaryBaseIterator<SeqValueUnionIterator, SeqValueUnionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqValueUnionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqValueUnionIterator, SeqValueUnionIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqValueUnionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SeqValueExceptIteratorState : public PlanIteratorState
{
public:
  Item_set_type* set_; //

  SeqValueExceptIteratorState();

  ~SeqValueExceptIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SeqValueExceptIterator : public NaryBaseIterator<SeqValueExceptIterator, SeqValueExceptIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqValueExceptIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqValueExceptIterator,
    NaryBaseIterator<SeqValueExceptIterator, SeqValueExceptIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqValueExceptIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqValueExceptIterator, SeqValueExceptIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqValueExceptIterator();

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
