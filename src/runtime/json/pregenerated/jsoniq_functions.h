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



#include "runtime/base/narybase.h"


namespace zorba {

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
  store::Item_t theOrigArray; //

  JSONFlattenIteratorState();

  ~JSONFlattenIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONFlattenIterator : public NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONFlattenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONFlattenIterator,
    NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>*)this);
  }

  JSONFlattenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>(sctx, loc, children)
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
class JSONNamesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePairs; //

  JSONNamesIteratorState();

  ~JSONNamesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONNamesIterator : public NaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONNamesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONNamesIterator,
    NaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>*)this);
  }

  JSONNamesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONNamesIterator, JSONNamesIteratorState>(sctx, loc, children)
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
class JSONNameIterator : public NaryBaseIterator<JSONNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONNameIterator,
    NaryBaseIterator<JSONNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONNameIterator, PlanIteratorState>*)this);
  }

  JSONNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONNameIterator, PlanIteratorState>(sctx, loc, children)
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
class JSONPairsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePairs; //

  JSONPairsIteratorState();

  ~JSONPairsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONPairsIterator : public NaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONPairsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONPairsIterator,
    NaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>*)this);
  }

  JSONPairsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONPairsIterator, JSONPairsIteratorState>(sctx, loc, children)
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
class JSONSizeIterator : public NaryBaseIterator<JSONSizeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONSizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONSizeIterator,
    NaryBaseIterator<JSONSizeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONSizeIterator, PlanIteratorState>*)this);
  }

  JSONSizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONSizeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONSizeIterator();

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

class JSONValuesIterator : public NaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONValuesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONValuesIterator,
    NaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>*)this);
  }

  JSONValuesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONValuesIterator, JSONValuesIteratorState>(sctx, loc, children)
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
class JSONValueIterator : public NaryBaseIterator<JSONValueIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONValueIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONValueIterator,
    NaryBaseIterator<JSONValueIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONValueIterator, PlanIteratorState>*)this);
  }

  JSONValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONValueIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONValueIterator();

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
