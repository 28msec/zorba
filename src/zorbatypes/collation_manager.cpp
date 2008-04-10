#include "common/libicu.h"

//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp> 
#include <vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include "zorbatypes/collation_manager.h"

namespace zorba {

#if !defined WIN32 && !defined WCE
#define strtok_s    strtok_r
#endif

  XQPCollator::XQPCollator(Collator* aCollator)
    : theCollator(aCollator) {}

  XQPCollator::~XQPCollator()
  {
    delete theCollator;
  }

  XQPCollator*
  CollationFactory::createCollator(const std::string& aCollationURI)
  {
    if (aCollationURI == "http://www.w3.org/2005/xpath-functions/collation/codepoint")
    {
      Collator* lCollator;
      UErrorCode lError = U_ZERO_ERROR;
      lCollator = Collator::createInstance(Locale("root"), lError);
      assert(lError == U_ZERO_ERROR);
      lCollator->setStrength(Collator::TERTIARY);
      lCollator->setAttribute(UCOL_CASE_FIRST, UCOL_UPPER_FIRST, lError);
      assert( lError == U_ZERO_ERROR );
      return new XQPCollator(lCollator);
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
    tok2 = strtok_s(collstrdup, "/", &strtok_context);
    if ( !tok2)
    {
      ::free(collstrdup);
      return 0;
    }
    tok3 = strtok_s(collstrdup, "/", &strtok_context);

    Collator* lCollator;
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

    if (!strcmp(tok1, "PRIMARY")) {
      lCollator->setStrength(Collator::PRIMARY);
    } else if (!strcmp(tok1, "SECONDARY")) {
      lCollator->setStrength(Collator::SECONDARY);
    } else if (!strcmp(tok1, "TERTIARY")) {
      lCollator->setStrength(Collator::TERTIARY);
    } else if (!strcmp(tok1, "QUATERNARY")) {
      lCollator->setStrength(Collator::QUATERNARY);
    } else if (!strcmp(tok1, "IDENTICAL")) {
      lCollator->setStrength(Collator::IDENTICAL);
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
    UErrorCode lError = U_ZERO_ERROR;
    Collator* lCollator = Collator::createInstance(Locale("en", "US"), lError); 
    if( U_FAILURE(lError) ) {
      assert(false);
    }
    lCollator->setStrength(Collator::IDENTICAL);

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
