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
    ResolveQNameIterator( const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~ResolveQNameIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
};
/*end class ResolveQNameIterator */

/*
 * 11.1.2 fn:QName
 * --------------------*/
 
/*begin class QNameIterator */
class QNameIterator : public BinaryBaseIterator<QNameIterator, PlanIteratorState>
{
  public:
    QNameIterator( const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~QNameIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
};
/*end class QNameIterator */

/*
 * 11.2.1 op:QName-equal
 * --------------------*/
 
/*begin class QNameEqualIterator */
class QNameEqualIterator : public BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>
{
  public:
    QNameEqualIterator( const QueryLoc& loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~QNameEqualIterator() {};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
};
/*end class QNameEqualIterator */

/*
 * 11.2.2 fn:prefix-from-QName
 * -------------------- */
/* begin class PrefixFromQNameIterator */
class PrefixFromQNameIterator : public UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>
{
  public:
    PrefixFromQNameIterator ( const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~PrefixFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
};
/* end class PrefixFromQNameIterator */

/*
 * 11.2.3 fn:local-name-from-QName
 * -------------------- */
/* begin class LocalNameFromQNameIterator */
class LocalNameFromQNameIterator : public UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>
{
  public:
    LocalNameFromQNameIterator ( const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~LocalNameFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
};
/* end class LocalNameFromQNameIterator */

/*
 * 11.2.4 fn:namespace-uri-from-QName
 * -------------------- */
/* begin class NamespaceUriFromQNameIterator */
class NamespaceUriFromQNameIterator : public UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>
{
  public:
    NamespaceUriFromQNameIterator ( const QueryLoc& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~NamespaceUriFromQNameIterator(){};
  public:
    bool nextImpl(store::Item_t& result, PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
};
/* end class NamespaceUriFromQNameIterator */

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 * --------------------*/
NARY_ITER (NamespaceUriForPrefixIterator);

/*
 * 11.2.6 fn:in-scope-prefixes
 * -------------------- */
/* begin class InScopePrefixesIterator */
class InScopePrefixesState : public PlanIteratorState
{
  friend class InScopePrefixesIterator;

private:
  std::vector<std::pair<xqpString, xqpString> > theBindings;
  unsigned long theCurrentPos;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


class InScopePrefixesIterator : public UnaryBaseIterator<InScopePrefixesIterator,
                                                         InScopePrefixesState>
{
public:
  InScopePrefixesIterator(const QueryLoc& loc, PlanIter_t& arg)
    :
  UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesState>(loc, arg) {};
  
  ~InScopePrefixesIterator() {};

public:
  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};
/* end class InScopePrefixesIterator */
}/*namespace zorba*/
#endif /* ZORBA_QNAMES_IMPL_H */
