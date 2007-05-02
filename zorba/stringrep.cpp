/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: stringrep.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "stringrep.h"

#include "context/common.h"
#include "runtime/item_iterator.h"
#include "runtime/singleton_iterators.h"
#include "store/itemstore.h"

using namespace std;
namespace xqp {

stringrep::stringrep(
	itemstore& istore,
	const string& s)
:
	theLength(sizeof(stringrep)+s.length())
{
	istore.add_text(s);
}


ostream& stringrep::put(
	zorba* zorp,
	ostream& os) const
{
	os << string(rest,0,theLength-sizeof(stringrep));
	return os;
}

string stringrep::describe(
	zorba* zorp) const
{
	ostringstream oss;
	oss << "xs_string(";
	put(zorp,oss) << ')';
	return oss.str();
}

iterator_t stringrep::atomized_value(
	zorba* zorp) const
{
	return NULL;
}

iterator_t stringrep::effective_boolean_value(
	zorba* zorp) const
{
	return NULL;
}

string stringrep::str() const
{
	ostringstream oss;
	os << string(rest,0,theLength-sizeof(stringrep));
	return oss.str();
}

iterator_t stringrep::string_value(
	zorba* zorp) const
{
	ostringstream oss;
	put(zorp,oss);
	item_iterator* it_p = new string_singleton(stringValue(oss.str()));
	return it_p;
}


} /* namespace xqp */
