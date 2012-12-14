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

#include <zorba/iterator.h>
#include "api/invoke_item_sequence.h"
#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"

namespace zorba { 

InvokeItemSequence::InvokeItemSequence(
    XQueryImpl* aQuery,
    Iterator_t aIter,
    StaticContext* aSctx)
  : theIterator(aIter),
    theXQuery(aQuery),
    theSctx(aSctx)
{
}

InvokeItemSequence::~InvokeItemSequence()
{
  delete theXQuery;
}

Iterator_t InvokeItemSequence::getIterator()
{
  return theIterator;
}

} // namespace zorba

/* vim:set et sw=2 ts=2: */
