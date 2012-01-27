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

  JSONFlattenIteratorState();

  ~JSONFlattenIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONFlattenIterator : public NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>
{ 
protected:
  bool thePropagateNonArrayItems; //
public:
  SERIALIZABLE_CLASS(JSONFlattenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONFlattenIterator,
    NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>*)this);

    ar & thePropagateNonArrayItems;
  }

  JSONFlattenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool propagateNonArrayItems)
    : 
    NaryBaseIterator<JSONFlattenIterator, JSONFlattenIteratorState>(sctx, loc, children),
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
class JSONPairAccessorIterator : public NaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONPairAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONPairAccessorIterator,
    NaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>*)this);
  }

  JSONPairAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONPairAccessorIterator, PlanIteratorState>(sctx, loc, children)
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
class JSONMemberAccessorIterator : public NaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONMemberAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONMemberAccessorIterator,
    NaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>*)this);
  }

  JSONMemberAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONMemberAccessorIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONMemberAccessorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONPairOrMemberAccessorIterator : public NaryBaseIterator<JSONPairOrMemberAccessorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONPairOrMemberAccessorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONPairOrMemberAccessorIterator,
    NaryBaseIterator<JSONPairOrMemberAccessorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONPairOrMemberAccessorIterator, PlanIteratorState>*)this);
  }

  JSONPairOrMemberAccessorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONPairOrMemberAccessorIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONPairOrMemberAccessorIterator();

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


/**
 * 
 *      json:delete
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


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
