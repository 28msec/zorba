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

#include <cassert>
#include <cstring>

#include <zorba/err.h>

#include "util/ascii_util.h"
#include "util/string_util.h"

#include "assert.h"
#include "dict.h"

using namespace std;

namespace zorba {
namespace err {

///////////////////////////////////////////////////////////////////////////////

QName::~QName() {
  // out-of-line since it's virtual.
}

ostream& operator<<( ostream &o, QName const &qn ) {
  char const *const prefix = qn.prefix();
  if ( prefix && *prefix )
    o << prefix << ':';
  else {
    char const *const ns = qn.ns();
    if ( ns && *ns )
      o << '{' << ns << '}';
  }
  char const *const local = qn.localname();
  if ( local && *local )
    o << local;
  return o;
}

bool operator==( QName const &q1, QName const &q2 ) {
  return ztd::equals( q1.localname(), q2.localname() )
      && ztd::equals( q1.ns(), q2.ns() );
}

bool operator==( QName const &q1, char const *q2 ) {
  if ( q2 ) {
    if ( *q2 == '{' ) {
      //
      // Assume "James Clark notation," i.e., "{uri}localname".
      //
      char const *const q2_ns = q2 + 1;
      if ( char const *const rbrace = ::strchr( q2_ns, '}' ) )
        if ( char const *const q1_ns = q1.ns() )
          if ( ::strncmp( q1_ns, q2_ns, rbrace - q2_ns ) == 0 )
            if ( char const *const q1_local = q1.localname() )
              return ::strcmp( q1_local, rbrace + 1 ) == 0;
    } else {
      //
      // Assume a prefix is present, i.e., "prefix:localname".
      //
      if ( char const *const colon = ::strchr( q2, ':' ) )
        if ( char const *const q1_prefix = q1.prefix() )
          if ( ::strncmp( q1_prefix, q2, colon - q2 ) == 0 )
            if ( char const *const q1_local = q1.localname() )
              return ::strcmp( q1_local, colon + 1 ) == 0;
    }
  } else {
    //
    // q2 is NULL so q1 must be also.
    //
    return !q1.ns() && !q1.prefix() && !q1.localname();
  }
  return false;
}

ostream& operator<<( ostream &o, type t ) {
  //
  // It's OK for these to be only in English: they're looked-up in the error
  // dictionary later.
  //
  switch ( t ) {
    case XQUERY_DYNAMIC      : o << "dynamic"               ; break;
    case XQUERY_SERIALIZATION: o << "serialization"         ; break;
    case XQUERY_STATIC       : o << "static"                ; break;
    case XQUERY_TYPE         : o << "type"                  ; break;
    case XQUERY_USER_DEFINED : o << "user-defined"          ; break;
    case ZORBA_API           : o << "Zorba API"             ; break;
    case ZORBA_DDF           : o << "Zorba data-definition" ; break;
    case ZORBA_OS            : o << "operating system"      ; break;
    case ZORBA_SERIALIZATION : o << "Zorba serialization"   ; break;
    case ZORBA_STORE         : o << "Zorba store"           ; break;
    case ZORBA_XQP           : o << "Zorba"                 ; break;
    default                  : /* suppresses warning */       break;
  }
  return o;
}

} // namespace err

///////////////////////////////////////////////////////////////////////////////

namespace internal {
namespace err {

location const location::empty;
parameters const parameters::empty;

parameters::value_type parameters::lookup_param( size_type i ) const {
  assert( i >= 1 );
  // TODO: should be changed to assert() at some point
  if ( i > params_.size() )
    return value_type();
  value_type param( params_[ i - 1 ] );
  if ( !param.empty() && param[0] == ZED_PREFIX[0] )
    param = zorba::err::dict::lookup( param );
  return param;
}

void parameters::substitute( value_type *s ) const {
  bool replaced;
  do {
    replaced = false;

    size_type dollar_pos = value_type::npos;
    bool got_lbrace = false;
    value_type param, replacement;

    for ( size_type i = 0; i < s->size(); ++i ) {
      char const c = s->at( i );
      if ( dollar_pos != value_type::npos ) {

        //
        // ${i} case
        //
        if ( got_lbrace ) {
          switch ( c ) {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
              param = lookup_param( c - '0' );
              replacement += param;
              break;
            case '}': {
              size_type const len = i - dollar_pos + 1;
              if ( param.empty() )
                s->erase( dollar_pos, len );
              else {
                s->replace( dollar_pos, len, replacement );
                replaced = true;
                param.clear();
              }
              dollar_pos = value_type::npos;
              got_lbrace = false;
              replacement.clear();
              break;
            }
            default:
              replacement += c;
          }
          continue;
        }

        //
        // $i case
        //
        switch ( c ) {
          case '{':
            got_lbrace = true;
            break;
          case '1': case '2': case '3': case '4': case '5':
          case '6': case '7': case '8': case '9':
            s->replace( dollar_pos, 2, lookup_param( c - '0' ) );
            dollar_pos = value_type::npos;
            break;
        }
        continue;
      } // if ( dollar_pos ...

      if ( c == '$' )
        dollar_pos = i;
    } // for
  } while ( replaced );
}

} // namespace err
} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
