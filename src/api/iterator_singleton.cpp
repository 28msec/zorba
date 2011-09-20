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

#include "api/iterator_singleton.h"

#include <zorba/item.h>

#include "api/zorbaimpl.h"

#include "system/globalenv.h"

#include "diagnostics/xquery_diagnostics.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

namespace zorba {

#define SINGLETON_ITERATOR_CATCH                               \
catch (ZorbaException const& e)                                \
{                                                              \
  ZorbaImpl::notifyError(theDiagnosticHandler, e);             \
}                                                              \
catch (std::exception const& e)                                \
{                                                              \
  ZorbaImpl::notifyError(theDiagnosticHandler, e.what());      \
}                                                              \
catch (...)                                                    \
{                                                              \
  ZorbaImpl::notifyError(theDiagnosticHandler);                \
} 


/*******************************************************************************

********************************************************************************/
API_SingletonIterator::API_SingletonIterator(
    const store::Item_t& aItem,
    DiagnosticHandler* aDiagnosticHandler)
  :
  theItem(aItem),
  theDiagnosticHandler(aDiagnosticHandler),
  theOwnDiagnosticHandler(false),
  theIsOpen(false),
  theIsDone(false)
{
  if (theDiagnosticHandler == NULL)
  {
    theDiagnosticHandler = new DiagnosticHandler();
    theOwnDiagnosticHandler = true;
  }
}


/*******************************************************************************

********************************************************************************/
API_SingletonIterator::~API_SingletonIterator()
{
  if (theOwnDiagnosticHandler)
    delete theDiagnosticHandler;
}


/*******************************************************************************

********************************************************************************/
void API_SingletonIterator::open()
{
  try
  {
    if (theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0041_ITERATOR_ALREADY_OPEN);

    theIsOpen = true;
    theIsDone = false;
  }
  SINGLETON_ITERATOR_CATCH
}


/*******************************************************************************

********************************************************************************/
bool API_SingletonIterator::next(Item& aItem)
{
  try
  {
    if (!theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

    if (theIsDone) 
      return false;
      
    aItem = theItem;
    theIsDone = true;

    return true;
  }
  SINGLETON_ITERATOR_CATCH
  return false;
}

 
/*******************************************************************************

********************************************************************************/
void API_SingletonIterator::close()
{
  try
  {
    if (!theIsOpen)  
      throw ZORBA_EXCEPTION( zerr::ZAPI0040_ITERATOR_NOT_OPEN );

    theIsOpen = false;
  }
  SINGLETON_ITERATOR_CATCH
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
