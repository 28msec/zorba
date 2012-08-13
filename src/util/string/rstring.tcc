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

#ifndef ZORBA_RSTRING_TCC
#define ZORBA_RSTRING_TCC

#ifndef ZORBA_RSTRING_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_RSTRING_H */

#include <algorithm>

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef min
#undef max
#endif

namespace zorba {

////////// out-of-line member function definitions ////////////////////////////

// RSTRING_APPEND_SAFE_CP_ST_CP_ST_X
template<class Rep> void
rstring<Rep>::append_safe( const_pointer s1, size_type n1, const_pointer s2,
                           size_type n2 ) {
  if ( size_type add_len = n1 + n2 ) {
    size_type const len = size();
    mutate( len, 0, add_len );
    if ( n1 )
      Rep::copy( data() + len, s1, n1 );
    if ( n2 )
      Rep::copy( data() + len + n1, s2, n2 );
  }
}

// RSTRING_APPEND_RS_2ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::append( rstring const &s, size_type s_pos, size_type s_n ) {
  s.check_pos( s_pos, "append" );
  s_n = s.limit_n( s_pos, s_n );
  if ( s_n )
    append_safe( s.data() + s_pos, s_n );
  return *this;
}

// RSTRING_APPEND_TS_2ST_X
template<class Rep>
template<class Rep2> rstring<Rep>&
rstring<Rep>::append( rstring<Rep2> const &s, size_type s_pos, size_type s_n ) {
  s.check_pos( s_pos, "append" );
  s_n = s.limit_n( s_pos, s_n );
  if ( s_n )
    append_safe( s.data() + s_pos, s_n );
  return *this;
}

// RSTRING_APPEND_SS_2ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::append( std_string const &s, size_type s_pos, size_type n ) {
  s.at( s_pos );
  n = limit_n( s_pos, s.size(), n );
  if ( n )
    append_safe( s.data() + s_pos, n );
  return *this;
}

// RSTRING_APPEND_CP_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::append( const_pointer s, size_type s_len ) {
  if ( s_len ) {
    size_type const len = size();
    if ( disjunct( s ) ) {
      mutate( len, 0, s_len );
    } else {
      size_type const off = s - data();
      mutate( len, 0, s_len );
      s = data() + off;
    }
    Rep::copy( data() + len, s, s_len );
  }
  return *this;
}

// RSTRING_APPEND_ST_VT_X
template<class Rep> rstring<Rep>&
rstring<Rep>::append( size_type n, value_type c ) {
  if ( n ) { 
    size_type const len = size();
    mutate( len, 0, n );
    assign_opt( data() + len, n, c );
  }
  return *this;
}

template<class Rep> void
rstring<Rep>::push_back( value_type c ) {
  size_type const len = size();
  mutate( len, 0, 1 );
  traits_type::assign( data()[ len ], c );
}

// RSTRING_ASSIGN_RS_X
template<class Rep> rstring<Rep>&
rstring<Rep>::assign( rstring const &s ) {
  if ( rep() != s.rep() ) {
    rep().dispose( get_allocator() );
    rep().share( s.rep(), get_allocator(), s.get_allocator() );
  }
  return *this;
}

// RSTRING_ASSIGN_CP_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::assign( const_pointer s, size_type n ) {
  if ( disjunct( s ) || rep().is_shared() )
    replace_safe( 0, size(), s, n );
  else {
    size_type const pos = s - data();
    if ( pos > n )
      Rep::copy( data(), s, n );
    else
      Rep::move( data(), s, n );
    rep().set_length( n );
  }
  return *this;
}

// RSTRING_ASSIGN_P_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::assign( pointer s, size_type n ) {
  allocator_type const a = get_allocator();
  rep().dispose( a );
  rep().construct( s, s + n, a );
  return *this;
}

