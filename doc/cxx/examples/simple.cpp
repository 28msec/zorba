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
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/zorba_exception.h>


using namespace zorba;

bool
example_1(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery("1+2");

  std::cout << lQuery << std::endl;

	return true;
}


bool
example_2(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("1+2");

  Iterator_t lIterator = lQuery->iterator();
  lIterator->open();

  Item lItem;
  while ( lIterator->next(lItem) ) 
  {
    std::cout << lItem.getStringValue() << std::endl;
  }

  lIterator->close();

	return true;
}


bool
example_3(Zorba* aZorba)
{

	XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 
  try {
    std::cout << lQuery << std::endl;
  } catch ( ZorbaException& e ) {
    std::cerr <<  e << std::endl;
    return true;
  }

	return false;
}


bool
example_4(Zorba* aZorba)
{

  try {
    XQuery_t lQuery = aZorba->compileQuery("for $x in (1, 2, 3)");
  } catch ( ZorbaException& e ) {
    std::cerr <<  e << std::endl;
    return true;
  }

  return false;
}


bool
example_5(Zorba* aZorba)
{
  std::string lQueryString("for $i in (1,2,3)");
  std::istringstream lInStream(lQueryString);

  try {
    XQuery_t lQuery = aZorba->compileQuery(lInStream);

    std::cout << lQuery << std::endl;
  } catch ( ZorbaException const &ze ) {
    std::cerr << ze << std::endl;
    return ze.diagnostic().kind() == diagnostic::XQUERY_STATIC;
  }

  return false;
}


bool
example_6(Zorba* aZorba)
{
  // set compiler hint => don't optimize
  Zorba_CompilerHints lHints;
  lHints.opt_level = ZORBA_OPT_LEVEL_O0;

  XQuery_t lQuery = aZorba->compileQuery("1+1", lHints);

  std::cout << lQuery << std::endl;

  return true;
}


bool
example_7()
{

  std::cout << Zorba::version() << std::endl;

  return true;
}


bool
example_8( Zorba * aZorba )
{
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setFileName("foo.xq");
  lQuery->compile("1+2");
  std::cout << lQuery << std::endl;
  return true;
}


bool
example_9( Zorba * aZorba )
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("1+1");
    lQuery->compile("1+2");
  } catch (ZorbaException & e) {
    std::cout << e << std::endl;
    return true;
  }
  return false;
}


bool
example_10( Zorba * aZorba )
{
  Iterator_t lIterator1;
  Iterator_t lIterator3;

  XQuery_t lQuery1 = aZorba->compileQuery("declare variable $i external; 1 to $i");
  XQuery_t lQuery2 = lQuery1->clone();

  DynamicContext* lDynContext1 = NULL;

  try
  {
    lDynContext1 = lQuery1->getDynamicContext();
    lDynContext1->setVariable("i", aZorba->getItemFactory()->createInteger(5));

    lIterator1 = lQuery1->iterator();

    // make sure that we cannot have more than one result iterators on a query
    bool checkOk = false;
    try
    {
      lIterator3 = lQuery1->iterator();  
    }
    catch (...)
    {
      checkOk = true;
    }

    if (!checkOk)
      return false;

    lIterator1->open();

    Item lItem;
    while ( lIterator1->next(lItem) ) 
    {
      DynamicContext* lDynContext2 = lQuery2->getDynamicContext();
      lDynContext2->setVariable("i", lItem);

      Iterator_t lIterator2 = lQuery2->iterator();
    
      lIterator2->open();
      while ( lIterator2->next(lItem) ) 
      {
        std::cout << lItem.getStringValue();
      }
      lIterator2->close();
      
      std::cout << std::endl;
    }

    lIterator1->close();
  }
  catch (ZorbaException& e)
  {
    std::cout << e.what() << std::endl;
    throw;
  }
  catch (...)
  {
    std::cout << "EXCEPTION !!!!" << std::endl;
    throw;
  }

  return true;
}


