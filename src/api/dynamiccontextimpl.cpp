#include "api/dynamiccontextimpl.h"

#include <zorba/default_error_handler.h>
#include <zorba/xmldatamanager.h>
#include <zorba/zorba.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "store/api/item.h"
#include "store/api/item_iterator.h"
#include "api/unmarshaller.h"

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
    theCtx->add_variable(lExpandedName, lIterator);
  }

  void
  DynamicContextImpl::setVariable( const String& aQName, const ItemSequence_t& aSequence )
  {
  }

  void
  DynamicContextImpl::setVariable( const String& aQName, const ResultIterator& aResultIterator )
  {
  }

  void
  DynamicContextImpl::setVariableAsDocument( const String& aQName, const String& aDocURI, std::istream& aStream )
  {
    XmlDataManager* lDataManager = Zorba::getInstance()->getXmlDataManager();

    Item lDocItem = lDataManager->loadDocument(aDocURI, aStream, theErrorHandler);
    setVariable ( aQName, lDocItem );
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
    XmlDataManager* lDataManager = Zorba::getInstance()->getXmlDataManager();

    Item lDocItem = lDataManager->loadDocument(aDocURI, aInStream, theErrorHandler);
    setContextItem ( lDocItem );
  }

} /* namespace zorba */
