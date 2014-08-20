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

#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/iterator.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>

using namespace zorba;

/**
 * Example to show the usage of the JSON data manager to
 * parse a JSON object
 */
bool
jsondatamanager_example_1(Zorba* aZorba, JsonDataManager* aDataManager)
{
  try {
    // create a JSON objects and arrays in temporary streams
    std::stringstream lInStreamSingle;
    lInStreamSingle << "{ \"hello\": \"world\" }";

    std::stringstream lInStreamMultiple;
    lInStreamMultiple << "{ \"first\": true }{ \"first\": false }";

    std::stringstream lInStreamArray;
    lInStreamArray << "[{ \"first\": true },{ \"first\": false }]";

    // (1) parse JSON objects and arrays
    ItemSequence_t lSingleObj = aDataManager->parseJSON(lInStreamSingle);
    ItemSequence_t lMultipleObjs = aDataManager->parseJSON(lInStreamMultiple);
    ItemSequence_t lArray = aDataManager->parseJSON(lInStreamArray);

    // (2) use the parsed objects and arrays in an XQuery expression
    XQuery_t lQuery = aZorba->compileQuery(
        "declare variable $single-obj external; "
        "declare variable $multiple-objs external; "
        "declare variable $array external; "
        "{"
          "\"test\": "
            "deep-equal({ \"hello\": \"world\" }, $single-obj) and "
            "deep-equal(({ \"first\": true() },{ \"first\": false() }), $multiple-objs) and "
            "deep-equal([{ \"first\": true() },{ \"first\": false() }], $array)"
        "}");

    DynamicContext* lCtx = lQuery->getDynamicContext();
    lCtx->setVariable("single-obj", lSingleObj->getIterator());
    lCtx->setVariable("multiple-objs", lMultipleObjs->getIterator());
    lCtx->setVariable("array", lArray->getIterator());
    std::stringstream lResult;
    lResult << lQuery;
    return lResult.str() == "{ \"test\" : true }";

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }
}

/*
 * Example to show the usage of the JSON datamanager to
 * parse a JSON object using options
 */
bool
jsondatamanager_example_2(Zorba* aZorba, JsonDataManager* aDataManager)
{
  try {
    // create a JSON objects and arrays in temporary streams
    std::stringstream lInStreamSingle;
    lInStreamSingle << "{ \"hello\": \"world\" }";

    std::stringstream lInStreamArray;
    lInStreamArray << "[{ \"first\": true },{ \"first\": false }]";

    JsonDataManager::ParseOptions lOptions;
    lOptions.setMultipleTopLevelItems(false);

    // (1) parse JSON objects and arrays
    ItemSequence_t lSingleObj = aDataManager->parseJSON(lInStreamSingle, lOptions);
    ItemSequence_t lArray = aDataManager->parseJSON(lInStreamArray, lOptions);

    // (2) use the parsed objects and arrays in an XQuery expression
    XQuery_t lQuery = aZorba->compileQuery(
        "declare variable $single-obj external; "
        "declare variable $array external; "
        "{"
        "\"test\": "
          "deep-equal({ \"hello\": \"world\" }, $single-obj) and "
          "deep-equal([{ \"first\": true() },{ \"first\": false() }], $array)"
        "}");

    DynamicContext* lCtx = lQuery->getDynamicContext();
    lCtx->setVariable("single-obj", lSingleObj->getIterator());
    lCtx->setVariable("array", lArray->getIterator());
    std::stringstream lResult;
    lResult << lQuery;
    if (lResult.str() != "{ \"test\" : true }")
      return false;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

  try {
    // create a JSON objects and arrays in temporary streams
    std::stringstream lInStreamMultiple;
    lInStreamMultiple << "{ \"first\": true }{ \"first\": false }";

    // (1) parse JSON objects and arrays
    JsonDataManager::ParseOptions lOptions;
    lOptions.setMultipleTopLevelItems(false);
    ItemSequence_t lMultipleObjs = aDataManager->parseJSON(lInStreamMultiple, lOptions);

    // (2) use the parsed objects and arrays in an XQuery expression
    XQuery_t lQuery = aZorba->compileQuery(
        "declare variable $multiple-objs external; "
        "{"
        "\"test\": "
          "deep-equal(({ \"first\": true() },{ \"first\": false() }), $multiple-objs)"
        "}");

    DynamicContext* lCtx = lQuery->getDynamicContext();
    lCtx->setVariable("multiple-objs", lMultipleObjs->getIterator());
    std::stringstream lResult;
    lResult << lQuery;
    return false;

  } catch (ZorbaException& e) {
    if (e.diagnostic().qname().localname() != std::string("JNDY0021"))
      return false;
  }

  return true;
}

/*
 * Example to show the usage of the JSON datamanager to
 * parse a JSON object using options
 */
bool
jsondatamanager_example_3(Zorba* aZorba, JsonDataManager* aDataManager)
{
  try {
    // create a JSON objects and arrays in temporary streams
    std::stringstream lInStreamSingle;
    lInStreamSingle << "{ \"hello\": \"world\" }";

    std::stringstream lInStreamMultiple;
    lInStreamMultiple << "{ \"first\": true }{ \"first\": false }";

    std::stringstream lInStreamArray;
    lInStreamArray << "[{ \"first\": true },{ \"first\": false }]";

    JsonDataManager::ParseOptions lOptions;
    lOptions.setStripTopLevelArray(true);

    // (1) parse JSON objects and arrays
    ItemSequence_t lSingleObj = aDataManager->parseJSON(lInStreamSingle, lOptions);
    ItemSequence_t lMultipleObjs = aDataManager->parseJSON(lInStreamMultiple, lOptions);
    ItemSequence_t lArray = aDataManager->parseJSON(lInStreamArray, lOptions);

    // (2) use the parsed objects and arrays in an XQuery expression
    XQuery_t lQuery = aZorba->compileQuery(
        "declare variable $single-obj external; "
        "declare variable $multiple-objs external; "
        "declare variable $array external; "
        "{"
        "\"test\": "
          "deep-equal({ \"hello\": \"world\" }, $single-obj) and "
          "deep-equal(({ \"first\": true() },{ \"first\": false() }), $multiple-objs) and "
          "deep-equal(({ \"first\": true() },{ \"first\": false() }), $array)"
        "}");

    DynamicContext* lCtx = lQuery->getDynamicContext();
    lCtx->setVariable("single-obj", lSingleObj->getIterator());
    lCtx->setVariable("multiple-objs", lMultipleObjs->getIterator());
    lCtx->setVariable("array", lArray->getIterator());
    std::stringstream lResult;
    lResult << lQuery;
    return lResult.str() == "{ \"test\" : true }";
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

int 
jsondatamanager(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  JsonDataManager_t lDataManager = lZorba->getJsonDataManager();
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = jsondatamanager_example_1(lZorba, lDataManager);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = jsondatamanager_example_2(lZorba, lDataManager);
  if (!res) return 2;
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = jsondatamanager_example_3(lZorba, lDataManager);
  if (!res) return 3;
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
