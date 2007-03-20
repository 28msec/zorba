/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "vector_iterator.h"

using namespace std;
namespace xqp {


/*..........................................
 : node_vector_iterator                    :
 :.........................................*/

void node_vector_iterator::open()
{
}

void node_vector_iterator::close()
{
}

abstract_item* node_vector_iterator::next(uint32_t delta = 1)
{
	for (uint32_t i=0; i<delta; ++i) ++it;
	return *it;
}

abstract_item* node_vector_iterator::peek() const
{
	return *it;
}

bool node_vector_iterator::done() const
{
	it==end;
}

void node_vector_iterator::rewind()
{
	it = nodev.begin();
}

item* node_vector_iterator::operator*() const
{
	return *it;
}

node_vector_iterator& node_vector_iterator::operator++()
{
	++it;
}

node_vector_iterator::node_vector_iterator(
	context * ctx_p,
	const std::vector<const attribute_node*>& _nodev)
:
	nodev(_nodev),
	it(nodev.begin()),
	end(nodev.end())
{
}

node_vector_iterator::node_vector_iterator(
	const node_vector_iterator& nvit)
:
	nodev(nv_it.nodev),
	it(nv_it.it),
	end(nv_it.end)
{
}

node_vector_iterator& node_vector_iterator::operator=(
	const node_vector_iterator& nvit)
{
	if (nvit.nodev!=nodev) return false;
	if (nvit.it!=it) return false;
	return true;
}

node_vector_iterator::~node_vector_iterator()
{
}



/*..........................................
 : attribute_vector_iterator               :
 :.........................................*/

/*
std::vector<const node*>& nodev;
std::vector<const node*>::const_iterator it;
std::vector<const node*>::const_iterator end;
*/

void attribute_vector_iterator::open()
{
}

void attribute_vector_iterator::close()
{
}

abstract_item* attribute_vector_iterator::next(uint32_t delta = 1)
{
	for (uint32_t i=0; i<delta; ++i) ++it;
	return *it;
}

abstract_item* attribute_vector_iterator::peek() const
{
	return *it;
}

bool attribute_vector_iterator::done() const
{
	it==end;
}

void attribute_vector_iterator::rewind()
{
	it = nodev.begin();
}

item* attribute_vector_iterator::operator*() const
{
	return *it;
}

attribute_vector_iterator& attribute_vector_iterator::operator++()
{
	++it;
}

attribute_vector_iterator::attribute_vector_iterator(
	context * ctx_p,
	const std::vector<const attribute_node*>& _nodev)
:
	nodev(_nodev),
	it(nodev.begin()),
	end(nodev.end())
{
}

attribute_vector_iterator::attribute_vector_iterator(
	const attribute_vector_iterator& nvit)
:
	nodev(nv_it.nodev),
	it(nv_it.it),
	end(nv_it.end)
{
}

attribute_vector_iterator& attribute_vector_iterator::operator=(
	const attribute_vector_iterator& nvit)
{
	if (nvit.nodev!=nodev) return false;
	if (nvit.it!=it) return false;
	return true;
}

attribute_vector_iterator::~attribute_vector_iterator()
{
}


}	/* namespace xqp */

