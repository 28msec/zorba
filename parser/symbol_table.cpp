/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: symbol_table.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 */

#include "symbol_table.h"
#include "util/fxcharheap.h"

#include <stdlib.h>
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
	return (uint32_t)heap.size();
}

off_t symbol_table::put(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_ncname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_qname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_uri(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_varname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_entityref(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_charref(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_stringlit(char const* text, uint32_t length)
{
	return heap.put(text, 1, length-2);
}

long double symbol_table::decimalval(char const* text, uint32_t length)
{
	return strtod(text, NULL);
// #ifndef WIN32
// 	return strtoll(text, NULL, 10);
// #else
// 	return _strtoi64(text, NULL, 10);
// #endif
}

double symbol_table::doubleval(char const* text, uint32_t length)
{
	return strtod(text, NULL);
}

int symbol_table::intval(char const* text, uint32_t length)
{
	return strtol(text, NULL, 10);
}

std::string symbol_table::get(off_t id)
{
	uint32_t n = heap.get_length0(id);
	char *buf;
	buf = (char*)malloc(n+1);
	heap.get0(id, buf, 0, n+1);
	std::string retstr = string(buf, 0, n);
	free(buf);
	return retstr;
}


}	/* namespace xqp */
