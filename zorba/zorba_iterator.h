
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

namespace xqp {


class funcall_iterator : public item_iterator
{
protected:
	std::vector<itref_t> arg_list;

public:	// iterator interface
	virtual void open() = 0;
	virtual void close() = 0;
	virtual item* next(uint32_t delta = 1) = 0;
	virtual item* peek() const = 0;
	virtual bool done() const = 0;
	virtual void rewind() = 0;

public:	// ctor,dtor
	funcall_iterator(dynamic_context* dcp) : item_iterator(dcp) {}
	virtual ~funcall_iterator() {}

public:	// C++ interface
	virtual item* operator*() const = 0;
	virtual funcall_iterator& operator++() = 0;
	virtual funcall_iterator operator++(int) = 0;

};


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
	void rewind() { done_b = false; }

public:	// C++ interface
	item* operator*() const { return i_p; }
	singleton_iterator& operator++() { done_b = true; return *this; }

public:	// ctor,dtor
	singleton_iterator(item*);
	singleton_iterator(abstract_value_factory*, const std::string&);
	singleton_iterator(abstract_value_factory*, bool);
	singleton_iterator(abstract_value_factory*, double);
	singleton_iterator(abstract_value_factory*, int);
	singleton_iterator(abstract_value_factory*, long);
	singleton_iterator(const singleton_iterator&);
	singleton_iterator& operator=(const singleton_iterator&);
	~singleton_iterator() {}

};




} /* namespace xqp */
#endif /* XQP_ZORBA_ITERATOR_H */