bool
example_11( Zorba * aZorba )
{
  StaticContext_t lContextWithProlog = aZorba->createStaticContext();
  String prolog (
"declare variable $x := 2;\n"
"declare function local:f ($n) { $x + $n };\n"
);
  const Zorba_CompilerHints_t hints;
  lContextWithProlog->loadProlog(prolog, hints);
  
  XQuery_t lQuery = aZorba->compileQuery("local:f ($x + 1)", lContextWithProlog);
  std::cout << lQuery << std::endl;
  return true;
}


bool
example_12(Zorba* aZorba)
{
	XQuery_t lQuery = aZorba->compileQuery("<a><b attr='1'/><b attr='2'/></a>");

  Iterator_t lIterator = lQuery->iterator();
  lIterator->open();

  Item lItem;
  while ( lIterator->next(lItem) ) 
  {
    Iterator_t lChildIter = lItem.getChildren();

    lChildIter->open();
    Item lChild;
    while (lChildIter->next(lChild)) 
    {
      Item lNodeName;
      lChild.getNodeName(lNodeName);
      std::cout << "node name " << lNodeName.getStringValue() << std::endl;
      Iterator_t lAttrIter = lChild.getAttributes();
      
      lAttrIter->open();

      Item lAttr;
      while (lAttrIter->next(lAttr)) 
      {
        std::cout << "  attribute value " << lAttr.getStringValue() << std::endl;
      }
      lAttrIter->close();
    }
    lChildIter->close();
  }

  lIterator->close();

	return true;
}



bool
example_13(Zorba* aZorba)
{
#if 0
  XQuery_t lQuery = aZorba->createQuery();
  lQuery->setTimeout(1);

  try 
  {
    lQuery->compile("while (fn:true()) {()};");
    std::cout << lQuery << std::endl;
  }
  catch (ZorbaException&) 
  {
    std::cout << "query interrputed after 1 second" << std::endl;
    return true;
  }

  return false;
#else
  return true;
#endif
}


bool
example_14()
{
  String str( "a" );
  str += "b";
  str += "c";

  return (str == "abc");
}


bool
example_15(Zorba* zorba)
{
  std::string queryString = 
  "declare variable $foo := 1;\
   \
   insert node <child/> into /parent";

  try
  {
    StaticContext_t sctx = zorba->createStaticContext();

    XQuery_t query = zorba->compileQuery(queryString, sctx);

    std::stringstream ss;
    ss << "<parent/>";
    Item context_item = zorba->getXmlDataManager()->parseXML(ss);
    DynamicContext* dctx = query->getDynamicContext();
    dctx->setContextItem(context_item);

    if( query->isUpdating() )
    {
      query->execute();

      Zorba_SerializerOptions_t options;
      Serializer_t serializer = Serializer::createSerializer(options);
      SingletonItemSequence seq(context_item);
      serializer->serialize(&seq, std::cout);
    }
    else
    {
      std::cerr << "The isUpdating() method should return true" << std::endl;
      return false;
    }

    query->close();
  }
  catch( ... )
  {
    std::cerr << "exception thrown" << std::endl;
  }

  return true;
}


int 
simple(int argc, char* argv[])
{
  void* lStore = StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = example_3(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  res = example_4(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
  res = example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 6" << std::endl;
  res = example_6(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 7" << std::endl;
  res = example_7();
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 8" << std::endl;
  res = example_8(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 9" << std::endl;
  res = example_9(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 10" << std::endl;
  res = example_10(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 11" << std::endl;
  res = example_11(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 12" << std::endl;
  res = example_12(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 13" << std::endl;
  res = example_13(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 14" << std::endl;
  res = example_14();
  if (!res) return 1;
  std::cout << std::endl;

  std::cout << "executing example 15" << std::endl;
  res = example_15(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  lZorba->shutdown();
  StoreManager::shutdownStore(lStore);
  return 0;
}
