/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ITERATOR_H
#define XQP_ITERATOR_H

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

class item_iterator : public rcobject
{
public:
	static item_iterator empty_sequence;

protected:
  context* ctx_p;

public:
	item_iterator(context *);
	item_iterator(item_iterator const&);
	virtual item_iterator& operator=(item_iterator const&);
	virtual ~item_iterator();

public:	// low-level interface
	virtual void open();				// aquire resources
	virtual void close();				// release resources
	virtual item* next(uint32_t delta = 1); // seek + delta (or NULL)
	virtual item* peek() const;	// current item (or NULL)
	virtual bool done() const;	// true <=> no more items
	virtual void rewind(); 			// equivalent to {close();open()}

public:	// C++ interface
	item* operator*() const;
	item_iterator& operator++();

public:
	std::string string_value();

};


class item_const_iterator : public rcobject
{
public:
	item_const_iterator();
	item_const_iterator(item_const_iterator const&);
	virtual item_const_iterator& operator=(item_const_iterator const&);
	virtual ~item_const_iterator();

public:	// low-level interface
	virtual void open();
	virtual void close();
	virtual item* next(uint32_t delta = 1);
	virtual item* peek() const;
	virtual bool done() const;
	virtual void rewind();

public:	// C++ interface
	item* operator*() const;
	item_const_iterator& operator++();

public:
	std::string string_value(context *);
};


class binary_iterator : public item_iterator
{
protected:
	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	item* (*op)(context *, item*, item*);

public:	// iterator interface
	void open();
	void close();
	item* next(uint32_t delta = 1);
	item* peek() const;
	bool done() const;
	void rewind();

public:	// ctor,dtor
	binary_iterator(
		context* ctx,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		item* (*op)(context*, item*, item*));
	binary_iterator(binary_iterator const&);
	binary_iterator& operator=(binary_iterator const&);
	~binary_iterator();

public:	// manipulators
	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };

};


class singleton_iterator : public item_const_iterator
{
protected:
	item* i_h;
	bool done_b;

public:	// iterator interface
	void open() { }
	void close() { done_b = false; }
	item* next(uint32_t delta=1) { done_b = true; return NULL; }
	item* peek() const { return **this; }
	bool done() const { return done_b; }
	void rewind() { done_b = false; }

public:	// C++ interface
	item* operator*() const { return i_h; }
	item_const_iterator& operator++() { done_b = true; return *this; }

public:	// ctor,dtor
	singleton_iterator(context *, item*);
	singleton_iterator(context *, std::string const&);
	singleton_iterator(context *, bool);
	singleton_iterator(context *, double);
	singleton_iterator(context *, int);
	singleton_iterator(context *, long);
	singleton_iterator(singleton_iterator const&);
	singleton_iterator& operator=(singleton_iterator const&);
	~singleton_iterator() {}

};


class concat_iterator : public item_iterator
{
protected:
	//list<rchandle<item_iterator> > it_list;
	//list_iterator<rchandle<item_iterator> > walker;
	//list_iterator<rchandle<item_iterator> > sentinel;

	std::vector<rchandle<item_iterator> > it_list;
	std::vector<rchandle<item_iterator> >::const_iterator walker;
	std::vector<rchandle<item_iterator> >::const_iterator sentinel;

	rchandle<item_iterator> currit_h;
	uint32_t it_counter;

public:	// iterator interface
	void open();
	void close();
	item* next(uint32_t delta = 1);
	item* peek() const;
	bool done() const;
	void rewind();

public:
	concat_iterator(
		context *,
		std::vector<rchandle<item_iterator> >);
		//list<rchandle<item_iterator> >);
	concat_iterator(concat_iterator const&);
	concat_iterator& operator=(concat_iterator const&);
	~concat_iterator();

};


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

