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

    ZORBA_TRY
      theStore = & GENV.getStore();
    ZORBA_CATCH
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
    ZORBA_TRY
      xqpStringStore* lString = Unmarshaller::getInternalString(uri);

      if ( ! stream.good() ) {
        ZORBA_ERROR_DESC(ZorbaError::API0015_CANNOT_OPEN_FILE, "cannot read from stream");
      }

      return &*theStore->loadDocument(lString, stream); 
    ZORBA_CATCH
    return Item(); 
  }

  Item
  XmlDataManagerImpl::loadDocument(const String& local_file_uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lString = Unmarshaller::getInternalString(local_file_uri);

      std::ifstream lFileIn(lString->c_str());

      return loadDocument(local_file_uri, lFileIn, aErrorHandler);
    ZORBA_CATCH
    return Item();
  }

  Item
  XmlDataManagerImpl::getDocument(const String& uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
      return &*theStore->getDocument(lUri); 
    ZORBA_CATCH
    return Item();
  }

  bool
  XmlDataManagerImpl::deleteDocument(const String& uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
      theStore->deleteDocument(lUri); 
      return true;
    ZORBA_CATCH
    return false;
  }

  Collection_t
  XmlDataManagerImpl::createCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
      return Collection_t(new CollectionImpl(theStore->createCollection(lUri), 
                                             aErrorHandler!=0?aErrorHandler:theErrorHandler));
    ZORBA_CATCH
    return Collection_t();
  }

  Collection_t
  XmlDataManagerImpl::getCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
      return Collection_t(new CollectionImpl(theStore->getCollection(lUri),
                                             aErrorHandler!=0?aErrorHandler:theErrorHandler));
    ZORBA_CATCH
    return Collection_t();
  }

  bool
  XmlDataManagerImpl::deleteCollection(const String& uri, ErrorHandler* aErrorHandler)
  {
    ZORBA_TRY
      xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
      theStore->deleteCollection(lUri);
      return true;
    ZORBA_CATCH
    return false;
  }

} /* namespace zorba */
