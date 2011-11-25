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
#include "stdafx.h"

#include <zorba/diagnostic_handler.h>
#include <zorba/zorba.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"

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
#include "compiler/expression/var_expr.h"

#include "runtime/util/item_iterator.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/temp_seq.h"

#include "util/xml_util.h"

#include "util/string_util.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"


namespace zorba {

#define ZORBA_DCTX_TRY try

#define ZORBA_DCTX_CATCH  catch (ZorbaException const& e) { \
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e); \
  } catch (std::exception const& e) { \
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e.what()); \
  } catch (...) { \
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler); \
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
  Utility function: Given a single-string var name, which may be either a lexical
  qname (eg. "ns:foo") or a Clark-style universal name (eg., "{nsuri}:foo"),
  return the var_expr node that represents this variable within the expression
  tree. The var_expr can be found within the static context that the variable
  belongs to. In the case of a lexical QName, this method will only attempt to
  look up the namespace prefix in the main module's static context. For a clark
  name, it will call to the other form of get_var_expr().
********************************************************************************/
var_expr* DynamicContextImpl::get_var_expr(const zstring& inVarName)
{
  // First check for universal name.
  zstring nsUri;
  if (xml::clark_uri(inVarName, &nsUri))
  {
    // Looks like it is a universal name; jump over to other form.
    zstring localname;
    xml::clark_localname(inVarName, &localname);
    return get_var_expr(nsUri, localname);
  }

  ZORBA_ASSERT(theStaticContext);

  // Note: expand_qname will throw an error if the qname has a non-empty
  // prefix and there is no associated namespace uri in theStaticContext.
  rchandle<QName> qname = new QName(QueryLoc::null, inVarName);
  store::Item_t qnameItem;
  theStaticContext->expand_qname(qnameItem,
                                 zstring(),
                                 qname->get_prefix(),
                                 qname->get_localname(),
                                 QueryLoc::null);

  // Note: lookup_var will return NULL if the variable is not known.
  var_expr* var = theStaticContext->lookup_var(qnameItem,
                                               QueryLoc::null,
                                               zerr::ZXQP0000_NO_ERROR);

  if (var == NULL)
  {
    throw XQUERY_EXCEPTION(err::XPST0008,
    ERROR_PARAMS(BUILD_STRING('{',
                              qnameItem->getNamespace(),
                              '}',
                              qnameItem->getLocalName()),
                 ZED(Variable)));
  }

  return var;
}


