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

#include "hash.h"

#include <sstream>

#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/base64.h>

#include "sha1.h"

namespace zorba { namespace security {

  ItemFactory* HashModule::theFactory = 0;

  zorba::String getOneStringArgument(const StatelessExternalFunction::Arguments_t& aArgs, int aIndex)
  {
    zorba::Item lItem;
    if (!(aArgs[aIndex]->next(lItem))) {
      std::stringstream lErrorMessage;
      lErrorMessage << "An empty-sequence is not allowed as "
                    << aIndex << ". parameter.";
      throw zorba::ExternalFunctionData::createZorbaException(XPTY0004,
          lErrorMessage.str().c_str(),
          __FILE__,
          __LINE__);
    }
    zorba::String lTmpString = lItem.getStringValue();
    if (aArgs[aIndex]->next(lItem)) {
      std::stringstream lErrorMessage;
      lErrorMessage << "A sequence of more then one item is not allowed as "
        << aIndex << ". parameter.";
      throw zorba::ExternalFunctionData::createZorbaException(XPTY0004,
          lErrorMessage.str().c_str(),
          __FILE__,
          __LINE__);
    }
    return lTmpString;
  }


HashModule::~HashModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}
  
StatelessExternalFunction*
HashModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname.equals("sha1")) {
      lFunc = new HashSHA1Function(this);
    }
  }
  return lFunc;
}

void
HashModule::destroy()
{
  if (!dynamic_cast<HashModule*>(this)) {
    return;
  }
  delete this;
}

std::string
SHA1(const std::string& aString)
{
  char lResult[64 + 1];
  memset(lResult, 0, 64 + 1);
  zorba::securitymodule::CSHA1 sha1;
  sha1.Reset();
  sha1.Update((unsigned char*)aString.c_str(), aString.length());
  sha1.Final();
  sha1.GetHash((UINT_8 *)lResult);
  zorba::String lDigest(lResult);
  zorba::String lSignature = zorba::encoding::Base64::encode(lDigest);
  return lSignature.c_str();  
}

String
HashSHA1Function::getURI() const
{
  return theModule->getURI();
}

zorba::ItemSequence_t
HashSHA1Function::evaluate(const Arguments_t& aArgs) const
{
  zorba::Item lItem;
  std::string lString = (getOneStringArgument(aArgs, 0)).c_str();
  std::string lSHA1 = SHA1(lString);
  lItem = theModule->getItemFactory()->createString(lSHA1);  
  return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lItem));
}

void
HashSHA1Function::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
}
} /* namespace security */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::security::HashModule();
}
