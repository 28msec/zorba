/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include <iostream>
#include <fstream>
#include <list>
#include <map>

#include <sstream>
#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_list.h>

using namespace std;
using namespace zorba;
#ifndef ZORBA_NO_FULL_TEXT
using namespace zorba::locale;
#endif /* ZORBA_NO_FULL_TEXT */

bool
sctx_test_1(Zorba* const zorba)
{
  StaticContext_t lSctx = zorba->createStaticContext();

  Zorba_CompilerHints_t lHints;

  std::stringstream lProlog;
  lProlog << "declare namespace foo = 'http://www.example.com';";

  lSctx->loadProlog(lProlog.str(), lHints);

  NsBindings lBindings;
  lSctx->getNamespaceBindings(lBindings);

  bool lFooFound = false;

  for (NsBindings::const_iterator lIter = lBindings.begin();
       lIter != lBindings.end(); ++lIter)
  {
    std::cout << "prefix: " << lIter->first << " bound to "
      << lIter->second << std::endl;

    if (lIter->first.compare("foo") == 0)
    {
      lFooFound = true;
    }
  }

  return lFooFound && lBindings.size() == 8; // JSONiq has 2 additional NS.
}

bool
sctx_test_2(Zorba* const zorba)
{
  StaticContext_t lSctx = zorba->createStaticContext();

  Zorba_CompilerHints_t lHints;

  try
  {
    Item lFetched = lSctx->fetch("http://zorba.io/modules/fetch", "MODULE");

    return !lFetched.isNull();
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
  }
  return false;
}


bool sctx_test_3(Zorba* zorba)
{
  StaticContext_t sctx = zorba->createStaticContext();

  try
  {
    Zorba_CompilerHints_t hints;
    std::stringstream prolog;
    prolog << "declare variable $prologVariable := <hello>World!</hello>;";
    sctx->loadProlog(prolog.str(), hints);

    // compile the main query using the populated static context
    XQuery_t query = zorba->compileQuery("declare variable $queryVar := <queryVar>foo</queryVar>; $prologVariable ", sctx);

    // execute the query and make sure that the result is correct
    Zorba_SerializerOptions lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    std::stringstream result;
    query->execute(result, &lSerOptions);
    std::cout << "Print prolog variable: " << result.str() << std::endl;

    if (result.str() != "<hello>World!</hello>")
      return false;
  }
  catch (XQueryException &e)
  {
    std::cerr << e << std::endl;
    return false;
  }

  return true;
}


bool
sctx_test_4(Zorba* const zorba)
{
  StaticContext_t lSctx = zorba->createStaticContext();

  Zorba_CompilerHints_t lHints;

  try
  {
    Item lFetched = lSctx->fetchBinary("http://zorba.io/modules/fetch", "MODULE");

    size_t s;
    return !lFetched.isNull() && lFetched.getBase64BinaryValue(s);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;
  }
  return false;
}


