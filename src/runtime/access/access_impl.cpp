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

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"


#include "system/globalenv.h"

#include "context/namespace_context.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "runtime/access/access.h"

#include "runtime/visitors/planiter_visitor.h"

#include <util/fs_util.h>
#include <util/uri_util.h>
#include <zorbatypes/URI.h>
#include <string>

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/shared_types.h"
#include "store/api/pul.h"
#include "store/api/index.h"
#include "store/api/annotation.h"
#include "store/api/ic.h"
#include "store/api/load_properties.h"
#include "api/dynamiccontextimpl.h"
#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"

#include <zorba/transcode_stream.h>

namespace zorba {

  static zstring normalizeInput(zstring const& aUri, static_context* aSctx,
                              QueryLoc const& loc)
  {
    zstring const aBaseUri = aSctx->get_base_uri();
    zstring lResolvedURI;

    try
    {
      // To support the very common (if technically incorrect) use
      // case of users passing local filesystem paths to fn:doc(),
      // we use the following heuristic: IF the base URI has a file:
      // scheme AND the incoming URI has no scheme, we will assume
      // the incoming URI is actually a filesystem path.  QQQ For
      // the moment, we assume any "unknown" schemes are probably
      // Windows drive letters.
      if ((uri::get_scheme(aUri) == uri::none ||
           uri::get_scheme(aUri) == uri::unknown) &&
          uri::get_scheme(aBaseUri) == uri::file)
      {
        // Ok, we assume it's a filesystem path. First normalize it.
        zstring lNormalizedPath =
          fs::get_normalized_path(aUri, zstring(""));
        // QQQ For now, get_normalized_path() doesn't do what we
        // want when base URI represents a file. So, when the
        // normalized path is relative, we pretend it's a relative
        // URI and resolve it as such.
        if (fs::is_absolute(lNormalizedPath))
        {
          URI::encode_file_URI(lNormalizedPath, lResolvedURI);
        }
        else
        {
  #ifdef WIN32
          ascii::replace_all(lNormalizedPath, '\\', '/');
  #endif
          lResolvedURI = aSctx->resolve_relative_uri(lNormalizedPath, true);
        }
      }
      else
      {
        // We do NOT assume it's a filesystem path; just resolve it.
        lResolvedURI = aSctx->resolve_relative_uri(aUri, true);
      }
    }
    catch (ZorbaException& e)
    {
      if (e.diagnostic() == err::XQST0046)
        // the value of a URILiteral is of nonzero length and is not in the
        // lexical space of xs:anyURI.
        e.set_diagnostic(err::FODC0005);
      else
        e.set_diagnostic(err::FODC0002);

      set_source(e, loc);
      throw;
    }

    return lResolvedURI;
  }
  
/*******************************************************************************
  14.8.5 fn:unparsed-text
********************************************************************************/
  static void streamReleaser(std::istream* aStream)
  {
    delete aStream;
  }
  /**
   * Utility method for fn:unparsed-text() and fn:unparsed-text-available(). 
   */

  static void readDocument(
    zstring const& aUri,
    zstring const& aEncoding,
    static_context* aSctx,
    PlanState& aPlanState,
    QueryLoc const& loc,
    store::Item_t& oResult)
  {
    //Normilize input to handle filesystem paths, etc.
    zstring const lNormUri(normalizeInput(aUri, aSctx, loc));

    store::LoadProperties lLoadProperties;

    //Resolve URI to stream
    zstring lErrorMessage;
    std::auto_ptr<internal::Resource> lResource = aSctx->resolve_uri
      (lNormUri, internal::EntityData::SOME_CONTENT, lErrorMessage);

    internal::StreamResource* lStreamResource =
      dynamic_cast<internal::StreamResource*>(lResource.get());
    
    if(lStreamResource == NULL)
    {
      throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(aUri, lErrorMessage), ERROR_LOC(loc));
    }

    std::istream *c = lStreamResource->getStream();
    std::unique_ptr<std::istream> lInStream;

    //check if encoding is needed
    if( transcode::is_necessary(aEncoding.c_str()) )
    {
      try
      {
        lInStream.reset( new transcode::stream<std::istream>(aEncoding.c_str(), c->rdbuf()) );
      }
      catch (std::invalid_argument const& e)
      {
        throw XQUERY_EXCEPTION(err::FOUT1190, ERROR_PARAMS(aUri, lErrorMessage), ERROR_LOC(loc));
      }
    }
    else
    {
      lInStream.reset( new std::istream(c->rdbuf()) );
    }

    //creates stream item
    GENV_ITEMFACTORY->createStreamableString(
      oResult,
      *lInStream.release(),
      &streamReleaser
      );
    lStreamResource->setStreamReleaser(nullptr);
    
    if(oResult.isNull())
    {
      throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(aUri), ERROR_LOC(loc));
    }
  }

  bool FnUnparsedTextIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t unparsedText;
    store::Item_t uriItem;
    store::Item_t encodingItem;
    zstring uriString;
    zstring encodingString("UTF-8");

    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

    if(!consumeNext(uriItem, theChildren[0].getp(), planState))
    {
      STACK_PUSH(false, state);
    }

    if (theChildren.size() == 2)
    {
      consumeNext(encodingItem, theChildren[1].getp(), planState);
      encodingItem->getStringValue2(encodingString);
    }

    uriItem->getStringValue2(uriString);
    readDocument(uriString, encodingString, theSctx, planState, loc, result);
    STACK_PUSH(true, state);

    STACK_END(state);
  }


/*******************************************************************************
  14.8.7 fn:unparsed-text-available
********************************************************************************/
   
  bool FnUnparsedTextAvailableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t unparsedText;
    store::Item_t uriItem;
    store::Item_t encodingItem;
    zstring uriString;
    zstring encodingString("UTF-8");

    PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    if(!consumeNext(uriItem, theChildren[0].getp(), planState))
    {
      STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, false), state);
    }

    if (theChildren.size() == 2)
    {
      consumeNext(encodingItem, theChildren[1].getp(), planState);
      encodingItem->getStringValue2(encodingString);
    }

    uriItem->getStringValue2(uriString);

    try
    {
      readDocument(uriString, encodingString, theSctx, planState, loc, unparsedText);
    }
    catch(XQueryException const& e)
    {
      unparsedText = NULL;
    }

    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, !(unparsedText.isNull()) ), state);
    
    STACK_END(state);
  }

}//namespace zorba
