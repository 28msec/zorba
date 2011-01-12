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
#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"

#include "runtime/util/item_iterator.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/temp_seq.h"

#include "util/xml_util.h"

#include "zorbaerrors/Assert.h"


namespace zorba {

#define ZORBA_DCTX_TRY try

#define ZORBA_DCTX_CATCH  catch (error::ZorbaError& e) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler, e); \
  } catch (std::exception& e) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler, e.what()); \
  } catch (...) { \
    ZorbaImpl::notifyError(theQuery->theErrorHandler); \
  } \


/****************************************************************************//**

********************************************************************************/
DynamicContextImpl::DynamicContextImpl(const XQueryImpl* aQuery)
  :
  theQuery(aQuery)
{
  theCtx = theQuery->theDynamicContext;
  theStaticContext = theQuery->theStaticContext.getp();
}


/****************************************************************************//**

********************************************************************************/
DynamicContextImpl::~DynamicContextImpl()
{
}


/****************************************************************************//**

********************************************************************************/

/**
 * Utility function: Given a single-string QName, which may be either
 * lexical (eg. "ns:foo") or a Clark-style universal name (eg.,
 * "{nsuri}:foo"), return the "expanded varname" which may be used to
 * add a variable to the underlying dynamic context. In the case of a
 * lexical QName, it will only attempt to look up the namespace prefix
 * on the main module's static context. For a universal name, it will
 * call to the other form of expand_varname().
 */
void DynamicContextImpl::expand_varname(
  const zstring &aQName, zstring* aExpandedName) const
{
  // First check for universal name.
  zstring lNsuri;
  if (xml::clark_uri(aQName, &lNsuri)) {
    // Looks like it is a universal name; jump over to other form.
    zstring lLocalname;
    xml::clark_localname(aQName, &lLocalname);
    expand_varname(lNsuri, lLocalname, aExpandedName);
    return;
  }

  // Note that this method will throw a ZorbaError if the qname has an
  // unknown prefix, which is fine. It apparently does not throw any
  // exception if the variable is not known, however, which is a
  // little odd and means that you'll get an unbound variable error at
  // runtime rather than an exception at setVariable() time.
  *aExpandedName = theCtx->expand_varname(theStaticContext, aQName);
}

/**
 * Utility function: Given an expanded QName (that is, a separate
 * namespace URI and localname), return the "expanded varname" which
 * may be used to add a variable to the underlying dynamic
 * context. This method will search through all static contexts,
 * including library modules, for a matching variable declaration.
 */
void DynamicContextImpl::expand_varname(
  const zstring &aNsuri, const zstring& aLocalname, zstring *aExpandedName)
  const
{
  std::map<short, static_context_t>& lMap = theQuery->theCompilerCB->theSctxMap;
  std::map<short, static_context_t>::iterator lIter;
  for (lIter = lMap.begin(); lIter != lMap.end(); lIter++) {
    // Note that this method will NOT throw any exception if the
    // variable is unknown - which is useful for us, even though it
    // probably should
    *aExpandedName = theCtx->expand_varname(lIter->second, aNsuri, aLocalname);
    // If it DID return something, we're done
    if (!aExpandedName->empty()) {
      return;
    }
  }
  // Consistent with the other form of expand_varname(), we do not
  // throw an exception if the variable isn't found anywhere; we just
  // return the empty varname adn let later code handle it.
}

