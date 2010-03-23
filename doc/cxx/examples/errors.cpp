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

#include <zorba/zorba.h>
#include <zorba/default_error_handler.h>
#include <zorba/store_manager.h>

using namespace zorba;

bool
error_example_1(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    std::cout << lQuery << std::endl;
  } catch ( ZorbaException& e) {
    std::cout << e << std::endl;
    return true;
  }

	return false;
}

bool
error_example_2(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div"); 

  } catch ( StaticException& se ) {
    std::cout << se << std::endl;
    return true;
  } catch ( DynamicException& de ) {
    std::cout << de << std::endl;
  } catch ( ZorbaException& e) {
    std::cout << e << std::endl;
  }

	return false;
}

// for callback functions that are not overriden, an
// exception will be thrown (see example 4)
// for all the ones that we override, we call the callback function (see example 3)
class MyErrorHandler  : public DefaultErrorHandler 
{
public:
  void
  staticError(const StaticException& aStaticError ) 
  { 
    std::cerr << aStaticError << std::endl;
  }

};

bool
error_example_3(Zorba* aZorba)
{
  MyErrorHandler lHandler;

	XQuery_t lQuery = aZorba->compileQuery("for $i in", &lHandler); 

	return true;
}


bool
error_example_4(Zorba* aZorba)
{
  MyErrorHandler lHandler;

  try {
    // move this outside if constant folding is fixed
    XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    lQuery->registerErrorHandler(&lHandler);
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl; 
    return true;
  }

	return false;
}


bool
error_example_5(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'), 'a user error', 1 to 10)"); 

    std::cout << lQuery << std::endl;
  } catch (UserException& e) {
    // get the error object of an error that was raised
    // using the fn:error function
    Iterator_t lIter = e.getErrorObject();
    lIter->open();
    Item lItem;
    while (lIter->next(lItem)) {
      std::cout << lItem.getStringValue() << std::endl;
    }
    return true;
  } catch (ZorbaException& ze) {
    std::cerr << ze << std::endl;
    return false;
  }

	return false;
}


int 
errors(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = error_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = error_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = error_example_3(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  res = error_example_4(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
  res = error_example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
