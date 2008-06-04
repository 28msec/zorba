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
#include <string>

#include <zorba/zorba.h>

#include "store/naive/simple_store.h"

#include "compiler/parsetree/parsenodes.h"
#include "parsertestdriverconfig.h" // SRC and BIN dir definitions
#include "compiler/parser/xquery_driver.h"
#include "compiler/api/compilercb.h"
#include "context/static_context.h"

using namespace zorba;

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  int status = 0;

  store::SimpleStore* store = store::SimpleStore::getInstance();

  Zorba* lZorba = Zorba::getInstance(store);

  std::string lQueryFileString;
  CompilerCB aCompilerCB;
  xquery_driver lDriver(&aCompilerCB);

  // do initial stuff
  if ( argc == 2 )
  {
    lQueryFileString  = zorba::PARSER_TEST_SRC_DIR +"/Queries/" + argv[1];
    std::string lQueryWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-3 );

    std::cout << "parsertest " << lQueryWithoutSuffix << std::endl;
  }
  else
  {
    std::cerr << std::endl << "usage:   parsertestdriver [testfile]" << std::endl;
    status = 1;
  }

  if (!status) {
    // TODO correct Exception handling with try-catch
    try {
      lDriver.parse_file(lQueryFileString.c_str());
    } catch (...) {
      status = 2;
    }
  }

  if (!status) {
    parsenode* lNode = lDriver.get_expr();
    if ( lNode == 0 ) {
      std::cerr << "Query parsed but no parsenode root generated!" << std::endl;
      status = 3;
    } 
  }

  lZorba->shutdown();
  return status;
}
