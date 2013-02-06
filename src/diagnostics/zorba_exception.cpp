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

#include "util/indent.h"
#include "util/omanip.h"
#include "zorbamisc/ns_consts.h"

#include "dict.h"

#ifndef NDEBUG
#include <cstdlib>                      /* for abort() */
ZORBA_DLL_PUBLIC bool g_abort_on_error;
#endif /* NDEBUG */

#define if_inc_indent if_do( do_indent, inc_indent )
#define if_dec_indent if_do( do_indent, dec_indent )

#undef if_nl
#define if_nl if_emit( do_indent, '\n' )

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

inline bool is_warning( Diagnostic const &d ) {
  return !!dynamic_cast<ZorbaWarningCode const*>( &d );
}

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

ZorbaException::ZorbaException( serialization::Archiver& ) 
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

int ZorbaException::get_ios_format_index() {
  static int const index = ios_base::xalloc();
  return index;
}

void ZorbaException::polymorphic_throw() const {
  throw *this;
}

ostream& ZorbaException::print( ostream& o ) const {
  print_format const format = get_print_format( o );
  bool const as_xml = format != format_text;
  bool const do_indent = format == format_xml_indented;
  if ( as_xml ) {
    o << "<exception xmlns=\""
      << (is_warning( diagnostic() ) ? ZORBA_WARN_NS : ZORBA_ERR_NS)
      << "\">" << if_nl << if_inc_indent;
  }
  print_impl( o );
  if ( as_xml )
    o << if_dec_indent << "</exception>";
  return o;
}

ostream& ZorbaException::print_impl( ostream &o ) const {
  Diagnostic const &d = diagnostic();
  print_format const format = get_print_format( o );
  bool const as_xml = format != format_text;
  bool const do_indent = format == format_xml_indented;

  if ( as_xml ) {
    diagnostic::QName const &q = d.qname();
    o << indent << "<kind>" << d.kind() << "</kind>" << if_nl
      << indent << "<code namespace=\"" << q.ns()
      << "\" local-name=\"" << q.localname() << "\"/>"
      << if_nl;
  } else {
    //
    // We need to create an error phrase (e.g., "static error") and look that
    // up as a unit rather than looking up the error kind word and "error"
    // separately because many languages have the word order reversed (e.g.,
    // "static error" becomes "erreur statique" in French).
    //
    ostringstream oss;
    oss << ZED_PREFIX;

    streampos pos = oss.tellp();
    oss << d.category();
    if ( oss.tellp() != pos )           // emit ' ' only if non-empty category
      oss << ' ';

    if ( diagnostic::kind const k = d.kind() )
      oss << k << ' ';

    oss << (is_warning( d ) ? "warning" : "error");
    o << diagnostic::dict::lookup( oss.str() ) << " [" << d.qname() << ']';
  }

  if ( char const *const w = what() )
    if ( *w ) {
      if ( as_xml )
        o << indent << "<message>" << w << "</message>" << if_nl;
      else
        o << ": " << w;
    }

#ifndef NDEBUG
  if ( as_xml )
    o << indent << "<raised-at file=\"" << raise_file()
      << "\" line=\"" << raise_line() << "\"/>" << if_nl;
  else
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
