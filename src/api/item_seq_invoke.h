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
#ifndef ZORBA_API_ITEM_SEQUENCE_INVOKE
#define ZORBA_API_ITEM_SEQUENCE_INVOKE

#include <zorba/config.h>
#include <zorba/item_sequence.h>

namespace zorba { 

class XQueryImpl;

/*******************************************************************************
  An ItemSequence representing the result of a function invocation via the c++
  API (see StaticContextImpl::invoke() method).

  theXQuery:
  ----------
  The XQuery obj that is created internally to execute the function invocation
  This Xquery obj is owned by "this".
  
  theIterator:
  ------------
  The ResultIteratorImpl obj for iterating over the result of theXQuery.

  theSctx:
  --------
  A smart ptr to the StaticContextImpl that created this InvokeItemSequence.
  Used to make sure the ctx lives longer then this sequence.
********************************************************************************/
class InvokeItemSequence : public ItemSequence
{
 public:
  InvokeItemSequence(const XQuery_t& query,  StaticContext* sctx);

  virtual ~InvokeItemSequence();

  virtual Iterator_t getIterator();

 protected:
  XQuery_t         theXQuery;

  StaticContext_t  theSctx;
};

} // namespace zorba
#endif


/* vim:set et sw=2 ts=2: */
