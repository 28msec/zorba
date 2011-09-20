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
#ifndef ZORBA_RUNTIME_INDEXING_IC_DDL_H
#define ZORBA_RUNTIME_INDEXING_IC_DDL_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"





namespace zorba {

/**
 * 
 *  activate($icName as xs:QName) as ()
 *
 *  Activates a staticaly declared integrity constraint for runtime
 *  check durring apply updates. After activation, the integrity
 *  constraint will become available in the dynamic context.
 *
 *  Error XXX is risen if $icName is not available in the static context.
 *    
 * Author: Zorba Team
 */
class ActivateICIterator : public UnaryBaseIterator<ActivateICIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ActivateICIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ActivateICIterator,
    UnaryBaseIterator<ActivateICIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<ActivateICIterator, PlanIteratorState>*)this);
  }

  ActivateICIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<ActivateICIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~ActivateICIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  deactivate($icName as xs:QName) as ()
 *
 *  Deactivates the runtime check of the $icName integrity constraint
 *  and it also removes it from dynamic context.
 *
 *  Error XXX is risen if $icName is not activated, i.e. available in 
 *  dynamic context.
 *    
 * Author: Zorba Team
 */
class DeactivateICIterator : public UnaryBaseIterator<DeactivateICIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DeactivateICIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DeactivateICIterator,
    UnaryBaseIterator<DeactivateICIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<DeactivateICIterator, PlanIteratorState>*)this);
  }

  DeactivateICIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<DeactivateICIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~DeactivateICIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *  check-integrity-constraint($icName as xs:QName) as ()
 *
 *  Calls the runtime check of the $icName integrity constraint.
 *
 *  Error XXX is risen if $icName is not activated, i.e. available in 
 *  dynamic context.
 *    
 * Author: Zorba Team
 */
class CheckICIterator : public UnaryBaseIterator<CheckICIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CheckICIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CheckICIterator,
    UnaryBaseIterator<CheckICIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<CheckICIterator, PlanIteratorState>*)this);
  }

  CheckICIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<CheckICIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~CheckICIterator();

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
