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
#include <zorba/default_error_handler.h>
#include <zorba/zorba.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"

#include "system/globalenv.h"

#include "types/typeops.h"
#include "types/typemanager.h"
#include "types/root_typemanager.h"
#include "types/schema/validate.h"

#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/storeiteratorimpl.h"
#include "api/dynamiccontextimpl.h"

#include "compiler/parser/query_loc.h"

#include "runtime/util/item_iterator.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"



namespace zorba {

#define ZORBA_DCTX_TRY try 
 
#define ZORBA_DCTX_CATCH  catch (error::ZorbaError& e) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler, e); \
  } catch (std::exception& e) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler, e.what()); \
  } catch (...) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler); \
  } \


DynamicContextImpl::DynamicContextImpl(const XQueryImpl* aQuery)
  :
  theQuery(aQuery)
{
  theCtx = theQuery->theDynamicContext;
  theStaticContext = theQuery->theStaticContext;
}


DynamicContextImpl::~DynamicContextImpl() 
{
}


bool
DynamicContextImpl::setVariable(
    const String& aQName,
    const Item& aItem )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    // unmarshall the string and the item
    store::Item_t lItem(Unmarshaller::getInternalItem(aItem));
    ZorbaImpl::checkItem(lItem);
    xqpString lString (Unmarshaller::getInternalString(aQName));

    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, lString);

    // add it to the internal context
    theCtx->add_variable(lExpandedName, lItem);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariable(
    const String& aQName,
    const Iterator_t& aIterator )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    Iterator* lIter = aIterator.get();
    if (!lIter)
      ZORBA_ERROR_DESC(API0014_INVALID_ARGUMENT, "Invalid Iterator given");
        
    store::Iterator_t lRes = Unmarshaller::getInternalIterator(lIter);

    xqpString lString (Unmarshaller::getInternalString(aQName));
    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, lString);

    theCtx->add_variable(lExpandedName, lRes);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariable(
    const String& aNamespace, const String& aLocalname,
    const Iterator_t& aIterator )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    Iterator* lIter = aIterator.get();
    if (!lIter)
      ZORBA_ERROR_DESC(API0014_INVALID_ARGUMENT, "Invalid Iterator given");
        
    store::Iterator_t lRes = Unmarshaller::getInternalIterator(lIter);

    xqpString lNamespace (Unmarshaller::getInternalString(aNamespace));
    xqpString lLocalname (Unmarshaller::getInternalString(aLocalname));
    xqpString lExpandedName = theCtx->expand_varname
      (theStaticContext, lNamespace, lLocalname);

    theCtx->add_variable(lExpandedName, lRes);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::getVariable(
  const String& aNamespace, const String& aLocalname,
  Item& aItem, Iterator_t& aIterator)
{
  ZORBA_DCTX_TRY
  {
    xqpString lNamespace (Unmarshaller::getInternalString(aNamespace));
    xqpString lLocalname (Unmarshaller::getInternalString(aLocalname));
    xqpString lExpandedName = theCtx->expand_varname
      (theStaticContext, lNamespace, lLocalname);

    store::Item_t lItem;
    store::Iterator_t lIter;
    theCtx->get_variable(lExpandedName, lItem, lIter);
    if (! lItem.isNull()) {
      aItem = lItem;
    }
    if (! lIter.isNull()) {
      Iterator_t lIt(new StoreIteratorImpl(lIter, theQuery->theErrorHandler));
      aIterator = lIt;
    }
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri,
    validation_mode_t aMode)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    TypeManager* tm = theStaticContext->get_typemanager();
    zorba::store::ItemFactory* factory = GENV_ITEMFACTORY;
    InternalDocumentURIResolver* uriResolver;
    uriResolver = theStaticContext->get_document_uri_resolver();

    xqpStringStore_t docUri = Unmarshaller::getInternalString(aDocUri);
    store::Item_t docUriItem;
    factory->createAnyURI(docUriItem, docUri);

    store::Item_t docItem;
    docItem = uriResolver->resolve(docUriItem, theStaticContext, true, false);
    
    if(docItem.isNull())
      return false;

#ifndef ZORBA_NO_XMLSCHEMA
    if (!docItem->isValidated())
    {
      if (aMode != validate_skip)
      {
        store::Item_t validatedNode;
        store::Item_t typeName;
        QueryLoc loc;

        ParseConstants::validation_mode_t mode = (aMode == validate_lax ?
                                                  ParseConstants::val_lax :
                                                  ParseConstants::val_strict);

        bool success = Validator::effectiveValidationValue(validatedNode,
                                                           docItem,
                                                           typeName,
                                                           tm,
                                                           mode,
                                                           theStaticContext,
                                                           loc);
        ZORBA_ASSERT(success);
      
        if (docItem != validatedNode)
        {
          GENV_STORE.deleteDocument(docUri);
          docItem = validatedNode;
          docItem->markValidated();
          GENV_STORE.addNode(docUri.getp(), docItem);
        }
      }
    }
    else if (tm->getSchema() == NULL || aMode == validate_skip)
    {
      GENV_STORE.deleteDocument(docUri);
      docItem = uriResolver->resolve(docUriItem, theStaticContext, true, false);
    }
#endif//ZORBA_NO_XMLSCHEMA

    return setVariable(aVarName, Item(docItem));
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri, 
    std::auto_ptr<std::istream> aStream,
    validation_mode_t aMode)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    TypeManager* tm = theStaticContext->get_typemanager();

    xqpStringStore_t docUri = Unmarshaller::getInternalString(aDocUri);

    store::Item_t docItem = GENV_STORE.loadDocument(docUri, *(aStream.get()));

