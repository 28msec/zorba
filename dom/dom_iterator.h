/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: dom_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_DOM_ITERATOR_H
#define XQP_DOM_ITERATOR_H

#include "runtime/item_iterator.h"
#include "util/rchandle.h"

#include <string>
#include <vector>

namespace xqp {

class context;
class dom_item;
class dom_stringValue;
class dom_boolValue;
class dom_doubleValue;
class dom_intValue;
class dom_longValue;


class dom_iterator : public item_iterator
{
public:
	dom_iterator() {}
	dom_iterator(const dom_iterator&) {}
	virtual dom_iterator& operator=(const dom_iterator&);
	virtual ~dom_iterator() {}

public:	// abstract iterator interface
	virtual void open() { }
	virtual void close() { }
	virtual item* next(uint32_t delta = 1) { return NULL; }
	virtual item* peek() const { return NULL; }
	virtual bool done() const { return true; }

public:	// C++ interface
	item* operator*() const { return NULL; }
	dom_iterator& operator++();
	dom_iterator operator++(int);

public:
	std::string string_value();

};



class dom_singleton_iterator : public dom_iterator
{
protected:
	dom_item* i_p;
	bool done_b;

public:	// abstract iterator interface
	void open() { }
	void close() { done_b = false; }
	dom_item* next(uint32_t delta=1) { done_b = true; return NULL; }
	dom_item* peek() const { return i_p; }
	bool done() const { return done_b; }

public:	// C++ interface
	dom_item* operator*() const { return i_p; }
	dom_singleton_iterator& operator++() { done_b = true; return *this; }
	dom_singleton_iterator operator++(int)
		{ dom_singleton_iterator result = *this; done_b = true; return result; }

public:	// ctor,dtor
	dom_singleton_iterator(dom_item*);
	dom_singleton_iterator(const std::string&);
	dom_singleton_iterator(const dom_singleton_iterator&);
	dom_singleton_iterator& operator=(const dom_singleton_iterator&);
	~dom_singleton_iterator() {}

};


}	/* namespace xqp */
#endif	/* XQP_DOM_ITERATOR_H */

