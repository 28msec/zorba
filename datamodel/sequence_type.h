/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sequence_type.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#ifndef XQP_SEQUENCE_TYPE_H
#define XQP_SEQUENCE_TYPE_H

#include "types.h"
#include <string>

namespace xqp {

/*______________________________________________________________________
|  
|	XQuery 1.0 "sequence type"
|	[http://www.w3.org/TR/xquery/#id-sequencetype-syntax]
|_______________________________________________________________________*/

class sequence_type
{
protected:
	item_type primary;				// e.g. "element", "comment", or "integer"
	int cardinality;					// the required cardinality

public:
	// static initialization
	static initialized;				// default initialized to 0
	static void initializer();

public:
  static SequenceType ANY_SEQUENCE;			// any sequence of items
  static SequenceType SINGLE_ITEM;			// exactly one item, of any kind
  static SequenceType SINGLE_ATOMIC;		// exactly one atomic value
  static SequenceType OPTIONAL_ATOMIC;	// zero or one atomic values
  static SequenceType ATOMIC_SEQUENCE;	// zero or more atomic values
	static SequenceType SINGLE_STRING;		// single string
	static SequenceType SINGLE_INTEGER;		// single integer
	static SequenceType OPTIONAL_INTEGER;	// single integer
	static SequenceType OPTIONAL_NODE;		// zero or one nodes
  static SequenceType SINGLE_NODE;			// single node
	static SequenceType NODE_SEQUENCE;		// sequence of zero or more nodes
	static SequenceType NUMERIC_SEQUENCE;	// sequence of zero or more numeric values
	static SequenceType EMPTY_SEQUENCE;		// the empty sequence

	/**
	 *	This is a private constructor: all external	clients use the
	 *	factory method make_sequence_type(), to allow object pooling.
   *	@param primary			The item type
   *	@param cardinality	The required cardinality
   */
	sequence_type(item_type primary, uint32_t cardinality);

	/**
	 *	Construct an instance of sequence_type. This is a factory method:
	 *	it maintains a pool of sequence_type objects to reduce the amount
	 *	of object creation.
	 *	@param primary			The item type
	 *	@param cardinality	The required cardinality
	 */
	static sequence_type make_sequence_type(item_type primary, uint32_t cardinality);

	/**
	 *	Get the "primary" part of this required type.
	 *	E.g. for type element(*, xs:date) the "primary type" is element()
	 *	@return The item type code of the primary type
 	 */
	item_type get_primary() { return primary; }

	/**
	 *	 Get the cardinality component of this sequence_type.
	 *	 This is one of the constants Cardinality.EXACTLY_ONE,
	 *	 Cardinality.ONE_OR_MORE, etc
	 *	 @return the required cardinality
	 */
	uint32_t get_cardinality() { return cardinality; }

	/**
	 * Return a string representation of this SequenceType
	 * @return the string representation of this sequence_type
	 */
	std::string describe();

};


} /* namespace xqp */
#endif /* XQP_SEQUENCE_TYPE_H */

