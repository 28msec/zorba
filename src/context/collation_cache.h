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
#ifndef ZORBA_COLLATION_CACHE_H
#define ZORBA_COLLATION_CACHE_H

#include <map>
#include "common/shared_types.h"

namespace zorba {
  class CollationCache
  {
    public:
      typedef std::map<std::string, XQPCollator*> CacheMap_t;

    private:
      static_context* theStaticContext;
      CacheMap_t theMap;
      XQPCollator* theDefaultCollator;

      friend class static_context;
    private:
      CollationCache(static_context* aStaticContext);
    public:
      virtual ~CollationCache();

      XQPCollator* getCollator(xqpStringStore* aName); 
      XQPCollator* getDefaultCollator();
  };
}

#endif
