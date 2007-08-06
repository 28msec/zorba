/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

// Definitions for Duff's device
#define STACK_INIT() switch (current_line) { case 0:
#define STACK_PUSH(x) do { current_line = __LINE__; return x; case __LINE__:; } while (0)
#define STACK_END() } return NULL;

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "parser/location.hh"
#include "parser/indent.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

extern int iteratorTreeDepth;

#define IT_INDENT			indent[++iteratorTreeDepth % 30]
#define IT_DEPTH			indent[iteratorTreeDepth % 30]
#define IT_OUTDENT		indent[iteratorTreeDepth-- % 30]
	
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
	virtual ~BasicIterator();

public:		// inline base logic

	void open();
	void close();
	bool isOpen() const;
	virtual bool done() const = 0;

	item_t next(); 
	// Info: Forcing inlining a function in g++: item_t next() __attribute__((always_inline)) {...}
	
	/** Produces an output item of the iterator. Implicitly, the first call 
	 * of 'producNext' initializes the iterator and allocates resources 
	 * (main memory, file descriptors, etc.). 
	 */
	item_t produceNext();
	
	/** 
	 * Restarts the iterator so that the next 'produceNext' call will start 
	 * again from the beginning (should not release any resources). 
	 */
	void reset();
	
	/** 
	 * Releases all resources of the iterator 
	 */
	void releaseResources();
	
	/** 
	 * Consumes the next item from one of the child iterators of the iterator. 
	 */
	item_t consumeNext(iterator_t& subIterator);
	
	/** 
	 * Resets a child iterator 
	 */
	void resetChild(iterator_t& subIterator);
	
	/** 
	 * Releases all resources of a child iterator. 
	 */
	void releaseChildResources(iterator_t& subIterator);
	
	std::ostream& show(std::ostream&);

protected:	// dispatch to concrete classes
	virtual void	 _open() = 0;
	virtual item_t _next() = 0;
	virtual void	 _close() = 0;
	
	/** 
	 * Produces the next item;  implicitly initializes the iterator and allocates 
	 * resources (if any) at its first call (or after a releaseResourcesImpl).
	 */
	virtual item_t nextImpl_()/* = 0*/;
	
	/**
	 * Resets the iterator so that it restarts from the beginning.
	 */
	virtual void resetImpl_()/* = 0*/;
	
	/**
	 * Releases all the resources. 
	 */
	virtual void releaseResourcesImpl_()/* = 0*/;

	virtual std::ostream&  _show(std::ostream&) const = 0;
};



/*
public:		// "treat as" operators
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


/*_____________________________________________________________
|
|	literals and for_var bindings
|______________________________________________________________*/

class SingletonIterator : public BasicIterator
{
protected:
	rchandle<item> i_h;
	bool is_done;

public:
	SingletonIterator(yy::location loc, item* _i_p) : 
												BasicIterator( loc),
												i_h(_i_p), is_done (false) {}
	SingletonIterator(const SingletonIterator& it) : BasicIterator (it), i_h(it.i_h),
																										is_done(it.is_done) 
																										{}
	~SingletonIterator() { }
	
protected:
	item_t nextImpl_() {
		bool was_done = is_done; is_done = true;
		return was_done ? NULL : i_h;
	}
	void resetImpl_() {
		this->is_done = false;
	}
	void releaseResourcesImpl_(){}

public:		// iterator interface
	void _open() {}

	void _close() {
		this->is_done = false;
	}
	
	std::ostream&  _show(std::ostream& os)	const
	{
		return os;
	}
	
	item_t _next() {
		bool was_done = is_done; is_done = true;
		return was_done ? NULL : i_h;
	}

	
	
	bool done() const { return is_done; }

public:
	SingletonIterator& operator=(const SingletonIterator& it)
		{ i_h = it.i_h; 
			loc = it.loc;
			return *this; }

};

// FIXME No expressions in iterators!!
class var_iterator : public SingletonIterator {
protected:
	string s_h;
	
public:
	var_iterator(string s_p, yy::location loc) : 
							SingletonIterator(loc,NULL), 
							s_h(s_p){}
	~var_iterator(){
		
	}
	
public:		// variable binding
	void bind(item_t _i_h) { i_h = _i_h; }
};

/*
template<class T>
class SingletonIterator : public item_iterator
{
protected:
	const T* val;
	bool done_b;

public:
	SingletonIterator(T _val) : val(_val), done_b(false) { }
	SingletonIterator(const SingletonIterator& it) : val(it.val), done_b(false) { }
	~SingletonIterator() {}

public:	// iterator interface
	void open() {}
	void close() {}
	item_t next(uint32_t delta = 1) { done_b = true; return val; }
	item_t peek() const { return val; }
	bool done() const { return done_b; }

public:
	SingletonIterator& operator=(const SingletonIterator& it)
		{ val = it.val; done_b = it.done_b; }

};
*/



/*_____________________________________________________________
|
|	let_var bindings
|______________________________________________________________*/

class ref_iterator : public BasicIterator
{
private:
	iterator_t it;

public:
	ref_iterator(iterator_t _it,yy::location loc) : 
										BasicIterator(loc),
										it(_it) {}

public:
	void _open() { it->open();  }
	item_t _next() { return it->next(); }
	void _close() { it->close(); }
	std::ostream&  _show(std::ostream& os) const {return os;}
	bool done() const { return it->done(); }
	void bind(iterator_t _it) { it = _it;}

};



/*_____________________________________________________________
|
|	for $x in  _input_  return  _expr_
|______________________________________________________________*/

class map_iterator : public BasicIterator
{
private:
	enum state {
		outer,
		inner
	};

	iterator_t theInput;
	iterator_t theExpr;
	std::vector<var_iter_t> varv;
	enum state theState;

public:
	map_iterator(
		yy::location loc,
		iterator_t _input,
		iterator_t _expr,
		std::vector<var_iter_t> _varv)
	:
		BasicIterator(loc),
		theInput(_input),
		theExpr(_expr),
		varv(_varv),
		theState(outer)
	{}

	~map_iterator() {}

public:
	item_t _next();
	void _open();
	void _close();
	std::ostream&  _show(std::ostream& os) const;
	bool done() const;

}; 


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

