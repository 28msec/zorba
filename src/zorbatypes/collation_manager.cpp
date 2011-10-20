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

#include "common/common.h"

#ifndef ZORBA_NO_UNICODE
# include <unicode/coll.h>
#endif /* ZORBA_NO_UNICODE */

#include <vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include <cstring>
#include <cstdlib>
#include "zorbatypes/collation_manager.h"
#include "zorbamisc/ns_consts.h"

namespace zorba {

  /**
   * Method splits the passed string into tokes. 
   * Delimiters are all characters passed in the variable delims.
   */
std::vector<std::string> std_string_tokenize(
    const std::string& str,
    const std::string& delims)
{
  // Skip delims at beginning, find start of first token
  std::string::size_type lastPos = str.find_first_not_of(delims, 0);
  // Find next delimiter @ end of token
  std::string::size_type pos     = str.find_first_of(delims, lastPos);

  // output vector
  std::vector<std::string> tokens;

  while (std::string::npos != pos || std::string::npos != lastPos)
  {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delims.  Note the "not_of". this is beginning of token
    lastPos = str.find_first_not_of(delims, pos);
    // Find next delimiter at end of token.
    pos     = str.find_first_of(delims, lastPos);
  }
  
  return tokens;
}
                                          


XQPCollator::XQPCollator(void* aCollator, const std::string& aCollationURI, bool doMemCmp)
  :
  theCollator((Collator*)aCollator),
  uri(aCollationURI),
  theDoMemCmp(doMemCmp)
{
}


XQPCollator::~XQPCollator()
{
  delete (Collator*)theCollator;
}

const std::string& XQPCollator::getURI()
{
  return uri;
}


XQPCollator*
CollationFactory::createCollator(const std::string& aCollationURI)
{
  static const char* coll_uri_start = ZORBA_COLLATION_NS_BASE;
  static int coll_uri_start_len = strlen (coll_uri_start);

  if (aCollationURI == W3C_CODEPT_COLLATION_NS)
  {
    //according to the rules of Unicode Codepoint Collation
    //http://www.w3.org/TR/xpath-functions-30/#codepoint-collation
    //and considering the fact that Zorba uses UTF-8 encoding, this means that
    //a comparison of the byte sequences is all it is needed, i.e. create a collator 
    // with 'theDoMemCmp' set to true
    return new XQPCollator(NULL, aCollationURI, true);
  }

  size_t lStartURI = aCollationURI.find(coll_uri_start);
  if ( lStartURI == std::string::npos )
    return 0;

  // e.g. PRIMARY/en/US
  std::string lCollationIdentifier = 
    aCollationURI.substr(coll_uri_start_len,
                         aCollationURI.size() - coll_uri_start_len);

  std::vector<std::string> lTokens = std_string_tokenize(lCollationIdentifier, "/");
  if(lTokens.size() < 2)
  {
    return 0;
  }
  
  Collator* lCollator;

#ifndef ZORBA_NO_UNICODE
  UErrorCode lError = U_ZERO_ERROR;
  if (lTokens.size() == 2) 
  {
    lCollator = Collator::createInstance(Locale(lTokens[1].c_str()), lError);
  }
  else 
  {
    lCollator = Collator::createInstance(Locale(lTokens[1].c_str(),
                                                lTokens[2].c_str()),
                                         lError);
  }

  if( U_FAILURE(lError) ) 
  {
    return 0;
  }

#else
  lCollator = new Collator;
#endif

  if (lTokens[0].compare("PRIMARY") == 0) 
  {
#ifndef ZORBA_NO_UNICODE
    lCollator->setStrength(Collator::PRIMARY);
#endif
  }
  else if (lTokens[0].compare("SECONDARY") == 0) 
  {
#ifndef ZORBA_NO_UNICODE
    lCollator->setStrength(Collator::SECONDARY);
#endif
  }
  else if (lTokens[0].compare("TERTIARY") == 0) 
  {
#ifndef ZORBA_NO_UNICODE
    lCollator->setStrength(Collator::TERTIARY);
#endif
  }
  else if (lTokens[0].compare("QUATERNARY") == 0) 
  {
#ifndef ZORBA_NO_UNICODE
    lCollator->setStrength(Collator::QUATERNARY);
#endif
  }
  else if (lTokens[0].compare("IDENTICAL") == 0) 
  {
#ifndef ZORBA_NO_UNICODE
    lCollator->setStrength(Collator::IDENTICAL);
#endif
  }
  else
  {
    return 0;
  }
  
  return new XQPCollator(lCollator, aCollationURI);
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
  return new XQPCollator(lCollator, (std::string)"");
}


CollationFactory::CollationFactory()
  :
  theRootCollator(0)
{
  theRootCollator = createCollator();
}


CollationFactory::~CollationFactory()
{
  delete theRootCollator;
}

} /* namespace xqp */
/* vim:set et sw=2 ts=2: */
