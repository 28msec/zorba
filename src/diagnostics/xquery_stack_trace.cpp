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

#include <typeinfo>

#include <zorba/xquery_exception.h>

#include "diagnostic.h"
#include "xquery_stack_trace.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

XQueryStackTrace::Entry::Entry( fn_name_type const &fn_name,
                                fn_arity_type fn_arity,
                                char const *file_name,
                                line_type line,
                                column_type column,
                                line_type line_end,
                                column_type column_end ) :
  fn_name_( fn_name ), fn_arity_( fn_arity ), filename_( file_name ),
  line_( line ), col_( column ), line_end_ ( line_end ), col_end_( column_end )
{
}

//for plan serialization
XQueryStackTrace::Entry::Entry() :
  fn_name_( *(serialization::Archiver*)NULL )
{
}

void XQueryStackTrace::push( Entry const &entry ) {
  trace_.push_back( entry );
}


void recordStackTrace(
    QueryLoc const &loc,
    QueryLoc const &call_loc,
    store::Item_t const &fn_name,
    XQueryStackTrace::fn_arity_type fn_arity,
    ZorbaException &ze ) 
{
  if ( XQueryException *const xe = dynamic_cast<XQueryException*>( &ze ) )
  {
    XQueryStackTrace &trace = xe->query_trace();

    if ( trace.empty() && xe->has_source() ) {
      if ( xe->source_uri() != loc.getFilename() )
        return;
      if ( xe->source_line() < loc.getLineBegin() )
        return;
      if ( xe->source_line() > loc.getLineEnd() )
        return;
      if ( xe->source_line() == loc.getLineBegin() ) {
        if ( xe->source_column() < loc.getColumnBegin() )
          return;
        if ( xe->source_column() > loc.getColumnEnd() )
          return;
      }
    }

    trace.push(
      XQueryStackTrace::Entry(
        diagnostic::to_QName<XQueryStackTrace::fn_name_type>( fn_name ),
        fn_arity,
        call_loc.getFilename().c_str(),
        call_loc.getLineBegin(),
        call_loc.getColumnBegin(),
        call_loc.getLineEnd(),
        call_loc.getColumnEnd()
      )
    );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
