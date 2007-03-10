/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: itemstore.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "itemstore.h"
#include "../types/sequence_type.h"
#include "../util/tracer.h"

#include <iostream>

/*______________________________________________________________________
|  
|  32bit-aligned, depth-first, inline XML encoding.
|_______________________________________________________________________*/

using namespace std;
namespace xqp {

itemstore::itemstore(
	uint32_t initial_size)
:
	store(),
	index(0.6f, initial_size),
	qncache()
{
}

itemstore::itemstore(
	string const& datapath,
	uint32_t initial_size)
:
	store( datapath+"/store" ),
	index( datapath+"/idx_", 0.6f, initial_size ),
	qncache( datapath )
{
}
 
itemstore::~itemstore()
{
}

itemref_t itemstore::add_text(
	std::string const& content)
{
	uint32_t sz = store.size();
	store.raw_copy(content.c_str(), content.length());
	return sz;
}

string itemstore::get_text(
	off_t offset,
	uint32_t length) const
{
	return string((char*)&store[offset],0,length);
}

itemref_t itemstore::add_key(
	uint64_t key)
{
	uint32_t sz = store.size();
	store.push_back(key>>32);
	store.push_back(key&0xffffffff);
	return sz;
}

void* itemstore::last()
{
	return static_cast<void*>(&store[store.size()]);
}


} /* namespace xqp */