bool
sctx_test_5(Zorba* zorba)
{
  std::stringstream queryString1;
  std::stringstream queryString2;

  queryString1
    << "import module namespace ddl = "
    << "\"http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl\";"
    << std::endl
    << "ddl:create(xs:QName(\"coll1\"));"
    << std::endl;

  queryString2
    << "import module namespace ddl = "
    << "\"http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl\";"
    << "import module namespace dml = "
    << "\"http://www.zorba-xquery.com/modules/store/dynamic/collections/dml\";"
    << std::endl
    << "ddl:create(xs:QName(\"coll1\"), <a/>);"
    << "count(dml:collection(xs:QName(\"coll1\")))"
    << std::endl;

  ItemFactory* factory = zorba->getItemFactory();

  Item fname = factory->
  createQName("http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl", 
              "create");

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 1);
    sctx->disableFunction(fname, 2);

    XQuery_t query = zorba->compileQuery(queryString1, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    if (e.diagnostic() != err::XPST0017)
      return false;
  }
  catch (...)
  {
    return false;
  }

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 1);
    sctx->disableFunction(fname, 2);

    queryString2.seekg(0, std::ios::beg);

    XQuery_t query = zorba->compileQuery(queryString2, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    if (e.diagnostic() != err::XPST0017)
      return false;
  }
  catch (...)
  {
    return false;
  }

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 1);

    queryString1.clear();
    queryString1.seekg(0, std::ios::beg);

    XQuery_t query = zorba->compileQuery(queryString1, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    if (e.diagnostic() != err::XPST0017)
      return false;
  }
  catch (...)
  {
    return false;
  }

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 1);

    queryString2.clear();
    queryString2.seekg(0, std::ios::beg);

    XQuery_t query = zorba->compileQuery(queryString2, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    return false;
  }
  catch (...)
  {
    return false;
  }


  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 2);

    queryString1.clear();
    queryString1.seekg(0, std::ios::beg);

    XQuery_t query = zorba->compileQuery(queryString1, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    return false;
  }
  catch (...)
  {
    return false;
  }

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 2);

    queryString2.clear();
    queryString2.seekg(0, std::ios::beg);

    XQuery_t query = zorba->compileQuery(queryString2, sctx);
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    if (e.diagnostic() != err::XPST0017)
      return false;
  }
  catch (...)
  {
    return false;
  }


  try
  {
    StaticContext_t sctx = zorba->createStaticContext();
    sctx->disableFunction(fname, 1);

    queryString2.clear();
    queryString2.seekg(0, std::ios::beg);

    {
      XQuery_t query = zorba->compileQuery(queryString2, sctx);

      std::ofstream planFile("out.plan");
      assert(planFile.good());

      query->saveExecutionPlan(planFile);
    }
    {
      std::ifstream planFile("out.plan");
      assert(planFile.good());

      XQuery_t query = zorba->createQuery();

      query->loadExecutionPlan(planFile);

      Zorba_SerializerOptions serOptions;
      serOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
      std::ostringstream out;
      query->execute(out, &serOptions);

      if (out.str() != "1")
      {
        std::cerr << out.str() << std::endl;
        return false;
      }
    }
  }
  catch (ZorbaException& e)
  {
    std::cerr << e << std::endl;

    return false;
  }
  catch (...)
  {
    std::cerr << "unknown exception" << std::endl;

    return false;
  }

  return true;
}


bool
sctx_test_6(Zorba* zorba)
{
  std::stringstream queryString;

  queryString
    << "jsoniq version \"1.0\";\n"
    << "declare function local:concat() { fn:current-dateTime() };\n"
    << "trace(concat(), \"concat\") instance of xs:dateTime";

  StaticContext_t sctx = zorba->createStaticContext();

  std::vector<String> lNamespaces;
  lNamespaces.push_back("http://www.w3.org/2005/xquery-local-functions");
  lNamespaces.push_back("http://www.w3.org/2005/xpath-functions");
  sctx->setDefaultFunctionNamespaces(lNamespaces);

  {
    XQuery_t lQuery = zorba->compileQuery(queryString.str(), sctx);
    std::ofstream planFile("out.plan");
    assert(planFile.good());

    lQuery->saveExecutionPlan(planFile);
  }
  {
    std::ifstream planFile("out.plan");
    assert(planFile.good());

    XQuery_t query = zorba->createQuery();

    query->loadExecutionPlan(planFile);

    Iterator_t lIter = query->iterator();

    lIter->open();

    Item lItem;
    if (!lIter->next(lItem) || !lItem.getBooleanValue())
    {
      return false;
    }
  }
  return true;
}



int test_static_context( int argc, char *argv[] ) 
{
  void* zstore = StoreManager::getStore();
  Zorba* zorba = Zorba::getInstance(zstore);

  std::cout << "executing sctx_test_1" << std::endl;
  if (!sctx_test_1(zorba))
    return 1;

  std::cout << "executing sctx_test_2" << std::endl;
  if (!sctx_test_2(zorba))
    return 2;

  std::cout << "executing sctx_test_3" << std::endl;
  if (!sctx_test_3(zorba))
    return 3;

  std::cout << "executing sctx_test_4" << std::endl;
  if (!sctx_test_4(zorba))
    return 4;

  std::cout << "executing sctx_test_5" << std::endl;
  if (!sctx_test_5(zorba))
    return 5;

  std::cout << "executing sctx_test_6" << std::endl;
  if (!sctx_test_6(zorba))
    return 5;

  zorba->shutdown();
  StoreManager::shutdownStore( zstore );
  return 0;
}
/* vim:set et sw=2 ts=2: */

