/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_ITERATOR_H
#define XQP_ZORBA_ITERATOR_H

#include "runtime/item_iterator.h"
#include <vector>

namespace xqp {

class value_factory;

class singleton_iterator : public item_iterator
{
protected:
	item* i_p;
	bool done_b;

public:	// iterator interface
	void open() { }
	void close() { done_b = false; }
	item* next(uint32_t delta=1) { done_b = true; return NULL; }
	item* peek() const { return i_p; }
	bool done() const { return done_b; }

public:	// C++ interface
	item* operator*() const { return i_p; }
	item_iterator& operator++() { done_b = true; return *this; }

public:	// ctor,dtor
	singleton_iterator(item*);
	singleton_iterator(const item*);
	singleton_iterator(value_factory*, const std::string&);
	singleton_iterator(value_factory*, bool);
	singleton_iterator(value_factory*, double);
	singleton_iterator(value_factory*, int);
	singleton_iterator(value_factory*, long);
	singleton_iterator(const singleton_iterator&);
	singleton_iterator& operator=(const singleton_iterator&);
	~singleton_iterator() {}

};


} /* namespace xqp */
#endif /* XQP_ZORBA_ITERATOR_H */

