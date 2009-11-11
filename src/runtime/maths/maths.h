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
#ifndef ZORBA_RUNTIME_MATHS_MATHS_H
#define ZORBA_RUNTIME_MATHS_MATHS_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"




namespace zorba {

/**
 * math:sqrt
 * 
 * Author: Zorba Team * 
 */
class FnSQRTIterator : public UnaryBaseIterator <FnSQRTIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnSQRTIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSQRTIterator,
    UnaryBaseIterator <FnSQRTIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator <FnSQRTIterator, PlanIteratorState>*)this);
  }

  FnSQRTIterator(
    static_context* sctx,
    const QueryLoc& loc
    , PlanIter_t& aChild)
    : UnaryBaseIterator <FnSQRTIterator, PlanIteratorState>
    (sctx, loc, aChild) {}

  virtual ~FnSQRTIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * math:atan2
 * 
 * Author: Zorba Team * 
 */
class FnAtan2Iterator : public BinaryBaseIterator <FnAtan2Iterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnAtan2Iterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnAtan2Iterator,
    BinaryBaseIterator <FnAtan2Iterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator <FnAtan2Iterator, PlanIteratorState>*)this);
  }

  FnAtan2Iterator(
    static_context* sctx,
    const QueryLoc& loc
    , PlanIter_t& aChild1, PlanIter_t& aChild2)
    : BinaryBaseIterator <FnAtan2Iterator, PlanIteratorState>
    (sctx, loc, aChild1, aChild2) {}

  virtual ~FnAtan2Iterator();

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
