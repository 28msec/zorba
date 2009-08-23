#include "error_printer.h"

#include <ostream>
#include "zorba/exception.h"

namespace zorba {

  std::ostream&
  ErrorPrinter::print(const QueryException& aException,
                      std::ostream&         aOut,
                      bool                  aIndent,
                      bool                  aAsXml)
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
