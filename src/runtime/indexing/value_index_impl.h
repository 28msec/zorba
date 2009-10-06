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
#ifndef ZORBA_RUNTIME_VALUE_INDEX
#define ZORBA_RUNTIME_VALUE_INDEX

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


namespace zorba 
{


/***************************************************************************//**
  Implements the create-internal-index function.
********************************************************************************/
class CreateInternalIndexIterator : public UnaryBaseIterator<CreateInternalIndexIterator,
                                                             PlanIteratorState>
{
protected:
  store::Item_t theQName;

public:
  SERIALIZABLE_CLASS(CreateInternalIndexIterator)

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CreateInternalIndexIterator,
  UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState >)

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState >*)this);

    ar & theQName;
  }

public:
  CreateInternalIndexIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& arg,
        store::Item* qname)
    :
    UnaryBaseIterator<CreateInternalIndexIterator, PlanIteratorState>(sctx, loc, arg),
    theQName(qname)
  {
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/***************************************************************************//**
  Implements the create-index function.
********************************************************************************/
UNARY_ITER(CreateIndexIterator);


/***************************************************************************//**
  Implements the create-index function.
********************************************************************************/
UNARY_ITER(RefreshIndexIterator);


/***************************************************************************//**
  Implements the drop-index function.
********************************************************************************/
UNARY_ITER(DropIndexIterator);


/***************************************************************************//**
  Implements the index-entry-builder function.
********************************************************************************/
class IndexEntryBuilderIteratorState : public  PlanIteratorState 
{
public:
  uint32_t theCurChild;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(IndexEntryBuilderIterator, IndexEntryBuilderIteratorState);


/***************************************************************************//**

********************************************************************************/
class IndexPointProbeState : public PlanIteratorState 
{
public:
  const store::Item           * theQname;
  store::Index                * theIndex;
  store::IndexProbeIterator_t   theIterator;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(IndexPointProbeIterator, IndexPointProbeState);


/***************************************************************************//**

********************************************************************************/
class IndexRangeProbeState : public PlanIteratorState 
{
public:
  const store::Item           * theQname;
  store::Index                * theIndex;
  store::IndexProbeIterator_t   theIterator;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(IndexRangeProbeIterator, IndexRangeProbeState);


}

#endif 
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
