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
#ifndef ZORBA_RUNTIME_INDEXING_INDEX_FUNC_H
#define ZORBA_RUNTIME_INDEXING_INDEX_FUNC_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "store/api/index.h"


namespace zorba {

/**
 * 
 *      keys($iindexName as xs:QName) as ()
 *    
 * Author: Zorba Team
 */
class IndexKeysIteratorState : public PlanIteratorState
{
public:
  store::Index::KeyIterator_t theIter; //

  IndexKeysIteratorState();

  ~IndexKeysIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class IndexKeysIterator : public NaryBaseIterator<IndexKeysIterator, IndexKeysIteratorState>
{ 
protected:
  store::NsBindings theNSBindings; //
public:
  SERIALIZABLE_CLASS(IndexKeysIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IndexKeysIterator,
    NaryBaseIterator<IndexKeysIterator, IndexKeysIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IndexKeysIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IndexKeysIterator, IndexKeysIteratorState>(sctx, loc, children),
    theNSBindings()
  {}

  virtual ~IndexKeysIterator();

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
