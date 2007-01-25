/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
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
#include <iostream>

namespace xqp {

class context;
class item;

class item_iterator : public rcobject
{
protected:
  context const& ctx;

public:
	item_iterator(context const& _ctx) : ctx(_ctx) {}
	virtual ~item_iterator() {}
  
public:
	// aquire resources
	virtual void open() {}

	// release resources
	virtual void close() {}

	// return handle to next item (or NULL)
	virtual rchandle<item> next() { return NULL; }

	// return true <=> iterator has no more items
	virtual bool done() { return true; }

	// rewind the iterator, equivalent to {close();open()}
	virtual void rewind() {}

};



class binary_iterator : public item_iterator
{
protected:
	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	rchandle<item> (*op)(rchandle<item> const&,rchandle<item> const&);

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:	// ctor,dtor
	binary_iterator(
		context const& ctx,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item> (*op)(rchandle<item> const&, rchandle<item> const&));

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
	bool done();
	void rewind();

public:	// ctor,dtor
	singleton_iterator(context const&, rchandle<item>);
	singleton_iterator(context const&, item *);
	singleton_iterator(context const&, std::string const& s);
	singleton_iterator(context const&, bool);
	singleton_iterator(context const&, double);
	singleton_iterator(context const&, float);
	singleton_iterator(context const&, int);
	singleton_iterator(context const&, long long);
	singleton_iterator(context const&, short);
	singleton_iterator(context const&, signed char);
	singleton_iterator(context const&, unsigned char);
	singleton_iterator(context const&, unsigned int);
	singleton_iterator(context const&, unsigned long long);
	singleton_iterator(context const&, unsigned short);

	~singleton_iterator();

};


class concat_iterator : public item_iterator
{
protected:
	list<rchandle<item_iterator> > it_list;
	list_iterator<rchandle<item_iterator> > walker;
	list_iterator<rchandle<item_iterator> > sentinel;
	rchandle<item_iterator> currit_h;

public:	// iterator interface
	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:
	concat_iterator(
		context const&,
		list<rchandle<item_iterator> >);

	~concat_iterator();

};



}	/* namespace xqp */
#endif	/* XQP_ITERATOR_H */


