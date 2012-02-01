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

/*******************************************************************************
  Iterator to optimize a fn:count(collection) expression

  theCollectionType:
  ------------------
  Whether the Collection is a W3C or Zorba Collection and if it's dynamic or 
  static collection module.
********************************************************************************/
class CountCollectionIterator : public NaryBaseIterator<CountCollectionIterator, 
                                                        PlanIteratorState>
{
public:
  enum CollectionType 
  { 
    W3C = 0,
    ZORBASTATIC = 1,
    ZORBADYNAMIC = 2 
  };

protected:
  CollectionType theCollectionType;
  bool           theIsJSONIQ;

public:
  SERIALIZABLE_CLASS(CountCollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CountCollectionIterator,
  NaryBaseIterator<CountCollectionIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  CountCollectionIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      CollectionType collectionType,
      bool isJSONIQ);

  ~CountCollectionIterator();

  bool isZorbaCollection() const { return W3C != theCollectionType; }

  bool isDynamic() const { return ZORBADYNAMIC == theCollectionType; }

  bool isJSONIQ() const { return theIsJSONIQ; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

protected:
  store::Collection_t getZorbaCollection(PlanState& planState) const;

  store::Collection_t getW3CCollection(PlanState& planState) const;
};

} //namespace zorba
#endif /* ZORBA_RUNTIME_COLLECTIONS_COLLECTIONS_IMPL_H */
/* vim:set et sw=2 ts=2: */

