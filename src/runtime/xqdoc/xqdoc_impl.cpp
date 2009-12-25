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

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/URI.h"

#include "context/static_context.h"
#include "context/standard_uri_resolvers.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

#include "runtime/xqdoc/xqdoc.h"

namespace zorba {

bool
XQDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t lURI;
  xqpString lFileName;
  store::Item_t lItem;
  store::Item_t lURIItem = 0;
  std::auto_ptr<std::istream> lFile;
  std::stringstream lOutput;
  std::istringstream lInput;
  static_context* lSctx;
  short sctxid;
  StandardModuleURIResolver* lModuleResolver = 0;

  // setup a new CompilerCB and a new XQueryCompiler 
  CompilerCB lCompilerCB(*planState.theCompilerCB);
  lCompilerCB.theRootSctx = GENV.getRootStaticContext().create_child_context();
  sctxid = planState.theCompilerCB->theSctxMap->size() + 1;
  (*planState.theCompilerCB->theSctxMap)[sctxid] = lCompilerCB.theRootSctx; 

  // the XQueryCompiler's constructor destroys the existing type manager 
  // in the static context. Hence, we create a new one
  XQueryCompiler lCompiler(&lCompilerCB);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the URI of the module to generate xqdoc for
  if(consumeNext(lItem, theChildren[0].getp(), planState))
  {
    lFileName = xqpString(lItem->getStringValue());
  }

  // resolve the uri in the surrounding static context and use
  // the URI resolver to retrieve the module
  lSctx = theSctx;
  lURI = lSctx->resolve_relative_uri(lItem->getStringValueP(), xqp_string()).getStore();
  if (!GENV_ITEMFACTORY->createAnyURI(lURIItem, lURI))
      ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "URI is not valid " << lURI);

  lModuleResolver = GENV.getModuleURIResolver();
  // we get the ownership of the input stream
  // TODO: we have to find a way to tell user defined resolvers when their input stream
  // can be freed. The current solution might leed to problems on Windows.
  lFile.reset(lModuleResolver->resolve(lURIItem, lSctx));

  // now, do the real work
  if(lFile.get() && lFile->good())
  {
    // retrieve the xqdoc elements as string and parse them
    // TODO: this could be done more efficiently if Items are returned immediately
    lCompiler.xqdoc(*lFile.get(),
                    lFileName.theStrStore->str(),
                    lOutput,
                    planState.dctx()->get_current_date_time());

    lInput.str(lOutput.str());

    result = GENV_STORE.loadDocument(lFileName.theStrStore, lInput, false);

    STACK_PUSH(true, state);
  }
  else
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "No module could be found at " << lURI);
  }
  STACK_END(state);
}

} /* namespace zorba */
