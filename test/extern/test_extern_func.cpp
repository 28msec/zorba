#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/empty_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/uri_resolvers.h>
#include <zorba/store_manager.h>

using namespace zorba;


class MySimpleExternalFunction : public NonePureStatelessExternalFunction
{
protected:
  const ExternalModule* theModule;

public:
  MySimpleExternalFunction(const ExternalModule* aModule)
    : theModule(aModule)
  {
  }

  String getURI() const { return theModule->getURI(); }

  String getLocalName() const { return "bar1"; }

  ItemSequence_t evaluate(
        const StatelessExternalFunction::Arguments_t& args,
        const StaticContext* sctx,
        const DynamicContext* dctx) const
  {
    std::cout << sctx->getNamespaceURIByPrefix("ns2") << std::endl;

    return ItemSequence_t(new EmptySequence());
  }
};

/*******************************************************************************
  External module with target namespace "urn:foo"
********************************************************************************/
class MyExternalModule : public ExternalModule
{
protected:
  mutable MySimpleExternalFunction           * bar1;

public:
  MyExternalModule()
    : bar1(new MySimpleExternalFunction(this))
  {
  }

  virtual ~MyExternalModule()
  {
    delete bar1;
  }

  String getURI() const { return "urn:foo"; }

  StatelessExternalFunction* getExternalFunction(String aLocalname) const
  {
    return bar1;
  }
};

int test1()
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  try
  {
    StaticContext_t sctx = lZorba->createStaticContext();

    MyExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;
    queryText << "declare namespace foo=\"urn:foo\";" << std::endl
              << "eval {" << std::endl
              << " 'declare namespace ns2 = \"myns\";" << std::endl
              << "  declare function foo:bar1() external;" << std::endl
              << " foo:bar1()'" << std::endl
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

    MyExternalModule module;
    sctx->registerModule(&module);

    std::ostringstream queryText;

    queryText << "import module namespace extern_func = \"http://www.zorba-xquery.com/extern_func\" at \"/home/colea/work/xquery_temp4/build_fast/test/test_extern_func_module.xq\";"
              << "extern_func:test() " << std::endl;
              // << "foo:bar1()" << std::endl;

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


int main(int argc, char** argv)
{
  if (argc <= 1)
    return 0;
    
  if (strcmp (argv[1], "--test1") == 0)
  {
    test1();
  } else if (strcmp (argv[1], "--test2") == 0) {
    test2();
  }

  return 0;
}
