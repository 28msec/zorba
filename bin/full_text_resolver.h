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
#ifndef ZORBA_FULL_TEXT_RESOLVER_H
#define ZORBA_FULL_TEXT_RESOLVER_H

#include <zorba/zorba.h>
#include <zorba/uri_resolvers.h>

namespace zorba {

#ifndef ZORBA_NO_FULL_TEXT
  class ZorbaCMDFullTextURIResolverResult: public FullTextURIResolverResult
  {
    public:
      virtual String getResolvedFullText() const { return theFullText; }
  
    protected:
      friend class ZorbaCMDFullTextURIResolver;
      String theFullText;
  };

  class ZorbaCMDFullTextURIResolver: public FullTextURIResolver
  {
    public:
      virtual ~ZorbaCMDFullTextURIResolver(){}
  
      virtual std::auto_ptr<FullTextURIResolverResult>
      resolve(
        const Item& aURI,
        StaticContext* aStaticContext)
      {
        std::auto_ptr<ZorbaCMDFullTextURIResolverResult> lResult(new ZorbaCMDFullTextURIResolverResult());
        MappingIter_t lIter = theMappings.find(aURI.getStringValue().c_str());
        if (lIter != theMappings.end()) {
          lResult->theFullText = lIter->second;
          lResult->setError(URIResolverResult::UR_NOERROR);
        } else {
          lResult->setError(URIResolverResult::UR_XQST0057);
        }
        return std::auto_ptr<FullTextURIResolverResult>(lResult.release());
      };
  
    public:
      void
      add_mapping(const std::string& aURI, const std::string& aValue)
      {
        theMappings[aURI] = aValue;
      }
  
    protected:
      typedef std::map<std::string, std::string> Mapping_t;
      typedef Mapping_t::const_iterator          MappingIter_t;
      Mapping_t theMappings;
  };
#endif

} /* namespace zorba */

#endif

