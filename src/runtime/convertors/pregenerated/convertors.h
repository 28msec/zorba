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
#ifndef ZORBA_RUNTIME_CONVERTORS_CONVERTORS_H
#define ZORBA_RUNTIME_CONVERTORS_CONVERTORS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "fstream"
#include "zorbautils/checked_vector.h"
#include "zorba/xquery.h"


namespace zorba {

/**
 * Parsing a sequence of valid JSON strings into a sequence of XDM elements.
 * Author: Zorba Team
 */
class ZorbaJsonParseIteratorState : public PlanIteratorState
{
public:
  zstring theBaseUri; //the base URI

  ZorbaJsonParseIteratorState();

  ~ZorbaJsonParseIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaJsonParseIterator : public NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonParseIterator,
    NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>*)this);
  }

  ZorbaJsonParseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonParseIterator, ZorbaJsonParseIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonParseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * The serialize function takes a sequence of elements as parameter and transforms each element into a valid JSON string.
 * Author: Zorba Team
 */
class ZorbaJsonSerializeIterator : public NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonSerializeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonSerializeIterator,
    NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>*)this);
  }

  ZorbaJsonSerializeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonSerializeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonSerializeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Parsing a sequence of valid JsonML strings into a sequence of XDM elements.
 * Author: Zorba Team
 */
class ZorbaJsonParseMLIteratorState : public PlanIteratorState
{
public:
  zstring theBaseUri; //the base URI

  ZorbaJsonParseMLIteratorState();

  ~ZorbaJsonParseMLIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class ZorbaJsonParseMLIterator : public NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonParseMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonParseMLIterator,
    NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>*)this);
  }

  ZorbaJsonParseMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonParseMLIterator, ZorbaJsonParseMLIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonParseMLIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * The serialize function takes a sequence of elements as parameter and transforms each element into a valid JsonML string.
 * Author: Zorba Team
 */
class ZorbaJsonSerializeMLIterator : public NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaJsonSerializeMLIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaJsonSerializeMLIterator,
    NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>*)this);
  }

  ZorbaJsonSerializeMLIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaJsonSerializeMLIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaJsonSerializeMLIterator();

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
