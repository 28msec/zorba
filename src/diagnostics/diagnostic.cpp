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

#include <iostream>

#include <zorba/error.h>

#include "util/ascii_util.h"
#include "util/string_util.h"

#include "assert.h"
#include "dict.h"

using namespace std;

namespace zorba {
namespace diagnostic {

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
    if ( ns && *ns ) {
      //
      // From <http://www.w3.org/TR/xquery-30/#id-identifying-errors>:
      //
      //    An error can be represented by a URI reference that is derived from
      //    the error QName as follows: an error with namespace URI NS and
      //    local part LP can be represented as the URI reference NS#LP . For
      //    example, an error whose QName is err:XPST0017 could be represented
      //    as http://www.w3.org/2005/xqt-errors#XPST0017.
      //
      o << ns << '#';
    }
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
    } else if ( char const *const hash = ::strchr( q2, '#' ) ) {
      //
      // XQuery 3.0, 2.3.2 Identifying and Reporting Errors:
      //
      //    An error can be represented by a URI reference that is derived from
      //    the error QName as follows: an error with namespace URI NS and
      //    local part LP can be represented as the URI reference NS#LP . For
      //    example, an error whose QName is err:XPST0017 could be represented
      //    as http://www.w3.org/2005/xqt-errors#XPST0017.
      //
      if ( char const *const q1_ns = q1.ns() )
        if ( ::strncmp( q1_ns, q2, hash - q2 ) == 0 )
          if ( char const *const q1_local = q1.localname() )
            return ::strcmp( q1_local, hash + 1 ) == 0;
    } else if ( char const *colon = ::strchr( q2, ':' ) ) {
      //
      // Assume EQName notation, i.e., URILiteral:NCName.
      //
      if ( (colon = strchr( colon + 1, ':' )) )
        if ( char const *const q1_ns = q1.ns() )
          if ( ::strncmp( q1_ns, q2, colon - q2 ) == 0 )
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

ostream& operator<<( ostream &o, category c ) {
  //
  // It's OK for these to be only in English: they're looked-up in the
  // diagnostic dictionary later.
  //
  switch ( c ) {
    case UNKNOWN_CATEGORY    : o << "unknown"               ; break;

    //   XQUERY_CORE         : /* nothing */
    case XQUERY_FULL_TEXT    : o << "full-text"             ; break;
    case XQUERY_SCRIPTING    : o << "scripting"             ; break;
    case XQUERY_SERIALIZATION: o << "serialization"         ; break;
    case XQUERY_UPDATE       : o << "update"                ; break;
    case XQUERY_USER_DEFINED : o << "user-defined"          ; break;

    case ZORBA_API           : o << "Zorba API"             ; break;
    case ZORBA_DDF           : o << "Zorba data-definition" ; break;
    case ZORBA_DEBUGGER      : o << "Zorba debugger"        ; break;
    case ZORBA_OS            : o << "operating system"      ; break;
    case ZORBA_SERIALIZATION : o << "Zorba serialization"   ; break;
    case ZORBA_STORE         : o << "Zorba store"           ; break;
    case ZORBA_XQP           : o << "Zorba"                 ; break;

    default                  : /* suppresses warning */       break;
  }
  return o;
}

ostream& operator<<( ostream &o, kind k ) {
  //
  // It's OK for these to be only in English: they're looked-up in the
  // diagnostic dictionary later.
  //
  switch ( k ) {
    case UNKNOWN_KIND  : o << "unknown"; break;
    case XQUERY_DYNAMIC: o << "dynamic"; break;
    case XQUERY_STATIC : o << "static" ; break;
    case XQUERY_TYPE   : o << "type"   ; break;
  }
  return o;
}

} // namespace diagnostic

///////////////////////////////////////////////////////////////////////////////

namespace internal {

SystemDiagnosticBase::map_type& SystemDiagnosticBase::get_map() {
  static map_type m;
  return m;
}

namespace diagnostic {

location const location::empty;
parameters const parameters::empty;

parameters::parameters() {
}

parameters::value_type parameters::lookup_param( size_type i ) const {
  assert( i >= 1 );
  assert( i <= 9 );
  if ( i > params_.size() )
    return value_type();
  value_type param( params_[ i - 1 ] );
  if ( !param.empty() && param[0] == ZED_PREFIX[0] )
    param = zorba::diagnostic::dict::lookup( param );
  return param;
}

void parameters::substitute( value_type *s ) const {
  for ( size_type i = 1; i <= 9; ++i ) {
    size_type dollar_pos = value_type::npos;
    bool got_lbrace = false;
    value_type param, replacement;

    for ( size_type pos = 0; pos < s->size(); ++pos ) {
      char const c = s->at( pos );
      if ( dollar_pos != value_type::npos ) {

        //
        // ${i} case
        //
        if ( got_lbrace ) {
          switch ( c ) {
            case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
              if ( c - '0' == static_cast<int>( i ) ) {
                param = lookup_param( i );
                replacement += param;
              } else
                dollar_pos = value_type::npos;
              break;
            case '}': {
              size_type const len = pos - dollar_pos + 1;
              if ( param.empty() )
                s->erase( dollar_pos, len );
              else {
                s->replace( dollar_pos, len, replacement );
                pos = dollar_pos + replacement.length();
              }
              dollar_pos = value_type::npos;
              got_lbrace = false;
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
            if ( c - '0' == static_cast<int>( i ) ) {
              replacement = lookup_param( i );
              s->replace( dollar_pos, 2, replacement );
              pos = dollar_pos + replacement.length();
            }
            // no break;
          default:
            dollar_pos = value_type::npos;
        }

        continue;
      } // if ( dollar_pos ...

      if ( c == '$' ) {
        dollar_pos = pos;
        param.clear();
        replacement.clear();
      }
    } // for ( ... pos ...
  } // for ( ... i ...
}

} // namespace diagnostic
} // namespace internal

///////////////////////////////////////////////////////////////////////////////

Diagnostic::~Diagnostic() {
  // out-of-line since it's virtual
}

void Diagnostic::destroy() const {
  delete this;
}

diagnostic::category Diagnostic::category() const {
  return diagnostic::UNKNOWN_CATEGORY;
}

diagnostic::kind Diagnostic::kind() const {
  return diagnostic::UNKNOWN_KIND;
}

char const* Diagnostic::message() const {
  return diagnostic::dict::lookup( qname().localname() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
