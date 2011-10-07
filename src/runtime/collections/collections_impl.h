/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_IMPL_H
#define ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_IMPL_H

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"
#include "runtime/collections/collections_base.h"

namespace zorba{

/**
 *
 *      fn:count(collection)
 *
 * Author: Zorba Team
 */
class CountCollectionIterator: public UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>
{
  protected:
    //Whether the Collection is of the dynamic or static collection module
    bool theDynamicCollection;

  public:

  SERIALIZABLE_CLASS(CountCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CountCollectionIterator,
      UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
        (UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>*)this);
  }
  CountCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    bool aDynamicCollection)
    :
    UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>(
        sctx, loc, child),
    theDynamicCollection(aDynamicCollection)
  {}

  virtual ~CountCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

} //namespace zorba
#endif /* ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_IMPL_H */
/* vim:set et sw=2 ts=2: */

