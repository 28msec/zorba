#ifndef ZORBA_XMLDATAMANAGER_IMPL_H
#define ZORBA_XMLDATAMANAGER_IMPL_H

#include <zorba/xmldatamanager.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

namespace zorba {

  class ErrorHandler;

  namespace store {
    class Store;
  }
  
  class XmlDataManagerImpl : public XmlDataManager
  {
    public:
      virtual ~XmlDataManagerImpl();

      static XmlDataManagerImpl*
      getInstance();

      Item 
      loadDocument(const String& uri, std::istream& stream, ErrorHandler* aErrorHandler = 0);

      Item
      loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler = 0);

    protected:
      XmlDataManagerImpl();

      store::Store* theStore;

      ErrorHandler* theErrorHandler;

  }; /* class XmlDataManagerImpl */

} /* namespace zorba */
#endif
