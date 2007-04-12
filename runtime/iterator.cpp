/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "iterator.h"

#include "../util/Assert.h"
#include "../util/xqp_exception.h"
#include "../values/abstract_value_factory.h"
#include "../values/xs_primitive_values.h"

#include <iostream>
#include <sstream>

using namespace std;
namespace xqp {


/*..........................................
 : item_iterator base                      :
 :.........................................*/

item_iterator& item_iterator::operator=(
	const item_iterator& it)
{
	dctx_p = it.dctx_p;
	return *this;
}

item_iterator& item_iterator::operator++()
{
	next();
	return *this;
}

string item_iterator::string_value()
{
	ostringstream oss;
	while (!done()) {
		item* i_p = reinterpret_cast<item*>(next());
		if (i_p==NULL) continue;
		i_p->put(oss);
	}
	return oss.str();
}



/*..........................................
 : item_const_iterator                     :
 :.........................................*/

item_const_iterator& item_const_iterator::operator=(
	const item_const_iterator& it)
{
	return *this;
}

item_const_iterator& item_const_iterator::operator++()
{
	next();
	return *this;
}

string item_const_iterator::string_value()
{
	ostringstream oss;
	while (!done()) {
		item* i_p = (item*)next();
		if (i_p==NULL) continue;
		oss << i_p->string_value();
	}
	return oss.str();
}


/*..........................................
 : binary iterator                         :
 :.........................................*/

void binary_iterator::open()
{
	it1_h->open();
	it2_h->open();
}

void binary_iterator::close()
{
	it1_h->close();
	it2_h->close();
}

abstract_item* binary_iterator::next(uint32_t delta)
{
	abstract_item* i1_p = it1_h->next(delta);
	abstract_item* i2_p = it2_h->next(delta);
	return (*op)(i1_p,i2_p);
}

abstract_item* binary_iterator::peek() const 
{
	abstract_item* i1_p = it1_h->peek();
	abstract_item* i2_p = it2_h->peek();
	return (*op)(i1_p,i2_p);
}

bool binary_iterator::done() const
{
	return it1_h->done() || it2_h->done();
}

void binary_iterator::rewind()
{
	it1_h->rewind();
	it2_h->rewind();
}

binary_iterator::binary_iterator(
	dynamic_context * dctx_p,
	rchandle<item_iterator> _it1_h,
	rchandle<item_iterator> _it2_h,
	abstract_item* (*_op)(abstract_item*, abstract_item*))
:
	item_iterator(dctx_p),
	it1_h(_it1_h),
	it2_h(_it2_h),
	op(_op)
{
}

binary_iterator& binary_iterator::operator=(
	const binary_iterator& it)
{
	dctx_p = it.dctx_p;
	it1_h = it.it1_h;
	it2_h = it.it2_h;
	op = it.op;
	return *this;
}

binary_iterator::~binary_iterator()
{
}



/*..........................................
 : singleton iterator                      :
 :.........................................*/

singleton_iterator::singleton_iterator(
	abstract_item* _i_p)
:
	i_p(_i_p),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(abstract_item*)\n";
#endif
}

singleton_iterator::singleton_iterator(
	abstract_value_factory* vf_p,
	const string& s)
:
	i_p(vf_p->make_xs_string(s)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(string)\n";
#endif
}

singleton_iterator::singleton_iterator(
	abstract_value_factory* vf_p,
	bool v)
:
	i_p(vf_p->make_xs_boolean(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(bool)\n";
#endif
}

singleton_iterator::singleton_iterator(
	abstract_value_factory* vf_p,
	double v)
:
	i_p(vf_p->make_xs_double(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(double)\n";
#endif
}

singleton_iterator::singleton_iterator(
	abstract_value_factory* vf_p,
	int v)
:
	i_p(vf_p->make_xs_int(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(int)\n";
#endif
}

singleton_iterator::singleton_iterator(
	abstract_value_factory* vf_p,
	long v)
:
	i_p(vf_p->make_xs_long(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(long)\n";
#endif
}

singleton_iterator::singleton_iterator(
	const singleton_iterator& it)
:
	i_p(it.i_p),
	done_b(it.done_b)
{
}

singleton_iterator& singleton_iterator::operator=(
	const singleton_iterator& it)
{
	i_p = it.i_p;
	done_b = it.done_b;
	return *this;
}



/*..........................................
 : concat iterator                         :
 :.........................................*/
/*
void concat_iterator::open()
{
}

void concat_iterator::close()
{
}

abstract_item* concat_iterator::next(uint32_t delta)
{
	while (currit_h->done() && ++walker!=sentinel) {
		currit_h = *walker;
		++it_counter;
	}
	if (done()) return NULL;
	return currit_h->next(delta);
}

abstract_item* concat_iterator::peek() const
{
	if (done()) return NULL;
	return currit_h->peek();
}

bool concat_iterator::done() const
{
	return (it_counter==it_list.size()
					&& currit_h->done());
}

void concat_iterator::rewind()
{
	walker = it_list.begin();
	for (; walker!=sentinel; ++walker) {
		(*walker)->rewind();
	}
	it_counter = 0;
}

concat_iterator::concat_iterator(
	dynamic_context* dctx_p,
	//list<rchandle<item_iterator> > _it_list)
	vector<rchandle<item_iterator> > _it_list)
:
	item_iterator(dctx_p),
	it_list(_it_list),
	walker(_it_list.begin()),
	sentinel(_it_list.end()),
	it_counter(1)
{
	currit_h = *walker;
	while (currit_h->done() && ++walker!=sentinel) {
		currit_h = *walker;
		++it_counter;
	}
}

concat_iterator::concat_iterator(
	const concat_iterator& it)
:
	item_iterator(it.dctx_p),
	it_list(it.it_list),
	walker(it.walker),
	sentinel(it.sentinel),
	currit_h(it.currit_h),
	it_counter(it.it_counter)
{
}

concat_iterator& concat_iterator::operator=(
	const concat_iterator& it)
{
	dctx_p = it.dctx_p;
	it_list = it.it_list;
	walker = it.walker;
	sentinel = it.sentinel;
	currit_h = it.currit_h;
	it_counter = it.it_counter;
	return *this;
}

concat_iterator::~concat_iterator()
{
}
*/


}	/* namespace xqp */

