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

///////////////////////////////////////////////////////////////////////////////

// BUF_REP_CONSTRUCT_2CP_A_X
template<class ResultRepType>
void buf_rep<ResultRepType>::construct( const_pointer begin, const_pointer end,
                                        allocator_type const &a ) {
  if ( !begin )
    throw std::logic_error( "NULL not valid" );
  p_ = const_cast<pointer>( begin );    // TODO: This const_cast is evil!
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

///////////////////////////////////////////////////////////////////////////////

// REP_PROXY_BUF_REP_SWAP_X
template<class ResultRep>
void rep_proxy< buf_rep<ResultRep> >::
swap( rep_proxy< buf_rep<ResultRep> > &that ) {
  pointer   const tmp_p   = this->p_;
  size_type const tmp_cap = this->capacity();
  size_type const tmp_len = this->length();

  this->p_ = that.p_;
  this->set_capacity( that.capacity() );
  this->set_length( that.length() );

  that.p_ = tmp_p;
  that.set_capacity( tmp_cap );
  that.set_length( tmp_len );
}

// REP_PROXY_BUF_REP_TAKE_X
template<class ResultRep>
void rep_proxy< buf_rep<ResultRep> >::
take( rep_proxy< buf_rep<ResultRep> > &that, allocator_type const &this_alloc,
      allocator_type const &that_alloc ) {
  if ( *this != that ) {
    this->p_ = that.p_;
    this->set_capacity( that.capacity() );
    this->set_length( that.length() );
    that.dispose( that_alloc );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace rstring_classes
} // namespace zorba

#endif /* ZORBA_RSTRING_BUF_REP_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
