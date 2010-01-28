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
#include "error_printer.h"

#include <ostream>
#include "zorba/exception.h"

namespace zorba {

  std::ostream&
  ErrorPrinter::print(const QueryException& aException,
                      std::ostream&         aOut,
                      bool                  aAsXml,
                      bool                  aIndent)
  {
      if( !aAsXml ) {
        aOut << aException << " ";
        if( aIndent ) { aOut << std::endl; };
      }
      else {
        aOut << "<errors>";
        if( aIndent ) aOut << std::endl << "  ";
        //code
        aOut << "<error code='" << aException.getErrorCodeAsString(aException.getErrorCode()) << "'>";
        if( aIndent ) aOut << std::endl << "    ";
        //location
        aOut << "<location module='" << aException.getQueryURI();
        aOut << "' lineStart='" << aException.getLineBegin();
        aOut << "' columnStart='" << aException.getColumnBegin();
        aOut << "' lineEnd='" << aException.getLineBegin();
        aOut << "' columnEnd='" << aException.getColumnBegin() << "' />";
        if( aIndent ) aOut << std::endl << "    ";
        //description
        aOut << "<description>" << aException.getDescription().formatAsXML() << "</description>";
        if( aIndent ) aOut << std::endl << "  ";
        aOut << "</error>";
        if( aIndent ) aOut << std::endl;
        aOut << "</errors>";
      }
      return aOut;
  }

} /* namespace zorba */