/****************************************************************************//**
  Utility function: Given an expanded QName (that is, a separate namespace URI
  and localname), return the var_expr node that represents this variable within
  the expression tree. The var_expr can be found within the static context that
  the variable  belongs to. This method will search through all static contexts,
  including library modules, for a matching variable declaration.
********************************************************************************/
var_expr* DynamicContextImpl::get_var_expr(
    const zstring& inVarUri,
    const zstring& inVarLocalName) const
{
  var_expr* var = NULL;

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, inVarUri, zstring(), inVarLocalName);

  if (theQuery != NULL)
  {
    std::map<short, static_context_t>& lMap = theQuery->theCompilerCB->theSctxMap;
    std::map<short, static_context_t>::const_iterator ite;
    for (ite = lMap.begin(); ite != lMap.end(); ++ite)
    {
      var = ite->second->lookup_var(qname, QueryLoc::null, zerr::ZXQP0000_NO_ERROR);

      if (var)
        break;
    }
  }
  else
  {
    var = theStaticContext->lookup_var(qname, QueryLoc::null, zerr::ZXQP0000_NO_ERROR);
  }

  if (var == NULL)
  {
    throw XQUERY_EXCEPTION(err::XPST0008,
    ERROR_PARAMS(BUILD_STRING('{', inVarUri, '}', inVarLocalName ), ZED(Variable)));
  }

  return var;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getVariable(
  const String& inNamespace,
  const String& inLocalname,
  Item& outItem,
  Iterator_t& outIterator) const
{
  ZORBA_DCTX_TRY
  {
    const zstring& nameSpace = Unmarshaller::getInternalString(inNamespace);
    const zstring& localName = Unmarshaller::getInternalString(inLocalname);

    var_expr* var = get_var_expr(nameSpace, localName);
    ulong varId = var->get_unique_id();

    store::Item_t item;
    store::TempSeq_t tempseq;

    theCtx->get_variable(varId, var->get_name(), QueryLoc::null, item, tempseq);

    if (! item.isNull())
    {
      outItem = item;
    }
    else if (! tempseq.isNull())
    {
      store::Iterator_t seqIter = tempseq->getIterator();
      Iterator_t lIt(new StoreIteratorImpl(seqIter, theQuery->theDiagnosticHandler));
      outIterator = lIt;
    }

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariable(
    const String& inNamespace,
    const String& inLocalname,
    const Iterator_t& inValue)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    if (!inValue.get())
    {
      throw ZORBA_EXCEPTION(zerr::ZAPI0014_INVALID_ARGUMENT,
      ERROR_PARAMS("null", ZED(BadIterator)));
    }

    const zstring& nameSpace = Unmarshaller::getInternalString(inNamespace);
    const zstring& localName = Unmarshaller::getInternalString(inLocalname);
    store::Iterator_t value = Unmarshaller::getInternalIterator(inValue.get());

    var_expr* var;

    try
    {
      var = get_var_expr(nameSpace, localName);
    }
    catch (ZorbaException const& e)
    {
      // Normally, we should be throwing an exception if the variable has not
      // been declared inside the xquery program, but this cases many failures
      // with the w3c XQTS.
      if (e.diagnostic() == err::XPST0008)
      {
        return false;
      }
      throw;
    }

    ulong varId = var->get_unique_id();

    theCtx->add_variable(varId, value);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariable(
    const String& inVarName,
    const Item& inValue)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    // unmarshall the string and the item
    const zstring& varName = Unmarshaller::getInternalString(inVarName);
    store::Item_t value(Unmarshaller::getInternalItem(inValue));
    ZorbaImpl::checkItem(value);
    var_expr* var;

    // For string items, check that the value is a valid Unicode codepoint sequence
    const char* invalid_char;
    TypeManager* tm = theStaticContext->get_typemanager();
    RootTypeManager& rtm = GENV_TYPESYSTEM;

    xqtref_t itemType = tm->create_value_type(value);

    if (value->isStreamable() == false &&
        TypeOps::is_equal(tm, *itemType, *rtm.STRING_TYPE_ONE, QueryLoc::null) &&
        (invalid_char = utf8::validate(value->getStringValue().c_str())) != NULL)
    {
      throw XQUERY_EXCEPTION(err::FOCH0001, 
      ERROR_PARAMS(zstring("#x") + 
      BUILD_STRING(std::uppercase << std::hex
                   << (static_cast<unsigned int>(*invalid_char) & 0xFF)) ));
    }

    try
    {
      var = get_var_expr(varName);
    }
    catch (ZorbaException const& e)
    {
      // Normally, we should be throwing an exception if the variable has not
      // been declared inside the xquery program, but this cases many failures
      // with the w3c XQTS.
      if (e.diagnostic() == err::XPST0008)
      {
        return false;
      }
      throw;
    }

    ulong varId = var->get_unique_id();

    // add it to the internal context
    theCtx->add_variable(varId, value);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setVariable(
    const String& inVarName,
    const Iterator_t& inValue)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    if (!inValue.get())
    {
      throw ZORBA_EXCEPTION(zerr::ZAPI0014_INVALID_ARGUMENT,
      ERROR_PARAMS("null", ZED( BadIterator)));
    }

    const zstring& varName = Unmarshaller::getInternalString(inVarName);
    store::Iterator_t value = Unmarshaller::getInternalIterator(inValue.get());
    var_expr* var;

    try
    {
      var = get_var_expr(varName);
    }
    catch (ZorbaException const& e)
    {
      // Normally, we should be throwing an exception if the variable has not
      // been declared inside the xquery program, but this cases many failures
      // with the w3c XQTS.
      if (e.diagnostic() == err::XPST0008)
      {
        return false;
      }
      throw;
    }

    ulong varId = var->get_unique_id();

    theCtx->add_variable(varId, value);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextItem(const Item& inValue)
{
  String varName = Unmarshaller::newString(static_context::DOT_VAR_NAME);
  return setVariable(varName, inValue);
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getContextItem(Item& outValue) const
{
  String varName;

  ZORBA_DCTX_TRY
  {
    varName = Unmarshaller::newString(static_context::DOT_VAR_NAME);
  }
  ZORBA_DCTX_CATCH

  Iterator_t dummy;

  return getVariable("", varName, outValue, dummy);
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

    if (!TypeOps::is_subtype(tm,
                             *lItemType,
                             *GENV_TYPESYSTEM.DATETIME_TYPE_ONE,
                             QueryLoc::null))
    {
      RAISE_ERROR_NO_LOC(zerr::ZAPI0014_INVALID_ARGUMENT,
      ERROR_PARAMS(lItemType->toString(),
                   ZED(TypeIsNotSubtype),
                   GENV_TYPESYSTEM.DATETIME_TYPE_ONE->toString()));
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
    throw ZORBA_EXCEPTION( zerr::ZAPI0027_CANNOT_UPDATE_DCTX_WITH_ITERATORS );
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
bool
DynamicContextImpl::addExternalFunctionParameter (
    const String& aName,
    ExternalFunctionParameter* aValue )
{
  ZORBA_DCTX_TRY
  {
    std::string lName = aName.c_str();
    return theCtx->addExternalFunctionParameter(lName, aValue);
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
ExternalFunctionParameter*
DynamicContextImpl::getExternalFunctionParameter ( const String& aName ) const
{
  ZORBA_DCTX_TRY
  {
    std::string lName = aName.c_str();
    return theCtx->getExternalFunctionParameter(lName);
  }
  ZORBA_DCTX_CATCH
  return 0;
}


/****************************************************************************//**

********************************************************************************/
bool 
DynamicContextImpl::isBoundExternalVariable(const String& aNamespace, const String& aLocalname) const
{
  ZORBA_DCTX_TRY
  {
    if(theQuery->isBoundVariable(aNamespace, aLocalname))
      return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}

/****************************************************************************//**

********************************************************************************/
bool
DynamicContextImpl::isBoundContextItem() const
{
  ZORBA_DCTX_TRY
  {
    String varName = Unmarshaller::newString(static_context::DOT_VAR_NAME);
    if(theQuery->isBoundVariable("", varName))
      return true;
  }
  ZORBA_DCTX_CATCH
  return false;

}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
