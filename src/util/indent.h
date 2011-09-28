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
#ifndef ZORBA_INDENT_H
#define ZORBA_INDENT_H

#include <iostream>

namespace zorba {

int get_ostream_indent_index();

/**
 * Gets the current indentation amount for the given ostream.
 *
 * @param os The ostream to get the indentation amount for.
 * @return Returns a modifyable reference to said indentation.
 */
template<typename charT,typename Traits> inline
long& get_indent( std::basic_ostream<charT,Traits> &os ) 
{
  //
  // See: "Standard C++ IOStreams and Locales: Advanced Programmer's Guide and
  // Reference," Angelika Langer and Klaus Kreft, Addison-Wesley, 2000, section
  // 3.3.1: "Using Stream Storage for Private Use: iword, pword, and xalloc."
  //
  return os.iword( get_ostream_indent_index() );
}

/**
 * Increments the indentation amount by 2 for the given ostream.
 *
 * @param os The ostream to increment the indentation amount of.
 * @return Returns the given ostream.
 */
template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
inc_indent( std::basic_ostream<charT,Traits> &os ) 
{
  get_indent( os ) += 2;
  return os;
}

/**
 * Decrements the indentation amount by 2 for the given ostream.
 *
 * @param os The ostream to decrement the indentation amount of.
 * @return Returns the given ostream.
 */
template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
dec_indent( std::basic_ostream<charT,Traits> &os ) 
{
  long &indent = get_indent( os );
  if ( (indent -= 2) < 0 )
    indent = 0;
  return os;
}

/**
 * Emits the number of space characters equal to the current indentation amount
 * of the given ostream to the given ostream.
 * 
 * @param os The ostream to emit the space characters to.
 * @return Returns the given ostream.
 */
template<typename charT,typename Traits> inline
std::basic_ostream<charT,Traits>&
indent( std::basic_ostream<charT,Traits> &os ) 
{
  for ( int i = get_indent( os ); i > 0; --i )
    os << ' ';
  return os;
}

} // namespace zorba

#endif /* ZORBA_INDENT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
