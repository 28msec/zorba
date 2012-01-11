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

#include <ostream>
#include <sstream>

#include <zorba/xquery_exception.h>
#include <zorba/xquery_functions.h>
#include <zorba/xquery_stack_trace.h>
#include <zorba/zorba_string.h>

#include "zorba/util/uri.h"
#include "error_printer.h"

namespace zorba {

  std::ostream&
  print_stack_trace(
    const XQueryException&  aException,
    std::ostream&           aOut,
    bool                    aAsXml,
    bool                    aIndent)
  {
    XQueryStackTrace const& lTrace = aException.query_trace();
    if (!lTrace.empty()) {
      XQueryStackTrace::const_iterator it = lTrace.begin();
      if (aAsXml) {
        if (aIndent) aOut << "  ";
        aOut << "<stack>";
      } 
      for (; it != lTrace.end(); ++it) {
        XQueryStackTrace::fn_name_type const& lName = it->getFnName();
        XQueryStackTrace::fn_arity_type lArity = it->getFnArity();
        char const *const lPrefix = lName.prefix();
        String lFileName = it->getFileName();
        if (fn::starts_with(lFileName,"file:")) {
          lFileName = URIHelper::decodeFileURI(lFileName);
          while (fn::starts_with(lFileName,"//")) {
            lFileName = lFileName.substr(1);
          }
        }
        if (aAsXml) {
          if (aIndent) aOut << std::endl << "      ";
          aOut << "<call ";
          if (lPrefix && *lPrefix) {
            aOut << "prefix=\"" << lPrefix << "\" ";
          }
          aOut << "arity=\"" << lArity << "\" ";
          aOut << "ns=\"" << lName.ns() << "\" ";
          aOut << "localName=\"" << lName.localname() << "\">";
          if (aIndent) aOut << std::endl << "        ";
          aOut << "<location ";
          aOut << "fileName=\"" << lFileName << "\" ";
          aOut << "lineStart=\"" << it->getLine() << "\" "
            << "columnStart=\"" << it->getColumn() << "\" ";
          if (it->getLineEnd())
            aOut << "lineEnd=\"" << it->getLineEnd() << "\" ";
          if (it->getColumnEnd())
            aOut << "lineEnd=\"" << it->getColumnEnd() << "\" ";
          aOut << "/>";
          if (aIndent) aOut << std::endl << "      ";
          aOut << "</call>"; 
        } else {
          std::ostringstream oss;
          oss << lName;
          String lFName = oss.str();
          aOut << "=================================================" << std::endl;
          aOut << lFName << "#" << lArity << " <" << lName.ns() << "> " << std::endl;
          aOut << lFileName << " at line " << it->getLine() << " column " << it->getColumn() << std::endl;
        }
      } 
      if  (aAsXml) {
        if (aIndent) aOut << std::endl << "    ";
        aOut << "</stack>";
      } 
    }
    return aOut;
  }

  std::ostream&
  ErrorPrinter::print(
    const XQueryException&  aException,
    std::ostream&           aOut,
    bool                    aAsXml,
    bool                    aIndent)
  {
      if (!aAsXml) {
        aOut << aException << " ";
        aOut << std::endl;
        print_stack_trace(aException, aOut, aAsXml, aIndent);
      } else {
        aOut << "<errors>";
        if (aIndent) aOut << std::endl << "  ";
        //code
        aOut << "<error code='" << aException.diagnostic().qname() << "'>";
        if (aIndent) aOut << std::endl << "    ";
        //location
        aOut << "<location module='" << aException.source_uri();
        aOut << "' lineStart='" << aException.source_line();
        aOut << "' columnStart='" << aException.source_column() << "'";
        if (aException.source_line_end())
          aOut << " lineEnd='" << aException.source_line_end() << "'";
        if (aException.source_column_end())
          aOut << " columnEnd='" << aException.source_column_end() << "'";
        aOut << "/>";
        if (aIndent) aOut << std::endl << "    ";
        //description
        aOut << "<description>" << aException.what() << "</description>";
        if( aIndent ) aOut << std::endl << "  ";
        print_stack_trace(aException, aOut, aAsXml, aIndent);
        if (aIndent) aOut << std::endl << "  ";
        aOut << "</error>";
        if (aIndent) aOut << std::endl;
        aOut << "</errors>";
      }
      return aOut;
  }

} // namespace zorba
