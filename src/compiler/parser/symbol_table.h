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
#pragma once
#ifndef ZORBA_SYMBOL_TABLE_H
#define ZORBA_SYMBOL_TABLE_H

#include "zorbatypes/schema_types.h"
#include <zorba/config.h>

#include "util/fx/fxcharheap.h"

namespace zorba {

class location;

class ZORBA_DLL_PUBLIC symbol_table
{
protected:	// state
	fxcharheap heap;

public:			// ctor,dtor
	symbol_table(uint32_t initial_heapsize=1024);
	~symbol_table();

public:			// table interface
  off_t put(char const* text);

  /* Accepted values for normalizationType:
   * normalizationType = 0 -- no normalization
   * normalizationType = 1 -- EOL normalization
   * normalizationType = 2 -- Attribute value normalization
   */
	off_t put(char const* text, uint32_t length, int normalizationType = 0);

	off_t put_ncname(char const* text, uint32_t length);
	off_t put_qname(char const* text, uint32_t length,
                  bool do_trim_start = false, bool do_trim_end = false, bool is_eqname = false);
	off_t put_uri(char const* text, uint32_t length);
	off_t put_varname(char const* text, uint32_t length);
	off_t put_entityref(char const* text, uint32_t length);
	off_t put_charref(char const* text, uint32_t length);
	off_t put_stringlit(char const* text, uint32_t length);
	off_t put_commentcontent(char const* text, uint32_t length);

	std::string get(off_t id);
	uint32_t size() const;

	xs_decimal* decimalval(char const* text, uint32_t length);
  xs_double* doubleval(char const* text, uint32_t length);   // Will return NULL if std::range_error is raised
  xs_integer* integerval(char const* text, uint32_t length); // Will return NULL if std::range_error is raised

};

}	/* namespace zorba */
#endif	/* ZORBA_SYMBOL_TABLE */

/* vim:set et sw=2 ts=2: */
