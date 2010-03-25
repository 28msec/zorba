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
#ifndef ZORBA_RUNTIME_FULL_TEXT_FULL_TEXT_H
#define ZORBA_RUNTIME_FULL_TEXT_FULL_TEXT_H


#include "common/shared_types.h"

#include "runtime/base/binarybase.h"


#include "zorbatypes/representations.h"
#include "compiler/expression/ftexpr.h"


namespace zorba {

/**
 * 
 *      contains text
 *    
 * Author: Paul J. Lucas
 */
class FTContainsIterator : public BinaryBaseIterator<FTContainsIterator, PlanIteratorState>
{ 
protected:
  ftexpr* ftselection_; //the ftexpr tree
public:
  SERIALIZABLE_CLASS(FTContainsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FTContainsIterator,
    BinaryBaseIterator<FTContainsIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<FTContainsIterator, PlanIteratorState>*)this);

    ar & ftselection_;
  }

  FTContainsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2,
    ftexpr* ftselection)
    : 
    BinaryBaseIterator<FTContainsIterator, PlanIteratorState>(sctx, loc, child1, child2),
    ftselection_(ftselection)
  {}

  virtual ~FTContainsIterator();

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
