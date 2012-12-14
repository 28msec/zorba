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

#include <stdexcept>

#include "common/common.h"
#include "util/string_util.h"
#include "zorbatypes/numconversions.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#define RANGE_ERROR(N,TYPE) \
  std::range_error( BUILD_STRING( '"', (N), "\": number can not be represented as an " TYPE ) )

xs_int to_xs_int( xs_double const &d ) {
  zstring const temp( d.toIntegerString() );
  return ztd::aton<xs_int>( temp.c_str() );
}

xs_int to_xs_int( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_int>( temp.c_str() );
#else
  if ( i.is_xs_int() )
    return static_cast<xs_int>( i.value_ );
  throw RANGE_ERROR( i, "xs:int" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

xs_long to_xs_long( xs_decimal const &d ) {
  if ( d.is_xs_long() ) {
    zstring const temp( d.toString() );
    return ztd::aton<xs_long>( temp.c_str() );
  }
  throw RANGE_ERROR( d, "xs:long" );
}

xs_long to_xs_long( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_long>( temp.c_str() );
#else
  if ( i.is_xs_long() )
    return static_cast<xs_long>( i.value_ );
  throw RANGE_ERROR( i, "xs:long" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

#ifndef ZORBA_WITH_BIG_INTEGER
xs_long to_xs_long( xs_nonNegativeInteger const &i ) {
  zstring const temp( i.toString() );
  return ztd::aton<xs_long>( temp.c_str() );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

xs_unsignedByte to_xs_unsignedByte( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_unsignedByte>( temp.c_str() );
#else
  if ( i.is_xs_unsignedByte() )
    return static_cast<xs_unsignedByte>( i.value_ );
  throw RANGE_ERROR( i, "xs:unsignedByte" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

xs_unsignedShort to_xs_unsignedShort( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_unsignedShort>( temp.c_str() );
#else
  if ( i.is_xs_unsignedShort() )
    return static_cast<xs_unsignedShort>( i.value_ );
  throw RANGE_ERROR( i, "xs:unsignedShort" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

xs_unsignedInt to_xs_unsignedInt( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_unsignedInt>( temp.c_str() );
#else
  if ( i.is_xs_unsignedInt() )
    return static_cast<xs_unsignedInt>( i.value_ );
  throw RANGE_ERROR( i, "xs:unsignedInt" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

xs_unsignedLong to_xs_unsignedLong( xs_integer const &i ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  zstring const temp( i.toString() );
  return ztd::aton<xs_unsignedLong>( temp.c_str() );
#else
  if ( i.is_xs_unsignedLong() )
    return static_cast<xs_unsignedLong>( i.value_ );
  throw RANGE_ERROR( i, "xs:unsignedLong" );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
