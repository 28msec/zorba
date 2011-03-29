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
#include <zorba/store_manager.h>
#include <zorba/uri_resolvers.h>
#include <zorba/declared_collection.h>
#include <zorba/declared_index.h>
#include <zorba/xquery_exception.h>


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

  } catch (ZorbaException &e) {
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

  } catch (ZorbaException &e) {
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

  } catch (ZorbaException &e) {
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
  std::ostringstream outStream1;
  std::ostringstream outStream2;

  std::auto_ptr<std::istream> lDocStream1(
    new std::stringstream("<books><book>Book 1</book><book>Book 2</book></books>"));

  std::auto_ptr<std::istream> lDocStream2(
    new std::stringstream("<books><book>Book 1.1</book><book>Book 2.2</book></books>"));

  zorba::XmlDataManager::LoadProperties ldProps;

  try
  {
    XQuery_t lQuery = aZorba->compileQuery("declare variable $doc external; $doc//book[1]/text()");

    DynamicContext* lCtx = lQuery->getDynamicContext();

    // Parses the input stream and internally creates a datamodel instance
    // that can be bound to the variable. Note that ownership of the stream
    // is transfered to the system using an auto_ptr.
    lCtx->setVariableAsDocument("doc", "books.xml", lDocStream1, ldProps);

    outStream1 << lQuery << std::endl;
    std::cout << outStream1.str() << std::endl;

    // Reset the value of the $doc variable to the 2nd document.
    lCtx->setVariableAsDocument("doc", "books.xml", lDocStream2, ldProps, true);

    outStream2 << lQuery << std::endl;
    std::cout << outStream2.str() << std::endl;

    if (outStream2.str() != "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\nBook 1.1\n")
    {
      std::cerr << "Test 4 failed with a wrong result : " << std::endl
                << outStream2.str() << std::endl;
      return false;
    }
  }
  catch (ZorbaException& e)
  {
    std::cerr << "Test 4 failed with exception : " << e << std::endl;
    return false;
  }
  catch (...)
  {
    std::cerr << "Test 4 failed with unknown exception" << std::endl;
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

  lCtx->setContextItemAsDocument("other_books.xml", lDocStream);

  try {
    std::cout << lQuery << std::endl;
  } catch (ZorbaException& e) {
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
  lStaticContext->addCollation("http://www.zorba-xquery.com/zorba/collations/PRIMARY/de/DE");

  lStaticContext->setBaseURI("http://www.zorba-xquery.com/");

  if ( lStaticContext->getBaseURI() != "http://www.zorba-xquery.com/")
    return false;

  /* Use the German collation as the third argument to the fn:compare() XQuery function */
  XQuery_t lQuery = aZorba->compileQuery("fn:compare('Strasse', 'Straße', 'http://www.zorba-xquery.com/zorba/collations/PRIMARY/de/DE')",
          lStaticContext);

  try {

    std::cout << lQuery << std::endl;

  } catch (ZorbaException &e) {
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

  } catch (XQueryException &e) {
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
 * Example to show the ability to define the current dateTime in the dynamic context.
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

/**
 * Example to show the findFunctions function of the static context
 */
bool
context_example_10(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();

  try {
    Item lQName = aZorba->getItemFactory()->createQName("http://www.w3.org/2005/xpath-functions", "doc");

    std::vector<Function_t> lFunctions;
    lContext->findFunctions(lQName, lFunctions);

    std::cout << "Number of Functions " << lFunctions.size() << std::endl;

    for (std::vector<Function_t>::const_iterator lIter = lFunctions.begin();
         lIter != lFunctions.end(); ++lIter)
    {
      std::cout << "Function Name " << (*lIter)->getFunctionName().getStringValue() << std::endl;
      std::cout << "  requires dynamic context " << (*lIter)->requiresDynamicContext() << std::endl;
      std::cout << "  is updating " << (*lIter)->isUpdating() << std::endl;
      std::cout << "  arity " << (*lIter)->getArity() << std::endl;

      lContext->disableFunction(*lIter);
    }

    try
    {
      XQuery_t lQuery = aZorba->compileQuery("fn:doc('test.xml')", lContext);
    }
    catch (ZorbaException const &se)
    {
      std::cerr << se << std::endl;
      return true;
    }
  }
  catch (ZorbaException &e)
  {
    std::cerr << e << std::endl;
    return false;
  }

	return false;
}


class PrologModuleURIResolverResult : public ModuleURIResolverResult
{
  friend class PrologModuleURIResolver;

protected:
  std::istream             * theModule;
  std::vector<std::string>   theComponentURIs;

public:
  std::istream* getModuleStream() const
  {
    return theModule;
  }

  void getModuleURL(std::string& url) const
  {
  }

  void getComponentURIs(std::vector<std::string>& uris) const
  {
    uris = theComponentURIs;
  }
};


class PrologModuleURIResolver : public ModuleURIResolver
{
public:
  virtual ~PrologModuleURIResolver() {}

  std::auto_ptr<ModuleURIResolverResult> resolveTargetNamespace(
        const String& aTargetNamespaceURI,
        const StaticContext& aStaticContext)
  {
    std::auto_ptr<PrologModuleURIResolverResult>
    lResult(new PrologModuleURIResolverResult());

    std::string compURI = aTargetNamespaceURI.c_str();
    lResult->theComponentURIs.push_back(compURI);

    return std::auto_ptr<ModuleURIResolverResult>(lResult.release());
  }

  std::auto_ptr<ModuleURIResolverResult> resolve(
        const String& aURI,
        const StaticContext& aStaticContext)
  {
    std::auto_ptr<PrologModuleURIResolverResult>
    lResult(new PrologModuleURIResolverResult());

    if (aURI == "http://www.zorba-xquery.com/mymodule")
    {
      std::auto_ptr<std::stringstream> lQuery(new std::stringstream());

      (*lQuery) << "module namespace mymodule = 'http://www.zorba-xquery.com/mymodule';" << std::endl
                << "import module namespace xqddf = 'http://www.zorba-xquery.com/modules/xqddf';" << std::endl
                << "declare variable $mymodule:var  := 'myvar';" << std::endl
                << "declare collection mymodule:collection;" << std::endl
                << "declare automatically maintained value equality index mymodule:index" << std::endl
                << "  on nodes xqddf:collection(xs:QName('mymodule:collection'))" << std::endl
                << "  by ./foo as xs:string;" << std::endl;
      // we have only one module
      lResult->theModule = lQuery.release();
      lResult->setError(URIResolverResult::UR_NOERROR);
    }

    return std::auto_ptr<ModuleURIResolverResult>(lResult.release());
  }
};

/**
 * test to demonstrate the loadProlog functionality that uses
 * a query to populate a static context.
 * The resulting context is used in order to compile another
 * (main) query.
 * The prolog contains a variable, a collection, and a function
 * declaration.
 */
bool
context_example_11(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();
  PrologModuleURIResolver lResolver;
  lContext->addModuleURIResolver(&lResolver);

  try {
    Zorba_CompilerHints_t hints;
    std::stringstream lProlog;
    lProlog << "import module namespace mymodule = 'http://www.zorba-xquery.com/mymodule';" << std::endl
            << "import module namespace sctx = 'http://www.zorba-xquery.com/modules/introspection/sctx';"
            << std::endl
            << "declare function local:collections() { " << std::endl
            << "  sctx:declared-collections()" << std::endl
            << "};" << std::endl;
    lContext->loadProlog(lProlog.str(), hints);

    // compile the main query using the populated static context
    XQuery_t lQuery = aZorba->compileQuery("$mymodule:var, local:collections()", lContext);

    // execute the query and make sure that the result is correct
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    std::stringstream lResult;
    lQuery->execute(lResult, &lSerOptions);
    std::cout << "result " << lResult.str() << std::endl;

    if (lResult.str().compare("myvar mymodule:collection") == 0) {
      return true;
    } else {
      std::cerr << "result doesn't match expected result (myvar mymodule:collection)"
                << std::endl;
      return false;
    }

  } catch (XQueryException &e) {
    std::cerr << e << std::endl;
    return false;
  }
	return false;
}

bool
context_example_12(Zorba* aZorba)
{
  std::ostringstream lTraceStream;

  StaticContext_t lContext = aZorba->createStaticContext();

  Item lTraceQName = aZorba->getItemFactory()->createQName("http://www.zorba-xquery.org/options", "trace");
  lContext->declareOption(lTraceQName, "enable");
  lContext->setTraceStream(lTraceStream);

  try {
    Zorba_CompilerHints_t hints;

    XQuery_t aQuery = aZorba->compileQuery("fn:trace(1 to 3, 'foo')", lContext);

    // execute the query
    std::cout << aQuery << std::endl;

    // check if the trace was successful
    std::string lTraceString = lTraceStream.str();
    if (lTraceString.compare("foo [0]: xs:integer(1)\n"
          "foo [1]: xs:integer(2)\n"
          "foo [2]: xs:integer(3)\n") != 0) {
      return false;
    }
    std::cout << lTraceString << std::endl;
    return true;

  } catch (XQueryException &e) {
    std::cerr << e << std::endl;
    return false;
  }

	return false;
}

struct callback_data
{
  bool b;
};

void
collection_callback(const DeclaredCollection& coll, void* data)
{
  std::cout << "collection callback function was called for collection "
            << coll.theName.getStringValue() << std::endl;
  static_cast<callback_data*>(data)->b = true;
}

void
index_callback(const DeclaredIndex& index, void* data)
{
  std::cout << "index callback function was called for index "
            << index.theName.getStringValue() << std::endl;
  static_cast<callback_data*>(data)->b = true;
}

bool
context_example_13(Zorba* aZorba)
{
  StaticContext_t lContext = aZorba->createStaticContext();
  PrologModuleURIResolver lResolver;
  lContext->addModuleURIResolver(&lResolver);

  callback_data c, i;
  c.b = false;
  i.b = false;

  lContext->setDeclaredCollectionCallback(collection_callback, (void*)&c);
  lContext->setDeclaredIndexCallback(index_callback, (void*)&i);

  try {
    Zorba_CompilerHints_t hints;
    std::stringstream lStr;
    lStr << "import module namespace mymodule = 'http://www.zorba-xquery.com/mymodule';" << std::endl
         << "1 + 1";

    // compile the main query using the populated static context
    XQuery_t lQuery = aZorba->compileQuery(lStr.str(), lContext);

    std::stringstream lResult;
    lQuery->execute(lResult);

    return c.b && i.b;

  } catch (XQueryException &e) {
    std::cerr << e << std::endl;
    return false;
  }
	return false;
}

int
context(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();

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

  std::cout << "executing example_10" << std::endl;
  res = context_example_10(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example_11" << std::endl;
  res = context_example_11(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example_12" << std::endl;
  res = context_example_12(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example_13" << std::endl;
  res = context_example_13(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}

/* vim:set et sw=2 ts=2: */
