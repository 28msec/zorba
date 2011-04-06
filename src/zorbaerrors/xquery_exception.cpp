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

#include <util/fs_util.h>
#include <util/uri_util.h>

#include "dict.h"
#include "xquery_exception.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

XQueryException::XQueryException( Error const &error, char const *throw_file,
                                  line_type throw_line,
                                  char const *message ) :
  ZorbaException( error, throw_file, throw_line, message )
{
}

XQueryException::XQueryException( XQueryException const &from ) :
  ZorbaException( from ),
  source_loc_( from.source_loc_ ),
  query_trace_( from.query_trace_ )
{
  // This copy constructor isn't necessary: the compiler-generated default copy
  // constructor would work just fine.  It is defined explicitly, however, so
  // as to future-proof the code and keep ABI compatibility.
}

XQueryException::~XQueryException() throw() {
  // out-of-line since it's virtual
}

XQueryException& XQueryException::operator=( XQueryException const &from ) {
  //
  // This assignment operator isn't necessary: the compiler-generated default
  // assignment operator would work just fine.  It is defined explicitly,
  // however, so as to future-proof the code and keep ABI compatibility.
  //
  if ( &from != this ) {
    ZorbaException::operator=( from );
    source_loc_  = from.source_loc_;
    query_trace_ = from.query_trace_;
  }
  return *this;
}

auto_ptr<ZorbaException> XQueryException::clone() const {
  return auto_ptr<ZorbaException>( new XQueryException( *this ) );
}

void XQueryException::set_source( char const *uri, line_type line,
                                  column_type col ) {
  source_loc_.set( uri, line, col );
}

void XQueryException::polymorphic_throw() const {
  throw *this;
}

ostream& XQueryException::print( ostream &o ) const {
  if ( has_source() ) {

    char const *const u = source_uri();
    if ( u && *u ) {
      switch ( uri::get_scheme( u ) ) {
        case uri::none:
        case uri::file:
          try {
            o << '<' << fs::get_normalized_path( u ) << '>';
            break;
          }
          catch ( ... ) {
            // fall back to printing as a URI
          }
          // no break;
        default:
          o << '<' << u << '>';
      }
    } else
      o << '(' << err::dict::lookup( ZED( NoSourceURI ) ) << ')';

    if ( source_line() ) {
      o << ':' << source_line();
      if ( source_column() )
        o << ',' << source_column();
      o << ':';
    }

    o << ' ';
  }
  return ZorbaException::print( o );
}

///////////////////////////////////////////////////////////////////////////////

namespace internal {

XQueryException make_xquery_exception( char const *throw_file,
                                       ZorbaException::line_type throw_line,
                                       Error const &error,
                                       err::parameters const &params,
                                       err::location const &loc ) {
  err::parameters::value_type message( error.message() );
  params.substitute( &message );
  XQueryException xe( error, throw_file, throw_line, message.c_str() );
  if ( loc )
    xe.set_source( loc.file(), loc.line(), loc.column() );
  return xe;
}

XQueryException* new_xquery_exception( char const *throw_file,
                                       ZorbaException::line_type throw_line,
                                       Error const &error,
                                       internal::err::parameters const &params,
                                       internal::err::location const &loc ) {
  internal::err::parameters::value_type message( error.message() );
  params.substitute( &message );
  XQueryException *const xe =
    new XQueryException( error, throw_file, throw_line, message.c_str() );
  if ( loc )
    xe->set_source( loc.file(), loc.line(), loc.column() );
  return xe;
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