// RSTRING_CONSTRUCT_CP_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::wrap_memory( const_pointer s, size_type n ) {
  allocator_type const a = get_allocator();
  rep().dispose( a );
  rep().construct( s, s + n, a );
  return *this;
}

// RSTRING_COMPARE_RS_X
template<class Rep> int
rstring<Rep>::compare( rstring const &s ) const {
  size_type const len = size();
  size_type const s_len = s.size();
  size_type const n = std::min( len, s_len );
  int const comp = traits_type::compare( data(), s.data(), n );
  return comp ? comp : compare( len, s_len );
}

// RSTRING_COMPARE_CP_ST_X
template<class Rep> int
rstring<Rep>::compare( const_pointer s, size_type s_n ) const {
  size_type const len = size();
  size_type const min_n = std::min( len, s_n );
  int const comp = traits_type::compare( data(), s, min_n );
  return comp ? comp : compare( len, s_n );
}

// RSTRING_COMPARE_2ST_RS_X
template<class Rep> int
rstring<Rep>::compare( size_type pos, size_type n, rstring const &s ) const {
  check_pos( pos, "compare" );
  n = limit_n( pos, n );
  size_type const s_len = s.size();
  size_type const min_n = std::min( n, s_len );
  int const comp = traits_type::compare( data() + pos, s.data(), min_n );
  return comp ? comp : compare( n, s_len );
}

// RSTRING_COMPARE_2ST_CP_X
template<class Rep> int
rstring<Rep>::compare( size_type pos, size_type n, const_pointer s ) const {
  check_pos( pos, "compare" );
  n = limit_n( pos, n );
  size_type const s_len = traits_type::length( s );
  size_type const min_n = std::min( n, s_len );
  int const comp = traits_type::compare( data() + pos, s, min_n );
  return comp ? comp : compare( n, s_len );
}

// RSTRING_COMPARE_2ST_RS_2ST_X
template<class Rep> int
rstring<Rep>::compare( size_type pos, size_type n, rstring const &s,
                       size_type s_pos, size_type s_n ) const {
  check_pos( pos, "compare" );
  s.check_pos( s_pos, "compare" );
  n = limit_n( pos, n );
  s_n = limit_n( s_pos, s_n );
  size_type const min_n = std::min( n, s_n );
  int const comp =
    traits_type::compare( data() + pos, s.data() + s_pos, min_n );
  return comp ? comp : compare( n, s_n );
}

// RSTRING_COMPARE_2ST_CP_ST_X
template<class Rep> int
rstring<Rep>::compare( size_type pos, size_type n, const_pointer s,
                       size_type s_n ) const {
  check_pos( pos, "compare" );
  n = limit_n( pos, n );
  size_type const min_n = std::min( n, s_n );
  int const comp = traits_type::compare( data() + pos, s, min_n );
  return comp ? comp : compare( n, s_n );
}

// RSTRING_COPY_P_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::copy( pointer buf, size_type n, size_type pos ) const {
  check_pos( pos, "copy" );
  n = limit_n( pos, n );
  if ( n )
    Rep::copy( buf, data(), n );
  return n;
}

// RSTRING_FIND_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find( const_pointer s, size_type pos, size_type n ) const {
  size_type const len = size();
  if ( !n )
    return pos <= len ? pos : npos;
  if ( n <= len ) {
    for ( ; pos <= len - n; ++pos )
      if ( traits_type::eq( data()[ pos ], s[0] ) &&
           traits_type::compare( data() + pos + 1, s + 1, n - 1 ) == 0 )
        return pos;
  }
  return npos;
}

// RSTRING_FIND_VT_ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find( value_type c, size_type pos ) const {
  size_type const len = size();
  if ( pos < len ) {
    if ( const_pointer p = traits_type::find( data() + pos, len - pos, c ) )
      return p - data();
  }
  return npos;
}

