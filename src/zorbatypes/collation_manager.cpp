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
#include "common/common.h"

#ifndef ZORBA_NO_UNICODE
#include "zorbatypes/libicu.h"
#endif

//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp> 
#include <vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include <cstring>
#include <cstdlib>
#include "zorbatypes/collation_manager.h"

namespace zorba {

#if !defined WIN32 && !defined WCE
#define strtok_s    strtok_r
#endif

  XQPCollator::XQPCollator(void* aCollator)
  : theCollator((Collator*)aCollator) {}

  XQPCollator::~XQPCollator()
  {
    delete (Collator*)theCollator;
  }

  XQPCollator*
  CollationFactory::createCollator(const std::string& aCollationURI)
  {
    if (aCollationURI == "http://www.w3.org/2005/xpath-functions/collation/codepoint")
    {
#ifndef ZORBA_NO_UNICODE
      Collator* lCollator;
      UErrorCode lError = U_ZERO_ERROR;
      lCollator = Collator::createInstance(Locale("root"), lError);
      assert(lError == U_ZERO_ERROR);
      lCollator->setStrength(Collator::TERTIARY);
      lCollator->setAttribute(UCOL_CASE_FIRST, UCOL_UPPER_FIRST, lError);
      assert( lError == U_ZERO_ERROR );
      return new XQPCollator(lCollator);
#else
      Collator  *coll = new Collator;
      return new XQPCollator(coll);
#endif
    }

    size_t lStartURI = aCollationURI.find("http://www.flworfound.org/collations/"); 
    if ( lStartURI == std::string::npos )
      return 0;

    // e.g. PRIMARY/en/US
    std::string lCollationIdentifier = aCollationURI.substr(37, aCollationURI.size() - 37);

    // the vector will contain the strength, language, and optional country code
//    std::vector<std::string> lSplitVec;; 
//    boost::split( lSplitVec, lCollationIdentifier, boost::algorithm::is_any_of("/") ); 
    char *strtok_context = NULL;
    char  *collstrdup = ::strdup(lCollationIdentifier.c_str());
    char  *tok1, *tok2, *tok3;
    tok1 = strtok_s(collstrdup, "/", &strtok_context);
    if(!tok1)
    {
      ::free(collstrdup);
      return 0;
    }
    tok2 = strtok_s(NULL, "/", &strtok_context);
    if ( !tok2)
    {
      ::free(collstrdup);
      return 0;
    }
    tok3 = strtok_s(NULL, "/", &strtok_context);

    Collator* lCollator;
#ifndef ZORBA_NO_UNICODE
    UErrorCode lError = U_ZERO_ERROR;
    if ( tok3 == NULL ) {
      lCollator = Collator::createInstance(Locale(tok2), lError);
    } else {
      lCollator = Collator::createInstance(Locale(tok2, tok3), lError);
    }

    if( U_FAILURE(lError) ) {
      ::free(collstrdup);
      return 0;
    }
#else
    lCollator = new Collator;
#endif

    if (!strcmp(tok1, "PRIMARY")) {
#ifndef ZORBA_NO_UNICODE
      lCollator->setStrength(Collator::PRIMARY);
#endif
    } else if (!strcmp(tok1, "SECONDARY")) {
#ifndef ZORBA_NO_UNICODE
      lCollator->setStrength(Collator::SECONDARY);
#endif
    } else if (!strcmp(tok1, "TERTIARY")) {
#ifndef ZORBA_NO_UNICODE
      lCollator->setStrength(Collator::TERTIARY);
#endif
    } else if (!strcmp(tok1, "QUATERNARY")) {
#ifndef ZORBA_NO_UNICODE
      lCollator->setStrength(Collator::QUATERNARY);
#endif
    } else if (!strcmp(tok1, "IDENTICAL")) {
#ifndef ZORBA_NO_UNICODE
      lCollator->setStrength(Collator::IDENTICAL);
#endif
    } else {
      ::free(collstrdup);
      return 0;
    }

    ::free(collstrdup);
    return new XQPCollator(lCollator);
  }

  XQPCollator*
  CollationFactory::createCollator()
  {
    Collator* lCollator;
#ifndef ZORBA_NO_UNICODE
    UErrorCode lError = U_ZERO_ERROR;
    lCollator = Collator::createInstance(Locale("en", "US"), lError); 
    if( U_FAILURE(lError) ) {
      assert(false);
    }
    lCollator->setStrength(Collator::IDENTICAL);
#else
    lCollator = new Collator;
#endif
    return new XQPCollator(lCollator);
  }

  CollationFactory::CollationFactory()
    : theRootCollator(0)
  {
    theRootCollator = createCollator();
  }

  CollationFactory::~CollationFactory()
  {
    if ( theRootCollator )
      delete theRootCollator;
  }

} /* namespace xqp */
