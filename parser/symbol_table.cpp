/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: symbol_table.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 */

#include "symbol_table.h"

#include <string>

using namespace std;
namespace xqp {

symbol_table::symbol_table(uint32_t initial_heapsize)
:
	heap(initial_heapsize)
{
}

symbol_table::~symbol_table()
{
}

uint32_t symbol_table::size() const
{
	return 0;
}

uint32_t symbol_table::put(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_ncname(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_qname(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_uri(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_varname(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_entityref(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_charref(char const* text, uint32_t length)
{
	return 0;
}

uint32_t symbol_table::put_stringlit(char const* text, uint32_t length)
{
	return 0;
}

double symbol_table::decimalval(char const* text, uint32_t length)
{
	return 0;
}

double symbol_table::doubleval(char const* text, uint32_t length)
{
	return 0;
}

int symbol_table::intval(char const* text, uint32_t length)
{
	return 0;
}

std::string symbol_table::get(uint32_t id)
{
	return "";
}


}	/* namespace xqp */
