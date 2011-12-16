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
#include "stdafx.h"

#include "unit_test_list.h"

#include "store/naive/json_loader.h"
#include "store/naive/json_items.h"
#include "store/naive/json_visitor.h"
#include <sstream>

using namespace zorba::simplestore::json;

namespace zorba {

namespace UnitTests {

int runLoaderTest(int argc, char* argv[])
{

  std::stringstream json;

  json
    << "{" << std::endl
    << "  \"glossary\": {" << std::endl
    << "      \"title\": \"example glossary\"," << std::endl
    << "  \"GlossDiv\": {" << std::endl
    << "          \"title\": \"S\"," << std::endl
    << "    \"GlossList\": {" << std::endl
    << "              \"GlossEntry\": {" << std::endl
    << "                  \"ID\": \"SGML\"," << std::endl
    << "        \"SortAs\": \"SGML\"," << std::endl
    << "        \"GlossTerm\": \"Standard Generalized Markup Language\"," << std::endl
    << "        \"Acronym\": \"SGML\"," << std::endl
    << "        \"Abbrev\": \"ISO 8879:1986\"," << std::endl
    << "        \"GlossDef\": {" << std::endl
    << "                      \"para\": \"A meta-markup language, used to create markup languages such as DocBook.\"," << std::endl
    << "          \"GlossSeeAlso\": [\"GML\", \"XML\"]" << std::endl
    << "                  }," << std::endl
    << "        \"GlossSee\": \"markup\"" << std::endl
    << "              }" << std::endl
    << "          }" << std::endl
    << "      }," << std::endl
    << "  \"integer\": 42," << std::endl
    << "  \"decimal\": 42.42," << std::endl
    << "  \"double\": 42e42" << std::endl
    << "  }" << std::endl
    << "}";
    json << "{ \"foo\": true, \"bar\": false }";
    json << "[ \"foo\", \"bar\", [ \"blub\" ] ]";

  JSONLoader lLoader(json);

  store::Item_t lJSON;
  
  while (lJSON = lLoader.next())
  {
    JSONPrinterVisitor lVisitor(std::cout);
    dynamic_cast<JSONItem*>(lJSON.getp())->accept(&lVisitor);
    std::cout << std::endl;
  }

  return 0;
}


}

}
/* vim:set et sw=2 ts=2: */

