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

#include "zorbautils/fatal.h"
#include "store/naive/nsbindings.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"
#include "zorbamisc/ns_consts.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
NsBindingsContext::NsBindingsContext(NsBindingsContext* parent)
  :
  theParent(parent)
{

#if 0
  std::cout << "Create binding context1 " << this << "; with parent = "
            << parent << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
NsBindingsContext::NsBindingsContext(ulong numBindings)
{
  theBindings.resize(numBindings);
#if 0
  std::cout << "Create binding context1 " << this << "; num bindings = "
            << numBindings << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
NsBindingsContext::NsBindingsContext(const store::NsBindings& bindings)
  :
  theBindings(bindings)
{
#if 0
  std::cout << "Create binding context2 " << this << "; num bindings = "
            << bindings.size() << std::endl;
#endif

  //check all bindings
  store::NsBindings::const_iterator   ns_iter;
  for(ns_iter = theBindings.begin(); ns_iter != theBindings.end(); ns_iter++)
  {
    check_ns_binding(ns_iter->first, ns_iter->second);
  }
}


/*******************************************************************************

********************************************************************************/
NsBindingsContext::~NsBindingsContext()
{
#if 0
  std::cout << "Removing binding context " << this << "; num bindings = "
            << theBindings.size() << std::endl;
#endif
}

/*******************************************************************************

********************************************************************************/
/**
 * A macro for calling equals() with a second argument of a string literal.
 */
#define ZSTREQ(STRING,LITERAL) \
        ::zorba::ztd::equals( STRING, LITERAL, sizeof( LITERAL ) - 1 )
void NsBindingsContext::check_ns_binding(const zstring& prefix, const zstring& uri)
{
  if (ZSTREQ(prefix, "xmlns"))
    throw XQUERY_EXCEPTION(
      err::XQST0070,
      ERROR_PARAMS( prefix, ZED( NoRebindPrefix ) )
    );

  if ((ZSTREQ(prefix, "xml") && !ZSTREQ(uri, XML_NS)))
  {
    throw XQUERY_EXCEPTION(
      err::XQST0070,
      ERROR_PARAMS( prefix, ZED( NoRebindPrefix ) )
    );
  }

  if ((ZSTREQ(uri, XML_NS) && !ZSTREQ(prefix, "xml")) ||
       ZSTREQ(uri, XMLNS_NS))
  {
    throw XQUERY_EXCEPTION(
      err::XQST0070, ERROR_PARAMS( uri, ZED( NoBindURI ) )
    );
  }

}

/*******************************************************************************

********************************************************************************/
bool NsBindingsContext::findBinding(const zstring& prefix, zstring& uri) const
{
  const NsBindingsContext* currentContext = this;

  while (currentContext != NULL)
  {
    const store::NsBindings& bindings = currentContext->theBindings;
    ulong numBindings = (ulong)bindings.size();

    for (ulong i = 0; i < numBindings; ++i)
    {
      if (bindings[i].first == prefix)
      {
        uri = bindings[i].second;
        return true;
      }
    }

    currentContext = currentContext->getParent();
  }

  return false;
}


/*******************************************************************************
  Add a binding between the given prefix and ns uri in the local binings, if
  such a binding does not exist already.

  If the given prefix is bound already to a different uri, then the method is
  a noop if soft is true, else it triggers a fatal assertion. 
********************************************************************************/
void NsBindingsContext::addBinding(
    const zstring& prefix,
    const zstring& ns,
    bool soft)
{
  ulong numBindings = (ulong)theBindings.size();

  for (ulong i = 0; i < numBindings; ++i)
  {
    if (theBindings[i].first == prefix)
    {
      if (!soft && theBindings[i].second != ns)
      {
        ZORBA_FATAL(theBindings[i].second == ns, "");
      }
      return;
    }
  }

  check_ns_binding(prefix, ns);
  theBindings.push_back(std::pair<zstring, zstring>(prefix, ns));
}


/*******************************************************************************
  If a binding for the given prefix exists already among the local bindings of
  "this", replace the associated ns uri with the given uri. Else, add a binding
  for the given prefix and ns uri to the local bindings.
********************************************************************************/
void NsBindingsContext::updateBinding(const zstring& prefix, const zstring& ns)
{
  ulong numBindings = (ulong)theBindings.size();

  for (ulong i = 0; i < numBindings; ++i)
  {
    if (theBindings[i].first == prefix)
    {
      theBindings[i].second = ns;
      return;
    }
  }

  check_ns_binding(prefix, ns);
  theBindings.push_back(std::pair<zstring, zstring>(prefix, ns));
}


/*******************************************************************************

********************************************************************************/
void NsBindingsContext::removeBinding(const zstring& prefix, const zstring& ns)
{
  ulong numBindings = (ulong)theBindings.size();

  for (ulong i = 0; i < numBindings; i++)
  {
    if (theBindings[i].first == prefix)
    {
      ZORBA_FATAL(theBindings[i].second == ns, "");

      theBindings.erase(theBindings.begin() + i);
      return;
    }
  }
}

} // namespace store
} // namespace zorba

/* vim:set et sw=2 ts=2: */
