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
#ifndef ZORBA_RUNTIME_CONTEXT_CONTEXT_H
#define ZORBA_RUNTIME_CONTEXT_CONTEXT_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * fn:current-dateTime
 * Author: Zorba Team
 */
class CurrentDateTimeIterator : public NaryBaseIterator<CurrentDateTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentDateTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentDateTimeIterator,
    NaryBaseIterator<CurrentDateTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentDateTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentDateTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentDateTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:current-date
 * Author: Zorba Team
 */
class CurrentDateIterator : public NaryBaseIterator<CurrentDateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentDateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentDateIterator,
    NaryBaseIterator<CurrentDateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentDateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentDateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentDateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:current-time
 * Author: Zorba Team
 */
class CurrentTimeIterator : public NaryBaseIterator<CurrentTimeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(CurrentTimeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CurrentTimeIterator,
    NaryBaseIterator<CurrentTimeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  CurrentTimeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<CurrentTimeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~CurrentTimeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:implicit-timezone
 * Author: Zorba Team
 */
class ImplicitTimezoneIterator : public NaryBaseIterator<ImplicitTimezoneIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ImplicitTimezoneIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ImplicitTimezoneIterator,
    NaryBaseIterator<ImplicitTimezoneIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ImplicitTimezoneIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ImplicitTimezoneIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ImplicitTimezoneIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:default-collation
 * Author: Zorba Team
 */
class DefaultCollationIterator : public NaryBaseIterator<DefaultCollationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(DefaultCollationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DefaultCollationIterator,
    NaryBaseIterator<DefaultCollationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  DefaultCollationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<DefaultCollationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~DefaultCollationIterator();

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
