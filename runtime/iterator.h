/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITERATOR_H
#define XQP_ITERATOR_H

#include "abstract_iterator.h"

#include "../util/list.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <iostream>
#include <string>
#include <vector>

namespace xqp {

class context;
class item;
class xs_stringValue;
class xs_boolValue;
class xs_doubleValue;
class xs_intValue;
class xs_longValue;

class item_iterator : public abstract_iterator
{
protected:
  context* ctx_p;

public:
	item_iterator(context *);
	item_iterator(const item_iterator&);
	virtual item_iterator& operator=(const item_iterator&);
	virtual ~item_iterator() {}

public:	// abstract iterator interface
	virtual void open() { }
	virtual void close() { }
	virtual abstract_item* next(uint32_t delta = 1) { return NULL; }
	virtual abstract_item* peek() const { return NULL; }
	virtual bool done() const { return true; }
	virtual void rewind() { }

public:	// C++ interface
	item* operator*() const { return NULL; }
	item_iterator& operator++();

public:
	std::string string_value();

};



class item_const_iterator : public abstract_iterator
{
public:
	item_const_iterator();
	item_const_iterator(const item_const_iterator&);
	virtual item_const_iterator& operator=(const item_const_iterator&);
	virtual ~item_const_iterator();

public:	// abstract iterator interface
	virtual void open() { }
	virtual void close() { }
	virtual abstract_item* next(uint32_t delta = 1) { return NULL; }
	virtual abstract_item* peek() const { return NULL; }
	virtual bool done() const { return true; }
	virtual void rewind() { }

public:	// C++ interface
	item* operator*() const { return NULL; }
	item_const_iterator& operator++();

public:
	std::string string_value(context *);

};


class binary_iterator : public item_iterator
{
protected:
	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	abstract_item* (*op)(context *, abstract_item*, abstract_item*);

public:	// abstract iterator interface
	void open();
	void close();
	abstract_item* next(uint32_t delta = 1);
	abstract_item* peek() const;
	bool done() const;
	void rewind();

public:	// ctor,dtor
	binary_iterator(
		context* ctx,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		abstract_item* (*op)(context*, abstract_item*, abstract_item*));

	binary_iterator(const binary_iterator&);
	binary_iterator& operator=(const binary_iterator&);
	~binary_iterator();

public:	// manipulators
	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };

};


class singleton_iterator : public item_const_iterator
{
protected:
	abstract_item* i_p;
	bool done_b;

public:	// abstract iterator interface
	void open() { }
	void close() { done_b = false; }
	abstract_item* next(uint32_t delta=1) { done_b = true; return NULL; }
	abstract_item* peek() const { return i_p; }
	bool done() const { return done_b; }
	void rewind() { done_b = false; }

public:	// C++ interface
	item* operator*() const { return (item*)(i_p); }
	singleton_iterator& operator++() { done_b = true; return *this; }

public:	// ctor,dtor
	singleton_iterator(context *, abstract_item*);
	singleton_iterator(context *, const std::string&);
	singleton_iterator(context *, bool);
	singleton_iterator(context *, double);
	singleton_iterator(context *, int);
	singleton_iterator(context *, long);
	singleton_iterator(const singleton_iterator&);
	singleton_iterator& operator=(const singleton_iterator&);
	~singleton_iterator() {}

};


class concat_iterator : public item_iterator
{
protected:
	std::vector<rchandle<item_iterator> > it_list;
	std::vector<rchandle<item_iterator> >::const_iterator walker;
	std::vector<rchandle<item_iterator> >::const_iterator sentinel;

	rchandle<item_iterator> currit_h;
	uint32_t it_counter;

public:	// abstract iterator interface
	void open();
	void close();
	abstract_item* next(uint32_t delta = 1);
	abstract_item* peek() const;
	bool done() const;
	void rewind();

public:	// C++ interface
	item* operator*() const;
	concat_iterator& operator++();

public:
	concat_iterator(
		context *,
		std::vector<rchandle<item_iterator> >);
	concat_iterator(const concat_iterator&);
	concat_iterator& operator=(const concat_iterator&);
	~concat_iterator();

};


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

