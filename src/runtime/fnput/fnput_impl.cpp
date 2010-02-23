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

#include "common/shared_types.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "runtime/fnput/fnput.h"

#include "store/api/pul.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"
#include "zorbatypes/URI.h"


namespace zorba 
{

/*******************************************************************************
  fn:put
********************************************************************************/
bool FnPutIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t node;
  store::Item_t uriItem;
  xqpStringStore_t uriString;
  xqpStringStore_t resolvedUriString;
  URI lTargetUri;
  store::Item_t resolvedUriItem;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(node, theChildren[0].getp(), planState);

  if (node->getNodeKind() != store::StoreConsts::elementNode &&
      node->getNodeKind() != store::StoreConsts::documentNode)
  {
    ZORBA_ERROR_LOC(FOUP0001, loc);
  }

  consumeNext(uriItem, theChildren[1].getp(), planState);

  uriString = uriItem->getStringValue();

  resolvedUriString = theSctx->resolve_relative_uri(uriString, false);

  GENV_ITEMFACTORY->createAnyURI(resolvedUriItem, resolvedUriString);

  try 
  {
    lTargetUri = URI(resolvedUriString.getp());
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_LOC_DESC(FOUP0002, loc, e.theDescription);
  }

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addPut(node, resolvedUriItem);

  result = pul.release();

  STACK_PUSH(true, state);

  STACK_END(state);
}



}
