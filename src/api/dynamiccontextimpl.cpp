#include "api/dynamiccontextimpl.h"

#include <zorba/default_error_handler.h>
#include <zorba/xmldatamanager.h>
#include <zorba/zorba.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "store/api/item.h"
#include "store/api/item_iterator.h"
#include "api/unmarshaller.h"
#include "system/globalenv.h"
#include "types/typeops.h"
#include "types/typemanager.h"
#include "types/root_typemanager.h"
#include "api/zorbaimpl.h"
#include "api/resultiteratorchainer.h"
#include "runtime/api/plan_wrapper.h"

namespace zorba {

  DynamicContextImpl::DynamicContextImpl(dynamic_context* aDctx, static_context* aSctx, ErrorHandler* aErrorHandler) 
    : theCtx(aDctx),
      theStaticContext(aSctx),
      theErrorHandler(aErrorHandler)
  {
  }

  DynamicContextImpl::~DynamicContextImpl() 
  {
  }

  void
  DynamicContextImpl::setVariable( const String& aQName, const Item& aItem )
  {
    // unmarshall the string and the item
    store::Item_t lItem(Unmarshaller::getInternalItem(aItem));
    xqpString     lString = xqpString(Unmarshaller::getInternalString(aQName));

    // create an item iterator to store in the dyn context
    store::ItemIterator_t lIterator = new store::ItemIterator(lItem);

    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, lString);

    // add it to the internal context
    theCtx->add_variable(lExpandedName, &*lIterator);
  }


  void
  DynamicContextImpl::setVariable( const String& aQName, const ResultIterator_t& aResultIterator )
  {
    store::Iterator_t lRes = new store::ResultIteratorChainer(&*aResultIterator);
    xqpString     lString = xqpString(Unmarshaller::getInternalString(aQName));

    xqpString lExpandedName = theCtx->expand_varname(theStaticContext, lString);

    theCtx->add_variable(lExpandedName, &*lRes);
  }

  void
  DynamicContextImpl::setVariableAsDocument( const String& aQName, const String& aDocURI, std::istream& aStream )
  {
    try {
      XmlDataManager* lDataManager = Zorba::getInstance()->getXmlDataManager();

      Item lDocItem = lDataManager->loadDocument(aDocURI, aStream, theErrorHandler);
      setVariable ( aQName, lDocItem );
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    }
  }

  void
  DynamicContextImpl::setContextItem ( const Item& aItem )
  {
    store::Item_t lItem(Unmarshaller::getInternalItem(aItem));
    theCtx->set_context_item(lItem, 0);
  }
  
  void
  DynamicContextImpl::setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream )
  {
    try {
      XmlDataManager* lDataManager = Zorba::getInstance()->getXmlDataManager();

      Item lDocItem = lDataManager->loadDocument(aDocURI, aInStream, theErrorHandler);
      setContextItem ( lDocItem );
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    }
  }

  void
  DynamicContextImpl::setCurrentDateTime( const Item& aDateTimeItem )
  {
    try {
      store::Item_t lItem = Unmarshaller::getInternalItem(aDateTimeItem);
      xqtref_t lItemType = theStaticContext->get_typemanager()->
                           create_named_type(lItem->getType(),
                                             TypeConstants::QUANT_ONE);

      if (!TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE)) {
        ZORBA_ERROR_DESC_OSS(ZorbaError::API0014_INVALID_ARGUMENT, "Given item of type [" << lItemType->toString() 
                                                                   << "] is not a subtype of [" 
                                                                   << GENV_TYPESYSTEM.DATETIME_TYPE_ONE->toString() << "]");
      }

      theCtx->set_current_date_time(lItem);
    } catch (error::ZorbaError &e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    }
  }
  
  Item
  DynamicContextImpl::getCurrentDateTime( )
  {
    return &*theCtx->get_current_date_time();
  }

  void
  DynamicContextImpl::setImplicitTimezone( int aTimezone )
  {
    theCtx->set_implicit_timezone(aTimezone);
  }

  int
  DynamicContextImpl::getImplicitTimezone()
  {
    return theCtx->get_implicit_timezone();
  }

  void
  DynamicContextImpl::setDefaultCollection( const Item& aCollectionUri )
  {
    store::Item_t lItem = Unmarshaller::getInternalItem(aCollectionUri);
    xqpString     lString(lItem->getStringValue());
    theCtx->set_default_collection(lString);
  }


  Iterator_t
  DynamicContextImpl::getAvailableCollections ( )
  {
  }


} /* namespace zorba */
