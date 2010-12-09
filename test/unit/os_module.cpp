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
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <cassert>
#include <cstdlib>

using namespace zorba;

bool test_operating_system(Zorba* aZorba)
{
  std::stringstream lQuery, lResult;
  lQuery << "import module namespace os = \"http://www.zorba-xquery.com/modules/os\";" << std::endl
         << "os:operating-system()" << std::endl;

  XQuery_t lXQuery = aZorba->compileQuery(lQuery);

  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  lXQuery->execute(lResult, &lSerOptions);

#ifdef APPLE
  assert(lResult.str() == "Mac OS X");
#elif defined(LINUX)
  std::string lStr = lResult.str();
  assert(lResult.str() == "Linux");
#elif defined(WIN32)
  assert(lResult.str() == "Windows");
#else
  assert(false);
#endif

  return true;
}

bool test_get_env(Zorba* aZorba)
{
  char lStr[] = "ZORBA=ISGREAT";
  putenv(lStr);

  std::stringstream lQuery, lResult;
  lQuery << "import module namespace os = \"http://www.zorba-xquery.com/modules/os\";" << std::endl
         << "os:get-env(\"ZORBA\")" << std::endl;

  XQuery_t lXQuery = aZorba->compileQuery(lQuery);

  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  lXQuery->execute(lResult, &lSerOptions);

  assert(lResult.str() == "ISGREAT");

  return true;
}

int os_module(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  if (!test_operating_system(lZorba))
    return 1;

  if (!test_get_env(lZorba))
    return 2;

  return 0;
}
