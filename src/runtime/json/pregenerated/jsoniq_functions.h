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
#ifndef ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_H
#define ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/noarybase.h"
#include "runtime/base/narybase.h"
#include <context/uri_resolver.h>
#include "runtime/json/json_loader.h"
#include "zorbautils/hashset.h"
#include "zorbautils/hashmap_zstring.h"


namespace zorba {

/**
 * 
 * Author: 
 */
class JSONDecodeFromRoundtripIteratorState : public PlanIteratorState
{
public:
  zstring thePrefix; //

  JSONDecodeFromRoundtripIteratorState();

  ~JSONDecodeFromRoundtripIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONDecodeFromRoundtripIterator : public NaryBaseIterator<JSONDecodeFromRoundtripIterator, JSONDecodeFromRoundtripIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONDecodeFromRoundtripIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONDecodeFromRoundtripIterator,
    NaryBaseIterator<JSONDecodeFromRoundtripIterator, JSONDecodeFromRoundtripIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONDecodeFromRoundtripIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONDecodeFromRoundtripIterator, JSONDecodeFromRoundtripIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONDecodeFromRoundtripIterator();

  zstring getNameAsString() const;

public:
  static void extractChildOfKind(const store::Item_t& aParent, const store::NodeKind& aKind, store::Item_t& aChild);
  bool decodeNode(const store::Item_t& aSerializedNode, const store::NodeKind& aKind, store::Item_t& aResult) const;
  bool decodeXDM(const store::Item_t& anObj, store::Item_t& aResult, JSONDecodeFromRoundtripIteratorState* aState) const;
  bool decodeObject(const store::Item_t& anObj, store::Item_t& aResult, JSONDecodeFromRoundtripIteratorState* aState) const;
  bool decodeArray(const store::Item_t& anArray, store::Item_t& aResult, JSONDecodeFromRoundtripIteratorState* aState) const;
  bool decodeItem(const store::Item_t& anItem, store::Item_t& aResult, JSONDecodeFromRoundtripIteratorState* aState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class JSONEncodeForRoundtripIteratorState : public PlanIteratorState
{
public:
  zstring thePrefix; //
  store::Item_t theSerParams; //
  XQueryDiagnostics* theDiag; //

  JSONEncodeForRoundtripIteratorState();

  ~JSONEncodeForRoundtripIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONEncodeForRoundtripIterator : public NaryBaseIterator<JSONEncodeForRoundtripIterator, JSONEncodeForRoundtripIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONEncodeForRoundtripIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONEncodeForRoundtripIterator,
    NaryBaseIterator<JSONEncodeForRoundtripIterator, JSONEncodeForRoundtripIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONEncodeForRoundtripIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONEncodeForRoundtripIterator, JSONEncodeForRoundtripIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONEncodeForRoundtripIterator();

  zstring getNameAsString() const;

public:
  bool encodeObject(const store::Item_t& anObj, store::Item_t& aResult, JSONEncodeForRoundtripIteratorState* aState) const;
  bool encodeArray(const store::Item_t& anArray, store::Item_t& aResult, JSONEncodeForRoundtripIteratorState* aState) const;
  bool encodeAtomic(const store::Item_t& aValue, store::Item_t& aResult, JSONEncodeForRoundtripIteratorState* aState) const;
  bool encodeNode(const store::Item_t& aNode, store::Item_t& aResult, JSONEncodeForRoundtripIteratorState* aState) const;
  bool encodeItem(const store::Item_t& anItem, store::Item_t& aResult, JSONEncodeForRoundtripIteratorState* aState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class JSONParseIteratorState : public PlanIteratorState
{
public:
  bool theAllowMultiple; //
  store::Item_t theInput; //
  std::istream* theInputStream; //
  bool theGotOne; //
  json::loader* loader_; //

  JSONParseIteratorState();

  ~JSONParseIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONParseIterator : public NaryBaseIterator<JSONParseIterator, JSONParseIteratorState>
{ 
protected:
  QueryLoc theRelativeLocation; //
public:
  SERIALIZABLE_CLASS(JSONParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONParseIterator,
    NaryBaseIterator<JSONParseIterator, JSONParseIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONParseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    QueryLoc aRelativeLocation)
    : 
    NaryBaseIterator<JSONParseIterator, JSONParseIteratorState>(sctx, loc, children),
    theRelativeLocation(aRelativeLocation)
  {}

  virtual ~JSONParseIterator();

  zstring getNameAsString() const;

public:
  bool processBooleanOption(const store::Item_t& options, char const* option_name, bool* option_value) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class MultiObjectKeysIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theObjKeysIte; //
  store::Item_t theSecondObj; //
  std::unique_ptr<HashSet<zstring, HashMapZStringCmp> > theUniqueKeys; //

  MultiObjectKeysIteratorState();

  ~MultiObjectKeysIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MultiObjectKeysIterator : public UnaryBaseIterator<MultiObjectKeysIterator, MultiObjectKeysIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MultiObjectKeysIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MultiObjectKeysIterator,
    UnaryBaseIterator<MultiObjectKeysIterator, MultiObjectKeysIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  MultiObjectKeysIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<MultiObjectKeysIterator, MultiObjectKeysIteratorState>(sctx, loc, child)
  {}

  virtual ~MultiObjectKeysIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SingleObjectKeysIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theObjKeysIte; //

  SingleObjectKeysIteratorState();

  ~SingleObjectKeysIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SingleObjectKeysIterator : public UnaryBaseIterator<SingleObjectKeysIterator, SingleObjectKeysIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SingleObjectKeysIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingleObjectKeysIterator,
    UnaryBaseIterator<SingleObjectKeysIterator, SingleObjectKeysIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SingleObjectKeysIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<SingleObjectKeysIterator, SingleObjectKeysIteratorState>(sctx, loc, child)
  {}

  virtual ~SingleObjectKeysIterator();

  zstring getNameAsString() const;

public:
  bool count(store::Item_t& result, PlanState& planState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class MultiObjectLookupIteratorState : public PlanIteratorState
{
public:
  store::Item_t theKey; //

  MultiObjectLookupIteratorState();

  ~MultiObjectLookupIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MultiObjectLookupIterator : public BinaryBaseIterator<MultiObjectLookupIterator, MultiObjectLookupIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MultiObjectLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MultiObjectLookupIterator,
    BinaryBaseIterator<MultiObjectLookupIterator, MultiObjectLookupIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  MultiObjectLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<MultiObjectLookupIterator, MultiObjectLookupIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~MultiObjectLookupIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SingleObjectLookupIterator : public BinaryBaseIterator<SingleObjectLookupIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SingleObjectLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingleObjectLookupIterator,
    BinaryBaseIterator<SingleObjectLookupIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SingleObjectLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<SingleObjectLookupIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~SingleObjectLookupIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class JSONObjectProjectIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> theFilterKeys; //

  JSONObjectProjectIteratorState();

  ~JSONObjectProjectIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONObjectProjectIterator : public BinaryBaseIterator<JSONObjectProjectIterator, JSONObjectProjectIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectProjectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectProjectIterator,
    BinaryBaseIterator<JSONObjectProjectIterator, JSONObjectProjectIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONObjectProjectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONObjectProjectIterator, JSONObjectProjectIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONObjectProjectIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class JSONObjectTrimIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> theFilterKeys; //

  JSONObjectTrimIteratorState();

  ~JSONObjectTrimIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class JSONObjectTrimIterator : public BinaryBaseIterator<JSONObjectTrimIterator, JSONObjectTrimIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectTrimIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectTrimIterator,
    BinaryBaseIterator<JSONObjectTrimIterator, JSONObjectTrimIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONObjectTrimIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONObjectTrimIterator, JSONObjectTrimIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONObjectTrimIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class MultiArrayMembersIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theMembers; //

  MultiArrayMembersIteratorState();

  ~MultiArrayMembersIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MultiArrayMembersIterator : public UnaryBaseIterator<MultiArrayMembersIterator, MultiArrayMembersIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MultiArrayMembersIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MultiArrayMembersIterator,
    UnaryBaseIterator<MultiArrayMembersIterator, MultiArrayMembersIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  MultiArrayMembersIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<MultiArrayMembersIterator, MultiArrayMembersIteratorState>(sctx, loc, child)
  {}

  virtual ~MultiArrayMembersIterator();

  zstring getNameAsString() const;

public:
  bool count(store::Item_t& result, PlanState& planState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SingleArrayMembersIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theMembers; //

  SingleArrayMembersIteratorState();

  ~SingleArrayMembersIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class SingleArrayMembersIterator : public UnaryBaseIterator<SingleArrayMembersIterator, SingleArrayMembersIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SingleArrayMembersIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingleArrayMembersIterator,
    UnaryBaseIterator<SingleArrayMembersIterator, SingleArrayMembersIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SingleArrayMembersIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<SingleArrayMembersIterator, SingleArrayMembersIteratorState>(sctx, loc, child)
  {}

  virtual ~SingleArrayMembersIterator();

  zstring getNameAsString() const;

public:
  bool count(store::Item_t& result, PlanState& planState) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class MultiArrayLookupIteratorState : public PlanIteratorState
{
public:
  store::Item_t thePosition; //

  MultiArrayLookupIteratorState();

  ~MultiArrayLookupIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MultiArrayLookupIterator : public BinaryBaseIterator<MultiArrayLookupIterator, MultiArrayLookupIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MultiArrayLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MultiArrayLookupIterator,
    BinaryBaseIterator<MultiArrayLookupIterator, MultiArrayLookupIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  MultiArrayLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<MultiArrayLookupIterator, MultiArrayLookupIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~MultiArrayLookupIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: 
 */
class SingleArrayLookupIterator : public BinaryBaseIterator<SingleArrayLookupIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(SingleArrayLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SingleArrayLookupIterator,
    BinaryBaseIterator<SingleArrayLookupIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  SingleArrayLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<SingleArrayLookupIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~SingleArrayLookupIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONArraySizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONArraySizeIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONArrayFlattenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONArrayFlattenIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONNullIterator(
    static_context* sctx,
    const QueryLoc& loc)
    : 
    NoaryBaseIterator<JSONNullIterator, PlanIteratorState>(sctx, loc)
  {}

  virtual ~JSONNullIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      internal function
 *  
 * Author: Zorba Team
 */
class JSONObjectInsertIterator : public NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONObjectInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectInsertIterator,
    NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONObjectInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONObjectInsertIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONArrayInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONArrayInsertIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    json:delete-member
 *  
 * Author: Zorba Team
 */
class JSONDeleteIterator : public BinaryBaseIterator<JSONDeleteIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONDeleteIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONDeleteIterator,
    BinaryBaseIterator<JSONDeleteIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONDeleteIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<JSONDeleteIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~JSONDeleteIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    internal function
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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONReplaceValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool copyInput)
    ;

  virtual ~JSONReplaceValueIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


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

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONRenameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONRenameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONRenameIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      internal function 
 *    
 * Author: Zorba Team
 */
class JSONArrayAppendIterator : public NaryBaseIterator<JSONArrayAppendIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONArrayAppendIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONArrayAppendIterator,
    NaryBaseIterator<JSONArrayAppendIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONArrayAppendIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONArrayAppendIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONArrayAppendIterator();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      
 *    
 * Author: Zorba Team
 */
class JSONBoxIterator : public UnaryBaseIterator<JSONBoxIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONBoxIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONBoxIterator,
    UnaryBaseIterator<JSONBoxIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONBoxIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<JSONBoxIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~JSONBoxIterator();

  zstring getNameAsString() const;

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
