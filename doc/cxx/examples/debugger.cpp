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

#include <zorba/zorba.h>
#include <debugger/debugger_server.h>

using namespace zorba;

bool example_1(Zorba *aZorba)
{
  ZorbaDebugger lDebugger( 8000, 9000 );
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->attach(&lDebugger);
  lQuery->setFileName("foo.xq");
  lQuery->compile("1+2");
  std::cout << lQuery << std::endl;
  return true;
}

int debugger( int argc, char *argv[] )
{
  simplestore::SimpleStore *lStore = simplestore::SimpleStore::getStore();
  Zorba *lZorba = Zorba::getInstance( lStore );
  bool res = false;
  
  std::cout << "executing example 1" << std::endl;
  res = example_1(lZorba);
  if ( !res ) return 1;
  std::cout << std::endl;

  return 0;
}

