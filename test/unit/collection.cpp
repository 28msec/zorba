#include <cassert>
#include <fstream>
#include <iostream>

#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/xquery.h>
#include <zorba/xquery_exception.h>


int collection(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* z = zorba::Zorba::getInstance(store);

  try
  {
    {
      std::ifstream lIn("collection1.xq");
      assert(lIn.good());
      zorba::XQuery_t lQuery = z->createQuery();
      Zorba_CompilerHints lHints;
      lQuery->compile(lIn, lHints);
      std::cout << lQuery << std::endl;
    }

    {
      std::ifstream lIn("collection2.xq");
      zorba::XQuery_t lQuery = z->createQuery();
      Zorba_CompilerHints lHints;
      lQuery->compile(lIn, lHints);
      std::cout << lQuery << std::endl;
    }
  }
  catch (zorba::XQueryException &e)
  {
    std::cerr << "Error: " << e << std::endl;
    return 0;
  }
  catch (zorba::ZorbaException &e)
  {
    std::cerr << "Error: " << e << std::endl;
    return 1;
  }

  return 1;
}
/* vim:set et sw=2 ts=2: */