// RSTRING_FIND_FIRST_OF_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( const_pointer s, size_type pos,
                             size_type s_n ) const {
  for ( ; s_n && pos < size(); ++pos ) {
    if ( traits_type::find( s, s_n, data()[ pos ] ) )
      return pos;
  }
  return npos;
}

// RSTRING_FIND_FIRST_NOT_OF_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( const_pointer s, size_type pos,
                                 size_type s_n ) const {
  for ( ; pos < size(); ++pos )
    if ( !traits_type::find( s, s_n, data()[ pos ] ) )
      return pos;
  return npos;
}

// RSTRING_FIND_FIRST_NOT_OF_VT_ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( value_type c, size_type pos ) const {
  for ( ; pos < size(); ++pos )
    if ( !traits_type::eq( data()[ pos ], c ) )
      return pos;
  return npos;
}

// RSTRING_FIND_LAST_OF_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( const_pointer s, size_type pos,
                            size_type s_n ) const {
  size_type len = size();
  if ( len && s_n ) {
    if ( --len > pos )
      len = pos;
    do {
      if ( traits_type::find( s, s_n, data()[ len ] ) )
        return len;
    } while ( --len );
  }
  return npos;
}

// RSTRING_FIND_LAST_NOT_OF_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( const_pointer s, size_type pos,
                                size_type s_n ) const {
  if ( size_type len = size() ) {
    if ( --len > pos )
      len = pos;
    do {
      if ( !traits_type::find( s, s_n, data()[ len ] ) )
        return len;
    } while ( len-- );
  }
  return npos;
}

// RSTRING_FIND_LAST_NOT_OF_VT_ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( value_type c, size_type pos ) const {
  if ( size_type len = size() ) {
    if ( --len > pos )
      len = pos;
    do {
      if ( !traits_type::eq( data()[ len ], c ) )
        return len;
    } while ( len-- );
  }
  return npos;
}

// RSTRING_RFIND_CP_2ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::rfind( const_pointer s, size_type pos, size_type s_n ) const {
  size_type const len = size();
  if ( s_n <= len ) {
    pos = std::min( len - s_n, pos );
    do {
      if ( traits_type::compare( data() + pos, s, s_n ) == 0 )
        return pos;
    } while ( pos-- > 0 );
  }
  return npos;
}

// RSTRING_RFIND_VT_ST_X
template<class Rep> typename rstring<Rep>::size_type
rstring<Rep>::rfind( value_type c, size_type pos ) const {
  if ( size_type len = size() ) {
    if ( --len > pos )
      len = pos;
    for ( ++len; len-- > 0; )
      if ( traits_type::eq( data()[ len ], c ) )
        return len;
  }
  return npos;
}

// RSTRING_INSERT_ST_CP_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::insert( size_type pos, const_pointer s, size_type s_n ) {
  check_pos( pos, "insert" );
  if ( disjunct( s ) || rep().is_shared() )
    return replace_safe( pos, 0, s, s_n );
  size_type const off = s - data();
  mutate( pos, 0, s_n );
  s = data() + off;
  pointer p = data() + pos;
  if ( s + s_n <= p )
    Rep::copy( p, s, s_n );
  else if ( s >= p )
    Rep::copy( p, s + s_n, s_n );
  else {
    size_type const nleft = p - s;
    Rep::copy( p, s, nleft );
    Rep::copy( p + nleft, p + s_n, s_n - nleft );
  }
  return *this;
}

template<class Rep> void
rstring<Rep>::mutate( size_type pos, size_type n1, size_type n2 ) {
  size_type const old_size = size();
  size_type const new_size = old_size + n2 - n1;
  size_type const how_much = old_size - pos - n1;

  if ( new_size > capacity() || rep().is_shared() ) {
    // must reallocate
    allocator_type const a = get_allocator();
    // TODO: if new_size == 0, use empty_rep()

    rep_proxy_type new_rep;

    // The call to construct will throw an error if the RepType is the buf_rep
    new_rep.realloc( new_size, capacity(), a );

    if ( pos )
      Rep::copy( new_rep.data(), data(), pos );
    if ( how_much )
      Rep::copy( new_rep.data() + pos + n2, data() + pos + n1, how_much );

    rep().take( new_rep, a, a );
  }
  else if ( how_much && n1 != n2 ) {
    // in-place
    Rep::move( data() + pos + n2, data() + pos + n1, how_much );
  }
  rep().set_length( new_size );
}

