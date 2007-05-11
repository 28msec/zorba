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
#include "util/tracer.h"
#include <iostream>

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



class item_const_iterator : public item_iterator
{
public:
	item_const_iterator() {}
	item_const_iterator(const item_const_iterator& it) {}
	virtual ~item_const_iterator() {}

public:	// iterator interface
	virtual void open() = 0;
	virtual void close() = 0;
	virtual const item& next(uint32_t delta = 1) = 0;
	virtual const item& peek() const = 0;
	virtual bool done() const = 0;

public:	// C++ interface
	virtual const item& operator*() const = 0;
	virtual item_const_iterator& operator++() = 0;
	//virtual item_const_iterator& operator=(const item_const_iterator&);

};



class item_singleton : public item_const_iterator
{
protected:
	const item* i_p;

public:
	item_singleton(const item* _i_p) : i_p(_i_p) {}
	item_singleton(const item_singleton& it) : i_p(it.i_p) {}
	~item_singleton() { }

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1) 
		{ const item* p = i_p; i_p = NULL; return *p; }
	const item& peek() const { return *i_p; }
	bool done() const { return (i_p==NULL); }

public:	// C++ interface
	const item& operator*() const { return *i_p; }
	item_singleton& operator++() { i_p = NULL; return *this; }
	item_singleton& operator=(const item_singleton& it)
		{ i_p = it.i_p; return *this; }

};


class qname_singleton : public item_const_iterator
{
protected:
	const qname* qn_p;

public:
	qname_singleton(const qname* _qn_p) : qn_p(_qn_p) {}
	qname_singleton(const qname_singleton& it) : qn_p(it.qn_p) {}
	~qname_singleton() { }

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1);
	const item& peek() const;
	bool done() const { return (qn_p==NULL); }

public:	// C++ interface
	const item& operator*() const;
	qname_singleton& operator++() { qn_p=NULL; return *this; }
	qname_singleton& operator=(const qname_singleton& it);

};


class node_singleton : public item_const_iterator
{
protected:
	const node* n_p;

public:
	node_singleton(const node* _n_p) : n_p(_n_p) {} 
	node_singleton(const node_singleton& it) : n_p(it.n_p) {}
	~node_singleton() { }

public:	// iterator interface
	void open() {}
	void close() {}
	const item& next(uint32_t delta = 1);
	const item& peek() const;
	bool done() const { return n_p==NULL; }

public:	// C++ interface
	const item& operator*() const;
	node_singleton& operator++() { n_p = NULL; return *this; }
	node_singleton& operator=(const node_singleton& it)
		{ n_p = it.n_p; return *this; }

};


template<class T>
class singleton_iterator : public item_iterator
{
protected:
	const T& val;
	bool done_b;

public:
	singleton_iterator(const T& _val)
	: val(_val),
		done_b(false)
	{ }

	singleton_iterator(const singleton_iterator& it)
	: val(it.val),
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
	const item& operator*() const
		{ return val; }

	singleton_iterator& operator++()
		{ done_b = true; return *this; }

	singleton_iterator& operator=(const singleton_iterator& it)
		{ val = it.val; done_b = it.done_b; }

};


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

