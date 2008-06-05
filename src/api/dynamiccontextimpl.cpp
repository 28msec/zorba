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
#include "api/dynamiccontextimpl.h"

#include <zorba/default_error_handler.h>
#include <zorba/zorba.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "system/globalenv.h"
#include "types/typeops.h"
#include "types/typemanager.h"
#include "types/root_typemanager.h"
#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/resultiteratorchainer.h"
#include "api/xmldatamanagerimpl.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/util/item_iterator.h"
#include "store/api/item.h"


namespace zorba {

#define GET_DATA_MANAGER() \
  reinterpret_cast<XmlDataManagerImpl*>(Zorba::getInstance(NULL)->getXmlDataManager());

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

  SYNC_CODE(theCloningMutexp = &theQuery->theCloningMutex;)
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

    // create an item iterator to store in the dyn context
    ItemIterator_t lIterator = new ItemIterator(lItem);

    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, lString);

    // add it to the internal context
    theCtx->add_variable(lExpandedName, &*lIterator);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariable(
    const String& aQName,
    const ResultIterator_t& aResultIterator )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    ResultIterator* lIter = &*aResultIterator;
    if (!lIter)
      ZORBA_ERROR_DESC(API0014_INVALID_ARGUMENT,
                       "Invalid ResultIterator given");
        
    store::Iterator_t lRes = new store::ResultIteratorChainer(lIter);

    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, Unmarshaller::getInternalString(aQName));

    theCtx->add_variable(lExpandedName, &*lRes);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariableAsDocument(
    const String& aQName,
    const String& aDocURI, 
    std::istream& aStream )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    XmlDataManagerImpl* lDataManager = GET_DATA_MANAGER(); 

    Item lDocItem = lDataManager->loadDocument(aDocURI, aStream, theQuery->theErrorHandler);
    setVariable ( aQName, lDocItem );

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setVariableAsDocument(
    const String& aQName,
    const String& aDocURI, 
    std::istream* aStream )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    XmlDataManagerImpl* lDataManager = GET_DATA_MANAGER();

    Item lDocItem = lDataManager->loadDocument(aDocURI, aStream, theQuery->theErrorHandler);
    setVariable ( aQName, lDocItem );

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

    SYNC_CODE(AutoMutex lock(theCloningMutexp);)

    theCtx->set_context_item(lItem, 0);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}

  
bool
DynamicContextImpl::setContextItemAsDocument (
    const String& aDocURI,
    std::istream& aInStream )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    XmlDataManagerImpl* lDataManager = GET_DATA_MANAGER();

    Item lDocItem = lDataManager->loadDocument(aDocURI, aInStream, theQuery->theErrorHandler);

    setContextItem ( lDocItem );
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


bool
DynamicContextImpl::setContextItemAsDocument (
    const String& aDocURI,
    std::istream* aInStream )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    XmlDataManagerImpl* lDataManager = GET_DATA_MANAGER();

    Item lDocItem = lDataManager->loadDocument(aDocURI, aInStream, theQuery->theErrorHandler);

    setContextItem ( lDocItem );
    return true;
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

    SYNC_CODE(AutoMutex lock(theCloningMutexp);)

    theCtx->set_current_date_time(lItem);
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}

  
Item
DynamicContextImpl::getCurrentDateTime( )
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

    SYNC_CODE(AutoMutex lock(theCloningMutexp);)

    theCtx->set_implicit_timezone(aTimezoneMinutes * 60);
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


int
DynamicContextImpl::getImplicitTimezone()
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
    xqpString     lString(lItem->getStringValue());

    SYNC_CODE(AutoMutex lock(theCloningMutexp);)

    theCtx->set_default_collection(lString);
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



} /* namespace zorba */
