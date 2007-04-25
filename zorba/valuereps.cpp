/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: valuereps.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */


#include "valuereps.h"
#include "../context/common.h"
#include "../store/itemstore.h"
 
namespace xqp {


/*..........................................
 :  sequencerep                            :
 :.........................................*/

string sequenceRep::describe() const
{
	return "item*";
}


/*..........................................
 :  itemrep                                :
 :.........................................*/

std::ostream& itemRep::put(
	std::ostream& os) const
{
	return os;
}

std::string itemRep::describe() const
{
	return "item";
}

iterator_t itemRep::atomized_value() const
{
	return NULL;
}

string itemRep::string_value() const
{
	return "";
}

bool itemRep::is_empty() const
{
	return false;
}

bool itemRep::is_node() const
{
	return false;
}

bool itemRep::is_atomic() const
{
	return false;
}


/*..........................................
 :  atomic_valuerep                        :
 :.........................................*/

std::ostream& atomic_valueRep::put(std::ostream& os) const
{
	return os;
}

std::string atomic_valueRep::describe() const
{
	return "xs_atomicValue";
}

iterator_t atomic_valueRep::atomized_value() const
{
	return NULL;
}

string atomic_valueRep::string_value() const
{
	return "xs_atomicValue";
}

bool atomic_valueRep::is_empty() const
{
	return false;
}

bool atomic_valueRep::is_node() const
{
	return false;
}

bool atomic_valueRep::is_atomic() const
{
	return true;
}


} /* namespace xqp */

