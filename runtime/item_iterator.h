/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_ITEM_ITERATOR_H
#define XQP_ITEM_ITERATOR_H

#include "../util/rchandle.h"

namespace xqp {

class context;
class item;

class item_iterator : public rcobject
{
protected:
  context const& ctx;

public:
	item_iterator(context const& _ctx) : ctx(_ctx) {}
	~item_iterator() {}
  
public:
	// aquire resources
	void open() {}

	// release resources
	void close() {}

	// return handle to next item (or NULL)
	rchandle<item> next() { return NULL; }

	// return true <=> iterator has no more items
	bool done() { return true; }

	// rewind the iterator, equivalent to {close();open()}
	void rewind() {}

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
	singleton_iterator(
		context const&,
		rchandle<item>);

	singleton_iterator(
		context const&,
		std::string const& s);

	~singleton_iterator();

};



}	/* namespace xqp */
#endif	/* XQP_ITEM_ITERATOR_H */

