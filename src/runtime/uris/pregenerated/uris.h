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
#ifndef ZORBA_RUNTIME_URIS_URIS_H
#define ZORBA_RUNTIME_URIS_URIS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "zorbautils/checked_vector.h"
#include "zorbatypes/schema_types.h"


namespace zorba {

/**
 * 
 *    uri:decode
 *  
 * Author: Zorba Team
 */
class DecodeURIIterator : public NaryBaseIterator<DecodeURIIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DecodeURIIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DecodeURIIterator,
    NaryBaseIterator<DecodeURIIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DecodeURIIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DecodeURIIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DecodeURIIterator();

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
