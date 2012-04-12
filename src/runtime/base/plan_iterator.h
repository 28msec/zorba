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
#pragma once
#ifndef ZORBA_RUNTIME_PLAN_ITERATOR
#define ZORBA_RUNTIME_PLAN_ITERATOR

#include <stack>

#include "common/shared_types.h"

#include "diagnostics/assert.h"

#include "runtime/util/flowctl_exception.h"

#include "compiler/parser/query_loc.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"


#if ZORBA_BATCHING_TYPE == 1
#include "store/api/item.h"
#endif


// Info: Forcing inlining a function in g++:
// store::Item_t next() __attribute__((always_inline)) {...}

/*******************************************************************************

  Macros to automate Duff's Device and separation of code and state.

  These macros are used in the nextImpl() method of each iterator. In general,
  the nextImpl() method will be called multiple times, and during each invocation,
  its behaviour depends on the current state of the iterator (which includes
  info about what the previous invocation(s) did). The Duff's device is a
  techique by which the point where each invocation exited from is remembered,
  and during the next invocation, execution of the method resumes at that point.
  In general, this simplifies the implementation of the method.

  DEFUALT_STACK_INIT : Gets a pointer to the iterator's state in the state block
                       and "starts" the duff's device.
  STACK_PUSH         : Causes the nextImpl() method to return with the given
                       status and saves the current line in the source file
                       into the duffs line so that when the nextImpl method
                       is called again, execution will start right after the
                       STACK_PUSH macro.
  STACK_END          : Causes the nextImpl() method to return with false,
                       indicating that there are no more results to produce.
                       It also saves the current line in the source file into
                       the duffs line so that if the nextImpl method is called
                       again, an exception will be raised.
********************************************************************************/

#define DEFAULT_STACK_INIT(stateType, stateObject, planState)           \
  stateObject = StateTraitsImpl<stateType>::getState(planState, this->theStateOffset); \
  switch (stateObject->getDuffsLine())                                  \
  {                                                                     \
  case PlanIteratorState::DUFFS_ALLOCATE_RESOURCES:

#define STACK_PUSH(status, stateObject)                                 \
  do                                                                    \
  {                                                                     \
    stateObject->setDuffsLine(__LINE__);                                \
    return status;                                                      \
  case __LINE__: ;                                                      \
   } while (0)

#define STACK_END( stateObject)                                         \
  do {                                                                  \
    stateObject->setDuffsLine(__LINE__);                                \
    return false;                                                       \
  case __LINE__:                                                        \
    stateObject->setDuffsLine(__LINE__ + 1);                            \
  case __LINE__ + 1:                                                    \
    ZORBA_ASSERT (false && "nextImpl() called past iterator end");      \
    return false;                                                       \
  default:                                                              \
    return false;                                                       \
  } while (0);                                                          \
  }


namespace zorba
{

class RuntimeCB;
class PlanIterVisitor;
class dynamic_context;
class DebuggerCommons;
class XQueryImpl;


/*******************************************************************************
  Class to represent state that is shared by all plan iterators.

  theBlock        : Pointer to the memory block that stores the local state of
                    each individual plan iterator.
  theBlockSize    : Size (in bytes) of the block.
  theHasToQuit    : Boolean that indicates if the query execution has to quit.
                    Checking this value is done in each consumeNext call,
                    i.e. between every two iterator next calls. This value is
                    set by the StateWrapper class (see runtime/util/timeout.h)
                    after a user-defined timeout value is exceeded.
********************************************************************************/
class PlanState
{
public:
  int8_t                  * theBlock;

  uint32_t                  theBlockSize;

  uint32_t                  theStackDepth;

  uint32_t                  theMaxStackDepth;

  // TODO this guy should become const because nothing can change anymore during
  // runtime. We need to make all accessor in the control block and static context
  // (see also shortcut below) const before doing that
  CompilerCB              * theCompilerCB;

  XQueryImpl              * theQuery;

  dynamic_context         * theGlobalDynCtx;

  dynamic_context         * theLocalDynCtx;

  std::stack<store::Item*>  theNodeConstuctionPath;

