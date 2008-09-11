/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "zorbatypes/numconversions.h"

#include "compiler/parser/symbol_table.h"
#include "util/fx/fxcharheap.h"
#include "compiler/parser/util.h"

#include "util/XmlWhitespace.h"

#include <cstdlib>
#include <string>

using namespace std;

namespace zorba {

/**
 * Whitespace characters used in the functions below
 */
static const char* whitespace = " \t\r\n\f";

/**
 * The function will trim the whitespace from the begging of the string,
 * returning a pointer to the new starting character.
 *
 */
void trim_start(const char** s, uint32_t& len)
{
  int done = 0;

  while (! done && len > 0) {
    done = 1;
    for (const char *ws = whitespace; *ws != '\0'; ws++)
      if (**s == *ws) {
        ++*s; len--;
        done = 0;
        break;
      }
  }
}

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

static bool decode_string (const char *yytext, uint32_t yyleng, string *result) {
  char delim = yytext [0];
  uint32_t i;
  for (i = 1; i + 1 < yyleng; i++) {
    char ch = yytext [i];
    if (ch == '&') {
      int d = decode_entity (yytext + i + 1, result);
      if (d < 0) return false;
      i += d;
    } else {
      *result += ch;
      if (ch == delim) ++i;
    }
  }
  return true;
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

static void normalize_eol (const char *text, uint32_t length, string *out) {
  uint32_t i;
  out->reserve (length + 1);
  char lastCh = '\0';
  for (i = 0; i < length; i++) {
    char ch = text [i];
    if (ch == '\r')
      *out += '\n';
    else if (ch != '\n' || lastCh != '\r')
      *out += ch;
    lastCh = ch;
  }
}

static void normalize_attribute(const char *text, uint32_t length, string *out)
{
  uint32_t i;
  out->reserve (length + 1);
  for (i = 0; i < length; i++)
  {
    char ch = text[i];
    if (ch == 0x0D || ch == 0x0A || ch == 0x09)
      *out += ' ';
    else 
      *out += ch;
  }
}

off_t symbol_table::put(char const* text)
{
  return put(text, strlen(text));
}

off_t symbol_table::put(char const* text, uint32_t length, int normalizationType)
{
  string normStr;
  if (normalizationType == 1)
  {
    normalize_eol (text, length, &normStr);
    text = normStr.c_str ();
    length = normStr.size ();
  }
  else if (normalizationType == 2)
  {
    normalize_attribute(text, length, &normStr);
    text = normStr.c_str ();
    length = normStr.size ();
  }
  
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
  trim_start(&text, length);
  trim_end(text, length);
  
  string result;
  if (! decode_string (text, length, &result)) 
    return -1;
  result = xmlWhitespaceCollapse (result);
  return heap.put (result.c_str (), 0, result.length ());
}

off_t symbol_table::put_varname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_entityref(char const* text, uint32_t length)
{
  string result;
  if (decode_entity (text + 1, &result) < 0)
    return -1;
	return heap.put(result.c_str(), 0, result.size ());
}

off_t symbol_table::put_charref(char const* text, uint32_t length)
{
	return heap.put (text + 1, 0, length - 1);
}

off_t symbol_table::put_stringlit(char const* yytext, uint32_t yyleng)
{
  string eolNorm;
  normalize_eol (yytext, yyleng, &eolNorm);
  yytext = eolNorm.c_str (); yyleng = eolNorm.size ();
  string result;
  if (! decode_string (yytext, yyleng, &result)) return -1;
	return heap.put (result.c_str (), 0, result.length ());
}

xqp_decimal* symbol_table::decimalval(char const* text, uint32_t length)
{
  xqp_decimal lDecimal;
  NumConversions::starCharToDecimal(text, lDecimal);
  return new xqp_decimal(lDecimal);
}

xqp_double* symbol_table::doubleval(char const* text, uint32_t length)
{
  xqp_double lDouble;
  NumConversions::starCharToDouble(text, lDouble);
  return new xqp_double(lDouble);
}

xqp_integer* symbol_table::integerval(char const* text, uint32_t length)
{
  xqp_integer lInteger;
  NumConversions::starCharToInteger(text, lInteger);
  return new xqp_integer(lInteger);
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


}	/* namespace zorba */
