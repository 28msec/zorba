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
#include "zorbatypes/integer.h"

#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"
#include "api/item_iter_query_result.h"
#include "api/item_iter_store.h"
#include "api/dynamiccontextimpl.h"

#include "compiler/expression/var_expr.h"
#include "compiler/parser/query_loc.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"

#include "runtime/util/item_iterator.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/temp_seq.h"
#include "types/casting.h"

#include "util/xml_util.h"

#include "util/string_util.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_exception.h"
#include "diagnostics/zorba_exception.h"
#include "diagnostics/dict.h"


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
  name, it will call to the other form of get_var_info().
********************************************************************************/
VarInfo* DynamicContextImpl::get_var_info(const zstring& inVarName)
{
  // First check for universal name.
  zstring nsUri;
  if (xml::clark_uri(inVarName, &nsUri))
  {
    // Looks like it is a universal name; jump over to other form.
    zstring localname;
    xml::clark_localname(inVarName, &localname);
    return get_var_info(nsUri, localname);
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
  VarInfo* var = theStaticContext->lookup_var(qnameItem);

  if (!var)
  {
    throw XQUERY_EXCEPTION(err::XPST0008,
    ERROR_PARAMS(ZED(XPST0008_VariableName_2),
                 BUILD_STRING('{',
                              qnameItem->getNamespace(),
                              '}',
                              qnameItem->getLocalName())));
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
VarInfo* DynamicContextImpl::get_var_info(
    const zstring& inVarUri,
    const zstring& inVarLocalName) const
{
  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, inVarUri, zstring(), inVarLocalName);

  VarInfo* var = NULL;

  if (theQuery != NULL)
  {
    CompilerCB::SctxMap& lMap = theQuery->theCompilerCB->theSctxMap;
    CompilerCB::SctxMap::const_iterator ite;

    for (ite = lMap.begin(); ite != lMap.end(); ++ite)
    {
      var = ite->second->lookup_var(qname);

      if (var)
        return var;
    }
  }
  else
  {
    var = theStaticContext->lookup_var(qname);
  }

  if (!var)
  {
    throw XQUERY_EXCEPTION(err::XPST0008,
    ERROR_PARAMS(ZED(XPST0008_VariableName_2),
                 BUILD_STRING('{', inVarUri, '}', inVarLocalName )));
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

    VarInfo* var = get_var_info(nameSpace, localName);

    ulong varId = var->getId();

    store::Item_t item;
    store::TempSeq_t tempseq;

    theCtx->get_variable(varId, var->getName(), QueryLoc::null, item, tempseq);

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

    VarInfo* var = NULL;

    try
    {
      var = get_var_info(varName);
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

    ulong varId = var->getId();

    theCtx->add_variable(varId, value);

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

    VarInfo* var = NULL;

    try
    {
      var = get_var_info(nameSpace, localName);
    }
    catch (ZorbaException const& e)
    {
      // Normally, we should be throwing an exception if the variable has not
      // been declared inside the xquery program, but this causes many failures
      // with the w3c XQTS.
      if (e.diagnostic() == err::XPST0008)
      {
        return false;
      }
      throw;
    }

    ulong varId = var->getId();

    theCtx->add_variable(varId, value);

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
    const Item& inValue)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    const zstring& nameSpace = Unmarshaller::getInternalString(inNamespace);
    const zstring& localName = Unmarshaller::getInternalString(inLocalname);

    store::Item_t value(Unmarshaller::getInternalItem(inValue));
    checkItem(value);

    VarInfo* var = NULL;

    try
    {
      var = get_var_info(nameSpace, localName);
    }
    catch (ZorbaException const& e)
    {
      // Normally, we should be throwing an exception if the variable has not
      // been declared inside the xquery program, but this causes many failures
      // with the w3c XQTS.
      if (e.diagnostic() == err::XPST0008)
      {
        return false;
      }
      throw;
    }

    ulong varId = var->getId();

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
    const Item& inValue,
    bool cast)
{
  ZORBA_DCTX_TRY
  {
    checkNoIterators();

    // unmarshall the string and the item
    const zstring& varName = Unmarshaller::getInternalString(inVarName);

    store::Item_t value(Unmarshaller::getInternalItem(inValue));
    checkItem(value);

    VarInfo* var = NULL;

    try
    {
      var = get_var_info(varName);
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

    if ( cast ) {
      store::Item_t temp;
      GenericCast::castToAtomic(
        temp, value, var->getType(), var->getVar()->get_type_manager(),
        /*nsCtx*/ nullptr, QueryLoc::null
      );
      value = temp;
    }

    ulong varId = var->getId();

    theCtx->add_variable(varId, value);

    return true;
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
void DynamicContextImpl::checkItem(const store::Item_t& item)
{
  if (!item)
  {
    throw ZORBA_EXCEPTION(zerr::ZAPI0014_INVALID_ARGUMENT,
    ERROR_PARAMS("null", ZED(BadItem)));
  }

  // For string items, check that the value is a valid Unicode codepoint sequence
  if (item->isStreamable() == false && item->isAtomic())
  {
    const char* invalid_char;

    store::SchemaTypeCode itemTypeCode = item->getTypeCode();
    
    if (TypeOps::is_subtype(itemTypeCode, store::XS_STRING) &&
        (invalid_char = utf8::validate(item->getStringValue().c_str())) != NULL)
    {
      throw XQUERY_EXCEPTION(err::FOCH0001,
      ERROR_PARAMS(zstring("#x") +
                   BUILD_STRING(std::uppercase << std::hex
                                << (static_cast<unsigned int>(*invalid_char) & 0xFF))));
    }
  }
}



/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextItem(const Item& inValue)
{
  String varName = Unmarshaller::newString(static_context::DOT_VAR_NAME);
  bool res = setVariable(varName, inValue);

  store::Item_t one;

  if (!theCtx->is_set_variable(dynamic_context::IDVAR_CONTEXT_ITEM_POSITION))
  {
    GENV_ITEMFACTORY->createInteger(one, xs_integer(1));

    varName = Unmarshaller::newString(static_context::DOT_POS_VAR_NAME);
    setVariable(varName, Item(one));
  }

  if (!theCtx->is_set_variable(dynamic_context::IDVAR_CONTEXT_ITEM_SIZE))
  {
    if (!one)
      GENV_ITEMFACTORY->createInteger(one, xs_integer(1));

    varName = Unmarshaller::newString(static_context::DOT_SIZE_VAR_NAME);
    setVariable(varName, Item(one));
  }

  return res;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextSize(const Item& inValue)
{
  try
  {
    store::Item* value = Unmarshaller::getInternalItem(inValue);

    if (!value->isAtomic())
    {
      throw ZORBA_EXCEPTION(zerr::ZAPI0023_NON_ATOMIC_CONTEXT_SIZE_VALUE);
    }

    store::SchemaTypeCode typeCode = value->getTypeCode();

    if (typeCode < store::XS_INTEGER || typeCode > store::XS_POSITIVE_INTEGER)
    {
      xqtref_t type = GENV_TYPESYSTEM.create_value_type(value);

      throw ZORBA_EXCEPTION(zerr::ZAPI0024_NON_INTEGER_CONTEXT_SIZE_VALUE,
      ERROR_PARAMS(type->toSchemaString()));
    }
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e);
    return false;
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e.what());
    return false;
  }
  catch (...)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler);
    return false;
  }

  String varName = Unmarshaller::newString(static_context::DOT_SIZE_VAR_NAME);
  return setVariable(varName, inValue);
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::setContextPosition(const Item& inValue)
{
  try
  {
    store::Item* value = Unmarshaller::getInternalItem(inValue);

    if (!value->isAtomic())
    {
      throw ZORBA_EXCEPTION(zerr::ZAPI0025_NON_ATOMIC_CONTEXT_POSITION_VALUE);
    }

    store::SchemaTypeCode typeCode = value->getTypeCode();

    if (typeCode < store::XS_INTEGER || typeCode > store::XS_POSITIVE_INTEGER)
    {
      xqtref_t type = GENV_TYPESYSTEM.create_value_type(value);

      throw ZORBA_EXCEPTION(zerr::ZAPI0026_NON_INTEGER_CONTEXT_POSITION_VALUE,
      ERROR_PARAMS(type->toSchemaString()));
    }
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e);
    return false;
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e.what());
    return false;
  }
  catch (...)
  {
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler);
    return false;
  }

  String varName = Unmarshaller::newString(static_context::DOT_POS_VAR_NAME);
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
bool DynamicContextImpl::getContextSize(Item& outValue) const
{
  String varName;

  ZORBA_DCTX_TRY
  {
    varName = Unmarshaller::newString(static_context::DOT_SIZE_VAR_NAME);
  }
  ZORBA_DCTX_CATCH

  Iterator_t dummy;

  return getVariable("", varName, outValue, dummy);
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::getContextPosition(Item& outValue) const
{
  String varName;

  ZORBA_DCTX_TRY
  {
    varName = Unmarshaller::newString(static_context::DOT_POS_VAR_NAME);
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

    checkItem(lItem);

    if (!TypeOps::is_subtype(lItem->getTypeCode(), store::XS_DATETIME))
    {
      TypeManager* tm = theStaticContext->get_typemanager();
      xqtref_t type = tm->create_value_type(lItem);
      RAISE_ERROR_NO_LOC(zerr::ZAPI0014_INVALID_ARGUMENT,
      ERROR_PARAMS(type->toSchemaString(),
                   ZED(TypeIsNotSubtype),
                   GENV_TYPESYSTEM.DATETIME_TYPE_ONE->toSchemaString()));
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
    checkItem(lItem);

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
void DynamicContextImpl::setLocale(
    locale::iso639_1::type aLang,
    locale::iso3166_1::type aCountry )
{
  theCtx->set_locale( aLang, aCountry );
}


void DynamicContextImpl::getLocale(
    locale::iso639_1::type *aLang,
    locale::iso3166_1::type *aCountry) const
{
  theCtx->get_locale(aLang, aCountry);
}


/****************************************************************************//**

********************************************************************************/
void DynamicContextImpl::setCalendar(time::calendar::type aCalendar)
{
  theCtx->set_calendar(aCalendar);
}


time::calendar::type DynamicContextImpl::getCalendar() const
{
  return theCtx->get_calendar();
}

/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::addExternalFunctionParam(
    const String& aName,
    void* aValue)
{
  ZORBA_DCTX_TRY
  {
    std::string lName( aName.c_str() );
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
    std::string lName( aName.c_str() );
    return theCtx->getExternalFunctionParam(lName, aValue);
  }
  ZORBA_DCTX_CATCH
  return false;
}


/****************************************************************************//**

********************************************************************************/
bool DynamicContextImpl::addExternalFunctionParameter(
    const String& aName,
    ExternalFunctionParameter* aValue ) const
{
  ZORBA_DCTX_TRY
  {
    std::string lName( aName.c_str() );
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
    std::string lName( aName.c_str() );
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
