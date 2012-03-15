/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include <fstream>
#include <iostream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/typeident.h>
#include <zorba/static_context.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>
#include <zorba/options.h>
#include <zorba/item_factory.h>

#include "system/properties.h"


int test_1(zorba::Zorba* zorba)
{
  try
  {
    std::ifstream queryStream("context_item1.xq");
    assert(queryStream.good());
    std::ostringstream resultStream;

    {
      zorba::StaticContext_t sctx = zorba->createStaticContext();

      zorba::TypeIdentifier_t type = sctx->getContextItemStaticType();
      zorba::IdentTypes::kind_t kind = type->getKind();
      if (kind != zorba::IdentTypes::ITEM_TYPE)
      {
        return 10;
      }

      type = zorba::TypeIdentifier::createNamedType("http://www.w3.org/2001/XMLSchema",
                                                    "integer");
      sctx->setContextItemStaticType(type);

      zorba::XQuery_t query = zorba->compileQuery(queryStream, sctx);

      Zorba_SerializerOptions serOptions;
      serOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

      zorba::Item ctxValue = zorba->getItemFactory()->createString("foo");

      zorba::DynamicContext* dctx = query->getDynamicContext();
      dctx->setContextItem(ctxValue);

      query->execute(resultStream, &serOptions);
    }
  }
  catch (zorba::XQueryException& qe)
  {
    if (qe.diagnostic() != zorba::err::XPTY0004)
    {
      std::cerr << qe << std::endl;
      return 3;
    }

    return 0;
  }
  catch (zorba::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 1;
  }
  catch (...)
  {
    return 2;
  }

  return 4;
}


int test_2(zorba::Zorba* zorba)
{
  try
  {
    std::ifstream queryStream("context_item2.xq");
    assert(queryStream.good());
    std::ostringstream resultStream;

    {
      zorba::Item ctxValue = zorba->getItemFactory()->createString("foo");

      zorba::XQuery_t query = zorba->compileQuery(queryStream);

      Zorba_SerializerOptions serOptions;
      serOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

      zorba::DynamicContext* dctx = query->getDynamicContext();
      dctx->setContextItem(ctxValue);

      query->execute(resultStream, &serOptions);

      if (resultStream.str() != "foo")
        return 5;
    }
  }
  catch (zorba::XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    return 3;
  }
  catch (zorba::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 1;
  }
  catch (...)
  {
    return 2;
  }

  return 0;
}

int test_3(zorba::Zorba* zorba)
{
  try
  {
    std::ifstream queryStream("context_item2.xq");
    assert(queryStream.good());
    std::ostringstream resultStream;

    {
      zorba::TypeIdentifier_t type =
      zorba::TypeIdentifier::createNamedType("http://www.w3.org/2001/XMLSchema",
                                             "integer");

      zorba::Item ctxValue = zorba->getItemFactory()->createString("foo");

      zorba::StaticContext_t sctx = zorba->createStaticContext();
      sctx->setContextItemStaticType(type);

      zorba::XQuery_t query = zorba->compileQuery(queryStream, sctx);

      zorba::DynamicContext* dctx = query->getDynamicContext();
      dctx->setContextItem(ctxValue);

      query->execute(resultStream);

      return 5;
    }
  }
  catch (zorba::XQueryException& qe)
  {
    std::cerr << qe << std::endl;
    if (qe.diagnostic() == zorba::err::XQST0099)
    {
      return 0;
    }
    return 1;
  }

  return 2;
}

int context_item(int argc, char* argv[]) 
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* zorba = zorba::Zorba::getInstance(store);

  zorba::Properties::load(0, NULL);

  int result1 = test_1(zorba);

  int result2 = test_2(zorba);

  int result3 = test_3(zorba);

  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);
  return result1 + result2 + result3;
}

/* vim:set et sw=2 ts=2: */
