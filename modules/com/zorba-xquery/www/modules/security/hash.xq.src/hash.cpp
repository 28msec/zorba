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

#include <sstream>
#include <map>

#include <zorba/base64.h>
#include <zorba/error_list.h>
#include <zorba/external_function.h>
#include <zorba/external_module.h>
#include <zorba/item_factory.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/xquery_exception.h>
#include <zorba/zorba.h>
#include "hash.h"

#include "md5_impl.h"
#include "sha1.h"

namespace zorba { namespace security {

zorba::String getOneStringArgument(
    const HashModule* aModule,
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aIndex)
{
  zorba::Item lItem;
  Iterator_t args_iter = aArgs[aIndex]->getIterator();
  args_iter->open();
  if (!(args_iter->next(lItem))) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aIndex << ". parameter.";
    Item lQName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hash",
        "XPTY0004");
    throw USER_EXCEPTION(lQName, lErrorMessage.str() );
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (args_iter->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
      << aIndex << ". parameter.";
    Item lQName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hash",
        "XPTY0004");
    throw USER_EXCEPTION(lQName, lErrorMessage.str() );
  }
  args_iter->close();
  return lTmpString;
}

static zorba::String getNodeText(
    const HashModule* aModule,
    const StatelessExternalFunction::Arguments_t&  aArgs,
    int                 aArgumentIndex)
{
  zorba::Item lItem;
  Iterator_t args_iter = aArgs[aArgumentIndex]->getIterator();
  args_iter->open();
  if (!(args_iter->next(lItem))) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as " << aArgumentIndex << ". parameter.";
    Item lQName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hash",
        "XPTY0004");
    throw USER_EXCEPTION(lQName, lErrorMessage.str() );
  }
  std::stringstream lTmpStream;
  zorba::String lText = lItem.getStringValue();
  if (args_iter->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as " << aArgumentIndex << ". parameter.";
    Item lQName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/security/hash",
        "XPTY0004");
    throw USER_EXCEPTION(lQName, lErrorMessage.str() );
  }
  args_iter->close();
  return lText;
}

HashModule::~HashModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}


void
HashModule::destroy()
{
  if (!dynamic_cast<HashModule*>(this)) {
    return;
  }
  delete this;
}

class HashFunction : public PureStatelessExternalFunction
{
protected:
  const HashModule* theModule;

public:
  HashFunction(const HashModule* aModule): theModule(aModule){}
  ~HashFunction(){}

  virtual String
  getLocalName() const { return "hash-unchecked"; }

  virtual zorba::ItemSequence_t
  evaluate(const Arguments_t& aArgs) const
  {
    std::string lText = (getNodeText(theModule, aArgs, 0)).c_str();
    std::string lAlg = (getOneStringArgument(theModule, aArgs, 1)).c_str();
    zorba::String lHash;
    if (lAlg == "sha1") {
      CSHA1 lSha1;
      const unsigned char* lData = (const unsigned char*) lText.c_str();
      lSha1.Update(lData, lText.size());
      lSha1.Final();
      char lRes[65];
      lSha1.GetHash((UINT_8 *)lRes);

      // SHA1 is always 20bytes long
      // avoid using a stream here because it might contain 0's
      // (i.e. be null terminated)
      std::stringstream lTmp;
      lTmp.write(lRes, 20);

      lHash = zorba::encoding::Base64::encode(lTmp);
    } else {
      lHash = md5(lText);
    }
    // implement here
    zorba::Item lItem;
    lItem = theModule->getItemFactory()->createString(lHash);
    return zorba::ItemSequence_t(new zorba::SingletonItemSequence(lItem));
  }

  virtual String
  getURI() const
  {
    return theModule->getURI();
  }

};

StatelessExternalFunction* HashModule::getExternalFunction(const 
    String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname == "hash-unchecked") {
      lFunc = new HashFunction(this);
    }
  }
  return lFunc;
}

ItemFactory* HashModule::theFactory = 0;


} /* namespace security */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::security::HashModule();
}