bool DynamicContextImpl::setVariable(
    const String& aQName,
    const Item& aItem)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    // unmarshall the string and the item
    store::Item_t lItem(Unmarshaller::getInternalItem(aItem));
    ZorbaImpl::checkItem(lItem);

    const zstring& lString = Unmarshaller::getInternalString(aQName);
    zstring lExpandedName;
    expand_varname(lString, &lExpandedName);

    // add it to the internal context
    theCtx->add_variable(lExpandedName.str(), lItem);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariable(
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

    const zstring& lString = Unmarshaller::getInternalString(aQName);
    zstring lExpandedName;
    expand_varname(lString, &lExpandedName);

    theCtx->add_variable(lExpandedName.str(), lRes);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariable(
    const String& aNamespace,
    const String& aLocalname,
    const Iterator_t& aIterator )
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    Iterator* lIter = aIterator.get();
    if (!lIter)
      ZORBA_ERROR_DESC(API0014_INVALID_ARGUMENT, "Invalid Iterator given");

    store::Iterator_t lRes = Unmarshaller::getInternalIterator(lIter);

    const zstring& lNamespace = Unmarshaller::getInternalString(aNamespace);
    const zstring& lLocalname = Unmarshaller::getInternalString(aLocalname);

    zstring lExpandedName;
    expand_varname(lNamespace, lLocalname, &lExpandedName);
    
    theCtx->add_variable(lExpandedName.str(), lRes);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getVariable(
  const String& aNamespace,
  const String& aLocalname,
  Item& aItem,
  Iterator_t& aIterator) const
{
  ZORBA_DCTX_TRY
  {
    const zstring& lNamespace = Unmarshaller::getInternalString(aNamespace);
    const zstring& lLocalname = Unmarshaller::getInternalString(aLocalname);

    zstring lExpandedName;
    expand_varname(lNamespace, lLocalname, &lExpandedName);

    store::Item_t item;
    store::TempSeq_t tempseq;
    theCtx->get_variable(lExpandedName.str(), QueryLoc::null, item, tempseq);
    if (! item.isNull())
    {
      aItem = item;
    }
    else if (! tempseq.isNull())
    {
      store::Iterator_t seqIter = tempseq->getIterator();
      Iterator_t lIt(new StoreIteratorImpl(seqIter, theQuery->theErrorHandler));
      aIterator = lIt;
    }

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**
  @deprecated Use setVariableAsDocument(... LoadProperties)
********************************************************************************/
bool DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri,
    validation_mode_t aMode)
{
  XmlDataManager::LoadProperties lLoadProperties;
  lLoadProperties.setValidationMode(aMode);
  return setVariableAsDocument(aVarName, aDocUri, lLoadProperties, false);
}


/****************************************************************************//**
  @deprecated Use setVariableAsDocument(... LoadProperties)
********************************************************************************/
bool DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri,
    std::auto_ptr<std::istream> aStream,
    validation_mode_t aMode)
{
  XmlDataManager::LoadProperties lLoadProperties;
  lLoadProperties.setValidationMode(aMode);
  return setVariableAsDocument(aVarName, aDocUri, aStream, lLoadProperties, false);
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool replaceDoc)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    zorba::store::ItemFactory* factory = GENV_ITEMFACTORY;
    InternalDocumentURIResolver* uriResolver;
    uriResolver = theStaticContext->get_document_uri_resolver();

    const zstring& docUri = Unmarshaller::getInternalString(aDocUri);

    zstring tmpDocUri(docUri);
    store::Item_t docUriItem;
    factory->createAnyURI(docUriItem, tmpDocUri);

    store::Item_t docItem;
    docItem = uriResolver->resolve(docUriItem, theStaticContext, true, false, replaceDoc);

    if(docItem.isNull())
      return false;

    validateIfNecesary(docItem, docUri, docUriItem, aLoadProperties);

    return setVariable(aVarName, Item(docItem));
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariableAsDocument(
    const String& aVarName,
    const String& aDocUri,
    std::auto_ptr<std::istream> aStream,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool replaceDoc)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    zstring const &docUri = Unmarshaller::getInternalString(aDocUri);
    zstring baseUri = theStaticContext->get_base_uri();

    if (replaceDoc)
      GENV_STORE.deleteDocument(docUri);

    store::LoadProperties lLoadProperties;
    lLoadProperties.setEnableDtd(aLoadProperties.getEnableDtd());

    store::Item_t docItem = GENV_STORE.loadDocument(baseUri,
                                                    docUri,
                                                    *(aStream.get()),
                                                    lLoadProperties);

    validateIfNecesary(docItem, docUri, baseUri, aStream, aLoadProperties);

    setVariable(aVarName, Item(docItem));
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextItem(const Item& aItem)
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


/****************************************************************************//**
  @deprecated Use setContextItemAsDocument(... LoadProperties)
********************************************************************************/
bool DynamicContextImpl::setContextItemAsDocument(
    const String& aDocURI,
    std::auto_ptr<std::istream> aInStream)
{
  XmlDataManager::LoadProperties aLoadProperties;
  return setContextItemAsDocument(aDocURI, aInStream, aLoadProperties, false);
}


/****************************************************************************//**
  @deprecated Use setContextItemAsDocument(... LoadProperties)
********************************************************************************/
bool DynamicContextImpl::setContextItemAsDocument(const String& aDocURI)
{
  XmlDataManager::LoadProperties aLoadProperties;
  return setContextItemAsDocument(aDocURI, aLoadProperties, false);
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextItemAsDocument(
    const String& aDocURI,
    std::auto_ptr<std::istream> aInStream,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool aReplaceDoc)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    const zstring& docUri = Unmarshaller::getInternalString(aDocURI);
    zstring const &baseUri = theStaticContext->get_base_uri();

    store::LoadProperties lLoadProperties;
    lLoadProperties.setEnableDtd(aLoadProperties.getEnableDtd());

    if (aReplaceDoc)
      GENV_STORE.deleteDocument(docUri);

    store::Item_t docItem = GENV_STORE.loadDocument(baseUri,
                                                    docUri,
                                                    *(aInStream.get()),
                                                    lLoadProperties);

    // todo cezar should enable validation even for context items
    validateIfNecesary(docItem, docUri, baseUri, aInStream, aLoadProperties);
    setContextItem(Item(docItem));
    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextItemAsDocument(
    const String& aDocURI,
    const XmlDataManager::LoadProperties& aLoadProperties,
    bool aReplaceDoc)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    zstring docUri = Unmarshaller::getInternalString(aDocURI);

    InternalDocumentURIResolver* uri_resolver;
    uri_resolver = theStaticContext->get_document_uri_resolver();

    store::Item_t uriItem;
    zstring tmpDocUri(docUri);
    GENV_ITEMFACTORY->createAnyURI(uriItem, tmpDocUri);

    store::Item_t docItem;
    docItem = uri_resolver->resolve(uriItem, theStaticContext, true, false, aReplaceDoc);

    if(docItem.isNull())
      return false;

    // todo cezar should enable validation even for context items
    validateIfNecesary(docItem, docUri, uriItem, aLoadProperties);

    return setContextItem(Item(docItem));
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getContextItem(Item& aItem) const
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


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setCurrentDateTime(const Item& aDateTimeItem)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    store::Item_t lItem = Unmarshaller::getInternalItem(aDateTimeItem);

    ZorbaImpl::checkItem(lItem);

    TypeManager* tm = theStaticContext->get_typemanager();

    xqtref_t lItemType = tm->create_named_type(lItem->getType(),
                                               TypeConstants::QUANT_ONE);

    if (!TypeOps::is_subtype(tm, *lItemType, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
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


/****************************************************************************//**

********************************************************************************/
Item DynamicContextImpl::getCurrentDateTime() const
{
  ZORBA_DCTX_TRY
  {
    return &*theCtx->get_current_date_time();
  }
  ZORBA_DCTX_CATCH
  return Item();
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setImplicitTimezone(int aTimezoneMinutes)
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


/****************************************************************************//**

********************************************************************************/
int DynamicContextImpl::getImplicitTimezone() const
{
  ZORBA_DCTX_TRY
  {
    return theCtx->get_implicit_timezone() / 60;
  }
  ZORBA_DCTX_CATCH
  return 0;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setDefaultCollection(const Item& aCollectionUri)
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


/****************************************************************************//**

********************************************************************************/
void DynamicContextImpl::checkNoIterators() const
{
  if (theQuery->theResultIterator &&
      theQuery->theResultIterator->isOpen())
  {
    ZORBA_ERROR(API0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS);
  }
}


/****************************************************************************//**

********************************************************************************/
Item DynamicContextImpl::getDefaultCollection() const
{
  ZORBA_DCTX_TRY
  {
    return &*theCtx->get_default_collection();
  }
  ZORBA_DCTX_CATCH
  return Item();
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::addExternalFunctionParam(
  const String& aName,
  void* aValue)
{
  ZORBA_DCTX_TRY
  {
    std::string lName = aName.c_str();
    return theCtx->addExternalFunctionParam(lName, aValue);
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getExternalFunctionParam(
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


/****************************************************************************//**

********************************************************************************/
void DynamicContextImpl::validateIfNecesary(
    store::Item_t& docItem,
    const zstring& docUri,
    store::Item_t& docUriItem,
    const XmlDataManager::LoadProperties& aLoadProperties)
{
#ifndef ZORBA_NO_XMLSCHEMA
  validation_mode_t lValidationMode = aLoadProperties.getValidationMode();
  TypeManager* tm = theStaticContext->get_typemanager();

  if (!docItem->isValidated())
  {
    if (lValidationMode != validate_skip)
    {
      store::Item_t validatedNode;
      store::Item_t typeName;
      QueryLoc loc;

      ParseConstants::validation_mode_t mode = (lValidationMode == validate_lax ?
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
        GENV_STORE.addNode(docUri, docItem);
      }
    }
  }
  else if (tm->getSchema() == NULL || lValidationMode == validate_skip)
  {
    GENV_STORE.deleteDocument(docUri);
    InternalDocumentURIResolver* uriResolver;
    uriResolver = theStaticContext->get_document_uri_resolver();
    docItem = uriResolver->resolve(docUriItem, theStaticContext, true, false, false);
  }
#endif//ZORBA_NO_XMLSCHEMA
}


/****************************************************************************//**

********************************************************************************/
void DynamicContextImpl::validateIfNecesary(
    store::Item_t& docItem,
    const zstring& docUri,
    const zstring& baseUri,
    std::auto_ptr<std::istream> aInStream,
    const XmlDataManager::LoadProperties& aLoadProperties)
{
#ifndef ZORBA_NO_XMLSCHEMA
  validation_mode_t lValidationMode = aLoadProperties.getValidationMode();
  TypeManager* tm = theStaticContext->get_typemanager();

  if (!docItem->isValidated())
  {
    if (lValidationMode != validate_skip)
    {
      store::Item_t validatedNode;
      store::Item_t typeName;
      QueryLoc loc;

      ParseConstants::validation_mode_t mode = (lValidationMode == validate_lax ?
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
        GENV_STORE.addNode(docUri, docItem);
      }
    }
  }
  else if (tm->getSchema() == NULL || lValidationMode == validate_skip)
  {
    GENV_STORE.deleteDocument(docUri);

    store::LoadProperties lStoreLoadProperties;
    lStoreLoadProperties.setEnableDtd(aLoadProperties.getEnableDtd());

    docItem = GENV_STORE.loadDocument(baseUri,
                                      docUri,
                                      *(aInStream.get()),
                                      lStoreLoadProperties);
  }
#endif
}

} /* namespace zorba */
