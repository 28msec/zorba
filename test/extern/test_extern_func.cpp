#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <map>
#include <fstream>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/empty_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/uri_resolvers.h>
#include <zorba/store_manager.h>
#include <zorba/singleton_item_sequence.h>

using namespace zorba;

class MySimpleExternalFunction;

/*******************************************************************************
  External module with target namespace "urn:extern"
********************************************************************************/
class TestExternalModule : public ExternalModule
{
protected:
  class ltstr
  {
    public:
      bool operator()(const String& s1, const String& s2) const
      {
        return s1.compare(s2) < 0;
      }
  };

protected:
  static ItemFactory* theFactory;
  typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;
  mutable FuncMap_t theFunctions;

public:
  TestExternalModule() { }

  virtual ~TestExternalModule()
  {
    for (FuncMap_t::const_iterator lIter = theFunctions.begin(); lIter != theFunctions.end(); ++lIter)
      delete lIter->second;
    theFunctions.clear();
  }

  String getURI() const { return "urn:extern"; }

  StatelessExternalFunction* getExternalFunction(String aLocalname) const;

  static ItemFactory* getItemFactory()
  {
    if(!theFactory)
      theFactory = Zorba::getInstance(0)->getItemFactory();
    return theFactory;
  }
};

ItemFactory* TestExternalModule::theFactory = NULL;


/*******************************************************************************
  External function bar()
********************************************************************************/
class BarExternalFunction : public NonePureStatelessExternalFunction
{
protected:
  const TestExternalModule* theModule;

public:
  BarExternalFunction(const TestExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar"; }

  ItemSequence_t evaluate(
        const StatelessExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const
  {
    // std::cout << sctx->getNamespaceURIByPrefix("ns2") << std::endl;
    SingletonItemSequence* seq = new SingletonItemSequence(theModule->getItemFactory()->createString(sctx->getNamespaceURIByPrefix("ns2")));

    return ItemSequence_t(seq);
  }
};

/*******************************************************************************
  External function nondeterm()
********************************************************************************/
class NondetermExternalFunction : public NonePureStatelessExternalFunction
{
protected:
  static int counter;

protected:
  const TestExternalModule* theModule;

public:
  NondetermExternalFunction(const TestExternalModule* aModule)
    :
    theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "nondeterm"; }

  ItemSequence_t evaluate(const StatelessExternalFunction::Arguments_t& args,
                          const StaticContext* sctx,
                          const DynamicContext* dctx) const
  {
    counter++;

    return ItemSequence_t(new SingletonItemSequence(theModule->getItemFactory()->createInt(counter)));
  }
};

int NondetermExternalFunction::counter = 0;


/*******************************************************************************
  TestExternalModule::getExternalFunction
********************************************************************************/
StatelessExternalFunction* TestExternalModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (aLocalname.equals("bar")) {
      lFunc = new BarExternalFunction(this);
    } else if (aLocalname.equals("nondeterm")) {
      lFunc = new NondetermExternalFunction(this);
    }
  }
  return lFunc;
}


/*******************************************************************************

  Tests

********************************************************************************/
int test1()
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << "declare namespace extern=\"urn:extern\";" << std::endl
              << "eval {" << std::endl
              << "  'declare namespace ns2 = \"myns\";" << std::endl
              << "   declare function extern:bar() external;" << std::endl
              << "   extern:bar()'" << std::endl
              << "}" << std::endl;


    XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}

int test2()
{
  // TODO: test2 not finished yet

  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << "import module namespace extern_func = \"http://www.zorba-xquery.com/extern_func\" at \"/home/colea/work/xquery_temp4/build_fast/test/test_extern_func_module.xq\";"
              << "extern_func:test() " << std::endl;
              // << "foo:bar()" << std::endl;

    /*
    queryText << "declare namespace foo=\"urn:foo\";" << std::endl
              << "eval {" << std::endl
              << " 'declare namespace ns2 = \"myns\";" << std::endl
              << "  declare function foo:bar1() external;" << std::endl
              << " foo:bar1()'" << std::endl
              << "}" << std::endl;
    */

  XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;
  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}

int test_nondeterm(const char* filename)
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  // read the input file
  std::ifstream in(filename);
  if (!in.is_open())
  {
    std::cerr << "Error: could not open input file \"" << filename << "\"" << std::endl;
    return 1;
  }

  char c;
  std::string str;
  while (in.get(c))
    str += c;

  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();
    TestExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << str;

    XQuery_t query = lZorba->compileQuery(queryText.str(), sctx);
    std::cout << query << std::endl;

  } catch (ZorbaException& e) {
    std::cerr << e << std::endl;
    return 1;
  }

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);

  return 0;
}


int main(int argc, char** argv)
{
  if (argc <= 1)
    return 0;

  if (strcmp (argv[1], "--test1") == 0) {
    test1();
  } else if (strcmp (argv[1], "--test2") == 0) {
    test2();
  } else if (strcmp (argv[1], "--nondeterm") == 0 && argc>=3) {
    test_nondeterm(argv[2]);
  }

  return 0;
}
