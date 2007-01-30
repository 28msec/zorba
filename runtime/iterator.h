/* -*- mode: c++; indent-tabs-mode: nil -*- *
 *  $Id: iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_ITERATOR_H
#define XQP_ITERATOR_H

#include "../types/xs_primitive_types.h"
#include "../util/list.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

#include <iostream>

namespace xqp {

class context;
class item;

class item_iterator : public rcobject
{
protected:
  context* ctx_p;

public:	// construct,copy,destroy
	item_iterator(context *);
	item_iterator(item_iterator const&);
	virtual item_iterator& operator=(item_iterator const&);
	virtual ~item_iterator();

public:	// low-level interface
	// aquire resources
	virtual void open();

	// release resources
	virtual void close();

	// return handle to next item (or NULL)
	virtual rchandle<item> next();

	// return handle to current item (or NULL)
	virtual rchandle<item> peek() const;

	// return true <=> iterator has no more items
	virtual bool done() const;

	// rewind the iterator, equivalent to {close();open()}
	virtual void rewind();

public:	// high-level interface
	virtual rchandle<item> operator*() const;
	virtual item_iterator& operator++();

public:
	virtual std::string string_value();

};


class binary_iterator : public item_iterator
{
protected:
	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	rchandle<item> (*op)(context *, rchandle<item> const&, rchandle<item> const&);

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	rchandle<item> peek() const;
	bool done() const;
	void rewind();

public:	// high-level interface
	rchandle<item> operator*() const;
	item_iterator& operator++();

public:	// ctor,dtor
	binary_iterator(
		context * ctx,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item> (*op)(context *, rchandle<item> const&, rchandle<item> const&));

	binary_iterator(binary_iterator const&);
	binary_iterator& operator=(binary_iterator const&);

	~binary_iterator();

public:	// manipulators
	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };

};


class singleton_iterator : public item_iterator
{
protected:
	rchandle<item> i_h;
	bool done_b;

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	rchandle<item> peek() const;
	bool done() const;
	void rewind();

public:	// high-level interface
	rchandle<item> operator*() const;
	item_iterator& operator++();

public:	// ctor,dtor
	singleton_iterator(context *, rchandle<item>);
	singleton_iterator(context *, item *);
	singleton_iterator(context *, std::string const& s);
	singleton_iterator(context *, bool);
	singleton_iterator(context *, double);
	singleton_iterator(context *, float);
	singleton_iterator(context *, int);
	singleton_iterator(context *, long long);
	singleton_iterator(context *, short);
	singleton_iterator(context *, signed char);
	singleton_iterator(context *, unsigned char);
	singleton_iterator(context *, unsigned int);
	singleton_iterator(context *, unsigned long long);
	singleton_iterator(context *, unsigned short);

	singleton_iterator(singleton_iterator const&);
	singleton_iterator& operator=(singleton_iterator const&);

	~singleton_iterator();

};


class concat_iterator : public item_iterator
{
protected:
	list<rchandle<item_iterator> > it_list;
	list_iterator<rchandle<item_iterator> > walker;
	list_iterator<rchandle<item_iterator> > sentinel;
	rchandle<item_iterator> currit_h;
	uint32_t it_counter;

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	rchandle<item> peek() const;
	bool done() const;
	void rewind();

public:	// high-level interface
	rchandle<item> operator*() const;
	item_iterator& operator++();

public:
	concat_iterator(
		context *,
		list<rchandle<item_iterator> >);

	concat_iterator(concat_iterator const&);
	concat_iterator& operator=(concat_iterator const&);

	~concat_iterator();

};


}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */

