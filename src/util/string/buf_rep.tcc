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

#ifndef ZORBA_RSTRING_BUF_REP_TCC
#define ZORBA_RSTRING_BUF_REP_TCC

#ifndef ZORBA_RSTRING_BUF_REP_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_RSTRING_BUF_REP_H */

#include <stdexcept>

namespace zorba {
namespace rstring_classes {

// BUF_REP_CONSTRUCT_2CP_A_X
template<class ResultRepType>
void buf_rep<ResultRepType>::construct( const_pointer begin, const_pointer end,
                                        allocator_type const &a ) {
  if ( begin == end )
    return;
  if ( !begin )
    throw std::logic_error( "NULL not valid" );
  p_ = const_cast<pointer>(begin);
  size_type const cap = end - begin;
  this->set_capacity( cap );
  //
  // Determine the actual length of the string by looking for a NULL.  We don't
  // use traits_type::length() because the string might not have a NULL.
  //
  size_type len = cap;
  for ( const_pointer i = begin; i != end; ++i )
    if ( !*i ) {
      len = i - begin;
      break;
    }
  this->set_length( len );
}

} // namespace rstring_classes
} // namespace zorba

#endif /* ZORBA_RSTRING_BUF_REP_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
