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
#include <store/naive/simple_store.h>

using namespace zorba;

/**
 * Example to show a quick way to serialize results of query execution using
 * the << operator on ostreams
 */
bool
serialization_example_1(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to invoke the serializer using the serialize() call on the query object.
 */
bool
serialization_example_2(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    lQuery->serialize(std::cout);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example that shows HTML serialization of the results.
 */
bool
serialization_example_3(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.ser_method = XQuery::SerializerOptions::serialization_method::HTML;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to serialize the result of a query with indentation.
 */
bool
serialization_example_4(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.indent = XQuery::SerializerOptions::indent::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_5(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = XQuery::SerializerOptions::omit_xml_declaration::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_6(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

    XQuery::SerializerOptions lSerOptions;
    lSerOptions.byte_order_mark = XQuery::SerializerOptions::byte_order_mark::YES;

    lQuery->serialize(std::cout, lSerOptions);
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

bool
serialization_example_7(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("for $i in (1 to 3) return <a> { $i } </a>"); 

  ResultIterator_t lIterator = lQuery->iterator();

  try {
    lIterator->open();

    Item lItem;
    while ( lIterator->next(lItem) ) {
      lItem.serialize(std::cout);
    }

    lIterator->close();

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    lIterator->close();
    return false;
  }
	return true;
}

int 
serialization(int argc, char* argv[])
{
  store::SimpleStore* lStore = store::SimpleStore::getInstance();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing serialization example 1" << std::endl;
  res = serialization_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 2" << std::endl;
  res = serialization_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 3" << std::endl;
  res = serialization_example_3(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 4" << std::endl;
  res = serialization_example_4(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 5" << std::endl;
  res = serialization_example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 6" << std::endl;
  res = serialization_example_6(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing serialization example 7" << std::endl;
  res = serialization_example_7(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  lStore->shutdown();
  return 0;
}