#ifndef ZORBA_NO_XMLSCHEMA
    if (!docItem->isValidated())
    {
      if (aMode != validate_skip)
      {
        store::Item_t validatedNode;
        store::Item_t typeName;
        QueryLoc loc;

        ParseConstants::validation_mode_t mode = (aMode == validate_lax ?
                                                  ParseConstants::val_lax :
                                                  ParseConstants::val_strict);
        bool success = Validator::effectiveValidationValue(validatedNode,
                                                           docItem,
                                                           typeName,
                                                           tm,
                                                           mode,
                                                           theStaticContext,
                                                           loc);
        ZORBA_ASSERT(success);
      
        if (docItem != validatedNode)
        {
          GENV_STORE.deleteDocument(docUri);
          docItem = validatedNode;
          docItem->markValidated();
          GENV_STORE.addNode(docUri.getp(), docItem);
        }
      }
    }
    else if (tm->getSchema() == NULL || aMode == validate_skip)
    {
      GENV_STORE.deleteDocument(docUri);
      docItem = GENV_STORE.loadDocument(docUri, *(aStream.get()));
    }
#endif

    setVariable(aVarName, Item(docItem));

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setContextItem ( const Item& aItem )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    store::Item_t lItem(Unmarshaller::getInternalItem(aItem));
    ZorbaImpl::checkItem(lItem);

    theCtx->set_context_item(lItem, 0);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}

  
bool
DynamicContextImpl::setContextItemAsDocument (
    const String& aDocURI,
    std::auto_ptr<std::istream> aInStream )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    xqpStringStore* lInternalDocURI = Unmarshaller::getInternalString(aDocURI);

    store::Item_t lDocItem = GENV_STORE.loadDocument(lInternalDocURI, *(aInStream.get()));

    setContextItem ( Item(lDocItem) );
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setContextItemAsDocument (
    const String& aDocURI)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    xqpString uriString (Unmarshaller::getInternalString(aDocURI));
    InternalDocumentURIResolver   *uri_resolver;
    uri_resolver = theStaticContext->get_document_uri_resolver();

    store::Item_t   uriItem;

    zorba::store::ItemFactory* item_factory = GENV_ITEMFACTORY;

    xqpStringStore_t uriStore = uriString.getStore();
    item_factory->createAnyURI(uriItem, uriStore);

    store::Item_t   docItem;
    docItem = uri_resolver->resolve(uriItem, theStaticContext, true, false);
    
    if(docItem.isNull())
      return false;

    return setContextItem ( Item(docItem) );
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::getContextItem (
  Item& aItem)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    store::Item_t lItem = theCtx->context_item();
    if (! lItem.isNull()) {
      aItem = lItem;
      return true;
    }
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setCurrentDateTime( const Item& aDateTimeItem )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    store::Item_t lItem = Unmarshaller::getInternalItem(aDateTimeItem);
    
    ZorbaImpl::checkItem(lItem);

    xqtref_t lItemType = theStaticContext->get_typemanager()->
                         create_named_type(lItem->getType(),
                                           TypeConstants::QUANT_ONE);

    if (!TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE)) 
    {
      ZORBA_ERROR_DESC_OSS(API0014_INVALID_ARGUMENT,
                           "Given item of type [" << lItemType->toString() 
                           << "] is not a subtype of [" 
                           << GENV_TYPESYSTEM.DATETIME_TYPE_ONE->toString() << "]");
    }

    theCtx->set_current_date_time(lItem);
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}

  
Item
DynamicContextImpl::getCurrentDateTime( ) const
{
  ZORBA_DCTX_TRY
  {
    return &*theCtx->get_current_date_time();
  }
  ZORBA_DCTX_CATCH
  return Item();
}


bool
DynamicContextImpl::setImplicitTimezone( int aTimezoneMinutes )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    theCtx->set_implicit_timezone(aTimezoneMinutes * 60);
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


int
DynamicContextImpl::getImplicitTimezone() const
{
  ZORBA_DCTX_TRY
  {
    return theCtx->get_implicit_timezone() / 60;
  }
  ZORBA_DCTX_CATCH
  return 0;
}


bool
DynamicContextImpl::setDefaultCollection( const Item& aCollectionUri )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    store::Item_t lItem = Unmarshaller::getInternalItem(aCollectionUri);
    ZorbaImpl::checkItem(lItem);

    theCtx->set_default_collection(lItem);
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


void DynamicContextImpl::checkNoIterators()
{
  ulong numIters = theQuery->theResultIterators.size();

  for (ulong i = 0; i < numIters; i++)
  {
    if (theQuery->theResultIterators[i]->isActive())
      ZORBA_ERROR(API0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS);
  }
}


Item
DynamicContextImpl::getDefaultCollection() const
{
  ZORBA_DCTX_TRY
  {
    return &*theCtx->get_default_collection();
  }
  ZORBA_DCTX_CATCH
  return Item();
}

bool
DynamicContextImpl::addExternalFunctionParam (
  const String& aName,
  void* aValue )
{
  ZORBA_DCTX_TRY
  {
    std::string lName = aName.c_str();
    return theCtx->addExternalFunctionParam(lName, aValue);
  }
  ZORBA_DCTX_CATCH
  return false;
}

bool
DynamicContextImpl::getExternalFunctionParam (
  const String& aName,
  void*& aValue) const
{
  ZORBA_DCTX_TRY
  {
    std::string lName = aName.c_str();
    return theCtx->getExternalFunctionParam(lName, aValue);
  }
  ZORBA_DCTX_CATCH
  return false;
}

} /* namespace zorba */
