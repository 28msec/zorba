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
#include <list>
#include <map>

#include <sstream>
#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>

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

#ifdef ZORBA_WITH_JSON
  return lFooFound && lBindings.size() == 7; // JSONiq has an additional NS.
#else
  return lFooFound && lBindings.size() == 6;
#endif
}

bool
sctx_test_2(Zorba* const zorba)
{
  StaticContext_t lSctx = zorba->createStaticContext();

  Zorba_CompilerHints_t lHints;

  try
  {
    Item lFetched = lSctx->fetch("http://www.zorba-xquery.com/modules/fetch", "MODULE");

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



int static_context( int argc, char *argv[] ) 
{
  void* const zstore = StoreManager::getStore();
  Zorba* const zorba = Zorba::getInstance( zstore );

  if (!sctx_test_1(zorba))
    return 1;

  if (!sctx_test_2(zorba))
    return 2;

  if (!sctx_test_3(zorba))
    return 3;

  zorba->shutdown();
  StoreManager::shutdownStore( zstore );
  return 0;
}
/* vim:set et sw=2 ts=2: */

