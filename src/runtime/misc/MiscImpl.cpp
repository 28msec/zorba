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
#include "runtime/misc/MiscImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/util/iterator_impl.h"

#include "zorbaerrors/error_manager.h"
#include "errors/user_error.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/URI.h"

namespace zorba {

// 3 The Error Function
//---------------------
bool FnErrorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  static const char *err_ns = "http://www.w3.org/2005/xqt-errors";
  store::Item_t err_qname;
  GENV_ITEMFACTORY->createQName (err_qname, err_ns, "err", "FOER0000");
  store::Item_t lTmpQName;
  store::Item_t lTmpErrorObject;
  store::Item_t lTmpDescr;
  xqp_string ns;
  xqp_string description;
  std::vector<store::Item_t> lErrorObject; 

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size () >= 1) {
    if (consumeNext(lTmpQName, theChildren[0].getp(), planState))
      err_qname = lTmpQName;
  }
  if (theChildren.size () >= 2) {
    consumeNext(lTmpDescr, theChildren[1].getp(), planState);
    description = lTmpDescr->getStringValue ().getp();
  }
  if (theChildren.size() == 3) {
    while (consumeNext(lTmpErrorObject, theChildren[2].getp(), planState)) {
      lErrorObject.push_back(lTmpErrorObject);
    }
  }
  
  {
    error::ZorbaUserError lError(err_qname, description, loc, 
                                 __FILE__, __LINE__, lErrorObject);
    throw lError;
  }

  STACK_END (state);
}


// 8.1 fn:resolve-uri
//---------------------
bool FnResolveUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t strRelative;
  xqpStringStore_t strBase;
  xqpStringStore_t strResult;
  URI::error_t err;
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  //TODO:check if both relative and base uri's are valid. If not raise err:FORG0002.
  if (consumeNext(item, theChildren[0], planState ))
  {
    strRelative = item->getStringValue();

    consumeNext(item, theChildren[1], planState );
    strBase = item->getStringValue();

    err = URI::resolve_relative (strBase, strRelative, strResult);

    switch (err) 
    {
    case URI::INVALID_URI:
      ZORBA_ERROR (FORG0002);
      break;
    case URI::RESOLUTION_ERROR:
      ZORBA_ERROR (FORG0009);
      break;
    case URI::MAX_ERROR_CODE:
      break;
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strResult), state);
  }

  //TODO fix the implementation
  
  STACK_END (state);
}

bool SequentialIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for (unsigned i = 0; i < theChildren.size () - 1; i++) {
    while (CONSUME (result, i));
  }

  while (CONSUME (result, theChildren.size () - 1))
    STACK_PUSH (true, state);

  STACK_END (state);
}

} /* namespace zorba */
