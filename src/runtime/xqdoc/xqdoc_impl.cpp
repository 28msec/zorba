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
#include "zorbaerrors/dict.h"

#include "context/static_context.h"
#include "context/uri_resolver.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

#include "runtime/xqdoc/xqdoc.h"

namespace zorba {

/*******************************************************************************

********************************************************************************/
bool
XQDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  zstring lURI;
  zstring lFileName;
  store::Item_t lItem;
  store::Item_t lURIItem = 0;
  zstring strval;
  std::string uriStr;
  static_context* lSctx;
  std::auto_ptr<impl::Resource> lResource;
  impl::StreamResource* lStream;
  std::auto_ptr<std::istream> lFile;

  // setup a new CompilerCB and a new XQueryCompiler 
  CompilerCB lCompilerCB(*planState.theCompilerCB);
  lCompilerCB.theRootSctx = GENV.getRootStaticContext().create_child_context();
  (planState.theCompilerCB->theSctxMap)[1] = lCompilerCB.theRootSctx; 

  XQueryCompiler lCompiler(&lCompilerCB);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the URI of the module to generate xqdoc for
  if(consumeNext(lItem, theChildren[0].getp(), planState))
  {
    lFileName = lItem->getStringValue().str();
  }

  // resolve the uri in the surrounding static context and use
  // the URI resolver to retrieve the module
  lSctx = theSctx;
  lItem->getStringValue2(strval);
  lURI = lSctx->resolve_relative_uri(strval);
  lResource = lSctx->resolve_uri(lURI, impl::Resource::MODULE);
  lStream = static_cast<impl::StreamResource*>(lResource.get());
  // We take ownership of the stream
  lFile = lStream->getStream();

  // now, do the real work
  if (lFile.get() && lFile->good())
  {
    try 
    {
      // retrieve the xqdoc elements 
      lCompiler.xqdoc(*lFile.get(),
                      lFileName,
                      result,
                      planState.theLocalDynCtx->get_current_date_time());
    }
    catch (XQueryException& e)
    {
      set_source( e, loc );
      throw;
    }

    STACK_PUSH(true, state);
  }
  else
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046,
      ERROR_PARAMS( lURI, ZED( ModuleNotFound ) ),
      ERROR_LOC( loc )
    );
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool
XQDocContentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  zstring lFileName;

  // setup a new CompilerCB and a new XQueryCompiler 
  CompilerCB lCompilerCB(*planState.theCompilerCB);
  lCompilerCB.theRootSctx = GENV.getRootStaticContext().create_child_context();
  (planState.theCompilerCB->theSctxMap)[1] = lCompilerCB.theRootSctx; 

  // the XQueryCompiler's constructor destroys the existing type manager 
  // in the static context. Hence, we create a new one
  XQueryCompiler lCompiler(&lCompilerCB);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the URI of the module to generate xqdoc for
  consumeNext(lItem, theChildren[0].getp(), planState);

  try 
  {
    std::istringstream is(lItem->getStringValue().c_str());

    // retrieve the xqdoc elements
    lCompiler.xqdoc(is,
                    lFileName,
                    result,
                    planState.theLocalDynCtx->get_current_date_time());
  }
  catch (XQueryException& e) 
  {
    set_source( e, loc );
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
