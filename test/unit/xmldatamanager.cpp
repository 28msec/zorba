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
#include <cassert>
#include <fstream>
#include <iostream>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/xquery.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_handler.h>

using namespace zorba;

class MyDiagnosticHandler : public DiagnosticHandler {
public:
  bool* error_called;

  MyDiagnosticHandler ( bool * b )
    : error_called ( b)
  {
  }

  virtual void
  error ( ZorbaException const &e )
  {
    std::cout << "diagnostic handler expectedly called: " << e << std::endl;
    *error_called = true;
  }
};


int xmldatamanager(int argc, char* argv[])
{
  void* store = StoreManager::getStore();
  Zorba* z = Zorba::getInstance(store);

  bool lCheck = false;

  MyDiagnosticHandler lHandler(&lCheck);

  XmlDataManager_t lMgr = z->getXmlDataManager();
  lMgr->registerDiagnosticHandler(&lHandler);

  std::stringstream lInStream;
  lInStream
    << "<books>" << std::endl
    << "  <book>Book 1</book>" << std::endl
    << "  <book>Book 2</book>" << std::endl;

  Item lDoc = lMgr->parseXML(lInStream);

  // make sure the diagnostic handler has been called
  return lCheck?0:1;
}

