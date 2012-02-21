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
#ifndef ZORBA_RUNTIME_DEBUG_DEBUG_ITERATOR_H
#define ZORBA_RUNTIME_DEBUG_DEBUG_ITERATOR_H


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

#ifdef ZORBA_WITH_DEBUGGER
/**
 * 
 *      This iterator wrapps iterators in which represents breakable expression
 *      if the query is compiled in debug mode. It is used to break expressions,
 *      interrupt the execution and evaluate expressions while the engine is
 *      suspended.
 *    
 * Author: Zorba Team
 */
class DebugIteratorState : public PlanIteratorState
{
public:
  bool notEmptySequence; //

  DebugIteratorState();

  ~DebugIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DebugIterator : public NaryBaseIterator<DebugIterator, DebugIteratorState>
{ 
protected:
  checked_vector<store::Item_t> varnames; //
  checked_vector<xqtref_t> vartypes; //
  std::vector<DebugIterator*> theDebuggerChildren; //
  DebugIterator* theDebuggerParent; //
  bool theIsVarDeclaration; //
public:
  SERIALIZABLE_CLASS(DebugIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DebugIterator,
    NaryBaseIterator<DebugIterator, DebugIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DebugIterator, DebugIteratorState>*)this);

    ar & varnames;
    ar & vartypes;
    ar & theDebuggerChildren;
    ar & theDebuggerParent;
    ar & theIsVarDeclaration;
  }

  DebugIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DebugIterator, DebugIteratorState>(sctx, loc, children),
    varnames(),
    vartypes(),
    theDebuggerChildren(),
    theDebuggerParent(),
    theIsVarDeclaration()
  {}

  virtual ~DebugIterator();

  bool isVarDeclaration() const { return theIsVarDeclaration; }

  void setVarDeclaration(bool aValue) { theIsVarDeclaration= aValue; }

public:
  const DebugIterator* getDebuggerParent() const;
  std::vector<DebugIterator*> getDebuggerChildren() const;
  const DebugIterator* getOverIterator() const;
  QueryLoc getQueryLocation() const;
  std::list<std::pair<zstring, zstring> > eval(PlanState* aState, Zorba_SerializerOptions* aSerOptions) const;
  void checkBreak(PlanState* aState) const;
  void setParent(DebugIterator* aParent);
  void addChild(DebugIterator* aChild);
  void setChildren(std::vector<PlanIter_t>* args);
  void setVariables(checked_vector<store::Item_t> aVarNames, checked_vector<xqtref_t> aVarTypes);
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
