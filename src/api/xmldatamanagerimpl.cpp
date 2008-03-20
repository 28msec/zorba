#include "api/xmldatamanagerimpl.h"

#include <fstream>

#include <zorba/string.h>
#include <zorba/item.h>
#include <zorba/default_error_handler.h>

#include "api/zorbaimpl.h"
#include "errors/errors.h"
#include "errors/error_manager.h"

#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"

namespace zorba {

  XmlDataManagerImpl::XmlDataManagerImpl() 
  {
    theErrorHandler = new DefaultErrorHandler();

    try {
      theStore = & GENV.getStore();
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    }
  }

  XmlDataManagerImpl::~XmlDataManagerImpl() 
  {
    delete theErrorHandler;
  }


  XmlDataManagerImpl*
  XmlDataManagerImpl::getInstance()
  {
    static XmlDataManagerImpl lInstance;
    return &lInstance;
  }

  Item
  XmlDataManagerImpl::loadDocument(const String& uri, std::istream& stream, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(uri);

    try { 
      if ( ! stream.good() ) {
        ZORBA_ERROR_DESC(ZorbaError::API0015_CANNOT_OPEN_FILE, "cannot read from stream");
      }

      return &*theStore->loadDocument(lString, stream); 
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(aErrorHandler!=0?aErrorHandler:theErrorHandler, e);
      return Item(); 
    }
  }

  Item
  XmlDataManagerImpl::loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(local_file_uri);

    std::ifstream lFileIn(lString->c_str());

    return loadDocument(local_file_uri, lFileIn, aErrorHandler);
  }

} /* namespace zorba */
