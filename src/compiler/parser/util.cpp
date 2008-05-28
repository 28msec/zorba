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
#include "common/common.h"
#include "zorbatypes/utf8.h"
#include "compiler/parser/util.h"
#include "compiler/parser/query_loc.h"
#include "zorbaerrors/error_manager.h"

using namespace std;
namespace zorba {

// TODO: reuse (better) code that is probably available elsewhere in Zorba
int decode_entity (const char *in, string *out) 
{
  QueryLoc loc;
  const char *start = in;

  if (in [0] == '#') 
  {
    ++in;
    int base = 10;
    if (*in == 'x') { base = 16; ++in; }

    for (; *in == '0'; ++in);

    unsigned long n = strtoul (in, (char **) &in, base);

    if (*in++ != ';')
      ZORBA_ERROR_LOC (XPST0003, loc);

    if (! is_code_point_valid (n))
      ZORBA_ERROR_LOC (XQST0090, loc);

#ifndef ZORBA_NO_UNICODE
    UTF8Encode (n, back_inserter (*out));
#else
    *out += (char)n;
#endif
    return in - start;
  }

#define M( str, len, r ) if (strncmp (in, str, len) == 0) { *out += r; return len; }
  M ("amp;", 4, "&") else
  M ("lt;", 3, "<") else
  M ("gt;", 3, ">") else
  M ("quot;", 5, "\"") else
  M ("apos;", 5, "'")
#undef M

  ZORBA_ERROR_LOC_DESC(XPST0003, loc, "Invalid entity reference");
  return -1;
}

}
