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
#include "util/unordered_set.h"
#include "zorbautils/specializations.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class SeqSetIntersectIteratorState : public PlanIteratorState
{
public:
  std::unordered_set<store::Item*,ztd::hash<store::Item*>,ztd::equal_to<store::Item*> > set_[2]; //

  SeqSetIntersectIteratorState();

  ~SeqSetIntersectIteratorState();

  void reset(PlanState&);
};

class SeqSetIntersectIterator : public NaryBaseIterator<SeqSetIntersectIterator, SeqSetIntersectIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqSetIntersectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqSetIntersectIterator,
    NaryBaseIterator<SeqSetIntersectIterator, SeqSetIntersectIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqSetIntersectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqSetIntersectIterator, SeqSetIntersectIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqSetIntersectIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SeqSetUnionIteratorState : public PlanIteratorState
{
public:
  int child_; //
  std::unordered_set<store::Item*,ztd::hash<store::Item*>,ztd::equal_to<store::Item*> > set_; //

  SeqSetUnionIteratorState();

  ~SeqSetUnionIteratorState();

  void reset(PlanState&);
};

class SeqSetUnionIterator : public NaryBaseIterator<SeqSetUnionIterator, SeqSetUnionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqSetUnionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqSetUnionIterator,
    NaryBaseIterator<SeqSetUnionIterator, SeqSetUnionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqSetUnionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqSetUnionIterator, SeqSetUnionIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqSetUnionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SeqSetExceptIteratorState : public PlanIteratorState
{
public:
  std::unordered_set<store::Item*,ztd::hash<store::Item*>,ztd::equal_to<store::Item*> > set_; //

  SeqSetExceptIteratorState();

  ~SeqSetExceptIteratorState();

  void reset(PlanState&);
};

class SeqSetExceptIterator : public NaryBaseIterator<SeqSetExceptIterator, SeqSetExceptIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SeqSetExceptIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SeqSetExceptIterator,
    NaryBaseIterator<SeqSetExceptIterator, SeqSetExceptIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SeqSetExceptIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<SeqSetExceptIterator, SeqSetExceptIteratorState>(sctx, loc, children)
  {}

  virtual ~SeqSetExceptIterator();

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
