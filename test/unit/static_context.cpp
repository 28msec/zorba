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

  return lFooFound && lBindings.size() == 6;
}

int static_context( int argc, char *argv[] ) {
  void *const zstore = StoreManager::getStore();
  Zorba *const zorba = Zorba::getInstance( zstore );

  if (!sctx_test_1(zorba))
    return 1;

  zorba->shutdown();
  StoreManager::shutdownStore( zstore );
  return 0;
}
/* vim:set et sw=2 ts=2: */

