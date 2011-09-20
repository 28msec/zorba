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

#ifndef NDEBUG

#include "util/indent.h"
#include "util/omanip.h"
#include "util/stl_util.h"

#include "ft_match.h"

using namespace std;

namespace zorba {

inline ostream& print_addr( ostream &o, void const *obj ) {
  return o << "0x" << hex << reinterpret_cast<unsigned long>( obj ) << dec;
}

DEF_OMANIP1( print_addr, void const*, obj )

ostream& operator<<( ostream &o, ft_string_match const &sm ) {
  return  o << "{SM: "
            << static_cast<ft_token_span const&>( sm )
            << " query_pos=" << sm.query_pos
            << " contiguous=" << (sm.is_contiguous ? 'T' : 'F')
            << '}';
}

static ostream& print_string_matches( ostream &o, char const *label,
                                      ft_string_matches const &sms ) {
  if ( !sms.empty() ) {
    o << inc_indent << indent << label << '\n' << inc_indent;
    FOR_EACH( ft_string_matches, sm, sms )
      o << indent << *sm << '\n';
    o << dec_indent << dec_indent;
  }
  return o;
}

DEF_OMANIP2( print_string_matches, char const*, label,
             ft_string_matches const&, sms )

ostream& operator<<( ostream &o, ft_match const &m ) {
  return  o << indent << "ft_match @ " << print_addr( &m ) << '\n'
            << print_string_matches( "INCLUDES", m.includes )
            << print_string_matches( "EXCLUDES", m.excludes );
}

ostream& operator<<( ostream &o, ft_all_matches const &am ) {
  o << indent << "ft_all_matches @ " << print_addr( &am ) << '\n';
  if ( !am.empty() ) {
    o << inc_indent;
    FOR_EACH( ft_all_matches, m, am )
      o << *m;
    o << dec_indent;
  }
  return o;
}

} // namespace zorba

#endif /* NDEBUG */
/* vim:set et sw=2 ts=2: */
