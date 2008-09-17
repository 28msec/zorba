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


#include <iostream>
#include <fstream>
#include <sstream>
#include <atlconv.h>
#include <atlbase.h>


#include <zorba/zorba.h>
#include <zorba/config.h>
#include <simplestore/simplestore.h>
#include <simplestore/msdom/import.h>

#include <msxml.h>


using namespace zorba;
using namespace zorba::simplestore;

/**
 * Example to show how to use the MS DOM store in Zorba.
 * The MS DOM store stands for "the store which keeps its data internaly also
 *    in Microsoft DOM format".
 * An xml file is loaded into a variable, processed with a simple XPath filter
 *    and then the result is exported as MS DOM document.
 * The result text will be serialized by MS DOM and by the result item. 
 * The outputs should look the same.
 * Note: In order to test this example you need to compile simplestore with
 *    the flag ZORBA_STORE_MSDOM set to ON in cmake.
 */
bool
msdom_store_example_1(Zorba* aZorba)
{
  //Get the SimpleStore object
  zorba::simplestore::SimpleStore* msdomstore = 
        zorba::simplestore::SimpleStoreManager::getStore();

  std::auto_ptr<std::istream> lDocStream( 
    new std::stringstream("<books><book>Book 1</book><book>Book 2</book><book processable=\"1\">Book 3</book><book processable=\"1\">Book 4<chapter1/><chapter2/></book></books>"));

  XQuery_t lQuery = aZorba->compileQuery("declare variable $var external; $var//book[@processable = 1]");

  DynamicContext* lCtx = lQuery->getDynamicContext();

  //load the above xml into variable $var, associating with URI "books.xml"
  //when loading, the MS DOM tree is constructed as well
  lCtx->setVariableAsDocument("var", "books.xml", lDocStream);

  try {
    ResultIterator_t    result;
    //get an iterator over the result items
    //the actual execution will be performed when asking for the next item
    result = lQuery->iterator();

    Item  item;
    result->open();//open the iterator
    while(result->next(item))
    {
      //export the MS DOM from Item
      IXMLDOMNode*  msdom_node;
      msdom_node = MSDOM2SimpleStore::exportItemAsMSDOM(item);
      std::cout << "Zorba item output:" << std::endl << std::endl;
      item.serialize(std::cout);
      std::cout << std::endl << std::endl;
      if(msdom_node)
      {
        BSTR  xml_bstr;
        msdom_node->get_xml(&xml_bstr);
        char  xml_ascii[1000];
        WideCharToMultiByte(CP_ACP, 0, xml_bstr, -1, xml_ascii, 1000, NULL, NULL);
        std::cout << "MSDOM output:" << std::endl << std::endl;
        std::cout << xml_ascii << std::endl << std::endl;
      }
      else
      {
        std::cout << "No MS DOM node associated" << std::endl;
      }
    }
    result->close();//close the iterator to free resources
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}

/**
 * Example to show how to import MS DOM tree in Zorba.
 * Load an xml into MS DOM and then import the MS DOM tree into Zorba.
 * Display the original MS DOM and the imported document to see if they match.

 * Note: In order to test this example you need to compile simplestore with
 *    the flag ZORBA_STORE_MSDOM set to ON in cmake.
 */
bool
msdom_store_example_2(Zorba* aZorba)
{
  //Get the SimpleStore object
  zorba::simplestore::SimpleStore* msdomstore = 
        zorba::simplestore::SimpleStoreManager::getStore();

  const char xmlDoc[] = "<?xml version=\"1.0\" encoding = \"UTF-8\"?><books><book>Book 1</book><book>Book 2</book><book processable=\"1\">Book 3</book><book processable=\"1\">Book 4</book></books>";

  //load xml into MS DOM
  IXMLDOMDocument *domdoc;
  CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, 
       IID_IXMLDOMDocument, (void**)&domdoc);

  CComBSTR  xml_bstr(xmlDoc);
  VARIANT_BOOL  is_success;
  HRESULT   hr;
  hr = domdoc->loadXML(xml_bstr, &is_success);

  //display what has been loaded into MS DOM
  BSTR  xml_bstr2;
  domdoc->get_xml(&xml_bstr2);
  {
    char  xml_ascii[1000];
    WideCharToMultiByte(CP_ACP, 0, xml_bstr2, -1, xml_ascii, 1000, NULL, NULL);
    std::cout << "MS DOM version of xml:" << std::endl;
    std::cout << xml_ascii << std::endl;
  }

  //import the MS DOM into Zorba store
  MSDOM2SimpleStore::importMSDOM(domdoc, 
                          String("importedDoc.xml"), String());
  


  XQuery_t lQuery = aZorba->compileQuery("fn:doc(\"importedDoc.xml\")");

  try {
    //execute the query
    std::cout << "Zorba version of xml:" << std::endl;
    std::cout << lQuery << std::endl;
  } catch (DynamicException& e) {
    std::cerr << e << std::endl;
    return false;
  }
  return true;
}


int
msdom(int argc, char *argv[])
{
  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();

  Zorba* lZorba = Zorba::getInstance(lStore);

  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = msdom_store_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = msdom_store_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);

  return 0;
}
