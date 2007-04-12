/* *- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: sequence_type.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_SEQUENCE_TYPE_H
#define XQP_SEQUENCE_TYPE_H

#include "typecodes.h"
#include "../context/common.h"

#include <string>

namespace xqp {

typedef TypeCode sequence_type_t;


/*______________________________________________________________________
|  
|	XQuery 1.0 "sequence type"
|	[http://www.w3.org/TR/xquery/#id-sequencetype-syntax]
|_______________________________________________________________________*/

class sequence_type
{
public:
	enum occurs_t {
		occurs_once,
		occurs_zero_or_more,
		occurs_one_or_more,
		occurs_zero_or_one
	};

private:
	sequence_type() {}
	~sequence_type() {}

public:
	// Get the cardinality component of this sequence_type.
	static enum occurs_t get_occurs(TypeCode);

	// Return a string representation of this sequence_type
	static std::string describe(TypeCode);

	// Sequence type matching
	// [http://www.w3.org/TR/xquery/#id-sequencetype-matching]
	static bool derives_from(TypeCode ta, TypeCode te);
	
};



} /* namespace xqp */
#endif /* XQP_SEQUENCE_TYPE_H */

