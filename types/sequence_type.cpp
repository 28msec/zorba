/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sequence_type.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "sequence_type.h"
#include "character.h"
#include "../parser/parse_constants.h"
#include <string>

using namespace std;
namespace xqp {

sequence_type sequence_type::ANY_SEQUENCE(item_type(),occurs_zero_or_more);
sequence_type sequence_type::SINGLE_ITEM(item_type(),occurs_exactly_one);
sequence_type sequence_type::SINGLE_ATOMIC(atomic_type(),occurs_exactly_one);
sequence_type sequence_type::OPTIONAL_ATOMIC(atomic_type(),occurs_optionally);
sequence_type sequence_type::ATOMIC_SEQUENCE(atomic_type(),occurs_zero_or_more);
sequence_type sequence_type::SINGLE_STRING(item_type(),occurs_exactly_one);
sequence_type sequence_type::SINGLE_INTEGER(item_type(),occurs_exactly_one);
sequence_type sequence_type::OPTIONAL_INTEGER(item_type(),occurs_optionally);
sequence_type sequence_type::OPTIONAL_NODE(item_type(),occurs_optionally);
sequence_type sequence_type::SINGLE_NODE(item_type(),occurs_exactly_one);
sequence_type sequence_type::NODE_SEQUENCE(item_type(),occurs_zero_or_more);
sequence_type sequence_type::NUMERIC_SEQUENCE(item_type(),occurs_zero_or_more);
sequence_type sequence_type::EMPTY_SEQUENCE(item_type(),occurs_never);


sequence_type::sequence_type()
:
	primary(item_type()),
	occurs(occurs_zero_or_more)
{
}

sequence_type::~sequence_type()
{
}

sequence_type::sequence_type(
	item_type _primary,
	enum occurrence_t _occurs)
:
	primary(_primary),
	occurs(_occurs)
{
}

sequence_type make_sequence_type(
	item_type primary, 
	enum occurrence_t occurs)
{
	return sequence_type(primary, occurs);
}

string sequence_type::describe() const
{
	if (occurs==occurs_never) {
		return "void()";
	}
	ostringstream oss;
	oss << primary.describe();
	switch (occurs) {
	case occurs_optionally: oss << "?"; break;
	case occurs_zero_or_more: oss << "*"; break;
	case occurs_one_or_more: oss << "+"; break;
	default: oss << "??";
	}
	return oss.str();
}

}	/* namepsace xqp */

