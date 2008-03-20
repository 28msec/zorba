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

      XQPCollator* getCollator(const std::string& aName); 
      XQPCollator* getDefaultCollator();
  };
}

#endif
