#include "common/libicu.h"

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp> 
#include <vector>
#include <iostream>
#include <memory>

#include "zorbatypes/collation_manager.h"

namespace zorba {


  XQPCollator::XQPCollator(Collator* aCollator)
    : theCollator(aCollator) {}

  XQPCollator::~XQPCollator()
  {
    delete theCollator;
  }

  XQPCollator*
  CollationFactory::createCollator(const std::string& aCollationURI)
  {
    size_t lStartURI = aCollationURI.find("http://www.flworfound.org/collations/"); 
    if ( lStartURI == std::string::npos )
      return 0;

    // e.g. PRIMARY/en/US
    std::string lCollationIdentifier = aCollationURI.substr(37, aCollationURI.size() - 37);

    // the vector will contain the strength, language, and optional country code
    std::vector<std::string> lSplitVec;; 
    boost::split( lSplitVec, lCollationIdentifier, boost::algorithm::is_any_of("/") ); 

    if ( lSplitVec.size() < 2 )
      return 0;

    Collator* lCollator;
    UErrorCode lError = U_ZERO_ERROR;
    if ( lSplitVec.size() == 2 ) {
      lCollator = Collator::createInstance(Locale(lSplitVec[1].c_str()), lError);
    } else {
      lCollator = Collator::createInstance(Locale(lSplitVec[1].c_str(), lSplitVec[2].c_str()), lError);
    }

    if( U_FAILURE(lError) ) {
      return 0;
    }

    if (lSplitVec[0].compare("PRIMARY") == 0) {
      lCollator->setStrength(Collator::PRIMARY);
    } else if (lSplitVec[0].compare("SECONDARY") == 0) {
      lCollator->setStrength(Collator::SECONDARY);
    } else if (lSplitVec[0].compare("TERTIARY") == 0) {
      lCollator->setStrength(Collator::TERTIARY);
    } else if (lSplitVec[0].compare("QUATERNARY") == 0) {
      lCollator->setStrength(Collator::QUATERNARY);
    } else if (lSplitVec[0].compare("IDENTICAL") == 0) {
      lCollator->setStrength(Collator::IDENTICAL);
    } else {
      return 0;
    }

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
    lCollator->setStrength(Collator::PRIMARY);

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
