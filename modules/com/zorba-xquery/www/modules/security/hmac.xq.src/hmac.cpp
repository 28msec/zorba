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

#include "hmac.h"

#include <sstream>

#include <zorba/base64.h>
#include <zorba/error_list.h>
#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/user_exception.h>

#include "hmac_sha1.h"

namespace zorba { namespace security {

  ItemFactory* HMACModule::theFactory = 0;

  zorba::String getOneStringArgument(const StatelessExternalFunction::Arguments_t& aArgs, int aIndex)
  {
    zorba::Item lItem;
    Iterator_t args_iter = aArgs[aIndex]->getIterator();
    args_iter->open();
    if (!(args_iter->next(lItem))) {
      std::stringstream lErrorMessage;
      lErrorMessage << "An empty-sequence is not allowed as "
                    << aIndex << ". parameter.";
      Item lQName = Zorba::getInstance(0)->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hmac",
          "XPTY0004");
      throw USER_EXCEPTION(lQName, lErrorMessage.str() );
    }
    zorba::String lTmpString = lItem.getStringValue();
    if (args_iter->next(lItem)) {
      std::stringstream lErrorMessage;
      lErrorMessage << "A sequence of more then one item is not allowed as "
        << aIndex << ". parameter.";
      Item lQName = Zorba::getInstance(0)->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hmac",
          "XPTY0004");
      throw USER_EXCEPTION(lQName, lErrorMessage.str() );
    }
    args_iter->close();
    return lTmpString;
  }


HMACModule::~HMACModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}
  
StatelessExternalFunction*
HMACModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname == "sha1") {
      lFunc = new HMACSHA1Function(this);
    }
  }
  return lFunc;
}

void
HMACModule::destroy()
{
  if (!dynamic_cast<HMACModule*>(this)) {
    return;
  }
  delete this;
}

std::string
hmacSHA1(const std::string& aData, const std::string& aKey)
{ 
  unsigned char digest[20] ; 

  char *message = new char[aData.length() + 1] ; 
  memset(message, aData.length() + 1, 0);
  strcpy(message, aData.c_str());
  
  char *key = new char[aKey.length() + 1];
  memset(key, aKey.length() + 1, 0);
  strcpy(key, aKey.c_str());
    
  zorba::securitymodule::CHMAC_SHA1 HMAC_SHA1 ;
  HMAC_SHA1.HMAC_SHA1((unsigned char*) message, strlen(message), (unsigned char*)key, strlen(key), digest) ;
  
  zorba::String lDigest(std::string((char const*) digest, 20));
  zorba::String lSignature = zorba::encoding::Base64::encode(lDigest);
  return lSignature.c_str(); // uri-encoding is done automatically within zorba rest call
}

String
HMACSHA1Function::getURI() const
{
  return theModule->getURI();
}

zorba::ItemSequence_t
HMACSHA1Function::evaluate(const Arguments_t& aArgs) const
{
    zorba::Item lItem;

    std::string lBaseString = (getOneStringArgument(aArgs, 0)).c_str();
    std::string lKey = (getOneStringArgument(aArgs, 1)).c_str();
    lItem = theModule->getItemFactory()->createString(hmacSHA1(lBaseString, lKey));
    return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lItem));
}
} /* namespace security */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::security::HMACModule();
}
