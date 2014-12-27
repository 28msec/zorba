/*
 * Copyright 2014 The FLWOR Foundation.
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

#include "util-tests.h"

#include <cassert>
#include <cstdlib>
#include <stdlib.h>

#include <zorba/function.h>
#include <zorba/zorba.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/util/uuid.h>


namespace zorba {

namespace tests {

String
TestFunction::getURI() const
{
  return theModule->getURI();
}

zorba::Item
TestFunction::getOneItemArgument(const Arguments_t& aArgs, int aIndex)
{
  Item lItem;
  Iterator_t args_iter = aArgs[aIndex]->getIterator();
  args_iter->open();
  args_iter->next(lItem);
  args_iter->close();

  return lItem;
}

zorba::Item
UtilTestsModule::getOneItemArgument(const Arguments_t& aArgs, int aIndex)
{
  Item lItem;
  Iterator_t args_iter = aArgs[aIndex]->getIterator();
  args_iter->open();
  args_iter->next(lItem);
  args_iter->close();

  return lItem;
}

/******************************************************************************
 *****************************************************************************/
zorba::ItemSequence_t
NonSeeakableStreamableStringFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext*,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();

  std::unique_ptr<std::stringstream> lResultStream(new std::stringstream());
  (*lResultStream.get()) << "streamable";

  return zorba::ItemSequence_t(
      new zorba::SingletonItemSequence(
          lFactory->createStreamableString(*lResultStream.release(), NonSeeakableStreamableStringFunction::streamReleaser, false)
      )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test01(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();

  zorba::Item lItem = getOneItemArgument(aArgs, 0);
  int64_t lParam = lItem.getLongValue();


  if (lParam < 10)
  {
    //x*x
    return zorba::ItemSequence_t(
        new zorba::SingletonItemSequence(
            lFactory->createInteger(lParam * lParam)
        )
    );
  }
  else if (lParam < 20)
  {
    //()
    return zorba::ItemSequence_t(
        new zorba::EmptySequence);
  }
  else
  {
    //$x, " == ", $x * $x
    std::vector<zorba::Item> lItems;
    lItems.push_back(lFactory->createInteger(lParam));
    lItems.push_back(lFactory->createString(" == "));
    lItems.push_back(lFactory->createInteger(lParam * lParam));

    return zorba::ItemSequence_t(
        new zorba::VectorItemSequence(lItems));
  }
}

zorba::ItemSequence_t
UtilTestsModule::test02(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();
  std::ostringstream os;
  Zorba_SerializerOptions_t lOptions;
  lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  Serializer_t lSerializer = Serializer::createSerializer(lOptions);

  std::stringstream lSerializedArg;
  lSerializer->serialize(aArgs[0]->getIterator(), lSerializedArg);
  std::vector<zorba::Item> lResult;
  zorba::Item lSerializedItem = lFactory->createString(lSerializedArg.str());
  lResult.push_back(lSerializedItem);

  uuid u;
  uuid::create(&u);
  std::ostringstream oss;
  oss << "urn:uuid:" << u;
  zorba::Item lRandomItem = lFactory->createString(oss.str());
  lResult.push_back(lRandomItem);

  return zorba::ItemSequence_t(
    new zorba::VectorItemSequence(
      lResult
    )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test03(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();

  // {"a":1}
  std::vector<std::pair<zorba::Item, zorba::Item> > lObjectPairs;
  zorba::Item lFieldName = lFactory->createString("a");
  zorba::Item lFieldValue = lFactory->createInteger(1);
  lObjectPairs.push_back(std::pair<zorba::Item, zorba::Item>(lFieldName, lFieldValue));
  zorba::Item lObject = lFactory->createJSONObject(lObjectPairs);

  //[1]
  std::vector<zorba::Item> lStackArray;
  zorba::Item lArrayValue = lFactory->createInteger("1");
  lStackArray.push_back(lArrayValue);
  zorba::Item lArray = lFactory->createJSONArray(lStackArray);

  //<a/>
  std::vector<std::pair<zorba::String, zorba::String> > lNSBindings;
  zorba::Item lNullItem;
  zorba::Item lTypeName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  zorba::Item lQName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "a");
  zorba::Item lElement = lFactory->createElementNode(lNullItem, lQName, lTypeName, false, false, lNSBindings);

  //1
  zorba::Item lInteger = lFactory->createInteger(1);

  std::vector<zorba::Item> lResult;
  lResult.push_back(lObject);
  lResult.push_back(lArray);
  lResult.push_back(lElement);
  lResult.push_back(lInteger);

  return zorba::ItemSequence_t(
    new zorba::VectorItemSequence(
      lResult
    )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test04(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();
  std::ostringstream os;
  Zorba_SerializerOptions_t lOptions;
  lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  Serializer_t lSerializer = Serializer::createSerializer(lOptions);

  std::vector<zorba::Item> lResult;

  std::unique_ptr<std::stringstream> lResultStream(new std::stringstream());
  (*lResultStream.get()) << "streamable";
  zorba::Item lString = lFactory->createStreamableString(
      *lResultStream.release(),
      NonSeeakableStreamableStringFunction::streamReleaser,
      false);
  lResult.push_back(lString);

  //{"key" : debug:non-seeakable-streamable-string()},
  std::vector<std::pair<zorba::Item, zorba::Item> > lObjectPairs;
  zorba::Item lFieldName = lFactory->createString("key");
  std::unique_ptr<std::stringstream> lResultStream2(new std::stringstream());
  (*lResultStream2.get()) << "streamable";
  zorba::Item lFieldValue = lFactory->createStreamableString(
      *lResultStream2.release(),
      NonSeeakableStreamableStringFunction::streamReleaser,
      false);
  lObjectPairs.push_back(std::pair<zorba::Item, zorba::Item>(lFieldName, lFieldValue));
  zorba::Item lObject = lFactory->createJSONObject(lObjectPairs);

  lResult.push_back(lObject);

  //[debug:non-seeakable-streamable-string()],
  std::vector<zorba::Item> lStackArray;
  std::unique_ptr<std::stringstream> lResultStream3(new std::stringstream());
      (*lResultStream3.get()) << "streamable";
  zorba::Item lArrayValue = lFactory->createStreamableString(
      *lResultStream3.release(),
      NonSeeakableStreamableStringFunction::streamReleaser,
      false);
  lStackArray.push_back(lArrayValue);
  zorba::Item lArray = lFactory->createJSONArray(lStackArray);

  lResult.push_back(lArray);

  //<a/>
  std::vector<std::pair<zorba::String, zorba::String> > lNSBindings;
  zorba::Item lNullItem;
  zorba::Item lTypeName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  zorba::Item lQName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "a");
  zorba::Item lElement = lFactory->createElementNode(lNullItem, lQName, lTypeName, false, false, lNSBindings);

  zorba::Item lAQName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "b");
  zorba::Item lATypeName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  std::unique_ptr<std::stringstream> lResultStream4(new std::stringstream());
        (*lResultStream4.get()) << "streamable";
  zorba::Item lAttrValue = lFactory->createStreamableString(
        *lResultStream4.release(),
        NonSeeakableStreamableStringFunction::streamReleaser,
        false);
  lFactory->createAttributeNode(lElement, lQName, lATypeName, lAttrValue);

  lResult.push_back(lElement);


  std::stringstream lFirstArg;
  lSerializer->serialize(aArgs[0]->getIterator(), lFirstArg);
  zorba::Item lFirstSerializedItem = lFactory->createString(lFirstArg.str());
  lResult.push_back(lFirstSerializedItem);

  std::stringstream lSecondArg;
  lSerializer->serialize(aArgs[1]->getIterator(), lSecondArg);
  zorba::Item lSecondSerializedItem = lFactory->createString(lSecondArg.str());
  lResult.push_back(lSecondSerializedItem);

  return zorba::ItemSequence_t(
    new zorba::VectorItemSequence(
      lResult
    )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test05(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::Item lBool = getOneItemArgument(aArgs, 0);
  zorba::Item lRet;
  if (lBool.getBooleanValue())
    lRet = getOneItemArgument(aArgs, 1);
  else
    lRet = lBool;

  return zorba::ItemSequence_t(
    new zorba::SingletonItemSequence(
      lRet
    )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test06(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();
  zorba::Item lX = getOneItemArgument(aArgs, 0);
  zorba::Item lY = getOneItemArgument(aArgs, 1);
  zorba::Item lRet = lFactory->createInteger(atoi(lX.getStringValue().str().c_str()) + atoi(lY.getStringValue().str().c_str()));

  return zorba::ItemSequence_t(
    new zorba::SingletonItemSequence(
      lRet
    )
  );
}

zorba::ItemSequence_t
UtilTestsModule::test07(const Arguments_t& aArgs,
    const zorba::StaticContext* aSctx,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();
  std::ostringstream os;
  Zorba_SerializerOptions_t lOptions;
  lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  Serializer_t lSerializer = Serializer::createSerializer(lOptions);

  std::vector<zorba::Item> lResult;
  std::vector<std::pair<Item, Item> > lPairs;
  lPairs.push_back(std::pair<Item, Item>(lFactory->createString("x"), getOneItemArgument(aArgs, 0)));
  lPairs.push_back(std::pair<Item, Item>(lFactory->createString("y"), getOneItemArgument(aArgs, 1)));
  Item lObj = lFactory->createJSONObject(lPairs);
  std::stringstream lSerializedObj;
  zorba::SingletonItemSequence lSeq(lObj);
  lSerializer->serialize(lSeq.getIterator(), lSerializedObj);
  lResult.push_back(lFactory->createString(lSerializedObj.str()));


  uuid u;
  uuid::create(&u);
  std::ostringstream oss;
  oss << "urn:uuid:" << u;
  zorba::Item lRandomItem = lFactory->createString(oss.str());
  lResult.push_back(lRandomItem);

  return zorba::ItemSequence_t(
    new zorba::VectorItemSequence(
      lResult
    )
  );
}

zorba::ItemSequence_t
UUIDFunction::evaluate(
    const Arguments_t& aArgs,
    const zorba::StaticContext*,
    const zorba::DynamicContext* aDctx) const
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(0)->getItemFactory();
  uuid u;
  uuid::create(&u);
  std::ostringstream oss;
  oss << "urn:uuid:" << u;
  zorba::Item lRandomItem = lFactory->createString(oss.str());

  return zorba::ItemSequence_t(
    new zorba::SingletonItemSequence(
      lRandomItem
    )
  );
}


/******************************************************************************
 *****************************************************************************/
zorba::ExternalFunction*
UtilTestsModule::getExternalFunction(const zorba::String& aLocalname)
{
  FuncMap_t::const_iterator lFind = theFunctions.find(aLocalname);
  zorba::ExternalFunction*& lFunc = theFunctions[aLocalname];
  if (lFind == theFunctions.end()) {
    if       (aLocalname.compare("test-01-cache") == 0)
      lFunc = new Test01CacheFunction(this);
    else if (aLocalname.compare("test-01-sd") == 0)
      lFunc = new Test01SDFunction(this);
    else if (aLocalname.compare("test-02-cache") == 0)
      lFunc = new Test02CacheFunction(this);
    else if (aLocalname.compare("test-02-sd") == 0)
      lFunc = new Test02SDFunction(this);
    else if (aLocalname.compare("test-03-cache") == 0)
       lFunc = new Test03CacheFunction(this);
    else if (aLocalname.compare("test-03-sd") == 0)
       lFunc = new Test03SDFunction(this);
    else if (aLocalname.compare("test-04-cache") == 0)
       lFunc = new Test04CacheFunction(this);
    else if (aLocalname.compare("test-04-sd") == 0)
       lFunc = new Test04SDFunction(this);
    else if (aLocalname.compare("test-05-cache") == 0)
       lFunc = new Test05CacheFunction(this);
    else if (aLocalname.compare("test-05-sd") == 0)
       lFunc = new Test05SDFunction(this);
    else if (aLocalname.compare("test-06-cache") == 0)
       lFunc = new Test06CacheFunction(this);
    else if (aLocalname.compare("test-06-sd") == 0)
       lFunc = new Test06SDFunction(this);
    else if (aLocalname.compare("test-07-cache") == 0)
       lFunc = new Test07CacheFunction(this);
    else if (aLocalname.compare("test-07-sd") == 0)
       lFunc = new Test07SDFunction(this);
    else if (aLocalname.compare("non-seeakable-streamable-string") == 0)
      lFunc = new NonSeeakableStreamableStringFunction(this);
    else if (aLocalname.compare("uuid") == 0)
      lFunc = new UUIDFunction(this);
  }
  return lFunc;
}

} /* namespace debugmodule */ } /* namespace zorba */


/******************************************************************************
 *****************************************************************************/
#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif
extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::tests::UtilTestsModule();
}
