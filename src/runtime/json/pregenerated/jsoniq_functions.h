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
class JSONObjectNamesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePairs; //

  JSONObjectNamesIteratorState();

  ~JSONObjectNamesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONObjectNamesIterator : public UnaryBaseIterator<JSONObjectNamesIterator, JSONObjectNamesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectNamesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectNamesIterator,
    UnaryBaseIterator<JSONObjectNamesIterator, JSONObjectNamesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONObjectNamesIterator, JSONObjectNamesIteratorState>*)this);
  }

  JSONObjectNamesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONObjectNamesIterator, JSONObjectNamesIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONObjectNamesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONObjectValueIterator : public BinaryBaseIterator<JSONObjectValueIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectValueIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectValueIterator,
    BinaryBaseIterator<JSONObjectValueIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONObjectValueIterator, PlanIteratorState>*)this);
  }

  JSONObjectValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONObjectValueIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONObjectValueIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONObjectProjectIterator : public BinaryBaseIterator<JSONObjectProjectIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectProjectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectProjectIterator,
    BinaryBaseIterator<JSONObjectProjectIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONObjectProjectIterator, PlanIteratorState>*)this);
  }

  JSONObjectProjectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONObjectProjectIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONObjectProjectIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONArraySizeIterator : public UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArraySizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArraySizeIterator,
    UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>*)this);
  }

  JSONArraySizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONArraySizeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONArrayMemberIterator : public BinaryBaseIterator<JSONArrayMemberIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArrayMemberIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArrayMemberIterator,
    BinaryBaseIterator<JSONArrayMemberIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<JSONArrayMemberIterator, PlanIteratorState>*)this);
  }

  JSONArrayMemberIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONArrayMemberIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONArrayMemberIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 * Author: 
 */
class JSONArrayMembersIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theMembers; //

  JSONArrayMembersIteratorState();

  ~JSONArrayMembersIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONArrayMembersIterator : public UnaryBaseIterator<JSONArrayMembersIterator, JSONArrayMembersIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArrayMembersIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArrayMembersIterator,
    UnaryBaseIterator<JSONArrayMembersIterator, JSONArrayMembersIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONArrayMembersIterator, JSONArrayMembersIteratorState>*)this);
  }

  JSONArrayMembersIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONArrayMembersIterator, JSONArrayMembersIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONArrayMembersIterator();

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
class JSONArrayFlattenIteratorState : public PlanIteratorState
{
public:
  std::stack<store::Iterator_t> theStack; //

  JSONArrayFlattenIteratorState();

  ~JSONArrayFlattenIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONArrayFlattenIterator : public UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArrayFlattenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArrayFlattenIterator,
    UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>*)this);
  }

  JSONArrayFlattenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONArrayFlattenIterator();

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
 *      internal function 
 *    
 * Author: Zorba Team
 */
class JSONArrayInsertIterator : public NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArrayInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArrayInsertIterator,
    NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>*)this);
  }

  JSONArrayInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONArrayInsertIterator();

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
 *      internal function
 *    
 * Author: Zorba Team
 */
class JSONReplaceValueIterator : public NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>
{ 
protected:
  bool theCopyInput; //
public:
  SERIALIZABLE_CLASS(JSONReplaceValueIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONReplaceValueIterator,
    NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>*)this);

    ar & theCopyInput;
  }

  JSONReplaceValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool copyInput)
    ;

  virtual ~JSONReplaceValueIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

#ifdef ZORBA_WITH_JSON
/**
 * 
 *      
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

}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
