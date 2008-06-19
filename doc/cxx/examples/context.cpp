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
#include <fstream>
#include <sstream>

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>


using namespace zorba;

/**
 * Example to show the binding of external variables in the query context.
 */
bool
context_example_1(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var + $var");

  ItemFactory* lFactory = aZorba->getItemFactory();

  /* The item that is to be bound to the external variable */
  Item lItem = lFactory->createInteger(4);

  DynamicContext* lCtx = lQuery->getDynamicContext();

  /* Actually perform the binding. */
  lCtx->setVariable("var", lItem);

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example showing an erroneous query that defines an external variable, but
 * whose dynamic context does not bind any values to it.
 * One needs to use the setVariable() call defined on the dynamic context
 * in order to use external variables correctly.
 */
bool
context_example_2(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var + $var");

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

/**
 * Example to show the usage of the context item in a query. It is treated just as
 * an external variable, except one uses the setContextItem() on the dynamic context
 * to bind the value. It is an error to use a context item in a query but not bind it
 * before execution.
 */
bool
context_example_3(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(".");

  ItemFactory* lFactory = aZorba->getItemFactory();

  Item lItem = lFactory->createInteger(4);

  DynamicContext* lCtx = lQuery->getDynamicContext();

  lCtx->setContextItem(lItem);

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to show the use of document content as the value of an external variable.
 */
bool
context_example_4(Zorba* aZorba)
{

  std::auto_ptr<std::istream> lDocStream( 
    new std::stringstream("<books><book>Book 1</book><book>Book 2</book></books>"));

  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var//book");

  DynamicContext* lCtx = lQuery->getDynamicContext();

  /* Parses the input stream and internally creates a datamodel instance
   * that can be bound to the variable
   * Note that ownership of the stream is transfered to the system using an auto_ptr.
   */
  lCtx->setVariableAsDocument("var", "books.xml", lDocStream);

  try {
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

/**
 * Example to show the use of document content as the value of the context item in
 * a query.
 */
bool
context_example_5(Zorba* aZorba)
{

  std::auto_ptr<std::istream> lDocStream(
    new std::stringstream("<books><book>Book 1</book><book>Book 2</book></books>"));

  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; .//book");

  DynamicContext* lCtx = lQuery->getDynamicContext();

  lCtx->setContextItemAsDocument("books.xml", lDocStream);

  try {
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

/**
 * Example to show the use of collations in string comparison.
 */
bool
context_example_6(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  /* Add the German collation to the context */
  lStaticContext->addCollation("http://www.zorba-xquery.com/collations/PRIMARY/de/DE");

  lStaticContext->setBaseURI("http://www.zorba-xquery.com/");

  if ( lStaticContext->getBaseURI() != "http://www.zorba-xquery.com/")
    return false;

  /* Use the German collation as the third argument to the fn:compare() XQuery function */
  XQuery_t lQuery = aZorba->compileQuery("fn:compare('Strasse', 'Straße', 'http://www.zorba-xquery.com/collations/PRIMARY/de/DE')", 
          lStaticContext); 

  try {

    std::cout << lQuery << std::endl;

  } catch (DynamicException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}

/**
 * Example to show the erroneous use of incorrect collation URIs in Zorba.
 */
bool
context_example_7(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  try {
    lStaticContext->addCollation("http://www.zorba-xquery.com/collations/PRIMARY");

    XQuery_t lQuery = aZorba->compileQuery("fn:compare('Strasse', 'Straße', 'http://www.zorba-xquery.com/collations/PRIMARY')", 
        lStaticContext); 

    std::cout << lQuery << std::endl;

  } catch (StaticException &e) {
    std::cerr << e << std::endl;
    return true;
  }

	return false;
}

/**
 * Example to show the connection between the ordering mode as defined in the query
 * prolog and that in the context of the query.
 */
bool
context_example_8(Zorba* aZorba)
{
  /* The query sets the ordering mode to ordered */
  XQuery_t lQuery1 = aZorba->compileQuery("declare ordering ordered; 1"); 

  const StaticContext* lStaticContext1 = lQuery1->getStaticContext();
  
  /* Programmatically the effect can be observed in the context */
  if (lStaticContext1->getOrderingMode() != ordered)
    return false;

  XQuery_t lQuery2 = aZorba->compileQuery("declare ordering unordered; 1"); 

  const StaticContext* lStaticContext2 = lQuery2->getStaticContext();
  
  return (lStaticContext2->getOrderingMode() == unordered);
}

/**
 * Example to show the ability to define the current dateTime in the dynami context.
 */
bool
context_example_9(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("fn:hours-from-dateTime(fn:current-dateTime())"); 

  DynamicContext* lDynContext = lQuery->getDynamicContext();

  try {
    Item lDateTimeItem = aZorba->getItemFactory()->createDateTime(2008, 03, 30, 16, 05, 42, 0); 

    lDynContext->setCurrentDateTime(lDateTimeItem);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return true;
}


int 
context(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();

  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

    std::cout << "executing example 1" << std::endl;
    res = context_example_1(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 2" << std::endl;
    res = context_example_2(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 3" << std::endl;
    res = context_example_3(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 4" << std::endl;
    res = context_example_4(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 5" << std::endl;
    res = context_example_5(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 6" << std::endl;
    res = context_example_6(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example 7" << std::endl;
    res = context_example_7(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example_8" << std::endl;
    res = context_example_8(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

    std::cout << "executing example_9" << std::endl;
    res = context_example_9(lZorba);
    if (!res) return 1; 
    std::cout << std::endl;

  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}
