/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 * @author Tim Kraska (tim.kraska@inf.ethz.ch), David Graf (dagraf@inf.ethz.ch)
 * @file runtime/core/batching.h
 *
 */
#ifndef XQP_ITERATOR_H
#define XQP_ITERATOR_H

#include "zorba/common.h"

#include <vector>

#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "store/api/item.h"
#include "util/utf8/xqpString.h"
#include "system/zorba.h"
#include "util/Assert.h"
#include "runtime/visitors/planitervisitor.h"

// Info: Forcing inlining a function in g++:
// Item_t next() __attribute__((always_inline)) {...}

/*******************************************************************************

  Macros to automate Duff's Device and separation of code and execution 

   DEFUALT_STACK_INIT : Initializes Duff's Device and gets the state of the
                        current iterator from the state block
   MANUAL_STACK_INIT  : If you want to do Resource allocation, you have to use
                        this STACK_INIT, to have the full control.
   STACK_PUSH         : Returns the passed item and saves the current position
                        of the next functions
   STACK_END          : Ends the execution of the next function
   GET_STATE          : Specific function to load the state of the current
                        iterator from the state block.

********************************************************************************/

#define DEFAULT_STACK_INIT(stateType, stateObject, planState )  \
  GET_STATE(stateType, stateObject, planState);                 \
  switch (stateObject->getDuffsLine())                          \
  {                                                             \
    case DUFFS_RELEASE_RESOURCES:                               \
      stateObject->init(planState);                                      \
    case DUFFS_RESET:


#define MANUAL_STACK_INIT(stateObject)                          \
  switch (stateObject->getDuffsLine())                          \
  {                                                             \
    case DUFFS_RELEASE_RESOURCES:


#define STACK_PUSH(x, stateObject)                             \
   do                                                          \
   {                                                           \
     stateObject->setDuffsLine(__LINE__);                      \
     return x;                                                 \
 case __LINE__: ;                                              \
   } while (0)


#define STACK_END()  } return NULL


#define GET_STATE(stateType, stateObject, planState) \
  stateObject = reinterpret_cast<stateType*>(planState.theBlock + this->stateOffset)


#define FINISHED_ALLOCATING_RESOURCES() case DUFFS_RESET:


static const int32_t DUFFS_RELEASE_RESOURCES = 0; //Should always be 0 because of the way, the memory is allocated
static const int32_t DUFFS_RESET =-1;


namespace xqp
{

class Item;
typedef rchandle<Item> Item_t;

class PlanIterator;
class Zorba;

typedef rchandle<PlanIterator> PlanIter_t;

class Zorba_XQueryBinary;

/*******************************************************************************
  Class to represent state that is shared by all plan iterators. 

  theBlock        : Pointer to the memory block that stores the local state of
                    each individual plan iterator.
  theBlockSize    : Size (in bytes) of the block.
  theZorba        : Pointer to the zorba object of the current thread. The zorba
                    obj provides quick access to thread specific storage (for
                    example, the error manager).
********************************************************************************/
class PlanState
{
public:
  int8_t     * theBlock;

  uint32_t     theBlockSize;

  Zorba      * theZorba;

public:
  PlanState(uint32_t blockSize);

  ~PlanState();
};


template <class T>
class StateTraitsImpl
{
private:
  StateTraitsImpl() {}
public:
 static uint32_t getStateSize()
 {
   return sizeof(T);
 }

 static void createState(void *ptr)
 {
   new (ptr)T();
 }
 
 static void destroyState(void *ptr)
 {
  (reinterpret_cast<T*>(ptr))->~T();
 }

 static void reset(PlanState& planState, int8_t *block,  uint32_t stateOffset)
 {
  (reinterpret_cast<T*>(block + stateOffset))->reset(planState);
 }
};


/**
 * Root object of all iterator state o bjects
 */
class PlanIteratorState
{
private:
  int32_t theDuffsLine;

public:
  PlanIteratorState() {}
  ~PlanIteratorState() {}

  /** 
   * Initialize the current state object.
   * The base class initializes information used for the duffs device.
   * To store information for new iterators, it might be necessary to derive from
   * this class. All initialization of such information should be done in this function.
   * If resources are requested during initializatioan, those must be released
   * in the destructor.
   * Classes that inherit from PlanIteratorState must call the init function 
   * of the base class explicitly in order to guarantee proper initialization.
    */
  void init(PlanState&) { theDuffsLine = DUFFS_RELEASE_RESOURCES; }

  /** 
   * Reset the current state object.
   * Reset is used in order to restart a run of the according iterator.
   * Therefore, this function prepares the duffs device such that
   * it restarts the iterator without initializing/requesting resources
   * (e.g. without calling init()) again.
   * Classes that inherit from PlanIteratorState must call the reset function 
   * of the base class explicitly in order to guarantee a proper reset.
    */
  void reset(PlanState&) { theDuffsLine = DUFFS_RESET; }
  
  void setDuffsLine(int32_t aVal) { theDuffsLine = aVal; }
  int32_t getDuffsLine() const    { return theDuffsLine; }
};

/**
 * Base class of all plan iterators.
 */
class PlanIterator : public rcobject
{
  friend class PlanIterWrapper;

protected:
  uint32_t      stateOffset;
  
public:
  yy::location  loc;
  
#if ZORBA_BATCHING_TYPE == 1  
  int32_t       theCurrItem;
  Item_t        theBatch[ZORBA_BATCHING_BATCHSIZE];
#endif

public:
  PlanIterator(yy::location aLoc) : loc(aLoc) {}
  PlanIterator(const PlanIterator& it) : rcobject(it), loc(it.loc) {}
  virtual ~PlanIterator() {}

public:

  /**
   * Accept method for the PlanIterator-Tree-Visitor
   * 
   * @param PlanIterVisitor
   */
  virtual void accept(PlanIterVisitor&) const = 0;

  /**
   * Begin the execution of the iterator
   * Initializes information required for the plan state
   * and constructs the state object.
   */
  virtual void open(PlanState& planState, uint32_t& offset) = 0;
  
  /** 
   * Produces an output item of the iterator. Implicitly, the first call 
   * of 'producNext' initializes the iterator and allocates resources 
   * (main memory, file descriptors, etc.). 
   *
   * @param stateBLock
   */
  virtual Item_t produceNext(PlanState& planState) = 0;

  /** 
   * Restarts the iterator so that the next 'produceNext' call will start 
   * again from the beginning (should not release any resources).  
   *
   * @param stateBLock
   */
  virtual void reset(PlanState& planState) = 0;

  /** 
   * Finish the execution of the iterator.
   * Releases all resources and destroy the according plan state
   * objects
   *
   * @param stateBLock
   */
  virtual void close(PlanState& planState) = 0;

  /** Returns the size of the state which must be saved for the current iterator
    * on the state block
    */
  virtual uint32_t getStateSize() const = 0;
  
  /** Returns the size of the state for the current iterator 
    * and all its sub-iterators.
    */
  virtual uint32_t getStateSizeOfSubtree() const = 0;
  
protected:

#if ZORBA_BATCHING_TYPE == 1  
  Item_t consumeNext(PlanIter_t& subIter, PlanState& planState)
  {
    if (subIter->theCurrItem == ZORBA_BATCHING_BATCHSIZE)
    {
      subIter->produceNext(planState);
      subIter->theCurrItem = 0;
    }
    return subIter->theBatch[subIter->theCurrItem++];
  }
#else
  inline Item_t consumeNext(PlanIter_t& subIter, PlanState& planState) const
  {
    return subIter->produceNext(planState);
  }
#endif

};


/*******************************************************************************
  Class to implement batching
********************************************************************************/
template <class IterType>
class Batcher: public PlanIterator
{
public:
  Batcher(const Batcher<IterType>& b)  : PlanIterator(b) {}
  Batcher(yy::location loc) : PlanIterator(loc) {}

  ~Batcher() {}

protected:
#if ZORBA_BATCHING_TYPE == 1  
  void produceNext(PlanState& planState) 
  {
    planState.theZorba->current_iterator.push(this);

    int32_t i = 0;
    theBatch[0] = static_cast<IterType*>(this)->nextImpl();
    while (i < ZORBA_BATCHING_BATCHSIZE && batch[i] != NULL) 
    {
      i++;
      theBatch[i] = static_cast<IterType*>(this)->nextImpl();
    }

    planState.theZorba->current_iterator.pop();
  }
#else
  Item_t produceNext(PlanState& planState)
  {
    Item_t  it;
    planState.theZorba->current_iterator.push(this);

    it = static_cast<IterType*>(this)->nextImpl(planState);
  
    planState.theZorba->current_iterator.pop();
    return it;
  }
#endif
  void open(PlanState& planState, uint32_t& offset)
  {
    static_cast<IterType*>(this)->openImpl(planState, offset);
  }

  void reset(PlanState& planState)
  {
    static_cast<IterType*>(this)->resetImpl(planState);
  }

  void close(PlanState& planState)
  {
    static_cast<IterType*>(this)->closeImpl(planState);
  }

public:
  inline Item_t nextImpl(PlanState& planState);

  inline void openImpl(PlanState& planState, uint32_t& offset);
  inline void resetImpl(PlanState& planState);
  inline void closeImpl(PlanState& planState);
};


template <class Iter, class StateTraits>
class NaryIterator : public Batcher<Iter>
{
protected:
  std::vector<PlanIter_t> theChildren;

public:
  NaryIterator(const yy::location& aLoc, std::vector<PlanIter_t>& aChildren)
    :
    Batcher<Iter>(aLoc), theChildren(aChildren)
  {
#ifndef NDEBUG
    std::vector<PlanIter_t>::const_iterator lIter = aChildren.begin();
    std::vector<PlanIter_t>::const_iterator lEnd = aChildren.end();
    for( ; lIter != lEnd; ++lIter)
    {
      Assert( *lIter ); // make sure alll children are set properly
    }
#endif
  }

  virtual ~NaryIterator() {}

  virtual void 
  accept(PlanIterVisitor&) const = 0;

  void
  openImpl(PlanState& aPlanState, uint32_t& aOffset)
  {
    // compute the position of the state in the state block
    // and create the state object
		Batcher<Iter>::stateOffset = aOffset;
		aOffset += getStateSize();
    StateTraits::createState(aPlanState.theBlock + Batcher<Iter>::stateOffset);

    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::iterator lEnd  = theChildren.end();
    for ( ; lIter!= lEnd; ++lIter )
    {
      ( *lIter )->open( aPlanState, aOffset );
    }
  }

  void
	closeImpl( PlanState& aPlanState )
	{
    std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
    for ( ; lIter!= theChildren.end(); ++lIter )
    {
      ( *lIter )->close( aPlanState );
		}

    StateTraits::destroyState(aPlanState.theBlock + Batcher<Iter>::stateOffset);
	}

  void resetImpl(PlanState& aPlanState) 
  { 
    StateTraits::reset(aPlanState, aPlanState.theBlock, this->stateOffset);
    
    std::vector<PlanIter_t>::iterator lIter = theChildren.begin();
    std::vector<PlanIter_t>::iterator lIterEnd = theChildren.end();
    for(; lIter != lIterEnd; ++lIter)
    {
      ( *lIter )->reset( aPlanState );
    }
  }

  virtual uint32_t
  getStateSize() const {
    return StateTraits::getStateSize();
  }

	virtual uint32_t
	getStateSizeOfSubtree() const
	{
		uint32_t lSize = 0;

    std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin(); 
    std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
    for ( ; lIter!= theChildren.end(); ++lIter )
    {
			lSize += ( *lIter )->getStateSizeOfSubtree();
		}

		return getStateSize() + lSize;
	}

};


#define NARY_ITER_STATE(iterName, stateName) class iterName \
  : public NaryIterator<iterName, StateTraitsImpl<stateName> > {\
public:\
  iterName(yy::location loc, std::vector<PlanIter_t>& aChildren) :\
    NaryIterator<iterName, StateTraitsImpl<stateName> >(loc, aChildren) \
  { } \
  virtual ~iterName() { } \
  \
  Item_t nextImpl(PlanState& aPlanState); \
  \
  virtual void accept(PlanIterVisitor& v) const \
  {  \
    v.beginVisit(*this); \
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin(); \
    for ( ; iter != theChildren.end(); ++iter ) { \
      ( *iter )->accept ( v ); \
    } \
    v.endVisit(*this); \
  } \
};

#define NARY_ITER(name) NARY_ITER_STATE(name, PlanIteratorState) 

/**
 * Wrapper used to drive the evaluation of an iterator (sub)tree.
 * 
 * The wrapper wraps the root iterator of the (sub)tree. It is responsible
 * for allocating and deallocating the plan state that is shared by all
 * iterators in the (sub)tree. In general, it hides internal functionality
 * like separation of code and execution, or garabage collection, and it
 * provides a simple interface that the application can use.
 */
class PlanWrapper : public Iterator
{
private:
  PlanIter_t   theIterator;
  PlanState*   theStateBlock;
  bool         theClosed;
  
public:
  PlanWrapper(PlanIter_t& iter);
  
  virtual ~PlanWrapper();
  
  void open();
  Item_t next();
  void reset();
  void close();
};


/*******************************************************************************
  This is a "helper" wrapper that is used when we need to pass a plan iterator
  to the store. The wrapper wraps the plan iterator in order to provide a
  simpler interface that the store can use.
 
  The wrapper does not allocate a new state block, but it points to the same 
  block that contains the state of the wrapped plan iterator.
********************************************************************************/
class PlanIteratorWrapper : public Iterator
{
private:
  PlanIter_t   theIterator;
  PlanState*   theStateBlock;
  bool         theClosed;

public:
  PlanIteratorWrapper(PlanIter_t& iter, PlanState& planState);
  
  virtual ~PlanIteratorWrapper();
 
  void open();
  Item_t next();
  void reset();
  void close();
};

} /* namespace xqp */

#endif  /* XQP_ITERATOR_H */

