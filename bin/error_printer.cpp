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
#include "zorba/util/uri.h"

namespace zorba {

  std::ostream& print_stack_trace(const QueryException& aException,
                                  std::ostream& aOut,
                                  bool aAsXml)
  {
    ZorbaException::StackTrace_t lTrace = aException.getStackTrace();
    if(!lTrace.empty()) {
      QueryException::StackTrace_t::iterator it = lTrace.begin();
      if(aAsXml) { aOut << "<stack>"; } 
      for(; it != lTrace.end(); ++it) {
        Item lName = it->getFunctionName();
        unsigned int lArity = it->getFunctionArity();
        QueryLocation_t lLocation = it->getLocation();
        String lPrefix = lName.getPrefix();
        String lFileName = lLocation->getFileName();
        if (lFileName.startsWith("file:")) {
          lFileName = URIHelper::decodeFileURI(lFileName);
          while (lFileName.startsWith("//")) {
            lFileName = lFileName.substring(1);
          }
        }
        if(aAsXml) {
          aOut << "<call ";
          if(lPrefix != "") {
            aOut << " prefix=\"" << lPrefix << "\" ";
          }
          aOut << " arity=\"" << lArity << "\" ";
          aOut << " ns=\"" << lName.getNamespace() << "\" ";
          aOut << " localName=\"" << lName.getLocalName() << "\">";
          aOut << "  <location ";
          aOut << "fileName=\"" << lFileName << "\" ";
          aOut << "lineBegin=\"" << lLocation->getLineBegin() << "\" ";  
          aOut << "lineEnd=\"" << lLocation->getLineEnd() << "\" ";  
          aOut << "columnBegin=\"" << lLocation->getColumnBegin() << "\" ";  
          aOut << "columnEnd=\"" << lLocation->getColumnEnd() << "\" ";  
          aOut << "  />";
          aOut << "</call>"; 
        } else {
          String lFName = lPrefix == "" ? lName.getLocalName() : lPrefix + ":" + lName.getLocalName();
          aOut << "=================================================" << std::endl;
          aOut << lFName << "#" << lArity << " ( " << lName.getNamespace() << " ) " << std::endl;
          aOut << lFileName << " at line " << lLocation->getLineBegin() << " column " << lLocation->getColumnBegin() << std::endl;
        }
      } 
      if(aAsXml) { aOut << "</stack>"; } 
    }
    return aOut;
  }

  std::ostream&
  ErrorPrinter::print(const QueryException& aException,
                      std::ostream&         aOut,
                      bool                  aAsXml,
                      bool                  aIndent)
  {
      if( !aAsXml ) {
        aOut << aException << " ";
        if( aIndent ) { aOut << std::endl; };
        print_stack_trace(aException, aOut, aAsXml);
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
        print_stack_trace(aException, aOut, aAsXml);
        aOut << "</error>";
        if( aIndent ) aOut << std::endl;
        aOut << "</errors>";
      }
      return aOut;
  }

} /* namespace zorba */
