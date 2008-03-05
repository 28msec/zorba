/* 
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska, David Graf
 *
 */

#ifndef ZORBA_ITEM_ITERATOR_H
#define ZORBA_ITEM_ITERATOR_H

#include "common/shared_types.h"
#include "runtime/base/noarybase.h"

namespace zorba {

class Item;
class node;
class zorba;


class SingletonIterator;
typedef rchandle<SingletonIterator> singleton_t;


/*******************************************************************************

   Class represents an empty sequence.

********************************************************************************/
class EmptyIterator : public NoaryBaseIterator<EmptyIterator, PlanIteratorState>
{
public:
  EmptyIterator(const QueryLoc& loc)
     : NoaryBaseIterator<EmptyIterator, PlanIteratorState>(loc) {}

  virtual ~EmptyIterator() {}
  
public:
  Item_t nextImpl(PlanState& planState) const { return NULL; }

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************

  Literals

********************************************************************************/
class SingletonIterator : public NoaryBaseIterator<SingletonIterator, PlanIteratorState>
{
protected:
  Item_t theValue;

public:
  SingletonIterator(const QueryLoc& loc, Item_t value)
    : NoaryBaseIterator<SingletonIterator, PlanIteratorState>(loc),
    theValue(value) {}

  virtual ~SingletonIterator() {}
  
public:
  Item_t nextImpl(PlanState& planState) const;

  const Item_t& getValue() const { return theValue; }
  
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************

  
********************************************************************************/
class IfThenElseIteratorState : public PlanIteratorState 
{
public:
  bool theThenUsed;
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
        const QueryLoc& loc,
        PlanIter_t& aCondIter,
        PlanIter_t& aThenIter,
        PlanIter_t& aElseIter,
        bool aIsBooleanIter = false);
    
  void openImpl(PlanState& planState, uint32_t& offset);
  Item_t nextImpl(PlanState& planState) const;
  void resetImpl(PlanState& planState) const;
  void closeImpl(PlanState& planState) const;
  
  virtual uint32_t getStateSize() const { return sizeof(IfThenElseIteratorState); }
  virtual uint32_t getStateSizeOfSubtree() const;
      
  virtual void accept(PlanIterVisitor&) const;
};


} /* namespace zorba */
#endif  /* ZORBA_ITEM_ITERATOR_H */

