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
    //Whether the Collection is a W3C or Zorba Collection
    //and if it's dynamic or static collection module
    enum CollectionType {W3C = 0, ZORBASTATIC = 1, ZORBADYNAMIC = 2 };
    CollectionType theCollectionType;

  public:

  SERIALIZABLE_CLASS(CountCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CountCollectionIterator,
      UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
        (UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>*)this);

        /*This ugly casting is necesary, if we used a static_cast directly it
          would create a new temporary variable with the "casted" value within
          it. This of course cannot be passed by &, we can pass the value to
          another variable, then pass the variable and sincronize the values of
          both again after conversion. I feel this is slightly more efficient
          and just as unreadable.*/
        int *intCollectionType = reinterpret_cast<int*>(&theCollectionType);

        ar & *intCollectionType;
  }

  CountCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    bool aDynamicCollection)
    :
    UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>(
        sctx, loc, child)
  {
    if(aDynamicCollection) theCollectionType = ZORBADYNAMIC;
    else theCollectionType = ZORBASTATIC;
  }

  CountCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    :
    UnaryBaseIterator<CountCollectionIterator, PlanIteratorState>(
        sctx, loc, child),
    theCollectionType(W3C)
  {}

  bool isZorbaCollection() const {return W3C != theCollectionType;}
  bool isDynamicCollection() const {return ZORBADYNAMIC == theCollectionType;}

  virtual ~CountCollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

protected:
  store::Collection_t getZorbaCollection(PlanState& planState) const;
  store::Collection_t getW3CCollection(PlanState& planState) const;
};

} //namespace zorba
#endif /* ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_IMPL_H */
/* vim:set et sw=2 ts=2: */

