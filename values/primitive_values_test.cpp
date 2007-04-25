/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: primitive_values_test.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "primitive_values.h"
#include <iostream>

using namespace std;
using namespace xqp;
  
int main(int argc, char* argv[])
{
	
	numericValue(xs_decimal,123).put(cout) << endl;
	numericValue(xs_integer,123).put(cout) << endl;
	numericValue(xs_long,123).put(cout) << endl;
	numericValue(xs_int,123).put(cout) << endl;
	numericValue(xs_short,123).put(cout) << endl;
	numericValue(xs_double,123).put(cout) << endl;
	numericValue(xs_float,123).put(cout) << endl;
	numericValue(xs_negativeInteger,123).put(cout) << endl;
	numericValue(xs_nonNegativeInteger,123).put(cout) << endl;
	numericValue(xs_nonPositiveInteger,123).put(cout) << endl;
	numericValue(xs_positiveInteger,123).put(cout) << endl;
	numericValue(xs_unsignedInt,123).put(cout) << endl;
	numericValue(xs_unsignedLong,123).put(cout) << endl;
	numericValue(xs_unsignedShort,123).put(cout) << endl;

	stringValue(xs_string,"text string").put(cout) << endl;
	stringValue(xs_normalizedString,"text normalized string").put(cout) << endl;
	stringValue(xs_token,"text token").put(cout) << endl;
	stringValue(xs_language,"text language").put(cout) << endl;
	stringValue(xs_nmtoken,"text nmtoken").put(cout) << endl;
	stringValue(xs_name,"text name").put(cout) << endl;
	stringValue(xs_ncName,"text ncName").put(cout) << endl;
	stringValue(xs_id,"text ID").put(cout) << endl;
	stringValue(xs_idref,"text IDREF").put(cout) << endl;
	stringValue(xs_entity,"text ENTITY").put(cout) << endl;
	stringValue(xs_anyURI,"text URI").put(cout) << endl;

	booleanValue(true).put(cout) << endl;
	booleanValue(false).put(cout) << endl;

/*
class timeValue : public atomic_value
	timeValue(sequence_type_t, struct tm);
	timeValue(const std::string&);
	std::ostream& put(std::ostream&) const;


class binaryValue : public atomic_value
	binaryValue(sequence_type_t, const void*, size_t length);
	unsigned char* val() const { return theVal; }
	std::ostream& put(std::ostream&) const;

*/

}

