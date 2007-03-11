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

#include "../context/context.h"
#include "../util/Assert.h"
#include "../util/xqp_exception.h"
#include "../values/xs_primitive_values.h"

#include <iostream>
#include <sstream>

using namespace std;
namespace xqp {

item_iterator item_iterator::empty_sequence(NULL);

/*..........................................
 : item_iterator base                      :
 :.........................................*/

item_iterator::item_iterator(context * _ctx_p)
: ctx_p(_ctx_p)
{
}

item_iterator::item_iterator( item_iterator const& it)
: ctx_p(it.ctx_p)
{
}

item_iterator& item_iterator::operator=(
	item_iterator const& it)
{
	ctx_p = it.ctx_p;
	return *this;
}

item_iterator::~item_iterator() { }
void item_iterator::open() { }
void item_iterator::close() { }
item* item_iterator::next(uint32_t delta) { return NULL; }
item* item_iterator::peek() const { return NULL; }
bool item_iterator::done() const { return true; }
void item_iterator::rewind() { }
item* item_iterator::operator*() const { return peek(); }

item_iterator& item_iterator::operator++()
{
	next();
	return *this;
}

string item_iterator::string_value()
{
	ostringstream oss;
	while (!done()) {
		item* i_p = next();
		if (i_p==NULL) continue;
		i_p->put(oss,ctx_p);
	}
	return oss.str();
}



/*..........................................
 : item_const_iterator                     :
 :.........................................*/

item_const_iterator::item_const_iterator() { }

item_const_iterator::item_const_iterator(
	item_const_iterator const& it)
{
}

item_const_iterator& item_const_iterator::operator=(
	item_const_iterator const& it)
{
	return *this;
}

item_const_iterator::~item_const_iterator() { }
void item_const_iterator::open() { }
void item_const_iterator::close() { }
item * item_const_iterator::next(uint32_t delta) { return NULL; }
item * item_const_iterator::peek() const { return NULL; }
bool item_const_iterator::done() const { return true; }
void item_const_iterator::rewind() { }
item* item_const_iterator::operator*() const { return peek(); }

item_const_iterator& item_const_iterator::operator++()
{
	next();
	return *this;
}

string item_const_iterator::string_value(
	context * ctx_p)
{
	ostringstream oss;
	while (!done()) {
		item* i_p = next();
		if (i_p==NULL) continue;
		i_p->put(oss,ctx_p);
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

item* binary_iterator::next(uint32_t delta)
{
	item* i1_p = it1_h->next(delta);
	item* i2_p = it2_h->next(delta);
	return (*op)(ctx_p,i1_p,i2_p);
}

item* binary_iterator::peek() const 
{
	item * i1_p = it1_h->peek();
	item * i2_p = it2_h->peek();
	return (*op)(ctx_p,i1_p,i2_p);
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
	context * ctx_p,
	rchandle<item_iterator> _it1_h,
	rchandle<item_iterator> _it2_h,
	item * (*_op)(context *, item *, item *))
:
	item_iterator(ctx_p),
	it1_h(_it1_h),
	it2_h(_it2_h),
	op(_op)
{
}

binary_iterator& binary_iterator::operator=(
	binary_iterator const& it)
{
	ctx_p = it.ctx_p;
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
	context * ctx_p,
	item * _i_p)
:
	i_h(_i_p),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(item*)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context * ctx_p,
	string const& s)
:
	i_h(new(*ctx_p->istore()) xs_stringValue(*ctx_p->istore(),s)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(string)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context * ctx_p,
	bool v)
:
	i_h(new(*ctx_p->istore()) xs_booleanValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(bool)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context * ctx_p,
	double v)
:
	i_h(new(*ctx_p->istore()) xs_doubleValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(double)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context * ctx_p,
	int v)
:
	i_h(new(*ctx_p->istore()) xs_intValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(int)\n";
#endif
}

singleton_iterator::singleton_iterator(
	context * ctx_p,
	long v)
:
	i_h(new(*ctx_p->istore()) xs_longValue(v)),
	done_b(false)
{
#ifdef DEBUG
	cout << "singleton_iterator(long)\n";
#endif
}

singleton_iterator::singleton_iterator(
	singleton_iterator const& it)
:
	i_h(it.i_h),
	done_b(it.done_b)
{
}

singleton_iterator& singleton_iterator::operator=(
	singleton_iterator const& it)
{
	i_h = it.i_h;
	done_b = it.done_b;
	return *this;
}



/*..........................................
 : concat iterator                         :
 :.........................................*/

void concat_iterator::open()
{
}

void concat_iterator::close()
{
}

item* concat_iterator::next(uint32_t delta)
{
	while (currit_h->done() && ++walker!=sentinel) {
		currit_h = *walker;
		++it_counter;
	}
	if (done()) return NULL;
	return currit_h->next(delta);
}

item* concat_iterator::peek() const
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
	context * ctx_p,
	list<rchandle<item_iterator> > _it_list)
	//vector<rchandle<item_iterator> > _it_list)
:
	item_iterator(ctx_p),
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
	concat_iterator const& it)
:
	item_iterator(it.ctx_p),
	it_list(it.it_list),
	walker(it.walker),
	sentinel(it.sentinel),
	currit_h(it.currit_h),
	it_counter(it.it_counter)
{
}

concat_iterator& concat_iterator::operator=(
	concat_iterator const& it)
{
	ctx_p = it.ctx_p;
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


}	/* namespace xqp */

