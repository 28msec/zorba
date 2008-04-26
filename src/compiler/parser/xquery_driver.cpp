#include <fstream>
#include "util/properties.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_parser.hpp"
#include "compiler/parser/xquery_scanner.h"
// #include "compiler/api/compilercb.h" // not yet needed, maybe for warnings later
#include "errors/error_manager.h"

using namespace std;
namespace zorba {

xquery_driver::xquery_driver(CompilerCB* aCompilerCB, uint32_t initial_heapsize)
    : symtab(initial_heapsize),
      expr_p (NULL),
      rename_bit(false),
      ftcontains_bit(false),
      theCompilerCB(aCompilerCB)
{ }

bool xquery_driver::parse_stream(std::istream& in, const xqpString& aFilename)
{
  theFilename = aFilename.c_str();

    xquery_scanner scanner(this, &in);
    scanner.set_yy_flex_debug(Properties::instance()->traceScanning());
    this->lexer = &scanner;

    zorba::xquery_parser parser(*this);
    parser.set_debug_level(Properties::instance()->traceParsing());
    return (parser.parse() == 0);
}

bool xquery_driver::parse_file(const xqpString& aFilename)
{
  std::ifstream in(aFilename.c_str());
  return parse_stream(in, aFilename);
}

bool xquery_driver::parse_string(const xqpString& input)
{
  std::istringstream iss(input);
  return parse_stream(iss);
}

void xquery_driver::error(
	const zorba::location& l,
	string const& m)
{
  QueryLoc lLoc = createQueryLoc(l);
  ZORBA_ERROR_LOC_DESC( ZorbaError::XPST0003, lLoc, m);
}
     
void xquery_driver::error(
	string const& m)
{
  ZORBA_ERROR_DESC( ZorbaError::XPST0003, m); 
}

QueryLoc xquery_driver::createQueryLoc(const zorba::location& aLoc) 
{
  QueryLoc lLoc;
  lLoc.setFilenameBegin(aLoc.begin.filename);
  lLoc.setLineBegin(aLoc.begin.line);
  lLoc.setColumnBegin(aLoc.begin.column);
  lLoc.setFilenameEnd(aLoc.end.filename);
  lLoc.setLineEnd(aLoc.end.line);
  lLoc.setColumnEnd(aLoc.end.column);
  return lLoc;
}

}	/* namespace zorba */
