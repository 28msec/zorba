/* *- mode: c++; indent-tabs-mode: nil -*-
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

#include "base_types.h"
#include "../parser/parse_constants.h"
#include "../util/rchandle.h"

#include <string>

namespace xqp {

/*______________________________________________________________________
|  
|	XQuery 1.0 "sequence type"
|	[http://www.w3.org/TR/xquery/#id-sequencetype-syntax]
|_______________________________________________________________________*/

class sequence_type : public rcobject
{
protected:
	item_type primary;				// e.g. "element", "comment", or "integer"
	enum occurrence_t occurs;	// e.g. "?", "*", "+"

public:
	//static bool initialized;				// default initialized to 0
	//static void initializer();

public:
  static sequence_type ANY_SEQUENCE;			// any sequence of items
  static sequence_type SINGLE_ITEM;				// exactly one item, of any kind
  static sequence_type SINGLE_ATOMIC;			// exactly one atomic value
  static sequence_type OPTIONAL_ATOMIC;		// zero or one atomic values
  static sequence_type ATOMIC_SEQUENCE;		// zero or more atomic values
	static sequence_type SINGLE_STRING;			// single string
	static sequence_type SINGLE_INTEGER;		// single integer
	static sequence_type OPTIONAL_INTEGER;	// single integer
	static sequence_type OPTIONAL_NODE;			// zero or one nodes
  static sequence_type SINGLE_NODE;				// single node
	static sequence_type NODE_SEQUENCE;			// sequence of zero or more nodes
	static sequence_type NUMERIC_SEQUENCE;	// sequence of zero or more numeric values
	static sequence_type EMPTY_SEQUENCE;		// the empty sequence

public:
	sequence_type();
	~sequence_type();

public:
	/**
	 *	This is a private constructor: all external	clients use the
	 *	factory method make_sequence_type(), to allow object pooling.
   *	@param primary			The item type
   *	@param cardinality	The required cardinality
   */
	sequence_type(item_type, enum occurrence_t);

	/**
	 *	Construct an instance of sequence_type. This is a factory method:
	 *	it maintains a pool of sequence_type objects to reduce the amount
	 *	of object creation.
	 *	@param primary			The item type
	 *	@param cardinality	The required cardinality
	 */
	static sequence_type make_sequence_type(item_type, occurrence_t);

	/**
	 *	Get the "primary" part of this required type.
	 *	E.g. for type element(*, xs:date) the "primary type" is element()
	 *	@return The item type code of the primary type
 	 */
	item_type get_primary() const { return primary; }

	/**
	 *	 Get the cardinality component of this sequence_type.
	 *	 This is one of the constants Cardinality.EXACTLY_ONE,
	 *	 Cardinality.ONE_OR_MORE, etc
	 *	 @return the required cardinality
	 */
	enum occurrence_t get_occurs() const { return occurs; }

	/**
	 * Return a string representation of this SequenceType
	 * @return the string representation of this sequence_type
	 */
	std::string describe() const;

};


} /* namespace xqp */
#endif /* XQP_SEQUENCE_TYPE_H */

