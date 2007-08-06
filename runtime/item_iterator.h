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

class basic_iterator : public rcobject
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
	//daniel basic_iterator() : zorp(NULL), open_b(false) {}
	basic_iterator(yy::location _loc);
	basic_iterator(const basic_iterator& it);
	virtual ~basic_iterator();

public:		// inline base logic

	void open();

	item_t next(); 
	// Info: Forcing inlining a function in g++: item_t next() __attribute__((always_inline)) {...}
	
	void close();
	std::ostream& show(std::ostream&);

	
	bool is_open() const;

	virtual bool done() const = 0;

protected:	// dispatch to concrete classes
	virtual void	 _open() = 0;
	virtual item_t _next() = 0;
	virtual void	 _close() = 0;

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

class singleton_iterator : public basic_iterator
{
protected:
	rchandle<item> i_h;
	bool is_done;

public:
	singleton_iterator(yy::location loc, item* _i_p) : 
												basic_iterator( loc),
												i_h(_i_p), is_done (false) {}
	singleton_iterator(const singleton_iterator& it) : basic_iterator (it), i_h(it.i_h),
																										is_done(it.is_done) 
																										{}
	~singleton_iterator() { }

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
	singleton_iterator& operator=(const singleton_iterator& it)
		{ i_h = it.i_h; 
			loc = it.loc;
			return *this; }

};

// FIXME No expressions in iterators!!
class var_iterator : public singleton_iterator {
protected:
	string s_h;
	
public:
	var_iterator(string s_p, yy::location loc) : 
							singleton_iterator(loc,NULL), 
							s_h(s_p){}
	~var_iterator(){
		
	}
	
public:		// variable binding
	void bind(item_t _i_h) { i_h = _i_h; }
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
	ref_iterator(iterator_t _it,yy::location loc) : 
										basic_iterator(loc),
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

class map_iterator : public basic_iterator
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
		basic_iterator(loc),
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

