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
#include "compiler/parser/location.hh"
#include "store/api/item.h"
#include "util/utf8/xqpString.h"
#include "system/zorba.h"
#include "util/Assert.h"
#include "runtime/visitors/planitervisitor.h"

// Info: Forcing inlining a function in g++:
// Item_t next() __attribute__((always_inline)) {...}

/*******************************************************************************

  Consts and macros to automate Duff's Device and separation of code and state. 


  DUFFS_ALLOCATE_RESOURCES : This is the initial value of the duffs line in 
                             every state object. Should always be 0 because of
                             the way, the memory is allocated
  DUFFS_RESTART            : The reset method of each iterator sets the duffs
                             line to DUFFS_RESTART

  DEFUALT_STACK_INIT : Initializes the state object of the current iterator
                       (which always includes the Duff's Device) and returns
                       a pointer to that state in the state block.
  MANUAL_STACK_INIT  : If you want to do resource allocation in addition to
                       what is done by the init() method of the state object,
                       you have to use this STACK_INIT, to have the full control.
  STACK_PUSH         : Returns the passed item and saves the current position
                       in the file into the duffs line so that when the nextImpl
                       method of the iterator is called again, execution will
                       start right after the STACK_PUSH macro.
  STACK_END          : Ends the execution of the nextImpl method
  GET_STATE          : Specific function to load the state of the current
                       iterator from the state block.

********************************************************************************/

static const int32_t DUFFS_ALLOCATE_RESOURCES = 0;
static const int32_t DUFFS_RESTART            = -1;


#define GET_STATE(stateType, stateObject, planState) \
  stateObject = reinterpret_cast<stateType*>(planState.theBlock + this->stateOffset)


#define DEFAULT_STACK_INIT(stateType, stateObject, planState )  \
  GET_STATE(stateType, stateObject, planState);                 \
  switch (stateObject->getDuffsLine())                          \
  {                                                             \
    case DUFFS_ALLOCATE_RESOURCES:                              \
      stateObject->init(planState);                             \
    case DUFFS_RESTART:


#define MANUAL_STACK_INIT(stateObject)                          \
  switch (stateObject->getDuffsLine())                          \
  {                                                             \
    case DUFFS_ALLOCATE_RESOURCES:


#define STACK_PUSH(x, stateObject)                             \
   do                                                          \
   {                                                           \
     stateObject->setDuffsLine(__LINE__);                      \
     return x;                                                 \
 case __LINE__: ;                                              \
   } while (0)


#define STACK_END()  } return NULL

#define FINISHED_ALLOCATING_RESOURCES() case DUFFS_RESTART:



namespace xqp
{

class Item;
typedef rchandle<Item> Item_t;

class PlanIterator;

typedef rchandle<PlanIterator> PlanIter_t;

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
   *
   * To store information for new iterators, it might be necessary to derive
   * from this class. All initialization of such information should be done in
   * this function. If resources are requested during initialization, they must
   * be released in the destructor.
   *
   * Classes that inherit from PlanIteratorState must call the init function of 
   * their parent class explicitly in order to guarantee proper initialization.
   */
  void init(PlanState&) { theDuffsLine = DUFFS_ALLOCATE_RESOURCES; }

  /** 
   * Reset the current state object.
   *
   * Reset() is invoked by the resetImpl() method of the associated iterator.
   * Reset() sets the duffs line so that when the nextImpl() method of the
   * iterator is called again after a resetImpl(), no resources will be
   * allocated again (i.e. the init() method of the state obj will not be
   * called).
   *
   * Classes that inherit from PlanIteratorState must call the reset function 
   * of their parent class explicitly in order to guarantee a proper reset.
   */
  void reset(PlanState&) { theDuffsLine = DUFFS_RESTART; }
  
  void setDuffsLine(int32_t aVal) { theDuffsLine = aVal; }
  int32_t getDuffsLine() const    { return theDuffsLine; }
};


/*******************************************************************************
  Base class of all plan iterators.
********************************************************************************/
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
   * @param planState
   */
  virtual void reset(PlanState& planState) = 0;

  /** 
   * Finish the execution of the iterator.
   * Releases all resources and destroy the according plan state
   * objects
   * Make sure that no exception is throw when destroying the states.
   * Otherwise we will have a lot of memory leaks.
   *
   * @param planState
   */
  virtual void close(PlanState& planState) throw() = 0;

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
  //  planState.theZorba->current_iterator.push(this);

    int32_t i = 0;
    theBatch[0] = static_cast<IterType*>(this)->nextImpl();
    while (i < ZORBA_BATCHING_BATCHSIZE && batch[i] != NULL) 
    {
      i++;
      theBatch[i] = static_cast<IterType*>(this)->nextImpl();
    }

   // planState.theZorba->current_iterator.pop();
  }
#else
  Item_t produceNext(PlanState& planState)
  {
    return static_cast<IterType*>(this)->nextImpl(planState);
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

  void close(PlanState& planState) throw()
  {
    static_cast<IterType*>(this)->closeImpl(planState);
  }

public:
  inline Item_t nextImpl(PlanState& planState);

  inline void openImpl(PlanState& planState, uint32_t& offset);
  inline void resetImpl(PlanState& planState);
  inline void closeImpl(PlanState& planState);
};


/*******************************************************************************
  Wrapper used to drive the evaluation of an iterator (sub)tree.
  
  The wrapper wraps the root iterator of the (sub)tree. It is responsible
  for allocating and deallocating the plan state that is shared by all
  iterators in the (sub)tree. In general, it hides internal functionality
  like separation of code and execution, or garabage collection, and it
  provides a simple interface that the application can use.
********************************************************************************/
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

