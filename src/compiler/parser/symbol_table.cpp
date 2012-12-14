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
#include "stdafx.h"

#include "zorbatypes/numconversions.h"

#include "compiler/parser/symbol_table.h"

// Include the driver for the createQueryLoc() function
#include "compiler/parser/xquery_driver.h"

#include "util/ascii_util.h"
#include "util/xml_util.h"

#include <cstdlib>
#include <string>

using namespace std;

namespace zorba {

/**
 * Whitespace characters used in the functions below
 */
static const char* whitespace = " \t\r\n\f\v";


static bool decode_string(const char *yytext, uint32_t yyleng, string *result) {
  char delim = yytext [0];
  uint32_t i;
  for (i = 1; i + 1 < yyleng; i++) {
    char ch = yytext [i];
    if (ch == '&') {
      int d = xml::parse_entity(yytext + i + 1, result);
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

// bool attribute == true when an attribute value is normalized
static void normalize_eol(const char *text, uint32_t length, string *out, bool attribute = false) {
  uint32_t i;
  out->reserve (length + 1);
  char lastCh = '\0';
  for (i = 0; i < length; i++) {
    char ch = text [i];
    if (ch == '\r')
      *out += attribute ? ' ' : '\n';
    else if (ch != '\n' || lastCh != '\r')
      *out += (attribute && (ch == '\t' || ch == '\n'))? ' ' : ch;

    lastCh = ch;
  }
}

off_t symbol_table::put(char const* text)
{
  return put(text, strlen(text));
}

// normalizationType == 2 is used for normalizing attribute values
off_t symbol_table::put(char const* text, uint32_t length, int normalizationType)
{
  string normStr;
  if (normalizationType == 1 || normalizationType == 2)
  {
    normalize_eol (text, length, &normStr, normalizationType == 2);
    text = normStr.c_str ();
    length = normStr.size ();
  }

	return heap.put(text, 0, length);
}

off_t symbol_table::put_ncname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_qname(char const* text, uint32_t length, bool do_trim_start, bool do_trim_end, bool is_eqname)
{
  if (do_trim_start)
  {
    char const* temp = ascii::trim_start(text, length, whitespace);
    length -= (temp-text);
    text = temp;
  }

  if (do_trim_end)
  {
    length = ascii::trim_end(text, length, whitespace);
  }

  if (!is_eqname)
    return heap.put(text, 0, length);
  else
  {
    // EQName:  Q{prefix}name
    string name;
    string prefix = text;
    string::size_type pos = prefix.rfind('}');
    name = prefix.substr(pos+1);
    prefix = prefix.substr(1, pos);

    off_t uri = put_uri(prefix.c_str(), prefix.size());
    name = get(uri) + ":" + name;

    return heap.put(name.c_str(), 0, name.size());
  }
}

off_t symbol_table::put_uri(char const* text, uint32_t length)
{
  // trim start
  char const* temp = ascii::trim_start(text, length, whitespace);
  length -= (temp-text);
  text = temp;

  // trim end
  length = ascii::trim_end(text, length, whitespace);

  // normalize whitespace
  string result;
  if (! decode_string (text, length, &result))
    return -1;
  ascii::normalize_whitespace( result );

  return heap.put (result.c_str (), 0, result.length ());
}

off_t symbol_table::put_varname(char const* text, uint32_t length)
{
	return heap.put(text, 0, length);
}

off_t symbol_table::put_entityref(char const* text, uint32_t length)
{
  string result;
  if (xml::parse_entity (text + 1, &result) < 0)
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

off_t symbol_table::put_commentcontent(char const* yytext, uint32_t yyleng)
{
  string eolNorm;
  normalize_eol (yytext, yyleng, &eolNorm);
  yytext = eolNorm.c_str (); yyleng = eolNorm.size ();
  return heap.put (yytext, 0, yyleng);
}

xs_decimal* symbol_table::decimalval(char const* text, uint32_t length)
{
  return new xs_decimal(text);
}

// Will return NULL if std::range_error is raised
xs_double* symbol_table::doubleval(char const* text, uint32_t length)
{
  try {
    return new xs_double(text);
  }
  catch ( std::range_error const& ) {
    return NULL;
  }
}

// Will return NULL if std::range_error is raised
xs_integer* symbol_table::integerval(char const* text, uint32_t length)
{
  try {
    return new xs_integer(text);
  }
  catch ( std::range_error const& ) {
    return NULL;
  }
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
/* vim:set et sw=2 ts=2: */
