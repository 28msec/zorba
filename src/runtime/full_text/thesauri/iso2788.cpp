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

#include <algorithm>                    /* for lower_bound() */
#include <cstring>

#include "util/less.h"
#include "iso2788.h"
#include "diagnostics/assert.h"

#define eacute  "\xC3\xA9"
#define uuml    "\xC3\xBC"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace iso2788 {

///////////////////////////////////////////////////////////////////////////////

struct rel_table_entry {
  rel_type type;
  char const *name;
};

struct less_rel_table_entry :
  binary_function<rel_table_entry const&,rel_table_entry const&,bool>
{
  less_rel_table_entry() { }
  result_type operator()( first_argument_type i, second_argument_type j ) {
    return ::strcmp( i.name, j.name ) < 0;
  }
};

#define REL_TABLE_END(LANG)                                     \
  static rel_table_entry const *const rel_table_##LANG##_end =  \
    rel_table_##LANG +                                          \
    sizeof( rel_table_##LANG ) / sizeof( rel_table_##LANG[0] )

static rel_table_entry rel_table_de[] = {
  // This MUST be sorted by name.
  { USE,  "benutzen" },
  { UF ,  "benutzt f" uuml "r" },
  { UF ,  "bf" },
  { USE,  "bs" },
  { SN ,  "d" },
  { SN ,  "definition" },
  { BTG,  "oa" },
  { BT ,  "ob" },
  { BT ,  "oberbegriff" },
  { BTG,  "oberbegriff abstraktionsrelation" },
  { TT ,  "sb" },
  { BTP,  "sp" },
  { TT ,  "spitzenbegriff" },
  { NTP,  "teilbegriff bestandsrelation" },
  { NTP,  "tp" },
  { NTG,  "ua" },
  { NT ,  "ub" },
  { NT ,  "unterbegriff" },
  { NTG,  "unterbegriff abstraktionsrelation" },
  { RT ,  "vb" },
  { BTP,  "verbandsbegriff bestandsrelation" },
  { RT ,  "verwandter begriff" },
//{ BTI,  /* TODO */ },
//{ NTI,  /* TODO */ },
};
REL_TABLE_END(de);

static rel_table_entry rel_table_en[] = {
  // This MUST be sorted by name.
  { BT ,  "broader term" },
  { BTG,  "broader term generic" },
  { BTI,  "broader term instance" },
  { BTP,  "broader term partitive" },
  { BT ,  "bt" },
  { BTG,  "btg" },
  { BTI,  "bti" },
  { BTP,  "btp" },
  { NT ,  "narrower term" },
  { NTG,  "narrower term generic" },
  { NTI,  "narrower term instance" },
  { NTP,  "narrower term partitive" },
  { NT ,  "nt" },
  { NTG,  "ntg" },
  { NTI,  "nti" },
  { NTP,  "ntp" },
  { RT ,  "related term" },
  { RT ,  "rt" },
  { SN ,  "scope note" },
  { TT ,  "top term" },
  { TT ,  "tt" },
  { UF ,  "uf" },
  { USE,  "use" },
  { UF ,  "use for" },
};
REL_TABLE_END(en);

static rel_table_entry rel_table_fr[] = {
  // This MUST be sorted by name.
  { USE,  "em" },
  { USE,  "employer" },
  { UF ,  "employ" eacute " pour" },
  { UF ,  "ep" },
  { TT ,  "mv" },
  { SN ,  "ne" },
  { TT ,  "nom de la classe la plus g" eacute "n" eacute "ale" },
  { SN ,  "note explicative" },
  { BT ,  "term g" eacute "n" eacute "rique" },
  { BTG,  "term g" eacute "n" eacute "rique g" eacute "n" eacute "rique" },
  { BTP,  "term g" eacute "n" eacute "rique partitif" },
  { NT ,  "terme sp" eacute "cifique" },
  { NTG,  "terme sp" eacute "cifique g" eacute "n" eacute "rique" },
  { NTP,  "terme sp" eacute "cifique partitif" },
  { BT ,  "tg" },
  { BTG,  "tgg" },
  { BTP,  "tgp" },
  { NT ,  "ts" },
  { NTG,  "tsg" },
  { NTP,  "tsp" },
  { RT ,  "va" },
  { RT ,  "voir aussi" },
//{ BTI,  /* TODO */ },
//{ NTI,  /* TODO */ },
};
REL_TABLE_END(fr);

#ifdef LANG
# undef LANG
#endif
#define LANG(CODE)                    \
  iso639_1::CODE:                     \
    *begin = rel_table_##CODE;        \
    *end   = rel_table_##CODE##_end;  \
    return true

static bool get_rel_table( iso639_1::type code, rel_table_entry const **begin,
                           rel_table_entry const **end ) {
  switch ( code ) {
    case LANG(de);
    case LANG(en);
    case LANG(fr);
    default:
      return false;
  }
}

///////////////////////////////////////////////////////////////////////////////

rel_type find_rel( char const *relationship, iso639_1::type lang ) {
  typedef pair<rel_table_entry const*,rel_table_entry const*> range_type;

  rel_table_entry const *begin, *end;
  if ( !get_rel_table( lang, &begin, &end ) ) {
    begin = rel_table_en;
    end   = rel_table_en_end;
  }

  rel_table_entry entry_to_find;
  entry_to_find.name = relationship;

  range_type const result =
    ::equal_range( begin, end, entry_to_find, less_rel_table_entry() );
  return result.first == result.second ? unknown : result.first->type;
}

rel_dir get_dir( rel_type t ) {
  switch ( t ) {
    case BT :
    case BTG:
    case BTI:
    case BTP:
    case TT :
      return broader;
    case NT :
    case NTG:
    case NTI:
    case NTP:
      return narrower;
    case RT :
    case SN :
    case UF :
    case USE:
    case unknown:
      return neutral;
    default:
      ZORBA_ASSERT( false );
  }
}

///////////////////////////////////////////////////////////////////////////////

char const *const string_of[] = {
  // This MUST be in sorted order.
  "#UNKNOWN",
  "bt",
  "btg",
  "bti",
  "btp",
  "nt",
  "ntg",
  "nti",
  "ntp",
  "rt",
  "sn",
  "tt",
  "uf",
  "use",
};

///////////////////////////////////////////////////////////////////////////////

} // namespace iso2788
} // namespace zorba
/* vim:set et sw=2 ts=2: */
