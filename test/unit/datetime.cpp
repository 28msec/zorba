/*
 * Copyright 2006-2011 The FLWOR Foundation.
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
#include <sstream>
#include <iostream>

#ifdef WIN32
# include <windows.h>
# define sleep(s) Sleep(s*1000)
#endif

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>


// test if the current-dateTime value of the dynamic context
// is reset when executing a query multiple times
int
datetime(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* z = zorba::Zorba::getInstance(store);

  try
  {
    std::ostringstream lQueryString;
    lQueryString << "fn:current-dateTime()";

    zorba::XQuery_t lQuery = z->compileQuery(lQueryString.str());

    std::ostringstream lResult1, lResult2;

    lQuery->execute(lResult1);
    sleep(1);
    lQuery->execute(lResult2);

    std::cout << "date time 1 " << lResult1.str() << std::endl;
    std::cout << "date time 2 " << lResult2.str() << std::endl;

    if (lResult1.str() == lResult2.str()) {
      return 1;
    } else {
      return 0;
    }
  }
  catch (zorba::ZorbaException &e)
  {
    std::cerr << "Error: " << e << std::endl;
    return 1;
  }

  return 1;
}

/* vim:set et sw=2 ts=2: */
