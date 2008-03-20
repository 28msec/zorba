#ifndef ZORBA_XMLDATAMANAGER_API_H
#define ZORBA_XMLDATAMANAGER_API_H

#include <istream>
#include <zorba/api_shared_types.h>

namespace zorba {
  
  class XmlDataManager 
  {
    public:
      virtual ~XmlDataManager() {}

      virtual Item 
      loadDocument(const String& uri, std::istream& stream, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Item
      loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler = 0) = 0;

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
