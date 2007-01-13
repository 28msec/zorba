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
#include "../values/value.h"

#include <iostream>

namespace xqp {


class object_iterator : public rcobject
{
protected:
  context *const ctx;
  
public:
	// aquire resources
	void open();

	// release resources
	void close();

	// return handle to next item (or NULL)
	rchandle<object> next();

	// return true <=> iterator has no more items
	bool done();

	// rewind the iterator, equivalent to {close();open()}
	void rewind();

};



class empty_sequence : public xqp_iterator
{
public:
	empty_sequence() {}
	~empty_sequence() {}
	
public:
	void open() {}
	rchandle<object> next() { return NULL; }
	bool done() { return true; }
	void close() {}
	
};


class var_iterator : public xqp_iterator
{
protected:
	rchandle<QName> varname_h;

public:	// iterator interface
	void open();
	void close();
	rchandle<object> next();
	bool done();
	void rewind();

public:	// ctor,dtor
	var_iterator(rchandle<QName>);
	~var_iterator();

public:	// manipulators
	rchandle<QName> get_varname() const { return varname_h; };

};


class binary_iterator : public xqp_iterator
{
protected:
	rchandle<xqp_iterator> it1_h;
	rchandle<xqp_iterator> it2_h;
	rchandle<object> (*op)(rchandle<object> const&,rchandle<object> const&);

public:	// iterator interface
	void open();
	void close();
	rchandle<object> next();
	bool done();
	void rewind();

public:	// ctor,dtor
	binary_iterator(
		rchandle<xqp_iterator>,
		rchandle<xqp_iterator>,
		rchandle<object> (*op)(rchandle<object> const&,rchandle<object> const&));

	~binary_iterator();

public:	// manipulators
	rchandle<xqp_iterator> get_it1() const { return it1_h; };
	rchandle<xqp_iterator> get_it2() const { return it2_h; };

};



}	/* namespace xqp */
#endif	/* XQP_DATA_INTERFACE_H */
