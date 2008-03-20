#include <string>
#include "compiler/parsetree/parsenodes.h"
#include "parsertestdriverconfig.h" // SRC and BIN dir definitions
#include "compiler/parser/xquery_driver.h"
#include "system/globalenv.h"
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
  GlobalEnvironment::init(); 
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
    return 1;
  }

  // TODO correct Exception handling with try-catch
  try {
    lDriver.parse_file(lQueryFileString.c_str());
  } catch (...) {
    GlobalEnvironment::destroy();
    return 2;
  }

  parsenode* lNode = lDriver.get_expr();
  if ( lNode == 0 ) {
    std::cerr << "Query parsed but no parsenode root generated!" << std::endl;
    GlobalEnvironment::destroy();
    return 3;
  } 
  GlobalEnvironment::destroy();
  return 0;
}
