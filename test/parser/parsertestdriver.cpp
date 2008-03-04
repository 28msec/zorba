#include <string>
#include "parsertestdriverconfig.h" // SRC and BIN dir definitions
#include "compiler/parser/xquery_driver.h"

using namespace xqp;

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
    lQueryFileString  = xqp::PARSER_TEST_SRC_DIR +"/Queries/" + argv[1];
    std::string lQueryWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-3 );

    std::cout << "parsertest " << lQueryWithoutSuffix << std::endl;
  }
  else
  {
    std::cerr << std::endl << "usage:   parsertestdriver [testfile]" << std::endl;
    return 1;
  }

  lDriver.parse_file(lQueryFileString.c_str());

  if ( lDriver.get_expr() == 0 ) {
    std::cerr << "Query parsed but no parsenode root generated!" << std::endl;
    return 2;
  }

  return 0;
}
