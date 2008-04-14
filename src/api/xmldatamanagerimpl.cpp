#include "api/xmldatamanagerimpl.h"

#include <fstream>

#include <zorba/zorbastring.h>
#include <zorba/item.h>
#include <zorba/default_error_handler.h>

#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"
#include "api/collectionimpl.h"
#include "errors/errors.h"
#include "errors/error_manager.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/store.h"
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

  Item
  XmlDataManagerImpl::getDocument(const String& uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
    try {
      return &*theStore->getDocument(lUri); 
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(aErrorHandler!=0?aErrorHandler:theErrorHandler, e);
      return Item();
    }
  }

  void
  XmlDataManagerImpl::deleteDocument(const String& uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
    try {
      theStore->deleteDocument(lUri); 
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(aErrorHandler!=0?aErrorHandler:theErrorHandler, e);
    }
  }

  Collection_t
  XmlDataManagerImpl::createCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
    try {
      return Collection_t(new CollectionImpl(theStore->createCollection(lUri), 
                                             aErrorHandler!=0?aErrorHandler:theErrorHandler));
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(aErrorHandler!=0?aErrorHandler:theErrorHandler, e);
      return Collection_t();
    }
  }

  Collection_t
  XmlDataManagerImpl::getCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
  }

  void
  XmlDataManagerImpl::deleteCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
  }

} /* namespace zorba */
