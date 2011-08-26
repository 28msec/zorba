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

#include <sstream>

#include <zorba/zorba_exception.h>
#include <zorba/xquery_warning.h>

#include "dict.h"

#ifndef NDEBUG
#include <cstdlib>                      /* for abort() */
ZORBA_DLL_PUBLIC bool g_abort_on_error;
#endif /* NDEBUG */

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

ZorbaException::ZorbaException( Diagnostic const &diagnostic,
                                char const *raise_file, line_type raise_line,
                                char const *message ) :
  diagnostic_( diagnostic.clone() ),
  raise_file_( raise_file ),
  raise_line_( raise_line ),
  message_( message )
{
#ifndef NDEBUG
  if ( g_abort_on_error )
    abort();
#endif /* NDEBUG */
}

ZorbaException::ZorbaException( ZorbaException const &from ) :
  std::exception( from ),
  diagnostic_( from.diagnostic_->clone() ),
  raise_file_( from.raise_file_ ),
  raise_line_( from.raise_line_ ),
  message_( from.message_ )
{
}

ZorbaException::ZorbaException( serialization::Archiver &ar ) 
{
}

ZorbaException::~ZorbaException() throw() {
  diagnostic_->destroy();
}

ZorbaException& ZorbaException::operator=( ZorbaException const &from ) {
  if ( &from != this ) {
    std::exception::operator=( from );
    diagnostic_->destroy();
    diagnostic_ = from.diagnostic_->clone();
    raise_file_ = from.raise_file_;
    raise_line_ = from.raise_line_;
    message_    = from.message_;
  }
  return *this;
}

unique_ptr<ZorbaException> ZorbaException::clone() const {
  return unique_ptr<ZorbaException>( new ZorbaException( *this ) );
}

void ZorbaException::polymorphic_throw() const {
  throw *this;
}

ostream& ZorbaException::print( ostream &o ) const {
  //
  // We need to create an error phrase (e.g., "static error") and look that up
  // as a unit rather than looking up the error kind word and "error"
  // separately because many languages have the word order reversed (e.g.,
  // "static error" becomes "erreur statique" in French).
  //
  ostringstream oss;
  oss << ZED_PREFIX;

  streampos pos = oss.tellp();
  Diagnostic const &d = diagnostic();
  oss << d.category();
  if ( oss.tellp() != pos )             // emit ' ' only if non-empty category
    oss << ' ';

  if ( diagnostic::kind const k = d.kind() )
    oss << k << ' ';

  oss << (dynamic_cast<ZorbaWarningCode const*>( &d ) ? "warning" : "error");

  o << diagnostic::dict::lookup( oss.str() ) << " [" << d.qname() << ']';

  if ( char const *const w = what() )
    if ( *w )
      o << ": " << w;

#ifndef NDEBUG
  o << "; raised at " << raise_file() << ':' << raise_line();
#endif
  return o;
}

char const* ZorbaException::what() const throw() {
  return message_.c_str();
}

///////////////////////////////////////////////////////////////////////////////

ZorbaException
make_zorba_exception( char const *raise_file,
                      ZorbaException::line_type raise_line,
                      Diagnostic const &diagnostic,
                      internal::diagnostic::parameters const &params ) {
  internal::diagnostic::parameters::value_type message( diagnostic.message() );
  params.substitute( &message );
  return ZorbaException( diagnostic, raise_file, raise_line, message.c_str() );
}

ZorbaException*
new_zorba_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Diagnostic const &diagnostic,
                     internal::diagnostic::parameters const &params ) {
  internal::diagnostic::parameters::value_type message( diagnostic.message() );
  params.substitute( &message );
  return new ZorbaException(
    diagnostic, raise_file, raise_line, message.c_str()
  );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
