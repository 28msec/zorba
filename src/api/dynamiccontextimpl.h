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
#pragma once
#ifndef ZORBA_DYNAMIC_CONTEXT_IMPL_H
#define ZORBA_DYNAMIC_CONTEXT_IMPL_H

#include <zorba/dynamic_context.h>

#include "common/shared_types.h"


namespace zorba {

class DiagnosticHandler;
class XQueryImpl;


/*******************************************************************************

  Wrapper of the internal dynamic_context class.

  An instance of DynamicContextImpl is created when the application asks for
  the dynamic context of a query (see XQueryImpl::getDynamicContext() method).
  There can be at most one instance of DynamicContextImpl per XQuery.
  DynamicContextImpl does not own any of the other objs that it points to.

  theCtx :
  Pointer to the internal dynamic_context obj (which is owned by the XQuery obj).

  theStaticContext :
  Pointer to the internal static_context obj (which is owned by the XQuery obj).
  Access to the static context is needed to resolve names, etc.

  theDiagnosticHandler :
  Pointer to the error handler of the query (which is owned either by the XQuery
  obj or the application).

********************************************************************************/
class DynamicContextImpl : public DynamicContext
{
  friend class Unmarshaller; // needs to get the context out of this class
  friend class XQueryImpl;
  friend class ExtFunctionCallIterator;  // ExtFunctionCallIterator needs to
                                         // create a wrapper to a dynamic_context
                                         // to pass it to the external function


protected:
  const XQueryImpl          * theQuery;

  dynamic_context           * theCtx;

  static_context            * theStaticContext;

protected:
  DynamicContextImpl(const XQueryImpl* aQuery);

  // Used by ExtFunctionCallIterator to create a temporary wrapper
  DynamicContextImpl(
      const XQueryImpl* aQuery,
      dynamic_context* aDctx,
      static_context* aSctx)
    :
    theQuery(aQuery), theCtx(aDctx), theStaticContext(aSctx)
  {
  }

  virtual ~DynamicContextImpl();

public:
  virtual bool
  getExternalVariables(
      std::vector<Item>& aVars)const;

  virtual bool
  getVariable(
      const String& inNamespace,
      const String& inLocalname,
      Item& outItem,
      Iterator_t& outIterator) const;

  virtual bool
  setVariable(
      const String& inVarName,
      const Item& inValue);

  virtual bool
  setVariable(
      const String& inVarName,
      const Iterator_t& inValue);

  virtual bool
  setVariable(
      const String& inNamespace,
      const String& inLocalname,
      const Iterator_t& inValue);

  virtual bool
  setContextItem(const Item& inValue);

  virtual bool
  getContextItem(Item& outValue) const;

  virtual bool
  setCurrentDateTime(const Item& aDateTimeItem);

  virtual Item
  getCurrentDateTime() const;

  // In minutes
  virtual bool
  setImplicitTimezone(int aTimezoneMinutes);

  // In minutes
  virtual int
  getImplicitTimezone() const;

  virtual bool
  setDefaultCollection(const Item& aCollectionUri);

  virtual Item
  getDefaultCollection() const;

  virtual bool
  addExternalFunctionParam(const String& aName, void* aValue);

  virtual bool
  getExternalFunctionParam(const String& aName, void*&) const;

  virtual bool
  addExternalFunctionParameter ( const String& aName, ExternalFunctionParameter* aParam );

  virtual ExternalFunctionParameter*
  getExternalFunctionParameter ( const String& aName ) const;

protected:
  void checkNoIterators() const;

private:
  var_expr* get_var_expr(const zstring& inVarName);

  var_expr* get_var_expr(const zstring& inVarUri, const zstring& inVarLocalName) const;
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
