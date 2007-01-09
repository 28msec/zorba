/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: source.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "source.h"

using namespace std;
namespace xqp {
  
  
rchandle<source> source_list::operator[](int i) const
{
	return src_v[i];
}

void source_list::push_back(rchandle<source> s_h)
{
	src_v.push_back(s_h);
}

uint32_t source_list::size() const
{
	return src_v.size();
}

 
  
} /* namespace xqp */

