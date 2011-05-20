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

#include <iostream>

#include <zorba/printer_diagnostic_handler.h>
#include <zorba/xquery_exception.h>

namespace zorba {

PrinterDiagnosticHandler::PrinterDiagnosticHandler(std::ostream& os, bool aPrintAsXml, bool aIndent)
  : theOStream(os),
    thePrintAsXml(aPrintAsXml),
    theIndent(aIndent)
{
}

PrinterDiagnosticHandler::~PrinterDiagnosticHandler() {
  // out-of-line since it's virtual
}

void printerDiagnosticHandlerHelper( ZorbaException const &ex,
                                     std::ostream&         o,
                                     bool                  aIndent)
{
  o << "<errors>";
  if ( aIndent ) o << std::endl << "  ";
  //code
  o << "<error code='" << ex.diagnostic().qname() << "'>";

  XQueryException const *xex = dynamic_cast<XQueryException const*>( &ex );
  if ( xex && xex->has_source() ) {
    //location
    if ( aIndent ) o << std::endl << "    ";
    o << "<location"
      << "' line='" << xex->source_line()
      << "' column='" << xex->source_column()
      << "' />";
  }

  if ( aIndent ) o << std::endl << "    ";
  //description
  o << "<description>" << ex.what() << "</description>";
  if ( aIndent ) o << std::endl << "  ";
  o << "</error>";
  if ( aIndent ) o << std::endl;
  o << "</errors>";
}

void
PrinterDiagnosticHandler::error( const ZorbaException& ex )
{
  if (thePrintAsXml)
    printerDiagnosticHandlerHelper( ex, theOStream, theIndent );
  else
    theOStream << ex;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
