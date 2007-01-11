/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: ft_values.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "ft_values.h"
#include <iostream>

using namespace std;
namespace xqp {

ostream& operator<<(ostream& os,ft_or_value const& v)
{
	return os << "ft_or_value[]";
}

ostream& operator<<(ostream& os,ft_and_value const& v)
{
	return os << "ft_and_value[]";
}

ostream& operator<<(ostream& os,ft_mildnot_value const& v)
{
	return os << "ft_mildnot_value[]";
}

ostream& operator<<(ostream& os, ft_unarynot_value const&)
{
	return os << "ft_unarynot_value[]";
}

ostream& operator<<(ostream& os, ft_qphrase_value const&)
{
	return os << "ft_qphrase_value[]";
}


ft_mildnot_value::ft_mildnot_value(
	rchandle<ft_value> _posval_h,
	rchandle<ft_value> _negval_h)
:
	posval_h(_posval_h)
{
	negval_hv.push_back(_negval_h);
}


} /* namespace xqp */

