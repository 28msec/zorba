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
#ifndef ZORBA_QNAMES_IMPL_H
#define ZORBA_QNAMES_IMPL_H

#include <vector>
#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/unarybase.h" // remove after iterator refactoring
#include "runtime/base/binarybase.h" // remove after iterator refactoring
#include "runtime/base/narybase.h"

namespace zorba {
/*
 * 11.1.1 fn:resolve-QName
 * --------------------*/
 
/*begin class ResolveQNameIterator */
class ResolveQNameIterator : public BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>
{
  public:
    ResolveQNameIterator( short sctx, const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>(sctx, loc, arg0, arg1){}

    ~ResolveQNameIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(ResolveQNameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ResolveQNameIterator, BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>*)this);
  }
};
/*end class ResolveQNameIterator */

/*
 * 11.1.2 fn:QName
 * --------------------*/
 
/*begin class QNameIterator */
class QNameIterator : public BinaryBaseIterator<QNameIterator, PlanIteratorState>
{
  public:
    QNameIterator( short sctx, const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameIterator, PlanIteratorState>(sctx, loc, arg0, arg1){}

    ~QNameIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(QNameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(QNameIterator, BinaryBaseIterator<QNameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<QNameIterator, PlanIteratorState>*)this);
  }
};
/*end class QNameIterator */

/*
 * 11.2.1 op:QName-equal
 * --------------------*/
 
/*begin class QNameEqualIterator */
class QNameEqualIterator : public BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>
{
  public:
    QNameEqualIterator( short sctx, const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>(sctx, loc, arg0, arg1){}

    ~QNameEqualIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(QNameEqualIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(QNameEqualIterator, BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>*)this);
  }
};
/*end class QNameEqualIterator */

/*
 * 11.2.2 fn:prefix-from-QName
 * -------------------- */
/* begin class PrefixFromQNameIterator */
class PrefixFromQNameIterator : public UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>
{
  public:
    PrefixFromQNameIterator ( short sctx, const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>( sctx, loc, arg ){};
  
    ~PrefixFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(PrefixFromQNameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PrefixFromQNameIterator, UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>*)this);
  }
};
/* end class PrefixFromQNameIterator */

/*
 * 11.2.3 fn:local-name-from-QName
 * -------------------- */
/* begin class LocalNameFromQNameIterator */
class LocalNameFromQNameIterator : public UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>
{
  public:
    LocalNameFromQNameIterator ( short sctx, const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>( sctx, loc, arg ){};
  
    ~LocalNameFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(LocalNameFromQNameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LocalNameFromQNameIterator, UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>*)this);
  }
};
/* end class LocalNameFromQNameIterator */

/*
 * 11.2.4 fn:namespace-uri-from-QName
 * -------------------- */
/* begin class NamespaceUriFromQNameIterator */
class NamespaceUriFromQNameIterator : public UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>
{
  public:
    NamespaceUriFromQNameIterator ( short sctx, const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>( sctx, loc, arg ){};
  
    ~NamespaceUriFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(NamespaceUriFromQNameIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NamespaceUriFromQNameIterator, UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>*)this);
  }
};
/* end class NamespaceUriFromQNameIterator */

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 * --------------------*/
NARY_ITER_SCTX (NamespaceUriForPrefixIterator);

/*
 * 11.2.6 fn:in-scope-prefixes
 * -------------------- */
/* begin class InScopePrefixesIterator */
class InScopePrefixesState : public PlanIteratorState
{
  friend class InScopePrefixesIterator;

private:
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > theBindings;
  unsigned long theCurrentPos;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


class InScopePrefixesIterator : public UnaryBaseIterator<InScopePrefixesIterator,
                                                         InScopePrefixesState>
{
public:
  InScopePrefixesIterator( short sctx,const QueryLoc& loc, PlanIter_t& arg)
    :
  UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesState>(sctx, loc, arg) {};
  
  ~InScopePrefixesIterator() {};

public:
  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(InScopePrefixesIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InScopePrefixesIterator, UnaryBaseIterator<InScopePrefixesIterator,InScopePrefixesState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<InScopePrefixesIterator,InScopePrefixesState>*)this);
  }
};
/* end class InScopePrefixesIterator */
}/*namespace zorba*/
#endif /* ZORBA_QNAMES_IMPL_H */
