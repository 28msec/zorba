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
#pragma once
#ifndef ZORBA_RUNTIME_MATERIALIZE_ITERATOR
#define ZORBA_RUNTIME_MATERIALIZE_ITERATOR


#include "runtime/base/unarybase.h"

namespace zorba
{


/*******************************************************************************

********************************************************************************/
class MaterializeIteratorState : public  PlanIteratorState
{
public:
  store::Iterator_t theChildWrapper;

  store::TempSeq_t  theTempSeq;

  store::Iterator_t theTempSeqIter;

public:
  MaterializeIteratorState();
  
  ~MaterializeIteratorState();

  void init(PlanState& planState);
};


/*******************************************************************************

********************************************************************************/
class MaterializeIterator : public UnaryBaseIterator<MaterializeIterator,
                                                     MaterializeIteratorState>
{
public:
  SERIALIZABLE_CLASS(MaterializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  MaterializeIterator,
  UnaryBaseIterator<MaterializeIterator, MaterializeIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  MaterializeIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& arg) 
    :
    UnaryBaseIterator<MaterializeIterator, MaterializeIteratorState>(sctx, loc, arg)
  {
  }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