// RSTRING_REPLACE_2ST_CP_ST_X
template<class Rep> rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, const_pointer s,
                       size_type s_n ) {
  check_pos( pos, "replace" );
  n = limit_n( pos, n );
  if ( disjunct( s ) || rep().is_shared() )
    return replace_safe( pos, n, s, s_n );
  bool left = s + s_n <= data() + pos;
  if ( left || data() + pos + n <= s ) {
    size_type off = s - data();
    if ( !left )
      off += s_n - n;
    mutate( pos, n, s_n );
    Rep::copy( data() + pos, data() + off, s_n );
  }
  return *this;
}

// RSTRING_REPLACE_2I_2II_X
template<class Rep>
template<class InputIterator> rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j,
                       InputIterator ii, InputIterator ij ) {
  rstring const temp( ii, ij );
  return replace_safe( i - ibegin(), j - i, temp.data(), temp.size() );
}

// RSTRING_RESIZE_ST_VT_X
template<class Rep> void
rstring<Rep>::resize( size_type new_size, value_type c ) {
  size_type const len = size();
  if ( len < new_size )
    append( new_size - len, c);
  else if ( new_size < len )
    erase( new_size );
}

// RSTRING_SWAP_RS_X
template<class Rep> void
rstring<Rep>::swap( rstring &s ) {
  if ( !rep().is_sharable() )
    rep().set_sharable();

  if ( !s.rep().is_sharable() )
    s.rep().set_sharable();

  if ( get_allocator() == s.get_allocator() ) {
    rep().swap( s.rep() );
  } else {
    rstring const temp1( ibegin(), iend(), s.get_allocator() );
    rstring const temp2( s.ibegin(), s.iend(), get_allocator() );
    *this = temp2;
    s = temp1;
  }
}

////////// out-of-line global function definitions ////////////////////////////

template<typename CharType,class TraitsType,class Rep>
std::basic_istream<CharType,TraitsType>&
getline( std::basic_istream<CharType,TraitsType> &is, rstring<Rep> &s,
         typename rstring<Rep>::value_type delim ) {
  typedef std::basic_istream<CharType,TraitsType> istream_type;
  typedef typename istream_type::int_type int_type;
  typedef std::basic_streambuf<CharType,TraitsType> streambuf_type;
  typedef rstring<Rep> string_type;
  typedef typename string_type::size_type size_type;

  std::ios_base::iostate err = std::ios_base::iostate( std::ios_base::goodbit );
  size_type extracted = 0;
  int_type const idelim = TraitsType::to_int_type( delim );
  int_type const eof = TraitsType::eof();

  s.clear();
  try {
    streambuf_type *const sb = is.rdbuf();
    int_type c = sb->sgetc();

    while ( !TraitsType::eq_int_type( c, eof ) &&
            !TraitsType::eq_int_type( c, idelim ) ) {
      s += TraitsType::to_char_type( c );
      ++extracted;
      c = sb->snextc();
    }
    if ( TraitsType::eq_int_type( c, eof ) )
      err |= std::ios_base::eofbit;
    else if ( TraitsType::eq_int_type( c, idelim ) ) {
      ++extracted;
      sb->sbumpc();
    } else
      err |= std::ios_base::failbit;
  }
  catch ( ... ) {
    is.setstate( std::ios_base::badbit );
  }
  if ( !extracted )
    err |= std::ios_base::failbit;
  if ( err )
    is.setstate( err );
  return is;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_RSTRING_TCC */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
