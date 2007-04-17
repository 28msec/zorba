/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: valuerep.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */


#include "valuerep.h"
#include "../store/itemstore.h"
 
namespace xqp {


/*..........................................
 :  sequencerep                            :
 :.........................................*/

string sequencerep::describe() const
{
	return "item*";
}


/*..........................................
 :  itemrep                                :
 :.........................................*/

std::ostream& itemrep::put(
	std::ostream& os) const
{
	return os;
}

std::string itemrep::describe() const
{
	return "item";
}

itref_t itemrep::atomized_value() const
{
	return NULL;
}

string itemrep::string_value() const
{
	return "";
}

bool itemrep::is_empty() const
{
	return false;
}

bool itemrep::is_node() const
{
	return false;
}

bool itemrep::is_atomic() const
{
	return false;
}


/*..........................................
 :  atomic_valuerep                        :
 :.........................................*/

std::ostream& atomic_valuerep::put(std::ostream& os) const
{
	return os;
}

std::string atomic_valuerep::describe() const
{
	return "xs_atomicValue";
}

itref_t atomic_valuerep::atomized_value() const
{
	return NULL;
}

string atomic_valuerep::string_value() const
{
	return "xs_atomicValue";
}

bool atomic_valuerep::is_empty() const
{
	return false;
}

bool atomic_valuerep::is_node() const
{
	return false;
}

bool atomic_valuerep::is_atomic() const
{
	return true;
}


} /* namespace xqp */

