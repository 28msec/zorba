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
#include <zorbatypes/collation_manager.h>
#include "zorbatypes/representations.h"
#include "context/collation_cache.h"
#include "context/static_context.h"

#include "errors/error_manager.h"

namespace zorba {

  CollationCache::CollationCache(static_context* aStaticContext)
  : theStaticContext(aStaticContext),
    theDefaultCollator(0)
  {}

  CollationCache::~CollationCache() 
  {
    {
      std::map<std::string, XQPCollator*>::iterator lIter = theMap.begin();
      std::map<std::string, XQPCollator*>::iterator lEnd = theMap.end();
      for ( ; lIter != lEnd ; ++lIter)
      {
        delete lIter->second;
      }
    }
    theMap.clear();
    if (theDefaultCollator != 0)
    {
      delete theDefaultCollator;
      theDefaultCollator = 0;
    }
  }

  XQPCollator*
  CollationCache::getCollator(xqpStringStore* aURI)
  {
    // temporary soluion because the static context does not yet deal with string stores
    xqpString lTmpURI(aURI); 
    if (!theStaticContext->has_collation_uri(lTmpURI))
    {
      ZORBA_ERROR_DESC_OSS(FOCH0002, "Collation " << *aURI << " not found in static context.");
    } else {
      CacheMap_t::iterator lFind = theMap.find(lTmpURI);
      if ( lFind != theMap.end() )
      {
        return lFind->second;
      }
      else
      {
        XQPCollator* lCollator = CollationFactory::createCollator(lTmpURI);
        if ( ! lCollator )
          ZORBA_ERROR_DESC_OSS(FOCH0002, "Collation " << *aURI << " not supported.");
        theMap[lTmpURI] = lCollator;
        return lCollator;
      } 
    }
  }

  XQPCollator*
  CollationCache::getDefaultCollator()
  {
    if (theDefaultCollator == 0)
    {
      const xqp_string& lDefaultURI = theStaticContext->default_collation_uri();
      theDefaultCollator = CollationFactory::createCollator(lDefaultURI);
    }
    return theDefaultCollator; 
  }
}
