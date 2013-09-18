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

bool operator==( location const &i, location const &j ) {
  return i.file_       == j.file_
      && i.line_       == j.line_
      && i.column_     == j.column_
      && i.line_end_   == j.line_end_
      && i.column_end_ == j.column_end_;
}

parameters const parameters::empty;

#define case_123456789 \
  case '1': case '2': case '3': case '4': case '5': \
  case '6': case '7': case '8': case '9'

parameters::parameters() {
}

void parameters::add_param( value_type const &s ) {
  params_.push_back( s );
  value_type &p = params_.back();
  //
  // We have to escape any literal \ characters in the parameter.
  //
  for ( value_type::size_type pos = 0;
        (pos = p.find( '\\', pos )) != value_type::npos;
        pos += 2 ) {
    p.replace( pos, 1, "\\\\" );
  }
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

inline
parameters::size_type parameters::to_index( value_type::value_type c ) const {
  return static_cast<size_type>( c - '0' );
}

void parameters::substitute( value_type *s ) const {
  value_type replacement;

  for ( size_type i = 1; i <= 9; ++i ) {
    value_type::size_type dollar_pos = value_type::npos;
    bool inside_braces = false;
    bool replace;

    for ( value_type::size_type pos = 0; pos < s->size(); ++pos ) {
      char c = s->at( pos );

      //
      // ordinary (non-substitution) character case
      //
      if ( dollar_pos == value_type::npos ) {
        switch ( c ) {
          case '$':
            dollar_pos = pos;
            replacement.clear();
            break;
          case '\\':
            //
            // We can't erase the \ here until the last iteration of the loop
            // since it has to do its job of escaping characters for all 9
            // passes.  Until then, simply skip over the next character (in
            // particular, the $) so it's not treated specially.
            //
            if ( i == 9 )
              s->erase( pos, 1 );
            else
              ++pos;
            break;
        }
        continue;
      }

      //
      // ${i} case
      //
      if ( inside_braces ) {
        switch ( c ) {
          case_123456789:
            if ( to_index( c ) == i ) {
              value_type const param( lookup_param( i ) );
              replace = !param.empty() || replace;
              replacement += param;
            } else
              dollar_pos = value_type::npos;
            break;
          case '}':
            inside_braces = false;
            goto replace_or_erase;
          case '\\':
            if ( pos + 1 < s->size() )
              c = s->at( ++pos );
            // no break;
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
          inside_braces = true;
          replace = false;
          break;
        case_123456789:
          if ( to_index( c ) == i ) {
            value_type const param( lookup_param( i ) );

            value_type::size_type pos2 = pos + 1;
            if ( pos2 < s->size() ) {
              switch ( s->at( pos2 ) ) {
                case '?':
                  if ( ++pos2 < s->size() ) {
                    //
                    // $i?<then>:<else> case
                    //
                    pos = pos2;
                    replace =
                      then_else( !param.empty(), *s, &pos, &replacement );
                    pos2 = pos + 1;
                    if ( pos2 < s->size() ) {
                      switch ( s->at( pos2 ) ) {
                        case ':':
                          pos = pos2 + 1;
                          replace =
                            then_else( param.empty(), *s, &pos, &replacement )
                            || replace;
                          break;
                        case '\\':
                          s->erase( pos2, 1 );
                          break;
                      } // switch
                    } // if ( pos2 ...
                    goto replace_or_erase;
                  } // if ( ++pos2 ...
                  break;
                case '\\':
                  s->erase( pos2, 1 );
                  break;
              } // switch
            } // if ( pos2 ...

            s->replace( dollar_pos, 2, param );
            pos = dollar_pos + param.length();
          } // if ( to_index( c ) ...
          // no break;
        default:
          dollar_pos = value_type::npos;
      } // switch

      continue;

replace_or_erase:
      value_type::size_type const replace_or_erase_len = pos - dollar_pos + 1;
      if ( replace ) {
        s->replace( dollar_pos, replace_or_erase_len, replacement );
        pos = dollar_pos + replacement.length() - 1;
      } else {
        s->erase( dollar_pos, replace_or_erase_len );
        pos = dollar_pos - 1;
      }
      dollar_pos = value_type::npos;

    } // for ( ... pos ...
  } // for ( ... i ...
}

bool parameters::then_else( bool expr, value_type const &s,
                            value_type::size_type *pos,
                            value_type *replacement ) const {
  value_type::value_type c = s[ *pos ];
  bool found_param = false, not_empty = false;

  switch ( c ) {
    case_123456789:
      found_param = true;
      if ( expr ) {
        *replacement = lookup_param( to_index( c ) );
        not_empty = !replacement->empty();
      }
      break;
    case '{':
      while ( ++*pos < s.size() ) {
        c = s[ *pos ];
        switch ( c ) {
          case_123456789:
            found_param = true;
            if ( expr ) {
              value_type const param = lookup_param( to_index( c ) );
              not_empty = !param.empty() || not_empty;
              *replacement += param;
            }
            break;
          case '}':
            goto done;
          case '\\':
            if ( *pos + 1 < s.size() )
              c = s[ ++*pos ];
            // no break;
          default:
            if ( expr )
              *replacement += c;
        } // switch
      } // while
      throw invalid_argument( "'}' expected for ?:" );
    default:
      throw invalid_argument(
        BUILD_STRING(
          '\'', c, "': invalid character after '", (expr ? '?' : ':'),
          "' (one of [1-9{] expected)"
        )
      );
  } // switch

done:
  return !found_param || not_empty;
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

diagnostic::kind Diagnostic::kind() const {
  return diagnostic::UNKNOWN_KIND;
}

char const* Diagnostic::message() const {
  return diagnostic::dict::lookup( qname().localname() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
