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
#ifndef ZORBA_RUNTIME_QNAMES_QNAMES_H
#define ZORBA_RUNTIME_QNAMES_QNAMES_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"

#include "runtime/base/narybase.h"
#include <vector>


namespace zorba {

/**
 * fn:resolve-QName
 * Author: Zorba Team
 */
class ResolveQNameIterator : public BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ResolveQNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ResolveQNameIterator,
    BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>*)this);
  }

  ResolveQNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~ResolveQNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:QName
 * Author: Zorba Team
 */
class QNameIterator : public BinaryBaseIterator<QNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(QNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(QNameIterator,
    BinaryBaseIterator<QNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<QNameIterator, PlanIteratorState>*)this);
  }

  QNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<QNameIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~QNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op:QName-equal
 * Author: Zorba Team
 */
class QNameEqualIterator : public BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(QNameEqualIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(QNameEqualIterator,
    BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>*)this);
  }

  QNameEqualIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child1, PlanIter_t& child2)
    : 
    BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>(sctx, loc, child1, child2)
  {}

  virtual ~QNameEqualIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:prefix-from-QName
 * Author: Zorba Team
 */
class PrefixFromQNameIterator : public UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(PrefixFromQNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrefixFromQNameIterator,
    UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>*)this);
  }

  PrefixFromQNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~PrefixFromQNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:local-name-from-QName
 * Author: Zorba Team
 */
class LocalNameFromQNameIterator : public UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LocalNameFromQNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LocalNameFromQNameIterator,
    UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>*)this);
  }

  LocalNameFromQNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~LocalNameFromQNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:namespace-uri-from-QName
 * Author: Zorba Team
 */
class NamespaceUriFromQNameIterator : public UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NamespaceUriFromQNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NamespaceUriFromQNameIterator,
    UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>*)this);
  }

  NamespaceUriFromQNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~NamespaceUriFromQNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:namespace-uri-for-prefix
 * Author: Zorba Team
 */
class NamespaceUriForPrefixIterator : public NaryBaseIterator<NamespaceUriForPrefixIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NamespaceUriForPrefixIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NamespaceUriForPrefixIterator,
    NaryBaseIterator<NamespaceUriForPrefixIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NamespaceUriForPrefixIterator, PlanIteratorState>*)this);
  }

  NamespaceUriForPrefixIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NamespaceUriForPrefixIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NamespaceUriForPrefixIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:in-scope-prefixes
 * Author: Zorba Team
 */
class InScopePrefixesIteratorState : public PlanIteratorState
{
public:
  store::NsBindings theBindings; //
  unsigned long theCurrentPos; //

  InScopePrefixesIteratorState();

  ~InScopePrefixesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class InScopePrefixesIterator : public UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InScopePrefixesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopePrefixesIterator,
    UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesIteratorState>*)this);
  }

  InScopePrefixesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesIteratorState>(sctx, loc, child)
  {}

  virtual ~InScopePrefixesIterator();

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