  DebuggerCommons         * theDebuggerCommons;

  bool                      theHasToQuit;

public:
  PlanState(
      dynamic_context* globalDctx,
      dynamic_context* localDctx,
      uint32_t blockSize,
      uint32_t aStackDepth = 0,
      uint32_t aMaxStackDepth = 1024);

  ~PlanState();

  void checkDepth(const QueryLoc& loc);
};


/*******************************************************************************
  Base class for all iterator state objects.
********************************************************************************/
class PlanIteratorState
{
public:
  static const uint32_t DUFFS_ALLOCATE_RESOURCES = 0;

private:
  uint32_t         theDuffsLine;

public:
#if ZORBA_BATCHING_TYPE == 1
public:
  uint32_t        theCurrItem;
  store::Item_t   theBatch[ZORBA_BATCHING_BATCHSIZE];
#endif
#ifndef NDEBUG
  bool            theIsOpened;
#endif

public:
  PlanIteratorState()
    :
    theDuffsLine(DUFFS_ALLOCATE_RESOURCES)
#if ZORBA_BATCHING_TYPE == 1
    , theCurrItem(ZORBA_BATCHING_BATCHSIZE)
#endif
#ifndef NDEBUG
    , theIsOpened(false)
#endif
  {}

  ~PlanIteratorState() {}

  void setDuffsLine(uint32_t aVal) { theDuffsLine = aVal; }

  uint32_t getDuffsLine() const { return theDuffsLine; }

  /**
   * Initialize the current state object.
   *
   * This method is invoked be the openImpl() method of the associated iterator
   * to initialize the state info needed by the iterator. All initialization of
   * such info should be done in this function. If resources are acquired during
   * initialization, they must be released in the destructor.
   *
   * Classes that inherit from PlanIteratorState must reimplement this method.
   * Each subclass implementation of this method must call the init() method of
   * their parent class explicitly in order to guarantee proper initialization.
   */
  void init(PlanState&)
  {
    theDuffsLine = DUFFS_ALLOCATE_RESOURCES;
#if ZORBA_BATCHING_TYPE == 1
    theCurrItem = ZORBA_BATCHING_BATCHSIZE;
#endif
  }

  /**
   * Reset the current state object.
   *
   * This method is invoked by the resetImpl() method of the associated iterator.
   * It resets the state info so that when the nextImpl() method of the iterator
   * is called again after a resetImpl(), it will behave as if it is called for
   * the first time.
   *
   * Classes that inherit from PlanIteratorState must reimplement this method.
   * Each subclass implementation of this method must call the reset() method
   * of their parent class explicitly in order to guarantee proper reset.
   */
  void reset(PlanState&)
  {
    theDuffsLine = DUFFS_ALLOCATE_RESOURCES;
#if ZORBA_BATCHING_TYPE == 1
    theCurrItem = ZORBA_BATCHING_BATCHSIZE;
    // seeting the first item to NULL only is sufficient so
    // that produceNext knows that it's not finished yet
    theBatch[0] = NULL;
#endif
  }
};


/*******************************************************************************

********************************************************************************/
template <class T>
class StateTraitsImpl
{
private:
  StateTraitsImpl() {} // prevent instantiation

public:
  static uint32_t getStateSize()
  {
    return sizeof(T);
  }

  static T* getState(PlanState& planState, uint32_t stateOffset)
  {
    return reinterpret_cast<T*>(planState.theBlock + stateOffset);
  }

  static void createState(PlanState& planState, uint32_t& stateOffset, uint32_t& offset)
  {
    stateOffset = offset;
    offset += StateTraitsImpl<T>::getStateSize();
    new (planState.theBlock + stateOffset)T();
  }

  static void initState(PlanState& planState, uint32_t& stateOffset)
  {
    getState(planState, stateOffset)->init(planState);
  }

  static void reset(PlanState& planState, uint32_t stateOffset)
  {
    (reinterpret_cast<T*>(planState.theBlock+ stateOffset))->reset(planState);
  }

