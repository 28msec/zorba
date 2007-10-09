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
#ifndef XQP_BATCHING_H
#define XQP_BATCHING_H

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
#define STACK_INIT2(stateType, stateObject, stateBlock) \
	GET_STATE(stateType, stateObject, stateBlock); \
	switch (stateObject->getDuffsLine()) { case 0: \
	stateObject->init()
#define STACK_PUSH2(x, stateObject) do { stateObject->setDuffsLine(__LINE__); return x; case __LINE__:; } while (0)
#define STACK_END2() } return NULL
#define GET_STATE(stateType, stateObject, stateBlock) \
	stateObject = reinterpret_cast<stateType*>(stateBlock.block + this->stateOffset)

namespace xqp {

class Item;
typedef rchandle<Item> Item_t;

class BasicIterator;
class node;
class zorba;

typedef rchandle<BasicIterator> Iterator_t;

extern int32_t iteratorTreeDepth;

class IteratorTreeStateBlock
{
public:
	int8_t* block;

	IteratorTreeStateBlock(int32_t blockSize);
};

/** Base class of all iterators.
	*/
class BasicIterator : public rcobject
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
	BasicIterator(yy::location _loc);
	BasicIterator(const BasicIterator& it);
	virtual ~BasicIterator();

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
	virtual Item_t produceNext(IteratorTreeStateBlock& stateBlock);

	/** 
	 * Restarts the iterator so that the next 'produceNext' call will start 
	 * again from the beginning (should not release any resources).  
	 *
	 * @param stateBLock
	 *
	 * TODO must be pure virtual
	 */
	virtual void reset(IteratorTreeStateBlock& stateBlock);

	/** 
	 * Releases all resources of the iterator  
	 *
	 * @param stateBLock
	 * 
	 * TODO must be pure virtual
	 */
	virtual void releaseResources(IteratorTreeStateBlock& stateBlock);

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
		*/
	virtual void setOffset(int32_t& offset);

protected:
	/** Root object of all iterator states */
	class BasicIteratorState {
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

		/* Release resources is not needed in BasicIterator but might be need
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
	inline void resetChild(Iterator_t& subIterator, IteratorTreeStateBlock& stateBlock) {
		subIterator->reset(stateBlock);
	}

#if BATCHING_TYPE == 1	
	inline Item_t consumeNext(Iterator_t& subIter) {
		if (subIter->cItem == BATCHSIZE) {
			subIter->produceNext();
			subIter->cItem = 0;
		}
		return subIter->batch[subIter->cItem++];
	}
#else
	inline Item_t consumeNext(Iterator_t& subIter, IteratorTreeStateBlock& stateBlock) {
		return subIter->produceNext(stateBlock);
	}
#endif

	inline void releaseChildResources(Iterator_t& subIterator, IteratorTreeStateBlock& stateBlock) {
		subIterator->releaseResources(stateBlock);
	}

	virtual std::ostream& _show(std::ostream& os) const {
		return os;
	}
};


template <class IterType>
class Batcher: public BasicIterator {
public:
	Batcher(const Batcher<IterType>& b)  : BasicIterator(b) {}
	Batcher(yy::location _loc) : BasicIterator(_loc) {}
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
	Item_t produceNext(IteratorTreeStateBlock& stateBlock) {
		return static_cast<IterType*>(this)->nextImpl(stateBlock);
	}
#endif

	void reset(IteratorTreeStateBlock& stateBlock) {
		this->current_line = 0;
		static_cast<IterType*>(this)->resetImpl(stateBlock);
	}

	void releaseResources(IteratorTreeStateBlock& stateBlock) {
		static_cast<IterType*>(this)->releaseResourcesImpl(stateBlock);
	}

public:
	inline Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
	inline void resetImpl(IteratorTreeStateBlock& stateBlock);
	inline void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
};


/** Wrapper to hide functionality like separation of code and execution, 
	* garabage collection, etc. during evaluation of an iterator tree
	*/
class IteratorWrapper {
private:
	Iterator_t iterator;
	IteratorTreeStateBlock* stateBlock;
	
public:
	/** Concsturctor
		* @param iter root of evaluated iterator tree
		*/
	IteratorWrapper(Iterator_t& iter);
	~IteratorWrapper();
	
	/** Returns the next item of the root iterator
		* @return item
		* FIXME must be adapted to batching
		*/
	Item_t next();
};

} /* namespace xqp */

#endif	/* XQP_BATCHING_H */

