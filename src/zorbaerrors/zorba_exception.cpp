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

#include <sstream>

#include <zorba/zorba_exception.h>

#include "dict.h"

#ifndef NDEBUG
#include <cstdlib>                      /* for abort() */
ZORBA_DLL_PUBLIC bool g_abort_on_error;
#endif /* NDEBUG */

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

ZorbaException::ZorbaException( Error const &error, char const *throw_file,
                                line_type throw_line, char const *message ) :
  error_( (Error*)error.clone() ),
  throw_file_( throw_file ),
  throw_line_( throw_line ),
  message_( message )
{
#ifndef NDEBUG
  if ( g_abort_on_error )
    abort();
#endif /* NDEBUG */
}

ZorbaException::ZorbaException( ZorbaException const &from ) :
  std::exception( from ),
  error_( (Error*)from.error_->clone() ),
  throw_file_( from.throw_file_ ),
  throw_line_( from.throw_line_ ),
  message_( from.message_ )
{
}

ZorbaException::ZorbaException( serialization::Archiver &ar ) 
{
}

ZorbaException::~ZorbaException() throw() {
  error_->destroy();
}

ZorbaException& ZorbaException::operator=( ZorbaException const &from ) {
  if ( &from != this ) {
    //
    // Doing it this way provides the strong exception guarantee.
    //
    Error const *const temp = from.error_->clone();
    error_->destroy();
    error_ = (Error*)temp;

    throw_file_ = from.throw_file_;
    throw_line_ = from.throw_line_;
    message_ = from.message_;
  }
  return *this;
}

auto_ptr<ZorbaException> ZorbaException::clone() const {
  return auto_ptr<ZorbaException>( new ZorbaException( *this ) );
}

void ZorbaException::polymorphic_throw() const {
  throw *this;
}

ostream& ZorbaException::print( ostream &o ) const {
  //
  // We need to create an error phrase (e.g., "static error") and look that up
  // as a unit rather than looking up the error type word and "error"
  // separately because many languages have the word order reversed (e.g.,
  // "erreur statique" in French).
  //
  ostringstream oss;
  oss << ZED_PREFIX;
  Error const &e = error();
  if ( err::type const t = e.type() )
    oss << t << ' ';
  oss << "error";

  o << err::dict::lookup( oss.str() ) << " [" << e.qname() << ']';

  if ( char const *const w = what() )
    if ( *w )
      o << ": " << w;

#ifndef NDEBUG
  o << "; thrown at " << throw_file() << ':' << throw_line();
#endif
  return o;
}

char const* ZorbaException::what() const throw() {
  return message_.c_str();
}

///////////////////////////////////////////////////////////////////////////////

namespace internal {

ZorbaException make_zorba_exception( char const *throw_file,
                                     ZorbaException::line_type throw_line,
                                     Error const &error,
                                     err::parameters const &params ) {
  err::parameters::value_type message( error.message() );
  params.substitute( &message );
  return ZorbaException( error, throw_file, throw_line, message.c_str() );
}

ZorbaException* new_zorba_exception( char const *throw_file,
                                     ZorbaException::line_type throw_line,
                                     Error const &error,
                                     err::parameters const &params ) {
  err::parameters::value_type message( error.message() );
  params.substitute( &message );
  return new ZorbaException( error, throw_file, throw_line, message.c_str() );
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
