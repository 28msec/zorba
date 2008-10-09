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
#include "api/xmldatamanagerimpl.h"

#include <fstream>

#include <zorba/zorbastring.h>
#include <zorba/item.h>
#include <zorba/default_error_handler.h>

#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"
#include "api/collectionimpl.h"
#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "zorbatypes/xqpstring.h"

namespace zorba {


#define ZORBA_DM_TRY                                              \
  ErrorHandler* errorHandler = (aErrorHandler != 0 ?              \
                                aErrorHandler : theErrorHandler); \
  try  

#define ZORBA_DM_CATCH                                  \
  catch (error::ZorbaError& e)                          \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler, e);            \
  }                                                     \
  catch (std::exception& e)                             \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler, e.what());     \
  }                                                     \
  catch (...)                                           \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler);               \
  }


XmlDataManagerImpl*
XmlDataManagerImpl::getInstance()
{
  static XmlDataManagerImpl lInstance;
  return &lInstance;
}


XmlDataManagerImpl::XmlDataManagerImpl() 
{
  theErrorHandler = new DefaultErrorHandler();
  theUserErrorHandler = false;

  ZORBA_TRY
  {
    theStore = & GENV.getStore();
  }
  ZORBA_CATCH
}


XmlDataManagerImpl::~XmlDataManagerImpl() 
{
  if (!theUserErrorHandler)
    delete theErrorHandler;
}


void XmlDataManagerImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  if (!theUserErrorHandler)
    delete theErrorHandler;

  theErrorHandler = aErrorHandler;
  theUserErrorHandler = true;
}


Item
XmlDataManagerImpl::loadDocument(
    const String& uri,
    std::istream& stream)
{
  return loadDocument(uri, stream, theErrorHandler);
}


Item
XmlDataManagerImpl::loadDocument(
    const String& uri,
    std::istream& stream,
    ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore_t lString = Unmarshaller::getInternalString(uri);

    if ( ! stream.good() ) {
      ZORBA_ERROR_DESC(API0015_CANNOT_OPEN_FILE, "cannot read from stream");
    }

    return &*theStore->loadDocument(lString, stream); 
  }
  ZORBA_DM_CATCH
  return Item(); 
}


Item
XmlDataManagerImpl::loadDocument(const String& local_file_uri)
{
  return loadDocument(local_file_uri, (ErrorHandler*)NULL);
}


Item
XmlDataManagerImpl::loadDocument(
    const String& local_file_uri,
    ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(local_file_uri);

    std::ifstream lFileIn(lString->c_str());

    return loadDocument(local_file_uri, lFileIn, aErrorHandler);
  }
  ZORBA_DM_CATCH
  return Item();
}


Item
XmlDataManagerImpl::getDocument(const String& uri)
{
  return getDocument(uri, theErrorHandler);
}


Item
XmlDataManagerImpl::getDocument(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore_t lUri = Unmarshaller::getInternalString(uri);
    return &*theStore->getDocument(lUri); 
  }
  ZORBA_DM_CATCH
  return Item();
}


bool
XmlDataManagerImpl::deleteDocument(const String& uri)
{
  return deleteDocument(uri, theErrorHandler);
}


bool
XmlDataManagerImpl::deleteDocument(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore_t lUri = Unmarshaller::getInternalString(uri);
    theStore->deleteDocument(lUri); 
    return true;
  }
  ZORBA_DM_CATCH
  return false;
}


Collection_t
XmlDataManagerImpl::createCollection(const String& uri)
{
  return createCollection(uri, theErrorHandler);
}


Collection_t
XmlDataManagerImpl::createCollection(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore_t lUri = Unmarshaller::getInternalString(uri);
    return Collection_t(new CollectionImpl(theStore->createCollection(lUri), 
                                           aErrorHandler));
  }
  ZORBA_DM_CATCH
  return Collection_t();
}


Collection_t
XmlDataManagerImpl::getCollection(const String& uri)
{
  return getCollection(uri, theErrorHandler);
}


Collection_t
XmlDataManagerImpl::getCollection(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
    store::Collection_t lColl = theStore->getCollection(lUri);
    if (lColl)
      return Collection_t(new CollectionImpl(lColl, aErrorHandler));
    else
      return NULL;
  }
  ZORBA_DM_CATCH
  return NULL;
}


bool
XmlDataManagerImpl::deleteCollection(const String& uri)
{
  return deleteCollection(uri, theErrorHandler);
}


bool
XmlDataManagerImpl::deleteCollection(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    xqpStringStore* lUri = Unmarshaller::getInternalString(uri);
    theStore->deleteCollection(lUri);
    return true;
  }
  ZORBA_DM_CATCH
  return false;
}

} /* namespace zorba */
