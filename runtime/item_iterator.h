/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "context/common.h"
#include "util/rchandle.h"
#include "util/tracer.h"
#include "parser/location.hh"
#include "parser/indent.h"
#include "batching.h"

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
class SingletonIterator : public Batcher<SingletonIterator>
{
protected:
	rchandle<item> i_h;
	bool is_done;

public:
	SingletonIterator(yy::location loc, item* _i_p) : 
												Batcher<SingletonIterator> (loc),
												i_h(_i_p), is_done (false) {}
	SingletonIterator(const SingletonIterator& it) : Batcher<SingletonIterator>(it), i_h(it.i_h),
																										is_done(it.is_done) 
																										{}
	~SingletonIterator() { }
	
public:
	item_t nextImpl() {
		bool was_done = is_done; is_done = true;
		return was_done ? NULL : i_h;
	}
	void resetImpl() {
		this->is_done = false;
	}
	void releaseResourcesImpl(){}

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

// class RefIterator : public BasicIterator
// {
// private:
// 	iterator_t it;
// 
// public:
// 	RefIterator(iterator_t _it,yy::location loc) : 
// 										BasicIterator(loc),
// 										it(_it) {}
// 
// public:
// 	void _open() { it->open();  }
// 	item_t _next() { return it->next(); }
// 	void _close() { it->close(); }
// 	std::ostream&  _show(std::ostream& os) const {return os;}
// 	bool done() const { return it->done(); }
// 	void bind(iterator_t _it) { it = _it;}
// 
// };



/*_____________________________________________________________
|
|	for $x in  _input_  return  _expr_
|______________________________________________________________*/
class MapIterator : public Batcher<MapIterator>
{
private:
// 	enum state {
// 		outer,
// 		inner
// 	};

	iterator_t theInput;
	iterator_t theExpr;
	std::vector<var_iter_t> varv;
// 	enum state theState;

public:
	MapIterator(
		yy::location loc,
		iterator_t _input,
		iterator_t _expr,
		std::vector<var_iter_t> _varv)
	:
		Batcher<MapIterator>(loc),
		theInput(_input),
		theExpr(_expr),
		varv(_varv)
	{}

	~MapIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
// 	void _open();
// 	void _close();
	std::ostream&  _show(std::ostream& os) const;
// 	bool done() const;

}; 


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

