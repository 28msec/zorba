/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "util/rchandle.h"
#include "values/primitive_values.h"

namespace xqp {

class item;
class node;
class qname;
class dynamic_context;

class item_iterator : public rcobject
{
protected:
  dynamic_context* dctx_p;

public:
	item_iterator() : dctx_p(NULL) {}
	item_iterator(dynamic_context* _dctx_p) : dctx_p(_dctx_p) {}
	item_iterator(const item_iterator& it) : dctx_p(it.dctx_p) {}
	virtual ~item_iterator() {}

public:	// iterator interface
	virtual void open() = 0;
	virtual void close() = 0;
	virtual const item& next(uint32_t delta = 1) = 0;
	virtual const item& peek() const = 0;
	virtual bool done() const = 0;

public:	// C++ interface
	virtual const item& operator*() const = 0;
	virtual item_iterator& operator++() = 0;
	//virtual item_iterator& operator=(const item_iterator&) = 0;

/*
public:		// treat as operators
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

};


class item_const_iterator : public rcobject
{
public:
	item_const_iterator() {}
	item_const_iterator(const item_const_iterator& it) {}
	virtual ~item_const_iterator() {}

public:	// iterator interface
	virtual void open() = 0;
	virtual void close() = 0;
	virtual item& next(uint32_t delta = 1) = 0;
	virtual item& peek() const = 0;
	virtual bool done() const = 0;
	virtual void rewind() = 0;

public:	// C++ interface
	virtual item* operator*() const = 0;
	virtual item_const_iterator& operator++() = 0;
	//virtual item_const_iterator& operator=(const item_const_iterator&);

};


class item_singleton : public item_iterator
{
protected:
	const item* i_p;
	bool done_b;

public:
	item_singleton(
		dynamic_context* _dctx_p,
		const item* _i_p)
	:
		item_iterator(_dctx_p),
		i_p(_i_p),
		done_b(false)
	{ }

	item_singleton(
		const item_singleton& it)
	:
		item_iterator(it.dctx_p),
		i_p(it.i_p),
		done_b(false)
	{ }

	~item_singleton() { }

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1) { done_b = true; return *i_p; }
	const item& peek() const { return *i_p; }
	bool done() const { return done_b; }

public:	// C++ interface
	const item& operator*() const { return *i_p; }
	item_singleton& operator++() { done_b = true; return *this; }

	item_singleton& operator=(
		const item_singleton& it)
	{
		dctx_p = it.dctx_p;
		i_p    = it.i_p;
		done_b = it.done_b;
		return *this;
	}

};


class node_singleton : public item_iterator
{
protected:
	const node* n_p;
	bool done_b;

public:
	node_singleton(
		dynamic_context* _dctx_p,
		const node* _n_p)
	:
		item_iterator(_dctx_p),
		n_p(_n_p),
		done_b(false)
	{ }

	node_singleton(
		const node_singleton& it)
	:
		item_iterator(it.dctx_p),
		n_p(it.n_p),
		done_b(false)
	{ }

	~node_singleton() { }

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1);
	const item& peek() const;
	bool done() const { return done_b; }

public:	// C++ interface
	const item& operator*() const;

	node_singleton& operator++()
	{
		done_b = true;
		return *this;
	}

	node_singleton& operator=(
		const node_singleton& it)
	{
		dctx_p = it.dctx_p;
		n_p    = it.n_p;
		done_b = it.done_b;
		return *this;
	}

};


template<class T>
class singleton_iterator : public item_iterator
{
protected:
	T& val;
	bool done_b;

public:
	singleton_iterator(
		dynamic_context* _dctx_p,
		T _val)
	:
		item_iterator(_dctx_p),
		val(_val),
		done_b(false)
	{ }

	singleton_iterator(
		const singleton_iterator& it)
	:
		item_iterator(it.dctx_p),
		val(it.val),
		done_b(false)
	{ }

	~singleton_iterator() {}

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1) { done_b = true; return val; }
	const item& peek() const { return val; }
	bool done() const { return done_b; }

public:	// C++ interface
	const item& operator*() const { return val; }
	singleton_iterator& operator++() { done_b = true; return *this; }

	singleton_iterator& operator=(const singleton_iterator& it)
	{
		dctx_p = it.dctx_p;
		val = it.val;
		done_b = it.done_b;
	}

};

typedef singleton_iterator<qname> qname_singleton;
typedef singleton_iterator<numericValue> numeric_singleton;
typedef singleton_iterator<stringValue> string_singleton;
typedef singleton_iterator<timeValue> time_singleton;
typedef singleton_iterator<binaryValue> binary_singleton;


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

