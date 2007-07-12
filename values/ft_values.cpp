/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
	ft_value const* _pos_p,
	ft_value const* _neg_p)
:
	pos_p(_pos_p)
{
	neg_pv.push_back(_neg_p);
}


} /* namespace xqp */

