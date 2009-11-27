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
#ifndef ZORBA_RUNTIME_INDEXING_INDEX_DDL_H
#define ZORBA_RUNTIME_INDEXING_INDEX_DDL_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"





namespace zorba {

/**
 * create-index($indexName as xs:QName) as pul() This is an updating function. During normal runtime (see CreateIndexIterator), it checks that index does not exist already (in the store) and generates an update primitive. During applyUpdates(), it creates the index container in the store and populates it according to the index definition. The specification for the index to create is taken from the static context, which stores a mapping from the index uri to ValueIndex obj (defined in indexing/value_index.h). The population of the index is done by a runtime plan that implements the following flwor expr: for $$dot at $$pos in domainExpr return index-entry-builder($$dot, fieldExpr1, ..., fieldExprN); This plan is generated "on-the-fly" by the CreateIndexIterator. The generated plan is stored in the update primitive, and during applyUpdates(), it is given as an arg to the SimpleStore::createIndex() method.
 * 
 * Author: Zorba Team * 
 */
class CreateIndexIterator : public UnaryBaseIterator <CreateIndexIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CreateIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CreateIndexIterator,
    UnaryBaseIterator <CreateIndexIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator <CreateIndexIterator, PlanIteratorState>*)this);
  }

  CreateIndexIterator(
    static_context* sctx,
    const QueryLoc& loc
    , PlanIter_t& aChild)
    : UnaryBaseIterator <CreateIndexIterator, PlanIteratorState>
    (sctx, loc, aChild) {}

  virtual ~CreateIndexIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * drop-index($indexName as xs:QName) as () This is an updating function. During normal runtime (see DropIndexIterator), it checks that index exists (in the dynamic context) and generates an update primitive. During applyUpdates(), it destroys the index container in the store and removes the index entry from the dynamic context.
 * 
 * Author: Zorba Team * 
 */
class DeleteIndexIterator : public UnaryBaseIterator <DeleteIndexIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeleteIndexIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeleteIndexIterator,
    UnaryBaseIterator <DeleteIndexIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator <DeleteIndexIterator, PlanIteratorState>*)this);
  }

  DeleteIndexIterator(
    static_context* sctx,
    const QueryLoc& loc
    , PlanIter_t& aChild)
    : UnaryBaseIterator <DeleteIndexIterator, PlanIteratorState>
    (sctx, loc, aChild) {}

  virtual ~DeleteIndexIterator();

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
