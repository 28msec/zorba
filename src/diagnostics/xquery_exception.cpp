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

// standard
#include <cstring>

// API
#include <zorba/xquery_stack_trace.h>
#include <zorba/zorba_string.h>
#include <zorba/util/uri.h>
#include <zorba/xquery_functions.h>

// Zorba
#include "util/fs_util.h"
#include "util/uri_util.h"

// local
#include "dict.h"
#include "xquery_exception.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

XQueryException::XQueryException( Diagnostic const &diagnostic,
                                  char const *raise_file, line_type raise_line,
                                  char const *message ) :
  ZorbaException( diagnostic, raise_file, raise_line, message )
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

XQueryException::XQueryException( serialization::Archiver &ar ) :
  ZorbaException( ar )
{
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

unique_ptr<ZorbaException> XQueryException::clone() const {
  return unique_ptr<ZorbaException>( new XQueryException( *this ) );
}

int XQueryException::get_ios_trace_index() {
  static int const index = ios_base::xalloc();
  return index;
}

void XQueryException::set_applied( char const *uri,
                                   line_type line,
                                   column_type col,
                                   line_type line_end,
                                   column_type col_end ) {
  if ( !uri || !*uri )
    uri = source_loc_.file();
  applied_loc_.set( uri, line, col, line_end, col_end );
}

void XQueryException::set_source( char const *uri,
                                  line_type line,
                                  column_type col,
                                  line_type line_end,
                                  column_type col_end ) {
  source_loc_.set( uri, line, col, line_end, col_end );
}

void XQueryException::polymorphic_throw() const {
  throw *this;
}

ostream& XQueryException::print_impl( ostream &o ) const {
  bool const as_xml = get_print_format( o ) == format_xml;
  if ( has_source() ) {
    if ( as_xml )
      o << "<location";
    if ( !print_uri( o, source_uri() ) && !as_xml )
      o << "(" << diagnostic::dict::lookup( ZED( NoSourceURI ) ) << ")";
    if ( !as_xml )
      o << ":" << source_line();
    else
      o << " line-begin=\"" << source_line() << '"';
    if ( as_xml && source_line_end() )
        o << " line-end=\"" << source_line_end() << '"';
    if ( source_column() ) {
      if ( as_xml )
        o << " column-begin=\"" << source_column() << '"';
      else
        o << "," << source_column();
    }
    if ( as_xml && source_column_end() )
      o << " column-end=\"" << source_column_end() << '"';

    if ( as_xml )
      o << " />";

    // diabled for XML printing because I don't know what the applied uri is
    if ( !as_xml && has_applied() ) {
      o << " (" << diagnostic::dict::lookup( ZED( AppliedAt ) ) << ' ';
      if ( applied_uri() && ::strcmp( applied_uri(), source_uri() ) != 0 ) {
        if ( print_uri( o, applied_uri() ) )
          o << ':';
      }
      o << applied_line();
      if ( applied_column() )
        o << ',' << applied_column();
      o << ')';
    }

    if ( !as_xml )
      o << ": ";

    if ( get_print_trace( o ) )
      print_stack_trace( o );
  }
  return ZorbaException::print( o );
}

ostream& XQueryException::print_stack_trace( ostream &o ) const {
  XQueryStackTrace const &trace = query_trace();
  if ( !trace.empty() ) {
    bool const as_xml = get_print_format( o ) == format_xml;
    if ( as_xml )
      o << "<stack>";
    FOR_EACH( XQueryStackTrace, it, trace ) {
      XQueryStackTrace::fn_name_type const& lName = it->getFnName();
      XQueryStackTrace::fn_arity_type lArity = it->getFnArity();
      char const *const lPrefix = lName.prefix();
      String lFileName = it->getFileName();
      if ( fn::starts_with(lFileName,"file:") ) {
        lFileName = URIHelper::decodeFileURI(lFileName);
        while (fn::starts_with(lFileName,"//")) {
          lFileName = lFileName.substr(1);
        }
      }
      if ( as_xml ) {
        o << "<call ";
        if ( lPrefix && *lPrefix ) {
          o << "prefix=\"" << lPrefix << "\" ";
        }
        o << "arity=\"" << lArity << "\" ";
        o << "ns=\"" << lName.ns() << "\" ";
        o << "local-name=\"" << lName.localname() << "\">";
        o << "<location ";
        o << "uri=\"" << lFileName << "\" ";
        o << "line-begin=\"" << it->getLine() << "\" "
          << "column-begin=\"" << it->getColumn() << "\" ";
        if ( it->getLineEnd() )
          o << "line-end=\"" << it->getLineEnd() << "\" ";
        if ( it->getColumnEnd() )
          o << "line-end=\"" << it->getColumnEnd() << "\" ";
        o << "/>";
        o << "</call>"; 
      } else {
        o << "=================================================" << std::endl;
        o << lName << "#" << lArity << " <" << lName.ns() << "> " << std::endl;
        o << lFileName << " at line " << it->getLine() << " column " << it->getColumn() << std::endl;
      }
    } 
    if ( as_xml )
      o << "</stack>";
  }
  return o;
}

bool XQueryException::print_uri( ostream &o, char const *uri ) {
  bool const as_xml = get_print_format( o ) == format_xml;
  if ( uri && *uri ) {
    switch ( uri::get_scheme( uri ) ) {
      case uri::none:
      case uri::file:
        try {
          o << (as_xml ? "<" : " uri=\"") 
            << fs::get_normalized_path( uri ) 
            << (as_xml ? '>' : '"');
          break;
        }
        catch ( ... ) {
          // fall back to printing as a URI
        }
        // no break;
      default:
        o << (as_xml ? "<" : "uri=\"") << uri << (as_xml ? '>' : '"');
    }
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

XQueryException
make_xquery_exception( char const *raise_file,
                       ZorbaException::line_type raise_line,
                       Diagnostic const &diagnostic,
                       internal::diagnostic::parameters const &params,
                       internal::diagnostic::location const &loc ) {
  internal::diagnostic::parameters::value_type message( diagnostic.message() );
  params.substitute( &message );
  XQueryException xe( diagnostic, raise_file, raise_line, message.c_str() );
  if ( loc )
    xe.set_source(
      loc.file(), loc.line(), loc.column(), loc.line_end(), loc.column_end()
    );
  return xe;
}

XQueryException*
new_xquery_exception( char const *raise_file,
                      ZorbaException::line_type raise_line,
                      Diagnostic const &diagnostic,
                      internal::diagnostic::parameters const &params,
                      internal::diagnostic::location const &loc ) {
  internal::diagnostic::parameters::value_type message( diagnostic.message() );
  params.substitute( &message );
  XQueryException *const xe =
    new XQueryException( diagnostic, raise_file, raise_line, message.c_str() );
  if ( loc )
    xe->set_source(
      loc.file(), loc.line(), loc.column(), loc.line_end(), loc.column_end()
    );
  return xe;
}

void set_applied( ZorbaException &ze, char const *file,
                  XQueryException::line_type line,
                  XQueryException::column_type col,
                  XQueryException::line_type line_end,
                  XQueryException::column_type col_end,
                  bool overwrite ) {
  if ( XQueryException *const xe = dynamic_cast<XQueryException*>( &ze ) ) {
    if ( !xe->has_applied() || overwrite )
      xe->set_applied( file, line, col, line_end, col_end );
  } else {
    XQueryException new_xe(
      ze.diagnostic(), ze.raise_file(), ze.raise_line(), ze.what()
    );
    new_xe.set_applied( file, line, col, line_end, col_end );
    throw new_xe;
  }
}

void set_source( ZorbaException &ze, char const *file,
                 XQueryException::line_type line,
                 XQueryException::column_type col,
                 XQueryException::line_type line_end,
                 XQueryException::column_type col_end,
                 bool overwrite ) {
  if ( XQueryException *const xe = dynamic_cast<XQueryException*>( &ze ) ) {
    if ( !xe->has_source() || overwrite )
      xe->set_source( file, line, col, line_end, col_end );
  } else {
    XQueryException new_xe(
      ze.diagnostic(), ze.raise_file(), ze.raise_line(), ze.what()
    );
    new_xe.set_source( file, line, col, line_end, col_end );
    throw new_xe;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
