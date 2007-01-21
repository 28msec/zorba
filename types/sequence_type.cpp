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

sequence_type sequence_type::ANY_SEQUENCE;			// any sequence of items
sequence_type sequence_type::SINGLE_ITEM;				// exactly one item, of any kind
sequence_type sequence_type::SINGLE_ATOMIC;			// exactly one atomic value
sequence_type sequence_type::OPTIONAL_ATOMIC;		// zero or one atomic values
sequence_type sequence_type::ATOMIC_SEQUENCE;		// zero or more atomic values
sequence_type sequence_type::SINGLE_STRING;			// single string
sequence_type sequence_type::SINGLE_INTEGER;		// single integer
sequence_type sequence_type::OPTIONAL_INTEGER;	// single integer
sequence_type sequence_type::OPTIONAL_NODE;			// zero or one nodes
sequence_type sequence_type::SINGLE_NODE;				// single node
sequence_type sequence_type::NODE_SEQUENCE;			// sequence of zero or more nodes
sequence_type sequence_type::NUMERIC_SEQUENCE;	// sequence of zero or more numeric values
sequence_type sequence_type::EMPTY_SEQUENCE;		// the empty sequence

/*
void sequence_type::initializer()
{
	ANY_SEQUENCE =
		make_sequence_type(any_item_type::get_instance(), ALLOWS_ZERO_OR_MORE);

	SINGLE_ITEM =
    make_sequence_type(any_item_type::get_instance(), EXACTLY_ONE);

	SINGLE_ATOMIC =
    make_sequence_type(atomic_type::get_instance(), EXACTLY_ONE);

	OPTIONAL_ATOMIC =
    make_sequence_type(atomic_type::get_instance(), ALLOWS_ZERO_OR_ONE);

	ATOMIC_SEQUENCE =
    make_sequence_type(atomic_type::get_instance(), ALLOWS_ZERO_OR_MORE);

	SINGLE_STRING =
    make_sequence_type(string_type::get_instance(), EXACTLY_ONE);

	SINGLE_INTEGER =
    make_sequence_type(integer_type::get_instance(), EXACTLY_ONE);

	OPTIONAL_INTEGER =
    make_sequence_type(integer_type::get_instance(), ALLOWS_ZERO_OR_ONE);

	OPTIONAL_NODE =
    make_sequence_type(any_node_test::get_instance(), ALLOWS_ZERO_OR_ONE);

	SINGLE_NODE =
    make_sequence_type(any_node_test::get_instance(), EXACTLY_ONE);

	NODE_SEQUENCE =
    make_sequence_type(any_node_test::get_instance(), ALLOWS_ZERO_OR_MORE);

	NUMERIC_SEQUENCE =
    make_sequence_type(number_type::get_instance(), ALLOWS_ZERO_OR_MORE);

	EMPTY_SEQUENCE =
    make_sequence_type(empty_sequence::get_instance(), EMPTY);
}
*/


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


} /* namespace xqp */

