/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Tim Kraska (tim.kraska@inf.ethz.ch), David Graf (dagraf@inf.ethz.ch)
 * @file runtime/core/batching.h
 *
 */
#ifndef XQP_ITERATOR_H
#define XQP_ITERATOR_H

#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "store/api/item.h"

#include "util/utf8/xqpString.h"

#include <assert.h>
#include <iostream>

// Info: Forcing inlining a function in g++: Item_t next() __attribute__((always_inline)) {...}

//0 = NO_BATCHING, 1 = SIMPLE_BATCHING, 2 = SUPER_BATCHING
#define BATCHING_TYPE 0

#define IT_INDENT			std::string(++iteratorTreeDepth, ' ')
#define IT_DEPTH			std::string(iteratorTreeDepth, ' ')
#define IT_OUTDENT		    std::string(iteratorTreeDepth--, ' ')

// TODO These Macros have to be deleted
#define STACK_INIT() switch (this->current_line) { case 0:
#define STACK_PUSH(x) do { this->current_line = __LINE__; return x; case __LINE__:; } while (0)
#define STACK_END() } return NULL;

/** Macros to automate Duff's Device and separation of code and execution 
	* STACK_INIT:	- initializes Duff's Device and gets the state of the
	*								current iterator from the state block
	* STACK_PUSH: - returns the passed item and saves the current position
	*								of the next functions
	* STACK_END:	- ends the execution of the next function
	* GET_STATE:	- specific function to load the state of the current iterator
	*								from the state block
	*/
