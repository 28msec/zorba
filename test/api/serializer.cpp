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

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/zorba_exception.h>
#include <zorba/singleton_item_sequence.h>


using namespace zorba;


// test for bug #3085093 "ZorbaError not caught in SerializerImpl::serialize"
bool
test_serialization_error(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("<a a='1'/>/@a"); 

  Zorba_SerializerOptions_t lOptions;
  Serializer_t lSerializer = Serializer::createSerializer(lOptions);

  Iterator_t lIterator = lQuery->iterator();

  try {
    lIterator->open();

    Item lItem;
    while ( lIterator->next(lItem) ) {
      // we have to wrap the item in a Serializable object
      SingletonItemSequence lSequence(lItem);
      lSerializer->serialize(&lSequence, std::cout);
    }

    lIterator->close();

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    lIterator->close();
    return true;
  }
	return false;
}


int
serializer(int argc, char* argv[]) 
{
  Zorba* lZorba = Zorba::getInstance(zorba::StoreManager::getStore());

  if (!test_serialization_error(lZorba)) {
    return 1;
  }

  return 0;
}

