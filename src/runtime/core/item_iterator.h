/* 
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska, David Graf
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/noarybase.h"
#include "system/zorba_engine.h"

#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;
namespace xqp {

class Item;
class node;
class zorba;




/*
public:   // "treat as" operators
  string_iterator& treat_as_string();
  node
  document
  element
  attribute
  namespace
  pi
  comment
  text
  string
  numeric 
  boolean
  time
  binary
  qname
  sequence

*/

class SingletonIterator;
typedef rchandle<SingletonIterator> singleton_t;


/** Class represents an empty sequence.
  */
class EmptyIterator : public Batcher<EmptyIterator>
{
public:
  EmptyIterator(yy::location loc) : Batcher<EmptyIterator>(loc) {}
  EmptyIterator(const EmptyIterator& it) : Batcher<EmptyIterator>(it) {}
  ~EmptyIterator() {}
  
  Item_t nextImpl(PlanState& planState) { return NULL; }
  void resetImpl(PlanState& planState)  { }
  void releaseResourcesImpl(PlanState& planState){ }

  virtual uint32_t getStateSize() const { return 0; }
  virtual uint32_t getStateSizeOfSubtree() const { 
    return 0; 
}
  virtual void setOffset(PlanState& planState, uint32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;
}; /* class EmptyIterator */


/*_____________________________________________________________
|
| literals and for_var bindings
|______________________________________________________________*/
class SingletonIterator : public NoaryBaseIterator<SingletonIterator>
{
protected:
  Item_t theValue;

public:
  SingletonIterator(yy::location loc, Item_t _i_p);
  ~SingletonIterator();
  
public:
  Item_t nextImpl(PlanState& planState);
  
  const Item_t& getValue() const { return theValue; }
  
  virtual void accept(PlanIterVisitor&) const;
};


class var_iterator : public SingletonIterator
{
protected:
  string s_h;
  const void *origin;  ///< origin expr, used as a kind of ID
  
public:
  var_iterator(string s_p, yy::location loc, const void *origin_) : 
              SingletonIterator(loc,NULL), 
              s_h(s_p), origin (origin_)
  {}
  ~var_iterator(){
    
  }
  
  virtual void accept(PlanIterVisitor&) const;
  
public:   // variable binding
  void bind(Item_t aValue) { theValue = aValue; }
};


/**
 * If a variable can hold more than one item, use this ref-holder
 * 
 */
class RefIterator : public Batcher<RefIterator>
{
private:
  Iterator_t it;
  const void *origin;  ///< like origin in var_iterator
  
public:
  RefIterator(string s_p, yy::location loc, const void *origin_)
    : Batcher<RefIterator> (loc), origin (origin_)
  {}
  ~RefIterator() {}  // TODO
  
public:   // variable binding
  void bind(Iterator_t _it) { it = _it;}
  Item_t nextImpl(PlanState& planState) { return it->next(); }  // TODO
  void resetImpl(PlanState& planState) { it->reset(); }  // TODO
  void releaseResourcesImpl(PlanState& planState) {  }  // TODO
  virtual uint32_t getStateSize() const { return 0; }  // TODO
  virtual uint32_t getStateSizeOfSubtree() const { return 0; }  // TODO
  virtual void setOffset(PlanState& planState, uint32_t& offset) {}  // TODO
  
  virtual void accept(PlanIterVisitor&) const;
};

  
class IfThenElseIterator : public Batcher<IfThenElseIterator>
{
private:
  PlanIter_t theCondIter;
  PlanIter_t theThenIter;
  PlanIter_t theElseIter;
  bool theIsBooleanIter;
    
public:
  /**
   * Constructor
   * @param loc location
   * @param iterCond_arg represents condition
   * @param iterThen_arg represents then expression
   * @param iterElse_arg represents else expression
   * @param condIsBooleanIter Optional flag. If true => condition is already an iterator 
   *                              which return true or false => the conditional value
   *                              does not have to be evaluated with the effective
   *                              boolean value function
   */
  IfThenElseIterator(
        const yy::location& loc,
        PlanIter_t& aCondIter,
        PlanIter_t& aThenIter,
        PlanIter_t& aElseIter,
        bool aIsBooleanIter = false);
    
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);
  
  virtual uint32_t getStateSize() const { return sizeof(IfThenElseIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const;
  virtual void setOffset ( PlanState& planState, uint32_t& offset );
      
  virtual void accept(PlanIterVisitor&) const;
  
  protected:
    class IfThenElseIteratorState : public PlanIteratorState {
      public:
        bool theThenUsed;
    };
}; /* class IfThenElseIterator */


} /* namespace xqp */
#endif  /* XQP_ITEM_ITERATOR_H */

