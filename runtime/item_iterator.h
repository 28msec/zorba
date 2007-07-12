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

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

class item;
class node;
class qname;
class zorba;

class basic_iterator : public rcobject
{
protected:
 	zorba* zorp;
	bool open_b;

public:
	basic_iterator() : zorp(NULL), open_b(false) {}
	basic_iterator(zorba* _zorp) : zorp(_zorp), open_b(false) {}
	basic_iterator(const basic_iterator& it) : rcobject (), zorp(it.zorp), open_b(it.open_b) {}
	virtual ~basic_iterator() {}

public:		// inline base logic

	void open()
	{
		assert(!open_b);
		open_b = true;
		_open();
	}

	item_t next()
	{
		assert(open_b);
		return _next(); 
	}

	void close()
	{
		assert(open_b);
		open_b = false;
		_close();
	}

	bool is_open() const
	{
		return open_b;
	}

	virtual bool done() const = 0;

protected:	// dispatch to concrete classes
	virtual void	 _open() = 0;
	virtual item_t _next() = 0;
	virtual void	 _close() = 0;

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

class singleton_iterator : public basic_iterator
{
protected:
	rchandle<item> i_h;
	bool is_done;

public:
	singleton_iterator(item* _i_p) : i_h(_i_p), is_done (false) {}
	singleton_iterator(const singleton_iterator& it) : basic_iterator (it), i_h(it.i_h) {}
	~singleton_iterator() { }

public:		// iterator interface
	void _open() {}
	void _close() {}
	item_t _next() {
		bool was_done = is_done; is_done = true;
		return was_done ? NULL : i_h;
	}
	bool done() const { return is_done; }

public:		// variable binding
	void bind(item_t _i_h) { i_h = _i_h; }

public:
	singleton_iterator& operator=(const singleton_iterator& it)
		{ i_h = it.i_h; return *this; }

};



/*
template<class T>
class singleton_iterator : public item_iterator
{
protected:
	const T* val;
	bool done_b;

public:
	singleton_iterator(T _val) : val(_val), done_b(false) { }
	singleton_iterator(const singleton_iterator& it) : val(it.val), done_b(false) { }
	~singleton_iterator() {}

public:	// iterator interface
	void open() {}
	void close() {}
	item_t next(uint32_t delta = 1) { done_b = true; return val; }
	item_t peek() const { return val; }
	bool done() const { return done_b; }

public:
	singleton_iterator& operator=(const singleton_iterator& it)
		{ val = it.val; done_b = it.done_b; }

};
*/



/*_____________________________________________________________
|
|	let_var bindings
|______________________________________________________________*/

class ref_iterator : public basic_iterator
{
private:
	iterator_t it;

public:
	ref_iterator(iterator_t _it) : it(_it) {}

public:
	void _open() { it->open();  }
	item_t _next() { return it->next(); }
	void _close() { it->close(); }
	bool done() const { return it->done(); }
	void bind(iterator_t _it) { it = _it;}

};



/*_____________________________________________________________
|
|	for $x in  _input_  return  _expr_
|______________________________________________________________*/

class map_iterator : public basic_iterator
{
private:
	enum state {
		outer,
		inner
	};

	iterator_t theInput;
	iterator_t theExpr;
	std::vector<singleton_t> varv;
	enum state theState;

public:
	map_iterator(
		iterator_t _input,
		iterator_t _expr,
		std::vector<singleton_t> _varv)
	:
		theInput(_input),
		theExpr(_expr),
		varv(_varv),
		theState(outer)
	{}

	~map_iterator() {}

public:
	void _open()
	{
		theState = outer;
		theInput->open();
	}

	void _close()
	{
		theInput->close();
		if (theState!=outer) theExpr->close();
	} 

	item_t _next()
	{
		basic_iterator& input = *theInput;
		basic_iterator& expr = *theExpr;

		while (true) {
			if (theState==outer) {
				item_t i_h = input.next();
				if (i_h==NULL) return NULL;
				vector<singleton_t>::const_iterator itv = varv.begin();
				for (; itv!=varv.end(); ++itv) { (*itv)->bind(i_h); }
				expr.open();
				theState = inner;
			}
			item_t r_h = expr.next();
			if (r_h != NULL) return r_h;
			expr.close();
			theState = outer;
		}
	}

	bool done() const { return theInput->done(); }

};


}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

