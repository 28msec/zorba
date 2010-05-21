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

#include "runtime/full_text/ft_match.h"
#include "zorbautils/indent.h"
#include "zorbautils/stl_util.h"

using namespace std;

namespace zorba {

ostream& operator<<( ostream &o, ft_string_match const &sm ) {
  return  o << "{SM: "
            << static_cast<ft_token_span const&>( sm )
            << " query_pos=" << sm.query_pos
            << " contiguous=" << (sm.is_contiguous ? 'T' : 'F')
            << '}';
}

ostream& operator<<( ostream &o, ft_match const &m ) {
  o << indent << "ft_match @ " << hex << (unsigned long)&m << endl;
  if ( !m.includes.empty() ) {
    o << inc_indent << indent << "INCLUDES\n" << inc_indent;
    FOR_EACH( ft_match::includes_t, i, m.includes )
      o << indent << *i << endl;
    o << dec_indent << dec_indent;
  }
  if ( !m.excludes.empty() ) {
    o << inc_indent << indent << "EXCLUDES\n" << indent;
    FOR_EACH( ft_match::excludes_t, e, m.excludes )
      o << indent << *e << endl;
    o << dec_indent << dec_indent;
  }
  return o;
}

ostream& operator<<( ostream &o, ft_all_matches const &am ) {
  o << indent << "ft_all_matches @ " << hex << (unsigned long)&am << endl;
  if ( !am.empty() ) {
    o << inc_indent;
    FOR_EACH( ft_all_matches, m, am )
      o << *m;
    o << dec_indent;
  }
  return o;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
