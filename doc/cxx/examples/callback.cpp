#include <assert.h>
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>

using namespace zorba;

class CallBackExample {
public:
  CallBackExample() : theNumbersCalled(0)
  {
    theStore = zorba::StoreManager::getStore();
    theZorba = Zorba::getInstance(theStore);
  }

  virtual ~CallBackExample()
  {
    theZorba->shutdown();
    StoreManager::shutdownStore(theStore);
  }

public:
  bool example1()
  {
    std::stringstream lStr;
    lStr << "(<anXMLExample/>, ";
    lStr << "<json type='object'><pair name='firstName' type='string'>";
    lStr << "John</pair></json>, ";
    lStr << "42)";
    XQuery_t lQuery = theZorba->compileQuery(lStr.str());
    try {
      lQuery->execute(std::cout, callback, this);
    } catch (ZorbaException& e) {
      std::cerr << e << std::endl;
      return false;
    }
    return true;
  }

  static Zorba_SerializerOptions_t* callback(void* aData)
  {
    std::cout << std::endl << "callback called" << std::endl;
    CallBackExample* lInst = static_cast<CallBackExample*>(aData);
    switch (lInst->theNumbersCalled++)
    {
    case 0:
      lInst->theSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
      break;
    case 1:
      lInst->theSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSON;
      break;
    case 2:
      lInst->theSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_BINARY;
      break;
    default:
      lInst->theSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
    }
    return &(lInst->theSerOptions);
  }
private:
  Zorba* theZorba;
  simplestore::SimpleStore* theStore;
  unsigned theNumbersCalled;
  Zorba_SerializerOptions_t theSerOptions;
};

int callback(int argc, char* argv[])
{
  CallBackExample lExample;
  lExample.example1();
  return 0;
}
