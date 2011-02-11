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
#ifndef ZORBA_RUNTIME_DEBUG_ZORBA_DEBUG_ITERATOR_H
#define ZORBA_RUNTIME_DEBUG_ZORBA_DEBUG_ITERATOR_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include <vector>
#include <map>
#include <string>
#include "runtime/util/plan_wrapper_holder.h"
#include "zorba/options.h"
#include "store/api/item.h"
#include "types/typeimpl.h"


namespace zorba {

/**
 * 
 *      This iterator wrapps iterators in which represents breakable expression
 *      if the query is compiled in debug mode. It is used to break expressions,
 *      interrupt the execution and evaluate expressions while the engine is
 *      suspended.
 *    
 * Author: Zorba Team
 */
class ZorbaDebugIteratorState : public PlanIteratorState
{
public:
  bool notEmptySequence; //

  ZorbaDebugIteratorState();

  ~ZorbaDebugIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaDebugIterator : public NaryBaseIterator<ZorbaDebugIterator, ZorbaDebugIteratorState>
{ 
protected:
  checked_vector<store::Item_t> varnames; //
  checked_vector<xqtref_t> vartypes; //
  std::vector<ZorbaDebugIterator*> theDebuggerChildren; //
  ZorbaDebugIterator* theDebuggerParent; //
public:
  SERIALIZABLE_CLASS(ZorbaDebugIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaDebugIterator,
    NaryBaseIterator<ZorbaDebugIterator, ZorbaDebugIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaDebugIterator, ZorbaDebugIteratorState>*)this);

    ar & varnames;
    ar & vartypes;
    ar & theDebuggerChildren;
    ar & theDebuggerParent;
  }

  ZorbaDebugIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaDebugIterator, ZorbaDebugIteratorState>(sctx, loc, children),
    varnames(),
    vartypes(),
    theDebuggerChildren(),
    theDebuggerParent()
  {}

  virtual ~ZorbaDebugIterator();

public:
  const ZorbaDebugIterator* getParent() const;
  const ZorbaDebugIterator* getOverIterator() const;
  QueryLoc getQueryLocation() const;
  std::list<std::pair<zstring, zstring> > eval(PlanState* aState, Zorba_SerializerOptions* aSerOptions) const;
  void checkBreak(PlanState* aState) const;
  void setParent(ZorbaDebugIterator* aParent);
  void addChild(ZorbaDebugIterator* aChild);
  void setChildren(std::vector<PlanIter_t>* args);
  void setVariables(checked_vector<store::Item_t> aVarNames, checked_vector<xqtref_t> aVarTypes);
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