#define STACK_INIT2(stateType, stateObject, planState) \
	GET_STATE(stateType, stateObject, planState); \
	switch (stateObject->getDuffsLine()) { case 0: \
	stateObject->init()
#define STACK_PUSH2(x, stateObject) do { stateObject->setDuffsLine(__LINE__); return x; case __LINE__:; } while (0)
#define STACK_END2() } return NULL
#define GET_STATE(stateType, stateObject, planState) \
	stateObject = reinterpret_cast<stateType*>(planState.block + this->stateOffset)

namespace xqp {

class Item;
typedef rchandle<Item> Item_t;

class PlanIterator;
class node;
class zorba;

typedef rchandle<PlanIterator> Iterator_t;

extern int32_t iteratorTreeDepth;

class PlanState
{
public:
	int8_t* block;

	PlanState(int32_t blockSize);
	~PlanState();
};


/**
  * Base class of all iterators.
	*/
class PlanIterator : public rcobject
{
protected:
	/** offset of the state of the current iterator */
	int32_t stateOffset;
	
	// TODO must be deleted. Is saved in state object.
	int32_t current_line;
	
	// TODO what's that for?
	zorba *zorp;
public:
	yy::location loc;
	
#if BATCHING_TYPE == 1	
	int32_t cItem;
	Item_t batch [BATCHSIZE];
#endif

public:
	PlanIterator(yy::location _loc);
	PlanIterator(const PlanIterator& it);
	virtual ~PlanIterator();

public:

	/** 
   * Produces an output item of the iterator. Implicitly, the first call 
	 * of 'producNext' initializes the iterator and allocates resources 
	 * (main memory, file descriptors, etc.). 
	 *
	 * @param stateBLock
	 *
	 * TODO must be pure virtual
	 */
	virtual Item_t produceNext(PlanState& planState);

	/** 
	 * Restarts the iterator so that the next 'produceNext' call will start 
	 * again from the beginning (should not release any resources).  
	 *
	 * @param stateBLock
	 *
	 * TODO must be pure virtual
	 */
	virtual void reset(PlanState& planState);

	/** 
	 * Releases all resources of the iterator  
	 *
	 * @param stateBLock
	 * 
	 * TODO must be pure virtual
	 */
	virtual void releaseResources(PlanState& planState);

	std::ostream& show(std::ostream&);
	
	/** Returns the size of the state which must be saved for the current iterator
		* on the state block
		*
		* TODO must be pure virtual
		*/
	virtual int32_t getStateSize();
	
	/** Returns the size of the state for the current iterator 
		* and all its sub-iterators.
		*
		* TODO must be pure virtual
		*/
	virtual int32_t getStateSizeOfSubtree();
	
	/** Sets the offset where the state of the iterator will be saved
		* on the state stack.
    *
		* TODO must be pure virtual
		*/
	virtual void setOffset(PlanState& planState, int32_t& offset);

protected:
	/** Root object of all iterator states */
	class PlanIteratorState {
	private:
		int32_t duffsLine;
	public:
		/** Initializes State Object for the current iterator.
			* All sub-states have it invoke the init resources of their parent 
			* to guarantee correct initialization.
			*/
		void init();

		/** Resets State Object for the current iterator.
			* All sub-states have it invoke the release reset of their parent 
			* to guarantee correct reset handling.
			*/
		void reset();

		/* Release resources is not needed in PlanIterator but might be need
		 * from Iterators. If so, they must be implemented there and invoked from
		 * releaseResourcesImpl from the corresponding iterator. If a state is a
		 * sub-class of a state which contains releaseResources, it has to 
		 * implement releaseResources too and has to invoke releaseResources
		 * from the parent.
		 */
		
		void setDuffsLine(int32_t);
		int32_t getDuffsLine();
	};

protected:
	inline void resetChild(Iterator_t& subIterator, PlanState& planState) {
		subIterator->reset(planState);
	}

#if BATCHING_TYPE == 1	
	inline Item_t consumeNext(Iterator_t& subIter, PlanState& planState) {
		if (subIter->cItem == BATCHSIZE) {
			subIter->produceNext(planState);
			subIter->cItem = 0;
		}
		return subIter->batch[subIter->cItem++];
	}
#else
	inline Item_t consumeNext(Iterator_t& subIter, PlanState& planState) {
		return subIter->produceNext(planState);
	}
#endif

	inline void releaseChildResources(Iterator_t& subIterator, PlanState& planState) {
		subIterator->releaseResources(planState);
	}

	virtual std::ostream& _show(std::ostream& os) const {
		return os;
	}
};


template <class IterType>
class Batcher: public PlanIterator {
public:
	Batcher(const Batcher<IterType>& b)  : PlanIterator(b) {}
	Batcher(yy::location _loc) : PlanIterator(_loc) {}
	~Batcher() {}

public:
#if BATCHING_TYPE == 1	
	void produceNext() {
		int32_t i = 0;
		batch[0] = static_cast<IterType*>(this)->nextImpl();
		while (i < BATCHSIZE && batch[i] != NULL) {
			i++;
			batch[i] = static_cast<IterType*>(this)->nextImpl();
		}
	}
#else
	Item_t produceNext(PlanState& planState) {
		return static_cast<IterType*>(this)->nextImpl(planState);
	}
#endif

	void reset(PlanState& planState) {
		this->current_line = 0;
		static_cast<IterType*>(this)->resetImpl(planState);
	}

	void releaseResources(PlanState& planState) {
		static_cast<IterType*>(this)->releaseResourcesImpl(planState);
	}

public:
	inline Item_t nextImpl(PlanState& planState);
	inline void resetImpl(PlanState& planState);
	inline void releaseResourcesImpl(PlanState& planState);
};


/** Wrapper to hide functionality like separation of code and execution, 
 * garabage collection, etc. during evaluation of an iterator tree.
 * 
 * This Wrapper can also be used to collect the items of an iterator is
 * belongs alread to another IteratorWrapper, resp. which belongs already
 * to a state block.
 */
class IteratorWrapper {
private:
	bool theAlienBlock;
	Iterator_t theIterator;
	PlanState* theStateBlock;
	
public:
	/** 
	 * Constructor for IteratorWrapper which is used to generate the results
	 * of a root operator.
	 * 
	 * @param iter root of evaluated iterator tree
	 */
	IteratorWrapper(Iterator_t& iter);
	
	/**
	 * Constructor for IteratorWrapper which is used to generate the results
	 * of an iterator which is not root => the state block handling, garbage
	 * collection, etc. is already made by another IteratorWrapper.
	 * 
	 * @param iter 
	 * @param planState 
	 */
	IteratorWrapper(Iterator_t& iter, PlanState& planState);
	
	/**
	 * Deconstructor.
	 */
	~IteratorWrapper();
	
	/** Returns the next item of the root iterator
		* @return item
		* FIXME must be adapted to batching
		*/
	Item_t next();
};

} /* namespace xqp */

#endif	/* XQP_ITERATOR_H */

