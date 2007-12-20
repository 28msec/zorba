/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: symbol_table.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 */

#include "compiler/parser/symbol_table.h"
#include "util/fx/fxcharheap.h"
#include "util/numconversions.h"

#include <stdlib.h>
#include <string>

using namespace std;
namespace xqp {

/**
 * Whitespace characters used in the functions below
 */
static const char* whitespace = " \t\r\n\f";

/**
 * The function will trim the whitespace from the end of the string,
 * returning the new length.
 *
 */
void trim_end(char const* s, uint32_t& len)
{
  int done = 0;

  while (!done && len>0)
  {
    done = 1;
    for (unsigned int i=0; i<strlen(whitespace); i++)
      if (s[len-1] == whitespace[i])
      {
        len--;
        done = 0;
        break;
      }
  }
}

/**
 * The function will trim the whitespace from the begging of the string,
 * returning a pointer to the new starting character.
 *
 */
void trim_start(const char** s, uint32_t& len)
{
  int done = 0;

  while (!done && len>0)
  {
    done = 1;
    for (unsigned int i=0; i<strlen(whitespace); i++)
      if (**s == whitespace[i])
      {
        *s++;
        len--;
        done = 0;
        break;
      }
  }
}

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

off_t symbol_table::put_qname(char const* text, uint32_t length, bool do_trim_start, bool do_trim_end)
{
  if (do_trim_start)
    trim_start(&text, length);
  
  if (do_trim_end)
    trim_end(text, length);
  
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

xqp_decimal symbol_table::decimalval(char const* text, uint32_t length)
{
  xqp_decimal lDecimal;
  NumConversions::starCharToDecimal(text, lDecimal);
  return lDecimal;
}

xqp_double symbol_table::doubleval(char const* text, uint32_t length)
{
  xqp_double lDouble;
  NumConversions::starCharToDouble(text, lDouble);
  return lDouble;
}

xqp_int symbol_table::intval(char const* text, uint32_t length)
{
  xqp_int lInt;
  NumConversions::starCharToInt(text, lInt);
  return lInt;
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
