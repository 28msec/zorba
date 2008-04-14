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

      virtual Item
      getDocument(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual void
      deleteDocument(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Collection_t
      createCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual Collection_t
      getCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

      virtual void
      deleteCollection(const String& uri, ErrorHandler* aErrorHandler = 0) = 0;

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
