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
#include "runtime/base/noarybase.h"
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
class JSONEmptyItemAccessorIteratorState : public PlanIteratorState
{
public:
  std::stack<store::Iterator_t> theStack; //

  JSONEmptyItemAccessorIteratorState();

  ~JSONEmptyItemAccessorIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONEmptyItemAccessorIterator : public UnaryBaseIterator<JSONEmptyItemAccessorIterator, JSONEmptyItemAccessorIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONEmptyItemAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONEmptyItemAccessorIterator,
    UnaryBaseIterator<JSONEmptyItemAccessorIterator, JSONEmptyItemAccessorIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONEmptyItemAccessorIterator, JSONEmptyItemAccessorIteratorState>*)this);
  }

  JSONEmptyItemAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONEmptyItemAccessorIterator, JSONEmptyItemAccessorIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONEmptyItemAccessorIterator();

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

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONNullIterator : public NoaryBaseIterator<JSONNullIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONNullIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONNullIterator,
    NoaryBaseIterator<JSONNullIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NoaryBaseIterator<JSONNullIterator, PlanIteratorState>*)this);
  }

  JSONNullIterator(
    static_context* sctx,
    const QueryLoc& loc)
    : 
    NoaryBaseIterator<JSONNullIterator, PlanIteratorState>(sctx, loc)
  {}

  virtual ~JSONNullIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:insert-into
 *    
 * Author: Zorba Team
 */
class JSONInsertIntoIterator : public NaryBaseIterator<JSONInsertIntoIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONInsertIntoIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONInsertIntoIterator,
    NaryBaseIterator<JSONInsertIntoIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONInsertIntoIterator, PlanIteratorState>*)this);
  }

  JSONInsertIntoIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONInsertIntoIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONInsertIntoIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:insert-as-first
 *    
 * Author: Zorba Team
 */
class JSONInsertAsFirstIterator : public NaryBaseIterator<JSONInsertAsFirstIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONInsertAsFirstIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONInsertAsFirstIterator,
    NaryBaseIterator<JSONInsertAsFirstIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONInsertAsFirstIterator, PlanIteratorState>*)this);
  }

  JSONInsertAsFirstIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONInsertAsFirstIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONInsertAsFirstIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:insert-after
 *    
 * Author: Zorba Team
 */
class JSONInsertAfterIterator : public NaryBaseIterator<JSONInsertAfterIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONInsertAfterIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONInsertAfterIterator,
    NaryBaseIterator<JSONInsertAfterIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONInsertAfterIterator, PlanIteratorState>*)this);
  }

  JSONInsertAfterIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONInsertAfterIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONInsertAfterIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:insert-before
 *    
 * Author: Zorba Team
 */
class JSONInsertBeforeIterator : public NaryBaseIterator<JSONInsertBeforeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONInsertBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONInsertBeforeIterator,
    NaryBaseIterator<JSONInsertBeforeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONInsertBeforeIterator, PlanIteratorState>*)this);
  }

  JSONInsertBeforeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONInsertBeforeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONInsertBeforeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:insert-as-last
 *    
 * Author: Zorba Team
 */
class JSONInsertAsLastIterator : public NaryBaseIterator<JSONInsertAsLastIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONInsertAsLastIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONInsertAsLastIterator,
    NaryBaseIterator<JSONInsertAsLastIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONInsertAsLastIterator, PlanIteratorState>*)this);
  }

  JSONInsertAsLastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONInsertAsLastIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONInsertAsLastIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:delete-member
 *    
 * Author: Zorba Team
 */
class JSONDeleteIterator : public NaryBaseIterator<JSONDeleteIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONDeleteIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONDeleteIterator,
    NaryBaseIterator<JSONDeleteIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONDeleteIterator, PlanIteratorState>*)this);
  }

  JSONDeleteIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONDeleteIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONDeleteIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:rename
 *    
 * Author: Zorba Team
 */
class JSONRenameIterator : public NaryBaseIterator<JSONRenameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONRenameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONRenameIterator,
    NaryBaseIterator<JSONRenameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONRenameIterator, PlanIteratorState>*)this);
  }

  JSONRenameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONRenameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONRenameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      json:replace-value
 *    
 * Author: Zorba Team
 */
class JSONReplaceValueIterator : public NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONReplaceValueIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONReplaceValueIterator,
    NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>*)this);
  }

  JSONReplaceValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONReplaceValueIterator();

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