  static void destroyState(PlanState& planState, uint32_t stateOffset)
  {
    (reinterpret_cast<T*>(planState.theBlock + stateOffset))->~T();
  }
};

#if ZORBA_BATCHING_TYPE == 1

#error "Batching not implemented with the new iterator contract."

#endif


/*******************************************************************************
  Base class of all plan iterators.
********************************************************************************/
class PlanIterator : public SimpleRCObject
{
  friend class PlanIterWrapper;

protected:
  uint32_t           theStateOffset;

public:
  QueryLoc           loc;
  static_context   * theSctx;

public:
  SERIALIZABLE_ABSTRACT_CLASS(PlanIterator);

  PlanIterator(zorba::serialization::Archiver& ar)
    :
    SimpleRCObject(ar),
    theSctx(NULL)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar);

public:
  PlanIterator(static_context* aContext, const QueryLoc& aLoc)
    :
    theStateOffset(0),
    loc(aLoc),
    theSctx(aContext)
  {
  }

  PlanIterator(const PlanIterator& it)
    :
    SimpleRCObject(it),
    theStateOffset(0),
    loc(it.loc),
    theSctx(it.theSctx)
  {}

  virtual ~PlanIterator() {}

  void setLocation(const QueryLoc& loc_) { loc = loc_; }

  const QueryLoc& getLocation() const { return loc; }

  uint32_t getStateOffset() const { return theStateOffset; }

  static_context* getStaticContext() const { return theSctx; }

  TypeManager* getTypeManager() const;

  virtual bool isConstructor() const { return false; }

  /**
   * Accept method for the PlanIterator-Tree-Visitor
   *
   * @param PlanIterVisitor
   */
  virtual void accept(PlanIterVisitor&) const = 0;

  /**
   * Returns the size of the state which must be saved for the current iterator
   * on the state block
   */
  virtual uint32_t getStateSize() const = 0;

  /**
   * Returns the size of the state for this iterator and all its sub-iterators.
   */
  virtual uint32_t getStateSizeOfSubtree() const = 0;

  /**
   * Begin the execution of the iterator. Initializes information required for
   * the plan state and constructs the state object.
   */
  virtual void open(PlanState& planState, uint32_t& offset) = 0;

  /**
   * Restarts the iterator so that the next 'produceNext' call will start
   * again from the beginning (should not release any resources).
   *
   * @param planState
   */
  virtual void reset(PlanState& planState) const = 0;

  /**
   * Finish the execution of the iterator. Releases all resources and destroys
   * the according plan state* objects. Make sure that no exception is throw
   * when destroying the states. Otherwise we will have a lot of memory leaks.
   *
   * @param planState
   */
  virtual void close(PlanState& planState) = 0;


#if ZORBA_BATCHING_TYPE == 1

  /**
   * Produce the next batch of items and place them in the batch buffer.
   * Implicitly, the first call  of producNext() initializes the iterator and
   * allocates resources (main memory, file descriptors, etc.).
   *
   * @param stateBLock
   */
  virtual void produceNext(PlanState& planState) const = 0;

  /**
   * Static Method: Retreives the next item from the batch buffer of the given
   * iterator and returns it to the caller. If all the items from the iterator's
   * batch buffer have been consumed already, then it makes the iterator produce
   * its next batch of results and retrieves the 1st item from this new batch.
   */
  static store::Item_t consumeNext(
        store::Item_t& result,
        const PlanIterator* iter,
        PlanState& planState)
  {
    try
    {
      // use the given iterator's planstate to access it's batch
      PlanIteratorState* lState =
      StateTraitsImpl<PlanIteratorState>::getState(planState, iter->getStateOffset());

      if ( lState->theCurrItem == ZORBA_BATCHING_BATCHSIZE )
      {
        iter->produceNext(planState);
        lState->theCurrItem = 0;
      }
    }
    catch(ZorbaException& e)
    {
      if(loc != NULL)
      {
        set_source(e, loc);
        throw;
      }
    }

    return lState->theBatch[lState->theCurrItem++];
  }


#else // ZORBA_BATCHING_TYPE

