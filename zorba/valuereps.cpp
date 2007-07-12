/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
 :  itemrep                                :
 :.........................................*/

std::ostream& itemRep::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os;
}

std::string itemRep::describe() const
{
	return "item";
}

string itemRep::string_value() const
{
	return "";
}


/*..........................................
 :  atomic_valuerep                        :
 :.........................................*/

std::ostream& atomic_valueRep::put(
	zorba* zorp,
	std::ostream& os) const
{
	return os;
}

std::string atomic_valueRep::describe() const
{
	return "xs_atomicValue";
}

string atomic_valueRep::string_value() const
{
	return "xs_atomicValue";
}


} /* namespace xqp */

