#ifndef ZORBA_XQUERY_DRIVER_H
#define ZORBA_XQUERY_DRIVER_H

#include <ostream>
#include "zorbatypes/xqpstring.h"

#include "compiler/parser/symbol_table.h"

// needed because we have to delete the main module node
#include "compiler/parsetree/parsenodes.h"

namespace zorba {

class location;
class parsenode;
class CompilerCB;

class xquery_driver
{
public:
  std::string theFilename;
  symbol_table symtab;
  rchandle<parsenode> expr_p;
  bool rename_bit;
  bool ftcontains_bit;
  CompilerCB* theCompilerCB;

  xquery_driver(CompilerCB* aCompilerCB, uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver() {}

  bool parse_stream(std::istream& in, const xqpString& aFilename = "");

  bool parse_string(const xqpString& input);

  bool parse_file(const xqpString& aFilename);

  void error(const location& l, const std::string& m);

  void error(const std::string& m);

	void set_expr(parsenode* e_p) { expr_p = e_p; }
	parsenode* get_expr() { return expr_p; }

	/**
	**	Deal with "as" operator overloading for update
	*/
	void set_rename(bool b) { rename_bit = b; }
	bool rename() const { return rename_bit; }


	/**
	**	Deal with operator overloading for ft
	*/
	void set_ftcontains(bool b) { ftcontains_bit = b; }
	bool ftcontains() const { return ftcontains_bit; }

  QueryLoc createQueryLoc(const location& aLoc);

  class xquery_scanner* lexer;
};

}	/* namespace zorba */
#endif /* ZORBA_XQUERY_DRIVER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