  /**
   * Produce the next item and return it to the caller. Implicitly, the first
   * call of 'producNext' initializes the iterator and allocates resources
   * (main memory, file descriptors, etc.).
   *
   * @param stateBLock
   */
  virtual bool produceNext(store::Item_t& handle, PlanState& planState) const = 0;

  /**
   * Static Method: Makes the given iterator produce its next result and returns
   * that result to the caller.
   */
#ifndef NDEBUG
  static bool consumeNext(
        store::Item_t& result,
        const PlanIterator* iter,
        PlanState& planState);
#else
  static bool consumeNext(
        store::Item_t& result,
        const PlanIterator* iter,
        PlanState& planState)
  {
    if (planState.theHasToQuit)
    {
      // Quit the execution
      throw FlowCtlException(FlowCtlException::INTERRUPT);
    }

    return iter->produceNext(result, planState);
  }
#endif

#endif // ZORBA_BATCHING_TYPE
};


/*******************************************************************************
  Class to implement batching
********************************************************************************/
template <class IterType>
class Batcher: public PlanIterator
{
public:
  SERIALIZABLE_CLASS_NO_FACTORY(Batcher)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(Batcher, PlanIterator)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (PlanIterator*)this);
  }

public:
  Batcher(const Batcher<IterType>& b)  : PlanIterator(b) {}

  Batcher(static_context* sctx, const QueryLoc& loc) : PlanIterator(sctx, loc) {}

  ~Batcher() {}


#if ZORBA_BATCHING_TYPE == 1

  void produceNext(PlanState& planState) const
  {
    PlanIteratorState* lState =
    StateTraitsImpl<PlanIteratorState>::getState(planState, stateOffset);
#ifndef NDEBUG
    ZORBA_ASSERT(lState->theIsOpened);
#endif
    bool more;
    uint32_t i = 0;
    do
    {
      // In general, to compute this iterator's next result, nextImpl() will
      // call consumeNext() on one or more of this iterator's child iterators.
      more = static_cast<const IterType*>(this)->nextImpl(lState->theBatch[i], planState);
    }
    while ( more && ++i < ZORBA_BATCHING_BATCHSIZE );
  }

#else

  bool produceNext(store::Item_t& result, PlanState& planState) const
  {
#ifndef NDEBUG
    PlanIteratorState* lState =
    StateTraitsImpl<PlanIteratorState>::getState(planState, theStateOffset);
    ZORBA_ASSERT(lState->theIsOpened);
#endif
    return static_cast<const IterType*>(this)->nextImpl(result, planState);
  }

#endif // ZORBA_BATCHING_TYPE

  void open(PlanState& planState, uint32_t& offset)
  {
    static_cast<IterType*>(this)->openImpl(planState, offset);
#ifndef NDEBUG
    // do this after openImpl because the state is created there
    PlanIteratorState* lState =
    StateTraitsImpl<PlanIteratorState>::getState(planState, theStateOffset);
    ZORBA_ASSERT( ! lState->theIsOpened ); // don't call open twice
    lState->theIsOpened = true;
#endif
  }

  void reset(PlanState& planState) const
  {
#ifndef NDEBUG
    PlanIteratorState* lState =
    StateTraitsImpl<PlanIteratorState>::getState(planState, theStateOffset);
    ZORBA_ASSERT( lState->theIsOpened );
#endif
    static_cast<const IterType*>(this)->resetImpl(planState);
  }

  void close(PlanState& planState)
  {
#ifndef NDEBUG
    PlanIteratorState* lState =
    StateTraitsImpl<PlanIteratorState>::getState(planState, theStateOffset);
    static_cast<IterType*>(this)->closeImpl(planState);
    lState->theIsOpened = false;
#else
    static_cast<IterType*>(this)->closeImpl(planState);
#endif
  }

  inline bool nextImpl(store::Item_t& result, PlanState& planState) const;

  inline void openImpl(PlanState& planState, uint32_t& offset) const;

  inline void resetImpl(PlanState& planState) const;

  inline void closeImpl(PlanState& planState);
};


} /* namespace zorba */

#endif  /* ZORBA_ITERATOR_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
