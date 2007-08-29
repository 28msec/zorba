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
 * @file runtime/batching.h
 *
 */
#ifndef XQP_BATCHING_H
#define XQP_BATCHING_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "parser/location.hh"
#include "parser/indent.h"

#include "utf8/xqpString.h"

#include <assert.h>
#include <iostream>

// Info: Forcing inlining a function in g++: item_t next() __attribute__((always_inline)) {...}

//0 = NO_BATCHING, 1 = SIMPLE_BATCHING, 2 = SUPER_BATCHING
#define BATCHING_TYPE 0

#define IT_INDENT			indent[++iteratorTreeDepth % 30]
#define IT_DEPTH			indent[iteratorTreeDepth % 30]
#define IT_OUTDENT		indent[iteratorTreeDepth-- % 30]

/**
 * This is a dummy class just because of compatibility issues.
 * It can be removed when all the code is cleaned up
 * 
 */

namespace xqp {

	extern int iteratorTreeDepth;
	
class OldIterator : public rcobject {
protected:
	bool open_b;

public:

	OldIterator();
	OldIterator(const OldIterator& it);
	~OldIterator();

	void open();
	void close();
	bool isOpen() const;
	virtual bool done() const;

protected:
	// dispatch to concrete classes
	virtual void _open() {
	}
	virtual item_t _next() {
		return NULL;
	}
	virtual void _close() {
	}
};

#if BATCHING_TYPE==0

#define STACK_INIT() switch (current_line) { case 0:
#define STACK_PUSH(x) do { current_line = __LINE__; return x; case __LINE__:; } while (0)
#define STACK_END() } return NULL;

class item;
class node;
class qname;
class zorba;

class BasicIterator : public OldIterator
{
protected:

	// Line Info for Duff's device
	int current_line;
	zorba *zorp;
public:
	yy::location loc;

public:
	BasicIterator(yy::location _loc);
	BasicIterator(const BasicIterator& it);
	~BasicIterator();

public:

	/**
	 * This is the wrapper which works for any kind of batching
	 */
	item_t next();

	/** Produces an output item of the iterator. Implicitly, the first call 
	 * of 'producNext' initializes the iterator and allocates resources 
	 * (main memory, file descriptors, etc.). 
	 */
	virtual item_t produceNext();

	/** 
	 * Restarts the iterator so that the next 'produceNext' call will start 
	 * again from the beginning (should not release any resources). 
	 */
	virtual void reset();

	/** 
	 * Releases all resources of the iterator 
	 */
	virtual void releaseResources();

	std::ostream& show(std::ostream&);

protected:
	inline void resetChild(iterator_t& subIterator) {
		subIterator->reset();
	}

	inline item_t consumeNext(iterator_t& subIter) {
		return subIter->produceNext();
	}

	inline void releaseChildResources(iterator_t& subIterator) {
		subIterator->releaseResources();
	}

	virtual std::ostream& _show(std::ostream& os) {
		return os;
	}
};

template <class IterType>
class Batcher: public BasicIterator {
public:
	Batcher(const Batcher<IterType>&);
	Batcher(yy::location _loc) : BasicIterator(_loc) {}
	~Batcher() {}

public:
	/**
	 * This method should be abstract. Only because of compatibility issues we implemented it
	 */
	item_t produceNext() {
		return static_cast<IterType*>(this)->nextImpl();
	}

	void reset() {
		this->current_line = 0;
		static_cast<IterType*>(this)->resetImpl();
	}

	void releaseResources() {
		static_cast<IterType*>(this)->releaseResourcesImpl();
	}

public:
	inline item_t nextImpl();
	inline void resetImpl();
	inline void releaseResourcesImpl();
};

#elif BATCHING_TYPE==1

#define STACK_INIT() switch (current_line) { case 0:
#define STACK_PUSH(x) do { current_line = __LINE__; return x; case __LINE__:; } while (0)
#define STACK_END() } return NULL;

#define BATCHSIZE 50

class item;
class node;
class qname;
class zorba;

class BasicIterator : public OldIterator {
protected:
	// Line Info for Duff's device
	int current_line;
	zorba *zorp;

public:
	yy::location loc;
	int cItem;
	item_t batch [BATCHSIZE];

public:
	//daniel BasicIterator() : zorp(NULL), open_b(false) {}
	BasicIterator(yy::location _loc);
	BasicIterator(const BasicIterator& it);
	~BasicIterator();

public:
	// inline base logic


	/**
	 * This method should be abstract. Only because of compatibility issues we implemented it
	 */
	virtual void produceNext();

	virtual void reset();

	virtual void releaseResources();

	/**
	 * This is the wrapper which works for any kind of batching
	 */
	item_t next();

	std::ostream& show(std::ostream&);

protected:
	inline void resetChild(iterator_t& subIterator){
		subIterator->reset();
	}
	
	inline item_t consumeNext(iterator_t& subIter) {
		if (subIter->cItem == BATCHSIZE) {
			subIter->produceNext();
			subIter->cItem = 0;
		}
		return subIter->batch[subIter->cItem++];
	}
	
	inline void releaseChildResources(iterator_t& subIterator){
		subIterator->releaseResources();
	}

	virtual std::ostream& _show(std::ostream&) const = 0;
};

template<class IterType> class Batcher : public BasicIterator {
public:
	Batcher(const Batcher<IterType>&);
	Batcher(yy::location _loc) :
		BasicIterator(_loc) {
	}
	~Batcher() {
	}

public:
	void produceNext() {
		int i = 0;
		batch[0] = static_cast<IterType*>(this)->nextImpl();
		while (i < BATCHSIZE && batch[i] != NULL) {
			i++;
			batch[i] = static_cast<IterType*>(this)->nextImpl();
		}
	}

	void reset() {
		this->current_line = 0;
		static_cast<IterType*>(this)->resetImpl();
	}

	void releaseResources() {
		this->current_line = 0;
		static_cast<IterType*>(this)->releaseResourcesImpl();
	}

public:
	inline item_t nextImpl();
	inline void resetImpl();
	inline void releaseResourcesImpl();
};

#endif //Batching Selection end

} /* namespace xqp */

#endif	/* XQP_ITEM_ITERATOR_H */

