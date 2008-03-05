#include <string>
#include "compiler/parsetree/parsenodes.h"
#include "parsertestdriverconfig.h" // SRC and BIN dir definitions
#include "compiler/parser/xquery_driver.h"

using namespace zorba;

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  std::string lQueryFileString;
  xquery_driver lDriver;
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
    return 2;
  }

  parsenode* lNode = lDriver.get_expr();
  if ( lNode == 0 ) {
    std::cerr << "Query parsed but no parsenode root generated!" << std::endl;
    return 3;
  } else {
    delete lNode;
  }

  return 0;
}
