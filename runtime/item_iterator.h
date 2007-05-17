/* -*- mode: c++; indent-tabs-mode: nil -*- *
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
#include <iostream>

namespace xqp {

class item;
class node;
class qname;
class zorba;

class item_iterator : public rcobject
{
protected:
 	zorba* zorp;

public:
	item_iterator() : zorp(NULL) {}
	item_iterator(zorba* _zorp) : zorp(_zorp) {}
	item_iterator(const item_iterator& it) : zorp(it.zorp) {}
	virtual ~item_iterator() {}

public:	// iterator interface
	virtual void open() = 0;
	virtual void close() = 0;
	virtual item_t next(uint32_t delta = 1) = 0;
	virtual item_t peek() const = 0;
	virtual bool done() const = 0;

public:	// C++ interface
	virtual item_t operator*() const = 0;
	virtual item_iterator& operator++() = 0;

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



class singleton_iterator : public item_iterator
{
protected:
	rchandle<item> i_h;

public:
	singleton_iterator(item* _i_p) : i_h(_i_p) {}
	singleton_iterator(const singleton_iterator& it) : i_h(it.i_h) {}
	~singleton_iterator() { }

public:	// iterator interface
	void open() {}
	void close() {}
	item_t next(uint32_t delta = 1)
		{ item_t p = i_h; i_h = NULL; return p; }
	item_t peek() const { return i_h; }
	bool done() const { return (i_h==NULL); }

public:	// C++ interface
	item_t operator*() const { return i_h; }

	singleton_iterator& operator++()
		{ i_h = NULL; return *this; }

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

public:	// C++ interface
	item_t operator*() const
		{ return val; }

	singleton_iterator& operator++()
		{ done_b = true; return *this; }

	singleton_iterator& operator=(const singleton_iterator& it)
		{ val = it.val; done_b = it.done_b; }

};
*/


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

