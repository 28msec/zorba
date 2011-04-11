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
#include "zorbaerrors/error_manager.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"

#include "runtime/util/flowctl_exception.h"

namespace zorba {


#define ZORBA_DM_TRY                                              \
  ErrorHandler* errorHandler = (aErrorHandler != 0 ?              \
                                aErrorHandler : theErrorHandler); \
  try

#define ZORBA_DM_CATCH                                  \
  catch (ZorbaException const& e)                       \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler, e);            \
  }                                                     \
  catch (std::exception const& e)                       \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler, e.what());     \
  }                                                     \
  catch (...)                                           \
  {                                                     \
    ZorbaImpl::notifyError(errorHandler);               \
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


Item XmlDataManagerImpl::parseDocument(std::istream& aStream)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)
  ErrorHandler* aErrorHandler = 0;
  ZORBA_DM_TRY
  {
    store::LoadProperties loadProperties;
    loadProperties.setStoreDocument(false);
    return &*theStore->loadDocument("", "", aStream, loadProperties);
  }
  ZORBA_DM_CATCH
  return Item();
}


Item XmlDataManagerImpl::loadDocument(
    const String& aLocalFileUri,
    bool aReplaceDoc)
{
  XmlDataManager::LoadProperties loadProperties;
  return loadDocument(aLocalFileUri, loadProperties, aReplaceDoc);
}


Item XmlDataManagerImpl::loadDocument(
    const String& aUri,
    std::istream& aStream,
    bool aReplaceDoc)
{
  XmlDataManager::LoadProperties loadProperties;
  return loadDocument(aUri, aStream, loadProperties, aReplaceDoc);
}


Item XmlDataManagerImpl::loadDocument(
    const String& aLocalFileUri,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool aReplaceDoc)
{
  ErrorHandler* aErrorHandler = NULL;

  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& fileUri = Unmarshaller::getInternalString(aLocalFileUri);

    std::ifstream fileStream(fileUri.c_str());

    return loadDocument(aLocalFileUri, fileStream, aLoadProperties, aReplaceDoc);
  }
  ZORBA_DM_CATCH
  return Item();
}


Item XmlDataManagerImpl::loadDocument(
    const String& uri,
    std::istream& stream,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool aReplaceDoc)
{
  ErrorHandler* aErrorHandler = NULL;

  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    if ( ! stream.good() )
			throw ZORBA_EXCEPTION( ZOSE0003_STREAM_READ_FAILURE );

    const zstring& docUri = Unmarshaller::getInternalString(uri);

    if (aReplaceDoc)
      theStore->deleteDocument(docUri);

    store::LoadProperties loadProps;
    loadProps.setEnableDtd( aLoadProperties.getEnableDtd() );

    return &*theStore->loadDocument(docUri, docUri, stream, loadProps);
  }
  ZORBA_DM_CATCH
  return Item();
}


Item XmlDataManagerImpl::loadDocumentFromUri(
    const String& aUri,
    bool aReplaceDoc)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ErrorHandler* aErrorHandler = NULL;

  ZORBA_DM_TRY
  {
    InternalDocumentURIResolver* uri_resolver;
    uri_resolver = GENV_ROOT_STATIC_CONTEXT.get_document_uri_resolver();

    zstring docUri = Unmarshaller::getInternalString(aUri);

    zorba::store::ItemFactory* item_factory = GENV_ITEMFACTORY;
    store::Item_t uriItem;

    item_factory->createAnyURI(uriItem, docUri);

    store::Item_t docItem;
    docItem = uri_resolver->resolve(uriItem,
                                    &GENV_ROOT_STATIC_CONTEXT,
                                    true,
                                    aReplaceDoc);

    if(docItem.isNull())
      return Item();

    return Item(docItem);
  }
  ZORBA_DM_CATCH
  return Item();
}


Item XmlDataManagerImpl::getDocument(const String& uri)
{
  return getDocument(uri, theErrorHandler);
}


Item XmlDataManagerImpl::getDocument(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& docUri = Unmarshaller::getInternalString(uri);
    return &*theStore->getDocument(docUri);
  }
  ZORBA_DM_CATCH
  return Item();
}


bool XmlDataManagerImpl::deleteDocument(const String& uri)
{
  return deleteDocument(uri, theErrorHandler);
}


bool XmlDataManagerImpl::deleteDocument(const String& uri, ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& docUri = Unmarshaller::getInternalString(uri);
    theStore->deleteDocument(docUri);
    return true;
  }
  ZORBA_DM_CATCH
  return false;
}


void XmlDataManagerImpl::deleteAllDocuments()
{
  ErrorHandler* aErrorHandler = NULL;

  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    theStore->deleteAllDocuments();
  }
  ZORBA_DM_CATCH
}


Collection_t XmlDataManagerImpl::createCollection(const String& uri)
{
  return createCollection(uri, theErrorHandler);
}


Collection_t XmlDataManagerImpl::createCollection(
    const String& uri,
    ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& colUri = Unmarshaller::getInternalString(uri);
    return Collection_t(new CollectionImpl(theStore->createUriCollection(colUri),
                                           aErrorHandler));
  }
  ZORBA_DM_CATCH
  return Collection_t();
}


Collection_t XmlDataManagerImpl::getCollection(const String& uri)
{
  return getCollection(uri, theErrorHandler);
}


Collection_t XmlDataManagerImpl::getCollection(
    const String& uri,
    ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& colUri = Unmarshaller::getInternalString(uri);
    store::Collection_t lColl = theStore->getUriCollection(colUri);
    if (lColl)
      return Collection_t(new CollectionImpl(lColl, aErrorHandler));
    else
      return NULL;
  }
  ZORBA_DM_CATCH
  return NULL;
}


bool XmlDataManagerImpl::deleteCollection(const String& uri)
{
  return deleteCollection(uri, theErrorHandler);
}


bool XmlDataManagerImpl::deleteCollection(
    const String& uri,
    ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::READ);)

  ZORBA_DM_TRY
  {
    const zstring& colUri = Unmarshaller::getInternalString(uri);
    theStore->deleteUriCollection(colUri);
    return true;
  }
  ZORBA_DM_CATCH
  return false;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
