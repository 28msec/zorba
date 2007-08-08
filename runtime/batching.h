#ifndef XQP_BATCHING_H
#define XQP_BATCHING_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "parser/location.hh"
#include "parser/indent.h"

#include <assert.h>
#include <iostream>


// Definitions for Duff's device
#define STACK_INIT() switch (current_line) { case 0:
#define STACK_PUSH(x) do { current_line = __LINE__; return x; case __LINE__:; } while (0)
#define STACK_END() } return NULL;

namespace xqp {

class item;
class node;
class qname;
class zorba;

class BasicIterator : public rcobject
{
protected:
	bool open_b;
	// Line Info for Duff's device
	int current_line;

	//daniel
	zorba	*zorp;
public:
	yy::location	loc;

public:
	//daniel BasicIterator() : zorp(NULL), open_b(false) {}
	BasicIterator(yy::location _loc);
	BasicIterator(const BasicIterator& it);
	~BasicIterator();

public:		// inline base logic

	void open();
	void close();
	bool isOpen() const;
	virtual bool done() const;

	item_t next(); 
	// Info: Forcing inlining a function in g++: item_t next() __attribute__((always_inline)) {...}
	
	/** Produces an output item of the iterator. Implicitly, the first call 
	 * of 'producNext' initializes the iterator and allocates resources 
	 * (main memory, file descriptors, etc.). 
	 */
	virtual item_t produceNext()  ;
	
	/** 
	 * Restarts the iterator so that the next 'produceNext' call will start 
	 * again from the beginning (should not release any resources). 
	 */
	virtual void reset() ;
	
	/** 
	 * Releases all resources of the iterator 
	 */
	virtual void releaseResources() ;
	
	
	std::ostream& show(std::ostream&);

protected:	// dispatch to concrete classes
	virtual void	 _open(){}
	virtual item_t _next(){return NULL;}
	virtual void	 _close(){}

	virtual std::ostream&  _show(std::ostream&) const = 0;
};


template <class IterType>
class Batcher: public BasicIterator {
public:
	Batcher(const Batcher<IterType>&);
	Batcher(yy::location _loc) : BasicIterator(_loc) { }
	~Batcher(){}

public:
	item_t produceNext() {
		return static_cast<IterType*>(this)->nextImpl();
	}


	void reset() {
		this->current_line = 0;
		static_cast<IterType*>(this)->resetImpl();
	}

	void freeResources() {
		static_cast<IterType*>(this)->freeResourcesImpl();
	}
	
protected:	
	item_t consumeNext(iterator_t& subIterator) {
		return subIterator->produceNext();
	}
	
	
	void resetChild(iterator_t& subIterator) {
		subIterator->reset();
	}
	
	
	void releaseChildResources(iterator_t& subIterator) {
		subIterator->releaseResources();
	}
	
// 	item_t produceNext();
// 	void reset();
// 	void freeResources();
// 	
// 	item_t consumeNext(iterator_t&);
// 	void resetChild(iterator_t&);
// 	void releaseChildResources(iterator_t&);

public:
	virtual item_t nextImpl() = 0;
	virtual void resetImpl() = 0;
	virtual void releaseResourcesImpl() = 0;
};

}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */
