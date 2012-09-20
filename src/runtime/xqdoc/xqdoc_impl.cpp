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

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"
#include "zorbatypes/URI.h"
#include "diagnostics/dict.h"

#include "context/static_context.h"
#include "context/uri_resolver.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compiler_api_consts.h"
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

#include "runtime/xqdoc/xqdoc.h"

namespace zorba {

/**
 * Helper function to transfrom the option item optionally passed to the
 * xqdoc functions into an uint32_t option value.
 */
void readOptions(uint32_t& aOptions, const store::Item& aOptionItem)
{
  aOptions = xqdoc_component_none;

  store::Iterator_t lAttrIter = aOptionItem.getAttributes();
  lAttrIter->open();
  store::Item_t lAttr;

  while (lAttrIter->next(lAttr))
  {
    zstring lLocalName = lAttr->getNodeName()->getLocalName();
    zstring lValue = lAttr->getStringValue();

    if(lValue != "true")
      continue;

    if (lLocalName == "comments")
      aOptions |= xqdoc_component_comments;
    else if (lLocalName == "imports")
      aOptions |= xqdoc_component_imports;
    else if (lLocalName == "variables")
      aOptions |= xqdoc_component_variables;
    else if (lLocalName == "functions")
      aOptions |= xqdoc_component_functions;
    else if (lLocalName == "collections")
      aOptions |= xqdoc_component_collections;
    else if (lLocalName == "indexes")
      aOptions |= xqdoc_component_indexes;
  }
}


/*******************************************************************************

********************************************************************************/
bool
XQDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  zstring lURI;
  zstring lFileName;
  store::Item_t lItem;
  store::Item_t lURIItem = 0;
  store::Item_t lOptionsItem;
  zstring strval;
  std::string uriStr;
  static_context* lSctx;
  std::auto_ptr<internal::Resource> lResource;
  internal::StreamResource* lStream;
  std::istream* lFile;
  zstring lErrorMessage;
  uint32_t lXQDocOptions;

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
  lResource = lSctx->resolve_uri(lURI, internal::EntityData::MODULE, lErrorMessage);
  lStream = static_cast<internal::StreamResource*>(lResource.get());
  if ( ! lStream )
  {
    throw XQUERY_EXCEPTION(
      err::XQST0046,
      ERROR_PARAMS( lURI, ZED( ModuleNotFound ) ),
      ERROR_LOC( loc )
    );
  }
  lFile = lStream->getStream();

  // now, do the real work
  if (lFile && lFile->good())
  {
    if (theChildren.size() > 1)
    {
      // retrieve the options
      consumeNext(lOptionsItem, theChildren[1].getp(), planState);
      readOptions(lXQDocOptions, *lOptionsItem);
    }
    else
    {
      // if no option passed, everything is printed
      lXQDocOptions = 0xFFFFFFFF;
    }

    try 
    {
      // retrieve the xqdoc elements 
      lCompiler.xqdoc(*lFile,
                      lFileName,
                      result,
                      planState.theLocalDynCtx->get_current_date_time(),
                      lXQDocOptions);
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
  store::Item_t lCodeItem, lOptionsItem;
  zstring lFileName;
  bool lIgnoreComments = true;
  uint32_t lXQDocOptions;

  // setup a new CompilerCB and a new XQueryCompiler 
  CompilerCB lCompilerCB(*planState.theCompilerCB);
  lCompilerCB.theRootSctx = GENV.getRootStaticContext().create_child_context();
  (planState.theCompilerCB->theSctxMap)[1] = lCompilerCB.theRootSctx; 

  // the XQueryCompiler's constructor destroys the existing type manager 
  // in the static context. Hence, we create a new one
  XQueryCompiler lCompiler(&lCompilerCB);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // retrieve the module code to generate xqdoc for
  consumeNext(lCodeItem, theChildren[0].getp(), planState);

  if (theChildren.size() > 1)
  {
    // retrieve the options
    consumeNext(lOptionsItem, theChildren[1].getp(), planState);
    readOptions(lXQDocOptions, *lOptionsItem);
  }
  else
  {
    // if no option passed, everything is printed
    lXQDocOptions = 0xFFFFFFFF;
  }

  try 
  {
    std::istringstream is(lCodeItem->getStringValue().c_str());

    // retrieve the xqdoc elements
    lCompiler.xqdoc(is,
                    lFileName,
                    result,
                    planState.theLocalDynCtx->get_current_date_time(),
                    lXQDocOptions);
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
