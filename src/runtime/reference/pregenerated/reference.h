/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_RUNTIME_REFERENCE_REFERENCE_H
#define ZORBA_RUNTIME_REFERENCE_REFERENCE_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 *        
 *      declare function ref:reference($item as item()) as xs:string
 *    
 * Author: Federico Cavalieri
 */
class ReferenceIterator : public NaryBaseIterator<ReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ReferenceIterator,
    NaryBaseIterator<ReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:has-reference($item as item()) as xs:boolean
 *    
 * Author: Till Westmann
 */
class HasReferenceIterator : public NaryBaseIterator<HasReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HasReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HasReferenceIterator,
    NaryBaseIterator<HasReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  HasReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HasReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HasReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:assign-reference($item as item()) as xs:boolean
 *    
 * Author: Till Westmann
 */
class AssignReferenceIterator : public NaryBaseIterator<AssignReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AssignReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AssignReferenceIterator,
    NaryBaseIterator<AssignReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  AssignReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AssignReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~AssignReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:dereference($reference as xs:string) as item()?
 *    
 * Author: Federico Cavalieri
 */
class DereferenceIterator : public NaryBaseIterator<DereferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DereferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DereferenceIterator,
    NaryBaseIterator<DereferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DereferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DereferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DereferenceIterator();

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
