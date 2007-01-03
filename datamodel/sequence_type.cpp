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

namespace xqp {


void sequence_type::initialize()
{
	ANY_SEQUENCE =
		make_sequence_type(Anyitem_type.getInstance(), StaticProperty.ALLOWS_ZERO_OR_MORE);

	SINGLE_ITEM =
    make_sequence_type(Anyitem_type.getInstance(), StaticProperty.EXACTLY_ONE);

	SINGLE_ATOMIC =
    make_sequence_type(Type.ANY_ATOMIC_TYPE, StaticProperty.EXACTLY_ONE);

	OPTIONAL_ATOMIC =
    make_sequence_type(Type.ANY_ATOMIC_TYPE, StaticProperty.ALLOWS_ZERO_OR_ONE);

	ATOMIC_SEQUENCE =
    make_sequence_type(Type.ANY_ATOMIC_TYPE, StaticProperty.ALLOWS_ZERO_OR_MORE);

	SINGLE_STRING =
    make_sequence_type(Type.STRING_TYPE, StaticProperty.EXACTLY_ONE);

	SINGLE_INTEGER =
    make_sequence_type(Type.INTEGER_TYPE, StaticProperty.EXACTLY_ONE);

	OPTIONAL_INTEGER =
    make_sequence_type(Type.INTEGER_TYPE, StaticProperty.ALLOWS_ZERO_OR_ONE);

	OPTIONAL_NODE =
    make_sequence_type(AnyNodeTest.getInstance(), StaticProperty.ALLOWS_ZERO_OR_ONE);

	SINGLE_NODE =
    make_sequence_type(AnyNodeTest.getInstance(), StaticProperty.EXACTLY_ONE);

	NODE_SEQUENCE =
    make_sequence_type(AnyNodeTest.getInstance(), StaticProperty.ALLOWS_ZERO_OR_MORE);

	NUMERIC_SEQUENCE =
    make_sequence_type(Type.NUMBER_TYPE, StaticProperty.ALLOWS_ZERO_OR_MORE);

	EMPTY_SEQUENCE =
    make_sequence_type(NoNodeTest.getInstance(), StaticProperty.EMPTY);
}


sequence_type::sequence_type(
	item_type primary,
	uint32_t cardinality)
{
	this.primaryType = primaryType;
	if (primaryType instanceof NoNodeTest) {
		this.cardinality = StaticProperty.EMPTY;
	} else {
		this.cardinality = cardinality;
	}
}


sequence_type makesequence_type(item_type primaryType, uint32_t cardinality)
{
	if (!(primaryType instanceof BuiltInAtomicType)) {
		return new sequence_type(primaryType, cardinality);
	}

	// For each item_type, there is an array of 8 sequence_types,
	// one for each possible cardinality (including impossible cardinalities,
	// such as "0 or many"). The pool is a static HashMap that obtains this array,
	// given an item_type. The array contains null entries for cardinalities that
	// have not been requested.

	sequence_type* array = (sequence_type*)pool.get(primary);
	if (array==NULL) {
		array = new sequence_type[8];
		pool.put(primary, array);
	}
	uint32_t code = StaticProperty.getCardinalityCode(cardinality);
	if (array[code] == null) {
		sequence_type s = new sequence_type(primaryType, cardinality);
		array[code] = s;
		return s;
	} else {
		return array[code];
	}
}


string sequnce_type::describe()
{
	string s = primary.describe();
	if (cardinality == StaticProperty.ALLOWS_ONE_OR_MORE) {
		s = s + '+';
	} else if (cardinality == StaticProperty.ALLOWS_ZERO_OR_MORE) {
		s = s + '*';
	} else if (cardinality == StaticProperty.ALLOWS_ZERO_OR_ONE) {
		s = s + '?';
	}
	return s;
}


} /* namespace xqp */

