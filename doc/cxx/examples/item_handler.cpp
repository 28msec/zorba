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
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

/**
 * This is a example which demonstrates, how one can use item handlers.
 */

using namespace zorba;
using namespace std;

typedef struct {
  Zorba_SerializerOptions_t* theOptions;
} my_data;

int called = 0;

Zorba_SerializerOptions_t* myhandler(void* aData)
{
  my_data* lData = (my_data*)aData;
  if (called++ % 2 == 0) {
    lData->theOptions->ser_method = ZORBA_SERIALIZATION_METHOD_XML;
    lData->theOptions->version = "1.0";
  }
  else {
    lData->theOptions->ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
    lData->theOptions->version = "4.0";
  }
  return lData->theOptions;
}

bool item_handler_example(Zorba* aZorba)
{
  my_data lData;
  Zorba_SerializerOptions_t lOptions;
  lData.theOptions = &lOptions;
  lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  ostringstream lStream;
  XQuery_t lQuery = aZorba->compileQuery("(<br/>, <br/>, <br/>, <br/>)");
  lQuery->execute(lStream, &myhandler, &lData, &lOptions);
  std::string lResult = lStream.str();
  if (lResult == "<br/><br><br/><br>")
    return true;
  return false;
}

int item_handler(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();

  Zorba* lZorba = Zorba::getInstance(lStore);
  if (!item_handler_example(lZorba)) return 1;
  return 0;
}
