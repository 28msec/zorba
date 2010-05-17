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

#ifndef ZORBA_INDENT_H
#define ZORBA_INDENT_H

#include <iostream>

namespace zorba {

int get_ostream_indent_index();

template<typename charT,typename Traits> inline
long& get_indent( std::basic_ostream<charT,Traits> &os ) {
  return os.iword( get_ostream_indent_index() );
}

template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
inc_indent( std::basic_ostream<charT,Traits> &os ) {
  get_indent( os ) += 2;
  return os;
}

template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
dec_indent( std::basic_ostream<charT,Traits> &os ) {
  long &indent = get_indent( os );
  if ( (indent -= 2) < 0 )
    indent = 0;
  return os;
}

template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
indent( std::basic_ostream<charT,Traits> &os ) {
  for ( int i = get_indent( os ); i > 0; --i )
    os << ' ';
  return os;
}

} // namespace zorba

#endif /* ZORBA_INDENT_H */
/* vim:set et sw=2 ts=2: */
