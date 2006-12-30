/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: data_interface.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_DATA_INTERFACE_H
#define XQP_DATA_INTERFACE_H

#include "../types/qname.h"
#include "../util/rchandle.h"

#include <iostream>

namespace xqp {

  
class item : public rcobject
{
public:
  item() {}
  virtual ~item() {}
  
public:
  void put(std::ostream&);
  
};



class item_iterator : public rcobject
{
public:

	// aquire resources
	void open();

	// release resources
	void close();

	// return handle to next item (or NULL)
	rchandle<item> next();

	// return true <=> iterator has no more items
	bool done();

	// rewind the iterator, equivalent to {close();open()}
	void rewind();

};



class empty_sequence : public item_iterator
{
public:
	empty_sequence() {}
	~empty_sequence() {}
	
public:
	void open() {}
	rchandle<item> next() { return NULL; }
	bool done() { return true; }
	void close() {}
	
};


class var_iterator : public item_iterator
{
protected:
	rchandle<QName> varname_h;

public:	// iterator interface

	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:	// ctor,dtor

	var_iterator(rchandle<QName>);
	~var_iterator();

public:	// manipulators

	rchandle<QName> get_varname() const { return varname_h; };

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
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item> (*op)(rchandle<item> const&,rchandle<item> const&));

	~binary_iterator();

public:	// manipulators

	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };

};


class ternary_iterator : public item_iterator
{
protected:

	rchandle<item_iterator> it1_h;
	rchandle<item_iterator> it2_h;
	rchandle<item_iterator> it3_h;
	
	rchandle<item> (*op)(rchandle<item> const&,rchandle<item> const&,rchandle<item> const&);

public:	// iterator interface

	void open();
	void close();
	rchandle<item> next();
	bool done();
	void rewind();

public:	// ctor,dtor

	ternary_iterator(
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item_iterator>,
		rchandle<item> (*op)(rchandle<item> const&,rchandle<item> const&,rchandle<item> const&));

	~ternary_iterator();

public:	// manipulators

	rchandle<item_iterator> get_it1() const { return it1_h; };
	rchandle<item_iterator> get_it2() const { return it2_h; };
	rchandle<item_iterator> get_it3() const { return it3_h; };

};


}	/* namespace xqp */
#endif	/* XQP_DATA_INTERFACE_H */
