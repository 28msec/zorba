/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file runtime/qnames/QNamesImpl.h
 *
 */

#ifndef XQP_QNAMES_IMPL_H
#define XQP_QNAMES_IMPL_H

#include <vector>
#include "common/shared_types.h"
#include "util/utf8/xqpString.h"
#include "runtime/base/unarybase.h" // remove after iterator refactoring
#include "runtime/base/binarybase.h" // remove after iterator refactoring

namespace xqp {
/*
 * 11.1.1 fn:resolve-QName
 * --------------------*/
 
/*begin class ResolveQNameIterator */
class ResolveQNameIterator : public BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>
{
  public:
    ResolveQNameIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<ResolveQNameIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~ResolveQNameIterator() {};
  public:
    Item_t nextImpl(PlanState& planState) const;
  
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
    QNameIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~QNameIterator() {};
  public:
    Item_t nextImpl(PlanState& planState) const;
  
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
    QNameEqualIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<QNameEqualIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~QNameEqualIterator() {};
  public:
    Item_t nextImpl(PlanState& planState) const;
  
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
    PrefixFromQNameIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<PrefixFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~PrefixFromQNameIterator(){};
  public:
    Item_t nextImpl(PlanState& planState) const;
    
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
    LocalNameFromQNameIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<LocalNameFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~LocalNameFromQNameIterator(){};
  public:
    Item_t nextImpl(PlanState& planState) const;
    
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
    NamespaceUriFromQNameIterator ( const yy::location& loc, PlanIter_t& arg )
  :
    UnaryBaseIterator<NamespaceUriFromQNameIterator, PlanIteratorState>( loc, arg ){};
  
    ~NamespaceUriFromQNameIterator(){};
  public:
    Item_t nextImpl(PlanState& planState) const;
    
    virtual void accept(PlanIterVisitor&) const;
};
/* end class NamespaceUriFromQNameIterator */

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 * --------------------*/
 
/*begin class NamespaceUriForPrefixlIterator */
class NamespaceUriForPrefixlIterator : public BinaryBaseIterator<NamespaceUriForPrefixlIterator, PlanIteratorState>
{
  public:
    NamespaceUriForPrefixlIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
  :
    BinaryBaseIterator<NamespaceUriForPrefixlIterator, PlanIteratorState>(loc, arg0, arg1){}

    ~NamespaceUriForPrefixlIterator() {};
  public:
    Item_t nextImpl(PlanState& planState) const;
  
    virtual void accept(PlanIterVisitor&) const;
};
/*end class NamespaceUriForPrefixlIterator */

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
  InScopePrefixesIterator(const yy::location& loc, PlanIter_t& arg)
    :
  UnaryBaseIterator<InScopePrefixesIterator, InScopePrefixesState>(loc, arg) {};
  
  ~InScopePrefixesIterator() {};

public:
  Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};
/* end class InScopePrefixesIterator */
}/*namespace xqp*/
#endif /* XQP_QNAMES_IMPL_H */
