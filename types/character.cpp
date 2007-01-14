/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: character.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "character.h"

#include <string>

using namespace std;
namespace xqp {
  
uint32_t get_cardinality_code(uint32_t cardinality)
{
	return (cardinality & CARDINALITY_MASK) >> 13;
}

string describe(uint32_t cardinality)
{
	uint32_t code = get_cardinality_code(cardinality);
	switch (code) {
	case 1:	return "exactly zero";
	case 2:	return "exactly one";
	case 3:	return "zero or one";
	case 4:	return "many";
	case 5:	return "zero or many";
	case 6:	return "one or more";
	case 7:	return "zero or more";
	default: return "not allowed";
	}
}

} /* namespace xqp */

