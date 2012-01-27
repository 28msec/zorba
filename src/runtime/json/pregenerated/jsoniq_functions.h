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
#ifndef ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_H
#define ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"

#include "runtime/base/narybase.h"


namespace zorba {

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONParseIterator : public NaryBaseIterator<JSONParseIterator, PlanIteratorState>
{ 
protected:
  QueryLoc theRelativeLocation; //
public:
  SERIALIZABLE_CLASS(JSONParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONParseIterator,
    NaryBaseIterator<JSONParseIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONParseIterator, PlanIteratorState>*)this);

    ar & theRelativeLocation;
  }

  JSONParseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    QueryLoc aRelativeLocation)
    : 
    NaryBaseIterator<JSONParseIterator, PlanIteratorState>(sctx, loc, children),
    theRelativeLocation(aRelativeLocation)
  {}

  virtual ~JSONParseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONNameIterator : public UnaryBaseIterator<JSONNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONNameIterator,
    UnaryBaseIterator<JSONNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONNameIterator, PlanIteratorState>*)this);
  }

  JSONNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONNameIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONValueIterator : public UnaryBaseIterator<JSONValueIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONValueIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONValueIterator,
    UnaryBaseIterator<JSONValueIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONValueIterator, PlanIteratorState>*)this);
  }

  JSONValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONValueIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONValueIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONNamesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePairs; //

  JSONNamesIteratorState();

  ~JSONNamesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONNamesIterator : public UnaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONNamesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONNamesIterator,
    UnaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>*)this);
  }

  JSONNamesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONNamesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONPairsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePairs; //

  JSONPairsIteratorState();

  ~JSONPairsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONPairsIterator : public UnaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONPairsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONPairsIterator,
    UnaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>*)this);
  }

  JSONPairsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONPairsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONPairAccessorIterator : public BinaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONPairAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONPairAccessorIterator,
    BinaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>*)this);
  }

  JSONPairAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONPairAccessorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONMemberAccessorIterator : public BinaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONMemberAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONMemberAccessorIterator,
    BinaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>*)this);
  }

  JSONMemberAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONMemberAccessorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *    jsoniq:flatten function
 *  
 * Author: Zorba Team
 */
class JSONFlattenIteratorState : public PlanIteratorState
{
public:
  std::stack<store::Iterator_t> theStack; //

  JSONFlattenIteratorState();

  ~JSONFlattenIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONFlattenIterator : public UnaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>
{ 
protected:
  bool thePropagateNonArrayItems; //
public:
  SERIALIZABLE_CLASS(JSONFlattenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONFlattenIterator,
    UnaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>*)this);

    ar & thePropagateNonArrayItems;
  }

  JSONFlattenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    bool propagateNonArrayItems)
    : 
    UnaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>(sctx, loc, child),
    thePropagateNonArrayItems(propagateNonArrayItems)
  {}

  virtual ~JSONFlattenIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONItemAccessorIterator : public BinaryBaseIterator<JSONItemAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONItemAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONItemAccessorIterator,
    BinaryBaseIterator<JSONItemAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONItemAccessorIterator, PlanIteratorState>*)this);
  }

  JSONItemAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONItemAccessorIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONItemAccessorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONValuesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theValues; //

  JSONValuesIteratorState();

  ~JSONValuesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONValuesIterator : public UnaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONValuesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONValuesIterator,
    UnaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>*)this);
  }

  JSONValuesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONValuesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONSizeIterator : public UnaryBaseIterator<JSONSizeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONSizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONSizeIterator,
    UnaryBaseIterator<JSONSizeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONSizeIterator, PlanIteratorState>*)this);
  }

  JSONSizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONSizeIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONSizeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
